/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "Widget_HV.h"
#include "ui_Widget_HV.h"

Widget_HV::Widget_HV(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_HV) {
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint); // 去掉标题栏
    ui->setupUi(this);
    ui->widget->move(90, 140);
    ui->widget->hide();

    ACW_Between_IR = false;
    Init_Flag = false;
    Init_Channel_6 = false;
    volt_set = 3000;
    set_i_up = 20.00;
    Line_HV = false;
    Line_HV_High = "";
    Line_HV_Low = "";
}

Widget_HV::~Widget_HV()
{
    delete ui;
}

/******************************************************************************
  * version:    1.0
  * author:     jeremy
  * date:       2017.2.24
  * brief:      初始化相耐设置
******************************************************************************/
void Widget_HV::Pri_HV_Init(QString str)
{
    qDebug() << "Widget_HV::Pri_HV_Init() Copy_HV_List" << Copy_HV_List.size();
    int i;
    Init_Flag = true;

    freq.clear();     freq << "50" << "60";  // -設置頻率
    ACW_Between_IR = str.toInt();
    if (ACW_Between_IR) {
        ui->widget->hide();
    } else {
        ui->widget->show();     ui->widget->raise();
    }

    Box_HV_list.clear();


    ui->double_Volt->setMaximum(volt_set);  //  500-5000 V
    ui->double_Volt->setMinimum(500);
    ui->double_Volt->setDecimals(0);
    ui->double_Volt->setValue(Copy_HV_List.at(20).toDouble());

    ui->double_Time->setMaximum(999.9);  //  0.5-999.9 S
    ui->double_Time->setMinimum(0.5);
    ui->double_Time->setDecimals(1);
    ui->double_Time->setValue(Copy_HV_List.at(21).toDouble());

    ui->double_I_Down->setMaximum(20.00);  //  0-2000V mA
    ui->double_I_Down->setMinimum(0);
    ui->double_I_Down->setDecimals(2);
    ui->double_I_Down->setValue(Copy_HV_List.at(23).toDouble());

    ui->double_I_Up->setMaximum(20.00);  //  10-2000 mA
    ui->double_I_Up->setMinimum(0.10);
    ui->double_I_Up->setDecimals(2);
    ui->double_I_Up->setValue(Copy_HV_List.at(24).toDouble());

    ui->comb_ARC->setCurrentIndex(Copy_HV_List[0].toInt());
    ui->comb_Freq->setCurrentIndex(Copy_HV_List[1].toInt());

    for (i = 0; i < Box_All_List.size(); i++) {
        if (Copy_HV_List.at(i).toInt() == 2) {
            Box_All_List.at(i)->setChecked(true);
        }
    }
    Init_Flag = false;
}

void Widget_HV::mousePressEvent(QMouseEvent *event)  // 处理鼠标被按下事件
{

}

/******************************************************************************
  * version:    1.0
  * author:     jeremy
  * date:       2017.3.1
  * brief:      保存相耐配置
******************************************************************************/
void Widget_HV::Pri_HV_Save_Data()
{
    int i;
     // 更新相间交耐数据
    if (ACW_Between_IR) {

    } else {
        // 更新普通交耐数据
        Copy_HV_List.replace(20, ui->double_Volt->text());
        Copy_HV_List.replace(21, ui->double_Time->text());
        Copy_HV_List.replace(23, ui->double_I_Down->text());
        Copy_HV_List.replace(24, ui->double_I_Up->text());
        Copy_HV_List.replace(0, QString::number(ui->comb_ARC->currentIndex()));
        Copy_HV_List.replace(1, QString::number(ui->comb_Freq->currentIndex()));
    }
}

void Widget_HV::on_double_I_Down_editingFinished()
{
    if ((ui->double_I_Down->text().toDouble()) >= \
            (ui->double_I_Up->text().toDouble())) {
        ui->double_I_Down->setValue(0);
    }
}
void Widget_HV::on_double_I_Up_editingFinished()
{
    if ((ui->double_I_Down->text().toDouble()) >= \
            (ui->double_I_Up->text().toDouble())) {
        ui->double_I_Down->setValue(0);
    }
}
/******************************************************************************
  * version:    1.0
  * author:     jeremy
  * date:       2017.3.1
  * brief:      快速设置
******************************************************************************/
void Widget_HV::Pri_HV_Default_value()
{
    if (ACW_Between_IR) {
        return;
    }
    //     ui->comb_ARC->setCurrentIndex(0);
    //     ui->comb_Freq->setCurrentIndex(0);
    //     ui->double_Volt->setValue(1800);
    //     ui->double_Time->setValue(1);
    //     ui->double_I_Down->setValue(0);
    //     ui->double_I_Up->setValue(5);
}

