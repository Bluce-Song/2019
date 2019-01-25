/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "widget_bemf.h"
#include "ui_widget_bemf.h"

Widget_BEMF::Widget_BEMF(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_BEMF)
{
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint); //-去掉标题栏
    ui->setupUi(this);

    //  电阻设置表头
    ui->bemfTab->horizontalHeader()->setStyleSheet\
            ("QHeaderView::section{background-color:#191919;color: white;"\
             "padding-left: 4px;border: 1px solid #447684;}");
    ui->bemfTab->horizontalHeader()->setFixedHeight(35);
    ui->bemfTab->horizontalHeader()->setResizeMode(QHeaderView::Fixed);
}

Widget_BEMF::~Widget_BEMF()
{
    delete ui;
}

void Widget_BEMF::Pri_BEMF_Init() {
    int i;
    ui->bemf_unbal->setValue(Copy_BEMF_List.at(0).toDouble());
    ui->bemf_speed->setValue(Copy_BEMF_List.at(1).toDouble());
    ui->bemf_turn->setValue(Copy_BEMF_List.at(2).toDouble());
    ui->bemf_hall->setValue(Copy_BEMF_List.at(3).toDouble());
    ui->bemf_time->setValue(Copy_BEMF_List.at(4).toDouble());
    ui->bemf_drive->setValue(Copy_BEMF_List.at(5).toDouble());
    ui->bemf_volt->setValue(Copy_BEMF_List.at(6).toDouble());
    ui->bemf_volt_2->setValue(Copy_BEMF_List.at(7).toDouble());

    ui->bemfTab->setRowCount(0);
    ui->bemfTab->setRowCount(2);

    QStringList lisit;   lisit << QString(tr("上限")) << QString(tr("下限"));
    BEMF_QTableWidgetItem.clear();
    for (i = 0; i < 2; i++) {
        BEMF_QTableWidgetItem.append(new QTableWidgetItem);
        BEMF_QTableWidgetItem[i]->setTextAlignment(Qt::AlignCenter);
        BEMF_QTableWidgetItem[i]->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        BEMF_QTableWidgetItem[i]->setText(lisit.at(i));
        ui->bemfTab->setItem(i, 0, BEMF_QTableWidgetItem[i]);
    }
    for (i = 0; i < 2; i++) {
        QTableWidgetItem *pg_high = new QTableWidgetItem;    // 高电平
        pg_high->setTextAlignment(Qt::AlignCenter);
        pg_high->setText(Copy_BEMF_List.at(50+i*15));
        ui->bemfTab->setItem(i, 1, pg_high);
        QTableWidgetItem *pg_low = new QTableWidgetItem;     // 低电平
        pg_low->setTextAlignment(Qt::AlignCenter);
        pg_low->setText(Copy_BEMF_List.at(51+i*15));
        ui->bemfTab->setItem(i, 2, pg_low);
        QTableWidgetItem *pg_fre = new QTableWidgetItem;     // 频率
        pg_fre->setTextAlignment(Qt::AlignCenter);
        pg_fre->setText(Copy_BEMF_List.at(52+i*15));
        ui->bemfTab->setItem(i, 3, pg_fre);

        QTableWidgetItem *pg_phase = new QTableWidgetItem;     // 相位差
        pg_phase->setTextAlignment(Qt::AlignCenter);
        pg_phase->setText(Copy_BEMF_List.at(53+i*15));
        ui->bemfTab->setItem(i, 4, pg_phase);
    }
}

