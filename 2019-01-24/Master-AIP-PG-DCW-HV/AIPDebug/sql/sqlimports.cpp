/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "sqlimports.h"

SqlImports::SqlImports(QObject *parent) : QObject(parent)
{
    //    QSqlQuery query(QSqlDatabase::database(sqliteName));
    //    quint64 uuid = snow.getId();

    //    query.prepare("insert into aip_record values(?,?,?,?,?,?,?,?,?)");
    //    query.addBindValue(uuid);
    //    query.addBindValue(QDate::currentDate().toString("yyyy-MM-dd"));
    //    query.addBindValue(QTime::currentTime().toString("hh:mm:ss"));
    //    query.addBindValue(msg.value("temp").toString());
    //    query.addBindValue(msg.value("post").toString());
    //    query.addBindValue(msg.value("type").toString());
    //    query.addBindValue(msg.value("numb").toString());
    //    query.addBindValue(msg.value("usrs").toString());
    //    query.addBindValue(msg.value("pass").toString());
    //    query.exec();

    //    QStringList content = msg.value("data").toString().split("\n");
    //    items.clear();
    //    for (int i=0; i < content.size(); i++) {
    //        QStringList temp = QString(content.at(i)).split("@");
    //        if (temp.size() >= 4) {
    //            int numb = getNumber(temp.at(0));
    //            query.prepare("insert into aip_records values(?,?,?,?,?,?,?)");
    //            query.addBindValue(uuid);
    //            query.addBindValue(snow.getId());
    //            query.addBindValue(QString::number(numb));
    //            query.addBindValue(temp.at(0));
    //            query.addBindValue(temp.at(1));
    //            query.addBindValue(temp.at(2));
    //            query.addBindValue(temp.at(3));
    //            query.exec();
    //        }
    //    }
}

void SqlImports::recvSqlImports(QByteArray msg)
{
    /*   QStringList dat = QString(msg).split("@");
    if (dat.size() == 4) {
        tmpList.append(dat);
    }
    if (dat.size() == 3) {
        if (dat.at(0) == QString(tr("总数"))) {
            count++;
            str_ResData.m_item = dat.at(0);
            str_ResData.m_para = dat.at(1);
            str_ResData.m_result = dat.at(2);
            dateList.append(str_ResData);
            for (int i = 0; i < dateList.size(); i++) {
                ResData m_strData;
                m_strData = dateList.at(i);

                memset(sSql, 0, 2048);
                max++;
                sprintf(sSql, "insert into aip_%s(id,item,para,result,judge,b1,b2,b3)\
                        values(%d, '%s', '%s', '%s', '%s', '%s', '%d', '%s')"\
                        , str.toLocal8Bit().data(), max, m_strData.m_item.toLocal8Bit().data()\
                        , m_strData.m_para.toLocal8Bit().data()\
                        , m_strData.m_result.toLocal8Bit().data(), m_strData.m_judge.toLocal8Bit().data()\
                        , str_ResData.m_para.toLocal8Bit().data(), count\
                        , dateTime_str.toLocal8Bit().data());
                err = query.exec(sSql);
                memset(sSql, 0, 2048);
            }
            dateList.clear();
        }

        viewSql(dat);
    } else {
        str_ResData.m_item = dat.at(0);
        str_ResData.m_para = dat.at(1);
        str_ResData.m_result = dat.at(2);
        str_ResData.m_judge = dat.at(3);
        dateList.append(str_ResData);
    } */
}

int SqlImports::getItemNumber(QString msg)
{
    int numb = 0;
    int item = 0;
    QStringList names;
    names << "电阻" << "反嵌" << "绝缘" << "交耐" << "直耐"
          << "匝间" << "电参" << "电感" << "堵转" << "低启"
          << "霍尔" << "负载" << "空载" << "反势";
    for (int i=0; i < names.size(); i++) {
        if (msg.startsWith(names.at(i))) {
            item = i+1;
            break;
        }
    }
    names.clear();
    names << "电阻" << "反嵌" << "绝缘" << "交耐" << "直耐"
          << "匝间" << "电参" << "电感" << "堵转" << "低启"
          << "FG" << "负载" << "空载" << "BEMF";
    for (int i=0; i < names.size(); i++) {
        if (msg.startsWith(names.at(i))) {
            item = i+1;
            break;
        }
    }
    if (item == 0) {
        if (msg.startsWith("-电阻-")) {
            numb = 0x1080;
        } else if (msg.startsWith("磁旋")) {
            numb = 0x2080;
        } else if (msg.startsWith("转向")) {
            numb = 0x7080;
        } else if (msg.startsWith("-电感-")) {
            numb = 0x8080;
        } else if (msg.startsWith("Q")) {
            numb = 0x80A0;
        } else {
            numb = 0x0080;
        }
    } else {
        items[item]++;
        numb = 256*item + items[item];
    }

    return numb;
}

