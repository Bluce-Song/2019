/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "Widget_IR.h"
#include "ui_Widget_IR.h"

Widget_IR::Widget_IR(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_IR)
{
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint); // 去掉标题栏
    ui->setupUi(this);

    ui->IrTab->horizontalHeader()->setStyleSheet\
            ("QHeaderView::section{background-color:#191919;color: white;"
             "padding-left: 4px;border: 1px solid #447684;}");
    ui->IrTab->horizontalHeader()->setFixedHeight(35);
    ui->IrTab->horizontalHeader()->setResizeMode(QHeaderView::Fixed);
    ui->IrTab->setColumnWidth(0, 48);
    ui->IrTab->setColumnWidth(1, 80);
    ui->IrTab->setColumnWidth(2, 90);
    ui->IrTab->setColumnWidth(3, 75);
    ui->IrTab->setColumnWidth(4, 90);
    ui->IrTab->setColumnWidth(5, 90);
    ui->IrTab->setColumnWidth(6, 75);
    ui->IrTab->setColumnWidth(7, 75);

    IR_btnGroup = new QButtonGroup;
    IR_btnGroup->addButton(ui->OK, 1);
    connect(IR_btnGroup, SIGNAL(buttonClicked(int)), this, SLOT(join_buttonJudge(int)));
    ui->OK->hide();

    Box_All_List.clear();
    Box_All_List.append(ui->checkBox_1);
    Box_All_List.append(ui->checkBox_2);
    Box_All_List.append(ui->checkBox_3);
    Box_All_List.append(ui->checkBox_4);
    Box_All_List.append(ui->checkBox_5);
    Box_All_List.append(ui->checkBox_6);
    Box_All_List.append(ui->checkBox_7);
    Box_All_List.append(ui->checkBox_8);
    Box_All_List.append(ui->checkBox_9);
    Box_All_List.append(ui->checkBox_10);

    ui->checkBox_1->hide();
    ui->checkBox_2->hide();
    ui->checkBox_3->hide();
    ui->checkBox_4->hide();
    ui->checkBox_5->hide();
    ui->checkBox_6->hide();
    ui->checkBox_7->hide();
    ui->checkBox_8->hide();
    ui->checkBox_9->hide();
    ui->checkBox_10->hide();

    IR_Labelhide = new QLabel(this);
    IR_Labelhide->setGeometry(0, 0, 800, 600);
    IR_Labelhide->hide();

    ui->IrTab->move(5, 90);
    ui->IrTab->hide();
    ui->widget->move(90, 140);
    ui->widget->hide();
    ui->dockwidget->move(210, 0);

    IR_Test_Total = 0;
    IR_Compensate_Flag = false;
    ACW_Between_IR = false;
    Init_Flag = false;
    Init_Channel_6 = false;
    ui->doubleSpinBox_Compensate->setDisabled(true);
    Line_HV = false;
    Line_HV_High = "";
    Line_HV_Low = "";
}


Widget_IR::~Widget_IR()
{
    delete ui;
}

void Widget_IR::join_buttonJudge(int) {
    int i;
    QStringList check;
    QString sendcheck;
    ui->dockwidget->hide();  IR_Labelhide->hide();
    for (i = 0; i < Box_All_List.size()-2; i++) {
        if (Box_All_List.at(i)->checkState() == 2) {
            check.append(QString::number(i + 1));
            sendcheck = check.join("");
        }
    }
    if (Box_All_List.at(9)->checkState() == 2) {
        ui->IrTab->currentItem()->setText("12345678");
    } else if (Box_All_List[8]->checkState() == 2) {
        ui->IrTab->currentItem()->setText("PE");
    } else {
        if (sendcheck == tr("")) {
            ui->IrTab->currentItem()->setText("1");
        } else {
            ui->IrTab->currentItem()->setText(sendcheck);
        }
    }
}

void Widget_IR::Pri_IR_Group_Two() {
    int j;
    QStringList T1_H; // -高端
    QStringList T2_H; // -低端
    int T1_H_Data = 0;
    int T2_H_Data = 0;
    IR_Volt.clear(); IR_Volt << "500" << "1000"; // 绝缘电压

    frame.can_id  = 0x23;
    frame.can_dlc = 0x08;
    frame.data[0] = 0x03; // -绝缘测试参数1
    frame.data[1] = 0x0B; // -测试组号
    frame.data[2] = 0x04; // -测试INS
    if (Line_HV) {
        T1_H_Data = 0;
        T1_H = Line_HV_High.split("");
        for (j = 1; j < T1_H.size() - 1; j++) {
            T1_H_Data = T1_H_Data | (1 << (T1_H.at(j).toInt() - 1));
        }
        frame.data[3] = 0x00; //-高压端
        frame.data[4] = T1_H_Data;

        /*低端can协议*/
        T2_H_Data = 0;
        T2_H = Line_HV_Low.split("");
        for (j = 1; j < T2_H.size() - 1; j++) {
            T2_H_Data = T2_H_Data | (1 << (T2_H.at(j).toInt() - 1));
        }
        frame.data[5] = 0x00; // -低压端
        frame.data[6] = T2_H_Data;
    } else {
        frame.data[3] = 0x80; // -高压端
        frame.data[4] = 0x00;
        frame.data[5] = 0xff; // -低压端
        frame.data[6] = 0xff;
    }
    frame.data[7] = 0x00; // -频率
    canSend(frame);

    frame.can_id  = 0x23;
    frame.can_dlc = 0x08;
    frame.data[0] = 0x04; // -绝缘测试参数2
    frame.data[1] = 0x0B; // -测试组号
    frame.data[2] = IR_Volt.at(Copy_IR_List[25].toInt()).toInt()/256;
    frame.data[3] = IR_Volt.at(Copy_IR_List[25].toInt()).toInt()%256;
    frame.data[4] = int(Copy_IR_List.at(26).toDouble()*10)/256; // -测试时间 -
    frame.data[5] = int(Copy_IR_List.at(26).toDouble()*10)%256;
    if (IRHostJudge == 2) {
        frame.data[6] = 1/256; // -下限绝缘单位0.1MΩ
        frame.data[7] = 1%256;
    } else {
        frame.data[6] = Copy_IR_List.at(27).toInt()/256; // -下限绝缘单位0.1MΩ
        frame.data[7] = Copy_IR_List.at(27).toInt()%256;
    }
    canSend(frame);

    frame.can_id  = 0x23;
    frame.can_dlc = 0x07;
    frame.data[0] = 0x05; // -绝缘测试参数3
    frame.data[1] = 0x0B; // -测试组号
    if (IRHostJudge == 2) {
        frame.data[2] = 0/256; // -上限绝缘单位0.1MΩ  // Copy_IR_List.at(2).toInt()/256
        frame.data[3] = 0%256;
    } else {
        frame.data[2] = Copy_IR_List.at(28).toInt()/256;
        frame.data[3] = Copy_IR_List.at(28).toInt()%256; // -上限绝缘单位0.1MΩ
    }
    frame.data[4] = 0x00; // -电弧等级
    frame.data[5] = 0x03; // -缓升
    frame.data[6] = 0x0a; // -缓降
    canSend(frame);
}

