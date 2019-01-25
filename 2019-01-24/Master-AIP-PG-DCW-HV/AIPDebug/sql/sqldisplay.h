/*******************************************************************************
 * Copyright [2016]   <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     2.0.7.1
 * author:      sl
 * brief:       头文件
*******************************************************************************/
#ifndef SQLDISPLAY_H
#define SQLDISPLAY_H

#include <QLabel>
#include <QDebug>
#include <QWidget>
#include <QLayout>
#include <QDateEdit>
#include <QComboBox>
#include <QTableView>
#include <QHeaderView>
#include <QPushButton>
#include <QElapsedTimer>
#include <QMessageBox>
#include <QShowEvent>

#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlTableModel>

class SqlDisplay : public QWidget
{
    Q_OBJECT
public:
    explicit SqlDisplay(QWidget *parent = 0);
    ~SqlDisplay();
signals:
    void sendSqlMap(QVariantMap msg);
private slots:
    void initUI();
    void initView();
    void initText();
    void initButton();
    void initLayout();
    void recvSelect();
    void recvExport();
    void recvDetail();
    void picture_Export();
    void clickIndex(QModelIndex index);
    void updateSqlite(QVariantMap msg);
    void recvSqlMap(QVariantMap msg);
    virtual void showEvent(QShowEvent *e);
private:
    QComboBox *type;
    QDateEdit *from;
    QDateEdit *stop;
    QHBoxLayout *txtLayout;
    QHBoxLayout *btnLayout;

    QString sqlName;
    QTableView *view;
    QSqlTableModel *mView;

    QTableView *item;
    QSqlTableModel *mItem;

    QVariantMap tmpMap;
    QVariantMap tmpExp;

    QPushButton *btnExport;
};

#endif // SQLDISPLAY_H
