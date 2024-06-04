#include "resultpage.h"
#include "ui_resultpage.h"

#include "dbconnector.h"
#include "model.h"

ResultPage::ResultPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResultPage)
{
    ui->setupUi(this);

    setWindowTitle("结果显示页面");

    // 初始化table样式
    ui->table_parking->verticalHeader()->setVisible(false);
    ui->table_parking->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->table_parking->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->table_parking->setSelectionMode(QAbstractItemView::NoSelection);

    ui->table_owner->verticalHeader()->setVisible(false);
    ui->table_owner->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->table_owner->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->table_owner->setSelectionMode(QAbstractItemView::NoSelection);
}

ResultPage::~ResultPage()
{
    delete ui;
}

void ResultPage::on_btn_parking_clicked()
{
    // 清理数据
    ui->table_parking->setRowCount(0);

    // 获得所有的车位和业主
    QList<Parking> parkings;
    QList<Owner> owners;
    QHash<int, int> owners_index;   // code <-> index

    QSqlQuery query(DbConnector::instance->db);
    query.exec("SELECT * FROM parkings");
    while (query.next()) {
        Parking p;
        p.fromQuery(&query);
        parkings.append(p);
    }
    query.exec("SELECT * FROM owners");
    while (query.next()) {
        Owner o;
        o.fromQuery(&query);
        owners.append(o);
        owners_index.insert(o.code, owners.length() - 1);
    }

    // 循环刷进去 (顺便统计数据)
    int parking_idel = 0;
    int parking_used = 0;
    for (int x = 0; x < parkings.length(); x++) {
        Parking p = parkings.at(x);
        if (p.status == G::PARKING_STATUS_IDLE) {
            parking_idel++;
        } else if (p.status == G::PARKING_STATUS_UDED) {
            parking_used++;
        }
        ui->table_parking->insertRow(x);
        ui->table_parking->setItem(x, 0, new QTableWidgetItem(G::parkingType(p.type)));
        ui->table_parking->setItem(x, 1, new QTableWidgetItem(p.code));
        ui->table_parking->setItem(x, 2, new QTableWidgetItem(p.is_mz? "是": "否"));
        ui->table_parking->setItem(x, 3, new QTableWidgetItem(G::parkingStatus(p.status)));
        if (p.status == G::PARKING_STATUS_UDED) {
            Owner o = owners.at(owners_index.value(p.owner_code));
            ui->table_parking->setItem(x, 4, new QTableWidgetItem(QString::number(o.code)));
            ui->table_parking->setItem(x, 5, new QTableWidgetItem(o.room_code));
            ui->table_parking->setItem(x, 6, new QTableWidgetItem(o.name));
        }
    }

    ui->label_parking->setText(QString::asprintf("车位信息：已分配车位%d，未分配车位%d", parking_used, parking_idel));
}

void ResultPage::on_btn_owner_clicked()
{
    // 清理数据
    ui->table_owner->setRowCount(0);

    // 获得所有的车位和业主
    QHash<int, Parking> parkingMap;
    QList<Owner> owners;

    QSqlQuery query(DbConnector::instance->db);
    query.exec("SELECT * FROM parkings");
    while (query.next()) {
        Parking p;
        p.fromQuery(&query);
        parkingMap.insert(p.id, p);
    }
    query.exec("SELECT * FROM owners");
    while (query.next()) {
        Owner o;
        o.fromQuery(&query);
        owners.append(o);
    }

    // 往里刷
    int owner_idle = 0;
    int owner_active = 0;
    int owner_finish = 0;
    for (int x = 0; x < owners.length(); x++) {
        Owner o = owners.at(x);
        if (o.status == G::OWNER_STATUS_IDLE) {
            owner_idle++;
        } else {
            owner_active++;
        }
        if (o.status == G::OWNER_STATUS_FINISH) {
            owner_finish++;
        }

        ui->table_owner->insertRow(x);
        ui->table_owner->setItem(x, 0, new QTableWidgetItem(QString::number(o.code)));
        ui->table_owner->setItem(x, 1, new QTableWidgetItem(o.room_code));
        ui->table_owner->setItem(x, 2, new QTableWidgetItem(o.name));
        ui->table_owner->setItem(x, 3, new QTableWidgetItem(o.plate1));
        ui->table_owner->setItem(x, 4, new QTableWidgetItem(o.plate2));
        ui->table_owner->setItem(x, 5, new QTableWidgetItem(G::ownerStatus(o.status)));
        if (o.status == G::OWNER_STATUS_FINISH) {
            if (o.parking_id >= 0) {
                Parking p = parkingMap.value(o.parking_id);
                ui->table_owner->setItem(x, 6, new QTableWidgetItem(G::parkingType(p.type) + "-" + p.code));
            } else {
                ui->table_owner->setItem(x, 7, new QTableWidgetItem("未中签"));
            }
        }
    }

    ui->label_owner->setText(QString::asprintf("业主信息：未激活%d，已激活%d，已获得车位%d", owner_idle, owner_active, owner_finish));
}
