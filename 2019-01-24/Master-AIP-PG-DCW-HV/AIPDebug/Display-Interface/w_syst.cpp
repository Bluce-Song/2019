/*******************************************************************************
 * Copyright [2016]   <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     2.0.7.1
 * author:      sl
 * brief:       头文件
*******************************************************************************/
#include "w_syst.h"
#include "ui_w_syst.h"


/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.11
  * brief:      显示时间和温度
******************************************************************************/
w_Syst::w_Syst(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::w_Syst)
{
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint); // -去掉标题栏
    ui->setupUi(this);

    Syst_Group = new QButtonGroup; // -配置按钮
    Syst_Group->addButton(ui->Key_A, Qt::Key_A);
    Syst_Group->addButton(ui->Key_H, Qt::Key_H);
    connect(Syst_Group, SIGNAL(buttonClicked(int)), this, SLOT(ButtonJudge(int)));

    dateList.append(ui->spinBox_1);
    dateList.append(ui->spinBox_2);
    dateList.append(ui->spinBox_3);
    dateList.append(ui->spinBox_4);
    dateList.append(ui->spinBox_5);
    dateList.append(ui->spinBox_6);
    ui->spinBox_6->hide();

    QPalette palette = this->palette(); // -设置背景颜色
    palette.setBrush(this->backgroundRole(), QBrush(QColor(133, 189, 229, 255), Qt::SolidPattern));
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    int i = 0;
    net_Widget_ui();

    IO_Widget = new QWidget(this);
    IO_Widget->setGeometry(150, 100, 500, 410);
    IO_Widget->setWindowFlags(Qt::WindowStaysOnTopHint);
    IO_Widget->setStyleSheet\
            ("border-radius: 10px;padding:2px 4px;background-color: gray;"\
             "color: black;border-color: black;");
    QGridLayout *IO_upside = new QGridLayout;
    QString IO_table[7]={QString(tr("延时时间(Ms):")), \
                         QString(tr("电阻平衡度:")), \
                         QString(tr("不合格弹起")), QString(tr("防呆:")), \
                        QString(tr("电阻1.5")), QString(tr("隐藏统计")), QString(tr("恢復出厂")) };
    for (i = 0; i < 7; i++) {
        IO_Show_Lable.append(new QLabel(this));
        IO_Show_Lable[i]->setText(IO_table[i]);
        IO_Show_Lable[i]->setMaximumHeight(35);
        IO_Show_Lable[i]->setMaximumWidth(135);
        IO_Show_Lable[i]->setAlignment(Qt::AlignCenter);
        IO_upside->addWidget(IO_Show_Lable[i], i, 0);
        if (i < 2) {
            IO_Line_Text.append(new QLineEdit(this));
            IO_Line_Text[i]->setMaximumHeight(35);
            IO_Line_Text[i]->setMaximumWidth(95);
            IO_upside->addWidget(IO_Line_Text[i], i, 1);
        }
    }
    NG_Push = new QCheckBox;
    NG_Push->setText(tr("不合格弹起"));
    NG_Push->setStyleSheet("QCheckBox::indicator " \
                           "{image: url(:/image/053.png);width: 55px;height: 45px;}"\
                           "QCheckBox::indicator:checked { image: url(:/image/051.png); }"\
                           "QCheckBox  { color: rgb(0, 0, 0);}");
    IO_upside->addWidget(NG_Push, 2, 1);


    stagnate = new QCheckBox;
    stagnate->setText(tr("取消"));
    stagnate->setStyleSheet\
            ("QCheckBox::indicator {image: url(:/image/053.png);width: 55px;"\
             "height: 45px;}QCheckBox::indicator:checked { image: url(:/image/051.png); }"\
             "QCheckBox  { color: rgb(0, 0, 0);}");
    IO_upside->addWidget(stagnate, 3, 1);

    dcr_Disable = new QCheckBox;
    dcr_Disable->setText(tr("使能"));
    dcr_Disable->setStyleSheet("QCheckBox::indicator "\
                               "{image: url(:/image/053.png);width: 55px;height: 45px;}"\
                               "QCheckBox::indicator:checked { image: url(:/image/051.png); }"\
                               "QCheckBox  { color: rgb(0, 0, 0);}");
    IO_upside->addWidget(dcr_Disable, 4, 1);

    Hide_Number = new QCheckBox;
    Hide_Number->setText(tr("隐藏"));
    Hide_Number->setStyleSheet("QCheckBox::indicator "\
                               "{image: url(:/image/053.png);width: 55px;height: 45px;}"\
                               "QCheckBox::indicator:checked { image: url(:/image/051.png); }"\
                               "QCheckBox  { color: rgb(0, 0, 0);}");
    IO_upside->addWidget(Hide_Number, 5, 1);

    QPushButton *button_recover = new QPushButton;
    button_recover->setText(tr("一键恢復"));
    button_recover->setMinimumHeight(50);
    button_recover->setMinimumWidth(90);
    button_recover->setStyleSheet\
            ("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"\
             "stop: 0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);");
    IO_upside->addWidget(button_recover, 6, 1);
    connect(button_recover, SIGNAL(clicked()), this, SLOT(button_recover()));

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
    IO_Widget->setLayout(Histogram_IO_Widget_layout);
    IO_Widget->hide();

    SQL_Widget = new QWidget(this);
    SQL_Widget->setGeometry(150, 100, 500, 400);
    SQL_Widget->setWindowFlags(Qt::WindowStaysOnTopHint);
    SQL_Widget->setStyleSheet\
            ("border-radius: 10px;padding:2px 4px;background-color: gray;"\
             "color: black;border-color: black;");
    QGridLayout *SQL_upside = new QGridLayout;
    QString SQL_table[6] = {"SQL-ip:", "SQL-User:", \
                            "SQL-Pass:", "SQL-Database:", \
                            "SQL-Port:", QString(tr("任务表"))};
    for (i = 0; i < 6; i++) {
        SQL_lable.append(new QLabel(this));
        SQL_lable[i]->setText(SQL_table[i]);
        SQL_lable[i]->setMaximumHeight(35); SQL_lable[i]->setMaximumWidth(135);
        SQL_lable[i]->setAlignment(Qt::AlignCenter);
        SQL_upside->addWidget(SQL_lable[i], i, 0);
        if (i < 6) {
            sql_line_Text.append(new QLineEdit(this));
            sql_line_Text[i]->setMaximumHeight(35);
            sql_line_Text[i]->setMaximumWidth(255);
            SQL_upside->addWidget(sql_line_Text[i], i, 1);
        }
    }
    sql_line_Text[2]->setEchoMode(QLineEdit::Password);
    QPushButton *button_quit_SQL = new QPushButton;
    button_quit_SQL->setText(tr("退出"));
    button_quit_SQL->setMinimumHeight(50);
    button_quit_SQL->setMinimumWidth(90);
    button_quit_SQL->setStyleSheet
            ("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: "\
             "0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);");
    SQL_upside->addWidget(button_quit_SQL, 0, 5);
    connect(button_quit_SQL, SIGNAL(clicked()), this, SLOT(SQL_Widget_autoquit()));
    net_sql_enable = new QCheckBox;
    net_sql_enable->setText(tr("启用   "));
    net_sql_enable->setStyleSheet
            ("QCheckBox::indicator {image: url(:/image/053.png);width: 55px;"\
             "height: 45px;}QCheckBox::indicator:checked { image: url(:/image/051.png); }"\
             "QCheckBox  { color: rgb(0, 0, 0);}");
    SQL_upside->addWidget(net_sql_enable, 4, 5);
    System.SaveNG = false;
    net_sql_NG = new QCheckBox;
    net_sql_NG->setText(tr("不保存数据"));
    net_sql_NG->setStyleSheet
            ("QCheckBox::indicator {image: url(:/image/053.png);width: 55px;"\
             "height: 45px;}QCheckBox::indicator:checked { image: url(:/image/051.png); }"\
             "QCheckBox  { color: rgb(0, 0, 0);}");
    SQL_upside->addWidget(net_sql_NG, 3, 5);
    QPushButton *button_set_sql = new QPushButton;
    button_set_sql->setText(tr("设置数据库"));
    button_set_sql->setMinimumHeight(50);
    button_set_sql->setMinimumWidth(90);
    button_set_sql->setStyleSheet
            ("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop:"
             "0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);");
    SQL_upside->addWidget(button_set_sql, 5, 5);
    connect(button_set_sql, SIGNAL(clicked()), this, SLOT(net_Widget_set_SQL()));
    QVBoxLayout *Histogram_Widget_layout_SQL = new QVBoxLayout;
    Histogram_Widget_layout_SQL->addLayout(SQL_upside);
    SQL_Widget->setLayout(Histogram_Widget_layout_SQL);
    SQL_Widget->hide();

    ui->comb_power->setDisabled(true);

    QStringList System_list; //  默认 System/Text
    System_list.clear();
    System_list.append("9");   // -蜂鸣器的档位
    System_list.append("0.1"); // -合格时间
    System_list.append("0.3"); // -不合格时间
    System_list.append("9");   // -Led档位
    System_list.append("0");   // -启动模式
    System_list.append("1");   // -管理员

    QStringList Allocation_list; // -默认 Allocation/Item
    Allocation_list.clear();
    Allocation_list.append("13");
    Allocation_list.append("14");
    Allocation_list.append("0");
    Allocation_list.append("0");
    Allocation_list.append("0");
    Allocation_list.append("0");
    Allocation_list.append("1");

    int SQLData_number = 0;
    QStringList SQLData_list;
    System_power      = "none";

    QSettings *set_Sys = new QSettings(Sys_path, QSettings::IniFormat);
    set_Sys->setIniCodec("GB18030");

    System.Sum        = set_Sys->value("System/Text", System_list).toStringList();
    System.SQL_enable = set_Sys->value("Sql/Text", "disable").toString();
    System.SaveNG     = set_Sys->value("Sql/SaveNG", "0").toInt();
    System.NG_Push = set_Sys->value("System/NG_Push", "0").toInt();
    SQLData_number    = set_Sys->value("Allocation/All", "7").toString().toInt();
    SQLData_list      = set_Sys->value("Allocation/Item", Allocation_list).\
            toStringList().mid(5, SQLData_number); // -数据型号
    DeChang_Enable    = set_Sys->value("DeChang/Enable", 0).toInt();
    DeChang_baudRate  = set_Sys->value("DeChang/baudRate", 0).toInt();
    DeChang_Commontion = set_Sys->value("DeChang/Commontion", 0).toInt();
    Int_Diaolay_number = set_Sys->value("System/Display_number", 0).toInt(); // 显示合格与不合格

    IO_Line_Text[0]->setText(set_Sys->value("System/IO_Delay_Time", "0").toString());
    IO_Line_Text[1]->setText(set_Sys->value("System/Unbalance", "1").toString());

    if (SQLData_list.contains("7") || \
            SQLData_list.contains("9") || \
            SQLData_list.contains("10")) { // -整机操作
        System_power = "All";
        ui->comb_power->setEnabled(true);
        ui->comb_power->setCurrentIndex(set_Sys->value("power/Text", "0")\
                                        .toString().toInt()); // 读取电源选择
    }
    if (System.SQL_enable == "enable") { // -读取数据库使能
        net_sql_enable->setChecked(true);
    }
    if (System.SaveNG) { // -读取数据库使能
        net_sql_NG->setChecked(true);
    }

    if (System.NG_Push) {
        NG_Push->setChecked(true);
    } else {
        //
    }

    if (Int_Diaolay_number) {
        Hide_Number->setChecked(true);
    } else {
        //
    }

    if (DeChang_Enable) {
        ui->Button_Usart->show();
    } else {
        ui->Button_Usart->hide();
    }

    sql_line_Text.at(5)->setText(set_Sys->value("Sql/Task_Table", "").toString());
    if (set_Sys->value("language/Text").toString() == "English") {  // -读取语言选择设置
        ui->comb_language->setCurrentIndex(1);
    } else if (set_Sys->value("language/Text").toString() == "Japan") { // 读取语言选择设置
        ui->comb_language->setCurrentIndex(2);
    } else {
        //
    }

    if (set_Sys->value("language/enabled").toString() == "Enable") { // -使能语言选择
        ui->comb_language->setEnabled(true);
    }
    ui->comb_imp_back->setDisabled(true);
    if (set_Sys->value("impvolt/text", QString(tr("back"))).toString() == \
            QString(tr("back"))) {
        ui->comb_imp_back->setCurrentIndex(0);
    } else {
        ui->comb_imp_back->setCurrentIndex(1);
    }
    if (set_Sys->value("stagnate/text", 0).toInt() == 2) {  //  防呆
        stagnate->setChecked(true);
    } else {
        //
    }

    if (set_Sys->value("System/dcr_Disable", 0).toInt() == 2) {  //  使能
        dcr_Disable->setChecked(true);
    } else {
       //
    }

    ui->comb_Beep->setCurrentIndex(System.Sum[0].toInt());
    ui->Beep_OK->setValue(System.Sum[1].toDouble());
    ui->Beep_NG->setValue(System.Sum[2].toDouble());
    ui->comb_Led->setCurrentIndex(System.Sum[3].toInt());
    ui->comb_Start->setCurrentIndex(System.Sum[4].toInt());
    ui->comb_Conf->setCurrentIndex(System.Sum[5].toInt());
    ui->scan_start->setValue(set_Sys->value("Barcode/start").toString().toInt());
    ui->scan_stop->setValue(set_Sys->value("Barcode/stop").toString().toInt());
    on_Led_Button_clicked();
    system("sync");
    delete set_Sys;

    L_count = 0;
    R_count = 0;

    QDir dir; // 备份文件
    if (!dir.exists("/mnt/Record")) {
        system("mkdir /mnt/Record");
        system("chmod +x /mnt/Record");
        system("cp /mnt/nandflash/AIP/Sys.ini /mnt/Record");
    } else {
        if (!dir.exists("/mnt/Record/Sys.ini")) {
            system("cp /mnt/nandflash/AIP/Sys.ini /mnt/Record");
        } else {
            //
        }
    }



    QString Get_Static_ip;
    QSettings *set_userinfo = new QSettings("/mnt/nandflash/userinfo.txt", QSettings::IniFormat);
    set_userinfo->setIniCodec("GB18030");
    Get_Static_ip = set_userinfo->value("LOCAL_MACHINE/DHCP").toString();
    Get_Static_ip = Get_Static_ip.replace(QRegExp("'"), "");
    if (Get_Static_ip == QString(tr("0"))) {
        //
    } else {
        Static_Ip->setChecked(true);
    }
    delete set_userinfo;

    char copystr[256];
    QString Time_string;
    LINUX_RTC rtc;
    rtc_time t;
    I2COpen(); // 打开ＲＴＣ接口
    for (i = 0; i < 7; i++) { //读取 DS1302 当前时间
        time[i] = DS1302SingleRead(i); //读取秒寄存器
        if (QString::number(time[6], 16).toInt() > 11) {
            t.tm_year = QString::number(time[6], 16).toInt() + 2000; // 10 转化为 １６进制显示
            t.tm_mon = QString::number(time[4], 16).toInt();
            t.tm_mday = QString::number(time[3], 16).toInt();
            t.tm_hour = QString::number(time[2], 16).toInt();
            t.tm_min  = QString::number(time[1], 16).toInt();
            t.tm_sec  = QString::number(time[0], 16).toInt();

            rtc.get_rtc();
            rtc.set_rtc(t);

            Time_string = "'" + QString::number(t.tm_year) + "-" \
                    + QString("%1").arg(t.tm_mon, 2, 10, QLatin1Char('0')) + "-"\
                    + QString("%1").arg(t.tm_mday, 2, 10, QLatin1Char('0')) + " "\
                    + QString("%1").arg(t.tm_hour, 2, 10, QLatin1Char('0')) + ":"\
                    + QString("%1").arg(t.tm_min, 2, 10, QLatin1Char('0')) + ":"\
                    + QString("%1").arg(t.tm_sec, 2, 10, QLatin1Char('0'))\
                    + "'";
            sprintf(copystr, "date -s %s", \
                    QString(Time_string).toUtf8().data());
            system(copystr);
        } else {
            //
        }
    }

    Usart_UI();
}

