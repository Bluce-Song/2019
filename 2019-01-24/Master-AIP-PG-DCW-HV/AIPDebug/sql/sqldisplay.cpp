/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "sqldisplay.h"

SqlDisplay::SqlDisplay(QWidget *parent) : QWidget(parent)
{
    initUI();
}

SqlDisplay::~SqlDisplay()
{
}

void SqlDisplay::initUI()
{
    initView();
    initText();
    initButton();
    initLayout();
}

void SqlDisplay::initView()
{
    view = new QTableView(this);
//  view->verticalHeader()->setVisible(false);
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
    connect(view, SIGNAL(clicked(QModelIndex)), this, SLOT(clickIndex(QModelIndex)));

    item = new QTableView(this);
    item->setStyleSheet("background-color:#191919; color:white; border:none;"\
                        "gridline-color:#447684; border-style: groove;"\
                        "border-width: 1px; border-color: #447684;");
    item->verticalHeader()->setVisible(false);
    item->setSelectionMode(QAbstractItemView::SingleSelection);
    item->setSelectionBehavior(QAbstractItemView::SelectRows);
#if (QT_VERSION <= QT_VERSION_CHECK(5, 0, 0))
    item->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
#else
    item->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
#endif
}

void SqlDisplay::initText()
{
    txtLayout = new QHBoxLayout;

    type = new QComboBox(this);
    type->setEditable(true);
    type->setFixedSize(125, 44);

    txtLayout->addWidget(new QLabel(tr("测试型号"), this));
    txtLayout->addWidget(type);

    from = new QDateEdit(this);
    from->setFixedSize(125, 44);
    from->setDisplayFormat("yyyy-MM-dd");
    from->setDateTime(QDateTime::currentDateTime());
    txtLayout->addWidget(new QLabel(tr("起始日期"), this));
    txtLayout->addWidget(from);

    stop = new QDateEdit(this);
    stop->setFixedSize(125, 44);
    stop->setDate(QDate::currentDate());
    stop->setDisplayFormat("yyyy-MM-dd");
    stop->setDateTime(QDateTime::currentDateTime());
    txtLayout->addWidget(new QLabel(tr("结束日期"), this));
    this->setStyleSheet((".QLabel{ color:white; border:none;}"));
    txtLayout->addWidget(stop);
}

void SqlDisplay::initButton()
{
    btnLayout = new QHBoxLayout;


    QPushButton *btnSelect = new QPushButton(this);
    btnSelect->setText(tr("查询数据"));
    btnSelect->setFixedSize(97, 44);
    btnLayout->addWidget(btnSelect);
    connect(btnSelect, SIGNAL(clicked(bool)), this, SLOT(recvSelect()));

    QPushButton *btnDetail = new QPushButton(this);
    btnDetail->setText(tr("显示详细"));
    btnDetail->setFixedSize(97, 44);
    btnLayout->addWidget(btnDetail);
    connect(btnDetail, SIGNAL(clicked(bool)), this, SLOT(recvDetail()));

    btnExport = new QPushButton(this);
    btnExport->setText(tr("全部导出"));
    btnExport->setFixedSize(97, 44);
    btnLayout->addWidget(btnExport);
    connect(btnExport, SIGNAL(clicked(bool)), this, SLOT(recvExport()));

//    QPushButton *btn_picture_Export = new QPushButton(this);
//    btn_picture_Export->setText(tr("图片导出"));
//    btn_picture_Export->setFixedSize(97, 44);
//    btnLayout->addWidget(btn_picture_Export);
//    connect(btn_picture_Export, SIGNAL(clicked(bool)), this, SLOT(picture_Export()));

    btnLayout->addStretch();
}

void SqlDisplay::initLayout()
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(view);
    layout->addWidget(item);
    layout->addLayout(txtLayout);
    layout->addLayout(btnLayout);

    this->setLayout(layout);
    item->hide();
    layout->setStretch(0, 1);
    layout->setStretch(1, 2);
}

