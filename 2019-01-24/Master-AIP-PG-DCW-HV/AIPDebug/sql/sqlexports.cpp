/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "sqlexports.h"

SqlExports::SqlExports(QObject *parent) : QObject(parent)
{
}

SqlExports::~SqlExports()
{
}

void SqlExports::recvSqlMap(QVariantMap msg)
{
    switch (msg.value("enum").toInt()) {
    case QMessageBox::Apply:
        tmpDat = msg;
        if (exportFile() == -1) {
            tmpMap.insert("enum", QMessageBox::Abort);
        } else {
            tmpMap.insert("enum", QMessageBox::Close);
        }
        emit sendSqlMap(tmpMap);
        tmpMap.clear();
        break;
    case QMessageBox::Abort:
        break;
    default:
        break;
    }
}

int SqlExports::exportFile()
{
    QElapsedTimer t;
    t.start();
    if (createFile() == -1)
        return -1;
    if (selectNumb() == -1)
        return-1;
    if (selectItem() == -1)
        return-1;
    if (exportHead() == -1)
        return-1;
    if (exportData() == -1)
        return-1;
    file->close();
    showText(tr("写入成功,实际用时%1ms").arg(t.elapsed()));
    return 0;
}

int SqlExports::createFile()
{
    file = new QFile(QString("%1").arg(tmpDat.value("path").toString()));
    if (!file->open(QFile::WriteOnly)) {
        showText(tr("文件打开失败"));
        return -1;
    }
    return 0;
}

int SqlExports::selectNumb()
{
    QSqlQuery query(QSqlDatabase::database(tmpDat.value("name").toString()));
    QString cmd;
    cmd = "select count(*) from aip_record where numb=0";
    if (!tmpDat.value("from").isNull()) {
        cmd += tr(" and uuid>=%1").arg(tmpDat.value("from").toLongLong());
    }
    if (!tmpDat.value("stop").isNull()) {
        cmd += tr(" and uuid<=%1").arg(tmpDat.value("stop").toLongLong());
    }
    if (!tmpDat.value("rslt").isNull()) {
        cmd += tr(" and rslt='%1'").arg(tmpDat.value("rslt").toString());
    }
    if (!query.exec(cmd)) {
        showText(tr("查询数据失败,%1").arg(query.lastError().text()));
        return -1;
    }
    if (!query.next()) {
        showText(tr("查询数据失败,%1").arg(query.lastError().text()));
        return -1;
    }
    quan = query.value(0).toInt();
    tmpMap.insert("enum", QMessageBox::Question);
    tmpMap.insert("quan", quan);
    emit sendSqlMap(tmpMap);
    tmpMap.clear();
    return 0;
}

int SqlExports::selectItem()
{
    QSqlQuery query(QSqlDatabase::database(tmpDat.value("name").toString()));
    QString cmd;
    numbs.clear();
    cmd = tr("select distinct numb from aip_record where numb >= %1 ").arg(0x0100);
    if (!tmpDat.value("from").isNull()) {
        cmd += tr(" and uuid>=%1").arg(tmpDat.value("from").toLongLong());
    }
    if (!tmpDat.value("stop").isNull()) {
        cmd += tr(" and uuid<=%1").arg(tmpDat.value("stop").toLongLong());
    }
    if (!query.exec(cmd)) {
        showText(tr("查询数据失败,%1").arg(query.lastError().text()));
        return -1;
    }
    while (query.next()) {
        numbs.append(query.value(0).toInt());
    }
    return 0;
}

int SqlExports::exportHead()
{
    QStringList title;
    title << tr("日期") << tr("时间") << tr("型号") << tr("判定")
          << tr("用户") << tr("温度") << tr("工位") << tr("编码");
    QStringList names;
    names << "电阻" << "反嵌" << "绝缘" << "交耐" << "直耐"
          << "匝间" << "电参" << "电感" << "堵转" << "低启"
          << "霍尔" << "负载" << "空载" << "BEMF";
    QStringList other;
    other << tr("-电阻-") << tr("磁旋") << tr("x") << tr("x") << tr("x")
          << tr("x") << tr("转向") << tr("-电感-") << tr("Q值");

    qSort(numbs.begin(), numbs.end());

    for (int i=0; i < numbs.size(); i++) {
        QString name;
        int t = numbs.at(i)%256;
        int n = numbs.at(i)/256;
        if (t < 0x80) {
            name = names.at(n-1);
            title.append(QString("%1项目%2").arg(name).arg(t));
            title.append(QString("%1参数%2").arg(name).arg(t));
            title.append(QString("%1结果%2").arg(name).arg(t));
            title.append(QString("%1判定%2").arg(name).arg(t));
        } else {
            if (n < other.size())
                name = other.at(n-1);
            else
                name = tr("其他");
            if (numbs.at(i) == 0x0181) {
                name = tr("电阻-2");
            }
            if (numbs.at(i) == 0x0281) {
                name = tr("磁旋-2");
            }
            title.append(QString("%1项目").arg(name));
            title.append(QString("%1参数").arg(name));
            title.append(QString("%1结果").arg(name));
            title.append(QString("%1判定").arg(name));
        }
    }
    file->write(ToGbk(title.join(",")));
    file->write("\n");
    return 0;
}