void Widget_HV::Pri_HV_Group_One() {
    double Down_Limit;
    double Up_Limit;
    double time_double;
    int Down_Limit_int;
    int Up_Limit_int;
    int time_int;
    int i;
    int j;

    Down_Limit = 0.0;
    Up_Limit = 0.0;
    time_double = 0.0;
    Down_Limit_int = 0;
    Up_Limit_int = 0;
    time_int = 0;
    i = 0;
    j = 0;

    QStringList T1_H;  // -高端
    QStringList T2_H;  // -低端
    int T1_H_Data = 0;
    int T2_H_Data = 0;

    frame.can_id  = 0x23;
    frame.can_dlc = 0x08;
    frame.data[0] = 0x03;  // -交耐测试参数1
    frame.data[1] = 0x03;  // -测试组号
    frame.data[2] = 0x0A;  // -测试ACV
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
        frame.data[3] = 0x80;  // -高压端
        frame.data[4] = 0x00;
        frame.data[5] = 0xff;  // -低压端
        frame.data[6] = 0xff;
    }

    frame.data[7] = ui->comb_Freq->currentText().toInt()%256;
    canSend(frame);

    Down_Limit = (Copy_HV_List.at(23).toDouble() + Copy_HV_List.at(3).toDouble());
    Down_Limit_int = (Down_Limit*1000 + 5)/10;
    time_double = Copy_HV_List.at(21).toDouble();
    time_int = (time_double *100 + 5)/10;
    frame.can_id  = 0x23;
    frame.can_dlc = 0x08;
    frame.data[0] = 0x04;  // -交耐测试参数2
    frame.data[1] = 0x03;  // -测试组号
    frame.data[2] = Copy_HV_List.at(20).toInt()/256;  // -电压高低字节
    frame.data[3] = Copy_HV_List.at(20).toInt()%256;
    frame.data[4] = time_int/256;  // -测试时间
    frame.data[5] = time_int%256;
    frame.data[6] = (Down_Limit_int)/256;  // -下限耐压单位0.01mA
    frame.data[7] = (Down_Limit_int)%256;
    canSend(frame);

    Up_Limit = Copy_HV_List.at(24).toDouble() + Copy_HV_List.at(3).toDouble();
    Up_Limit_int = (Up_Limit*1000 + 5)/10;
    frame.can_id  = 0x23;
    frame.can_dlc = 0x07;
    frame.data[0] = 0x05;  // -交耐测试参数3
    frame.data[1] = 0x03;  // -测试组号
    frame.data[2] = (Up_Limit_int)/256;  // -上限耐压单位0.01mA
    frame.data[3] = (Up_Limit_int)%256;
    frame.data[4] = Copy_HV_List[0].toInt();  // -电弧等级
    frame.data[5] = 0x03;  // -缓升
    frame.data[6] = 0x0a;  // -缓降
    canSend(frame);
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.3.11
  * brief:      测试交耐新协议
******************************************************************************/
void Widget_HV::Pri_HV_Test()
{
    double Down_Limit;
    double Up_Limit;
    double time_double;
    int Down_Limit_int;
    int Up_Limit_int;
    int time_int;
    int i;
    int j;

    Down_Limit = 0.0;
    Up_Limit = 0.0;
    time_double = 0.0;
    Down_Limit_int = 0;
    Up_Limit_int = 0;
    time_int = 0;
    i = 0;
    j = 0;

    if (ACW_Between_IR) {
        //
    } else {
        Pri_HV_Group_One();
    }
}

void  Widget_HV::HV_NetData(QStringList list, QString str) {
    Init_Flag = true;
    if ((list.size() == 5) || (list.size() == 6)) {
        //
    } else {
        return;
    }

    if (list.size() == 5) {
        if (str == QString(tr("volt"))) {
            Copy_HV_List.replace(20, list.at(4));
            ui->double_Volt->setValue(list.at(4).toInt());
        } else if (str == QString(tr("min"))) {
            Copy_HV_List.replace(23, list.at(4));
            ui->double_I_Down->setValue(list.at(4).toDouble());
        } else if (str == QString(tr("max"))) {
            Copy_HV_List.replace(24, list.at(4));
            ui->double_I_Up->setValue(list.at(4).toDouble());
        } else if (str == QString(tr("time"))) {
            Copy_HV_List.replace(21, list.at(4));
            ui->double_Time->setValue(list.at(4).toDouble());
        } else if (str == QString(tr("freq"))) {
            Copy_HV_List.replace(1, list.at(4));
            ui->comb_Freq->setCurrentIndex(list.at(4).toInt());
        } else if (str == QString(tr("arc"))) {
            Copy_HV_List.replace(0, list.at(4));
            ui->comb_ARC->setCurrentIndex(list.at(4).toInt());
        } else {
            //
        }
    } else {
        if (str == QString(tr("volt"))) {
            Copy_HV_List.replace(20, list.at(4));
            Copy_HV_List.replace(25, list.at(5));
            ui->double_Volt->setValue(list.at(4).toInt());
        } else if (str == QString(tr("min"))) {
            Copy_HV_List.replace(23, list.at(4));
            Copy_HV_List.replace(28, list.at(5));
            ui->double_I_Down->setValue(list.at(4).toDouble());
        } else if (str == QString(tr("max"))) {
            Copy_HV_List.replace(24, list.at(4));
            Copy_HV_List.replace(29, list.at(5));
            ui->double_I_Up->setValue(list.at(4).toDouble());
        } else if (str == QString(tr("time"))) {
            Copy_HV_List.replace(21, list.at(4));
            Copy_HV_List.replace(26, list.at(4));
            ui->double_Time->setValue(list.at(4).toDouble());
        } else if (str == QString(tr("freq"))) {
            Copy_HV_List.replace(1, list.at(4));
            Copy_HV_List.replace(5, list.at(5));
            ui->comb_Freq->setCurrentIndex(list.at(4).toInt());
        } else if (str == QString(tr("arc"))) {
            Copy_HV_List.replace(0, list.at(4));
            Copy_HV_List.replace(4, list.at(5));
            ui->comb_ARC->setCurrentIndex(list.at(4).toInt());
        } else {
            //
        }
    }

    Init_Flag = false;
}