void SqlDisplay::recvSelect()
{
    tmpExp.clear();
    QDateTime t;
    t.setDate(from->date());
    quint64 id_from = quint64(t.toMSecsSinceEpoch()) << 20;
    t.setDate(stop->date().addDays(1));
    quint64 id_stop = quint64(t.toMSecsSinceEpoch()) << 20;
    QString filter = tr("uuid>=%1 and uuid<=%2 and numb=0").arg(id_from).arg(id_stop);
    if (!type->currentText().isEmpty()) {
        filter.append(tr(" and rslt = '%1'").arg(type->currentText()));
        tmpExp.insert("rslt", type->currentText());
    }
    tmpExp.insert("from", id_from);
    tmpExp.insert("stop", id_stop);

    qDebug() << filter;
    mView->setFilter(filter);
    mView->setSort(0, Qt::AscendingOrder);
    mView->select();
}

void SqlDisplay::picture_Export() {
    tmpMap.insert("enum", QMessageBox::Reset);
    tmpMap.insert("name", sqlName);
    if (!tmpExp.value("from").isNull())
        tmpMap.insert("from", tmpExp.value("from").toLongLong());
    if (!tmpExp.value("stop").isNull())
        tmpMap.insert("stop", tmpExp.value("stop").toLongLong());
    if (!tmpExp.value("rslt").isNull())
        tmpMap.insert("rslt", tmpExp.value("rslt").toString());
    emit sendSqlMap(tmpMap);
    tmpMap.clear();
}

void SqlDisplay::recvExport()
{
    btnExport->setDisabled(true);
    tmpMap.insert("enum", QMessageBox::Apply);
    tmpMap.insert("name", sqlName);
    if (!tmpExp.value("from").isNull())
        tmpMap.insert("from", tmpExp.value("from").toLongLong());
    if (!tmpExp.value("stop").isNull())
        tmpMap.insert("stop", tmpExp.value("stop").toLongLong());
    if (!tmpExp.value("rslt").isNull())
        tmpMap.insert("rslt", tmpExp.value("rslt").toString());
    emit sendSqlMap(tmpMap);
    tmpMap.clear();
}

void SqlDisplay::recvDetail()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (btn->text() == tr("显示详细")) {
        item->show();
        btn->setText(tr("隐藏详细"));
    } else {
        item->hide();
        btn->setText(tr("显示详细"));
    }
}

void SqlDisplay::clickIndex(QModelIndex index)
{
    if (item->isHidden())
        return;
    int row = index.row();
    qint64 guid = mView->index(row, 0).data().toLongLong();
    mItem->setFilter(tr("guid=%1 and numb>100").arg(guid));
    mItem->select();
}

void SqlDisplay::updateSqlite(QVariantMap msg)
{
    sqlName = msg.value("recordName").toString();
    mView = new QSqlTableModel(this, QSqlDatabase::database(sqlName));
    mView->setTable("aip_record");
    mView->setFilter("numb=0");
    mView->setSort(0, Qt::AscendingOrder);
    mView->select();
    view->setModel(mView);
    view->hideColumn(0);
    view->hideColumn(1);
    view->hideColumn(2);
    QStringList header;
    header << tr("UUID") << tr("GUID") << tr("NUMB")
           << tr("测试日期") << tr("测试时间") << tr("测试型号") << tr("测试判定");
    if (mView->columnCount() >= header.size()) {
        for (int i=0; i < header.size(); i++)
            mView->setHeaderData(i, Qt::Horizontal, header.at(i));
    }

    mItem = new QSqlTableModel(this, QSqlDatabase::database(sqlName));
    mItem->setTable("aip_record");
    mItem->setFilter("numb>100");
    mItem->select();
    item->setModel(mItem);
    item->hideColumn(0);
    item->hideColumn(1);
    item->hideColumn(2);
    QStringList items;
    items << tr("UUID") << tr("GUID") << tr("NUMB")
          << tr("测试项目") << tr("测试参数") << tr("测试结果") << tr("测试判定");
    if (mItem->columnCount() >= header.size()) {
        for (int i=0; i < items.size(); i++)
            mItem->setHeaderData(i, Qt::Horizontal, items.at(i));
    }
}

void SqlDisplay::recvSqlMap(QVariantMap msg)
{
    switch (msg.value("enum").toInt()) {
    case QMessageBox::Open:
        updateSqlite(msg);
        break;
    case QMessageBox::Ok:
        btnExport->setEnabled(true);
        break;
    default:
        break;
    }
}

void SqlDisplay::showEvent(QShowEvent *e)
{
    mView->select();
    e->accept();
}
