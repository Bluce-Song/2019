/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "sqlnetwork.h"

SqlNetwork::SqlNetwork(QWidget *parent) : QWidget(parent)
{
    initUI();
}

SqlNetwork::~SqlNetwork()
{
}

void SqlNetwork::initUI()
{
    initView();
    initText();
    initLayout();
}

void SqlNetwork::initView()
{
    view = new QTableView(this);
    view->setSelectionMode(QAbstractItemView::SingleSelection);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->setStyleSheet("background-color:#191919; color:white; border:none;"\
                        "gridline-color:#447684; border-style: groove;"\
                        "border-width: 1px; border-color: #447684;");
#if (QT_VERSION <= QT_VERSION_CHECK(5, 0, 0))
    view->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
#else
    view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
#endif
}

void SqlNetwork::initText()
{
    btnLayout = new QHBoxLayout;
    QLabel *text = new QLabel(this);
    btnLayout->addWidget(text);
}

void SqlNetwork::initLayout()
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(view);
    layout->addLayout(btnLayout);
    this->setLayout(layout);
}

void SqlNetwork::createSqlite()
{
    QSqlQuery query(QSqlDatabase::database(sqlName));
//        query.exec("drop table sqlnet");
    QString cmd;
    cmd = "create table if not exists sqlnet (";
    cmd += "id integer primary key, explanation text, parameter text, name text)";
    if (!query.exec(cmd)) {
        qDebug() << "create table sqlnet Error";
    }
}

void SqlNetwork::updateSqlite()
{
    mView = new QSqlTableModel(this, QSqlDatabase::database(sqlName));
    mView->setTable("sqlnet");
    mView->select();
    mView->setHeaderData(1, Qt::Horizontal, tr("名称"));
    mView->setHeaderData(2, Qt::Horizontal, tr("参数"));
    if (mView->rowCount() == 0) {
        insertSqlite();
        mView->select();
    }
    if (mView->columnCount() >= 4) {
        view->setModel(mView);

        view->hideColumn(0);
        view->hideColumn(3);
    }
}

void SqlNetwork::insertSqlite()
{
    QSqlQuery query(QSqlDatabase::database(sqlName));
    QStringList names;
    QStringList explanations;
    QStringList parameters;
    SqlSnowUid snow;

    names << "netMode";
    parameters << "0";
    explanations << tr("上传模式");

    names << "netAddr";
    parameters << "192.168.1.128";
    explanations << tr("网络地址");

    names << "netUser";
    parameters << "sa";
    explanations << tr("登录用户");

    names << "netPass";
    parameters << "123";
    explanations << tr("登录密码");

    names << "sqlName";
    parameters << "aip-server";
    explanations << tr("数据库名");

    names << "netPort";
    parameters << "1433";
    explanations << QString(tr("网络端口"));

    for (int i=0; i < names.size(); i++) {
        query.prepare("insert into sqlnet values(?,?,?,?)");
        query.bindValue(0, snow.getId());
        query.bindValue(1, explanations.at(i));
        query.bindValue(2, parameters.at(i));
        query.bindValue(3, names.at(i));
        query.exec();
    }
}

void SqlNetwork::changeSqlite()
{
    mView->submitAll();
}

void SqlNetwork::showEvent(QShowEvent *e)
{
    mView->submitAll();
    e->accept();
}


void SqlNetwork::recvSqlMap(QVariantMap msg)
{
    switch (msg.value("enum").toInt()) {
    case QMessageBox::Open:
        sqlName = msg.value("sqliteName").toString();
        createSqlite();
        updateSqlite();
        break;
    default:
        break;
    }
}