void Widget_BEMF::Pri_BEMF_Data_Save() {
    Copy_BEMF_List.replace(0, QString::number(ui->bemf_unbal->value()));
    Copy_BEMF_List.replace(1, QString::number(ui->bemf_speed->value()));
    Copy_BEMF_List.replace(2, QString::number(ui->bemf_turn->value()));
    Copy_BEMF_List.replace(3, QString::number(ui->bemf_hall->value()));
    Copy_BEMF_List.replace(4, QString::number(ui->bemf_time->value()));
    Copy_BEMF_List.replace(5, QString::number(ui->bemf_drive->value()));
    Copy_BEMF_List.replace(6, QString::number(ui->bemf_volt->value()));
    Copy_BEMF_List.replace(7, QString::number(ui->bemf_volt_2->value()));

    for (int i = 0; i < 2; i++) {
        Copy_BEMF_List.replace(50+i*15, ui->bemfTab->item(i, 1)->text());
        Copy_BEMF_List.replace(51+i*15, ui->bemfTab->item(i, 2)->text());
        Copy_BEMF_List.replace(52+i*15, ui->bemfTab->item(i, 3)->text());
        Copy_BEMF_List.replace(53+i*15, ui->bemfTab->item(i, 4)->text());
    }
}

void Widget_BEMF::Pub_Conf_Set_BEMF(QString str, int flag)
{
    switch (flag) {
    case 1:
        Pri_BEMF_Init();
        break;
    case 2:
        Pri_BEMF_Data_Save();
        break;
    }
    str.clear();
}

QStringList Widget_BEMF::BEMF_Test_Param()
{
    QString str;
    QStringList strSql;
    QStringList strParam, strTest;
    strTest.clear();
    strParam.clear();

    str = QString(tr("BEMF"));
    strTest.append(str);
    str = QString(Copy_BEMF_List.at(50))+QString("-")+QString(Copy_BEMF_List.at(65))+QString("V,");
    str += QString("k=")+QString(Copy_BEMF_List.at(66))+QString(",");
    str += QString(Copy_BEMF_List.at(52))+QString("-")+QString(Copy_BEMF_List.at(67));
    strParam.append(str);
    strSql.append(tr("BEMF"));

    QStringList Back_List;
    Back_List.append(QString::number(strTest.size()));
    Back_List.append(QString::number(strParam.size()));
    Back_List.append(QString::number(strSql.size()));
    Back_List.append(strTest);
    Back_List.append(strParam);
    Back_List.append(strSql);
    return Back_List;
}

void Widget_BEMF::BEMF_NetData(QStringList list, QString str) {
    if (str == QString(tr("bemf_min"))) {
        ui->bemfTab->item(0, 1)->setText(list.at(0));
    } else if (str == QString(tr("bemf_max"))) {
        ui->bemfTab->item(1, 1)->setText(list.at(0));
    } else if (str == QString(tr("volt_min"))) {
        ui->bemfTab->item(0, 2)->setText(list.at(0));
    } else if (str == QString(tr("volt_max"))) {
        ui->bemfTab->item(1, 2)->setText(list.at(0));
    } else if (str == QString(tr("speed"))) {
       ui->bemf_speed->setValue(list.at(0).toDouble());
    } else if (str == QString(tr("turn"))) {
        ui->bemf_turn->setValue(list.at(0).toDouble());
    } else if (str == QString(tr("angle_min"))) {
        ui->bemfTab->item(0, 3)->setText(list.at(0));
    } else if (str == QString(tr("angle_max"))) {
        ui->bemfTab->item(1, 3)->setText(list.at(0));
    } else if (str == QString(tr("noun"))) {
        ui->bemf_unbal->setValue(list.at(0).toDouble());
    } else if (str == QString(tr("volt_vcc"))) {
        ui->bemf_volt->setValue(list.at(0).toDouble());
        Pri_BEMF_Data_Save();
    } else if (str == QString(tr("time"))) {
        ui->bemf_time->setValue(list.at(0).toDouble());
    } else {
        //
    }
    //    else if (str == QString(tr("hw_volt_min"))) {
    //        ui->bemfTab->item(0, 3)->setText(list.at(0));
    //    }
    //    else if (str == QString(tr("hw_volt_max"))) {
    //        ui->bemfTab->item(1, 3)->setText(list.at(0));
    //    }
}