w_Syst::~w_Syst()
{
    delete Syst_Group;
    delete ui;
}

void w_Syst::net_Widget_ui() {
    net_Widget = new QWidget(this);
    net_Widget->setGeometry(150, 100, 500, 410);
    net_Widget->setWindowFlags(Qt::WindowStaysOnTopHint);
    net_Widget->setStyleSheet
            ("border-radius: 10px;padding:2px 4px;background-color: gray;"\
             "color: black;border-color: black;");
    QGridLayout *upside = new QGridLayout;
    QString net_table[6] = {"ip:", QString(tr("网关:")), "DNS:", QString(tr("自动获取")), \
                            QString(tr("Wifi 名称")), QString(tr("Wifi 密码"))};
    int i = 0;
    for (i = 0; i < 6; i++) {
        PushHist_lable.append(new QLabel(this));
        PushHist_lable[i]->setText(net_table[i]);
        PushHist_lable[i]->setMaximumHeight(35);
        PushHist_lable[i]->setMaximumWidth(135);
        PushHist_lable[i]->setAlignment(Qt::AlignCenter);
        upside->addWidget(PushHist_lable[i], i, 0);
        if (i < 3) {
            net_line_Text.append(new QLineEdit(this));
            net_line_Text[i]->setMaximumHeight(35);
            net_line_Text[i]->setMaximumWidth(255);
            upside->addWidget(net_line_Text[i], i, 1);
        } else if (i > 3) {
            net_line_Text.append(new QLineEdit(this));
            net_line_Text[i - 1]->setMaximumHeight(35);
            net_line_Text[i - 1]->setMaximumWidth(255);
            upside->addWidget(net_line_Text[i - 1], i, 1);
        } else {
            //
        }
    }
    Static_Ip = new QCheckBox;
    Static_Ip->setText(tr("设置"));
    Static_Ip->setStyleSheet\
            ("QCheckBox::indicator {image: url(:/image/053.png);width: 55px;"\
             "height: 45px;}QCheckBox::indicator:checked { image: url(:/image/051.png); }"\
             "QCheckBox  { color: rgb(0, 0, 0);}");
    upside->addWidget(Static_Ip, 3, 1);

    QPushButton *button_quit = new QPushButton;
    button_quit->setText(tr("退出"));
    button_quit->setMinimumHeight(50);
    button_quit->setMinimumWidth(90);
    button_quit->setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"\
                               "stop: 0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);");
    upside->addWidget(button_quit, 0, 5);
    connect(button_quit, SIGNAL(clicked()), this, SLOT(net_Widget_autoquit()));

    QPushButton *button_set_net = new QPushButton;
    button_set_net->setText(tr("设置网络"));
    button_set_net->setMinimumHeight(50);
    button_set_net->setMinimumWidth(90);
    button_set_net->setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"\
                                  "stop: 0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);");
    upside->addWidget(button_set_net, 2, 5);
    connect(button_set_net, SIGNAL(clicked()), this, SLOT(net_Widget_set_net()));

    QPushButton *button_Wifi = new QPushButton;
    button_Wifi->setText(tr("设置无线"));
    button_Wifi->setMinimumHeight(50);
    button_Wifi->setMinimumWidth(90);
    button_Wifi->setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"\
                                  "stop: 0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);");
    upside->addWidget(button_Wifi, 5, 5);
    connect(button_Wifi, SIGNAL(clicked()), this, SLOT(Wifi_set_net()));

    QVBoxLayout *Histogram_Widget_layout = new QVBoxLayout;
    Histogram_Widget_layout->addLayout(upside);
    net_Widget->setLayout(Histogram_Widget_layout);
    net_Widget->hide();

    QString line_data;
    QFile file("/etc/wpa_supplicant.conf");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        //
    } else {
        QTextStream in(&file);
        in.setCodec("UTF-8");
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line.contains("ssid=\"", Qt::CaseInsensitive)) {
               line_data = line;
               line_data.replace(QRegExp("ssid=\""), QString(""));
               line_data.remove(QRegExp("\\s"));
               line_data.replace(QRegExp("\""), QString(""));
               net_line_Text.at(3)->setText(line_data);
            }
            if (line.contains("psk=", Qt::CaseInsensitive)) {
               line_data = line;
               line_data.replace(QRegExp("psk="), QString(""));
               line_data.remove(QRegExp("\\s"));
               line_data.replace(QRegExp("\""), QString(""));
               net_line_Text.at(4)->setText(line_data);
            }
        }
        file.close();
    }
}

