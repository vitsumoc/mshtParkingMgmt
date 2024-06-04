#ifndef MODEL_H
#define MODEL_H

#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QDateTime>

#include "constant.h"

// 车位类
class Parking {
public:
    int id = 0;
    QString code = "";                      // 编号
    int type = -1;                          // 车位类型码
    int status = G::PARKING_STATUS_IDLE;    // 状态码
    bool is_mz = false;                     // 是否母子车位
    int owner_code = -1;                    // 所属业主编号

    void fromQuery(QSqlQuery *query) {
        id = query->value("id").toInt();
        code = query->value("code").toString();
        type = query->value("type").toInt();
        status = query->value("status").toInt();
        is_mz = query->value("is_mz").toBool();
        owner_code = query->value("owner_code").toInt();
    }

    void toQuery(QSqlQuery *query) const {
        query->prepare("INSERT INTO parkings (code, type, status, is_mz, owner_code) "
                       "VALUES (:code, :type, :status, :is_mz, :owner_code)");
        query->bindValue(":code", code);
        query->bindValue(":type", type);
        query->bindValue(":status", status);
        query->bindValue(":is_mz", is_mz);
        query->bindValue(":owner_code", owner_code);
    }
};


// 业主类
class Owner {
public:
    int code = -1;                  // 编号
    QString room_code = "";         // 房间号
    QString name = "";              // 业主名
    QString phone = "";             // 手机号
    QString plate1 = "";                // 车牌号1
    QString plate2 = "";                // 车牌号2
    int status = G::OWNER_STATUS_IDLE;      // 摇号状态码
    int parking_id = -1;                    // 获得的车位号
    // 业务相关
    QDateTime active_time;                  // 激活时间
    QDateTime r1_time;                      // 摇号时间
    double r1;                              // 第一轮摇号值
    int r1_all;                             // 第一轮摇号池
    QDateTime r2_time;                      // 摇号时间
    double r2;                              // 第一轮摇号值
    int r2_all;                             // 第一轮摇号池
    QDateTime r3_time;                      // 摇号时间
    double r3;                              // 第一轮摇号值
    int r3_all;                             // 第一轮摇号池

    void fromQuery(QSqlQuery *query) {
        code = query->value("code").toInt();
        room_code = query->value("room_code").toString();
        name = query->value("name").toString();
        phone = query->value("phone").toString();
        plate1 = query->value("plate1").toString();
        plate2 = query->value("plate2").toString();
        status = query->value("status").toInt();
        parking_id = query->value("parking_id").toInt();
        active_time = query->value("active_time").toDateTime();
        r1_time = query->value("r1_time").toDateTime();
        r1 = query->value("r1").toDouble();
        r1_all = query->value("r1_all").toInt();
        r2_time = query->value("r2_time").toDateTime();
        r2 = query->value("r2").toDouble();
        r2_all = query->value("r2_all").toInt();
        r3_time = query->value("r3_time").toDateTime();
        r3 = query->value("r3").toDouble();
        r3_all = query->value("r3_all").toInt();
    }

    void toQuery(QSqlQuery *query) const {
        query->prepare("INSERT INTO owners (code, room_code, name, phone, plate1, plate2, status, parking_id, r1, r2, r3) "
                      "VALUES (:code, :room_code, :name, :phone, :plate1, :plate2, :status, :parking_id, :r1, :r2, :r3)");
        query->bindValue(":code", code);
        query->bindValue(":room_code", room_code);
        query->bindValue(":name", name);
        query->bindValue(":phone", phone);
        query->bindValue(":plate1", plate1);
        query->bindValue(":plate2", plate2);
        query->bindValue(":status", status);
        query->bindValue(":parking_id", parking_id);
        query->bindValue(":r1", -1.0);
        query->bindValue(":r2", -1.0);
        query->bindValue(":r3", -1.0);
    }

    void recordR1(QSqlQuery *query) {
        query->prepare("UPDATE owners SET "
                      "status = :status, "
                      "parking_id = :parking_id, "
                      "r1_time = :r1_time, "
                      "r1 = :r1, "
                      "r1_all = :r1_all "
                      "WHERE code = :code");
        query->bindValue(":status", status);
        query->bindValue(":parking_id", parking_id);
        query->bindValue(":r1_time", r1_time);
        query->bindValue(":r1", r1);
        query->bindValue(":r1_all", r1_all);
        query->bindValue(":code", code);
    }

    void recordR2(QSqlQuery *query) {
        query->prepare("UPDATE owners SET "
                      "status = :status, "
                      "parking_id = :parking_id, "
                      "r2_time = :r2_time, "
                      "r2 = :r2, "
                      "r2_all = :r2_all "
                      "WHERE code = :code");
        query->bindValue(":status", status);
        query->bindValue(":parking_id", parking_id);
        query->bindValue(":r2_time", r2_time);
        query->bindValue(":r2", r2);
        query->bindValue(":r2_all", r2_all);
        query->bindValue(":code", code);
    }

    void recordR3(QSqlQuery *query) {
        query->prepare("UPDATE owners SET "
                      "status = :status, "
                      "parking_id = :parking_id, "
                      "r3_time = :r3_time, "
                      "r3 = :r3, "
                      "r3_all = :r3_all "
                      "WHERE code = :code");
        query->bindValue(":status", status);
        query->bindValue(":parking_id", parking_id);
        query->bindValue(":r3_time", r3_time);
        query->bindValue(":r3", r3);
        query->bindValue(":r3_all", r3_all);
        query->bindValue(":code", code);
    }
};
#endif
