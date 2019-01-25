/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "widget_load.h"
#include "ui_widget_load.h"

Widget_Load::Widget_Load(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Load)
{
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint); // -去掉标题栏
    ui->setupUi(this);

    //  电阻设置表头
    ui->loadTab->horizontalHeader()->setStyleSheet\
            ("QHeaderView::section{background-color:#191919;color: white;"
             "padding-left: 4px;border: 1px solid #447684;}");
    ui->loadTab->horizontalHeader()->setFixedHeight(35);
    ui->loadTab->horizontalHeader()->setResizeMode(QHeaderView::Fixed);

    ui->load_time_series->horizontalHeader()->setStyleSheet\
            ("QHeaderView::section{background-color:#191919;color: white;"\
             "padding-left: 4px;border: 1px solid #447684;}");
    ui->load_time_series->horizontalHeader()->setFixedHeight(35);
    ui->load_time_series->horizontalHeader()->setResizeMode(QHeaderView::Fixed);
}

Widget_Load::~Widget_Load()
{
    delete ui;
}

void Widget_Load::Pri_LOAD_Init() {
    int i = 0;
    ui->load_volt->setValue(Copy_LOAD_List.at(0).toDouble());
    ui->load_vcc->setValue(Copy_LOAD_List.at(1).toDouble());
    ui->load_vsp->setValue(Copy_LOAD_List.at(2).toDouble());
    ui->load_time->setValue(Copy_LOAD_List.at(3).toDouble());
    ui->load_nm->setValue(Copy_LOAD_List.at(4).toDouble());
    ui->load_power->setValue(Copy_LOAD_List.at(5).toDouble());
    ui->load_drive->setValue(Copy_LOAD_List.at(6).toDouble());
    ui->load_pwmvsp->setValue(Copy_LOAD_List.at(7).toDouble());


    ui->loadTab->setRowCount(0);
    ui->loadTab->setRowCount(2);

    QStringList lisit;   lisit << QString(tr("上限")) << QString(tr("下限"));
    LOAD_QTableWidgetItem.clear();
    for (i = 0; i < 2; i++) {
        LOAD_QTableWidgetItem.append(new QTableWidgetItem);
        LOAD_QTableWidgetItem[i]->setTextAlignment(Qt::AlignCenter);
        LOAD_QTableWidgetItem[i]->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        LOAD_QTableWidgetItem[i]->setText(lisit.at(i));
        ui->loadTab->setItem(i, 0, LOAD_QTableWidgetItem[i]);
    }
    for (i = 0; i < 2; i++) {
        QTableWidgetItem *pg_high = new QTableWidgetItem;    // 电流
        pg_high->setTextAlignment(Qt::AlignCenter);
        pg_high->setText(Copy_LOAD_List.at(50+i*15));
        ui->loadTab->setItem(i, 1, pg_high);
        QTableWidgetItem *pg_low = new QTableWidgetItem;     // 功率
        pg_low->setTextAlignment(Qt::AlignCenter);
        pg_low->setText(Copy_LOAD_List.at(51+i*15));
        ui->loadTab->setItem(i, 2, pg_low);
        QTableWidgetItem *pg_fre = new QTableWidgetItem;     // 转速
        pg_fre->setTextAlignment(Qt::AlignCenter);
        pg_fre->setText(Copy_LOAD_List.at(52+i*15));
        ui->loadTab->setItem(i, 3, pg_fre);
    }

    ui->load_time_series->setRowCount(0);
    ui->load_time_series->setRowCount(1);
    for (i = 0; i < 13; i++) {
        LOAD_Time_Series.append(new QTableWidgetItem);
        LOAD_Time_Series[i]->setTextAlignment(Qt::AlignCenter);
        LOAD_Time_Series[i]->setText(Copy_LOAD_List.at(110+i));
        ui->load_time_series->setItem(0, i+1, LOAD_Time_Series[i]);
    }
}