void w_Syst::Usart_UI() {
    int i;

    Usart_Widget = new QWidget(this);
    Usart_Widget->setGeometry(150, 100, 500, 410);
    Usart_Widget->setWindowFlags(Qt::WindowStaysOnTopHint);
    Usart_Widget->setStyleSheet\
            (".QWidget{border-radius: 10px;padding:2px 4px;background-color: gray;"\
             "color: black;border-color: black;}");
    QGridLayout *Usart_upside = new QGridLayout;
    Usart_upside->setSpacing(20);
    QString Usart_table[2]={QString(tr("通信方式:")), \
                         QString(tr("波特率:"))};
    for (i = 0; i < 2; i++) {
        Usart_Show_Lable.append(new QLabel(this));
        Usart_Show_Lable[i]->setText(Usart_table[i]);
        Usart_Show_Lable[i]->setMaximumHeight(35);
        Usart_Show_Lable[i]->setMaximumWidth(135);
        Usart_Show_Lable[i]->setAlignment(Qt::AlignCenter);
        Usart_upside->addWidget(Usart_Show_Lable[i], i, 0);
    }

    Usart_Commontion = new QComboBox;
    Usart_Commontion->addItem(tr("直接式"));
    Usart_Commontion->addItem(tr("交互式"));
    Usart_upside->addWidget(Usart_Commontion, 0, 1);
    Usart_Commontion->setCurrentIndex(DeChang_Commontion);

    Usart_baudRatecomboBox = new QComboBox;
    Usart_baudRatecomboBox->addItem("115200"); // 115200
    Usart_baudRatecomboBox->addItem("19200"); // 19200
    Usart_baudRatecomboBox->addItem("9600");
    Usart_upside->addWidget(Usart_baudRatecomboBox, 1, 1);
    Usart_baudRatecomboBox->setCurrentIndex(DeChang_baudRate);
    Usart_baudRatecomboBox->setDisabled(true);

    QPushButton *Usart_button_quit = new QPushButton;
    Usart_button_quit->setText(tr("退出"));
    Usart_button_quit->setMinimumHeight(50);
    Usart_button_quit->setMinimumWidth(90);
    Usart_button_quit->setStyleSheet\
            ("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"\
             "stop: 0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);");
    Usart_upside->addWidget(Usart_button_quit, 0, 2);
    connect(Usart_button_quit, SIGNAL(clicked()), this, SLOT(Usart_Widget_autoquit()));

    Usart_OC = new QPushButton;
    Usart_OC->setText(tr("关闭串口"));
    Usart_OC->setMinimumHeight(50);
    Usart_OC->setMinimumWidth(90);
    Usart_OC->setStyleSheet\
            ("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"\
             "stop: 0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);");
    Usart_upside->addWidget(Usart_OC, 1, 2);
    connect(Usart_OC, SIGNAL(clicked()), this, SLOT(Usart_OC_Clicked()));

    QVBoxLayout *Histogram_Usart_Widget_layout = new QVBoxLayout;
    Histogram_Usart_Widget_layout->addLayout(Usart_upside);
    Usart_Widget->setLayout(Histogram_Usart_Widget_layout);
    Usart_Widget->hide();
}

