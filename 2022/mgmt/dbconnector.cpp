#include <QtDebug>

#include "dbconnector.h"

DbConnector* DbConnector::instance = nullptr;

DbConnector::DbConnector(QObject *parent) : QObject(parent)
{
    // 单例
    DbConnector::instance = this;

    // 初始化数据库
    db = QSqlDatabase::addDatabase("QSQLITE", "db");
    db.setDatabaseName("./db/mshtPM.db");
    if (!db.open()) {
        qWarning() << "db open error!";
    }
}
