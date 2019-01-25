/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "Widget_DLR.h"
#include "ui_Widget_DLR.h"

Widget_DLR::Widget_DLR(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_DLR)
{
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint); // -去掉标题栏
    ui->setupUi(this);

    Edit_DLR_List.append(ui->Res_StandTemp); // -电阻设置列表
    Edit_DLR_List.append(ui->Res_ComTemp);
    Edit_DLR_List.append(ui->Res_Time);
    Edit_DLR_List.append(ui->Res_calculateDown);
    Edit_DLR_List.append(ui->Res_calculateUp);
    Edit_DLR_List.append(ui->Res_Unbalance);

    DLR_Comb_List.append(ui->Com_DLR);

    DLR_Group = new QButtonGroup;
    DLR_Group->addButton(ui->Key_1, 1);
    DLR_Group->addButton(ui->Key_2, 2);
    DLR_Group->addButton(ui->Key_3, 3);
    DLR_Group->addButton(ui->Key_4, 4);
    DLR_Group->addButton(ui->Key_5, 5);
    DLR_Group->addButton(ui->Key_6, 6);
    DLR_Group->addButton(ui->Key_7, 7);
    DLR_Group->addButton(ui->Key_8, 8);

    connect(DLR_Group, SIGNAL(buttonClicked(int)), this, SLOT(join_buttonJudge(int)));

    //  电阻设置表头
    ui->resTab->horizontalHeader()->setStyleSheet\
            ("QHeaderView::section{background-color:#191919;color: white;"\
             "padding-left: 4px;border: 1px solid #447684;}");
    ui->resTab->horizontalHeader()->setFixedHeight(35);
    ui->resTab->horizontalHeader()->setResizeMode(QHeaderView::Fixed);

    DLR_Compensate_Left = false;
    DLR_Compensate_Right = false;

    DLR_Temp_Flag = false;
    button_autocalc_Flag = 0;
    Init_Flag = false;
    ui->dockWidget->hide();
    RES_Compensate_Sum = 0;
    RES_Compensate_Ok = 0;

    DLR_Labelhide = new QLabel(this);
    DLR_Labelhide->setGeometry(0, 0, 800, 600);
    DLR_Labelhide->hide();

    /*  ui->resTab->setColumnWidth(2, 100);*/  // 设置长度
    ui->resTab->setColumnWidth(3, 80);
    ui->resTab->setColumnWidth(4, 80);
    ui->resTab->setColumnWidth(5, 80);
    ui->resTab->setColumnWidth(6, 50);
    ui->resTab->setColumnWidth(7, 60);
    ui->resTab->setColumnWidth(8, 65);
    ui->resTab->setColumnWidth(9, 65);
    ui->resTab->setColumnWidth(10, 60);


    Init_Channel_6 = false;
    Init_dcr_15 = false;

    int i;
    DCR_Widget = new QWidget(this);
    DCR_Widget->setGeometry(150, 180, 500, 250);
    DCR_Widget->setWindowFlags(Qt::WindowStaysOnTopHint);
    DCR_Widget->setStyleSheet("border-radius: 10px;padding:2px 4px;background-color: gray;"\
                              "color: black;border-color: black;");
    QGridLayout *IO_upside = new QGridLayout;
    QString IO_table[1]={QString(tr("不平衡度模式:"))};
    for (i = 0; i < 1; i++) {
        DCR_Show_Lable.append(new QLabel(this));
        DCR_Show_Lable[i]->setText(IO_table[i]);
        DCR_Show_Lable[i]->setMaximumHeight(35); DCR_Show_Lable[i]->setMaximumWidth(155);
        DCR_Show_Lable[i]->setAlignment(Qt::AlignCenter);
        IO_upside->addWidget(DCR_Show_Lable[i], i, 0);
        if (i < 1) {
            DCR_DoubleSpinBox.append(new QDoubleSpinBox(this));
            DCR_DoubleSpinBox[i]->setMaximumHeight(35);
            DCR_DoubleSpinBox[i]->setMaximumWidth(255);
            DCR_DoubleSpinBox[i]->setMaximum(3);
            DCR_DoubleSpinBox[i]->setMinimum(1);
            DCR_DoubleSpinBox[i]->setDecimals(0);
            IO_upside->addWidget(DCR_DoubleSpinBox[i], i, 1);
        }
    }
    QPushButton *IO_button_quit = new QPushButton;
    IO_button_quit->setText(tr("退出"));
    IO_button_quit->setMinimumHeight(50);
    IO_button_quit->setMinimumWidth(90);
    IO_button_quit->setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"\
                                  "stop: 0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);");
    IO_upside->addWidget(IO_button_quit, 0, 5);
    connect(IO_button_quit, SIGNAL(clicked()), this, SLOT(IO_Widget_autoquit()));
    QVBoxLayout *Histogram_IO_Widget_layout = new QVBoxLayout;
    Histogram_IO_Widget_layout->addLayout(IO_upside);
    DCR_Widget->setLayout(Histogram_IO_Widget_layout);
    DCR_Widget->hide();
    Init_dcr_balance = 0;
    YY_Type = false;
}

Widget_DLR::~Widget_DLR()
{
    delete ui;
}
void Widget_DLR::mousePressEvent(QMouseEvent *event) // 处理鼠标被按下事件
{
    if ((ui->resTab->currentColumn() == 1) || (ui->resTab->currentColumn() == 2)) {
        ui->dockWidget->hide();   DLR_Labelhide->hide();
    }
}

void Widget_DLR::IO_Widget_autoquit() {
    DCR_Widget->hide();
}