void w_Syst::update_system()
{
    System.Sum.clear();
    System.Sum.append(QString::number(ui->comb_Beep->currentIndex())); // -蜂鸣器时间
    System.Sum.append(ui->Beep_OK->text());
    System.Sum.append(ui->Beep_NG->text());
    System.Sum.append(QString::number(ui->comb_Led->currentIndex()));  // -液晶屏亮度
    System.Sum.append(QString::number(ui->comb_Start->currentIndex())); // -启动方式
    System.Sum.append(QString::number(ui->comb_Conf->currentIndex())); // -管理员和操作员
    System.Sum.append(ui->comb_Start->currentText()); // -启动方式
    System.Sum.append(ui->comb_Conf->currentText());  // -用户
    System.Sum.append(ui->scan_start->text());        // -条码扫描起始
    System.Sum.append(ui->scan_stop->text());         // -条码扫描终止
}
void w_Syst::ButtonJudge(int id)
{
    qDebug() << "w_Syst::ButtonJudge()" << id;
    switch (id) {
    case Qt::Key_A: {
        IO_Widget->hide();
        net_Widget->hide();
        SQL_Widget->hide();
        update_system();
        signal_to_main(QStringList(""), wMain_Surface, 3);
        signal_to_main(System.Sum, 2, 2);

        QString currentDateTime = QDateTime::currentDateTime()\
                .toString("yyyy-MM-dd---hh-mm-ss"); // -设置显示格式
        QSettings set_Test_File(Test_Day_Record_path,  QSettings::IniFormat);
        set_Test_File.setIniCodec(QTextCodec::codecForName("GB2312"));
        QDir *temp = new QDir;   bool exist = temp->exists(Test_Day_Record_path);
        if (exist) {
            //
        } else {
            system("mkdir /mnt/nandflash/AIP/dayrecord/");
            system("touch /mnt/nandflash/AIP/dayrecord/dayrecord.ini");
            system("chmod +x /mnt/nandflash/AIP/dayrecord/dayrecord.ini");
        }
        QString keyname;
        keyname = QString("Data/%1").arg(currentDateTime);
        set_Test_File.setValue(keyname, System.Sum.at(6)+System.Sum.at(7));

        QSettings *set_Sys = new QSettings(Sys_path, QSettings::IniFormat);
        set_Sys->setIniCodec("GB18030");
        set_Sys->setValue("Barcode/start", QString::number(ui->scan_start->value()));
        set_Sys->setValue("Barcode/stop", QString::number(ui->scan_stop->value()));
        set_Sys->setValue("System/IO_Delay_Time", IO_Line_Text[0]->text());
        set_Sys->setValue("System/Unbalance", IO_Line_Text[1]->text());
        set_Sys->setValue("DeChang/baudRate", Usart_baudRatecomboBox->currentIndex());
        set_Sys->setValue("DeChang/Commontion", Usart_Commontion->currentIndex());
        if (ui->comb_language->currentIndex() == 0) {
            set_Sys->setValue("language/Text", "Chinese");
        } else if (ui->comb_language->currentIndex() == 1) {
            set_Sys->setValue("language/Text", "English");
        } else {
            set_Sys->setValue("language/Text", "Japan");
        }


        if (System_power == "All") { //  整机
            set_Sys->setValue("power/Text", QString::number(ui->comb_power->currentIndex()));
        } else {
            //  定子
        }

        if (ui->comb_imp_back->currentIndex() == 0) {
            set_Sys->setValue("impvolt/text", QString(tr("back")));
        } else {
            set_Sys->setValue("impvolt/text", QString(tr("noback")));
        }
        if (NG_Push->checkState() == 2) {
            set_Sys->setValue("System/NG_Push", "1");
        } else {
            set_Sys->setValue("System/NG_Push", "0");
        }

        if (Hide_Number->checkState() == 2) {
            set_Sys->setValue("System/Display_number", "2");
        } else {
            set_Sys->setValue("System/Display_number", "0");
        }

        if (stagnate->checkState() == 2) {
            set_Sys->setValue("stagnate/text", "2");
        } else {
            set_Sys->setValue("stagnate/text", "0");
        }

        if (dcr_Disable->checkState() == 2) {
            set_Sys->setValue("System/dcr_Disable", "2");
        } else {
            set_Sys->setValue("System/dcr_Disable", "0");
        }
        system("sync");
        delete set_Sys;
        break;
    }
    default:
        //
        break;
    }
    qDebug() << "w_Syst::ButtonJudge()Finsh";
}

