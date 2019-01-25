/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "Widget_BLOCK.h"
#include "ui_Widget_BLOCK.h"

Widget_BLOCK::Widget_BLOCK(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_BLOCK)
{
    ui->setupUi(this);

    //  堵转设置表头
    ui->dzTab->horizontalHeader()->setStyleSheet
            ("QHeaderView::section{background-color:#191919;color: white;"\
             "padding-left: 4px;border: 1px solid #447684;}");
    ui->dzTab->horizontalHeader()->setFixedHeight(25);
    ui->dzTab->horizontalHeader()->setResizeMode(QHeaderView::Fixed);
    ui->dzTab->setColumnWidth(0, 110);
    ui->dzTab->setColumnWidth(1, 110);
    ui->dzTab->setColumnWidth(2, 110);
    ui->dzTab->setColumnWidth(3, 110);
    // ui->dzTab->setColumnWidth(4, 60);

    EPAR_Init_Flag = 0;

    wave[0] = new wt_Wave(this);
    wave[0]->setStyleSheet("border-style:outset;border-width:1px;border-color:#447684;");
    wave[0]->Block_Point = 1;
    wave[0]->IMP_Point = 0;
    wave[0]->Block_Save_Point.clear();
    ui->waveLayout->addWidget(wave[0], 0);
    ui->label_hide->show();
    ui->label_hide->setStyleSheet("background-color:#191919");  // background-color:#191919;


    Collect_pwr_data.clear();     Collect_pwr_data_copy.clear();
    Collect_current_data.clear();
    Collect_Highest_Point = 255;
    Narrow_Proportion = 1;
    Update_Motor_Flag = 1;
    // ui->pushButton->hide();
    pushButton_Count = 0;
    wave_show_count = 0;

    ui->label_volt->hide();  ui->BLOCK_Volt->hide();
    ui->label_fre->hide();   ui->BLOCK_Fre->hide();
    ui->label_channel->hide(); ui->BLOCK_channel->hide();
    power_chose = 0;
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_Volt->hide();

    int i;
    Volt_Widget = new QWidget(this);
    Volt_Widget->setGeometry(110, 110, 500, 300);
    Volt_Widget->setWindowFlags(Qt::WindowStaysOnTopHint);
    Volt_Widget->setStyleSheet("border-radius: 10px;padding:2px 4px;background-color: gray;"\
                               "color: black;border-color: black;");
    QGridLayout *IO_upside = new QGridLayout;
    QString IO_table[1]={QString(tr("补偿数值(V):"))};

    QPushButton *IO_button_sample = new QPushButton;
    IO_button_sample->setText(tr("采集"));
    IO_button_sample->setMinimumHeight(50);
    IO_button_sample->setMinimumWidth(90);
    IO_button_sample->setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, "\
                                    "y2: 1,stop: 0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);");
    IO_upside->addWidget(IO_button_sample, 0, 0);
    connect(IO_button_sample, SIGNAL(clicked()), this, SLOT(Volt_sample()));

    for (i = 0; i < 1; i++) {
        IO_Show_Lable.append(new QLabel(this));
        IO_Show_Lable[i]->setText(IO_table[i]);
        IO_Show_Lable[i]->setMaximumHeight(35);
        IO_Show_Lable[i]->setMaximumWidth(135);
        IO_Show_Lable[i]->setAlignment(Qt::AlignCenter);
        IO_upside->addWidget(IO_Show_Lable[i], i, 1);
        if (i < 1) {
            Volt_Line_Text.append(new QDoubleSpinBox(this));
            Volt_Line_Text[i]->setMaximumHeight(35);
            Volt_Line_Text[i]->setMaximumWidth(100);
            // IO_Line_Text[i]->setMaximumWidth(51);
            Volt_Line_Text[i]->setDecimals(0);
            Volt_Line_Text[i]->setSingleStep(1);
            Volt_Line_Text[i]->setMaximum(20);
            Volt_Line_Text[i]->setMinimum(-20);
            Volt_Line_Text[i]->setAlignment(Qt::AlignCenter);
            Volt_Line_Text[i]->setButtonSymbols(QAbstractSpinBox::NoButtons);
            IO_upside->addWidget(Volt_Line_Text[i], i, 2);
        }
    }

    Volt_Back_Lable = new QLabel(this);
    Volt_Back_Lable->setText("");
    Volt_Back_Lable->setMaximumHeight(35); Volt_Back_Lable->setMaximumWidth(135);
    Volt_Back_Lable->setAlignment(Qt::AlignCenter);
    IO_upside->addWidget(Volt_Back_Lable, 1, 5);

    QPushButton *IO_button_quit = new QPushButton;
    IO_button_quit->setText(tr("退出"));
    IO_button_quit->setMinimumHeight(50);
    IO_button_quit->setMinimumWidth(90);
    IO_button_quit->setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, "\
                                  "y2: 1,stop: 0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);");
    IO_upside->addWidget(IO_button_quit, 0, 5);
    connect(IO_button_quit, SIGNAL(clicked()), this, SLOT(Volt_Widget_autoquit()));
    QVBoxLayout *Histogram_IO_Widget_layout = new QVBoxLayout;
    Histogram_IO_Widget_layout->addLayout(IO_upside);
    Volt_Widget->setLayout(Histogram_IO_Widget_layout);
    Volt_Widget->hide();

    Volt_Sample_ONE = false;
    Volt_ONE = 0;
}

