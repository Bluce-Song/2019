/*******************************************************************************
 * Copyright [2016]   <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     2.0.7.1
 * author:      sl
 * brief:       头文件
*******************************************************************************/
#ifndef SQLHISTORY_H
#define SQLHISTORY_H

#include <QLabel>
#include <QDebug>
#include <QWidget>
#include <QLayout>
#include <QDateEdit>
#include <QShowEvent>
#include <QTableView>
#include <QHeaderView>
#include <QPushButton>
#include <QFileSystemModel>
#include <QMessageBox>

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlTableModel>

class SqlHistory : public QWidget
{
    Q_OBJECT
public:
    explicit SqlHistory(QWidget *parent = 0);
signals:
    void sendSqlMap(QVariantMap msg);
private slots:
    void initUI();
    void initView();
    void initButton();
    void initLayout();
    void updateFile();
    void recvExport();
    void recvDelete();
    virtual void showEvent(QShowEvent *e);
private:
    QTableView *view;
    QFileSystemModel *mView;
    QHBoxLayout *btnLayout;

    QDateEdit *from;
    QDateEdit *stop;
    QVariantMap tmpMap;
};

#endif // SQLHISTORY_H
