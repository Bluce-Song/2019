/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     2.0
 * author:      SL
 * date:        2015.12.10
 * brief:       主界面
*******************************************************************************/
#ifndef MYTCPTHREAD_H
#define MYTCPTHREAD_H

#include <QDir>
#include <QFile>
#include <QTimer>
#include <QObject>
#include <QProcess>
#include <QHostInfo>
#include <QTcpSocket>
#include <QDataStream>
#include <QApplication>
#include <QNetworkInterface>
#include <QCryptographicHash>

#define NET "./network/"
#define TMP "./temp/"
#define CON "./config/"

class MyTcpThread : public QTcpSocket
{
    Q_OBJECT
public:
    explicit MyTcpThread(QObject *parent = 0);

signals:
    void TransformCmd(quint16 addr, quint16 cmd, QByteArray data);

private slots:
    void TcpInit(void);
    void Connected(void);
    void KeepAlive(void);
    void ReadBlock(void);
    void ReadFileHead(quint16 addr, QByteArray msg);
    void ReadFileData(quint16 addr, QByteArray msg);
    void WriteFileData(qint64 numBytes);
    void WriteBlock(quint16 addr, quint16 cmd, QByteArray data);
    void WriteFileHead(quint16 addr, quint16 cmd, QByteArray data);
    void ExcuteCmd(quint16 addr, quint16 cmd, QByteArray data);
    QString getHardwareAddress(void);
    void Error(QAbstractSocket::SocketError);
private:
    QTimer *timer;
    QString InitMsg;
    QProcess *process;

    QFile *file;
    QString fileName;
    QString fileDetail;

    qint64 count;
    qint64 loadSize;
    qint64 blockSize;
    qint64 bytesRead;
    qint64 bytesToRead;
    qint64 bytesToWrite;
    qint64 bytesWritten;
    QByteArray SendVerify;
    QByteArray RecvVerify;
};

#endif // MYTCPTHREAD_H
