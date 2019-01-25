/*******************************************************************************
 * Copyright [2016]   <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     2.0.7.1
 * author:      sl
 * brief:       头文件
*******************************************************************************/
#ifndef SQLIMPORTS_H
#define SQLIMPORTS_H

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

typedef struct {
    QString m_item;
    QString m_para;
    QString m_result;
    QString m_judge;
    QString m_b1;
}ResData;

class SqlImports : public QObject
{
    Q_OBJECT
public:
    explicit SqlImports(QObject *parent = 0);

signals:

private slots:
    void recvSqlImports(QByteArray msg);
    int getItemNumber(QString msg);
private:
    QSqlDatabase db;
    int count;
    int m_count;
    QString code;
    QMap<int, QStringList> tmpMap;
    QMap<int, int> items;
    QStringList tmpList;
};

#endif // SQLIMPORTS_H
