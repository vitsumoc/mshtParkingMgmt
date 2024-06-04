#include <QSqlQuery>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QPainter>
#include <QTimer>
#include <QMutexLocker>

#include "lotterypage.h"
#include "ui_lotterypage.h"

#include "dbconnector.h"
#include "model.h"

LotteryPage::LotteryPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LotteryPage)
{
    ui->setupUi(this);

    setWindowTitle("摇号页面");

    // 初始化table样式
    ui->table_round->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->table_round->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->table_round->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->table_round->setSelectionMode(QAbstractItemView::NoSelection);

    ui->table_result->verticalHeader()->setVisible(false);
    ui->table_result->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->table_result->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->table_result->setSelectionMode(QAbstractItemView::NoSelection);


    // 初始化并设定定时器
    _timer = new QTimer(this);
    connect(_timer, SIGNAL(timeout()), this, SLOT(slt_timer()));
    _timer->start(80);

    // 初始化抽奖用户
    _owner = new Owner();
}

LotteryPage::~LotteryPage()
{
    delete _owner;
    delete ui;
}

void LotteryPage::changeRound()
{
    ui->label_round->setText("当前轮次 : 第" + QString::number(G::ROUND) + "轮");
    // 获得所有车位并写入
    QSqlQuery query(DbConnector::instance->db);
    // 显示车位数据
    QList<Parking> parkings;
    query.exec("SELECT * FROM parkings");
    while (query.next()) {
        Parking p;
        p.fromQuery(&query);
        parkings.append(p);
    }
    int p1 = 0;
    int p2 = 0;
    for (Parking p : parkings) {
        switch (p.type) {
        case G::PARKING_TYPE_GROUND:
            p1++;
            break;
        case G::PARKING_TYPE_B1:
            p2++;
            break;
        case G::PARKING_TYPE_B2:
            p2++;
            break;
        default:
            break;
        }
    }
    ui->table_round->item(0, 0)->setText(QString::number(p1));
    ui->table_round->item(0, 1)->setText(QString::number(p2));

    // 显示参与人数和中签率
    if (G::ROUND == 1) {
        ui->table_round->item(1, 0)->setText(QString::number(G::R1));
        ui->table_round->item(2, 0)->setText(QString::number(100.0 * p1 / G::R1) + "%");
    }
    if (G::ROUND == 2) {
        ui->table_round->item(1, 1)->setText(QString::number(G::R2));
        ui->table_round->item(2, 1)->setText(QString::number(100.0 * p2 / G::R2) + "%");
    }
}

void LotteryPage::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    QImage bg("./img/bg.png");
    p.drawImage(this->rect(), bg, bg.rect());
}

