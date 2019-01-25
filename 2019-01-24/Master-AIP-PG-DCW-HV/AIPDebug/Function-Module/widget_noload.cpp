/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "widget_noload.h"
#include "ui_widget_noload.h"

Widget_Noload::Widget_Noload(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Noload)
{
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint); //-去掉标题栏
    ui->setupUi(this);

    //  电阻设置表头
    ui->noloadTab->horizontalHeader()->setStyleSheet\
            ("QHeaderView::section{background-color:#191919;color: white;"\
             "padding-left: 4px;border: 1px solid #447684;}");
    ui->noloadTab->horizontalHeader()->setFixedHeight(35);
    ui->noloadTab->horizontalHeader()->setResizeMode(QHeaderView::Fixed);

    ui->noload_time_series->horizontalHeader()->setStyleSheet\
            ("QHeaderView::section{background-color:#191919;color: white;"\
             "padding-left: 4px;border: 1px solid #447684;}");
    ui->noload_time_series->horizontalHeader()->setFixedHeight(35);
    ui->noload_time_series->horizontalHeader()->setResizeMode(QHeaderView::Fixed);

    ui->noloadTab->setColumnWidth(1, 128);
    ui->noloadTab->setColumnWidth(2, 128);
    ui->noloadTab->setColumnWidth(3, 128);
    ui->noloadTab->setColumnWidth(4, 128);

    NoLoad_Init_Flag = false;


    Test_Widget = new QWidget(this);
    Test_Widget->setGeometry(150, 100, 500, 410);
    Test_Widget->setWindowFlags(Qt::WindowStaysOnTopHint);
    Test_Widget->setStyleSheet\
            ("border-radius: 10px;padding:2px 4px;background-color: gray;"\
             "color: black;border-color: black;");
    QGridLayout *IO_upside = new QGridLayout;
    QString IO_table[2] = {QString(tr("左工位电流(A):")), QString(tr("右工位电流(A):"))};
    int i = 0;
    for (i = 0; i < 2; i++) {
        IO_Show_Lable.append(new QLabel(this));
        IO_Show_Lable[i]->setText(IO_table[i]);
        IO_Show_Lable[i]->setMaximumHeight(35);
        IO_Show_Lable[i]->setMaximumWidth(135);
        IO_Show_Lable[i]->setAlignment(Qt::AlignCenter);
        IO_upside->addWidget(IO_Show_Lable[i], i, 0);

        IO_Line_Text.append(new QDoubleSpinBox(this));
        IO_Line_Text[i]->setMaximumHeight(35);
        IO_Line_Text[i]->setMaximumWidth(95);
        IO_Line_Text[i]->setMinimum(-3);
        IO_Line_Text[i]->setDecimals(3);
        IO_Line_Text[i]->setSingleStep(0.001);
        IO_upside->addWidget(IO_Line_Text[i], i, 1);
    }

    QPushButton *IO_button_quit = new QPushButton;
    IO_button_quit->setText(tr("退出"));
    IO_button_quit->setMinimumHeight(50);
    IO_button_quit->setMinimumWidth(90);
    IO_button_quit->setStyleSheet\
            ("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"\
             "stop: 0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);");
    IO_upside->addWidget(IO_button_quit, 0, 5);
    connect(IO_button_quit, SIGNAL(clicked()), this, SLOT(IO_Widget_autoquit()));

    QVBoxLayout *Histogram_IO_Widget_layout = new QVBoxLayout;
    Histogram_IO_Widget_layout->addLayout(IO_upside);
    Test_Widget->setLayout(Histogram_IO_Widget_layout);
    Test_Widget->hide();
}

Widget_Noload::~Widget_Noload()
{
    delete ui;
}

void Widget_Noload::IO_Widget_autoquit() {
    Test_Widget->hide();
}

