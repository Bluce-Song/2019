/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     2.0
 * author:      SL
 * date:        2015.12.10
 * brief:       主界面
*******************************************************************************/
// Serial.h: interface for the CSerial class.
//
//////////////////////////////////////////////////////////////////////
#ifndef _SERIAL_H
#define _SERIAL_H

#include <pthread.h>
#include <QApplication>
#include <QDebug>


class CSerial: public QObject
{
    Q_OBJECT
private:
    pthread_t  m_thread;
    static int ReceiveThreadFunc(void* lparam);
public:
    CSerial();
    virtual ~CSerial();
    int m_fd;
    pthread_mutex_t mutex;


    int  m_DatLen;
    char DatBuf[1500];

    int  m_ExitThreadFlag;

    int  OpenPort(char *PortNo, int baudrate, char databits, char stopbits, char parity);
    int  ClosePort();
    int  WritePort(char* Buf, int len);
    virtual int PackagePro(char* Buf, int len);

signals:
    void readyRead(QString);
};

#endif
