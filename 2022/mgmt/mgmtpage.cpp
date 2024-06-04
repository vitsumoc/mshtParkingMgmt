#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QMessageBox>
#include <QFileDialog>
#include <QSqlQuery>
#include <QThread>

#include "mgmtpage.h"
#include "ui_mgmtpage.h"

#include "constant.h"
#include "model.h"
#include "dbconnector.h"
#include "lotterypage.h"
#include "resultpage.h"

#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
using namespace QXlsx;

#include <QtDebug>
MgmtPage::MgmtPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MgmtPage)
{
    ui->setupUi(this);

    // 初始化软件
    init();
    // 初始化样式
    initStyle();
}

MgmtPage::~MgmtPage()
{
    delete _resultPage;
    delete _lotteryPage;
    delete ui;
}

void MgmtPage::init()
{
    setWindowTitle("名仕豪庭车位摇号软件——管理端");
    setAttribute(Qt::WA_DeleteOnClose);
    // 数据库连接单例
    new DbConnector(this);

    // 子页面
    _lotteryPage = new LotteryPage(nullptr);
    _lotteryPage->hide();
    _resultPage = new ResultPage(nullptr);
    _resultPage->hide();
}

void MgmtPage::initStyle()
{
    QFile f(":/qdarkstyle/light/style.qss");

    if (!f.exists())   {
        printf("Unable to set stylesheet, file not found\n");
    }
    else   {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        qApp->setStyleSheet(ts.readAll());
        f.close();
    }
}


void MgmtPage::on_btn_lock_clicked()
{
    // 获得密码并清空
    QString password = ui->line_password->text();
    ui->line_password->clear();
    if (_enable) {
        _enable = false;
        ui->btn_reset->setEnabled(false);
        ui->btn_export->setEnabled(false);
        ui->btn_parking->setEnabled(false);
        ui->btn_owner->setEnabled(false);
        ui->btn_lock->setText("解锁");
    } else {
        if (G::PASSWORD != password) {
            return;
        }
        _enable = true;
        ui->btn_reset->setEnabled(true);
        ui->btn_export->setEnabled(true);
        ui->btn_parking->setEnabled(true);
        ui->btn_owner->setEnabled(true);
        ui->btn_lock->setText("锁定");
    }
}

void MgmtPage::on_btn_reset_clicked()
{
    // 实现方法是，先把当前数据库复制一份，然后清空数据库
    if (_isWorking) {
        return;
    }
    _isWorking = true;
    // 文件复制
    if (QFile::copy("./db/mshtPM.db", "./db/" + QDateTime::currentDateTime().toString("yyyyMMddHHmmss") + ".db.bk")) {
        // 清空数据库
        bool ok = true;
        QSqlQuery query(DbConnector::instance->db);
        ok = query.exec("DELETE FROM parkings") && ok;
        ok = query.exec("DELETE FROM owners") && ok;
        if (ok) {
            QMessageBox::information(this, "提示", "操作成功");
        } else {
            QMessageBox::information(this, "提示", "数据异常，请联系技术员");
        }
    } else {
        QMessageBox::information(this, "提示", "数据库复制失败");
    }
    _isWorking = false;
}

void MgmtPage::on_btn_parking_clicked()
{
    if (_isWorking) {
        return;
    }
    _isWorking = true;
    // 判断是否已有数据
    QSqlQuery query(DbConnector::instance->db);
    query.exec("SELECT COUNT(*) as c FROM parkings");
    query.first();
    if (query.value("c").toInt() > 0) {
        QMessageBox::information(this, "提示", "操作失败：表中已有内容");
        _isWorking = false;
        return;
    }

    // 获得excel
    QString fileName = QFileDialog::getOpenFileName(this, ".xlsx");
    if (fileName.isEmpty()) {
        _isWorking = false;
        return;
    }

    // 解析车位excel
    Document parkingDoc(fileName);
    if (!parkingDoc.load()) {
        QMessageBox::information(this, "提示", "操作失败：Excel加载失败");
        _isWorking = false;
        return;
    }
    QList<Parking> parkings;
    // 将excel中的内容读入内存
    int row = 2;
    while (true) {
        Cell *c1 = parkingDoc.cellAt(row, 1);
        Cell *c2 = parkingDoc.cellAt(row, 2);
        Cell *c3 = parkingDoc.cellAt(row, 3);
        if (nullptr == c1 || nullptr == c2) {
            break;
        }
        Parking p;
        p.type = G::parkingType(c1->readValue().toString());
        p.code = c2->readValue().toString();
        if (c3 != nullptr) {
            if (c3->readValue().toString() == QString("是")) {
                p.is_mz = true;
            }
        }
        if (p.type == -1) {
            QMessageBox::information(this, "提示", "操作失败：未知车位类型");
            _isWorking = false;
            return;
        }
        parkings.append(p);

        // 下一行
        row++;
    }
    // 数据收集完毕，做批量入库
    for (int x = 0; x < parkings.size(); x++) {
        QThread::msleep(2);
        query.clear();
        parkings.at(x).toQuery(&query);
        if (!query.exec()) {
            QMessageBox::information(this, "提示", "操作失败：数据操作失败");
            _isWorking = false;
            return;
        }
    }

    QMessageBox::information(this, "提示", QString::asprintf("成功插入数据 %d 条", parkings.length()));
    _isWorking = false;
}