void Widget_Noload::Pri_NOLOAD_Init(QStringList list) {
    int i = 0;
    NoLoad_Init_Flag = true;
    ui->noload_volt->setValue(Copy_NOLOAD_List.at(0).toDouble());
    ui->noload_vcc->setValue(Copy_NOLOAD_List.at(1).toDouble());
    ui->noload_vsp->setValue(Copy_NOLOAD_List.at(2).toDouble());
    ui->noload_time->setValue(Copy_NOLOAD_List.at(3).toDouble());
    ui->Com_Power->setCurrentIndex(Copy_NOLOAD_List.at(5).toInt());
    ui->Com_Drive->setCurrentIndex(Copy_NOLOAD_List.at(6).toInt());
    ui->noload_pwmvsp->setValue(list.at(0).toInt()); // 获取测试波形

    ui->noload_Ripple->setValue(Copy_NOLOAD_List.at(8).toDouble());
    ui->noload_Bandwidth->setValue(Copy_NOLOAD_List.at(9).toDouble());
    ui->noload_GAIN->setValue(Copy_NOLOAD_List.at(10).toDouble());
    ui->Com_Turn->setCurrentIndex(Copy_NOLOAD_List.at(11).toInt());
    ui->Com_Vcc_Drive->setCurrentIndex(Copy_NOLOAD_List.at(12).toInt());
    ui->noload_count->setValue(Copy_NOLOAD_List.at(13).toInt());
    ui->noload_item->setValue(list.at(1).toInt()); // 获取启动方式

    ui->noloadTab->setRowCount(0);
    ui->noloadTab->setRowCount(2);

    IO_Line_Text[0]->setValue(Copy_NOLOAD_List.at(15).toDouble());
    IO_Line_Text[1]->setValue(Copy_NOLOAD_List.at(16).toDouble());

    QStringList lisit;   lisit << QString(tr("下限")) << QString(tr("上限"));
    NOLOAD_QTableWidgetItem.clear();
    for (i = 0; i < 2; i++) {
        NOLOAD_QTableWidgetItem.append(new QTableWidgetItem);
        NOLOAD_QTableWidgetItem[i]->setTextAlignment(Qt::AlignCenter);
        NOLOAD_QTableWidgetItem[i]->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        NOLOAD_QTableWidgetItem[i]->setText(lisit.at(i));
        ui->noloadTab->setItem(i, 0, NOLOAD_QTableWidgetItem[i]);
    }
    for (i = 0; i < 2; i++) {
        QTableWidgetItem *pg_high = new QTableWidgetItem;    // 电流
        pg_high->setTextAlignment(Qt::AlignCenter);
        pg_high->setText(Copy_NOLOAD_List.at(50+i*15));
        ui->noloadTab->setItem(i, 1, pg_high);
        QTableWidgetItem *pg_volt = new QTableWidgetItem;     // 电压
        pg_volt->setTextAlignment(Qt::AlignCenter);
        pg_volt->setText(Copy_NOLOAD_List.at(53+i*15));
        ui->noloadTab->setItem(i, 2, pg_volt);
        QTableWidgetItem *pg_low = new QTableWidgetItem;     // 功率
        pg_low->setTextAlignment(Qt::AlignCenter);
        pg_low->setText(Copy_NOLOAD_List.at(51+i*15));
        ui->noloadTab->setItem(i, 3, pg_low);
        QTableWidgetItem *pg_fre = new QTableWidgetItem;     // 转速
        pg_fre->setTextAlignment(Qt::AlignCenter);
        pg_fre->setText(Copy_NOLOAD_List.at(52+i*15));
        ui->noloadTab->setItem(i, 4, pg_fre);
    }
    ui->noload_time_series->setRowCount(0);
    ui->noload_time_series->setRowCount(1);

    NOLOAD_Time_Series.clear();
    for (i = 0; i < 10; i++) {
        NOLOAD_Time_Series.append(new QTableWidgetItem);
        NOLOAD_Time_Series[i]->setTextAlignment(Qt::AlignCenter);
        NOLOAD_Time_Series[i]->setText(Copy_NOLOAD_List.at(110+i));
        ui->noload_time_series->setItem(0, i+1, NOLOAD_Time_Series[i]);
    }
    NOLOAD_Time_Series.append(new QTableWidgetItem);
    NOLOAD_Time_Series[10]->setTextAlignment(Qt::AlignCenter);
    NOLOAD_Time_Series[10]->setText(tr("时间(s)"));
    ui->noload_time_series->setItem(0, 0, NOLOAD_Time_Series[10]);
    NoLoad_Init_Flag = false;
}

