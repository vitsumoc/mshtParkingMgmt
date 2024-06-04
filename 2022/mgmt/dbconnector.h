#ifndef DBCONNECTOR_H
#define DBCONNECTOR_H

#include <QObject>
#include <QSqlDatabase>

class DbConnector : public QObject
{
    Q_OBJECT
public:
    explicit DbConnector(QObject *parent = nullptr);
    // 单例指针
    static DbConnector* instance;
    // 数据库连接
    QSqlDatabase db;
};

#endif // DBCONNECTOR_H