void MgmtPage::on_btn_owner_clicked()
{
    if (_isWorking) {
        return;
    }
    _isWorking = true;
    // 判断是否已有数据
    QSqlQuery query(DbConnector::instance->db);
    query.exec("SELECT COUNT(*) as c FROM owners");
    query.first();
    if (query.value("c").toInt() > 0) {
        QMessageBox::information(this, "提示", "操作失败：表中已有内容");
        _isWorking = false;
        return;
    }

    // 获得excel
    QString fileName = QFileDialog::getOpenFileName(this, ".xlsx");
    if (fileName.isEmpty()) {
        _isWorking = false;
        return;
    }

    // 解析业主excel
    Document ownerDoc(fileName);
    if (!ownerDoc.load()) {
        QMessageBox::information(this, "提示", "操作失败：Excel加载失败");
        _isWorking = false;
        return;
    }
    QList<Owner> owners;
    // 将excel中的内容读入内存
    int row = 2;
    while (true) {
        Cell *c1 = ownerDoc.cellAt(row, 1);
        Cell *c2 = ownerDoc.cellAt(row, 2);
        Cell *c3 = ownerDoc.cellAt(row, 3);
        Cell *c4 = ownerDoc.cellAt(row, 4);
        Cell *c5 = ownerDoc.cellAt(row, 5);
        Cell *c6 = ownerDoc.cellAt(row, 6);
        if (nullptr == c1 || nullptr == c2 ||
                nullptr == c3 || nullptr == c4 ||
                nullptr == c5) {
            break;
        }
        Owner o;
        o.code = c1->readValue().toInt();
        o.room_code = c2->readValue().toString();
        o.name = c3->readValue().toString();
        o.phone = c4->readValue().toString();
        o.plate1 = c5->readValue().toString();
        if (c6 != nullptr) {
            if (!c6->readValue().toString().isEmpty()) {
                o.plate2 = c6->readValue().toString();
            }
        }
        owners.append(o);

        // 下一行
        row++;
    }
    // 数据收集完毕，做批量入库
    for (int x = 0; x < owners.size(); x++) {
        QThread::msleep(2);
        query.clear();
        owners.at(x).toQuery(&query);
        if (!query.exec()) {
            QMessageBox::information(this, "提示", "操作失败：数据操作失败");
            _isWorking = false;
            return;
        }
    }

    QMessageBox::information(this, "提示", QString::asprintf("成功插入数据 %d 条", owners.length()));
    _isWorking = false;
}

