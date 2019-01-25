/*******************************************************************************
 * Copyrigh(c) 2015,  青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.10
 * brief:       主界面
*******************************************************************************/
#include "w_test.h"
#include "ui_w_test.h"
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.11
  * brief:      测试界面构造
******************************************************************************/
static int Qualified = 0;
static int Unqualified = 0;
static int Test_Count = 0;
static int count = 0;

w_Test::w_Test(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::w_Test)
{
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint); // 去掉标题栏
    ui->setupUi(this);

    int i = 0, j = 0;
    Qualified = 0; Unqualified = 0; Test_Count = 0;
    show_color.clear();
    show_color.append(ui->colorLabel01); // -线夹颜色配置参数
    show_color.append(ui->colorLabel02);
    show_color.append(ui->colorLabel03);
    show_color.append(ui->colorLabel04);
    show_color.append(ui->colorLabel05);
    show_color.append(ui->colorLabel06);
    show_color.append(ui->colorLabel07);
    show_color.append(ui->colorLabel08);

    wave_name.clear();
    wave_name.append(ui->label_A); // 显示
    wave_name.append(ui->label_B);
    wave_name.append(ui->label_C);

    test_parameters.clear();
    test_parameters.append(ui->label_model); // 配置参数
    test_parameters.append(ui->label_number);
    test_parameters.append(ui->label_user);
    test_parameters.append(ui->label_temp);

    Test_Item.clear();
    Test_Item.append(tr("清除"));
    Test_Item.append(tr("电阻")); // -1
    Test_Item.append(tr("反嵌")); // -2
    Test_Item.append(tr("绝缘")); // -3
    Test_Item.append(tr("交耐")); // -4
    Test_Item.append(tr("直耐")); // -5
    Test_Item.append(tr("匝间")); // -6
    Test_Item.append(tr("电参")); // -7
    Test_Item.append(tr("电感")); // -8
    Test_Item.append(tr("堵转")); // -9
    Test_Item.append(tr("低启")); // -10

    Test_Item.append(tr("HALL")); // -11
    Test_Item.append(tr("负载")); // -12
    Test_Item.append(tr("空载")); // -13
    Test_Item.append(tr("BEMF")); // -14

    Error_Mount = 0;
    for (i = 0; i < 3; i++) { //-添加波形图形
        wave[i] = new wt_Wave(this);
        wave[i]->setFixedWidth(200);
        wave[i]->setStyleSheet("border-style:outset;border-width:1px;border-color:#447684;");
        ui->waveLayout->addWidget(wave[i], 0);
    }
    ui->waveLayout->addStretch();

    ui->testTab->setColumnWidth(0, 29); // -测试表格的宽度调整 35 77 250
    ui->testTab->setColumnWidth(1, 87);
    ui->testTab->setColumnWidth(2, 250);
    ui->testTab->setColumnWidth(3, 218);
    // -ui->testTab->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    //自动等宽

    ui->testTab->horizontalHeader()->setStyleSheet("QHeaderView::section{"\
                                     "background-color:#191919;color: white;"\
                                     "padding-left: 4px;border: 1px solid #447684;}");
    ui->testTab->horizontalHeader()->setFixedHeight(25);
    ui->testTab->horizontalHeader()->setResizeMode(QHeaderView::Fixed);
  //  ui->testTab->verticalHeader()->setResizeMode(QHeaderView::Stretch);
  //  connect(ui->testTab, SIGNAL(itemChanged(QTableWidgetItem*)),
  //          ui->testTab, SLOT(resizeRowsToContents()) );


    PG_Row.clear();                          // -位置不可动,放在时间更新之前
    QTimer *Timer_Update = new QTimer(this); // -3秒进行时间的更新
    connect(Timer_Update, SIGNAL(timeout()), this, SLOT(join_updateTime()));
    Timer_Update->start(3000);

    DCR_Total_Number  = 0;
    DCR_TestItem_H    = 0;  DCR_TestItem_L  = 0;
    MAG_Total_Number  = 0;  MAG_TestItem    = 0;
    IMP_Total_Number  = 0;  IMP_TestItem    = 0;
    INDL_Total_Number = 0;
    INDL_TestItem_H   = 0;  INDL_TestItem_L = 0;

    Test.Finshed_Count    = 0;
    Test.Next_Finsh_Count = 0;
    Test.Current_Row      = 0;
    Test.NG_Item          = 0;
    Test.Interrupted      = false;
    Test.Status_Ing       = Test_Station_Free;
    Test.Judge_NG         = false;

    Test.serial_number = "";                           // -编码条码信息，初始化为“”
    Model_Occur_Unqualified = Test_NG_Continue; // -遇到不合格的模式

    Temp_Error = false; // -温度传感器错误
    Temp_In    = false; // -机箱内温度过高

    DCR_Test_Record_Number   = 0; // -电阻测试的数目
    MAG_Test_Record_Number   = 0; // -反嵌测试的数目
    IMP_Test_Record_Number   = 0; // -匝间测试的数目
    INDL_Test_Record_Number  = 0; // -电感测试的数目

    MAG_Current_Testing_Item = 0; // -反嵌测试中的项目
    IMP_Current_Testing_Item = 0; // -匝间测试中的项目

    Recrd_Wave  = 0;
    CRecrd_Wave = 0;

    IRFinsh      = false;
    NoLoadFinsh  = false;
    RemoveLastIR = false;
    RemoveLastNOLoad = false;
    TestIRACW    = 0;

    TaskMagDirnumber = 0;
    Data_Complete = false;
    StrResult_Size = 0;
    StrJudge_Size  = 0;

    Mouse.Time = new QTimer(this);
    connect(Mouse.Time, SIGNAL(timeout()), this, SLOT(join_test_mouse_check()));
    Mouse.Ms   = 0;
    Mouse.Us   = 0;
    Mouse.Flag = false;

    keyboard_string.clear();
    key_board = new QTimer(this);
    connect(key_board, SIGNAL(timeout()), this, SLOT(join_key_out()));

    Beep.Time = new QTimer(this);
    connect(Beep.Time, SIGNAL(timeout()), this, SLOT(join_beep_stop()));
    Beep.Flag    = false;
    Beep.Grade   = 0;
    Beep.OK_Time = 0.0;
    Beep.NG_Time = 0.0;

    Button_Start_Time_Flag = false;
    Button_Start_Station   = 0x13;
    Self_starting.clear();
    Self_starting.append("0");
    Self_starting.append("0");
    Self_starting.append("0");

    join_updateTime(); // -显示系统时间(可以屏蔽)

    label_Show = new QLabel(this);
    label_Show->setGeometry(0, 420, 600, 130);
    label_Show->show();

    Test_TShape = new wt_Wave(this);
    Test_TShape->setGeometry(0, 0, 800, 600);
    Test_TShape->TestShape_Flag = 1;
    Test_TShape->setStyleSheet("background-color:#191919;");
    Test_TShape->setWindowFlags(Qt::FramelessWindowHint);
    Test_TShape->hide();
    connect(Test_TShape, SIGNAL(SET_Free()), this, SLOT(join_shape_set_free()));

    label_Waring = new QLabel(this);
    label_Waring->setGeometry(0, 0, 800, 600);
    label_Waring->setWindowFlags(Qt::WindowStaysOnTopHint);
    label_Waring->hide();
    Test_Waring_Flag = false;

    record_wave_row = 0;
    Histogram_List.clear();
    Histogram_List.append(ui->label_sum);
    Histogram_List.append(ui->label_qualified);
    Histogram_List.append(ui->label_Unqualified);
    Histogram_List.at(0)->setText("0");
    Histogram_List.at(1)->setText("0");
    Histogram_List.at(2)->setText("0");

    ui->label_station->setText(tr("左")); // -设置(显示工位信息)和(工位信息显示框的背景颜色)
    ui->label_station->setStyleSheet("color: rgb(255, 255, 255);"\
                                     "border: none;font: Bold 40pt  Ubuntu  ;");
    ui->frame_state->setStyleSheet("border:1px groove ;"\
                                   "background-color: #191919;"\
                                   "border-radius:8px;border-color: #447684;");

    QStringList Allocation_list;         // -默认 Allocation/Item
    Allocation_list.clear();
    Allocation_list.append("13");
    Allocation_list.append("14");
    Allocation_list.append("0");
    Allocation_list.append("0");
    Allocation_list.append("0");
    Allocation_list.append("0");
    Allocation_list.append("1");

    QSettings *set_Sys = new QSettings(Sys_path, QSettings::IniFormat); //-获取配置信息
    set_Sys->setIniCodec("GB18030");
    Ini_Number      = set_Sys->value("Allocation/All", "7").toInt();
    Ini_Proj        = set_Sys->value("Allocation/Item", \
                                     Allocation_list).toStringList().mid(5, Ini_Number);
    Ini_Mag_Hide    = set_Sys->value("magshapehide/text", "0").toInt();
    Ini_NG_Data     = set_Sys->value("NG/text", "0").toInt();
    Ini_Stagnate    = set_Sys->value("stagnate/text", "0").toInt();
    Ini_NineBoard   = set_Sys->value("BoardNumber/text", "0").toInt();
    Ini_AMPTemp     = set_Sys->value("AMP_Temp/text", "50").toInt();
    Ini_DCR_Ask     = set_Sys->value("DCR_In/text", "1").toInt();
    GND_Volt        = set_Sys->value("System/GND", "20").toInt();
    Ini_Motor       = set_Sys->value("System/PG", "Common").toString();
//    Ini_NoBalance   = set_Sys->value("System/Unbalance", "1").toInt();
    Ini_LR          = set_Sys->value("System/LR", "0").toInt();
    Ini_Pwr_Turn    = set_Sys->value("System/Shan_Turn", "0").toInt();
    Ini_ACWandIR    = set_Sys->value("commonACW/text", "0").toInt();
    // -设置相间耐压和普通耐压的转换
    Ini_SaveNG      = set_Sys->value("Sql/SaveNG", "0").toInt();
    Ini_Direction   = set_Sys->value("System/Turn", "0").toInt();
    Ini_Power_Chose = set_Sys->value("power/Text", "0").toInt();
    Ini_MAG_Device  = set_Sys->value("System/MAG_Device", "0").toInt();    // -设置测试IO板
    Ini_Vacuum_Model = set_Sys->value("System/Vacuum_Model", "0").toInt(); // -设置真空测试
    Ini_imp_min      = set_Sys->value("imp_min/area_diff", "0").toInt(); // -设置匝间下限
    Ini_BLDC_PG      = set_Sys->value("System/PLC_BLDC_PG", "0").toInt(); // -设置 BLDC_PG 控制 PLC
    Self_starting    = set_Sys->value("Selfstart/value", Self_starting).toStringList();
    Ini_IO_Model     = set_Sys->value("System/IO_Model", "0").toInt();
    Ini_IO_Test      = set_Sys->value("System/IO_Test", "0").toInt();
    Ini_IO_Delay      = set_Sys->value("System/IO_Delay", "0").toInt();
    Ini_IO_Delay_Time = set_Sys->value("System/IO_Delay_Time", "0").toInt();
    NG_Push           = set_Sys->value("System/NG_Push", "0").toInt();
    Ini_ROT       = false;

    QString pgtext;
    pgtext = set_Sys->value("PGturn/text").toString();
    if (pgtext == QString(tr("hall"))) {
        PGturn_model = 1;
    } else if (pgtext == QString(tr("induction"))) {
        PGturn_model = 2;
    } else {
        set_Sys->setValue(QString("PGturn/text").toUtf8().data(), "hall");
        PGturn_model = 1;
    }
    system("sync");
    delete set_Sys;
    if (Ini_LR == 2) { // -判断是否工位信号反转
        ui->label_station->setText(tr("右"));
    } else {
        //
    }

    if (Ini_Motor == QString(tr("PG"))) { // -判断是否为PG板子
        Ini_Proj.append("16");
    } else {
        //
    }

    /******************功率显示窗口******************/
    PWR_Par_Widget = new QWidget(this);
    PWR_Par_Widget->setGeometry(120, 100, 535, 300);
    PWR_Par_Widget->setWindowFlags(Qt::WindowStaysOnTopHint);
    PWR_Par_Widget->setStyleSheet("border-radius: 10px;padding:2px 4px;background-color: gray;");
    PWR_Par_Widget->hide();
    QGridLayout *PWR_side = new QGridLayout;
    QString PWR_table[10] =
                  {QString(tr("电压(V)")), QString(tr("电流(A)")), QString(tr("功率(W)")), \
                  QString(tr("功率因数")), QString(tr("频率(Hz)")), QString(tr("时间(S)")), \
                  QString(tr("容压(V)")), QString(tr("容值(uF)")), QString(tr("转向")), \
                  QString(tr("转速(rpm)"))};
    QString PWR_Display[10]={" ", " ", " ", " ", " ", " ", " ", " ", " ", " "};
    for (i= 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            PWR_Lable.append(new QLabel(this));
            PWR_Lable[i*2+j]->setText(PWR_table[i*2+j]);
            PWR_Lable[i*2+j]->setMaximumWidth(150);
            PWR_Lable[i*2+j]->setAlignment(Qt::AlignRight);
            PWR_side->addWidget(PWR_Lable[i*2+j], i, j*2);

            PWR_Display_Lable.append(new QLabel(this));
            PWR_Display_Lable[i*2+j]->setText(PWR_Display[i*2+j]);
            PWR_Display_Lable[i*2+j]->setMaximumWidth(100);
            PWR_Display_Lable[i*2+j]->setAlignment(Qt::AlignLeft);
            PWR_side->addWidget(PWR_Display_Lable[i*2+j], i, j*2+1);
        }
    }
    QVBoxLayout *Up_Widget_layout = new QVBoxLayout;
    Up_Widget_layout->addLayout(PWR_side);
    PWR_Par_Widget->setLayout(Up_Widget_layout);

    /******************柱状图显示窗口******************/
    Histogram_Widget = new QWidget(this);
    Histogram_Widget->setGeometry(100, 100, 600, 400);
    Histogram_Widget->setWindowFlags(Qt::WindowStaysOnTopHint);
    Histogram_Widget->setStyleSheet("border-radius: 10px;padding:2px 4px;background-color: gray;");
    QGridLayout *upside = new QGridLayout;
    QLabel *Planpro_label = new QLabel;   Planpro_label->setText(tr("计划生产"));
    upside->addWidget(Planpro_label, 0, 0);
    Text_Edit = new QLineEdit(this);
    Text_Edit->setMaximumWidth(100);
    Text_Edit->setStyleSheet("border: 1px solid #000000;color: black;");
    connect(Text_Edit, SIGNAL(editingFinished()), this, SLOT(join_autoconfirm()));
    upside->addWidget(Text_Edit, 0, 1);

    QHBoxLayout * hbbox = new QHBoxLayout;  hbbox->addStretch();
    upside->addLayout(hbbox, 0, 2);
    button_dump = new QPushButton;
    button_dump->setText(tr("清除"));
    button_dump->setMinimumHeight(50);
    button_dump->setMinimumWidth(90);
    button_dump->setStyleSheet("background: qlineargradient"\
                               "(x1: 0, y1: 0, x2: 0, y2: 1,stop: "\
                               "0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);");
    upside->addWidget(button_dump, 0, 4);
    connect(button_dump, SIGNAL(clicked(bool)), this, SLOT(join_autodump(bool)));
    QPushButton *button_quit = new QPushButton;
    button_quit->setText(tr("退出"));
    button_quit->setMinimumHeight(50);
    button_quit->setMinimumWidth(90);
    button_quit->setStyleSheet("background: qlineargradient"\
                               "(x1: 0, y1: 0, x2: 0, y2: 1,stop: "\
                               "0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);");
    upside->addWidget(button_quit, 0, 5);
    connect(button_quit, SIGNAL(clicked()), this, SLOT(join_autoquit()));
    QHBoxLayout *middleside = new QHBoxLayout;
    QString color;   QString color_table[19]={"yellow", "blue", "green", \
                                              "red", "red", "red", \
                                              "red", "red", "red", \
                                              "red", "red", "red", \
                                              "red", \
                                              "red", "red", "red", "red", "red", \
                                              "red"};
    for (i = 0; i < Ini_Proj.size() + 2; i++) {  // +2    ==  -1+3
        color = QString("background-color: %1;").arg(color_table[i]);
        PushHist_List.append(new QLabel(this));
        PushHist_List[i]->setStyleSheet(color);
        PushHist_List[i]->setMinimumHeight(2);
        PushHist_List[i]->setMaximumHeight(250);   PushHist_List[i]->setFixedHeight(250);
        PushHist_List[i]->setMaximumWidth(52);
        PushHist_List[i]->setMinimumWidth(38);
        middleside->addWidget(PushHist_List[i], 10, Qt::AlignLeft | Qt::AlignBottom);
    }
    QString TestItem_table[19]={tr("计划"), tr("总数"), tr("合格"), \
                                tr("电阻"), tr("反嵌"), tr("绝缘"), \
                                tr("交耐"), tr("直耐"), tr("匝间"), \
                                tr("电参"), tr("电感"), tr("堵转"), \
                                tr("低启"), \
                                tr("HALL"), tr("负载"), tr("空载"), tr("BEMF"), tr(" "), \
                                tr("PG")};
    QGridLayout *bottomside = new QGridLayout;
    for (i = 0; i < Ini_Proj.size() + 2; i++) { // +2   ==   -1+3
        PushHist_Text.append(new QLabel(this));
        if (i >= 3) {
            PushHist_Text[i]->setText(TestItem_table[Ini_Proj.at(i-2).toInt()+2]);
            PushHist_Text[i]->setStyleSheet("color: red;font: 10pt Ubuntu;");
        } else {
            PushHist_Text[i]->setText(TestItem_table[i]);
            PushHist_Text[i]->setStyleSheet("font: 10pt Ubuntu;");
        }
        PushHist_Text[i]->setMaximumHeight(25);
        PushHist_Text[i]->setMaximumWidth(56);
        PushHist_Text[i]->setMinimumWidth(56);
        PushHist_Text[i]->setAlignment(Qt::AlignCenter);
        bottomside->addWidget(PushHist_Text[i], 0, i);
    }
    QGridLayout *bottomside_bottom = new QGridLayout;
    for (i = 0; i < Ini_Proj.size()+2; i++) { // +2   ==   -1 + 3
        PushHist_Count_Text.append(new QLabel(this));
        PushHist_Count_Text[i]->setText("0");
        if (i >= 3) {
            PushHist_Count_Text[i]->setStyleSheet("color: red;");
        }
        PushHist_Count_Text[i]->setMaximumHeight(20);
        PushHist_Count_Text[i]->setMaximumWidth(56);
        PushHist_Count_Text[i]->setMinimumWidth(56);
        PushHist_Count_Text[i]->setAlignment(Qt::AlignCenter);
        bottomside_bottom->addWidget(PushHist_Count_Text[i], 0, i);
    }
    QVBoxLayout *Histogram_Widget_layout = new QVBoxLayout;
    Histogram_Widget_layout->addLayout(upside);
    Histogram_Widget_layout->addLayout(middleside);
    Histogram_Widget_layout->addLayout(bottomside);
    Histogram_Widget_layout->addLayout(bottomside_bottom);
    Histogram_Widget->setLayout(Histogram_Widget_layout);
    Histogram_Widget->hide();

    /******************询问和提示显示窗口******************/
    Ask_Widget = new QWidget(this);
    Ask_Widget->setGeometry(670, 188, 122, 235);
    Ask_Widget->setWindowFlags(Qt::WindowStaysOnTopHint);
    Ask_Widget->setStyleSheet("border-radius: 10px;padding:2px 4px;background-color: gray;");
    QGridLayout *Ask_Up = new QGridLayout;
    Ask_Up_label = new QLabel(this);
    Ask_Up_label->setText(tr(" 按Test继续测试 \n 按Reset中止测试 "));
    Ask_Up_label->setAlignment(Qt::AlignCenter);
    Ask_Up->addWidget(Ask_Up_label, 0, 0);
    QGridLayout *Ask_bottom = new QGridLayout;
    if (Ini_DCR_Ask == 1) { // 重测,继续
        QPushButton *button_Current = new QPushButton;
        button_Current->setText(tr("重测"));
        button_Current->setMinimumHeight(50);
        button_Current->setMinimumWidth(90);
        button_Current->setStyleSheet("background: qlineargradient" \
                                      "(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #5B5F5F,"\
                                      "stop: 0.5 #0C2436,stop: 1 #27405A);");
        Ask_bottom->addWidget(button_Current, 0, 0);
        connect(button_Current, SIGNAL(clicked()), this, SLOT(Pri_Ask_Test_Current()));
        QPushButton *button_Continue = new QPushButton;
        button_Continue->setText(tr("继续"));
        button_Continue->setMinimumHeight(50);
        button_Continue->setMinimumWidth(90);
        button_Continue->setStyleSheet("background: qlineargradient" \
                                       "(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #5B5F5F," \
                                       "stop: 0.5 #0C2436,stop: 1 #27405A);");
        Ask_bottom->addWidget(button_Continue, 1, 0);
        connect(button_Continue, SIGNAL(clicked()), this, SLOT(Pri_Ask_Test_Continue()));
    } else if (Ini_DCR_Ask == 2) { // 取消
        QVBoxLayout * hb = new QVBoxLayout;
        hb->addStretch();
        Ask_bottom->addLayout(hb, 0, 0);
        QPushButton *button_Current = new QPushButton;
        button_Current->setText(tr("取消"));
        button_Current->setMinimumHeight(50);
        button_Current->setMinimumWidth(110);
        button_Current->setStyleSheet("background: qlineargradient" \
                                      "(x1: 0, y1: 0, x2: 0, y2: 1,stop:" \
                                      "0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);");
        Ask_bottom->addWidget(button_Current, 1, 0);
        connect(button_Current, SIGNAL(clicked()), this, SLOT(Pri_Ask_Test_Continue()));
    } else if (Ini_DCR_Ask == 3) { // 取消
        QVBoxLayout * hb = new QVBoxLayout;
        hb->addStretch();
        Ask_bottom->addLayout(hb, 0, 0);
        QPushButton *button_Current = new QPushButton;
        button_Current->setText(tr("重测"));
        button_Current->setMinimumHeight(50);
        button_Current->setMinimumWidth(90);
        button_Current->setStyleSheet("background: qlineargradient" \
                                      "(x1: 0, y1: 0, x2: 0, y2: 1,stop:" \
                                      "0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);");
        Ask_bottom->addWidget(button_Current, 0, 0);
        connect(button_Current, SIGNAL(clicked()), this, SLOT(Pri_Ask_Test_Current()));

        QPushButton *button_Stop = new QPushButton;
        button_Stop->setText(tr("终止"));
        button_Stop->setMinimumHeight(50);
        button_Stop->setMinimumWidth(90);
        button_Stop->setStyleSheet("background: qlineargradient" \
                                   "(x1: 0, y1: 0, x2: 0, y2: 1,stop:" \
                                   "0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);");
        Ask_bottom->addWidget(button_Stop, 1, 0);
        connect(button_Stop, SIGNAL(clicked()), this, SLOT(Pri_Ask_Test_Stop()));

        QPushButton *button_Cancel = new QPushButton;
        button_Cancel->setText(tr("取消"));
        button_Cancel->setMinimumHeight(50);
        button_Cancel->setMinimumWidth(90);
        button_Cancel->setStyleSheet("background: qlineargradient" \
                                     "(x1: 0, y1: 0, x2: 0, y2: 1,stop:" \
                                     "0 #ff0000, stop: 0.5 #ff0000,stop: 1 #ff0000);");
        Ask_bottom->addWidget(button_Cancel, 2, 0);
        connect(button_Cancel, SIGNAL(clicked()), this, SLOT(Pri_Ask_Test_Cancel()));
    } else if(Ini_DCR_Ask==4) { // 继续 停止
        QPushButton *button_Continue = new QPushButton;
        button_Continue->setText(tr("继续"));
        button_Continue->setMinimumHeight(50);
        button_Continue->setMinimumWidth(90);
        button_Continue->setStyleSheet("background: qlineargradient"\
                                       "(x1: 0, y1: 0, x2: 0, y2: 1,stop: "\
                                       "0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);");
        Ask_bottom->addWidget(button_Continue,1,0);
        connect(button_Continue,SIGNAL(clicked()),this,SLOT(Pri_Ask_Test_Continue()));

        QPushButton *button_Stop = new QPushButton;
        button_Stop->setText(tr("停止"));
        button_Stop->setMinimumHeight(50);
        button_Stop->setMinimumWidth(90);
        button_Stop->setStyleSheet("background: qlineargradient"\
                                   "(x1: 0, y1: 0, x2: 0, y2: 1,stop: "\
                                   "0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);");
        Ask_bottom->addWidget(button_Stop,0,0);
        connect(button_Stop,SIGNAL(clicked()),this,SLOT(Pri_Ask_Test_Stop()));

    } else {
        //
    }
    QVBoxLayout *Ask_Widget_layout = new QVBoxLayout;
    Ask_Widget_layout->addLayout(Ask_Up);
    Ask_Widget_layout->addLayout(Ask_bottom);
    Ask_Widget->setLayout(Ask_Widget_layout);
    Ask_Widget->hide();


    for (i = 0; i < 19; i++) { // 柱状图的测试数据进行清空
        Error_Item[i] = 0;
        Error_Item_Count[i] = 0;
    }

    /******************窗口显示STOP******************/

    lable_stop = new QLabel(this);
    lable_stop->setGeometry(670, 300, 122, 125);
    lable_stop->setWindowOpacity(0.7);
    lable_stop->setWindowFlags(Qt::WindowStaysOnTopHint); // border:1px groove white;
    lable_stop->setStyleSheet("font: Bold 30pt Ubuntu;" \
                              "border:1px groove #447684;border-radius: 10px;"\
                              "padding:2px 4px; background-color: #191919;color: red;");
    lable_stop->setText("STOP");
    lable_stop->setAlignment(Qt::AlignCenter);

    lable_stop->hide();

    lable_GND_Volt = new QLabel(this);
    lable_GND_Volt->setGeometry(5,575,651,25);
    lable_GND_Volt->setWindowOpacity(0.7);
    lable_GND_Volt->setWindowFlags(Qt::WindowStaysOnTopHint);// border:1px groove white;
    lable_GND_Volt->setStyleSheet("font-size:15pt; color:#0055ff; "\
                                  "background-color: #191919;color: red;");
    lable_GND_Volt->setAlignment(Qt::AlignCenter);
    lable_GND_Volt->hide();

    turn.clear();
    turn.append(QString(tr("不转")));
    turn.append(QString(tr("反转")));
    turn.append(QString(tr("正转")));

    Non_barcode_scanner = false; // 默认条形码扫描
    JUMP_Chose = 0;
    scan_scart = 0, scart_stop = 0;
    Block_cycle = 0;
    Station_Chose = 0x13;

    PWR_Display_Lable.at(0)->setText("0");
    PWR_Display_Lable.at(1)->setText("0");
    PWR_Display_Lable.at(2)->setText("0");
    PWR_Display_Lable.at(3)->setText("0");
    PWR_Display_Lable.at(4)->setText("0");
    PWR_Display_Lable.at(5)->setText("0");
    PWR_Display_Lable.at(6)->setText("0");
    PWR_Display_Lable.at(7)->setText("0");
    PWR_Display_Lable.at(8)->setText("0");
    PWR_Display_Lable.at(9)->setText("0");

    BLOCK_list.clear();
    BLOCK_list.append("0");
    BLOCK_list.append("0");

    PWR_Test_Count = 0; PG_Result_List.clear();
    ACW_Test_Count = 0;
    IR_Test_Count = 0;
    FG_Test_Count = 0;
    FG_Shape_Count = 0;


    strJudge.clear();
    Result_INDL = 0;
    Result_Main = 0;  Result_Q = 0;
    START_Model = 0;
    Connect_Test = false;

    COLOR_Id.clear();
    for (i = 0; i < 8; i++) {
        COLOR_Id.append(" ");
    }

    PWR_Test_Data.clear();
    PWR_Test_Data.append("1");
    PWR_Test_Data.append("1");

    FG_Test_Data.clear();
    FG_Test_Data.append("1");
    FG_Test_Data.append("1");

    PG_list.clear();
    False_Test  = false;
    DCR_Connect = false;
    Back_board_ID = {0, 0, 0, 0x23, 0x23, 0x23, 0, 0x27, 0, 0x27, 0x27, 0, 0, 0x2c, 0x2c, 0, 0};

    dcr_board = new QTimer(this);
    connect(dcr_board, SIGNAL(timeout()), this, SLOT(test_join_dcr_stop()));

    IO_Pumb_Start = new QTimer(this);
    connect(IO_Pumb_Start,SIGNAL(timeout()),this,SLOT(IO_Pumb_Start_timeout()));

    IO_Delay_Start = new QTimer(this);
    connect(IO_Delay_Start,SIGNAL(timeout()),this,SLOT(IO_Delay_Start_timeout()));

    In_Temp       = 0; // -机箱内温度
    Test_GND_Volt = 0; // -测试接地电压

    IR_Error.clear();
    IR_Error.append("1");        // -1
    IR_Error.append("2");        // -2
    IR_Error.append("3");        // -3
    IR_Error.append("4");        // -4
    IR_Error.append("LEAK");     // -5
    IR_Error.append("OVER-POWER"); // -6
    IR_Error.append("DCPT");     // -7
    IR_Error.append("<0M");    // -8

    ACW_Error.clear();
    ACW_Error.append("1");        // -1
    ACW_Error.append("2");        // -2
    ACW_Error.append("3");        // -3
    ACW_Error.append("4");        // -4
    ACW_Error.append("LEAK");     // -5
    ACW_Error.append("OVER-POWER"); // -6
    ACW_Error.append("DCPT");     // -7
    ACW_Error.append(">20mA");    // -8

    Cancel_No_Save     = false;
    waveform_all_count = 0;
    waveform_row_count = 0;

    IMP_Right_List.append(new wt_Wave);
    IMP_Left_List.append(new wt_Wave);

    Main_ActiveFile = "";

    Dir = 0;
    Pf_A = 0;
    time = 0;
    Speed = 0;
    Freq_A = 0;
    Hall_Speed = 0;
    Volt_A = 0; Current_A = 0; Pwr_A = 0;
    Volt_B = 0; Current_B = 0; Pwr_B = 0;
    Volt_C = 0; Current_C = 0; Pwr_C = 0;

    pg_up = 0;
    pg_Cur = 0;
    pg_floor = 0;
    pg_freq_min = 0; pg_freq_avr = 0; pg_freq_max = 0;
    pg_duty_min = 0; pg_duty_avr = 0; pg_duty_max = 0;

    Turn_Elec_force = 0; // -反电动势为0
    Exist_PWR = false;   // -判断是否存在功率，在启动电阻时进行反电动势的检测


    for (i = 0; i < 370; i++) {
       Hall_Update.append("0");
    }
    for (i = 0; i < 31; i++) {
       NoLoad_Update.append("0");
    }

    Test_Model_Vacuum = false;
    Test_IMP_Ready = false;
    Vacuum_Ready = false;

    Test_Model_Vacuum_ACW = false;
    Test_ACW_Ready = false;

    Vacuum_pump_Close = false;
    System_Free_Time = 0;

    Test_MAG_Ready = false;
    MAG_Drive = false;
    NetTest_Ready_DLR = false;     DLR_Issue_Ing = false;
    NetTest_Ready_MAG = false;     MAG_Issue_Ing = false;
    NetTest_Ready_IR  = false;     IR_Issue_Ing = false;
    NetTest_Ready_ACW = false;     ACW_Issue_Ing = false;
    NetTest_Ready_IMP = false;     IMP_Issue_Ing = false;
    NetTest_Ready_IND = false;     IND_Issue_Ing = false;

    NetTest_Resdy_HALL = false;    HALL_Issue_Ing = false;
    NetTest_Resdy_LOAD = false;    LOAD_Issue_Ing = false;
    NetTest_Resdy_NOLOAD = false;  NOLOAD_Issue_Ing = false;
    NetTest_Resdy_BEMF = false;    BEMF_Issue_Ing = false;

    Start_No = false;
    Last_Station = 1;

    PLC_Singal_Widget = new QWidget(this); // 电机到位图标
    PLC_Singal_Widget->setGeometry(5,575,200,25);
    PLC_Singal_Widget->setWindowFlags(Qt::WindowStaysOnTopHint);
    QGridLayout *PLC_upside = new QGridLayout;
    PLC_upside->setContentsMargins(0,0,0,0);
    QLabel *Motor_label = new QLabel;
    Motor_label->setPixmap(QPixmap(":/image/stepper_motor.png"));
    PLC_upside->addWidget(Motor_label,0,0);
    PLC_Singal_Widget->setLayout(PLC_upside);
    PLC_Singal_Widget->hide();

    Key_E_Count = 0;
    IO_Input_Data = new QLabel(this);
    IO_Input_Data->setGeometry(510,575,160,25);
    IO_Input_Data->setWindowFlags(Qt::WindowStaysOnTopHint);
    IO_Input_Data->setStyleSheet("background-color:#191919;font-size:12pt; color:#0055ff;");
    IO_Input_Data->setText("");
    IO_Input_Data->setAlignment(Qt::AlignCenter);
    IO_Input_Data->hide();

    Kai_Yu_Curtain  = false;
    Kai_yu_In_Place = false;
    Kai_Yu_Oid_Count = 0;
    Kai_Yu_New_Count = 0;
    Kai_Yu_Clumped = false;
    Kai_Yu_Pushed  = false;

    Kongshi_Stall = false;
    Kongshi_Continue_Test = false;
    Kongshi_Stall_Time = 0;

    No_load_Param.clear();
    No_load_Param << "50" << "53" << "51" << "52";
    FG_Param_A << "51" << "50" << "52" << "53";
    Hall_Count << "A" << "B" << "C" << "D" << "E";
    FG_direction << "不转" << "顺时针" << "逆时针";

    PG_Test_State = 0x00;
    mag_zero.clear();
    for (i = 0; i < 8; i++)
    {
        mag_zero.append("0");
    }

    BenDuo_L = false;
    BenDuo_R = false;

    Test_Message.clear();
    Test_Message.append(QString(tr("          当前用户模式为操作员     \n      无权限进行保存和修改       "))); // 0
    Test_Message.append(QString(tr("温度传感器有问题,请关掉温度补偿"))); // 1
    Test_Message.append(QString(tr("   线圈电阻过小，停止测试   "))); // 2
    Test_Message.append(QString(tr("  气缸动作超时  "))); // 3
    Test_Message.append(QString(tr("    系统接地不良--%1     \n 请先检查地线再进行测试 ")));  // 4
    Test_Message.append(QString(tr("  当前启动方式错误  "))); // 5
    Test_Message.append(QString(tr("  测试失败，反电动势过高--%1 V  "))); // 6
    Test_Message.append(QString(tr("  功率板未能测试到反电动势，中止测试  "))); // 7
    Test_Message.append(QString(tr("光幕被遮挡"))); // 8
    Test_Message.append(QString(tr("样品未到位"))); // 9
    Test_Message.append(QString(tr("禁止重復测试"))); // 10
    Test_Message.append(QString(tr("测试背板状态异常"))); // 11

    Test_noise_enabled = false;
    Noise_CW_Time = 0.0;
    Noise_CCW_Time = 0.0;
    Noise_Delay_Time = 0.0;
    ui->label_noise->hide();
    Noise_step = 0;
    Noise_Stop = new QTimer(this);
    connect(Noise_Stop,SIGNAL(timeout()),this,SLOT(Noise_Stop_timeout()));

    ui->button_down->setEnabled(true);
    ui->button_up->setDisabled(true);

    AMP_Conneted = true;
}

