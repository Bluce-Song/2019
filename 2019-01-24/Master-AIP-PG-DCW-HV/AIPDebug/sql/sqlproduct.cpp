/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "sqlproduct.h"

SqlProduct::SqlProduct(QWidget *parent) : QWidget(parent)
{
    initUI();
}

void SqlProduct::initUI()
{
    initView();
    initText();
    initLayout();
}

void SqlProduct::initView()
{
    view = new QTableView(this);
    view->setSortingEnabled(true);
    view->setSelectionMode(QAbstractItemView::SingleSelection);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->setStyleSheet("background-color:#191919; color:white; border:none;"\
                        "gridline-color:#447684; border-style: groove;"\
                        "border-width: 1px; border-color: #447684;");
#if (QT_VERSION <= QT_VERSION_CHECK(5, 0, 0))
    view->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    view->verticalHeader()->setResizeMode(QHeaderView::Stretch);
#else
    view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    view->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
#endif
}

void SqlProduct::initText()
{
    btnLayout = new QHBoxLayout;

    stop = new QDateEdit(this);
    stop->setFixedSize(125, 44);
    stop->setDate(QDate::currentDate());
    stop->setDisplayFormat("yyyy-MM-dd");
    QLabel *Resent_date = new QLabel(this);
    Resent_date->setText(tr("最近日期"));
    Resent_date->setStyleSheet("color: rgb(255, 255, 255);");
    btnLayout->addWidget(Resent_date);
    btnLayout->addWidget(stop);

    btnLayout->addStretch();

    QPushButton *btnSelect = new QPushButton(this);
    btnSelect->setText(tr("重新查询"));
    btnSelect->setFixedSize(97, 44);
    btnLayout->addWidget(btnSelect);
    connect(btnSelect, SIGNAL(clicked(bool)), this, SLOT(selectSqlite()));
}

void SqlProduct::initLayout()
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(view);
    layout->addLayout(btnLayout);
    this->setLayout(layout);
}

void SqlProduct::createSqlite()
{
    QSqlQuery query(QSqlDatabase::database(sqlName));

    QString cmd;
    cmd = "create table if not exists sql_record (";
    cmd += "id integer primary key, date text, prod integer)";
    if (!query.exec(cmd)) {
        qDebug() << "create table sql_record Error";
    }

    if (!query.exec("delete from sql_record")) {
        qDebug() << "delete table sql_record" << query.lastError();
    }

    query.finish();
    query.clear();
}

void SqlProduct::updateSqlite()
{
    mView = new QSqlTableModel(this, QSqlDatabase::database(sqlName));
    mView->setTable("sql_record");
    mView->setSort(0, Qt::AscendingOrder);
    mView->select();
    mView->setHeaderData(1, Qt::Horizontal, tr("日期"));
    mView->setHeaderData(2, Qt::Horizontal, tr("产量"));
    if (mView->columnCount() >= 2) {
        view->setModel(mView);
        view->hideColumn(0);
    }
}

void SqlProduct::insertSqlite()
{
    QDateTime t1;
    QDateTime t2;
    t1.setDate(stop->date().addDays(1));
    t2.setDate(stop->date().addDays(0));
    QSqlQuery query(QSqlDatabase::database(sqlName));

    QSqlDatabase::database(sqlName).transaction();
    int c = 0;
    for (int i=0; i < 15; i++) {
        query.prepare("select count(*) from aip_record where uuid < ? and uuid > ? and numb=0");
        query.addBindValue(quint64(t1.toMSecsSinceEpoch()) << 20);
        query.addBindValue(quint64(t2.toMSecsSinceEpoch()) << 20);
        if (!query.exec()) {
            qDebug() << query.lastError();
        }
        if (query.next()) {
            c = query.value(0).toInt();
        }
        query.prepare("replace into sql_record values(?,?,?)");
        query.bindValue(0, quint64(t1.toMSecsSinceEpoch()) << 20);
        query.bindValue(1, t2.toString("yyyy-MM-dd"));
        query.bindValue(2, c);
        query.exec();
        t1.setDate(t1.date().addDays(-1));
        t2.setDate(t2.date().addDays(-1));
    }
    QSqlDatabase::database(sqlName).commit();
    query.finish();
    query.clear();
}

void SqlProduct::selectSqlite()
{
    createSqlite();
    insertSqlite();
    mView->select();
}

void SqlProduct::showEvent(QShowEvent *e)
{
    mView->select();
    e->accept();
}

void SqlProduct::recvSqlMap(QVariantMap msg)
{
    switch (msg.value("enum").toInt()) {
    case QMessageBox::Open:
        sqlName = msg.value("recordName").toString();
        createSqlite();
        insertSqlite();
        updateSqlite();
        break;
    default:
        break;
    }
}
