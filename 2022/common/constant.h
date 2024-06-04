#ifndef CONSTANT_H
#define CONSTANT_H
// 描述系统中所有的枚举类

#include <QString>

namespace G {
    // 当前轮次
    extern int ROUND;

    // 三轮参与人数
    extern int R1;
    extern int R2;

    // 超管密码
    static const QString PASSWORD = "654123";   // 数据管理密码

    // 车位类型
    static const int PARKING_TYPE_GROUND = 1;   // 地面
    static const int PARKING_TYPE_B1 = 2;       // 负一层
    static const int PARKING_TYPE_B2 = 3;       // 负二层
    // 车位类型字符串(Excel解析用)
    static const QString PARKING_TYPE_GROUND_S = "地面";
    static const QString PARKING_TYPE_B1_S = "负一层";
    static const QString PARKING_TYPE_B2_S = "负二层";

    // 车位状态
    static const int PARKING_STATUS_IDLE = 1;       // 车位状态空闲
    static const int PARKING_STATUS_UDED = 2;       // 车位状态已用

    // 车位状态字符(显示用)
    static const QString PARKING_STATUS_IDLE_S = "未分配";       // 车位状态空闲
    static const QString PARKING_STATUS_UDED_S = "已分配";       // 车位状态已用

    // 业主状态
    static const int OWNER_STATUS_IDLE = 1;         // 业主状态空闲
    static const int OWNER_STATUS_ACTIVE = 2;       // 业主状态已激活
    static const int OWNER_STATUS_FINISH = 3;       // 业主状态已中签

    static QString parkingType(int type) {
        switch (type) {
        case PARKING_TYPE_GROUND:
            return PARKING_TYPE_GROUND_S;
        case PARKING_TYPE_B1:
            return PARKING_TYPE_B1_S;
        case PARKING_TYPE_B2:
            return PARKING_TYPE_B2_S;
        default:
            return "";
        }
    }

    static int parkingType(QString type) {
        if (type == PARKING_TYPE_GROUND_S) {
            return PARKING_TYPE_GROUND;
        } else if (type == PARKING_TYPE_B1_S) {
            return PARKING_TYPE_B1;
        } else if (type == PARKING_TYPE_B2_S) {
            return PARKING_TYPE_B2;
        } else {
            return -1;
        }
    }

    static QString parkingStatus(int status) {
        switch (status) {
        case PARKING_STATUS_IDLE:
            return PARKING_STATUS_IDLE_S;
        case PARKING_STATUS_UDED:
             return PARKING_STATUS_UDED_S;
        default:
             return "";
        }
    }

    static QString ownerStatus(int status) {
        switch (status) {
        case OWNER_STATUS_IDLE:
            return "未激活";
        case OWNER_STATUS_ACTIVE:
            return "已激活";
        case OWNER_STATUS_FINISH:
            return "已获得车位";
        default:
            return "";
        }
    }
}
#endif