void LotteryPage::on_btn_lottery_clicked()
{
    // 避免连击
    ui->btn_lottery->setEnabled(false);

    // 避免和抽奖操作冲突
    QMutexLocker locker(&_mutex);

    QSqlQuery query(DbConnector::instance->db);

    if (!_rolling) {
        if (ui->line_code->text().isEmpty()) {
            return;
        }

        // 获得code
        bool ok;
        int code = ui->line_code->text().toInt(&ok);
        if (!ok) {
            QMessageBox::information(this, "提示", "输入错误");
            ui->line_code->clear();
            return;
        }

        // 获得业主
        query.prepare("SELECT * FROM owners WHERE code = :code");
        query.bindValue(":code", code);
        query.exec();
        if (!query.next()) {
            QMessageBox::information(this, "提示", "未查到业主号");
            ui->line_code->clear();
            return;
        }

        _owner->fromQuery(&query);

        // 判断状态
        if (_owner->status == G::OWNER_STATUS_IDLE) {
            QMessageBox::information(this, "提示", "业主未激活");
            ui->line_code->clear();
            return;
        }

        if (_owner->status == G::OWNER_STATUS_FINISH) {
            QMessageBox::information(this, "提示", "业主已获得车位");
            ui->line_code->clear();
            return;
        }

        if (_owner->status != G::OWNER_STATUS_ACTIVE) {
            QMessageBox::information(this, "提示", "异常状态");
            ui->line_code->clear();
            return;
        }

        switch (G::ROUND) {
        case 1:
            if (_owner->r1 >= 0) {
                QMessageBox::information(this, "提示", "业主已参与第一轮摇号");
                ui->line_code->clear();
                return;
            }
            _owner->r1_time = QDateTime::currentDateTime();
            break;
        case 2:
            if (_owner->r2 >= 0) {
                QMessageBox::information(this, "提示", "业主已参与第二轮摇号");
                ui->line_code->clear();
                return;
            }
            _owner->r2_time = QDateTime::currentDateTime();
            break;
        default:
            QMessageBox::information(this, "提示", "轮次异常");
            ui->line_code->clear();
            return;
        }

        // 双车牌只能参与第三轮
        if (G::ROUND != 2 && !_owner->plate2.isEmpty()) {
            QMessageBox::information(this, "提示", "双车牌用户只能参加第二轮摇号");
            ui->line_code->clear();
            return;
        }

        ui->btn_lottery->setText("停止");

        _rolling = true;
    } else {
        // 结束摇号，记录状态
        _rolling = false;

        ui->btn_lottery->setText("开始");

        // 根据是否中签处理
        if (_ownerWin) {
            QMessageBox::information(this, "提示", "恭喜中签");

            // TODO 这个地方两表操作，没做事务，存在极低的故障风险
            switch (G::ROUND) {
            case 1:
                _owner->recordR1(&query);
                query.exec();
                break;
            case 2:
                _owner->recordR2(&query);
                query.exec();
                break;
            default:
                QMessageBox::information(this, "提示", "轮次异常");
                ui->line_code->clear();
                return;
            }

            // 在车位表中记录
            query.prepare("UPDATE parkings SET "
                          "status = :status, "
                          "owner_code = :owner_code "
                          "WHERE id = :id");
            query.bindValue(":status", G::PARKING_STATUS_UDED);
            query.bindValue(":owner_code", _owner->code);
            query.bindValue(":id", _owner->parking_id);
            query.exec();

            ui->line_code->clear();
        } else {
            QMessageBox::information(this, "提示", "未中签");

            switch (G::ROUND) {
            case 1:
                _owner->recordR1(&query);
                query.exec();
                break;
            case 2:
                _owner->recordR2(&query);
                query.exec();
                break;
            default:
                QMessageBox::information(this, "提示", "轮次异常");
                ui->line_code->clear();
                return;
            }
            ui->line_code->clear();
        }
    }
}

void LotteryPage::slt_timer()
{
    if (_rolling) {
        doRoll();
    }
    ui->btn_lottery->setEnabled(true);
}

