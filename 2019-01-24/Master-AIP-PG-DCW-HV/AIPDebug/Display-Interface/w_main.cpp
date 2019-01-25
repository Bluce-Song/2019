/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     2.0
 * author:      SL
 * date:        2015.12.10
 * brief:       主界面
*******************************************************************************/
#include "w_main.h"
#include "ui_w_main.h"
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.10
  * brief:      主界面构造/初始化
******************************************************************************/
w_Main::w_Main(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::w_Main)
{
    this->setWindowFlags(Qt::FramelessWindowHint);  //去掉标题栏
    ui->setupUi(this);

    wSyst = NULL;
    wData = NULL;
    wTest = NULL;
    wHelp = NULL;
    wConf = NULL;
    wColr = NULL;
    wDebug    = NULL;
    wPassWord = NULL;


    ui->label_net->hide();     //-网络图标隐藏
    ui->label_print->hide();   //-打印机图标隐藏
    ui->label_sqldata->hide(); //-数据库图标隐藏
    ui->label_Version->hide(); //-版本信息标签隐藏
    ui->label_hand->hide();    //-握手信息图标隐藏
    ui->label_no_connect->hide();
    ui->label_clock->hide();
    ui->label_->setText(QString(tr("")));

    step_system = 0;
    window_old  = 0;   window_current = 0;

    can_number   = 0;
    can_bug_time = 0;

    imp_back_number = 0; imp_waveform_error = true;
    mag_back_number = 0; mag_waveform_error = true;  mag_set_rotation = 0;
    waveform_count  = 0;
    pg_waveform_error = true;
 // fg_waveform_error = true;

    IRACW.updata = 0;
    IRACW.time   = 0;
    IRACW.volt   = 0;
    IRACW.voltc  = 0;
    IRACW.result = 0;
    IRACW.resultc = 0;
    IRACW.judge  = 0;
    IRACW.resultc_dou  = 0;
    IRACW.show_resultc = 0;

    int i;
    for (i = 0; i < 800; i++) {
        waveform_point[i] = 0;
        waveform_IMP_Compare[i] = 0;
        waveform_IMP_YY_Compare[i] = 0;
        waveform_point_c[i] = 0;
    }

    out_station = 0x13;
    isTesting = false;
    PreCount  = 0xff;

    this->Button_Main_Group = new QButtonGroup;     //-配置按钮
    this->Button_Main_Group->addButton(ui->Key_A, Qt::Key_A);  ui->Key_A->hide();
    this->Button_Main_Group->addButton(ui->Key_B, Qt::Key_B);  ui->Key_B->hide();
    this->Button_Main_Group->addButton(ui->Key_C, Qt::Key_C);  ui->Key_C->hide();
    this->Button_Main_Group->addButton(ui->Key_D, Qt::Key_D);  ui->Key_D->hide();
    this->Button_Main_Group->addButton(ui->Key_E, Qt::Key_E);
    connect(this->Button_Main_Group, SIGNAL(buttonClicked(int)), \
            this, SLOT(Button_Main_Group_Judge(int)));

    if (QString(Version_System) == QString("Release")) {  // -系统(Release)隐藏退出按键
        ui->Key_E->hide();
    } else {
        ui->Key_E->show();
    }

    this->p_ipmethod = new IPMethod; // 启用输入法
    QWSServer::setCurrentInputMethod(this->p_ipmethod);
    connect(this, SIGNAL(Serial_SendString(QString)), this->p_ipmethod, SLOT(Preedit(QString)));
    connect(this, SIGNAL(Serial_SendEnter()), this->p_ipmethod, SLOT(Confirm()));
    connect(this, SIGNAL(Serial_SendBackspace()), this->p_ipmethod, SLOT(Backspace()));
    connect(this, SIGNAL(Serial_SendEscape()), this->p_ipmethod, SLOT(Escape()));
    connect(this, SIGNAL(Serial_Upspace()), this->p_ipmethod, SLOT(Upspace()));
    connect(this, SIGNAL(Serial_Downspace()), this->p_ipmethod, SLOT(Downspace()));
    connect(this, SIGNAL(Serial_Tabspace()), this->p_ipmethod, SLOT(Tabspace()));
    connect(this, SIGNAL(Serial_BackTabspace()), this->p_ipmethod, SLOT(BackTabspace()));

    Timer_system = new QTimer(this);
    connect(Timer_system, SIGNAL(timeout()), this, SLOT(System_Runing()));
    Timer_system->start(50);

    out_board = new QTimer(this);
    connect(out_board, SIGNAL(timeout()), this, SLOT(Out_Board_Stop()));
    dcr_board = new QTimer(this);
    connect(dcr_board, SIGNAL(timeout()), this, SLOT(Dcr_Board_Stop()));
    acw_board = new QTimer(this);
    connect(acw_board, SIGNAL(timeout()), this, SLOT(Acw_Board_Stop()));
    Appointment_Timer = new QTimer(this);
    connect(Appointment_Timer, SIGNAL(timeout()), this, SLOT(Appointment_Timer_out()));

    Mouse.Time = new QTimer(this);
    connect(Mouse.Time, SIGNAL(timeout()), this, SLOT(Mouse_Judge()));
    Mouse.Ms = 0;  Mouse.Us = 0;
    Mouse.Flag = false;


    PG_State_Check_Time = new QTimer(this);
    connect(PG_State_Check_Time, SIGNAL(timeout()), this, SLOT(PG_State_Check()));
    PG_Down_Get_Data = false;
    PG_Finsh_Count = 0;
    PG_Finsh_Shape_Count = 0;

    QPalette palette = ui->Print_Text->palette(); // 设置输出文本信息
    palette.setBrush(QPalette::Base, QBrush(Qt::NoBrush));
    ui->Print_Text->setPalette(palette);
    ui->Print_Text->setReadOnly(true);
    ui->Print_Text->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   //-设置垂直滚动条不可见
    ui->Print_Text->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //-设置水平滚动条不可见
    QTextCursor text_cursor(ui->Print_Text->textCursor());                //-设置光标的位置
    text_cursor.movePosition(QTextCursor::End);
    ui->Print_Text->setTextCursor(text_cursor);

    myThread = new MyThread; // 开启一个线程，判断U盘的操作
    myThread->start();

    QStringList system_conf_list;   system_conf_list.clear();
    system_conf_list.append("9");   //-蜂鸣器的档位
    system_conf_list.append("0.1"); //-合格时间
    system_conf_list.append("0.3"); //-不合格时间
    system_conf_list.append("9");   // -Led档位
    system_conf_list.append("0");   //-启动模式
    system_conf_list.append("1");   //-管理员

    QStringList Allocation_list; //-默认 Allocation/Item
    Allocation_list.clear();
    Allocation_list.append("13");
    Allocation_list.append("14");
    Allocation_list.append("0");
    Allocation_list.append("0");
    Allocation_list.append("0");
    Allocation_list.append("0");
    Allocation_list.append("1");

    QStringList Password_list; //-默认 Password/Text
    Password_list.clear();
    Password_list.append("6");
    Password_list.append("456");
    Password_list.append("789");

    QSettings *set_Test_File = new QSettings(Sys_path, QSettings::IniFormat);
    set_Test_File->setIniCodec("GB18030");
    set_Test_File->setValue("Version/text", Version_number); //-通过程序将版本号进行写入
    qDebug() << "w_Main::Version_number" << Version_number;

    barcode_start = set_Test_File->value("Barcode/start", "0").toInt(); //-获取截取的字符串的起始位
    barcode_stop  = set_Test_File->value("Barcode/stop", "0").toInt();  //-获取截取的字符串的结束位
    out_stamp     = set_Test_File->value("outsingal/text", "0").toInt();
    signal_model  = set_Test_File->value("DCR_In/text", "1").toInt();
    nine_board    = set_Test_File->value("BoardNumber/text", 0).toInt();
    set_gnd_vlot  = set_Test_File->value("System/GND", "20").toInt();
    acsw_board    = set_Test_File->value("System/ACSW", "0").toInt();
    udp_enable    = set_Test_File->value("UDP/text", "0").toInt();
    system_conf   = set_Test_File->value("System/Text", system_conf_list).toStringList();

    Ini_Number    = set_Test_File->value("Allocation/All", "7").toString().toInt();
    Ini_Proj_Real = set_Test_File->value("Allocation/Item", Allocation_list).toStringList();
    Ini_Proj      = set_Test_File->value("Allocation/Item", \
                                         Allocation_list).toStringList().mid(5, Ini_Number);
    Ini_Password  = set_Test_File->value("Password/Text", Password_list).toStringList();
    Ini_IRACW_True = set_Test_File->value("Allocation/Set", "2").toInt(); //-设置绝缘耐压显示数值
    Ini_WD        = set_Test_File->value("System/WD", "Common").toString(); // -设置测试WD板
    Ini_IO        = set_Test_File->value("System/IO", "0").toInt();         // -设置测试IO板
    Ini_LR_Beep   = set_Test_File->value("System/LR_Beep", "0").toInt();         // -设置测试IO板
    Ini_IO_Model  = set_Test_File->value("System/IO_Model", "0").toInt();
    Ini_Motor     = set_Test_File->value("System/PG", "Common").toString();
    Ini_MAG_Device   = set_Test_File->value("System/MAG_Device", "0").toInt();   // -设置测试IO板
    Ini_Vacuum_Model = set_Test_File->value("System/Vacuum_Model", "0").toInt(); // -设置真空测试
    Ini_BLDC_PG      = set_Test_File->value("System/PLC_BLDC_PG", "0").toInt();
    Ini_Mag_Hide    = set_Test_File->value("magshapehide/text", "0").toInt();
    Ini_Appointment = set_Test_File->value("System/Order", "0").toInt();
    DeChang_baudRate   = set_Test_File->value("DeChang/baudRate", 0).toInt();
    DeChang_Commontion = set_Test_File->value("DeChang/Commontion", 0).toInt();
    DeChang_Enable   = set_Test_File->value("DeChang/Enable", 0).toInt();
    Ini_Start_Stop   = set_Test_File->value("IO/Start_Stop", "0").toInt();
    Ini_Beep_Up      = set_Test_File->value("IO/Beep_Up", "0").toInt();
    Ini_Set_Model    = set_Test_File->value("System/Set_Model", "0").toInt();
    Ini_Get_Temp     = set_Test_File->value("System/Temp", "Inter").toString(); // 飛雪派克外部溫度
    Ini_NG_Reset     = set_Test_File->value("System/NG_Reset", "0").toInt(); // 真空设备不合格不允许启动另外工位
    Ini_new_rot      = set_Test_File->value("System/new_rot", "0").toInt();

    // -设置 BLDC_PG 控制 PLC

    DeChang_baudRate_List.clear();
    DeChang_baudRate_List.append("115200");
    DeChang_baudRate_List.append("19200");
    DeChang_baudRate_List.append("9600");

    Ini_ROT = false;
    if (system_conf.size() != system_conf_list.size()) {
        system_conf = system_conf_list;
    }
    ui->label_Version->setText(ui->label_Version->text().append(Version_number));

    QString magtext;
    magtext = set_Test_File->value(QString("MAG/text").toUtf8().data()).toString();
    if (magtext == QString("")) {
        set_Test_File->setValue(QString("MAG/text").toUtf8().data(), "Positive");
    } else {
        if (magtext == QString(tr("Positive"))) {
            mag_set_rotation = 0;
        } else if (magtext == QString(tr("negative"))) {
            mag_set_rotation = 1;
        } else {
            mag_set_rotation = 0;
        }
    }
    system("sync");
    delete set_Test_File;

    DCR_Beep_Ok = 0;
    DCR_Beep_Ng = 0;
    DCR_BEEP = 0;

    calibration_count = 0;
    Cheak_Ready_count = 0;

    GND_State = false;
    AMP_All_Count = 0;
    AMP_No_Count  = 0;

    Shake_hand_Success = false;
    Shake_hand_runcount = 0;
    WMessage_Text.clear();
    WMessage_Text.append(QString(tr("         输出板异常        ")));  // 0
    WMessage_Text.append(QString(tr("         电阻板异常        \n         B02A--异常      ")));
    WMessage_Text.append(QString(tr("         绝缘板异常        \n         B03A--异常      ")));
    WMessage_Text.append(QString(tr("         匝间板异常        \n         B04A--异常      ")));
    WMessage_Text.append(QString(tr("         电参板异常        \n         B07A--异常      ")));
    WMessage_Text.append(QString(tr("         电感板异常        \n         B06A--异常      ")));
    WMessage_Text.append(QString(tr("         左输出板异常        \n         B10A---异常      ")));
    WMessage_Text.append(QString(tr("         右输出板异常        \n         B10A---异常      ")));
    WMessage_Text.append\
            (QString(tr("         系统接地异常！        \n         建议接地后使用     ")));
    WMessage_Text.append\
            (QString(tr("         电源切换板异常！        \n         B09A 异常     ")));
    WMessage_Text.append\
            (QString(tr("         内存空间不足  \n    建议导出数据，清除数据库       ")));
    WMessage_Text.append(QString(tr("         WD板异常        \n         B0BA---异常      ")));
    WMessage_Text.append(QString(tr("         PG板异常        \n         B0CA---异常      ")));
    WMessage_Text.append(QString(tr("         IO板异常        \n         B0DA---异常      ")));
    WMessage_Text.append(QString(tr("         相序异常        ")));     // 14
    WMessage_Text.append(QString(tr("         热继电器异常        ")));  // 15
    WMessage_Text.append(QString(tr("         輸出板异常 请拍照        ")));  // 16
    WMessage_Text.append(QString(tr("         IO板异常  请拍照        ")));  // 17
    WMessage_Text.append(QString(tr("         样品未检测,请拿开样品,重新放置        ")));  // 18
    WMessage_Text.append(QString(tr("         光幕被遮挡        ")));  // 19
    WMessage_Text.append(QString(tr("         ROT板异常        \n         B05A---异常      ")));  // 20

    WD_I = 0.0;
    WD_V = 0.0;
    WD_P = 0.0;
    Fg_Direction = 0;
    Square_WD = 0.0;

    BEMF_HIGH_Low.clear();
    for (i = 0; i < 150; i++) {
        BEMF_HIGH_Low.append("0");
    }
    Shape_BEMF_Fre.clear();
    for (i = 0; i < 20; i++) {
        Shape_BEMF_Fre.append("0");
    }
    Phase_diffence.clear();
    for (i = 0; i < 20; i++) {
        Phase_diffence.append("0");
    }
    Shape_Pg.clear();
    WD_PWR = false;
    RFID_H.clear();
    lock_count = 0;
    Cheak_Ready_count = 0;
    GND_State = false;
    AMP_All_Count = 0, AMP_No_Count = 0;
    PG_Test_Count = 0;
    System_Display_Volt = 0;

    Start_get_pg_shape = false;
    IMP_Sample_Dou = false;

    AMP_Inter_Lock();
    Appointment_Test_Enable = false;
    Appointment_Test_Station = 0;
    Appointment_Test_wait_count = 0;

    Set_Drive = false;
    DeChang_Receive = true;
    Control_Enable_BaoJiaLiYa = false;

    WL_Test_Flag = true;
    Net_Get_Temp = 25.00;
}
/******************************************************************************
      * version:    1.0
      * author:     link
      * date:       2015.12.10
      * brief:      主界面析构
******************************************************************************/
w_Main::~w_Main() {
    delete this->p_ipmethod;
    delete this->Button_Main_Group;
    tcp->quit();
    tcp->wait();
    udp->quit();
    udp->wait();
    delete ui;
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2015.12.10
      * brief:      处理鼠标被按下事件
******************************************************************************/
void w_Main::mousePressEvent(QMouseEvent *event) {
    handleMousePressEvent(event);
    Mouse.Time->start(1);
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2015.12.10
      * brief:      处理鼠标被按下事件
******************************************************************************/
void w_Main::mouseReleaseEvent(QMouseEvent *event) {
    event = 0;
    Mouse.Time->stop();
    if ((Mouse.Flag) && (Mouse.Ms >= 2)) {
        Pubs_ChangeWindow(5);
    }
    Mouse.Ms = 0;
    Mouse.Us = 0;
    Mouse.Flag = false;
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2015.12.10
      * brief:      鼠标长按处理
******************************************************************************/
void w_Main::Mouse_Judge() {
    Mouse.Us++;
    if (Mouse.Us >= 1000) {
        Mouse.Us = 0;
        Mouse.Ms++;
    }
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2015.12.10
      * brief:      鼠标进行位置选择
******************************************************************************/
bool w_Main::handleMousePressEvent(QMouseEvent *event) {
    QPoint topLeft(680, 440);
    QPoint rightBottom(800, 600);
    QRect  rect(topLeft, rightBottom);
    if (rect.contains(event->pos())) {
        Mouse.Flag = true;
    } else {
        Mouse.Flag = false;
    }
    return true;
}

void w_Main::AMP_Inter_Lock() {
    int i;
    QStringList AMP_lable_Text; //
    AMP_lable_Text.clear();
    AMP_lable_Text.append(tr("B03A异常,Inter Lock断开"));
    AMP_lable_Text.append(tr("Inter Lock 状态:"));
    AMP_lable_Text.append(tr("请保持连接,点击<复位>,等待10s"));

    AMP_Widget = new QWidget(this);
    AMP_Widget->setGeometry(170, 220, 460, 210);
    AMP_Widget->setWindowFlags(Qt::WindowStaysOnTopHint);
    AMP_Widget->setStyleSheet("border-radius: 10px;padding:2px 4px;background-color: gray;");

    QGridLayout *upside = new QGridLayout;
    for (i = 0; i < 3; i++) {
        AMP_lable.append(new QLabel(this));
        AMP_lable[i]->setText(AMP_lable_Text.at(i));
        AMP_lable[i]->setMaximumHeight(35);
        AMP_lable[i]->setMaximumWidth(335);
        AMP_lable[i]->setAlignment(Qt::AlignCenter);
        upside->addWidget(AMP_lable[i], i, 0);
    }
    Reset_IR_ACW = new QPushButton;
    Reset_IR_ACW->setText(tr("复位"));
    Reset_IR_ACW->setMinimumHeight(50);
    Reset_IR_ACW->setMinimumWidth(90);
    Reset_IR_ACW->setStyleSheet
            ("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: "\
             "0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);");
    upside->addWidget(Reset_IR_ACW, 3, 0);
    connect(Reset_IR_ACW, SIGNAL(clicked()), this, SLOT(Reset_IR_ACW_clicked()));
    QVBoxLayout *AMP_layout_SQL = new QVBoxLayout;
    AMP_layout_SQL->addLayout(upside);
    AMP_Widget->setLayout(AMP_layout_SQL);
    AMP_Widget->hide();
    AMP_Count = 0;
}

void w_Main::Reset_IR_ACW_clicked() {
    frame.can_id = 0x23; //-绝缘板复位信号
    frame.can_dlc = 0x01;
    frame.data[0] = 0x0f;
    canSend(frame, 88); usleep(500);
    AMP_Cheak_Ready = new QTimer(this);
    connect(AMP_Cheak_Ready, SIGNAL(timeout()), \
            this, SLOT(Reset_ok()));
    AMP_Cheak_Ready->start(1000);
}

void w_Main::Reset_ok() {
    AMP_Count++;
    Reset_IR_ACW->setText(tr("%1S").arg(QString::number(AMP_Count)));
    if (AMP_Count >= 10) {
        AMP_Count = 0;
        AMP_Cheak_Ready->stop();
        AMP_Widget->hide();
        Pubs_Cheak_Ready();
    } else {
        //
    }
}

/******************************************************************************
      * version:    1.0
      * author:     link
      * date:       2015.12.10
      * brief:      按钮功能
******************************************************************************/
void w_Main::Button_Main_Group_Judge(int id) {
    QString CurrentDateTime;
    QStringList Search;
    QStringList data_t;
    switch (id) {
    case Qt::Key_A: //-进入系统设置
        Pubs_ChangeWindow(10);
        break;
    case Qt::Key_B: //-进入型号管理
        Pubs_ChangeWindow(8);
        break;
    case Qt::Key_C: //-进入数据管理
        CurrentDateTime = QDateTime::currentDateTime().toString("yyyy/MM/dd"); //设置显示格式
        Search << wConf->Ini_ActiveFile << CurrentDateTime << CurrentDateTime;
//        wData->Structure_Interface("wMain", wConf->Ini_ActiveFile);
        Pubs_ChangeWindow(3);
        qApp->processEvents(); // 立即显示生效

        data_t.append(QString::number(wConf->Conf_User));
        data_t.append(QString::number(wConf->Ini_ACW_And_IR));
        data_t.append(Ini_Motor);
//        wData->Pub_Set_Data(data_t);
//        wData->File = wConf->currentFile;
        break;
    case Qt::Key_D: //-进入测试
        Pubs_ChangeWindow(4);
        wConf->Pub_main_to_conf(QStringList(""), QString(""), 1, 7);
        break;
    case Qt::Key_E: //-退出
        Pubs_ChangeWindow(100);
        break;
    default:
        //
        break;
    }
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:
      * brief:      conf界面的接收函数
******************************************************************************/
void w_Main::Pubs_from_conf(QStringList list, QString str, int data, int value) {
    switch (value) {
    case 1:
        Pri_Sync_Data(list);
        Pubs_ChangeWindow(data);
        break;
    case 2:
        Pubs_ChangeWindow(data);
        PLC_test_to_Switchover(KaiYu, 0x00, 6);
        break;
    case 3:
        ui->label_sqldata->show();
        ui->label_no_connect->hide();
        break;
    case 5:
        if (str == QString(tr("ABC"))) {
            Ini_ROT = true;
        } else {
            Ini_ROT = false;
        }
        wTest->Pub_Main_to_test(QStringList(""), str, 22, 22);
        break;
    case 6:
        if (data == 100) {
        //  PLC_test_to_Switchover(BaoJiaLiYa, str.toInt(), 2); // 断开交流接触器
        } else {
            if (data) {
                Control_Enable_BaoJiaLiYa = true;
            } else {
                Control_Enable_BaoJiaLiYa = false;
            }
        }
        break;
    default:
        //
        break;
    }
}

void w_Main::Pri_Send_FG_Test_Enable() {
    wTest->FG_Conf_Item.clear(); //
    wTest->FG_Conf_Item.append("0"); // 空载
    wTest->FG_Conf_Item.append("0"); // 负载
    wTest->FG_Conf_Item.append("0"); // BEMF

    if (wTest->Conf_Item.contains(tr("11"))) { // FG
        if (wConf->WPG->wave_count/1000 == 0) {
            wTest->FG_Conf_Item.replace(0, QString::number(wConf->WPG->wave_count));
        } else if (wConf->WPG->wave_count/1000 == 1) {
            wTest->FG_Conf_Item.replace(1, QString::number(wConf->WPG->wave_count));
        } else if (wConf->WPG->wave_count/1000 == 2) {
            wTest->FG_Conf_Item.replace(2, QString::number(wConf->WPG->wave_count));
        } else {
            //
        }
    } else {
        //
    }
}

void w_Main::Pri_Send_PLC() {
    QStringList PLC_List;
    PLC_List.clear();
    if (wTest->Conf_Item.contains(tr("6"))) { // 匝间
        PLC_List.append("1");
    } else {
        PLC_List.append("0");
    }

    if (wTest->Conf_Item.contains(tr("3"))) { // 绝缘
        PLC_List.append("1");
    } else {
        PLC_List.append("0");
    }

    if (wTest->Conf_Item.contains(tr("4"))) { // 交耐
        PLC_List.append("1");
    } else {
        PLC_List.append("0");
    }

    if (wTest->Conf_Item.contains(tr("2"))) { // 反嵌
        PLC_List.append("1");
    } else {
        PLC_List.append("0");
    }

    if (Ini_MAG_Device == 1) { // 反嵌驱动-美芝项目
        PLC_List.append("1");
    } else {
        PLC_List.append("0");
    }
    qDebug() << "w_Main::Pri_Send_PLC()" << PLC_List;
    Signal_main_to_pic(PLC_List, 0, 7);
}

/******************************************************************************
      * version:    1.0
      * author:     link
      * date:       2015.12.10
      * brief:      同步数据
******************************************************************************/
void w_Main::Pri_Sync_Data(QStringList Data) {
    qDebug() << "w_Main::Pri_Sync_Data";
    int i = 0;
    if (wTest == NULL) {
        return;
    }
    if (wConf == NULL) {
        return;
    }

    Main_ActiveFile = Data.at(0);
    Pri_Synchron_Result_Data(); // 结果参数
    wTest->Conf_Item = wConf->Conf_Test;
    Pri_Send_PLC();
    Pri_Send_FG_Test_Enable();
    wTest->COLOR_Id  = wConf->colorIdList_C; // -颜色Color

    for (i = 0; i < Ini_Proj.size(); i++) {
        switch (Ini_Proj.at(i).toInt()) {
        case  1:
            wTest->strRES = wConf->strRES;
            wTest->DLR_UpDown = wConf->strDLR_UpDown;
            break;
        case  2:
            wTest->strOPP = wConf->strOPP;
            break;
        case  3:
            wTest->strIR  = wConf->strIR;
            break;
        case  4:
            wTest->strACW = wConf->strACW;
            break;
        case  5:
            wTest->strDCW = wConf->strDCW; //
            break;
        case  6:
            wTest->strITT = wConf->strITT;
            wTest->IMP_Param = wConf->strIMP_Param;
            wTest->Pub_Main_to_test(QStringList(""), Main_ActiveFile, 1, 21);
            break;
        case  7:
            wTest->strPWR = wConf->strPWR;
            break;
        case  8:
            wTest->strINDL = wConf->strINDL;
            break;
        case  9:
            wTest->strBLOCK = wConf->strBLOCK;
            break;
        case 10:
            wTest->strLVS = wConf->strLVS;
            break;
        case 11:
            wTest->strPG = wConf->strPG;
            break;
        case 12:
            wTest->strLOAD = wConf->strLOAD;
            break;
        case 13:
            wTest->strNOLOAD = wConf->strNOLOAD;
            break;
        case 14:
            wTest->strBEMF = wConf->strBEMF;
            break;
        case 15:
            wTest->strHV = wConf->strHV;
            break;
        default:
            break;
        }
    }
    wTest->Pub_Main_to_test(Data, QString(""), 1, 8);
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2017.7.20
      * brief:      测试界面获取系统配置界面的参数
******************************************************************************/
void w_Main::Pri_Synchron_Syst_Data() {
    QStringList list;
    list.append(system_conf);
    list.append("");
    list.append("");
    list.append(QString::number(barcode_start));
    list.append(QString::number(barcode_stop));
    DCR_Beep_Ok = system_conf.at(1).toDouble();
    DCR_Beep_Ng = system_conf.at(2).toDouble();
    wTest->Pub_Main_to_test(list, QString(""), 1, 3);
}

/******************************************************************************
      * version:    1.0
      * author:     link
      * date:       2015.12.10
      * brief:      获取配置密码
******************************************************************************/
void w_Main::Pri_Synchron_PassWord_Data() {
    wPassWord->Password.Syst =  Ini_Password.at(0);   //  密码
    wPassWord->Password.Debug = Ini_Password.at(1);
    wPassWord->Password.Conf =  Ini_Password.at(2);
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2016.8.26
      * brief:      同步数据
******************************************************************************/
void w_Main::Pri_Synchron_Result_Data() {
    int i = 0;
    int j = 0;
    for (i = 0; i < Ini_Proj.size(); i++) {
        switch (Ini_Proj.at(i).toInt()) {
        case 1:
            wTest->DCR_Total_Number = wConf->WDLR->DLR_TestNumber;
            wTest->DCR_TestItem_H   = wConf->WDLR->DLR_TestItemsH;
            wTest->DCR_TestItem_L   = wConf->WDLR->DLR_TestItemsL;
            break;
        case 2:
            wTest->MAG_Total_Number = wConf->WMAG->MAG_TestNumber;
            wTest->MAG_TestItem = wConf->WMAG->MAG_TestItems;
            wTest->YY_ROT_Test = wConf->WMAG->YY_ROT_Test;
            wTest->MEKJ_Test = wConf->WMAG->MEKJ_Test;
            break;
        case 3:
            wTest->IR_Test_Total = wConf->WIR->IR_Test_Total;
            wTest->IRgroup_num = wConf->WIR->IRgroup_num;
            break;
        case 4:
            wTest->ACW_Test_Total = wConf->WACW->ACW_Test_Total;    //测试总数
            wTest->ACWgroup_num = wConf->WACW->ACWgroup_num;        //当前测试项
            break;
        case 5:
            wTest->DCW_Test_Total = wConf->WDCW->DCW_Test_Total;    //测试总数
            wTest->DCWgroup_num = wConf->WDCW->DCWgroup_num;        //当前测试项
            break;
        case 6:
            wTest->IMP_Total_Number = wConf->WIMP->IMP_TestNumber;
            wTest->IMP_TestItem  = wConf->WIMP->IMP_TestItems;
            wTest->Copy_IMP_Gear  = wConf->WIMP->Copy_IMP_Gear;
            qDebug() << "Pri_Synchron_Result_Data" << wTest->Copy_IMP_Gear;
            break;
        case 7: // 电参
            wTest->PWR_Test_Data = wConf->WPWR->PWR_Test_Data;
            wTest->PWR_SetData = wConf->WPWR->PWR_SetData;
            wTest->PG_Test_Order = wConf->WPWR->PG_Test_Order;
            for (j = 0; j < wTest->PG_Test_Order.size(); j++) {
                if (wTest->PG_Test_Order.at(j) != "0") {
                     PG_Test_Count = wTest->PG_Test_Order.at(j).toInt();
                } else {
                    //
                }
            }
            break;
        case 8: // 电感
            wTest->INDL_Total_Number = wConf->WINDL->INDL_TestNumber;
            wTest->INDL_TestItem_H   = wConf->WINDL->INDL_TestItemsH;
            wTest->INDL_TestItem_L   = wConf->WINDL->INDL_TestItemsL;
            break;
        case 9: // 堵转
            //
            break;
        case 10: // 低启
            //
            break;
        case 11: // PG
            wTest->FG_Test_Data = wConf->WPG->FG_Test_Data;
            break;
        case 12: // LOAD
            //
            break;
        case 13: // NOLOAD

            break;
        case 14: // BEMF
            //
            break;
        default:
            //
            break;
        }
    }
}

/******************************************************************************
      * version:    1.0
      * author:     link
      * date:       2015.12.10
      * brief:      窗口切换
******************************************************************************/
void w_Main::Pubs_ChangeWindow(int win) {
    int Windows_out_station;
    qDebug() << "w_Main::Pubs_ChangeWindow win-->" << win << window_old;
    wTest->releaseKeyboard();
    window_current = win;
    Windows_out_station = out_station;
    if (window_old == wTest_Surface) { // -判断在离开或者进入测试界面时，关闭指示灯
        wTest->Pub_Main_to_test(QStringList(""), QString(""), 0, 9);
        out_station = 0x12;
        Pubs_Usart_Send(QString("LED1").toLatin1().data());

        Signal_main_to_pic(QStringList(""), Windows_out_station-19, 17);
        Signal_main_to_pic(QStringList(""), 0, 13);
        if (Ini_ROT) {
            PLC_test_to_Switchover(Ciximinghua, 0X13, 2); // 吸合交流接触器
        } else {
            //
        }


        frame.can_id = 0x13; //-输出板 13 输出量信号发送
        frame.can_dlc = 0x02;
        frame.data[0] = 0x02;
        frame.data[1] = 0x00;
        canSend(frame, 88); usleep(500);
        frame.can_id = 0x14; //-输出板 14 输出量信号发送
        frame.can_dlc = 0x02;
        frame.data[0] = 0x02;
        frame.data[1] = 0x00;
        canSend(frame, 88); usleep(500);
//        frame.can_id  = 0x2D;  frame.can_dlc = 0x04;
//        frame.data[0] = 0xf1;
//        frame.data[1] = 0x00;
//        frame.data[2] = 0x00;
//        frame.data[3] = 0x00;
//        canSend(frame, 88);
    }
    switch (win) {
    case 0: // -主界面
        this->show();    this->raise();     this->activateWindow();      this->setFocus();
        break;
    case 1: // -系统设置
        if (wSyst == NULL) {
            return;
        }
        qDebug() << "wSyst";
        Sigmain_data_to_syst(QString(""), 2);
        wSyst->show();     wSyst->raise();    wSyst->activateWindow();    wSyst->setFocus();
        Sigmain_save_DayRecoord("System", ""); //-日志记录
        break;
    case 2: // -型号管理
        //
        break;
    case 3: // -数据管理
        if (wData == NULL) {
            return;
        }
        qDebug() << "wData";
        system("echo 1 > /sys/class/usb-reset/usb-reset/reset");
        wData->show();    wData->raise();     wData->activateWindow();     wData->setFocus();
        break;
    case 4: // -进入测试
        if (wTest == NULL) {
            return;
        }

        qDebug() << "wTesting";
        PreCount = 0xff;
        Signal_main_to_pic(QStringList(""), 1, 13);
        PLC_test_to_Switchover(BePuDa, 0x12, 12);
        wTest->Pub_Main_to_test(QStringList(""), QString(""), 1, 9);
        wTest->show();    wTest->raise();     wTest->activateWindow();     wTest->setFocus();
        wTest->grabKeyboard();
        // -2017.6.7,下发启动方式 更改为滑罩启动
        Pri_Can_Set_OUTModel(0x13, system_conf.at(4).toInt()); usleep(1800);
        Pri_Can_Set_OUTModel(0x14, system_conf.at(4).toInt()); usleep(1800);
        break;
    case 5: //-进入帮助
        if (wHelp == NULL) {
            return;
        }
        if (wTest->Back_Test_Status() != Test_Station_Free) {
            return;
        }
        qDebug() << "wHelp";
        wHelp->show();    wHelp->raise();     wHelp->activateWindow();     wHelp->setFocus();
        wHelp->updateText(window_old, wConf->index_c);
        break;
    case 6: //-进入后台
        //
        break;
    case 7: //-颜色设置
        if (wColr == NULL) {
            return;
        }
        qDebug() << "wColr";
        wColr->show();  wColr->raise();     wColr->activateWindow();        wColr->setFocus();
        break;
    case 8: //-设置界面
        if (wConf == NULL) {
            return;
        }
        qDebug() << "wConf";
        PLC_test_to_Switchover(KaiYu, 0x03, 6);
        wConf->show();  wConf->raise();    wConf->activateWindow();      wConf->setFocus();
        Pubs_Usart_Send(QString("LED1").toLatin1().data());
        wConf->Pub_main_to_conf(QStringList(""), QString(""), wTest->JUMP_Chose*1000, 11);
        Pri_Can_Set_OUTModel(0x13, 2); usleep(1800); // -2017.6.7,下发启动方式 更改为滑罩启动
        Pri_Can_Set_OUTModel(0x14, 2); usleep(1800);
        break;
    case 9: //-调试界面
        if (wDebug == NULL) {
            return;
        }
        qDebug() << "wDebug";
        wDebug->show();    wDebug->raise();   wDebug->activateWindow();   wDebug->setFocus();
        Sigmain_data_to_debug(QStringList(""), QString(""), 5);
        Sigmain_save_DayRecoord("Debug", ""); // -日志记录
        break;
    case 10: //-密码界面
        if (wPassWord == NULL) {
            return;
        }
        qDebug() << "wPassWord";
        wPassWord->CheckDisplay(window_old);
        wPassWord->Password_Check = window_old;
        wPassWord->show();   wPassWord->raise();    wPassWord->activateWindow();
        wPassWord->setFocus();

        break;
    default: //-程序退出
        qDebug() << "default: //-程序退出";
        if (wSyst != NULL) wSyst->close();
        if (wData != NULL) wData->close();
        if (wTest != NULL) wTest->close();
        if (wHelp != NULL) wHelp->close();
        if (wConf != NULL) wConf->close();
        if (wColr != NULL) wColr->close();
        if (wDebug != NULL)    wDebug->close();
        if (wPassWord != NULL) wPassWord->close();

        myThread->quit();
        myCom->WritePort(QString("LED1").toLatin1().data(), 4);
        myCom->ClosePort();
        delete myCom;
        myCom = NULL;
        delete wpic;

        can.canClose();
        this->close();
        break;
    }
    window_old = win; // -保存界面ID备用
}

/******************************************************************************
      * version:    1.0
      * author:     link
      * date:       2015.12.10
      * brief:      同步颜色
******************************************************************************/
void w_Main::Pri_Sync_Color(QString colr) {
    if (wConf == NULL) {
        return;
    } else {
        //
    }
    wConf->Pub_main_to_conf(QStringList(""), colr, 1, 4);
}

/******************************************************************************
      * version:    1.0
      * author:     link
      * date:       2015.12.10
      * brief:      CAN总线发送数据
******************************************************************************/
void w_Main::canSend(can_frame frame, int Judge_Win) {
//    int i;
//    QStringList can_string;
    if ((Judge_Win == window_current) || (Judge_Win == 88) || (Judge_Win == 99)) {
        can.canSend(frame);
//        can_string.append(QString::number(Judge_Win));
//        can_string.append(QString::number(frame.can_id));
//        can_string.append(QString::number(frame.can_dlc));
//        for (i = 0; i < frame.can_dlc; i++) {
//            can_string.append(QString::number(frame.data[i]));
//        }
//        qDebug() << "can_string " << can_string ;
    } else {
        //
    }
    if (Judge_Win != 99) {
        can_bug_time = 0;
    } else {
        //
    }
}
/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2015.12.10
      * brief:      系统设置界面获取参数
******************************************************************************/
void w_Main::Pubs_from_syst(QStringList list, int number, int value) {
    qint8 myComi; //初始化界面
    switch (value) {
    case 1:
        Pubs_Cheak_Ready();
        break;
    case 2:
        Pri_SaveSystemData(list);
        break;
    case 3:
        Pubs_ChangeWindow(number);
        break;
    case 4:

        break;
    case 5:
         wTest->Pub_Main_to_test(QStringList(""), QString(""), number, 118);
        break;
    case 6:
        frame.can_id = 0x2D;  frame.can_dlc = 0x03;
        frame.data[0] = 0x12;
        frame.data[1] = 0x02;
        frame.data[2] = number;
        canSend(frame, 88);
        usleep(500);
        break;
    case 7:
        frame.can_id = 0x2D;  frame.can_dlc = 0x02;
        frame.data[0] = 0x12;
        frame.data[1] = 0x01;
        canSend(frame, 88);
        usleep(500);
        break;
    case 8:
        PLC_test_to_Switchover(Bosch, number, 7);
        break;
    case 9: // 关闭串口
        myCom_DeChang ->ClosePort();
        delete myCom_DeChang;
        myCom_DeChang = NULL;
        break;
    case 10: // 打开转口
        myCom_DeChang = new CSerial;
        myComi = myCom_DeChang ->OpenPort(QString("ttyS1").toLatin1().data(), \
                                          DeChang_baudRate_List.at(number).toInt(), \
                                          '8', '1', 'N');
        if (myComi < 0) {
            delete myCom;
            myCom_DeChang = NULL;
        } else {
            //
        }
        connect(myCom_DeChang, SIGNAL(readyRead(QString)), \
                this, SLOT(readMyCom_Dechang(QString)));
        break;
    default:
        break;
    }
}
/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2017.7.20
      * brief:      数据管理界面获取参数
******************************************************************************/
void w_Main::Pubs_from_data(QStringList list, int number, int value)
{
    switch (value) {
    case 1:
        Pubs_ChangeWindow(number);
        break;
//    case 2:
//        Singal_to_SQL(QString(""),list,3);
//        MYSQL_DB->start();
//        break;
//    case 3:
//        Singal_to_SQL(QString(""),list,1);
//        MYSQL_DB->start();
//        break;
//    case 4:
//        Singal_to_SQL(QString(""),QStringList(""),2);
//        MYSQL_DB->start();
//        break;
//    case 5:
//        Singal_to_SQL(QString(""),QStringList(""),4);
//        break;
    default:
        break;
    }
}
/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2017.7.20
      * brief:      密码界面获取参数
******************************************************************************/
void w_Main::Pubs_from_pass(int number, int value) {
    switch (value) {
    case 1:
        Pubs_ChangeWindow(number);
        break;
    case 2:
        Pri_Change_Password();
        break;
    default:
        break;
    }
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2017.7.20
      * brief:      颜色界面获取参数
******************************************************************************/
void w_Main::Pubs_from_color(QString str, int number, int value) {
    switch (value) {
    case 1:
        Pubs_ChangeWindow(number);
        break;
    case 2:
        Pri_Sync_Color(str);
        break;
    default:
        break;
    }
}
/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2017.7.20
      * brief:      测试界面获取参数
******************************************************************************/
void w_Main::Pubs_from_test(int number, int value) {
    qDebug() << "Pubs_from_test" << number << value;
    int i;
    switch (value) {
    case 1:
        Pubs_ChangeWindow(number);
        break;
    case 2:
        Start_get_pg_shape = false;
        for (i = 0; i < 800; i++)  {
            waveform_point[i] = 0;
            waveform_IMP_Compare[i] = 0;
            waveform_IMP_YY_Compare[i] = 0;
            waveform_point_c[i] = 0;
        }
        break;
    case 3:

        break;
    case 5:

        break;
    case 6:
        // 状态清空
        PG_Down_Get_Data = true;
        PG_Finsh_Count = 0;
        PG_Finsh_Shape_Count = number;

        WD_I = 0.00;
        WD_V = 0.00;
        WD_P = 0.00;
        Square_WD = 0.00;
        I_Vcc = 0;
        I_Vsp = 0;
        pg_Turn = 0;
        Phase_enable = 0;

        BEMF_HIGH_Low.clear();
        for (int i = 0; i < 150; i++) {
            BEMF_HIGH_Low.append("0");
        }
        Shape_BEMF_Fre.clear();
        for (int i = 0; i < 20; i++) {
            Shape_BEMF_Fre.append("0");
        }
        Phase_diffence.clear();
        for (int i = 0; i < 20; i++) {
            Phase_diffence.append("0");
        }
        PG_State_Check_Time->start(200);
        break;
    default:
        break;
    }
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2017.7.20
      * brief:      调试界面获取参数
******************************************************************************/
void w_Main::Pubs_from_debug(QStringList list, int number, int value) {
    switch (value) {
    case 1:
        Pubs_ChangeWindow(number);
        wTest->Pub_Main_to_test(list, QString(""), 1, 18);
        break;
    case 2:

        break;
    case 3:
        ui->label_net->show();
        ui->label_no_connect->hide();
        break;
    case 4:
        ui->label_net->hide();
        break;
    default:
        break;
    }
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2016.5.5
      * brief:      保存系统配置数据
******************************************************************************/
void w_Main::Pri_SaveSystemData(QStringList list)
{
    int i = 0;
    if (system_conf != list.mid(0, 6)) {
        if (system_conf.at(4).toInt() != list.at(4).toInt()) { // 下发启动方式
            for (i = 0; i < 5; i++) {
                if (board_state[i*2] != 0) {
                    continue;
                } else {
                    //
                }
                Pri_Can_Set_OUTModel(0x13+i, list.at(4).toInt());
            }
        }
        system_conf = list;
        wConf->Pub_main_to_conf(list, QString(""), 2, 3);
        Signal_main_to_pic(list, 1000, 1000);
        DCR_Beep_Ok = system_conf.at(1).toDouble();
        DCR_Beep_Ng = system_conf.at(2).toDouble();
    } else {
        qDebug() << "w_Main::Pri_SaveSystemData";
    }
    wTest->Pub_Main_to_test(list, QString(""), 1, 3);
}

/******************************************************************************
      * version:    1.0
      * author:     link
      * date:       2016.9.26
      * brief:      网络初始化设置
******************************************************************************/
void w_Main::Pri_TcpInit()
{
    tcp = new QThread(this); // 启动tcp连接
    MyTcpThread *tcpThread = new MyTcpThread;
    tcpThread->moveToThread(tcp);
    connect(tcp, SIGNAL(started()), tcpThread, SLOT(TcpInit()));
    connect(tcpThread, SIGNAL(TransformCmd(quint16, quint16, QByteArray)), \
            wDebug, SLOT(Slot_TransformCmd(quint16, quint16, QByteArray)));
    tcp->start();

    udp = new QThread(this); // 启动udp连接
    UdpClient *udpThread = new UdpClient;
    udpThread->moveToThread(udp);
    connect(udp, SIGNAL(started()), udpThread, SLOT(Init()));
    connect(wConf, SIGNAL(WriteMessage(quint16, quint16, QByteArray)), \
            udpThread, SLOT(ReadMessage(quint16, quint16, QByteArray)));
    connect(wTest, SIGNAL(WriteMessage(quint16, quint16, QByteArray)), \
            udpThread, SLOT(ReadMessage(quint16, quint16, QByteArray)));
    connect(udpThread, SIGNAL(SendCommand(quint16, quint16, QByteArray)), \
            this, SLOT(ReadMessage(quint16, quint16, QByteArray)));
    connect(this, SIGNAL(WriteMessage(quint16, quint16, QByteArray)), \
            udpThread, SLOT(ReadMessage(quint16, quint16, QByteArray)));

    connect(wConf, SIGNAL(WriteMessage_NoVacuum(quint16, quint16, QByteArray)), \
            udpThread, SLOT(ReadMessage_NoVacuum(quint16, quint16, QByteArray)));
    connect(wTest, SIGNAL(WriteMessage_NoVacuum(quint16, quint16, QByteArray)), \
            udpThread, SLOT(ReadMessage_NoVacuum(quint16, quint16, QByteArray)));
    connect(this, SIGNAL(WriteMessage_NoVacuum(quint16, quint16, QByteArray)), \
            udpThread, SLOT(ReadMessage_NoVacuum(quint16, quint16, QByteArray)));
    udp->start();

    if (wTest->START_Model == 4) { // 连接模式,进行延时等待结果
        QEventLoop Wait_Shake_hand;
        for (int x = 0; x < 600; x++) {
            if (x % 2) {
                ui->label_hand->show();
            } else {
                ui->label_hand->hide();
            }
            if (Shake_hand_Success) {
                x = 616;
                ui->label_hand->show();
            }
            QTimer::singleShot(1000, &Wait_Shake_hand, SLOT(quit()));
            Wait_Shake_hand.exec();
            qDebug() << "w_Main::Pri_TcpInit() Wait PC shake hand....";
        }
    } else {
        qDebug() << "w_Main::Pri_TcpInit() Not shake hand";
    }
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2017.7.20
      * brief:      读取网络控制功能
******************************************************************************/
void w_Main::ReadMessage(quint16 addr, quint16 cmd, QByteArray msg)
{
    QString STATUSING;
    QSettings *set_Test_File;
    int Set_IO_L_Data;
    int Set_IO_H_Data;
    int Set_IO_Add_Data;

    if (addr != 6000) {
        return;
    } else {
        //
    }
    QStringList n = QString(msg).split(" ");
    switch (cmd) {
    case CMD_In_START:
        if (window_current == wTest_Surface) {
            wTest->Pub_Main_to_test(QStringList(""), QString::number(wTest->START_Model), n.at(0).toInt(), 11);
        } else {
            //
        }
        break;
    case CMD_In_STOP:
        wTest->Pub_Main_to_test(QStringList(""), "0", 1, 12);
        break;
    case CMD_In_STATUS_Ing:
        if (wTest->Back_Test_Status() == Test_Station_Free) {
            STATUSING = "free";
        } else {
            STATUSING = "busy";
        }
        WriteMessage_NoVacuum(6000, CMD_Put_STATUS_Ing, STATUSING.toUtf8());
        break;
    case CMD_In_Param:
        if ((wTest->Back_Test_Status() != Test_Station_Free) || \
                (Main_ActiveFile == QString(msg))) {
            WriteMessage(6000, CMD_Put_STATUS_Ing, QString(tr("Busy or Used")).toUtf8());
        } else {
            Pubs_ChangeWindow(8);     // 进入配置界面
            if (wConf->currentFile.contains(QString(msg))) {
                Pubs_ChangeWindow(8); // 进入配置界面
                wConf->Pub_main_to_conf(QStringList(""), QString(msg), 1, 18); // 修改型号
                Pubs_ChangeWindow(4); // 进入测试界面
                wConf->Pub_main_to_conf(QStringList(""), QString(""), 1, 7);
                WriteMessage(6000, CMD_Put_STATUS_Ing, QString(tr("Ok")).toUtf8());
            } else {
                WriteMessage(6000, CMD_Put_STATUS_Ing, QString(tr("No Model")).toUtf8());
            }
        }
        break;
    case CMD_In_ICO:
        if (udp_enable) {
            ui->label_print->show(); // -显示打印图标
        } else {
          //
        }
        if (wTest->START_Model == 4) {
            ui->label_hand->show();    // -显示握手标志
            Shake_hand_Success = true; // -进行握手标志
            WriteMessage(6000, CMD_Put_Login, QString(tr("Login")).toUtf8());
        } else {
            //
        }
        break;
    case CMD_In_CONF_Data:
        wConf->Pub_main_to_conf(QStringList(""), QString(""), n.at(0).toInt(), 13);
        if (n.at(0).toInt() == 1) {
            Pubs_ChangeWindow(8);
        } else {
            //
        }
        break;
    case CMD_In_Start_Item:
        wTest->Pub_Main_to_test(QStringList(""), n.at(1), 1, 10);
        break;
    case CMD_In_Init_Data:
        wConf->Pub_QbyteArray_conf(msg);
        break;
    case CMD_In_Judge:
//        Signal_main_to_pic(QStringList(""), 0, 5); //
//        wTest->Pub_Main_to_test(QStringList(""), QString(""), 0, 26);
//        Signal_main_to_pic(QStringList(""), 10, 5);
//        wTest->Pub_Main_to_test(QStringList(""), QString(""), 10, 26);
//        wTest->Pub_Main_to_test(QStringList(""), QString(""), 1, 33);
        Button_Main_Group_Judge(Qt::Key_D);
        break;
    case CMD_In_Add_Model:
        wConf->Pub_main_to_conf(QStringList(""), n.at(1), 1, 10);
        break;
    case CMD_In_Del_Model:
        wConf->Pub_main_to_conf(QStringList(""), QString(""), 2, 10);
        break;
    case CMD_In_Oder_Model:
        wConf->Pub_main_to_conf(QStringList(""), QString(""), 3, 10);
        break;
    case CMD_Put_Updae_Model:
        wConf->Pub_main_to_conf(QStringList(""), n.at(1), 5, 10);
        break;
    case CMD_Put_All_Start:
        if (window_current == wTest_Surface) {
            out_station = n.at(1).toInt(); // 记录当前工位
            if (Ini_Vacuum_Model) {
                Signal_main_to_pic(QStringList(""), n.at(1).toInt()-19, 15);
            } else {
                wTest->Pub_Main_to_test(QStringList(""), "3", n.at(1).toInt(), 11);
            }
        } else {
            //
        }
        break;
    case CMD_In_9a:
        if (window_current == wTest_Surface) {
            Back_out_station = n.at(1).toInt();
            out_station = n.at(1).toInt();
            wTest->Pub_Main_to_test(QStringList(""), QString::number(Ini_Set_Model), n.at(1).toInt(), 11);
        } else {
            //
        }
        break;
    case CMD_Put_All_Stop:
        qDebug() << "w_Main::ReadMessage() CMD_Put_All_Stop";
        wTest->Pub_Main_to_test(QStringList(""), "0", 1, 12);
        Signal_main_to_pic(QStringList(""), out_station-19, 17);
        break;
    case CMD_In_Connect:
        WriteMessage((6000), CMD_Put_Message, QString(WMessage_Record.join(" ")).toUtf8());
        break;
    case CMD_Put_Time:
        wTest->Pub_Main_to_test(QStringList(""), QString(""), 6001, 1);
        break;
    case CMD_In_IO_Put:
        qDebug() << "w_Main::ReadMessage() CMD_In_IO_Put" << n;
        frame.can_id  = 0x2D;  frame.can_dlc = 0x04;
        frame.data[0] = 0xf1;
        frame.data[1] = n.at(1).toInt()%256;       // (1<<(ui->IO_Bit1->text().toInt()));
        frame.data[2] = n.at(1).toInt()%65536/256; // (1<<(ui->IO_Bit2->text().toInt()));
        frame.data[3] = n.at(1).toInt()/65536;     // (1<<(ui->IO_Bit2->text().toInt()));
        canSend(frame, 88);
        break;
    case CMD_In_MAG_Sample:
        IMP_Sample_Dou = false;
        if (Ini_MAG_Device) {
            Signal_main_to_pic(QStringList(""), 1, 9);
        } else {
            wConf->Pub_main_to_conf(QStringList(""), QString(""), n.at(1).toInt(), 19);
            wConf->Pub_main_to_conf(QStringList(""), QString(""), 24, 2);
        }
        break;
    case CMD_In_IMP_Sample: // 匝间采样
        IMP_Sample_Dou = false;
        Back_out_station = n.at(1).toInt();
        PLC_test_to_Switchover(BDVacuum, n.at(1).toInt() - 18, 9);
        if (n.at(2).toInt()) {
            Signal_main_to_pic(QStringList(""), n.at(1).toInt(), 6); // 0x13 0x14
        } else {
            wConf->Pub_main_to_conf(QStringList(""), QString(""), n.at(1).toInt(), 19);
            wConf->Pub_main_to_conf(QStringList(""), QString(""), 24, 2);
        }
        break;
    case CMD_In_A6:
        IMP_Sample_Dou = true;
        Back_out_station = n.at(1).toInt();
        PLC_test_to_Switchover(BDVacuum, n.at(1).toInt() - 18, 9);
        if (n.at(2).toInt()) {
            Signal_main_to_pic(QStringList(""), n.at(1).toInt(), 6); // 0x13 0x14
        } else {
            wConf->Pub_main_to_conf(QStringList(""), QString(""), n.at(1).toInt(), 19);
            wConf->Pub_main_to_conf(QStringList(""), QString(""), 24, 21);
        }
        break;
    case CMD_In_IMP_Ready:
        //
        break;
    case CMD_In_IMP_Finsh: // 匝间采集完成
        frame.can_id = Back_out_station;
        frame.can_dlc = 0x02; //-输出板输出量信号发送
        frame.data[0] = 0x02;
        frame.data[1] = 0x02;
        canSend(frame, 88); usleep(500);
        out_board->setSingleShot(TRUE);
        out_board->start(system_conf.at(1).toDouble()*1000 + 100); //-印度客户启动定时器
        PLC_test_to_Switchover(BDVacuum, 0, 9);
        Signal_main_to_pic(QStringList(""), 1, 6);
        break;
    case CMD_In_Vacuum_IMP:
        Signal_main_to_pic(QStringList(""), n.at(1).toInt(), 5);
        wTest->Pub_Main_to_test(QStringList(""), QString(""), n.at(1).toInt(), 26);
        break;
    case CMD_In_Vacuum_ACW:
        Signal_main_to_pic(QStringList(""), n.at(1).toInt()+10, 5); // 耐压真空测试
        wTest->Pub_Main_to_test(QStringList(""), QString(""), n.at(1).toInt()+10, 26);
        break;
    case CMD_In_IMP_PL:
        wConf->WIMP->Pub_Conf_Set_IMP(n.at(1), 15);
        break;
    case CMD_In_Start_Auto:
        Signal_main_to_pic(QStringList(""), n.at(1).toInt(), 19);
        break;
    case CMD_In_PIC:
        if (n.at(1).toInt()) {
            qDebug() << "w_Main::ReadMessage() -----------disconnect-PIC";
            PIC_Connect = false;
            Signal_main_to_pic(QStringList(""), 0, 18);
            disconnect(wpic, SIGNAL(canSend(can_frame, int)), \
                       this, SLOT(canSend(can_frame, int)));
        } else {
            qDebug() << "w_Main::ReadMessage() ---------connect-PIC";
            PIC_Connect = true;
            connect(wpic, SIGNAL(canSend(can_frame, int)), this, SLOT(canSend(can_frame, int)));
        }
        break;
    case CMD_In_Start_No:
        wTest->Pub_Main_to_test(QStringList(""), QString(""), n.at(1).toInt(), 27);
        break;
    case CMD_IN_Beep:
        if (n.size() < 3) {
            break;
        } else {
            //
        }
        system_conf.replace(1, n.at(1));
        system_conf.replace(2, n.at(2));
        Pri_Synchron_Syst_Data();
        break;
    case CMD_In_A2:
        if (n.at(1).toInt()) {
            Set_IO_H_Data = 0x02;
        } else {
            Set_IO_H_Data = 0x00;
        }
        frame.can_id  = 0x2D;  frame.can_dlc = 0x04;
        frame.data[0] = 0xf1;
        frame.data[1] = 0x00;
        frame.data[2] = 0x00;
        frame.data[3] = Set_IO_H_Data;
        canSend(frame, 88);
        break;
        break;
    case CMD_In_A3:
        if (n.at(1).toInt()) {
            Set_IO_L_Data = 0x40;
            Set_IO_H_Data = 0x04;
            Set_Drive = true;
        } else {
            Set_IO_L_Data = 0x40;
            Set_IO_H_Data = 0x02;
            Set_Drive = false;
        }
        frame.can_id  = 0x2D;  frame.can_dlc = 0x04;
        frame.data[0] = 0xf1;
        frame.data[1] = 0x00;
        frame.data[2] = Set_IO_L_Data;
        frame.data[3] = Set_IO_H_Data;
        canSend(frame, 88);
        break;
    case CMD_In_A4: // 苏鹏控制变频器电源
       frame.can_id  = 0x2C;  frame.can_dlc = 0x02;
       frame.data[0] = 0x18;
       frame.data[1] = n.at(1).toInt();
       canSend(frame, 88); usleep(600);
       usleep(1000);

       frame.can_id  = 0x2C;  frame.can_dlc = 0x08;
       frame.data[0] = 0x03;
       frame.data[1] = n.at(2).toInt();
       frame.data[2] = n.at(3).toInt(); // 01 vcc    02 vsp    03 vm
       if (n.at(3).toInt() == 1) { // 01 菊水
           frame.data[3] = n.at(4).toInt();
           frame.data[4] = int(n.at(5).toInt())%256;
           frame.data[5] = int(n.at(5).toInt())/256;
           frame.data[6] = 0x00;
           frame.data[7] = 0x00;
       } else if (n.at(3).toInt() == 2)  { // 02 天虹
           frame.data[3] = n.at(4).toInt();
           frame.data[4] = int(n.at(5).toInt())/1000;
           frame.data[5] = int(n.at(5).toInt())%1000/100;
           frame.data[6] = int(n.at(5).toInt())%100/10;
           frame.data[7] = int(n.at(5).toInt())%10;
       } else { // 03 蓝仪
           frame.data[3] = n.at(4).toInt();
           frame.data[4] = int(n.at(5).toInt())%256;
           frame.data[5] = int(n.at(5).toInt())/256;
           frame.data[6] = 0x00;
           frame.data[7] = 0x00;
       }
       canSend(frame, 88); usleep(600);

       frame.can_id  = 0x2C;  frame.can_dlc = 0x02;
       frame.data[0] = 0x18;
       frame.data[1] = n.at(1).toInt();
       canSend(frame, 88); usleep(600);
       usleep(1000);

       frame.can_id  = 0x2C;  frame.can_dlc = 0x08;
       frame.data[0] = 0x03;
       frame.data[1] = n.at(2).toInt();
       frame.data[2] = n.at(3).toInt(); // 01 vcc    02 vsp    03 vm
       if (n.at(3).toInt() == 1) { // 01 菊水
           frame.data[3] = n.at(4).toInt();
           frame.data[4] = int(n.at(5).toInt())%256;
           frame.data[5] = int(n.at(5).toInt())/256;
           frame.data[6] = 0x00;
           frame.data[7] = 0x00;
       } else if (n.at(3).toInt() == 2)  { // 02 天虹
           frame.data[3] = n.at(4).toInt();
           frame.data[4] = int(n.at(5).toInt())/1000;
           frame.data[5] = int(n.at(5).toInt())%1000/100;
           frame.data[6] = int(n.at(5).toInt())%100/10;
           frame.data[7] = int(n.at(5).toInt())%10;
       } else { // 03 蓝仪
           frame.data[3] = n.at(4).toInt();
           frame.data[4] = int(n.at(5).toInt())%256;
           frame.data[5] = int(n.at(5).toInt())/256;
           frame.data[6] = 0x00;
           frame.data[7] = 0x00;
       }
       canSend(frame, 88); usleep(600);
       break;
    case CMD_In_A7:
        Set_IO_Add_Data = n.at(1).toInt()%65536/256;
        Set_IO_L_Data = n.at(1).toInt()%256;
        Set_IO_H_Data = n.at(1).toInt()/65536;

        if (Set_Drive) {
            Set_IO_L_Data = Set_IO_L_Data|0x40;
            Set_IO_H_Data = 0x04 | Set_IO_H_Data;
        } else {
            Set_IO_L_Data = Set_IO_L_Data|0x40;
            Set_IO_H_Data = 0x02 | Set_IO_H_Data;
        }

        qDebug() << "w_Main::ReadMessage() CMD_In_A7 Set_IO_Add_Data" << Set_IO_Add_Data\
                 << "Set_IO_L_Data" << Set_IO_L_Data
                 << "Set_IO_H_Data" << Set_IO_H_Data;
        frame.can_id  = 0x2D;  frame.can_dlc = 0x04;
        frame.data[0] = 0xf1;
        frame.data[1] = Set_IO_Add_Data;
        frame.data[2] = Set_IO_L_Data;
        frame.data[3] = Set_IO_H_Data;
        canSend(frame, 88);
        break;
    case CMD_In_A8:
        if (n.at(1).toInt()) {
            Pubs_Usart_Send_E(QString("LEDG").toLatin1().data());
        } else {
            Pubs_Usart_Send_E(QString("LEDR").toLatin1().data());
        }
        break;
    case CMD_In_Test_Auto:
        if (n.size() != 4) {
            break;
        } else {
            set_Test_File = new QSettings(Sys_path, QSettings::IniFormat);
            set_Test_File->setIniCodec("GB18030");
            set_Test_File->setValue("Selfstart/value", QStringList(n.mid(1, 3))); // -自动启动
            wTest->Pub_Main_to_test(QStringList(n.mid(1, 3)), QString(""), 1, 18);
        }
        break;
    case CMD_In_MEIZHI:
        WriteMessage((6000), CMD_Put_MEIZHI, QString::number(wpic->Record_Test).toUtf8());
        Signal_main_to_pic(QStringList(""), 0, 21);
        wTest->Pub_Main_to_test(QStringList(""), QString(""), 1, 122);
        Out_Board_Stop();
        break;
    case CMD_In_AA:
        frame.can_id = 0x2c;  frame.can_dlc = 0x08; // WD板控制继电器
        frame.data[0] = 0x15;
        frame.data[1] = 0x03;
        frame.data[2] = n.at(1).toInt() - 0x12; // 1
        frame.data[3] = n.at(2).toInt(); // 2018-2-28 内外置驱动
        frame.data[4] = 0x00;
        frame.data[5] = 0x00;
        frame.data[6] = 0x00;
        frame.data[7] = 0x00;
        canSend(frame, 88);
        break;
    case CMD_Put_GetTemp:
        Net_Get_Temp = n.at(0).toDouble();
        wTest->Pub_Main_to_test(QStringList(""), n.at(0), 1, 138);
        break;
    case CMD_In_GetOut:
        Signal_main_to_pic(QStringList(""), n.at(1).toInt(), 22);
        break;
    case CMD_In_Two_ACW:
        wTest->Pub_Main_to_test(QStringList(""), QString(""), n.at(1).toInt(), 33);
        break;
    case CMD_In_No_Start:
        Signal_main_to_pic(QStringList(""), n.at(1).toInt(), 24);
        break;
    case CMD_In_Delay:
        wTest->Pub_Main_to_test(n, QString(""), 1, 34);
        break;
    default:
        //
        break;
    }
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2016.5.6
      * brief:      修改密码
******************************************************************************/
void w_Main::Pri_Change_Password()
{
    Ini_Password.clear();
    Ini_Password.append(wPassWord->Password.Syst);
    Ini_Password.append(wPassWord->Password.Debug);
    Ini_Password.append(wPassWord->Password.Conf);

    Pri_Synchron_PassWord_Data();
    wConf->Pub_main_to_conf(system_conf, QString(""), 3, 3);
}

/***********************************************************
    * @name	 	1.0
    * @brief  	SL
    * @param  	2016.3.24
    * @retval 	初始进入测试界面
***********************************************************/
void w_Main::Pubs_Cheak_Ready()
{
    int i = 0;
    int Check_CurrentProj = 0;
    Cheak_Ready_count++;
    if (Cheak_Ready_count%2 == 1) {
        qDebug() << "w_Main::Pubs_Cheak_Ready() Clear Data";
        for (int j = 0; j < 240; j++) { // 初始化记录数值
            board_state[j] = 100;
        }
    }
    for (i = 0; i < Ini_Proj_Real.size(); i++) {
        if (i <= 5) {
            Version.OutV[i]="0";
            if (Ini_Proj_Real.at(i).toInt() != 0) {
                Pri_Can_CheckState(0x13+i);   usleep(1800);
                Pri_Can_CheckVersion(0x13+i); usleep(1800);
            } else {
                //
            }
        } else if (Ini_Proj_Real.at(i).toInt() <= 2) { // 电阻板
            if (Check_CurrentProj != 2) {
                Pri_Can_CheckState(0x22);   usleep(1800);
                Pri_Can_CheckVersion(0x22); usleep(1800);
                Check_CurrentProj = 2;
            } else {
                //
            }
            continue;
        } else if (Ini_Proj_Real.at(i).toInt() <= 5) { // 绝缘板
            if (Check_CurrentProj != 5) {
                Pri_Can_CheckState(0x23);   usleep(1800);
                Pri_Can_CheckVersion(0x23); usleep(1800);
                Check_CurrentProj = 5;
            } else {
                //
            }
            continue;
        } else if (Ini_Proj_Real.at(i).toInt() <= 6) { // 匝间板
            if (Check_CurrentProj != 6) {
                Pri_Can_CheckState(0x24);   usleep(1800);
                Pri_Can_CheckVersion(0x24); usleep(1800);
                Check_CurrentProj = 6;
            } else {
                //
            }
            continue;
        } else if ((Ini_Proj_Real.at(i).toInt() == 7) || (Ini_Proj_Real.at(i).toInt() == 9) || \
                   (Ini_Proj_Real.at(i).toInt() == 10)) { // 电参板
            if (Check_CurrentProj != 7) {
                Pri_Can_CheckState(0x27);   usleep(1800);
                Pri_Can_CheckVersion(0x27); usleep(1800);
                usleep(1000);
                Check_CurrentProj = 7;
            } else {
                //
            }
            continue;
        } else if (Ini_Proj_Real.at(i).toInt() <= 8) { // 电感板
            if (Check_CurrentProj != 8) {
                Pri_Can_CheckState(0x26);   usleep(1800);
                Pri_Can_CheckVersion(0x26); usleep(1800);

                frame.can_id = 0x26;  frame.can_dlc = 0x02;
                frame.data[0] = 0x07;
                frame.data[1] = 0x00;
                canSend(frame, 88); //  输出板发送
                usleep(1800);
                Check_CurrentProj = 8;
            } else {
                //
            }
            continue;
        } else if (Ini_Proj_Real.at(i).toInt() <= 11) { // 电感板
            if (Check_CurrentProj != 11) {
                Pri_Can_CheckState(0x2C);   usleep(1800);
                Pri_Can_CheckVersion(0x2C); usleep(1800);
                usleep(1800);
                Check_CurrentProj = 11;
            } else {
                //
            }
            continue;
        } else {
            //
        }
    }
    if (nine_board) { // 判断为9插板，进行功放板状态的查询
        Pri_Can_CheckState(0x2A);   usleep(1800);
        Pri_Can_CheckVersion(0x2A); usleep(1800); // 进行功放板的版本查询
        qDebug() << "w_Main::Pubs_Cheak_Ready() Check Connet";
        frame.can_id = 0x2A;  frame.can_dlc = 0x01; //-输出板发送
        frame.data[0] = 0x03;
        canSend(frame, 88);
        usleep(500);
        usleep(1800);
    } else {
        //
    }
    if (acsw_board) { // 查询电源板
        Pri_Can_CheckState(0x29);   usleep(1800); // 进行电源切换板的查询
        Pri_Can_CheckVersion(0x29); usleep(1800); // 进行电源切换板的版本查询
    } else {
        //
    }
    if (Ini_WD == QString(tr("WD"))) {  // 查询WD板
        Pri_Can_CheckState(0x2B);   usleep(1800); // 进行WD的查询
        Pri_Can_CheckVersion(0x2B); usleep(1800); // 进行WD的版本查询
    } else {
        //
    }

    if (Ini_IO) { // 查询IO板
        Signal_main_to_pic(QStringList(""), Ini_IO_Model, 119); // 控制气缸
        Pri_Can_CheckState(0x2d);   usleep(1800); // 进行WD的查询
        Pri_Can_CheckVersion(0x2d); usleep(1800); // 进行WD的版本查询

        frame.can_id  = 0x2D;  frame.can_dlc = 0x03;
        frame.data[0] = 0xf5;
        frame.data[1] = 0x01;
        if (Ini_Start_Stop) {
           frame.data[2] = 0x01;
        } else {
           frame.data[2] = 0x00;
        }
        canSend(frame, 88);
        usleep(1800);

        frame.can_id  = 0x2D;  frame.can_dlc = 0x01;
        frame.data[0] = 0xf0;
        canSend(frame, 88);
        usleep(1800);

        frame.can_id = 0x2d; // 查询初始状态的ＡＤ的数值
        frame.can_dlc = 0x03;
        frame.data[0] = 0xf2;
        frame.data[1] = 0x05;
        frame.data[2] = 0x00;
        canSend(frame, 88);
        usleep(1800);
    } else {
        //
    }

    if (Ini_new_rot) {
        Pri_Can_CheckState(0x25);   usleep(1800); //
        Pri_Can_CheckVersion(0x25); usleep(1800); //
    } else {
        //
    }
    QTimer *Time_Cheak_Finsh = new QTimer(this);
    if ((window_current == wMain_Surface) && (Cheak_Ready_count%2 == 0)) {
        connect(Time_Cheak_Finsh, SIGNAL(timeout()), this, SLOT(Pubs_Cheak_Main_Finsh()));
        Time_Cheak_Finsh->setSingleShot(TRUE);
        Time_Cheak_Finsh->start(280);
    } else if ((window_current == wSyst_Surface) && (Cheak_Ready_count%2 == 0)) {
        connect(Time_Cheak_Finsh, SIGNAL(timeout()), this, SLOT(Pubs_Cheak_Syst_Finsh()));
        Time_Cheak_Finsh->setSingleShot(TRUE);
        Time_Cheak_Finsh->start(280);
    } else {
        connect(Time_Cheak_Finsh, SIGNAL(timeout()), this, SLOT(Pubs_Cheak_Ready()));
        Time_Cheak_Finsh->setSingleShot(TRUE);
        Time_Cheak_Finsh->start(50);
    }
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2017.7.20
      * brief:      系统设置界面查询板子的状态
******************************************************************************/
void w_Main::Pubs_Cheak_Syst_Finsh()
{
    int i;
    int Error_Flag = 0;
    int All_OK = 0;
    int Check_CurrentProj = 0;

    for (i = 0; i < Ini_Proj_Real.size(); i++) {
        if (i<= 5) {
            if (Ini_Proj_Real.at(i).toInt() != 0) {
                if (board_state[i*2] == 0) { //  输出板
                    //
                } else if (board_state[i*2] == 100) {
                    Error_Flag = i+13;
                } else {
                    Error_Flag = i+13;
                }
            }
        }  else if (Ini_Proj_Real.at(i).toInt() <= 2) {
            if (Check_CurrentProj != 2) {
                if (board_state[20] == 0) { //  电阻板
                    //
                } else if (board_state[20] == 100) {
                    Error_Flag = 2;
                } else {
                    Error_Flag = 2;
                }
                Check_CurrentProj = 2;
            }
        } else if (Ini_Proj_Real.at(i).toInt() <= 5) {
            if (Check_CurrentProj != 3) {
                if (board_state[40] == 0) { //  绝缘板
                   //
                } else if (board_state[40] == 100) {
                    Error_Flag = 3;
                } else {
                    Error_Flag = 3;
                }
                Check_CurrentProj = 3;
            }
        } else if (Ini_Proj_Real.at(i).toInt() <= 6) {
            if (Check_CurrentProj != 4) {
                if (board_state[60] == 0) { //  匝间板
                   //
                } else if (board_state[60] == 100) {
                    Error_Flag = 4;
                } else {
                    Error_Flag = 4;
                }
                Check_CurrentProj = 4;
            } else {
                //
            }
        } else if ((Ini_Proj_Real.at(i).toInt() == 7) || (Ini_Proj_Real.at(i).toInt() == 9) || \
                   (Ini_Proj_Real.at(i).toInt() == 10)) { // 电参板
            if (Check_CurrentProj != 5) {
                if (board_state[80] == 0) {
                    ui->Print_Text->append("System PWR Ok");
                    ui->Print_Text->append("System PWR Version");
                    ui->Print_Text->append(Version.PWR_LV+"  ");
                } else if (board_state[80] == 100) {
                    Error_Flag = 5;
                    ui->Print_Text->append("System PWR Can communication Error");
                } else {
                    Error_Flag = 5;
                    ui->Print_Text->append("System PWR Error");
                    ui->Print_Text->append(QString::number(board_state[80]));
                    ui->Print_Text->append("System PWR Error Value");
                    ui->Print_Text->append(QString::number(board_state[90]));
                }
                Check_CurrentProj = 5;
            } else {
                //
            }
        } else if (Ini_Proj_Real.at(i).toInt() <= 8) {
            if (Check_CurrentProj != 7) {
                if ((board_state[100] == 0) || (board_state[100] == 3)) { //  电感板
                    //
                } else if (board_state[100] == 100) {
                    Error_Flag = 7;
                } else {
                    Error_Flag = 7;
                }
                Check_CurrentProj = 7;
            } else {
                //
            }
        } else if (Ini_Proj_Real.at(i).toInt() <= 11) {
            if (Check_CurrentProj != 8) {
                if ((board_state[170] == 0) || (board_state[170] == 10)) { // PG板
                    //
                } else if (board_state[170] == 100) {
                    Error_Flag = 8;
                } else {
                    Error_Flag = 8;
                }
                Check_CurrentProj = 8;
            } else {
                //
            }
        } else {
            //
        }
        if (Error_Flag != 0) {
            switch (Error_Flag) {
            case 1:
                Sigmain_data_to_syst(QString(tr("         输出板异常        ")), 1);
                break;
            case 2:
                Sigmain_data_to_syst(QString(tr("         电阻板异常        \n" \
                                                "B02A--异常      ")), 1);
                break;
            case 3:
                Sigmain_data_to_syst(QString(tr("         绝缘板异常        \n" \
                                                "B03A--异常      ")), 1);
                break;
            case 4:
                Sigmain_data_to_syst(QString(tr("         匝间板异常        \n" \
                                                "B04A--异常      ")), 1);
                break;
            case 5:
                Sigmain_data_to_syst(QString(tr("         电参板异常        \n" \
                                                "B07A--异常      ")), 1);
                break;
            case 6:
                Sigmain_data_to_syst(QString(tr("         电参板异常        \n" \
                                                "B07A--异常      ")), 1);
                break;
            case 7:
                Sigmain_data_to_syst(QString(tr("         电感板异常        \n" \
                                                "B06A--异常      ")), 1);
                break;
            case 8:
                Sigmain_data_to_syst(QString(tr("         PG板异常        \n" \
                                                "B0CA--异常      ")), 1);
                break;
            default:
                if (Error_Flag == 13) {
                    Sigmain_data_to_syst(QString(tr("         左输出板异常        \n" \
                                                    "B10A---异常      ")), 1);
                } else if (Error_Flag == 14) {
                    Sigmain_data_to_syst(QString(tr("         右输出板异常        \n" \
                                                    "B10A---异常      ")), 1);
                } else {
                    //
                }
                break;
            }
            All_OK++;
            Error_Flag = 0;
        }
    }
    if ((nine_board) && (!GND_State)) { // 判断为9插板进行，接地的检查
        All_OK++;
        Sigmain_data_to_syst(QString(tr("         系统接地异常！        \n" \
                                        "建议接地后使用     ")), 1);
    } else {
        //
    }
    if (acsw_board) {
        if (board_state[140] == 0) {
            //
        } else if (board_state[140] == 100) {
            All_OK++;
            Sigmain_data_to_syst(QString(tr("         电源切换板异常！        \n" \
                                            "B0BA 异常     ")), 1);
        } else {
            All_OK++;
        }
    } else {
        //
    }

    if (Ini_WD == QString(tr("WD"))) {
        if (board_state[190] == 0) {
            //
        } else if (board_state[190] == 100) {
            All_OK++;
            Sigmain_data_to_syst(QString(tr("         WD板异常！        \n:"\
                                            "B09A 异常     ")), 1);
        } else {
            All_OK++;
        }
    } else {
        //
    }
    if (Ini_IO) {
        if (board_state[210] == 17) {
            //
        } else if (board_state[210] == 100) {
            All_OK++;
            Sigmain_data_to_syst(QString(tr("         IO板异常！        \n" \
                                            "B0DA 异常     ")), 1);
        } else {
            //
        }
    } else {
        //
    }

    if (Ini_new_rot) {
        if (board_state[230] == 0) {
            //
        } else if (board_state[230] == 100) {
            All_OK++;
            Sigmain_data_to_syst(QString(tr("         ROT板异常！        \n" \
                                            "B5DA 异常     ")), 1);
        } else {
            //
        }
    } else {
        //
    }

    if (All_OK == 0) {
        Sigmain_data_to_syst(QString(tr("       全部正常      ")), 1);
    } else {
        //
    }
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2017.7.20
      * brief:      主页面查询板子的状态
******************************************************************************/
void w_Main::Pubs_Cheak_Main_Finsh()
{
    int i = 0;
    int Error_Flag = 0;
    QString string_q = "";
    int Check_CurrentProj = 0;
    int Check_PWR_L = 0;
    bool AMP_Error;
    AMP_Error = false;

    ui->Print_Text->hide();
    ui->label_4->hide();
    for (i = 0; i < Ini_Proj_Real.size(); i++) {
        if (i <= 5) {
            if (Ini_Proj_Real.at(i).toInt() != 0) {
                if (board_state[i*2] == 0) { //  输出板
                    string_q = QString("System OUT %1 Ok").arg(QString::number(13 + i));
                    ui->Print_Text->append(string_q); string_q.clear();
                    ui->Print_Text->append(QString(Version.OutV[i])+"  ");
                    Pri_Can_Set_OUTModel(0x13 + i, system_conf.at(4).toInt());
                } else if (board_state[i*2] == 100) {
                    Error_Flag = i+13;
                    string_q = QString("System OUT %1 Can communication Error").arg \
                            (QString::number(13 + i));
                    ui->Print_Text->append(string_q);  string_q.clear();
                } else {
                    Error_Flag = i+13;
                    string_q = QString("System OUT %1 Error").arg(QString::number(13 + i));
                    ui->Print_Text->append(string_q);  string_q.clear();
                }
            }
        } else if (Ini_Proj_Real.at(i).toInt() <= 2) {
            if (Check_CurrentProj != 2) {
                if (board_state[20] == 0) { //  电阻板
                    ui->Print_Text->append("System DLR Ok");
                    ui->Print_Text->append("System DLR Version");
                    ui->Print_Text->append(Version.DLRV+"  ");
                } else if (board_state[20] == 100) {
                    Error_Flag = 2;
                    ui->Print_Text->append("System DLR Can communication Error");
                } else {
                    Error_Flag = 2;
                    ui->Print_Text->append("System DLR Error");
                    ui->Print_Text->append(QString::number(board_state[20]));
                }
                Check_CurrentProj = 2;
            }
        } else if (Ini_Proj_Real.at(i).toInt() <= 5) {
            if (Check_CurrentProj != 3) {
                if (board_state[40] == 0) { //  绝缘板
                    ui->Print_Text->append("System IR Ok");
                    ui->Print_Text->append("System IR Version");
                    ui->Print_Text->append(Version.IWV+"  ");
                } else if (board_state[40] == 100) {
                    Error_Flag = 3;
                    ui->Print_Text->append("System IR Can communication Error");
                } else {
                    Error_Flag = 3;
                    ui->Print_Text->append("System IR Error");
                    ui->Print_Text->append(QString::number(board_state[40]));
                    ui->Print_Text->append("System IR Error Value");
                    ui->Print_Text->append(QString::number(board_state[50]));
                }
                Check_CurrentProj = 3;
            }
        } else if (Ini_Proj_Real.at(i).toInt() <= 6) {
            if (Check_CurrentProj != 4) {
                if (board_state[60] == 0) { //  匝间板
                    ui->Print_Text->append("System IMP Ok");
                    ui->Print_Text->append("System IMP Version");
                    ui->Print_Text->append(Version.IMPV+"  ");
                } else if (board_state[60] == 100) {
                    Error_Flag = 4;
                    ui->Print_Text->append("System IMP Can communication Error");
                } else {
                    Error_Flag = 4;
                    ui->Print_Text->append("System IMP Error");
                    ui->Print_Text->append(QString::number(board_state[60]));
                    ui->Print_Text->append("System IMP Error Value");
                    ui->Print_Text->append(QString::number(board_state[70]));
                }
                Check_CurrentProj = 4;
            }
        } else if ((Ini_Proj_Real.at(i).toInt() == 7) || (Ini_Proj_Real.at(i).toInt() == 9) || \
                 (Ini_Proj_Real.at(i).toInt() == 10)) { // 电参板
            if (Check_PWR_L != 5) {
                if (board_state[80] == 0) {
                    ui->Print_Text->append("System PWR Ok");
                    ui->Print_Text->append("System PWR Version");
                    ui->Print_Text->append(Version.PWR_LV+"  ");
                } else if (board_state[80] == 100) {
                    Error_Flag = 5;
                    ui->Print_Text->append("System PWR Can communication Error");
                } else {
                    Error_Flag = 5;
                    ui->Print_Text->append("System PWR Error");
                    ui->Print_Text->append(QString::number(board_state[80]));
                    ui->Print_Text->append("System PWR Error Value");
                    ui->Print_Text->append(QString::number(board_state[90]));
                }
                Check_PWR_L = 5;
            } else {
                //
            }
        } else if (Ini_Proj_Real.at(i).toInt() <= 8) { //  电感板
            if (Check_CurrentProj != 7) {
                if ((board_state[100] == 0) || (board_state[100] == 3)) {
                    ui->Print_Text->append("System INDL Ok");
                    ui->Print_Text->append("System INDL Version");
                    ui->Print_Text->append(Version.INDLV+"  ");
                } else if (board_state[100] == 100) {   Error_Flag=7;
                    ui->Print_Text->append("System INDL Can communication Error");
                } else {
                    Error_Flag = 7;
                    ui->Print_Text->append("System INDL Error");
                    ui->Print_Text->append(QString::number(board_state[100]));
                    ui->Print_Text->append("System INDL Error Value");
                    ui->Print_Text->append(QString::number(board_state[110]));
                }
                Check_CurrentProj = 7;
            }
        } else if (Ini_Proj_Real.at(i).toInt() <= 11) { //  PG板
            if (Check_CurrentProj != 8) {
                if ((board_state[170] == 0) || (board_state[170] == 10)) {
                    ui->Print_Text->append("System PG Ok");
                    ui->Print_Text->append("System PG Version");
                    ui->Print_Text->append(Version.VBLDCPG+"  ");
                } else if (board_state[170] == 100) {
                    Error_Flag = 8;
                    ui->Print_Text->append("System PG Can communication Error");
                } else {
                    Error_Flag = 8;
                    ui->Print_Text->append("System PG Error");
                    ui->Print_Text->append("System PG Error Value");
                }
                Check_CurrentProj = 8;
            }
        } else {
            //
        }
        if (Error_Flag != 0) {
            switch (Error_Flag) {
            case 1:
                Pri_Main_WMessage(0, QString(tr("")));
                break;
            case 2:
                Pri_Main_WMessage(1, QString::number(board_state[20]));
                break;
            case 3:
                AMP_Error = true;
                Pri_Main_WMessage(2, QString::number(board_state[40]));
                break;
            case 4:
                Pri_Main_WMessage(3, QString::number(board_state[60]));
                break;
            case 5:
                if (board_state[80] != 0) {
                    Pri_Main_WMessage(4, QString::number(board_state[80]));
                } else {
                    //
                }
                break;
            case 7:
                Pri_Main_WMessage(5, QString::number(board_state[100]));
                break;
            case 8:
                Pri_Main_WMessage(12, QString::number(wTest->PG_Test_State));
                break;
            default:
                if (Error_Flag == 13) {
                    Pri_Main_WMessage(6, QString::number(board_state[0]));
                } else if (Error_Flag == 14) {
                    Pri_Main_WMessage(7, QString::number(board_state[2]));
                } else {
                    //
                }
                break;
            }
            Error_Flag = 0;
        }
    }
    if (nine_board) {
        if (board_state[120] == 0) {
            ui->Print_Text->append("System AMP Ok");
            ui->Print_Text->append("System AMP Version");
            ui->Print_Text->append(Version.AMP+"  ");
        } else if (board_state[120] == 100) {
            ui->Print_Text->append("System AMP Can communication Error");
        } else {
            ui->Print_Text->append("System AMP Error");
            ui->Print_Text->append(QString::number(board_state[120]));
        }
    } else {
        //
    }
    if ((nine_board) && (!GND_State)) { // 判断为9插板进行，接地的检查
        Pri_Main_WMessage(8, QString::number(System_Display_Volt));
    } else {
        //
    }
    if (acsw_board) {
        if (board_state[140] == 0) {
            ui->Print_Text->append("System ACSW Ok");
            ui->Print_Text->append("System ACSW Version");
            ui->Print_Text->append(Version.ACSW+"  ");
        } else if (board_state[140] == 100) {
            ui->Print_Text->append("System ACSW Can communication Error");
            Pri_Main_WMessage(9, QString::number(board_state[140]));
        } else {
            //
        }
    } else {
        //
    }
    if (Ini_WD == QString(tr("WD"))) {
        if (board_state[190] == 0) {
            ui->Print_Text->append("System WD Ok");
            ui->Print_Text->append("System WD Version");
            ui->Print_Text->append(Version.BLDCWD+"  ");
        } else if (board_state[190] == 100) {
            ui->Print_Text->append("System WD Can communication Error");
            Pri_Main_WMessage(11, QString::number(board_state[190]));
        } else {
            ui->Print_Text->append("System WD Error");
            ui->Print_Text->append("System WD Error Value");
        }
    }
    if (Ini_IO) {
        if (board_state[210] ==  17) {
            ui->Print_Text->append("System IO Ok");
            ui->Print_Text->append("System IO Version");
            ui->Print_Text->append(Version.IO+"  ");
        } else if (board_state[210] == 100) {
            ui->Print_Text->append("System IO Can communication Error");
            Pri_Main_WMessage(13, QString::number(board_state[210]));
        } else {
            ui->Print_Text->append("System IO Error");
            ui->Print_Text->append("System IO Error Value");
        }
    } else {
        //
    }

    if (Ini_new_rot) {
        if (board_state[230] == 0) {
            ui->Print_Text->append("System ROT Ok");
            ui->Print_Text->append("System ROT Version");
            ui->Print_Text->append(Version.New_Rot+"  ");
        } else if (board_state[230] == 100) {
            ui->Print_Text->append("System ROT Can communication Error");
            Pri_Main_WMessage(20, QString::number(board_state[230]));
        } else {
            ui->Print_Text->append("System ROT Error");
            ui->Print_Text->append("System ROT Error Value");
            Pri_Main_WMessage(20, QString::number(board_state[230]));
        }
    } else {
        //
    }

    ui->Print_Text->append("System Ok");
    qApp->processEvents();
    Sigmain_save_DayRecoord("Check", \
                            QString(ui->Print_Text->toPlainText().mid(503)).replace \
                            (QRegExp("\\s{2,}"), "，").replace(QRegExp("\\s{1,}"), " "));
    Sigmain_data_to_debug(QStringList(ui->Print_Text->toPlainText()), QString(""), 4);

    ui->label_2->hide();
    ui->label_->show();
    ui->Key_A->show();
    ui->Key_B->show();
    ui->Key_C->show();
    ui->Key_D->show();
    ui->label_Version->show();

    WriteMessage((6000), CMD_Put_V_State, QString("").toUtf8());
    if ((!(wTest->AMP_Conneted)) && (AMP_Error)) {
        ui->label_2->show();
        Reset_IR_ACW->setText(tr("复位"));
        AMP_Widget->show();
    } else {
        QTimer *Time_Jump = new QTimer(this);
        connect(Time_Jump, SIGNAL(timeout()), this, SLOT(Jump_wTest_Surface()));
        Time_Jump->setSingleShot(TRUE);
        Time_Jump->start(1000);
    }
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2016.6.7
      * brief:      跳转到Test界面
******************************************************************************/
void w_Main::Jump_wTest_Surface()
{
    Dechang_Join_Test(1);
    if ((Ini_Vacuum_Model) || (wTest->START_Model == Start_model_Net)) {
        qDebug() << "return---> w_Main::Jump_wTest_Surface()";
        return;
    } else {
        //
    }
    if (window_current != wMain_Surface) { //  判断当前页面为主页面
        qDebug() << "return---> w_Main::Jump_wTest_Surface()";
        return;
    } else {
        //
    }

    Pubs_ChangeWindow(4);
    wConf->Pub_main_to_conf(QStringList(""), QString(""), 1, 7);
}

void w_Main::Pubs_UDisk_Data(int a, QString USB) {
    Sigmain_save_DayRecoord("USB", " ");
//    wData->UDisk_Test(a, USB);
    a = 0;
    USB.clear();
}

/******************************************************************************
      * version:    1.0
      * author:     link
      * date:       2015.12.10
      * brief:      系统后台功能/CAN总线接收
******************************************************************************/
void w_Main::System_Runing()
{
    can_bug_time++;
    qint8 myComi; //初始化界面

    switch (step_system) {
    case 0:
        ui->Print_Text->append("0-Syetem-set:");
        ui->Print_Text->append("portnoo=tttyS3;");
        ui->Print_Text->append("m_baudRate=115200;");
        myCom  = new CSerial;
        myComi = myCom ->OpenPort(QString("ttyS3").toLatin1().data(), 115200, '8', '1', 'N');
        if (myComi < 0) {
            delete myCom;
            myCom = NULL;
        } else {
            ui->Print_Text->append("Open Usart success;");
        }
        connect(myCom, SIGNAL(readyRead(QString)), \
                this, SLOT(readMyCom(QString)));

        qDebug() << "w_Main::System_Runing() baudRate" << DeChang_baudRate_List.at(DeChang_baudRate);
        myCom_DeChang = new CSerial;
        if (Ini_IO_Model == DeChang) {
            myComi = myCom_DeChang ->OpenPort(QString("ttyS1").toLatin1().data(), \
                                              DeChang_baudRate_List.at(DeChang_baudRate).toInt(), \
                                              '8', '1', 'N');
        } else if (Ini_IO_Model == WL_Hall) {
            myComi = myCom_DeChang ->OpenPort(QString("ttyS1").toLatin1().data(), \
                                              9600, \
                                              '8', '1', 'N');
        } else if (Ini_IO_Model == ME_Hall) {
            myComi = myCom_DeChang ->OpenPort(QString("ttyS1").toLatin1().data(), \
                                              9600, \
                                              '8', '1', 'N');
        } else {
            //
        }

        if (myComi < 0) {
            delete myCom;
            myCom_DeChang = NULL;
        } else {
            //
        }
        if (Ini_IO_Model == DeChang) {
            connect(myCom_DeChang, SIGNAL(readyRead(QString)), \
                    this, SLOT(readMyCom_Dechang(QString)));
        } else if (Ini_IO_Model == WL_Hall) {
            //
        } else if (Ini_IO_Model == ME_Hall) {
            //
        } else {
            //
        }

        ui->Print_Text->append("can.canOpen(500000);");
        can.canOpen(500000); // -运行Can设置，进行配置,打开CAN口

        wSyst = new w_Syst;
        connect(wSyst, SIGNAL(signal_to_main(QStringList, int, int)), \
                this, SLOT(Pubs_from_syst(QStringList, int, int)));
        connect(this, SIGNAL(Sigmain_data_to_syst(QString, int)), \
                wSyst, SLOT(slot_from_main(QString, int)));

        wDebug = new w_Debug;
        connect(wDebug, SIGNAL(Singal_debug_to_main(QStringList, int, int)), \
                this, SLOT(Pubs_from_debug(QStringList, int, int)));
        connect(wDebug, SIGNAL(canSend(can_frame, int)), \
                this, SLOT(canSend(can_frame, int)));
        connect(this, SIGNAL(Sigmain_data_to_debug(QStringList, QString, int)), \
                wDebug, SLOT(Slot_from_Main(QStringList, QString, int)));


        for (int j = 0; j < 240; j++) { //-初始化记录数值
            board_state[j] = 100;
        }
        wPassWord = new PassWord;
        connect(wPassWord, SIGNAL(Singal_pass_to_main(int, int)), \
                this, SLOT(Pubs_from_pass(int, int)));
        step_system++;
        break;
    case 1:
        ui->Print_Text->append("1-Syetem-set:");
        step_system++;
        break;
    case 2:
        ui->Print_Text->append("2-Syetem-set:");
        wData = new SqlDesktop;
        connect(wData, SIGNAL(Signal_Data_to_Main(QStringList, int, int)), \
                this, SLOT(Pubs_from_data(QStringList, int, int)));
//      connect(myThread, SIGNAL(Singal_U_Test(int, QString)),
//              this, SLOT(Pubs_UDisk_Data(int, QString)));
        connect(myThread, SIGNAL(Singal_U_Test(int, QString)), \
                this, SLOT(Pubs_UDisk_Data(int, QString)));
        connect(this , SIGNAL(Singal_Record_Error(int, QString)), \
                myThread , SLOT(Slot_Record_Error(int, QString)));


//        connect(MYSQL_DB, SIGNAL(Singal_Data_Scale(QStringList, int, int)),
//                wData, SLOT(pubslot_display_scale(QStringList, int, int)));
//        connect(this, SIGNAL(Singal_to_SQL(QString, QStringList, int)),
//                MYSQL_DB, SLOT(Slot_Data_to_SQLDB(QString, QStringList, int)),
//                Qt::QueuedConnection);
        step_system++;
        break;
    case 3:
        ui->Print_Text->append("3-Syetem-set:");
        ui->Print_Text->append("System Initialization Test!");
        wTest = new w_Test;
        connect(wTest, SIGNAL(canSend(can_frame, int)), \
                this, SLOT(canSend(can_frame, int)));
        connect(wTest, SIGNAL(Signal_Test_to_Main(int, int)), \
                this, SLOT(Pubs_from_test(int, int)));
        connect(wTest, SIGNAL(Sigtest_Usart_Send(char *)), \
                this, SLOT(Pubs_Usart_Send(char *)));

        connect(wTest, SIGNAL(Sigtest_Usart_Send_DeChang(QString)), \
               this, SLOT(Pubs_Usart_Send_DeChang(QString)));
        connect(wTest, SIGNAL(Sigtest_Usart_Send_WEILING(QString)), \
               this, SLOT(Pubs_Usart_Send_WEILING(QString)));
        connect(this, SIGNAL(Sigmain_data_to_test(QStringList)), \
                wTest, SLOT(join_updatedata(QStringList)));
        connect(wTest , SIGNAL(Singal_Record_Error(int, QString)), \
                myThread , SLOT(Slot_Record_Error(int, QString)));

        step_system++;
        break;
    case 4:
        ui->Print_Text->append("4-Syetem-set:");
        ui->Print_Text->append("System Initialization Test!");
        wHelp = new w_Help;
        connect(wHelp, SIGNAL(sendData(int)), \
                this, SLOT(Pubs_ChangeWindow(int)));
        step_system++;
        break;
    case 5:
        ui->Print_Text->append("5-Syetem-set:");
        ui->Print_Text->append("System Initialization Test!");
        step_system++;
        break;
    case 6:
        ui->Print_Text->append("6-Syetem-set:");
        ui->Print_Text->append("System Initialization Test!");
        ui->Print_Text->append("w_Conf Sql Connecting");
        wConf = new w_Conf;
        connect(wConf, SIGNAL(sendAppMap(QVariantMap)), \
                wData, SLOT(recvSqlDat(QVariantMap)));
        connect(this, SIGNAL(Sigmain_save_DayRecoord(QString, QString)), \
                wConf, SLOT(Slot_Save_DayRecoord(QString, QString)));
        connect(wDebug, SIGNAL(Singal_Save_Debug(QString, QString)), \
                wConf, SLOT(Slot_Save_Debug(QString, QString)));
        connect(wTest, SIGNAL(Sigtest_Save_Data(QStringList, QString, int)), \
                wConf, SLOT(Slot_test_to_conf(QStringList, QString, int)));
        connect(wConf, SIGNAL(Singal_Conf_to_Main(QStringList, QString, int, int)), \
                this, SLOT(Pubs_from_conf(QStringList, QString, int, int)));
        connect(wConf, SIGNAL(canSend(can_frame, int)), \
                this, SLOT(canSend(can_frame, int)));
        connect(this, SIGNAL(Sigmain_can_to_conf(can_frame, QStringList, int)), \
                wConf, SLOT(SlOT_can_to_conf(can_frame, QStringList, int)));

        wConf->Pub_main_to_conf(QStringList(""), QString(""), 1, 5);
        step_system++;
        ui->Print_Text->append("w_Conf Sql Connect Success");
        break;
    case 7:
        ui->Print_Text->append("7-Syetem-set:");
        ui->Print_Text->append("System Initialization Test!");
        wColr = new w_Colr;
        connect(wColr, SIGNAL(Signal_color_to_Main(QString, int, int)), \
                this, SLOT(Pubs_from_color(QString, int, int)));
        step_system++;
        break;
    case 8:
        ui->Print_Text->append("8-Syetem-set:");
        ui->Print_Text->append("System Initialization Test!");
        step_system++;
        break;
    case 9:
    {
        ui->Print_Text->append("9-Syetem-set:");
        ui->Print_Text->append("System Initialization Complete!");

        step_system++;
        Pri_Synchron_Syst_Data();
        Pri_Synchron_PassWord_Data();
        Pri_TcpInit();
        Pri_availableDisk();
        Clock_show();

        wpic = new pic;
        PIC_Connect = true;
        connect(this, SIGNAL(Signal_main_to_pic(QStringList, int, int)), \
                wpic, SLOT(Pubs_from_main(QStringList, int, int)));
        connect(wTest, SIGNAL(Signal_test_to_pic(QStringList, int, int)), \
                wpic, SLOT(Pubs_from_main(QStringList, int, int)));
        connect(this, SIGNAL(Signal_main_to_Switchover(int, int32_t, int)), \
                wpic, SLOT(Pubs_from_Switchover(int, int32_t, int)));
        connect(wTest, SIGNAL(Signal_test_to_Switchover(int, int32_t, int)), \
                wpic, SLOT(Pubs_from_Switchover(int, int32_t, int)));

        connect(wpic, SIGNAL(canSend(can_frame, int)), \
                this, SLOT(canSend(can_frame, int)));
        connect(wpic, SIGNAL(Signal_pic_to_Test(QString, int, int)), \
                wTest, SLOT(Pubs_from_pic(QString, int, int)));
        connect(wpic, SIGNAL(Signal_pic_to_Main(QString, int, int)), \
                this, SLOT(Pubs_from_pic(QString, int, int)));
        Signal_main_to_pic(QStringList(""), Ini_IO_Model, 119); // 控制气缸
        Signal_main_to_pic(QStringList(""), Ini_Vacuum_Model, 0);
        Signal_main_to_pic(QStringList(""), Ini_NG_Reset, 121);

        QTimer *Time_Cheak_Ready = new QTimer(this);
        connect(Time_Cheak_Ready, SIGNAL(timeout()), \
                this, SLOT(Pubs_Cheak_Ready()));
        Time_Cheak_Ready->setSingleShot(TRUE);
        Time_Cheak_Ready->start(50);
        break;
    }
    default:
        wTest->Pub_Main_to_test(QStringList(""), QString(""), can_bug_time, 1);
        while (can.canRecv()) { // -Can接收数据
            Pri_can_data_analytical();
        }
        break;
    }
    if (Shake_hand_Success) {
        Shake_hand_runcount++;
        if (Shake_hand_runcount <= 60) { // 计时3s
            return;
        } else {
            //
        }
        Shake_hand_runcount = 0;
        WriteMessage(6000, CMD_Put_Reply, QString(tr("Reply")).toUtf8()); // 进行心跳响应
    } else {
        //
    }
}

void w_Main::Clock_show() {
    int i;
    i = 0;
    i = DS1302SingleRead(0);
    if ((i & 0x80) != 0) {
        ui->label_clock->hide();
    } else {
        ui->label_clock->show();
    }

    QProcess *cmd = new QProcess;
    QString strArg = "ifconfig";
    cmd->start(strArg);
    cmd->waitForReadyRead();
    cmd->waitForFinished();
    QString retStr = cmd->readAll();
    if (retStr.indexOf("ra0") != -1) {
        qDebug() << "ra0 show";
        ui->label_no_connect->show();
    } else {
        qDebug() << "ra0 hide";
        ui->label_no_connect->hide();
    }

    retStr.clear();
}

void w_Main::PLC_test_to_Switchover(int Factory, int32_t value, int chose) {
    if (Ini_IO_Model != Factory) {
        qDebug() << "return---> Switchover_Factory != Factory";
        return;
    } else {
        Signal_main_to_Switchover(Factory, value, chose);
    }
}

void w_Main::Dechang_Join_Test(int value) {
    if (DeChang_Enable) {
        //
    } else {
        return;
    }
    // 进入德昌处理发送信息
    switch (value) {
    case 1:
        Pubs_Usart_Send_DeChang(QString("70  3 ")); // 联机查询
        usleep(2000); usleep(2000); usleep(2000);
        Pubs_Usart_Send_DeChang(QString("70  2 ")); // 待机状态
        break;
    default:
        //
        break;
    }
}

void w_Main::DeChang_Function_Model_Switch(int value) {
    QStringList Test_Item;
    Test_Item.clear();
    Pubs_Usart_Send_DeChang(QString("70  1 ")); // 进入忙状态
    Pubs_ChangeWindow(8); // 进入配置界面
    switch (value) {
    case 1: // 设置为综合测试
        Test_Item.append("3");
        Test_Item.append("4");
        break;
    case 2: // 设置为绝缘测试
        Test_Item.append("3");
        break;
    case 3: // 设置为耐压测试
        Test_Item.append("4");
        break;
    default:
        //
        break;
    }
    wConf->Pub_main_to_conf(Test_Item, QString(""), 1, 22);
    Pubs_Usart_Send_DeChang(QString("70  2 ")); // 进入待机状态
}

void w_Main::DeChang_Function_Model_Set(int value, QString string_q) {
    QString msg;
    QStringList Test_Data;
    QStringList Test_Item;
    Test_Item.clear();
    Test_Item.append("3");
    Test_Item.append("4");
    Pubs_Usart_Send_DeChang(QString("70  1 ")); // 进入忙状态
    switch (value) {
    case 1: // 1#需要调用的型号名称，最多 23 个字符
        msg = string_q.mid(7, string_q.length() - 12);
        if ((wTest->Back_Test_Status() != Test_Station_Free) || \
                (Main_ActiveFile == QString(msg))) {
            //
        } else {
            Pubs_ChangeWindow(8);     // 进入配置界面
            if (wConf->currentFile.contains(QString(msg))) {
                wConf->Pub_main_to_conf(QStringList(""), QString(msg), 1, 18); // 修改型号
                wConf->Pub_main_to_conf(QStringList(""), QString(""), 1, 7);
            } else {
                wConf->Pub_main_to_conf(QStringList(""), QString(""), 1, 7);
            }
        }
        break;
    case 2: // 2#A#B#C#D#E#F#G#H#I#J#  有->修改 沒有->新建型號
        msg = string_q.mid(7, string_q.length() - 13);
        Test_Data = msg.split("#");
        if ((wTest->Back_Test_Status() != Test_Station_Free) || \
                (Main_ActiveFile == QString(msg))) {
            //
        } else {
            Pubs_ChangeWindow(8);     // 进入配置界面
            if (wConf->currentFile.contains(Test_Data.at(1))) {
                wConf->Pub_main_to_conf(QStringList(""), QString(msg), 1, 18); // 修改型号
                wConf->Pub_main_to_conf(Test_Item, QString(""), 0, 22);
                wConf->Pub_main_to_conf(Test_Data, QString(""), 1, 23); // IR
                wConf->Pub_main_to_conf(Test_Data, QString(""), 2, 23); // ACW
                wConf->Pub_main_to_conf(QStringList(""), QString(""), 1, 7);
            } else { // 新建型號
                wConf->Pub_main_to_conf(QStringList(""), Test_Data.at(1), 1, 10);
                wConf->Pub_main_to_conf(Test_Item, QString(""), 0, 22);
                wConf->Pub_main_to_conf(Test_Data, QString(""), 1, 23); // IR
                wConf->Pub_main_to_conf(Test_Data, QString(""), 2, 23); // ACW
                wConf->Pub_main_to_conf(QStringList(""), QString(""), 1, 7);
            }
        }
        break;
    default:
        //
        break;
    }
    Pubs_Usart_Send_DeChang(QString("70  2 ")); // 进入待机状态
}

void w_Main::DeChang_Function_Data_Get(int value) {
//    int i;
//    QString Test_Data;
    switch (value) {
    case 2: // 将返回当前所有测试数据
        //
        break;
    case 6: // 将返回当前绝缘测试数据
        //
        break;
    case 7: // 将返回当前耐压测试数据
        wTest->Back_ACW_Result = true;
        break;
    default:
        //
        break;
    }
}

void w_Main::DeChang_Function_Key(int value) {
    switch (value) {
    case 1: // 切换状态为自动测试
        //
        break;
    case 2: // 切换状态为标准测试
        //
        break;
    case 3: // 切换状态为调试测试
        //
        break;
    case 5: // 执行测试设定按钮
        //
        break;
    case 6: // 锁定屏幕按钮
        //
        break;
    case 7: // 执行 CLEAR 按钮，清除数据
        wTest->Pub_Main_to_test(QStringList(""), "0", 1, 12);
        Beep_PWM_Stop();
        isTesting = false; //
        break;
    default:
        //
        break;
    }
}

void w_Main::DeChang_Data(QString data) {
    QString Get_crc;
    uint16_t crc;
    bool crc_result;
    crc_result = false;
    QString Funtion_ASCII;
    int Back_Error_Funtion_ASCII;
    Get_crc = data.mid(data.length()-5, 4);

    crc = crc16_modbus(data.mid(1, data.length()-5).toLatin1().data(),
                 data.length() - 6);
    if (Get_crc == (QString("%1").arg(crc, 4, 16, QLatin1Char('0'))).toUpper()) {
        crc_result = true;
    } else {
        crc_result = false;
    }

    if (crc_result) { // 校验正确
        if (DeChang_Commontion == 1) { // 交互式 先返回命令
            myCom_DeChang->WritePort(data.toLatin1().data(),
                                     QString(data).length());
        } else {
            //
        }
        Funtion_ASCII = data.mid(1, 2); // 解析功能码
        if (Funtion_ASCII == tr("65")) { // 模式切换
            DeChang_Function_Model_Switch(data.mid(5, 1).toInt());
        } else if (Funtion_ASCII == tr("66")) { // 型号调用
            DeChang_Function_Model_Set(data.mid(5, 1).toInt(), data);
        } else if (Funtion_ASCII == tr("67")) { // 数据读取
            DeChang_Function_Data_Get(data.mid(5, 1).toInt());
        } else if (Funtion_ASCII == tr("71")) { // 面板按钮
            DeChang_Function_Key(data.mid(5, 1).toInt());
        } else {
            qDebug() << "w_Main::DeChang_Data() Error Funtion_ASCII" << Funtion_ASCII;
        }
        wTest->Pub_Main_to_test(QStringList(""), QString(""), 123, 123); // 显示图标
    } else { // 校验错误 功能码加上 128 返回数据
        qDebug() << "w_Main::DeChang_Data() False";
        Funtion_ASCII = data.mid(1, 2); // 解析功能码
        Back_Error_Funtion_ASCII = Funtion_ASCII.toInt() + 128;
        Funtion_ASCII = (QString("%1").arg(Back_Error_Funtion_ASCII, \
                                           2, 10, QLatin1Char('0'))).toUpper();
        Funtion_ASCII = Funtion_ASCII + data.mid(4, data.length() - 9); // 3-4
        Pubs_Usart_Send_DeChang(Funtion_ASCII); // 返回
    }
}

void  w_Main::readMyCom_Dechang(QString String) {
    qDebug() << String;
    if (String.contains("$")) {
        DeChang_Receive = true;
        DeChang__Qstring.clear();
        DeChang__Qstring += String;
    } else if (String.contains("*")) {
        DeChang__Qstring += String;
        DeChang_Data(DeChang__Qstring); // 数据处理函数
        DeChang__Qstring.clear();
    } else {
        DeChang__Qstring += String;
    }
}

void  w_Main::readMyCom(QString String) {
    QString USART;
    if (String.contains("\n")) {
        key_data += String;
        USART = key_data;
        key_data.clear();
    } else {
        key_data += String;
    }

    USART = QString(USART).mid(1, USART.length()-3); //  接收的字符串

    if (USART == "1") {
        if (window_current == wTest_Surface) {
//          frame.can_id  = 0x2D;  frame.can_dlc = 0x04;
//          frame.data[0] = 0xf1;
//          frame.data[1] = 0x00;
//          frame.data[2] = 0x00;
//          frame.data[3] = 0x00;
//          canSend(frame, 88);
            wTest->Pub_Main_to_test(QStringList(""), "0", 1, 12);
            Beep_PWM_Stop();
            isTesting = false;
        } else if (window_current == wConf_Surface) {
            Button_Main_Group_Judge(Qt::Key_D);
        } else {
            //
        }
    } else if ((USART == "2")&&(window_current == wTest_Surface)) { // 启动信号
        out_station = 0x13;
        wTest->Pub_Main_to_test(QStringList(""), "0", 0x13, 11);
    } else if ((USART == "18") && (wTest->Back_Test_Status() == Test_Station_Free)) { // 空闲状态
        if (window_old != wPassWord_Surface) { // 密码禁止进入帮助
            Pubs_ChangeWindow(5);
        } else {
            //
        }
    } else if (USART == "17") {
        calibration_count++;
        if (calibration_count%10 == 0) {
            system("./ts_calibrate -qws&");
        } else {
            //
        }
    } else if (window_current == wConf_Surface) { //  配置界面
        Pri_KEY_ConfSurface(USART);
    } else if (window_current == wTest_Surface) {  //  测试界面
        wTest->Pub_Main_to_test(QStringList(""), USART, 1, 2);
    } else if (window_current == wMain_Surface) {  //  测试界面
        Pri_KEY_MainSurface(USART);
    } else {
        qDebug() << "w_Main::readMyCom Error";
    }
}

void w_Main::Pubs_from_pic(QString string_q, int value, int flag) {
    switch (flag) {
    case 1:
        if (window_current == wTest_Surface) {
            qDebug() << "w_Main::Pubs_from_pic()";
            out_station = value;
            wTest->Pub_Main_to_test(QStringList(""), "0", value, 11);
        } else {
            //
        }
        break;
    case 2:
        if (window_current == wTest_Surface) {
            wTest->Pub_Main_to_test(QStringList(""), "0", 1, 12);
            Beep_PWM_Stop();
        } else {
            //
        }
        break;
    case 3:
        if (window_current == wConf_Surface) {
            if (IMP_Sample_Dou) {
                wConf->Pub_main_to_conf(QStringList(""), QString(""), 19, 19);
                wConf->Pub_main_to_conf(QStringList(""), QString(""), 24, 21);
            } else {
                wConf->Pub_main_to_conf(QStringList(""), QString(""), 19, 19);
                wConf->Pub_main_to_conf(QStringList(""), QString(""), 24, 2);
            }
        } else {
            //
        }
        break;
    case 5:
        if (window_current == wConf_Surface) {
            if (IMP_Sample_Dou) {
                wConf->Pub_main_to_conf(QStringList(""), QString(""), 20, 19);
                wConf->Pub_main_to_conf(QStringList(""), QString(""), 24, 21);
            } else {
                wConf->Pub_main_to_conf(QStringList(""), QString(""), 20, 19);
                wConf->Pub_main_to_conf(QStringList(""), QString(""), 24, 2);
            }
        } else {
            //
        }
        break;
    case 6:
        WriteMessage(6000, CMD_Put_96, QString::number(value).toUtf8());
        break;
    case 7:
        Pri_Main_WMessage(value, QString(tr("")));
        break;
    case 8:
        Out_Board_Stop();
        usleep(500);
        frame.can_id = 0x22;  frame.can_dlc = 0x02; //-发送给电阻板
        frame.data[0] = 0x09;
        frame.data[1] = 0x00;
        canSend(frame, 88);
        usleep(500);
        dcr_board->stop();
        break;
    case 9:
        Out_Board_Stop();
        break;
    case 10:
        WriteMessage((6000), CMD_Put_Message, QString::number(value).toUtf8());
        break;
    case 11:
        WriteMessage((6000), CMD_Put_NoStart, QString::number(value).toUtf8());
        break;
    case 12:
    //    WriteMessage((6000), CMD_Test_Message, string_q.toUtf8());
        break;
    default:
        //
        break;
    }
    string_q.clear();
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2017.7.20
      * brief:      系统接收的can信息进行解析
******************************************************************************/
void w_Main::Pri_can_data_analytical()
{
//    qDebug() << "Pri_can_data_analytical()--- Join";
    int i = 0, Id = 0;
    int j = 0;
    can_bug_time = 0;
    Id = can.frame.can_id & 0xffff; can.frame.can_id = 0; // -ID
    //  Pri_Can_Receive(Id);
    switch (Id) {
    case CAN_DLR:       // -电阻板测试系统
        Pri_Board_DLR();
        break;
    case CAN_DLR_SHAPE: // -反嵌波形
        mag_waveform_error = true;           // -初始设置为错误，在出现错误时显示一条横线；
        for (i = 0; i < can.frame.can_dlc; i++) { // -反嵌測試項目
            waveform_point[waveform_count] = can.frame.data[i];
            waveform_count++;
            if (waveform_count == 400) {
                mag_waveform_error = false;
                waveform_count = 399;
            } else {
                //
            }
        }
        break;
    case CAN_IR:       // -绝缘交耐板测试系统
        Pri_Board_IR_ACW();
        break;
    case CAN_ANP:      // -功放板测试系统
        Pri_Board_AMP();
        break;
    case CAN_IW:       // -匝间板测试系统
        Pri_Board_IMP();
        break;
    case CAN_IW_SHAPE: // -匝间板波形
        if (window_current == wDebug_Surface) {
            return;
        } else {
            //
        }
        imp_waveform_error = true;               // -初始设置为错误，在出现错误时显示一条横线；
        for (i = 0; i < (can.frame.can_dlc/2); i++) { // -匝间測試項目
            waveform_point[waveform_count] = can.frame.data[i*2]*256 + can.frame.data[i*2 + 1];
            waveform_count++;
            if (waveform_count == 400) {
                imp_waveform_error = false;
                waveform_count = 399;
            } else {
                //
            }
        }
        break;
    case CAN_PWR1:      // -电参测试系统
        Pri_Board_PWR(Id);
        break;
    case CAN_PWR2:      // -电参测试系统
        Pri_Board_PWR(Id);
        break;
    case CAN_PWR_SHAPE: // -PG波形的接收
        pg_waveform_error = true;
        for (i = 0; i < can.frame.can_dlc; i++) { // -PG波形进行接收
            waveform_point[waveform_count] = can.frame.data[i] + 3;
            waveform_count++;
            if (waveform_count == 400) {
                Start_get_pg_shape = true;
                pg_waveform_error = false;
                waveform_count = 399;
                for (j = 0; j < 400; j++) {
                    waveform_point_c[j] = waveform_point[j];
                }
            } else {
                //
            }
        }
        break;
    case CAN_INDL: //-电感测试系统
        Pri_Board_INDL();
        break;
    case CAN_ACSW: //-电源切换板
        Pri_Board_ACSW();
        break;
    case CAN_WD:
        Pri_Board_WD();
        break;
    case CAN_PG:
        Pri_Board_PG();
        break;
    case CAN_IO:
        Pri_Can_Receive(Id);
        Pri_Board_IO();
        break;
    case CAN_PG_SHAPE:
        Pri_Board_PG_Wave();
     /* fg_waveform_error = true;
        for (i = 0; i < can.frame.can_dlc; i++) { // -PG波形进行接收
            waveform_point[waveform_count] = can.frame.data[i];
            waveform_count++;
            if (waveform_count == 400) {
                fg_waveform_error = false;
                waveform_count = 399;
            } else {
                //
            }
        }*/
        break;
    case CAN_HALL:       // -电阻板测试系统
        Pri_Can_Receive(Id);
        Pri_Board_New_Hall();
        break;
    default: //-输出板或者其他
        if ((Id >= CAN_13OUT) && (Id <= CAN_17OUT)) { // -输出板（13-17）测试系统
            Pri_Can_Receive(Id);
            Pri_Board_Out(((Id-CAN_13OUT)/32), 0X13 + ((Id - CAN_13OUT)/32));
        } else {
            //
        }
        break;
    }
//    qDebug() << "Pri_can_data_analytical()--- Finsh";
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2017.7.20
      * brief:      系统接收的Usart信息进行解析
******************************************************************************/
void w_Main::Pri_usart_analytical()
{
//   qDebug() << QString(myCom->DatBuf).mid(1, myCom->m_DatLen-3);
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2017.7.20
      * brief:      主页面按键操作
******************************************************************************/
void w_Main::Pri_KEY_MainSurface(QString USART)
{
    switch (USART.toInt()) {
    case 26:  // F1
        Button_Main_Group_Judge(Qt::Key_A);
        break;
    case 27:  // F2
        Button_Main_Group_Judge(Qt::Key_B);
        break;
    case 24:  // F3
        Button_Main_Group_Judge(Qt::Key_C);
        break;
    case 25:  // F4
        Button_Main_Group_Judge(Qt::Key_D);
        break;
    default:
        break;
    }
}

void w_Main::Pri_Board_New_Hall() {
    if (can.frame.data[0] == 0) {
        if (window_current == wTest_Surface) {
            wTest->Pub_Main_to_test(QStringList(""), QString(""), can.frame.data[0] , 127);
        } else {
            board_state[230] = can.frame.data[1];
        }
    } else if (can.frame.data[0] == 2) {
        wTest->Pub_Main_to_test(QStringList(""), QString(""), can.frame.data[1] , 126);
    } else if (can.frame.data[0] == CAN_UPLOAD_Version) {
        Version.New_Rot = Pri_Board_Version();
    } else {
        //
    }
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2017.7.20
      * brief:      配置界面按键操作
******************************************************************************/
void w_Main::Pri_KEY_ConfSurface(QString USART)
{
    int  key_table[] = {10, 10, 10, 1, 2, 3, 10, 4, 5, 6, 10, 7, 8, 9, 10, 0, 10};
    //-机器界面按键的数值
    if (USART == "6") {        // 退格
        Serial_SendBackspace();
    } else if (USART == "14") {  // 确定
        Serial_SendEnter();
        Serial_SendEscape();
    } else if (USART == "16") {
        Serial_SendString(".");
    } else if (USART == "23") {
        Serial_Upspace();
    } else if (USART == "22") {
        Serial_Downspace();
    } else if (USART == "20") {
        Serial_Tabspace();
    } else if (USART == "19") {
        Serial_BackTabspace();
    } else if (USART == "21") {
        wConf->Pub_main_to_conf(QStringList(""), QString(""), 1, 1);
    } else if ((USART.toInt() >= 24) && (USART.toInt() <= 27)) {
        wConf->Pub_main_to_conf(QStringList(""), QString(""), USART.toInt(), 2);
    } else if (key_table[USART.toInt()] < 10) {
        Serial_SendString(QString::number(key_table[USART.toInt()]));
    } else {
        //
    }
}

void w_Main::Appointment_Test(int wait_count, int wait_Station) {
    if (Appointment_Test_Enable) {
        //
    } else {
        return;
    }
    Appointment_Test_Enable = false;
    qDebug() << "w_Main::Appointment_Test()";
    Signal_main_to_pic(QStringList(""), wait_Station*10+1, 11);
    out_station = wait_Station;
    // -更改顺序，在大疆无人机出现的问题-2017.5.16

    wTest->Pub_Main_to_test(QStringList(""), \
                            QString::number(wTest->START_Model), wait_Station, 11);
    WriteMessage((6000), CMD_Put_97, QString::number(out_station).toUtf8());
    if (wTest->START_Model == 2) { //-滑罩启动
        isTesting = true;
        PreCount  = wait_count;
    } else {
        //
    }
}

void w_Main::Appointment_Timer_out() {
    Appointment_Test(Appointment_Test_wait_count, Appointment_Test_Station);  // 进入预约函数
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2015.5.20
      * brief:      输出板 状态检测和启动测试和版本号
******************************************************************************/
void w_Main::Pri_Board_Out(int count, int Station)
{
    if (can.frame.data[0] == CAN_UPLOAD_STATE) {          //-上传状态
        board_state[count*2] = can.frame.data[1];
    } else if (can.frame.data[0] == CAN_UPLOAD_RESULT_ONE) { //-上传结果
        if (can.frame.data[1] == Receive_Stop) {          //-拉开滑罩-停止
            if (window_current == wTest_Surface) {        //-测试界面
                if (Ini_Appointment) {
                    if (Station == out_station) {
                        //
                    } else {
                        Appointment_Test_Enable = false;
                        return;
                    }
                } else {
                    //
                }

                Signal_main_to_pic(QStringList(""), Station*10 + 0, 11);
                qDebug() << "w_Main::Pri_Board_Out  CMD_Put_98 ";
                WriteMessage(6000, CMD_Put_98, QString::number(out_station).toUtf8());
                wTest->Pub_Main_to_test(QStringList(""), "0", 2, 12);
                PLC_test_to_Switchover(LvZhi, 0x12, 2);
                PLC_test_to_Switchover(WeiLing, out_station, 3);
                PLC_test_to_Switchover(XINQIDIAN, out_station, 18);
                PLC_test_to_Switchover(SAIPU, 0, 1);
                if ((wTest->START_Model == 2) && \
                        (((PreCount == count) || (PreCount == 0xff)))) { // -滑罩启动
                    isTesting = false;
                } else {
                    //
                }
                if (Appointment_Test_Station == Station) { // 预约工位断开
                    Appointment_Test_Enable = false;
                } else {
                    if (Ini_Appointment) {
                        Appointment_Timer->setSingleShot(TRUE);
                        Appointment_Timer->start(400); // 启动定时器
                    } else {
                        return;
                    }
                }
            } else if (window_current == wConf_Surface) {
                wConf->Pub_main_to_conf(QStringList(""), QString(""), 1, 19);
            } else {
                //
            }
        } else if (can.frame.data[1] == Receive_Start) {             // -拉上滑罩 启动
            if ((window_current == wTest_Surface) && (!isTesting)) { // -测试界面,已经拉开滑罩
                Appointment_Test_Enable = false;
                Signal_main_to_pic(QStringList(""), Station*10+1, 11);
                out_station = Station;
                // -更改顺序，在大疆无人机出现的问题-2017.5.16

                wTest->Pub_Main_to_test(QStringList(""), \
                                        QString::number(wTest->START_Model), Station, 11);

                WriteMessage((6000), CMD_Put_97, QString::number(out_station).toUtf8());
                if (wTest->START_Model == 2) { //-滑罩启动
                    isTesting = true;
                    PreCount  = count;
                } else {
                    //
                }
            } else if (window_current == wConf_Surface) {
                wConf->Pub_main_to_conf(QStringList(""), QString(""), Station, 19);
                out_station = Station;
                PLC_test_to_Switchover(LvZhi, out_station, 2);
                PLC_test_to_Switchover(BePuDa, out_station, 12);
                if (Ini_ROT) {
                    PLC_test_to_Switchover(Ciximinghua, out_station, 2); // 吸合交流接触器
                } else {
                    //
                }

                if (Control_Enable_BaoJiaLiYa) {
                    PLC_test_to_Switchover(BaoJiaLiYa, out_station, 2); // 吸合交流接触器
                } else {
                    //
                }
            } else {
                Appointment_Test_wait_count = count;
                Appointment_Test_Enable = true;
                Appointment_Test_Station = Station;
                qDebug()<< "w_Main::Pri_Board_Out  Error testing"; //
            }
        } else {
            //
        }
    } else if (can.frame.data[0] == 0x02) {
        Singal_Record_Error(1, QString::number(Station));
        WriteMessage((6000), CMD_Put_Message, QString("16").toUtf8());
        Pri_Can_Set_OUTModel(0x13, system_conf.at(4).toInt());
        Pri_Can_Set_OUTModel(0x14, system_conf.at(4).toInt());
    } else if (can.frame.data[0] == CAN_UPLOAD_Version) { // 上传版本号
        Version.OutV[count] = Pri_Board_Version();
    } else {
        //
    }
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2015.6.27
      * brief:      DLR板获取结果参数
******************************************************************************/
QStringList w_Main::Pri_Board_DLR_TestData(can_frame canframe)
{
    QStringList Back_QStringList; Back_QStringList.clear();
    if ((canframe.data[2] == 1) || (canframe.data[2] == 2)) { // -档位（1，2）-"mΩ"
        Back_QStringList.append(QString::number((canframe.data[3] * 256 + canframe.data[4]) \
                * (qPow(10, -(6-canframe.data[2]))) * 1000));  //
        Back_QStringList.append("mΩ");
    } else if ((canframe.data[2] == 3) || (canframe.data[2] == 4) || (canframe.data[2] == 5)) {
        // -档位（3，4，5）-"Ω"
        Back_QStringList.append(QString::number((canframe.data[3] * 256 + canframe.data[4]) \
                * (qPow(10, -(6-canframe.data[2])))));  //
        Back_QStringList.append("Ω");
    } else if ((canframe.data[2] == 6) || (canframe.data[2] == 7) || (canframe.data[2] == 8)) {
        // -档位（6，7，8）-"KΩ" 其中（7，8）暂时未用到
        Back_QStringList.append(QString::number((canframe.data[3] * 256 + canframe.data[4]) \
                * (qPow(10, (canframe.data[2]-6))) / 1000));  //
        Back_QStringList.append("KΩ");
    } else {
        //
    }
    Back_QStringList.append(QString::number(canframe.data[1]));
    if (canframe.data[2] < 6) {
        Back_QStringList.append(QString::number((canframe.data[3] * 256 + canframe.data[4]) \
                * (qPow(10, -(6-canframe.data[2])))));
    } else {
        Back_QStringList.append(QString::number((canframe.data[3]*256+canframe.data[4]) \
                * (qPow(10, (canframe.data[2]-6)))));
    }
    Back_QStringList.append(QString::number(canframe.data[2]));
    return Back_QStringList;
}
void  w_Main::Pri_Mag_Trend(int *waveform_point) {
    /*int i;
    QStringList data;
    data.append("0");
    for (i = 0; i < 399; i++) {
        if (waveform_point[i+1] > waveform_point[i]) {
            data.append("1");
        } else if(waveform_point[i+1] < waveform_point[i]) {
            data.append("0");
        } else {
            data.append(data.at(i));
        }
    }
    qDebug() << "data" << data.size() << data;
    for (i = 1; i < 398; i++) {
        if (data.at(i) != data.at(i + 1)) {
            data.replace(i + 1, data.at(i));
            i = i + 1;
        } else {

        }
    }*/ //測試趨勢
    int i = 0;

    int H_data = 0, L_data = 0;
    H_data = 0;
    L_data = 0;

    int zero_count = 0;
    zero_count = 0;

    QStringList zero_list;
    zero_list.clear();

    for (i = 0; i < 400; i++) {
        if ((waveform_point[i]) >= 125) {
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

    QStringList zero_list_update;
    for (i = 0; i < zero_list.size(); i++) {
        if (zero_list.at(i).toInt()%1000 <= 10) {
            //
        }
        else {
            zero_list_update.append(zero_list.at(i));
        }
    }

    if (zero_list_update.size() == 1) {
        qDebug() << "w_Main::Pri_Mag_Trend zero_count";
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
    qDebug() << "w_Main::Pri_Mag_Trend zero_count" << zero_count;
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2017.7.20
      * brief:      DLR板
******************************************************************************/
void w_Main::Pri_Board_DLR()
{
    int i = 0;
    double Temp_Get;
    int Net_Rot;
    QStringList Net_Shape_List;
    if (can.frame.data[0] == CAN_UPLOAD_STATE) {
        Temp_Get = (can.frame.data[2]*256 + can.frame.data[3]);
        Temp_Get = (Temp_Get)/10 - 50.0;

        if (Ini_Get_Temp == "External") {
            Temp_Get = Net_Get_Temp;
        } else {
            //
        }
        wTest->Pub_Main_to_test(QStringList(""), QString::number(Temp_Get), 1, 5);
        board_state[20] = can.frame.data[1];
        if (window_current == wTest_Surface) {
            wTest->Pub_Main_to_test(QStringList(""), QString(""), 1 , 19);
        } else if (window_current == wConf_Surface) {
            wConf->Board_DLR = 1;     //  可以进行测试
            if ((Ini_MAG_Device) && (can.frame.data[1] == 0)) {
                Signal_main_to_pic(QStringList(""), 0, 9);
            } else {
                //
            }
        } else {
            //
        }
    } else if (can.frame.data[0] == CAN_UPLOAD_RESULT_ONE) { //-电阻测试结果
        QStringList DLR_Can_Data;
        if (window_current == wTest_Surface) {
            if (Ini_Get_Temp == "External") {
                Sigmain_data_to_test(wConf->WDLR->DCR_Test_Result(can.frame, \
                                                                  Back_out_station, (Net_Get_Temp+50)*10));
            } else {
                Net_Get_Temp = (can.frame.data[5]*256 + can.frame.data[6]);
                if ((can.frame.data[5]*256 + can.frame.data[6])/10 == 200) {
                    if (wConf->WDLR->DLR_Temp_Flag) { // 温度补偿
                        DLR_Can_Data.clear();
                        DLR_Can_Data.append("Error");
                        Sigmain_data_to_test(DLR_Can_Data);
                    } else {
                        Sigmain_data_to_test(wConf->WDLR->DCR_Test_Result(can.frame, \
                                                                          Back_out_station, Net_Get_Temp));
                    }
                } else {
                    Sigmain_data_to_test(wConf->WDLR->DCR_Test_Result(can.frame, \
                                                                      Back_out_station, Net_Get_Temp));
                }
            }
        } else if (window_current == wConf_Surface) {
            Sigmain_can_to_conf(can.frame, QStringList(""), 6);
        } else if (window_current == wDebug_Surface) {
            DLR_Can_Data = Pri_Board_DLR_TestData(can.frame);
            Sigmain_data_to_debug(QStringList(""), \
                                  QString::number(can.frame.data[3]*256+can.frame.data[4]), 2);
        } else {
            //
        }
    } else if (can.frame.data[0] == CAN_UPLOAD_RESULT_TWO) {
        mag_back_number = can.frame.data[1];
        if (window_current == wTest_Surface) { // 显示在ABC显示区
            mag_str = QString::number(wConf->WMAG->Test_MagData(2, Back_out_station, can.frame));
        } else if (window_current == wConf_Surface) { // 显示在显示区
            wConf->WMAG->Test_MagData(1, 1, can.frame);
            Net_Shape_List.clear();
            Net_Shape_List.append(QString::number(mag_back_number));
            for (i = 0; i < 5; i++) {
                Net_Shape_List.append(QString::number(can.frame.data[i]));
            }
            emit WriteMessage(6000, CMD_Put_87, QString(Net_Shape_List.join(" ")).toUtf8());
        } else {
            //
        }
        waveform_count = 0;
    } else if (can.frame.data[0] == CAN_UPLOAD_SHAPE) {
        if (can.frame.data[1] != 255) {
            return;
        } else {
            //
        }
        if (window_current == wConf_Surface) {
            Net_Rot = wConf->WMAG->MagDir_Conf(mag_back_number, mag_set_rotation, waveform_point);
            emit WriteMessage(6000, CMD_Put_ROT, QString::number(Net_Rot).toUtf8());
            waveform_count = 0;
            Net_Shape_List.clear();
            Net_Shape_List.append(QString::number(mag_back_number));
            for (i = 0; i < 400; i++) {
                Net_Shape_List.append(QString::number(waveform_point[i]));
            }

            emit WriteMessage(6000, CMD_Put_81, QString(Net_Shape_List.join(" ")).toUtf8());
        } else {
            //
        }
        if (window_current == wTest_Surface) {
            QStringList mag_data; mag_data.clear();
            mag_data.append(QString::number(mag_waveform_error));
            mag_data.append(QString::number(mag_back_number));
            mag_data.append(QString::number(mag_set_rotation));
            Net_Shape_List.clear();
            Net_Shape_List.append(QString::number(mag_back_number));
            for (i = 0; i < 400; i++) {
                Net_Shape_List.append(QString::number(waveform_point[i]));
            }
            Pri_Mag_Trend(waveform_point); // 判斷趨勢
            if (Ini_Mag_Hide == 0) {
                emit WriteMessage(6000, CMD_Put_82, QString(Net_Shape_List.join(" ")).toUtf8());
            } else {
                //
            }
            wTest->Pub_MAG_Param(mag_data, waveform_point);
            QStringList mag_result;
            mag_result.clear();
            mag_result.append(mag_str);
            Sigmain_data_to_test(mag_result);
        } else {
            //
        }
    } else if (can.frame.data[0] == CAN_UPLOAD_Version) {
        Version.DLRV = Pri_Board_Version();
    } else if (can.frame.data[0] == CAN_UPLOAD_Debug) {
        if (window_current != wDebug_Surface) {
            return;
        } else {
            //
        }
        QStringList list;
        list.append(QString::number(can.frame.data[1]));
        list.append(QString::number(can.frame.data[2]));
        list.append(QString::number(can.frame.data[3]));
        Sigmain_data_to_debug(list, QString(""), 7);
    } else if ((can.frame.data[0] == CAN_UPLOAD_In) && ((window_current == wTest_Surface))) {
        if (signal_model == 1) { //-重测和继续
            if (can.frame.data[1] == 1) { //-重测
                WriteMessage(6000, CMD_Reset_Again, QString("1").toUtf8());
                wTest->Pub_Main_to_test(QStringList(""), "0", 1, 6);
            } else if (can.frame.data[2] == 1) { //-继续
                WriteMessage(6000, CMD_Reset_Again, QString("0").toUtf8());
                wTest->Pub_Main_to_test(QStringList(""), "0", 1, 15);
            } else {
                //
            }
        } else if (signal_model == 2) {
            if (can.frame.data[2] == 1) { //-继续
                wTest->Pub_Main_to_test(QStringList(""), "0", 1 , 15);
            }
        } else {
            //
        }
    } else if (can.frame.data[0] == 0X0b) {
       if (signal_model == 12) {
            wTest->Pub_Main_to_test(QStringList(""), "0", can.frame.data[1] , 31);
       }
    } else {
        //
    }
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2015.6.27
      * brief:      IR板
-******************************************************************************/
void w_Main::Pri_Board_IR_ACW()
{
    if (can.frame.data[0] == CAN_UPLOAD_RESULT_ONE) {
        IRACW.time++;
        IRACW.volt += can.frame.data[1]*256+can.frame.data[2];
        IRACW.result += can.frame.data[3]*256+can.frame.data[4];
        IRACW.judge = can.frame.data[6]; //-判定是否合格

        IRACW.show_resultc = (can.frame.data[3]*256 + can.frame.data[4]) \
                * (qPow(10, -can.frame.data[5])); //-不合格数据
//        if (IRACW.judge == 1) { // -NG-数据
//            IRACW.show_resultc = (can.frame.data[3]*256 + can.frame.data[4]) \
//                    * (qPow(10, -can.frame.data[5])); //-不合格数据
//        } else {
//            //
//        }
        if (IRACW.time != IRACW_Time) { //-计时两次
            return;
        } else {
            //
        }

        IRACW.time = 0;
        IRACW.volt = IRACW.volt/IRACW_Time;
        if (((IRACW.volt + 3) <= (IRACW.voltc)) || (((IRACW.volt - 3) >= (IRACW.voltc)))) {
            IRACW.voltc = IRACW.volt;
            IRACW.updata = 1;
        } else {
            //
        }

        IRACW.result = IRACW.result/IRACW_Time; //-平均测试结果 绝缘电阻和耐压电流
        if (((IRACW.result + 2) <= (IRACW.resultc)) || (((IRACW.result - 2) >= (IRACW.resultc)))) {
            IRACW.resultc = IRACW.result;
            IRACW.updata = 1;
            IRACW.resultc_dou = IRACW.resultc*(qPow(10, -can.frame.data[5]));
            if (IRACW.judge == 0) { //- 判定合格将数据 到 显示的最终数据
                IRACW.show_resultc = IRACW.resultc_dou;
            } else {
                //
            }
        }

        if (window_current == wTest_Surface) {
            if (IRACW.updata != 1) { //-需要更新数据
                IRACW.volt = 0;
                IRACW.result = 0;
                return;
            } else {
                //
            }
            IRACW.updata = 0;
            if (wTest->TestIRACW == TestIW_ACW) {
                QStringList ACW_Data; ACW_Data.clear();
                ACW_Data.append(QString::number(Ini_IRACW_True));
                ACW_Data.append(QString::number(IRACW.voltc));
                ACW_Data.append(QString::number(wTest->ACW_Test_Count));
                ACW_Data.append(QString::number(IRACW.show_resultc));
                ACW_Data.append(QString::number(IRACW.judge));
                ACW_Data.append(QString::number(wTest->ACW_First_Test_Enabled));
                ACW_IR_Test_Data = wConf->WACW->ACW_Test_Result(ACW_Data);
                qDebug() << "w_Main::Pri_Board_IR_ACW() ACW---" << ACW_IR_Test_Data;
            } else if (wTest->TestIRACW == TestIW_IR) {
                QStringList IR_Data; IR_Data.clear();
                IR_Data.append(QString::number(Ini_IRACW_True));
                IR_Data.append(QString::number(IRACW.voltc));
                IR_Data.append(QString::number(wTest->IR_Test_Count));
                IR_Data.append(QString::number(IRACW.resultc_dou));
                IR_Data.append(QString::number(IRACW.judge));
                IR_Data.append(QString::number(wTest->IR_First_Test_Enabled));
                ACW_IR_Test_Data = wConf->WIR->IR_Test_Result(IR_Data);
                qDebug() << "w_Main::Pri_Board_IR_ACW() IR---" << ACW_IR_Test_Data;
            }  else if (wTest->TestIRACW == TestIW_DCW) {
                QStringList DCW_Data; DCW_Data.clear();
                DCW_Data.append(QString::number(Ini_IRACW_True));
                DCW_Data.append(QString::number(IRACW.voltc));
                DCW_Data.append(QString::number(wTest->DCW_Test_Count));
                DCW_Data.append(QString::number(IRACW.resultc_dou));
                DCW_Data.append(QString::number(IRACW.judge));
                ACW_IR_Test_Data = wConf->WDCW->DCW_Test_Result(DCW_Data);
                qDebug() << "w_Main::Pri_Board_IR_ACW() DCW---" << ACW_IR_Test_Data;
            }  else if (wTest->TestIRACW == TestIW_HV) {
                QStringList HV_Data; HV_Data.clear();
                HV_Data.append(QString::number(Ini_IRACW_True));
                HV_Data.append(QString::number(IRACW.voltc));
                HV_Data.append(QString::number(wTest->ACW_Test_Count));
                HV_Data.append(QString::number(IRACW.show_resultc));
                HV_Data.append(QString::number(IRACW.judge));
                HV_Data.append(QString::number(wTest->ACW_First_Test_Enabled));
                ACW_IR_Test_Data = wConf->WHV->HV_Test_Result(HV_Data);
                qDebug() << "w_Main::Pri_Board_IR_ACW() HV---" << ACW_IR_Test_Data;
            }  else {
                //
            }
            Sigmain_data_to_test(ACW_IR_Test_Data);
        } else if (window_current == wConf_Surface) {
            if (IRACW.updata == 1) {
                IRACW.updata = 0;
                wConf->Pub_main_to_conf(QStringList(""), QString::number(IRACW.resultc_dou), 0, 20);
            } else {
                //
            }
        } else if (window_current == wDebug_Surface) {
            Sigmain_data_to_debug(QStringList(""), QString::number(IRACW.resultc), 3);
        } else {
            //
        }
        IRACW.volt = 0;
        IRACW.result = 0;
    } else if (can.frame.data[0] == CAN_UPLOAD_STATE) {
        if (window_current == wTest_Surface) { //-绝缘数据解析
            wTest->IRFinsh = true;
            if (wTest->TestIRACW == TestIW_ACW) {
                QStringList ACW_Data; ACW_Data.clear();
                ACW_Data.append(QString::number(Ini_IRACW_True));
                ACW_Data.append(QString::number(IRACW.voltc));
                ACW_Data.append(QString::number(wTest->ACW_Test_Count));
                ACW_Data.append(QString::number(IRACW.show_resultc));
                ACW_Data.append(QString::number(IRACW.judge));
                ACW_Data.append(QString::number(wTest->ACW_First_Test_Enabled));
                ACW_IR_Test_Data = wConf->WACW->ACW_Test_Result(ACW_Data);
                qDebug() << "w_Main::Pri_Board_IR_ACW() ACW Finsh---" << ACW_IR_Test_Data;
            } else if (wTest->TestIRACW == TestIW_IR) {
                QStringList IR_Data; IR_Data.clear();
                IR_Data.append(QString::number(Ini_IRACW_True));
                IR_Data.append(QString::number(IRACW.voltc));
                IR_Data.append(QString::number(wTest->IR_Test_Count));
                IR_Data.append(QString::number(IRACW.show_resultc));
                IR_Data.append(QString::number(IRACW.judge));
                IR_Data.append(QString::number(wTest->IR_First_Test_Enabled));
                ACW_IR_Test_Data = wConf->WIR->IR_Test_Result(IR_Data);
                qDebug() << "w_Main::Pri_Board_IR_ACW() IR Finsh---" << ACW_IR_Test_Data;
            }  else if (wTest->TestIRACW == TestIW_DCW) {
                QStringList DCW_Data; DCW_Data.clear();
                DCW_Data.append(QString::number(Ini_IRACW_True));
                DCW_Data.append(QString::number(IRACW.voltc));
                DCW_Data.append(QString::number(wTest->DCW_Test_Count));
                DCW_Data.append(QString::number(IRACW.show_resultc));
                DCW_Data.append(QString::number(IRACW.judge));
                ACW_IR_Test_Data = wConf->WDCW->DCW_Test_Result(DCW_Data);
                qDebug() << "w_Main::Pri_Board_IR_ACW() DCW---" << ACW_IR_Test_Data;
            }  else if (wTest->TestIRACW == TestIW_HV) {
                QStringList HV_Data; HV_Data.clear();
                HV_Data.append(QString::number(Ini_IRACW_True));
                HV_Data.append(QString::number(IRACW.voltc));
                HV_Data.append(QString::number(wTest->ACW_Test_Count));
                HV_Data.append(QString::number(IRACW.show_resultc));
                HV_Data.append(QString::number(IRACW.judge));
                HV_Data.append(QString::number(wTest->ACW_First_Test_Enabled));
                ACW_IR_Test_Data = wConf->WHV->HV_Test_Result(HV_Data);
                qDebug() << "w_Main::Pri_Board_IR_ACW() HV---" << ACW_IR_Test_Data;
            }  else {
                //
            }
            IRACW.time = 0;
            IRACW.volt = 0;  IRACW.voltc = 0;  IRACW.result = 0;  IRACW.resultc = 0;
            IRACW.resultc_dou = 0;
            IRACW.show_resultc = 0;
            Sigmain_data_to_test(ACW_IR_Test_Data); //-更新数据
        } else if (window_current == wConf_Surface) {
            wConf->Pub_main_to_conf(QStringList(""), QString::number(IRACW.resultc_dou), 1, 20);
        } else {
            board_state[40] = can.frame.data[1];
            board_state[50] = can.frame.data[2]*256 + can.frame.data[3];
        }
    } else if (can.frame.data[0] == CAN_UPLOAD_Debug) {
        QStringList list;
        list.append(QString::number(can.frame.data[1]));
        list.append(QString::number(can.frame.data[2]));
        list.append(QString::number(can.frame.data[3]));
        list.append(QString::number(can.frame.data[4]));
        list.append(QString::number(can.frame.data[5]));
        Sigmain_data_to_debug(list, QString(""), 6);
    } else if (can.frame.data[0] == CAN_UPLOAD_Version)  {
        Version.IWV = Pri_Board_Version();
    } else if (can.frame.data[0] == 0x02)  {
        wTest->Pub_Main_to_test(QStringList(""), QString(""), can.frame.data[1], 32);
    } else if (can.frame.data[0] == 0x03)  {
        qDebug() << "w_Main::Pri_Board_IR_ACW() DC ok";
    } else if (can.frame.data[0] == 0x0f)  {
        Singal_Record_Error(2, QString::number(10));
    } else {
        //
    }
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2017.7.20
      * brief:      功放板
******************************************************************************/
void w_Main::Pri_Board_AMP()
{
    int min_Volt = 0;
    if (can.frame.data[0] == CAN_UPLOAD_Version) {
        Version.AMP = Pri_Board_Version();
    }

    if ((can.frame.data[0] == 0x03)) {
        if (can.frame.data[1] == 0) { // 连接
            wTest->AMP_Conneted = true;

            if (window_current == wMain_Surface) {
                AMP_lable[1]->setText(tr("Inter Lock 状态:连接"));
                Reset_IR_ACW->setEnabled(true);
            } else {
                //
            }
        } else if (can.frame.data[1] == 1) { // 断开
            wTest->AMP_Conneted = false; //
            if (window_current == wTest_Surface) {
                wTest->Pub_Main_to_test(QStringList(""), "0", 1, 12);
                Beep_PWM_Stop();
            } else if (window_current == wMain_Surface) {
                 AMP_lable[1]->setText(tr("Inter Lock 状态:断开"));
                 Reset_IR_ACW->setDisabled(true);
            } else {
                //
            }
        } else {
            //
        }
    } else {
        //
    }

    if (can.frame.data[0] != CAN_UPLOAD_STATE) {
        return;
    } else {
        //
    }
    if ((window_current == wMain_Surface) || (window_current == wSyst_Surface)) {
        board_state[120] = can.frame.data[1];
    } else {
        //
    }
    min_Volt = (can.frame.data[5] > can.frame.data[6]) ? can.frame.data[6] : can.frame.data[5];
    //-获得火线零线对地线的电压
    AMP_All_Count++;
    if (min_Volt > set_gnd_vlot) {
        AMP_No_Count++;
        System_Display_Volt = min_Volt;
        GND_State_Volt.append(QString::number(min_Volt) + ",   ");
    } else {
        //
    }

    if (AMP_All_Count >= 10) {
        if (AMP_No_Count <= 7) {
            GND_State_Volt.clear();
            GND_State = true;
        } else {
            GND_State = false;
        }
        AMP_All_Count = 0;  AMP_No_Count = 0;
    } else {
        //
    }

    if ((window_current == wMain_Surface) || (window_current == wSyst_Surface)) {
        if (min_Volt > set_gnd_vlot) { // 接地不良
            GND_State = false;
        } else { // 接地良好
            GND_State = true;
        }
    } else if (window_current == wTest_Surface) {
        wTest->Pub_Main_to_test(GND_State_Volt, \
                                QString::number(System_Display_Volt+GND_State*1000), \
                                (can.frame.data[3]*256 + can.frame.data[4]-1000)/10, 16);
    }
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2015.6.27
      * brief:      IMP板
******************************************************************************/
void w_Main::Pri_Board_IMP()
{
    int i;
    QStringList Net_Shape_List;
    if (can.frame.data[0] == CAN_UPLOAD_STATE) {
        qDebug() << "w_Main::Pri_Board_IMP()";
        board_state[60] = can.frame.data[1];
        board_state[70] = can.frame.data[2]*256 + can.frame.data[3];
        if (window_current == wTest_Surface) {
            wTest->Pub_Main_to_test(QStringList(""), QString(""), 1, 19);
        } else if (window_current == wConf_Surface) {
            wConf->WIMP->Pub_Main_IMP_FinshSample();
            PLC_test_to_Switchover(BePuDa, 0x12, 12);
            WriteMessage((6000), CMD_Put_B1, QString(tr("Sample")).toUtf8());
        } else if (window_current == wDebug_Surface) {
            Sigmain_data_to_debug(QStringList(), QString(), 10); //-可以进行测试
        } else {
            //
        }
    } else if (can.frame.data[0] == CAN_UPLOAD_RESULT_TWO) { //-采样结果上传
        if (window_current == wConf_Surface) {
            Sigmain_can_to_conf(can.frame, QStringList(""), 1);
        } else {
            //
        }
    } else if (can.frame.data[0] == CAN_UPLOAD_SHAPE) { //-采样结束
        if (window_current != wDebug_Surface) {
            if (can.frame.data[1] == 255) {
                if ((imp_back_number%3 == 0) && ((wConf->WIMP->Copy_IMP_List.at(16).toInt() == 2)\
                        || (wConf->WIMP->Copy_IMP_List.at(17).toInt() == 2))) { //- 比较模式
                    for (int i = 0; i < 400; i++) {
                        waveform_IMP_Compare[i] = waveform_point[i];
                    }
                } else {
                    //
                }
                if (window_current == wTest_Surface) {
                    QStringList imp_data;
                    imp_data.clear();
                    imp_data.append(QString::number(imp_waveform_error));
                    imp_data.append(QString::number(imp_back_number));
                    imp_data.append(QString::number(waveform_count));
                    Net_Shape_List.clear();
                    Net_Shape_List.append(QString::number(imp_back_number));
                    for (i = 0; i < 9; i++) {
                        Net_Shape_List.append(QString::number(waveform_point[7]+7-i));
                    }
                    for (i = 9; i < 400; i++) {
                        Net_Shape_List.append(QString::number(waveform_point[i]));
                    }

                    emit WriteMessage(6000, CMD_Put_86, QString(Net_Shape_List.join(" ")).toUtf8());
                    wTest->Pub_IMP_Param(imp_data, waveform_point, waveform_IMP_Compare);

                    QStringList imp_result;

                    if (wConf->WIMP->Copy_IMP_List.at(16).toInt() == 2) {
                        imp_result = wConf->WIMP->Pub_Main_IMP_Result_Compare(imp_back_number, \
                                                         waveform_point, waveform_IMP_Compare);
                    } else if (wConf->WIMP->Copy_IMP_List.at(17).toInt() == 2) {
                        imp_result = wConf->WIMP->Pub_Main_IMP_Result_Compare_2(imp_back_number, \
                                                         waveform_point, waveform_IMP_Compare, \
                                                                                Back_out_station);
                    } else {
                        imp_result = wConf->WIMP->Pub_Main_IMP_Result(imp_back_number, \
                                                     waveform_point, Back_out_station);
                    }
                    Sigmain_data_to_test(imp_result);
                } else if (window_current == wConf_Surface) { // 显示在显示区
                    qDebug() << "w_Main::Pri_Board_IMP() Write";
                    wConf->WIMP->Pub_Main_IMP_Get_date(imp_back_number, waveform_point);
                    Net_Shape_List.clear();
                    Net_Shape_List.append(QString::number(imp_back_number));
                    for (i = 0; i < 9; i++) {
                        Net_Shape_List.append(QString::number(waveform_point[7]+7-i));
                    }
                    for (i = 9; i < 400; i++) {
                        Net_Shape_List.append(QString::number(waveform_point[i]));
                    }
                    emit WriteMessage(6000, CMD_Put_85, QString(Net_Shape_List.join(" ")).toUtf8());
                    waveform_count = 0;
                } else {
                    //
                }
                waveform_count = 0;
            } else {
                imp_back_number = can.frame.data[1];
                if (window_current == wTest_Surface) {
                    wTest->Pub_Main_to_test(QStringList(""), QString(""), imp_back_number, 20);
                } else {
                    //
                }
                if (window_current == wConf_Surface) {
                    wConf->WIMP->IMP_WaveList[imp_back_number]->IMP_PP = \
                            can.frame.data[3]*256 + can.frame.data[4];
                    wConf->WIMP->IMP_WaveList[imp_back_number]->IMP_Point = can.frame.data[2];
                } else {
                    //
                }
                waveform_count = 0;
            }
        } else if (window_current == wDebug_Surface) {
            if (can.frame.data[1] == 255) {
                //
            } else {
                Sigmain_data_to_debug(QStringList(), \
                                QString::number(can.frame.data[3]*256 + can.frame.data[4]), 8);
            }
        }
    } else if (can.frame.data[0] == CAN_UPLOAD_Version) { //-版本号
        Version.IMPV = Pri_Board_Version();
        QString string_q = "";
        string_q.clear();
        for (int i = 0; i < 8; i++) {
            string_q += QString::number(can.frame.data[i]);
        }
        if (string_q.toInt() >= 60) {
            wConf->Pub_main_to_conf(QStringList(""), QString(""), 1, 17);
            Sigmain_data_to_syst(QString(""), 3);
        } else {
            //
        }
    } else if (can.frame.data[0] == CAN_UPLOAD_Debug) { //-调试参数上传
        if ((window_current == wDebug_Surface) && (can.frame.data[1] <= 5)) {
            QStringList list;
            list.append(QString::number(can.frame.data[1]));
            list.append(QString::number(can.frame.data[2]));
            list.append(QString::number(can.frame.data[3]));
            Sigmain_data_to_debug(list, QString(""), 9);
        } else {
            //
        }
    } else {
        //
    }
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2016.11.14
      * brief:      PWR 板
******************************************************************************/
void w_Main::Pri_Board_PWR(int Id)
{
    if (can.frame.data[0] == CAN_UPLOAD_STATE) {
        if ((window_current == wMain_Surface) || (window_current == wSyst_Surface)) {
            //-查询数据的状态
            board_state[80] = can.frame.data[1]; //-左工位
            board_state[90] = can.frame.data[2]*256+can.frame.data[3];
            return;
        }
        if (window_current == wTest_Surface) {
            if (can.frame.data[1] == 0) {
                QStringList pg_data; pg_data.clear();
                pg_data.append(QString::number(pg_waveform_error));
                pg_data.append(QString::number(Start_get_pg_shape));
                wTest->Pub_PWR_Param(pg_data, waveform_point, waveform_point_c);
            } else if (can.frame.data[1] == 1) {
                wTest->Pub_Main_to_test(QStringList(""), QString(""), 1, 7);
            } else {
                //
            }
        } else if (window_current == wConf_Surface) {
            if (can.frame.data[1] == 0) {
                wConf->Pub_main_to_conf(QStringList(""), QString(""), 1, 16);
            } else if (can.frame.data[1] == 5) {
                wConf->Pub_main_to_conf(QStringList(""), QString(""), 2, 16);
            } else {
                //
            }
        } else {
            //-其他界面暂时不做处理
        }
    } else if ((can.frame.data[0] == 0x01) || (can.frame.data[0] == 0x02) || \
               (can.frame.data[0] == 0x03)) { // -A相上传 频率时间转向转速  B相上传
        if (window_current == wTest_Surface) {
            wTest->Pub_Main_can_to_test(can.frame, 1);
        } else {
            //
        }
        if (window_current == wConf_Surface) {
            if (can.frame.data[0] == 1) {
                Sigmain_can_to_conf(can.frame, QStringList(""), 5);
            } else {
                //
            }
        } else {
            //
        }
    } else if (can.frame.data[0] == CAN_UPLOAD_Debug) { //-调试界面
        QStringList Aphase;     Aphase.clear();
        QStringList Bphase;     Bphase.clear();
        QStringList Cphase;     Cphase.clear();
        switch (can.frame.data[1]) {
        case 0:
            Aphase.append(QString::number((can.frame.data[2]*256 + can.frame.data[3])));
            Aphase.append(QString::number((can.frame.data[4]*256 + can.frame.data[5])));
            Aphase.append(QString::number((can.frame.data[6]*256 + can.frame.data[7])));
            Sigmain_data_to_debug(Aphase, QString::number(can.frame.data[1]), 12);
            break;
        case 1:
            Bphase.append(QString::number((can.frame.data[2]*256 + can.frame.data[3])));
            Bphase.append(QString::number((can.frame.data[4]*256 + can.frame.data[5])));
            Bphase.append(QString::number((can.frame.data[6]*256 + can.frame.data[7])));
            Sigmain_data_to_debug(Bphase, QString::number(can.frame.data[1]), 12);
            break;
        case 2:
            Cphase.append(QString::number((can.frame.data[2]*256 + can.frame.data[3])));
            Cphase.append(QString::number((can.frame.data[4]*256 + can.frame.data[5])));
            Cphase.append(QString::number((can.frame.data[6]*256 + can.frame.data[7])));
            Sigmain_data_to_debug(Cphase, QString::number(can.frame.data[1]), 12);
            break;
        default:
            break;
        }
    } else if (can.frame.data[0] == CAN_UPLOAD_Version) {
        if (Id == 225) {
            Version.PWR_LV = Pri_Board_Version();
        } else {
            //
        }
    }
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2016.11.14
      * brief:      INDL板
******************************************************************************/
void w_Main::Pri_Board_INDL()
{
    if (can.frame.data[0] == CAN_UPLOAD_STATE) {
        if ((window_current == wMain_Surface) || (window_current == wSyst_Surface)) {
            board_state[100] = can.frame.data[1];
        } else if (window_current == wDebug_Surface) {
            Sigmain_data_to_debug(QStringList(""), QString::number(can.frame.data[1]), 13);
        } else if (window_current == wConf_Surface) {
            wConf->Board_INDL = 1;
            wConf->Pub_main_to_conf(QStringList(""), QString(""), 1, 12);
        } else {
            //
        }
    } else if (can.frame.data[0] == CAN_UPLOAD_RESULT_ONE) {
        if (window_current == wTest_Surface) {
            wTest->Pub_Main_can_to_test(can.frame, 2);
        } else if (window_current == wConf_Surface) {
            Sigmain_can_to_conf(can.frame, QStringList(""), 3);
        } else {
            //
        }
    } else if (can.frame.data[0] == CAN_UPLOAD_Version) {
        QString str = "";
        str.clear();
        for (int i = 1; i < 6; i++) {
            str += (QChar)(can.frame.data[i]);
        }
        str += QString::number(can.frame.data[6]);
        str += " ";
        str += QString::number(can.frame.data[7]);
        Version.INDLV = str;
    } else {
        //
    }
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2017.6.12
      * brief:      ACSW板
******************************************************************************/
void w_Main::Pri_Board_ACSW()
{
    if (can.frame.data[0] == CAN_UPLOAD_STATE) {
        if ((window_current == wMain_Surface) || (window_current == wSyst_Surface)) {
            board_state[140] = can.frame.data[1];
        } else {
            //
        }
    } else if (can.frame.data[0] == CAN_UPLOAD_Version) {
        Version.ACSW = Pri_Board_Version();
    } else if ((can.frame.data[0] == 1) || (can.frame.data[0] == 2) || (can.frame.data[0] == 3)) {
        if (window_current == wTest_Surface) {
            wTest->Pub_Main_can_to_test(can.frame, 3);
        } else {
            //
        }
    } else if (can.frame.data[0] == 4) {
        if (can.frame.data[1] == 0) {
            waveform_count = 0;
            qDebug() << "w_Main::Pri_Board_ACSW() start upload";
        } else if (can.frame.data[1] != 0) {
            qDebug() << "w_Main::Pri_Board_ACSW() start upload finsh";
        } else {
            //
        }
    } else {
        //
    }
}

void w_Main::PG_State_Check() {
    qDebug() << "w_Main::PG_State_Check()---1" << wTest->PG_Test_State;
    frame.can_id = 0x2C; // -PG
    frame.can_dlc = 0x01;
    frame.data[0] = 0x00;
    canSend(frame, 88);

    if (wTest->PG_Test_State == 0xA2) {
        // -
    } else if (wTest->PG_Test_State == 0xA3) { // 完成状态
        if (PG_Down_Get_Data) {
            PG_Down_Get_Data = false;
//            frame.can_id = 0x2C; // -PG
//            frame.can_dlc = 0x04;
//            frame.data[0] = 0x0C; frame.data[1] = PG_Finsh_Shape_Count;
//            frame.data[2] = 400 % 256; frame.data[3] = 400 / 256;
//            canSend(frame, 88); usleep(1000); usleep(1000); usleep(1000);
        } else { // 完成状态　累加
            qDebug() << "3" << PG_Finsh_Count;
            PG_Finsh_Count++;
            if (PG_Finsh_Count == 10) {
                frame.can_id = 0x2C; // -PG
                frame.can_dlc = 0x04;
                frame.data[0] = 0x0C; frame.data[1] = PG_Finsh_Shape_Count;
                frame.data[2] = 400 % 256; frame.data[3] = 400 / 256;
                canSend(frame, 88); usleep(1000); usleep(1000); usleep(1000);
            }
            if (PG_Finsh_Count == 20) { // 4S
                PG_Finsh_Count = 0;
                qDebug() << "w_Main::PG_State_Check() PG_State_Check_Time->stop();";
                PG_State_Check_Time->stop();
                Sigmain_data_to_test(QStringList("")); // 更新数据
            }
        }
    } else {
        //
    }
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2017.8.18
      * brief:      PG板
******************************************************************************/
void  w_Main::Pri_Board_PG() {
    QStringList list_d;
    if (can.frame.data[0] == CAN_UPLOAD_STATE) {
        board_state[170] = can.frame.data[1];
        if (window_current == wTest_Surface) {
            if (can.frame.data[1] == 0xA0) { // 测试状态
                wTest->PG_Test_State = 0xA0;
                qDebug() << "w_Main::Pri_Board_PG() WD_Read_Param";
                frame.can_id = 0x2B;  frame.can_dlc = 0x02; //
                frame.data[0] = 0x01;
                frame.data[1] = 0x01;
                canSend(frame, 88);
            } else if (can.frame.data[1] == 0xA1) { // 缓升状态
                wTest->PG_Test_State = 0xA1;
            } else if (can.frame.data[1] == 0xA2) { // 缓降状态
                wTest->PG_Test_State = 0xA2;
            } else if (can.frame.data[1] == 0xA3) { // 测试完成状态
                wTest->PG_Test_State = 0xA3;
            } else {
                qDebug() << "w_Main::Pri_Board_PG() PG_State_Error" << can.frame.data[1];
                wTest->PG_Test_State = can.frame.data[1];
            }
        } else {
            //
        }
    } else if (can.frame.data[0] == 0x09) {
        if (can.frame.data[1] == 1) {
            Shape_BEMF_Fre.replace(can.frame.data[2], \
                    QString::number(can.frame.data[5]*65536 + can.frame.data[4]*256 + can.frame.data[3]));
        } else {
            //
        }
    } else if (can.frame.data[0] == 0x0a) {
        BEMF_HIGH_Low.replace((can.frame.data[1]*10 + can.frame.data[2])*2, \
               QString::number(can.frame.data[4]*256 + can.frame.data[3]));
        BEMF_HIGH_Low.replace((can.frame.data[1]*10 + can.frame.data[2])*2+1, \
               QString::number(can.frame.data[6]*256 + can.frame.data[5]));

    } else if (can.frame.data[0] == 0x0c) {
        qDebug() << "w_Main::Pri_Board_PG() Shape Start";
        Shape_Pg.append(QString::number(can.frame.data[1]));
    } else if (can.frame.data[0] == 0xff) {
        qDebug() << "w_Main::Pri_Board_PG() Shape Stop";
        qDebug() << "w_Main::Pri_Board_PG() Shape_Pg" << Shape_Pg.at(0);
        wTest->Pub_FG_Param(Shape_Pg);
        waveform_count = 0;
        WriteMessage(6000, CMD_Put_75, QString(Shape_Pg.join(" ")).toUtf8());
        Shape_Pg.clear();
    } else if (can.frame.data[0] == 0x17) {
        Fg_Direction = can.frame.data[1];
        pg_Turn = can.frame.data[1];
    } else if (can.frame.data[0] == CAN_UPLOAD_Version) {
        Version.VBLDCPG = Pri_Board_Version();
    } else if (can.frame.data[0] == 0x1E) { // 相位角
        Phase_diffence.replace(can.frame.data[1]*4 + can.frame.data[2]*2, \
                QString::number(can.frame.data[4] * 256 + can.frame.data[3]));
        Phase_diffence.replace(can.frame.data[1]*4 + can.frame.data[2]*2 + 1, \
                QString::number(can.frame.data[6] * 256 + can.frame.data[5]));
    } else if (can.frame.data[0] == 0x22) { // 转向
        Phase_enable = can.frame.data[1];
    } else if (can.frame.data[0] == 0x1f) {
        if (can.frame.data[1] == 0x01) {
            wTest->NoLoadFinsh = true;
            qDebug() << "w_Main::Pri_Board_PG() PG_State_Check_Time->stop();";
            PG_State_Check_Time->stop();

            list_d.clear();
            list_d.append(Phase_diffence);
            list_d.append(QString::number(WD_I));
            list_d.append(QString::number(WD_V));
            list_d.append(QString::number(WD_P));
            list_d.append(Shape_BEMF_Fre.at(0)); // 转速
            list_d.append(QString::number(I_Vcc));
            list_d.append(QString::number(I_Vsp));
            list_d.append(QString::number(pg_Turn));
            list_d.append(BEMF_HIGH_Low.at(2));
            list_d.append(BEMF_HIGH_Low.at(22));
            list_d.append(BEMF_HIGH_Low.at(42));
            list_d.append(QString::number(Phase_enable));


            wTest->Pub_Main_to_test(list_d, \
                                    QString(""), 1, 29);

            list_d.clear();
            list_d.append(Phase_diffence);
            list_d.append(Shape_BEMF_Fre);
            list_d.append(BEMF_HIGH_Low);
            wTest->Pub_Main_to_test(list_d, \
                                    QString(""), 1, 30);

               //
        }
    } else {
        //
    }
}

void  w_Main::Pri_Board_IO() {
    int i = 0;
    int in_data = 0;
    QStringList Test_Io_data;
    if (can.frame.data[0] == CAN_UPLOAD_STATE) {
        board_state[210] = can.frame.data[1];
    } else if (can.frame.data[0] == CAN_UPLOAD_Version) {
        Version.IO = Pri_Board_Version();
    } else if ((can.frame.data[0] == 0xf0)&&((can.frame.can_dlc == 3))) {
        in_data = can.frame.data[1] + can.frame.data[2]*256;
        WriteMessage(6000, CMD_Put_IO_IN, QString::number(in_data).toUtf8());
        if (PIC_Connect) {
            Signal_main_to_pic(QStringList(""), in_data, 1);
        } else {
            //
        }
        wTest->Pub_Main_to_test(QStringList(""), QString(""), in_data, 120);
    } else if ((can.frame.data[0] == 0xf0)&&((can.frame.can_dlc == 4))) {
        in_data = can.frame.data[1]+can.frame.data[2]*256 + can.frame.data[3]*65536;
        WriteMessage(6000, CMD_Put_IO_IN, QString::number(in_data).toUtf8());
        if (PIC_Connect) {
            Signal_main_to_pic(QStringList(""), in_data, 1);
        } else {
            //
        }
        wTest->Pub_Main_to_test(QStringList(""), QString(""), in_data, 120);
    } else if (can.frame.data[0] == 0x11) {
        RFID_H.clear();
        for (i = can.frame.can_dlc-1; i >= 1; i--) {
            RFID_H += QString("%1").arg(can.frame.data[i] & 0xFF, 2, 16, QLatin1Char('0'));
        }
        wTest->Pub_Main_to_test(QStringList(""), RFID_H, 1, 121);
    }  else if (can.frame.data[0] == 0x12) {
        Sigmain_data_to_syst(QString::number(can.frame.data[2]), 4);
    }  else if (can.frame.data[0] == 0xf6) {
        if (can.frame.data[1] == 0x02) {
            if (window_current == wTest_Surface) {        //-测试界面
                qDebug() << "w_Main::Pri_Board_IO() Stop";
                Signal_main_to_pic(QStringList(""), 19*10 + 0, 11);
                PLC_test_to_Switchover(DeChang, 0, 16);
                wTest->Pub_Main_to_test(QStringList(""), "0", 2, 12);
            }
        } else if ((can.frame.data[1] == 0x01) && (can.frame.data[2] == 0x00)) {
            //            if (window_current == wTest_Surface) {        //-测试界面
            //                 qDebug() << "停止";
            //                Signal_main_to_pic(QStringList(""), 19*10 + 0, 11);
            //                WriteMessage(6000, CMD_Put_98, QString::number(out_station).toUtf8());
            //                wTest->Pub_Main_to_test(QStringList(""), "0", 2, 12);
            //            }
        } else if ((can.frame.data[1] == 0x01) && (can.frame.data[2] == 0x01)) {
            if (window_current == wTest_Surface) { // -测试界面,已经拉开滑罩
                qDebug() << "w_Main::Pri_Board_IO() Start";
                Signal_main_to_pic(QStringList(""), 19*10+1, 11);
                out_station = 0x13;
                // -更改顺序，在大疆无人机出现的问题-2017.5.16
                WriteMessage((6000), CMD_Put_97, QString::number(out_station).toUtf8());
                wTest->Pub_Main_to_test(QStringList(""), \
                                        QString::number(wTest->START_Model), 0x13, 11);
            }
        } else {
            //
        }
    } else if (can.frame.data[0] == 0xff) {

        frame.can_id  = 0x2D;  frame.can_dlc = 0x01;
        frame.data[0] = 0xf0;
        canSend(frame, 88);
        usleep(1800);

        WriteMessage((6000), CMD_Put_Message, QString("17").toUtf8());
    } else if (can.frame.data[0] == 0xf2) {
        Test_Io_data.clear();
        Test_Io_data.append(QString::number(can.frame.data[2]*256 + can.frame.data[1]));
        Test_Io_data.append(QString::number(can.frame.data[4]*256 + can.frame.data[3]));
        if (WL_Test_Flag) {
            WL_Test_Flag = false;
            wTest->Pub_Main_to_test(Test_Io_data, \
                                    QString(""), 1, 125);
        } else {
            wTest->Pub_Main_to_test(Test_Io_data, \
                                    QString(""), 0, 125);
        }
    } else {
        //
    }
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2017.8.18
      * brief:      WD板
******************************************************************************/
void  w_Main::Pri_Board_WD() {
    QStringList list_d;
    if (can.frame.data[0] == CAN_UPLOAD_STATE) {
        board_state[190] = can.frame.data[1];
        if (window_current == wTest_Surface) {
            //
        }
    } else if (can.frame.data[0] == 0x03) {
        WD_I = ((double(can.frame.data[3]*256 + can.frame.data[2]))/10000)*5;
        if (WD_I < 0.00) {
            WD_I = 0.00;
        } else {
            //
        }
        WD_V = ((double(can.frame.data[5]*256 + can.frame.data[4]))/10000)*1650.6319;
        if (WD_V < 0.00) {
            WD_V = 0.00;
        } else {
            //
        }
        WD_P = WD_I*WD_V;

        list_d.clear();
        list_d.append(Phase_diffence);
        list_d.append(QString::number(WD_I));
        list_d.append(QString::number(WD_V));
        list_d.append(QString::number(WD_P));
        list_d.append(Shape_BEMF_Fre.at(0)); // 转速
        list_d.append(QString::number(I_Vcc));
        list_d.append(QString::number(I_Vsp));
        list_d.append(QString::number(pg_Turn));
        list_d.append(BEMF_HIGH_Low.at(2));
        list_d.append(BEMF_HIGH_Low.at(22));
        list_d.append(BEMF_HIGH_Low.at(42));
        list_d.append(QString::number(Phase_enable));


        wTest->Pub_Main_to_test(list_d, \
                                QString(""), 1, 28);
    } else if (can.frame.data[0] == 0x06) {
        Square_WD = can.frame.data[4]*65536 + can.frame.data[3]*256 + can.frame.data[2];
    } else if (can.frame.data[0] == 0x07) {
        //
    } else if (can.frame.data[0] == CAN_UPLOAD_Version) {
        Version.BLDCWD = Pri_Board_Version();
    } else {
        //
    }
}


/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2017.8.18
      * brief:      PG板波形数据
******************************************************************************/
void  w_Main::Pri_Board_PG_Wave() {
    int i = 0;
    for (i = 0; i < 8; i++) {
        Shape_Pg.append(QString::number(can.frame.data[i]));
    }
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2015.5.20
      * brief:      输出板状态检测和启动测试
******************************************************************************/
QString w_Main::Pri_Board_Version()
{
    QString str = "";
    str.clear();

    for (int i = 1; i < 6; i++) {
        str += (QChar)(can.frame.data[i]);
    }
    str += QString::number(can.frame.data[6]);
    str += "-";
    str += QString::number(can.frame.data[7]);

    return str;
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2015.5.26
      * brief:      打印CAN接收信息
******************************************************************************/
void w_Main::Pri_Can_Receive(int Id)
{
    int i = 0;
    QString Can_Receive = "";
    can_number++;
    if (can_number >= 65536) {
        can_number = 0;
    } else {
        //
    }
    Can_Receive.clear();
    Can_Receive = QString::number(Id)+" "+ QString::number(can.frame.can_dlc)+" ";
    for (i = 0; i < can.frame.can_dlc; i++) {
        Can_Receive += QString::number(can.frame.data[i]); Can_Receive += " ";
    }
    Can_Receive += "  ";  Can_Receive += QString::number(can_number);
    qDebug() << Can_Receive;
    Can_Receive.clear();
}

void w_Main::Pubs_Usart_Send_DeChang(QString str) {
    if (myCom_DeChang == NULL) {
        return;
    } else {
        //
    }
    uint16_t crc;
    QString Send_Data;
    crc = crc16_modbus(str.toLatin1().data(), str.length());
    Send_Data =
    Send_Data = QString("$") + \
            str + \
            (QString("%1").arg(crc, 4, 16, QLatin1Char('0'))).toUpper() + \
            QString("*");
    myCom_DeChang->WritePort(Send_Data.toLatin1().data(),
                             QString(Send_Data).length());
}
void w_Main::Pubs_Usart_Send_WEILING(QString str) {
    if (myCom_DeChang == NULL) {
        return;
    } else {
        //
    }

    QByteArray aa;
    aa.append(str);
    myCom_DeChang->WritePort(QByteArray::fromHex(aa).data(), \
                             QByteArray::fromHex(aa).length());
}

void w_Main::Pubs_Usart_Send_E(char *Buf) {
    qDebug() << "w_Main::Pubs_Usart_Send_E" << QString(Buf);
    if (Ini_LR_Beep && (Back_out_station == 20)) {
        frame.can_id = 0x22;  frame.can_dlc = 0x02; //-发送给电阻板
        frame.data[0] = 0x09;
        if (QString(Buf) == "LEDY") { //-黄灯
            frame.data[1] = 0x04;
        } else if (QString(Buf) == "LEDG") { //-绿灯
            if (DCR_Beep_Ok != 0) {
                DCR_BEEP = 0x02|0x08;
                dcr_board->setSingleShot(TRUE);
                dcr_board->start(DCR_Beep_Ok*1000);
            } else {
                DCR_BEEP = 0x02;
            }
            frame.data[1] = DCR_BEEP;
        } else if (QString(Buf)== "LEDR") { //-红灯
            if (DCR_Beep_Ng != 0) {
                DCR_BEEP = 0x01|0x08;
                dcr_board->setSingleShot(TRUE);
                dcr_board->start(DCR_Beep_Ng*1000);
            } else {
                DCR_BEEP = 0x01;
            }
            frame.data[1] = DCR_BEEP;
        } else {
            frame.data[1] = 0x00;
            dcr_board->stop();
        }
        canSend(frame, 88); usleep(500);
    } else if (Ini_LR_Beep&&(Back_out_station == 19)) {
        frame.can_id = 0x23;  frame.can_dlc = 0x02; //-发送给耐压板
        frame.data[0] = 0x09;
        if (QString(Buf) == "LEDY") { //-黄灯
            frame.data[1] = 0x04;
        } else if (QString(Buf) == "LEDG") { //-绿灯
            if (DCR_Beep_Ok != 0) {
                DCR_BEEP = 0x02|0x08;
                acw_board->setSingleShot(TRUE);
                acw_board->start(DCR_Beep_Ok*1000);
            } else {
                DCR_BEEP = 0x02;
            }
            frame.data[1] = DCR_BEEP;
        } else if (QString(Buf) == "LEDR") { //-红灯
            if (DCR_Beep_Ng != 0) {
                DCR_BEEP = 0x01|0x08;
                acw_board->setSingleShot(TRUE);
                acw_board->start(DCR_Beep_Ng*1000);
            } else {
                DCR_BEEP = 0x01;
            }
            frame.data[1] = DCR_BEEP;
        } else {
            frame.data[1] = 0x00;
            acw_board->stop();
        }
        canSend(frame, 88); usleep(500);
    } else {
        frame.can_id = 0x22;  frame.can_dlc = 0x02; //-发送给电阻板
        frame.data[0] = 0x09;
        if (QString(Buf) == "LEDY") { //-黄灯
            frame.data[1] = 0x04;
        } else if (QString(Buf) == "LEDG") { //-绿灯
            if (DCR_Beep_Ok != 0) {
                DCR_BEEP = 0x02|0x08;
                dcr_board->setSingleShot(TRUE);
                dcr_board->start(DCR_Beep_Ok*1000);
            } else {
                DCR_BEEP = 0x02;
            }
            frame.data[1] = DCR_BEEP;
        } else if (QString(Buf) == "LEDR") { //-红灯
            if (DCR_Beep_Ng != 0) {
                DCR_BEEP = 0x01|0x08;
                dcr_board->setSingleShot(TRUE);
                dcr_board->start(DCR_Beep_Ng*1000);
            } else {
                DCR_BEEP = 0x01;
            }
            frame.data[1] = DCR_BEEP;
        } else {
            frame.data[1] = 0x00;
            dcr_board->stop();
        }
        canSend(frame, 88); usleep(500);
    }

}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2015.5.5
      * brief:      打印串口信息 (2016.10.9 添加输出板输出量信号)
******************************************************************************/
void w_Main::Pubs_Usart_Send(char *Buf)
{
    if (Ini_Beep_Up) {
        if (QString(Buf) == "LEDY") {
            //
        } else {
            qDebug() << "return---> w_Main::Pubs_Usart_Send()";
            return;
        }
    }
    myCom->WritePort(Buf, 4); usleep(10); myCom->WritePort(Buf, 4); usleep(00);

    Back_out_station = out_station; //-发送给输出板
    frame.can_id = Back_out_station;
    frame.can_dlc = 0x02; //-输出板输出量信号发送
    frame.data[0] = 0x02;
    if (QString(Buf) == "LEDY") {
        frame.data[1] = 0x01;
    } else if (QString(Buf) == "LEDG") {
        frame.data[1] = 0x02;
    } else if (QString(Buf) == "LEDR")  {
        frame.data[1] = 0x03;
    } else {
        frame.data[1] = 0x00;
    }
    canSend(frame, 88); usleep(500);

    if ((QString(Buf) == "LEDG")&&(out_stamp)) { //-判定合格之后，进行短暂显示
        out_board->setSingleShot(TRUE);
        out_board->start(system_conf.at(1).toDouble()*1000); //-印度客户启动定时器
    } else {
        //
    }

    qDebug() << "w_Main::Pubs_Usart_Send()" << QString(Buf);
    if (Ini_LR_Beep&&(Back_out_station == 20)) {
        frame.can_id = 0x22;  frame.can_dlc = 0x02; //-发送给电阻板
        frame.data[0] = 0x09;
        if (QString(Buf) == "LEDY") { //-黄灯
            frame.data[1] = 0x04;
        } else if (QString(Buf) == "LEDG") { //-绿灯
            if (DCR_Beep_Ok != 0) {
                DCR_BEEP = 0x02|0x08;
                dcr_board->setSingleShot(TRUE);
                dcr_board->start(DCR_Beep_Ok*1000);
            } else {
                DCR_BEEP = 0x02;
            }
            frame.data[1] = DCR_BEEP;
        } else if (QString(Buf)== "LEDR") { //-红灯
            if (DCR_Beep_Ng != 0) {
                DCR_BEEP = 0x01|0x08;
                dcr_board->setSingleShot(TRUE);
                dcr_board->start(DCR_Beep_Ng*1000);
            } else {
                DCR_BEEP = 0x01;
            }
            frame.data[1] = DCR_BEEP;
        } else {
            frame.data[1] = 0x00;
            dcr_board->stop();
        }
        canSend(frame, 88); usleep(500);
    } else if (Ini_LR_Beep&&(Back_out_station == 19)) {
        frame.can_id = 0x23;  frame.can_dlc = 0x02; //-发送给耐压板
        frame.data[0] = 0x09;
        if (QString(Buf) == "LEDY") { //-黄灯
            frame.data[1] = 0x04;
        } else if (QString(Buf) == "LEDG") { //-绿灯
            if (DCR_Beep_Ok != 0) {
                DCR_BEEP = 0x02|0x08;
                acw_board->setSingleShot(TRUE);
                acw_board->start(DCR_Beep_Ok*1000);
            } else {
                DCR_BEEP = 0x02;
            }
            frame.data[1] = DCR_BEEP;
        } else if (QString(Buf) == "LEDR") { //-红灯
            if (DCR_Beep_Ng != 0) {
                DCR_BEEP = 0x01|0x08;
                acw_board->setSingleShot(TRUE);
                acw_board->start(DCR_Beep_Ng*1000);
            } else {
                DCR_BEEP = 0x01;
            }
            frame.data[1] = DCR_BEEP;
        } else {
            frame.data[1] = 0x00;
            acw_board->stop();
        }
        canSend(frame, 88); usleep(500);
    } else {
        frame.can_id = 0x22;  frame.can_dlc = 0x02; //-发送给电阻板
        frame.data[0] = 0x09;
        if (QString(Buf) == "LEDY") { //-黄灯
            frame.data[1] = 0x04;
        } else if (QString(Buf) == "LEDG") { //-绿灯
            if (DCR_Beep_Ok != 0) {
                DCR_BEEP = 0x02|0x08;
                dcr_board->setSingleShot(TRUE);
                dcr_board->start(DCR_Beep_Ok*1000);
            } else {
                DCR_BEEP = 0x02;
            }
            frame.data[1] = DCR_BEEP;
        } else if (QString(Buf) == "LEDR") { //-红灯
            if (DCR_Beep_Ng != 0) {
                DCR_BEEP = 0x01|0x08;
                dcr_board->setSingleShot(TRUE);
                dcr_board->start(DCR_Beep_Ng*1000);
            } else {
                DCR_BEEP = 0x01;
            }
            frame.data[1] = DCR_BEEP;
        } else {
            frame.data[1] = 0x00;
            dcr_board->stop();
        }
        canSend(frame, 88); usleep(500);
    }

    if (QString(Buf) == "LED1") {
        frame.can_id = 0x22;  frame.can_dlc = 0x02; //-发送给电阻板
        frame.data[0] = 0x09;
        frame.data[1] = 0x00;
        dcr_board->stop();
        canSend(frame, 88); usleep(500);
        frame.can_id = 0x23;  frame.can_dlc = 0x02; //-发送给耐压板
        frame.data[0] = 0x09;
        frame.data[1] = 0x00;
        acw_board->stop();
        canSend(frame, 88); usleep(500);
    } else {
        //
    }
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2017.7.20
      * brief:      输出板停止
******************************************************************************/
void w_Main::Out_Board_Stop() {
    frame.can_id = Back_out_station; //-输出板输出量信号发送
    frame.can_dlc = 0x02;
    frame.data[0] = 0x02;
    frame.data[1] = 0x00;
    canSend(frame, 88); usleep(500);
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2017.7.20
      * brief:      电阻板停止
******************************************************************************/
void w_Main::Dcr_Board_Stop() {
    frame.can_id = 0x22; //-输出板输出量信号发送
    frame.can_dlc = 0x02;
    frame.data[0] = 0x09;
    frame.data[1] = (DCR_BEEP&0x07);
    canSend(frame, 88); usleep(500);
}

void w_Main::Acw_Board_Stop() {
    frame.can_id = 0x23; //-输出板输出量信号发送
    frame.can_dlc = 0x02;
    frame.data[0] = 0x09;
    frame.data[1] = (DCR_BEEP&0x07);
    canSend(frame, 88); usleep(500);
}

/******************************************************************************
       * version:    1.0
       * author:     sl
       * date:       2016.5.19
       * brief:      设置警告弹出框
******************************************************************************/
void  w_Main::Pri_Main_WMessage(int number, QString str) {
    qDebug() << "w_Main::Pri_Main_WMessage" << wTest->START_Model;
    if (wTest->START_Model == 3) {
        WMessage_Record.append(QString::number(number));
    } else if ((Ini_Vacuum_Model) && (wTest->START_Model == 2)) {
        WMessage_Record.append(QString::number(number));
    } else {
        QMessageBox *message = new QMessageBox(this);
        message->setWindowFlags(Qt::FramelessWindowHint);
        message->setStyleSheet("QMessageBox{border: gray;" \
                       "border-radius: 10px;padding:2px 4px;" \
                       "background-color: gray;height:390px;width:375px;}");
        message->setText(WMessage_Text.at(number) + str + "\n");
        message->addButton(QMessageBox::Ok)->setStyleSheet("height:39px;width:75px;"\
                  "border:5px groove;border:none;border-radius:10px;padding:2px 4px;");
        message->setButtonText(QMessageBox::Ok, QString(tr("确 定")));
        message->setIcon(QMessageBox::Warning);
        message->exec();
    }
    /*  if (Shake_hand_Success) {
          WriteMessage(6000, CMD_Put_Message,QString("%1").arg(QString::number(100+number)).toUtf8());
      } */
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2016.6.8
      * brief:      查询板子状态
******************************************************************************/
void  w_Main::Pri_Can_CheckState(int id) {
    frame.can_id = id;  frame.can_dlc = 0x01; //-输出板发送
    frame.data[0] = 0x00;
    canSend(frame, 88);
    usleep(500);
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2016.6.8
      * brief:      查询板子版本
******************************************************************************/
void  w_Main::Pri_Can_CheckVersion(int id)
{
    frame.can_id = id;  frame.can_dlc = 0x01; //-输出板发送
    frame.data[0] = 0x08;
    canSend(frame, 88);
    usleep(500);
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2016.6.8
      * brief:      设置输出板  启动方式
******************************************************************************/
void  w_Main::Pri_Can_Set_OUTModel(int id, int KeyModel)
{
    frame.can_id =  id;  frame.can_dlc = 0x02;
    frame.data[0] = 0x03;
    frame.data[1] = KeyModel;
    canSend(frame, 88);
    usleep(500);
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2016.9.28
      * brief:      设置内存空间的剩余空间报警
******************************************************************************/
void  w_Main::Pri_availableDisk()
{
    struct statfs diskInfo;
    statfs("/mnt/nandflash", &diskInfo);
    uint64_t blocksize = diskInfo.f_bsize;                  // -每个block里包含的字节数
    uint64_t freeDisk = diskInfo.f_bfree * blocksize;       // -剩余空间的大小
    uint64_t availableDisk = diskInfo.f_bavail * blocksize; // -可用空间大小

    qDebug() << "w_Main::Pri_availableDisk()" << (freeDisk >> 20) << (availableDisk >> 20);
    if ((availableDisk>>20) < Memory_surplus) { //-设置内存空间
        Pri_Main_WMessage(10, QString::number(availableDisk>>20));
    } else {
       //
    }
}

uint16_t w_Main::crc16_modbus(char *data, uint16_t length)
{
    uint8_t i;
    uint16_t crc = 0xffff;        // Initial value
    while (length--) {
        crc ^= *data++;            // crc ^= *data; data++;
        for (i = 0; i < 8; ++i) {
            if (crc & 1)
                crc = (crc >> 1) ^ 0xA001;        // 0xA001 = reverse 0x8005
            else
                crc = (crc >> 1);
        }
    }
    return crc;
}


/******************************************************************************
                                        END

******************************************************************************/