void Widget_Noload::Pri_NOLOAD_Data_Save() {
    int i = 0;

    Copy_NOLOAD_List.replace(0, QString::number(ui->noload_volt->value()));
    Copy_NOLOAD_List.replace(1, QString::number(ui->noload_vcc->value()));
    Copy_NOLOAD_List.replace(2, QString::number(ui->noload_vsp->value()));
    Copy_NOLOAD_List.replace(3, QString::number(ui->noload_time->value()));
    Copy_NOLOAD_List.replace(5, QString::number(ui->Com_Power->currentIndex()));
    Copy_NOLOAD_List.replace(6, QString::number(ui->Com_Drive->currentIndex()));
    Copy_NOLOAD_List.replace(7, QString::number(ui->noload_pwmvsp->value()));

    Copy_NOLOAD_List.replace(8, QString::number(ui->noload_Ripple->value()));
    Copy_NOLOAD_List.replace(9, QString::number(ui->noload_Bandwidth->value()));
    Copy_NOLOAD_List.replace(10, QString::number(ui->noload_GAIN->value()));
    Copy_NOLOAD_List.replace(11, QString::number(ui->Com_Turn->currentIndex()));
    Copy_NOLOAD_List.replace(12, QString::number(ui->Com_Vcc_Drive->currentIndex()));
    Copy_NOLOAD_List.replace(13, QString::number(ui->noload_count->value()));
    Copy_NOLOAD_List.replace(14, QString::number(ui->noload_item->value()));

    Copy_NOLOAD_List.replace(15, QString::number(IO_Line_Text[0]->value()));
    Copy_NOLOAD_List.replace(16, QString::number(IO_Line_Text[1]->value()));

    for (i = 0; i < 2; i++) {
        Copy_NOLOAD_List.replace(50+i*15, ui->noloadTab->item(i, 1)->text());
        Copy_NOLOAD_List.replace(51+i*15, ui->noloadTab->item(i, 3)->text());
        Copy_NOLOAD_List.replace(52+i*15, ui->noloadTab->item(i, 4)->text());
        Copy_NOLOAD_List.replace(53+i*15, ui->noloadTab->item(i, 2)->text());
    }

    for (i = 0; i < 10; i++) {
        Copy_NOLOAD_List.replace(110+i, ui->noload_time_series->item(0, i+1)->text());
    }
}

void Widget_Noload::Pub_Conf_Set_NOLOAD(QStringList list, int flag) {
    switch (flag) {
    case 1:
        Pri_NOLOAD_Init(list);
        break;
    case 2:
        Pri_NOLOAD_Data_Save();
        break;
    }
}