void LotteryPage::doRoll()
{
    QMutexLocker locker(&_mutex);

    if (G::ROUND == 1) {
        QSqlQuery query(DbConnector::instance->db);
        // 准备业主
        QList<Owner> owners;
        query.exec("SELECT * FROM owners");
        while (query.next()) {
            Owner o;
            o.fromQuery(&query);
            owners.append(o);
        }
        // 进行摇号，先准备全量数据
        QList<Parking> parkings;
        query.exec("SELECT * FROM parkings WHERE type = " + QString::number(G::PARKING_TYPE_GROUND));
        while (query.next()) {
            Parking p;
            p.fromQuery(&query);
            parkings.append(p);
        }
        // 中签率
        double win_rate = 0;
        // 剩余的人数 freeOwner
        int freeOwners = 0;
        // 根据时间产生一个 0 ~ 1之间的随机数，和中签率比对
        double score = QRandomGenerator::global()->bounded(1.0);
        // 空闲车位列表
        QList<Parking> freeParkings;
        for (Parking p : parkings) {
            if (p.status == G::PARKING_STATUS_IDLE) {
                freeParkings.append(p);
            }
        }
        // 标记为因车位满导致的不可中签
        if (freeParkings.isEmpty()) {
            score = 10;
        } else {
            freeOwners = G::R1;
            for (Owner o : owners) {
                if (o.r1 >= 0) {
                    freeOwners -= 1;
                }
            }

            // 首中签率 = (当前轮次剩余的车位数 / 当前轮次剩余的业主数)
            // 0 ~ 1 的中签率，等于0则不可能中签，大于1则必中签
            win_rate = 1.0 * freeParkings.size() / freeOwners;
        }

        // 计入用户
        _owner->r1 = score;
        // 10000 * 车位数 + 人数
        _owner->r1_all = 10000 * freeParkings.size() + freeOwners;

        // 未中签
        if (score > win_rate) {
            _ownerWin = false;
            _owner->parking_id = -1;
            _owner->status = G::OWNER_STATUS_ACTIVE;
            // 提示，显示
            ui->table_result->clearContents();
            ui->table_result->setItem(0, 0, new QTableWidgetItem(QString::number(_owner->code)));
            ui->table_result->setItem(0, 1, new QTableWidgetItem("未中签"));
            return;
        }

        // 中签 获得随机车位
        int r = QRandomGenerator::global()->bounded(freeParkings.length());
        // 给车位，入库，弹提示
        Parking p = freeParkings.at(r);
        _owner->parking_id = p.id;
        _owner->status = G::OWNER_STATUS_FINISH;

        _ownerWin = true;
        // 提示，显示
        ui->table_result->clearContents();
        ui->table_result->setItem(0, 0, new QTableWidgetItem(QString::number(_owner->code)));
        ui->table_result->setItem(0, 1, new QTableWidgetItem("中签"));
        ui->table_result->setItem(0, 2, new QTableWidgetItem(G::parkingType(p.type)));
        ui->table_result->setItem(0, 3, new QTableWidgetItem(p.code));

        return;
    }
    if (G::ROUND == 2) {
        QSqlQuery query(DbConnector::instance->db);
        // 进行摇号，先准备全量数据
        QList<Parking> parkings;
        query.exec("SELECT * FROM parkings WHERE type = " + QString::number(G::PARKING_TYPE_B1));

        while (query.next()) {
            Parking p;
            p.fromQuery(&query);
            parkings.append(p);
        }

        query.clear();
        query.exec("SELECT * FROM parkings WHERE type = " + QString::number(G::PARKING_TYPE_B2));

        while (query.next()) {
            Parking p;
            p.fromQuery(&query);
            parkings.append(p);
        }

        // 首先统计中签率 = (当前轮次的车位数 / 当前轮次报名的业主数)
        // 0 ~ 1 的中签率，等于0则不可能中签，大于1则必中签
        double win_rate = 1.0 * parkings.size() / G::R2;

        // 根据时间产生一个 0 ~ 1之间的随机数，和中签率比对
        double score = QRandomGenerator::global()->bounded(1.0);
        // 空闲车位普通
        QList<Parking> freeParkings;
        for (Parking p : parkings) {
            if (p.status == G::PARKING_STATUS_IDLE && !p.is_mz) {
                freeParkings.append(p);
            }
        }
        // 空闲车位母子
        QList<Parking> freeParkingsMz;
        for (Parking p : parkings) {
            if (p.status == G::PARKING_STATUS_IDLE && p.is_mz) {
                freeParkingsMz.append(p);
            }
        }
        // 单车用户
        if (_owner->plate2.isEmpty()) {
            if (freeParkings.isEmpty()) {
                // 单车用户可用双车位，但优先使用单车位
                freeParkings = freeParkingsMz;
            }
            if (freeParkings.isEmpty()) {
                // 车位满
                score = 10;
            }
        }
        // 双车用户
        if (!_owner->plate2.isEmpty()) {
            freeParkings = freeParkingsMz;
            if (freeParkings.isEmpty()) {
                // 双车车位满
                score = 20;
            }
        }

        // 计入用户
        _owner->r2 = score;
        _owner->r2_all = G::R2;

        // 未中签
        if (score > win_rate) {
            _ownerWin = false;
            _owner->parking_id = -1;
            _owner->status = G::OWNER_STATUS_ACTIVE;
            // 提示，显示
            ui->table_result->clearContents();
            ui->table_result->setItem(0, 0, new QTableWidgetItem(QString::number(_owner->code)));
            ui->table_result->setItem(0, 1, new QTableWidgetItem("未中签"));
            return;
        }

        // 中签 获得随机车位
        int r = QRandomGenerator::global()->bounded(freeParkings.length());
        // 给车位，入库，弹提示
        Parking p = freeParkings.at(r);
        _owner->parking_id = p.id;
        _owner->status = G::OWNER_STATUS_FINISH;

        _ownerWin = true;
        // 提示，显示
        ui->table_result->clearContents();
        ui->table_result->setItem(0, 0, new QTableWidgetItem(QString::number(_owner->code)));
        ui->table_result->setItem(0, 1, new QTableWidgetItem("中签"));
        ui->table_result->setItem(0, 2, new QTableWidgetItem(G::parkingType(p.type)));
        ui->table_result->setItem(0, 3, new QTableWidgetItem(p.code));

        return;
    }
    QMessageBox::information(this, "提示", "轮次异常");
    return;
}
