/*******************************************************************************
 * Copyright [2016]   <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     2.0.7.1
 * author:      sl
 * brief:       头文件
*******************************************************************************/
#include "w_conf.h"
#include "ui_w_conf.h"
static bool Clicked = true;
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      设置界面初始化
******************************************************************************/
w_Conf::w_Conf(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::w_Conf)
{
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint); // 去掉标题栏
    ui->setupUi(this);

    WDLR   = NULL;  // -电阻界面为空
    WMAG   = NULL;  // -反嵌界面为空
    WIR    = NULL;  // -绝缘界面为空
    WACW   = NULL;  // -交耐界面为空
    WDCW   = NULL;  // -直耐界面为空
    WIMP   = NULL;  // -匝间界面为空
    WPWR   = NULL;  // -功率界面为空
    WINDL  = NULL;  // -电感界面为空
    WBLOCK = NULL;  // -堵转界面为空
    WLVS   = NULL;  // -低启界面为空
    WPG    = NULL;  // -霍尔界面为空
    WLOAD  = NULL;  // -负载界面为空
    WNoLoad = NULL;  // -空载界面为空
    WBEMF  = NULL;  // -BEMF界面为空

    btnGroup_function = new QButtonGroup; // -配置按钮
    btnGroup_function->addButton(ui->Key_A, Qt::Key_A);
    btnGroup_function->addButton(ui->Key_B, Qt::Key_B);
    btnGroup_function->addButton(ui->Key_C, Qt::Key_C);
    btnGroup_function->addButton(ui->Key_D, Qt::Key_D); ui->Key_D->hide();
    btnGroup_function->addButton(ui->Key_E, Qt::Key_E); ui->Key_E->hide();
    connect(btnGroup_function, SIGNAL(buttonClicked(int)), \
            this, SLOT(SlOT_Button_Function_Judge(int)));

    btnGroup_Color = new QButtonGroup;    // -颜色按键
    connect(btnGroup_Color, SIGNAL(buttonClicked(int)), this, SLOT(SlOT_Button_Color_Judge(int)));

    btnGroup_Conf = new QButtonGroup;     // -测试项目
    btnGroup_Conf->addButton(ui->Button_ALL, Qt::Key_0);
    btnGroup_Conf->addButton(ui->Button_DLR, Qt::Key_1); ui->Button_DLR->hide();
    btnGroup_Conf->addButton(ui->Button_MAG, Qt::Key_2); ui->Button_MAG->hide();
    btnGroup_Conf->addButton(ui->Button_IR,  Qt::Key_3); ui->Button_IR->hide();
    btnGroup_Conf->addButton(ui->Button_ACW,  Qt::Key_4); ui->Button_ACW->hide();
    btnGroup_Conf->addButton(ui->Button_DCW,  Qt::Key_5); ui->Button_DCW->hide();
    btnGroup_Conf->addButton(ui->Button_IMP,  Qt::Key_6); ui->Button_IMP->hide();
    btnGroup_Conf->addButton(ui->Button_PWR,  Qt::Key_7); ui->Button_PWR->hide();
    btnGroup_Conf->addButton(ui->Button_INDL, Qt::Key_8); ui->Button_INDL->hide();
    btnGroup_Conf->addButton(ui->Button_BLOCK,  Qt::Key_9); ui->Button_BLOCK->hide();
    btnGroup_Conf->addButton(ui->Button_LVS,  58);          ui->Button_LVS->hide();
    btnGroup_Conf->addButton(ui->Button_Hall,  59);         ui->Button_Hall->hide();
    btnGroup_Conf->addButton(ui->Button_Load,  60);         ui->Button_Load->hide();
    btnGroup_Conf->addButton(ui->Button_NoLoad,  61);       ui->Button_NoLoad->hide();
    btnGroup_Conf->addButton(ui->Button_BEMF,  62);         ui->Button_BEMF->hide();
    btnGroup_Conf->addButton(ui->Button_HV,  63);         ui->Button_HV->hide();

    connect(btnGroup_Conf, SIGNAL(buttonClicked(int)), this, SLOT(SlOT_Button_Conf_Judge(int)));

    int i = 0;
    Item_Widget = new QWidget(this); // -建立弹出项目
    Item_Widget->setGeometry(450, 10, 250, 576);
    Item_Widget->setWindowFlags(Qt::WindowStaysOnTopHint);
    QStringList Item_Text, Item_Id;

    Item_Text.clear();
    Count_Item = 15;
    Item_Text << tr("取消") << tr("设置") << tr("电阻") << tr("电感") << tr("反嵌") << tr("绝缘")\
             << tr("交耐") << tr("直耐") << tr("匝间") << tr("电参")\
            << tr("堵转") << tr("低启")\
            << tr("HALL") << tr("负载") << tr("空载") << tr("BEMF")\
            << tr("搭线");
    Item_Id << tr("0") << tr("20") << tr("1") << tr("8") << tr("2") << tr("3")\
           << tr("4") << tr("5") << tr("6") << tr("7")\
          << tr("9") << tr("10")\
         << tr("11") << tr("12") << tr("13") << tr("14")\
         << tr("15");
    int position[] = {00, 10, 30, 40, 50, 60, \
                70, 80, 90, 31, \
               41, 51, \
              61, 71, 81, 91, 100};

    QGridLayout *Item_all = new QGridLayout;
    btnGroup_Item = new QButtonGroup; // -进行设置按键的增加
    for (i = 0; i < Item_Text.size(); i++) {
        Item_Putton.append(new QPushButton(this));
        btnGroup_Item->addButton(Item_Putton[i], Item_Id.at(i).toInt());
        Item_Putton[i]->setText(Item_Text.at(i));
        Item_Putton[i]->setMinimumHeight(40);
        Item_Putton[i]->setMinimumWidth(90);
        Item_all->addWidget(Item_Putton[i], position[i]/10, position[i]%10);
    }
    QVBoxLayout *hb_one = new QVBoxLayout;
    hb_one->addStretch();
    Item_all->addLayout(hb_one, 16, 0);
    QVBoxLayout *hb_two = new QVBoxLayout;
    hb_two->addStretch();
    Item_all->addLayout(hb_two, 16, 1);
    for (i = 2; i < Item_Text.size(); i++) {
        Item_Putton[i]->hide(); // 功能隐藏
    }
    connect(btnGroup_Item, SIGNAL(buttonClicked(int)), this, SLOT(SlOT_ButtonProj(int)));
    Item_Putton[0]->setStyleSheet("background-color: gray;");
    Item_Putton[1]->setStyleSheet("background-color: green;");
    QLabel *Item_Lable_padding = new QLabel;
    Item_Lable_padding->setStyleSheet("background-color: #191919;");
    Item_Lable_padding->setMinimumHeight(50);
    Item_all->addWidget(Item_Lable_padding, 2, 0);
    Item_all->setAlignment(Qt::AlignTop);
    Item_Chose_Box = new QCheckBox(this);
    Item_Chose_Box->setStyleSheet
            ("QCheckBox::indicator {image: url(:/image/053.png);"\
             "width: 50px;height: 55px;}"\
             "QCheckBox::indicator:checked {image: url(:/image/051.png);}");
    Item_Chose_Box->setChecked(false);
    connect(Item_Chose_Box, SIGNAL(stateChanged(int)), \
            this, SLOT(Item_Chose_Box_stateChanged(int)));
    Item_all->addWidget(Item_Chose_Box, 0, 1);
    Item_Widget->setStyleSheet(".QWidget{background-color: #191919;border: 2px solid #447684;}");
    Item_Widget->setLayout(Item_all);
    Item_Widget->hide();

    btnGroup_IMP_Sample = new QButtonGroup;
    btnGroup_IMP_Sample->addButton(ui->imp_button_add, 0);    ui->imp_button_add->hide();
    btnGroup_IMP_Sample->addButton(ui->imp_button_cancel, 1); ui->imp_button_cancel->hide();
    btnGroup_IMP_Sample->addButton(ui->imp_button_finsh, 2);  ui->imp_button_finsh->hide();
    connect(btnGroup_IMP_Sample, SIGNAL(buttonClicked(int)), \
            this, SLOT(SlOT_Button_IMP_Sample(int)));

    Test_Item.clear();
    Test_Item.append(tr("清除")); // 0
    Test_Item.append(tr("电阻")); // 1
    Test_Item.append(tr("反嵌")); // 2
    Test_Item.append(tr("绝缘")); // 3
    Test_Item.append(tr("交耐")); // 4
    Test_Item.append(tr("直耐")); // 5
    Test_Item.append(tr("匝间")); // 6
    Test_Item.append(tr("电参")); // 7
    Test_Item.append(tr("电感")); // 8
    Test_Item.append(tr("堵转")); // 9
    Test_Item.append(tr("低启")); // 10
    Test_Item.append(tr("HALL")); // 11
    Test_Item.append(tr("负载")); // 12
    Test_Item.append(tr("空载")); // 13
    Test_Item.append(tr("BEMF")); // 14
    Test_Item.append(tr("搭线")); // 15
    Test_Item.append(tr("PG"));  // 11

    ui->fileTab->horizontalHeader()->setStyleSheet
    ("QHeaderView::section{background-color:#191919;"\
     "color: white;padding-left: 4px;border: 1px solid #447684;}");
    ui->fileTab->horizontalHeader()->setResizeMode(QHeaderView::Fixed);
    ui->test->horizontalHeader()->setStyleSheet
    ("QHeaderView::section{background-color:#191919;"\
     "color: white;padding-left: 4px;border: 1px solid #447684;}");

    Mouse.Time = new QTimer(this);
    connect(Mouse.Time, SIGNAL(timeout()), this, SLOT(test_mouse_check()));
    Mouse.Ms = 0;  Mouse.Us = 0;
    Mouse.Flag = false;

    Conf_User = User_Operator; // -默认设置为操作员
    TabWidget_Changed = true;  // -默认设置为页面改变
    remove_row = 0;            // -移除的项目
    Quick_Set  = false;        // -默认非快速设置
    index_c    = 0;            // -当前页面的序列号, 默认为0

    parameter.clear();
    parameter.append(QString(tr("Conf")));
    parameter.append(QString(tr("DLR")));
    parameter.append(QString(tr("MAG")));
    parameter.append(QString(tr("IR")));
    parameter.append(QString(tr("ACW")));
    parameter.append(QString(tr("DCW")));
    parameter.append(QString(tr("IMP")));
    parameter.append(QString(tr("PWR")));
    parameter.append(QString(tr("INDL")));
    parameter.append(QString(tr("BLOCK")));
    parameter.append(QString(tr("LVS")));
    parameter.append(QString(tr("HALL")));
    parameter.append(QString(tr("LOAD")));
    parameter.append(QString(tr("NOLOAD")));
    parameter.append(QString(tr("BEMF")));
    parameter.append(QString(tr("HV")));

    Conf_label_Hide = new QLabel(ui->W_All);
    Conf_label_Hide->setGeometry(0, 0, 700, 600);
    Conf_label_Hide->hide();

    conf_Waring = false;
    label_Waring = new QLabel(this);
    label_Waring->setGeometry(0, 0, 800, 600);
    label_Waring->hide();

    Beep.Time = new QTimer(this);
    connect(Beep.Time, SIGNAL(timeout()), this, SLOT(beep_stop()));
    Beep.Flag = false;

    QString path = ("/mnt/nandflash/AIP/Model/"); // -读取全部型号, 建立文件类型列表--model_Type
    QDir *dir = new QDir(path);
    QStringList filter;   filter << "*.jpg";
    QString FileName;
    QString FileNameInter;
    dir->setNameFilters(filter);
    QList<QFileInfo> *fileInfo = new QList<QFileInfo>(dir->entryInfoList(filter));
    ui->MotorType->clear();
    for (i = 0; i < fileInfo->count(); i++) {
        FileName = fileInfo->at(i).fileName();
        FileNameInter = FileName.mid(0, FileName.indexOf("."));
        ui->MotorType->addItem(FileNameInter, i);
        model_Type.append(FileNameInter);
    }

//    FILE *SD_Exist;
//    SD_Exist = fopen("/dev/mmcblk0", "r"); // 查看SD卡是否进行挂载
//    if (SD_Exist != NULL) {
//        sdcard_exist = true;
//        sql.openSql("/mnt/sdcard/aip.db"); // 打开 sdcard 数据库
//    } else {
//        sdcard_exist = false;
//        sql.openSql("/mnt/nandflash/aip.db"); // 打开 nandflash 数据库
//    }

    same_ip_address = false;
    NetSQL_OpenOk = false;
    // if (Get_Ip_Address()) // 判断IP是否处在同一个网段
    {
        same_ip_address = true;
    }
    isopend = false;

    label_Set = new QLabel(this);
    label_Set->setGeometry(720, 10, 66, 571);
    label_Set->setText(tr("设\n置\n中\n，\n请\n稍\n候"));
    label_Set->setStyleSheet("color: white;font: Bold  30pt Ubuntu;");
    label_Set->setAlignment(Qt::AlignCenter);
    label_Set->hide();

    lable_Zero = new QLabel(this);
    lable_Zero->setGeometry(0, 0, 800, 600);
    lable_Zero->setStyleSheet("color: white;font: Bold  30pt Ubuntu;");
    lable_Zero->setText(tr("正在清零，请稍后"));
    lable_Zero->setAlignment(Qt::AlignCenter);
    lable_Zero->hide();

    Quick_Set_UI();

    Ini_Power_Chose = 0;    // -功率板的电源初始化为0
    Ini_Mag_Hide    = 0;
    Ini_Udp_Enable  = false;
    Ini_ACW_And_IR  = false;
    Ini_System.clear();
    Ini_Number = 0;
    Ini_Proj_Real.clear();
    Ini_Proj.clear();

    SQL_Init = true;
    SQL_Widget = new QWidget(this);
    SQL_Widget->setGeometry(150, 100, 500, 400);
    SQL_Widget->setWindowFlags(Qt::WindowStaysOnTopHint);
    SQL_Widget->setStyleSheet
    ("border-radius: 10px;padding:2px 4px;background-color: gray;"\
     "color: black;border-color: black;");
    QGridLayout *SQL_upside = new QGridLayout;
    QString SQL_table[5]={tr("生产线:"), tr("生产任务号:"), \
                          tr("计划数量:"), tr("生产部门:"), tr("产品型号:")};
    for (i = 0; i < 5; i++) {
        SQL_lable.append(new QLabel(this));
        SQL_lable[i]->setText(SQL_table[i]);
        SQL_lable[i]->setMaximumHeight(35); SQL_lable[i]->setMaximumWidth(135);
        SQL_lable[i]->setAlignment(Qt::AlignCenter);
        SQL_upside->addWidget(SQL_lable[i], i, 0);
        if (i > 1) {
            SQL_Line_Text.append(new QLineEdit(this));
            SQL_Line_Text[i-2]->setMaximumHeight(35);      SQL_Line_Text[i-2]->setMaximumWidth(255);
            SQL_upside->addWidget(SQL_Line_Text[i-2], i, 1);
        }
    }
    SQL_Produce_Plan = new QComboBox(this);
    SQL_Produce_Plan->setMaximumHeight(35); SQL_Produce_Plan->setMaximumWidth(255);
    SQL_upside->addWidget(SQL_Produce_Plan, 0, 1);
    connect(SQL_Produce_Plan, SIGNAL(currentIndexChanged(const QString &)), \
            this, SLOT(SQL_Produce_Plan_textChanged(const QString &)));
    SQL_Produce_Number = new QComboBox(this);
    SQL_Produce_Number->setMaximumHeight(35); SQL_Produce_Number->setMaximumWidth(255);
    SQL_upside->addWidget(SQL_Produce_Number, 1, 1);
    connect(SQL_Produce_Number, SIGNAL(currentIndexChanged(const QString &)), \
            this, SLOT(SQL_Produce_Number_textChanged(const QString &)));
    QPushButton *button_quit_SQL = new QPushButton;
    button_quit_SQL->setText(tr("退出"));
    button_quit_SQL->setMinimumHeight(50);
    button_quit_SQL->setMinimumWidth(90);
    button_quit_SQL->setStyleSheet("background: qlineargradient"\
                                   "(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #5B5F5F, "\
                                   "stop: 0.5 #0C2436,stop: 1 #27405A);");
    SQL_upside->addWidget(button_quit_SQL, 0, 5);
    connect(button_quit_SQL, SIGNAL(clicked()), this, SLOT(SQL_Widget_autoquit()));
    QVBoxLayout *Histogram_Widget_layout_SQL = new QVBoxLayout;
    Histogram_Widget_layout_SQL->addLayout(SQL_upside);
    SQL_Widget->setLayout(Histogram_Widget_layout_SQL);
    SQL_Widget->hide();
    SQL_Init = false;

    PWR_Test_Usart = false;

    strTest.clear();  // -测试项目清除
    strParam.clear(); // -测试参数清除

    Result_indl.dat[0] = 0;
    Result_indl.dat[1] = 0;
    Result_indl.dat[2] = 0;
    Result_indl.dat[3] = 0;

    Quick_set_IRACW_Value = true;
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      析构
******************************************************************************/
w_Conf::~w_Conf()
{
    delete btnGroup_function;
    delete ui;
}

void w_Conf::Quick_Set_UI() {
    int i;
    Quick_Set_Widget = new QWidget(this);
    Quick_Set_Widget->setGeometry(225, 150, 350, 310);
    Quick_Set_Widget->setWindowFlags(Qt::WindowStaysOnTopHint);
    Quick_Set_Widget->setStyleSheet\
            (".QWidget{border-radius: 10px;padding:2px 4px;background-color: gray;"\
             "color: black;border-color: black;}");
    QGridLayout *Quick_Set_upside = new QGridLayout;
    Quick_Set_upside->setSpacing(20);
    QString Quick_Set_table[3]={QString(tr("匝间电压:")), \
                         QString(tr("标准接线:")), QString(tr("工位:"))}; //
    for (i = 0; i < 3; i++) {
        Quick_Set_Show_Lable.append(new QLabel(this));
        Quick_Set_Show_Lable[i]->setText(Quick_Set_table[i]);
        Quick_Set_Show_Lable[i]->setMaximumHeight(35);
        Quick_Set_Show_Lable[i]->setMaximumWidth(135);
        Quick_Set_Show_Lable[i]->setAlignment(Qt::AlignCenter);
        Quick_Set_upside->addWidget(Quick_Set_Show_Lable[i], i, 0);
    }

    Quick_Set_DoubleSpinBox.append(new QDoubleSpinBox(this));
    Quick_Set_DoubleSpinBox[0]->setMaximumHeight(35);
    Quick_Set_DoubleSpinBox[0]->setMaximumWidth(255);
    Quick_Set_DoubleSpinBox[0]->setMaximum(3000);
    Quick_Set_DoubleSpinBox[0]->setMinimum(500);
    Quick_Set_DoubleSpinBox[0]->setDecimals(0);
    Quick_Set_DoubleSpinBox[0]->setValue(1800);
    Quick_Set_upside->addWidget(Quick_Set_DoubleSpinBox[0], 0, 1);

    Quick_Set_Standard = new QCheckBox;
    Quick_Set_Standard->setText(tr(""));
    Quick_Set_Standard->setStyleSheet\
            ("QCheckBox::indicator {image: url(:/image/053.png);width: 55px;"\
             "height: 45px;}QCheckBox::indicator:checked { image: url(:/image/051.png); }"\
             "QCheckBox  { color: rgb(0, 0, 0);}");
    Quick_Set_Standard->setChecked(true);
    Quick_Set_upside->addWidget(Quick_Set_Standard, 1, 1);


    QPushButton *Quick_Set_Show_quit = new QPushButton;
    Quick_Set_Show_quit->setText(tr("退出"));
    Quick_Set_Show_quit->setMinimumHeight(50);
    Quick_Set_Show_quit->setMinimumWidth(90);
    Quick_Set_Show_quit->setStyleSheet\
            ("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"\
             "stop: 0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);");
    Quick_Set_upside->addWidget(Quick_Set_Show_quit, 0, 2);
    connect(Quick_Set_Show_quit, SIGNAL(clicked()), this, SLOT(Quick_Set_autoquit()));

    Station_Chose_Group = new QButtonGroup(this);
    QString Station_QRadioPutton_table[2]={QString(tr("左工位")), \
                         QString(tr("右工位"))}; //
    for (i = 0; i < 2; i++) {
       Station_QRadioPutton.append(new QRadioButton(this));
       Station_QRadioPutton[i]->setText(Station_QRadioPutton_table[i]);
       Station_QRadioPutton[i]->setMinimumHeight(40);
       Station_QRadioPutton[i]->setMinimumWidth(90);
       Station_QRadioPutton[i]->setStyleSheet\
               ("QRadioButton::indicator {image: url(:/image/1.png);width: 55px;"\
                "height: 45px;}QRadioButton::indicator:checked { image: url(:/image/2.png); }"\
                "QRadioButton  { color: rgb(0, 0, 0);}");
       Station_Chose_Group->addButton(Station_QRadioPutton[i], i);
       Quick_Set_upside->addWidget(Station_QRadioPutton[i], 2 + i, 1);
    }
    Station_QRadioPutton[0]->setChecked(true);
    Right_Test = 19;
    connect(Station_Chose_Group, SIGNAL(buttonClicked(int)), \
            this, SLOT(ModeButtonsToggled(int)));


    Quick_Set_Show_join = new QPushButton;
    Quick_Set_Show_join->setText(tr("快速设置"));
    Quick_Set_Show_join->setMinimumHeight(50);
    Quick_Set_Show_join->setMinimumWidth(90);
    Quick_Set_Show_join->setStyleSheet\
            ("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"\
             "stop: 0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);");
    Quick_Set_upside->addWidget(Quick_Set_Show_join, 1, 2);
    connect(Quick_Set_Show_join, SIGNAL(clicked()), this, SLOT(Quick_Set_Show_join_Clicked()));

    QVBoxLayout *Histogram_Quick_Set_Widget_layout = new QVBoxLayout;
    Histogram_Quick_Set_Widget_layout->addLayout(Quick_Set_upside);
    Quick_Set_Widget->setLayout(Histogram_Quick_Set_Widget_layout);
    Quick_Set_Widget->hide();
}

void w_Conf::Quick_Set_autoquit() {
    Quick_Set_Widget->hide();
    label_Waring->hide();
}

void w_Conf::Quick_Set_Show_join_Clicked() {
    Quick_Set_Widget->hide();
    label_Waring->hide();
    Quick_Set_Function();
}

