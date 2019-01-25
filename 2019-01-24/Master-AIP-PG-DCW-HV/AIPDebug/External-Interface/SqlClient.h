/*******************************************************************************
 * Copyright [2016]   <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     2.1.0.170427
 * author:      zhaonanlin
 * brief:       SQL处理模块
*******************************************************************************/
#ifndef SQLCLIENT_H
#define SQLCLIENT_H

#include <QFile>
#include <QDate>
#include <QTime>
#include <QDebug>
#include <QObject>
#include <QVariant>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QStringList>
#include <QList>

#include "define.h"

typedef struct {
    QString m_item;
    QString m_para;
    QString m_result;
    QString m_judge;
    QString m_b1;
}ResData;

class SqlClient : public QObject
{
    Q_OBJECT
public:
    explicit SqlClient(QObject *parent = 0);

    void viewSql(QStringList qs);
    void typeSql(QString qs);
    QList<ResData> dateList;

private slots:
    void DeviceOpen();
    void DeviceQuit(void);
    void Write(QByteArray msg);

private:
    QSqlDatabase db;
    int count;
    int m_count;
    QString code;
};

#endif // SQLCLIENT_H
