/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "linux_sql.h"

LINUX_SQL::LINUX_SQL(QWidget *parent) :
    QWidget(parent) {
    //
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.21
  * brief:      获取最大ID
******************************************************************************/
int LINUX_SQL::selectMax(QVariant table)
{
    int max_id = 0;
    QSqlQuery query(db);
    QString str = "select max(id) from :table";
    str.replace(":table", table.toString());
    if (!query.exec(str)) {
        qDebug() << query.lastError();
    } else {
        while (query.next()) {
            max_id = query.value(0).toInt();
        }
    }
    return max_id;
}
int LINUX_SQL::selectMax_net(QVariant table)
{
    int max_id = 0;
    QSqlQuery query(dbtwo);
    QString str = "select max(id) from :table";
    str.replace(":table", table.toString());
    if (!query.exec(str)) {
        qDebug() << query.lastError();
    } else {
        while (query.next()) {
            max_id = query.value(0).toInt();
        }
    }
    return max_id;
}
bool LINUX_SQL::open_net_Sql(QVariant sqldata)
{
    QString UserName, Password;
    QSettings set_Sys("/usr/local/arm/unixODBC/etc/odbc.ini", QSettings::IniFormat);
    UserName = set_Sys.value("testodbc/UserName").toString();
    Password = set_Sys.value("testodbc/Password").toString();
    dbtwo = QSqlDatabase::addDatabase("QODBC", "dbtwo");
    dbtwo.setDatabaseName(sqldata.toString());
    dbtwo.setUserName(UserName);
    dbtwo.setPassword(Password);
    return dbtwo.open();
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.21
  * brief:      打开数据库
******************************************************************************/
bool LINUX_SQL::openSql(QVariant sqldata)
{
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        db = QSqlDatabase::database("qt_sql_default_connection");
        //   db = QSqlDatabase::addDatabase("QSQLITE");
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE");
    }

    db.setDatabaseName(sqldata.toString());

    if (!db.open()) {
        qDebug() << db.lastError();
        return false;
    } else {
        return true;
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.21
  * brief:      关闭数据库
******************************************************************************/
bool LINUX_SQL::closeSql()
{
    db.close();
    return true;
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.21
  * brief:      创建表
******************************************************************************/
bool LINUX_SQL::createSql(QVariant table, QVariant param)
{
    QSqlQuery query(db);
    QString str("create table :table (id int primary key, :param)");

    str.replace(":table", table.toString());
    str.replace(":param", param.toString());
    if (!query.exec(str)) {
        qDebug() << query.lastError();
    }

    return 0;
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.21
  * brief:      添加项
******************************************************************************/
bool LINUX_SQL::insertSql(QVariant table, QVariant title, QVariant param, QVariant id)
{
    QSqlQuery query(db);
    QString str("insert into :table (id, :title)""values(:id, :param)");
    str.replace(":table", table.toString());
    str.replace(":title", title.toString());
    str.replace(":param", param.toString());
    str.replace(":id", id.toString());
    if (!query.exec(str)) {
        qDebug() << query.lastError();
    }

    return 0;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.21
  * brief:      更新项
******************************************************************************/
bool LINUX_SQL::updateSql(QVariant table, QVariant title, QVariant param, QVariant id)
{
    QSqlQuery query(db);
    QString str("update :table set :title = :param where id = :id");

    str.replace(":table", table.toString());
    str.replace(":title", title.toString());
    str.replace(":param", param.toString());
    str.replace(":id", id.toString());
    query.exec(str);

    return 0;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.21
  * brief:      选择项
******************************************************************************/
QVariant LINUX_SQL::selectSql(QVariant table, QVariant title, QVariant id)
{
    QSqlQuery query(db);
    QString str("select :title from :table where id = :id");

    str.replace(":title", title.toString());
    str.replace(":table", table.toString());
    str.replace(":id", id.toString());
    query.exec(str);
    query.next();
    return query.value(0);
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.21
  * brief:      删除项
******************************************************************************/
bool LINUX_SQL::deleteSql(QVariant table, QVariant id)
{
    QSqlQuery query(db);
    QString str("delete from :table where id = :id");
    str.replace(":table", table.toString());
    str.replace(":id", id.toString());
    query.exec(str);

    return 0;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.21
  * brief:      删除所有
******************************************************************************/
bool LINUX_SQL::deleteAll(QVariant table)
{
    QSqlQuery query(db);
    QString str("delete from :table");

    str.replace(":table", table.toString());
    query.exec(str);
    //  query.exec("VACUUM");
    return 0;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.21
  * brief:      删除表
******************************************************************************/
bool LINUX_SQL::deleteTab(QVariant table)
{
    QSqlQuery query(db);
    this->deleteAll(table);
    QString str("drop table :table purge");

    str.replace(":table", table.toString());
    query.exec(str);

    return 0;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.21
  * brief:      判断表是否存在
******************************************************************************/
bool LINUX_SQL::isTabExst(QVariant table, QSqlDatabase Qdb) {
    QSqlQuery query(Qdb);
    QString str("select count(*) from sqlite_master where type='table' and name=':name'");
    str.replace(":name", table.toString());
    query.exec(str);    // 关键的判断
    if (query.next()) {
        if (query.value(0).toInt() == 0) { // not exist
            return false;
        } else { // existed
            return true;
        }
    } else {
        //
    }
    return true;
}

/******************************************************************************
                                    END
******************************************************************************/
