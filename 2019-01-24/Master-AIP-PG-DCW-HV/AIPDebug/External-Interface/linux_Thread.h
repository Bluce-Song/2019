/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     2.0
 * author:      SL
 * date:        2015.12.10
 * brief:       主界面
*******************************************************************************/
#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include <QDir>
#include <QProcess>
#include <QDateTime>
#include <QSettings>
#include <define.h>

#define UEVENT_BUFFER_SIZE 2048

class MyThread : public QThread
{
    Q_OBJECT
private:
    char* p;
    static  int init_hotplug_sock();

    QString currentDateTime;
    QDir *temp;
    bool exist;
    QString keyname;
    QString Reset_Text;
    QString Board;

public:
    int fd;
    bool stop;
    explicit MyThread(QObject *parent = 0);
    void run();

signals:
    void Singal_U_Test(int, QString);

public slots:
    void Slot_Record_Error(int, QString);
};
#endif // MYTHREAD_H