void w_Syst::on_Key_H_clicked()
{
    ui->Key_H->setDisabled(true);
    IO_Widget->hide();
    net_Widget->hide();
    SQL_Widget->hide();
    signal_to_main(QStringList(""), wPassWord_Surface, 3);
}

void w_Syst::on_Timer_clicked()
{
    int i;
    char copystr[256];
    QString Time_string;
    LINUX_RTC rtc;
    rtc_time t;

    if (!dateList.isEmpty()) {
        t.tm_year = dateList[0]->value();
        t.tm_mon  = dateList[1]->value();
        t.tm_mday = dateList[2]->value();
        t.tm_hour = dateList[3]->value();
        t.tm_min  = dateList[4]->value();
        t.tm_sec  = dateList[5]->value();
    }


    Time_string = "'" + QString::number(t.tm_year) + "-" \
            + QString("%1").arg(t.tm_mon, 2, 10, QLatin1Char('0')) + "-"\
            + QString("%1").arg(t.tm_mday, 2, 10, QLatin1Char('0')) + " "\
            + QString("%1").arg(t.tm_hour, 2, 10, QLatin1Char('0')) + ":"\
            + QString("%1").arg(t.tm_min, 2, 10, QLatin1Char('0')) + ":"\
            + QString("%1").arg(t.tm_sec, 2, 10, QLatin1Char('0'))\
            + "'";
    sprintf(copystr, "date -s %s", \
            QString(Time_string).toUtf8().data());
    system(copystr);
    rtc.set_rtc(t);

    DS1302SingleWrite(7, 0x00); // 撤销写保护以允许写入数据
    DS1302SingleWrite(0, QString::number(dateList[5]->value()).toInt(NULL, 16)); // 秒
    DS1302SingleWrite(1, QString::number(dateList[4]->value()).toInt(NULL, 16)); // 分
    DS1302SingleWrite(2, QString::number(dateList[3]->value()).toInt(NULL, 16)); // 时
    DS1302SingleWrite(3, QString::number(dateList[2]->value()).toInt(NULL, 16)); // 日
    DS1302SingleWrite(4, QString::number(dateList[1]->value()).toInt(NULL, 16)); // 月
    if (dateList[0]->value() > 2000) { // 年
        DS1302SingleWrite(6, QString::number(dateList[0]->value() - 2000).toInt(NULL, 16));
    } else {
        DS1302SingleWrite(6, 0x00);
    }
}

