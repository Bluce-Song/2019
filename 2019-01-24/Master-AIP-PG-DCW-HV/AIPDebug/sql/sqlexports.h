/*******************************************************************************
 * Copyright [2016]   <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     2.0.7.1
 * author:      sl
 * brief:       头文件
*******************************************************************************/
#ifndef SQLEXPORTS_H
#define SQLEXPORTS_H

#include <QObject>
#include <QFile>
#include <QTimer>
#include <QDebug>
#include <QWidget>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlDatabase>
#include <QElapsedTimer>
#include <QSqlQueryModel>
#include <QTextCodec>
#include <QSqlTableModel>
#include <QMessageBox>

#ifdef __arm__
#define LENTH 10000
#else
#define LENTH 10000
#endif

class SqlExports : public QObject
{
    Q_OBJECT
public:
    explicit SqlExports(QObject *parent = 0);
    ~SqlExports();

signals:
    void sendSqlMap(QVariantMap msg);
private slots:
    QByteArray ToGbk(const QString &inStr);
    void recvSqlMap(QVariantMap msg);
    int exportFile();
    int createFile();
    int selectNumb();
    int selectItem();
    int exportHead();
    int exportData();
    void showText(QString err);
private:
    QSqlDatabase db;
    int timeOut;
    int quan;
    QString fileName;
    QList<int> numbs;
    QFile *file;
    QVariantMap tmpDat;
    QVariantMap tmpMap;
};

#endif // SQLEXPORTS_H
