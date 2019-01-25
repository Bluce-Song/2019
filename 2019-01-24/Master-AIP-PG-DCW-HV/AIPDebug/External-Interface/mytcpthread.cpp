/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "mytcpthread.h"

MyTcpThread::MyTcpThread(QObject *parent) :
    QTcpSocket(parent) {
    count        = 0;
    loadSize     = 4 * 1024;;
    blockSize    = 0;
    bytesRead    = 0;
    bytesToRead  = 0;
    bytesToWrite = 0;
    bytesWritten = 0;

    QDir *dir = new QDir;
    if (!dir->exists(QString(TMP)))
        dir->mkdir(QString(TMP));
    if (!dir->exists(QString(NET)))
        dir->mkdir(QString(NET));

    process = new QProcess(this);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(KeepAlive()));
    connect(this, SIGNAL(connected()), this, SLOT(Connected()));
    connect(this, SIGNAL(readyRead()), this, SLOT(ReadBlock()));
    connect(this, SIGNAL(bytesWritten(qint64)), this, SLOT(WriteFileData(qint64)));
    connect(this, SIGNAL(error(QAbstractSocket::SocketError)), \
            this, SLOT(Error(QAbstractSocket::SocketError)));
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.07.16
  * brief:      网络初始化
******************************************************************************/
void MyTcpThread::TcpInit()
{
    count = 0;
    QString hostName = "s.aipuo.com";
    //  qDebug() << "Connecting to host";
    this->connectToHost(hostName,  6000);
    timer->start(10000);
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.07.16
  * brief:      连接成功
******************************************************************************/
void MyTcpThread::Connected()
{
    ExcuteCmd(quint16(6000), quint16(1000), NULL);
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.07.16
  * brief:      心跳
******************************************************************************/
void MyTcpThread::KeepAlive()
{
    if (this->state() != QAbstractSocket::ConnectedState) {
        TcpInit();
    } else {
        WriteBlock(6000, 6000, "NULL");
        count++;
        if (count >10) {
            qDebug()  <<  "no respond from host";
            this->abort();
        }
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.07.16
  * brief:      读取数据
******************************************************************************/
void MyTcpThread::ReadBlock()
{
    quint16 addr;
    quint16 cmd;
    QByteArray msg;
    QDataStream in(this);
    in.setVersion(QDataStream::Qt_4_8);
    while (1) {
        if (blockSize == 0) {
            if (this->bytesAvailable() < qint64(sizeof(qint64)))
                return;
            in >> blockSize;
        }
        if (blockSize > 8*1024) {
            qDebug()  <<  "block size overflow";
            this->abort();
            return;
        }
        if (this->bytesAvailable() < blockSize)
            return;
        in >> addr >> cmd >> msg;
        ExcuteCmd(addr, cmd, msg);
        blockSize = 0;
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.07.16
  * brief:      读取文件头
******************************************************************************/
void MyTcpThread::ReadFileHead(quint16 addr, QByteArray msg)
{
    SendVerify = msg.mid(0, 16);
    QString temp = msg.remove(0, 17);
    QStringList detail = temp.split(" ");
    bytesToRead = detail.at(0).toInt();
    bytesRead = 0;
    file = new QFile(QString(TMP).append(detail.at(1)));
    if (file->open(QFile::ReadWrite)) {
      //
    } else {
        WriteBlock(addr, 2003, "NULL");
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.07.16
  * brief:      读取文件
******************************************************************************/
void MyTcpThread::ReadFileData(quint16 addr, QByteArray msg)
{
    int ret;
    if (file->isOpen())
        ret = file->write(msg);
    else
        return;
    bytesRead += ret;
    if (bytesRead == bytesToRead) {
        file->seek(0);
        RecvVerify = QCryptographicHash::hash(file->readAll(), QCryptographicHash::Md5);
        file->close();
        bytesRead = 0;
        bytesToRead = 0;
        if (SendVerify == RecvVerify) {
            QProcess::execute("sync");
            QString cmd = QString("mv %1 %2").arg(file->fileName()).arg(NET);
            QProcess::execute(cmd);
            WriteBlock(addr, 2002, "NULL");
        } else {
            QString cmd = QString("rm %1").arg(file->fileName());
            QProcess::execute(cmd);
            WriteBlock(addr, 2003, "NULL");
        }
        return;
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.07.16
  * brief:      写数据
******************************************************************************/
void MyTcpThread::WriteBlock(quint16 addr,  quint16 cmd,  QByteArray data)
{
    QByteArray msg;
    QDataStream out(&msg,  QIODevice::ReadWrite);
    out.setVersion(QDataStream::Qt_4_8);
    out << (qint64)0  <<  quint16(addr) << quint16(cmd) << data;
    out.device()->seek(0);
    out << (qint64)(msg.size()-sizeof(qint64));
    this->write(msg);
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.07.16
  * brief:      发送文件头
******************************************************************************/
void MyTcpThread::WriteFileHead(quint16 addr,  quint16 cmd,  QByteArray data)
{
    QString name = data;
    file = new QFile(name);
    if (!file->open(QFile::ReadOnly)) {
        WriteBlock(6000, 1003, QString(tr("获取失败:%1")).arg(file->errorString()).toUtf8());
        return;
    }
    QByteArray msg;
    msg.append(QCryptographicHash::hash(file->readAll(), QCryptographicHash::Md5));
    file->seek(0);
    msg.append(QString(" %1 ").arg(file->size()));
    msg.append(name.right(name.size()- name.lastIndexOf('/')-1));
    WriteBlock(addr, cmd, msg);
    bytesToWrite = file->size();
    bytesWritten = 0;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.07.16
  * brief:      发送文件
******************************************************************************/
void MyTcpThread::WriteFileData(qint64 numBytes)
{
    if (bytesToWrite == 0)
        return;
    bytesWritten += (int)numBytes;
    WriteBlock(quint16(6000), quint16(2001), file->read(loadSize));
    bytesToWrite -= (int)qMin(bytesToWrite, loadSize);

    if (bytesToWrite == 0)
        file->close();
    count = 0;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.07.16
  * brief:      命令执行
******************************************************************************/
void MyTcpThread::ExcuteCmd(quint16 addr,  quint16 cmd,  QByteArray data)
{
    timer->stop();
    count = 0;
    switch (cmd) {
    case 1000:
        InitMsg.clear();
        InitMsg.append(tr("测试号 "));
        InitMsg.append(getHardwareAddress());
        InitMsg.append(" V-1.0");
        WriteBlock(quint16(addr), quint16(cmd), InitMsg.toUtf8());
        emit TransformCmd(8, 8, this->errorString().toUtf8());
        break;
    case 1001: // 下线退出
        emit TransformCmd(addr, cmd, data);
        break;
    case 1002: // 获取文件
        WriteFileHead(addr, 2000, data);
        break;
    case 1003: // 获取失败
        break;
    case 1004: // 启动测试
        break;
    case 1005: // 停止测试
        break;
    case 1006: // 测试数据
        break;
    case 1007: //
        break;
    case 2000:
        ReadFileHead(addr, data);
        break;
    case 2001:
        ReadFileData(addr, data);
        break;
    case 2002:
        //
        break;
    case 2003:
        //
        break;
    case 2004: // 执行命令
        process->start(data);
        process->waitForFinished();
        WriteBlock(quint16(addr), 2005, process->readAll());
        break;
    case 2005: // 命令回显
        break;
    case 6000:
        break;
    default:
        //
        break;
    }
    timer->start(10000);
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.07.16
  * brief:      获取硬件地址
******************************************************************************/
QString MyTcpThread::getHardwareAddress()
{
    int i;
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
    for (i = 0; i < list.size(); i++) {
        if (list[i].name() == "eth0")
            return list[i].hardwareAddress();
    }
    return list[1].hardwareAddress();
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.07.16
  * brief:      输出错误信息
******************************************************************************/
void MyTcpThread::Error(QAbstractSocket::SocketError socketError)
{
    if (socketError == QAbstractSocket::RemoteHostClosedError)
        return;
    emit TransformCmd(10, 10, this->errorString().toUtf8());
    this->close();
}