void w_Syst::gettime()
{
    LINUX_RTC rtc;
    rtc_time t;
    t = rtc.get_rtc();
    dateList[0]->setValue(t.tm_year);
    dateList[1]->setValue(t.tm_mon);
    dateList[2]->setValue(t.tm_mday);
    dateList[3]->setValue(t.tm_hour);
    dateList[4]->setValue(t.tm_min);
}

void w_Syst::on_Beep_Button_clicked()
{
    if (ui->Beep_Button->text() == QString(tr("停止"))) {
        ui->Beep_Button->setText(tr("音量 设定查看"));
        Beep_PWM_Stop();
    } else if (ui->Beep_Button->text() == QString(tr("音量 设定查看"))) {
        ui->Beep_Button->setText(tr("停止"));
        Beep_PWM_Start(ui->comb_Beep->currentText().toInt()*10-1);
    } else {
        //
    }
}

void w_Syst::on_Led_Button_clicked()
{
    Led_PWM_Start(ui->comb_Led->currentText().toInt()-1);
}

void w_Syst::on_Button_Check_clicked()
{
    signal_to_main(QStringList(""), 1, 1);
}

void w_Syst::slot_from_main(QString str, int value)
{
    switch (value) {
    case 1:
        check_finsh(str);
        break;
    case 2:
        ui->Key_H->setEnabled(true);
        gettime();
        break;
    case 3:
        ui->comb_imp_back->setEnabled(true);
        break;
    case 4:
        IO_Line_Text[3]->setText(str);
        break;
    default:
        break;
    }
}

void w_Syst::check_finsh(QString Waring_Text)
{
    QMessageBox *message = new QMessageBox(this);
    message->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    message->setStyleSheet("QMessageBox{border: gray;border-radius: 10px;"\
                           "padding:2px 4px;background-color: gray;height:390px;width:375px;}");
    message->setText(Waring_Text+"\n");
    message->addButton(QMessageBox::Ok)->setStyleSheet
            ("height:39px;width:75px;border:5px groove;"\
             "border:none;border-radius:10px;padding:2px 4px;");
    message->setButtonText(QMessageBox::Ok, QString(tr("确 定")));
    message->setIcon(QMessageBox::Warning);
    message->exec();
}

void w_Syst::on_Button_Check_2_clicked()
{
    system("./ts_calibrate -qws&");
}

void w_Syst::Wifi_set_net() {
    QString Set_qq;    Set_qq = "\"";
    QString line_data;
    QString ssid; ssid =  net_line_Text.at(3)->text() + Set_qq;
    QString psk;  psk = Set_qq + net_line_Text.at(4)->text() + Set_qq;

    QFile file("/etc/wpa_supplicant.conf");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        //
    } else {
        QTextStream in(&file);
        in.setCodec("UTF-8");
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line.contains("ssid=\"", Qt::CaseInsensitive)) {
               line.replace(QRegExp("ssid=\".*"), QString("ssid=\"") + ssid);
            }
            if (line.contains("psk=", Qt::CaseInsensitive)) {
               line.replace(QRegExp("psk=.*"), QString("psk=") + psk);
            }
            line = line + "\n";
            line_data = line_data + line;
        }
        file.close();
        QFile::remove("/etc/wpa_supplicant.conf");
        if (!file.open(QIODevice::WriteOnly)) {
            qDebug() << "w_Syst::Wifi_set_net()Cannot open file for Writing";
            return;
        }

        file.write(line_data.toUtf8());
        file.close();
    }
}