void Widget_Load::Pri_LOAD_Data_Save() {
    int i = 0;
    Copy_LOAD_List.replace(0, QString::number(ui->load_volt->value()));
    Copy_LOAD_List.replace(1, QString::number(ui->load_vcc->value()));
    Copy_LOAD_List.replace(2, QString::number(ui->load_vsp->value()));
    Copy_LOAD_List.replace(3, QString::number(ui->load_time->value()));
    Copy_LOAD_List.replace(4, QString::number(ui->load_nm->value()));
    Copy_LOAD_List.replace(5, QString::number(ui->load_power->value()));
    Copy_LOAD_List.replace(6, QString::number(ui->load_drive->value()));
     Copy_LOAD_List.replace(7, QString::number(ui->load_pwmvsp->value()));

    for (i = 0; i < 2; i++) {
        Copy_LOAD_List.replace(50 + i*15, ui->loadTab->item(i, 1)->text());
        Copy_LOAD_List.replace(51 + i*15, ui->loadTab->item(i, 2)->text());
        Copy_LOAD_List.replace(52 + i*15, ui->loadTab->item(i, 3)->text());
    }

    for (i = 0; i < 13; i++) {
        Copy_LOAD_List.replace(110+i, ui->load_time_series->item(0, i+1)->text());
    }
}

void Widget_Load::Pub_Conf_Set_LOAD(QString str, int flag) {
    switch (flag) {
    case 1:
        Pri_LOAD_Init();
        break;
    case 2:
        Pri_LOAD_Data_Save();
        break;
    }
    str.clear();
}
QStringList Widget_Load::LOAD_Test_Param()
{
    QString str;
    QStringList strSql;
    QStringList strParam, strTest;
    strTest.clear();
    strParam.clear();

    str = QString(tr("负载"));
//    str =QString(tr("参数2")); strParam.append(str);
//    strSql.append(tr("负载"));

    strTest.append(str);
    str = Copy_LOAD_List.at(50) + tr("-") + Copy_LOAD_List.at(65);
    str += QString(tr("mA,"));
    str += Copy_LOAD_List.at(51) + tr("-") + Copy_LOAD_List.at(66);
    str += QString(tr("W,"));
    str += Copy_LOAD_List.at(52) + tr("-") + Copy_LOAD_List.at(67);
    str += QString(tr("rpm,"));
    str += Copy_LOAD_List.at(4) + QString(tr(" N/m"));
    strParam.append(str);
    strSql.append(tr("空载"));

    QStringList Back_List;
    Back_List.append(QString::number(strTest.size()));
    Back_List.append(QString::number(strParam.size()));
    Back_List.append(QString::number(strSql.size()));
    Back_List.append(strTest);
    Back_List.append(strParam);
    Back_List.append(strSql);
    return Back_List;
}

void Widget_Load::LOAD_NetData(QStringList list, QString str) {
    if (str == QString(tr("volt"))) {
        ui->load_volt->setValue(list.at(0).toDouble());
    } else if (str == QString(tr("curr_min"))) {
        ui->loadTab->item(0, 1)->setText(list.at(0));
    } else if (str == QString(tr("curr_max"))) {
        ui->loadTab->item(1, 1)->setText(list.at(0));
    } else if (str == QString(tr("pwr_min"))) {
        ui->loadTab->item(0, 2)->setText(list.at(0));
    } else if (str == QString(tr("pwr_max"))) {
        ui->loadTab->item(1, 2)->setText(list.at(0));
    } else if (str == QString(tr("speed_min"))) {
        ui->loadTab->item(0, 3)->setText(list.at(0));
    } else if (str == QString(tr("speed_max"))) {
        ui->loadTab->item(1, 3)->setText(list.at(0));
    } else if (str == QString(tr("torque"))) {
        ui->load_nm->setValue(list.at(0).toDouble());
    } else if (str == QString(tr("vcc_volt"))) {
        ui->load_vcc->setValue(list.at(0).toDouble());
    } else if (str == QString(tr("vsp_volt"))) {
        ui->load_vsp->setValue(list.at(0).toDouble());
        Pri_LOAD_Data_Save();
    } else if (str == QString(tr("time"))) {
        ui->load_time->setValue(list.at(0).toDouble());
    } else if (str == QString(tr("driver"))) {
        ui->load_drive->setValue(list.at(0).toDouble());
    } else if (str == QString(tr("power"))) {
        ui->load_power->setValue(list.at(0).toDouble());
    } else if (str == QString(tr("sequence"))) {
        for (int i = 0; i < list.size(); i++) {
            ui->load_time_series->item(0, i+1)->setText(list.at(i));
        }
    } else {
        //
    }
}
