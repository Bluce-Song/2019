/*******************************************************************************
 * Copyright [2016]   <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     2.0.7.1
 * author:      sl
 * brief:       头文件
*******************************************************************************/
#ifndef SQLDESKTOP_H
#define SQLDESKTOP_H

#include <QDir>
#include <QFile>
#include <QDebug>
#include <QLabel>
#include <QLayout>
#include <QWidget>
#include <QThread>
#include <QProcess>
#include <QDateTime>
#include <QFileDialog>
#include <QPushButton>
#include <QMessageBox>
#include <QElapsedTimer>
#include <QStackedWidget>
#include <QProgressDialog>

#include "sqldisplay.h"
#include "sqlnetwork.h"
#include "sqlexports.h"
#include "sqlsnowuid.h"
#include "sqlhistory.h"
#include "sqlproduct.h"

#define WIDTH  111
#define Heigth 51

#define SD_SIZE 20000

class SqlDesktop : public QWidget
{
    Q_OBJECT
public:
    explicit SqlDesktop(QWidget *parent = 0);
    ~SqlDesktop();
signals:
    void sendAppMsg(QVariantMap msg);
    void sendSqlMap(QVariantMap msg);
    void Signal_Data_to_Main(QStringList, int, int);

private slots:
    void initUI();
    void initDir();
    void initSql();
    void initLayout();
    void initSqlDisplay();
    void initSqlProduct();
    void initSqlNetwork();
    void initSqlHistory();
    void initSqlExports();
    void initSqlSignOut();
    void sendSqlExports(QVariantMap msg);
    void sendSqlExports_picture(QVariantMap msg);
    void initProgressBar();
    void updateSqlExport();
    void createSqlRecord();
    void backupSqlRecord();
    void updateSqlMessage();
    void clickButton();
    bool existsSdcardDisk();
    QString existsFlashDisk();
    void deleteFlashDisk();
    void recvQuan(QVariantMap msg);
    void recvOver(QVariantMap msg);
    void recvSqlMap(QVariantMap msg);
    void recvSqlDat(QVariantMap msg);
    int  getNumber(QString numb);
    void widget_hide();
private:
    QStackedWidget *stack;
    QVBoxLayout *btnLayout;
    QList<QPushButton*> buttons;
    QVariantMap tmpMap;
    QThread *thread;
    QProgressDialog *pBar;
    QTimer *timer;
    int time;
    int quan;
    QLabel *text;
    QMap<int, int> items;
    QElapsedTimer t;
    QMessageBox *box;
    QTimer *timerb;
};

#endif // SQLDESKTOP_H