void w_Syst::net_Widget_set_net()
{
    char copystr[256];
    char *whom;
    if (net_line_Text.at(0)->text() != "") {
        whom = QString(net_line_Text.at(0)->text()).toUtf8().data();
        sprintf(copystr, "ifconfig eth0 %s netmask 255.255.255.0", whom);
        system(copystr);
    }
    if (net_line_Text.at(1)->text() != "") {
        whom = QString(net_line_Text.at(1)->text()).toUtf8().data();
        sprintf(copystr, "echo nameserver %s >>/etc/resolv.conf", whom);
        system(copystr);
    }
    if (net_line_Text.at(2)->text() != "") {
        whom = QString(net_line_Text.at(2)->text()).toUtf8().data();
        sprintf(copystr, "route add default gw %s", whom);
        system(copystr);
    }

    QString Set_qq;    Set_qq = "\"";
    QString DHCP;
    QString line_data;
    QString IPAddress; IPAddress = Set_qq + net_line_Text.at(0)->text() + Set_qq;
    QString DefaultGateway; DefaultGateway = Set_qq + net_line_Text.at(1)->text() + Set_qq;
    QString SubnetMask; SubnetMask = Set_qq + net_line_Text.at(2)->text() + Set_qq;

    if (Static_Ip->checkState() == 2) {
        DHCP = Set_qq + "1" + Set_qq;
    } else {
        DHCP = Set_qq + "0" + Set_qq;
    }

    QFile file("/mnt/nandflash/userinfo.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        //
    } else {
        QTextStream in(&file);
        in.setCodec("UTF-8");
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line.contains("IPAddress=", Qt::CaseInsensitive)) {
               line.replace(QRegExp("IPAddress=.*"), QString("IPAddress=") + IPAddress);
            }
            if (line.contains("DefaultGateway=", Qt::CaseInsensitive)) {
                line.replace(QRegExp("DefaultGateway=.*"), \
                             QString("DefaultGateway=") + DefaultGateway);
            }
            if (line.contains("SubnetMask=", Qt::CaseInsensitive)) {
                line.replace(QRegExp("SubnetMask=.*"), QString("SubnetMask=") + SubnetMask);
            }
            if (line.contains("DHCP=", Qt::CaseInsensitive)) {
                line.replace(QRegExp("DHCP=.*"), QString("DHCP=") + DHCP);
            } else {
                //
            }
            line = line + "\n";
            line_data = line_data + line;
        }
        file.close();
        QFile::remove("/mnt/nandflash/userinfo.txt");
        if (!file.open(QIODevice::WriteOnly)) {
            qDebug() << "w_Syst::net_Widget_set_net() Cannot open file for Writing";
            return;
        }

        file.write(line_data.toUtf8());
        file.close();
    }
}

void w_Syst::net_Widget_set_SQL() //  /usr/local/arm/unixODBC/etc
{
    QSettings set_odbc("/usr/local/arm/unixODBC/etc/odbc.ini",  QSettings::IniFormat);
    if (sql_line_Text.at(0)->text() != "") { //  Server
        set_odbc.setValue("testodbc/Server", sql_line_Text.at(0)->text());
    }
    if (sql_line_Text.at(1)->text() != "") { //  UserName
        set_odbc.setValue("testodbc/UserName", sql_line_Text.at(1)->text());
    }
    if (sql_line_Text.at(2)->text() != "") { //  Password
        set_odbc.setValue("testodbc/Password", sql_line_Text.at(2)->text());
    }
    if (sql_line_Text.at(3)->text() != "") { //  Database
        set_odbc.setValue("testodbc/Database", sql_line_Text.at(3)->text());
    }
    if (sql_line_Text.at(4)->text() != "") { //  Port
        set_odbc.setValue("testodbc/Port", sql_line_Text.at(4)->text());
    }

    QSettings *set_Sys = new QSettings(Sys_path,  QSettings::IniFormat);
    if (net_sql_enable->checkState() == 2) {
        set_Sys->setValue("Sql/Text", "enable");
    } else {
        set_Sys->setValue("Sql/Text", "disable");
    }

    if (net_sql_NG->checkState() == 2) {
        set_Sys->setValue("Sql/SaveNG", "1");
    } else {
        set_Sys->setValue("Sql/SaveNG", "0");
    }


    if (net_sql_NG->checkState() == 2) {
        set_Sys->setValue("Sql/SaveNG", "1");
    } else {
        set_Sys->setValue("Sql/SaveNG", "0");
    }

    if (sql_line_Text.at(5)->text() != "") {
        set_Sys->setValue("Sql/Task_Table", sql_line_Text.at(5)->text());
    }

    delete set_Sys;
    system("sync");
}
void w_Syst::button_recover() {
    QMessageBox Collect_Ask;
    Collect_Ask.setWindowFlags(Qt::FramelessWindowHint);
    Collect_Ask.setStyleSheet\
            ("QMessageBox{border:3px groove gray;"\
             "}background-color: rgb(209, 209, 157);");
    Collect_Ask.setText(tr("   恢复出厂？  "));
    Collect_Ask.addButton(QMessageBox::Ok)->setStyleSheet\
            ("border:none;height:30px;width:65px;border:5px groove gray;"\
             "border-radius:10px;padding:2px 4px;");

    Collect_Ask.addButton(QMessageBox::Cancel)->setStyleSheet\
            ("border:none;height:30px;width:65px;border:5px groove gray;"\
             "border-radius:10px;padding:2px 4px;");
    Collect_Ask.setButtonText(QMessageBox::Ok, QString(tr("确定")));
    Collect_Ask.setButtonText(QMessageBox::Cancel, QString(tr("取消")));
    Collect_Ask.setIcon(QMessageBox::Warning);
    int ret = Collect_Ask.exec();
    if (ret == QMessageBox::Ok) {
       system("cp /mnt/Record/Sys.ini /mnt/nandflash/AIP/");
    } else if (ret == QMessageBox::Cancel) {
        //
    } else {
        //
    }
}

void w_Syst::IO_Widget_autoquit() {
    signal_to_main(QStringList(""), IO_Line_Text[0]->text().toInt(), 5);
    IO_Widget->hide();
}

void w_Syst::Usart_OC_Clicked() {
    if (Usart_OC->text() == QString(tr("打开串口"))) {
        Usart_OC->setText(QString(tr("关闭串口")));
        Usart_baudRatecomboBox->setDisabled(true);
        signal_to_main(QStringList(""), Usart_baudRatecomboBox->currentIndex(), 10);
    } else if (Usart_OC->text() == QString(tr("关闭串口"))) {
        Usart_OC->setText(QString(tr("打开串口")));
        Usart_baudRatecomboBox->setEnabled(true);
        signal_to_main(QStringList(""), 9, 9);
    } else {
        //
    }
}

void w_Syst::Usart_Widget_autoquit() {
    Usart_Widget->hide();
}

