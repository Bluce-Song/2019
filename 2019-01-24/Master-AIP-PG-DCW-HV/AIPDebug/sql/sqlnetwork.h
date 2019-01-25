/*******************************************************************************
 * Copyright [2016]   <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     2.0.7.1
 * author:      sl
 * brief:       头文件
*******************************************************************************/
#ifndef SQLNETWORK_H
#define SQLNETWORK_H

#include <QLabel>
#include <QDebug>
#include <QWidget>
#include <QLayout>
#include <QShowEvent>
#include <QTableView>
#include <QHeaderView>
#include <QPushButton>
#include <QMessageBox>

#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlTableModel>

#include "sqlsnowuid.h"

class SqlNetwork : public QWidget
{
    Q_OBJECT
public:
    explicit SqlNetwork(QWidget *parent = 0);
    ~SqlNetwork();
private slots:
    void initUI();
    void initView();
    void initText();
    void initLayout();
    void createSqlite();
    void updateSqlite();
    void insertSqlite();
    void changeSqlite();
    virtual void showEvent(QShowEvent *e);
    void recvSqlMap(QVariantMap msg);
private:
    QHBoxLayout *btnLayout;

    QString sqlName;
    QTableView *view;
    QSqlTableModel *mView;
};

#endif // SQLNETWORK_H