int SqlExports::exportData()
{
    QSqlQuery query(QSqlDatabase::database(tmpDat.value("name").toString()));
    QString cmd;
    quint64 uuid = tmpDat.value("from").toLongLong();
    QStringList groupBuffer;
    QStringList lineBuffer;
    QMap<int, QString> buffer;
    for (int i=0; i < numbs.size(); i++) {
        buffer[numbs.at(i)] = QString(",,,");
    }
    QMap<int, QString> tempBuffer = buffer;
    int t = 0;
    if (tmpDat.value("stop").isNull()) {
        while (1) {
            cmd = tr("select * from aip_record where guid > %1").arg(uuid);
            if (!query.exec(cmd)) {
                qDebug() << query.lastError();
                showText(tr("查询数据失败,%1").arg(query.lastError().text()));
                return -1;
            }
            while (query.next()) {
                uuid = query.value(0).toULongLong();
                quint64 guid = query.value(1).toULongLong();
                int numb = query.value(2).toInt();
                groupBuffer.clear();
                groupBuffer.append(query.value(3).toString());
                groupBuffer.append(query.value(4).toString());
                groupBuffer.append(query.value(5).toString());
                groupBuffer.append(query.value(6).toString());
                tempBuffer[numb] = groupBuffer.join(",");
                if (uuid == guid) {
                    foreach(int n, tempBuffer.keys()) {
                        lineBuffer.append(tempBuffer[n]);
                    }
                    file->write(ToGbk(lineBuffer.join(",")));
                    file->write("\n");
                    lineBuffer.clear();
                    tempBuffer = buffer;
                    t++;
                    if (t%LENTH == 0)
                        break;
                }
            }
//            query.clear();
            showText(tr("已导出%1/%2").arg(t).arg(quan));
            if (t >= quan || !query.next())
                break;
        }
    } else if (tmpDat.value("rslt").isNull()) {
        quint64 tuid = tmpDat.value("stop").toLongLong();
        while (1) {
            cmd = tr("select * from aip_record where guid > %1 and guid < %2").arg(uuid).arg(tuid);
            if (!query.exec(cmd)) {
                qDebug() << query.lastError();
                showText(tr("查询数据失败,%1").arg(query.lastError().text()));
                return -1;
            }
            while (query.next()) {
                uuid = query.value(0).toULongLong();
                quint64 guid = query.value(1).toULongLong();
                int numb = query.value(2).toInt();
                groupBuffer.clear();
                groupBuffer.append(query.value(3).toString());
                groupBuffer.append(query.value(4).toString());
                groupBuffer.append(query.value(5).toString());
                groupBuffer.append(query.value(6).toString());
                tempBuffer[numb] = groupBuffer.join(",");
                if (uuid == guid) {
                    foreach(int n, tempBuffer.keys()) {
                        lineBuffer.append(tempBuffer[n]);
                    }
                    file->write(ToGbk(lineBuffer.join(",")));
                    file->write("\n");
                    lineBuffer.clear();
                    tempBuffer = buffer;
                    t++;
                    if (t%LENTH == 0)
                        break;
                }
            }
//            query.clear();
            showText(tr("已导出%1/%2").arg(t).arg(quan));
            if (t >= quan || !query.next())
                break;
        }
    } else {
        quint64 tuid = tmpDat.value("stop").toLongLong();
        QString rslt = tmpDat.value("rslt").toString();
        while (1) {
            cmd = tr("select * from aip_record where guid > %1 and guid < %2").arg(uuid).arg(tuid);
            if (!query.exec(cmd)) {
                qDebug() << query.lastError();
                showText(tr("查询数据失败,%1").arg(query.lastError().text()));
                return -1;
            }
            while (query.next()) {
                uuid = query.value(0).toULongLong();
                quint64 guid = query.value(1).toULongLong();
                int numb = query.value(2).toInt();
                groupBuffer.clear();
                groupBuffer.append(query.value(3).toString());
                groupBuffer.append(query.value(4).toString());
                groupBuffer.append(query.value(5).toString());
                groupBuffer.append(query.value(6).toString());
                tempBuffer[numb] = groupBuffer.join(",");
                if (uuid == guid) {
                    foreach(int n, tempBuffer.keys()) {
                        lineBuffer.append(tempBuffer[n]);
                    }
                    if (query.value(5).toString() == rslt) {
                        file->write(ToGbk(lineBuffer.join(",")));
                        file->write("\n");
                    }
                    lineBuffer.clear();
                    tempBuffer = buffer;
                    t++;
                    if (t%LENTH == 0)
                        break;
                }
            }
//            query.clear();
            showText(tr("已导出%1/%2").arg(t).arg(quan));
            if (t >= quan || !query.next())
                break;
        }
    }

    return 0;
}

QByteArray SqlExports::ToGbk(const QString &inStr)
{
    QTextCodec *gbk = QTextCodec::codecForName("GB18030");
    return gbk->fromUnicode(inStr);
}

void SqlExports::showText(QString err)
{
    tmpMap.insert("enum", QMessageBox::Information);
    tmpMap.insert("text", err);
    emit sendSqlMap(tmpMap);
    tmpMap.clear();
}