w_Test::~w_Test()
{
    delete ui;
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:
  * brief:      柱状图大窗口隐藏
******************************************************************************/
void w_Test::join_autoquit()
{
    this->grabKeyboard();
    Non_barcode_scanner = false;
    label_Waring->hide();
    Histogram_Widget->hide();
    Test.Status_Ing = Test_Station_Free;
    Ask_Widget->hide();
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:
  * brief:      清除现有的数据
******************************************************************************/
void w_Test::join_autodump(bool clicked)
{
    int i = 0;
    if (clicked) {
        button_dump->setChecked(false);
        if(test_parameters[2]->text()==tr("操作者:操作员")) {
            Test_WMessage(0, QString(""));
            return;
        }
        else {

        }
    }
    else {

    }

    Qualified = 0; Unqualified = 0; Test_Count = 0;
    for (i = 0; i < 19; i++) {
        Error_Item[i] = 0;
    }
    Histogram_List.at(0)->setText(QString::number(Test_Count));
    Histogram_List.at(1)->setText(QString::number(Qualified));
    Histogram_List.at(1)->setGeometry(717, 190, 31, 100);
    Histogram_List.at(2)->setText(QString::number(Unqualified));
    Histogram_List.at(2)->setGeometry(759, 190, 31, 100);

    PushHist_Count_Text[1]->setText(QString::number(Test_Count));
    PushHist_Count_Text[2]->setText(QString::number(Qualified));
    for (i = 3; i < Ini_Proj.size() + 2; i++) {  // +2  =-1+3
        PushHist_Count_Text[i]->setText(QString::number(Error_Item[Ini_Proj.at(i-2).toInt()]));
    }
    PushHist_List[2]->setFixedHeight(250);
    for (i = 3; i < Ini_Proj.size() + 2; i++) {
        PushHist_List[i]->setFixedHeight(0);
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:
  * brief:      确认计划生产
******************************************************************************/
void w_Test::join_autoconfirm()
{
    if (Text_Edit->text() != "") {
        PushHist_Count_Text[0]->setText(Text_Edit->text());
    } else {
        PushHist_Count_Text[0]->setText("0");
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.7.19
  * brief:      处理鼠标被按下事件
******************************************************************************/
void w_Test::mousePressEvent(QMouseEvent *event) //-
{
    event->x();
    if (Test.Status_Ing == Test_Station_Free) {
        Mouse.Ms = 0;    Mouse.Us = 0;
        Mouse.Time->start(1);
        Mouse.Flag = true;
        handleMousePressEvent(event);
    } else if (Test.Status_Ing == Test_Station_Busy) { // -添加触摸屏幕停止
        Can_Stop(0x23);
        Can_Stop(0x22);
        Can_Stop(0x24);
        Can_Stop(0x27);  Can_Stop(0x29);
        Sigtest_Usart_Send(QString("LEDR").toLatin1().data());
        Test_Judge_State("NG");
    } else {
        //
    }
    join_autoquit();
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.7.19
  * brief:      处理鼠标离开事件
******************************************************************************/
void w_Test::mouseReleaseEvent(QMouseEvent *event) //
{
    event->x();
    if (Mouse.Flag) {
        Mouse.Time->stop();
        if ((Mouse.Ms >= 2) && (Test.Status_Ing == Test_Station_Free)) {
            IO_Test_Readying = false;
            Signal_Test_to_Main(wHelp_Surface, 1);
        } else {
            //
        }
    } else {
        //
    }
    Mouse.Flag = false;
    Mouse.Ms = 0;    Mouse.Us = 0;
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.7.19
  * brief:      长按计时
******************************************************************************/
void w_Test::join_test_mouse_check()
{
    Mouse.Us++;
    if (Mouse.Us >= 1000) {
        Mouse.Us = 0;
        Mouse.Ms++;
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.7.19
  * brief:      处理鼠标被按下事件
******************************************************************************/
bool w_Test::handleMousePressEvent(QMouseEvent *event)
{
    int k = 0;
    QPoint topLeft(0, 420);  // left top
    QPoint rightBottom(605, 550);
    QRect  rect(topLeft, rightBottom);
    if ((rect.contains(event->pos())) && (Test.Status_Ing == Test_Station_Free)) {
        Test.Status_Ing = Test_Station_Inte;
        int number = (event->pos().x()/200);
        if (number <= 2) {
            Test_TShape->show();
            Test_TShape->raise();
            Test_TShape->Test_string = wave_name[number]->text();
            for (k =0 ; k < 400; k++) {
                Test_TShape->point[k] = wave[number]->point[k];
                Test_TShape->pointgreen[k] = wave[number]->pointgreen[k];
            }
            Test_TShape->num = 400;
            Test_TShape->update();
        }
    } else {
        //
    }
    return true;
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.5.1
  * brief:      测试状态设为 Free
******************************************************************************/
void w_Test::join_shape_set_free()
{
    Test.Status_Ing = Test_Station_Free;
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.5.1
  * brief:      蜂鸣器停止
******************************************************************************/
void w_Test::join_beep_stop()
{
    Beep_PWM_Stop();
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.11
  * brief:      更新测试界面信息数据
******************************************************************************/
void w_Test::InitTest_Interface(QStringList Data_List)
{
    qDebug() << "InitTest_Interface";
    int i = 0;
    QString str;
    QString Plan_Number;
    Main_ActiveFile = Data_List.at(0);
    Model_Occur_Unqualified = Data_List.at(1).toInt();
    Test.serial_number = Data_List.at(2);
    Plan_Number   = Data_List.at(3);
    Exist_PWR     = Data_List.at(4).toInt();
    strTest       = Data_List.mid(7, Data_List.at(5).toInt());
    // -测试项目
    strParam      = Data_List.mid(7 + Data_List.at(5).toInt(), Data_List.at(6).toInt());
    // -测试参数

    ui->testTab->setRowCount(0);

    if (strTest.size() <= 12) {
        ui->testTab->setRowCount(12);
    } else {
        ui->testTab->setRowCount(strTest.size());
    }

    for (i = 0; i < strTest.size(); i++) { // -测试序号
        QTableWidgetItem *pItem = new QTableWidgetItem(QString::number(i+1));
        pItem->setTextAlignment(Qt::AlignCenter);
        ui->testTab->setItem(i, 0, pItem);
    }
    for (i = 0; i < strTest.size(); i++) { // -测试项目
        QTableWidgetItem *pItem = new QTableWidgetItem(strTest.at(i));
        pItem->setTextAlignment(Qt::AlignCenter);
        ui->testTab->setItem(i, 1, pItem);
    }
    for (i = 0; i < strParam.size(); i++) { // -测试参数
        QTableWidgetItem *pItem = new QTableWidgetItem(strParam.at(i));
        pItem->setTextAlignment(Qt::AlignCenter);
        ui->testTab->setItem(i, 2, pItem);
    }
    for (i = 0; i < strTest.size(); i++) { // -测试结果
        QTableWidgetItem *pItem = new QTableWidgetItem("");
        pItem->setTextAlignment(Qt::AlignCenter);
        ui->testTab->setItem(i, 3, pItem);
    }
    for (i = 0; i < strTest.size(); i++) { // -测试判定
        QTableWidgetItem *pItem = new QTableWidgetItem("");
        pItem->setTextAlignment(Qt::AlignCenter);
        ui->testTab->setItem(i, 4, pItem);
    }
    for (i = 0; i < show_color.size(); i++) { // -初始化线夹颜色
        if (COLOR_Id.at(i) == "#000000") {
            str = QString("border:0px groove gray;color: #191919;"\
                        "border-radius:10px;padding:2px 4px;"\
                        "background-color:%1;color:white").arg(COLOR_Id.at(i));
            show_color[i]->setStyleSheet(str);
        } else {
            str = QString("border:0px groove gray;color: #191919;"\
                        "border-radius:10px;padding:2px 4px;"\
                        "background-color:%1").arg(COLOR_Id.at(i));
            show_color[i]->setStyleSheet(str);
        }
    }

    if ((ui->testTab->rowCount()) > 12) { // -设置显示在开始第一行位置
        ui->testTab->verticalScrollBar()->setValue(0);
    }
    for (i = 0; i < 50; i++) { // -清除存储保存的波形
        WavePoint_strList[i].clear();
    }

    TaskMagDirstrList[0].clear();
    TaskMagDirstrList[1].clear();
    TaskMagDirstrList[2].clear();

    for (i = 0; i < 3; i++) { // -清除三个显示区
        wave[i]->num = 0;  wave[i]->Test_Shape = 0; wave[i]->update();
        wave_name[i]->setText(tr("测试项")); // -清空测试项
    }

    if (Test.serial_number  ==  "") {
        ui->label_number->setText(tr("编号:") + QString::number(Test_Count));
    } else {
        ui->label_number->setText(tr("编号:") + Test.serial_number);
    }

    if (test_parameters[0]->text() != (QString(tr("型号：")) + Main_ActiveFile)) {
        // -清空柱状图
        join_autodump(false);
        test_parameters[0]->setText(QString(tr("型号：")) + Main_ActiveFile);
    }

    PG_Row.clear();
    for (i = 0; i < strTest.size(); i++) { // -测试参数,是否包含PG,2017.5.20
        if (strTest.at(i).contains(QString(tr("PG")))) {
            PG_Row.append(QString::number(i));
        } else {
            //
        }
    }

    for (i = 0; i < strTest.size(); i++) { // -测试参数,是否包含PG,2017.5.20
        if (strTest.at(i).contains(QString(tr("空载")))) {
            ui->testTab->setRowHeight(i,50);
        } else if (strTest.at(i).contains(QString(tr("HALL")))) {
            ui->testTab->setRowHeight(i,50);
        } else {
            //
        }
    }


    Text_Edit->setText(Plan_Number); join_autoconfirm();
    Test.Finshed_Count = 0;
    if (strLVS.size() != 0) {
        Ini_LVS_Judge = strLVS.at(5).toInt();
    } else {
        //
    }
    if (Conf_Item.contains("7")) {
        if (strPWR.size() != 0) {
            Noise_CW_Time = strPWR.at(31).toDouble();    // noise CW
            Noise_CCW_Time = strPWR.at(23).toDouble();   // noise CCW
            Noise_Delay_Time = strPWR.at(22).toDouble(); // noise Delay
            if (strPWR.at(32).toInt()  == 2) { // noise--
               Test_noise_enabled = true;
            } else {
                Test_noise_enabled = false;
            }
        } else {
            //
        }
    } else {
        Test_noise_enabled = false;
    }
    ui->label_6->text().clear();
    qDebug() << "InitTest_Interface  Finsh";
}

void w_Test::Noise_Stop_timeout() {
    if (Noise_step == 0) {
        if (strPWR.at(24).toInt()  == 2) { // 反向测试
            Signal_test_to_Switchover(Noise,Station_Chose - 0x13 + 1,7); // 切换进入反向测试
            Noise_step = 1;
            Noise_Stop->setSingleShot(TRUE);
            Noise_Stop->start(Noise_Delay_Time*1000); //
            ui->label_noise->hide();
        } else {
           Signal_test_to_Switchover(Noise,0x00,7); // 关闭所有通路
           ui->label_noise->hide();
        }
    } else if (Noise_step == 1) {
        ui->label_noise->show();
        Signal_test_to_Switchover(Noise,Station_Chose - 0x13 + 1 + 16,7); // 切换进入反向测试
        Noise_step = 2;
        Noise_Stop->setSingleShot(TRUE);
        Noise_Stop->start(Noise_CCW_Time*1000); //
        ui->label_noise->show();
    } else if (Noise_step == 2) {
        Signal_test_to_Switchover(Noise,0x00,7); // 关闭所有通路
        ui->label_noise->hide();
    } else {
        //
    }
}

void w_Test::Pubs_from_pic(QString string, int value, int flag)
{
    switch (flag) {
    case 1:
        if (Ini_IO_Model==BenDuo) {
            if (Ini_IO_Test) {
                //
            } else {
                return;
            }
            if (IO_Test_Readying) { // 启动
                IO_Test_Readying = false;
                Test_Process(); // 清空后，开始测试
            } else {
                //
            }
        } else if (Ini_IO_Model == KaiYu) { // 凯宇下压复位
            if (Ini_IO_Test) {
                Kai_Yu_Pushed = false;
            } else {
                return;
            }
        } else if (Ini_IO_Model == BenDuoTWO) {
            if(value) { // 本多样品到位
                BenDuo_L = true;
                PLC_Singal_Widget->show();
            }
            else { // 本多样品
                BenDuo_L = false;
                PLC_Singal_Widget->hide();
            }
        } else {
            //
        }
        break;
    case 2:
        if (Ini_IO_Model == BenDuo) {
            IO_Test_Readying = false; // 停止
            join_test_stop(1);
        } else if (Ini_IO_Model == KaiYu) { // 凯宇下压到位
            Kai_Yu_Pushed = true;
            Kai_Yu_Ready_Test();
        } else if (Ini_IO_Model == Bosch) { // 启动
            if (Ini_IO_Test) {
                //
            } else {
                return;
            }
            if (IO_Test_Readying) {
                IO_Test_Readying = false;
                Test_Process(); // 清空后，开始测试
            } else {
                return;
            }
        } else if (Ini_IO_Model == BenDuoTWO) {
            if(value) { // 本多样品到位
                BenDuo_R = true;
                PLC_Singal_Widget->show();
            }
            else { // 本多样品
                BenDuo_R = false;
                PLC_Singal_Widget->hide();
            }
        } else {
            //
        }
        break;
    case 3:
        if (Ini_IO_Model == KaiYu) { // 凯宇夹住复位
            Kai_Yu_Clumped = false;
        } else {
            //
        }
        break;
    case 4:
        if (Ini_IO_Model == KaiYu) { // 凯宇夹住到位
            Kai_Yu_Clumped = true;
            Kai_Yu_Ready_Test();
        } else {
            //
        }
        break;
    case 5:
        if (Ini_IO_Model == KaiYu) { // 凯宇解锁
            if(Test.Status_Ing == Test_Station_Free) {
                Signal_test_to_Switchover(KaiYu, 0x00, 6);
            } else {
                //
            }
        } else {
            //
        }
        break;
    case 6:
        if (Ini_IO_Model == KaiYu) {
            if (value) { // 凯宇样品
                Kai_yu_In_Place = false;
                PLC_Singal_Widget->hide();
            } else { // 凯宇样品到位
                Kai_yu_In_Place = true;
                PLC_Singal_Widget->show();
            }
        } else {
            //
        }
        break;
    case 7:
        if (Ini_IO_Model == KaiYu) {
            if (value) { // 凯宇光幕
                Kai_Yu_Curtain = true;
                IO_Test_Readying = false;
                join_test_stop(1);
            } else { // 凯宇
                Kai_Yu_Curtain = false;
                Kai_Yu_New_Count++;
            }
        } else if (Ini_IO_Model == Bosch) { // 启动
            if (value) {
                frame.can_id  = 0x2D;  frame.can_dlc = 0x04;
                frame.data[0] = 0xf1;
                frame.data[1] = 0x00;
                frame.data[2] = 0x00;
                frame.data[3] = 0x00;
                canSend(frame, 88);
            }
        } else {
            //
        }
        break;
    case 8:
        if (Kongshi_Stall) {
            Kongshi_Continue_Test = true;
            Test_Start();
        } else {
            //
        }
        break;
    case 101:
        Vacuum_Ready = true;
        qDebug() << "Test_IMP_Ready" << Test_IMP_Ready;
        qDebug() << "Test_ACW_Ready" << Test_ACW_Ready;
        if (Test_IMP_Ready) {
            Test_IMP_Ready = false;
            NetTest_Ready_IMP = true;
            Can_Start_IMP();
        } else if (Test_ACW_Ready) {
            Test_ACW_Ready = false;
            NetTest_Ready_ACW = true;
            Can_Start_ACW();
        } else {
            //
        }
        break;
    case 102:
        MAG_Drive = true;
        qDebug() << "Test_MAG_Ready" << Test_MAG_Ready;
        if (Test_MAG_Ready) {
            Test_MAG_Ready = false;
            NetTest_Ready_MAG = true;
            Can_Start_MAG();
        }
        break;
    default:

        break;
    }
    string.clear();
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.11
  * brief:      显示时间，显示外部传感器报警，机箱温度报警，PG数据进行轮流显示
******************************************************************************/
void w_Test::join_updateTime()
{
    if (Test.Status_Ing == Test_Station_Free) {
        System_Free_Time++;
        if (System_Free_Time >= 200) { // 10min 200 1min 20
            System_Free_Time = 0;
            Vacuum_pump_Close = true;
            if ((Test_Model_Vacuum) || (Test_Model_Vacuum_ACW)) {
                qDebug() << "Close Pumb";
                Signal_test_to_pic(QStringList(""), 0, 12); // 关闭真空泵 真空增加
                WriteMessage(6000, 0x99, test_parameters[3]->text().toUtf8());
            } else {
                //
            }
        } else {
            //
        }
    } else {
        System_Free_Time = 0;
    }


    if (Test.Status_Ing == Test_Station_Free) {
        char str_t1[30], str_t2[30];
        rtc_time    t;
        t = rtc.get_rtc();
        QString string_t1 = "<font color=#0055ff size=4 >:str</font></font>";
        sprintf(str_t1, "%02d:%02d", t.tm_hour, t.tm_min);
        string_t1.replace(":str", str_t1);
        ui->S1Label->setText(string_t1);

        QString string_t2 = "<font color=#0055ff size=4>:str</font>";
        sprintf(str_t2, "%02d/%02d/%02d", t.tm_year, t.tm_mon, t.tm_mday);
        string_t2.replace(":str", str_t2);
        ui->S1Label_2->setText(string_t2);

        frame.can_id = 0x22;  frame.can_dlc = 0x01; frame.data[0] = 0x00;
        canSend(frame, wTest_Surface);     // -电阻板发送
        usleep(1000);
        if (Ini_NineBoard  ==  2) {
            frame.can_id = 0x2A;  frame.can_dlc = 0x01; frame.data[0] = 0x00;
            canSend(frame, wTest_Surface); // -功放板发送
            usleep(1000);

            frame.can_id = 0x2A;  frame.can_dlc = 0x01; //-输出板发送
            frame.data[0] = 0x03;
            canSend(frame, 88);
        } else {
            //
        }
    } else {
        //
    }

    if (Temp_Error) { // -外部温度传感器进行报警
        count++;
        if (count%2 == 0) {
            ui->label_temp->show();
        } else {
            ui->label_temp->hide();
        }
    } else {
        ui->label_temp->show();
    }

    if (Temp_In) { //-温度过高
        if (count%2 == 0) {
            ui->label_5->setStyleSheet("background-color:red");
            ui->label_5->setText(QString(tr("机箱内部温度过高-%1，建议停止使用")).arg(In_Temp));
            ui->label_5->show();
        } else {
            ui->label_5->setStyleSheet("background-color:red");
            ui->label_5->setText(QString(tr("机箱内部温度过高-%1，建议停止使用")).arg(In_Temp));
            ui->label_5->hide();
        }
    } else {
        ui->label_5->setStyleSheet("background-color:#191919;font-size:15pt; color:#0055ff;");
        ui->label_5->setText(QString(tr("青岛艾普智能仪器有限公司--电机综合测试仪")));
        ui->label_5->show();
    }

    if (PG_Row.size() == 0) { // -不包含PG，若存在则进行PG的轮流显示
        return;
    }

    int Current_Row = 0;

    if ((PG_Row.size() != 0) && (Test.Status_Ing == Test_Station_Free)) {
        //
    } else {
        return;
    }

    for (int i = 0; i < PG_Row.size(); i++) {
        if (i < PG_Result_List.size()) {

        } else {
            continue;
        }
        Current_Row = PG_Row.at(i).toInt();
        QTableWidgetItem *pItem = new QTableWidgetItem;
        pItem->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *pItem3 = new QTableWidgetItem;
        pItem3->setTextAlignment(Qt::AlignCenter);
        if (ui->testTab->item(Current_Row, 2)->text().contains(QString(tr("Hz")))) {
            pItem->setText(strParam.at(Current_Row).mid(3 +  \
                                           strParam.at(Current_Row).indexOf(QString(tr("Hz")))));
            ui->testTab->setItem(Current_Row, 2, pItem);
            if ((i <= PG_Result_List.size()) && \
                    (ui->testTab->item(Current_Row, 3)->text() != NULL)) {
                pItem3->setText(PG_Result_List.at(i).mid(3 + \
                                            PG_Result_List.at(i).indexOf(QString(tr("Hz")))));
                ui->testTab->setItem(Current_Row, 3, pItem3);
            }
        } else {
            pItem->setText(strParam.at(Current_Row).mid \
                           (0, 2 + strParam.at(Current_Row).indexOf(QString(tr("Hz")))));
            ui->testTab->setItem(Current_Row, 2, pItem);
            if ((i <= PG_Result_List.size()) && \
                    (ui->testTab->item(Current_Row, 3)->text() != NULL)) {
                pItem3->setText(PG_Result_List.at(i).mid \
                                (0, 2 + PG_Result_List.at(i).indexOf(QString(tr("Hz")))));
                ui->testTab->setItem(Current_Row, 3, pItem3);
            }
        }
    }
}

void w_Test::Board_ACW_Data(QStringList ACW_Data_List)
{
    QString str;
    double  Replace_Data = 0.0;
    if ((ACW_Data_List.isEmpty()) || (ACW_Data_List.size() != 3)) {
        ACW_Data_List.clear();
        ACW_Data_List.append("--");
        ACW_Data_List.append("--");
        ACW_Data_List.append("1");
    }
    RemoveLastIR = true;

    if (Ini_ACWandIR) {
        Replace_Data = ACW_Data_List.at(1).toDouble() - strACW.at \
                (ACWgroup_num.at(ACW_Test_Count).toInt()*16 + 37).toDouble();
        if (Replace_Data < 0.00) {
            Replace_Data = 0.00;
        }
        ACW_Data_List.replace(1, QString::number(Replace_Data));
    }

    str = ACW_Data_List.at(0) + (QString::number(ACW_Data_List.at(1).toDouble(), 'f', ACW_Point)) + "mA";
    strResult.append(str);
    str.clear();
    if (!IRFinsh) {
        ACW_Data_List.clear();
        return;
    }

    frame.can_id  = 0x2C;  frame.can_dlc = 0x02; // 高压回路
    frame.data[0] = 0x12; // 高压回路
    frame.data[1] = 0x00;
    canSend(frame, wTest_Surface);
    usleep(500);

    RemoveLastIR = false;
    switch (ACW_Data_List.at(2).toInt()) {
    case 0: str = "OK";
        break;
    case 1: str = "NG";  Test.NG_Item = 4;
        break;
    case 2: str = "STOP";
        break;
    case 3: str = "ARC"; Test.NG_Item = 4;
        break;
    default:
        strResult.removeLast();
        strResult.append(ACW_Error.at(ACW_Data_List.at(2).toInt()));
        str = "NG";
        Test.NG_Item = 4;
        break;
    }
    strJudge.append(str);  str.clear();
    IRFinsh = false; qDebug() << "Test ACV Ok";
    if (Ini_ACWandIR) {
        ACW_Test_Count++;
        if (ACW_Test_Total == ACW_Test_Count) {
            ACW_Test_Count = 0;
            Test.Finshed_Count++;
        } else {
            Test.NG_Item = 0;
            if (Test.Interrupted) {
                ACW_Test_Count = 0;
                Test.Interrupted = false;
                join_test_stop(3);
            } else {
                if (Model_Occur_Unqualified == Test_NG_Continue) { // -遇不合格测试项目继续
                    usleep(5000);
                    Can_Start_ACW();
                } else if ((Model_Occur_Unqualified == Test_NG_Stop) && \
                           (ACW_Data_List.at(2).toInt())) { // -遇不合格测试项目停止
                    join_test_stop(3);
                } else if ((Model_Occur_Unqualified == Test_NG_Ask) && \
                           (ACW_Data_List.at(2).toInt())) { // -遇不合格测试项目询问
                    frame.can_id  = 0x22; // -电阻板输出量信号发送
                    frame.can_dlc = 0x02;
                    frame.data[0] = 0x09;
                    frame.data[1] = 0X04 | 0x08 | 0X01;
                    canSend(frame, wTest_Surface);
                    usleep(500);

                    if (Beep.NG_Time != 0) {
                        dcr_board->setSingleShot(TRUE);
                        dcr_board->start(Beep.NG_Time*1000);
                    }

                    Ask_Up_label->setAlignment(Qt::AlignCenter);
                    Ask_Up_label->setText("耐压\n不合格");
                    Ask_Widget->show();
                    Test.Status_Ing = Test_Station_Ask;
                } else {
                    usleep(5000);
                    Can_Start_ACW();
                }
            }
        }
    } else {
        Test.Finshed_Count++;
    }
}

void w_Test::Board_DCW_Data()
{
    QString str;
    str ="--";
    strResult.append(str);
    str ="--";
    strJudge.append(str);
    qDebug() << "Test DCV Ok";
}

void w_Test::Board_IR_Data(QStringList IR_Data_List)
{
    QString str;
    if ((IR_Data_List.isEmpty()) || (IR_Data_List.size() != 3)) {
        IR_Data_List.clear();
        IR_Data_List.append("--");
        IR_Data_List.append("--");
        IR_Data_List.append("1");
    }
    RemoveLastIR = true;
    if (IR_Data_List.at(1).toDouble() > 100) {
        if (IR_Data_List.at(1).toDouble() <= 500) {
            str = IR_Data_List.at(0) + QString::number \
                    ((int)(IR_Data_List.at(1).toDouble())) +"MΩ";
        } else {
            str = IR_Data_List.at(0) + ">500MΩ";
        }
    } else {
        str = IR_Data_List.at(0) + (QString::number \
                                    ((((int)(IR_Data_List.at(1).toDouble()*10))*0.1)) ) + "MΩ";
    }

    strResult.append(str);

    if (!IRFinsh) { // -IR未完成
        IR_Data_List.clear();
        return;
    }

    frame.can_id  = 0x2C;  frame.can_dlc = 0x02; // 高压回路
    frame.data[0] = 0x12; // 高压回路
    frame.data[1] = 0x00;
    canSend(frame, wTest_Surface);
    usleep(500);

    RemoveLastIR = false;
    switch (IR_Data_List.at(2).toInt()) {
    case 0:
        str = "OK";
        break;
    case 1:
        str = "NG";  Test.NG_Item = 3;
        break;
    case 2:
        str = "STOP";
        break;
    case 3:
        str = "ARC";  Test.NG_Item = 3;
        break;
    default:
        strResult.removeLast();
        strResult.append(IR_Error.at(IR_Data_List.at(2).toInt()));
        str = "NG"; Test.NG_Item = 3;
        break;
    }
    strJudge.append(str); str.clear();

    IRFinsh = false;  qDebug() << "Test IR Ok";
    if (Ini_ACWandIR) {
        IR_Test_Count++;
        if (IR_Test_Total == IR_Test_Count) {
            IR_Test_Count = 0;
            Test.Finshed_Count++;
        } else {
            Test.NG_Item = 0;
            if (Test.Interrupted) {
                IR_Test_Count = 0;
                Test.Interrupted = false;
                join_test_stop(3);
            } else {
                if (Model_Occur_Unqualified == Test_NG_Continue) { // -遇不合格测试项目继续
                    usleep(5000);
                    Can_Start_IR();
                } else if ((Model_Occur_Unqualified == Test_NG_Stop) && \
                           (IR_Data_List.at(2).toInt())) {
                    // -遇不合格测试项目停止
                    join_test_stop(3);
                } else if ((Model_Occur_Unqualified == Test_NG_Ask) && \
                           (IR_Data_List.at(2).toInt())) {
                    // -遇不合格测试项目询问
                    frame.can_id  = 0x22; // -电阻板输出量信号发送
                    frame.can_dlc = 0x02;
                    frame.data[0] = 0x09;
                    frame.data[1] = 0X04 | 0x08 | 0X01;
                    canSend(frame, wTest_Surface);
                    usleep(500);

                    if (Beep.NG_Time != 0) {
                        dcr_board->setSingleShot(TRUE);
                        dcr_board->start(Beep.NG_Time*1000);
                    }
                    Ask_Up_label->setAlignment(Qt::AlignCenter);
                    Ask_Up_label->setText("绝缘\n不合格");
                    Ask_Widget->show();
                    Test.Status_Ing = Test_Station_Ask;
                } else {
                    usleep(5000);
                    Can_Start_IR();
                }
            }
        }
    } else {
        Test.Finshed_Count++;
    }
}

void w_Test::Board_PWR_Data()
{
    QString str;
    qDebug() << "-----w_Test::Board_PWR_Data()---PWR test finsh--------";
    if (PWR_Result_Judge.size() < 10) {
        PWR_Result_Judge.append("0");
        PWR_Result_Judge.append("0");
        PWR_Result_Judge.append("0");
        PWR_Result_Judge.append("0");
        PWR_Result_Judge.append("0");
        PWR_Result_Judge.append("0");
        PWR_Result_Judge.append("0");
        PWR_Result_Judge.append("0");
        PWR_Result_Judge.append(QString(tr("不转")));
        PWR_Result_Judge.append("0");
    }
    str = PWR_Result_Judge.at(1) + "A," + PWR_Result_Judge.at(2) + "W," + \
            PWR_Result_Judge.at(6) + "V"; //-功率
    strResult.append(str);
    int PWR_Data = PWR_Test_Data.at(1 + PWR_Test_Count).toInt()/10;

    bool Error_flag = false;
    if ((PWR_Result_Judge.at(1).toDouble() < strPWR.at(38 + (PWR_Data)*20).toDouble()) || \
            (PWR_Result_Judge.at(1).toDouble() > strPWR.at(39 + (PWR_Data)*20).toDouble())) {
        Error_flag = true;
    }
    if ((PWR_Result_Judge.at(2).toDouble() < strPWR.at(40 + (PWR_Data)*20).toDouble()) || \
            (PWR_Result_Judge.at(2).toDouble() > strPWR.at(41 + (PWR_Data)*20).toDouble())) {
        Error_flag = true;
    }
    if ((PWR_Result_Judge.at(6).toDouble() < strPWR.at(42+(PWR_Data)*20).toDouble()) || \
            (PWR_Result_Judge.at(6).toDouble() > strPWR.at(43+(PWR_Data)*20).toDouble())) {
        Error_flag = true;
    }
    if (Error_flag) {
        str = "NG";
        Test.NG_Item = 7;
    } else {
        str = "OK";
    }
    strJudge.append(str);


    if (Ini_Pwr_Turn) { // -假转子测试转向，去除功率测试项目
        strResult.removeLast();
        strJudge.removeLast();
    }

    if (strPWR.at(44 + (PWR_Data)*20).toInt()) { // -转向
        str = PWR_Result_Judge.at(8);   strResult.append(str);
        if (turn.at(strPWR.at(44 + (PWR_Data)*20).toInt()) == PWR_Result_Judge.at(8)) {
            str ="OK";
        } else {
            str ="NG";
            Test.NG_Item = 7;
        }
        strJudge.append(str);
    }


    if ((Ini_Motor == QString(tr("PG"))) && (strPWR.at(5 + PWR_Data).toInt() == 2)) { // -显示PG
        qDebug() << "PG_list------------------------>" << PG_list;
        if (PG_list.size() != 6) {
            PG_list.clear();
            PG_list.append("0");
            PG_list.append("0");
            PG_list.append("0");
            PG_list.append("0");
            PG_list.append("0");
            PG_list.append("0");
        }
        str = PG_list.at(1)  +"V" + PG_list.at(2) + "V," + PG_list.at(3) + "Hz," + \
                PG_list.at(4) + "%," + PG_list.at(0) + "mA," + PG_list.at(5) + "rpm";
        // -低电平,高电平,频率

        PG_Result_List.append(str);
        strResult.append(str);
        qDebug() << "PG_Result_List^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << PG_Result_List;
        /**********进行---电流、高电平、低电平、频率、占空比---的比较，然后设置数据**********/
        QStringList PG_Param;
        PG_Param << "169" << "166" << "165" << "167" << "168" << "170";
        str ="OK";
        for (int i = 0; i < 6; i++) { //-进行参数的对比
            if (str == "OK") {
                if ((PG_list.at(i).toDouble() <= strPWR.at \
                    (30*PWR_Data + PG_Param.at(i).toInt()).toDouble()) && \
                        (PG_list.at(i).toDouble() >= strPWR.at \
                         (30*PWR_Data + PG_Param.at(i).toInt() + 15).toDouble())) {
                    //
                } else {
                    str = "NG";
                    Test.NG_Item = 7;
                }
            } else {
                //
            }
        }
        strJudge.append(str);
    }
    PWR_Test_Count++;
    if (PWR_Test_Data.at(0).toInt() == PWR_Test_Count) {
        Test.Finshed_Count++; // -增加计数
    } else {
        if (Test.Interrupted) {
            Test.Interrupted = false;
            join_test_stop(3);
        } else {
            if (Model_Occur_Unqualified == Test_NG_Continue) { // -遇不合格测试项目继续
                usleep(5000);
                Can_Start_PWR(2);
            } else if ((Model_Occur_Unqualified == Test_NG_Stop) && \
                       (Test.NG_Item == 7)) { // -遇不合格测试项目停止
                join_test_stop(3);
            } else if ((Model_Occur_Unqualified == Test_NG_Ask) && \
                       (Test.NG_Item == 7)) { // -遇不合格测试项目询问
                frame.can_id = 0x22;  frame.can_dlc = 0x02; // -电阻板输出量信号发送
                frame.data[0] = 0x09;
                frame.data[1] = 0X04 | 0x08 | 0X01;
                canSend(frame, wTest_Surface);
                usleep(500);

                if (Beep.NG_Time != 0) {
                    dcr_board->setSingleShot(TRUE);
                    dcr_board->start(Beep.NG_Time*1000);
                }

                Ask_Up_label->setAlignment(Qt::AlignCenter);
                Ask_Up_label->setText("功率\n不合格");
                Ask_Widget->show();
                Test.Status_Ing = Test_Station_Ask;
            } else {
                usleep(5000);
                Can_Start_PWR(2);
            }
            Test.NG_Item = 0;
        }
    }
}

void w_Test::Board_IMP_Data(QStringList IMP_Data_List)
{
    QString str;
    qDebug() << IMP_Data_List;
    if ((IMP_Data_List.isEmpty()) || (IMP_Data_List.size() != 4)) {
        IMP_Data_List.clear();
        IMP_Data_List.append("100");
        IMP_Data_List.append("100");
        IMP_Data_List.append("100");
        IMP_Data_List.append("100");
    }
    if (Data_Complete) {
        Data_Complete = false;
        int IMP_Row = 0;
        QStringList IMP_Text = IMP_Param.at(IMP_Test_Record_Number).split(",");
        qDebug() << "IMP_Text" << IMP_Text;
        if ((IMP_Text.indexOf("0", 3)  ==  0) || \
                (IMP_Text.indexOf("0", 4)  ==  0) || \
                (IMP_Text.size()  ==  3)) {
            str = QString(tr("面积:")) + IMP_Data_List.at(0) + \
                    "," + QString(tr("差积:")) + IMP_Data_List.at(1);
            IMP_Row = 2;
        } else {
            str = IMP_Data_List.at(0) + "," + IMP_Data_List.at(1) + "," \
                    + IMP_Data_List.at(2) + "," + IMP_Data_List.at(3);
            IMP_Row = 4;
        }
        strResult.append(str);
        for (int i = 0; i < IMP_Row; i++) {
            if (fabs(IMP_Data_List.at(i).toDouble()) <= strITT.at\
                    (IMP_Current_Testing_Item*820 + 4 + i).toDouble()) {
                str = "OK";
            } else {
                str = "NG";
                Test.NG_Item = 6;
                break;
            }
        }
        if ((Ini_imp_min) && (str  ==  "OK")) {
            qDebug() << "((Ini_imp_min)&&(str  ==  NG))-------------------------0K";
            for (int i = 0; i < 2; i++) {
                if ((IMP_Data_List.at(i).toInt()) >= strITT.at \
                        (IMP_Current_Testing_Item*820 + 19 - i).toInt()) {
                    str = "OK";
                } else {
                    str = "NG";
                    Test.NG_Item = 6;
                    break;
                }
            }
        } else {
            //
        }
        strJudge.append(str);
    } else {
        str = "0,0,0,0"; strResult.append(str);
        str = "NG"; strJudge.append(str);
        str.clear();
        Test.NG_Item = 6;
    }

    IMP_Test_Record_Number++;
    if (IMP_Total_Number  ==  IMP_Test_Record_Number) {
        IMP_Test_Record_Number = 0; qDebug() << "Test ITT Ok";
        Test.Finshed_Count++;

        Signal_test_to_Switchover(BDVacuum, 0, 9);
    }
}

void w_Test::Board_BLOCK_Data()
{
    QString str;
    if (BLOCK_list.size() < 2) {
        BLOCK_list << "0" << "0";
    } else {
        //
    }
    str = BLOCK_list.at(0) + "A," + BLOCK_list.at(1) + "W";
    strResult.append(str);

    if (((strBLOCK.at(211).toDouble() >= BLOCK_list.at(0).toDouble()) && \
         (BLOCK_list.at(0).toDouble() >= strBLOCK.at(221).toDouble())) && \
            ((strBLOCK.at(212).toDouble() >= BLOCK_list.at(1).toDouble()) && \
             (BLOCK_list.at(1).toDouble() >= strBLOCK.at(222).toDouble()))) {
        str = "OK";
    } else {
        str = "NG";
        Test.NG_Item = 9;
    }
    strJudge.append(str);
    Test.Finshed_Count++;
//    Kongshi_Stall = true;
//    Signal_test_to_Switchover(ZhongTe, ((1 << 0)*65536) | (1 << 7), 1);
    qDebug() << "BLOCK Finsh";
}

void w_Test::Board_LVS_Data()
{
    QString str;
    if (LVS_Result_Judge.size() < 10) {
        LVS_Result_Judge.append("0");
        LVS_Result_Judge.append("0");
        LVS_Result_Judge.append("0");
        LVS_Result_Judge.append("0");
        LVS_Result_Judge.append("0");
        LVS_Result_Judge.append("0");
        LVS_Result_Judge.append("0");
        LVS_Result_Judge.append("0");
        LVS_Result_Judge.append(QString(tr("不转")));
        LVS_Result_Judge.append("0");
    }
    str = LVS_Result_Judge.at(1) + "A," + LVS_Result_Judge.at(2) + "W";
    // -通过电流和功率判断
    if (Ini_LVS_Judge != 0) { // -通过旋向判断
        str = LVS_Result_Judge.at(8);
    }
    strResult.append(str);

    bool Error_flag = false;

    if ((LVS_Result_Judge.at(1).toDouble() < strLVS.at(30).toDouble()) || \
            (LVS_Result_Judge.at(1).toDouble() > strLVS.at(31).toDouble())) {
        Error_flag = true;
    }
    if ((LVS_Result_Judge.at(2).toDouble() < strLVS.at(32).toDouble()) || \
            (LVS_Result_Judge.at(2).toDouble() > strLVS.at(33).toDouble())) {
        Error_flag = true;
    }
    if (Error_flag) {
        str = "NG";
        Test.NG_Item = 10;
    } else {
        str = "OK";
    }

    if (Ini_LVS_Judge != 0) { // -通过旋向判断
        if (LVS_Result_Judge.at(8)  ==  turn.at(strLVS.at(3).toInt() + 1)) {
            str = "OK";
        } else {
            str = "NG";
        }
    } else {
        //
    }

    strJudge.append(str);
    Test.Finshed_Count++;
}

void w_Test::Board_INDL_Data()
{
    int i = 0;
    QString str;
    double  Q_Balance_All = 0.0, Q_Balance_Average = 0.0, Q_Balance_Value = 0.0, Q_Balance_Set= 0.0 ;
    QString Q_Balance_List;
    bool    Q_Balance_Judge = 0;

    double  INDL_Balance_All = 0.0,INDL_Balance_Average = 0.0,INDL_Balance_Value = 0.0,INDL_Balance_Set = 0.0;
    QString INDL_Balance_List;
    bool    INDL_Balance_Judge = 0;

//    if(strINDL.at(30+20*(Result_INDL-1)+7).toInt()  ==  0)
//    {
//        Result_Main = Result_Main + strINDL.at(30+20*(Result_INDL-1)+9).toDouble();
//    }
//    else if(strINDL.at(30+20*(Result_INDL-1)+7).toInt()  ==  1)
//    {
//        Result_Main = Result_Main + strINDL.at(30+20*(Result_INDL-1)+9).toDouble()*1000;
//    }
//    else
//    {
//        //-不做处理
//    }


    if (Station_Chose  ==  0x13) {
        if (strINDL.at(30 + 20*(Result_INDL - 1) + 7).toInt() == 0) {
            Result_Main = Result_Main + strINDL.at(30 + 20*(Result_INDL - 1) + 9).toDouble();
        } else if (strINDL.at(30 + 20*(Result_INDL - 1) + 7).toInt() == 1) {
            Result_Main = Result_Main + \
                    strINDL.at(30 + 20*(Result_INDL - 1) + 9).toDouble()*1000;
        } else  {
            // 不做处理
        }
    } else if (Station_Chose  ==  0x14) {
        if (strINDL.at(30 + 20*(Result_INDL - 1) + 7).toInt()  ==  0) {
            Result_Main = Result_Main + strINDL.at(30 + 20*(Result_INDL - 1) + 10).toDouble();
        } else if (strINDL.at(30 + 20*(Result_INDL - 1) + 7).toInt()  ==  1) {
            Result_Main = Result_Main + \
                    strINDL.at(30 + 20*(Result_INDL - 1) + 10).toDouble()*1000;
        } else {
            // 不做处理
        }
    } else {
        //
    }


    if (Result_Main < 0) {
        str ="---";
    } else if (Result_Main <= 1000) {
        str = QString::number(Result_Main, 'f', 1) + "uH";
    } else if (Result_Main <= 10000) {
        str = QString::number(Result_Main/1000, 'f', 3) + "mH";
    } else if (Result_Main <= 100000) {
        str = QString::number(Result_Main/1000, 'f', 2) + "mH";
    } else if (Result_Main <= 1000000) {
        str = QString::number(Result_Main/1000, 'f', 1) + "mH";
    } else  if (Result_Main <= 10000000) {
        str = QString::number(Result_Main/1000, 'f', 0) + "mH";
    } else {
        str ="---";
    }

    if (strINDL.at(7).toDouble() != 0.000) { // -Q值
        str +="," + QString::number(Result_Q, 'f', 2);
    } else {
        //
    }

    strResult.append(str);
    if (strINDL.at(30 + 20*(Result_INDL - 1) + 7).toInt()  ==  0) { // -单位uH
        if (strINDL.at(30 + 20*(Result_INDL - 1) + 5).toDouble() != 0.000) {
            if (((Result_Main >= strINDL.at(30 + 20*(Result_INDL - 1) + 2).toDouble()) && \
                (Result_Main <= strINDL.at(30 + 20*(Result_INDL - 1) + 3).toDouble())) && \
                    (Result_Q >= strINDL.at(30 + 20*(Result_INDL - 1) + 4).toDouble()) && \
                    (Result_Q <= strINDL.at(30 + 20*(Result_INDL - 1) + 5).toDouble())) {
                str = "OK";
            } else {
                str = "NG";
                Test.NG_Item = 8;
            }
        } else {
            if (((Result_Main >= strINDL.at(30 + 20*(Result_INDL - 1) + 2).toDouble()) && \
                 (Result_Main <= strINDL.at(30 + 20*(Result_INDL - 1) + 3).toDouble()))) {
                str = "OK";
            } else {
                str = "NG";
                Test.NG_Item = 8;
            }
        }
    } else if (strINDL.at(30 + 20*(Result_INDL - 1) + 7).toInt() == 1) { // -单位mH
        if (strINDL.at(30 + 20*(Result_INDL - 1) + 5).toDouble() != 0.000) {
            if (((Result_Main/1000 >= strINDL.at(30 + 20*(Result_INDL - 1) + 2).toDouble()) && \
                 (Result_Main/1000 <= strINDL.at(30 + 20*(Result_INDL - 1) + 3).toDouble())) && \
                    (Result_Q >= strINDL.at(30 + 20*(Result_INDL - 1) + 4).toDouble()) && \
                    (Result_Q <= strINDL.at(30 + 20*(Result_INDL - 1) + 5).toDouble())) {
                str = "OK";
            } else {
                str = "NG";
                Test.NG_Item = 8;
            }
        } else {
            if (((Result_Main/1000 >= strINDL.at(30 + 20*(Result_INDL - 1) + 2).toDouble()) && \
                 (Result_Main/1000 <= strINDL.at(30 + 20*(Result_INDL - 1) + 3).toDouble()))) {
                str = "OK";
            } else {
                str = "NG";
                Test.NG_Item = 8;
            }
        }
    }
    if (strResult.last()  ==  "---") {
        str = "NG";
        Test.NG_Item = 8;
    }
    if (str == QString(tr("NG"))) {
        //
    } else {
        if ((strINDL.at(7) != "0.0") && (INDL_Total_Number >= 3)) {
            if ((Result_Q >= strINDL.at(30 + 20*(Result_INDL - 1) + 4).toFloat()) && \
                    (Result_Q <= strINDL.at(30 + 20*(Result_INDL - 1) + 5).toFloat())) {
                str = "OK";
            } else {
                str = "NG";  Test.NG_Item = 8;
            }
        } else {
            //
        }
    }
    strJudge.append(str);

    INDL_Test_Record_Number++;
    if (INDL_Test_Record_Number <= 3) { // -计算不平衡度使用
        if (Result_Main <= 1000) {
            ResultTable_INDL_All[INDL_Test_Record_Number] = \
                    QString::number(Result_Main, 'f', 1).toDouble();
        } else {
            ResultTable_INDL_All[INDL_Test_Record_Number] = \
                    QString::number(Result_Main/1000, 'f', 2).toDouble();
        }
        ResultTable_INDL_Q[INDL_Test_Record_Number] = \
                QString::number(Result_Q, 'f', 2).toDouble();
    }
    if (INDL_Total_Number != INDL_Test_Record_Number) { // -判断电感是否测试完成
        return;
    }
    INDL_Test_Record_Number = 0;
    if((strINDL.at(1) != "0.0")&&(INDL_Total_Number >= 3))
    {

        INDL_Balance_Set = strINDL.at(1).toDouble();

        for(i=0;i<3;i++)
        {
            INDL_Balance_All += ResultTable_INDL_All[i+1];
        }
        INDL_Balance_Average = INDL_Balance_All/3;
        for(i=0;i<3;i++)
        {
            INDL_Balance_Value = fabs(( \
              fabs(INDL_Balance_Average-ResultTable_INDL_All[i+1])*100/INDL_Balance_Average));
                // .replace()
            if(INDL_Balance_Value>100.0)
            {
                INDL_Balance_Value = 100.0;
            }
            INDL_Balance_List += (QString::number(INDL_Balance_Value,'f',1)+"% ");
            if(INDL_Balance_Value>INDL_Balance_Set)
            {
                qDebug() << INDL_Balance_Value<<INDL_Balance_Set;
                INDL_Balance_Judge=1;
            }
        }
        strResult.append(INDL_Balance_List);

        if(INDL_Balance_Judge == 1)
        {
            strJudge.append("NG");Test.NG_Item = 8;
        }
        else
        {
            strJudge.append("OK");
        }
        Test.Current_Row++; // -行数增加
    } /*
    if ((strINDL.at(1) != "0.0") && (INDL_Total_Number >= 3)) {
        double  INDL_Balance_All = 0.0, INDL_Balance_Average = 0.0, INDL_Balance_Value = 0.0, INDL_Balance_Set = 0.0;
        QString INDL_Balance_List;
        bool    INDL_Balance_Judge = 0;
        INDL_Balance_Set = strINDL.at(1).toDouble();

        for (i = 0; i < 3; i++) {
            INDL_Balance_All += ResultTable_INDL_All[i + 1];
        }

        INDL_Balance_Average = INDL_Balance_All/3;

        double Res_Balance_difference = 0.0;
        double Compare_One = 0.0, Compare_Two = 0.0;
        double Compare_Finsh = 0.0;
        for (j = strResult.size(); j > strResult.size() - 3; j--) {
            for (i = strResult.size(); i > strResult.size() - 3; i--) {
                Compare_One = QString(strResult.at(j-1)).replace \
                        (QRegExp("[^\\d.]+"), "").toDouble();
                Compare_Two = QString(strResult.at(i-1)).replace \
                        (QRegExp("[^\\d.]+"), "").toDouble();
                Compare_Finsh = fabs(Compare_One-Compare_Two);
                if (Compare_Finsh > Res_Balance_difference) {
                    Res_Balance_difference = Compare_Finsh;
                }
            }
        }
        qDebug() << "Res_Balance_difference" << Res_Balance_difference;
        qDebug() << "INDL_Balance_Average" << INDL_Balance_Average;

        INDL_Balance_Value = (Res_Balance_difference)*100/INDL_Balance_Average; // .replace()
        if (INDL_Balance_Value > 100.0) {
            INDL_Balance_Value = 100.0;
        }
        INDL_Balance_List += (QString::number(INDL_Balance_Value, 'f', 2)+"% ");
        if (INDL_Balance_Value > INDL_Balance_Set) {
            qDebug() << INDL_Balance_Value << INDL_Balance_Set;
            INDL_Balance_Judge = 1;
        }

        strResult.append(INDL_Balance_List);

        if (INDL_Balance_Judge == 1) {
            strJudge.append("NG");
            Test.NG_Item = 8;
        } else {
            strJudge.append("OK");
        }
        Test.Current_Row++; // -行数增加
    }*/
    if ((strINDL.at(7).toDouble() != 0.0) && (INDL_Total_Number >= 3)) {
        Q_Balance_Set = strINDL.at(7).toDouble();

        for (i = 0; i < 3; i++) {
            Q_Balance_All += ResultTable_INDL_Q[i + 1];
        }
        Q_Balance_Average = Q_Balance_All/3;
        for (i = 0; i < 3; i++) {
            qDebug() << fabs(Q_Balance_Average - ResultTable_INDL_Q[i + 1]) << "3";
            Q_Balance_Value = (( \
            fabs(Q_Balance_Average - ResultTable_INDL_Q[i + 1])*100/Q_Balance_Average));
            // .replace()
            if (Q_Balance_Value >= double(100.0)) {
                Q_Balance_Value = double(100.0);
            } else {
                //
            }

            Q_Balance_List += (QString::number(Q_Balance_Value, 'f', 2) + "% ");
            if (Q_Balance_Value > Q_Balance_Set) {
                Q_Balance_Judge = 1;
            } else {
                //
            }
        }
        strResult.append(Q_Balance_List);

        if (Q_Balance_Judge == 1) {
            strJudge.append("NG");
            Test.NG_Item = 8;
        } else {
            strJudge.append("OK");
        }
        Test.Current_Row++; // -行数增加
    }
    qDebug() << "Test INDL Ok";
    Test.Finshed_Count++;
}

void w_Test::Board_MAG_Data(QStringList MAG_Data_List)
{
    QString str;
    qDebug() << "MAG_Data_List" << MAG_Data_List;
    if ((MAG_Data_List.isEmpty()) || (MAG_Data_List.size() != 1)) {
        MAG_Data_List.clear();
        MAG_Data_List.append("100");
    }

    if (Ini_Mag_Hide == 0) {
        if (MAG_Data_List.at(0).toInt() > 100) {
            str ="100%";
        } else {
            str = MAG_Data_List.at(0) + "%";
        }
        strResult.append(str);
        if ((MAG_Data_List.at(0).toDouble()) <= (strOPP.at \
                             (MAG_Current_Testing_Item*820+2).toDouble())) {
            str = "OK";
        } else {
            str = "NG";  Test.NG_Item = 2;
        }
        strJudge.append(str);
        if ((strOPP.at(7).toInt() == 2) && str == QString(tr("OK"))) {
            if(strOPP.at(MAG_Current_Testing_Item*NUM_OPP+8) != \
                    mag_zero.at(MAG_Current_Testing_Item)) { // 零點不同
                strResult.removeLast();
                strJudge.removeLast();
                str = strOPP.at(MAG_Current_Testing_Item*NUM_OPP+8);
                str += mag_zero.at(MAG_Current_Testing_Item);
                strResult.append("101%" + str);
                strJudge.append("NG"); Test.NG_Item = 2;
            } else { // 零點相同
                //
            }
        } else {

        }
    } else { // -隐藏波形数据
        if ((MAG_Data_List.at(0).toDouble()) <= (strOPP.at \
                             (MAG_Current_Testing_Item*820+2).toDouble())) {
            //
        } else {
            Test.NG_Item = 2;
        }
        Test.Current_Row--;
    }

    MAG_Test_Record_Number++;
    if (MAG_Total_Number != MAG_Test_Record_Number) {
        return;
    }

    if (TaskMagDirnumber != 5) { // -判断是否进行磁旋的判定
        if (Test.NG_Item == 2) {
            TaskMagDirnumber = 2;
        } else {
            //
        }
        switch (TaskMagDirnumber) {
        case 0:   str = QString(tr("正转"));  break;
        case 1:   str = QString(tr("反转"));  break;
        case 2:   str = QString(tr("不转"));  break;
        default:  str = QString(tr("--"));   break;
        }
        strResult.append(str);
        if (strOPP.at(6).toInt() == TaskMagDirnumber) {
            str = "OK";
        } else {
            str = "NG";
            Test.NG_Item = 2;
        }
        strJudge.append(str);
        Test.Current_Row++; // -行数增加
    }
    MAG_Test_Record_Number = 0; //  qDebug() << "Test MAG Ok";
    Test.Finshed_Count++;
}

void w_Test::Board_DLR_Data(QStringList DLR_Data_List)
{
    QString str;
    if ((DLR_Data_List.size() == 1) && (DLR_Data_List.at(0) == QString(tr("Error")))) {
        Test_WMessage(1, QString(tr("")));
        return;
    }
    if ((DLR_Data_List.isEmpty()) || (DLR_Data_List.size() != 5)) {
        DLR_Data_List.clear();
        DLR_Data_List.append("-1");
        DLR_Data_List.append("Ω");
        DLR_Data_List.append("0");
        DLR_Data_List.append("0");
        DLR_Data_List.append("0");
    }

    int MaxCount = 2*(qPow(10, DLR_Data_List.at(4).toInt()%3+1));
    MaxCount = MaxCount+MaxCount/10; // -判断是否超出限制(110%)

    if (DLR_Data_List.at(0).toDouble() <= MaxCount) {
        str = DLR_Data_List.at(0)+DLR_Data_List.at(1);
    } else {
        str = "> " + QString::number(MaxCount) + " " + DLR_Data_List.at(1);
    }
    strResult.append(str);

    if (((DLR_Data_List.at(0).toDouble()) >= \
         ((DLR_UpDown.at(DLR_Data_List.at(2).toInt()*2).toDouble()))) && \
            (((DLR_Data_List.at(0).toDouble())) <= \
             ((DLR_UpDown.at(DLR_Data_List.at(2).toInt()*2 + 1).toDouble())))) {
        str = "OK";
    } else {
        str = "NG";
        Test.NG_Item = 1;
        if (((DLR_Data_List.at(0).toDouble())) <= \
                (DLR_UpDown.at(DLR_Data_List.at(2).toInt()*2 + 1).toDouble()/2)) {
            DCR_Connect = true;
        } else {
            //
        }
    }
    strJudge.append(str);
    DCR_Test_Record_Number++;
    if (DCR_Total_Number == DCR_Test_Record_Number) { // -判断电阻是否测试完成
        if (DLR_UpDown.at(20).toDouble() != 0.000) {   // -计算电阻不平衡度
            Board_DLR_Unbalance(DCR_Total_Number);
        }
        DCR_Test_Record_Number = 0;   qDebug() << "Test DLR Ok";
        Test.Finshed_Count++;
    }
}

void w_Test::Board_DLR_Unbalance(int dlr_conut)
{
    double  Res_Balance_All = 0.0, Res_Balance_Average = 0.0, Res_Balance_Value = 0.0, Res_Balance_Set = 0.0;
    double  Res_Balance_difference = 0.0; // -电阻不平衡度两两数值差
    QString Res_Balance_List;
    bool    Res_Balance_Judge = 0;
    int     i = 0, j = 0;
    Res_Balance_Set = DLR_UpDown.at(20).toDouble();
    if ((strRES.at(10).toInt() == 1)&&(DCR_Total_Number >= 3)) { // -普通电阻三个测试不平衡度
        for (i = strResult.size() - dlr_conut; i < strResult.size(); i++) {
            Res_Balance_All += QString(strResult.at(i)).replace \
                    (QRegExp("[^\\d.]+"), "").toDouble(); // .replace()
        }
        Res_Balance_Average = Res_Balance_All/dlr_conut;

        for (i = strResult.size() - dlr_conut; i < strResult.size(); i++) {
            Res_Balance_Value = (fabs(Res_Balance_Average-QString(strResult.at(i)).replace \
               (QRegExp("[^\\d.]+"), "").toDouble())*100/Res_Balance_Average); // .replace()
            Res_Balance_List += (QString::number(Res_Balance_Value, 'f', 3)+"% ");
            if (Res_Balance_Value >= Res_Balance_Set) {
                Res_Balance_Judge = 1;
            }
        }
        strResult.append(Res_Balance_List);
        if (Res_Balance_Judge == 1) {
            strJudge.append("NG");
            Test.NG_Item = 1;
        } else {
            strJudge.append("OK");
        }
        Test.Current_Row++; // -行数增加
    } else if ((strRES.at(10).toInt() == 2) && (DCR_Total_Number >= 2)) { // -两两相减的电阻差
        Res_Balance_difference = 0;
        double Compare_One = 0.0, Compare_Two = 0.0;
        double Compare_Finsh = 0.0;
        for (j = strResult.size(); j > strResult.size() - dlr_conut ; j--) {
            for (i = strResult.size(); i > strResult.size() - dlr_conut; i--) {
                Compare_One = QString(strResult.at(j-1)).replace \
                        (QRegExp("[^\\d.]+"), "").toDouble();
                Compare_Two = QString(strResult.at(i-1)).replace \
                        (QRegExp("[^\\d.]+"), "").toDouble();
                Compare_Finsh = fabs(Compare_One - Compare_Two);
                if (Compare_Finsh > Res_Balance_difference) {
                    Res_Balance_difference = Compare_Finsh;
                }
            }
        }
        Res_Balance_Value = Res_Balance_difference*100/strRES.at(NUM_RES_Con + 4).toDouble();
        Res_Balance_List += (QString::number(Res_Balance_Value, 'f', 3)+"% ");
        if (Res_Balance_Value > Res_Balance_Set) {
            Res_Balance_Judge = 1;
        }
        strResult.append(Res_Balance_List);
        if (Res_Balance_Judge == 1) {
            strJudge.append("NG");
            Test.NG_Item = 1;
        } else {
            strJudge.append("OK");
        }
        Test.Current_Row++; // -行数增加
    } else if ((strRES.at(10).toInt() == 3) && (DCR_Total_Number >= 3)) { // -两两相减的电阻差
        Res_Balance_difference = 0;
        double Compare_One = 0.0, Compare_Two = 0.0;
        double Compare_Finsh = 0.0;
        for (j = strResult.size(); j > strResult.size() - dlr_conut; j--) {
            for (i = strResult.size(); i > strResult.size() -dlr_conut; i--) {
                Compare_One =  QString(strResult.at(j-1)).replace \
                        (QRegExp("[^\\d.]+"), "").toDouble();
                Compare_Two =  QString(strResult.at(i-1)).replace \
                        (QRegExp("[^\\d.]+"), "").toDouble();
                Compare_Finsh = fabs(Compare_One-Compare_Two);
                if (Compare_Finsh > Res_Balance_difference) {
                    Res_Balance_difference = Compare_Finsh;
                }
            }
        }

//        for (i = strResult.size() - dlr_conut; i < strResult.size(); i++) {
//            Res_Balance_All += QString(strResult.at(i)).replace \
//                    (QRegExp("[^\\d.]+"), "").toDouble(); // .replace()
//        }
//        Res_Balance_Average = Res_Balance_All/dlr_conut;
        qDebug() << "电阻平衡度测试---" << Res_Balance_difference;
        qDebug() << "电阻平衡度测试平均" << Res_Balance_Average;
//        Res_Balance_Value = Res_Balance_difference*100/Res_Balance_Average;
        Res_Balance_List += (QString::number(Res_Balance_difference, 'f', 3));
        if (Res_Balance_Value > Res_Balance_Set) {
            Res_Balance_Judge = 1;
        }
        strResult.append(Res_Balance_List);
        if (Res_Balance_Judge == 1) {
            strJudge.append("NG");
            Test.NG_Item = 1;
        } else {
            strJudge.append("OK");
        }
        Test.Current_Row++; // -行数增加
    }
}

void w_Test::Board_FG_Data(QStringList Updatedata_List) {
    QStringList FG_list;
    QString str;
    int FG_count = 0;
    int i = 0;

    double H_Lever = 0.0, L_Lever = 0.0;
 /*   qDebug() << Updatedata_List.size();
    qDebug() << Updatedata_List.at(260) << Updatedata_List.at(261);
    qDebug() << Updatedata_List.at(280) << Updatedata_List.at(281);
    qDebug() << Updatedata_List.at(300) << Updatedata_List.at(301);
    qDebug() << Updatedata_List.at(350) << Updatedata_List.at(351);
    qDebug() << Updatedata_List.at(354) << Updatedata_List.at(355);
    qDebug() << Updatedata_List.at(358) << Updatedata_List.at(359);

        str = QString::number(PG_Fre) + "Hz," + QString::number(PG_Bb) + "%," + \
                QString::number(PG_High) + "V," + QString::number(PG_Low) + "V"; */

    H_Lever = Updatedata_List.at(101 + 20*FG_Test_Count).toDouble() * 15.68 / 4096;
    L_Lever = Updatedata_List.at(100 + 20*FG_Test_Count).toDouble() * 15.68 / 4096;

    FG_list.clear();
    FG_list.append(QString::number((H_Lever),'f',2));
    FG_list.append(QString::number((L_Lever),'f',2));
    FG_list.append(QString::number((Updatedata_List.at(20 + 4*FG_Test_Count).toDouble()/1000),'f',1));
    FG_list.append(QString::number((Updatedata_List.at(21 + 4*FG_Test_Count).toDouble()/1000),'f',1));

    FG_count = 0;
    str =  FG_list.at(0) + "V," \
            + FG_list.at(1) + "V," \
           + FG_list.at(2) + "Hz " \
           + FG_list.at(3) + "%";

    for (i = 0; i < 5; i++) {

        if (FG_Test_Data.at(1 + FG_Test_Count) == Hall_Count.at(i)) {
            FG_count = i;
            break;
        }
    }
    strResult.append(str);

    for (i = 0; i < 4; i++) {
//        qDebug() << "i" << i << FG_Param_A.at(i).toInt() + 15 + FG_count*30;
//        qDebug() << FG_Param_A.at(i).toInt() + FG_count*30;

        if ((FG_list.at(i).toDouble() <= \
                strPG.at(FG_Param_A.at(i).toInt() + 15 + FG_count*30).toDouble()) &&  \
            (FG_list.at(i).toDouble() >= \
                strPG.at(FG_Param_A.at(i).toInt() + FG_count*30).toDouble()))  { //
            str = "OK";
        } else {
            str = "NG";
            Test.NG_Item = 11;
            break;
        }
    }

    strJudge.append(str);
 // emit WriteMessage(6000, 0x73, QString(Updatedata_List.join(" ")).toUtf8());

    if (FG_Test_Data.at(1 + FG_Test_Count) == QString(tr("A"))) {
        FG_Param(Shape_Hall_A);
    } else if (FG_Test_Data.at(1 + FG_Test_Count) == QString(tr("B"))) {
        FG_Param(Shape_Hall_B);
    } else if (FG_Test_Data.at(1 + FG_Test_Count) == QString(tr("C"))) {
        FG_Param(Shape_Hall_C);
    } else {

    }

    FG_Test_Count++;
    qDebug() << FG_Test_Data.at(FG_Test_Count) << "2018-3-9";
    if (FG_Test_Count == FG_Test_Data.at(0).toInt()) {
        Test.Finshed_Count++;
    } else {
        Can_Start_BLDCHALL();
    }
}

void w_Test::Board_NOLOAD_Data(QStringList Updatedata_List) {
    int i = 0;
    QString str;
    double  I_get = 0.0, P_get= 0.0 ;
    QStringList Noload_list;

    if ((Updatedata_List.isEmpty()) || (Updatedata_List.size() != 31)) {
        Updatedata_List.clear();
        Updatedata_List = NoLoad_Update;
    }
    RemoveLastNOLoad = true;

    Updatedata_List.replace(3,QString::number((Updatedata_List.at(26).toInt())/strNOLOAD.at(13).toInt()));

    Noload_list.clear();
    if (Station_Chose == 0x13) {
        I_get = Updatedata_List.at(23).toDouble() + strNOLOAD.at(15).toDouble();
    } else {
        I_get = Updatedata_List.at(23).toDouble() + strNOLOAD.at(16).toDouble();
    }

    if (I_get < 0) {
        I_get = 0.000;
    } else {
        //
    }
    P_get = I_get * Updatedata_List.at(24).toDouble();
    Noload_list.append(QString::number(I_get, 'f', 2));
    Noload_list.append(QString::number(Updatedata_List.at(24).toDouble(), 'f', 1));
    Noload_list.append(QString::number(P_get, 'f', 1));
    Noload_list.append(QString::number(Updatedata_List.at(25).toInt()));

    if (Updatedata_List.at(29).toInt() > 2) {
        Updatedata_List.replace(29, QString::number(0));
    }

//    join_test_start_two(Updatedata_List);
    str = Noload_list.at(0) + "A," +
            Noload_list.at(1) + "V," + \
            Noload_list.at(2) + "W " + \
            Noload_list.at(3) + "rpm";
    if (strNOLOAD.at(11).toInt() != 0) {
        str += ",";
        str += FG_direction.at(Updatedata_List.at(29).toInt());
    }
    strResult.append(str);
    if (!NoLoadFinsh) {
        qDebug() << "return";
        return;
    } else {
        qDebug() << "111";
    }

    for (i = 0; i < 4; i++) {
        if ((Noload_list.at(i).toDouble() <= \
                strNOLOAD.at(No_load_Param.at(i).toInt()+15).toDouble()) &&  \
            (Noload_list.at(i).toDouble() >= \
                strNOLOAD.at(No_load_Param.at(i).toInt()).toDouble()))  { //
            str = "OK";
        } else {
            str = "NG";
            Test.NG_Item = 13;
            break;
        }
    }
    if ((strNOLOAD.at(11).toInt() != 0) && (str == "OK")) {
        if (Updatedata_List.at(29).toInt() != strNOLOAD.at(11).toInt()) {
            str = "NG";
            Test.NG_Item = 13;
        } else {

        }
    }

    RemoveLastNOLoad = false;
    strJudge.append(str);
    Test.Finshed_Count++;
    NoLoadFinsh = false;

    for (i = 0; i < 200; i++) { // 下发参数延时等待 200ms
        usleep(1000);
    }

    Signal_test_to_Switchover(Bosch, 0x01, 7);
}

void w_Test::Board_LOAD_Data(QStringList Updatedata_List) {
    QString str;
    Test.Finshed_Count++;
    if ((Updatedata_List.isEmpty()) || (Updatedata_List.size() != 5)) {
        Updatedata_List.clear();
        Updatedata_List.append("0,");
        Updatedata_List.append("0,");
        Updatedata_List.append("0,");
        Updatedata_List.append("0");
        Updatedata_List.append("0");
    }

//    join_test_start_two(Updatedata_List);
    str = (QString::number(Updatedata_List.at(0).toDouble(), 'f', 2)) + "mA," +
            (QString::number(Updatedata_List.at(2).toDouble(), 'f', 1)) + "W," +
            Updatedata_List.at(3);
    strResult.append(str);  strJudge.append("OK");
}

void w_Test::Board_BEMF_Data(QStringList Updatedata_List) {
    QString str;
    Test.Finshed_Count++;
    strResult.append("NULL");  strJudge.append("NG");
    emit WriteMessage(6000, 0x73, QString(Updatedata_List.join(" ")).toUtf8());
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.1.28
  * brief:      更新测试结果
******************************************************************************/
void w_Test::join_updatedata(QStringList Updatedata_List)
{
    int i = 0;
    char copystr[256];
    char *whom;


    if (Test.Status_Ing != Test_Station_Busy) { // -在测试遇不合格测试项目时
        qDebug() << "Not test busying,exit test--------------------->" << Test.Status_Ing;
        return;
    }
    qDebug() << "Join update data---------------------------------->";
    switch (Conf_Item.at(Test.Finshed_Count).toInt()) { // -寻找测试项目
    case 1: // -电阻
        Board_DLR_Data(Updatedata_List);
        break;
    case 2: // -反嵌
        Board_MAG_Data(Updatedata_List);
        break;
    case 3: // -绝缘
        Board_IR_Data(Updatedata_List);
        break;
    case 4: // -交耐
        Board_ACW_Data(Updatedata_List);
        break;
    case 5: // -直耐
        Board_DCW_Data();
        break;
    case 6: // -匝间
        Board_IMP_Data(Updatedata_List);
        break;
    case 7: // -功率
        Board_PWR_Data();
        Signal_test_to_Switchover(NanXin, 18, 5);
        break;
    case 8: // -电感
        Board_INDL_Data();
        break;
    case 9: // -堵转
        Board_BLOCK_Data();
        break;
    case 10: // -低启
        Board_LVS_Data();
        break;
    case 11: // -霍尔
        Board_FG_Data(Updatedata_List);
        break;
    case 12: // -负载
        Board_LOAD_Data(Updatedata_List);
        break;
    case 13: // -空载
        Board_NOLOAD_Data(Updatedata_List);
        break;
    case 14: // -反电动势
        Board_BEMF_Data(Updatedata_List);
        break;
    default:
        //
        break;
    }
    for (i = StrResult_Size; i < strResult.size(); i++) { // -添加测试结果
        QTableWidgetItem *pItem = new QTableWidgetItem(strResult.at(i));
        pItem->setTextAlignment(Qt::AlignCenter);
        ui->testTab->setItem(i, 3, pItem);
        PC_Test_Result_Data(strResult.at(i), QString(tr("Test_Data_Result")));


        if ((RemoveLastIR) || (RemoveLastNOLoad)) {
        //    StrResult_Size = strResult.size();
        } else {
            StrResult_Size = strResult.size();
        }
        if (i < strJudge.size()) {
            PC_Test_Result_Data(strJudge.at(i), QString(tr("Test_Data_Judge")));
        }
    }
    for (i = StrJudge_Size; i < strJudge.size(); i++) {  // -添加测试判定
        QTableWidgetItem *ppItem = new QTableWidgetItem(strJudge.at(i));
        ppItem->setTextAlignment(Qt::AlignCenter);
    //    PC_Test_Result_Data(strJudge.at(i), QString(tr("Test_Data_Judge")));
        QFont fontfont  = this->font();

        fontfont.setBold(true);
        qDebug() << "strJudge[i] " << i << strJudge[i] << strResult[i] ;
        ppItem->setFont(fontfont); // -设置粗体
        if (strJudge[i] == "OK") {
            ppItem->setTextColor(QColor("green"));
        } else {
            Test.Judge_NG = true;
            ppItem->setTextColor(QColor("red"));
        }

        ui->testTab->setItem(i, 4, ppItem);
        if ((RemoveLastIR) || (RemoveLastNOLoad)) {
           // StrJudge_Size = strJudge.size();
        } else {
            StrJudge_Size = strJudge.size();
        }

//        if (!RemoveLastIR) {
//            StrJudge_Size = strJudge.size();
//        }
//        if (!RemoveLastNOLoad) {
//            StrJudge_Size = strJudge.size();
//        }
    }
    qApp->processEvents();
    if (Conf_Item.contains(tr("7")) || \
            Conf_Item.contains(tr("13"))) {
        if (DCR_Connect) {       // -测试线圈是否短路,进行保护
            DCR_Connect = false;
            join_test_stop(3); // -测试立即停止
        //  Test_WMessage(2, QString(tr("")));
            Ask_Up_label->setAlignment(Qt::AlignCenter);
            Ask_Up_label->setText(tr("电阻过小\nSTOP"));
            Ask_Widget->show();
        } else {
            //
        }
    }
    if (RemoveLastIR) { // -判断在（绝缘和耐压）更新
        RemoveLastIR = false;
        strResult.removeLast();
    } else if (RemoveLastNOLoad) { // -判断在（绝缘和耐压）更新
        RemoveLastNOLoad = false;
        strResult.removeLast();
    } else {
        Test.Current_Row++;
        if (Test.Current_Row > 11) { // -条行框实时显示
            ui->testTab->verticalScrollBar()->setValue(Test.Current_Row - 11);
        } else {
            //
        }
    }
    qApp->processEvents();
    if ((Test.Status_Ing != Test_Station_Busy))  {    // -进行测试项目判断标志
        return;
    }
    if (Test.Next_Finsh_Count != Test.Finshed_Count) { // -测试单个项目和总项目是否完成
        return;
    } else {
        qDebug() << " (Conf_Item.at(Test.Finshed_Count-1).toInt()) finsh-----" \
                 << (Conf_Item.at(Test.Finshed_Count-1).toInt());
        switch (Conf_Item.at(Test.Finshed_Count-1).toInt()) {
        case 1: // -电阻
            PC_Test_Result_ItemData(QString::number(DCR_Total_Number), "DCR");
            break;
        case 2: // -反嵌
            PC_Test_Result_ItemData(QString::number(MAG_Total_Number), "MAG");
            break;
        case 3: //- 绝缘
            PC_Test_Result_ItemData(QString::number(1), "IR");
            Signal_test_to_pic(QStringList(""), 3, 8);  // IR判定增加
            break;
        case 4: // -交耐
            PC_Test_Result_ItemData(QString::number(1), "ACW");
            Signal_test_to_pic(QStringList(""), 4, 8);  // ACW判定增加
            break;
        case 5: // -直耐
            //
            break;
        case 6: // -匝间
            PC_Test_Result_ItemData(QString::number(IMP_Total_Number), "IMP");
            break;
        case 7: // -功率
            //
            break;
        case 8: // -电感
            PC_Test_Result_ItemData(QString::number(INDL_Total_Number), "IND");
            break;
        case 9: // -堵转
            //
            break;
        case 10: // -低启
            //
            break;
        case 11: // -霍尔
            PC_Test_Result_ItemData(QString::number(1), "HALL");
            break;
        case 12: // -负载
            PC_Test_Result_ItemData(QString::number(1), "LOAD");
            break;
        case 13: // -空载
            PC_Test_Result_ItemData(QString::number(1), "NOLOAD");
            break;
        case 14: // -反电动势
            PC_Test_Result_ItemData(QString::number(1), "BEMF");
            break;
        default:
            break;
        }
    }

    qDebug() << "(!(Test.Interrupted))" << (!(Test.Interrupted));
    qDebug() << "Test.Judge_NG" << Test.Judge_NG;
    qDebug() << "(Test.NG_Item == (Conf_Item[Test.Finshed_Count-1].toInt()))" << \
                (Test.NG_Item == (Conf_Item[Test.Finshed_Count-1].toInt()));
    if ((!(Test.Interrupted)) && (Test.Judge_NG) && (Model_Occur_Unqualified == Test_NG_Ask) \
            && (Test.NG_Item == (Conf_Item[Test.Finshed_Count-1].toInt()))) {
        // 遇不合格测试项目询问
        Test.Judge_NG = false;
        frame.can_id  = 0x22; // -输出板输出量信号发送
        frame.can_dlc = 0x02;
        frame.data[0] = 0x09;
        frame.data[1] = 0X04|0x08|0X01;
        canSend(frame, wTest_Surface);
        usleep(500);
        if (Beep.NG_Time != 0) {
            dcr_board->setSingleShot(TRUE);
            dcr_board->start(Beep.NG_Time*1000);
        }
        whom = QString(Test_Item.at(Test.NG_Item)).toUtf8().data();
        sprintf(copystr,  "%s\n不合格", whom);
        Ask_Up_label->setAlignment(Qt::AlignCenter);
        Ask_Up_label->setText(copystr);
        Ask_Widget->show();
        Test.Status_Ing = Test_Station_Ask;
    } else if (((Conf_Item.size()) == (Test.Finshed_Count)) \
               && (!(Test.Interrupted))) { //-测试全部完成
        if ((ui->testTab->rowCount()) > 12) { // -显示出全部
            ui->testTab->verticalScrollBar()->setValue(ui->testTab->rowCount());
        }
        Test.Current_Row = 0;
        Test.Interrupted = false;
        Test.Status_Ing  = Test_Station_Free;
        Test.Next_Finsh_Count = 0;
        Test.Finshed_Count = 0;
        waveform_all_count = 0; // -波形数量清0
        waveform_row_count = 0;
        Signal_Test_to_Main(2, 2); // 波形数量清0
        if (Test_Judge_TotalResult()) { // -判定最终的显示状态(显示,蜂鸣器,LED)
            Test_Beep_State(Beep.NG_Time, "NG");
            Sigtest_Usart_Send(QString("LEDR").toLatin1().data());
            Test_Judge_State("NG");
        } else {
            Test_Beep_State(Beep.OK_Time, "OK");
            Sigtest_Usart_Send(QString("LEDG").toLatin1().data());
            Test_Judge_State("OK");
        }

        strResult.clear();  strJudge.clear(); // -列表(结果,判定)清0
        StrResult_Size = 0; StrJudge_Size = 0;
        CRecrd_Wave = Recrd_Wave;   // -记录匝间和反嵌的数目
        if (((Recrd_Wave - 1)/3) >= 1) { // -设置上查询使能
            ui->button_up->setEnabled(true);
        } else {
            ui->button_down->setDisabled(true);
        }
        // gettimeofday(&stop,0);
        // timeval_subtract(&diff,&start,&stop);
        Test_SelfStart(); qDebug() << "Test All Ok";
    } else { // -测试单个完成，触发下一个项目
        qDebug() << "Test one finsh" << Test.Interrupted << Test.Judge_NG << Model_Occur_Unqualified;
        if (Test.Interrupted) {
            Test.Interrupted = false;
            join_test_stop(3);
            lable_stop->show();
        } else if (Test.Judge_NG) {
            if (Model_Occur_Unqualified == Test_NG_Stop) { // -遇不合格测试项目停止
                join_test_stop(3);
            } else if ((Model_Occur_Unqualified == Test_NG_Ask) && \
                     (Test.NG_Item == (Conf_Item[Test.Finshed_Count - 1].toInt()))) {
                // -遇不合格测试项目询问
                frame.can_id  = 0x22; // -电阻板输出量信号发送
                frame.can_dlc = 0x02;
                frame.data[0] = 0x09;
                frame.data[1] = 0X04 | 0x08 | 0X01;
                canSend(frame, wTest_Surface);
                usleep(500);
                if (Beep.NG_Time != 0) {
                    dcr_board->setSingleShot(TRUE);
                    dcr_board->start(Beep.NG_Time*1000);
                }
                whom = QString(Test_Item.at(Test.NG_Item)).toUtf8().data();
                sprintf(copystr,  "%s\n不合格", whom);
                Ask_Up_label->setAlignment(Qt::AlignCenter);
                Ask_Up_label->setText(copystr);
                Ask_Widget->show();
                Test.Status_Ing = Test_Station_Ask;
            } else if (Model_Occur_Unqualified == Test_NG_Continue) {
                // -遇不合格测试项目继续
                Test_Start();
            } else { // -其余选项
                Test_Start();
            }
        } else {
            Test_Start();
        }
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      老化自启动函数
******************************************************************************/
void w_Test::Test_SelfStart()
{
    if (Self_starting[0].toInt() != 1) {
        return;
    }

    Test.Status_Ing = Test_Station_Inte; // -防止进入测试界面
    if (Self_starting[1].toInt() == 0) {
        Button_Start_Station = 0x13;
    } else if (Self_starting[1].toInt() == 1) {
        Button_Start_Station = 0x14;
    } else if (Self_starting[1].toInt() == 2) {
        if (Button_Start_Station == 0x13) {
            Button_Start_Station = 0x14;
        } else if (Button_Start_Station == 0x14) {
            Button_Start_Station = 0x13;
        } else {
            //
        }
    } else {
        //
    }
    QTimer *Button_Start = new QTimer(this);
    connect(Button_Start, SIGNAL(timeout()), this, SLOT(join_test_button_start())); //
    Button_Start->setSingleShot(TRUE);
    Button_Start->start(Self_starting[2].toInt()*1000);
    Button_Start_Time_Flag = true;
    label_Waring->show();
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      自启动，虚拟进入滑罩
******************************************************************************/
void w_Test::join_test_button_start()
{
    Test.Status_Ing = Test_Station_Free; // -防止进入测试界面
    if (!Button_Start_Time_Flag) {
        return;
    }

    Button_Start_Time_Flag = false;
    ui->label_6->text().clear();
    ui->label_6->setText("");
    if (Button_Start_Station != 0x13) {
        Button_Start_Station = 0x14;
    }
    join_test_start(START_Model, Button_Start_Station);
}

void w_Test::IO_Delay_Start_timeout() {
    if (Ini_IO_Delay) {
        //
    } else {
        return;
    }
    if (IO_Test_Readying) {
        IO_Test_Readying = false;
        Test_Process(); // 清空后，开始测试
    } else {
       //
    }
}

void w_Test::IO_Pumb_Start_timeout() {
    if(IO_Test_Readying) {
        //
    } else {
        IO_Test_Readying = false;
        return;
    }
    IO_Test_Readying = false;
    Test_WMessage(3, QString(tr("")));
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      测试电阻板的停止
******************************************************************************/
void w_Test::test_join_dcr_stop()
{
    frame.can_id  = 0x22; //-电阻板输出量信号发送
    frame.can_dlc = 0x02;
    frame.data[0] = 0x09;
    frame.data[1] = 0X04|0X01;
    canSend(frame, wTest_Surface);
    usleep(500);
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.11
  * brief:      判定最终的显示结果
******************************************************************************/
int w_Test::Test_Judge_TotalResult()
{
    int i = 0;
    if (strJudge.size() == strTest.size()) {
        //
    } else {
        for (i = strJudge.size(); i < strTest.size(); i++) {
            strJudge.append("");
            strResult.append("");
        }
    }
    for (i = 0; i < strJudge.size(); i++) {
        if (strJudge[i] == "OK") {
            //
        } else {
            return 1;
        }
    }
    return 0;
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.11
  * brief:      返回主页
******************************************************************************/
void w_Test::on_button_back_clicked()
{
    Histogram_Widget->hide();
    if (Test.Status_Ing != Test_Station_Free) {
        return;
    }
    IO_Test_Readying = false;
    Signal_Test_to_Main(wMain_Surface, 1);
    Test_Judge_State("");
    ui->label_station->setStyleSheet("color: rgb(255, 255, 255);"\
                                     "border: none;font: Bold 40pt Ubuntu;");
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.11
  * brief:      进入参数设置
******************************************************************************/
void w_Test::on_button_set_clicked()
{
    if (Test.Status_Ing != Test_Station_Free) {
        return;
    }
    if ((ui->testTab->currentRow() >= 0) && (ui->testTab->currentRow() < strTest.size())) {
        if ((ui->testTab->item(ui->testTab->currentRow(), 1)->text()) == QString(tr("磁旋"))) {
            JUMP_Chose = 2;
        } else if ((ui->testTab->item(ui->testTab->currentRow(), 1)->text()) == \
                  QString(tr("转向"))) {
            JUMP_Chose = 7;
        } else if (ui->testTab->item(ui->testTab->currentRow(), 1)->text().contains(tr("PG"))) {
            JUMP_Chose = 7;
        } else {
            JUMP_Chose = 0;
            for (int i = 0; i < Test_Item.size(); i++) {
                qDebug() << ui->testTab->item(ui->testTab->currentRow(), 1)->text();
                qDebug() << Test_Item.at(i);
                if (ui->testTab->item(ui->testTab->currentRow(), 1)->text().contains \
                        (Test_Item.at(i), Qt::CaseInsensitive)) {
                    JUMP_Chose = i;
                }
            }
        }
    } else {
        JUMP_Chose = 0;
    }
    qDebug() << "JUMP_Chose" << JUMP_Chose;
    IO_Test_Readying = false;
    Signal_Test_to_Main(wConf_Surface, 1);
    JUMP_Chose = 0;
    Test_Judge_State("");
    ui->label_station->setStyleSheet("color: rgb(255, 255, 255);"\
                                     "border: none;font: Bold 40pt Ubuntu;");
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.11
  * brief:      上移下移功能
******************************************************************************/
void w_Test::on_testTab_clicked(const QModelIndex &index)
{
    int value = ui->testTab->verticalScrollBar()->value();

    if (index.row()-value >= 8) {      // -下3格,下移
        ui->testTab->verticalScrollBar()->setValue(++value);
    } else if (index.row()-value <= 4) { // -上3格,上移
        ui->testTab->verticalScrollBar()->setValue(--value);
    } else {
        //
    }
}
// int w_Test::timeval_subtract(struct timeval* result, struct timeval* x, struct timeval* y)
// {
//    if ( x->tv_sec>y->tv_sec )
//        return -1;
//    if ( (x->tv_sec == y->tv_sec) && (x->tv_usec>y->tv_usec) )
//        return -1;
//    result->tv_sec = ( y->tv_sec-x->tv_sec );
//    result->tv_usec = ( y->tv_usec-x->tv_usec );
//    if (result->tv_usec<0)
//    {
//        result->tv_sec--;
//        result->tv_usec+=1000000;
//    }
//    qDebug() << "result->tv_sec"<<result->tv_sec<<"result->tv_usec"<<result->tv_usec;
//    return 0;
// }


void w_Test::Test_CiXiMingHua() {
    if (Ini_IO_Model == Ciximinghua) {
        qDebug() << "Test_CiXiMingHua~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|---->";//
        qDebug() << Test.Finshed_Count << Conf_Item[Test.Finshed_Count].toInt();
    } else {
        return;
    }


}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.1.27
  * brief:      按钮功能
******************************************************************************/
void w_Test::Test_Start()
{
    // gettimeofday(&start,0);
    qDebug() << "Test_Start()----------------------------->";
    usleep(5000);

    if (Kongshi_Stall) {
        if (Kongshi_Continue_Test) {
            Kongshi_Stall = false;
            Kongshi_Continue_Test = false;
        } else {
            return;
        }
    } else {
        //
    }

    Test.Interrupted = false;
    if (Conf_Item.size() <= Test.Finshed_Count) {
        Ask_Widget->hide();
        label_Waring->hide();

        if ((ui->testTab->rowCount()) > 12) { // -显示出全部
            ui->testTab->verticalScrollBar()->setValue(ui->testTab->rowCount());
        }
        Test.Current_Row = 0;
        Test.Interrupted = false;
        Test.Status_Ing  = Test_Station_Free;
        Test.Next_Finsh_Count = 0;
        Test.Finshed_Count    = 0;
        waveform_all_count    = 0; // -波形数量清0
        waveform_row_count    = 0;
        Signal_Test_to_Main(2, 2); // 波形数量清0
        if (Test_Judge_TotalResult()) { // -判定最终的显示状态(显示,蜂鸣器,LED)
            Test_Beep_State(Beep.NG_Time, "NG");
            Sigtest_Usart_Send(QString("LEDR").toLatin1().data());
            Test_Judge_State("NG");
        } else {
            Test_Beep_State(Beep.OK_Time, "OK");
            Sigtest_Usart_Send(QString("LEDG").toLatin1().data());
            Test_Judge_State("OK");
        }

        strResult.clear();  strJudge.clear(); // -列表(结果,判定)清0
        StrResult_Size = 0; StrJudge_Size = 0;

        CRecrd_Wave = Recrd_Wave; // -记录匝间和反嵌的数目

        if (((Recrd_Wave-1)/3) >= 1) { // -设置上查询使能
           ui->button_up->setEnabled(true);
        } else {
            ui->button_down->setDisabled(true);
        }
        return;
    } else {
        qDebug() << "true";
    }

    Test_CiXiMingHua();
    switch (Conf_Item[Test.Finshed_Count].toInt()) {
    case 1:
        qDebug() << "Test RES" << DCR_Total_Number;
        DCR_Test_Record_Number = 0;
        Test.Next_Finsh_Count++;
        Can_Start_DLR();
        return;
        break;
    case 2:
        qDebug() << "Test OPP" << MAG_Total_Number;
        MAG_Test_Record_Number = 0;
        TaskMagDirnumber = 5;
        Test.Next_Finsh_Count++;
        Can_Start_MAG();
        return;
        break;
    case 3:
        qDebug() << "Test INS" << 1;
        TestIRACW = TestIW_IR;
        IRFinsh = false;
        Can_Start_IR();
        if (Test.Next_Finsh_Count != Test.Finshed_Count) { // 进行相间时的处理
            Test.Next_Finsh_Count--;
        }
        break;
    case 4:
        qDebug() << "Test ACV" << 1;
        TestIRACW = TestIW_ACW;
        IRFinsh =  false;
        Can_Start_ACW();
        if (Test.Next_Finsh_Count != Test.Finshed_Count) { // 进行相间时的处理
            Test.Next_Finsh_Count--;
        }
        break;
    case 5:
        qDebug() << "Test DCV";
        // Can_Start_DCW();
        break;
    case 6:
        qDebug() << "Test ITT" << IMP_Total_Number << ((1 << 1)*65536);
        if (Station_Chose == 0x13) {
            Signal_test_to_Switchover(BDVacuum, 1, 9); //  ((1 << 6)*256)
        } else {
            Signal_test_to_Switchover(BDVacuum, 2, 9); // ((1 << 1)*65536)
        }

        IMP_Test_Record_Number = 0;
        Can_Test_IMP_Parameter();
        Test.Next_Finsh_Count++;
        Can_Start_IMP();
        return;
        break;
    case 7:
        qDebug() << "Test PWR";
        if (Test.Next_Finsh_Count != Test.Finshed_Count) { // -新协议 测试功率启动
            qDebug() << "2";
            Can_Start_PWR(2);
            Test.Next_Finsh_Count--;
        } else {
            qDebug() << "1";
            Can_Start_PWR(1);
        }
        break;
    case 8:
        qDebug() << "Test INDL" << INDL_Total_Number;
        INDL_Test_Record_Number = 0;
        Test.Next_Finsh_Count++;
        Can_Start_INDL();
        return;
        break;
    case 9:
        qDebug() << "Test BLOCK" << 1;
        Can_Start_BLOCK();
        break;
    case 10:
        qDebug() << "Test LVS" << 1;
        Can_Start_LVS();
        break;
    case 11:
        Test.Next_Finsh_Count++;
        Can_Start_BLDCHALL();
        return;
        break;
    case 12:
        Test.Next_Finsh_Count++;
        frame.can_id = 0x2C; //-PG
        frame.can_dlc = 0x01;
        frame.data[0] = 0x00;
        canSend(frame, wTest_Surface); usleep(1000); usleep(1000); usleep(1000);
        Can_Start_LOAD();
        return;
        break;
    case 13:
        Test.Next_Finsh_Count++;   //  位置不可以动
        frame.can_id = 0x2C; //-PG
        frame.can_dlc = 0x01;
        frame.data[0] = 0x00;
        canSend(frame, wTest_Surface); usleep(1000); usleep(1000); usleep(1000);
        NoLoadFinsh = false;
        Can_Start_NOLOAD();
        return;
        break;
    case 14:
        Test.Next_Finsh_Count++;
        frame.can_id = 0x2C; //-PG
        frame.can_dlc = 0x01;
        frame.data[0] = 0x00;
        canSend(frame, wTest_Surface); usleep(1000); usleep(1000); usleep(1000);
        Can_Start_BEMF();
        return;
        break;
    default: break;
    }
    Test.Next_Finsh_Count++;
    qDebug() << "Test.Next_Finsh_Count" << Test.Next_Finsh_Count;
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      在波形查看MAG的波形
******************************************************************************/
void w_Test::MAG_Check_Button(int i)
{
    wave[i]->Test_Shape = 0;
    for (int k = 0; k < 400; k++) {
        wave[i]->point[k] = WavePoint_strList[CRecrd_Wave/3*3+  i][k + 6].toInt();
        wave[i]->pointgreen[k] = 260;
    }
    wave[i]->num = 400;
    wave[i]->update();
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      在波形查看IMP的波形
******************************************************************************/
void w_Test::IMP_Check_Button(int i)
{
    wave[i]->Test_Shape = 1;
    wave[i]->Test_IMP_PP = WavePoint_strList[CRecrd_Wave/3*3 + i][3].toInt();
    for (int k = 0; k < 400; k++) {
        wave[i]->point[k] = WavePoint_strList[CRecrd_Wave/3*3 + i][k + 406].toInt();
        wave[i]->pointgreen[k] = WavePoint_strList[CRecrd_Wave/3*3 + i][k + 6].toInt()/4;
    }
    wave[i]->num = 400;
    wave[i]->update();
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      在波形查看PG的波形
******************************************************************************/
void w_Test::PG_Check_Button(int i)
{
    wave[i]->Test_Shape = 0;
    for (int k = 0; k < 400; k++) {
        wave[i]->point[k] = 260;
        wave[i]->pointgreen[k] = WavePoint_strList[CRecrd_Wave/3*3 + i][k + 6].toInt();
    }
    wave[i]->num = 400;
    wave[i]->update();
}

void w_Test::FG_Check_Button(int i)
{
    qDebug() << "FG_Check_Button" << CRecrd_Wave << (CRecrd_Wave/3*3 + i);
    wave[i]->Test_Shape = 0;
    for (int k = 0; k < 400; k++) {
        wave[i]->point[k] = 260;
        wave[i]->pointgreen[k] = WavePoint_strList[CRecrd_Wave/3*3 + i][k + 6].toInt();
    }
    wave[i]->num = 400;
    wave[i]->update();
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.3.17
  * brief:      按钮上查询功能
******************************************************************************/
void w_Test::on_button_up_clicked()
{
    int i = 0, j = 0;
    qDebug() << "on_button_up_clicked";
    if (!(ui->button_up->isEnabled())) {
        return;
    }

    ui->button_up->setDisabled(true);
    for (i = 0; i < strTest.size(); i++) { // -测试序号
        for (j = 0; j < 5; j++) {
            ui->testTab->item(i, j)->setBackgroundColor(QColor(25, 25, 25));
        }
    }

    if ((CRecrd_Wave/3) != 0) {
        CRecrd_Wave = CRecrd_Wave - 3;
        if (((CRecrd_Wave%3) == 0) && (Recrd_Wave == (CRecrd_Wave + 3))) {
            CRecrd_Wave = CRecrd_Wave - 3;
        }
        wave[0]->num = 0;    wave[0]->Test_Shape = 0;
        wave[0]->update();
        wave[1]->num = 0;    wave[1]->Test_Shape = 0;
        wave[1]->update();
        wave[2]->num = 0;    wave[2]->Test_Shape = 0;
        wave[2]->update();

        for (i = 0; i < 3; i++) {
            if ((WavePoint_strList[(CRecrd_Wave)/3*3 + i].isEmpty())) {
                continue;
            }

            ChangeLable(i, (CRecrd_Wave)/3*3 + i);
            for (j = 0; j < 5; j++) {
                ui->testTab->item(WavePoint_strList[CRecrd_Wave/3*3 + i][2].toInt(), j) \
                        ->setBackgroundColor(QColor(44, 76, 84));
            }
            if (WavePoint_strList[CRecrd_Wave/3*3 + i][2].toInt() >= 12) {
                ui->testTab->verticalScrollBar()->setValue \
                        (WavePoint_strList[CRecrd_Wave/3*3 + i][2].toInt());
            } else {
                ui->testTab->verticalScrollBar()->setValue(0);
            }

            if (WavePoint_strList[(CRecrd_Wave)/3*3 + i][0].toInt() == 1) {     // -反嵌
                MAG_Check_Button(i);
            } else if (WavePoint_strList[(CRecrd_Wave)/3*3 + i][0].toInt() == 2) { // -匝间
                IMP_Check_Button(i);
            } else if (WavePoint_strList[(CRecrd_Wave)/3*3 + i][0].toInt() == 3) { // -PG
                PG_Check_Button(i);
            } else if (WavePoint_strList[(CRecrd_Wave)/3*3 + i][0].toInt() == 4) { // -FG
                FG_Check_Button(i);
            } else {
                //
            }
        }
        ui->button_down->setEnabled(true);
    }
    if ((CRecrd_Wave/3) == 0) {
        ui->button_up->setDisabled(true);
    } else {
        ui->button_up->setEnabled(true);
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.3.17
  * brief:      按钮下查询功能
******************************************************************************/
void w_Test::on_button_down_clicked()
{
    int i = 0, j = 0;
    qDebug() << "on_button_down_clicked";
    if (!(ui->button_down->isEnabled())) {
        return;
    }

    ui->button_down->setDisabled(true);
    CRecrd_Wave = CRecrd_Wave + 3;
    for (i = 0; i < 3; i++) {
        wave[i]->Test_Shape = 0;
        wave[i]->num = 0;
        wave[i]->update();
    }
    for (i = 0; i < strTest.size(); i++) { // -测试序号
        for (j = 0; j < 5; j++) {
            ui->testTab->item(i, j)->setBackgroundColor(QColor(25, 25, 25));
        }
    }

    if ((CRecrd_Wave) <= Recrd_Wave) {
        for (i = 0; i < 3; i++) {
            if (((CRecrd_Wave)/3*3 + i)<  Recrd_Wave) {
                if ((WavePoint_strList[(CRecrd_Wave)/3*3 + i].isEmpty())) {
                    continue;
                }

                ChangeLable(i, CRecrd_Wave/3*3 + i);
                for (j = 0; j < 5; j++) {
                    qDebug() << WavePoint_strList[CRecrd_Wave/3*3 + i][2].toInt();
                    ui->testTab->item(WavePoint_strList[CRecrd_Wave/3*3 + i][2].toInt(), j) \
                            ->setBackgroundColor(QColor(44, 76, 84));
                }

                if (WavePoint_strList[CRecrd_Wave/3*3+i][2].toInt() >= 12) {
                    ui->testTab->verticalScrollBar()->setValue\
                            (WavePoint_strList[CRecrd_Wave/3*3 + i][2].toInt());
                } else {
                    ui->testTab->verticalScrollBar()->setValue(0);
                }
                if (WavePoint_strList[CRecrd_Wave/3*3 + i][0].toInt() == 1) {     // -反嵌
                    MAG_Check_Button(i);
                } else if (WavePoint_strList[CRecrd_Wave/3*3 + i][0].toInt() == 2) {  // -匝间
                    IMP_Check_Button(i);
                } else if (WavePoint_strList[(CRecrd_Wave)/3*3 + i][0].toInt() == 3) { // -PG
                    PG_Check_Button(i);
                } else if (WavePoint_strList[(CRecrd_Wave)/3*3 + i][0].toInt() == 4) { // -FG
                    FG_Check_Button(i);
                } else {
                    //
                }
            }
        }
        ui->button_up->setEnabled(true);
    }

    if (CRecrd_Wave%3 == 0) {
        if ((CRecrd_Wave+3) == Recrd_Wave) {
            CRecrd_Wave = CRecrd_Wave + 3;
        }
    }
    if (((CRecrd_Wave) >= Recrd_Wave)) {
        ui->button_down->setDisabled(true);
    } else {
        ui->button_down->setEnabled(true);
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      通过按键板进行波形的上查看和下查看
******************************************************************************/
void w_Test::Test_Usart_Clicked(QString String)
{
    if (String == "Up") {
        if (record_wave_row > 0) {
            record_wave_row--;
            on_testTab_cellClicked(record_wave_row, 1);
        }
    } else if (String == "Down") {
        record_wave_row++;
        on_testTab_cellClicked(record_wave_row, 1);
    } else if (String == "Point") {
        on_testTab_cellClicked(0, 1);
    } else {
        //
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.3.17
  * brief:      定位标号
******************************************************************************/
void w_Test::on_testTab_cellClicked(int row,  int column)
{
    int i = 0, j = 0;
    record_wave_row = row;  i = column;
    for (i = 0; i < strTest.size(); i++) { // -测试清空
        for (j = 0; j < 5; j++) {
            ui->testTab->item(i, j)->setBackgroundColor(QColor(25, 25, 25));
        }
    }
    if (row < strTest.size()) {          // -设置背景
        for (j = 0; j < 5; j++)  {
            ui->testTab->item(row, j)->setBackgroundColor(QColor(44, 76, 84));
        }
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.3.17
  * brief:      上下查詢顯示
******************************************************************************/
void w_Test::ChangeLable(int Lable, int number)
{
    QString str;
    int i = 0;
    str.clear();
    if (WavePoint_strList[number][0].toInt() == 1) {
        str += QString(tr("反嵌"));
        str += strOPP.at(WavePoint_strList[number][1].toInt()*820);
        str += "-";
        str += strOPP.at(WavePoint_strList[number][1].toInt()*820+1);
    } else if (WavePoint_strList[number][0].toInt() == 2) {
        str += QString(tr("匝间"));
        str += strITT.at(WavePoint_strList[number][1].toInt()*820);
        str += "-";
        str += strITT.at(WavePoint_strList[number][1].toInt()*820+1);
    } else if (WavePoint_strList[number][0].toInt() == 3) { // -PG波形
        str += QString(tr("PG"));
        QStringList list;
        list << "123" << "124" << "125" << "126" << "127" << "128";
        str += list.at(WavePoint_strList[number][1].toInt());
    } else if (WavePoint_strList[number][0].toInt() == 4) { // -PG波形
        str += WavePoint_strList[number][1];
    } else {
        //
    }

    if (Lable == 0) {
        for (i = 0; i < 3; i++) {
            wave_name[i]->setText(tr("测试项")); // -清空测试项
        }
    }
    wave_name[Lable]->setText(str); // -清空测试项
    str.clear();
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.4.26
  * brief:      更新测试界面 和 测试数据
******************************************************************************/
void w_Test::Test_Ready()
{
    qDebug() << "Test_Ready()--------------------->";
    int i = 0, j = 0;
    lable_stop->hide();
    strResult.clear();   strJudge.clear(); // -(结果列表, 判定列表) 清0
    StrResult_Size = 0;  StrJudge_Size = 0;

    Test.Current_Row = 0;
    Test.Interrupted = false;
    Test.Judge_NG    = false;
    Test.Next_Finsh_Count = 0;
    Test.Finshed_Count    = 0;
    waveform_all_count    = 0; // -波形数量清0
    waveform_row_count    = 0;
    Signal_Test_to_Main(2, 2); // 波形数量清0
    CRecrd_Wave = Recrd_Wave;    // -记录匝间和反嵌的数目

    ui->button_up->setDisabled(true);   // -上查询按键使能
    ui->button_down->setDisabled(true); // -下查询按键使能

    for (i = 0; i < 50; i++) {
        WavePoint_strList[i].clear();
    }

    TaskMagDirstrList[0].clear();
    TaskMagDirstrList[1].clear();
    TaskMagDirstrList[2].clear();

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 400; j++) {
            wave[i]->point[j] = 0;
            wave[i]->pointgreen[j] = 0;
        }
        wave[i]->num = 400;
        wave[i]->Test_Shape = 0;
        wave[i]->update();
        wave_name[i]->setText(tr("测试项")); // -清空测试项
    }

    ui->testTab->setRowCount(0);
    if (strTest.size() <= 12) {
        ui->testTab->setRowCount(12);
    } else {
        ui->testTab->setRowCount(strTest.size());
    }

    for (i = 0; i < strTest.size(); i++) {
        QTableWidgetItem *pItem = new QTableWidgetItem(QString::number(i+1));
        pItem->setTextAlignment(Qt::AlignCenter);
        ui->testTab->setItem(i, 0, pItem);
    }
    for (i = 0; i < strTest.size(); i++) {
        QTableWidgetItem *pItem = new QTableWidgetItem(strTest.at(i));
        pItem->setTextAlignment(Qt::AlignCenter);
        ui->testTab->setItem(i, 1, pItem);
    }
    for (i = 0; i < strParam.size(); i++) {
        QTableWidgetItem *pItem = new QTableWidgetItem(strParam.at(i));
        pItem->setTextAlignment(Qt::AlignCenter);
        ui->testTab->setItem(i, 2, pItem);
    }
    for (i = 0; i < strTest.size(); i++) {
        QTableWidgetItem *pItem = new QTableWidgetItem("");
        pItem->setTextAlignment(Qt::AlignCenter);
        ui->testTab->setItem(i, 3, pItem);
    }
    for (i = 0; i < strTest.size(); i++) {
        QTableWidgetItem *pItem = new QTableWidgetItem("");
        pItem->setTextAlignment(Qt::AlignCenter);
        ui->testTab->setItem(i, 4, pItem);
    }
    if (Test.serial_number == "") { // -设置编号信息
        ui->label_number->setText(tr("编号:") + QString::number(Test_Count));
    } else {
        ui->label_number->setText(tr("编号:") + Test.serial_number);
    }
    ui->testTab->verticalScrollBar()->setValue(0);

    for (i = 0; i < strTest.size(); i++) { // -测试参数,是否包含PG,2017.5.20
        if (strTest.at(i).contains(QString(tr("空载")))) {
            ui->testTab->setRowHeight(i,50);
        } else if (strTest.at(i).contains(QString(tr("HALL")))) {
            ui->testTab->setRowHeight(i,50);
        } else {
            //
        }
    }

    ui->label_station->setStyleSheet("color: rgb(255, 255, 255);"\
                                     "border: none;font:Bold 40pt Ubuntu ;");
    qDebug() << "Station_Chose" << Station_Chose;
    if (Station_Chose == 0x13) {
        if (Ini_LR == 2) {
            ui->label_station->setText(tr("右"));
        } else {
            ui->label_station->setText(tr("左"));
        }
    } else {
        if (Ini_LR == 2) {
            ui->label_station->setText(tr("左"));
        } else {
            ui->label_station->setText(tr("右"));
        }
    }
    ui->label_station->setStyleSheet("color: rgb(255, 255, 255);"\
                                     "border: none;font: Bold 40pt Ubuntu  ;");
    Test_Judge_State("");
    IR_Test_Count = 0;  // -绝缘测试数目清0
    ACW_Test_Count = 0; // -交耐测试数目清0
    FG_Test_Count = 0;
    FG_Shape_Count = 0;
    PG_Result_List.clear();
}

void w_Test::Modification_Soft_Askoll(int Askoll_Station) {
    if (Askoll_Station != Last_Station) { // 升级阿斯科
        Last_Station = Askoll_Station;
    } else {
        Last_Station = Askoll_Station;
        QMessageBox Quick_Set_Ask;
        Quick_Set_Ask.setWindowFlags(Qt::FramelessWindowHint);
        Quick_Set_Ask.setStyleSheet("QMessageBox{border:3px groove gray;}"\
                                    "background-color: rgb(209, 209, 157);");
        Quick_Set_Ask.setText(tr("       重复进行当前工位的测试吗？     \n          "));
        Quick_Set_Ask.addButton(QMessageBox::Ok)->setStyleSheet\
                ("border:none;height:30px;width:65px;border:5px groove gray;"\
                 "border-radius:10px;padding:2px 4px;");
        Quick_Set_Ask.addButton(QMessageBox::Cancel)->setStyleSheet\
                ("border:none;height:30px;width:65px;border:5px groove gray;"\
                 "border-radius:10px;padding:2px 4px;");
        Quick_Set_Ask.setButtonText(QMessageBox::Ok, QString(tr("确 定")));
        Quick_Set_Ask.setButtonText(QMessageBox::Cancel, QString(tr("取 消")));
        Quick_Set_Ask.setIcon(QMessageBox::Warning);
        int ret = Quick_Set_Ask.exec();
        if (ret  == QMessageBox::Ok) {
            //
        }
        if (ret ==QMessageBox::Cancel) {
            return;
        }
    }
}

void w_Test::Test_Process() {
    int i = 0;
    Error_Mount = 0;
 // Modification_Soft_Askoll(Station);
    Start_Time.clear();
    rtc_time rtc_t; // -得到时分秒-数据 进行更新秒数据
    rtc_t = rtc.get_rtc();
    Start_Time.append(QString::number(rtc_t.tm_hour) + ":" + \
                      QString::number(rtc_t.tm_min) + ":" + QString::number(rtc_t.tm_sec));
    Test.Status_Ing = Test_Station_Busy;
    if (ui->label_number->text() == tr("编号:")) {
        ui->label_number->setText(tr("编号:") + "16888");
    }
    Test_IMP_Ready = false;
    Test_ACW_Ready = false;
    Vacuum_Ready = false;
    Test_MAG_Ready = false;
    MAG_Drive = false;
    NetTest_Ready_DLR = false;
    NetTest_Ready_MAG = false;
    NetTest_Ready_IR  = false;
    NetTest_Ready_ACW = false;
    NetTest_Ready_IMP = false;
    NetTest_Ready_IND = false;
    NetTest_Resdy_HALL = false;
    NetTest_Resdy_LOAD = false;
    NetTest_Resdy_NOLOAD = false;
    NetTest_Resdy_BEMF = false;

    Shape_Hall_A.clear();
    Shape_Hall_B.clear();
    Shape_Hall_C.clear();

    Sigtest_Usart_Send(QString("LEDY").toLatin1().data());
    Sigtest_Usart_Send(QString("LEDY").toLatin1().data()); // 运行状态指示灯 黄灯
    Signal_test_to_Switchover(ZhongTe, (1<<7), 1);
    Test_Count++;
    Histogram_List.at(0)->setText(QString::number(Test_Count));
    for (i = 0; i < 14; i++) {
        Error_Item_Count[i] = 0;
    }
    Ask_Widget->hide();
    // 开始测试前进行接地的测试保护 2017.5.19
    if (Ini_NineBoard == 2) { // -开始测试前进行接地的测试保护 2017.5.19
        frame.can_id  = 0x2A; // -功放板发送
        frame.can_dlc = 0x01;
        frame.data[0] = 0x00;
        canSend(frame,  wTest_Surface);
        usleep(1000);
    }

    Kongshi_Stall = false;
    Kongshi_Continue_Test = false;
    Kongshi_Stall_Time = 0;


    Test.NG_Item = 0;
    Test_Ready();
    Test_Start(); // 清空后，开始测试

    if ((Ini_IO_Model==Noise)&&(Test_noise_enabled)&&(Noise_CW_Time!=0)) { //
        qDebug() << "noise";
        Signal_test_to_Switchover(Noise,Station_Chose - 0x13 + 1 + 8,7); // 切换进入反向测试
        Noise_step = 0;
        Noise_Stop->setSingleShot(TRUE);
        Noise_Stop->start(Noise_CW_Time*1000); //
        ui->label_noise->show();
    } else {
        //
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.4.26
  * brief:      测试启动
******************************************************************************/
void w_Test::join_test_start(int Model, int Station)
{
    qDebug() << "Model" << Model;
    qDebug() << "Station" << Station;
    if ((!(Test_GND_Volt/1000)) && (Ini_NineBoard == 2)) {
        lable_GND_Volt->show();
        lable_GND_Volt->setText(Test_GND_Volt_List.join(","));
        Test_WMessage(4, QString::number(Test_GND_Volt%1000));
        return;
    } else {
        lable_GND_Volt->hide();
    }
    qDebug() << "1";
    if (Start_No) {
        Start_No = false;
        return;
    } else {
        //
    }
    qDebug() << "Test.Status_Ing" << Test.Status_Ing;
    if (Test.Status_Ing == Test_Station_Ask) {
        if ((Station_Chose == 0x13) || (Station_Chose == 0x14)) {
            Station_Chose = Station_Chose;
        } else {
            Station_Chose = Station; // -提供给全局变量
        }
    } else if (Test.Status_Ing == Test_Station_Busy) {
        return;
    } else {
        Station_Chose = Station; // -提供给全局变量
    }

    if (AMP_Conneted) {

    } else {
        Ask_Up_label->setAlignment(Qt::AlignCenter);
        Ask_Up_label->setText(tr("Inter Lock\n断开\n停止启动"));
        Ask_Widget->show();
        return;
    }

    if (Test.Status_Ing == Test_Station_Ask) {
        Test.Status_Ing = Test_Station_Busy;
        Ask_Widget->hide();
        label_Waring->hide();
        Sigtest_Usart_Send(QString("LEDY").toLatin1().data()); // -运行状态指示灯-黄灯
        Test_Start();
    } else if (START_Model == Model) {
        if (((Ini_Stagnate == 0) && ((START_Model == 2) || (START_Model==1)))) { // -在滑罩模式下,取消防呆
            if (ui->label_6->text() == "NG") {
                ui->label_6->setText("");
                return;
            } else {
                //
            }
        } else {
            //
        }
        qDebug() << "2";
        if (strTest.isEmpty()) {
            return;
        }
        qDebug() << "3";
        if (Vacuum_pump_Close) {
            Vacuum_pump_Close = false;
            if ((Test_Model_Vacuum) || (Test_Model_Vacuum_ACW)) {
                Signal_test_to_pic(QStringList(""), 1, 12); // 打开真空泵
            } else {
                //
            }
        } else {
            //
        }
        if (Ini_IO_Test) { // 启动信号启动
            IO_Test_Readying = true;
            if (Ini_IO_Model == BenDuo) { //

            } else if (Ini_IO_Model == KaiYu) { //
                Signal_test_to_Switchover(KaiYu, 0x03, 6);
            } else if (Ini_IO_Model == Bosch) { //
                Signal_test_to_Switchover(Bosch, 0x01, 7);
            }  else if (Ini_IO_Model == BenDuoTWO) { //
                TTT();
            } else {
                //
            }
        }
        else if(Ini_IO_Delay) { // 延时启动
            IO_Test_Readying = true;
            IO_Delay_Start->setSingleShot(TRUE);
            IO_Delay_Start->start(Ini_IO_Delay_Time); // 启动定时器,记录定时器启动计时
            if (Ini_IO_Model == LvZhi) { //
                Signal_test_to_Switchover(LvZhi, Station_Chose, 2);
            } else if (Ini_IO_Model==BePuDa) { //
                Signal_test_to_Switchover(BePuDa,Station_Chose,12);
            } else {
                //
            }
        }
        else {
//          frame.can_id  = 0x2D;  frame.can_dlc = 0x01;
//          frame.data[0] = 0x11;
//          canSend(frame,wTest_Surface);
//          usleep(600);
            Test_Process(); // 清空后，开始测试
        }
    } else {
        if (Test_Waring_Flag) {
            return;
        }
        if (ui->label_6->text() != tr("NG")) {
            qDebug() << "Test.Status_Ing" << Test.Status_Ing;
            Test_WMessage(5, QString(tr("")));
        }
    }
}

void w_Test::TTT() {
    if ((Station_Chose == 0x13) && (BenDuo_L)) {
        Test_Process(); // 清空后，开始测试
    } else if ((Station_Chose == 0x14) && (BenDuo_R)) {
        Test_Process(); // 清空后，开始测试
    } else {

    }
}

bool w_Test::parameter_Issue_ing() {
    int i;
    Test.Interrupted = true;
    if (DLR_Issue_Ing) {
        DLR_Issue_Ing = false;
        for (i = 0; i < DCR_Total_Number; i++) {
            join_updatedata(QStringList(""));
        }
        qDebug() << "Test 2017-12-20------> DLR_Issue_Ing Stop Update";
        return false;
    } else if (MAG_Issue_Ing) {
        MAG_Issue_Ing = false;
        for (i = 0; i < MAG_Total_Number; i++) {
            join_updatedata(QStringList(""));
        }
        qDebug() << "Test 2017-12-20------> MAG_Issue_Ing Stop Update";
        return false;
    } else if (IR_Issue_Ing) {
        IR_Issue_Ing = false;
        IRFinsh = true;
        for (i = 0; i < 1; i++) {
            join_updatedata(QStringList(""));
        }
        qDebug() << "Test 2017-12-20------> IR_Issue_Ing Stop Update";
        return false;
    } else if (ACW_Issue_Ing) {
        IRFinsh = true;
        ACW_Issue_Ing = false;
        for (i = 0; i < 1; i++) {
            join_updatedata(QStringList(""));
        }
        qDebug() << "Test 2017-12-20------> ACW_Issue_Ing Stop Update";
        return false;
    } else if (IMP_Issue_Ing) {
        IMP_Issue_Ing = false;
        for (i = 0; i < IMP_Total_Number; i++) {
            join_updatedata(QStringList(""));
        }
        qDebug() << "Test 2017-12-20------> IMP_Issue_Ing Stop Update";
        return false;
    } else if (IND_Issue_Ing) {
        IND_Issue_Ing = false;
        for (i = 0; i < INDL_Total_Number; i++) {
            join_updatedata(QStringList(""));
        }
        qDebug() << "Test 2017-12-20------> IND_Issue_Ing Stop Update";
        return false;
    } else if (HALL_Issue_Ing)   {
        HALL_Issue_Ing = false;
        join_updatedata(Hall_Update);
        qDebug() << "Test 2017-12-20------> HALL_Issue_Ing Stop Update";
        return false;
    } else if (LOAD_Issue_Ing)   {
        LOAD_Issue_Ing = false;
        join_updatedata(QStringList(""));
        qDebug() << "Test 2017-12-20------> LOAD_Issue_Ing Stop Update";
        return false;
    } else if (NOLOAD_Issue_Ing) {
        NOLOAD_Issue_Ing = false;
        join_updatedata(QStringList(""));
        qDebug() << "Test 2017-12-20------> NOLOAD_Issue_Ing Stop Update";
        return false;
    } else if (BEMF_Issue_Ing)   {
        BEMF_Issue_Ing = false;
        join_updatedata(QStringList(""));
        qDebug() << "Test 2017-12-20------> BEMF_Issue_Ing Stop Update";
        return false;
    } else {
        //
    }
    return true;
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.3.23
  * brief:      测试停止时，进入遇不合格（继续）
******************************************************************************/
void w_Test::join_test_occur_unqualified_Continue(int Stop)
{
    qDebug() << "----------Test_NG_Continue----------" << "--Stop--" << \
                Stop << "测试状态" << Test.Status_Ing;
    if (Conf_Item.size() == 0) {
        return;
    }
    switch (Stop) {
    case 1: // 串口
        qDebug() << "Test.Finshed_Count" << Test.Finshed_Count << "Conf_Item.size()" \
                 << Conf_Item.size() << "Error_Mount" << Error_Mount;
        if ((Test.Finshed_Count < (Conf_Item.size())) && \
                (Test.Status_Ing == Test_Station_Busy) && \
                (Error_Mount <= 3)) { //  判断是否超限 和 测试测试中
            qDebug() << "Usart if";
            Error_Mount++;
            Can_Stop(Back_board_ID[Conf_Item[Test.Finshed_Count].toInt()]);
            PWR_Par_Widget->hide();
            Test.Interrupted = true;
        } else {
            qDebug() << "Usart else";
            Can_Stop(0x22); Can_Stop(0x23); Can_Stop(0x24); Can_Stop(0x27);  Can_Stop(0x29);
            Error_Mount = 0;
            Test.Status_Ing = Test_Station_Free;
            Sigtest_Usart_Send(QString("LED1").toLatin1().data());
            Test_Judge_State("");
            ui->label_station->setStyleSheet("color: rgb(255, 255, 255);" \
                                             "border: none;font:Bold 40pt Ubuntu;");
            Test_Ready();
            label_Waring->hide();
        }
        break;
    case 2: // 滑罩 脚踏
        if ((Test.Finshed_Count < (Conf_Item.size())) && \
                (Test.Status_Ing == Test_Station_Busy) && \
                (Error_Mount <= 10)) { //  判断是否超限 和 测试测试中
            Error_Mount++;
            Can_Stop(Back_board_ID[Conf_Item[Test.Finshed_Count].toInt()]);
            PWR_Par_Widget->hide();
            Test.Interrupted = true;
        } else {
            Can_Stop(0x22); Can_Stop(0x23); Can_Stop(0x24); Can_Stop(0x27);
            Error_Mount = 0;
            if ((Test.Status_Ing == Test_Station_Inte) || \
                    (ui->label_6->text() != "NG")) { //
                Test.Status_Ing = Test_Station_Free;
                /*Sigtest_Usart_Send(QString("LED1").toLatin1().data());
                Test_Judge_State("");
                ui->label_station->setStyleSheet("color: rgb(255, 255, 255);border: none;font:Bold 40pt Ubuntu;");
                Test_Ready();*/
                lable_stop->hide();
            } else {
                Test.Status_Ing = Test_Station_Inte;
            }
            label_Waring->hide();
            if (START_Model == 1) { //  脚踏时去掉
                Test.Status_Ing = Test_Station_Free;
                Sigtest_Usart_Send(QString("LED1").toLatin1().data());
                Test_Judge_State("");
                ui->label_station->setStyleSheet("color: rgb(255, 255, 255);"\
                                                 "border: none;font:Bold 40pt Ubuntu;");
                Test_Ready();
                lable_stop->hide();
            } else {
                //
            }
        }
        break;
    case 3:
        qDebug() << "NG STOP";
        if ((Test.Finshed_Count < (Conf_Item.size())) && \
                (Test.Status_Ing == Test_Station_Busy)) {
            Can_Stop(Back_board_ID[Conf_Item[Test.Finshed_Count].toInt()]);
            PWR_Par_Widget->hide();
        } else {
            Ask_Widget->hide();
            label_Waring->hide();
            if ((ui->testTab->rowCount()) > 12) { // 显示出全部
                ui->testTab->verticalScrollBar()->setValue(ui->testTab->rowCount());
            }
            Test.Current_Row = 0;
            Test.Interrupted = false;
            Test.Status_Ing  = Test_Station_Free;
            Test.Next_Finsh_Count = 0;
            Test.Finshed_Count = 0;
            waveform_all_count = 0; // -波形数量清0
            waveform_row_count = 0;

            strResult.clear();  strJudge.clear(); // 列表（结果 判定）清0
            StrResult_Size = 0; StrJudge_Size = 0;

            CRecrd_Wave = Recrd_Wave;   // 记录匝间和反嵌的数目

            if (((Recrd_Wave-1)/3) >= 1) { // 设置上查询使能
               ui->button_up->setEnabled(true);
            } else {
                ui->button_down->setDisabled(true);
            }
            qDebug() << "Test All Ok";
        }
        if (Test_Judge_TotalResult()) { // 判定最终的显示状态  （显示  蜂鸣器 LED）
            Test_Beep_State(Beep.NG_Time, "NG");
            Sigtest_Usart_Send(QString("LEDR").toLatin1().data());
            Sigtest_Usart_Send(QString("LEDR").toLatin1().data());
            Test_Judge_State("NG");
        } else {
            Test_Beep_State(Beep.OK_Time, "OK");
            Sigtest_Usart_Send(QString("LEDG").toLatin1().data());
            Sigtest_Usart_Send(QString("LEDG").toLatin1().data());
            Test_Judge_State("OK");
        }
//        Test_Beep_State(Beep.NG_Time,"NG");
//        Sigtest_Usart_Send(QString("LEDR").toLatin1().data());
//        Test_Judge_State("NG");
        Test.Status_Ing = Test_Station_Inte;
        label_Waring->hide();
        break;
    default:
        //
        break;
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.3.23
  * brief:      测试停止时，进入遇不合格（停止）
******************************************************************************/
void w_Test::join_test_occur_unqualified_Stop(int Stop)
{
    qDebug() << "----------Test_NG_Stop----------" << "--Stop--" << Stop \
             << "test state" << Test.Status_Ing;
    if (Conf_Item.size() == 0) {
        return;
    }
    switch (Stop) {
    case 1: // 串口
        if ((Test.Finshed_Count < (Conf_Item.size())) && \
                (Test.Status_Ing == Test_Station_Busy) && \
                (Error_Mount <= 3)) { // 判断是否超限 和 测试测试中
            Error_Mount++;
            Can_Stop(Back_board_ID[Conf_Item[Test.Finshed_Count].toInt()]);
            PWR_Par_Widget->hide();
            Test.Interrupted = true;
        } else {
            Can_Stop(0x22); Can_Stop(0x23); Can_Stop(0x24); Can_Stop(0x27);  Can_Stop(0x29);
            Error_Mount = 0;
            Test.Status_Ing = Test_Station_Free;
            Sigtest_Usart_Send(QString("LED1").toLatin1().data());
            Test_Judge_State("");
            ui->label_station->setStyleSheet("color: rgb(255, 255, 255);"\
                                             "border: none;font:Bold 40pt Ubuntu;");
            Test_Ready();
            label_Waring->hide();
        }
        break;
    case 2: // 滑罩 脚踏
        if ((Test.Finshed_Count < (Conf_Item.size())) && \
                (Test.Status_Ing == Test_Station_Busy) && \
                (Error_Mount <= 10)) { //  判断是否超限 和 测试测试中
            Error_Mount++;
            Can_Stop(Back_board_ID[Conf_Item[Test.Finshed_Count].toInt()]);
            PWR_Par_Widget->hide();
            Test.Interrupted = true;
        } else {
            Can_Stop(0x22); Can_Stop(0x23); Can_Stop(0x24); Can_Stop(0x27);  Can_Stop(0x29);
            Error_Mount = 0;
            qDebug() << "----------enture state--------" << ui->label_6->text() << Test.Status_Ing;
            if ((Test.Status_Ing == Test_Station_Inte) || \
                    (ui->label_6->text() != "NG")) {
                // (ui->label_6->text() == "OK") 2017-6-29 修改不能进入测试
                Test.Status_Ing = Test_Station_Free;
                /*Sigtest_Usart_Send(QString("LED1").toLatin1().data());
                Test_Judge_State("");
                ui->label_station->setStyleSheet("color: rgb(255, 255, 255);border: none;font:Bold 40pt Ubuntu;");
                Test_Ready();*/
                lable_stop->hide();
            } else {
                Test.Status_Ing = Test_Station_Inte;
            }
            label_Waring->hide();
            if (START_Model == 1) { //  脚踏时去掉
                Test.Status_Ing = Test_Station_Free;
                Sigtest_Usart_Send(QString("LED1").toLatin1().data());
                Test_Judge_State("");
                ui->label_station->setStyleSheet("color: rgb(255, 255, 255);"\
                                                 "border: none;font:Bold 40pt Ubuntu;");
                Test_Ready();
                lable_stop->hide();
            } else {
                //
            }
        }
        break;
    case 3:
        qDebug() << "NG STOP";
        if ((Test.Finshed_Count < (Conf_Item.size())) && \
                (Test.Status_Ing == Test_Station_Busy)) {
            Can_Stop(Back_board_ID[Conf_Item[Test.Finshed_Count].toInt()]);
            PWR_Par_Widget->hide();
        } else {
            //
        }
        if (Test_Judge_TotalResult()) { // 判定最终的显示状态  （显示  蜂鸣器 LED）
            Test_Beep_State(Beep.NG_Time, "NG");
            Sigtest_Usart_Send(QString("LEDR").toLatin1().data());
            Sigtest_Usart_Send(QString("LEDR").toLatin1().data());
            Test_Judge_State("NG");
        } else {
            Test_Beep_State(Beep.OK_Time, "OK");
            Sigtest_Usart_Send(QString("LEDG").toLatin1().data());
            Sigtest_Usart_Send(QString("LEDG").toLatin1().data());
            Test_Judge_State("OK");
        }
//      Test_Beep_State(Beep.NG_Time,"NG");
//      Sigtest_Usart_Send(QString("LEDR").toLatin1().data());
//      Test_Judge_State("NG");
        Test.Status_Ing = Test_Station_Inte;
        label_Waring->hide();
        break;
    default:
        //
        break;
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.3.23
  * brief:      测试停止时，进入遇不合格（询问）
******************************************************************************/
void w_Test::join_test_occur_unqualified_Ask(int Stop)
{
    qDebug() << "----------Test_NG_Ask----------" << "--Stop--" << Stop \
             << "test state" << Test.Status_Ing;
    if (Conf_Item.size() == 0) {
        return;
    }
    switch (Stop) {
    case 1: // 串口
        if ((Test.Finshed_Count < (Conf_Item.size())) && \
                ((Test.Status_Ing == Test_Station_Busy) || \
                 (Test.Status_Ing == Test_Station_Ask)) && \
                (Error_Mount <= 3)) { //  判断是否超限 和 测试测试中
            Error_Mount++;
            Can_Stop(Back_board_ID[Conf_Item[Test.Finshed_Count].toInt()]);  PWR_Par_Widget->hide();
            Test.Interrupted = true;
            if (Test.Status_Ing == Test_Station_Ask) {
                Ask_Widget->hide();
                label_Waring->hide();
                Test.Status_Ing = Test_Station_Inte;
                join_test_occur_unqualified_Ask(1);
            }
        } else if (Test.Finshed_Count == (Conf_Item.size())) {
            Ask_Widget->hide();
            label_Waring->hide();
            if ((ui->testTab->rowCount()) > 12) { // 显示出全部
                ui->testTab->verticalScrollBar()->setValue(ui->testTab->rowCount());
            }
            Test.Current_Row = 0;
            Test.Interrupted = false;
            Test.Status_Ing  = Test_Station_Free;
            Test.Next_Finsh_Count = 0;
            Test.Finshed_Count = 0;
            waveform_all_count = 0; // -波形数量清0
            waveform_row_count = 0;
            Signal_Test_to_Main(2, 2); // 波形数量清0
            if (Test_Judge_TotalResult()) {  // 判定最终的显示状态  （显示  蜂鸣器 LED）
                Test_Beep_State(Beep.NG_Time, "NG");
                Sigtest_Usart_Send(QString("LEDR").toLatin1().data());
                Test_Judge_State("NG");
            } else {
                Test_Beep_State(Beep.OK_Time, "OK");
                Sigtest_Usart_Send(QString("LEDG").toLatin1().data());
                Test_Judge_State("OK");
            }
            strResult.clear();  strJudge.clear(); // 列表（结果 判定）清0
            StrResult_Size = 0; StrJudge_Size = 0;
            CRecrd_Wave = Recrd_Wave;   // 记录匝间和反嵌的数目
            if (((Recrd_Wave-1)/3) >= 1) { // 设置上查询使能
               ui->button_up->setEnabled(true);
            } else {
               ui->button_down->setDisabled(true);
            }
            qDebug() << "Test All Ok";
        } else {
            Can_Stop(0x22); Can_Stop(0x23); Can_Stop(0x24); Can_Stop(0x27);  Can_Stop(0x29);
            Error_Mount = 0;
            Test.Status_Ing = Test_Station_Free;
            Sigtest_Usart_Send(QString("LED1").toLatin1().data());
            Test_Judge_State("");
            ui->label_station->setStyleSheet("color: rgb(255, 255, 255);"\
                                             "border: none;font:Bold 40pt Ubuntu;");
            Test_Ready();
            Ask_Widget->hide();
            label_Waring->hide();
        }
        break;
    case 2: // 滑罩 启动
        if ((Test.Finshed_Count < (Conf_Item.size())) && \
                ((Test.Status_Ing == Test_Station_Busy) || \
                 (Test.Status_Ing == Test_Station_Ask)) && \
                (Error_Mount <= 10)) { //  判断是否超限 和 测试测试中
            Error_Mount++;
            Can_Stop(Back_board_ID[Conf_Item[Test.Finshed_Count].toInt()]);
            PWR_Par_Widget->hide();
            Test.Interrupted = true;
            if (Test.Status_Ing == Test_Station_Ask) {
                Ask_Widget->hide();
                label_Waring->hide();
                join_test_stop(3);
            }
        } else if (Test.Finshed_Count == (Conf_Item.size())) {
            Ask_Widget->hide();
            label_Waring->hide();
            if (ui->testTab->rowCount() > 12) { // -显示出全部
                ui->testTab->verticalScrollBar()->setValue(ui->testTab->rowCount());
            }
            Test.Current_Row = 0;
            Test.Interrupted = false;
            Test.Status_Ing  = Test_Station_Free;
            Test.Next_Finsh_Count = 0;
            Test.Finshed_Count = 0;
            waveform_all_count = 0; // -波形数量清0
            waveform_row_count = 0;
            Signal_Test_to_Main(2, 2); // 波形数量清0
            if (Test_Judge_TotalResult()) { // -判定最终的显示状态(显示,蜂鸣器,LED)
                Test_Beep_State(Beep.NG_Time, "NG");
                Sigtest_Usart_Send(QString("LEDR").toLatin1().data());
                Test_Judge_State("NG");
            } else {
                Test_Beep_State(Beep.OK_Time, "OK");
                Sigtest_Usart_Send(QString("LEDG").toLatin1().data());
                Test_Judge_State("OK");
            }
            strResult.clear();  strJudge.clear(); // 列表（结果 判定）清0
            StrResult_Size = 0; StrJudge_Size = 0;
            CRecrd_Wave = Recrd_Wave;   // 记录匝间和反嵌的数目
            if (((Recrd_Wave-1)/3) >= 1) { // 设置上查询使能
               ui->button_up->setEnabled(true);
            } else {
               ui->button_down->setDisabled(true);
            }
            qDebug() << "Test All Ok";
        } else {
            Can_Stop(0x22); Can_Stop(0x23); Can_Stop(0x24); Can_Stop(0x27);  Can_Stop(0x29);
            Error_Mount = 0;
            if ((Test.Status_Ing == Test_Station_Inte) || \
                    (ui->label_6->text() != "NG")) {
                // (ui->label_6->text() == "OK") 2017-6-29 修改不能进入测试
                Test.Status_Ing = Test_Station_Free;
               /* Sigtest_Usart_Send(QString("LED1").toLatin1().data());
                Test_Judge_State("");
                ui->label_station->setStyleSheet("color: rgb(255, 255, 255);border: none;font:Bold 40pt Ubuntu;");
                Test_Ready();*/
                lable_stop->hide();
            } else {
                Test.Status_Ing = Test_Station_Inte;
            }
            Ask_Widget->hide();
            label_Waring->hide();
            if (START_Model == 1) { //  脚踏时去掉
                Test.Status_Ing = Test_Station_Free;
                Sigtest_Usart_Send(QString("LED1").toLatin1().data());
                Test_Judge_State("");
                ui->label_station->setStyleSheet("color: rgb(255, 255, 255);"
                                                 "border: none;font:Bold 40pt Ubuntu;");
                Test_Ready();
                lable_stop->hide();
            } else {
                //
            }
        }
        break;
    case 3:
        qDebug() << "NG STOP";
        if ((Test.Finshed_Count < (Conf_Item.size())) && \
                ((Test.Status_Ing == Test_Station_Busy) || \
                 (Test.Status_Ing == Test_Station_Ask))) { // 添加测试状态为 询问 进行测试
            Can_Stop(Back_board_ID[Conf_Item[Test.Finshed_Count].toInt()]);
            PWR_Par_Widget->hide();
            Test_Beep_State(Beep.NG_Time, "NG");
            Sigtest_Usart_Send(QString("LEDR").toLatin1().data());
            Test_Judge_State("NG");
            Test.Status_Ing = Test_Station_Inte;
            label_Waring->hide();
        } else if (Test.Finshed_Count == (Conf_Item.size())) {
            Ask_Widget->hide();
            label_Waring->hide();
            if ((ui->testTab->rowCount()) > 12) { // -显示出全部
                ui->testTab->verticalScrollBar()->setValue(ui->testTab->rowCount());
            }
            Test.Current_Row = 0;
            Test.Interrupted = false;
            Test.Status_Ing  = Test_Station_Free;
            Test.Next_Finsh_Count = 0;
            Test.Finshed_Count = 0;
            waveform_all_count = 0; // -波形数量清0
            waveform_row_count = 0;
            Signal_Test_to_Main(2, 2); // 波形数量清0
            if (Test_Judge_TotalResult()) { // -判定最终的显示状态(显示,蜂鸣器,LED)
                Test_Beep_State(Beep.NG_Time, "NG");
                Sigtest_Usart_Send(QString("LEDR").toLatin1().data());
                Test_Judge_State("NG");
            } else {
                Test_Beep_State(Beep.OK_Time, "OK");
                Sigtest_Usart_Send(QString("LEDG").toLatin1().data());
                Test_Judge_State("OK");
            }
            strResult.clear();  strJudge.clear(); // -列表(结果,判定)清0
            StrResult_Size = 0;  StrJudge_Size = 0;

            CRecrd_Wave = Recrd_Wave;  // -记录匝间和反嵌的数目
            if (((Recrd_Wave-1)/3) >= 1) { // -设置上查询使能
               ui->button_up->setEnabled(true);
            } else {
                ui->button_down->setDisabled(true);
            }
            qDebug() << "Test All Ok";
        } else {
            //
        }
        break;
    default:
        break;
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.4.26
  * brief:      测试停止
******************************************************************************/
void w_Test::join_test_stop(int Stop)
{
    switch (Model_Occur_Unqualified) {
    case Test_NG_Continue: // -0 继续
        join_test_occur_unqualified_Continue(Stop);
        break;
    case Test_NG_Stop:     // -1 停止
        join_test_occur_unqualified_Stop(Stop);
        break;
    case Test_NG_Ask:      // -2 询问
        join_test_occur_unqualified_Ask(Stop);
        break;
    default:
        //
        break;
    }
    Button_Start_Time_Flag = false; //-在自启动时候调用
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.5.31
  * brief:      显示左右工位的状态  “OK”  “NG”  “ ”
******************************************************************************/
void w_Test::Test_Judge_State(QString Show_State)
{
    if (Show_State == "OK") { // Italic 倾斜
        ui->label_6->setStyleSheet("color:rgb(0,255,0);font: Bold  42pt Ubuntu;border: none;");
    } else if (Show_State == "NG") {
        ui->label_6->setStyleSheet("color:rgb(255,0,0);font: Bold  42pt Ubuntu;border: none;");
        ui->frame_state->setStyleSheet("border:1px groove ;"\
                         "background-color: gold;border-radius:8px;border-color: #447684;");
        ui->label_station->setStyleSheet("color: rgb(255, 0, 0);border: none;"\
                                         "font: Bold 40pt Ubuntu  ;");
    } else {
        ui->frame_state->setStyleSheet("border:1px groove ;"\
                         "background-color: #191919;border-radius:8px;border-color: #447684;");
    }
    ui->label_6->text().clear();   ui->label_6->setText(Show_State);
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.5.31
  * brief:      蜂鸣器的报警状态
******************************************************************************/
void w_Test::Test_Beep_State(double time_beep, QString Dis)
{
    int i = 0;
    int k = 0;
    int IO_put = 0; IO_put = 0;
    if (Ini_BLDC_PG) {
        frame.can_id  = 0x2D;  frame.can_dlc = 0x03;
        frame.data[0] = 0xf1;
        frame.data[1] = 0x00;
        frame.data[2] = 0x00;
        frame.data[3] = 0x00;
        canSend(frame, wTest_Surface);   usleep(5000); usleep(5000); usleep(5000);
    } else {
        //
    }
    if (!Beep.Flag) {
        Beep.Flag = true;
        Beep.Time->setSingleShot(TRUE);
        Beep.Time->start(time_beep*1000);
        if (time_beep != 0) {
            Beep_PWM_Start(Beep.Grade);
        }
        Beep.Flag = false;
    } else {
        //
    }
    if (strJudge.size() == strTest.size()) {
        //
    } else {
        for (i = strJudge.size(); i < strTest.size(); i++) {
            strJudge.append("");
            strResult.append("");
        }
    }
    QStringList QStringList_No_OK;
    for (i = 0; i < strTest.size(); i++) {
        if (strJudge[i] == "OK") {
            continue;
        }
        k = 0;
        for (int t = 0; t < Test_Item.size(); t++) {
            if (strTest.at(i).contains(Test_Item.at(t))) {
                k = t;
                break;
            }
        }
        if (strTest.at(i) == (tr("磁旋"))) {
            k = 2;
        } else if (strTest.at(i) == (tr("转向"))) {
            k = 7;
        } else if (strTest.at(i).contains(tr("PG"))) {
            k = 16;
        } else {
            //
        }
        if (k <= 16) {
            Error_Item_Count[k]++;
            if (Error_Item_Count[k] == 1) {
                QStringList_No_OK.append(QString::number(k));
                Error_Item[k]++;
            } else {
                //
            }
        } else {
            //
        }
    } /* */

    for( i = 3; i < Ini_Proj.size() + 2; i++) { // +2  ==-1+3
        if (!(Error_Item_Count[Ini_Proj.at(i - 2).toInt()])) {
            continue;
        }
        switch (Ini_Proj.at(i - 2).toInt()) {
        case 1: // DCR
            IO_put = (1 << 1) | IO_put;
            break;
        case 2: // MAG
            IO_put = (1 << 5) | IO_put;
            break;
        case 3: // IR
            IO_put = (1 << 3) | IO_put;
            break;
        case 4: // ACW
            IO_put = (1 << 0) | IO_put;
            break;
        case 6: // IMP
            IO_put = (1 << 2) | IO_put;
            break;
        case 7: // PWR
            IO_put = ((1 << 3) * 256) | IO_put;
            break;
        case 8: // INDL
            IO_put = (1 << 4) | IO_put;
            break;
        case 9: // BLOCK
            IO_put = ((1 << 7) * 256) | IO_put;
            break;
        case 10: // LVS
            IO_put = ((1 << 2) * 256) | IO_put;
            break;
        default:
            //
            break;
        }
    }
    for (i = 0; i < strTest.size(); i++)
    {
        if (strJudge[i]=="OK") {
            continue;
        } else if(strJudge[i]=="") {
            continue;
        } else {
            //
        }
        k = 0;
        if (strTest.at(i) == tr("磁旋")) {
            IO_put = ((1 << 1)*256) | IO_put;
            k = 2;
        } else if (strTest.at(i) == tr("转向")) {
            IO_put = ((1 << 1)*256) | IO_put;
            k = 7;
        } else if (strTest.at(i).contains(tr("PG"))) {
            IO_put = ((1 << 4)*256) | IO_put;
            k = 11;
        } else {
            //
        }
        if (k == 0) {
            continue;
        }
        qDebug() << "k---Error" << k;
        if (k <= 11) {
            Error_Item_Count[k]++;
            if (Error_Item_Count[k] == 1) {
                Error_Item[k]++;
            }
        } else {
            //
        }
    }
    Signal_test_to_Switchover(NanXin, 18, 5);


    int judge = 0;
    if (Dis == "NG") {
        judge = 0;
        qDebug() << "NG -- 0xb0";
        WriteMessage((6000), 0xb0, QString("NG").toUtf8());
    //  Signal_test_to_Switchover(Bosch, 0x00, 7);
    } else {
        judge = 1;
        qDebug() << "OK -- 0xb0";
        WriteMessage((6000), 0xb0, QString("OK").toUtf8());
        Signal_test_to_Switchover(Bosch, 0x00, 7);
    }
    QStringList Get_Set;
    if (Station_Chose == 0x13) {
        Signal_test_to_pic(QStringList(""), judge, 2); // 左工位测试判定
        if (Ini_LR == 2) {
            Get_Set.append(tr("右工位"));
        } else {
            Get_Set.append(tr("左工位"));
        }
    } else {
        Signal_test_to_pic(QStringList(""), judge, 3); // 右工位测试判定
        if (Ini_LR == 2) {
            Get_Set.append(tr("左工位"));
        } else {
            Get_Set.append(tr("右工位"));
        }
    }
    if (Dis == "NG") {
        IO_put = ((1<<0)*256)|IO_put;
        Get_Set.append("NG");
        Histogram_List.at(2)->setText(QString::number(++Unqualified));
        // -不合格时设置不合格的显示文本
    } else {
        IO_put = IO_put | (1<<6);
        Signal_test_to_Switchover(NanXin, Station_Chose, 3);
        Signal_test_to_Switchover(KaiYu, 0x00, 6);
        Get_Set.append("OK");
        Histogram_List.at(1)->setText(QString::number(++Qualified));
        // -合格时设置合格的显示文本
    }

    if ((Dis=="NG")&&(NG_Push)) {
        Signal_test_to_Switchover(NanXin, Station_Chose, 3);
    }
    else {

    }

    Histogram_List.at(1)->setGeometry(717, (290-Qualified*100/Test_Count), 31, \
                                      (Qualified*100/Test_Count));
    Histogram_List.at(2)->setGeometry(759, (290-Unqualified*100/Test_Count), 31, \
                                      (Unqualified*100/Test_Count));
    rtc_time rtc_t; char str_t1[30]; // -得到时分秒-数据,进行更新秒数据
    rtc_t = rtc.get_rtc();
    sprintf(str_t1, "%02d:%02d:%02d", rtc_t.tm_hour, rtc_t.tm_min, rtc_t.tm_sec);

    qDebug()<<"2017-12-13 IO_put-----------" << IO_put;
    Signal_test_to_Switchover(ZhongTe, IO_put, 1);

    Get_Set.append(Start_Time + "---" + str_t1);                          // -时分
    Get_Set.append(ui->S1Label_2->text().mid(27, 10));                    // -年月日
    Get_Set.append(ui->label_temp->text().remove(QString(tr("温度:"))));   // -温度
    Get_Set.append(ui->label_number->text().remove(QString(tr("编号:")))); // -编号
    Get_Set.append(ui->label_user->text().remove(QString(tr("操作者:")))); // -操作者

    QStringList all_data;
    all_data.append(QString::number(strResult.size()));
    all_data.append(QString::number(strJudge.size()));
    all_data.append(QString::number(Get_Set.size()));
    //   all_data.append(QString::number(QStringList_No_OK.size()));
    all_data.append(strResult);
    all_data.append(strJudge);
    all_data.append(Get_Set);
    //   all_data.append(QStringList_No_OK);
    if (Ini_SaveNG) {
        //
    } else {
        if (Cancel_No_Save) {
            Cancel_No_Save = false;
        } else {
            Sigtest_Save_Data(all_data,QString(""), 1);
        }
    }

    Test.NG_Item = 0;
    ui->label_number->setText(tr("编号:"));
    Test.serial_number = ""; //
    if ((Ini_NG_Data == 2) && (Dis == "NG")) { // 不合格状态，设置选为（测试后显示不合格波形）
        Test_NG_Data();
    } else {
        //
    }
    Signal_test_to_Switchover(BePuDa,0x12,12);
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.3.14
  * brief:      NG_Data  显示表格
******************************************************************************/
void w_Test::Test_NG_Data()
{
    int i = 0;
    PG_Row.clear();
    QStringList NG_Test, NG_Param, NG_Result, NG_Judge;
    for (i = 0; i < strResult.size(); i++) {
        if (strJudge.at(i) != "OK") { // -结果非OK
            NG_Test.append(strTest.at(i));
            NG_Param.append(strParam.at(i));
            NG_Result.append(strResult.at(i));
            NG_Judge.append(strJudge.at(i));
        } else {
            //
        }
    }
    ui->testTab->setRowCount(0);
    if (strTest.size() <= 12) {
        ui->testTab->setRowCount(12);
    }  else {
        ui->testTab->setRowCount(NG_Test.size());
    }
    for (i = 0; i < NG_Test.size(); i++) { // -测试序号
        QTableWidgetItem *pItem = new QTableWidgetItem(QString::number(i + 1));
        pItem->setTextAlignment(Qt::AlignCenter);
        ui->testTab->setItem(i, 0, pItem);
    }
    for (i = 0; i < NG_Test.size(); i++) { // -测试项目
        QTableWidgetItem *pItem = new QTableWidgetItem(NG_Test.at(i));
        pItem->setTextAlignment(Qt::AlignCenter);
        ui->testTab->setItem(i, 1, pItem);
    }
    for (i = 0; i < NG_Param.size(); i++) { // -测试参数
        QTableWidgetItem *pItem = new QTableWidgetItem(NG_Param.at(i));
        pItem->setTextAlignment(Qt::AlignCenter);
        ui->testTab->setItem(i, 2, pItem);
    }
    for (i = 0; i < NG_Result.size(); i++) { // -测试结果
        QTableWidgetItem *pItem = new QTableWidgetItem(NG_Result.at(i));
        pItem->setTextAlignment(Qt::AlignCenter);
        ui->testTab->setItem(i, 3, pItem);
    }
    for (i = 0; i < NG_Judge.size(); i++) { // -测试判定
        QTableWidgetItem *pItem = new QTableWidgetItem(NG_Judge.at(i));
        pItem->setTextAlignment(Qt::AlignCenter);
        ui->testTab->setItem(i, 4, pItem);
    }
    for (i = 0; i < NG_Test.size(); i++) { // -测试参数 是否包含PG 2017.5.20
        if (strTest.at(i).contains(QString(tr("PG")))) {
            PG_Row.append(QString::number(i));
            break;
        } else {
            //
        }
    }

    for (i = 0; i < strTest.size(); i++) { // -测试参数,是否包含PG,2017.5.20
        if (strTest.at(i).contains(QString(tr("空载")))) {
            ui->testTab->setRowHeight(i,50);
        } else if (strTest.at(i).contains(QString(tr("HALL")))) {
            ui->testTab->setRowHeight(i,50);
        } else {
            //
        }
    }

    qApp->processEvents();
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.6.6
  * brief:      启动电阻进行测试(测试功率)
******************************************************************************/
void w_Test::Can_Start_DLR()
{
    DLR_Issue_Ing = true;
    qDebug() << "Connect_Test" << Connect_Test;
    if (Connect_Test) {
        if (NetTest_Ready_DLR) {
            //
        } else {
            qDebug() << "Test 2017-12-19------> Wait DLR Ready";
            return;
        }
    } else {
        //
    }
    NetTest_Ready_DLR = false;
    qDebug() << "Can_Start_DLR()";
    if (Conf_Item.contains(tr("7")) || \
            Conf_Item.contains(tr("9")) || \
            Conf_Item.contains(tr("10"))) {
 //   if (Exist_PWR) {
        if (QString(Ver_System) == QString("Release")) {
            False_Test = true;
            if (Station_Chose != 0x13) { // -测试新PG时进行屏蔽
                frame.can_id = 0x27;  frame.can_dlc = 0x08;
                frame.data[0] = 0x01;  // -设置功率参数
                frame.data[1] = 1<<4;  // -档位 增加功率档位
                frame.data[2] = 5/256; // -测试时间
                frame.data[3] = 5%256;
                frame.data[4] = Ini_Power_Chose << 4; // -电压
                frame.data[5] = 0x00;
                frame.data[6] = 0x00;
                frame.data[7] = 0;
                canSend(frame, wTest_Surface);
            } else {
                frame.can_id = 0x27;  frame.can_dlc = 0x08;
                frame.data[0] = 0x01;  // -设置功率参数
                frame.data[1] = 1;     // -档位 增加功率档位
                frame.data[2] = 5/256; // -测试时间
                frame.data[3] = 5%256;
                frame.data[4] = Ini_Power_Chose << 4; // -电压
                frame.data[5] = 0x00;
                frame.data[6] = 0x00;
                frame.data[7] = 0;
                canSend(frame, wTest_Surface);
            }
        } else {
            frame.can_id = 0x22;  frame.can_dlc = 0x06;
            frame.data[0] = 0x01;
            frame.data[1] = 0x01;
            frame.data[2] = 0x00;
            frame.data[3] = Station_Chose;
            frame.data[4] = DCR_TestItem_H;
            frame.data[5] = DCR_TestItem_L;
            canSend(frame, wTest_Surface);
            usleep(500);
        }
    } else {
        frame.can_id = 0x22;  frame.can_dlc = 0x06;
        frame.data[0] = 0x01;
        frame.data[1] = 0x01;
        frame.data[2] = 0x00;
        frame.data[3] = Station_Chose;
        frame.data[4] = DCR_TestItem_H;
        frame.data[5] = DCR_TestItem_L;
        canSend(frame, wTest_Surface);
        usleep(500);
        qDebug() << "frame.data[3]" << frame.data[3];
    }
    DLR_Issue_Ing = false;
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.6.6
  * brief:      启动电阻进行测试
******************************************************************************/
void w_Test::Can_Start_DLR_True()
{
    frame.can_id = 0x22;  frame.can_dlc = 0x06;
    frame.data[0] = 0x01;
    frame.data[1] = 0x01;
    frame.data[2] = 0x00;
    frame.data[3] = Station_Chose;
    frame.data[4] = DCR_TestItem_H;
    frame.data[5] = DCR_TestItem_L;
    canSend(frame, wTest_Surface);
    qDebug() << "frame.data[3]" << frame.data[3];
    usleep(500);
}

/******************************************************************************
  * brief:      启动反嵌进行测试
******************************************************************************/
void w_Test::Can_Start_MAG()
{
    int i = 0;
    MAG_Issue_Ing = true;
    if (Connect_Test) {
        if (NetTest_Ready_MAG) {
            //
        } else {
            qDebug() << "Test 2017-12-19-------------------------> Wait MAG Ready";
            return;
        }
    } else {
        //
    }
    qDebug() << "Test 2017-12-20-----------------> 1" << Ini_MAG_Device << MAG_Drive;
    if (Ini_MAG_Device) {
        if (!MAG_Drive) {
           Test_MAG_Ready = true;
        // Signal_test_to_pic(QStringList(""), 1, 20); // Ask
           return;
        }
        MAG_Drive = false;
    }
    mag_zero.clear();
    for (i = 0; i < 8; i++) {
        mag_zero.append("0");
    }
    NetTest_Ready_MAG = false;
    frame.can_id  = 0x22;  frame.can_dlc = 0x06;
    frame.data[0] = 0x01;
    frame.data[1] = 0x02;
    frame.data[2] = 0x00;
    frame.data[3] = Station_Chose;
    frame.data[4] = 0x00;
    frame.data[5] = MAG_TestItem;
    canSend(frame, wTest_Surface);
    usleep(500);
    MAG_Issue_Ing = false;
}

/******************************************************************************
  * brief:      启动绝缘进行测试
******************************************************************************/
void w_Test::Can_Start_IR()
{
    IR_Issue_Ing = true;
    frame.can_id  = 0x2C;  frame.can_dlc = 0x02; // 高压回路
    frame.data[0] = 0x12; // 高压回路
    if (Station_Chose == 0x13) {
        frame.data[1] = 0x01;
    } else {
        frame.data[1] = 0x02;
    }
    canSend(frame, wTest_Surface);
    if (Connect_Test) {
        if (NetTest_Ready_IR) {
            //
        } else {
            qDebug() << "Test 2017-12-19------> Wait IR Ready";
            return;
        }
    } else {
        //
    }
    NetTest_Ready_IR = false;
    qDebug() << "Can_Start_IR()";
    if (IR_Test_Count < 0) {
        IR_Test_Count = IR_Test_Total - 1;
    }
    Sigtest_Save_Data(QStringList(""), QString(""), 2);
    if (Ini_ACWandIR) { // -相间绝缘
        frame.can_id = 0x23;
        frame.can_dlc = 0x05;
        frame.data[0] = 0x01;
        frame.data[1] = 0x04;
        frame.data[2] = 0x00;
        frame.data[3] = Station_Chose;
        frame.data[4] = IRgroup_num.at(IR_Test_Count).toInt();
        canSend(frame, wTest_Surface);
        usleep(500);
    } else {
        frame.can_id = 0x23;
        frame.can_dlc = 0x05;
        frame.data[0] = 0x01;           // 启动测试
        frame.data[1] = 0x04;           // 测试型号
        frame.data[2] = 0x00;           // 0自动选档，其他为定档
        frame.data[3] = Station_Chose;  // 工位
        frame.data[4] = 0x01;           // 测试组
        canSend(frame, wTest_Surface);
        usleep(500);
    }
    IR_Issue_Ing = false;
}

/******************************************************************************
  * brief:      启动耐压进行测试
******************************************************************************/
void w_Test::Can_Start_ACW()
{
    ACW_Issue_Ing = true;
    frame.can_id  = 0x2C;  frame.can_dlc = 0x02; // 高压回路
    frame.data[0] = 0x12; // 高压回路
    if (Station_Chose == 0x13) {
        frame.data[1] = 0x01;
    } else {
        frame.data[1] = 0x02;
    }
    canSend(frame, wTest_Surface);
    usleep(500);
    if (Connect_Test) {
        if (NetTest_Ready_ACW) {
            //
        } else {
            qDebug() << "Test 2017-12-19------> Wait ACW Ready";
            return;
        }
    } else {
        //
    }
    qDebug() << "Can_Start_ACW()";
    qDebug() << "Test_Model_Vacuum_ACW" << Test_Model_Vacuum_ACW;
    if (Test_Model_Vacuum_ACW) {
        if (!Vacuum_Ready) {
            Test_ACW_Ready = true;
            return;
        }
    }
    NetTest_Ready_ACW = false;
    qDebug() << "Can_Start_ACW()";
    if (ACW_Test_Count < 0) {
        ACW_Test_Count = ACW_Test_Total-1;
    }
    Sigtest_Save_Data(QStringList(""), QString(""), 3);
    if (Ini_ACWandIR) { // 相间耐压
        frame.can_id = 0x23;
        frame.can_dlc = 0x05;
        frame.data[0] = 0x01;
        frame.data[1] = 0x05;
        frame.data[2] = 0x00;
        frame.data[3] = Station_Chose;
        frame.data[4] = ACWgroup_num.at(ACW_Test_Count).toInt();
        canSend(frame, wTest_Surface);
        usleep(500);
    } else {
        qDebug() << "ACW------------------";
        frame.can_id = 0x23;
        frame.can_dlc = 0x05;
        frame.data[0] = 0x01;
        frame.data[1] = 0x05;
        frame.data[2] = 0x00;
        frame.data[3] = Station_Chose;
        frame.data[4] = 0x00;
        canSend(frame, wTest_Surface);
        usleep(500);
    }
    ACW_Issue_Ing = false;
}

/******************************************************************************
  * brief:      启动直耐进行测试
******************************************************************************/
void w_Test::Can_Start_DCW()
{
    usleep(500);
}

/******************************************************************************
  * brief:      启动匝间进行测试
******************************************************************************/
void w_Test::Can_Test_IMP_Parameter()
{
    int i = 0;
    IMP_TestItem = 0;
    IMP_Total_Number = 0;
    for (i = 0; i < 8; i++) {
        if (strITT.at(NUM_ITT*i+8).toInt() == 2) {         //- 判断匝间数据库是否被勾选
            frame.can_id = 0x24; frame.can_dlc = 0x08;
            frame.data[0] = 0x03; frame.data[1] = i;
            frame.data[2] = strITT[i*NUM_ITT].toInt(); // -测试点
            frame.data[3] = strITT[i*NUM_ITT+1].toInt();
            if (Station_Chose == 0x13) { // 启动左工位
                frame.data[4] =(strITT[i*NUM_ITT+10].toInt())/256; // -下发实际电压
                frame.data[5] =(strITT[i*NUM_ITT+10].toInt())%256;
                qDebug() << "Lest  Volt" << (strITT[i*NUM_ITT+10].toInt());
            } else {
                frame.data[4] =(strITT[i*NUM_ITT+15].toInt())/256; // -下发实际电压
                frame.data[5] =(strITT[i*NUM_ITT+15].toInt())%256;\
                qDebug() << "Right Volt" << (strITT[i*NUM_ITT+10].toInt());
            }

            if (strITT[i*NUM_ITT+2].toInt() <= 1000) {
                frame.data[6] = 1;
            } else if (strITT[i*NUM_ITT+2].toInt() <= 2000) {
                frame.data[6] = 2;
            } else if (strITT[i*NUM_ITT+2].toInt() <= 4000) {
                frame.data[6] = 3;
            } else {
                frame.data[6] = 4;
            }

            if (strITT[i*NUM_ITT+3].toInt() == 1) {
               frame.data[6]=((frame.data[6]<<4)+strITT[i*NUM_ITT+3].toInt() +1);
            } else {
               frame.data[6]=((frame.data[6]<<4)+strITT[i*NUM_ITT+3].toInt());
            }

            if (Station_Chose == 0x13) { // -启动左工位
                frame.data[7] = strITT[i*NUM_ITT + 9].toInt(); // -频率
                qDebug() << "Left  Fre" << frame.data[7];
            } else { // 启动右工位
                frame.data[7] = strITT[i*NUM_ITT + 14].toInt(); // -频率
                qDebug() << "Right Fre" << frame.data[7];
            }
            canSend(frame, wTest_Surface);
            usleep(1000);
            IMP_TestItem = IMP_TestItem + (1 << i);
            IMP_Total_Number++;
        }
    }
}

/******************************************************************************
  * brief:      启动匝间进行测试
******************************************************************************/
void w_Test::Can_Start_IMP()
{
    IMP_Issue_Ing = true;
    if (Connect_Test) {
        if (NetTest_Ready_IMP) {
            //
        } else {
            qDebug() << "Test 2017-12-19------> Wait IMP Ready";
            return;
        }
    } else {
        //
    }
    if (Test_Model_Vacuum) {
        if (!Vacuum_Ready) {
           Test_IMP_Ready = true;
           return;
        } else {
            //
        }
    } else {
        //
    }
    NetTest_Ready_IMP = false;
    qDebug() << "Can_Start_IMP()---";

    int j = 0;
    for (j = 0; j < 200; j++) { // 下发参数延时等待 50ms
        usleep(1000);
    }


    frame.can_id = 0x24;   frame.can_dlc = 0x05;
    frame.data[0] = 0x01;
    frame.data[1] = 0x00; // -0x00测试 0x01自动选频采样 0x02定频采样
    frame.data[2] = Station_Chose;
    frame.data[3] = 0x00;
    frame.data[4] = IMP_TestItem;
    canSend(frame, wTest_Surface);
    usleep(500);
    IMP_Issue_Ing = false;
}

/******************************************************************************
  * brief:      启动功率进行测试
******************************************************************************/
void w_Test::Can_Start_PWR(int str)
{
    int PWR_Volt = 0;
    PG_list.clear();
    Signal_test_to_Switchover(NanXin, Station_Chose, 5);
    int i = 0, time = 0, fre = 0, grade = 0, position_grade = 0;
    for (i = 0; i < 36; i++) {
        usleep(1000);
        qApp->processEvents();
    }
    if (str  ==  1) {
        Test.NG_Item   = 0; // -初次测试,进行数据清空
        PWR_Test_Count = 0;
    } else {
        // -不进行任何操作
    }
    for (i = 0; i < 10; i++) {
        PWR_Display_Lable.at(i)->setText("");
    }

    PWR_Result_Judge.clear();
    if (strPWR.at(26).toInt() == 60) { // -频率为60HZ
        fre = 1 << 1;
    } else { // -其余全部为50HZ
        fre = 0 << 1;
    }

    frame.can_id  = 0x29;  frame.can_dlc = 0x02;
    frame.data[0] = 0x04;          // -PG参数
    if (strPWR.at(31).toInt() % 2 == 0) {
        frame.data[1] = 0x00;
    } else {
        frame.data[1] = 0x01;
    }
    canSend(frame, wTest_Surface);
    usleep(500);

    qDebug() << PWR_Test_Data.size() << PWR_Test_Data << PWR_Test_Count;
    position_grade = PWR_Test_Data.at(1 + PWR_Test_Count).toInt()/10; // -位置
    grade    = PWR_Test_Data.at(1 + PWR_Test_Count).toInt()%10;       // -档位
    time     = strPWR.at(45 + position_grade*20).toDouble()*10;       // -各个档位的时间
    PWR_Volt = strPWR.at(25).toInt();
    /*进行PG的测试*/
    if ((Ini_Motor == QString(tr("PG"))) && ((strPWR.at(5 + position_grade).toInt() == 2))) {
        frame.can_id  = 0x29;  frame.can_dlc = 0x05;
        frame.data[0] = 0x03;          // -PG参数
        frame.data[1] = Station_Chose; // -工位
        frame.data[2] = (time)/256;
        frame.data[3] = (time)%256;
        frame.data[4] = strPWR.at(155 + position_grade).toDouble()*10;
        canSend(frame, wTest_Surface);
        usleep(500);
        qDebug() << "Down PG";
    } else {
        //
    }

    /*进行功率的测试*/
    frame.can_id = 0x27;  frame.can_dlc = 0x08;
    frame.data[0] = 0x01;         // -设置功率参数
    if (Station_Chose == 0x13) {
        frame.data[1] = grade;    // -左工位
    } else {
        frame.data[1] = grade << 4; // -右工位
    }
    time = strPWR.at(45 + position_grade*20).toDouble()*10;       // -各个档位的时间
    frame.data[2] = time/256;     // ----测试时间
    frame.data[3] = time%256;
    if (Ini_Power_Chose == 0) {      // -无电源
        frame.data[4] = 0x00;
        frame.data[5] = 0x00;
    } else if (Ini_Power_Chose == 1) {  // -吉利电源
        frame.data[4] = ((1 << 4) | (fre) | (PWR_Volt/256));
        frame.data[5] = PWR_Volt%256;
    } else if (Ini_Power_Chose == 2) {  // -外部电源板
        frame.data[4] = (2 << 4);
        frame.data[5] = (strPWR.at(30).toInt());
    } else if (Ini_Power_Chose == 3)  { // -变压器方案
        frame.data[4] = ((3 << 4) | (PWR_Volt/256));
        frame.data[5] = PWR_Volt%256;
    }  else if (Ini_Power_Chose == 4)  { // 内部
        frame.data[4] = ((4 << 4) | ((PWR_Volt + strPWR.at(46+(grade-1)*20).toInt())/256));
        frame.data[5] = (PWR_Volt + strPWR.at(46+(grade-1)*20).toInt())%256;
    } else {
        frame.data[4] = 0x00;
        frame.data[5] = 0x00;
    }
    if (strPWR.at(44 + (position_grade)*20).toInt() != 0) {
        if (PGturn_model == 1) {
            frame.data[6] = 0x01; // -hall      测试转向
        } else {
            frame.data[6] = 0x02; // -induction 测试转向
        }
    } else {
        frame.data[6] = 0x00;     // -不测试转向
    }
    frame.data[7] = 0;
    canSend(frame, wTest_Surface);
    qDebug() << "Down PWR";
}

/******************************************************************************
  * brief:      启动电感进行测试
******************************************************************************/
void w_Test::Can_Start_INDL()
{
    IND_Issue_Ing = true;
    if (Connect_Test) {
        if (NetTest_Ready_IND) {
            //
        } else {
            qDebug() << "Test 2017-12-19------> Wait IND Ready";
            return;
        }
    } else {
        //
    }
    NetTest_Ready_IND = false;
    qDebug() << "Can_Start_INDL()";
    usleep(15000);
    frame.can_id = 0x26;  frame.can_dlc = 0x08;
    frame.data[0] = 0x01;
    if (strINDL.at(6).toInt() == 1) {
        frame.data[1] = 0x00;
    } else {
        frame.data[1] = 0x10;
    }
    frame.data[2] = 0x00;
    frame.data[3] = Station_Chose;
    frame.data[4] = INDL_TestItem_H;
    frame.data[5] = INDL_TestItem_L;
    frame.data[6] = 0x07;
    frame.data[7] = 0x08;
    canSend(frame, wTest_Surface);
    usleep(500);
    IND_Issue_Ing = false;
}

/******************************************************************************
  * brief:      启动堵转进行测试
******************************************************************************/
void w_Test::Can_Start_BLOCK()
{
    Block_cycle = 0;
    int fre = 0;
    int pwr_volt = 0;

    pwr_volt = strBLOCK.at(200).toInt();

    if (strBLOCK.at(206).toInt() == 60) { // -频率60HZ
        fre = 1 << 1;
    } else { // -其余全部为50HZ
        fre = 0 << 1;
    }
    frame.can_id = 0x27;  frame.can_dlc = 0x05;
    frame.data[0] = 0x03; // -堵转
    if (Station_Chose == 0x13) {
        frame.data[1] = strBLOCK.at(202).toInt();    // -档位
    } else {
        frame.data[1] = strBLOCK.at(202).toInt() << 4; // -档位
    }
    frame.data[2] = strBLOCK.at(201).toInt()/10;     // -时间
    if (Ini_Power_Chose == 0) {     //-无电源
        frame.data[3] = 0x00;
        frame.data[4] = 0x00;
    } else if (Ini_Power_Chose == 1) { // -吉利电源
        frame.data[3] = ((1 << 4) | (fre) | (pwr_volt/256));
        frame.data[4] = pwr_volt%256;
    } else if (Ini_Power_Chose == 2) { // -外部电源
        frame.data[3] = (2 << 4);
        frame.data[4] = (strBLOCK.at(207).toInt());
    } else if (Ini_Power_Chose == 3) { // -变压器方案
        frame.data[3] = ((3 << 4) | (pwr_volt/256));
        frame.data[4] = pwr_volt%256;
    } else if(Ini_Power_Chose==4) { // 内部
        frame.data[3] = ((4<<4)|((pwr_volt+strBLOCK.at(208).toInt())/256));    // 电压 (增加 电源 频率)
        frame.data[4] = (pwr_volt+strBLOCK.at(208).toInt())%256;
    } else {
        frame.data[3] = 0x00;
        frame.data[4] = 0x00;
    }
    canSend(frame, wTest_Surface);
}

/******************************************************************************
  * brief:      启动低启进行测试
******************************************************************************/
void w_Test::Can_Start_LVS()
{
    int time = 0, fre = 0;
    int pwr_volt = 0;

    if (strLVS.at(1).toInt() == 60) { // -频率为(60)HZ
        fre = 1 << 1;
    } else { // -其余全部为50 HZ
        fre = 0 << 1;
    }

    pwr_volt = strLVS.at(0).toInt();

    LVS_Result_Judge.clear();
    frame.can_id = 0x27;  frame.can_dlc = 0x08;
    frame.data[0] = 0x01; // -设置功率参数
    if (Station_Chose == 0x13) {
        frame.data[1] = strLVS.at(6).toInt();    // -档位
    } else {
        frame.data[1] = strLVS.at(6).toInt() << 4; // -档位
    }
    time = strLVS.at(34).toDouble()*10;
    frame.data[2] = time/256;   // -测试时间
    frame.data[3] = time%256;
    if (Ini_Power_Chose == 0) {   // -无电源
        frame.data[4] = 0x00;
        frame.data[5] = 0x00;
    } else if (Ini_Power_Chose == 1) { // -吉利电源
        frame.data[4] = ((1 << 4) | (fre) | (pwr_volt/256));
        frame.data[5] = pwr_volt%256;
    } else if (Ini_Power_Chose == 2) { // -外部电源
        frame.data[4] = (2 << 4);
        frame.data[5] = (strLVS.at(2).toInt());
    } else if (Ini_Power_Chose == 3) { // -变压器方案
        frame.data[4] = ((3 << 4) | (pwr_volt/256));
        frame.data[5] = pwr_volt%256;
    } else if (Ini_Power_Chose==4) { // 内部
        frame.data[4] = ((4<<4)|((pwr_volt+strLVS.at(7).toInt())/256));
        frame.data[5] = (pwr_volt+strLVS.at(7).toInt())%256;
    }else {
        frame.data[4] = 0x00; // -电压
        frame.data[5] = 0x00;
    }
    if (Ini_LVS_Judge != 0) {
        if (PGturn_model == 1) { // -hall
            frame.data[6] = 0x01;
        } else { // induction
            frame.data[6] = 0x02;
        }
    } else { // 不测试转向
        frame.data[6] = 0x00;
    }
    frame.data[7] = 0x00;
    canSend(frame, wTest_Surface);
}

void w_Test::join_test_hall() {
    join_updatedata(Hall_Update);
}

void w_Test::Can_Start_BLDCHALL() {
    HALL_Issue_Ing = true;
    if (Connect_Test) {
        if (NetTest_Resdy_HALL) {
            //
        } else {
            qDebug() << "Test 2017-12-19------> Wait Hall Ready";
            return;
        }
    } else {
        //
    }
    NetTest_Resdy_HALL = false;
    qDebug() << "Can_Start_BLDCHALL()";
    QTimer *Button_Start = new QTimer(this);
    connect(Button_Start, SIGNAL(timeout()), this, SLOT(join_test_hall())); //
    Button_Start->setSingleShot(TRUE);
    Button_Start->start(100);
    HALL_Issue_Ing = false;
}

void w_Test::Can_Start_LOAD() {
    LOAD_Issue_Ing = true;
    int j = 0;
    if (Connect_Test) {
        if (NetTest_Resdy_LOAD) {
            //
        } else {
            qDebug() << "Test 2017-12-19------> Wait Load Ready";
            return;
        }
    } else {
        //
    }
    NetTest_Resdy_LOAD = false;
    qDebug() << "Can_Start_LOAD()--change vm";
    frame.can_id = 0x2c;  frame.can_dlc = 0x08; // WD板控制继电器
    frame.data[0] = 0x15;
    frame.data[1] = 0x03;
    frame.data[2] = Station_Chose - 0x12;
    frame.data[3] = strLOAD.at(6).toInt(); // 更改内外置驱动方式
    frame.data[4] = 0x00;
    frame.data[5] = 0x00;
    frame.data[6] = 0x00;
    frame.data[7] = 0x00;
    canSend(frame, wTest_Surface);
    for (j = 0; j < 10; j++) { // 下发参数延时等待 10ms
        usleep(1000);
    }
    frame.can_id = 0x2C;  frame.can_dlc = 0x08; // 下发vcc 电压 缓升时间
    frame.data[0] = 0x03;
    frame.data[1] = Station_Chose - 0x12;
    frame.data[2] = 0x01; // 01 vcc 02 vsp 03 vm
    frame.data[3] = 0x01; // 01 缓升 02 缓降
    frame.data[4] = (int)(strLOAD.at(1).toDouble()*245-6)%256; //
    frame.data[5] = (int)(strLOAD.at(1).toDouble()*245-6)/256; //
    frame.data[6] = int(strLOAD.at(110).toDouble()*1000)%256;
    frame.data[7] = int(strLOAD.at(110).toDouble()*1000)/256;
    canSend(frame, wTest_Surface);
    for (j = 0; j < 10; j++) { // 下发参数延时等待 10ms
        usleep(1000);
    }
    frame.can_id = 0x2C;  frame.can_dlc = 0x08; // 下发vcc 电压 缓降时间
    frame.data[0] = 0x03;
    frame.data[1] = Station_Chose - 0x12;
    frame.data[2] = 0x01; // 01 vcc  02 vsp  03 vm
    frame.data[3] = 0x02; // 01 缓升 02 缓降
    frame.data[4] = (int)(strLOAD.at(1).toDouble()*245-6)%256; // *4095/16.8
    frame.data[5] = (int)(strLOAD.at(1).toDouble()*245-6)/256; // *4095/16.8
    frame.data[6] = int(strLOAD.at(119).toDouble()*1000)%256;
    frame.data[7] = int(strLOAD.at(119).toDouble()*1000)/256;
    canSend(frame, wTest_Surface);
    for (j = 0; j < 10; j++) {  // 下发参数延时等待 10ms
        usleep(1000);
    }
    frame.can_id = 0x2C;  frame.can_dlc = 0x08; // 下发vsp 电压 缓升时间
    frame.data[0] = 0x03;
    frame.data[1] = Station_Chose - 0x12;
    frame.data[2] = 0x02; // 01 vcc    02 vsp    03 vm
    frame.data[3] = 0x01; // 01 缓升    02 缓降
    frame.data[4] = (int)(strLOAD.at(2).toDouble()*245-6)%256; // *4095/16.8
    frame.data[5] = (int)(strLOAD.at(2).toDouble()*245-6)/256; // *4095/16.8
    frame.data[6] = int(strLOAD.at(114).toDouble()*1000)%256;
    frame.data[7] = int(strLOAD.at(114).toDouble()*1000)/256;
    canSend(frame, wTest_Surface);
    for (j = 0; j < 10; j++) { // 下发参数延时等待 10ms
        usleep(1000);
    }
    frame.can_id = 0x2C;  frame.can_dlc = 0x08; // 下发vsp 电压 缓降时间
    frame.data[0] = 0x03;
    frame.data[1] = Station_Chose - 0x12;
    frame.data[2] = 0x02; // 01 vcc    02 vsp    03 vm
    frame.data[3] = 0x02; // 01 缓升    02 缓降
    frame.data[4] = (int)(strLOAD.at(2).toDouble()*245-6)%256; // *4095/16.8
    frame.data[5] = (int)(strLOAD.at(2).toDouble()*245-6)/256; // *4095/16.8
    frame.data[6] = int(strLOAD.at(115).toDouble()*1000)%256;
    frame.data[7] = int(strLOAD.at(115).toDouble()*1000)/256;
    canSend(frame, wTest_Surface);
    for (j = 0; j < 10; j++) { // 下发参数延时等待 10ms
        usleep(1000);
    }
    frame.can_id  = 0x2C;  frame.can_dlc = 0x08; // 下发vm 缓升时间
    frame.data[0] = 0x03;
    frame.data[1] = Station_Chose - 0x12;
    frame.data[2] = 0x03; // 01 vcc    02 vsp    03 vm
    if (strLOAD.at(5).toInt() == 1) { // 01 菊水
        frame.data[3] = strLOAD.at(5).toInt();
        frame.data[4] = int(strLOAD.at(0).toDouble())%256;
        frame.data[5] = int(strLOAD.at(0).toDouble())/256;
        frame.data[6] = 0x00;
        frame.data[7] = 0x00;
    } else { // 02 天虹
        frame.data[3] = strLOAD.at(5).toInt();
        frame.data[4] = int(strLOAD.at(0).toDouble()*100)/1000;
        frame.data[5] = int(strLOAD.at(0).toDouble()*100)%1000/100;
        frame.data[6] = int(strLOAD.at(0).toDouble()*100)%100/10;
        frame.data[7] = int(strLOAD.at(0).toDouble()*100)%10;
    }
    canSend(frame, wTest_Surface);
    for (j = 0; j < 10; j++) { // 下发参数延时等待 10ms
        usleep(1000);
    }
    int vcc_up_time = 0;
    int vsp_up_time = 0;
    int vm_up_time = 0;
    int vcc_down_time = 0;
    int vsp_down_time = 0;
    int vm_down_time = 0;
    vcc_up_time = 2;
    vm_up_time = vcc_up_time + strLOAD.at(110).toDouble()*1000 + strLOAD.at(111).toDouble()*1000;
    vsp_up_time = vm_up_time + strLOAD.at(112).toDouble()*1000 + strLOAD.at(113).toDouble()*1000;

    vsp_down_time = 2;
    vm_down_time = vsp_down_time + strLOAD.at(115).toDouble()*1000 + \
            strLOAD.at(116).toDouble()*1000;
    vcc_down_time = vm_down_time + strLOAD.at(117).toDouble()*1000 + \
            strLOAD.at(118).toDouble()*1000;
    frame.can_id = 0x2C;  frame.can_dlc = 0x08; //上升延时
    frame.data[0] = 0x03;
    frame.data[1] = 0x04;
    frame.data[2] = vcc_up_time % 256; // vcc 低8位
    frame.data[3] = vcc_up_time / 256; // vcc 高8位
    frame.data[4] = vsp_up_time % 256; // vsp 低8位
    frame.data[5] = vsp_up_time / 256; // vsp 高8位
    frame.data[6] = vm_up_time % 256;  // vm  低8位
    frame.data[7] = vm_up_time / 256;  // vm  高8位
    canSend(frame, wTest_Surface);
    for (j = 0; j < 10; j++) { // 下发参数延时等待 10ms
        usleep(1000);
    }
    frame.can_id = 0x2C;  frame.can_dlc = 0x08; //下降延时
    frame.data[0] = 0x03;
    frame.data[1] = 0x05;
    frame.data[2] = vcc_down_time % 256; // vcc 低8位
    frame.data[3] = vcc_down_time / 256; // vcc 高8位
    frame.data[4] = vsp_down_time % 256; // vsp 低8位
    frame.data[5] = vsp_down_time / 256; // vsp 高8位
    frame.data[6] = vm_down_time % 256;  // vm  低8位
    frame.data[7] = vm_down_time / 256;  // vm  高8位
    canSend(frame, wTest_Surface);
    for (j = 0; j < 10; j++) { // 下发参数延时等待 10ms
        usleep(1000);
    }
    frame.can_id = 0x2C;  frame.can_dlc = 0x08; // vcc vsp 供电方式
    frame.data[0] = 0x03; // vcc vsp 供电方式
    frame.data[1] = 0x06;
    frame.data[2] = strLOAD.at(6).toInt(); // 00 驱动内置 01 驱动外置
    frame.data[3] = 0x00; // vsp 00 pwm 01
    canSend(frame, wTest_Surface);
    for (j = 0; j < 10; j++) {
        usleep(1000);
    }

    frame.can_id = 0x2C;  frame.can_dlc = 0x05; // 启动测试
    frame.data[0] = 0x01;
    frame.data[1] = Station_Chose - 0x12;
    frame.data[2] = strNOLOAD.at(14).toInt(); // 测试 HALL-A
    frame.data[3] = (int)(strNOLOAD.at(3).toDouble()*1000)%256;
    frame.data[4] = (int)(strNOLOAD.at(3).toDouble()*1000)/256;
    canSend(frame, wTest_Surface);
    for (j = 0; j < 10; j++) { // 下发参数延时等待 10ms
        usleep(1000);
    }

    frame.can_id = 0x2C;  frame.can_dlc = 0x01; // 启动电机
    frame.data[0] = 0x13; // 启动电机
    canSend(frame, wTest_Surface);
    for (j = 0; j < 10; j++) { // 下发参数延时等待 10ms
        usleep(1000);
    }

    qDebug() << "PG_Test_State" << PG_Test_State;
    if ((PG_Test_State == 0xA3) || (PG_Test_State == 10)) {
        //
    } else {
        Can_Stop(0x2c);
        join_updatedata(QStringList("")); // 更新数据
        // 上传状态
        return;
    }

    frame.can_id = 0x2C; //-PG
    frame.can_dlc = 0x01;
    frame.data[0] = 0x00;
    canSend(frame, 88); usleep(1000); usleep(1000); usleep(1000);

    qDebug() << "启动定时器";
    Signal_Test_to_Main(FG_Conf_Item.at(1).toInt()%1000,6); // 启动定时器读取状态

    LOAD_Issue_Ing = false;
}

void w_Test::Can_Start_NOLOAD() {
    NOLOAD_Issue_Ing = true;
    int j = 0;
    if (Ini_IO_Model == Bosch) { //
        if (Station_Chose == 0x13) {
            Signal_test_to_Switchover(Bosch, 0x03, 7);
        } else if (Station_Chose == 0x14) {
            Signal_test_to_Switchover(Bosch, 0x05, 7);
        }
    }

    if (Connect_Test) {
        if (NetTest_Resdy_NOLOAD) {
            //
        } else {
            qDebug() << "Test 2017-12-19------> Wait NOLoad Ready";
            return;
        }
    } else {
        //
    }
    NetTest_Resdy_NOLOAD = false;

    qDebug() << "Can_Start_NOLOAD()--change vm";
    frame.can_id = 0x2c;  frame.can_dlc = 0x08; // WD板控制继电器
    frame.data[0] = 0x15;
    frame.data[1] = 0x03;
    frame.data[2] = Station_Chose - 0x12;
    frame.data[3] = strNOLOAD.at(6).toInt(); // 更改内外置驱动方式
    frame.data[4] = 0x00;
    frame.data[5] = strNOLOAD.at(8).toInt();
    frame.data[6] = strNOLOAD.at(9).toInt();
    frame.data[7] = strNOLOAD.at(10).toInt();
    canSend(frame, wTest_Surface);
    for (j = 0; j < 10; j++) {  // 下发参数延时等待 10ms
        usleep(1000);
    }
    if (Ini_BLDC_PG) {
        frame.can_id  = 0x2D;  frame.can_dlc = 0x03;
        frame.data[0] = 0xf1;
        frame.data[1] = 0x07;
        frame.data[2] = 0x00;
        frame.data[3] = 0x00;
        canSend(frame, wTest_Surface);   usleep(5000); usleep(5000); usleep(5000);
    } else {
        //
    }
    frame.can_id = 0x2C;  frame.can_dlc = 0x08; // 下发vcc 电压 缓升时间
    frame.data[0] = 0x03;
    frame.data[1] = Station_Chose - 0x12;
    frame.data[2] = 0x01; // 01 vcc 02 vsp 03 vm
    frame.data[3] = 0x01; // 01 缓升 02 缓降
    frame.data[4] = (int)(strNOLOAD.at(1).toDouble()*245-6)%256; // *4095/16.8
    frame.data[5] = (int)(strNOLOAD.at(1).toDouble()*245-6)/256; // *4095/16.8
    frame.data[6] = int(strNOLOAD.at(110).toDouble()*1000)%256;
    frame.data[7] = int(strNOLOAD.at(110).toDouble()*1000)/256;
    canSend(frame, wTest_Surface);
    for (j = 0; j < 10; j++) { // 下发参数延时等待 10ms
        usleep(1000);
    }
    frame.can_id = 0x2C;  frame.can_dlc = 0x08; // 下发vcc 电压 缓降时间
    frame.data[0] = 0x03;
    frame.data[1] = Station_Chose - 0x12;
    frame.data[2] = 0x01; // 01 vcc  02 vsp  03 vm
    frame.data[3] = 0x02; // 01 缓升 02 缓降
    frame.data[4] = (int)(strNOLOAD.at(1).toDouble()*245-6)%256; // *4095/16.8
    frame.data[5] = (int)(strNOLOAD.at(1).toDouble()*245-6)/256; // *4095/16.8
    frame.data[6] = int(strNOLOAD.at(119).toDouble()*1000)%256;
    frame.data[7] = int(strNOLOAD.at(119).toDouble()*1000)/256;
    canSend(frame, wTest_Surface);
    for (j = 0; j < 10; j++) { // 下发参数延时等待 10ms
        usleep(1000);
    }
    frame.can_id = 0x2C;  frame.can_dlc = 0x08; // 下发vsp 电压 缓升时间
    frame.data[0] = 0x03;
    frame.data[1] = Station_Chose - 0x12;
    frame.data[2] = 0x02; // 01 vcc    02 vsp    03 vm
    frame.data[3] = 0x01; // 01 缓升    02 缓降
    frame.data[4] = (int)(strNOLOAD.at(2).toDouble()*245-6)%256; // *4095/16.8
    frame.data[5] = (int)(strNOLOAD.at(2).toDouble()*245-6)/256; // *4095/16.8
    frame.data[6] = int(strNOLOAD.at(114).toDouble()*1000)%256;
    frame.data[7] = int(strNOLOAD.at(114).toDouble()*1000)/256;
    canSend(frame, wTest_Surface);
    for (j = 0; j < 10; j++) { // 下发参数延时等待 10ms
        usleep(1000);
    }
    frame.can_id = 0x2C;  frame.can_dlc = 0x08; // 下发vsp 电压 缓降时间
    frame.data[0] = 0x03;
    frame.data[1] = Station_Chose - 0x12;
    frame.data[2] = 0x02; // 01 vcc    02 vsp    03 vm
    frame.data[3] = 0x02; // 01 缓升    02 缓降
    frame.data[4] = (int)(strNOLOAD.at(2).toDouble()*245-6)%256; // *4095/16.8
    frame.data[5] = (int)(strNOLOAD.at(2).toDouble()*245-6)/256; // *4095/16.8
    frame.data[6] = int(strNOLOAD.at(115).toDouble()*1000)%256;
    frame.data[7] = int(strNOLOAD.at(115).toDouble()*1000)/256;
    canSend(frame, wTest_Surface);
    for (j = 0; j < 10; j++) { // 下发参数延时等待 10ms
        usleep(1000);
    }
    frame.can_id  = 0x2C;  frame.can_dlc = 0x08; // 下发vm 缓升时间
    frame.data[0] = 0x03;
    frame.data[1] = Station_Chose - 0x12;
    frame.data[2] = 0x03; // 01 vcc    02 vsp    03 vm
    if (strNOLOAD.at(5).toInt() == 1) { // 01 菊水
        frame.data[3] = strNOLOAD.at(5).toInt();
        frame.data[4] = int(strNOLOAD.at(0).toDouble())%256;
        frame.data[5] = int(strNOLOAD.at(0).toDouble())/256;
        frame.data[6] = 0x00;
        frame.data[7] = 0x00;
    } else if (strNOLOAD.at(5).toInt() == 2) { // 02 天虹
        frame.data[3] = strNOLOAD.at(5).toInt();
        frame.data[4] = int(strNOLOAD.at(0).toDouble()*100)/1000;
        frame.data[5] = int(strNOLOAD.at(0).toDouble()*100)%1000/100;
        frame.data[6] = int(strNOLOAD.at(0).toDouble()*100)%100/10;
        frame.data[7] = int(strNOLOAD.at(0).toDouble()*100)%10;
    } else {
        frame.data[3] = strNOLOAD.at(5).toInt();
        frame.data[4] = int(strNOLOAD.at(0).toDouble())%256;
        frame.data[5] = int(strNOLOAD.at(0).toDouble())/256;
        frame.data[6] = 0x00;
        frame.data[7] = 0x00;
    }
    qDebug() << "2018-3-2 frame.data[3]--Power" << frame.data[3];
    canSend(frame, wTest_Surface);
    for (j = 0; j < 10; j++) { // 下发参数延时等待 10ms
        usleep(1000);
    }
    int vcc_up_time = 0;
    int vsp_up_time = 0;
    int vm_up_time = 0;
    int vcc_down_time = 0;
    int vsp_down_time = 0;
    int vm_down_time = 0;
    vcc_up_time = 2;
    vm_up_time = vcc_up_time + strNOLOAD.at(110).toDouble()*1000 + \
            strNOLOAD.at(111).toDouble()*1000;
    vsp_up_time = vm_up_time + strNOLOAD.at(112).toDouble()*1000 + \
            strNOLOAD.at(113).toDouble()*1000;
    vsp_down_time = 2;
    vm_down_time = vsp_down_time + strNOLOAD.at(115).toDouble()*1000 \
            + strNOLOAD.at(116).toDouble()*1000;
    vcc_down_time = vm_down_time + strNOLOAD.at(117).toDouble()*1000 \
            + strNOLOAD.at(118).toDouble()*1000;
    frame.can_id = 0x2C;  frame.can_dlc = 0x08; //上升延时
    frame.data[0] = 0x03; //上升延时
    frame.data[1] = 0x04;
    frame.data[2] = vcc_up_time % 256; // vcc 低8位
    frame.data[3] = vcc_up_time / 256; // vcc 高8位
    frame.data[4] = vsp_up_time % 256; // vsp 低8位
    frame.data[5] = vsp_up_time / 256; // vsp 高8位
    frame.data[6] = vm_up_time % 256;  // vm  低8位
    frame.data[7] = vm_up_time / 256;  // vm  高8位
    canSend(frame, wTest_Surface);
    for (j = 0; j < 10; j++) { // 下发参数延时等待 10ms
        usleep(1000);
    }
    frame.can_id = 0x2C;  frame.can_dlc = 0x08; //下降延时
    frame.data[0] = 0x03; //下降延时
    frame.data[1] = 0x05;
    frame.data[2] = vcc_down_time % 256; // vcc 低8位
    frame.data[3] = vcc_down_time / 256; // vcc 高8位
    frame.data[4] = vsp_down_time % 256; // vsp 低8位
    frame.data[5] = vsp_down_time / 256; // vsp 高8位
    frame.data[6] = vm_down_time % 256;  // vm  低8位
    frame.data[7] = vm_down_time / 256;  // vm  高8位
    canSend(frame, wTest_Surface);
    for (j = 0; j < 10; j++) { // 下发参数延时等待 10ms
        usleep(1000);
    }
    frame.can_id = 0x2C;  frame.can_dlc = 0x08; // vcc vsp 供电方式
    frame.data[0] = 0x03; // vcc vsp 供电方式
    frame.data[1] = 0x06;
    frame.data[2] = strNOLOAD.at(12).toInt(); // 00 驱动内置 01 驱动外置
    frame.data[3] = 0x00; // vsp 00 pwm 01
    canSend(frame, wTest_Surface);
    for (j = 0; j < 10;j++) { // 下发参数延时等待 10ms
        usleep(1000);
    }
    frame.can_id = 0x2C;  frame.can_dlc = 0x01; // 启动电机
    frame.data[0] = 0x13; // 启动电机
    canSend(frame, wTest_Surface);
    for (j = 0; j < 10; j++) { // 下发参数延时等待 10ms
        usleep(1000);
    }





    frame.can_id = 0x2C;  frame.can_dlc = 0x05; // 启动测试
    frame.data[0] = 0x01;
    frame.data[1] = Station_Chose - 0x12;
    frame.data[2] = 0x02; // 测试 HALL-A
    frame.data[3] = (int)(strLOAD.at(3).toDouble()*1000)%256;
    frame.data[4] = (int)(strLOAD.at(3).toDouble()*1000)/256;
    canSend(frame, wTest_Surface);
    for (j = 0; j < 500; j++) { // 下发参数延时等待 500ms
        usleep(1000);
    }

    qDebug() << "PG_Test_State" << PG_Test_State;
    if ((PG_Test_State == 0xA3) || (PG_Test_State == 10)) {
        //
    } else {
        Can_Stop(0x2c);
        join_updatedata(QStringList("")); // 更新数据
        // 上传状态
        return;
    }

    frame.can_id = 0x2C; //-PG
    frame.can_dlc = 0x01;
    frame.data[0] = 0x00;
    canSend(frame, 88); usleep(1000); usleep(1000); usleep(1000);

    qDebug() << "启动定时器";
    Signal_Test_to_Main(FG_Conf_Item.at(0).toInt()%1000,6); // 启动定时器读取状态

    NOLOAD_Issue_Ing = false;
    qDebug() << "下发10ms";
}

void w_Test::Can_Start_BEMF() {
    BEMF_Issue_Ing = true;
    int j = 0;
    if (Connect_Test) {
        if (NetTest_Resdy_BEMF) {
            //
        } else {
            qDebug() << "Test 2017-12-19------> Wait BEMF Ready";
            return;
        }
    } else {
        //
    }
    NetTest_Resdy_BEMF = false;
    qDebug() << "Can_Start_BEMF()";

    frame.can_id = 0x2C;  frame.can_dlc = 0x08; // 下发vcc 电压 缓升时间
    frame.data[0] = 0x03;
    frame.data[1] = Station_Chose - 0x12;
    frame.data[2] = 0x01; // 01 vcc 02 vsp 03 vm
    frame.data[3] = 0x01; // 01 缓升 02 缓降
    frame.data[4] = (int)(strBEMF.at(6).toDouble()*245-6)%256; // *4095/16.8
    frame.data[5] = (int)(strBEMF.at(6).toDouble()*245-6)/256; // *4095/16.8
    frame.data[6] = 1;
    frame.data[7] = 0;
    canSend(frame, wTest_Surface);
    for (j = 0; j < 10; j++) { // 下发参数延时等待 10ms
        usleep(1000);
    }
    frame.can_id = 0x2C;  frame.can_dlc = 0x08; // 下发vcc 电压 缓降时间
    frame.data[0] = 0x03;
    frame.data[1] = Station_Chose - 0x12;
    frame.data[2] = 0x01; // 01 vcc  02 vsp  03 vm
    frame.data[3] = 0x02; // 01 缓升 02 缓降
    frame.data[4] = (int)(strBEMF.at(6).toDouble()*245-6)%256; // *4095/16.8
    frame.data[5] = (int)(strBEMF.at(6).toDouble()*245-6)/256; // *4095/16.8
    frame.data[6] = 1;
    frame.data[7] = 0;
    canSend(frame, wTest_Surface);
    for (j = 0; j < 10; j++) { // 下发参数延时等待 10ms
        usleep(1000);
    }

    int vcc_up_time = 0;
    int vsp_up_time = 0;
    int vm_up_time = 0;
    int vcc_down_time = 0;
    int vsp_down_time = 0;
    int vm_down_time = 0;
    vcc_up_time = 2;
    vm_up_time = vcc_up_time + 2 + 2;
    vsp_up_time = vm_up_time + 2 + 2;

    vsp_down_time = 2;
    vm_down_time = vsp_down_time + 2 + 2;
    vcc_down_time = vm_down_time + 2 + 2;
    frame.can_id = 0x2C;  frame.can_dlc = 0x08; // 上升延时
    frame.data[0] = 0x03; // 上升延时
    frame.data[1] = 0x04;
    frame.data[2] = vcc_up_time % 256; // vcc 低8位
    frame.data[3] = vcc_up_time / 256; // vcc 高8位
    frame.data[4] = vsp_up_time % 256; // vsp 低8位
    frame.data[5] = vsp_up_time / 256; // vsp 高8位
    frame.data[6] = vm_up_time % 256;  // vm  低8位
    frame.data[7] = vm_up_time / 256;  // vm  高8位
    canSend(frame, wTest_Surface);
    for (j = 0; j < 10; j++) { // 下发参数延时等待 10ms
        usleep(1000);
    }
    frame.can_id = 0x2C;  frame.can_dlc = 0x08; // 下降延时
    frame.data[0] = 0x03; // 下降延时
    frame.data[1] = 0x05;
    frame.data[2] = vcc_down_time % 256; // vcc 低8位
    frame.data[3] = vcc_down_time / 256; // vcc 高8位
    frame.data[4] = vsp_down_time % 256; // vsp 低8位
    frame.data[5] = vsp_down_time / 256; // vsp 高8位
    frame.data[6] = vm_down_time % 256;  // vm  低8位
    frame.data[7] = vm_down_time / 256;  // vm  高8位
    canSend(frame, wTest_Surface);
    for (j = 0; j < 10; j++) { // 下发参数延时等待 10ms
        usleep(1000);
    }
    frame.can_id = 0x2C;  frame.can_dlc = 0x08; // vcc vsp 供电方式
    frame.data[0] = 0x03; //
    frame.data[1] = 0x06;
    frame.data[2] = 0x00; // 00 驱动外置 01 驱动内置
    frame.data[3] = 0x00; // vsp 00 pwm 01
    canSend(frame, wTest_Surface);
    for (j = 0; j < 10; j++) { // 下发参数延时等待 10ms
        usleep(1000);
    }
    frame.can_id = 0x2C;  frame.can_dlc = 0x01; // 启动电机
    frame.data[0] = 0x13; // 启动电机
    canSend(frame, wTest_Surface);
    for (j = 0; j < 10; j++) { // 下发参数延时等待 10ms
        usleep(1000);
    }
    frame.can_id = 0x2C;  frame.can_dlc = 0x05;  //启动三角形
    frame.data[0] = 0x01; // 启动测试
    frame.data[1] = Station_Chose - 0x12;
    frame.data[2] = 0xfe; //
    frame.data[3] = (int)(strBEMF.at(4).toDouble()*1000)%256;
    frame.data[4] = (int)(strBEMF.at(4).toDouble()*1000)/256;
    canSend(frame, wTest_Surface);
    for (j = 0; j < 10; j++) { // 下发参数延时等待 10ms
        usleep(1000);
    }
    qDebug() << "Start BEMF wait------------------------";

    qDebug() << "PG_Test_State" << PG_Test_State;
    if ((PG_Test_State == 0xA3) || (PG_Test_State == 10)) {
        //
    } else {
        Can_Stop(0x2c);
        join_updatedata(QStringList("")); // 更新数据
        // 上传状态
        return;
    }

    frame.can_id = 0x2C; //-PG
    frame.can_dlc = 0x01;
    frame.data[0] = 0x00;
    canSend(frame, 88); usleep(1000); usleep(1000); usleep(1000);

    qDebug() << "启动定时器";
    Signal_Test_to_Main(FG_Conf_Item.at(2).toInt()%1000+7, 6); // 启动定时器读取状态
    BEMF_Issue_Ing = false;
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.6.6
  * brief:      停止测试(参数为各个板子的ID)
******************************************************************************/
void w_Test::Can_Stop(int Can_Id)
{
    frame.can_id = Can_Id;  frame.can_dlc = 0x01;
    frame.data[0] = 0x02;
    canSend(frame, wTest_Surface);
    usleep(500);
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:
  * brief:      测试界面进行警告提示
******************************************************************************/
void w_Test::Test_WMessage(int number,QString Waring_Text)
{
    if (START_Model == 3) {
        WriteMessage((6000), 0x23, QString::number(2100*number).toUtf8());
    } else if ((Ini_Vacuum_Model) && (START_Model == 2)) {
        WriteMessage((6000), 0x23, QString::number(2100*number).toUtf8());
    } else {
        if (Test_Waring_Flag) {
            return;
        }
        Test_Waring_Flag = true;
        Test.Status_Ing = Test_Station_Inte;  // 2017-12-28 改为中断
        Test_Judge_State("NG");
        label_Waring->show();
        QMessageBox *message = new QMessageBox(this);
        message->setWindowFlags(Qt::FramelessWindowHint);
        message->setStyleSheet("QMessageBox{border: gray;border-radius: 10px;" \
                               "padding:2px 4px;background-color: gray;height:390px;width:375px;}");
        message->setText("\n" + Test_Message.at(number) + Waring_Text +"\n");
        message->addButton(QMessageBox::Ok)->setStyleSheet("height:39px;width:75px;" \
                               "border:5px groove;border:none;border-radius:10px;padding:2px 4px;");
        message->setButtonText(QMessageBox::Ok, QString(tr("确 定")));
        message->setIcon(QMessageBox::Warning);
        message->exec();
        Test_Waring_Flag = false;
        Test.Status_Ing  = Test_Station_Free;
        label_Waring->hide();
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      柱状图显示
******************************************************************************/
void w_Test::on_button_shape_clicked()
{
    this->releaseKeyboard();  Non_barcode_scanner = true;
    int i = 0;
    Test.Status_Ing = Test_Station_Inte;
    label_Waring->show();
    Histogram_Widget->show();
    PushHist_Count_Text[1]->setText(QString::number(Test_Count));
    PushHist_Count_Text[2]->setText(QString::number(Qualified));
    for (i = 3; i < Ini_Proj.size() + 2; i++) { // +2 == -1+3
        PushHist_Count_Text[i]->setText(QString::number(Error_Item[Ini_Proj.at(i - 2).toInt()]));
    }
    if (Test_Count != 0) {
        PushHist_List[2]->setFixedHeight(250*Qualified/Test_Count);
        for (i = 3; i < Ini_Proj.size() + 2; i++) { // +2 == -1+3
            PushHist_List[i]->setFixedHeight(250*(Error_Item[Ini_Proj.at(i-2).toInt()])/Test_Count);
        }
    } else {
        for (i = 3; i < Ini_Proj.size() + 2; i++) { // +2 == -1+3
            PushHist_List[i]->setFixedHeight(0);
        }
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      功率界面的显示窗口
******************************************************************************/
void w_Test::Test_PWR_Widget(double volt, int value)
{
    char copystr[256];
    char *whom;
    if (Conf_Item[Test.Finshed_Count].toInt() == 1) { // -测试假功率
        PWR_Par_Widget->hide();
        if ((False_Test) && (value == 2) && (volt < 5)) { // -反电动势大于5V
            False_Test = false;
            Can_Start_DLR_True();
        } else if (volt > 5) {
            join_test_stop(3);
        //  Test_WMessage(6, QString::number(volt));
            whom = QString::number(volt).toUtf8().data();
            sprintf(copystr, QString(tr("反电动势高\n%sV\nSTOP")).toUtf8().data(), whom);
            Ask_Up_label->setAlignment(Qt::AlignCenter);
            Ask_Up_label->setText(copystr);
            Ask_Widget->show();
        } else {
            //
        }
    } else {
        //
    }
    if (Conf_Item[Test.Finshed_Count].toInt() == 7) {
        if ((value == 1) && (strPWR.at(2).toInt() == 2)) {
            PWR_Par_Widget->show();
        } else if (value == 2) {
            PWR_Par_Widget->hide();
        } else {
            PWR_Par_Widget->hide();
        }
    } else {
        PWR_Par_Widget->hide();
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      主页面传递信息到Test
******************************************************************************/
void w_Test::Pub_Main_to_test(QStringList list, QString str, int value, int flag)
{
    int i;
    QString A1, A2, A3;
    switch (flag) {
    case 1:
        Test_Overtime_Alarm(value);
        break;
    case 2:
        Test_KEY_Surface(str);
        break;
    case 3:
        Test_Background_Param(list);
        break;
    case 5:
        Test_Get_Temp(str);
        break;
    case 6:
        Pri_Ask_Test_Current();
        break;
    case 7:
        Test_PWR_Widget(str.toDouble(), value);
        break;
    case 8:
        InitTest_Interface(list);
        break;
    case 9:
        Signal_test_to_Switchover(ZhongTe, 0, 1);
        join_updateTime();
        PWR_Par_Widget->hide();
        Test.Status_Ing = Test_Station_Free;
        break;
    case 10:
        qDebug() << "Test-2017-12-19 Net single item test" << str << Test.Status_Ing;
        if (Test.Status_Ing  ==  Test_Station_Busy) {
            //
        } else {
            qDebug() << "Test-2018-01-18 ------------- return";
            return;
        }
        if (str == QString(tr("DCR"))) {
            NetTest_Ready_DLR = true;
            Can_Start_DLR();
        } else if (str == QString(tr("MAG"))) {
            NetTest_Ready_MAG = true;
            Can_Start_MAG();
        } else if (str == QString(tr("IR"))) {
            NetTest_Ready_IR = true;
            Can_Start_IR();
        } else if (str == QString(tr("ACW"))) {
            NetTest_Ready_ACW = true;
            Can_Start_ACW();
        } else if (str == QString(tr("IMP"))) {
            NetTest_Ready_IMP = true;
            Can_Start_IMP();
        } else if (str == QString(tr("IND"))) {
            NetTest_Ready_IND = true;
            Can_Start_INDL();
        } else if (str == QString(tr("HALL"))) {
            NetTest_Resdy_HALL = true;
            Can_Start_BLDCHALL();
        } else if (str == QString(tr("LOAD"))) {
            NetTest_Resdy_LOAD = true;
            Can_Start_LOAD();
        } else if (str == QString(tr("NOLOAD"))) {
            NetTest_Resdy_NOLOAD = true;
            Can_Start_NOLOAD();
        } else if (str == QString(tr("BEMF"))) {
            NetTest_Resdy_BEMF = true;
            Can_Start_BEMF();
        } else {
            //
        }
        break;
    case 11:
        if (START_Model == 1) { // -脚踏启动
            if (Test.Status_Ing == Test_Station_Ask) {
                return;
            } else {
                //
            }
        } else {
            //
        }
        join_test_start(str.toInt(), value);
        break;
    case 12:
        if (Kongshi_Stall) {
            Kongshi_Stall = false;
            Pri_main_to_test_four(QString(""), 110);
        }
        qDebug() << "2017-12-13 Test-12" << Test.Status_Ing << NetTest_Ready_IMP;
        if ((Test.Status_Ing == Test_Station_Busy) && (Connect_Test)) {
            if (NetTest_Ready_DLR) {
                for (i = 0; i < DCR_Total_Number; i++) {
                    join_updatedata(QStringList(""));
                }
                qDebug() << "Test 2017-12-20------> DLR Stop Update";
                return;
            } else if (NetTest_Ready_MAG) {
                for (i = 0; i < MAG_Total_Number; i++) {
                    join_updatedata(QStringList(""));
                }
                qDebug() << "Test 2017-12-20------> MAG Stop Update";
                return;
            } else if (NetTest_Ready_IR)  {
                IRFinsh = true;
                for (i = 0; i < 1; i++) {
                    join_updatedata(QStringList(""));
                }
                qDebug() << "Test 2017-12-20------> IR Stop Update";
                return;
            } else if (NetTest_Ready_ACW) {
                IRFinsh = true;
                for (i = 0; i < 1; i++) {
                    join_updatedata(QStringList(""));
                }
                qDebug() << "Test 2017-12-20------> ACW Stop Update";
                return;
            } else if (NetTest_Ready_IMP) {
                for (i = 0; i < IMP_Total_Number; i++) {
                    join_updatedata(QStringList(""));
                }
                qDebug() << "Test 2017-12-20------> IMP Stop Update";
                return;
            } else if (NetTest_Ready_IND) {
                for (i = 0; i < INDL_Total_Number; i++) {
                    join_updatedata(QStringList(""));
                }
                qDebug() << "Test 2017-12-20------> INDL Stop Update";
                return;
            } else if (NetTest_Resdy_HALL)   {
                join_updatedata(Hall_Update);
                qDebug() << "Test 2017-12-20------> HALL Stop Update";
                return;
            } else if (NetTest_Resdy_LOAD)   {
                join_updatedata(QStringList(""));
                qDebug() << "Test 2017-12-20------> LOAD Stop Update";
                return;
            } else if (NetTest_Resdy_NOLOAD) {
                join_updatedata(QStringList(""));
                qDebug() << "Test 2017-12-20------> NOLOAD Stop Update";
                return;
            } else if (NetTest_Resdy_BEMF)   {
                join_updatedata(QStringList(""));
                qDebug() << "Test 2017-12-20------> BEMF Stop Update";
                return;
            } else {
                //
            }
            if (parameter_Issue_ing()) {
                //
            } else {
                return;
            }
        }

        if (Test_MAG_Ready) {
            Test_MAG_Ready = false;
            for (i = 0; i < MAG_Total_Number; i++) {
                join_updatedata(QStringList(""));
            }
            qDebug() << "Test 2017-12-20------> MAG Stop Update";
            return;
        } else if (Test_IMP_Ready) {
            Test_IMP_Ready = false;
            for (i = 0; i < IMP_Total_Number; i++) {
                join_updatedata(QStringList(""));
            }
            qDebug() << "Test 2017-12-20------> IMP Stop Update";
            return;
        } else if (Test_ACW_Ready) {
            Test_ACW_Ready = false;
            IRFinsh = true;
            for (i = 0; i < 1; i++) {
                join_updatedata(QStringList(""));
            }
            qDebug() << "Test 2017-12-20------> ACW Stop Update";
            return;
        } else {
            //
        }
        if (Conf_Item.size() == 0) {
            break;
        } else {
            //
        }


        qDebug() << "2018-01-24 Test-14" << Conf_Item << Test.Finshed_Count;
        Signal_test_to_Switchover(Noise,0x00,7);
        Noise_Stop->stop();
        ui->label_noise->hide();
        Ask_Widget->hide();
        IO_Test_Readying = false;
        IO_Pumb_Start->stop();
        IO_Delay_Start->stop();
        join_test_stop(value);
        Signal_test_to_Switchover(BePuDa,0x12,12);
        qDebug() << "2018-01-24 Test-13";
        break;
    case 14:
        Pri_Ask_Test_Current();
        break;
    case 15:
        Pri_Ask_Test_Continue();
        break;
    case 16:
        Test_GND_Volt = str.toInt(); // -获得测试对地线的电压
        Temp_In = value/Ini_AMPTemp;  In_Temp = value;
        Test_GND_Volt_List = list;
        break;

    case 18:
        Self_starting = list;
        break;
    case 19:
        if (((Test.Status_Ing == Test_Station_Busy) || (Test.Status_Ing == Test_Station_Ask)) \
                && (waveform_all_count%3 != 0)) { // -不为整形数据
            waveform_all_count = (waveform_all_count/3 + 1)*3;
        } else {
            //
        }
        break;
    case 20:
        wave[waveform_all_count%3]->Test_IMP_PP = (strITT.at(NUM_ITT*value + 2).toInt());
        break;
    case 21:
        IMP_Init_Wave(str);
        break;
    case 22:
        if (str==QString(tr("ABC"))) {
            Ini_ROT = true;
        }
        else {
            Ini_ROT = false;
        }
        break;
    case 26:
        if (value/10) { // 耐压判定
            qDebug() << "---Test-26 2017-12-15 ACW" << value%10;
            if (value%10) {
                Test_Model_Vacuum_ACW = true;
            } else {
                Test_Model_Vacuum_ACW = false;
            }
        } else { // 匝间判定
            qDebug() << "---Test-26 2017-12-15 IMP" << value%10;
            if (value%10) {
                Test_Model_Vacuum = true;
            } else {
                Test_Model_Vacuum = false;
            }
        }
        qDebug() << " Test_Model_Vacuum&&Test_Model_Vacuum_ACW" << Test_Model_Vacuum \
                 << Test_Model_Vacuum_ACW;
        if ((Test_Model_Vacuum) || (Test_Model_Vacuum_ACW)) {
            qDebug() << "Test 2017-12-15 Vacuum";
            Signal_test_to_pic(QStringList(""), 1, 12); // 打开真空泵
        } else {
            qDebug() << "Test 2017-12-15 !Vacuum";
            Signal_test_to_pic(QStringList(""), 2, 12); // 真空泵
        }
        break;
    case 27:
        qDebug() << "value" << value;
        if (value) {
            Start_No = true;
        } else {
            //
        }
        break;
    case 28:
        emit WriteMessage(6000, 0x73, QString(list.join(" ")).toUtf8()); // 传输上位机
        join_updatedata(list); //
        break;
    case 29:
        qDebug() << list;
        emit WriteMessage(6000, 0x73, QString(list.join(" ")).toUtf8());
        join_updatedata(list); //

        break;
    case 30:
        Hall_Update = list;
        break;
    case 118:
        Ini_IO_Delay_Time = value;
        qDebug()<<"Ini_IO_Delay_Time"<<Ini_IO_Delay_Time;
        break;
    case 120:
        A3 = "00000000";
        A1 = QString::number((int)(value / 256), 2);
        A2 = QString::number((int)(value % 256), 2);
        IO_Input_Data->setText(A3.mid(0, 8 - A1.size()) + A1 + " "\
                               + A3.mid(0, 8 - A2.size()) + A2);
        break;
    case 121:
        qDebug() << Test.serial_number;
        Test.serial_number = str.toUpper();
        ui->label_number->setText(tr("编号:") + Test.serial_number);
        qApp->processEvents();
        break;
    case 122:
        break;
    default:
        break;
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      匝间初始化左右工位波形参数
******************************************************************************/
void w_Test::IMP_Init_Wave(QString current_file)
{
    int j = 0, x = 0;
    QString Filename;
    Filename = QString("/mnt/nandflash/AIP/ConfFile/%1.ini").arg(current_file);
    QSettings set_File(Filename,  QSettings::IniFormat);
    QStringList imp_left_value = set_File.value("IMP/value").toStringList();
    QStringList imp_right_value = set_File.value("IMP/righvalue").toStringList();
    if (imp_left_value.size() < 6561) { // -判断(imp_right_value)是否丢失
        qDebug() << "imp_left_value Error" << imp_left_value.size();
        for (x = imp_left_value.size(); x < 6561; x++) {
            imp_left_value.append("0");
        }
    } else {
        qDebug() << "imp_left_value Right";
    }
    if (imp_right_value.size() < 6561) { // -判断(imp_right_value)是否丢失
        qDebug() << "imp_right_value Error" << imp_right_value.size();
        for (x = imp_right_value.size(); x < 6561; x++) {
            imp_right_value.append("0");
        }
    } else {
        qDebug() << "imp_right_value Right";
    }
    for (x = 0; x < 8; x++) {
        for (j = 0; j < 400; j++) { // -拉伸400个点
            IMP_Right_List[0]->sample_point[x][j] = \
                    imp_right_value.at(NUM_ITT*x + 20 + j).toInt()/4;
            IMP_Left_List[0]->sample_point[x][j] = \
                    imp_left_value.at(NUM_ITT*x + 20 + j).toInt()/4;
        }
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      堵转结果数据
******************************************************************************/
void w_Test::Test_Block_ResultData(QStringList list)
{
    Block_cycle++;
    if (Block_cycle == strBLOCK.at(203).toInt()) {
        BLOCK_list = list;
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      功率板结果数据
******************************************************************************/
void w_Test::Test_PWR_ResultData(QStringList list, int value)
{
    PWR_Display_Lable.at(0)->setText(list.at(0));
    PWR_Display_Lable.at(1)->setText(list.at(1));
    PWR_Display_Lable.at(2)->setText(list.at(2));
    PWR_Display_Lable.at(3)->setText(list.at(3));
    PWR_Display_Lable.at(4)->setText(list.at(4));
    PWR_Display_Lable.at(5)->setText(QString::number((list.at(5).toDouble())/10));
    PWR_Display_Lable.at(6)->setText(list.at(6));
    PWR_Display_Lable.at(7)->setText(list.at(7));
    PWR_Display_Lable.at(8)->setText(list.at(8));
    PWR_Display_Lable.at(9)->setText(list.at(9));

    if (value == 10) { // -低启
        if (strLVS.at(34).toDouble()*10 - list.at(5).toDouble() > 1) { // -0.4秒-不计算
            LVS_Result_Judge = list;
        } else {
            //
        }
    } else if (value == 7) { // -功率
        int PWR_Data = PWR_Test_Data.at(1 + PWR_Test_Count).toInt()/10;
        if (strPWR.at(45 + (PWR_Data)*20).toDouble()*10 - list.at(5).toDouble()> 1) { // 0.4秒不计算
            PWR_Result_Judge = list;
            qDebug() << "PWR_Result_Judge" << PWR_Result_Judge;
        }
    } else {
        //
    }
    qApp->processEvents();
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.1.5
  * brief:      测试超时报警
******************************************************************************/
void w_Test::Test_Overtime_Alarm(int Bug_Count)
{
    int t;
    if (Test.Status_Ing != Test_Station_Busy) { // -非忙碌状态
        return;
    }
    if (Ini_Vacuum_Model) {
        if (Bug_Count <= 70) {  // -真空等待计数小于180
            return;
        }
    } else {
        if (Bug_Count <= 60) {  // -非真空等待计数小于60
            return;
        }
    }

    if (Test.Status_Ing == Test_Station_Ask) { //-询问模式
        return;
    }
    if ((Test.Finshed_Count < Conf_Item.size()) && (!False_Test)) {
        switch (Conf_Item.at(Test.Finshed_Count).toInt()) {
        case 1:
            frame.can_id = 0x22;  frame.can_dlc = 0x01;
            frame.data[0] = 0x00;
            canSend(frame, 99);
            break;
        case 8:
            frame.can_id = 0x26;  frame.can_dlc = 0x02;
            frame.data[0] = 0x07;
            frame.data[1] = 0x00;
            canSend(frame, 99);
            break;
        default:
            break;
        }
    } else {
        //
    }
    if ((Bug_Count) > 100) {
        Bug_Count = 0;
        qDebug() << "No result return stop";
        Test_Beep_State(Beep.NG_Time, "NG");
        Sigtest_Usart_Send(QString("LEDR").toLatin1().data());
        Test_Judge_State("NG");
        Test.Status_Ing = Test_Station_Free;
        frame.can_id  = 0x2C;  frame.can_dlc = 0x02; // 高压回路
        frame.data[0] = 0x12; // 高压回路
        frame.data[1] = 0x00;
        canSend(frame, wTest_Surface);
        usleep(500);
        join_test_stop(2);
        if (False_Test) {
             False_Test = false;
        //   Test_WMessage(7, QString(tr("")));
             Ask_Up_label->setAlignment(Qt::AlignCenter);
             Ask_Up_label->setText(tr("反电动势\n无结果\nSTOP"));
             Ask_Widget->show();
             t = 100;
        } else {
            Ask_Up_label->setAlignment(Qt::AlignCenter);
            Ask_Up_label->setText(tr("%1板异常\n停止测试").arg\
                                  (Test_Item.at(Conf_Item.at(Test.Finshed_Count).toInt())));
            Ask_Widget->show();
            t = ((Conf_Item.at(Test.Finshed_Count).toInt()));
        }

        Test_Record(QString::number(t));

    } else {
        //
    }
}
void w_Test::Test_Record(QString Text = "") {
    QString currentDateTime = QDateTime::currentDateTime().toString \
            ("yyyy-MM-dd---hh-mm-ss"); // -设置显示格式
    QSettings set_Test_File(Test_Day_Record_e, QSettings::IniFormat);
    QDir *temp = new QDir;
    bool exist = temp->exists(Test_Day_Record_e);
    if (exist) {
        qDebug() << "Day_Record File     exist";
    } else {
        qDebug() << "Day_Record File Not Exist";
        system("mkdir /mnt/nandflash/AIP/dayrecord/");
        system("touch /mnt/nandflash/AIP/dayrecord/day.ini");
        system("chmod +x /mnt/nandflash/AIP/dayrecord/day.ini");
    }
    QString keyname;
    keyname = QString("%1/%2").arg(Text).arg(currentDateTime);
    set_Test_File.setValue(keyname, "Error");
    system("sync");
}

void w_Test::Pri_main_to_test_four(QString str,int bug_count)
{
    str.clear();
    if (Kongshi_Stall) {
        Kongshi_Stall_Time++;
        qDebug() << "Kongshi_Stall_Time" << Kongshi_Stall_Time;
        if (Kongshi_Stall_Time > 10) {
            //
        } else {
            return;
        }
    } else {
        //
    }

    if ((Test.Status_Ing == Test_Station_Busy) && (bug_count > 60)) {
        qDebug() << "Pri_main_to_test_four";
        if ((Test.Finshed_Count < Conf_Item.size()) && (False_Test == 0)) {
            switch (Conf_Item.at(Test.Finshed_Count).toInt()) {
            case 1:
                frame.can_id = 0x22;
                frame.can_dlc = 0x01;
                frame.data[0] = 0x00;
                canSend(frame, 99);
                break;
            case 8:
                frame.can_id = 0x26;
                frame.can_dlc = 0x02;
                frame.data[0] = 0x07;
                frame.data[1] = 0x00;
                canSend(frame, 99);
                break;
            default:
                break;
            }
        }
        if ((bug_count) > 100) {
            qDebug() << "无结果返回停止";
            bug_count = 0;
            Test_Beep_State(Beep.NG_Time, "NG");
            Sigtest_Usart_Send(QString("LEDR").toLatin1().data());
            Sigtest_Usart_Send(QString("LEDR").toLatin1().data());
            Test_Judge_State("NG");

            Test.Status_Ing = Test_Station_Free;
            join_test_stop(2);
            Ask_Up_label->setAlignment(Qt::AlignCenter);
            Ask_Up_label->setText(tr("%1板异常\n停止测试").arg\
                                  (Test_Item.at(Conf_Item.at(Test.Finshed_Count).toInt())));
            Ask_Widget->show();
        }
    }
}

/***********************************************************
* @name	 	MagDir_Test
* @brief  	磁场旋向测试函数
* @param  	None
* @retval 	None
***********************************************************/
void w_Test::Test_Mag_MagDir(QString str, int mag_rotation)
{
    uint16_t i = 0, j = 0;
    int16_t  temp = 0;
    // 计算主副相的面积，差积，和左右移动的差积
    uint32_t area1, area2, diff, diff1, diff2;
    area1 = 0;
    area2 = 0;
    diff = 0;
    diff1 = 0;
    diff2 = 0;
    if(str==QString(tr("one"))) {
        area1=0; area2=0;
        diff=0;  diff1=0; diff2=0;
        for (i = 10; i < 390; i++) { // -波形差积-410改为390
            temp = (TaskMagDirstrList[0][i].toInt()) - 0x80;
            area1 += temp*temp;
            temp = (TaskMagDirstrList[1][i].toInt()) - 0x80;
            area2 += temp*temp;
            // 差积
            temp = (TaskMagDirstrList[0][i].toInt() - TaskMagDirstrList[1][i].toInt());
            diff += temp*temp;
            // 移相后的差积
            // area2+=MagBuf.wave[AssistantItem-5][i]*MagBuf.wave[AssistantItem-5][i];
            for (j = 1; j < 11; j++) {
                temp = (TaskMagDirstrList[0][i].toInt() - TaskMagDirstrList[1][i+j].toInt());
                // -副相左移  point
                diff1 += temp*temp;
                temp = (TaskMagDirstrList[0][i].toInt() - TaskMagDirstrList[1][i-j].toInt());
                // -副相右移  pointgreen
                diff2 += temp*temp;
            }
        }
        diff1 = diff1/10;
        diff2 = diff2/10;
        if (((diff*3 < area1) && (diff*3 < area2)) || (area1 < (area2>>4)) || (area2 < (area1>>4))) {
            TaskMagDirnumber = 2;
        } else {
            if (diff1 < diff2) { // -副相在前
                if (mag_rotation == 0) {
                    TaskMagDirnumber = 1;
                } else {
                    TaskMagDirnumber = 0;
                }
            } else if (diff1 > diff2) {  // -主相在前
                if (mag_rotation == 0) {
                    TaskMagDirnumber = 0;
                } else {
                    TaskMagDirnumber = 1;
                }
            } else {
                TaskMagDirnumber = 2;
            }
        }
        if (Ini_ROT) {
            qDebug()<<"Ini_ROT---if";
        }
        else {
            TaskMagDirstrList[0].clear();
            TaskMagDirstrList[1].clear();
            return;
        }
    } else if(str==QString(tr("two"))) {
        area1=0; area2=0;
        diff=0;  diff1=0; diff2=0;
        for (i = 10; i < 390; i++) { // -波形差积-410改为390
            temp = (TaskMagDirstrList[1][i].toInt()) - 0x80;
            area1 += temp*temp;
            temp = (TaskMagDirstrList[2][i].toInt()) - 0x80;
            area2 += temp*temp;
            // 差积
            temp = (TaskMagDirstrList[1][i].toInt() - TaskMagDirstrList[2][i].toInt());
            diff += temp*temp;
            // 移相后的差积
            // area2+=MagBuf.wave[AssistantItem-5][i]*MagBuf.wave[AssistantItem-5][i];
            for (j = 1; j < 11; j++) {
                temp = (TaskMagDirstrList[1][i].toInt() - TaskMagDirstrList[2][i+j].toInt());
                // -副相左移  point
                diff1 += temp*temp;
                temp = (TaskMagDirstrList[1][i].toInt() - TaskMagDirstrList[2][i-j].toInt());
                // -副相右移  pointgreen
                diff2 += temp*temp;
            }
        }
        diff1 = diff1/10;
        diff2 = diff2/10;


        if(((diff*3<area1)&&(diff*3<area2))||(area1<(area2>>4))||(area2<(area1>>4)))
        {
            TaskMagDirnumber_ROT=2;
        }
        else
        {
            if(diff1<diff2)     //副相在前
            {
                if(mag_rotation==0)
                {
                    TaskMagDirnumber_ROT=1;
                }
                else
                {
                    TaskMagDirnumber_ROT=0;
                }
            }
            else if(diff1>diff2)//主相在前
            {
                if(mag_rotation==0)
                {
                    TaskMagDirnumber_ROT = 0;
                }
                else
                {
                    TaskMagDirnumber_ROT = 1;
                }
            }
            else
            {
                TaskMagDirnumber_ROT = 2;
            }
        }

        if (TaskMagDirnumber_ROT!=TaskMagDirnumber) {
            qDebug()<<"TaskMagDirnumber_ROT"<<TaskMagDirnumber_ROT<<"TaskMagDirnumber"<<TaskMagDirnumber;
            qDebug()<<"测试转向---不合格";
            TaskMagDirnumber = strOPP.at(6).toInt()+1;
            TaskMagDirnumber = TaskMagDirnumber%2;
        }
        else {
            qDebug()<<"TaskMagDirnumber_ROT"<<TaskMagDirnumber_ROT<<"TaskMagDirnumber"<<TaskMagDirnumber;
            qDebug()<<"测试转向---合格";
        }
        TaskMagDirstrList[0].clear();
        TaskMagDirstrList[1].clear();
        TaskMagDirstrList[2].clear();
    } else {

    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      询问重测时，删除行信息
******************************************************************************/
void w_Test::Test_Delete_Row(int value)
{
    int i = 0, j = 0, PWR_Data = 0;
    qDebug() << "Test_Delete_Row----------" << value << Test.Status_Ing;
    int PG_True = 0;
    switch (value) {
    case 1: // -电阻
        if ((DLR_UpDown.at(20).toDouble() != 0.000) && (DCR_Total_Number >= 3)) { // -包含电阻不平衡度
            strResult = strResult.mid(0, strResult.size() - DCR_Total_Number - 1);
            StrResult_Size = strResult.size();
            strJudge = strJudge.mid(0, strJudge.size() - DCR_Total_Number - 1);
            StrJudge_Size = strJudge.size();
            Test.Current_Row = Test.Current_Row - DCR_Total_Number - 1;
        } else {
            strResult = strResult.mid(0, strResult.size() - DCR_Total_Number);
            StrResult_Size = strResult.size();
            strJudge = strJudge.mid(0, strJudge.size() - DCR_Total_Number);
            StrJudge_Size = strJudge.size();
            Test.Current_Row = Test.Current_Row - DCR_Total_Number;
        }
        break;
    case 2: // -反嵌
        if (TaskMagDirnumber != 5) { // -包含转向
            strResult = strResult.mid(0, strResult.size() - MAG_Total_Number - 1);
            StrResult_Size = strResult.size();
            strJudge = strJudge.mid(0, strJudge.size() - MAG_Total_Number - 1);
            StrJudge_Size = strJudge.size();
            Test.Current_Row = Test.Current_Row - MAG_Total_Number - 1;
        } else {
            strResult = strResult.mid(0, strResult.size() - MAG_Total_Number);
            StrResult_Size = strResult.size();
            strJudge = strJudge.mid(0, strJudge.size() - MAG_Total_Number);
            StrJudge_Size = strJudge.size();
            Test.Current_Row = Test.Current_Row - MAG_Total_Number;
        }
        waveform_all_count = waveform_all_count - ((MAG_Total_Number-1)/3 + 1)*3; // -处理波形
        WavePoint_strList[(waveform_row_count-1)*3 + 0].clear();
        WavePoint_strList[(waveform_row_count-1)*3 + 1].clear();
        WavePoint_strList[(waveform_row_count-1)*3 + 2].clear();
        waveform_row_count--;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 400; j++) {
                wave[i]->point[j] = 0;
                wave[i]->pointgreen[j] = 0;
            }
            wave[i]->num = 400;
            wave[i]->Test_Shape = 0;
            wave[i]->update();
            wave_name[i]->setText(tr("测试项")); // -清空测试项
        }
        break;
    case 3: // -绝缘
        strResult = strResult.mid(0, strResult.size() - 1);
        StrResult_Size = strResult.size();
        strJudge = strJudge.mid(0, strJudge.size()-1);
        StrJudge_Size = strJudge.size();
        Test.Current_Row = Test.Current_Row - 1;
        if (Ini_ACWandIR) {
            IR_Test_Count--;
        } else {
            //
        }
        break;
    case 4: // -交耐
        strResult = strResult.mid(0, strResult.size() - 1);
        StrResult_Size = strResult.size();
        strJudge = strJudge.mid(0, strJudge.size() - 1);
        StrJudge_Size = strJudge.size();
        Test.Current_Row = Test.Current_Row - 1;
        if (Ini_ACWandIR) {
            ACW_Test_Count--;
        } else {
            //
        }
        break;
    case 5: // -直耐
        //
        break;
    case 6: // -匝间
        strResult = strResult.mid(0, strResult.size() - IMP_Total_Number);
        StrResult_Size = strResult.size();
        strJudge = strJudge.mid(0, strJudge.size() - IMP_Total_Number);
        StrJudge_Size = strJudge.size();
        Test.Current_Row = Test.Current_Row - IMP_Total_Number;
        waveform_all_count = waveform_all_count - ((IMP_Total_Number-1)/3 + 1)*3; // -处理波形
        WavePoint_strList[(waveform_row_count-1)*3 + 0].clear();
        WavePoint_strList[(waveform_row_count-1)*3 + 1].clear();
        WavePoint_strList[(waveform_row_count-1)*3 + 2].clear();
        waveform_row_count--;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 400; j++) {
                wave[i]->point[j] = 0;
                wave[i]->pointgreen[j] = 0;
            }
            wave[i]->num = 400;
            wave[i]->Test_Shape = 0;
            wave[i]->update();
            wave_name[i]->setText(tr("测试项")); // -清空测试项
        }
        break;
    case 7: // -功率
        if (PWR_Test_Data.at(0).toInt() == PWR_Test_Count) {
            Test.Next_Finsh_Count++;
        }
        PWR_Test_Count--;
        if (Ini_Pwr_Turn) { // -假转子测试
            //
        } else {
            strResult = strResult.mid(0, strResult.size() - 1);
            StrResult_Size = strResult.size();
            strJudge = strJudge.mid(0, strJudge.size() - 1);
            StrJudge_Size = strJudge.size();
            Test.Current_Row = Test.Current_Row - 1;
        }
        PWR_Data = PWR_Test_Data.at(1 + PWR_Test_Count).toInt()/10;
        if (strPWR.at(44 + (PWR_Data)*20).toInt()) { // -包含转向
            strResult = strResult.mid(0, strResult.size() - 1);
            StrResult_Size = strResult.size();
            strJudge = strJudge.mid(0, strJudge.size() - 1);
            StrJudge_Size = strJudge.size();
            Test.Current_Row = Test.Current_Row - 1;
        }
        if ((Ini_Motor == QString(tr("PG"))) && (strPWR.at(5+PWR_Data).toInt() == 2)) { // -包含PG
            qDebug() << "PWR_Test_Count" << PWR_Test_Count;
            qDebug() << "waveform_all_count" << waveform_all_count;
            PG_True = PG_Test_Order.at(PWR_Test_Count).toInt() - 1;
            qDebug() << "PG_True" << PG_True;
            if (PWR_Test_Data.at(0).toInt() == PWR_Test_Count+1) {
                waveform_all_count = waveform_all_count - 3 + PG_True + 1 - 1;
            } else {
                waveform_all_count = waveform_all_count - 1;
            }
            if (waveform_all_count%3 == 0) {
                waveform_row_count--;
            }
            strResult = strResult.mid(0, strResult.size() - 1);
            StrResult_Size = strResult.size();
            strJudge  = strJudge.mid(0, strJudge.size() - 1);
            StrJudge_Size  = strJudge.size();
            PG_Result_List.removeLast();
            Test.Current_Row = Test.Current_Row - 1;
            for (j = 0; j < 400; j++) {
                wave[PG_True]->point[j] = 0;
                wave[PG_True]->pointgreen[j] = 0;
            }
            wave[PG_True]->num = 400;
            wave[PG_True]->Test_Shape = 0;
            wave[PG_True]->update();
            wave_name[PG_True]->setText(tr("测试项")); // -清空测试项
        }
        break;
    case 8: //-电感
        if (((strINDL.at(1) != "0.0")) && (INDL_Total_Number >= 3)) { // -包含电感不平衡度
            strResult = strResult.mid(0, strResult.size() - INDL_Total_Number - 1);
            StrResult_Size = strResult.size();
            strJudge = strJudge.mid(0, strJudge.size() - INDL_Total_Number - 1);
            StrJudge_Size = strJudge.size();
            Test.Current_Row = Test.Current_Row-INDL_Total_Number - 1;
        } else {
            strResult = strResult.mid(0, strResult.size() - INDL_Total_Number);
            StrResult_Size = strResult.size();
            strJudge = strJudge.mid(0, strJudge.size() - INDL_Total_Number);
            StrJudge_Size = strJudge.size();
            Test.Current_Row = Test.Current_Row - INDL_Total_Number;
        }
        if (((strINDL.at(7).toDouble() != 0.0)) && (INDL_Total_Number >= 3)) {
            strResult = strResult.mid(0, strResult.size() - 1);
            StrResult_Size = strResult.size();
            strJudge = strJudge.mid(0, strJudge.size() - 1);
            StrJudge_Size = strJudge.size();
            Test.Current_Row = Test.Current_Row - 1;
        } else {
            //
        }
        break;
    case 9: // -堵转
        strResult = strResult.mid(0, strResult.size() - 1);
        StrResult_Size = strResult.size();
        strJudge = strJudge.mid(0, strJudge.size() - 1);
        StrJudge_Size = strJudge.size();
        Test.Current_Row = Test.Current_Row - 1;
        break;
    case 10: // -低启
        strResult = strResult.mid(0, strResult.size() - 1);
        StrResult_Size = strResult.size();
        strJudge = strJudge.mid(0, strJudge.size() - 1);
        StrJudge_Size = strJudge.size();
        Test.Current_Row = Test.Current_Row - 1;
        break;
    case 11: // HALL
        qDebug() << "HALL";
        qDebug() << strResult.size() << strJudge.size();
        strResult = strResult.mid(0, strResult.size() - FG_Test_Data.at(0).toInt() -1);
        StrResult_Size = strResult.size();
        strJudge = strJudge.mid(0, strJudge.size() - FG_Test_Data.at(0).toInt() -1);
        StrJudge_Size = strJudge.size();
        qDebug() << strResult.size() << strJudge.size();


      /*  if (PWR_Test_Data.at(0).toInt() == PWR_Test_Count+1) {
            waveform_all_count = waveform_all_count - 3 + PG_True + 1 - 1;
        } else {
            waveform_all_count = waveform_all_count - 1;
        }
        if (waveform_all_count%3 == 0) {
            waveform_row_count--;
        } */


        qDebug() << "waveform_all_count--1" << waveform_all_count;
        Test.Current_Row = Test.Current_Row - FG_Test_Data.at(0).toInt() -1;
        waveform_all_count = waveform_all_count - ((FG_Test_Data.at(0).toInt()-1)/3 + 1)*3; // -处理波形
        WavePoint_strList[(waveform_row_count-1)*3 + 0].clear();
        WavePoint_strList[(waveform_row_count-1)*3 + 1].clear();
        WavePoint_strList[(waveform_row_count-1)*3 + 2].clear();
        waveform_row_count--;
         qDebug() << "waveform_all_count--2" << waveform_all_count;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 400; j++) {
                wave[i]->point[j] = 0;
                wave[i]->pointgreen[j] = 0;
            }
            wave[i]->num = 400;
            wave[i]->Test_Shape = 0;
            wave[i]->update();
            wave_name[i]->setText(tr("测试项")); // -清空测试项
        }
        Shape_Hall_A.clear();
        Shape_Hall_B.clear();
        Shape_Hall_C.clear();
        FG_Test_Count = 0;
        FG_Shape_Count = 0;
        Test.Finshed_Count--;
        Test.Next_Finsh_Count--;
        qApp->processEvents();
        break;
    case 12: // 负载
        strResult = strResult.mid(0, strResult.size() - 1);
        StrResult_Size = strResult.size();
        strJudge = strJudge.mid(0, strJudge.size() - 1);
        StrJudge_Size = strJudge.size();
        Test.Current_Row = Test.Current_Row - 1;
        break;
    case 13: // 空载
        strResult = strResult.mid(0, strResult.size() - 1);
        StrResult_Size = strResult.size();
        strJudge = strJudge.mid(0, strJudge.size() - 1);
        StrJudge_Size = strJudge.size();
        Test.Current_Row = Test.Current_Row - 1;
        break;
    case 14: // BEMF
        strResult = strResult.mid(0, strResult.size() - 1);
        StrResult_Size = strResult.size();
        strJudge = strJudge.mid(0, strJudge.size() - 1);
        StrJudge_Size = strJudge.size();
        Test.Current_Row = Test.Current_Row - 1;
        break;
    default:
        //
        break;
    }
    qApp->processEvents();
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      询问Stop
******************************************************************************/
void w_Test::Pri_Ask_Test_Stop()
{
    join_test_stop(2);
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      询问Cancel
******************************************************************************/
void w_Test::Pri_Ask_Test_Cancel()
{
    Cancel_No_Save = true;
    join_test_stop(2);
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      询问重测当前
******************************************************************************/
void w_Test::Pri_Ask_Test_Current()
{
    if (Test.Status_Ing != Test_Station_Ask) {
        qDebug() << "Model is error ----Not Asking";
        return;
    } else {
        //
    }
    frame.can_id  = 0x22;  frame.can_dlc = 0x02;  // -输出板输出量信号发送
    frame.data[0] = 0x09;
    frame.data[1] = 0X04;
    canSend(frame, wTest_Surface);
    usleep(500);
    Ask_Widget->hide();
    label_Waring->hide();
    qDebug() << "Pri_Ask_Test_Current";
    if (Test.Next_Finsh_Count != Test.Finshed_Count) { //-进行项目之间（内部）的处理
        Test_Delete_Row(Conf_Item[Test.Finshed_Count].toInt());
        qDebug() << "1";
    } else {
        Test.Finshed_Count--;
        Test_Delete_Row(Conf_Item[Test.Finshed_Count].toInt());
        qDebug() << "2";
        Test.Next_Finsh_Count--;
    }
    Test.NG_Item = 0; // 重新测试
    Test_Start();
    Test.Status_Ing = Test_Station_Busy;
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      询问继续
******************************************************************************/
void w_Test::Pri_Ask_Test_Continue()
{
    if (Test.Status_Ing != Test_Station_Ask) {
        return;
    } else {
        //
    }
    if ((ui->label_6->text() == "") && (Test.Status_Ing != Test_Station_Free)) {
        frame.can_id = 0x22;  frame.can_dlc = 0x02;  //  输出板输出量信号发送
        frame.data[0] = 0x09;
        frame.data[1] = 0X04;
        canSend(frame, wTest_Surface);
        usleep(500);
        join_test_start(START_Model, Station_Chose);
    } else {
        //
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      询问退出
******************************************************************************/
void w_Test::Pri_Ask_Test_Exit()
{
    if (Test.Status_Ing != Test_Station_Ask) {
        qDebug() << "Model is error ----Not Asking";
        return;
    } else {
        //
    }
    Ask_Widget->hide();
    label_Waring->hide();
    Test.Status_Ing = Test_Station_Free;
    Sigtest_Usart_Send(QString("LED1").toLatin1().data());
    Test_Judge_State("");
    ui->label_station->setStyleSheet("color: rgb(255, 255, 255);border: none;"\
                                     "font:Bold 40pt Ubuntu;");
    Test_Ready();
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      按键板信息
******************************************************************************/
void w_Test::Test_KEY_Surface(QString USART)
{
    switch (USART.toInt()) {
    case 3:  // -重测当前
        //
        break;
    case 4:  // -重测全部
        //
        break;
    case 5:  // -退出
        //
        break;
    case 21: // -聚焦
        Test_Usart_Clicked("Point");
        break;
    case 20: // -下点击
        Test_Usart_Clicked("Down");
        break;
    case 19: // -上点击
        Test_Usart_Clicked("Up");
        break;
    case 22: // -下翻页
        on_button_down_clicked();
        break;
    case 23: // -上翻页
        on_button_up_clicked();
        break;
    case 26: // -返回
        on_button_back_clicked();
        break;
    case 27: // -参数设置
        on_button_set_clicked();
        break;
    default:
        break;
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.1.5
  * brief:      获取后台信息,蜂鸣器的档位 时间 启动模式 操作者 条码扫描的起始位 终止位
******************************************************************************/
void w_Test::Test_Background_Param(QStringList list)
{
    Beep.Grade   = (list[0].toInt()+1)*10-1;
    Beep.OK_Time = list[1].toDouble();
    Beep.NG_Time = list[2].toDouble();
    START_Model  = list[4].toInt();
    if ((START_Model == Start_model_Net) || ((START_Model == Start_model_Cover) \
                                             && (Ini_Vacuum_Model))) {
        Connect_Test = true;
    } else {
        Connect_Test = false;
    }
    if (list[5].toInt() == User_Administrators) {
        test_parameters[2]->setText(tr("操作者:管理员"));
    } else {
        test_parameters[2]->setText(tr("操作者:操作员"));
    }
    scan_scart = list.at(8).toInt(); qDebug() << "scan_scart" << list.at(8);
    scart_stop = list.at(9).toInt(); qDebug() << "scart_stop" << list.at(9);
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.1.5
  * brief:      配置PWR界面，参数返回
******************************************************************************/
QStringList w_Test::Pub_Set_PWR(can_frame frame)
{
    QStringList turn;
    turn.clear();
    turn.append(QString(tr("不转")));
    turn.append(QString(tr("反转")));
    turn.append(QString(tr("正转")));
    QStringList turn_Change;
    turn_Change.clear();
    turn_Change.append(QString(tr("不转")));
    turn_Change.append(QString(tr("正转")));
    turn_Change.append(QString(tr("反转")));
    if (frame.data[0] == 1) {
        Volt_A    = ((double)(frame.data[1]*256 + frame.data[2]))/10;
        Current_A = ((double)(frame.data[3]*256 + frame.data[4]))/1000; // -电流
        Pwr_A     = ((double)(frame.data[5]*256 + frame.data[6]))/10;   // -功率
    } else if (frame.data[0] == 2) {
        Freq_A = ((double)(frame.data[1]*256+frame.data[2]))/10;
        time   = frame.data[3]*256+frame.data[4];
        Dir    =  frame.data[5];
        Speed  = frame.data[6]*256+frame.data[7];
    } else if (frame.data[0] == 3) {
        Volt_B    = ((double)(frame.data[1]*256 + frame.data[2]))/10;   // -容压
        Current_B = ((double)(frame.data[3]*256 + frame.data[4]))/1000;
        Pwr_B     = ((double)(frame.data[5]*256 + frame.data[6]))/10;
    } else {
        //
    }

    QStringList data;
    if ((frame.data[0] == 2) && (time != 0)) {
    //  double C = Current_C/(2*3.141*50*Volt_B)*1000*1000;
        Pf_A = Pwr_A/Volt_A/Current_A;
        if (Pf_A  ==  Pf_A) {
            //
        } else {
             Pf_A = 0;
        }
        data.append(QString::number(Volt_A, 'f', 1));
        data.append(QString::number(Current_A, 'f', 3));
        data.append(QString::number(Pwr_A, 'f', 1));
        data.append(QString::number(Pf_A, 'f', 3));
        data.append(QString::number(Freq_A,  'f', 1));
        data.append(QString::number(time));
        data.append(QString::number(Volt_B, 'f', 1));
        data.append(QString("--")); // 保留容值
        // data.append(QString::number(C,'f',2));
        // C=I/(2*π*f*U);
        // -C=I/(2*π*f*U);
        if (Dir  <=  2) {
            if (Ini_Direction) {
                data.append(turn_Change.at(Dir));
            } else {
                data.append(turn.at(Dir));
            }
        } else {
            data.append(QString::number(Dir));
        }
        if (Hall_Speed  ==  0) {
            data.append(QString("  "));
        } else {
            data.append(QString::number(Hall_Speed));
        }
        Hall_Speed = 0;
    }
    return data;
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.2.10
  * brief:      配置PWR，设置PG
******************************************************************************/
QStringList w_Test::Pub_Set_PG(can_frame frame)
{
    double pg_speed;
    if (frame.data[0] == 1) {     // -电流,低电平,高电平
        pg_Cur = ((double)(frame.data[1]*256 + frame.data[2]))/100;
        pg_floor = ((double)(frame.data[3]*256 + frame.data[4]))/100;
        pg_up = ((double)(frame.data[5]*256 + frame.data[6]))/100;
    } else if (frame.data[0] == 2) { // -频率,min avr max
        pg_freq_min = ((double)(frame.data[1]*256 + frame.data[2]))/10;
        pg_freq_max = ((double)(frame.data[3]*256 + frame.data[4]))/10;
        pg_freq_avr = ((double)(frame.data[5]*256 + frame.data[6]))/10;
    } else if (frame.data[0] == 3) { // -占空比,min avr max
        pg_duty_min = ((double)(frame.data[1]*256 + frame.data[2]))/10;
        pg_duty_max = ((double)(frame.data[3]*256 + frame.data[4]))/10;
        pg_duty_avr = ((double)(frame.data[5]*256 + frame.data[6]))/10;
    } else {
        //
    }
    QStringList data;
    if (frame.data[0] == 3) {
        data.append(QString::number(pg_Cur, 'f', 2));      // -电流
        data.append(QString::number(pg_floor, 'f',  2));   // -低电平
        data.append(QString::number(pg_up, 'f', 2));       // -高电平
        data.append(QString::number(pg_freq_avr, 'f', 1)); // -频率
        data.append(QString::number(pg_duty_avr, 'f', 1)); // -占空比
        pg_speed = 60*pg_freq_avr/(strPWR.at(161).toInt());
        data.append(QString::number(pg_speed,'f',0));    // 速度
        qDebug() << "PG-Data-------" << data;
    } else {
        //
    }
    return data;
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      can信息，主页面传递给Test界面
******************************************************************************/
void w_Test::Pub_Main_can_to_test(can_frame canframe, int value)
{
    QStringList PWR_Back_List;
    QStringList PG_Back_List;
    switch (value) {
    case 1:
        if (Conf_Item[Test.Finshed_Count].toInt() == 1) {
            // -电阻进行前，获取反电动势
            if (canframe.data[0] == 1) {
                Turn_Elec_force = ((double)(canframe.data[1]*256 + canframe.data[2]))/10;
            } else {
                //
            }
        } else if (Conf_Item[Test.Finshed_Count].toInt() == 7) { // -功率(增加PG)
            if (canframe.data[0] < 10) { // -功率
                PWR_Back_List = Pub_Set_PWR(canframe);
                if ((canframe.data[0] == 2) && (PWR_Back_List != QStringList())) {
                    Test_PWR_ResultData(PWR_Back_List, Conf_Item[Test.Finshed_Count].toInt());
                }
            } else {
                //
            }
        } else if (Conf_Item[Test.Finshed_Count].toInt() == 9) { //-堵转
            if (canframe.data[0] == 1) { // -只获取A相
                PWR_Back_List.append(QString::number(((double)(canframe.data[3]*256 + \
                                                        canframe.data[4]))/1000, 'f', 3)); // -电流
                PWR_Back_List.append(QString::number(((double)(canframe.data[5]*256 + \
                                                      canframe.data[6]))/10, 'f', 1));   // -功率
                Test_Block_ResultData(PWR_Back_List);
            } else {
                //
            }
        } else if (Conf_Item[Test.Finshed_Count].toInt() == 10) { //-低启
            PWR_Back_List = Pub_Set_PWR(canframe);
            if ((canframe.data[0] == 2) && (PWR_Back_List != QStringList())) {
                Test_PWR_ResultData(PWR_Back_List, Conf_Item[Test.Finshed_Count].toInt()); // -低启
            } else {
                //
            }
        } else {
            //
        }
        break;
    case 2:
        Result_INDL = canframe.data[1];
        if (canframe.data[3] == 0) {      // 主参
            ResultReg.dat[0] = canframe.data[4];
            ResultReg.dat[1] = canframe.data[5];
            ResultReg.dat[2] = canframe.data[6];
            ResultReg.dat[3] = canframe.data[7];
            qDebug() << "G Main------" << ResultReg.Result;
            Result_Main = ResultReg.Result;
        } else if (canframe.data[3] == 1) { // 副参
            ResultReg.dat[0] = canframe.data[4];
            ResultReg.dat[1] = canframe.data[5];
            ResultReg.dat[2] = canframe.data[6];
            ResultReg.dat[3] = canframe.data[7];
            qDebug() << "G Q------" << ResultReg.Result;
            Result_Q = ResultReg.Result;
            join_updatedata(QStringList(""));
        } else {
            //
        }
        break;
    case 3:
        if (Test.Finshed_Count >= Conf_Item.size()) {
            qDebug() << "PG Error-------------------------Back";
            return;
        } else {
            //
        }

        if (Conf_Item[Test.Finshed_Count].toInt() == 7) {
            PG_Back_List = Pub_Set_PG(canframe); // -PG返回列表
            if ((canframe.data[0] == 3) && (PG_Back_List != QStringList())) {
                PG_list = PG_Back_List;
                if (PG_list.size() >= 6) {
                   Hall_Speed = PG_list.at(5).toDouble();
                } else {
                    //
                }
            } else {
                //
            }
        }
        break;
    default:
        break;
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.1.5
  * brief:      测试界面获取温度
******************************************************************************/
void w_Test::Test_Get_Temp(QString list)
{
    double Temp_Get = 0.0;
    if (strRES == QStringList()) {
        Temp_Get = list.toDouble();
    } else {
        Temp_Get = list.toDouble() + strRES.at(NUM_RES_Con+8).toDouble();
    }
    if (Temp_Get < 150) {
        Temp_Error = false;
        test_parameters[3]->setText(QString(tr("温度:")) + QString::number(Temp_Get, 'f', 1) + "°C");
    } else {
        Temp_Error = true;
        test_parameters[3]->setText(tr("温度:--°C"));
    }
    WriteMessage(6000, 0x76, test_parameters[3]->text().toUtf8());
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      条码扫描进行接收
******************************************************************************/
void w_Test::keyPressEvent(QKeyEvent  *event)
{
    key_board->stop();
    keyboard_string.append(event->text());
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      条码扫描结束
******************************************************************************/
void w_Test::keyReleaseEvent(QKeyEvent  *event)
{
    event->text();
    key_board->start(50);
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      条码扫描完毕
******************************************************************************/
void w_Test::join_key_out()
{
    key_board->stop();
    if (Non_barcode_scanner) {
        keyboard_string.clear();
        return;
    } else {
        //
    }
    if ((scan_scart == 0) && (scart_stop == 0)) {
        ui->label_number->setText(QString(tr("编号:")) + keyboard_string);
        Test.serial_number = keyboard_string;
    } else if ((scan_scart < keyboard_string.size()) && (scart_stop <= keyboard_string.size())) {
        ui->label_number->setText(QString(tr("编号:")) + \
                    keyboard_string.mid(scan_scart, scart_stop-scan_scart));
        Test.serial_number = keyboard_string.mid(scan_scart, scart_stop - scan_scart);
    } else if ((scan_scart < keyboard_string.size()) && (scart_stop > keyboard_string.size())) {
        ui->label_number->setText(QString(tr("编号:")) + \
                    keyboard_string.mid(scan_scart, keyboard_string.size() - scan_scart));
        Test.serial_number = keyboard_string.mid(scan_scart, keyboard_string.size() - scan_scart);
    } else if (scan_scart >= keyboard_string.size()) {
        ui->label_number->setText(QString(tr("编号:")));
        Test.serial_number = "";
    } else {
        ui->label_number->setText(QString(tr("编号:")));
        Test.serial_number = "";
    }
    keyboard_string.clear();
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      反嵌波形参数
******************************************************************************/
void w_Test::Pub_MAG_Param(QStringList mag_data, int *waveform_point)
{
    int i = 0;
    bool mag_waveform_error;
    int  mag_back_number = 0;
    bool mag_set_rotation;
    mag_waveform_error = mag_data.at(0).toInt();
    mag_back_number = mag_data.at(1).toInt();
    mag_set_rotation = mag_data.at(2).toInt();
    if (Ini_Mag_Hide == 0) {
        if (waveform_all_count%3 == 0) {
            for (i = 0; i < 3; i++) { // -3组数据清理
                wave[i]->Test_Shape = 0;
                wave[i]->num = 0;
                wave[i]->update();
            }
            waveform_row_count++;
        } else {
            //
        }
        if (mag_waveform_error) { // -采集波形有错误
            mag_waveform_error = false;
            for (i = 0; i < 400; i++) {
                waveform_point[i] = 128;
            }
        } else {
            //
        }
        for (i = 0; i < 400; i++) {
            wave[waveform_all_count%3]->point[i] = waveform_point[i];
            wave[waveform_all_count%3]->pointgreen[i] = 260;
        }
        wave[waveform_all_count%3]->num = 400;
        wave[waveform_all_count%3]->update();
        WavePoint_strList[(waveform_row_count-1)*3 + waveform_all_count%3]. \
                append(QString::number(1));
        WavePoint_strList[(waveform_row_count-1)*3 + waveform_all_count%3]. \
                append(QString::number(mag_back_number));
        WavePoint_strList[(waveform_row_count-1)*3 + waveform_all_count%3]. \
                append(QString::number(strResult.size()));
        WavePoint_strList[(waveform_row_count-1)*3 + waveform_all_count%3]. \
                append(QString::number(0));
        for (i = 0; i < 2; i++) {
            WavePoint_strList[(waveform_row_count-1)*3 + waveform_all_count%3]. \
                    append(QString::number(0));
        }
        for (i = 0; i < 400; i++) {
            WavePoint_strList[(waveform_row_count-1)*3 + waveform_all_count%3]. \
                    append(QString::number(waveform_point[i]));
        }
        Recrd_Wave = (waveform_row_count-1)*3 + waveform_all_count%3+1;
        ChangeLable(waveform_all_count%3, (waveform_row_count-1)*3 + waveform_all_count%3);
        // waveform_count = 0;  // -7.12 屏蔽
        waveform_all_count++;   // -记录波形的个数
    }
    if (strOPP.at(6).toInt() != 2) { // -判断磁旋不是 不测
        if ((mag_back_number == 2) || (mag_back_number == 1) || (mag_back_number == 0)) {
            for (i = 0; i < 400; i++) {
                TaskMagDirstrList[mag_back_number].append(QString::number(waveform_point[i]));
            }
        } else {
            //
        }
        if (mag_back_number == 1) {
            if (((strOPP.at(NUM_OPP*0+3).toInt()) == 2) && \
                    ((strOPP.at(NUM_OPP*1+3).toInt()) == 2)) {
                Test_Mag_MagDir(QString(tr("one")), mag_set_rotation); // -测试磁旋
            }
        } else {
            //
        }
        if ((mag_back_number == 2) && (Ini_ROT)) {
            if (((strOPP.at(NUM_OPP*1 + 3).toInt()) == 2) && \
                    ((strOPP.at(NUM_OPP*2 + 3).toInt()) == 2)) {
                Test_Mag_MagDir(QString(tr("two")), mag_set_rotation); // -测试磁旋
            }
        } else {

        }
    } else {
        //
    }
    if (strOPP.at(8).toInt() == 2) {
        Test_Mag_Trend(mag_back_number, waveform_point);
    }
    MAG_Current_Testing_Item = mag_back_number;
}

void w_Test::Test_Mag_Trend(int mag,int *waveform_point) {
    int i = 0;

    int H_data = 0, L_data = 0;
    H_data = 0;
    L_data = 0;
    bool Add_zero;
    Add_zero = false;
    int Max_point = 0,Min_point = 0;
    int zero_count = 0;
    zero_count = 0;

    QStringList zero_list;
    zero_list.clear();

    qDebug() << "mag" << mag;
    for (i = 0; i < 400; i++) {
        if ((waveform_point[i]) >= 128) {
            if (H_data == 0) {
                zero_list.append(QString::number(2000 + L_data));
            } else {
                //
            }
            H_data++;
            L_data = 0;
        } else {
            if (L_data == 0) {
                zero_list.append(QString::number(1000 + H_data));
            } else {
                //
            }
            L_data++;
            H_data = 0;
        }
    }
    zero_list.append(QString::number(2000 + L_data));
    zero_list.append(QString::number(1000 + H_data));

    qDebug() << "zero_list" << zero_list;
    Max_point = waveform_point[0];
    Min_point = waveform_point[0];
    for (i = 1; i < 10; i++) {
        if (waveform_point[i] <= Min_point) {
            Min_point = waveform_point[i];
        } else {
            //
        }
        if (waveform_point[i] > Max_point) {
            Max_point = waveform_point[i];
        } else {
            //
        }
    }
    for (i = 390; i < 400; i++) {
        if (waveform_point[i] <= Min_point) {
            Min_point = waveform_point[i];
        } else {
            //
        }
        if (waveform_point[i] > Max_point) {
            Max_point = waveform_point[i];
        } else {
            //
        }
    }
    if ((Min_point <= 128) && (Max_point >= 128)) {
        qDebug() << "1" << Min_point << Max_point;
        Add_zero = true;
    } else {
        qDebug() << "2";
    }

    QStringList zero_list_update;
    for (i = 0; i < zero_list.size(); i++) {
        if (zero_list.at(i).toInt()%1000 < 10) {
            //
        }
        else {
            zero_list_update.append(zero_list.at(i));
        }
    }

    if (zero_list_update.size() == 1) {
        qDebug() << "zero_count" << "0";
        mag_zero.replace(mag, QString::number(0));
        return;
    } else {
        //
    }

    for (i = 0; i < zero_list_update.size() - 1; i++) {
        if (zero_list_update.at(i).toInt()/1000 != \
                zero_list_update.at(i + 1).toInt()/1000) {
            zero_count++;
        } else {
            //
        }
    }

    if (Add_zero) {
        zero_count++;
    }

    mag_zero.replace(mag, QString::number(zero_count));
    qDebug() << "zero_count" << zero_count;

}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      匝间波形参数
******************************************************************************/
void w_Test::Pub_IMP_Param(QStringList imp_data, int *waveform_point, int *waveform_point_compare )
{
    int i = 0;
    bool imp_waveform_error;
    int  imp_back_number = 0;
    int  imp_count = 0;
    imp_waveform_error = imp_data.at(0).toInt();
    imp_back_number = imp_data.at(1).toInt();
    imp_count = imp_data.at(2).toInt();

    if (waveform_all_count%3 == 0) {
        for (i = 0; i < 3; i++) { // -3组数据清理
            wave[i]->num = 0;
            wave[i]->update();
        }
        waveform_row_count++;
    } else {
        //
    }
    if (imp_waveform_error) { // -采集波形有错误
        for (i = 0; i < 400; i++) {
            waveform_point[i] = 521;
        }
    } else {
        qDebug() << "Sampling waveform is right";
    }
    int Imp_Compare_Model = 0;
    qDebug() << "3";

    if (strITT.at(16).toInt() == 2) {
        Imp_Compare_Model = 0;               //-比较模式
        if (imp_back_number == 0) {
            if (Station_Chose == 0x13) {
                for (i = 0; i < 400; i++) {
                    IMP_Left_List[0]->sample_point[0][i] = waveform_point[i]/4;
                }
            } else {
                for (i = 0; i < 400; i++) {
                    IMP_Right_List[0]->sample_point[0][i] = waveform_point[i]/4;
                }
            }
        } else {
            //
        }
    } else if (strITT.at(17).toInt() == 2) {
        Imp_Compare_Model = 0;               //-比较模式
        if (imp_back_number == 0) {
//            if (Station_Chose == 0x13) {
//                for (i = 0; i < 400; i++) {
//                    IMP_Left_List[0]->sample_point[0][i] = waveform_point[i]/4;
//                }
//            } else {

//                for (i = 0; i < 400; i++) {
//                    IMP_Right_List[0]->sample_point[0][i] = waveform_point[i]/4;
//                }
//            }
        } else {
            Imp_Compare_Model = imp_back_number;
            if (Station_Chose == 0x13) {
                for (i = 0; i < 400; i++) {
                    IMP_Left_List[0]->sample_point[Imp_Compare_Model][i] = waveform_point_compare[i]/4;
                }
            } else {

                for (i = 0; i < 400; i++) {
                    IMP_Right_List[0]->sample_point[Imp_Compare_Model][i] = waveform_point_compare[i]/4;
                }
            }
        }
    } else {
        Imp_Compare_Model = imp_back_number; // -测试模式
    }
    if (Station_Chose == 0x13) {
        for (i = 0; i < 400; i++) {
            wave[waveform_all_count%3]->point[i] = \
                    IMP_Left_List[0]->sample_point[Imp_Compare_Model][i];
//            qDebug() << "IMP_Left_List[0]->sample_point[Imp_Compare_Model][i]" \
//                        << IMP_Left_List[0]->sample_point[Imp_Compare_Model][i];
            wave[waveform_all_count%3]->pointgreen[i] = waveform_point[i]/4;
//            qDebug() << "waveform_point[i]/4" \
//                        << waveform_point[i]/4;
        }
    } else {
        for (i = 0; i < 400; i++) {
            wave[waveform_all_count%3]->point[i] = \
                    IMP_Right_List[0]->sample_point[Imp_Compare_Model][i];
            wave[waveform_all_count%3]->pointgreen[i] = waveform_point[i]/4;
        }
    }
    wave[waveform_all_count%3]->Test_Shape = 1;
    wave[waveform_all_count%3]->num = 400;
    wave[waveform_all_count%3]->update();
    WavePoint_strList[(waveform_row_count-1)*3 + waveform_all_count%3].append \
            (QString::number(2));
    WavePoint_strList[(waveform_row_count-1)*3 + waveform_all_count%3].append \
            (QString::number(imp_back_number));
    WavePoint_strList[(waveform_row_count-1)*3 + waveform_all_count%3].append \
            (QString::number(strResult.size()));
    if (imp_waveform_error) {
        qDebug() << "imp_waveform_error" << imp_waveform_error << imp_count;
        WavePoint_strList[(waveform_row_count-1)*3 + waveform_all_count%3].append \
                (QString::number(imp_count));
    } else {
        WavePoint_strList[(waveform_row_count-1)*3 + waveform_all_count%3].append \
                (QString::number(wave[waveform_all_count%3]->Test_IMP_PP));
    }

    for (i = 0; i < 2; i++) {
        WavePoint_strList[(waveform_row_count-1)*3 + waveform_all_count%3].append \
                (QString::number(0));
    }

    for (i = 0; i < 400; i++) {
        WavePoint_strList[(waveform_row_count-1)*3 + waveform_all_count%3].append \
                (QString::number(waveform_point[i]));
    }
    if (Station_Chose == 0x13) {
        for (i = 0; i < 400; i++) {
            WavePoint_strList[(waveform_row_count-1)*3 + waveform_all_count%3].append \
                    (QString::number(IMP_Left_List[0]->sample_point[Imp_Compare_Model][i]));
        }
    } else {
        for (i = 0; i < 400; i++) {
            WavePoint_strList[(waveform_row_count-1)*3 + waveform_all_count%3].append \
                    (QString::number(IMP_Right_List[0]->sample_point[Imp_Compare_Model][i]));
        }
    }
    Data_Complete = true;
    Recrd_Wave = (waveform_row_count-1)*3 + waveform_all_count%3 + 1;
    ChangeLable(waveform_all_count%3, (waveform_row_count-1)*3 + waveform_all_count%3);
    // waveform_count = 0; // -7.12-屏蔽
    waveform_all_count++; // -记录波形的个数
    IMP_Current_Testing_Item = imp_back_number;
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.7.10
  * brief:      PWR-的参数
******************************************************************************/
void w_Test::Pub_PWR_Param(QStringList pg_data, int *waveform_point, int *waveform_point_c)
{
    if (Conf_Item[Test.Finshed_Count].toInt() == 1) {
        Test_PWR_Widget(Turn_Elec_force, 2);
        return;
    } else {
        //
    }
    Test_PWR_Widget(Turn_Elec_force, 2);
    PG_Param(pg_data, waveform_point, waveform_point_c);
    frame.can_id  = 0x29;  frame.can_dlc = 0x01; // -PG测试终止
    frame.data[0] = 0x02;
    canSend(frame, wTest_Surface);
    usleep(1000);
    join_updatedata(QStringList(""));
}

void w_Test::Pub_FG_Param(QStringList FG_shape)
{
    qDebug() << FG_shape.size() << FG_shape.at(0);
    switch (FG_shape.at(0).toInt()) {
    case 0:
        //
        break;
    case 1:
        //
        break;
    case 2:
        //
        break;
    case 3:
        Shape_Hall_A = FG_shape.mid(1,400);
        break;
    case 4:
        Shape_Hall_B = FG_shape.mid(1,400);
        break;
    case 5:
        Shape_Hall_C = FG_shape.mid(1,400);
        break;
    case 6:
        //
        break;
    case 7:
        //
        break;
    default:
        break;
    }
}

void w_Test::FG_Param(QStringList shape_list) // int *waveform_point
{
    int i;
    if (waveform_all_count%3 == 0) {
        for (i = 0; i < 3; i++) { // -3组数据清理
            wave[i]->Test_Shape = 0;
            wave[i]->num = 0;
            wave[i]->update();
        }
        waveform_row_count++;
    } else {
        //
    }
    /*波形显示*/

    if (shape_list.size() == 400) {
       //
    } else {
        shape_list.clear();
        for (i = 0; i < 400; i++) {
            shape_list.append(QString(tr("192")));
        }
    }
    for (i = 0; i < 400; i++) {
        wave[waveform_all_count%3]->point[i] = 260;
        wave[waveform_all_count%3]->pointgreen[i] = shape_list.at(i).toInt();
    }
    wave[waveform_all_count%3]->num = 400;
    wave[waveform_all_count%3]->update();
    // waveform_count = 0; //-7.12 屏蔽
    WavePoint_strList[(waveform_row_count-1)*3+waveform_all_count%3].append \
            (QString::number(4));
    WavePoint_strList[(waveform_row_count-1)*3+waveform_all_count%3].append \
            (QString(tr("HALL-")) + FG_Test_Data.at(1 + FG_Shape_Count));
    WavePoint_strList[(waveform_row_count-1)*3+waveform_all_count%3].append \
            (QString::number(strResult.size()-1));
    WavePoint_strList[(waveform_row_count-1)*3+waveform_all_count%3].append \
            (QString::number(0));
    for (i = 0; i < 2; i++) {
        WavePoint_strList[(waveform_row_count-1)*3+waveform_all_count%3].append \
                (QString::number(0));
    }
    for (i = 0; i < 400; i++) {
        WavePoint_strList[(waveform_row_count-1)*3+waveform_all_count%3].append \
                (shape_list.at(i));
    }
    Recrd_Wave = (waveform_row_count-1)*3+waveform_all_count%3 + 1;
    ChangeLable(waveform_all_count%3, (waveform_row_count-1)*3 + waveform_all_count%3);
    // waveform_count = 0;   //-7.12 进行屏蔽
    waveform_all_count++; //-记录波形的个数
  //  waveform_all_count = (waveform_all_count/3+1)*3;
    FG_Shape_Count++;
    if (FG_Test_Data.at(0).toInt() == FG_Shape_Count) {
        if (waveform_all_count%3 != 0) { // -波形数量不为3的整形
            waveform_all_count = (waveform_all_count/3+1)*3;
        } else {
            //-波形数目保持不变
        }
        qDebug() << "waveform is finsh";
    } else {
        //
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.7.18
  * brief:      PG-的参数
******************************************************************************/
void w_Test::PG_Param(QStringList pg_data, int *waveform_point, int *waveform_point_c)
{
    int i;
    bool pg_waveform_error;
    bool Start_get_pg_shape;
    pg_waveform_error = pg_data.at(0).toInt();
    Start_get_pg_shape = pg_data.at(1).toInt();
    qDebug() << "PG_Param---pg_waveform_error" << pg_waveform_error;
    if (strPWR == QStringList()) {
        return;
    } else {
        //
    }

    if (Conf_Item[Test.Finshed_Count].toInt() == 7) { // -当前测试项目为功率项目
        //
    } else {
        return;
    }

    qDebug() << "1" << Ini_Motor << PWR_Test_Count << PWR_Test_Data;
    if ((Ini_Motor == QString("PG")) && \
            (strPWR.at(5+PWR_Test_Data.at(1+PWR_Test_Count).toInt()/10).toInt() == 2)) {
        // -判断是否寻在PG
        //
    } else {
        return;
    }
    qDebug() << "2";

    if (waveform_all_count%3 == 0) {
        for (i = 0; i < 3; i++) { // -3组数据清理
            wave[i]->Test_Shape = 0;
            wave[i]->num = 0;
            wave[i]->update();
        }
        waveform_row_count++;
    } else {
        //
    }
    if (pg_waveform_error) { //-采集波形有错误
        qDebug() << "waveform is error";
        pg_waveform_error = false;

        if (Start_get_pg_shape) {
            Start_get_pg_shape = false;
            for(i=0; i<400; i++) {
                waveform_point[i] = waveform_point_c[i];
            }
        } else {
            for(i=0; i<400; i++) {
                waveform_point[i] = 128;
            }
        }
    } else {
        qDebug() << "waveform is right";
    }
    /*波形显示*/
    for (i = 0; i < 400; i++) {
        wave[waveform_all_count%3]->point[i] = 260;
        wave[waveform_all_count%3]->pointgreen[i] = waveform_point[i];
    }
    wave[waveform_all_count%3]->num = 400;
    wave[waveform_all_count%3]->update();
    // waveform_count = 0; //-7.12 屏蔽
    WavePoint_strList[(waveform_row_count-1)*3+waveform_all_count%3].append \
            (QString::number(3));
    WavePoint_strList[(waveform_row_count-1)*3+waveform_all_count%3].append \
            (QString::number(PWR_Test_Data.at(1+PWR_Test_Count).toInt()%10-1));
    WavePoint_strList[(waveform_row_count-1)*3+waveform_all_count%3].append \
            (QString::number(strResult.size()));
    WavePoint_strList[(waveform_row_count-1)*3+waveform_all_count%3].append \
            (QString::number(0));
    for (i = 0; i < 2; i++) {
        WavePoint_strList[(waveform_row_count-1)*3+waveform_all_count%3].append \
                (QString::number(0));
    }
    for (i = 0; i < 400; i++) {
        WavePoint_strList[(waveform_row_count-1)*3+waveform_all_count%3].append \
                (QString::number(waveform_point[i]));
    }
    Recrd_Wave = (waveform_row_count-1)*3+waveform_all_count%3 + 1;
    ChangeLable(waveform_all_count%3, (waveform_row_count-1)*3 + waveform_all_count%3);
    // waveform_count = 0;   //-7.12 进行屏蔽
    waveform_all_count++; //-记录波形的个数
    if (PWR_Test_Data.at(0).toInt() == (PWR_Test_Count+1)) {
        if (waveform_all_count%3 != 0) { // -波形数量不为3的整形
            waveform_all_count = (waveform_all_count/3+1)*3;
        } else {
            //-波形数目保持不变
        }
        qDebug() << "waveform is finsh";
    } else {
        //
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.3.17
  * brief:      返回测试状态
******************************************************************************/
int  w_Test::Back_Test_Status()
{
    return Test.Status_Ing;
}
void w_Test::PC_Test_Result_ItemData(QString netdata, QString param)
{
    QDomText text;
    QDomDocument doc;
    QDomElement root = doc.createElement(param);
    doc.appendChild(root);

    QDomElement Test_1 = doc.createElement("Test_3"); // Test_3
    root.appendChild(Test_1);
    text = doc.createTextNode(netdata);
    Test_1.appendChild(text);

    emit WriteMessage(6000, 0x61, doc.toByteArray());
    qDebug() << "2018-3-22 doc.toByteArray()" << doc.toByteArray();
}

void w_Test::PC_Test_Result_Data(QString netdata, QString param)
{
    QDomText text;
    QDomDocument doc;
    QDomElement root = doc.createElement(param);
    doc.appendChild(root);

    QDomElement Test_1 = doc.createElement("Test_3"); // Test_3
    root.appendChild(Test_1);
    text = doc.createTextNode(netdata);
    Test_1.appendChild(text);

    emit WriteMessage(6000, 0x60, doc.toByteArray());
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2018.01.04
  * brief:      日电产凯宇准备测试
******************************************************************************/
void w_Test::Kai_Yu_Ready_Test() {
    if (IO_Test_Readying) {
        //
    } else {
        return;
    }

    if (Kai_Yu_Clumped && Kai_Yu_Pushed) {
        //
    } else {

        return;
    }

    if (!Kai_Yu_Curtain) {
        //
    } else {
        Test_WMessage(8, QString(tr(""))); // 8
        return;
    }

    if (Kai_yu_In_Place) {
        //
    } else {
        Test_WMessage(9, QString(tr(""))); // 9
        return;
    }

    if (Kai_Yu_New_Count != Kai_Yu_Oid_Count) {
        //
    } else {
        Test_WMessage(10, QString(tr(""))); // 10
        return;
    }

    if (IO_Test_Readying) { // 启动
        IO_Test_Readying = false;
        Kai_Yu_Oid_Count = Kai_Yu_New_Count;
        Test_Process(); // 清空后，开始测试
    } else {

    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2018.01.04
  * brief:      IO测试数据显示输入数据
******************************************************************************/
void w_Test::on_Key_E_clicked()
{
    Key_E_Count++;
    if (Key_E_Count%5 == 0) {
        IO_Input_Data->show();
    } else {
        IO_Input_Data->hide();
    }
}