void w_Conf::ModeButtonsToggled(int Test_a) {
    if (Test_a) {
        Right_Test = 20;
    } else {
        Right_Test = 19;
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.1.15
  * brief:      获取ip地址，并且与数据库ip做对比
******************************************************************************/
int w_Conf::Get_Ip_Address()
{
    int sock_get_ip = 0;
    int i = 0;
    bool ip_same = 0;
    char ipaddr[50];
    struct sockaddr_in *sin;
    struct ifreq ifr_ip;
    if  ((sock_get_ip=socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        //
    } else {
        //
    }
    memset(&ifr_ip, 0, sizeof(ifr_ip));
    strncpy(ifr_ip.ifr_name, "eth0", sizeof(ifr_ip.ifr_name) - 1);
    if (ioctl(sock_get_ip, SIOCGIFADDR, &ifr_ip) < 0) {
        //
    }
    sin = (struct sockaddr_in *)&ifr_ip.ifr_addr;
    strcpy(ipaddr, inet_ntoa(sin->sin_addr));
    QStringList ip_split = QString(ipaddr).split(".");

    QSettings set_odbc("/usr/local/arm/unixODBC/etc/odbc.ini", QSettings::IniFormat); // 数据库 ip
    QString sql_net_ip = set_odbc.value("testodbc/Server", "1,1,1,1").toString();
    QStringList sql_net_ip_split = QString(sql_net_ip).split(".");

    for (i = 0; i < sql_net_ip_split.size() - 1; i++) {
        if (ip_split.at(i) == sql_net_ip_split.at(i)) {
            ip_same = 1;
        } else {
            ip_same = 0;
            break;
        }
    }
    return ip_same;
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.5.1
  * brief:      处理鼠标被按下事件
******************************************************************************/
void w_Conf::mousePressEvent(QMouseEvent *event)
{
    handleMousePressEvent(event);
    Item_Widget->hide();
    Conf_label_Hide->hide();
    Mouse.Ms = 0;    Mouse.Us = 0;
    Mouse.Time->start(1);
    Mouse.Flag = false;
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.5.1
  * brief:      处理鼠标离开事件
******************************************************************************/
void w_Conf::mouseReleaseEvent(QMouseEvent *event)
{
    Mouse.Time->stop();
    if ((Mouse.Ms >= 2) && (!conf_Waring)) {
        Singal_Conf_to_Main(QStringList(""), QString(""), wHelp_Surface, 2);
    }
    Mouse.Ms = 0;    Mouse.Us = 0;
    Mouse.Flag = false;
    event->x();
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.5.1
  * brief:      长按计时功能
******************************************************************************/
void w_Conf::test_mouse_check()
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
  * date:       2017.7.19
  * brief:      点击页面操作
******************************************************************************/
bool w_Conf::handleMousePressEvent(QMouseEvent *event)
{
    QPoint topLeftUser(0, 30); // left top
    QPoint rightBottomUser(711, 600);
    QRect  rectUser(topLeftUser, rightBottomUser);
    if (rectUser.contains(event->pos())) {
        if ((Conf_User == User_Operator) && (!conf_Waring)) {
            Pri_Conf_WMessage(tr("         当前用户模式为操作员     \n"\
                                 "无权限进行保存和修改       "));
        }
    }
    return true;
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.5.1
  * brief:      蜂鸣器停止
******************************************************************************/
void w_Conf::beep_stop()
{
    Beep_PWM_Stop();
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.5.31
  * brief:      蜂鸣器的报警状态
******************************************************************************/
void w_Conf::Beep_State()
{
    if (Beep.Flag) {
        return;
    }
    Beep.Flag = true;
    Beep.Time->setSingleShot(TRUE);  Beep.Time->start(80);   Beep_PWM_Start(99);
    Beep.Flag = false;
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.5.31
  * brief:      匝间进行采样 (多样品采集)
******************************************************************************/
void w_Conf::SlOT_Button_IMP_Sample(int id)
{
    if (Conf_User == User_Operator) {
        Pri_Conf_WMessage(tr("          当前用户模式为操作员     \n"\
                             "无权限进行保存和修改       "));
    } else {
        WIMP->Pub_Conf_GetSample(id);
        if (id == 2) {
            SlOT_Button_Function_Judge(Qt::Key_B);
        } else {
            //
        }
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.5.10
  * brief:      可选项目 按键功能   //  已屏蔽
******************************************************************************/
void w_Conf::SlOT_ButtonProj(int id)
{
    int i = 0;
    qDebug() << "w_Conf::SlOT_ButtonProj";
    Item_Widget->hide();
    Conf_label_Hide->hide();
    if (remove_row < (test_Inifile.size())) {
        switch (id) {
        case 0:  // -清除
            test_Inifile.removeAt(remove_row);
            break;
        case 20: // -设置
            SlOT_Button_Conf_Judge(test_Inifile.at(remove_row).toInt()+48);
            break;
        default: // -取代  (电阻 反嵌 绝缘 交耐 直耐 匝间 电参 电感 堵转 低启)
            test_Inifile.replace(remove_row, (QString::number(id)));
            break;
        }
    } else {
        if ((id != 0) && (id != 20)) { // -去除(清除和取消)
            test_Inifile.append(QString::number(id));
        }
    }

    QSettings set_Test_File(Test_File_path, QSettings::IniFormat);
    set_Test_File.setIniCodec("UTF-8");
    QString   name_list;
    name_list = QString("Test_File/%1").arg(Ini_ActiveFile);
    set_Test_File.setValue(name_list, test_Inifile);

    ui->test->setRowCount(0);
    ui->test->setGeometry(305, 20, 131, 39*14 + (ui->test->horizontalHeader()->height()));
    ui->test->setRowCount(13);
    for (i = 0; i < 13; i++) {
        ui->test->setRowHeight(i, 39);
    }
    Init_test_TableWidget(); // -初始化测试项目

    for (i = 1; i <= Count_Item; i++) { // -设置显示, 锁定端子号
        btnGroup_Item->button(i)->hide();
    }
    btnGroup_Item->button(0)->show();
    btnGroup_Item->button(20)->show();

    for (i = 1; i < Ini_Proj.size(); i++) {
        btnGroup_Item->button(Ini_Proj.at(i).toInt())->show();
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      在操作页面获取焦点
******************************************************************************/
void w_Conf::Usart_GetFcous()
{
    switch (index_c) {
    case 0:
        //
        break;
    case 1:
        WDLR->Pub_Conf_Set_DLR("", 8);
        break;
    case 2:
        WMAG->Pub_Conf_Set_MAG("", 8);
        break;
    case 3:
        //
        break;
    case 4:
        //
        break;
    case 5:
        //
        break;
    case 6:
        WIMP->Pub_Conf_Set_IMP("", 9);
        break;
    case 7:
        //
        break;
    case 8:
        //
        break;
    case 9:
        //
        break;
    case 10:
        //
        break;
    case 11: // 霍尔
        //
        break;
    case 12: // 负载
        //
        break;
    case 13: // 空载
        //
        break;
    case 14: // 反电动势
        //
        break;
    case 15: // HV
        //
        break;
    default:
        //
        break;
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.5.10
  * brief:      进入测试项目的设置界面
******************************************************************************/
void w_Conf::SlOT_Button_Conf_Judge(int id)
{
    if (((id - 48) != index_c) && (!Quick_Set)) {
        Save_Hint();
    }
    ui->Key_A->show();      ui->Key_B->setText(tr("测试主页"));
    ui->Key_B->show();      ui->Key_B->setText(tr("保存设置"));
    ui->Button_ALL->show(); ui->Button_ALL->setText(tr("设置首页"));
    ui->Key_C->hide();
    ui->Key_D->hide();
    ui->Key_E->hide();      ui->Key_E->setText("补偿");
    ui->Key_D->setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"\
                        "stop: 0 #5B5F5F, stop: 0.5 #0C2436,"\
                             "stop: 1 #27405A); color:rgb(255, 255, 255);");
    ui->Key_E->setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"\
                        "stop: 0 #5B5F5F, stop: 0.5 #0C2436,"\
                             "stop: 1 #27405A); color:rgb(255, 255, 255);");
    switch (id) {
    case Qt::Key_0:
        ui->label_User->setGeometry(299, 0, 401, 600);
        ui->stackedWidget->setCurrentIndex(0);
        ui->imp_button_add->hide();
        ui->imp_button_cancel->hide();
        ui->imp_button_finsh->hide();
        ui->Button_ALL->hide();
        ui->Key_C->show();   ui->Key_C->setText(tr("快速设置"));
        break;
    case Qt::Key_1: // -电阻
        WDLR->Pub_Conf_Set_DLR(QString::number(Out_Channel_6), 100);
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(WDLR));
        ui->Key_D->show();  ui->Key_D->setText(tr("左清零"));
        ui->Key_E->show();  ui->Key_E->setText(tr("右清零"));
        if (WDLR->DLR_Compensate_Left) {
            ui->Key_D->setStyleSheet("background:#00FF00;color:rgb(0, 0, 0);");
            ui->Key_D->setText(tr("左OK")); // -已清零
        } else {
            ui->Key_D->setText(tr("左清零")); // -未清零
        }

        if (WDLR->DLR_Compensate_Right) {
            ui->Key_E->setStyleSheet("background:#00FF00;color:rgb(0, 0, 0);");
            ui->Key_E->setText(tr("右OK")); // -已清零
        } else {
            ui->Key_E->setText(tr("右清零")); // -未清零
        }
        WDLR->Pub_Conf_Set_DLR(ui->MotorType->currentText(), 14);
        break;
    case Qt::Key_2: // -反嵌
        if (WMAG != NULL) {
            WMAG->Pub_Conf_Set_MAG(QString::number(Out_Channel_6), 100);
            ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(WMAG));
            Board_DLR = 1;
            if (Ini_IO_Model == WL_Hall) {
                //
            } else if (Ini_IO_Model == ME_Hall) {
                //
            } else if (Ini_IO_Model == NEW_Hall) {
                //
            } else {
                ui->Key_D->show();  ui->Key_D->setText(tr("采集"));
            }
            WMAG->Pub_Conf_Set_MAG("", 9);
            WMAG->Pub_Conf_Set_MAG(ui->MotorType->currentText(), 14);
            break;
        } else if (WPWR != NULL) {
            id = 0x37;
            ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(WPWR));
            WPWR->setFocus();
            break;
        } else {
            //
        }
        break;
    case Qt::Key_3: // -绝缘
        if (Quick_set_IRACW_Value) {
            if (test_Inifile.indexOf("3") == remove_row) {
                WIR->Pub_Conf_Set_IR("0", 101); // 第一项目
            } else {
                WIR->Pub_Conf_Set_IR("2", 101); // 第二项目
            }
        } else {
            //
        }


        WIR->Pub_Conf_Set_IR(QString::number(Out_Channel_6), 100);
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(WIR));
        if (Ini_ACW_And_IR) {
            ui->Key_E->hide();
        } else {
            ui->Key_E->show();
        }

        if (WIR->IR_Back_Key_E()) {
            ui->Key_E->setStyleSheet("background:#00FF00;color:rgb(0, 0, 0);");
            ui->Key_E->setText(tr("已补偿"));
        } else {
            ui->Key_E->setText(tr("未补偿"));
        }
        break;
    case Qt::Key_4: // -交耐
        if (Quick_set_IRACW_Value) {
            if (test_Inifile.indexOf("4") == remove_row) {
                WACW->Pub_Conf_Set_ACW("0", 103); // 第一项目
            } else {
                WACW->Pub_Conf_Set_ACW("2", 103); // 第二项目
            }
        } else {
            //
        }

        WACW->Pub_Conf_Set_ACW(QString::number(Out_Channel_6), 100);
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(WACW));
        if (Ini_ACW_And_IR) {
            ui->Key_E->hide();
        } else {
            ui->Key_E->show();
        }

        if (WACW->ACW_Back_Key_E()) {
            ui->Key_E->setStyleSheet("background:#00FF00;color:rgb(0, 0, 0);");
            ui->Key_E->setText(tr("已补偿"));
        } else {
            ui->Key_E->setText(tr("未补偿"));
        }
        break;
    case Qt::Key_5: // -直耐
        WDCW->Pub_Conf_Set_DCW(QString::number(Out_Channel_6), 100);
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(WDCW));
        if (Ini_ACW_And_IR) {
            ui->Key_E->hide();
        } else {
            ui->Key_E->show();
        }

        if (WDCW->DCW_Back_Key_E()) {
            ui->Key_E->setStyleSheet("background:#00FF00;color:rgb(0, 0, 0);");
            ui->Key_E->setText(tr("已补偿"));
        } else {
            ui->Key_E->setText(tr("未补偿"));
        }
        break;
    case Qt::Key_6: // -匝间
        WIMP->Pub_Conf_Set_IMP(QString::number(Out_Channel_6), 100);
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(WIMP));
        if (Ini_IMP_36 == 2) {
            WIMP->Pub_Conf_Set_IMP(ui->MotorType->currentText(), 3);
        } else {
            WIMP->Pub_Conf_Set_IMP(" ", 3);
        }
        ui->Key_D->show(); ui->Key_D->setText(tr("采集"));
        ui->imp_button_add->show();
        ui->imp_button_cancel->show();
        ui->imp_button_finsh->show();
        break;
    case Qt::Key_7:
        WPWR->Pub_Conf_Set_PWR(QStringList(""), QString::number(Out_Channel_6), 100);
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(WPWR));
        WPWR->setFocus();
        break;
    case Qt::Key_8:
        WINDL->Pub_Conf_Set_INDL(QString::number(Out_Channel_6), 100, 100);
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(WINDL));
        WINDL->setFocus();
        break;
    case Qt::Key_9:
        WBLOCK->Pub_Conf_Set_BLOCK(QString::number(Out_Channel_6), 100, 100);
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(WBLOCK));
        WBLOCK->setFocus();
        WBLOCK->Pub_Conf_Set_BLOCK("", 1, 6);
        break;
    case 58:
        WLVS->Pub_Conf_Set_LVS(QString::number(Out_Channel_6), 100);
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(WLVS));
        WLVS->setFocus();
        break;
    case 59: // 霍尔
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(WPG));
        WPG->setFocus();
        break;
    case 60: // 负载
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(WLOAD));
        WLOAD->setFocus();
        break;
    case 61: // 空载
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(WNoLoad));
        WNoLoad->setFocus();
        break;
    case 62: // 反电动势
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(WBEMF));
        WBEMF->setFocus();
        break;
    case 63: // 高压
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(WHV));
        WHV->setFocus();
        break;
    default:
        ui->Key_C->show();
        ui->stackedWidget->setCurrentIndex(0);
        break;
    }
    if (Quick_Set) {
        ui->Key_A->hide();
        ui->Key_B->hide();
        ui->Key_C->hide();
        ui->Key_D->hide();
        ui->Key_E->hide();
        ui->imp_button_add->hide();
        ui->imp_button_cancel->hide();
        ui->imp_button_finsh->hide();
        ui->Button_ALL->hide();
    }
    qApp->processEvents();
    index_c = (id - 48)%16; // -获取保存序列号-16
    TabWidget_Changed = true;
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      配置页面的键盘操作
******************************************************************************/
void w_Conf::Usart_Button(int Usart_number)
{
    if (Usart_number == 26) {
        SlOT_Button_Function_Judge(Qt::Key_A);
    } else if (Usart_number == 27) {
        SlOT_Button_Function_Judge(Qt::Key_B);
    } else if (Usart_number == 24) {
        switch (index_c) {
        case 0:
            SlOT_Button_Function_Judge(Qt::Key_C);
            break;
        case 1:
            SlOT_Button_Function_Judge(Qt::Key_E);
            break;
        case 2:
            SlOT_Button_Function_Judge(Qt::Key_D);
            break;
        case 3:
            SlOT_Button_Function_Judge(Qt::Key_E);
            break;
        case 4:
            SlOT_Button_Function_Judge(Qt::Key_E);
            break;
        case 5:
            //
            break;
        case 6:
            SlOT_Button_Function_Judge(Qt::Key_D);
            break;
        case 7:
            //
            break;
        case 8:
            //
            break;
        case 9:
            //
            break;
        case 10:
            //
            break;
        case 11: // 霍尔
            //
            break;
        case 12: // 负载
            //
            break;
        case 13: // 空载
            //
            break;
        case 14: // 反电动势
            //
            break;
        case 15: // 高压
            //
            break;
        default:
            //
            break;
        }
    } else if (Usart_number == 25) {
        SlOT_Button_Conf_Judge(Qt::Key_0);
    } else {
       //
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2015.12.30
  * brief:      颜色设置
******************************************************************************/
void w_Conf::SlOT_Button_Color_Judge(int id)
{
    if (id >= 12) {
        return;
    }
    iColorBtn = id;
    Singal_Conf_to_Main(QStringList(""), QString(""), wColr_Surface, 2);
}

void w_Conf::PC_Test_Param_connect() {
    QStringList netdata;
    QStringList strParam_c;
    strParam_c.clear();
    netdata.clear();
    netdata.append(strTest);
    strParam_c = strParam;
    for (int i = 0; i < strParam.size(); i++) {
        strParam_c.replace(i, QString(strParam_c.at(i)).replace(QRegExp("\\,"), " "));
    }
    netdata.append(strParam_c);
    PC_Test_Param_Data(netdata);
}

void w_Conf::PWR_DCR_bound_Item() {
    int i;
    if (Ini_DCR_Cancle) {
       return;
    } else {
        //
    }
    /*判断是否存在功率的测试项目，若存在在功率前添加电阻*/
    if ((test_Inifile.contains(tr("7"))) || \
            (test_Inifile.contains(tr("9"))) || \
            (test_Inifile.contains(tr("10")))|| \
            (test_Inifile.contains(tr("13")))) {
        Exist_Pwr = true;
        WDLR->Pub_Conf_Set_DLR("0", 4); // -WDLR->DLR_TestNumber的总数
        if ((test_Inifile.indexOf(tr("1"))) == 0) {
            //
        } else {
            test_Inifile.removeAt(test_Inifile.indexOf(tr("1")));
            test_Inifile.insert(0, "1");
            QSettings set_Test_File(Test_File_path, QSettings::IniFormat);
            set_Test_File.setIniCodec("UTF-8");
            QString   name_list;
            name_list = QString("Test_File/%1").arg(Ini_ActiveFile);
            set_Test_File.setValue(name_list, test_Inifile);

            ui->test->setRowCount(0);
            ui->test->setGeometry(305, 20, 131, 39*14+(ui->test->horizontalHeader()->height()));
            ui->test->setRowCount(13);
            for (i = 0; i < 13; i++) {
                ui->test->setRowHeight(i, 39);
            }
            Init_test_TableWidget();
            qApp->processEvents(); // 立即显示生效
        }
        if ((test_Inifile.contains(tr("1")))) {
            if (WDLR->DLR_TestNumber == 0) {
                WDLR->Pub_Conf_Set_DLR("", 12);
                WDLR->Pub_Conf_Set_DLR("", 3);
                RES = WDLR->Copy_DLR_List;
                QSettings set_Test_File(Test_File_path, QSettings::IniFormat);
                set_Test_File.setIniCodec("UTF-8");
                QString   name_list;
                name_list = QString("Test_File/%1").arg(Ini_ActiveFile);
                set_Test_File.setValue(name_list, test_Inifile);

                ui->test->setRowCount(0);
                ui->test->setGeometry(305, 20, 131, 39*14 + \
                                      (ui->test->horizontalHeader()->height()));
                ui->test->setRowCount(13);
                for (i = 0; i < 13; i++) {
                    ui->test->setRowHeight(i, 39);
                }
                Init_test_TableWidget();
                qApp->processEvents(); // 立即显示生效
            }
        } else if (WDLR != NULL) {
            test_Inifile.insert(0, "1");
            WDLR->Pub_Conf_Set_DLR("", 12);
            WDLR->Pub_Conf_Set_DLR("", 3);
            RES = WDLR->Copy_DLR_List;
            QSettings set_Test_File(Test_File_path, QSettings::IniFormat);
            set_Test_File.setIniCodec("UTF-8");
            QString   name_list;
            name_list = QString("Test_File/%1").arg(Ini_ActiveFile);
            set_Test_File.setValue(name_list, test_Inifile);

            ui->test->setRowCount(0);
            ui->test->setGeometry(305, 20, 131, 39*14+(ui->test->horizontalHeader()->height()));
            ui->test->setRowCount(13);

            for (i = 0; i < 13; i++) {
                ui->test->setRowHeight(i, 39);
            }

            Init_test_TableWidget();
            qApp->processEvents();
        } else {
            //
        }
        ui->test->item((test_Inifile.indexOf(tr("1"))), 0)->setTextColor(QColor("green"));
    }
}

void w_Conf::FG_bound_Item() {
    int i = 0;
    if (test_Inifile.contains(tr("11"))) {
        // (0  空载) (1  负载) (2  BEMF)
        // (13 空载) (12 负载) (14 BEMF)
        switch (WPG->Copy_BLDCPG_List.at(3).toInt()) {
        case 0:
            if (Ini_Proj.contains(tr("13"))) {
                test_Inifile.removeAt(test_Inifile.indexOf(tr("13")));
                test_Inifile.insert(test_Inifile.indexOf(tr("11")), QString(tr("13")));
            } else {
                test_Inifile.removeAt(test_Inifile.indexOf(tr("11"))); // 删除ＦＧ
            }
            break;
        case 1:
            if (Ini_Proj.contains(tr("12"))) {
                test_Inifile.removeAt(test_Inifile.indexOf(tr("12")));
                test_Inifile.insert(test_Inifile.indexOf(tr("11")), QString(tr("12")));
            } else {
                test_Inifile.removeAt(test_Inifile.indexOf(tr("11"))); // 删除ＦＧ
            }
            break;
        case 2:
            if (Ini_Proj.contains(tr("14"))) {
                test_Inifile.removeAt(test_Inifile.indexOf(tr("14")));
                test_Inifile.insert(test_Inifile.indexOf(tr("11")), QString(tr("14")));
            } else {
                test_Inifile.removeAt(test_Inifile.indexOf(tr("11"))); // 删除ＦＧ
            }
            break;
        default:
            break;
        }

        QSettings set_Test_File(Test_File_path, QSettings::IniFormat);
        set_Test_File.setIniCodec("UTF-8");
        QString name_list;
        name_list = QString("Test_File/%1").arg(Ini_ActiveFile);
        set_Test_File.setValue(name_list, test_Inifile);

        ui->test->setRowCount(0);
        ui->test->setGeometry(305, 20, 131, 39*14 + (ui->test->horizontalHeader()->height()));
        ui->test->setRowCount(13);
        for (i = 0; i < 13; i++) {
            ui->test->setRowHeight(i, 39);
        }
        Init_test_TableWidget();
        if ((test_Inifile.indexOf(tr("1"))) >= 0) {
            ui->test->item((test_Inifile.indexOf(tr("1"))), 0)->setTextColor(QColor("green"));
        } else {
            //
        }
        qApp->processEvents(); // 立即显示生效

    } else {
        //
    }
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      按钮功能-功能选择 （测试主页 保存设置 快速设置 采集波形 补偿）
******************************************************************************/
void w_Conf::SlOT_Button_Function_Judge(int id)
{
    int i = 0;
    bool  IR_Test_First;
    bool  ACW_Test_First;
    IR_Test_First = false;
    ACW_Test_First = false;
    Exist_Pwr = false;
    switch (id) {
    case Qt::Key_A: {
        if (Conf_User == User_Administrators) { // -管理员(进行保存提示)
            Save_Hint();
        }
        TabWidget_Changed = true;

        PWR_DCR_bound_Item();
        FG_bound_Item();

        for (i = 0; i < test_Inifile.size(); i++) {
            switch (test_Inifile[i].toInt()) {
            case 1:
                qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_ATest---> RES ";
                WDLR->Pub_Conf_Set_DLR("0", 4);
                break;
            case 2:
                qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_ATest---> Test OPP ";
                WMAG->Pub_Conf_Set_MAG(" ", 7);
                break;
            case 3:
                qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_ATest---> Test INS ";
                if (IR_Test_First) {
                    WIR->Pub_Conf_Set_IR(QString::number(Ini_IRHostJudge), 102);
                } else {
                    WIR->Pub_Conf_Set_IR(QString::number(Ini_IRHostJudge), 5);
                }
                IR_Test_First = true;
                break;
            case 4:
                qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_ATest---> Test ACV ";

                if (ACW_Test_First) {
                    WACW->Pub_Conf_Set_ACW(" ", 102);
                } else {
                    WACW->Pub_Conf_Set_ACW(" ", 5);
                }
                ACW_Test_First = true;
                break;
            case 5:
                qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_ATest---> Test DCV ";
                WDCW->Pub_Conf_Set_DCW(" ", 5);
                break;
            case 6:
                qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_ATest---> Test_IMP ";
                break;
            case 7:
                qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_ATest---> Test_PWR ";
                WPWR->Pub_Conf_Set_PWR(QStringList(""), "0", 3);
                break;
            case 8:
                qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_ATest---> Test_INDL";
                WINDL->Pub_Conf_Set_INDL("0", 1, 3);
                break;
            case 9:
                qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_ATest---> Test_BLOCK";
                break;
            case 10:
                qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_ATest---> Test_LVS";
                WLVS->Pub_Conf_Set_LVS("0", 3);
                break;
            case 11:
                qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_ATest---> Test_PG";
                break;
            case 12:
                qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_ATest---> Test_LOAD";
                break;
            case 13:
                qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_ATest---> Test_NOLOAD";
                break;
            case 14:
                qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_ATest---> Test_BEMF";
                break;
            case 15:
                qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_ATest---> Test HV ";
                WHV->Pub_Conf_Set_HV(" ", 5);
                break;
            default:
                //
                break;
            }
        }
        Sync_Test_Widget();
        QStringList Main_Data; Main_Data.clear();
        Main_Data.append(Ini_ActiveFile);
        Main_Data.append(QString::number(Test_Occur_Debug));
        Main_Data.append(serial_number);
        Main_Data.append(SQL_Line_Text.at(0)->text());
        Main_Data.append(QString::number(Exist_Pwr));
        Main_Data.append(QString::number(strTest.size()));
        Main_Data.append(QString::number(strParam.size()));
        Main_Data.append(strTest);
        Main_Data.append(strParam);
        PC_Test_Param_connect();
        Singal_Conf_to_Main(Main_Data, QString(""), wTest_Surface, 1);
        break;
    }
    case Qt::Key_B:
        Beep_State(); // -蜂鸣器提醒
        if (Conf_User == User_Operator) {
            Pri_Conf_WMessage(tr("          当前用户模式为操作员     \n"\
                                 "无权限进行保存和修改       "));
            break;
        }
        qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_B";
        TabWidget_Changed = false;

        switch (Ini_Proj.at(ui->stackedWidget->currentIndex()).toInt()) {
        case 0:
            qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_B  CONF";
            Save_ConfData();
            conf_c = CONF;
            break;
        case 1:
            qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_B  RES";
            WDLR->Pub_Conf_Set_DLR("", 3);
            RES = WDLR->Copy_DLR_List;
            break;
        case 2:
            qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_B  OPP";
            WMAG->Pub_Conf_Set_MAG("", 2);
            OPP = WMAG->Copy_MAG_List;
            break;
        case 3:
            qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_B  INS";
            WIR->Pub_Conf_Set_IR("", 2);
            INS = WIR->Copy_IR_List;
            break;
        case 4:
            qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_B  ACV";
            WACW->Pub_Conf_Set_ACW("", 2);
            ACV = WACW->Copy_ACW_List;
            break;
        case 5:
            qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_B  DCV";
            WDCW->Pub_Conf_Set_DCW("", 2);
            DCV = WDCW->Copy_DCW_List;
            break;
        case 6:
            qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_B  ITT";
            WIMP->Pub_Conf_Set_IMP("", 4);
            ITT = WIMP->Copy_IMP_List;
            break;
        case 7:
            WPWR->Pub_Conf_Set_PWR(QStringList(""), "", 2);
            PWR = WPWR->Copy_PWR_List;
            qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_B  PWR";
            break;
        case 8:
            WINDL->Pub_Conf_Set_INDL("", 1, 2);
            INDL = WINDL->Copy_INDL_List;
            qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_B  INDL";
            break;
        case 9:
            WBLOCK->Pub_Conf_Set_BLOCK("", 1, 2);
            BLOCK = WBLOCK->Copy_BLOCK_List;
            qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_B  BLOCK";
            break;
        case 10:
            WLVS->Pub_Conf_Set_LVS("", 2);
            LVS = WLVS->Copy_LVS_List;
            qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_B  LVS";
            break;
        case 11:
            WPG->Pub_Conf_Set_PG(QStringList(""), 2);
            BLDCPG = WPG->Copy_BLDCPG_List;
            qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_B  BLDCPG";
            break;
        case 12:
            WLOAD->Pub_Conf_Set_LOAD("", 2);
            LOAD = WLOAD->Copy_LOAD_List;
            qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_B  LOAD";
            break;
        case 13:
            WNoLoad->Pub_Conf_Set_NOLOAD(QStringList(""), 2);
            NOLOAD = WNoLoad->Copy_NOLOAD_List;
            qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_B  NOLOAD";
            break;
        case 14:
             WBEMF->Pub_Conf_Set_BEMF(QString(""), 2);
             BEMF = WBEMF->Copy_BEMF_List;
            qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_B  BEMF";
            break;
        case 15:
            qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_B  HV";
            WHV->Pub_Conf_Set_HV("", 2);
            HV = WHV->Copy_HV_List;
            break;
        default: break;
        }

        Save_SqlData();
        TabWidget_Changed = true;
        qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_B  Start All OK";
        break;
    case Qt::Key_C:
        if (Conf_User == User_Operator) {
            Pri_Conf_WMessage(tr("          当前用户模式为操作员     \n"\
                                 "无权限进行保存和修改       "));
            break;
        }
        Item_Widget->hide();
        if ((Ini_Proj[ui->stackedWidget->currentIndex()].toInt() == 0) && \
                (ui->MotorType->currentText() != "None")) { // 在 None型号时，不能进行快速设置
              Quick_Set_Widget->show();
              label_Waring->show();
//            QMessageBox Quick_Set_Ask;
//            Quick_Set_Ask.setWindowFlags(Qt::FramelessWindowHint);
//            Quick_Set_Ask.setStyleSheet("QMessageBox{border:3px groove gray;}"\
//                                        "background-color: rgb(209, 209, 157);");
//            Quick_Set_Ask.setText(tr("       确定进行快速设置     \n          "));
//            Quick_Set_Ask.addButton(QMessageBox::Ok)->setStyleSheet
//                    ("border:none;height:30px;width:65px;border:5px groove gray;"\
//                     "border-radius:10px;padding:2px 4px;");
//            Quick_Set_Ask.addButton(QMessageBox::Cancel)->setStyleSheet
//                    ("border:none;height:30px;width:65px;border:5px groove gray;"\
//                     "border-radius:10px;padding:2px 4px;");
//            Quick_Set_Ask.setButtonText(QMessageBox::Ok, QString(tr("确 定")));
//            Quick_Set_Ask.setButtonText(QMessageBox::Cancel, QString(tr("取 消")));
//            Quick_Set_Ask.setIcon(QMessageBox::Warning);
//            int ret = Quick_Set_Ask.exec();
//            if (ret == QMessageBox::Ok) {
//                Quick_Set_Function();
//            }
//            if (ret == QMessageBox::Cancel) {
//                //
//            }
        }
        break;
    case Qt::Key_D:
        qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_D";
        if (Conf_User == User_Operator) {
            Pri_Conf_WMessage(tr("          当前用户模式为操作员     \n"\
                                 "无权限进行保存和修改       "));
            break;
        }
        if (Ini_Proj[ui->stackedWidget->currentIndex()].toInt() == 1) { // 电阻
            if (WDLR->Pub_Conf_Station(QString(tr("Left")))) {
                ui->Key_D->setStyleSheet
                        ("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"\
               "stop: 0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);color:rgb(255, 255, 255);");
                ui->Key_D->setText(tr("左清零"));
            }
        } else if ((Ini_Proj[ui->stackedWidget->currentIndex()].toInt() == 2) && (Board_DLR)) {
            Board_DLR = 0;
            label_Waring_MAG = new QLabel(this);
            label_Waring_MAG->setGeometry(700, 0, 800, 600);
            label_Waring_MAG->show();
            WMAG->Pub_Conf_Set_MAG("3", 3);
            WMAG->Pub_Conf_Set_MAG(" ", 6);
            label_Waring_MAG->hide();
        } else if ((Ini_Proj[ui->stackedWidget->currentIndex()].toInt() == 6)) {
            label_Waring_MAG = new QLabel(this);
            label_Waring_MAG->setGeometry(700, 0, 800, 600);
            label_Waring_MAG->show();
            WIMP->Pub_Conf_Set_IMP("", 7);
            label_Waring_MAG->hide();
        } else {
            //
        }
        break;
    case Qt::Key_E:
        qDebug() << "w_Conf::SlOT_Button_Function_Judge() Qt::Key_E";
        if (Conf_User == User_Operator) {
            Pri_Conf_WMessage(tr("          当前用户模式为操作员     \n"\
                                 "无权限进行保存和修改       "));
            break;
        }
        SlOT_Button_Function_Judge(Qt::Key_B); // -进行保存
        TabWidget_Changed = true;              // -触发没有保存
        if (Ini_Proj[ui->stackedWidget->currentIndex()].toInt() == 1) { // -电阻
            if (WDLR->Pub_Conf_Station(QString(tr("Right")))) {
                ui->Key_E->setStyleSheet
                        ("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"\
               "stop: 0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);color:rgb(255, 255, 255);");
                ui->Key_E->setText(tr("右清零"));
            }
        } else if (Ini_Proj[ui->stackedWidget->currentIndex()].toInt() == 3) { // -绝缘
            IRACW_Compensate = TestIW_IR;
            if (WIR->IR_If_Compensate(QString::number(Ini_ACW_And_IR))) {
                ui->Key_E->setStyleSheet
                        ("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"\
               "stop: 0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);color:rgb(255, 255, 255);");
                ui->Key_E->setText(tr("未补偿"));
            }
        } else if (Ini_Proj[ui->stackedWidget->currentIndex()].toInt() == 4) { // -交耐
            IRACW_Compensate = TestIW_ACW;
            WACW->Pub_Conf_Set_ACW(QString::number(Ini_IR5000), 101);
            if (WACW->ACW_If_Compensate(QString::number(Ini_ACW_And_IR))) {
                ui->Key_E->setStyleSheet
                        ("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"\
               "stop: 0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);color:rgb(255, 255, 255);");
                ui->Key_E->setText(tr("未补偿"));
            }
        }  else if (Ini_Proj[ui->stackedWidget->currentIndex()].toInt() == 5) { // -直耐
            IRACW_Compensate = TestIW_DCW;
            WDCW->Pub_Conf_Set_DCW(QString::number(Ini_DCW_Volt_Up), 103);
            if (WDCW->DCW_If_Compensate(QString::number(Ini_ACW_And_IR))) {
                ui->Key_E->setStyleSheet
                        ("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"\
               "stop: 0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);color:rgb(255, 255, 255);");
                ui->Key_E->setText(tr("未补偿"));
            }
        } else {
            //
        }
        break;
    default:
        //
        break;
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      快速设置
******************************************************************************/
void w_Conf::Quick_Set_Function()
{
    int i = 0, j = 0, x = 0;
    QString DLR_String;
    QString MAG_String;
    QString INDL_String;
    QString IMP_String;

    Quick_Set = true;  label_Waring->show();
    label_Set->show();
    ui->Key_A->hide();
    ui->Key_B->hide();
    ui->Key_C->hide();
    ui->Key_D->hide();
    ui->Key_E->hide();
    ui->imp_button_add->hide();
    ui->imp_button_cancel->hide();
    ui->imp_button_finsh->hide();
    ui->Button_ALL->hide();

    DLR_String = Ini.DLR;
    MAG_String = Ini.MAG;
    INDL_String = Ini.IINDL;
    IMP_String = Ini.IMP;
    if (Quick_Set_Standard->checkState() == 2) {
        // 不做处理
    } else {
        DLR_String = "";
        MAG_String = "";
        INDL_String = "";
        IMP_String = "";
    }
    IMP_String = IMP_String + "&&" + QString::number(Quick_Set_DoubleSpinBox.at(0)->value());
    Quick_set_IRACW_Value = false;
    for (i = 0; i < test_List.size(); i++) { // -快速设置选择项目
        if (i != test_List.indexOf(test_List.at(i))) { // -去除重复选项
            continue;
        }
        SlOT_Button_Conf_Judge(48+Test_Item.indexOf(test_List.at(i))); // -页面切换
        if (Test_Item.indexOf(test_List.at(i)) == 1) {       // -电阻
            WDLR->Pub_Conf_Set_DLR(DLR_String, 6);
        //    if (WDLR->DLR_Compensate_Left) {
        //        WDLR->DLR_Compensate_Left = false;
                ui->Key_D->setStyleSheet("background: qlineargradient"\
                               "(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #5B5F5F, "\
                               "stop: 0.5 #0C2436,stop: 1 #27405A);color:rgb(255, 255, 255);");
                ui->Key_D->setText(tr("左清零"));
        //    }
        //    if (WDLR->DLR_Compensate_Right) {
        //        WDLR->DLR_Compensate_Right = false;
                ui->Key_E->setStyleSheet("background: qlineargradient"\
                                  "(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #5B5F5F, "\
                                  "stop: 0.5 #0C2436,stop: 1 #27405A);color:rgb(255, 255, 255);");
                ui->Key_E->setText(tr("右清零"));
        //    }

            for (j = 7; j > 0; j--) {         //  档位选择
                usleep(50000);
                usleep(50000);
                usleep(50000);
                usleep(50000);
                usleep(50000);
                WDLR->Pub_Conf_Set_DLR(QString::number(j), 4);
                WDLR->Pub_Conf_Set_DLR(QString::number(Right_Test), 5);

                Board_DLR = 0;
                QEventLoop DLRloop;   //  进行延时等待结果
                for (x = 0; x < 7; x++) {
                    QTimer::singleShot(300, &DLRloop, SLOT(quit()));
                    DLRloop.exec();
//                    if (Board_DLR == 1) { // 设置电阻
//                        x = 21;
//                    }
                }
                usleep(50000);
                usleep(50000);
                usleep(50000);
                usleep(50000);
                usleep(50000);
            }
            QEventLoop DLRloop;
            QTimer::singleShot(300, &DLRloop, SLOT(quit()));
            DLRloop.exec();
            for (j = 0; j < 8; j++) {
                if (!(AutoSet[j].isEmpty())) {
                    WDLR->on_AutoSet(AutoSet[j]);
                    AutoSet[j].clear();
                }
            }
            WDLR->Pub_Conf_Set_DLR("", 9);
        } else if (Test_Item.indexOf(test_List.at(i)) == 2) { // -反嵌
            int cutt; cutt = 0;
            WMAG->Pub_Conf_Set_MAG(QString::number(Right_Test), 10);
            WMAG->Pub_Conf_Set_MAG(MAG_String, 5);
            SlOT_Button_Function_Judge(Qt::Key_D);
            QEventLoop eventloop;
            for (j = 0; j < 100; j++) {
                QTimer::singleShot(100, &eventloop, SLOT(quit()));
                eventloop.exec();
                if (Board_DLR == 1) {
                    cutt++;
                    if (cutt >= (Ini.MAG.size()/2)) {
                        j = 101;
                    }
                }
            }
        } else if (Test_Item.indexOf(test_List.at(i)) == 3) { // -绝缘
            WIR->Pub_Conf_Set_IR("", 3);
            ui->Key_E->setText(tr("未补偿"));
        } else if (Test_Item.indexOf(test_List.at(i)) == 4) { // -交耐
            WACW->Pub_Conf_Set_ACW("", 3);
            ui->Key_E->setText(tr("未补偿"));
        } else if (Test_Item.indexOf(test_List.at(i)) == 5) { // -直耐
            WDCW->Pub_Conf_Set_DCW("", 3);
            ui->Key_E->setText(tr("未补偿"));
        } else if (Test_Item.indexOf(test_List.at(i)) == 6) { // -匝间
            WIMP->Pub_Conf_Set_IMP(QString::number(Right_Test), 13);
            WIMP->Pub_Conf_Set_IMP(IMP_String, 6);       // 匝间-设置电压数值
            SlOT_Button_Function_Judge(Qt::Key_D);    // 匝间-采集波形
            QEventLoop eventloop;
            for (j = 0; j < 300; j++) {
                QTimer::singleShot(100, &eventloop, SLOT(quit()));
                eventloop.exec();
                if (WIMP->Pub_Conf_GetSample(3)) {
                    j = 301;
                }
            }
        } else if (Test_Item.indexOf(test_List.at(i)) == 7) { // -电参
            //
        } else if (Test_Item.indexOf(test_List.at(i)) == 8) { // -电感
            WINDL->Pub_Conf_Set_INDL(INDL_String, 1, 6);           // 电感设置数值
            WINDL->Pub_Conf_Set_INDL("", 1, 8);
            WINDL->Pub_Conf_Set_INDL("", Right_Test, 4);
            Board_INDL = 0;
            QEventLoop eventloop;
            for (j = 0; j < 100; j++) {
                QTimer::singleShot(100, &eventloop, SLOT(quit()));
                eventloop.exec();
                if (Board_INDL == 1) {
                    Board_INDL = 0;
                    j = 98;
                }
            }
            Board_INDL = 0;
            WINDL->Pub_Conf_Set_INDL("", 1, 3);
            WINDL->Pub_Conf_Set_INDL("", Right_Test, 4);
            for (j = 0; j < 100; j++) {
                QTimer::singleShot(100, &eventloop, SLOT(quit()));
                eventloop.exec();
                if (Board_INDL == 1) {
                    Board_INDL = 0;
                    j = 101;
                }
            }
        } else if (Test_Item.indexOf(test_List.at(i)) == 9) { // -堵转
            //
        } else if (Test_Item.indexOf(test_List.at(i)) == 10) { // -低启
            //
        } else if (Test_Item.indexOf(test_List.at(i)) == 15) { // -交耐
            WHV->Pub_Conf_Set_HV("", 3);
            ui->Key_E->setText(tr("未补偿"));
        } else {
            //
        }
        QEventLoop eventloop;
        QTimer::singleShot(600, &eventloop, SLOT(quit())); // -延时等待,暂留视觉
        eventloop.exec();
        qApp->processEvents();
        SlOT_Button_Function_Judge(Qt::Key_B); // -快速设置保存
    }
    Quick_set_IRACW_Value = true;
    Quick_Set = false;
    label_Waring->hide();
    label_Set->hide();
    SlOT_Button_Conf_Judge(Qt::Key_0);   //  设置完成后返回设置首页
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      同步数据库与设置界面
******************************************************************************/
void w_Conf::Sync_Conf()
{
    int i = 0, j = 0;
    QStringList BLDC_Noload_Data;
    QStringList PWR_Data;
    QStringList BLDC_PG_Data;
    Get_SqlData();         // -读取数据库文件
    Init_Conf_Interface(); // -初始化设置界面
    for (i = 0; i < Ini_Proj.size(); i++) {
        Conf_ProjKey(Ini_Proj.at(i).toInt(), true);
    }

    Save_Ini_DateFile();
    Init_Conf_file(currentFile.size(), currentFile); // -初始化文件名称
    qApp->processEvents();
    if (ui->stackedWidget->count() > 1) {
        for (i = ui->stackedWidget->count(); i >= 1; i--) {
            switch  (Ini_Proj.at(i-1).toInt()) {
            case 1:
                qDebug() << "w_Conf::Sync_Conf() removeWidget(WDLR)";
                ui->stackedWidget->removeWidget(WDLR);
                break;
            case 2:
                qDebug() << "w_Conf::Sync_Conf() removeWidget(WMAG)";
                ui->stackedWidget->removeWidget(WMAG);
                break;
            case 3:
                qDebug() << "w_Conf::Sync_Conf() removeWidget(WIR)";
                ui->stackedWidget->removeWidget(WIR);
                break;
            case 4:
                qDebug() << "w_Conf::Sync_Conf() removeWidget(WACW)";
                ui->stackedWidget->removeWidget(WACW);
                break;
            case 5:
                qDebug() << "w_Conf::Sync_Conf() removeWidget(WDCW)";
                ui->stackedWidget->removeWidget(WDCW);
                break;
            case 6:
                qDebug() << "w_Conf::Sync_Conf() removeWidget(WIMP)";
                ui->stackedWidget->removeWidget(WIMP);
                break;
            case 7:
                qDebug() << "w_Conf::Sync_Conf() removeWidget(WPWR)";
                ui->stackedWidget->removeWidget(WPWR);
                break;
            case 8:
                qDebug() << "w_Conf::Sync_Conf() removeWidget(WINDL)";
                ui->stackedWidget->removeWidget(WINDL);
                break;
            case 9:
                qDebug() << "w_Conf::Sync_Conf() removeWidget(WBLOCK)";
                ui->stackedWidget->removeWidget(WBLOCK);
                break;
            case 10:
                qDebug() << "w_Conf::Sync_Conf() removeWidget(LVS)";
                ui->stackedWidget->removeWidget(WLVS);
            case 11:
                qDebug() << "w_Conf::Sync_Conf() removeWidget(WPG)";
                ui->stackedWidget->removeWidget(WPG);
            case 12:
                qDebug() << "w_Conf::Sync_Conf() removeWidget(WLOAD)";
                ui->stackedWidget->removeWidget(WLOAD);
            case 13:
                qDebug() << "w_Conf::Sync_Conf() removeWidget(WNoLoad)";
                ui->stackedWidget->removeWidget(WNoLoad);
            case 14:
                qDebug() << "w_Conf::Sync_Conf() removeWidget(WBEMF)";
                ui->stackedWidget->removeWidget(WBEMF);
                break;
            case 15:
                qDebug() << "w_Conf::Sync_Conf() removeWidget(WHV)";
                ui->stackedWidget->removeWidget(WHV);
                break;
            default:
                qDebug() << "w_Conf::Sync_Conf() removeWidget(----NULL)";
                break;
            }
        }
    }
    // struct timeval start, stop, diff;
    for (i = 1; i < Ini_Proj.size(); i++) {
        // gettimeofday(&start, 0);
        switch (Ini_Proj.at(i).toInt()) {
        case 1:
            qDebug() << "w_Conf::Sync_Conf() Init_DLR";
            WDLR = new Widget_DLR(this);
            ui->stackedWidget->addWidget(WDLR);
            if (RES.size() < 153) {
                qDebug() << "w_Conf::Sync_Conf() RES Error" << RES.size();
                for (j = RES.size(); j < 153; j++) {
                    RES.append("0");
                }
            } else {
                qDebug() << "w_Conf::Sync_Conf() RES Ok";
            }
            WDLR->Copy_DLR_List = RES;  //  DLR数据 复制
            WDLR->Pub_Conf_Set_DLR(QString::number(Ini_DCR15), 1);
            WDLR->Pub_Conf_Set_DLR(ui->MotorType->currentText(), 14);
            WDLR->Pub_Conf_Set_DLR(QString::number(Ini_DCR_Balance), 13);
            connect(WDLR, SIGNAL(canSend(can_frame)), this, SLOT(SlOT_CanSendFrame(can_frame)));
            break;
        case 2:
            qDebug() << "w_Conf::Sync_Conf() Init_MAG";
            WMAG = new Widget_MAG(this);
            ui->stackedWidget->addWidget(WMAG);
            if (OPP.size() < 6660) {
                qDebug() << "w_Conf::Sync_Conf() OPP Error" << OPP.size();
                for (j = OPP.size(); j < 6660; j++) {
                    OPP.append("0");
                }
            } else {
                qDebug() << "w_Conf::Sync_Conf() OPP Ok";
            }
            WMAG->Copy_MAG_List = OPP;  //  MAG数据 复制
            WMAG->Pub_Conf_Set_MAG(QString::number(Ini_Mag_Hide), 1);
            WMAG->Pub_Conf_Set_MAG(ui->MotorType->currentText(), 14);
            WMAG->Pub_Conf_Set_MAG(QString::number(Ini_IO_Model), 101);
            connect(WMAG, SIGNAL(canSend(can_frame)), this, SLOT(SlOT_CanSendFrame(can_frame)));
            break;
        case 3:
            qDebug() << "w_Conf::Sync_Conf() Init_IR";
            WIR = new Widget_IR(this);
            ui->stackedWidget->addWidget(WIR);
            if (INS.size() < 100) { // 增加相间绝缘
                QStringList list;
                for (j = 0; j < 200; j++) {
                    list.append("0");
                }
                INS.append(list);
            }
            if (INS.size() < 229) {
                qDebug() << "w_Conf::Sync_Conf() INS Error" << INS.size();
                for (j = INS.size(); j < 229; j++) {
                    INS.append("0");
                }
            } else {
                qDebug() << "w_Conf::Sync_Conf() INS Ok";
            }

            WIR->Copy_IR_List = INS;    //  IR数据 复制
            WIR->Pub_Conf_Set_IR(QString::number(Ini_ACW_And_IR), 1);
            if (Ini_Line_HV) {
               WIR->Pub_Conf_Set_IR(Line_HV_High, 6);
               WIR->Pub_Conf_Set_IR(Line_HV_Low, 7);
            } else {

            }
            connect(WIR, SIGNAL(canSend(can_frame)), this, SLOT(SlOT_CanSendFrame(can_frame)));
            break;
        case 4:
            qDebug() << "w_Conf::Sync_Conf() Init_ACW";
            WACW = new Widget_ACW(this);
            ui->stackedWidget->addWidget(WACW);
            if (ACV.size() < 100) { // 增加相间耐压
                QStringList list;
                for (j = 0; j < 200; j++) {
                    list.append("0");
                }
                ACV.append(list);
            }
            if (ACV.size() < 226) {
                qDebug() << "w_Conf::Sync_Conf() ACV Error" << ACV.size();
                for (j = ACV.size(); j < 226; j++) {
                    ACV.append("0");
                }
            } else {
                qDebug() << "w_Conf::Sync_Conf() ACV Ok";
            }

            WACW->Copy_ACW_List = ACV;  //  ACW数据 复制
            WACW->Pub_Conf_Set_ACW(QString::number(Ini_IR5000), 101);
            WACW->Pub_Conf_Set_ACW(QString::number(Ini_ACW_And_IR), 1);
            WACW->Pub_Conf_Set_ACW(QString::number(Ini_ACW_I_Up), 9);
            WACW->Pub_Conf_Set_ACW(QString::number(Ini_ACW_Volt_Limit), 10);
            if (Ini_Line_HV) {
               WACW->Pub_Conf_Set_ACW(Line_HV_High, 6);
               WACW->Pub_Conf_Set_ACW(Line_HV_Low, 7);
            } else {
               //
            }
            connect(WACW, SIGNAL(canSend(can_frame)), this, SLOT(SlOT_CanSendFrame(can_frame)));
            break;
        case 5:
            qDebug() << "w_Conf::Sync_Conf() Init_DCW";
            WDCW = new Widget_DCW(this);
            ui->stackedWidget->addWidget(WDCW);
            if (DCV.size() < 226) {
                qDebug() << "w_Conf::Sync_Conf() DCV Error" << DCV.size();
                for (j = DCV.size(); j < 226; j++) {
                    DCV.append("0");
                }
            } else {
                qDebug() << "w_Conf::Sync_Conf() DCV Ok";
            }
            WDCW->Copy_DCW_List = DCV;  //  DCW数据 复制
            WDCW->Pub_Conf_Set_DCW(QString::number(Ini_DCW_Volt_Up), 103);
            WDCW->Pub_Conf_Set_DCW(QString::number(Ini_ACW_And_IR), 1);
            WDCW->Pub_Conf_Set_DCW(QString::number(Ini_DCW_I_Up), 9);
            connect(WDCW, SIGNAL(canSend(can_frame)), this, SLOT(SlOT_CanSendFrame(can_frame)));
            break;
        case 6:
            qDebug() << "w_Conf::Sync_Conf() Init_IMP";
            WIMP = new Widget_IMP(this);
            ui->stackedWidget->addWidget(WIMP);
            if (ITT.size() < 6561) {
                qDebug() << "w_Conf::Sync_Conf() ITT Error" << ITT.size();
                ITT.clear();
                for (j = ITT.size(); j < 6561; j++) {
                    ITT.append("0");
                }
            } else {
                qDebug() << "w_Conf::Sync_Conf() ITT Ok";
            }
            WIMP->Copy_IMP_List = ITT;  //  IMP数据 复制
            WIMP->Pub_Conf_Set_IMP(QString::number(Ini_IMP5000), 101);
            WIMP->Pub_Conf_Set_IMP(Ini_ActiveFile, 1);
            if (Ini_Set_ImpVolt == QString(tr("noback"))) { // 匝间初始化-反馈-不反馈-
                WIMP->Pub_Conf_Set_IMP("", 12);
            }
            connect(WIMP, SIGNAL(canSend(can_frame)), this, SLOT(SlOT_CanSendFrame(can_frame)));
            connect(WIMP, SIGNAL(Signal_imp_3_6_test(int)), \
                    this, SLOT(SlOT_Receive_3_6_test(int)));
            break;
        case 7:
            qDebug() << "w_Conf::Sync_Conf() Init_WPWR";
            WPWR = new Widget_PWR(this);
            ui->stackedWidget->addWidget(WPWR);
            if (PWR.size() < 495) {
                qDebug() << "w_Conf::Sync_Conf() PWR Error" << PWR.size();
                for (j = PWR.size(); j < 495; j++) {
                    PWR.append("0");
                }
            } else {
                qDebug() << "w_Conf::Sync_Conf() PWR Ok";
            }
            PWR_Data.clear();
             PWR_Data.append(Ini_Motor);
             PWR_Data.append(QString::number(Ini_Set_pwr_Turn));
             WPWR->Copy_PWR_List = PWR;
             WPWR->Pub_Conf_Set_PWR(PWR_Data, Ini_Motor, 1);
             connect(WPWR, SIGNAL(canSend(can_frame, int)), this, \
                     SLOT(SlOT_CanSendFrame_PWR(can_frame, int)));
             WPWR->Pub_Conf_Set_PWR(QStringList(""), QString::number(Ini_Power_Chose), 4);
             WPWR->Pub_Conf_Set_PWR(QStringList(""), QString::number(Ini_Pwr_Turn), 6);
            break;
        case 8:
            qDebug() << "w_Conf::Sync_Conf() Init_WINDL";
            WINDL = new Widget_INDL(this);
            ui->stackedWidget->addWidget(WINDL);
            if (INDL.size() < 495) {
                qDebug() << "w_Conf::Sync_Conf() INDL Error" << INDL.size();
                for (j = INDL.size(); j < 495; j++) {
                    INDL.append("0");
                }
            } else {
                qDebug() << "w_Conf::Sync_Conf() INDL Ok";
            }
            WINDL->Copy_INDL_List = INDL;
            WINDL->Pub_Conf_Set_INDL("", 1, 1);
            connect(WINDL, SIGNAL(canSend(can_frame)), this, SLOT(SlOT_CanSendFrame(can_frame)));
            connect(WINDL, SIGNAL(Lable_Display()), this, SLOT(SlOT_Lable_Display()));
            break;
        case 9:
            qDebug() << "w_Conf::Sync_Conf() Init_WBLOCK";
            WBLOCK = new Widget_BLOCK(this);
            ui->stackedWidget->addWidget(WBLOCK);
            if (BLOCK.size() < 495) {
                qDebug() << "w_Conf::Sync_Conf() BLOCK Error" << BLOCK.size();
                for (j = BLOCK.size(); j < 495; j++) {
                    BLOCK.append("0");
                }
            } else {
                qDebug() << "w_Conf::Sync_Conf() BLOCK Ok";
            }
            WBLOCK->Copy_BLOCK_List = BLOCK;
            WBLOCK->Pub_Conf_Set_BLOCK("", 1, 1);
            connect(WBLOCK, SIGNAL(canSend(can_frame)), this, SLOT(SlOT_CanSendFrame(can_frame)));
            WBLOCK->Pub_Conf_Set_BLOCK(QString::number(Ini_Power_Chose), 1, 4);
            break;
        case 10:
            qDebug() << "w_Conf::Sync_Conf() Init_WLVS";
            WLVS = new Widget_LVS(this);
            ui->stackedWidget->addWidget(WLVS);
            if (LVS.size() < 495) {
                qDebug() << "w_Conf::Sync_Conf() LVS Error" << LVS.size();
                for (j = LVS.size(); j < 495; j++) {
                    LVS.append("0");
                }
            } else {
                qDebug() << "w_Conf::Sync_Conf() LVS Ok";
            }
            WLVS->Copy_LVS_List = LVS;
            WLVS->Pub_Conf_Set_LVS(QString(""), 1);
            connect(WLVS, SIGNAL(canSend(can_frame)), this, SLOT(SlOT_CanSendFrame(can_frame)));
            WLVS->Pub_Conf_Set_LVS(QString::number(Ini_Power_Chose), 4);
            break;
        case 11:
            qDebug() << "w_Conf::Sync_Conf() Init_WHALL";
            WPG = new Widget_BLDC_PG(this);
            ui->stackedWidget->addWidget(WPG);
            if (BLDCPG.size() < 300) {
                qDebug() << "w_Conf::Sync_Conf() BLDCPG Error" << BLDCPG.size();
                for (j = BLDCPG.size(); j < 300; j++) {
                    BLDCPG.append("0");
                }
            } else {
                qDebug() << "w_Conf::Sync_Conf() BLDCPG Ok";
            }
            BLDC_PG_Data.clear();
            BLDC_PG_Data.append(QString::number(Ini_BLDC_PG_Chose));
            WPG->Copy_BLDCPG_List = BLDCPG;
            WPG->Pub_Conf_Set_PG(BLDC_PG_Data, 1);
            connect(WPG, SIGNAL(canSend(can_frame)), this, SLOT(SlOT_CanSendFrame(can_frame)));
            break;
        case 12:
            qDebug() << "w_Conf::Sync_Conf() Init_WLOAD";
            WLOAD = new Widget_Load(this);
            ui->stackedWidget->addWidget(WLOAD);
            if (LOAD.size() < 200) {
                qDebug() << "w_Conf::Sync_Conf() LOAD Error" << LOAD.size();
                for (j = LOAD.size(); j < 200; j++) {
                    LOAD.append("0");
                }
            } else {
                qDebug() << "w_Conf::Sync_Conf() LOAD Ok";
            }
            WLOAD->Copy_LOAD_List = LOAD;
            WLOAD->Pub_Conf_Set_LOAD(QString(""), 1);
            connect(WLOAD, SIGNAL(canSend(can_frame)), this, SLOT(SlOT_CanSendFrame(can_frame)));
            break;
        case 13:
            qDebug() << "w_Conf::Sync_Conf() Init_WNoLoad";
            WNoLoad = new Widget_Noload(this);
            ui->stackedWidget->addWidget(WNoLoad);
            if (NOLOAD.size() < 200) {
                qDebug() << "w_Conf::Sync_Conf() NOLOAD Error" << NOLOAD.size();
                for (j = NOLOAD.size(); j < 200; j++) {
                    NOLOAD.append("0");
                }
            } else {
                qDebug() << "w_Conf::Sync_Conf() NOLOAD Ok";
            }
            BLDC_Noload_Data.clear();
            BLDC_Noload_Data.append(QString::number(Ini_BLDC_Start_Mode));
            BLDC_Noload_Data.append(QString::number(Ini_BLDC_Start_Item));
            WNoLoad->Copy_NOLOAD_List = NOLOAD;
            WNoLoad->Pub_Conf_Set_NOLOAD(BLDC_Noload_Data, 1);
            connect(WNoLoad, SIGNAL(canSend(can_frame)), this, SLOT(SlOT_CanSendFrame(can_frame)));
            break;
        case 14:
            qDebug() << "w_Conf::Sync_Conf() Init_WBEMF";
            WBEMF = new Widget_BEMF(this);
            ui->stackedWidget->addWidget(WBEMF);
            if (BEMF.size() < 200) {
                qDebug() << "w_Conf::Sync_Conf() BEMF Error" << BEMF.size();
                for (j = BEMF.size(); j < 200; j++) {
                    BEMF.append("0");
                }
            } else {
                qDebug() << "w_Conf::Sync_Conf() BEMF Ok";
            }
            WBEMF->Copy_BEMF_List = BEMF;
            WBEMF->Pub_Conf_Set_BEMF(QString(""), 1);
            connect(WBEMF, SIGNAL(canSend(can_frame)), this, SLOT(SlOT_CanSendFrame(can_frame)));
            break;
        case 15:
            qDebug() << "w_Conf::Sync_Conf() Init_HV";
            WHV = new Widget_HV(this);
            ui->stackedWidget->addWidget(WHV);
            if (HV.size() < 100) { // 增加相间耐压
                QStringList list;
                for (j = 0; j < 200; j++) {
                    list.append("0");
                }
                HV.append(list);
            }
            if (HV.size() < 226) {
                qDebug() << "w_Conf::Sync_Conf() HV Error" << HV.size();
                for (j = HV.size(); j < 226; j++) {
                    HV.append("0");
                }
            } else {
                qDebug() << "w_Conf::Sync_Conf() HV Ok";
            }

            WHV->Copy_HV_List = HV;  //  ACW数据 复制
            WHV->Pub_Conf_Set_HV(QString::number(Ini_IR5000), 101);
            WHV->Pub_Conf_Set_HV(QString::number(Ini_ACW_And_IR), 1);
            connect(WHV, SIGNAL(canSend(can_frame)), this, SLOT(SlOT_CanSendFrame(can_frame)));
            break;
        default:
            //
            break;
        }
        // gettimeofday(&stop, 0);
        // timeval_subtract(&dif f, &start, &stop);
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      计时操作
******************************************************************************/
int w_Conf::timeval_subtract(struct timeval* result, struct timeval* x, struct timeval* y)
{
    if  (x->tv_sec > y->tv_sec )
        return -1;

    if  ((x->tv_sec == y->tv_sec) && (x->tv_usec > y->tv_usec) )
        return -1;

    result->tv_sec = (y->tv_sec-x->tv_sec);
    result->tv_usec = (y->tv_usec-x->tv_usec);

    if (result->tv_usec < 0) {
        result->tv_sec--;
        result->tv_usec += 1000000;
    }
    return 0;
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      同步测试界面参数
******************************************************************************/
void w_Conf::Sync_Test_Widget()
{
    signed int i = 0;
    int j = 0;
    QString      name_list;
    QStringList  Back_Data;

    strTest.clear();  // -测试项目
    strParam.clear(); // -测试参数
    sql_Test.clear(); // -测试数据库保存项目
    for (i = 0; i < test_Inifile.size(); i++) {
        for (j = 1; j < Ini_Proj.size(); j++) {
            if (test_Inifile.at(i).toInt() == Ini_Proj[j].toInt()) {
                break;
            }
            if (j == (Ini_Proj.size()-1)) {
                test_Inifile.removeAt(i);
                QSettings set_Test_File(Test_File_path, QSettings::IniFormat);
                set_Test_File.setIniCodec("UTF-8");
                name_list = QString("Test_File/%1").arg(Ini_ActiveFile);
                set_Test_File.setValue(name_list, test_Inifile);
                i--;
            }
        }
    }

    Test_Occur_Debug = CONF.at(12).toInt();
    serial_number    = CONF.at(14);

    Conf_Test = test_Inifile;
    int remove_number = 0;
    int size = Conf_Test.size();


    for (i = 0; i < size; i++) {
        remove_number++;
        if (ui->test->item(i, 0)->textColor().name() != "#008000") {
            // 绿色字体的下发
            Conf_Test.removeAt(remove_number-1);
            remove_number--;
        }
    }
    bool IR_First_finsh;
    bool ACW_First_finsh;
    IR_First_finsh = false;
    ACW_First_finsh = false;
    for (i = 0; i < Conf_Test.size(); i++) {
        switch (Conf_Test.at(i).toInt()) {
        case 1:  // 电阻
            strRES = RES;
            Back_Data = WDLR->DCR_Test_Param();
            strTest.append(Back_Data.mid(4, Back_Data.at(0).toInt()));
            strParam.append(Back_Data.mid(4 + Back_Data.at(0).toInt(), Back_Data.at(1).toInt()));
            strDLR_UpDown = Back_Data.mid(4 + Back_Data.at(0).toInt() +  \
                                          Back_Data.at(1).toInt(), Back_Data.at(2).toInt());
            sql_Test.append(Back_Data.mid(4 + Back_Data.at(0).toInt() + \
                                          Back_Data.at(1).toInt() + Back_Data.at(2).toInt()));
            break;
        case 2: // 反嵌
            strOPP = OPP;
            Back_Data = WMAG->MAG_Test_Param(Ini_Mag_Hide);
            strTest.append(Back_Data.mid(3, Back_Data.at(0).toInt()));
            strParam.append(Back_Data.mid(3 + Back_Data.at(0).toInt(), Back_Data.at(1).toInt()));
            sql_Test.append(Back_Data.mid(3 + Back_Data.at(0).toInt() + Back_Data.at(1).toInt()));
            break;
        case 3:  // 绝缘
            strIR = INS;
            Back_Data = WIR->IR_Test_Param(IR_First_finsh);
            strTest.append(Back_Data.mid(3, Back_Data.at(0).toInt()));
            strParam.append(Back_Data.mid(3 + Back_Data.at(0).toInt(), Back_Data.at(1).toInt()));
            sql_Test.append(Back_Data.mid(3 + Back_Data.at(0).toInt() + Back_Data.at(1).toInt()));
            IR_First_finsh = true;
            break;
        case 4:  // 交耐
            strACW = ACV;
            Back_Data = WACW->ACW_Test_Param(ACW_First_finsh);
            strTest.append(Back_Data.mid(3, Back_Data.at(0).toInt()));
            strParam.append(Back_Data.mid(3 + Back_Data.at(0).toInt(), Back_Data.at(1).toInt()));
            sql_Test.append(Back_Data.mid(3 + Back_Data.at(0).toInt() + Back_Data.at(1).toInt()));
            ACW_First_finsh = true;
            break;
        case 5:  // 直耐
            strDCW = DCV;
            Back_Data = WDCW->DCW_Test_Param();
            strTest.append(Back_Data.mid(3, Back_Data.at(0).toInt()));
            strParam.append(Back_Data.mid(3 + Back_Data.at(0).toInt(), Back_Data.at(1).toInt()));
            sql_Test.append(Back_Data.mid(3 + Back_Data.at(0).toInt() + Back_Data.at(1).toInt()));
            break;
        case 6:  // 匝间
            strITT = ITT;
            Back_Data = WIMP->IMP_Test_Param(Ini_imp_min);
            strTest.append(Back_Data.mid(3, Back_Data.at(0).toInt()));
            strParam.append(Back_Data.mid(3 + Back_Data.at(0).toInt(), Back_Data.at(1).toInt()));
            strIMP_Param = Back_Data.mid(3 + Back_Data.at(0).toInt(), Back_Data.at(1).toInt());
            sql_Test.append(Back_Data.mid(3 + Back_Data.at(0).toInt() + Back_Data.at(1).toInt()));
            break;
        case 7:  // 电参
            strPWR = PWR;
            Back_Data = WPWR->PWR_Test_Param();
            strTest.append(Back_Data.mid(3, Back_Data.at(0).toInt()));
            strParam.append(Back_Data.mid(3 + Back_Data.at(0).toInt(), Back_Data.at(1).toInt()));
            sql_Test.append(Back_Data.mid(3 + Back_Data.at(0).toInt() + Back_Data.at(1).toInt()));
            break;
        case 8:  // 电感
            strINDL = INDL;
            Back_Data = WINDL->INDL_Test_Param();
            strTest.append(Back_Data.mid(3, Back_Data.at(0).toInt()));
            strParam.append(Back_Data.mid(3 + Back_Data.at(0).toInt(), Back_Data.at(1).toInt()));
            sql_Test.append(Back_Data.mid(3 + Back_Data.at(0).toInt() + Back_Data.at(1).toInt()));
            break;
        case 9:  // -堵转
            strBLOCK = BLOCK;
            Back_Data = WBLOCK->BLOCK_Test_Param();
            strTest.append(Back_Data.mid(3, Back_Data.at(0).toInt()));
            strParam.append(Back_Data.mid(3 + Back_Data.at(0).toInt(), Back_Data.at(1).toInt()));
            sql_Test.append(Back_Data.mid(3 + Back_Data.at(0).toInt() + Back_Data.at(1).toInt()));
            break;
        case 10: // -低启
            strLVS = LVS;
            Back_Data = WLVS->LVS_Test_Param();
            strTest.append(Back_Data.mid(3, Back_Data.at(0).toInt()));
            strParam.append(Back_Data.mid(3 + Back_Data.at(0).toInt(), Back_Data.at(1).toInt()));
            sql_Test.append(Back_Data.mid(3 + Back_Data.at(0).toInt() + Back_Data.at(1).toInt()));
            break;
        case 11: // -霍尔
            strPG = BLDCPG;
            Back_Data = WPG->PG_Test_Param();
            strTest.append(Back_Data.mid(3, Back_Data.at(0).toInt()));
            strParam.append(Back_Data.mid(3 + Back_Data.at(0).toInt(), Back_Data.at(1).toInt()));
            sql_Test.append(Back_Data.mid(3 + Back_Data.at(0).toInt() + Back_Data.at(1).toInt()));
            break;
        case 12: // -负载
            strLOAD = LOAD;
            Back_Data = WLOAD->LOAD_Test_Param();
            strTest.append(Back_Data.mid(3, Back_Data.at(0).toInt()));
            strParam.append(Back_Data.mid(3 + Back_Data.at(0).toInt(), Back_Data.at(1).toInt()));
            sql_Test.append(Back_Data.mid(3 + Back_Data.at(0).toInt() + Back_Data.at(1).toInt()));
            break;
        case 13: // -空载
            strNOLOAD = NOLOAD;
            Back_Data = WNoLoad->NOLOAD_Test_Param();
            strTest.append(Back_Data.mid(3, Back_Data.at(0).toInt()));
            strParam.append(Back_Data.mid(3 + Back_Data.at(0).toInt(), Back_Data.at(1).toInt()));
            sql_Test.append(Back_Data.mid(3 + Back_Data.at(0).toInt() + Back_Data.at(1).toInt()));
            break;
        case 14: // -反电动势
            strBEMF = BEMF;
            Back_Data = WBEMF->BEMF_Test_Param();
            strTest.append(Back_Data.mid(3, Back_Data.at(0).toInt()));
            strParam.append(Back_Data.mid(3 + Back_Data.at(0).toInt(), Back_Data.at(1).toInt()));
            sql_Test.append(Back_Data.mid(3 + Back_Data.at(0).toInt() + Back_Data.at(1).toInt()));
            break;
        case 15:  // 交耐
            strHV = HV;
            Back_Data = WHV->HV_Test_Param();
            strTest.append(Back_Data.mid(3, Back_Data.at(0).toInt()));
            strParam.append(Back_Data.mid(3 + Back_Data.at(0).toInt(), Back_Data.at(1).toInt()));
            sql_Test.append(Back_Data.mid(3 + Back_Data.at(0).toInt() + Back_Data.at(1).toInt()));
            break;
        default:
            //
            break;
        }
    }

    QString  Check_strTest; // -建立字符串, 字符串列表转化为字符串
    for (i = 0; i < strTest.size(); i++) {
        Check_strTest += strTest.at(i);
    }
    signed int si;
    for (si = 0; si < Conf_Test.size(); si++) {
        switch (Conf_Test.at(si).toInt()) {
        case 1:
            if (Check_strTest.indexOf(QString(tr("电阻"))) < 0) {
                Conf_Test.removeAt(si);
                si--;
            }
            break;
        case 2:
            if ((Check_strTest.indexOf(QString(tr("反嵌"))) < 0) && \
                    (Check_strTest.indexOf(QString(tr("磁旋"))) < 0)) {
                Conf_Test.removeAt(si);
                si--;
            }
            break;
        case 3:
            if (Check_strTest.indexOf(QString(tr("绝缘"))) < 0) {
                Conf_Test.removeAt(si);
                si--;
            }
            break;
        case 4:
            if (Check_strTest.indexOf(QString(tr("交耐"))) < 0) {
                Conf_Test.removeAt(si);
                si--;
            }
            break;
        case 5:
            if (Check_strTest.indexOf(QString(tr("直耐"))) < 0) {
                Conf_Test.removeAt(si);
                si--;
            }
            break;
        case 6:
            if (Check_strTest.indexOf(QString(tr("匝间")), 0, Qt::CaseInsensitive) < 0) {
                Conf_Test.removeAt(si);
                si--;
            }
            break;
        case 7:
            //
            break;
        case 8:
            if (Check_strTest.indexOf(QString(tr("电感"))) < 0) {
                Conf_Test.removeAt(si);
                si--;
            }
            break;
        case 9:
            //
            break;
        case 10:
            //
            break;
        case 11:
            //
            break;
        case 12:
            //
            break;
        case 13:
            //
            break;
        case 14:
            //
            break;
        case 15:
            if (Check_strTest.indexOf(QString(tr("搭线"))) < 0) {
                Conf_Test.removeAt(si);
                si--;
            }
            break;
        default:
            break;
        }
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.7.19
  * brief:      保存配置Ini文件
******************************************************************************/
void w_Conf::Save_Ini_DateFile()
{
    QSettings set_Test_File(Test_File_path, QSettings::IniFormat);
    set_Test_File.setIniCodec("UTF-8");
    set_Test_File.setValue("DateFile/datefile", DateFile);
    set_Test_File.setValue("DateFile/currentfile", currentFile);
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      从配置文件中，读取设置数据
******************************************************************************/
void w_Conf::Get_SqlData()
{
    int i = 0;
    QStringList Allocation_list; // -默认 Allocation/Item
    Allocation_list.clear();
    Allocation_list.append("13");
    Allocation_list.append("14");
    Allocation_list.append("0");
    Allocation_list.append("0");
    Allocation_list.append("0");
    Allocation_list.append("0");
    Allocation_list.append("1");

    QStringList Password_list; // -默认 Password/Text
    Password_list.clear();
    Password_list.append("6");
    Password_list.append("456");
    Password_list.append("789");

    QStringList System_list; // 默认 System/Text
    System_list.clear();
    System_list.append("9");   // -蜂鸣器的档位
    System_list.append("0.1"); // -合格时间
    System_list.append("0.3"); // -不合格时间
    System_list.append("9");   // -Led档位
    System_list.append("0");   // -启动模式
    System_list.append("1");   // -管理员

    QString parameter_set;
    QSettings *set_Sys = new QSettings(Sys_path, QSettings::IniFormat);
    set_Sys->setIniCodec("GB18030");

    Ini_Number       = set_Sys->value("Allocation/All", "7").toString().toInt();
    Ini_Proj_Real    = set_Sys->value("Allocation/Item", Allocation_list).toStringList();
    //  Ini_Proj_Real.append(tr("14"));
    Ini_Proj         = set_Sys->value("Allocation/Item",
                                      Allocation_list).toStringList().mid(5, Ini_Number);
    // Ini_Proj.append(tr("14"));
    Ini_Password     = set_Sys->value("Password/Text", Password_list).toStringList();
    Ini_SQL_Enable   = set_Sys->value("Sql/Text", "disable").toString();
    Ini_Factory      = set_Sys->value("Factory/text", "V-0.0.0").toString();
    Ini_Set_ImpVolt  = set_Sys->value("impvolt/text", "noback").toString();
    Ini_IRHostJudge  = set_Sys->value("IRHostJudge/text", "0").toInt();
    Ini_Motor        = set_Sys->value("System/PG", "Common").toString();
    Ini_DCR_Balance  = set_Sys->value("System/Unbalance", "1").toInt();
    Ini_Task_Table   = set_Sys->value("Sql/Task_Table", "1").toString();
    Ini_Pwr_Turn     = set_Sys->value("System/Shan_Turn", "0").toInt();
    Ini_Power_Chose  = set_Sys->value("power/Text", "0").toInt();
    // -电源选择方式-默认为0
    Ini_Mag_Hide     = set_Sys->value("magshapehide/text", "0").toInt();
    // -反嵌的波形是否隐藏-默认为0
    Ini_Udp_Enable   = set_Sys->value("UDP/text", "0").toInt();
    // -UDP上传-默认为0
    Ini_ACW_And_IR   = set_Sys->value("commonACW/text", "0").toInt();
    // -设置相间耐压和普通耐压的转换-默认为0
    Ini_System       = set_Sys->value("System/Text", System_list).toStringList();
    Ini_ActiveFile   = set_Sys->value("ActiveFile/file", "Base_File").toString();
    // 获取当前文件
    Ini_imp_min      = set_Sys->value("imp_min/area_diff", "0").toInt();
    // -设置匝间下限
    Ini_BLDC_Start_Mode = set_Sys->value("BLDC/Start_Mode", "0").toInt();
    Ini_BLDC_Start_Item = set_Sys->value("BLDC/Start_Item", "0").toInt();
    Ini_BLDC_PG_Chose   = set_Sys->value("BLDC/PG_Chose", "0").toInt();

    Out_Channel_6       = set_Sys->value("System/out6", "0").toInt();
    Ini_IMP5000         = set_Sys->value("System/IMP5000", "0").toInt();
    Ini_IR5000          = set_Sys->value("System/IR5000", "0").toInt();
    Ini_DCR15           = set_Sys->value("System/dcr_Disable", "0").toInt();
    Ini_DCR_Cancle      = set_Sys->value("System/DCR_Cancle", "0").toInt();
    Ini_Set_pwr_Turn    = set_Sys->value("System/Set_Turn", "0").toInt();
    Ini_ACW_I_Up        = set_Sys->value("ACW_Set/I_Up", "20.00").toDouble();
    Ini_ACW_Volt_Limit  = set_Sys->value("ACW_Set/Volt_Limit", "500").toInt();
    Ini_DCW_I_Up        = set_Sys->value("DCW_Set/I_Up", "10.00").toDouble();
    Ini_DCW_Volt_Up     = set_Sys->value("DCW_Set/Volt_Up", "0").toInt();
    Ini_IMP_36          = set_Sys->value("System/IMP_36", "0").toInt();
    Ini_IO_Model        = set_Sys->value("System/IO_Model", "0").toInt();
    Ini_Line_HV         = set_Sys->value("Line_HV/Enable", "0").toInt();
    Line_HV_High        = set_Sys->value("Line_HV/High", "0").toString();
    Line_HV_Low         = set_Sys->value("Line_HV/Low", "0").toString();
    Ini_Vacuum_Model    = set_Sys->value("System/Vacuum_Model", "0").toInt();

    if (Ini_IMP5000) {
        Quick_Set_DoubleSpinBox[0]->setMaximum(5000);
    } else {
        //
    }
    system("sync");
    delete set_Sys;

    Conf_User = Ini_System.at(5).toInt(); // 2017.6.7 添加使用用户
    Ini_Factory = "A"+Ini_Factory;

    ui->label_Text->setText(QString(tr("当前文件：")) + Ini_ActiveFile);
    if ((Ini_SQL_Enable == "enable") && (same_ip_address) && (!isopend)) {
        isopend = true;
        if (sql_net.open_net_Sql("testodbc")) {
            Singal_Conf_to_Main(QStringList(""), QString(""), 1, 3);

            NetSQL_OpenOk = true;

            SQL_Init = true;
            SQL_Task.clear();
            QSqlQuery query_net(sql_net.dbtwo);
            if (sql_net.dbtwo.tables().contains(Ini_Factory)) {
                // -查询是否存在表，若不存在进行创建数据库
                //
            } else {
                QString create = (QString(tr("create table %1 (id integer primary key, "\
                                  "项目 nvarchar(50), 参数 nvarchar(50), 结果 nvarchar(50), "\
                                  "判定 nvarchar(50), 配置 nvarchar(50), 项目1 nvarchar(50), "\
                                  "项目2 nvarchar(50))")).arg(Ini_Factory));
                query_net.exec(create);
            }
            QString net_str = QString(tr("Select 生产线, 生产任务编号 from %1 "))\
                    .arg(Ini_Task_Table); //
            query_net.exec(net_str);
            while (query_net.next()) {
                SQL_Task.append(query_net.value(0).toString().trimmed());
                SQL_Task.append(query_net.value(1).toString().trimmed());
            }
            for (i = 0; i < SQL_Task.size()/2; i++) {
                SQL_Produce_Plan->addItem(QWidget::tr("%1").arg(SQL_Task.at(i*2+0)));
                SQL_Produce_Number->addItem(QWidget::tr("%1").arg(SQL_Task.at(i*2+1)));
            }
            SQL_Init = false;
            SQL_Produce_Plan_textChanged(SQL_Produce_Plan->currentText());
        } else {
            NetSQL_OpenOk = false;
        }
    } else {
        //
    }

    QString Filename;
    Filename = QString("/mnt/nandflash/AIP/ConfFile/%1.ini").arg(Ini_ActiveFile);
    QSettings set_File(Filename, QSettings::IniFormat);
    for (i = 0; i < parameter.size(); i++) {
        parameter_set = QString("%1/value").arg(parameter[i]);
        strList[i] = set_File.value(parameter_set).toStringList();
    }
    QSettings Add_File("/mnt/nandflash/AIP/AddFile.ini", QSettings::IniFormat);
    Add_File.setIniCodec("UTF-8");
    if (PWR == QStringList()) {
        strList[7] = Add_File.value("PWR/value").toStringList();
    }
    if (INDL == QStringList()) {
        strList[8] = Add_File.value("INDL/value").toStringList();
    }

    if (BLOCK == QStringList()) {
        strList[9] = Add_File.value("BLOCK/value").toStringList();
    }
    if (LVS == QStringList()) {
        strList[10] = Add_File.value("LVS/value").toStringList();
    }

    if (CONF.size() < 100) {
        for (i = CONF.size(); i < 150; i++) {
            CONF.append("0");
        }
    } else {
        //
    }
    conf_c = CONF;

    // 获取Test_File.ini文件(若不存在，建立ini文件)
    QSettings set_Test_File(Test_File_path, QSettings::IniFormat);
    QString   name_list;   name_list = QString("Test_File/%1").arg(Ini_ActiveFile);
    set_Test_File.setIniCodec("UTF-8");
    test_Inifile = set_Test_File.value(name_list).toStringList();

    // -2016-12-9 在修改配置后，以前的测试文件必须删除，比如之前的-<测试项目>-有电参，
    // 现在配置里面取消电参配置，在测试文件-<测试项目>-取消电参
    for (i = 0; i < test_Inifile.size(); i++) {
        if (Ini_Proj.indexOf(test_Inifile.at(i)) >= 0) {
            //
        } else {
            test_Inifile.removeAt(i);
            i--;
        }
    }

    DateFile    = set_Test_File.value("DateFile/datefile").toStringList();
    currentFile = set_Test_File.value("DateFile/currentfile").toStringList();

 /*   QSqlQuery query(sql.db);
    sql.db.transaction();
    if (sql.isTabExst("TestDa", sql.db)) { // 若TestDa存在,必要时进行删除操作

    } else {
        QString create=tr("create table TestDa (id integer primary key,"\
                          "项目 Text,参数 Text,结果 Text,判定 Text,配置 Text,"\
                          "项目1 Text,项目2 Text)");
        query.exec(create);
        if (sdcard_exist) {
            system("chmod +x /mnt/sdcard/aip.db");
        } else {
            system("chmod +x /mnt/nandflash/aip.db");
        }
    } */
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      初始化文件名称
******************************************************************************/
void w_Conf::Init_Conf_file(int row, QStringList file)
{
    int i = 0;

    ui->fileTab->setRowCount(0);
    ui->fileTab->setColumnWidth(0, 135); // -初始化文件名称
    if (row > 9) { // -设置文件和型号行数
        ui->fileTab->setRowCount(row);
        for (i = 0; i < row; i++) {
            ui->fileTab->setRowHeight(i, 39);
        }
    } else {
        ui->fileTab->setRowCount(9);
        for (i = 0; i < 9; i++) {
            ui->fileTab->setRowHeight(i, 39);
        }
    }
    for (i = 0; i < row; i++) {
        QTableWidgetItem *pItem = new QTableWidgetItem(file.at(i));
        pItem->setTextAlignment(Qt::AlignCenter);
        ui->fileTab->setItem(i, 0, pItem);
    }
    ui->fileTab->verticalScrollBar()->setValue(0);
    checked_File = file;
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2015.6.6
  * brief:      可选项目 按键使能
******************************************************************************/
void w_Conf::Conf_ProjKey(int i, bool judge)
{
    if (judge == false) {
        btnGroup_Item->button(i)->hide();
    } else {
        btnGroup_Item->button(i)->show();
    }
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      初始化设置界面
******************************************************************************/
void w_Conf::Init_Conf_Interface()
{
    int i = 0;
    ui->combConf1->setCurrentIndex(CONF[12].toInt());   // 遇不合格测试项目是否继续
    ui->file_number->setText(CONF[14]);
    if (model_Type.indexOf(CONF[13]) >= 0) {
        if (CONF[13] == ui->MotorType->currentText()) {
            on_MotorType_currentIndexChanged(model_Type.indexOf(CONF[13]));
        } else {
            ui->MotorType->setCurrentIndex(model_Type.indexOf(CONF[13]));
        }
    } else {
        on_MotorType_currentIndexChanged(0);
    }
    ui->test->setRowCount(0);
    ui->test->setGeometry(305, 20, 131, 39*14+(ui->test->horizontalHeader()->height()));
    if ((test_Inifile.size()) >= 13) {
        if (test_Inifile.size() <= 15) {
            ui->test->setRowCount(test_Inifile.size()+1);
            for (i = 0; i < (test_Inifile.size() + 1); i++) {
                ui->test->setRowHeight(i, 39);
            }
        } else {
            ui->test->setRowCount(16);
            for (i = 0; i < (test_Inifile.size() + 1); i++) {
                ui->test->setRowHeight(i, 39);
            }
        }
    } else {
        ui->test->setRowCount(13);
        for (i = 0; i < 13; i++) {
            ui->test->setRowHeight(i, 39);
        }
    }

    Init_test_TableWidget();
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2015.12.30
  * brief:      初始化测试项目
******************************************************************************/
void w_Conf::Init_test_TableWidget()
{
    int i = 0;
    test_List.clear();
    for (i = 0; i < test_Inifile.size(); i++) {
        int item = test_Inifile[i].toInt();
        test_List.append(Test_Item[item]);
        QTableWidgetItem *pItem = new QTableWidgetItem;
        pItem->setTextAlignment(Qt::AlignCenter);
        pItem->setText(Test_Item[item]);
        pItem->setTextColor(QColor("green"));
        ui->test->setItem(i, 0, pItem);
    }
    qApp->processEvents();
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2015.12.30
  * brief:      将数据存入数据库
******************************************************************************/
void w_Conf::Save_SqlData()
{
    int num = Ini_Proj[ui->stackedWidget->currentIndex()].toInt();

    QString Filename;
    Filename = QString("/mnt/nandflash/AIP/ConfFile/%1.ini").arg(Ini_ActiveFile);
    QSettings set_File(Filename, QSettings::IniFormat);
    set_File.setValue(QString("%1/value").arg(parameter[num]), strList[num]);
}

/******************************************************************************
  * version:    1.0
  * author:     SL
  * date:       2016.4.15
  * brief:      将配置数据存入数据库
******************************************************************************/
void w_Conf::Save_SystemConf_Data(int choose)
{
    QSettings *configIniWrite = new QSettings(Sys_path, QSettings::IniFormat);
    configIniWrite->setIniCodec("GB18030");
    switch (choose) {
    case 1:
        configIniWrite->beginGroup("Allocation"); // -配置数据
        configIniWrite->setValue("All", QString::number(Ini_Number));
        configIniWrite->setValue("Item", QStringList(Ini_Proj_Real));
        break;
    case 2:
        configIniWrite->beginGroup("System");     //系统数据
        configIniWrite->setValue("Text", QStringList(Ini_System.mid(0, 6)));
        break;
    case 3:
        configIniWrite->beginGroup("Password");   // -密码数据
        configIniWrite->setValue("Text", QStringList(Ini_Password));
        break;
    default:
        //
        break;
    }
    system("sync");
    configIniWrite->endGroup();
    delete configIniWrite;
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      保存配置数据
******************************************************************************/
void w_Conf::Save_ConfData()
{
    int i = 0; // -更新设置数据
    Item_Widget->hide();
    Conf_label_Hide->hide();
    for (i = 0; i < 8; i++) {
        CONF.replace(i, colorIdList[i]);
    }
    CONF.replace(12, QString::number(ui->combConf1->currentIndex()));
    CONF.replace(13, ui->MotorType->currentText());
    CONF.replace(14, ui->file_number->text());
}

void w_Conf::Set_Color(QString colr)
{
    QString str;
    colorIdList.replace(iColorBtn, colr);
    colorIdList_C.replace(iColorBtn, colr);
    if (colr == "#000000") {
        str = QString("height:120px;width:95px;background-color:%1;color:white;").arg((colr));
    } else {
        str = QString("height:120px;width:95px;background-color:%1").arg((colr));
    }
    qColor_BtnList[iColorBtn]->setStyleSheet(str);
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2015.5.11
  * brief:      设置提示保存
******************************************************************************/
void w_Conf::Save_Hint()
{
    int i = 0, SetAddress = 0; // -初始状态 0
    QStringList PWR_Data;
    if (!TabWidget_Changed) {
        qDebug() << "return--->w_Conf::Save_Hint() !TabWidget_Changed";
        return;
    }
    for (i = 0; i < (Ini_Number-5); i++) {
        if ((Ini_Proj.at(i).toInt()) == index_c) {
            SetAddress = i;
            break;
        }
    }
    if (SetAddress > Ini_Proj.size()) {
        SetAddress = 0;
    }
    qDebug() << "w_Conf::Save_Hint()" << Ini_Proj.at(SetAddress).toInt();
    switch (Ini_Proj.at(SetAddress).toInt()) {
    case 0:
        Save_ConfData();
        if (CONF != conf_c) {
            conf_c = CONF;
            if (model_Type.indexOf(CONF[13]) >= 0) {
                ui->MotorType->setCurrentIndex(model_Type.indexOf(CONF[13]));
            } else {
                ui->MotorType->setCurrentIndex(0); // -设定文件
            }
            Init_Conf_Interface();
        }
        break;
    case 1:
        WDLR->Pub_Conf_Set_DLR("", 3);
        if (RES != WDLR->Copy_DLR_List) {
            TabWidget_Changed = false;
        }
        break;
    case 2:
        WMAG->Pub_Conf_Set_MAG("", 2);
        if (OPP != WMAG->Copy_MAG_List) {
            TabWidget_Changed = false;
        }
        break;
    case 3:
        WIR->Pub_Conf_Set_IR("", 2);
        if (INS != WIR->Copy_IR_List) {
            TabWidget_Changed = false;
        }
        break;
    case 4:
        WACW->Pub_Conf_Set_ACW("", 2);
        if (ACV != WACW->Copy_ACW_List) {
            TabWidget_Changed = false;
        }
        break;
    case 5:
        WDCW->Pub_Conf_Set_DCW("", 2);
        if (DCV != WDCW->Copy_DCW_List)  {
            TabWidget_Changed = false;
        }
        break;
    case 6:
        WIMP->Pub_Conf_Set_IMP("", 4);
        if (ITT != WIMP->Copy_IMP_List) {
            TabWidget_Changed = false;
        }
        break;
    case 7:
        WPWR->Pub_Conf_Set_PWR(QStringList(""), "", 2);
        if (PWR != WPWR->Copy_PWR_List) {
            TabWidget_Changed = false;
        }
        break;
    case 8:
        WINDL->Pub_Conf_Set_INDL("", 1, 2);
        if (INDL != WINDL->Copy_INDL_List) {
            TabWidget_Changed = false;
        }
        break;
    case 9:
        WBLOCK->Pub_Conf_Set_BLOCK("", 1, 2);
        if (BLOCK != WBLOCK->Copy_BLOCK_List) {
            TabWidget_Changed = false;
        }
        break;
    case 10:
        WLVS->Pub_Conf_Set_LVS("", 2);
        if (LVS != WLVS->Copy_LVS_List) {
            TabWidget_Changed = false;
        }
        break;
    case 11:
        WPG->Pub_Conf_Set_PG(QStringList(""), 2);
        if (BLDCPG != WPG->Copy_BLDCPG_List) {
            TabWidget_Changed = false;
        }
        break;
    case 12:
        WLOAD->Pub_Conf_Set_LOAD("", 2);
        if (LOAD != WLOAD->Copy_LOAD_List) {
            TabWidget_Changed = false;
        }
        break;
    case 13:
         WNoLoad->Pub_Conf_Set_NOLOAD(QStringList(""), 2);
         if (NOLOAD != WNoLoad->Copy_NOLOAD_List) {
             TabWidget_Changed = false;
         }
        break;
    case 14:
         WBEMF->Pub_Conf_Set_BEMF(QString(""), 2);
         if (BEMF != WBEMF->Copy_BEMF_List) {
             TabWidget_Changed = false;
         }
        break;
    case 15:
        WHV->Pub_Conf_Set_HV("", 2);
        if (HV != WHV->Copy_HV_List) {
            TabWidget_Changed = false;
        }
        break;
    default:
        //
        break;
    }
    if (TabWidget_Changed) { // -数据有改动
        qDebug() << "return--->w_Conf::Save_Hint() TabWidget_Changed";
        return;
    }

    ui->stackedWidget->setCurrentIndex(SetAddress);  //  11.11  更改设置
    QMessageBox message;  //= new QMessageBox(this);
    message.setWindowFlags(Qt::FramelessWindowHint);
    message.setStyleSheet("QMessageBox{border:3px groove gray;}"\
                          "background-color: rgb(209,  209, 157);");
    message.setText(tr("       是否进行保存     \n          "));
    message.addButton(QMessageBox::Ok)->setStyleSheet
            ("border:none;height:30px;width:65px;"\
             "border:5px groove gray;border-radius:10px;padding:2px 4px;");
    message.addButton(QMessageBox::Cancel)->setStyleSheet
            ("border:none;height:30px;width:65px;border:5px groove gray;"\
             "border-radius:10px;padding:2px 4px;");
    message.setButtonText(QMessageBox::Ok, QString(tr("确 定")));
    message.setButtonText(QMessageBox::Cancel, QString(tr("取 消")));
    message.setIcon(QMessageBox::Warning);
    int ret = message.exec();
    if (ret == QMessageBox::Ok) {
        SlOT_Button_Function_Judge(Qt::Key_B); // -触发保存
    }
    if (ret == QMessageBox::Cancel) {
        switch (Ini_Proj.at(SetAddress).toInt()) {
        case 0:
            CONF = conf_c;
            if (model_Type.indexOf(CONF[13]) >= 0) {
                ui->MotorType->setCurrentIndex(model_Type.indexOf(CONF[13]));
            } else {
                ui->MotorType->setCurrentIndex(0); // -设定文件
            }
            Init_Conf_Interface();
            break;
        case 1:
            WDLR->Copy_DLR_List = RES;
            WDLR->Pub_Conf_Set_DLR(QString::number(Ini_DCR15), 1);
            WDLR->Pub_Conf_Set_DLR(ui->MotorType->currentText(), 14);
            WDLR->Pub_Conf_Set_DLR(QString::number(Ini_DCR_Balance), 13);
            break;
        case 2:
            WMAG->Copy_MAG_List = OPP;
            WMAG->Pub_Conf_Set_MAG(QString::number(Ini_Mag_Hide), 1);
            WMAG->Pub_Conf_Set_MAG(ui->MotorType->currentText(), 14);
            WMAG->Pub_Conf_Set_MAG(QString::number(Ini_IO_Model), 101);
            break;
        case 3:
            WIR->Copy_IR_List = INS;
            WIR->Pub_Conf_Set_IR(QString::number(Ini_ACW_And_IR), 1);
            break;
        case 4:
            WACW->Copy_ACW_List = ACV;
            WACW->Pub_Conf_Set_ACW(QString::number(Ini_IR5000), 101);
            WACW->Pub_Conf_Set_ACW(QString::number(Ini_ACW_And_IR), 1);
            WACW->Pub_Conf_Set_ACW(QString::number(Ini_ACW_I_Up), 9);
            WACW->Pub_Conf_Set_ACW(QString::number(Ini_ACW_Volt_Limit), 10);
            break;
        case 5:
            WDCW->Copy_DCW_List = DCV;
            WDCW->Pub_Conf_Set_DCW(QString::number(Ini_DCW_Volt_Up), 103);
            WDCW->Pub_Conf_Set_DCW(QString::number(Ini_ACW_And_IR), 1);
            WDCW->Pub_Conf_Set_DCW(QString::number(Ini_DCW_I_Up), 9);
            break;
        case 6:
            WIMP->Copy_IMP_List = ITT;
            WIMP->Pub_Conf_Set_IMP(QString::number(Ini_IMP5000), 101);
            WIMP->Pub_Conf_Set_IMP(Ini_ActiveFile, 1);
            break;
        case 7:
            WPWR->Copy_PWR_List = PWR;
             PWR_Data.clear();
             PWR_Data.append(Ini_Motor);
             PWR_Data.append(QString::number(Ini_Set_pwr_Turn));
             WPWR->Pub_Conf_Set_PWR(PWR_Data, Ini_Motor, 1);
             WPWR->Pub_Conf_Set_PWR(QStringList(""), QString::number(Ini_Pwr_Turn), 6);
            break;
        case 8:
            WINDL->Copy_INDL_List = INDL;
            WINDL->Pub_Conf_Set_INDL("", 1, 1);
            break;
        case 9:
            WBLOCK->Copy_BLOCK_List = BLOCK;
            WBLOCK->Pub_Conf_Set_BLOCK("", 1, 1);
            break;
        case 10:
            WLVS->Copy_LVS_List = LVS;
            WLVS->Pub_Conf_Set_LVS(QString(""), 1);
            break;
        case 11:
             //
             break;
        case 12:
             //
             break;
        case 13:
             //
             break;
        case 14:
             //
             break;
        case 15:
            WHV->Copy_HV_List = HV;
            WHV->Pub_Conf_Set_HV(QString::number(Ini_IR5000), 101);
            WHV->Pub_Conf_Set_HV(QString::number(Ini_ACW_And_IR), 1);
            break;
        default:
            //
            break;
        }
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.6.6
  * brief:      选定 测试项目
******************************************************************************/
void w_Conf::on_test_clicked(const QModelIndex &index)
{
    int i = 0;
    btnGroup_Item->button(0)->hide();
    btnGroup_Item->button(20)->hide();
    Item_Chose_Box->hide();
    Item_Chose_Box->setChecked(true);
    if ((index.row() + 1) <= (test_Inifile.size())) {
        btnGroup_Item->button(0)->show();
        btnGroup_Item->button(20)->show();
        Item_Chose_Box->show();
        if (ui->test->item(index.row(), 0)->textColor().name() != "#008000") {
            Item_Chose_Box->setChecked(false);
        }
    }
    for (i = 1; i <= 10; i++) { // -设置组不能超过--两组
        if (test_Inifile.indexOf(QString::number(i)) < 0) {
            continue;
        }
        if (test_Inifile.indexOf(QString::number(i), \
                                 (1+test_Inifile.indexOf(QString::number(i)))) >= 0) {
            btnGroup_Item->button(i)->hide();
        }
    }
    remove_row = index.row();
    Conf_label_Hide->show();
    Item_Widget->show();     Item_Widget->raise();
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      添加文件
******************************************************************************/
void w_Conf::on_fileBtnAdd_clicked()
{
    int i = 0;
    char copystr[256];
    QString currentDateTime = QDateTime::currentDateTime().toString\
            ("yyyy-MM-dd hh:mm:ss"); // -设置显示格式
    if (ui->fileEdit1->text() != NULL) {
        for (i = 0; i < currentFile.size(); i++) {
            if (ui->fileEdit1->text() == currentFile.at(i)) {
                ui->label_Text->setText(tr("型号名称重復"));
                break;
            }
        }
        if (i == currentFile.size()) {
            currentFile.append(ui->fileEdit1->text());
            DateFile.append(currentDateTime);
            Save_Ini_DateFile();

            Init_Conf_file(currentFile.size(), currentFile);
            ui->fileTab->verticalScrollBar()->setValue(ui->fileTab->rowCount());
            //更新数据
            sprintf(copystr, "touch /mnt/nandflash/AIP/ConfFile/%s.ini", \
                    QString(ui->fileEdit1->text()).toUtf8().data());
            system(copystr);
            sprintf(copystr, "chmod +x /mnt/nandflash/AIP/ConfFile/%s.ini", \
                    QString(ui->fileEdit1->text()).toUtf8().data());
            system(copystr);
            QString Filename;   Filename = QString("/mnt/nandflash/AIP/ConfFile/%1.ini").\
                    arg(ui->fileEdit1->text());
            QSettings set_File(Filename, QSettings::IniFormat);
            for (i = 0; i < parameter.size(); i++) {
                set_File.setValue(QString("%1/value").arg(parameter[i]), strList[i]);
            }
            QSettings set_Test_File(Test_File_path,  QSettings::IniFormat);
            set_Test_File.setIniCodec("UTF-8");
            set_Test_File.setValue(QString("Test_File/%1").arg \
                                   (ui->fileEdit1->text()), test_Inifile);
            ui->label_Text->setText(QString(tr("当前文件：")) + Ini_ActiveFile);
            on_fileTab_cellClicked(currentFile.size()-1, 0);
        }
        ui->fileEdit1->clear();
    } else {
        Pri_Conf_WMessage(QString(tr("请输入型号名称")));
    }
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      删除文件
******************************************************************************/
void w_Conf::on_fileBtnDel_clicked()
{
    QMessageBox Quick_Set_Ask;
    Quick_Set_Ask.setWindowFlags(Qt::FramelessWindowHint);
    Quick_Set_Ask.setStyleSheet("QMessageBox{border:3px groove gray;}"\
                                "background-color: rgb(209, 209, 157);");
    Quick_Set_Ask.setText(tr("       确定刪除当前文件     \n          "));
    Quick_Set_Ask.addButton(QMessageBox::Ok)->setStyleSheet
            ("border:none;height:30px;width:65px;border:5px groove gray;"\
             "border-radius:10px;padding:2px 4px;");
    Quick_Set_Ask.addButton(QMessageBox::Cancel)->setStyleSheet
            ("border:none;height:30px;width:65px;border:5px groove gray;"\
             "border-radius:10px;padding:2px 4px;");
    Quick_Set_Ask.setButtonText(QMessageBox::Ok, QString(tr("确 定")));
    Quick_Set_Ask.setButtonText(QMessageBox::Cancel, QString(tr("取 消")));
    Quick_Set_Ask.setIcon(QMessageBox::Warning);
    int ret = Quick_Set_Ask.exec();
    if (ret == QMessageBox::Ok) {
        Delete_File();
    } else {
        //
    }
    if (ret == QMessageBox::Cancel) {
        //
    } else {
        //
    }
}

void w_Conf::Delete_File() {
    char copystr[256];
    ui->fileTab->currentRow();

    if (currentFile.at(0) != "Base_File") {
        currentFile.removeAt(0);   DateFile.removeAt(0);
        Save_Ini_DateFile();

        sprintf(copystr, "rm /mnt/nandflash/AIP/ConfFile/%s.ini", \
                QString(Ini_ActiveFile).toUtf8().data());
        system(copystr);

        QSettings set_Test_File(Test_File_path, QSettings::IniFormat);
        set_Test_File.setIniCodec("UTF-8");
        set_Test_File.remove(QString("Test_File/%1").arg(Ini_ActiveFile));

        Init_Conf_file(currentFile.size(), currentFile);
        on_fileTab_cellClicked(0, 0);
    } else if (currentFile.at(0) == "Base_File") {
        Pri_Conf_WMessage(QString(tr("Base_File不能删除  ")));
    } else {
        //
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.5.1
  * brief:      Can发送数据 触发
******************************************************************************/
void w_Conf::SlOT_CanSendFrame(can_frame frame)
{
    emit canSend(frame, 88); // -总触发
}

void w_Conf::SlOT_Receive_3_6_test(int data) {
    Singal_Conf_to_Main(QStringList(""), QString(""), data, 6);
}

void w_Conf::SlOT_CanSendFrame_PWR(can_frame frame, int Usart) {
    if (Usart == 1) {
        PWR_Test_Usart = true;
    } else {
        //
    }
    emit canSend(frame, 88);  // 总触发
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.7.19
  * brief:      电感清0
******************************************************************************/
void w_Conf::SlOT_Lable_Display()
{
    lable_Zero->show();
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.5.8
  * brief:      温度进行补偿
******************************************************************************/
void w_Conf::DLR_Compensate_Back(QStringList list)
{
    int DLR_Compensate = 0;
    DLR_Compensate = WDLR->Pub_Conf_DLR_Compensate(list);
    if (DLR_Compensate == 1) {
        ui->Key_D->setStyleSheet("background:#00FF00; color:rgb(0, 0,  0);");
        ui->Key_D->setText(tr("左OK"));  // -已补偿
    } else if (DLR_Compensate == 2) {
        ui->Key_D->setStyleSheet("background: qlineargradient"\
                                 "(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #5B5F5F, "\
                                 "stop: 0.5 #0C2436,stop: 1 #27405A);color:rgb(255, 255, 255);");
        ui->Key_D->setText(tr("左清零")); // -未补偿

        Pri_Conf_WMessage(tr("     左工位补偿错误    "));
        Conf_Net_WMessage("Left Compensate Error");
    } else if (DLR_Compensate == 3) {
        ui->Key_E->setStyleSheet("background:#00FF00; color:rgb(0, 0, 0);");
        ui->Key_E->setText(tr("右OK"));  // -已补偿
    } else if (DLR_Compensate == 4) {
        ui->Key_E->setStyleSheet("background: qlineargradient"\
                                 "(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #5B5F5F, "\
                                 "stop: 0.5 #0C2436,stop: 1 #27405A);color:rgb(255, 255, 255);");
        ui->Key_E->setText(tr("右清零")); // -未补偿
        Pri_Conf_WMessage(tr("    右工位补偿错误    "));
        Conf_Net_WMessage("Right Compensate Error");
    } else {
        //
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.5.10
  * brief:      设置操作员和管理者
******************************************************************************/
void w_Conf::Conf_Set_User(int value)
{
    int id = value/1000;
    int changer_number = value%1000;
    if (Conf_User == User_Administrators) {
        ui->label_User->hide(); // -可以设置
        ui->fileEdit1->setEnabled(true);
        ui->fileBtnAdd->setEnabled(true);
        ui->fileBtnCheck->setEnabled(true);
        ui->fileBtnDel->setEnabled(true);
    } else {
        //
    }

    if ((Conf_User == User_Operator) && (!conf_Waring)) {
        ui->label_User->show(); // -不可以设置
        ui->label_User->raise();
        ui->fileEdit1->setDisabled(true);
        ui->fileBtnAdd->setDisabled(true);
        ui->fileBtnCheck->setDisabled(true);
        ui->fileBtnDel->setDisabled(true);
    } else {
        //
    }

    if (changer_number != 0) {
        on_fileTab_cellClicked(changer_number, 0);
    } else {
        //
    }

    ui->imp_button_add->hide();
    ui->imp_button_cancel->hide();
    ui->imp_button_finsh->hide();
    if (id < 100) {
        if ((Conf_User == User_Operator) && (!conf_Waring)) {
            ui->label_User->setGeometry(0, 0, 721, 600);
            ui->label_User->move(0, 0);
        }
        SlOT_Button_Conf_Judge(48+id); // -进入到设置首页
    } else {
        ui->label_User->setGeometry(299, 0, 401, 600);
        SlOT_Button_Conf_Judge(48);   // -进入到设置首页
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.5.19
  * brief:      配置查询文件和型号
******************************************************************************/
void w_Conf::on_fileBtnCheck_clicked()
{
    int i = 0;
    int Error_Flag = 0;
    QStringList Check_File;
    if (ui->fileEdit1->text() == "") {
        Error_Flag = 1;
    } else if (ui->fileEdit1->text() != "") {
        Check_File.clear();
        for (i = 0; i < currentFile.size(); i++) {
            if (!(ui->fileTab->item(i, 0) == NULL)) {
                if (ui->fileTab->item(i, 0)->text().contains\
                        (ui->fileEdit1->text(), Qt::CaseInsensitive)) {
                    Check_File.append(ui->fileTab->item(i, 0)->text());
                    Error_Flag = 2;
                }
            }
        }
        if (Error_Flag == 2) {
            Init_Conf_file(Check_File.size(), Check_File);
        }
    } else {
        //
    }
    if (Error_Flag == 0) {
        Pri_Conf_WMessage(tr("       当前查询不存在       "));
    }
    if (Error_Flag == 1) {
        Save_Ini_DateFile();
        Init_Conf_file(currentFile.size(), currentFile);
    }
    ui->fileEdit1->clear(); // -文件和型号清空
}

void w_Conf::Conf_Net_WMessage(QString data) {
    if (Ini_Vacuum_Model) {
        WriteMessage(6000, CMD_Test_Message, data.toUtf8());
    } else {
        //
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.5.19
  * brief:      设置警告弹出框
******************************************************************************/
void  w_Conf::Pri_Conf_WMessage(QString Waring_Text)
{
    if (Ini_Vacuum_Model) {
        //
    } else {
        conf_Waring = true;   label_Waring->show();
        QMessageBox *message = new QMessageBox(this);
        message->setWindowFlags(Qt::FramelessWindowHint);
        message->setStyleSheet("QMessageBox{border: gray;border-radius: 10px;"\
                               "padding:2px 4px;background-color: gray;height:390px;width:375px;}");
        message->setText("\n"+Waring_Text+"\n");
        message->addButton(QMessageBox::Ok)->setStyleSheet("height:39px;width:75px;"\
                             "border:5px groove;border:none;border-radius:10px;padding:2px 4px;");
        message->setButtonText(QMessageBox::Ok, QString(tr("确 定")));
        message->setIcon(QMessageBox::Warning);
        message->exec();
        conf_Waring = false;   label_Waring->hide();
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.5.19
  * brief:      单击文件列表  更换数据管理型号
******************************************************************************/
void w_Conf::on_fileTab_cellClicked(int row, int column)
{
    int i = 0, Count = 0;
    if (!Clicked) {
        return;
    }
    column = 0;
    label_Waring->show();
    Clicked = false;
    if (Ini_Proj[ui->stackedWidget->currentIndex()].toInt() == 0) {
        if (row < 0) {
            label_Waring->hide();
            Clicked = true;
            return;
        }
        if (row >= (checked_File.size())) {
            label_Waring->hide();
            Clicked = true;
            return;
        }
        if (checked_File.at(row) == Ini_ActiveFile) {
            label_Waring->hide();
            Clicked = true;
            return;
        }
        for (i = 0; i < currentFile.size(); i++) {
            if (ui->fileTab->item(row, 0)->text() == currentFile.at(i)) { // -设置背景
                Count = i;
                break;
            }
        }
        QSettings *set_Sys = new QSettings(Sys_path, QSettings::IniFormat);
        set_Sys->setIniCodec("GB18030");
        set_Sys->setValue("ActiveFile/file", ui->fileTab->item(row, 0)->text());
        system("sync");
        delete set_Sys;
        currentFile.removeAt(i);
        currentFile.insert(0, ui->fileTab->item(row, 0)->text());
        DateFile.removeAt(i);
        DateFile.insert(0, QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
        Save_Ini_DateFile();
        Sync_Conf();
    }
    label_Waring->hide();
    Clicked = true;
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.7.19
  * brief:      测试界面和配置界面传递信息
******************************************************************************/
void w_Conf::Slot_test_to_conf(QStringList list, QString str, int value)
{
    str.clear();
    switch (value) {
    case 1:
        Save_Test_Data(list);
        break;
    case 2:
        WIR->Pub_Conf_Set_IR(QString::number(Ini_IRHostJudge), 5); // -测试绝缘启动
        break;
    case 3:
        WACW->Pub_Conf_Set_ACW(" ", 5); // -测试交耐启动
        break;
    case 4:
        WDCW->Pub_Conf_Set_DCW(" ", 5); // -测试直耐启动
        break;
    default:
        break;
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.7.28
  * brief:      测试数据的保存
******************************************************************************/
void w_Conf::Save_Test_Data(QStringList all_data)
{
    int i = 0;
    QStringList Result, Judge, Get_Set;
    Result  = all_data.mid(3, all_data.at(0).toInt());                        // -结果
    Judge   = all_data.mid(3+all_data.at(0).toInt(), all_data.at(1).toInt()); // -判定
    Get_Set = all_data.mid(3+all_data.at(0).toInt()+all_data.at(1).toInt(), \
                           all_data.at(2).toInt()); // -数据
 /* QStringList_No_OK = all_data.mid(4+all_data.at(0).toInt()+ \
    all_data.at(1).toInt()+all_data.at(2).toInt(),all_data.at(3).toInt()); // -不合格项目

    QSqlQuery query(sql.db);
    sql.db.transaction(); */

    if (strTest.size() != Judge.size()) { // -补齐判定数据
        for (i = Judge.size(); i < strTest.size(); i++) {
            Judge.append("");
        }
    }
    if (strTest.size() != Result.size()) { // -补齐结果数据
        for (i = Result.size(); i < strTest.size(); i++) {
            Result.append("");
        }
    }

    for (i = 0; i < strTest.size(); i++) { // -判断测试结果中是否包含","   ","替换为 "，"
        if ((strTest.at(i).contains(tr("绝缘"))) || \
                (strTest.at(i).contains(tr("交耐"))) || \
                (strTest.at(i).contains(tr("直耐"))) || \
                (strTest.at(i).contains(tr("匝间"))) || \
                (strTest.at(i).contains(tr("电感"))) || \
                (strTest.at(i).contains(tr("堵转"))) || \
                (strTest.at(i).contains(tr("电参"))) || \
                (strTest.at(i).contains(tr("低启"))) || \
                (strTest.at(i).contains(tr("PG")))   || \
                (strTest.at(i).contains(tr("空载"))) || \
                (strTest.at(i).contains(tr("HALL"))) || \
                (strTest.at(i).contains(tr("HV")))) {   //  绝缘 交耐 匝间
            strParam.replace(i, QString(strParam.at(i)).replace(QRegExp("\\,"),  " "));
            // 2017 3 10 印度问题改变","--" "
        }
        if ((strTest.at(i).contains(tr("电阻"))) || \
                (strTest.at(i).contains(tr("绝缘")))) {
            strParam.replace(i, QString(strParam.at(i)).replace(QRegExp("\\Ω"),  " "));
        }
    }

    for (i = 0; i < Judge.size(); i++) {
        if (strTest.at(i).contains(tr("电阻"))) {     // -电阻参数
            Result.replace(i, QString(Result.at(i)).replace(QRegExp("\\Ω"), ""));
        } else if (strTest.at(i).contains(tr("绝缘"))) { // -绝缘
            Result.replace(i, QString(Result.at(i)).mid \
                  (QString(Result.at(i)).indexOf(",")+1, QString(Result.at(i)).length()));
            Result.replace(i, QString(Result.at(i)).replace(QRegExp("\\MΩ"),  ""));
        } else if (strTest.at(i).contains(tr("交耐"))) { // -交耐
            Result.replace(i, QString(Result.at(i)).mid \
                  (QString(Result.at(i)).indexOf(",")+1, QString(Result.at(i)).length()));
            Result.replace(i, QString(Result.at(i)).replace(QRegExp("\\mA"), ""));
        }  else if (strTest.at(i).contains(tr("搭线"))) { // -搭线
            Result.replace(i, QString(Result.at(i)).mid \
                  (QString(Result.at(i)).indexOf(",")+1, QString(Result.at(i)).length()));
            Result.replace(i, QString(Result.at(i)).replace(QRegExp("\\mA"), ""));
        }  else if (strTest.at(i).contains(tr("直耐"))) { // -直耐
            Result.replace(i, QString(Result.at(i)).mid \
                  (QString(Result.at(i)).indexOf(",")+1, QString(Result.at(i)).length()));
            Result.replace(i, QString(Result.at(i)).replace(QRegExp("\\mA"), ""));
        } else if (strTest.at(i).contains(tr("匝间"))) { // -匝间 若没有(电晕,相位)时进行补齐
            if ((QStringList(QString(Result.at(i)).split(",")).size()-1) == 1) {
                Result.replace(i, QString(Result.at(i)).append(", , "));
            } else if ((QStringList(QString(Result.at(i)).split(",")).size()-1) == 3) {
                //
            } else {
                Result.replace(i, " , , , ");
            }
        } else if (strTest.at(i).contains(tr("电感"))) { // -电感 若没有(Q值)时进行补齐
            if ((QStringList(QString(Result.at(i)).split(",")).size()-1) == 0) {
                 Result.replace(i, QString(Result.at(i)).append(", "));
            } else {
                //
            }
        } else if (strTest.at(i).contains(tr("电参"))) { // -电参
            if ((QStringList(QString(Result.at(i)).split(",")).size()-1) == 2) {
                Result.replace(i, QString(Result.at(i)).replace(QRegExp("[A-Z]"),  " "));
            } else {
                Result.replace(i, " , , ");
            }
        } else if (strTest.at(i).contains(tr("堵转"))) { // -堵转
            if ((QStringList(QString(Result.at(i)).split(",")).size()-1) == 1) {
                Result.replace(i, QString(Result.at(i)).replace(QRegExp("[A-Z]"),  " "));
            } else {
                Result.replace(i, " , ");
            }
        } else if (strTest.at(i).contains(tr("低启"))) { // -低启
            if ((QStringList(QString(Result.at(i)).split(",")).size()-1) == 1) {
                Result.replace(i, QString(Result.at(i)).replace(QRegExp("[A-Z]"),  " "));
            } else {
                Result.replace(i, " , ");
            }
        } else if (strTest.at(i).contains(tr("PG"))) { // -PG
            Result.replace(i, QString(Result.at(i)).replace(QRegExp("\\,"),  " "));
        } else if (strTest.at(i).contains(tr("空载"))) { // -空载
            Result.replace(i, QString(Result.at(i)).replace(QRegExp("\\,"),  " "));
        } else if (strTest.at(i).contains(tr("HALL"))) { // -HALL
            Result.replace(i, QString(Result.at(i)).replace(QRegExp("\\,"),  " "));
        } else {
           //
        }
    }

    QStringList SQL_Item, SQL_Param, SQL_Result, SQL_Judge;

    SQL_Item.append("ITEM-1");         // -ITEM-1
    SQL_Item.append("ITEM-2");         // -ITEM-2
    SQL_Item.append("ITEM-3");         // -ITEM-3

    SQL_Param.append(Get_Set.at(3));   // -date
    SQL_Param.append(Get_Set.at(2));   // -时间
    SQL_Param.append(Get_Set.at(5));   // -编号

    SQL_Result.append(Ini_ActiveFile); // -当前型号
    SQL_Result.append(Get_Set.at(4));  // -温度
    SQL_Result.append(Get_Set.at(6));  // -用户

    SQL_Judge.append(Get_Set.at(1));   // -总结果
    SQL_Judge.append(Get_Set.at(0));   // -工位
    SQL_Judge.append(QString::number(Judge.size())); // -总测试项目

    SQL_Item.append(strTest);
    SQL_Param.append(strParam);
    SQL_Result.append(Result);
    SQL_Judge.append(Judge);


    /*QString QStringList_OK, QStringList_No_OK;
    QStringList_OK.clear();
    QStringList_No_OK.clear();
    QString s;

    for (i = 0; i < 19; i++) { // 柱状图的测试数据进行清空
        Error_Item[i] = 0;
        Error_Item_Count[i] = 0;
    }

    for (i = 0; i < strTest.size(); i++) {
        if (strTest.at(i) == (tr("磁旋"))) {
            if (Judge[i] == "OK") {
                QStringList_OK += tr("磁旋 ");
            } else {
                QStringList_No_OK += tr("磁旋 ");
            }
            continue;
        } else if (strTest.at(i) == (tr("转向"))) {
            if (Judge[i] == "OK") {
                QStringList_OK += (tr("转向 "));
            } else {
                QStringList_No_OK += (tr("转向 "));
            }
            continue;
        } else if (strTest.at(i).contains(tr("PG"))) {
            if (Judge[i] == "OK") {
                QStringList_OK += tr("PG ");
            } else {
                QStringList_No_OK += tr("PG ");
            }
            continue;
        } else {
            //
        }

        if (Judge[i] == "OK") {
            continue;
        }
        int k = 0;
        for (int t = 0; t < Test_Item.size(); t++) {
            if (strTest.at(i).contains(Test_Item.at(t))) {
                k = t;
                break;
            }
        }

        if (k <= 16) {
            Error_Item_Count[k]++;
            if (Error_Item_Count[k] == 1) {
                QStringList_No_OK += ((Test_Item.at(k))+" ");
                Error_Item[k]++;
            } else {
                //
            }
        } else {
            //
        }
    } */


//    for (i = 0; i < Conf_Test.size(); i++) { // 10-29 Hide
//        if (QStringList_No_OK.contains(Test_Item.at(Conf_Test.at(i).toInt()))) {
//            //
//        } else {
//            QStringList_OK += (Test_Item.at(Conf_Test.at(i).toInt())+" ");
//        }
//    }

 /*   int id = sql.selectMax("TestDa");
    query.prepare(QString(tr("insert into TestDa (id,项目,参数,结果,判定,配置)"\
                             "values(:id,:项目,:参数,:结果,:判定,:配置)")));
    for (i = 0; i < SQL_Item.size(); i++) {
//        qDebug() << "SQL_Item.at(i)" << SQL_Item.at(i);
//        qDebug() << "SQL_Param.at(i)" << SQL_Param.at(i);
//        qDebug() << "SQL_Result.at(i)" << SQL_Result.at(i);
//        qDebug() << "SQL_Judge.at(i)" << SQL_Judge.at(i);
//        qDebug() << QStringList_OK + "------" + QStringList_No_OK;
        id = id + 1;
        query.bindValue(tr(":id" ), id);
        query.bindValue(tr(":项目"), SQL_Item.at(i));
        query.bindValue(tr(":参数"), SQL_Param.at(i));
        query.bindValue(tr(":结果"), SQL_Result.at(i));
        query.bindValue(tr(":判定"), SQL_Judge.at(i));
        if (i > 0) {
            query.bindValue(tr(":配置"), tr(""));
        } else {
            query.bindValue(tr(":配置"), QStringList_OK + QStringList_No_OK + "------" + QStringList_No_OK);
        }
        query.exec();
    }
    sql.db.commit(); */

    QStringList tmpList;
       for (int i=0; i < strTest.size(); i++) {
           QString tmpStr;
           tmpStr.append(strTest.at(i));
           tmpStr.append("@");
           tmpStr.append(strParam.at(i));
           tmpStr.append("@");
           if (i < Result.size())
               tmpStr.append(Result.at(i));
           else
               tmpStr.append("");
           tmpStr.append("@");
           if (i < Judge.size())
               tmpStr.append(Judge.at(i));
           else
               tmpStr.append("");
           tmpList.append(tmpStr);
       }
       QVariantMap tmpMap;
       tmpMap.insert("enum", QMessageBox::Save);
       tmpMap.insert("post", Get_Set.at(0));  // 工位
       tmpMap.insert("pass", Get_Set.at(1));  // 总判定
       tmpMap.insert("time", Get_Set.at(2));  // 时间
       tmpMap.insert("date", Get_Set.at(3));  // 日期
       tmpMap.insert("temp", Get_Set.at(4));  // 温度
       tmpMap.insert("numb", Get_Set.at(5));  // 编码
       tmpMap.insert("user", Get_Set.at(6));  // 用户
       tmpMap.insert("type", Ini_ActiveFile);  // 型号
       tmpMap.insert("data", tmpList.join("\n"));
       emit sendAppMap(tmpMap);
       tmpMap.clear();
   /* for (i = 0; i < QStringList_OK.size(); i++) {
        s.clear();
        s = QString(tr("%1@%2@OK")).arg(QStringList_OK.at(i)).arg(SQL_Result.at(0));
        WConf_WriteSql(s.toUtf8());
    }
    for (i = 0; i < QStringList_No_OK.size(); i++) {
        s.clear();
        s = QString(tr("%1@%2@NG")).arg(QStringList_No_OK.at(i)).arg(SQL_Result.at(0));
        WConf_WriteSql(s.toUtf8());
    }
    for (i = 3; i < SQL_Item.size(); i++) {
        s.clear();
        s.append(sql_Test.at(i-3) + "@" + SQL_Item.at(i) + " " + SQL_Param.at(i) + \
                 "@" + SQL_Result.at(i) + "@" + SQL_Judge.at(i));
        WConf_WriteSql(s.toUtf8());
    }
    s = QString(tr("总数@%1@%2")).arg(SQL_Result.at(0)).arg(SQL_Judge.at(0));
    WConf_WriteSql(s.toUtf8()); */

    if ((Ini_Udp_Enable) || (NetSQL_OpenOk)) { // -
        if (SQL_Item.at(1) == "ITEM-2") {
            SQL_Result.replace(1, QString(SQL_Result.at(1)).replace(QRegExp("\\°C"), "C"));
            if (SQL_Judge.at(1) == QString(tr("左工位"))) {
                SQL_Judge.replace(1, "Left");
            } else {
                SQL_Judge.replace(1, "Right");
            }
        }
        if (SQL_Item.at(2) == "ITEM-3") {
            if (SQL_Result.at(2) == QString(tr("管理员"))) {
                SQL_Result.replace(2, "Admin");
            } else {
                SQL_Result.replace(2, "Guest");
            }
        }
        for (i = 0; i < SQL_Item.size(); i++) {
            if (SQL_Item.at(i).contains(tr("电阻"))) {
                SQL_Item.replace(i, QString(SQL_Item.at(i)).replace\
                                 (QRegExp(tr("\\电阻")),  "DCR"));
                SQL_Param.replace(i, QString(SQL_Param.at(i)).replace\
                                  (QRegExp("\\Ω"),  "ohm"));
                SQL_Result.replace(i, QString(SQL_Result.at(i)).replace\
                                   (QRegExp("\\Ω"),  ""));
                SQL_Param.replace(i, QString(SQL_Param.at(i)).\
                                  replace(QRegExp(tr("\\不平衡度")),  "Banlance--"));
            } else if (SQL_Item.at(i).contains(tr("反嵌"))) {
                SQL_Item.replace(i, QString(SQL_Item.at(i)).\
                                 replace(QRegExp(tr("\\反嵌")),  "MAG"));
            } else if (SQL_Item.at(i).contains(tr("磁旋"))) {
                SQL_Item.replace(i, QString(SQL_Item.at(i)).\
                                 replace(QRegExp(tr("\\磁旋")),  "DIR"));
                SQL_Param.replace(i, QString(SQL_Param.at(i)).\
                                  replace(QRegExp(tr("\\正转")), "CW"));
                SQL_Param.replace(i, QString(SQL_Param.at(i)).\
                                  replace(QRegExp(tr("\\反转")), "CCWW"));
                SQL_Result.replace(i, QString(SQL_Result.at(i)).\
                                   replace(QRegExp(tr("\\正转")), "CW"));
                SQL_Result.replace(i, QString(SQL_Result.at(i)).\
                                   replace(QRegExp(tr("\\反转")), "CCW"));
                SQL_Result.replace(i, QString(SQL_Result.at(i)).\
                                   replace(QRegExp(tr("\\不转")), "NO"));
            } else if (SQL_Item.at(i).contains(tr("绝缘"))) {
                SQL_Item.replace(i, QString(SQL_Item.at(i)).\
                                 replace(QRegExp(tr("\\绝缘")), "IR"));
                SQL_Param.replace(i, QString(SQL_Param.at(i)).\
                                  replace(QRegExp("\\Ω"),  "ohm"));
                SQL_Result.replace(i, QString(SQL_Result.at(i)).\
                                   replace(QRegExp("\\Ω"), ""));
            } else if (SQL_Item.at(i).contains(tr("交耐"))) {
                SQL_Item.replace(i, QString(SQL_Item.at(i)).\
                                 replace(QRegExp(tr("\\交耐")),  "ACHV"));
            }  else if (SQL_Item.at(i).contains(tr("直耐"))) {
                SQL_Item.replace(i, QString(SQL_Item.at(i)).\
                                 replace(QRegExp(tr("\\直耐")),  "DCHV"));
            } else if (SQL_Item.at(i).contains(tr("匝间"))) {
                SQL_Item.replace(i, QString(SQL_Item.at(i)).\
                                 replace(QRegExp(tr("\\匝间")), "SURGE"));
                SQL_Param.replace(i, QString(SQL_Param.at(i)).\
                                  replace(QRegExp(tr("\\面积")), " Area"));
                SQL_Param.replace(i, QString(SQL_Param.at(i)).\
                                  replace(QRegExp(tr("\\差积")), " Diff"));
                SQL_Result.replace(i, QString(SQL_Result.at(i)).\
                                   replace(QRegExp(tr("\\面积")), " Area"));
                SQL_Result.replace(i, QString(SQL_Result.at(i)).\
                                   replace(QRegExp(tr("\\差积")), " Diff"));
            } else if (SQL_Item.at(i).contains(tr("电感"))) {
                SQL_Item.replace(i, QString(SQL_Item.at(i)).\
                                 replace(QRegExp(tr("\\电感")),  "IND"));
                SQL_Param.replace(i, QString(SQL_Param.at(i)).\
                                  replace(QRegExp(tr("\\不平衡度")), "Banlance--"));
            } else if (SQL_Item.at(i).contains(tr("电参"))) {
                SQL_Item.replace(i, QString(SQL_Item.at(i)).\
                                 replace(QRegExp(tr("\\电参")), "POWER"));
            } else if (SQL_Item.at(i) == (tr("转向"))) {
                SQL_Item.replace(i, QString(SQL_Item.at(i)).\
                                 replace(QRegExp(tr("\\转向")), "T"));
                SQL_Param.replace(i, QString(SQL_Param.at(i)).\
                                  replace(QRegExp(tr("\\正转")), "CW"));
                SQL_Param.replace(i, QString(SQL_Param.at(i)).\
                                  replace(QRegExp(tr("\\反转")),  "CCW"));
                SQL_Result.replace(i, QString(SQL_Result.at(i)).\
                                   replace(QRegExp(tr("\\正转")), "CW"));
                SQL_Result.replace(i, QString(SQL_Result.at(i)).\
                                   replace(QRegExp(tr("\\反转")), "CCW"));
                SQL_Result.replace(i, QString(SQL_Result.at(i)).\
                                   replace(QRegExp(tr("\\不转")), "NO"));
            } else if (SQL_Item.at(i).contains(tr("堵转"))) {
                SQL_Item.replace(i, QString(SQL_Item.at(i)).\
                                 replace(QRegExp(tr("\\堵转")), "BLOCK"));
            } else if (SQL_Item.at(i).contains(tr("低启"))) {
                SQL_Item.replace(i, QString(SQL_Item.at(i)).\
                                 replace(QRegExp(tr("\\低启")), "LVS"));
            } else if (SQL_Item.at(i).contains(tr("PG"))) {
                SQL_Item.replace(i, QString(SQL_Item.at(i)).\
                                 replace(QRegExp(tr("\\PG")), "PG"));
            } else {
                //
            }
        }
    }

    if (Ini_Udp_Enable) { // -UDP上传
        QString UDP_Data;
        for (i = 0; i < SQL_Item.size(); i++) {
            UDP_Data += "(" + SQL_Item.at(i) + ")(" + SQL_Param.at(i) + \
                    ")(" + SQL_Result.at(i)+")(" + SQL_Judge.at(i)+")";
        }
        WriteMessage_NoVacuum(6000, CMD_Put_ITEM, UDP_Data.toUtf8());
        WriteMessage_NoVacuum(6000, CMD_Put_STATUS_Cheak, ("free"));
    } else {
        //
    }

    if (NetSQL_OpenOk) { // -网络数据库
        QSqlQuery query_net(sql_net.dbtwo);
        int id = sql_net.selectMax_net(Ini_Factory);
        query_net.prepare(QString(("insert into %1 (id,项目,参数,结果,判定)""values(?,?,?,?,?)"))\
                          .arg(Ini_Factory)); // ,配置,?
        for (i = 0; i < SQL_Item.size(); i++) {
            id = id+1;
            query_net.bindValue(0, id);
            query_net.bindValue(1, SQL_Item.at(i));
            query_net.bindValue(2, SQL_Param.at(i));
            query_net.bindValue(3, SQL_Result.at(i));
            query_net.bindValue(4, SQL_Judge.at(i));
            query_net.exec();
            sql_net.dbtwo.commit();
        }
    } else {
        //
    }
    system("sync");
    qDebug() << "w_Conf::Save_Test_Data Finsh";
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.7.28
  * brief:      调试数据的保存
******************************************************************************/
void w_Conf::Slot_Save_Debug(QString Name, QString Data)
{
    // 保存数据文件进行保存数据(ini)文件进行
    QString currentDateTime = QDateTime::currentDateTime().\
            toString("yyyy-MM-dd-hh-mm-ss"); // -设置显示格式
    QString qname;
    QSettings set_Test_File(Test_Debug_path, QSettings::IniFormat);
    set_Test_File.setIniCodec("GB2312");

    QDir *temp = new QDir;
    bool exist = temp->exists(Test_Debug_path);
    if (exist) {
        qname = QString("%1/%2").arg(currentDateTime).arg(Name);
        set_Test_File.setValue(qname, Data);
    } else {
        system("mkdir /mnt/nandflash/AIP/debug/");
        system("touch /mnt/nandflash/AIP/debug/debug.ini");
        system("chmod +x /mnt/nandflash/AIP/debug/debug.ini");
        qname = QString("%1/%2").arg(currentDateTime).arg(Name);
        set_Test_File.setValue(qname, Data);
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.7.19
  * brief:      电阻板测试电阻信息，用于快速设置和测试补偿
******************************************************************************/
QStringList w_Conf::Board_DLR_TestData(can_frame canframe)
{
    return WDLR->DCR_Test_Quick_Result(canframe);
//    QStringList Back_QStringList; Back_QStringList.clear();
//    if ((canframe.data[2] == 1) || (canframe.data[2] == 2)) {
//        // -档位（1，2）-"mΩ"
//        Back_QStringList.append(QString::number((canframe.data[3]*256+canframe.data[4])* \
//                (qPow(10, -(6-canframe.data[2])))*1000));  //
//        Back_QStringList.append("mΩ");
//    } else if ((canframe.data[2] == 3) || (canframe.data[2] == 4) || (canframe.data[2] == 5)) {
//        // -档位（3，4，5）-"Ω"
//        Back_QStringList.append(QString::number((canframe.data[3]*256+canframe.data[4])*\
//                (qPow(10, -(6-canframe.data[2])))));  //
//        Back_QStringList.append("Ω");
//    } else if ((canframe.data[2] == 6) || (canframe.data[2] == 7) || (canframe.data[2] == 8)) {
//        // -档位（6，7，8）-"KΩ" 其中（7，8）暂时未用到
//        Back_QStringList.append(QString::number((canframe.data[3]*256+canframe.data[4])*\
//                (qPow(10, (canframe.data[2]-6)))/1000));  //
//        Back_QStringList.append("KΩ");
//    }
//    Back_QStringList.append(QString::number(canframe.data[1]));
//    if (canframe.data[2] < 6) {
//        Back_QStringList.append(QString::number((canframe.data[3]*256+canframe.data[4])*\
//                (qPow(10, -(6-canframe.data[2])))));
//    } else {
//        Back_QStringList.append(QString::number((canframe.data[3]*256+canframe.data[4])*\
//                (qPow(10, (canframe.data[2]-6)))));
//    }
//    Back_QStringList.append(QString::number(canframe.data[2]));

//    return Back_QStringList;
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.7.19
  * brief:      can信息传递到配置页面
******************************************************************************/
void w_Conf::SlOT_can_to_conf(can_frame frame, QStringList Data, int flag)
{
    QStringList DLR_Can_Data;
    QStringList PWR_Conf_Data;
    switch  (flag) {
    case 1:
        WIMP->Pub_Conf_Get_Result(frame, 1);
        if ((frame.data[6] == 0) && (!Quick_Set)) { // -采样失败, 快速设置
            Pri_Conf_WMessage(tr("采集失败，电机存在击穿的状况\n建议降低电压进行采集"));
            Conf_Net_WMessage("Sample Fail");
        } else {
            WriteMessage(6000, CMD_Put_92, QString::number(frame.data[1]*100+frame.data[3]).toUtf8());
        }
        break;
    case 2:
        //
        break;
    case 3:
        if (!Quick_Set) {
            return;
        }
        if (frame.data[3] != 0) { // -主参
            return;
        }
        Result_indl.dat[0] = frame.data[4];
        Result_indl.dat[1] = frame.data[5];
        Result_indl.dat[2] = frame.data[6];
        Result_indl.dat[3] = frame.data[7];
        WINDL->Pub_Conf_Set_INDL(QString::number(Result_indl.Result), frame.data[1], 7);
        break;
    case 5:
      /*  WBLOCK->Pub_Conf_Set_BLOCK(QString::number(frame.data[3]*256 + frame.data[4]), \
                frame.data[5]*256 + frame.data[6], 5); */
        PWR_Conf_Data.clear();
        PWR_Conf_Data.append(QString::number(frame.data[1]*256 + frame.data[2]));
        PWR_Conf_Data.append(QString::number(frame.data[3]*256 + frame.data[4]));
        PWR_Conf_Data.append(QString::number(frame.data[5]*256 + frame.data[6]));
        if (index_c == 7) {
            WPWR->Pub_Conf_Set_PWR(QStringList(""), PWR_Conf_Data.at(0), 7);
        } else if (index_c == 9) {
            WBLOCK->Pub_Conf_Set_BLOCK(PWR_Conf_Data.at(0), 7, 7);
        } else if (index_c == 10) {
            WLVS->Pub_Conf_Set_LVS(PWR_Conf_Data.at(0), 7);
        } else {
            //
        }
        break;
    case 6:
        DLR_Can_Data = Board_DLR_TestData(frame);
        if (Quick_Set) { // -快速设置
            if (DLR_Can_Data.at(0).toDouble() < (2*qPow(10, (1+frame.data[2]%3)))) {
                // -小于 20，200，2000
                AutoSet[frame.data[1]] = DLR_Can_Data;
            } else {
                //
            }
        } else {
            DLR_Compensate_Back(DLR_Can_Data);
        }
        break;
    default:
        //
        break;
    }
    Data.clear();
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.7.28
  * brief:      日志数据的保存
******************************************************************************/
void w_Conf::Slot_Save_DayRecoord(QString Text = "", QString GetData = "")
{
    QString currentDateTime = QDateTime::currentDateTime().toString \
            ("yyyy-MM-dd---hh-mm-ss"); // -设置显示格式
    QSettings set_Test_File(Test_Day_Record_path, QSettings::IniFormat);
    set_Test_File.setIniCodec(QTextCodec::codecForName("GB2312"));
    QDir *temp = new QDir;
    bool exist = temp->exists(Test_Day_Record_path);
    if (exist) {
        //
    } else {
        //
        system("mkdir /mnt/nandflash/AIP/dayrecord/");
        system("touch /mnt/nandflash/AIP/dayrecord/dayrecord.ini");
        system("chmod +x /mnt/nandflash/AIP/dayrecord/dayrecord.ini");
    }
    QString keyname;
    keyname = QString("%1/%2").arg(Text).arg(currentDateTime);
    set_Test_File.setValue(keyname, GetData);
    system("sync");

//  for (int i=0;i<strstr.size()/10;i++) {
//      qDebug() << strstr.mid(i*10, 10);
//  }
//  qDebug() << strstr.size()<<strstr;
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.8.16
  * brief:      勾选是否进行测试
******************************************************************************/
void w_Conf::Item_Chose_Box_stateChanged(int checked)
{
    if (Item_Chose_Box->isHidden()) {
        return;
    }
    if (checked) {
        ui->test->item(ui->test->currentRow(), 0)->setTextColor(QColor("green"));
    } else {
        ui->test->item(ui->test->currentRow(), 0)->setTextColor(QColor("red"));
    }
}


/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      电机类型切换
******************************************************************************/
int w_Conf::on_MotorType_currentIndexChanged(int index)
{
    if ((model_Type.size() == 0) || (index < 0)) {
        return 0;
    }
    int i = 0;
    QString str;
    ui->Label_Picture->clear();
    QPixmap *pixmap;
    pixmap = new QPixmap(QString("/mnt/nandflash/AIP/Model/%1.jpg").arg \
                         (ui->MotorType->currentText()));
    ui->Label_Picture->setPixmap(*pixmap);
    QSettings settings(data_path, QSettings::IniFormat);
    Ini.Color = settings.value(QString("%1/Color").arg \
                               (ui->MotorType->currentText())).toString();

    for (i = 0; i < Ini_Proj.size(); i++) { // -对端点进行锁定
        switch (Ini_Proj.at(i).toInt()) {
        case 1: // -电阻
            Ini.DLR = settings.value(QString("%1/DLR").arg \
                                   (ui->MotorType->currentText()), "12").toString();
            break;
        case 2: // -反嵌
            Ini.MAG = settings.value(QString("%1/MAG").arg \
                                   (ui->MotorType->currentText()), "12").toString();
            break;
        case 3: // -绝缘
            //
            break;
        case 4: // -交耐
            //
            break;
        case 5: // -直耐
            //
            break;
        case 6: // -匝间
            Ini.IMP = settings.value(QString("%1/IMP").arg \
                                     (ui->MotorType->currentText()), "12").toString();
            break;
        case 7: // -功率
            //
            break;
        case 8: // -电感
            Ini.IINDL = settings.value(QString("%1/INDL").arg \
                                     (ui->MotorType->currentText()), "12").toString();
            break;
        case 9: // -堵转
            //
            break;
        case 10: // -低启
            //
            break;
        case 11: // -霍尔
            //
            break;
        case 12: // -负载
            //
            break;
        case 13: // -空载
            //
            break;
        case 14: // -反电动势
            //
            break;
        case 15: // -高压
            //
            break;
        }
    }
    if (ui->MotorType->currentText() == "None") { // -(None)型号时按键全部使能
        Ini.Color = "12345678"; // -设置初始值
    } else {
        //
    }
    CONF.replace(13, ui->MotorType->currentText());
    qColor_BtnList.clear();
    colorIdList.clear();
    colorIdList_C.clear();

    Singal_Conf_to_Main(QStringList(""), ui->MotorType->currentText(), 5, 5);
    for (i = 0; i < 8; i++) { // -初始化下拉列表
        qColor_BtnList.append(new QToolButton(this));
        ui->colrLayout->addWidget(qColor_BtnList[i], i/2, i%2);
        btnGroup_Color->addButton(qColor_BtnList[i], i);
        qColor_BtnList[i]->setEnabled(true);
        colorIdList.append(CONF[i]);
        colorIdList_C.append(CONF[i]);
        if (Ini.Color.indexOf(QString::number(i+1)) >= 0) {
            if (colorIdList[i] == "#000000") {
                str = QString("height:90px;width:95px;color: #191919;"\
                              "border:none;background-color:%1;color:white").arg\
                        (colorIdList[i]);
            } else {
                str = QString("height:90px;width:95px;"\
                              "color: #191919;border:none;background-color:%1").arg\
                        (colorIdList[i]);
            }
        } else {
            qColor_BtnList[i]->setDisabled(true);
            colorIdList_C.replace(i, "#191919");
            str = QString("height:90px;width:95px;color: #191919;"\
                          "border:none;background-color:%1").arg \
                    (colorIdList_C[i]);
        }
        qColor_BtnList[i]->setStyleSheet(str);
        qColor_BtnList[i]->setText(QString::number(i+1));
    }
    return true;
}


/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.7.19
  * brief:      Main传递数据到配置页面
******************************************************************************/
void w_Conf::Pub_main_to_conf(QStringList list, QString str, int value, int flag)
{
    int Success = 0;
    int i;
    switch (flag) {
    case 1:
        Usart_GetFcous();
        break;
    case 2:
        Usart_Button(value);
        break;
    case 3:
        Ini_System = list;
        Conf_User  = list[5].toInt();
        Save_SystemConf_Data(value);
        break;
    case 4:
        Set_Color(str);
        break;
    case 5: // 用于系统初始化
        thread_sql = new QThread(this);
        sql_Client.moveToThread(thread_sql);
        connect(thread_sql,  SIGNAL(started()), &sql_Client, SLOT(DeviceOpen()));
        connect(thread_sql, SIGNAL(finished()), &sql_Client, SLOT(DeviceQuit()));
        connect(this, SIGNAL(WConf_WriteSql(QByteArray)), &sql_Client, SLOT(Write(QByteArray)));
        thread_sql->start();

        Sync_Conf();
        break;
    case 7:
        SlOT_Button_Function_Judge(Qt::Key_A);
        break;
    case 10:
        if (value == 1) {
           ui->fileEdit1->setText(str);
           on_fileBtnAdd_clicked();
        } else if (value == 2) {
            on_fileBtnDel_clicked();
        } else if (value == 3) {
            emit WriteMessage(6000, CMD_Put_Oder_Model, QString(currentFile.join(" ")).toUtf8());
        } else if (value == 5) {
            for (i = 0; i < currentFile.size(); i++) {
                if (ui->fileTab->item(i, 0)->text() == str) { //  设置背景
                    on_fileTab_cellClicked(i, 0);
                }
            }
        } else {
            //
        }
        break;
    case 11:
        Quick_set_IRACW_Value = false;
        Conf_Set_User(value);
        Quick_set_IRACW_Value = true;
        break;
    case 12:
        lable_Zero->hide();
        break;
    case 13:
        qDebug() << "13----" << value;
        if (value == 1) {
            PC_CONF_Data();
        } else if (value == 2) {
            PC_SYS_Data();
        } else if (value == 3) {
            PC_Item_DCR_Data();
        } else if (value == 4) {
            PC_Item_IR_Data();
        } else if (value == 5) {
            PC_Item_ACW_Data();
        } else if (value == 6) {
            PC_Item_IMP_Data();
        } else if (value == 7) {
            PC_Item_IND_Data();
        } else if (value == 8) {
            PC_Item_PWR_Data();
        } else if (value == 11) {
            PC_Item_PGHALL_Data();
        } else if (value == 12) {
            PC_Item_LOAD_Data();
        } else if (value == 13) {
            PC_Item_NOLOAD_Data();
        } else if (value == 14) {
             PC_Item_BEMF_Data();
        } else if (value == 15) {
            PC_Item_MAG_Data();
        } else if (value == 16) {
            PC_Item_DCW_Data();
        } else {
            //
        }
        break;
    case 15:
        if (index_c == 7) {
            WPWR->Pub_Conf_Set_PWR(QStringList(""), list.at(0), 7);
        } else if (index_c == 9) {
            WBLOCK->Pub_Conf_Set_BLOCK(list.at(0), 7, 7);
        } else if (index_c == 10) {
            WLVS->Pub_Conf_Set_LVS(list.at(0), 7);
        } else {
            //
        }
        break;
    case 16:
        if (index_c == 7) {
            if (PWR_Test_Usart) {
                PWR_Test_Usart = false;
            } else {
                WPWR->Pub_Conf_Set_PWR(QStringList(""), QString(""), 8);
                break;
            }
            if (value == 2) {
                Pri_Conf_WMessage("串口不在调试模式，或者串口出现问题");
            } else {
                Pri_Conf_WMessage("串口 Ok");
            }
        } else if (index_c == 9) {
            WBLOCK->Pub_Conf_Set_BLOCK("", 8, 8);
        }  else if (index_c == 10) {
            WLVS->Pub_Conf_Set_LVS("", 8);
        } else {
            //
        }
        break;
    case 17:
        if (Ini_Set_ImpVolt == QString(tr("noback"))) {
            WIMP->Pub_Conf_Set_IMP("", 12);
        }
        break;
    case 18:
        for (i = 0; i < currentFile.size(); i++) {
            if (ui->fileTab->item(i, 0)->text() == str) { //  设置背景
                on_fileTab_cellClicked(i, 0);
            }
        }
        qApp->processEvents();   //  立即显示生效
        break;
    case 19:
        if (WMAG != NULL) {
            WMAG->Pub_Conf_Set_MAG(QString::number(value), 10);
        } else {
            //
        }
        if (WIMP != NULL) {
            WIMP->Pub_Conf_Set_IMP(QString::number(value), 13);
        } else {
            //
        }
        break;
    case 20:
        if (IRACW_Compensate == TestIW_IR) {
            if (value == 0) {
                return;
            }

            Success = WIR->IR_Compensate(str.toDouble());
            if (Success == 0) {
                return;
            } else if (Success == 1) {
                ui->Key_E->setStyleSheet("background:#00FF00;color:rgb(0, 0, 0);");
                ui->Key_E->setText(tr("已补偿"));
            } else if (Success == 2) {
                Pri_Conf_WMessage(tr("     补偿错误       "));
            } else {
                //
            }
        } else if (IRACW_Compensate == TestIW_ACW) {
            if (value == 0) {
                return;
            }
            Success = WACW->ACW_Compensate(str.toDouble());
            if (Success == 0) {
                return;
            } else if (Success == 1) {
                ui->Key_E->setStyleSheet("background:#00FF00;color:rgb(0, 0, 0);");
                ui->Key_E->setText(tr("已补偿"));
            } else if (Success == 2) {
                Pri_Conf_WMessage(tr("     补偿错误       "));
            } else {
                //
            }
        } else if (IRACW_Compensate == TestIW_DCW) {
            if (value == 0) {
                return;
            }
            Success = WDCW->DCW_Compensate(str.toDouble());
            if (Success == 0) {
                return;
            } else if (Success == 1) {
                ui->Key_E->setStyleSheet("background:#00FF00;color:rgb(0, 0, 0);");
                ui->Key_E->setText(tr("已补偿"));
            } else if (Success == 2) {
                Pri_Conf_WMessage(tr("     补偿错误       "));
            } else {
                //
            }
        } else {
            //
        }
        break;
    case 21:
        SlOT_Button_IMP_Sample(0);
        break;
    case 22:
        Conf_Usart_Data(value, list);
        break;
    case 23:
        if (value == 1) {
            SlOT_Button_Conf_Judge(Qt::Key_3);
            WIR->IR_UsartData(list);
            INS = WIR->Copy_IR_List;
            SlOT_Button_Function_Judge(Qt::Key_B);
            SlOT_Button_Conf_Judge(Qt::Key_0);
        } else if (value == 2) {
            SlOT_Button_Conf_Judge(Qt::Key_4);
            WACW->ACW_UsartData(list);
            ACV = WACW->Copy_ACW_List;
            SlOT_Button_Function_Judge(Qt::Key_B);
            SlOT_Button_Conf_Judge(Qt::Key_0);
        } else {
            //
        }
        break;
    default:
        break;
    }
}

void w_Conf::Pub_QbyteArray_conf(QByteArray dat) {
    int model_position = 0;
    int i = 0;
    int j = 0;
    dat = dat.remove(0, 5);
    QDomDocument docs;
    QStringList temp;
    docs.setContent(dat);
    if  (!(docs.elementsByTagName("DCR").isEmpty())) {
        QDomNodeList list = docs.elementsByTagName("DCR").at(0).childNodes();
        for (i = 0; i < list.size(); i++) {
            QDomNode node = list.item(i);
            QDomElement dom = node.toElement();
            temp = dom.text().split(",");
            WDLR->DLR_NetData(temp, node.nodeName());
            if (node.nodeName() == QString(tr("wire_comp2"))) {
                RES = WDLR->Copy_DLR_List;
                SlOT_Button_Function_Judge(Qt::Key_B);
                SlOT_Button_Conf_Judge(Qt::Key_0);
            }
        }
    } else if (!(docs.elementsByTagName("MAG").isEmpty())) {
        QDomNodeList list = docs.elementsByTagName("MAG").at(0).childNodes();
        for (i = 0; i < list.size(); i++) {
            QDomNode node = list.item(i);
            QDomElement dom = node.toElement();
            temp = dom.text().split(",");
            WMAG->MAG_NetData(temp, node.nodeName());
            if (node.nodeName() == QString(tr("wave"))) {
                OPP = WMAG->Copy_MAG_List;
                SlOT_Button_Function_Judge(Qt::Key_B);
            }
        }
    } else if (!(docs.elementsByTagName("IR").isEmpty())) {
        QDomNodeList list = docs.elementsByTagName("IR").at(0).childNodes();
        for (i = 0; i < list.size(); i++) {
            QDomNode node = list.item(i);
            QDomElement dom = node.toElement();
            temp = dom.text().split(",");
            WIR->IR_NetData(temp, node.nodeName());
            if (node.nodeName() == QString(tr("volt"))) {
                INS = WIR->Copy_IR_List;
                SlOT_Button_Function_Judge(Qt::Key_B);
                SlOT_Button_Conf_Judge(Qt::Key_0);
            }
        }
    } else if (!(docs.elementsByTagName("ACW").isEmpty())) {

        QDomNodeList list = docs.elementsByTagName("ACW").at(0).childNodes();
        for (i = 0; i < list.size(); i++) {
            QDomNode node = list.item(i);
            QDomElement dom = node.toElement();
            temp = dom.text().split(",");

            WACW->ACW_NetData(temp, node.nodeName());
            if (node.nodeName() == QString(tr("volt"))) {
                ACV = WACW->Copy_ACW_List;
                SlOT_Button_Function_Judge(Qt::Key_B);
                SlOT_Button_Conf_Judge(Qt::Key_0);
            }
        }
    } else if (!(docs.elementsByTagName("DCW").isEmpty())) {

        QDomNodeList list = docs.elementsByTagName("DCW").at(0).childNodes();
        for (i = 0; i < list.size(); i++) {
            QDomNode node = list.item(i);
            QDomElement dom = node.toElement();
            temp = dom.text().split(",");
            WDCW->DCW_NetData(temp, node.nodeName());
            if (node.nodeName() == QString(tr("volt"))) {
                DCV = WDCW->Copy_DCW_List;
                SlOT_Button_Function_Judge(Qt::Key_B);
                SlOT_Button_Conf_Judge(Qt::Key_0);
            }
        }
    } else if (!(docs.elementsByTagName("IMP").isEmpty())) {
        QDomNodeList list = docs.elementsByTagName("IMP").at(0).childNodes();
        for (i = 0; i < list.size(); i++) {
            QDomNode node = list.item(i);
            QDomElement dom = node.toElement();
            temp = dom.text().split(",");
            WIMP->IMP_NetData(temp, node.nodeName());
            if (node.nodeName() == QString(tr("waveR"))) {
                ITT = WIMP->Copy_IMP_List;
                SlOT_Button_Function_Judge(Qt::Key_B);
            }
        }
    } else if (!(docs.elementsByTagName("IND").isEmpty())) {
        QDomNodeList list = docs.elementsByTagName("IND").at(0).childNodes();
        for (i = 0; i < list.size(); i++) {
            QDomNode node = list.item(i);
            QDomElement dom = node.toElement();
            temp = dom.text().split(",");
            WINDL->INDL_NetData(temp, node.nodeName());
            if (node.nodeName() == QString(tr("wire_comp2"))) {
                INDL = WINDL->Copy_INDL_List;
                SlOT_Button_Function_Judge(Qt::Key_B);
            //    SlOT_Button_Conf_Judge(Qt::Key_0);
            }
        }
    } else if (!(docs.elementsByTagName("PWR").isEmpty())) {
        QDomNodeList list = docs.elementsByTagName("PWR").at(0).childNodes();
        for (i = 0; i < list.size(); i++) {
            QDomNode node = list.item(i);
            QDomElement dom = node.toElement();
            temp = dom.text().split(",");
            WPWR->PWR_NetData(temp, node.nodeName());
            if (node.nodeName() == QString(tr("volt"))) {
                PWR = WPWR->Copy_PWR_List;
                SlOT_Button_Function_Judge(Qt::Key_B);
            }
        }
    } else if (!(docs.elementsByTagName("HALL").isEmpty())) {
        QDomNodeList list = docs.elementsByTagName("HALL").at(0).childNodes();
        for (i = 0; i < list.size(); i++) {
            QDomNode node = list.item(i);
            QDomElement dom = node.toElement();
            temp = dom.text().split(",");
            WPG->BLDCPG_NetData(temp, node.nodeName());
            if (node.nodeName() == QString(tr("wave"))) {
                BLDCPG = WPG->Copy_BLDCPG_List;
                SlOT_Button_Function_Judge(Qt::Key_B);
                SlOT_Button_Conf_Judge(Qt::Key_0);
            }
        }
    } else if (!(docs.elementsByTagName("LOAD").isEmpty())) {
        QDomNodeList list = docs.elementsByTagName("LOAD").at(0).childNodes();
        for (i = 0; i < list.size(); i++) {
            QDomNode node = list.item(i);
            QDomElement dom = node.toElement();
            temp = dom.text().split(",");
            WLOAD->LOAD_NetData(temp, node.nodeName());
            if (node.nodeName() == QString(tr("vsp_volt"))) {
                LOAD = WLOAD->Copy_LOAD_List;
                SlOT_Button_Function_Judge(Qt::Key_B);
                SlOT_Button_Conf_Judge(Qt::Key_0);
            }
        }
    } else if (!(docs.elementsByTagName("NOLOAD").isEmpty())) {
        QDomNodeList list = docs.elementsByTagName("NOLOAD").at(0).childNodes();
        for (i = 0; i < list.size(); i++) {
            QDomNode node = list.item(i);
            QDomElement dom = node.toElement();
            temp = dom.text().split(",");
            WNoLoad->NOLOAD_NetData(temp, node.nodeName());
            if (node.nodeName() == QString(tr("vsp_volt"))) {
                NOLOAD = WNoLoad->Copy_NOLOAD_List;
                SlOT_Button_Function_Judge(Qt::Key_B);
                SlOT_Button_Conf_Judge(Qt::Key_0);
            }
        }
    } else if (!(docs.elementsByTagName("BEMF").isEmpty())) {
        QDomNodeList list = docs.elementsByTagName("BEMF").at(0).childNodes();
        for (i = 0; i < list.size(); i++) {
            QDomNode node = list.item(i);
            QDomElement dom = node.toElement();
            temp = dom.text().split(",");
            WBEMF->BEMF_NetData(temp, node.nodeName());
            if (node.nodeName() == QString(tr("volt_vcc"))) {
                BEMF = WBEMF->Copy_BEMF_List;
                SlOT_Button_Function_Judge(Qt::Key_B);
                SlOT_Button_Conf_Judge(Qt::Key_0);
            }
        }
    } else if (!(docs.elementsByTagName("Conf").isEmpty())) {
        QDomNodeList list = docs.elementsByTagName("Conf").at(0).childNodes();
        for (i = 0; i < list.size(); i++) {
            QDomNode node = list.item(i);
            QDomElement dom = node.toElement();
            temp = dom.text().split(",");
            if (node.nodeName() == QString(tr("color"))) {
                for (j = 0; j < 8; j++) {
                    iColorBtn = i;
                    Set_Color(temp.at(i));
                }
            }
            if (node.nodeName() == QString(tr("type"))) {
                model_position = model_Type.indexOf(temp.at(0));
                ui->MotorType->setCurrentIndex(model_position);
                Save_ConfData();
            }
        }
    } else if (!(docs.elementsByTagName("Sys").isEmpty())) {
        QDomNodeList list = docs.elementsByTagName("Sys").at(0).childNodes();
        for (i = 0; i < list.size(); i++) {
            QDomNode node = list.item(i);
            QDomElement dom = node.toElement();
            temp = dom.text().split(",");

            if (node.nodeName() == QString(tr("Test_Item"))) {
                QSettings set_Test_File(Test_File_path, QSettings::IniFormat);
                set_Test_File.setIniCodec("UTF-8");
                QString   name_list;
                name_list = QString("Test_File/%1").arg(Ini_ActiveFile);
                set_Test_File.setValue(name_list, temp);
                test_Inifile = temp;
                ui->test->setRowCount(0);
                ui->test->setGeometry(305, 20, 131, 39*14+(ui->test->horizontalHeader()->height()));
                ui->test->setRowCount(13);
                for (i =0 ; i < 13; i++) {
                    ui->test->setRowHeight(i, 39);
                }
                Init_test_TableWidget(); // -初始化测试项目

                for (i = 1; i <= Count_Item; i++) { // -设置显示, 锁定端子号
                    btnGroup_Item->button(i)->hide();
                }
                btnGroup_Item->button(0)->show();
                btnGroup_Item->button(20)->show();
                for (i = 1; i < Ini_Proj.size(); i++) {
                    btnGroup_Item->button(Ini_Proj.at(i).toInt())->show();
                }
                SlOT_Button_Function_Judge(Qt::Key_B);
           //     SlOT_Button_Function_Judge(Qt::Key_A);
                qApp->processEvents();
            }
        }
    } else {
        qDebug() << "w_Conf::Error Data";
    }
}

void w_Conf::Conf_Usart_Data(int value, QStringList temp) {
    int i;
    QSettings set_Test_File(Test_File_path, QSettings::IniFormat);
    set_Test_File.setIniCodec("UTF-8");
    QString   name_list;
    name_list = QString("Test_File/%1").arg(Ini_ActiveFile);
    set_Test_File.setValue(name_list, temp);
    test_Inifile = temp;
    ui->test->setRowCount(0);
    ui->test->setGeometry(305, 20, 131, 39*14 + \
                          (ui->test->horizontalHeader()->height()));
    ui->test->setRowCount(13);
    for (i =0 ; i < 13; i++) {
        ui->test->setRowHeight(i, 39);
    }
    Init_test_TableWidget(); // -初始化测试项目

    for (i = 1; i <= Count_Item; i++) { // -设置显示, 锁定端子号
        btnGroup_Item->button(i)->hide();
    }
    btnGroup_Item->button(0)->show();
    btnGroup_Item->button(20)->show();
    for (i = 1; i < Ini_Proj.size(); i++) {
        btnGroup_Item->button(Ini_Proj.at(i).toInt())->show();
    }

    SlOT_Button_Function_Judge(Qt::Key_B);
    if (value == 1) {
        SlOT_Button_Function_Judge(Qt::Key_A);
    } else {
        //
    }
    qApp->processEvents();
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2017.6.10
      * brief:      网络数据库打开，数据库窗口显示
******************************************************************************/
void w_Conf::on_SQL_Task_clicked()
{
    if  (NetSQL_OpenOk) { // -网络数据库打开
        SQL_Widget->show();
    } else {
        Pri_Conf_WMessage(tr("未连接网络\n下载远程数据库失败"));
    }
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2017.6.10
      * brief:      数据库窗口隐藏
******************************************************************************/
void w_Conf::SQL_Widget_autoquit()
{
    SQL_Widget->hide();
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2017.6.10
      * brief:      数据库查询任务表-生产线-
******************************************************************************/
void w_Conf::SQL_Produce_Plan_textChanged(const QString &text)
{
    int i = 0;
    if (SQL_Init) {
        return;
    }

    SQL_Task.clear();
    QSqlQuery query_net(sql_net.dbtwo);

    QString net_str = QString(tr("Select 生产任务编号 from %2 Where 生产线 = '%1'").arg\
                              (text).arg(Ini_Task_Table));
    query_net.exec(net_str);
    while (query_net.next()) {
        SQL_Task.append(query_net.value(0).toString().trimmed());
    }

    SQL_Init = true;
    SQL_Line_Text.at(0)->text().clear(); // -计划数量清空
    SQL_Line_Text.at(1)->text().clear(); // -生产部门清空
    SQL_Line_Text.at(2)->text().clear(); // -产品型号清空
    SQL_Produce_Number->clear();
    for (i = 0; i < SQL_Task.size(); i++) {
        SQL_Produce_Number->addItem(QWidget::tr("%1").arg(SQL_Task.at(i)));
    }
    SQL_Init = false;
    SQL_Produce_Number_textChanged(SQL_Produce_Number->currentText());
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2017.6.10
      * brief:      数据库查询任务表-生产任务号-
******************************************************************************/
void w_Conf::SQL_Produce_Number_textChanged(const QString &text)
{
    if (SQL_Init) {
        return;
    }
    if (SQL_Produce_Plan->currentText() == "") {
        return;
    }
    SQL_Line_Text.at(0)->text().clear(); // -计划数量清空
    SQL_Line_Text.at(1)->text().clear(); // -生产部门清空
    SQL_Line_Text.at(2)->text().clear(); // -产品型号清空
    SQL_Task.clear();
    QSqlQuery query_net(sql_net.dbtwo);

    QString net_str = QString(tr("Select 计划数量, 生产部门, 产品型号 from %3 Where  "\
                                 "生产线 = '%1' and 生产任务编号 ='%2'").arg \
                     (SQL_Produce_Plan->currentText()).arg(text).arg(Ini_Task_Table));
    query_net.exec(net_str);
    while (query_net.next()) {
        SQL_Task.append(query_net.value(0).toString().trimmed());
        SQL_Task.append(query_net.value(1).toString().trimmed());
        SQL_Task.append(query_net.value(2).toString().trimmed());
        SQL_Line_Text.at(0)->setText(SQL_Task.at(0));
        SQL_Line_Text.at(1)->setText(SQL_Task.at(1));
        SQL_Line_Text.at(2)->setText(SQL_Task.at(2));
    }
}

void w_Conf::PC_Test_Param_Data(QStringList netdata)
{
    int i = 0;
    QDomText text;
    QDomDocument doc;
    QDomElement root = doc.createElement("Test_Data_Param");
    doc.appendChild(root);

    QStringList temp;
    for (i=0; i < netdata.size()/2; i++) {
        temp.append(netdata.at(i));
    }
    QDomElement Test_1 = doc.createElement("Test_1"); // Test_1
    root.appendChild(Test_1);
    text = doc.createTextNode(temp.join(","));
    Test_1.appendChild(text);

    temp.clear();
    for (i=0; i < netdata.size()/2; i++) {
        temp.append(netdata.at(netdata.size()/2+i));
    }
    QDomElement Test_2 = doc.createElement("Test_2");
    root.appendChild(Test_2);
    text = doc.createTextNode(temp.join(","));
    Test_2.appendChild(text);
    emit WriteMessage(6000, CMD_Put_CONF_Data, doc.toByteArray());
}

void  w_Conf::PC_Item_IR_Data() {
    int i = 0;
    int j = 0;
    QDomText text;
    QDomDocument doc;
    QDomElement root = doc.createElement("IR");
    doc.appendChild(root);

    QStringList ir_param;
    QStringList ir_param_common;
    ir_param.clear();
    ir_param_common.clear();
    ir_param << tr("test") << tr("port1") << tr("port2") << tr("volt")\
             << tr("min") << tr("max") << tr("time");
    ir_param_common << tr("2") << tr("PE") << tr("ALL");
    ir_param_common.append(INS.at(20));
    ir_param_common.append(INS.at(23));
    ir_param_common.append(INS.at(22));
    ir_param_common.append(INS.at(21));

    int ir_position[] = {36, 30, 31, 32, \
                    33, 34, 35, \
                    };
    QStringList temp;
    for (j = 0; j < ir_param.size(); j++) {
        temp.clear();
        for (i = 0; i < 4; i++) {
            temp.append(RES.at(10*i+ir_position[j]));
        }
        temp.append(ir_param_common.at(j));
        QDomElement test = doc.createElement(ir_param.at(j));
        root.appendChild(test);
        text = doc.createTextNode(temp.join(","));
        test.appendChild(text);
    }
    emit WriteMessage(6000, CMD_Put_CONF_Data, doc.toByteArray());
    Quick_set_IRACW_Value = false;
    SlOT_Button_Conf_Judge(Qt::Key_3);
    Quick_set_IRACW_Value = true;
}

void  w_Conf::PC_Item_DCW_Data() {
    QDomText text;
    QDomDocument doc;
    QDomElement root = doc.createElement("DCW");
    doc.appendChild(root);
    QStringList acw_param;
    QStringList acw_param_common;
    acw_param.clear();
    acw_param_common.clear();
    acw_param << tr("test") << tr("port1") << tr("port2") << tr("volt")\
             << tr("min") << tr("max") << tr("time")\
               << tr("freq") << tr("arc");
    acw_param_common << tr("2") << tr("PE") << tr("ALL");
    acw_param_common.append(DCV.at(20));
    acw_param_common.append(DCV.at(23));
    acw_param_common.append(DCV.at(24));
    acw_param_common.append(DCV.at(21));
    acw_param_common.append(DCV.at(1));
    acw_param_common.append(DCV.at(0));

    int acw_position[] = {40, 30, 31, 32, \
                    33, 34, 36, \
                    10, 35};

    QStringList temp;
    for (int j = 0; j < acw_param.size(); j++) {
        temp.clear();
        qDebug() << j;
        if  (j  ==  7) {
            for (int i = 0; i < 4; i++) {
                temp.append(DCV.at(acw_position[j]));
            }
        } else {
            for (int i = 0; i < 4; i++) {
                temp.append(DCV.at(16*i+acw_position[j]));
            }
        }
        temp.append(acw_param_common.at(j));
        QDomElement test = doc.createElement(acw_param.at(j));
        root.appendChild(test);
        text = doc.createTextNode(temp.join(","));
        test.appendChild(text);
    }
    emit WriteMessage(6000, CMD_Put_CONF_Data, doc.toByteArray());
    Quick_set_IRACW_Value = false;
    SlOT_Button_Conf_Judge(Qt::Key_5);
    Quick_set_IRACW_Value = true;
}

void  w_Conf::PC_Item_ACW_Data() {
    QDomText text;
    QDomDocument doc;
    QDomElement root = doc.createElement("ACW");
    doc.appendChild(root);
    QStringList acw_param;
    QStringList acw_param_common;
    acw_param.clear();
    acw_param_common.clear();
    acw_param << tr("test") << tr("port1") << tr("port2") << tr("volt")\
             << tr("min") << tr("max") << tr("time")\
               << tr("freq") << tr("arc");
    acw_param_common << tr("2") << tr("PE") << tr("ALL");
    acw_param_common.append(ACV.at(20));
    acw_param_common.append(ACV.at(23));
    acw_param_common.append(ACV.at(24));
    acw_param_common.append(ACV.at(21));
    acw_param_common.append(ACV.at(1));
    acw_param_common.append(ACV.at(0));

    int acw_position[] = {40, 30, 31, 32, \
                    33, 34, 36, \
                    10, 35};

    QStringList temp;
    for (int j = 0; j < acw_param.size(); j++) {
        temp.clear();
        qDebug() << j;
        if  (j  ==  7) {
            for (int i = 0; i < 4; i++) {
                temp.append(ACV.at(acw_position[j]));
            }
        } else {
            for (int i = 0; i < 4; i++) {
                temp.append(ACV.at(16*i+acw_position[j]));
            }
        }
        temp.append(acw_param_common.at(j));
        QDomElement test = doc.createElement(acw_param.at(j));
        root.appendChild(test);
        text = doc.createTextNode(temp.join(","));
        test.appendChild(text);
    }
    emit WriteMessage(6000, CMD_Put_CONF_Data, doc.toByteArray());
    Quick_set_IRACW_Value = false;
    SlOT_Button_Conf_Judge(Qt::Key_4);
    Quick_set_IRACW_Value = true;
}
void  w_Conf::PC_Item_IMP_Data() {
    SlOT_Button_Conf_Judge(Qt::Key_6);
}
void  w_Conf::PC_Item_PWR_Data() {
    SlOT_Button_Conf_Judge(Qt::Key_7);
}
void  w_Conf::PC_Item_IND_Data() {
    QDomText text;
    QDomDocument doc;
    QDomElement root = doc.createElement("IND");
    doc.appendChild(root);

    QStringList ind_param;
    ind_param.clear();
    ind_param << tr("test") << tr("port1") << tr("port2") << tr("unit")\
            << tr("min") << tr("max") << tr("qmin") << tr("qmax")\
           << tr("std") << tr("mode") << tr("noun");
    int ind_position[] = {38, 30, 31, 37, \
                    32, 33, 34, 35, \
                    36};

    QStringList temp;
    for (int j = 0; j < ind_param.size(); j++) {
        temp.clear();
        if (j  ==  9) {
            temp.append(INDL.at(0)); // 次数
            temp.append(INDL.at(2)); // 频率
            temp.append(INDL.at(3)); // 频率
            temp.append(INDL.at(6)); // 快测慢测
        } else if (j == 10) {
            temp.append(INDL.at(1)); // 不平衡度
        } else {
            for (int i=0; i < 8; i++) {
                temp.append(INDL.at(20*i+ind_position[j]));
            }
        }
        QDomElement test = doc.createElement(ind_param.at(j));
        root.appendChild(test);
        text = doc.createTextNode(temp.join(","));
        test.appendChild(text);
    }
    emit WriteMessage(6000, CMD_Put_CONF_Data, doc.toByteArray());
    SlOT_Button_Conf_Judge(Qt::Key_8);
}

void  w_Conf::PC_Item_PGHALL_Data() {
    QDomText text;
    QDomDocument doc;
    QDomElement root = doc.createElement("HALL");
    doc.appendChild(root);
    QStringList fg_param;
    fg_param.clear();

    fg_param << tr("volt_low_min") << tr("volt_low_max") << tr("volt_up_min") << tr("volt_up_max")\
             << tr("freq_min") << tr("freq_max") << tr("duty_min") << tr("duty_max")\
               << tr("skewing_min") << tr("skewing_max")\
                 << tr("count") << tr("vcc_volt") << tr("time");

     int fg_position[] = {50, 65, 51, 66, \
                    52, 67, 53, 68, \
                   54, 69, \
                    1, 0, 2};

    QStringList temp;
    for (int j = 0; j < fg_param.size(); j++) {
        temp.clear();
        temp.append(BLDCPG.at(fg_position[j]));

        QDomElement test = doc.createElement(fg_param.at(j));
        root.appendChild(test);
        text = doc.createTextNode(temp.join(","));
        test.appendChild(text);
    }
    emit WriteMessage(6000, CMD_Put_CONF_Data, doc.toByteArray());
    SlOT_Button_Conf_Judge(59);
}

void  w_Conf::PC_Item_LOAD_Data() {
    QDomText text;
    QDomDocument doc;
    QDomElement root = doc.createElement("LOAD");
    doc.appendChild(root);
    QStringList load_param;
    load_param.clear();

    load_param << tr("volt") << tr("curr_min") << tr("curr_max") << tr("pwr_min") << tr("pwr_max")\
              << tr("speed_min") << tr("speed_max") << tr("torque") << tr("vcc_volt")\
             << tr("vsp_volt") << tr("time") << tr("sequence");

    int load_position[] = {0, 50, 65, 51, 66, \
                    52, 67, 4, 1, \
                   2, 3, 110};

    QStringList temp;
    for (int j = 0; j < load_param.size(); j++) {
        temp.clear();
        if (j == 11) {
            for (int i = 0; i < 14; i++)  {
                temp.append(LOAD.at(load_position[j]+i));
            }
        } else {
            temp.append(LOAD.at(load_position[j]));
        }

        QDomElement test = doc.createElement(load_param.at(j));
        root.appendChild(test);
        text = doc.createTextNode(temp.join(","));
        test.appendChild(text);
    }
    emit WriteMessage(6000, CMD_Put_CONF_Data, doc.toByteArray());
    SlOT_Button_Conf_Judge(60);
}

void  w_Conf::PC_Item_NOLOAD_Data() {
    QDomText text;
    QDomDocument doc;
    QDomElement root = doc.createElement("NOLOAD");
    doc.appendChild(root);
    QStringList noload_param;
    noload_param.clear();

    noload_param << tr("volt") << tr("curr_min") << tr("curr_max") << tr("pwr_min") \
                 << tr("pwr_max")\
              << tr("speed_min") << tr("speed_max") << tr("vcc_volt")\
             << tr("vsp_volt") << tr("time") << tr("sequence")\
            << tr("turn");

    int noload_position[] = {0, 50, 65, 51, 66, \
                    52, 67, 1, \
                   2, 3, 110, \
                       4};

    QStringList temp;
    for (int j = 0; j < noload_param.size(); j++) {
        temp.clear();
        if (j == 10) {
            for (int i = 0; i < 10; i++)  {
                temp.append(NOLOAD.at(noload_position[j]+i));
            }
        } else {
            temp.append(NOLOAD.at(noload_position[j]));
        }

        QDomElement test = doc.createElement(noload_param.at(j));
        root.appendChild(test);
        text = doc.createTextNode(temp.join(","));
        test.appendChild(text);
    }
    emit WriteMessage(6000, CMD_Put_CONF_Data, doc.toByteArray());
    SlOT_Button_Conf_Judge(61);
}

void  w_Conf::PC_Item_BEMF_Data() {
    QDomText text;
    QDomDocument doc;
    QDomElement root = doc.createElement("BEMF");
    doc.appendChild(root);
    QStringList bemf_param;
    bemf_param.clear();

    bemf_param << tr("hu_volt_min") << tr("hu_volt_max") << tr("hv_volt_min") << tr("hv_volt_max")\
             << tr("hw_volt_min") << tr("hw_volt_max") << tr("speed") << tr("turn")\
               << tr("skewing") << tr("noun");

    int bemf_position[] = {50, 65, 51, 66, \
                    52, 67, 1, 2, \
                   3, 0};

    QStringList temp;
    for (int j = 0; j < bemf_param.size(); j++) {
        temp.clear();
        temp.append(BEMF.at(bemf_position[j]));

        QDomElement test = doc.createElement(bemf_param.at(j));
        root.appendChild(test);
        text = doc.createTextNode(temp.join(","));
        test.appendChild(text);
    }
    emit WriteMessage(6000, CMD_Put_CONF_Data, doc.toByteArray());
    SlOT_Button_Conf_Judge(62);
}

void  w_Conf::PC_Item_DCR_Data() {
    QDomText text;
    QDomDocument doc;
    QDomElement root = doc.createElement("DCR");
    doc.appendChild(root);

    QStringList dcr_param;
    dcr_param.clear();
    dcr_param <<  tr("test") << tr("port1") << tr("port2") << tr("wire")\
             << tr("unit") << tr("min") << tr("max") << tr("std")\
            << tr("std_temp") << tr("wire_comp1") << tr("wire_comp2")\
           << tr("temp_comp") << ("noun");

    int dcr_position[] = {7, 0, 1, 5, \
                    9, 2, 3, 4, \
                    0, 6, 10, \
                    33, 7};
    QStringList temp;
    for (int j = 0; j < dcr_param.size(); j++) {
        temp.clear();
        if ((j == 8)  ||  (j == 11)  ||  (j == 12)) {
            temp.append(RES.at(dcr_position[j]));
        } else {
            for (int i=0; i < 8; i++) {
                temp.append(RES.at(25+16*i+dcr_position[j]));
            }
        }
        QDomElement test = doc.createElement(dcr_param.at(j));
        root.appendChild(test);
        text = doc.createTextNode(temp.join(","));
        test.appendChild(text);
    }

    emit WriteMessage(6000, CMD_Put_CONF_Data, doc.toByteArray());
    SlOT_Button_Conf_Judge(Qt::Key_1);
}
void w_Conf::PC_Item_MAG_Data() {
    SlOT_Button_Conf_Judge(Qt::Key_2);
}
void w_Conf::PC_SYS_Data() {
    QDomText text;
    QDomDocument doc;
    QDomElement root = doc.createElement("Sys");
    doc.appendChild(root);

    QStringList temp;
    for (int i=0; i < test_Inifile.size(); i++) {
        temp.append(test_Inifile.at(i));
    }
    QDomElement Test_Item = doc.createElement("Test_Item");
    root.appendChild(Test_Item);
    text = doc.createTextNode(temp.join(","));
    Test_Item.appendChild(text);

    emit WriteMessage(6000, CMD_Put_CONF_Data, doc.toByteArray());
}

void w_Conf::PC_CONF_Data() {
    QDomText text;
    QDomDocument doc;
    QDomElement root = doc.createElement("Conf");
    doc.appendChild(root);

    QStringList temp;
    for (int i=0; i < colorIdList_C.size(); i++) {
        temp.append(colorIdList_C.at(i));
    }
    QDomElement color = doc.createElement("color");
    root.appendChild(color);
    text = doc.createTextNode(temp.join(","));
    color.appendChild(text);

    temp.clear();
    temp.append(ui->MotorType->currentText());
    QDomElement type = doc.createElement("type");
    root.appendChild(type);
    text = doc.createTextNode(temp.join(","));
    type.appendChild(text);

    emit WriteMessage(6000, CMD_Put_CONF_Data, doc.toByteArray());
}