void Widget_DLR::join_buttonJudge(int id)
{
    ui->dockWidget->hide();  DLR_Labelhide->hide();
    if (id != 9) {
        ui->resTab->currentItem()->setText(QString::number(id));
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.1.27
  * brief:      测试电阻
******************************************************************************/
void Widget_DLR::Pri_DLR_Test(QString str_Set)
{
    int i, Set;
    Set = str_Set.toInt();
    DLR_TestItemsH = 0;
    DLR_TestItemsL = 0;

    DLR_TestNumber = 0;
    for (i = 0; i < (Copy_DLR_List.size()-NUM_RES_Con)/NUM_RES; i++) {
        if (DLR_Box_List[i]->checkState() == 2) {
            //  if (Copy_DLR_List.at(NUM_RES*i+7+NUM_RES_Con).toInt() == 2)
            // if (!(RES[i*NUM_RES+11].toInt()))
            frame.can_id = 0x22;  frame.can_dlc = 0x06;
            frame.data[0] = 0x03;
            frame.data[1] = i;                                       // 序号
            frame.data[2] = ui->resTab->item(i, 1)->text().toInt();   // 低端
            frame.data[3] = ui->resTab->item(i, 2)->text().toInt();   // 高端
            if (Set == 0) {
                frame.data[4] = Pri_judge_grade(i, 0);                    // 档位
                frame.data[5] = ui->Res_Time->text().toDouble()*10;  // 测试时间
            } else {
                if ((Init_dcr_15) && (Set == 3)) {
                    frame.data[4] = 4;
                } else {
                    frame.data[4] = Set;
                }
                frame.data[5] = 1;  // 电阻测试时间
            }
            canSend(frame);

            if (i >= 8) {
                DLR_TestItemsH = DLR_TestItemsH+(1 << (i-8));   //  高字节
            } else {
                DLR_TestItemsL = DLR_TestItemsL+(1 << i);       //  低字节
            }
            DLR_TestNumber++;                                 //  测试总数
        }
    }
}
void Widget_DLR::Pri_DLR_Start(QString str)
{
    if (DLR_TestNumber > 0) {
        frame.can_id = 0x22;  frame.can_dlc = 0x06;
        frame.data[0] = 0x01;
        frame.data[1] = 0x01;
        frame.data[2] = 0x00;
        if (str == QString("19")) {
            frame.data[3] = 0x13; // 左工位清 0
        } else if (str == QString("20")) {
            frame.data[3] = 0x14; // 右工位清 0
        } else {
            frame.data[3] = 0x13;
        }
        frame.data[4] = DLR_TestItemsH;
        frame.data[5] = DLR_TestItemsL;
        canSend(frame);
    }
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      初始化电阻设置
******************************************************************************/
void Widget_DLR::Pri_DLR_Init(QString dcr15)
{
    int i, j;
    Init_Flag = true;
    ui->resTab->setRowCount(0);

    DLR_Meterial.clear();
    DLR_Meterial << QString(tr("铜")) << QString(tr("铝")) << QString(tr("铜铝")) << QString(tr("PT")) ; // 电阻材料
    DLR_Unit.clear();     DLR_Unit << "mΩ" << "Ω" << "KΩ"; // 电阻单位

    int Pardec[5] = {0, 0, 1, 0, 0};
    int Parmin[5] = {0, 0, 0, 0, 0};
    int Parmax[5] = {100, 50, 20, 100, 100};

    if (dcr15.toInt()) {
        Init_dcr_15 = true;
    } else {
        Init_dcr_15 = false;
    }

    for (i = 0; i < 5; i++) {         // 5个离散数据
        if (i != 1) {
            Edit_DLR_List[i]->setValue(Copy_DLR_List.at(i).toDouble());
            initSpinBox(Edit_DLR_List[i], Pardec[i], Parmin[i], Parmax[i]);
        }
    }

    for (j = 0; j < 8; j++) { // 清除列表
        DLR_SpinList[j].clear();
    }
    DLR_STD_List.clear();
    DLR_Comb_List[0]->setCurrentIndex(Copy_DLR_List[6].toInt());
    Edit_DLR_List[5]->setValue(Copy_DLR_List.at(7).toDouble());
    if (ui->Com_DLR->currentIndex() == 0) {
        DLR_Temp_Flag = true;
    }

    ui->resTab->setRowCount((Copy_DLR_List.size() - NUM_RES_Con)/NUM_RES);  //  设置电阻行数
    DLR_T1_List.clear();
    DLR_T2_List.clear();
    for (i = 0; i < (Copy_DLR_List.size()-NUM_RES_Con)/NUM_RES; i++)  {
        //初始化输入框
        DLR_T1_List.append(new QTableWidgetItem);
        DLR_T1_List[i]->setTextAlignment(Qt::AlignCenter);
        DLR_T1_List[i]->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        DLR_T1_List[i]->setText(Copy_DLR_List.at(i*NUM_RES+NUM_RES_Con));
        ui->resTab->setItem(i, 1, DLR_T1_List[i]);

        DLR_T2_List.append(new QTableWidgetItem);
        DLR_T2_List[i]->setTextAlignment(Qt::AlignCenter);
        DLR_T2_List[i]->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        DLR_T2_List[i]->setText(Copy_DLR_List.at(i*NUM_RES+NUM_RES_Con+1));
        ui->resTab->setItem(i, 2, DLR_T2_List[i]);
        for (j = 2; j < 4; j++) {
            DLR_SpinList[j].append(new QTableWidgetItem);
            DLR_SpinList[j][i]->setText(Copy_DLR_List.at(i*NUM_RES+NUM_RES_Con+j));
            DLR_SpinList[j][i]->setTextAlignment(Qt::AlignCenter);
            ui->resTab->setItem(i, j + 1, DLR_SpinList[j][i]);
        }
        DLR_STD_List.append(new QTableWidgetItem);
        DLR_STD_List[i]->setTextAlignment(Qt::AlignCenter);
        DLR_STD_List[i]->setText(Copy_DLR_List.at(i*NUM_RES+NUM_RES_Con+4));
        ui->resTab->setItem(i, 5, DLR_STD_List[i]);

        QTableWidgetItem *UnitItem = new QTableWidgetItem;
        UnitItem->setText(DLR_Unit[Copy_DLR_List[i*NUM_RES+NUM_RES_Con+9].toInt()]);
        UnitItem->setTextAlignment(Qt::AlignCenter);
        UnitItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ui->resTab->setItem(i, 6, UnitItem);

        QTableWidgetItem *pItem = new QTableWidgetItem;
        pItem->setText(DLR_Meterial[Copy_DLR_List[i*NUM_RES+5+NUM_RES_Con].toInt()]);
        pItem->setTextAlignment(Qt::AlignCenter);
        pItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ui->resTab->setItem(i, 7, pItem);

        QTableWidgetItem *ppItem = new QTableWidgetItem;
        ppItem->setTextAlignment(Qt::AlignCenter);
        ppItem->setText(QString::number((i + 1)));
        ppItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ui->resTab->setItem(i, 0, ppItem);
    }
    DLR_Box_List.clear();
    for (i = 0; i < 8; i++) {
        DLR_Box_List.append(new QCheckBox);
        DLR_Box_List[i]->setStyleSheet\
                ("QCheckBox::indicator {image: url(:/image/053.png);width: 65px;"\
                 "height: 55px;}QCheckBox::indicator:checked {image: url(:/image/051.png);}");
        if (Copy_DLR_List.at(NUM_RES*i+7+NUM_RES_Con).toInt() == 2) {
            DLR_Box_List[i]->setChecked(true);
        }
    }

    ui->Res_ComTemp->setValue(Copy_DLR_List.at(NUM_RES_Con + 8).toDouble());
    for (i = 0; i < 8; i++) {
        ui->resTab->setRowHeight(i, 53);
        ui->resTab->setCellWidget(i, 10, DLR_Box_List[i]);
    }

    DLR_Compensate_Left = Copy_DLR_List.at(5).toInt();
    DLR_Compensate_Right = Copy_DLR_List.at(8).toInt();
    Pri_DLR_Init_Compensate();

    if (Copy_DLR_List.at(10).toInt() == 0) {
        DCR_DoubleSpinBox[0]->setValue(Init_dcr_balance);
    } else {
        DCR_DoubleSpinBox[0]->setValue(Copy_DLR_List.at(10).toInt());
    }

    Init_Flag = false;
}
void Widget_DLR::Pri_DLR_Init_Compensate()
{
    int i;
    DLR_SpinList[6].clear();
    DLR_SpinList[7].clear();
//    DLR_Offset_List_Left.clear();
//    DLR_Offset_List_Right.clear();
    if (DLR_Compensate_Left) {
        for (i = 0; i < (Copy_DLR_List.size()-NUM_RES_Con)/NUM_RES; i++) {
            DLR_SpinList[6].append(new QTableWidgetItem);
            DLR_SpinList[6][i]->setText(Copy_DLR_List.at(i*NUM_RES + 6 + NUM_RES_Con));
            DLR_SpinList[6][i]->setTextAlignment(Qt::AlignCenter);
            ui->resTab->setItem(i, 8, DLR_SpinList[6][i]);
        }
    } else {
        for (i = 0; i < (Copy_DLR_List.size() - NUM_RES_Con)/NUM_RES; i++) {
            DLR_SpinList[6].append(new QTableWidgetItem);
            DLR_SpinList[6][i]->setText(Copy_DLR_List.at(i*NUM_RES + 6 + NUM_RES_Con));
            DLR_SpinList[6][i]->setTextAlignment(Qt::AlignCenter);

//            DLR_Offset_List_Left.append(new QTableWidgetItem);
//            DLR_Offset_List_Left[i]->setTextAlignment(Qt::AlignCenter);
//            DLR_Offset_List_Left[i]->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
//            DLR_Offset_List_Left[i]->setText("*");
            ui->resTab->setItem(i, 8, DLR_SpinList[6][i]);
        }
    }
    if (DLR_Compensate_Right) {
        for (i = 0; i < (Copy_DLR_List.size()-NUM_RES_Con)/NUM_RES; i++) {
            DLR_SpinList[7].append(new QTableWidgetItem);
            DLR_SpinList[7][i]->setText(Copy_DLR_List.at(i*NUM_RES + 10 + NUM_RES_Con));
            DLR_SpinList[7][i]->setTextAlignment(Qt::AlignCenter);
            ui->resTab->setItem(i, 9, DLR_SpinList[7][i]);
        }
    } else {
        for (i = 0; i < (Copy_DLR_List.size()-NUM_RES_Con)/NUM_RES; i++) {
            DLR_SpinList[7].append(new QTableWidgetItem);
            DLR_SpinList[7][i]->setText(Copy_DLR_List.at(i*NUM_RES + 10 + NUM_RES_Con));
            DLR_SpinList[7][i]->setTextAlignment(Qt::AlignCenter);

//            DLR_Offset_List_Right.append(new QTableWidgetItem);
//            DLR_Offset_List_Right[i]->setTextAlignment(Qt::AlignCenter);
//            DLR_Offset_List_Right[i]->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
//            DLR_Offset_List_Right[i]->setText("*");
            ui->resTab->setItem(i, 9, DLR_SpinList[7][i]);
        }
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      保存电阻配置
******************************************************************************/
void Widget_DLR::Pri_DLR_Save_Data()
{
    int i, j;
    for (i = 0; i < (Copy_DLR_List.size()-NUM_RES_Con)/NUM_RES; i++) {
        if (DLR_Box_List[i]->checkState() == 2) {
            Pri_judge_grade(i, 1);
        }
    }
    ui->dockWidget->hide();   DLR_Labelhide->hide();
    if (ui->Com_DLR->currentIndex() == 0) {
        DLR_Temp_Flag = true;
    } else {
        DLR_Temp_Flag = false;
    }
    //更新电阻数据
    for (i = 0; i < 5; i++) {
        if (i != 1) {
            Copy_DLR_List.replace(i, Edit_DLR_List[i]->text());
        }
    }

    Copy_DLR_List.replace(8+NUM_RES_Con, QString::number(ui->Res_ComTemp->value()));
    Copy_DLR_List.replace(6, QString::number(ui->Com_DLR->currentIndex()));
    Copy_DLR_List.replace(7, ui->Res_Unbalance->text());   //  电阻不平衡度设置参数
    Copy_DLR_List.replace(10, QString::number(DCR_DoubleSpinBox[0]->value()));
    //  电阻不平衡度设置参数
    if (Pri_check_extreme_point()) {
        Pri_Dlr_WMessage(tr("  设置端点错误，保存不成功   \n  端子之间不能间隔为3    \n  如：1-4"));
    } else {
        for (i = 0; i < (Copy_DLR_List.size() - NUM_RES_Con)/NUM_RES; i++) {
            Copy_DLR_List.replace(NUM_RES*i+NUM_RES_Con, \
                                  QString::number(ui->resTab->item(i, 1)->text().toInt()));
            Copy_DLR_List.replace(NUM_RES*i+NUM_RES_Con+1, \
                                  QString::number(ui->resTab->item(i, 2)->text().toInt()));
            for (j = 2; j < 4; j++) {
                Copy_DLR_List.replace(NUM_RES*i+NUM_RES_Con+j, \
                                      (DLR_SpinList[j][i]->text()));
                //  QString::number(DLR_SpinList[j][i]->value())
            }
            Copy_DLR_List.replace(NUM_RES*i + NUM_RES_Con + 4, DLR_STD_List[i]->text());
            Copy_DLR_List.replace(NUM_RES*i + 7 + NUM_RES_Con, \
                                  QString::number(DLR_Box_List[i]->checkState()));
        //    if (DLR_Compensate_Left)
            {
                Copy_DLR_List.replace(NUM_RES*i + 6 + NUM_RES_Con, ui->resTab->item(i, 8)->text());
            }
        //    if (DLR_Compensate_Right)
            {
                Copy_DLR_List.replace(NUM_RES*i + 10 + NUM_RES_Con, ui->resTab->item(i, 9)->text());
            }
        }
    }
}
bool Widget_DLR::Pri_check_extreme_point()
{
    int i;
    for (i = 0; i < (Copy_DLR_List.size()-NUM_RES_Con)/NUM_RES; i++) {
        if (DLR_Box_List[i]->checkState() == 2) {
            if ((abs(ui->resTab->item(i, 1)->text().toInt() - \
                     ui->resTab->item(i, 2)->text().toInt()))%3 == 0) {
                i = 100;
                break;
            }
        }
    }
    if (i == 100) {
        return true;
    } else {
        return false;
    }
}
double Widget_DLR::RealTime_Compensate(double Get_Temp, int Numb)
{
    double Temp = 0.0;
    Get_Temp = Get_Temp - 50.0;
    if (Get_Temp < 150) {
        switch (Copy_DLR_List[Numb*NUM_RES+5+NUM_RES_Con].toInt()) {
        case 0:  //  材料铜
            Temp = ((1 + Meterial_Copper*(ui->Res_StandTemp->text().toDouble() - \
                                          Get_Temp-ui->Res_ComTemp->value())));
            break;
        case 1:  //  材料铝
            Temp = ((1 + Meterial_Aluminum*(ui->Res_StandTemp->text().toDouble() - \
                                            Get_Temp-ui->Res_ComTemp->value())));
            break;
        case 2:  //  材料铜铝
            Temp = ((1 + Meterial_CA_Alloy*(ui->Res_StandTemp->text().toDouble() - \
                                            Get_Temp-ui->Res_ComTemp->value())));
            break;
        case 3:
            Temp = 1;
            break;
        default:
            //
            break;
        }
    } else {
        Temp = 10000;
    }
    return Temp;
}
QStringList Widget_DLR::DCR_Test_Result(can_frame canframe,  int Back_out_station, double Net_temp)
{
    int a_int;
    double a_double;

    a_int = 0;
    a_double = 0.0;
    QStringList Back_QStringList;
    Back_QStringList.clear();
    if ((canframe.data[2] == 1) || (canframe.data[2] == 2)) { // -档位（1，2）-"mΩ"
        Back_QStringList.append(QString::number((canframe.data[3]*256 + \
                            canframe.data[4])*(qPow(10, -(6 - canframe.data[2])))*1000));  //
        Back_QStringList.append("mΩ");
    } else if ((canframe.data[2] == 3) || (canframe.data[2] == 4) || \
               (canframe.data[2] == 5)) { // -档位（3，4，5）-"Ω"
        Back_QStringList.append(QString::number((canframe.data[3]*256 + \
                             canframe.data[4])*(qPow(10, -(6 - canframe.data[2])))));  //
        Back_QStringList.append("Ω");
    } else if ((canframe.data[2] == 6) || (canframe.data[2] == 7) || \
               (canframe.data[2] == 8)) { // -档位（6，7，8）-"KΩ" 其中（7，8）暂时未用到
        Back_QStringList.append(QString::number((canframe.data[3]*256 + \
                            canframe.data[4])*(qPow(10, (canframe.data[2] - 6)))/1000));  //
        Back_QStringList.append("KΩ");
    } else {
        //
    }
 /*   if (canframe.data[1] == 0) {
        Back_QStringList.append("6.409");
        Back_QStringList.append("Ω");
    } else if (canframe.data[1] == 1) {
        Back_QStringList.append("6.398");
        Back_QStringList.append("Ω");
    } else if (canframe.data[1] == 2) {
        Back_QStringList.append("6.364");
        Back_QStringList.append("Ω");
    } else {
        //
    } */
    Back_QStringList.append(QString::number(canframe.data[1]));
    if (canframe.data[2] < 6) {
        Back_QStringList.append(QString::number((canframe.data[3]*256 + \
                         canframe.data[4])*(qPow(10, -(6 - canframe.data[2])))));
    } else {
        Back_QStringList.append(QString::number((canframe.data[3]*256 + \
                         canframe.data[4])*(qPow(10, (canframe.data[2] - 6)))));
    }
    Back_QStringList.append(QString::number(canframe.data[2]));

    double dlr_data = 0.0; dlr_data = Back_QStringList.at(0).toDouble();
//    Back_QStringList.append(QString::number(dlr_data, 'f', \
//                                               (3 - (canframe.data[2])%3)));
//    Back_QStringList.append(Back_QStringList.at(1));

    if (DLR_Temp_Flag) { // 温度补偿
//        if ((canframe.data[5]*256+canframe.data[6])/10 == 200) {
//            Back_QStringList.clear();
//            Back_QStringList.append("Error");
//            return Back_QStringList;
//        }
//        a_int = (canframe.data[5]*256 + canframe.data[6]);
//        a_double = a_int;
//        dlr_data = dlr_data*(RealTime_Compensate((a_double/10), canframe.data[1]));
          a_double = Net_temp;
          dlr_data = dlr_data*(RealTime_Compensate((a_double/10), canframe.data[1]));
    }

    if ((Back_out_station == 0x13)) {
        // 线路补偿  (DLR_Compensate_Left) && // 线路补偿在温度补偿之后
        dlr_data = (dlr_data - (Copy_DLR_List.at(NUM_RES*canframe.data[1] \
                                + 6 + NUM_RES_Con).toDouble()));
    }
    if ((Back_out_station == 0x14)) { // (DLR_Compensate_Right) &&
        dlr_data = (dlr_data - (Copy_DLR_List.at(NUM_RES*canframe.data[1] \
                                + 10 + NUM_RES_Con).toDouble()));
    }

    if (dlr_data < 0) {   //  测试时不能出现负数
        dlr_data = 0;
    }

    Back_QStringList.replace(0, QString::number(dlr_data, 'f', \
                              (3 - (canframe.data[2])%3))); // -确保5位的显示数字
    return Back_QStringList;
}

QStringList Widget_DLR::DCR_Test_Quick_Result(can_frame canframe)
{
    int a_int;
    double a_double;

    a_int = 0;
    a_double = 0.0;
    QStringList Back_QStringList;
    Back_QStringList.clear();
    if ((canframe.data[2] == 1) || (canframe.data[2] == 2)) { // -档位（1，2）-"mΩ"
        Back_QStringList.append(QString::number((canframe.data[3]*256 + \
                            canframe.data[4])*(qPow(10, -(6 - canframe.data[2])))*1000));  //
        Back_QStringList.append("mΩ");
    } else if ((canframe.data[2] == 3) || (canframe.data[2] == 4) || \
               (canframe.data[2] == 5)) { // -档位（3，4，5）-"Ω"
        Back_QStringList.append(QString::number((canframe.data[3]*256 + \
                             canframe.data[4])*(qPow(10, -(6 - canframe.data[2])))));  //
        Back_QStringList.append("Ω");
    } else if ((canframe.data[2] == 6) || (canframe.data[2] == 7) || \
               (canframe.data[2] == 8)) { // -档位（6，7，8）-"KΩ" 其中（7，8）暂时未用到
        Back_QStringList.append(QString::number((canframe.data[3]*256 + \
                            canframe.data[4])*(qPow(10, (canframe.data[2] - 6)))/1000));  //
        Back_QStringList.append("KΩ");
    } else {
        //
    }

    Back_QStringList.append(QString::number(canframe.data[1]));
    if (canframe.data[2] < 6) {
        Back_QStringList.append(QString::number((canframe.data[3]*256 + \
                         canframe.data[4])*(qPow(10, -(6 - canframe.data[2])))));
    } else {
        Back_QStringList.append(QString::number((canframe.data[3]*256 + \
                         canframe.data[4])*(qPow(10, (canframe.data[2] - 6)))));
    }
    Back_QStringList.append(QString::number(canframe.data[2]));

    double dlr_data = 0.0; dlr_data = Back_QStringList.at(0).toDouble();


    if (DLR_Temp_Flag) { // 温度补偿
        if ((canframe.data[5]*256+canframe.data[6])/10 == 200) {
            //
            return Back_QStringList;
        }
        a_int = (canframe.data[5]*256 + canframe.data[6]);
        a_double = a_int;
        dlr_data = dlr_data*(RealTime_Compensate((a_double/10), canframe.data[1]));
    }

    if (dlr_data < 0) {   //  测试时不能出现负数
        dlr_data = 0;
    }

    Back_QStringList.replace(0, QString::number(dlr_data, 'f', \
                              (3 - (canframe.data[2])%3))); // -确保5位的显示数字
    return Back_QStringList;
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.3.1
  * brief:      电阻材料的切换选择
******************************************************************************/
void Widget_DLR::on_resTab_cellClicked(int row,  int column)
{
    int i;
    int number_column;
    ui->Key_1->show(); ui->Key_2->show(); ui->Key_3->show(); ui->Key_4->show();
    ui->Key_5->show(); ui->Key_6->show(); ui->Key_7->show(); ui->Key_8->show();

    if (Init_Channel_6) {
        ui->Key_7->hide();
        ui->Key_8->hide();
    } else {
        //
    }

    if (column == 1 || column == 2) {
        if (column == 1) {
            number_column = ui->resTab->item(row, 2)->text().toInt();
            if ((number_column == 1) || (number_column == 4) || (number_column == 7)) {
                ui->Key_1->hide();   ui->Key_4->hide();   ui->Key_7->hide();
            } else if ((number_column == 2) || (number_column == 5) || (number_column == 8)) {
                ui->Key_2->hide();   ui->Key_5->hide();   ui->Key_8->hide();
            } else if ((number_column == 3) || (number_column == 6)) {
                ui->Key_3->hide();   ui->Key_6->hide();
            }
        } else if (column == 2) {
            number_column = ui->resTab->item(row, 1)->text().toInt();
            if ((number_column == 1) || (number_column == 4) || (number_column == 7)) {
                ui->Key_1->hide();   ui->Key_4->hide();   ui->Key_7->hide();
            } else if ((number_column == 2) || (number_column == 5) || (number_column == 8)) {
                ui->Key_2->hide();   ui->Key_5->hide();   ui->Key_8->hide();
            } else if ((number_column == 3) || (number_column == 6)) {
                ui->Key_3->hide();   ui->Key_6->hide();
            }
        }
        DLR_Labelhide->show();
        ui->dockWidget->show();
        ui->dockWidget->raise();
        //  ui->resTab->setEditTriggers(QAbstractItemView::NoEditTriggers);
    } else if (column == 6) {
        int resId = (Copy_DLR_List[row*NUM_RES+9+NUM_RES_Con].toInt()+1)%DLR_Unit.size();

        /* if (row == 0)
        {
            for (i=0;i<8;i++)
            {
                Copy_DLR_List.replace(i*NUM_RES+9+NUM_RES_Con, QString::number(resId));
                QTableWidgetItem *UnitItem = new QTableWidgetItem(DLR_Unit[resId]);
                UnitItem->setTextAlignment(Qt::AlignCenter);
                UnitItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                ui->resTab->setItem(i, 6, UnitItem);
            }
        }     */
        //  else
        {
            Copy_DLR_List.replace(row*NUM_RES+9+NUM_RES_Con, QString::number(resId));
            QTableWidgetItem *UnitItem = new QTableWidgetItem(DLR_Unit[resId]);
            UnitItem->setTextAlignment(Qt::AlignCenter);
            UnitItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            ui->resTab->setItem(row, 6, UnitItem);
            ui->resTab->setEditTriggers(QAbstractItemView::AllEditTriggers);
            if (resId == 2) {
                ui->resTab->item(row, 3)->setText("0");
                ui->resTab->item(row, 4)->setText("1");
                ui->resTab->item(row, 5)->setText("1");
            }
        }
        ui->resTab->setEditTriggers(QAbstractItemView::AllEditTriggers);
    } else if (column == 7) {
        int resId = (Copy_DLR_List[row*NUM_RES + 5 + NUM_RES_Con].toInt() + 1)%DLR_Meterial.size();
        if (row == 0) {
            for (i = 0; i < 8; i++) {
                Copy_DLR_List.replace(i*NUM_RES + 5 + NUM_RES_Con, QString::number(resId));
                QTableWidgetItem *pItem = new QTableWidgetItem(DLR_Meterial[resId]);
                pItem->setTextAlignment(Qt::AlignCenter);
                pItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                ui->resTab->setItem(i, 7, pItem);
            }
        } else {
            Copy_DLR_List.replace(row*NUM_RES+5+NUM_RES_Con, QString::number(resId));
            QTableWidgetItem *pItem = new QTableWidgetItem(DLR_Meterial[resId]);
            pItem->setTextAlignment(Qt::AlignCenter);
            pItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            ui->resTab->setItem(row, 7, pItem);
        }
        ui->resTab->setEditTriggers(QAbstractItemView::AllEditTriggers);
    } else if (column == 8) {
          /*      if (DLR_Compensate_Left)
                {
                    DLR_Labelhide->show();
                    QString stra, strb, strc;
                    bool ok;
                    stra=QString(tr("    当前补偿值为"))+DLR_SpinList[6][row]->text()+\
         DLR_Unit[Copy_DLR_List[row*NUM_RES+9+NUM_RES_Con].toInt()]+"   \n";
                    strb=QString(tr("    补偿值范围：0～"))+
         QString::number(((double)(qPow(10, Pri_judge_grade(row, 0)%3))), 'f', \
         (3-Pri_judge_grade(row, 0)%3))+DLR_Unit \
         [Copy_DLR_List[row*NUM_RES+9+NUM_RES_Con].toInt()]+"   \n";
                    strc=QString(tr("    修改补偿值为：  "));
                    QInputDialog *input=new QInputDialog(this);
                    input->setStyleSheet("QInputDialog{border: gray;border-radius: 10px;"\
                    "padding:2px 4px;background-color: gray;height:390px;width:375px;}");
                    input->setWindowFlags(Qt::FramelessWindowHint);
                    input->setInputMode(QInputDialog::DoubleInput);
                    input->setDoubleDecimals((3-Pri_judge_grade(row, 1)%3));
                    input->setDoubleMinimum(0);
                    input->setDoubleMaximum((((double)(qPow(10, Pri_judge_grade(row, 0)%3)))));
                    input->setLabelText(stra+strb+strc);
                    input->setDoubleValue(DLR_SpinList[6][row]->text().toDouble());
                    input->setOkButtonText(tr("确定"));
                    input->setCancelButtonText(tr("取消"));
                    ok =input->exec();
                    if (ok)
                    {
                        DLR_SpinList[6][row]->setText(QString::number(input->doubleValue()));
                    }
                    DLR_Labelhide->hide();
                } */
    }
}
void Widget_DLR::on_AutoSet(QStringList Test)
{
    int resId;
    ui->resTab->item(Test.at(2).toInt(), 5)->setText(Test.at(0));
    if (ui->resTab->item(Test.at(2).toInt(), 6)->text() != Test.at(1)) {
        resId = DLR_Unit.indexOf(Test.at(1));
        Copy_DLR_List.replace(Test.at(2).toInt()*NUM_RES + 9 + NUM_RES_Con, QString::number(resId));
        QTableWidgetItem *UnitItem = new QTableWidgetItem(DLR_Unit[resId]);
        UnitItem->setTextAlignment(Qt::AlignCenter);
        UnitItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ui->resTab->setItem(Test.at(2).toInt(), 6, UnitItem);
    }
}
void Widget_DLR::on_button_autocalc_clicked()   //  自动计算
{
    int i;
    button_autocalc_Flag = 1;
    for (i = 0; i < (Copy_DLR_List.size() - NUM_RES_Con)/NUM_RES; i++) {  //  电阻测试项目 8项
        if (DLR_Box_List[i]->checkState() == 2) {
            DLR_SpinList[3][i]->setText(QString::number\
                                        (DLR_STD_List[i]->text().toDouble()*(100 \
                             + (ui->Res_calculateUp->text().toInt()))/100, 'f', 3));
            DLR_SpinList[2][i]->setText(QString::number\
                                        (DLR_STD_List[i]->text().toDouble()*(100 \
                             - (ui->Res_calculateDown->text().toInt()))/100, 'f', 3));
        }
    }
    button_autocalc_Flag = 0;
}
void Widget_DLR::initSpinBox(QDoubleSpinBox *spin,  int dec, int min, int max)
{
    spin->setMaximum(max);              // 最大值
    spin->setMinimum(min);              // 最小值
    spin->setDecimals(dec);             // 小数点后位数
    // spin->setStyleSheet("border:none"); // 透明
    spin->setAlignment(Qt::AlignCenter); // 居中
    spin->setFocusPolicy(Qt::ClickFocus);
    spin->setButtonSymbols(QAbstractSpinBox::NoButtons);
}
void Widget_DLR::on_resTab_cellChanged(int row, int column)
{
    int i, After_Point = 0;
    QString str;
    if (Init_Flag) {
        return;
    }
    Init_Flag = true;
    if ((column == 3) || (column == 4) || (column == 5) || (column == 8) || (column == 9)) {
        str = ui->resTab->item(row, column)->text();
        if (str == NULL) {
            ui->resTab->item(row, column)->setText("0");
        }
        for (i = 0; i < str.length(); i++) {  //判断输入是" 0-9 . "
            if (((str[i] >= '0') && (str[i] <= '9')) \
                    || (str[i] == '.') || (str[i] == '*') || (str[i] == '-')) {
                //
            } else {
                ui->resTab->item(row, column)->setText("0");
                break;
            }

            if (str[i] == '.') { //  判断是否规范
                After_Point = str.length() - i - 1;
                if ((i == 0)) {
                    ui->resTab->item(row, column)->setText("0");
                }
                if (i == (str.length()-1)) {
                    ui->resTab->item(row, column)->setText\
                            (ui->resTab->item(row, column)->text().left(i));
                }
            }
        }

        if (Copy_DLR_List.at(row*NUM_RES+9+NUM_RES_Con).toInt() == 2) {
            if (ui->resTab->item(row, column)->text().toDouble() > 20) {
                ui->resTab->item(row, column)->setText("20");
            }
        } else {
            if (ui->resTab->item(row, column)->text().toDouble() > 2000) {
                ui->resTab->item(row, column)->setText("2000");
            }
        }

        if ((column == 5) || (column == 8) || (column == 9)) {
            ui->resTab->item(row, column)->setText\
                    (QString::number(ui->resTab->item(row, column)->text().toDouble(), \
                                     'f', 3 - Pri_judge_grade(row, 0) % 3));
        }
        if ((column == 3) || (column == 4)) {
            ui->resTab->item(row, column)->setText\
                 (QString::number(ui->resTab->item(row, column)->text().toDouble(), \
                                   'f', 3 - Pri_judge_grade(row, 0) % 3));
            if (column == 4) {  // 上限改变，下限和补偿值也相应改变
                ui->resTab->item(row, 3)->setText\
                        (QString::number(ui->resTab->item(row, 3)->text().toDouble(), \
                                         'f', 3-Pri_judge_grade(row, 0)%3));
             /*    ui->resTab->item(row, 8)->setText\
                 (QString::number(ui->resTab->item(row, 8)->text().toDouble(), \
                 'f', 3-Pri_judge_grade(row, 0)%3)); */
            }
        }
        if (!button_autocalc_Flag) { // 非自动计算时，进行输入的上限下限比较
            if (column == 3) {
                if ((ui->resTab->item(row, 3)->text().toDouble()) > \
                        (ui->resTab->item(row, 4)->text().toDouble())) {
                    Pri_Dlr_WMessage(tr("       输入错误，下限大于上限      "));
                    ui->resTab->item(row, 3)->setText("0");
                }
            }
            if (column == 4) {
                if ((ui->resTab->item(row, 3)->text().toDouble()) > \
                        (ui->resTab->item(row, 4)->text().toDouble())) {
                    Pri_Dlr_WMessage(tr("       输入错误，下限大于上限       "));
                    ui->resTab->item(row, 3)->setText("0");
                }
            }
        }
    }
    Init_Flag = false;
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.5.19
  * brief:      设置警告弹出框
******************************************************************************/
void Widget_DLR::Pri_Dlr_WMessage(QString Waring_Text)
{
    QMessageBox message;
    message.setWindowFlags(Qt::FramelessWindowHint);
    message.setStyleSheet\
            ("QMessageBox{border: gray;border-radius: 10px;"\
             "padding:2px 4px;background-color: gray;}");
    message.setText("\n"+Waring_Text+"\n");

    message.addButton(QMessageBox::Ok)->setStyleSheet\
            ("height:39px;width:75px;border:5px groove;"\
             "border:none;border-radius:10px;padding:2px 4px;");
    message.setButtonText(QMessageBox::Ok, QString(tr("确 定")));
    message.setIcon(QMessageBox::Warning);
    message.exec();
}
int  Widget_DLR::Pri_judge_grade(int ROW, bool flag)  //  判断出档位 进行测试
{
    Init_Flag = true;
    int i = 0, DLR_Grade = 0;
//    int resId;
    for (i = 1; i < 4; i++) {
        if (DLR_SpinList[3][ROW]->text().toDouble() <= (2*qPow(10, i))) {
            DLR_Grade = DLR_Unit.indexOf(ui->resTab->item(ROW, 6)->text())*3 + i - 1;
            // 由单位确定档位
            if (DLR_Grade == 0) {
                DLR_Grade = 1;
            }
            break;
        }
    }
 /*   if (flag == 1) {
        double Value = DLR_SpinList[3][ROW]->text().toDouble()*qPow(10, 3*DLR_Grade/3);
        for (i = DLR_Grade - 1; i >= 1; i--) {
            if (Value < (2*qPow(10, i + 1))) {
                DLR_Grade = i;
                if ((DLR_Grade/3) != (DLR_Unit.indexOf(ui->resTab->item(ROW, 6)->text()))) {
                    resId = (DLR_Grade/3);
                    Copy_DLR_List.replace(ROW*NUM_RES + 9 + NUM_RES_Con, QString::number(resId));
                    QTableWidgetItem *UnitItem = new QTableWidgetItem(DLR_Unit[resId]);
                    UnitItem->setTextAlignment(Qt::AlignCenter);
                    UnitItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                    ui->resTab->setItem(ROW, 6, UnitItem);

                    ui->resTab->item(ROW, 4)->setText\
                            (QString::number(ui->resTab->item(ROW, 4)->text().toDouble()*1000, \
                                             'f', 3-DLR_Grade%3));
                    ui->resTab->item(ROW, 3)->setText\
                            (QString::number(ui->resTab->item(ROW, 3)->text().toDouble()*1000, \
                                             'f', 3-DLR_Grade%3));
                    ui->resTab->item(ROW, 5)->setText\
                            (QString::number(ui->resTab->item(ROW, 5)->text().toDouble()*1000, \
                                             'f', 3-DLR_Grade%3));
                }
            } else {
                break;
            }
        }
    }*/
    if ((Init_dcr_15) && (DLR_Grade == 3)) {
        if (DLR_SpinList[3][ROW]->text().toDouble() >= 10) {
            DLR_Grade = 4;
        } else {
            //
        }
    } else {
        //
    }

    if (DLR_Grade == 0) {
        DLR_Grade = 1;
    }
    Init_Flag = false;
    flag = 0;
    return DLR_Grade;
}
void Widget_DLR::on_Res_calculateUp_editingFinished() // 下限跟随上限变化
{
    ui->Res_calculateDown->setValue(ui->Res_calculateUp->value());
}

/******************************************************************************
  * version:    2.0.7.1
  * author:     sl
  * date:       2017.8.17
  * brief:      快速设置
  *             （在快速设置时不进行配置文件的修改）
******************************************************************************/
void Widget_DLR::Pri_DLR_Default_value(QString number)
{
    int i;
    if (number.size() == 0) {
        return;
    } else {
        //
    }
    for (i = 0; i < 8; i++) {
        DLR_Box_List[i]->setChecked(false);
    }
    for (i = 0; i < number.size()/2; i++) {
        ui->resTab->item(i, 1)->setText(number.mid(i*2, 1));
        ui->resTab->item(i, 2)->setText(number.mid(i*2 + 1, 1));
        DLR_Box_List[i]->setChecked(true);
    }
//    ui->Res_calculateUp->setValue(10);
//    ui->Res_Time->setValue(0);
//    ui->Com_DLR->setCurrentIndex(1);
//    ui->Res_Unbalance->setValue(0);
}
void Widget_DLR::Pri_DLR_Set_PWR_Conf()
{
    int i;
    for (i = 0; i < 5; i++) {
        DLR_Box_List[i]->setChecked(false);
    }
    for (i = 0; i < 5; i++) {
        ui->resTab->item(i, 1)->setText(QString::number(i + 1));
        ui->resTab->item(i, 2)->setText(QString::number(i + 2));
        ui->resTab->item(i, 3)->setText("0");
        ui->resTab->item(i, 4)->setText("200");
        DLR_Box_List[i]->setChecked(true);

        Copy_DLR_List.replace(i*NUM_RES + 9 + NUM_RES_Con, "1");
        QTableWidgetItem *UnitItem = new QTableWidgetItem(DLR_Unit[1]);
        UnitItem->setTextAlignment(Qt::AlignCenter);
        UnitItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ui->resTab->setItem(i, 6, UnitItem);
    }
}
bool Widget_DLR::Pub_Conf_Station(QString Station)
{
    int i;
    bool Success; Success = false;
    DCR_Offect_Station = Station;
    if (DCR_Offect_Station == QString(tr("Left"))) {
        if (DLR_Compensate_Left) {
            DLR_Compensate_Left = false;
            for (i = 0; i < 8; i++) {
                Copy_DLR_List.replace(NUM_RES*i + 6 + NUM_RES_Con, "0");
            //    Copy_DLR_List.replace(5, "0");   // 电阻未补偿
            }
            Pub_Conf_Set_DLR("", 2);
            Success = true;
        } else {
            Pub_Conf_Set_DLR("0", 4);
            Pub_Conf_Set_DLR("0", 5); // 左工位 13工位
        }
    } else if (DCR_Offect_Station == QString(tr("Right"))) {
        if (DLR_Compensate_Right) {
            DLR_Compensate_Right = false;
            for (i = 0; i < 8; i++) {
                Copy_DLR_List.replace(NUM_RES*i + 10 + NUM_RES_Con, "0");
            //    Copy_DLR_List.replace(8, "0");   // 电阻未补偿
            }
            Pub_Conf_Set_DLR("", 2);
            Success = true;
        } else {
            Pub_Conf_Set_DLR("0", 4);
            Pub_Conf_Set_DLR("1", 5);
        }
    }
    return Success;
}
int Widget_DLR::Pub_Conf_DLR_Compensate(QStringList list)
{
    int i;
    int Back_int; Back_int = 0;
    strRES_Compensate_Value = list[0];
    strRES_Compensate = list[3];
    strRES_Compensate_Grade = list[4].toInt();
    strRES_Compensate_Num = list[2].toInt();

    if (DCR_Offect_Station == tr("Left")) {
        for (i = 0; i < 8; i++) {
            if (i != strRES_Compensate_Num) {
                continue;
            }
            if ((strRES_Compensate.toDouble()) < \
                    (2*(qPow(10, (strRES_Compensate_Grade) - 2)))) {
                // 电阻补偿5% 9月7日升级10%  百分之十
                Copy_DLR_List.replace(NUM_RES*i + 6 + NUM_RES_Con, strRES_Compensate_Value);
                DLR_SpinList[6][i]->setText(Copy_DLR_List.at(NUM_RES*i + 6 + NUM_RES_Con));
                break;
            } else {
                RES_Compensate_Ok = 1;
            }
        }
        RES_Compensate_Sum = RES_Compensate_Sum++;
        if (RES_Compensate_Sum != DLR_TestNumber) {
            return 0;
        }
        RES_Compensate_Sum = 0;
        if (RES_Compensate_Ok == 0) {
            Back_int = 1;
            DLR_Compensate_Left = true;
        //    Copy_DLR_List.replace(5, "1");   // 电阻已补偿
            Pub_Conf_Set_DLR("", 2);
        } else {
            RES_Compensate_Ok = 0;
            Back_int = 2;
        //    Copy_DLR_List.replace(5, "0");   // 电阻未补偿
            for (i = 0; i < 8; i++) {
                Copy_DLR_List.replace(NUM_RES*i + 6 + NUM_RES_Con, "0.0");
            }
        }
    } else if (DCR_Offect_Station == tr("Right")) {
        for (i = 0; i < 8; i++) {
            if (i != strRES_Compensate_Num) {
                continue;
            }
            if ((strRES_Compensate.toDouble()) < \
                    (2*(qPow(10, (strRES_Compensate_Grade) - 2)))) {
                // 电阻补偿5% 9月7日升级10%  百分之十
                Copy_DLR_List.replace(NUM_RES*i + 10 + NUM_RES_Con, strRES_Compensate_Value);
                break;
            } else {
                RES_Compensate_Ok = 1;
            }
        }
        RES_Compensate_Sum = RES_Compensate_Sum++;
        if (RES_Compensate_Sum != DLR_TestNumber) {
            return 0;
        }
        RES_Compensate_Sum = 0;
        if (RES_Compensate_Ok == 0) {
            Back_int = 3;
            DLR_Compensate_Right = true;
        //    Copy_DLR_List.replace(8, "1");   // 电阻已补偿
            Pub_Conf_Set_DLR("", 2);
        } else {
            RES_Compensate_Ok = 0;
            Back_int = 4;
        //    Copy_DLR_List.replace(8, "0");   // 电阻未补偿
            for (i = 0; i < 8; i++) {
                Copy_DLR_List.replace(NUM_RES*i + 10 + NUM_RES_Con, "0.0");
            }
        }
    } else {
        //
    }
    return Back_int;
}
QStringList Widget_DLR::DCR_Test_Param()
{
    QString str;
    QStringList  strSql;
    QStringList  dlr_unit;  dlr_unit.clear();   dlr_unit << "mΩ" << "Ω" << "KΩ";
    QStringList strDLR_UpDown, strParam, strTest;
    strTest.clear();
    strParam.clear();
    strDLR_UpDown.clear();
    for (int m = 0; m < 20; m++) {
        strDLR_UpDown.append("0");
    }
    for (int j = 0; j < 8; j++) {
        if (DLR_Box_List[j]->checkState() == 2) {
            str = QString(tr("电阻")) + Copy_DLR_List.at(j*NUM_RES+NUM_RES_Con) + \
                    "-" + Copy_DLR_List.at(j*NUM_RES+NUM_RES_Con+1);
            strTest.append(str);    //测试项目
            str.clear();
            strDLR_UpDown.replace\
                    (j*2, QString::number(DLR_SpinList[2][j]->text().toDouble(), 'f', 3));
            str = DLR_SpinList[2][j]->text() + \
                    dlr_unit.at(Copy_DLR_List[j*NUM_RES+NUM_RES_Con+9].toInt()) + "~";

            strDLR_UpDown.replace(j*2 + 1, \
                                  QString::number(DLR_SpinList[3][j]->text().toDouble(), 'f', 3));
            str += DLR_SpinList[3][j]->text() + \
                    dlr_unit.at(Copy_DLR_List[j*NUM_RES+NUM_RES_Con+9].toInt());
            strParam.append(str);
            strSql.append(tr("电阻"));
        }
    }
    strDLR_UpDown.append(ui->Res_Unbalance->text());
    if (Copy_DLR_List.at(10).toInt() == 1) {
        if ((ui->Res_Unbalance->text() != "0.000") && (DLR_TestNumber >= 3)) {
            strTest.append(QString(tr("电阻")));
            strParam.append(QString(tr("不平衡度 ")) + ui->Res_Unbalance->text() + "%");
            strSql.append(tr("电阻"));
        } else {
            //
        }
        if (YY_Type) {
            if ((ui->Res_Unbalance->text() != "0.000") && (DLR_TestNumber >= 6)) {
                strTest.append(QString(tr("电阻-2")));
                strParam.append(QString(tr("不平衡度-2 ")) + ui->Res_Unbalance->text() + "%");
                strSql.append(tr("电阻"));
            } else {
                //
            }
        } else {
            //
        } //-将(-电阻-)修改为(电阻)
    } else if (Copy_DLR_List.at(10).toInt() == 2) {
        if ((ui->Res_Unbalance->text() != "0.000") && (DLR_TestNumber >= 2)) {
            strTest.append(QString(tr("电阻")));
            strParam.append(QString(tr("不平衡度 ")) + ui->Res_Unbalance->text() + "%");
            strSql.append(tr("电阻"));
        }   //-将(-电阻-)修改为(电阻)
    } else if (Copy_DLR_List.at(10).toInt() == 3) {
        if ((ui->Res_Unbalance->text() != "0.000") && (DLR_TestNumber >= 2)) {
            strTest.append(QString(tr("电阻")));
            strParam.append(QString(tr("不平衡度 ")) + ui->Res_Unbalance->text());
            strSql.append(tr("电阻"));
        }   //-将(-电阻-)修改为(电阻)
    } else {
        //
    }
    QStringList Back_List;
    Back_List.append(QString::number(strTest.size()));
    Back_List.append(QString::number(strParam.size()));
    Back_List.append(QString::number(strDLR_UpDown.size()));
    Back_List.append(QString::number(strSql.size()));
    Back_List.append(strTest);
    Back_List.append(strParam);
    Back_List.append(strDLR_UpDown);
    Back_List.append(strSql);
    return Back_List;
}

void Widget_DLR::DLR_NetData(QStringList list, QString str) {
    Init_Flag = true;
    int i;
    if (str == QString(tr("test"))) {
        for (i = 0; i < 8; i++) {
            if (list.at(i).toInt() != 0) {
                DLR_Box_List[i]->setChecked(true);
            } else {
                DLR_Box_List[i]->setChecked(false);
            }
        }
    } else if (str == QString(tr("port1"))) {
        for (i = 0; i < 8; i++) {
            ui->resTab->item(i, 1)->setText(list.at(i));
        }
    } else if (str == QString(tr("port2"))) {
        for (i = 0; i < 8; i++) {
             ui->resTab->item(i, 2)->setText(list.at(i));
        }
    } else if (str == QString(tr("wire"))) {
        for (i = 0; i < 8; i++) {
             ui->resTab->item(i, 7)->setText(DLR_Meterial[list.at(i).toInt()]);
             Copy_DLR_List.replace(i*NUM_RES+5+NUM_RES_Con, list.at(i));
        }
    } else if (str == QString(tr("unit"))) {
        for (i = 0; i < 8; i++) {
            ui->resTab->item(i, 6)->setText(DLR_Unit[list.at(i).toInt()]);
            Copy_DLR_List.replace(i*NUM_RES+9+NUM_RES_Con, list.at(i));
        }
    } else if (str == QString(tr("min"))) {
        for (i = 0; i < 8; i++) {
             ui->resTab->item(i, 3)->setText(list.at(i));
        }
    } else if (str == QString(tr("max"))) {
        for (i = 0; i < 8; i++) {
             ui->resTab->item(i, 4)->setText(list.at(i));
        }
    } else if (str == QString(tr("std"))) {
        for (i = 0; i < 8; i++) {
             ui->resTab->item(i, 5)->setText(list.at(i));
        }
    } else if (str == QString(tr("std_temp"))) {
         Edit_DLR_List.at(0)->setValue(list.at(0).toDouble());
    } else if (str == QString(tr("mode"))) {
        DCR_DoubleSpinBox[0]->setValue(list.at(0).toInt());
    } else if (str == QString(tr("temp_comp"))) {
        ui->Com_DLR->setCurrentIndex(list.at(0).toInt());
    } else if (str == QString(tr("time"))) {
        ui->Res_Time->setValue(list.at(0).toDouble());
    } else if (str == QString(tr("comp_temp"))) {
        ui->Res_ComTemp->setValue(list.at(0).toDouble());
    } else if (str == QString(tr("noun"))) {
        ui->Res_Unbalance->setValue(list.at(0).toDouble());
    } else if (str == QString(tr("wire_comp1"))) {
        for (i = 0; i < 8; i++) {
            ui->resTab->item(i, 8)->setText(list.at(i));
        }
    } else if (str == QString(tr("wire_comp2"))) {
        for (i = 0; i < 8; i++) {
            ui->resTab->item(i, 9)->setText(list.at(i));
        }
        Pri_DLR_Save_Data();
    } else {
        //
    }
    Init_Flag = false;
}

void Widget_DLR::Pub_Conf_Set_DLR(QString str, int flag)
{
    switch (flag) {
    case 1:
        Pri_DLR_Init(str);
        break;
    case 2:
        Pri_DLR_Init_Compensate();
        break;
    case 3:
        Pri_DLR_Save_Data();
        break;
    case 4:
        Pri_DLR_Test(str);
        break;
    case 5:
        Pri_DLR_Start(str);
        break;
    case 6:
        Pri_DLR_Default_value(str);
        break;
    case 8:
        on_resTab_cellClicked(0, 3);
        break;
    case 9:
        on_button_autocalc_clicked();
        break;
    case 10:
        //
        break;
    case 11:
        break;
    case 12:
        Pri_DLR_Set_PWR_Conf();
        break;
    case 13:
        Init_dcr_balance = str.toInt();
        if ((Init_dcr_balance >=1) && (Init_dcr_balance <=3)) {
            //
        } else {
            Init_dcr_balance = 1;
        }
        break;
    case 14:
        qDebug() << "Widget_DLR::YYYYY";
        if ((str == "YY") || (str == "Y-YY") || (str == "D-YY") \
                || (str == "YY-PT")|| (str == "YY-1")) {
            YY_Type = true;
        } else {
            YY_Type = false;
        }
        break;
    case 100:
        if (str.toInt()) {
            Init_Channel_6 = true;
        } else {
            Init_Channel_6 = false;
        }
        break;
    default:
        break;
    }
}
void Widget_DLR::on_button_model_clicked()
{
    DCR_Widget->show();
}