void w_Syst::Left_Widget_autoquit() {
    L_count++;
    if (L_count%2) {
        signal_to_main(QStringList(""), 2, 8);
    } else {
        signal_to_main(QStringList(""), 0, 8);
    }
}

void w_Syst::Right_Widget_autoquit() {
    R_count++;
    if (R_count%2) {
        signal_to_main(QStringList(""), 4, 8);
    } else {
        signal_to_main(QStringList(""), 0, 8);
    }
}

void w_Syst::IO_RFID_Read() {
    signal_to_main(QStringList(""), 7, 7);
}

void w_Syst::IO_RFID_Write() {
    signal_to_main(QStringList(""), IO_Line_Text[4]->text().toInt(), 6);

    QSettings *set_Sys = new QSettings(Sys_path, QSettings::IniFormat);
    if (IO_Line_Text.at(4)->text() != "") {
        set_Sys->setValue("RFID/Code", IO_Line_Text.at(4)->text());
    }
    delete set_Sys;
    system("sync");
}
void w_Syst::net_Widget_autoquit()
{
    net_Widget->hide();
}

void w_Syst::SQL_Widget_autoquit()
{
    SQL_Widget->hide();
}

QString w_Syst::GetIP()
{
    int sock_get_ip;
    char ipaddr[50];
    struct  sockaddr_in *sin;
    struct  ifreq ifr_ip;
    if ((sock_get_ip=socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        //
    }
    memset(&ifr_ip, 0, sizeof(ifr_ip));
    strncpy(ifr_ip.ifr_name, "eth0", sizeof(ifr_ip.ifr_name) - 1);
    if (ioctl(sock_get_ip, SIOCGIFADDR, &ifr_ip) < 0) {
        //
    }
    sin = (struct sockaddr_in *)&ifr_ip.ifr_addr;
    strcpy(ipaddr, inet_ntoa(sin->sin_addr));
    return QString(ipaddr);
}

QString w_Syst::GetGateWay()
{
    FILE *fp;
    char buf[512];
    char cmd[128];
    char gateway[30];
    char *tmp;

    strcpy(cmd, "ip route");
    fp = popen(cmd, "r");
    if (NULL == fp) {
        perror("popen error");
        return "";
    }
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        tmp = buf;
        while (*tmp && isspace(*tmp))
            ++tmp;
        if (strncmp(tmp, "default", strlen("default")) == 0)
            break;
    }
    sscanf(buf, "%*s%*s%s", gateway);

    pclose(fp);

    return QString(gateway);
}

void w_Syst::on_Button_Check_3_clicked()
{
    QString Get_DefaultGateway;
    QString Get_Static_DNS;
    QSettings *set_userinfo = new QSettings("/mnt/nandflash/userinfo.txt", QSettings::IniFormat);
    set_userinfo->setIniCodec("GB18030");
    Get_DefaultGateway = set_userinfo->value("LOCAL_MACHINE/DefaultGateway").toString();
    Get_Static_DNS = set_userinfo->value("LOCAL_MACHINE/SubnetMask", \
                                         QString("255.255.255.0")).toString();
    delete set_userinfo;

    Get_DefaultGateway = Get_DefaultGateway.replace(QRegExp("'"), "");
    Get_Static_DNS = Get_Static_DNS.replace(QRegExp("'"), "");
    net_line_Text.at(0)->setText(GetIP()); //  ip
    net_line_Text.at(1)->setText(Get_DefaultGateway); //  网关
    net_line_Text.at(2)->setText(Get_Static_DNS); //  DNS
    net_Widget->show();
}

void w_Syst::on_lineEdit_editingFinished()
{
    if ((ui->scan_start->text().toInt() == 0) && (ui->scan_stop->text().toInt() == 0)) {
        //
    } else if ((ui->scan_start->text().toInt() < ui->lineEdit->text().size()) && \
             (ui->scan_stop->text().toInt() < ui->lineEdit->text().size())) {
        ui->lineEdit->setText(ui->lineEdit->text().mid(ui->scan_start->text().toInt(), \
                       ui->scan_stop->text().toInt()-ui->scan_start->text().toInt()));
    } else if ((ui->scan_start->text().toInt() < ui->lineEdit->text().size()) && \
               (ui->scan_stop->text().toInt() > ui->lineEdit->text().size())) {
        ui->lineEdit->setText(ui->lineEdit->text().mid(ui->scan_start->text().toInt(), \
                        ui->lineEdit->text().size()-ui->scan_start->text().toInt()));
    } else if (ui->scan_start->text().toInt() >= ui->lineEdit->text().size()) {
        ui->lineEdit->setText("");
    } else {
        //
    }
}

void w_Syst::on_scan_start_editingFinished()
{
    if (ui->scan_start->text().toInt() > ui->scan_stop->text().toInt()) {
        ui->scan_start->setValue(0);
    }
}

void w_Syst::on_scan_stop_editingFinished()
{
    if (ui->scan_start->text().toInt() > ui->scan_stop->text().toInt()) {
        ui->scan_start->setValue(0);
    }
}

void w_Syst::on_Button_SQL_clicked()
{
    QSettings set_odbc("/usr/local/arm/unixODBC/etc/odbc.ini", QSettings::IniFormat);
    sql_line_Text.at(0)->setText(set_odbc.value("testodbc/Server").toString()); //  SQL-IP
    sql_line_Text.at(1)->setText(set_odbc.value("testodbc/UserName").toString()); //  SQL-User
    sql_line_Text.at(2)->setText(set_odbc.value("testodbc/Password").toString()); //  SQL-Pass
    sql_line_Text.at(3)->setText(set_odbc.value("testodbc/Database").toString()); //  SQL-Database
    sql_line_Text.at(4)->setText(set_odbc.value("testodbc/Port").toString()); //  SQL-Port
    SQL_Widget->show();
}
void w_Syst::on_Button_IO_clicked()
{
    IO_Widget->show();
}

void w_Syst::on_Button_Usart_clicked()
{
    Usart_Widget->show();
}