QStringList Widget_HV::HV_Test_Result(QStringList ACW_Data)
{
    QStringList Back_QStringList;  Back_QStringList.clear();
    bool IRACW_True_Value;
    int  ACW_volt;
    int  ACW_Test_Count;
    double ACW_Show_Data;
    int ACW_Judge;

    IRACW_True_Value = ACW_Data.at(0).toInt();
    ACW_volt = ACW_Data.at(1).toInt();
    ACW_Test_Count = ACW_Data.at(2).toInt();
    ACW_Show_Data = ACW_Data.at(3).toDouble();
    ACW_Judge = ACW_Data.at(4).toInt();
    if (ACW_Between_IR) {
        //
    } else {
        if (IRACW_True_Value) {
            ACW_volt = Copy_HV_List.at(20).toInt();
        }
        Back_QStringList.append(QString::number(ACW_volt)+"V, ");
    }



    Back_QStringList.append(QString::number(ACW_Show_Data));

    Back_QStringList.append(QString::number(ACW_Judge));

    return Back_QStringList;
}
QStringList Widget_HV::HV_Test_Param()
{
    QString str;
    QStringList strSql;
    QStringList strTest, strParam;
    strTest.clear();
    strParam.clear();
    if (ACW_Between_IR) {
        for (int j = 0; j < 4; j++) {
            if (Copy_HV_List[40+j*16].toInt()  ==  2) {
                str = QString(tr("搭线")) + QString::number(j+1);
                strTest.append(str);
                str.clear();
                str += QString(tr("高端:"));
                str += Copy_HV_List.at(30+j*16); str += QString(tr(" "));
                str += Copy_HV_List.at(32+j*16); str += "V,";
                str += Copy_HV_List.at(34+j*16); str += "mA,ARC:";
                str += Copy_HV_List.at(35+j*16);
                strParam.append(str);
                str.clear();
                strSql.append(tr("搭线"));
            }
        }
    } else {
        str = QString(tr("搭线"));
        strTest.append(str);
        str.clear();
        str += Copy_HV_List.at(20);   str += "V,";
        str += Copy_HV_List.at(24);   str += "mA,ARC:";
        str += Copy_HV_List.at(0);
        strParam.append(str);
        str.clear();
        strSql.append(tr("搭线"));
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

void Widget_HV::Pri_HV_Param(QString value) {

    ui->double_Volt->setValue(Copy_HV_List.at(20).toDouble());
    ui->double_Time->setValue(Copy_HV_List.at(21).toDouble());
    ui->double_I_Down->setValue(Copy_HV_List.at(23).toDouble());
    ui->double_I_Up->setValue(Copy_HV_List.at(24).toDouble());
    ui->comb_ARC->setCurrentIndex(Copy_HV_List[0].toInt());
    ui->comb_Freq->setCurrentIndex(Copy_HV_List[1].toInt());
    qApp->processEvents();
}
void Widget_HV::Pub_Conf_Set_HV(QString str, int value)
{
    switch (value) {
    case 1:
        Pri_HV_Init(str);
        break;
    case 2:
        Pri_HV_Save_Data();
        break;
    case 3:
        Pri_HV_Default_value();
        break;
    case 5:
        Pri_HV_Test();
        break;
    case 6:
        Line_HV = true;
        Line_HV_High = str;
        break;
    case 7:
        Line_HV = true;
        Line_HV_Low = str;
        break;
    case 9:
        Pri_HV_Param(str);
        break;
    case 100:
        if (str.toInt()) {
            Init_Channel_6 = true;
        } else {
            Init_Channel_6 = false;
        }
        break;
    case 101:
        if (str.toInt()) {
            volt_set = 5000;
        } else {
            volt_set = 3000;
        }
        break;
    default:
        break;
    }
}