Widget_BLOCK::~Widget_BLOCK()
{
    delete ui;
}

void Widget_BLOCK::Volt_sample() {
    double value_double;
    int value_int;

    value_double = 0.0;
    value_int = 0;
    value_double = ui->BLOCK_Volt->value();
    value_int = (value_double*10 + 5)/10;

    Volt_Sample_ONE = true;
    frame.can_id  = 0x27;  frame.can_dlc = 0x05;
    frame.data[0] = 0x03;                    // 堵转
    frame.data[1] = ui->DZ_grade->value();   // 档位
    frame.data[2] = 1000/10; // 时间
    frame.data[3] = ((4<<4)|(value_int/256)); // 电压
    frame.data[4] = value_int%256;
    canSend(frame);
}

void  Widget_BLOCK::Pri_Test_Two() {
    double value_double;
    int value_int;

    value_double = 0.0;
    value_int = 0;
    value_double = (ui->BLOCK_Volt->value() + Volt_Line_Text[0]->value());
    value_int = (value_double*10 + 5)/10;

    Volt_Back_Lable->setText("");
    frame.can_id  = 0x27;  frame.can_dlc = 0x05;
    frame.data[0] = 0x03;                    // 堵转
    frame.data[1] = ui->DZ_grade->value();   // 档位
    frame.data[2] = 1000/10; // 时间
    frame.data[3] = ((4<<4)|(value_int/256)); // 电压
    frame.data[4] = value_int%256;
    canSend(frame);
}