void Widget_IR::Pri_IR_Group_One() {
    int j;
    QStringList T1_H; // -高端
    QStringList T2_H; // -低端
    int T1_H_Data = 0;
    int T2_H_Data = 0;
    IR_Volt.clear(); IR_Volt << "500" << "1000"; // 绝缘电压

    frame.can_id  = 0x23;
    frame.can_dlc = 0x08;
    frame.data[0] = 0x03; // -绝缘测试参数1
    frame.data[1] = 0x01; // -测试组号
    frame.data[2] = 0x04; // -测试INS
    if (Line_HV) {
        T1_H_Data = 0;
        T1_H = Line_HV_High.split("");
        for (j = 1; j < T1_H.size() - 1; j++) {
            T1_H_Data = T1_H_Data | (1 << (T1_H.at(j).toInt() - 1));
        }
        frame.data[3] = 0x00; //-高压端
        frame.data[4] = T1_H_Data;

        /*低端can协议*/
        T2_H_Data = 0;
        T2_H = Line_HV_Low.split("");
        for (j = 1; j < T2_H.size() - 1; j++) {
            T2_H_Data = T2_H_Data | (1 << (T2_H.at(j).toInt() - 1));
        }
        frame.data[5] = 0x00; // -低压端
        frame.data[6] = T2_H_Data;
    } else {
        frame.data[3] = 0x80; // -高压端
        frame.data[4] = 0x00;
        frame.data[5] = 0xff; // -低压端
        frame.data[6] = 0xff;
    }
    frame.data[7] = 0x00; // -频率
    canSend(frame);

    frame.can_id  = 0x23;
    frame.can_dlc = 0x08;
    frame.data[0] = 0x04; // -绝缘测试参数2
    frame.data[1] = 0x01; // -测试组号
    frame.data[2] = IR_Volt.at(Copy_IR_List[20].toInt()).toInt()/256;
    frame.data[3] = IR_Volt.at(Copy_IR_List[20].toInt()).toInt()%256;
    frame.data[4] = int(Copy_IR_List.at(21).toDouble()*10)/256; // -测试时间 -
    frame.data[5] = int(Copy_IR_List.at(21).toDouble()*10)%256;
    if (IRHostJudge == 2) {
        frame.data[6] = 1/256; // -下限绝缘单位0.1MΩ
        frame.data[7] = 1%256;
    } else {
        frame.data[6] = Copy_IR_List.at(22).toInt()/256; // -下限绝缘单位0.1MΩ
        frame.data[7] = Copy_IR_List.at(22).toInt()%256;
    }
    canSend(frame);

    frame.can_id  = 0x23;
    frame.can_dlc = 0x07;
    frame.data[0] = 0x05; // -绝缘测试参数3
    frame.data[1] = 0x01; // -测试组号
    if (IRHostJudge == 2) {
        frame.data[2] = 0/256; // -上限绝缘单位0.1MΩ  // Copy_IR_List.at(2).toInt()/256
        frame.data[3] = 0%256;
    } else {
        frame.data[2] = Copy_IR_List.at(23).toInt()/256;
        frame.data[3] = Copy_IR_List.at(23).toInt()%256; // -上限绝缘单位0.1MΩ
    }
    frame.data[4] = 0x00; // -电弧等级
    frame.data[5] = 0x03; // -缓升
    frame.data[6] = 0x0a; // -缓降
    canSend(frame);
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.3.11
  * brief:      测试绝缘新协议
******************************************************************************/
void Widget_IR::Pri_IR_Test(QString str, int value)
{
    int i,  j;
    QStringList T1_H; // -高端
    QStringList T2_H; // -低端
    int T1_H_Data = 0;
    int T2_H_Data = 0;
    IRgroup_num.clear();
    IR_Test_Total = 0;
    IRHostJudge = str.toInt();
    if (ACW_Between_IR) {
        for (i = 0; i < 4; i++) {
            if (Box_IR_list.at(i)->checkState() != 2) {
                continue;
            }
            frame.can_id  = 0x23;
            frame.can_dlc = 0x08;
            frame.data[0] = 0x03;
            frame.data[1] = i + 4; //-测试组号
            frame.data[2] = 0x04;
            if (Copy_IR_List.at(30+i*10) == "PE") {
                frame.data[3] = 0x80; //-高压端
                frame.data[4] = 0x00;
            } else {
                /*高端can协议*/
                T1_H_Data = 0;
                T1_H =  Copy_IR_List.at(30 + i*10).split("");
                for (j = 1; j < T1_H.size() - 1; j++) {
                    T1_H_Data = T1_H_Data | (1 << (T1_H.at(j).toInt() - 1));
                }
                frame.data[3] = 0x00; //-高压端
                frame.data[4] = T1_H_Data;
            }

            if (Copy_IR_List.at(31+i*10) == "PE") {
                frame.data[5] = 0x7f; //-低压端
                frame.data[6] = 0xff;
            } else {
                /*低端can协议*/
                T2_H_Data = 0;
                T2_H = Copy_IR_List.at(31 + i*10).split("");
                for (j = 1; j < T2_H.size() - 1; j++) {
                    T2_H_Data = T2_H_Data | (1 << (T2_H.at(j).toInt() - 1));
                }
                frame.data[5] = 0x00; // -低压端
                frame.data[6] = T2_H_Data;
            }
            frame.data[7] = 0x00;
            canSend(frame);

            frame.can_id  = 0x23;
            frame.can_dlc = 0x08;
            frame.data[0] = 0x04; // -绝缘测试参数2
            frame.data[1] = i + 4; // -测试组号
            frame.data[2] = (Copy_IR_List.at(32 + i*10).toInt()%2*500 + 500)/256;
            frame.data[3] = (Copy_IR_List.at(32 + i*10).toInt()%2*500 + 500)%256;
            frame.data[4] = int(Copy_IR_List.at(35 + i*10).toDouble()*10)/256; // -测试时间
            frame.data[5] = int(Copy_IR_List.at(35 + i*10).toDouble()*10)%256;
            frame.data[6] = Copy_IR_List.at(33 + i*10).toInt()/256;
            // -下限耐压单位0.01mA，绝缘单位0.1MΩ
            frame.data[7] = Copy_IR_List.at(33 + i*10).toInt()%256;
            canSend(frame);

            frame.can_id  = 0x23;
            frame.can_dlc = 0x07;
            frame.data[0] = 0x05; // -绝缘测试参数3
            frame.data[1] = i + 4; // -测试组号
            frame.data[2] = Copy_IR_List.at(34+i*10).toInt()/256;
            frame.data[3] = Copy_IR_List.at(34+i*10).toInt()%256;
            // -上限耐压单位0.01mA，绝缘单位0.1MΩ
            frame.data[4] = 0x00; // -电弧等级
            frame.data[5] = 0x03; // -缓升
            frame.data[6] = 0x0a; // -缓降
            canSend(frame);

            IR_Test_Total++;
            IRgroup_num.append(QString::number(i + 4));
        }
    } else {
        if (value == 1) {
           Pri_IR_Group_One();
        } else {
           Pri_IR_Group_Two();
        }
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      初始化绝缘设置
******************************************************************************/
void Widget_IR::Pri_IR_Init(QString str)
{
    int i;
    IR_Volt.clear(); IR_Volt << "500" << "1000"; // 绝缘电压
    Init_Flag = true;
    ui->IrTab->setRowCount(4);
    ui->IrTab->setColumnCount(9);

    Box_IR_list.clear();
    ACW_Between_IR = str.toInt();
    if (ACW_Between_IR) {
        ui->IrTab->show();  ui->IrTab->raise();
        ui->widget->hide();
    } else {
        ui->widget->show(); ui->widget->raise();
        ui->IrTab->hide();
    }
    for (i = 0; i < 4; i++) {
        //初始化输入框
        QTableWidgetItem *ppItem = new QTableWidgetItem;
        ppItem->setTextAlignment(Qt::AlignCenter);
        ppItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ppItem->setText(QString::number((i+1)));
        ui->IrTab->setItem(i, 0, ppItem);

        IR_H.append(new QTableWidgetItem);
        IR_H[i]->setTextAlignment(Qt::AlignCenter);
        IR_H[i]->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        IR_H[i]->setText(Copy_IR_List.at(30+i*10));
        ui->IrTab->setItem(i, 1, IR_H[i]);

        IR_L.append(new QTableWidgetItem);
        IR_L[i]->setTextAlignment(Qt::AlignCenter);
        IR_L[i]->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        IR_L[i]->setText(Copy_IR_List.at(31+i*10));
        ui->IrTab->setItem(i, 2, IR_L[i]);

        IR_vola.append(new QTableWidgetItem);
        IR_vola[i]->setTextAlignment(Qt::AlignCenter);
        IR_vola[i]->setText(IR_Volt.at(Copy_IR_List.at(32+i*10).toInt()%2));
        IR_vola[i]->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ui->IrTab->setItem(i, 3, IR_vola[i]);

        IR_bres.append(new QTableWidgetItem);
        IR_bres[i]->setTextAlignment(Qt::AlignCenter);
        IR_bres[i]->setText(Copy_IR_List.at(33+i*10));
        ui->IrTab->setItem(i, 4, IR_bres[i]);

        IR_pres.append(new QTableWidgetItem);
        IR_pres[i]->setTextAlignment(Qt::AlignCenter);
        IR_pres[i]->setText(Copy_IR_List.at(34+i*10));
        ui->IrTab->setItem(i, 5, IR_pres[i]);

        IR_time.append(new QTableWidgetItem);
        IR_time[i]->setTextAlignment(Qt::AlignCenter);
        IR_time[i]->setText(Copy_IR_List.at(35+i*10));
        ui->IrTab->setItem(i, 6, IR_time[i]);

        IR_compensate.append(new QTableWidgetItem);
        IR_compensate[i]->setTextAlignment(Qt::AlignCenter);
        IR_compensate[i]->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        IR_compensate[i]->setText("*");
        ui->IrTab->setItem(i, 7, IR_compensate[i]);

        Box_IR_list.append(new QCheckBox);
        Box_IR_list[i]->setStyleSheet\
                ("QCheckBox::indicator {image: url(:/image/053.png);"\
                 "width: 58px;height: 55px;}QCheckBox::indicator:checked "\
                 "{image: url(:/image/051.png);}");
        if (Copy_IR_List.at(36 + i*10).toInt() == 2) {
            Box_IR_list[i]->setChecked(true);
        }

        ui->IrTab->setRowHeight(i, 70);
        ui->IrTab->setCellWidget(i, 8, Box_IR_list[i]);
    }


    ui->doubleSpinBox_IR_Time->setMaximum(999.9);  // 1.0-999.9s
    ui->doubleSpinBox_IR_Time->setMinimum(0.5);
    ui->doubleSpinBox_IR_Time->setDecimals(1);
    ui->doubleSpinBox_IR_Time->setValue(Copy_IR_List.at(21).toDouble());

    ui->doubleSpinBox_IR_UpDCR->setMaximum(500);   // 1.0-1000
    ui->doubleSpinBox_IR_UpDCR->setMinimum(1);
    ui->doubleSpinBox_IR_UpDCR->setDecimals(0);
    ui->doubleSpinBox_IR_UpDCR->setValue(Copy_IR_List.at(22).toDouble());

    ui->doubleSpinBox_IR_DownDCR->setMaximum(9999);   // 0-1000
    ui->doubleSpinBox_IR_DownDCR->setMinimum(0);
    ui->doubleSpinBox_IR_DownDCR->setDecimals(0);
    ui->doubleSpinBox_IR_DownDCR->setValue(Copy_IR_List.at(23).toDouble());

    ui->ComboBox_IR_Volt->setCurrentIndex(Copy_IR_List[20].toInt());
    //  读取数据 ComboBox_IR_Volt 的数值
    IR_Compensate_Flag = Copy_IR_List.at(0).toInt();
    if (IR_Compensate_Flag) {
        ui->doubleSpinBox_Compensate->setValue(Copy_IR_List.at(1).toDouble());
        IR_Compensate_Result = Copy_IR_List.at(1).toDouble();
    }
    for (i = 0; i < Box_All_List.size(); i++) {
        if (Copy_IR_List.at(i).toInt() == 2) {
            Box_All_List.at(i)->setChecked(true);
        }
    }
    Init_Flag = false;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      保存绝缘配置
******************************************************************************/
void Widget_IR::Pri_IR_Save_Data()
{   //   更新绝缘数据
    int i;
    if (ACW_Between_IR) {
        for (i = 0; i < 4; i++) {
            Copy_IR_List.replace(30+i*10, (ui->IrTab->item(i, 1)->text()));
            Copy_IR_List.replace(31+i*10, (ui->IrTab->item(i, 2)->text()));
         // Copy_IR_List.replace(32+i*10, (IR_vola[i]->text()));
            Copy_IR_List.replace(33+i*10, (IR_bres[i]->text()));
            Copy_IR_List.replace(34+i*10, (IR_pres[i]->text()));
            Copy_IR_List.replace(35+i*10, (IR_time[i]->text()));
            Copy_IR_List.replace(36+i*10, QString::number(Box_IR_list.at(i)->checkState()));
        }
    } else {
        if (ui->label_IR_Param->text() == "IR-1") {
            Copy_IR_List.replace(20, QString::number(ui->ComboBox_IR_Volt->currentIndex()));
            Copy_IR_List.replace(21, ui->doubleSpinBox_IR_Time->text());
            Copy_IR_List.replace(22, ui->doubleSpinBox_IR_UpDCR->text());
            Copy_IR_List.replace(23, ui->doubleSpinBox_IR_DownDCR->text());
        } else {
            Copy_IR_List.replace(25, QString::number(ui->ComboBox_IR_Volt->currentIndex()));
            Copy_IR_List.replace(26, ui->doubleSpinBox_IR_Time->text());
            Copy_IR_List.replace(27, ui->doubleSpinBox_IR_UpDCR->text());
            Copy_IR_List.replace(28, ui->doubleSpinBox_IR_DownDCR->text());
        }
    }
    if (IR_Compensate_Flag) { //-补偿后进行修改数值
        if (ui->label_IR_Param->text() == "IR-1") {
            Copy_IR_List.replace(1, \
                                 QString::number(ui->doubleSpinBox_Compensate->value(), 'f', 2));
            ui->doubleSpinBox_Compensate->setValue(Copy_IR_List.at(1).toDouble());
        } else {
            Copy_IR_List.replace(3, \
                                 QString::number(ui->doubleSpinBox_Compensate->value(), 'f', 2));
            ui->doubleSpinBox_Compensate->setValue(Copy_IR_List.at(3).toDouble());
        }
    }
}

void Widget_IR::IR_UsartData(QStringList list) {
    if (list.size() < 5) {
        return;
    } else {
        //
    }

    Init_Flag = true;
    QString IR_usart_volt;
    double IR_usart_down;
    double IR_usart_time;

    IR_usart_volt = list.at(2);
    IR_usart_down = list.at(3).toDouble();
    IR_usart_time = list.at(4).toDouble();

    if (IR_usart_volt == "0.5") {
        Copy_IR_List.replace(20, "0");
        ui->ComboBox_IR_Volt->setCurrentIndex(0);
    } else {
        Copy_IR_List.replace(20, "1");
        ui->ComboBox_IR_Volt->setCurrentIndex(1);
    }

    Copy_IR_List.replace(22, list.at(3));
    ui->doubleSpinBox_IR_UpDCR->setValue(IR_usart_down);
    Copy_IR_List.replace(21, list.at(4));
    ui->doubleSpinBox_IR_Time->setValue(IR_usart_time);

    Init_Flag = false;
}

void Widget_IR::IR_NetData(QStringList list, QString str) {
    Init_Flag = true;
    IR_Volt.clear(); IR_Volt << "500" << "1000"; // 绝缘电压
    int i;
    if ((list.size() == 5) || (list.size() == 6)) {
        //
    } else {
        return;
    }
    if (list.size() == 5) {
        if (str == QString(tr("volt"))) {
            Copy_IR_List.replace(20, list.at(4));
            ui->ComboBox_IR_Volt->setCurrentIndex(list.at(4).toInt());
        } else if (str == QString(tr("min"))) {
            Copy_IR_List.replace(22, list.at(4));
            ui->doubleSpinBox_IR_UpDCR->setValue(list.at(4).toDouble());
        } else if (str == QString(tr("max"))) {
            Copy_IR_List.replace(23, list.at(4));
            ui->doubleSpinBox_IR_DownDCR->setValue(list.at(4).toDouble());
        } else if (str == QString(tr("time"))) {
            Copy_IR_List.replace(21, list.at(4));
            ui->doubleSpinBox_IR_Time->setValue(list.at(4).toDouble());
        } else {
            //
        }
    } else {
        if (str == QString(tr("volt"))) {
            Copy_IR_List.replace(20, list.at(4));
            Copy_IR_List.replace(25, list.at(5));
            ui->ComboBox_IR_Volt->setCurrentIndex(list.at(4).toInt());
        } else if (str == QString(tr("min"))) {
            Copy_IR_List.replace(22, list.at(4));
            Copy_IR_List.replace(27, list.at(5));
            ui->doubleSpinBox_IR_UpDCR->setValue(list.at(4).toDouble());
        } else if (str == QString(tr("max"))) {
            Copy_IR_List.replace(23, list.at(4));
            Copy_IR_List.replace(28, list.at(5));
            ui->doubleSpinBox_IR_DownDCR->setValue(list.at(4).toDouble());
        } else if (str == QString(tr("time"))) {
            Copy_IR_List.replace(21, list.at(4));
            Copy_IR_List.replace(26, list.at(5));
            ui->doubleSpinBox_IR_Time->setValue(list.at(4).toDouble());
        } else {
            //
        }
    }


    if (str == QString(tr("volt"))) {
        for (i = 0; i < 4; i++) {
            Copy_IR_List.replace(32+i*10, list.at(i));
            QTableWidgetItem *UnitItem = new QTableWidgetItem(IR_Volt[list.at(i).toInt()]);
            UnitItem->setTextAlignment(Qt::AlignCenter);
            UnitItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            ui->IrTab->setItem(i, 3, UnitItem);
            ui->IrTab->setEditTriggers(QAbstractItemView::AllEditTriggers);
        }
    } else if (str == QString(tr("min"))) {
        for (i = 0; i < 4; i++) {
            IR_bres[i]->setText(list.at(i));
        }
    } else if (str == QString(tr("max"))) {
        for (i = 0; i < 4; i++) {
            IR_pres[i]->setText(list.at(i));
        }
    } else if (str == QString(tr("time"))) {
        for (i = 0; i < 4; i++) {
            IR_time[i]->setText(list.at(i));
        }
    } else if (str == QString(tr("test"))) {
        for (i = 0; i < 4; i++) {
            if (list.at(i).toInt() == 1) {
                Box_IR_list[i]->setChecked(true);
            } else {
                Box_IR_list[i]->setChecked(false);
            }
        }
    } else if (str == QString(tr("port1"))) {
        for (i = 0; i < 4; i++) {
            ui->IrTab->item(i, 1)->setText(list.at(i));
        }
    } else if (str == QString(tr("port2"))) {
        for (i = 0; i < 4; i++) {
            ui->IrTab->item(i, 2)->setText(list.at(i));
        }
    } else {
        //
    }

    Init_Flag = false;
}

void Widget_IR::on_IrTab_cellClicked(int row,  int column)
{
    int i;
    if (column == 1 || column == 2) {
        for (i = 0; i < Box_All_List.size(); i++) {
            Box_All_List[i]->setChecked(false);
        }
        if (column == 1) {
            ui->checkBox_1->show();  ui->checkBox_2->hide();  ui->checkBox_3->hide();
            ui->checkBox_4->show();  ui->checkBox_5->hide();  ui->checkBox_6->hide();
            ui->checkBox_7->show();  ui->checkBox_8->hide();
            ui->checkBox_9->show();  ui->checkBox_10->hide();
            ui->OK->show();
        } else if (column == 2) {
            ui->checkBox_1->show();  ui->checkBox_2->show();  ui->checkBox_3->show();
            ui->checkBox_4->show();  ui->checkBox_5->show();  ui->checkBox_6->show();
            ui->checkBox_7->show();  ui->checkBox_8->show();
            ui->checkBox_9->hide();   ui->checkBox_10->hide();
            ui->OK->show();
        }
        if (Init_Channel_6) {
            ui->checkBox_7->hide();
            ui->checkBox_8->hide();
        } else {
            //
        }
        IR_Labelhide->show();
        ui->dockwidget->show();
        ui->dockwidget->raise();
    } else if (column == 3) {
        int resId = (Copy_IR_List.at(32+row*10).toInt()+1)%IR_Volt.size();
        Copy_IR_List.replace(32+row*10, QString::number(resId));
        QTableWidgetItem *UnitItem = new QTableWidgetItem(IR_Volt[resId]);
        UnitItem->setTextAlignment(Qt::AlignCenter);
        UnitItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ui->IrTab->setItem(row, 3, UnitItem);
        ui->IrTab->setEditTriggers(QAbstractItemView::AllEditTriggers);
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.5.16
  * brief:      进行端子有无重合的判定
******************************************************************************/
bool Widget_IR::Pri_IR_T1T2_Judge(QString T1, QString T2)
{
    for (int i = 0; i < T1.length(); i++) {
        for (int j = 0; j < T2.length(); j++) {
            if (T1.mid(i, 1).toInt() == T2.mid(j, 1).toInt()) {
                return true;
            }
        }
    }
    return false;
}
void Widget_IR::on_IrTab_cellChanged(int row,  int column)
{
    int i;
    int After_Point = 0;
    QString str;

    if (Init_Flag) {
        return;
    }
    Init_Flag = true;
    if (column == 1 || column == 2) {
        if (Pri_IR_T1T2_Judge(ui->IrTab->item(row,  1)->text(), \
                              ui->IrTab->item(row,  2)->text())) {
            ui->IrTab->item(row,  1)->setText("1");
            ui->IrTab->item(row,  2)->setText("2");
            Pri_IR_WMessage(tr("       输入错误，端点有重合       "));
        } else {
            //
        }
    }
    if ((column == 4) || (column == 5) || (column == 6)) {
        str = ui->IrTab->item(row,  column)->text();
        if (str == NULL) {
            ui->IrTab->item(row,  column)->setText("0");
        }
        for (i = 0; i < str.length(); i++) {
            if (((str[i] >= '0') && (str[i] <= '9')) || (str[i] == '.')) {
                //
            } else {
                ui->IrTab->item(row,  column)->setText("0");
                break;
            }
            if (str[i] == '.') { //  判断是否规范
                After_Point = str.length() - i - 1;
                if ((i == 0)) {
                    ui->IrTab->item(row, column)->setText("0");
                }
                if (i == (str.length() - 1)) {
                    ui->IrTab->item(row, column)->setText\
                            (ui->IrTab->item(row, column)->text().left(i));
                }
            }
        }

        if (column == 4) {
            if (ui->IrTab->item(row, column)->text().toDouble() > 500) {
                ui->IrTab->item(row, column)->setText("500");
            } else {
                //
            }
        } else {
            if (ui->IrTab->item(row, column)->text().toDouble() > 10000) {
                ui->IrTab->item(row, column)->setText("9999");
            } else {
                //
            }
        }


        if (column == 4 || column == 5) {
            ui->IrTab->item(row,  column)->setText\
                    (QString::number(ui->IrTab->item(row,  column)->text().toDouble(),  'f',  0));
            if ((column == 4)&&(ui->IrTab->item(row, 4)->text().toDouble() < 1)) {
                ui->IrTab->item(row, 4)->setText("1");
            }
        }

        if (column == 6) {
            ui->IrTab->item(row,  column)->setText\
                    (QString::number(ui->IrTab->item(row,  column)->text().toDouble(),  'f',  1));
            if (ui->IrTab->item(row, 6)->text().toDouble() <= 0.5) {
                ui->IrTab->item(row, 6)->setText("0.5");
            }
        }
        if (column == 4) {
            if (((ui->IrTab->item(row, 4)->text().toDouble()) > \
                 (ui->IrTab->item(row, 5)->text().toDouble())) && \
                    (ui->IrTab->item(row, 5)->text().toDouble() != 0)) {
                // 确保在上限不为0的状态下，上限大于下限
                Pri_IR_WMessage(tr("       输入错误，下限大于上限      "));
                ui->IrTab->item(row, 4)->setText("1");
            }
        }
        if (column == 5) {
            if (((ui->IrTab->item(row, 4)->text().toDouble()) > \
                 (ui->IrTab->item(row, 5)->text().toDouble())) && \
                    (ui->IrTab->item(row, 5)->text().toDouble() != 0)) {
                // 确保在上限不为0的状态下，上限大于下限
                Pri_IR_WMessage(tr("       输入错误，下限大于上限       "));
                ui->IrTab->item(row, 4)->setText("1");
            }
        }
    }
    Init_Flag = false;
}
void Widget_IR::box_statechange()
{
    int i,  j;
    for (i = 0; i < 4; i++) {
        if (Copy_IR_List.at(36+i*10).toInt() != 2) {
            continue;
        }
        for (j = 0; j < 7; j++) {
            if (Copy_IR_List.at(31+i*10).mid(j, 1) == "") {
                break;
            }
            if ((Copy_IR_List.at(31+i*10).mid(j, 1).toInt()) == \
                    (Copy_IR_List.at(30+i*10).mid(0, 1).toInt())) {
                Pri_IR_WMessage(tr("       输入错误，端点有重合       "));
                ui->IrTab->item(i, 2)->setText("0");
                break;
            } else if ((Copy_IR_List.at(31+i*10).mid(j, 1).toInt()) == \
                       (Copy_IR_List.at(30+i*10).mid(1, 1).toInt())) {
                Pri_IR_WMessage(tr("       输入错误，端点有重合       "));
                ui->IrTab->item(i, 2)->setText("0");
                break;
            } else if ((Copy_IR_List.at(31+i*10).mid(j, 1).toInt()) == \
                       (Copy_IR_List.at(30+i*10).mid(2, 1).toInt())) {
                Pri_IR_WMessage(tr("       输入错误，端点有重合       "));
                ui->IrTab->item(i, 2)->setText("0");
                break;
            }
        }
    }
}
void Widget_IR::on_doubleSpinBox_IR_UpDCR_editingFinished()
{
    if ((ui->doubleSpinBox_IR_UpDCR->text().toDouble()) >= \
            (ui->doubleSpinBox_IR_DownDCR->text().toDouble())) {
        if ((ui->doubleSpinBox_IR_DownDCR->text().toDouble()) != 0) {
            ui->doubleSpinBox_IR_UpDCR->setValue(1);
        }
    }
}
void Widget_IR::on_doubleSpinBox_IR_DownDCR_editingFinished()
{
    if ((ui->doubleSpinBox_IR_UpDCR->text().toDouble()) >= \
            (ui->doubleSpinBox_IR_DownDCR->text().toDouble())) {
        if ((ui->doubleSpinBox_IR_DownDCR->text().toDouble()) != 0) {
            ui->doubleSpinBox_IR_UpDCR->setValue(1);
        }
    }
}
void Widget_IR::Pri_IR_Default_value()
{
    if (ACW_Between_IR) {
        return;
    }
//    ui->ComboBox_IR_Volt->setCurrentIndex(1);
//    ui->doubleSpinBox_IR_Time->setValue(1);
//    ui->doubleSpinBox_IR_UpDCR->setValue(1); //-下限设置
//    ui->doubleSpinBox_IR_DownDCR->setValue(0); //-上限设置
//    IR_Compensate_Flag = false;
}
void Widget_IR::Pri_IR_WMessage(QString Warning_Text)
{
    QMessageBox message;
    message.setWindowFlags(Qt::FramelessWindowHint);
    message.setStyleSheet\
            ("QMessageBox{border: gray;border-radius: 10px;"\
             "padding:2px 4px;background-color: gray;}");
    message.setText("\n"+Warning_Text+"\n");

    message.addButton(QMessageBox::Ok)->setStyleSheet\
            ("height:39px;width:75px;border:5px groove;border:none;"\
             "border-radius:10px;padding:2px 4px;");
    message.setButtonText(QMessageBox::Ok, QString(tr("确 定")));
    message.setIcon(QMessageBox::Warning);
    message.exec();
}
QStringList Widget_IR::IR_Test_Result(QStringList IR_Data)
{
    QStringList Back_QStringList;  Back_QStringList.clear();

    bool IRACW_True_Value;
    int  IRvolt;
    int  IR_Test_Count;
    double IR_Display_Data = 0.0;
    int  IR_Judge;
    int  IR_First_Test;
    IRACW_True_Value = IR_Data.at(0).toInt();
    IRvolt = IR_Data.at(1).toInt();
    IR_Test_Count = IR_Data.at(2).toInt();
    IR_Display_Data = IR_Data.at(3).toDouble();
    IR_Judge = IR_Data.at(4).toInt();
    IR_First_Test = IR_Data.at(5).toInt();
    if (ACW_Between_IR) {
        if (IRACW_True_Value) { // -测试界面结果显示
            IRvolt = Copy_IR_List.at(32 + \
                        (IRgroup_num.at(IR_Test_Count).toInt()-4)*10).toInt()%2*500+500;
        } else {
            //
        }
        Back_QStringList.append(QString::number(IRvolt) + "V, ");
    } else {
        if (IRACW_True_Value) {
            if (IR_First_Test == 1) {
                IRvolt = (Copy_IR_List.at(20).toInt() + 1)*500; // 显示实际电压
            } else {
                IRvolt = (Copy_IR_List.at(25).toInt() + 1)*500; // 显示实际电压
            }
        } else {
            //
        }
        Back_QStringList.append(QString::number(IRvolt) + "V, ");
    }


    if (IR_Compensate_Flag) { //-绝缘补偿
        if ((IR_Display_Data) >= (IR_Compensate_Result)) {
            Back_QStringList.append(QString::number(IR_Display_Data));
        } else {
            Back_QStringList.append(QString::number\
                                    (IR_Display_Data*(IR_Compensate_Result)/\
                                     ((IR_Compensate_Result) - IR_Display_Data)));
        }
    } else {
        Back_QStringList.append(QString::number(IR_Display_Data));
    }
    if ((IRHostJudge == 2) && (!(ACW_Between_IR))) {
        if (IR_Judge == 0) {
            if (Copy_IR_List.at(23).toInt() == 0) { // 上限等于0
                if (Back_QStringList.at(1).toDouble() > Copy_IR_List.at(22).toInt()) { // <下限
                    Back_QStringList.append("0"); // 合格
                } else {
                    Back_QStringList.append("1"); // 不合格
                }
            } else { // 上限不等于0
                if ((Back_QStringList.at(1).toDouble() > \
                     Copy_IR_List.at(22).toInt()) && \
                        (Back_QStringList.at(1).toDouble() < Copy_IR_List.at(23).toInt())) {
                    Back_QStringList.append("0"); // 合格
                } else {
                    Back_QStringList.append("1"); // 不合格
                }
            }
        } else {
            Back_QStringList.append(QString::number(IR_Judge));
        }
    } else {
        Back_QStringList.append(QString::number(IR_Judge));
    }
    return Back_QStringList;
}
QStringList Widget_IR::IR_Test_Param(bool Test_Enable)
{
    QString str;
    QStringList strSql;
    QStringList strTest, strParam;
    strTest.clear();
    strParam.clear();
    IR_Volt.clear(); IR_Volt << "500" << "1000"; // 绝缘电压

    if (ACW_Between_IR) {
        for (int j = 0; j < 4; j++) {
            if (Copy_IR_List[36+j*10].toInt() != 2) {
                continue;
            }
            str = QString(tr("绝缘")) + QString::number(j+1);
            strTest.append(str);
            str.clear();
            str += QString(tr("高端:"));
            str += Copy_IR_List.at(30+j*10);
            str += QString(tr(" "));
            str += QString::number(Copy_IR_List.at(32+j*10).toInt()%2*500 + 500); str += "V,";
            str += Copy_IR_List.at(33 + j*10); str += "MΩ,";
            str += Copy_IR_List.at(35 + j*10); str += "s";
            strParam.append(str);
            str.clear();
            strSql.append(tr("绝缘"));
        }
    } else {
        if (Test_Enable) {
            str = QString(tr("绝缘"));
            strTest.append(str);

            str.clear();
            str += IR_Volt.at(Copy_IR_List[25].toInt());   str += "V,";
            str += Copy_IR_List.at(27);  str += "MΩ,";
            // 2018.10.20 修改显示下限
            str += Copy_IR_List.at(26); str += "s";
            strParam.append(str);
            str.clear();
            strSql.append(tr("绝缘"));
        } else {
            str = QString(tr("绝缘"));
            strTest.append(str);

            str.clear();
            str += IR_Volt.at(Copy_IR_List[20].toInt());   str += "V,";
            str += Copy_IR_List.at(22);  str += "MΩ,";
            // 2017.3.10 修改显示下限
            str += Copy_IR_List.at(21); str += "s";
            strParam.append(str);
            str.clear();
            strSql.append(tr("绝缘"));
        }
    }

    QStringList Back_List;
    Back_List.append(QString::number(strTest.size()));
    Back_List.append(QString::number(strParam.size()));
    Back_List.append(QString::number(strSql.size()));
    Back_List.append(strTest);
    Back_List.append(strParam);
    Back_List.append(strSql);
    return Back_List;
}
bool Widget_IR::IR_If_Compensate(QString ACW_Between_IR)
{
    if (IR_Compensate_Flag) {
        IR_Compensate_Flag = false;
        if (ui->label_IR_Param->text() == "IR-1") {
            Copy_IR_List.replace(0, "0");
            Copy_IR_List.replace(1, "0");
        } else {
            Copy_IR_List.replace(2, "0");
            Copy_IR_List.replace(3, "0");
        }
        ui->doubleSpinBox_Compensate->setValue(0);
        return true;
    } else {
        Pri_IR_Init(ACW_Between_IR);
        frame.can_id = 0x23;  frame.can_dlc = 0x05;
        frame.data[0] = 0x01;
        frame.data[1] = 0x04;
        frame.data[2] = 0x00;
        frame.data[3] = 0x13;
        frame.data[4] = 0x01;
        canSend(frame);
        return false;
    }
}
bool Widget_IR::IR_Back_Key_E()
{
    if (ACW_Between_IR) {
        IR_Compensate_Flag = false;
    }

    if (IR_Compensate_Flag) {
        return 1;
    } else {
        return 0;
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.12
  * brief:      绝缘补偿数据
******************************************************************************/
int  Widget_IR::IR_Compensate(double Compensate_Value)
{
    if (IR_Compensate_Flag) { // IR_Compensate_Flag!=0
        return 0;
    }
    IR_Compensate_Result = Compensate_Value;
    if (IR_Compensate_Result > 50) {
        IR_Compensate_Flag = true;
        ui->doubleSpinBox_Compensate->setValue(IR_Compensate_Result);
        if (ui->label_IR_Param->text() == "IR-1") {
            Copy_IR_List.replace(0, "1");
            Copy_IR_List.replace(1, QString::number(IR_Compensate_Result));
        } else {
            Copy_IR_List.replace(2, "1");
            Copy_IR_List.replace(3, QString::number(IR_Compensate_Result));
        }
        return 1;
    } else {
        frame.can_id = 0x23;  frame.can_dlc = 0x01;
        frame.data[0] = 0x02;
        canSend(frame);
        IR_Compensate_Flag = false;
        return 2;
    }
}

void Widget_IR::Pri_IR_Param(QString value) {
    if (value == "2") {
        ui->label_IR_Param->setText("IR-2");
        ui->doubleSpinBox_IR_Time->setValue(Copy_IR_List.at(26).toDouble());
        ui->doubleSpinBox_IR_UpDCR->setValue(Copy_IR_List.at(27).toDouble());
        ui->doubleSpinBox_IR_DownDCR->setValue(Copy_IR_List.at(28).toDouble());
        ui->ComboBox_IR_Volt->setCurrentIndex(Copy_IR_List[25].toInt());
        ui->doubleSpinBox_Compensate->setValue(Copy_IR_List.at(3).toDouble());
    } else {
        ui->label_IR_Param->setText("IR-1");
        ui->doubleSpinBox_IR_Time->setValue(Copy_IR_List.at(21).toDouble());
        ui->doubleSpinBox_IR_UpDCR->setValue(Copy_IR_List.at(22).toDouble());
        ui->doubleSpinBox_IR_DownDCR->setValue(Copy_IR_List.at(23).toDouble());
        ui->ComboBox_IR_Volt->setCurrentIndex(Copy_IR_List[20].toInt());
        ui->doubleSpinBox_Compensate->setValue(Copy_IR_List.at(1).toDouble());
    }
    qDebug() << ui->doubleSpinBox_IR_Time->value();
    qApp->processEvents();
}

void Widget_IR::Pub_Conf_Set_IR(QString str, int value)
{
    qDebug() << "Widget_IR::Pub_Conf_Set_IR" << value;
    switch (value) {
    case 1:
        Pri_IR_Init(str);
        break;
    case 2:
        Pri_IR_Save_Data();
        if (ACW_Between_IR) {
            box_statechange();
        } else {
            //
        }
        break;
    case 3:
        Pri_IR_Default_value();
        break;
    case 5:
        Pri_IR_Test(str, 1);
        break;
    case 6:
        Line_HV = true;
        Line_HV_High = str;
        break;
    case 7:
        Line_HV = true;
        Line_HV_Low = str;
        break;
    case 100:
        if (str.toInt()) {
            Init_Channel_6 = true;
        } else {
            Init_Channel_6 = false;
        }
        break;
    case 101:
        Pri_IR_Param(str);
        break;
    case 102:
        Pri_IR_Test(str, 2);
        break;
    default:
        break;
    }
}