void MgmtPage::on_btn_activation_clicked()
{
    if (_isWorking) {
        return;
    }
    _isWorking = true;

    // 校验输入
    bool ok;
    int code = ui->line_owner_active->text().toInt(&ok);
    if (!ok || code <= 0) {
        QMessageBox::information(this, "提示", "操作失败：输入不正确");
        _isWorking = false;
        return;
    }

    // 查询数据条数
    QSqlQuery query(DbConnector::instance->db);
    query.exec("SELECT COUNT(*) as c FROM owners WHERE code = " + QString::number(code));
    query.first();
    if (query.value("c").toInt() != 1) {
        QMessageBox::information(this, "提示", "操作失败：用户不存在或重复");
        _isWorking = false;
        return;
    }

    // 判断用户当前状态
    query.prepare("SELECT * FROM owners WHERE code = :code");
    query.bindValue(":code", code);
    query.exec();
    query.first();
    Owner owner;
    owner.fromQuery(&query);

    if (owner.status == G::OWNER_STATUS_ACTIVE) {
        QMessageBox::information(this, "提示", "操作失败：用户已激活");
        _isWorking = false;
        return;
    }

    if (owner.status == G::OWNER_STATUS_FINISH) {
        QMessageBox::information(this, "提示", "操作失败：用户已获得车位");
        _isWorking = false;
        return;
    }

    // 将用户激活，并设置激活时间
    query.prepare("UPDATE owners SET status = :status, "
                  "active_time = :active_time "
                  "WHERE code = :code");
    query.bindValue(":status", G::OWNER_STATUS_ACTIVE);
    query.bindValue(":active_time", QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
    query.bindValue(":code", code);
    if (!query.exec()) {
        QMessageBox::information(this, "提示", "操作失败：数据操作失败");
        _isWorking = false;
        return;
    }

    QMessageBox::information(this, "提示", "激活成功");
    ui->line_owner_active->clear();
    _isWorking = false;
}

void MgmtPage::on_btn_export_clicked()
{
    // 将结果输出为一个excel
    if (_isWorking) {
        return;
    }
    _isWorking = true;

    // 获得全量的信息列表
    QSqlQuery query(DbConnector::instance->db);
    QList<Parking> parkings;
    QList<Owner> owners;
    QHash<int, int> owner_index;     //业主code和序号对应表

    // 查出所有车位信息
    if (!query.exec("SELECT * FROM parkings")) {
        QMessageBox::information(this, "提示", "操作失败：数据操作失败");
        _isWorking = false;
        return;
    }
    while (query.next()) {
        Parking parking;
        parking.fromQuery(&query);
        parkings.append(parking);
    }

    // 查出所有业主信息
    if (!query.exec("SELECT * FROM owners")) {
        QMessageBox::information(this, "提示", "操作失败：数据操作失败");
        _isWorking = false;
        return;
    }
    while (query.next()) {
        Owner owner;
        owner.fromQuery(&query);
        owners.append(owner);
    }
    for (int x = 0; x < owners.length(); x++) {
        owner_index.insert(owners.at(x).code, x);
    }

    // 生成excel，分别记录车位和业主信息
    QString nowStr = QDateTime::currentDateTime().toString("yyyyMMddHHmmss");
    Document xlsxParking;
    // 写入表头
    xlsxParking.write(1, 1, "车位类型");
    xlsxParking.write(1, 2, "车位号");
    xlsxParking.write(1, 3, "母子车位");
    xlsxParking.write(1, 4, "车位状态");
    xlsxParking.write(1, 5, "业主号");
    xlsxParking.write(1, 6, "房间号");
    xlsxParking.write(1, 7, "业主名");
    xlsxParking.write(1, 8, "手机号");
    xlsxParking.write(1, 9, "车牌1");
    xlsxParking.write(1, 10, "车牌2");
    // 写入内容
    int row = 2;
    for (int x = 0; x < parkings.length(); x++) {
        Parking p = parkings.at(x);
        xlsxParking.write(row, 1, G::parkingType(p.type));
        xlsxParking.write(row, 2, p.code);
        xlsxParking.write(row, 3, p.is_mz? "是": "否");
        xlsxParking.write(row, 4, G::parkingStatus(p.status));
        // 如果是已经分配的车位，则追加业主信息
        if (p.status == G::PARKING_STATUS_UDED) {
            Owner owner = owners.at(owner_index.value(p.owner_code));
            xlsxParking.write(row, 5, p.owner_code);
            xlsxParking.write(row, 6, owner.room_code);
            xlsxParking.write(row, 7, owner.name);
            xlsxParking.write(row, 8, owner.phone);
            xlsxParking.write(row, 9, owner.plate1);
            xlsxParking.write(row, 10, owner.plate2);
        }

        row++;
    }
    if (!xlsxParking.saveAs(nowStr + "车位.xlsx")) {
        QMessageBox::information(this, "提示", "操作失败：excel保存失败");
        _isWorking = false;
        return;
    }

    QMessageBox::information(this, "提示", "操作成功");
    _isWorking = false;
}

void MgmtPage::on_btn_lottery_clicked()
{
    _lotteryPage->show();
}

void MgmtPage::on_btn_result_clicked()
{
    _resultPage->show();
}

void MgmtPage::on_btn_r1_clicked()
{
    // 第一轮
    QString r1Str = ui->line_r1->text();
    bool ok;
    int r1 = r1Str.toInt(&ok);
    if (!ok) {
        QMessageBox::information(this, "提示", "请输入第一轮摇号人数");
        return;
    }
    G::R1 = r1;
    G::ROUND = 1;
    _lotteryPage->changeRound();
    ui->line_r1->setEnabled(false);
    ui->btn_r1->setEnabled(false);
    ui->line_r2->setEnabled(true);
    ui->btn_r2->setEnabled(true);
}

void MgmtPage::on_btn_r2_clicked()
{
    // 第二轮
    QString r2Str = ui->line_r2->text();
    bool ok;
    int r2 = r2Str.toInt(&ok);
    if (!ok) {
        QMessageBox::information(this, "提示", "请输入第二轮摇号人数");
        return;
    }
    G::R2 = r2;
    G::ROUND = 2;
    _lotteryPage->changeRound();
    ui->line_r2->setEnabled(false);
    ui->btn_r2->setEnabled(false);
}