void Widget_BLOCK::Volt_Widget_autoquit() {
    Volt_Widget->hide();
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.11.5
  * brief:      初始化堵转设置
******************************************************************************/
void Widget_BLOCK::Pri_BLOCK_Init()
{
    int i;
    EPAR_Init_Flag = 1;
    QStringList lisit; lisit <<  QString(tr("上限")) <<  QString(tr("下限"));
    ui->dzTab->setRowCount(2);
    DZ_QTableWidgetItem.clear();
    for (i = 0; i < 2; i++) {
        DZ_QTableWidgetItem.append(new QTableWidgetItem);
        DZ_QTableWidgetItem[i]->setTextAlignment(Qt::AlignCenter);
        DZ_QTableWidgetItem[i]->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        DZ_QTableWidgetItem[i]->setText(lisit.at(i));
        ui->dzTab->setItem(i, 0, DZ_QTableWidgetItem[i]);
    }

    // 堵转
    ui->BLOCK_Volt->setValue(Copy_BLOCK_List.at(200).toInt());   //  堵转外部电源电压
    ui->DZ_time->setValue(Copy_BLOCK_List.at(201).toInt());   //  堵转时间
    ui->DZ_grade->setValue(Copy_BLOCK_List.at(202).toInt());  //  堵转档位
    ui->BLOCK_Fre->setValue(Copy_BLOCK_List.at(206).toInt());
    ui->BLOCK_channel->setValue(Copy_BLOCK_List.at(207).toInt());

    Volt_Line_Text[0]->setValue(Copy_BLOCK_List.at(208).toInt());

    ui->DZ_Cycle->setValue(Copy_BLOCK_List.at(203).toInt());
    ui->label_current->setText(QString(tr("电流:")) + \
                               QString::number(Copy_BLOCK_List.at(204).toInt()));
    ui->label_pwr->setText(QString(tr("功率:"))+QString::number(Copy_BLOCK_List.at(205).toInt()));
    for (i = 0; i < 2; i++) {
        QTableWidgetItem *dz_volt = new QTableWidgetItem;     // 电压
        dz_volt->setTextAlignment(Qt::AlignCenter);
        dz_volt->setText(Copy_BLOCK_List.at(210+i*10));
        ui->dzTab->setItem(i, 1, dz_volt);
        QTableWidgetItem *dz_current = new QTableWidgetItem;  // 电流
        dz_current->setTextAlignment(Qt::AlignCenter);
        dz_current->setText(Copy_BLOCK_List.at(211+i*10));
        ui->dzTab->setItem(i, 2, dz_current);
        QTableWidgetItem *dz_pwr = new QTableWidgetItem;      // 功率
        dz_pwr->setTextAlignment(Qt::AlignCenter);
        dz_pwr->setText(Copy_BLOCK_List.at(212+i*10));
        ui->dzTab->setItem(i, 3, dz_pwr);
        //      QTableWidgetItem *dz_time = new QTableWidgetItem;     // 时间
        //      dz_time->setTextAlignment(Qt::AlignCenter);
        //      dz_time->setText(Copy_BLOCK_List.at(213+i*10));
        //      ui->dzTab->setItem(i, 4, dz_time);
    }
    EPAR_Init_Flag = 0;
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2015.12.30
  * brief:      保存 BLOCK 配置
******************************************************************************/
void Widget_BLOCK::Pri_BLOCK_Data_Save()
{
    int i;
    //  保存堵转
    Copy_BLOCK_List.replace(200, QString::number(ui->BLOCK_Volt->value()));
    Copy_BLOCK_List.replace(201, QString::number(ui->DZ_time->value()));
    Copy_BLOCK_List.replace(202, QString::number(ui->DZ_grade->value()));
    Copy_BLOCK_List.replace(203, ui->DZ_Cycle->text());
    Copy_BLOCK_List.replace(204, ui->label_current->text().remove(QString(tr("电流:"))));
    Copy_BLOCK_List.replace(205, ui->label_pwr->text().remove(QString(tr("功率:"))));
    Copy_BLOCK_List.replace(206, QString::number(ui->BLOCK_Fre->value()));
    Copy_BLOCK_List.replace(207, QString::number(ui->BLOCK_channel->value()));
    Copy_BLOCK_List.replace(208, QString::number(Volt_Line_Text[0]->value()));

    for (i = 0; i < 2; i++) {
        Copy_BLOCK_List.replace(210 + i*10, ui->dzTab->item(i, 1)->text());
        Copy_BLOCK_List.replace(211 + i*10, ui->dzTab->item(i, 2)->text());
        Copy_BLOCK_List.replace(212 + i*10, ui->dzTab->item(i, 3)->text());
        // Copy_BLOCK_List.replace(213+i*10, ui->dzTab->item(i, 4)->text());
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.11.5
  * brief:      Conf 配置 BLOCK 界面
******************************************************************************/
void Widget_BLOCK::Pub_Conf_Set_BLOCK(QString str, int value, int flag)
{
    switch (flag) {
    case 1:
        Pri_BLOCK_Init();
        break;
    case 2:
        Pri_BLOCK_Data_Save();
        break;
    case 3:
        Pri_BLOCK_Display();
        break;
    case 4:
        Pub_Conf_power_chose(str.toInt());
        break;
    case 5:
        if (value >= Collect_Highest_Point) {
            Collect_Highest_Point = value;
        }
        Collect_current_data.append(str);
        Collect_pwr_data.append(QString::number(value));
        break;
    case 6:
        Volt_Widget->hide();
        pushButton_Count = 0;
        ui->pushButton_3->setDisabled(true);
        ui->pushButton_3->setStyleSheet("color: red;");
        break;
    case 7:
        Volt_Back_Lable->setText(QString::number(str.toDouble()/10, 'f', 0));
        break;
    case 8:
        if (Volt_Sample_ONE) {
            Volt_Sample_ONE = false;
            Volt_Line_Text[0]->setValue((ui->BLOCK_Volt->value()) - \
                                        Volt_Back_Lable->text().toInt());
            Volt_ONE = (ui->BLOCK_Volt->value())-Volt_Back_Lable->text().toInt();
            Pri_Test_Two();
        } else {
            Volt_Line_Text[0]->setValue((ui->BLOCK_Volt->value()) - \
                                        Volt_Back_Lable->text().toInt() + Volt_ONE);
            Volt_Back_Lable->setText(QString(tr("Ok")));
        }
        break;
    case 100:
        if (str.toInt()) {
            ui->DZ_grade->setMaximum(4);
        } else {
            //
        }
        break;
    default:
        break;
    }
}
void Widget_BLOCK::Pub_Conf_power_chose(int value)
{
    power_chose = value;
    if (value == 0) {
        //
    } else if (value == 1) {
        ui->label_volt->show();    ui->BLOCK_Volt->show();
        ui->label_fre->show();     ui->BLOCK_Fre->show();
    } else if (value == 2) {
        ui->label_channel->show(); ui->BLOCK_channel->show();
    } else if (value == 3) {
        ui->label_volt->show();    ui->BLOCK_Volt->show();
    } else if (value == 4) {
        ui->label_volt->show();    ui->BLOCK_Volt->show();
        ui->pushButton_Volt->show();
    } else {
        //
    }
}
void Widget_BLOCK::Pri_BLOCK_Display()
{
    int i, k;
    if (Update_Motor_Flag == 1) {
        Update_Motor_Flag = 0;
        Narrow_Proportion = Collect_Highest_Point/256+1;
        Collect_Cycle = Collect_pwr_data.size();
    }

    if (Collect_pwr_data.size() > Collect_Cycle) {
        for (i = Collect_pwr_data.size(); i > Collect_Cycle; i--) {
            Collect_pwr_data.removeAt(i - 1);
            Collect_current_data.removeAt(i - 1);
        }
    } else if (Collect_pwr_data.size() < Collect_Cycle) {
        for (i = Collect_pwr_data.size(); i < Collect_Cycle; i++) {
            Collect_pwr_data.append("0");
            Collect_current_data.append("0");
        }
    }
    for (k = 0; k < Collect_pwr_data.size(); k++) {
        wave[0]->point[k] = Collect_pwr_data.at(k).toInt()/Narrow_Proportion;
        wave[0]->pointgreen[k]  = 260;
    }
    wave[0]->num = Collect_pwr_data.size();
    wave[0]->update();
    Collect_pwr_data_copy.append(Collect_pwr_data);
    Collect_pwr_data.clear();
    Collect_Highest_Point = 255;
    ui->pushButton->setText(tr("采集"));
}
void Widget_BLOCK::on_dzTab_cellChanged(int row,  int column)
{
    QString str;
    int i, After_Point = 0;
    if (EPAR_Init_Flag == 0) {
        EPAR_Init_Flag = 1;
        str = ui->dzTab->item(row, column)->text();
        if (str == NULL) {
            ui->dzTab->item(row, column)->setText("0");
        }
        for (i = 0; i < str.length(); i++) { // 判断输入是" 0-9 . "
            if (((str[i] >= '0') && (str[i] <= '9')) || (str[i] == '.')) {
                //
            } else {
                ui->dzTab->item(row, column)->setText("0");
                break;
            }
            if (str[i] == '.') { //  判断是否规范
                After_Point = str.length()-i-1;
                if ((i == 0)) {
                    ui->dzTab->item(row, column)->setText("0");
                }
                if (i == (str.length()-1)) {
                    ui->dzTab->item(row, column)->setText\
                            (ui->dzTab->item(row, column)->text().left(i));
                }
            }
        }

        if (column == 1) { // 电压
            if (ui->dzTab->item(row, column)->text().toDouble() < 1) {
                ui->dzTab->item(row, column)->setText("1");
            } else if (ui->dzTab->item(row, column)->text().toDouble() > 255) {
                ui->dzTab->item(row, column)->setText("255");
            }
            ui->dzTab->item(row, column)->setText\
                    (QString::number(ui->dzTab->item(row, column)->text().toDouble(), 'f', 0));
        }
        if (column == 2) { // 电流
            if (ui->dzTab->item(row, column)->text().toDouble() < 0.001) {
                ui->dzTab->item(row, column)->setText("0.001");
            } else if (ui->dzTab->item(row, column)->text().toDouble() > 5.500) {
                ui->dzTab->item(row, column)->setText("5.000");
            }
            ui->dzTab->item(row, column)->setText\
                    (QString::number(ui->dzTab->item(row, column)->text().toDouble(), 'f', 3));
        }
        if (column == 3) { //功率
            if (ui->dzTab->item(row, column)->text().toDouble() < 0.1) {
                ui->dzTab->item(row, column)->setText("0.1");
            } else if (ui->dzTab->item(row, column)->text().toDouble() > 1275) {
                ui->dzTab->item(row, column)->setText("1275.0");
            }
            ui->dzTab->item(row, column)->setText\
                    (QString::number(ui->dzTab->item(row, column)->text().toDouble(), 'f', 1));
        }

        if (column == 1) { // 电压
            if ((ui->dzTab->item(0, 1)->text().toDouble()) <
                    (ui->dzTab->item(1, 1)->text().toDouble())) {
                ui->dzTab->item(1, 1)->setText("1");
            }
        }
        if (column == 2) { // 电流
            if ((ui->dzTab->item(0, 2)->text().toDouble()) < \
                    (ui->dzTab->item(1, 2)->text().toDouble())) {
                ui->dzTab->item(1, 2)->setText("0.001");
            }
        }
        if (column == 3) { // 功率
            if ((ui->dzTab->item(0, 3)->text().toDouble()) < \
                    (ui->dzTab->item(1, 3)->text().toDouble())) {
                ui->dzTab->item(1, 3)->setText("0.1");
            }
        }
        EPAR_Init_Flag = 0;
    }
}
void Widget_BLOCK::on_pushButton_clicked()
{
    int fre;
    double value_double;
    int value_int;

    value_int = 0;
    if (ui->BLOCK_Fre->text().toInt() == 60) {
        fre = 1 <<  1;
    } else {
        fre = 0 <<  1;
    }
    if (ui->pushButton->text() == QString(tr("采集"))) {
        wave[0]->num = 0;
        wave[0]->update();
        ui->pushButton->setText(tr("请等待.."));
        value_double = ui->BLOCK_Volt->value();
        value_int = (value_double*10 + 5)/10;
        frame.can_id  = 0x27;  frame.can_dlc = 0x05;
        frame.data[0] = 0x03;                    // 堵转
        frame.data[1] = ui->DZ_grade->value();   // 档位
        frame.data[2] = ui->DZ_time->value()/10; // 时间
        if (power_chose == 0) { // 空电源
            frame.data[3] = 0x00; // 电压
            frame.data[4] = 0x00;
        } else if (power_chose == 1) { // 吉利电源
            frame.data[3] = ((1 <<  4)|(fre)|(value_int/256)); // 电压
            frame.data[4] = value_int%256;
        } else if (power_chose == 2) { // 外部电源板
            frame.data[3] = (2 <<  4); // 电压
            frame.data[4] = (ui->BLOCK_channel->text().toInt());
        } else if (power_chose == 3) { // 变压器方案
            frame.data[3] = ((3 <<  4)|(value_int/256)); // 电压
            frame.data[4] = value_int%256;
        } else if (power_chose == 4) { // 内部方案
            frame.data[3] = ((4<<4)|(value_int/256)); // 电压
            frame.data[4] = value_int%256;
        } else {
            frame.data[3] = 0x00; // 电压
            frame.data[4] = 0x00;
        }
        canSend(frame);
    }
    pushButton_Count++;
    if (pushButton_Count >= 10) {
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_3->setStyleSheet("color: green;");
    }
}
void Widget_BLOCK::on_pushButton_2_clicked()
{
    Update_Motor_Flag = 1;
    wave[0]->Block_Save_Point.clear();
    Collect_pwr_data_copy.clear();
    ui->DZ_Cycle->setValue(0);
    ui->label_current->setText(QString(tr("电流:")));
    ui->label_pwr->setText(QString(tr("功率:")));
}
void Widget_BLOCK::on_pushButton_3_clicked()
{
    int i, k;
    int Trough, Trough_Point;  // 波谷
    int average_data = 0, variance = 0;
    int wave_avage = wave[0]->Block_Save_Point.size()/Collect_Cycle;
    pushButton_Count = 0;
    ui->pushButton_3->setDisabled(true);
    ui->pushButton_3->setStyleSheet("color: red;");
    QStringList Collect_pwr_one_cycle_average;
    Collect_pwr_one_cycle_average.clear();
    if (wave[0]->Block_Save_Point.size() != 0) {  //  Collect_pwr_one_cycle_average 平均数
        Trough = 0;
        for (k = 0; k < Collect_Cycle; k++) {
            average_data = 0;
            variance = 0;
            for (i = 0; i < wave_avage; i++) {
                average_data += wave[0]->Block_Save_Point.at(i*Collect_Cycle+k).toInt();
            }
            average_data = average_data/wave_avage;   // 得到平均数

            for (i = 0; i < wave_avage; i++) { // 求取方差
                variance += ((average_data-wave[0]->Block_Save_Point.at\
                             (i*Collect_Cycle+k).toInt()))*((average_data-wave[0]->\
                              Block_Save_Point.at(i*Collect_Cycle+k).toInt()));
            }
            variance = variance / wave_avage;
            Collect_pwr_one_cycle_average.append(QString::number(variance));
            Collect_pwr_one_cycle_average.append(" ");
        }
        ui->textEdit->setText(Collect_pwr_one_cycle_average.join(" "));
        for (i = 0; i < Collect_pwr_one_cycle_average.size(); i++) {
            Collect_pwr_one_cycle_average.removeAll(" ");
        }

        Collect_pwr_one_cycle_average.removeAt(Collect_pwr_one_cycle_average.size()-1);
        Collect_pwr_one_cycle_average.removeAt(1); // 2017.5.26 取消掉操作
        Collect_pwr_one_cycle_average.removeAt(0);


        double pwr_stable_average = 0; // 功率平均数
        for (i = 0; i < wave_avage; i++) {
            pwr_stable_average += Collect_pwr_data_copy.at(i*Collect_Cycle+Collect_Cycle-1).toInt();
        }
        pwr_stable_average = pwr_stable_average/wave_avage;


        Trough = Collect_pwr_one_cycle_average.at(0).toInt(); // 方差最小的波谷
        Trough_Point = 2; // 波谷测试点
        for (i = 0; i < Collect_pwr_one_cycle_average.size() - 1; i++) {
            if (Collect_pwr_data_copy.at((wave_avage-1)*Collect_Cycle + \
                                         Trough_Point-1).toInt() < pwr_stable_average) {
                Trough = Collect_pwr_one_cycle_average.at(i+1).toInt();
                Trough_Point = i+3;
                continue;
            } else {
                //
            }
            if ((Trough > Collect_pwr_one_cycle_average.at(i+1).toInt()) && \
                    (Collect_pwr_data_copy.at((wave_avage-1)*Collect_Cycle + \
                    Trough_Point+1).toInt() > (2*pwr_stable_average))) {
                Trough = Collect_pwr_one_cycle_average.at(i+1).toInt();
                Trough_Point = i+3;
            } else if (Trough < Collect_pwr_one_cycle_average.at(i+1).toInt()) {
                break;
            } else if (Trough == 0) {
                break;
            } else {
                //
            }
        }
        ui->DZ_Cycle->setValue(Trough_Point+1);

        // 求取----------电流平均数 功率平均数------------
        double current_average = 0;
        for (i = 0; i < wave_avage; i++) { // 电流平均谁
            current_average += Collect_current_data.at(i*Collect_Cycle+Trough_Point).toInt();
        }
        current_average = current_average/wave_avage;
        ui->label_current->setText(QString(tr("电流:")) + \
                                   QString::number(current_average/1000, 'f', 3));

        double pwr_average = 0; // 功率平均数
        for (i = 0; i < wave_avage; i++) {
            pwr_average += Collect_pwr_data_copy.at(i*Collect_Cycle+Trough_Point).toInt();
        }
        pwr_average = pwr_average/wave_avage;
        ui->label_pwr->setText(QString(tr("功率:"))+QString::number(pwr_average/10, 'f', 1));
    }
}

void Widget_BLOCK::on_toolButton_4_clicked()
{
    wave_show_count++;
    if (wave_show_count == 12) {
        ui->label_hide->hide();
        wave[0]->show();
        ui->textEdit->show();
    } else {
        ui->label_hide->show();
        wave[0]->hide();
        ui->textEdit->hide();
    }
}
QStringList Widget_BLOCK::BLOCK_Test_Param()
{
    QString str;
    QStringList  strSql;
    QStringList strParam, strTest;
    strTest.clear();
    strParam.clear();

    str = QString(tr("堵转"));
    strTest.append(str);
    str ="I:"+Copy_BLOCK_List.at(211)+"A,"+"P:"+Copy_BLOCK_List.at(212)+"W";
    strSql.append(tr("堵转"));
    strParam.append(str);

    QStringList Back_List;
    Back_List.append(QString::number(strTest.size()));
    Back_List.append(QString::number(strParam.size()));
    Back_List.append(QString::number(strSql.size()));
    Back_List.append(strTest);
    Back_List.append(strParam);
    Back_List.append(strSql);
    return Back_List;
}
void Widget_BLOCK::on_pushButton_Volt_clicked()
{
    Volt_Widget->show();
}