QStringList Widget_Noload::NOLOAD_Test_Param()
{
    QString str;
    QStringList strSql;
    QStringList strParam, strTest;
    strTest.clear();
    strParam.clear();

    str = QString(tr("空载"));
    strTest.append(str);
    str = Copy_NOLOAD_List.at(65); // Copy_NOLOAD_List.at(50) + tr("-") +
    str += QString(tr("A,"));
    str += Copy_NOLOAD_List.at(68); // Copy_NOLOAD_List.at(53) + tr("-") +
    str += QString(tr("V,"));
    str += Copy_NOLOAD_List.at(66); // Copy_NOLOAD_List.at(51) + tr("-") +
    str += QString(tr("W "));
    str += Copy_NOLOAD_List.at(52) + tr("-") + Copy_NOLOAD_List.at(67);
    str += QString(tr("rpm"));
    if (ui->Com_Turn->currentText() == QString(tr("不测"))) {
        //
    } else {
        str += ",";
        str += QString(tr(" ")) + ui->Com_Turn->currentText();
    }
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

void Widget_Noload::NOLOAD_NetData(QStringList list, QString str) {
    if (str == QString(tr("volt"))) {
        ui->noload_volt->setValue(list.at(0).toDouble());
    } else if (str == QString(tr("curr_min"))) {
        ui->noloadTab->item(0, 1)->setText(list.at(0));
    } else if (str == QString(tr("curr_max"))) {
        ui->noloadTab->item(1, 1)->setText(list.at(0));
    } else if (str == QString(tr("pwr_min"))) {
        ui->noloadTab->item(0, 3)->setText(list.at(0));
    } else if (str == QString(tr("pwr_max"))) {
        ui->noloadTab->item(1, 3)->setText(list.at(0));
    } else if (str == QString(tr("speed_min"))) {
        ui->noloadTab->item(0, 4)->setText(list.at(0));
    } else if (str == QString(tr("speed_max"))) {
        ui->noloadTab->item(1, 4)->setText(list.at(0));
    } else if (str == QString(tr("vcc_volt"))) {
        ui->noload_vcc->setValue(list.at(0).toDouble());
    } else if (str == QString(tr("vsp_volt"))) {
        ui->noload_vsp->setValue(list.at(0).toDouble());
        Pri_NOLOAD_Data_Save();  // 保存
    } else if (str == QString(tr("time"))) {
        ui->noload_time->setValue(list.at(0).toDouble());
    } else if (str == QString(tr("sequence"))) {
        for (int i = 0; i < 10; i++) {
            ui->noload_time_series->item(0, i+1)->setText(list.at(i));
        }
    } else if (str == QString(tr("power"))) {
        ui->Com_Power->setCurrentIndex(list.at(0).toInt());
    } else if (str == QString(tr("driver"))) {
        ui->Com_Drive->setCurrentIndex(list.at(0).toInt());
    } else if (str == QString(tr("turn"))) {
        ui->Com_Turn->setCurrentIndex(list.at(0).toInt());
    } else {
        //
    }
}

void Widget_Noload::on_noloadTab_cellChanged(int row, int column)
{
    QString str;
    int i = 0, After_Point = 0;
    if (NoLoad_Init_Flag) {
        return;
    } else {
        //
    }
    NoLoad_Init_Flag = true;

    str = ui->noloadTab->item(row, column)->text();
    if (str == NULL) {
        ui->noloadTab->item(row, column)->setText("0");
    }
    for (i = 0; i < str.length(); i++) { //判断输入是" 0-9 . "
        if (((str[i] >= '0') && (str[i] <= '9')) || (str[i] == '.')) {
            //
        } else {
            ui->noloadTab->item(row, column)->setText("0");
            break;
        }
        if (str[i] == '.') { //  判断是否规范
            After_Point = str.length() - i - 1;
            if ((i == 0)) {
                ui->noloadTab->item(row, column)->setText("0");
            }
            if (i == (str.length()-1)) {
                ui->noloadTab->item(row, column)->setText\
                        (ui->noloadTab->item(row, column)->text().left(i));
            }
        }
    }
    if (column == 1) {
        if (ui->noloadTab->item(row, column)->text().toDouble() > 20) {
            ui->noloadTab->item(row, column)->setText("20.00");
        }
        ui->noloadTab->item(row, column)->setText\
                (QString::number(ui->noloadTab->item(row, column)->text().toDouble(), 'f', 2));
    }
    if (column == 2) {
        if (ui->noloadTab->item(row, column)->text().toDouble() > 300) {
            ui->noloadTab->item(row, column)->setText("300.0");
        }
        ui->noloadTab->item(row, column)->setText\
                (QString::number(ui->noloadTab->item(row, column)->text().toDouble(), 'f', 1));
    }
    if (column == 3) {
        if (ui->noloadTab->item(row, column)->text().toDouble() > 6000) {
            ui->noloadTab->item(row, column)->setText("6000.0");
        }
        ui->noloadTab->item(row, column)->setText\
                (QString::number(ui->noloadTab->item(row, column)->text().toDouble(), 'f', 1));
    }
    if (column == 4) {
        if (ui->noloadTab->item(row, column)->text().toDouble() > 30000) {
            ui->noloadTab->item(row, column)->setText("30000");
        }
        ui->noloadTab->item(row, column)->setText\
                (QString::number(ui->noloadTab->item(row, column)->text().toDouble(), 'f', 0));
    }
    if (column == 1) {
        if ((ui->noloadTab->item(0, 1)->text().toDouble()) > \
                (ui->noloadTab->item(1, 1)->text().toDouble())) {
            ui->noloadTab->item(0, 1)->setText("0.00");
        }
    }
    if (column == 2) {
        if ((ui->noloadTab->item(0, 2)->text().toDouble()) > \
                (ui->noloadTab->item(1, 2)->text().toDouble())) {
            ui->noloadTab->item(0, 2)->setText("0.0");
        }
    }
    if (column == 3) {
        if ((ui->noloadTab->item(0, 3)->text().toDouble()) > \
                (ui->noloadTab->item(1, 3)->text().toDouble())) {
            ui->noloadTab->item(0, 3)->setText("0.0");
        }
    }
    if (column == 4) {
        if ((ui->noloadTab->item(0, 4)->text().toDouble()) > \
                (ui->noloadTab->item(1, 4)->text().toDouble())) {
            ui->noloadTab->item(0, 4)->setText("0");
        }
    }

    NoLoad_Init_Flag = false;
}

void Widget_Noload::on_pushButton_clicked()
{
    Test_Widget->show();
}
