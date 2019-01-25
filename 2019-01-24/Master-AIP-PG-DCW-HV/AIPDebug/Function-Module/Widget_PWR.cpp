/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "Widget_PWR.h"
#include "ui_Widget_PWR.h"

Widget_PWR::Widget_PWR(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_PWR)
{
    ui->setupUi(this);

    //  电参设置表头
    ui->pwrTab->horizontalHeader()->setStyleSheet\
            ("QHeaderView::section{background-color:#191919;color: white;"\
             "padding-left: 4px;border: 1px solid #447684;}");
    ui->pwrTab->horizontalHeader()->setFixedHeight(25);
    ui->pwrTab->horizontalHeader()->setResizeMode(QHeaderView::Fixed);
    ui->pwrTab->setColumnWidth(0, 100);
    ui->pwrTab->setColumnWidth(1, 70);
    ui->pwrTab->setColumnWidth(2, 70);
    ui->pwrTab->setColumnWidth(3, 85);
    ui->pwrTab->setColumnWidth(4, 85);
    ui->pwrTab->setColumnWidth(5, 75);
    ui->pwrTab->setColumnWidth(6, 75);
    ui->pwrTab->setColumnWidth(7, 70);

    ui->pwrset_Turn->horizontalHeader()->setStyleSheet\
           ("QHeaderView::section{background-color:#191919;color: white;"\
            "padding-left: 4px;border: 1px solid #447684;}");
    ui->pwrset_Turn->horizontalHeader()->setFixedHeight(25);
    ui->pwrset_Turn->horizontalHeader()->setResizeMode(QHeaderView::Fixed);
    ui->pwrset_Turn->setFixedHeight(267);
    ui->pwrset_Turn->hide();
    //  PG设置表头
    ui->pgTab->horizontalHeader()->setStyleSheet\
            ("QHeaderView::section{background-color:#191919;color: white;"\
             "padding-left: 4px;border: 1px solid #447684;}");
    ui->pgTab->horizontalHeader()->setFixedHeight(25);
    ui->pgTab->horizontalHeader()->setResizeMode(QHeaderView::Fixed);
    ui->pgTab->setColumnWidth(0, 72);
    ui->pgTab->setColumnWidth(1, 72);
    ui->pgTab->setColumnWidth(2, 72);
    ui->pgTab->setColumnWidth(3, 72);
    ui->pgTab->setColumnWidth(4, 72);
    ui->pgTab->setColumnWidth(5, 72);
    ui->pgTab->setColumnWidth(6, 72);
    ui->pwrTab->setFixedHeight(267);


    pg_Cur = 0, pg_floor = 0, pg_up = 0;
    pg_freq_min = 0, pg_freq_avr = 0, pg_freq_max = 0;
    pg_duty_min = 0, pg_duty_avr = 0, pg_duty_max = 0;
    pg_speed = 0;

    EPAR_Init_Flag = 0;
    ui->checkBox_pwm->setDisabled(true);
    //  ui->checkBox_pg->setDisabled(true);
    PWM_Row_Count = 6;
    Set_pwr_Turn = 0;

    PWR_Test_Data.clear();  PWR_Test_Data.append("0");
    PWR_SetData.clear();    PWR_SetData.append("0");
    PG_Test_Order.clear();

    ui->label_volt->hide();  ui->PWR_Volt->hide();
    ui->label_fre->hide();  ui->PWR_Fre->hide();
    ui->label_channel->hide(); ui->PWR_channel->hide();
    ui->label_time->hide();   ui->PWR_time->hide();
    Turn_Shan = false;
    Pwr_Usart_Count = 0;

    PWR_Labelhide = new QLabel(this);
    PWR_Labelhide->setGeometry(0, 0, 800, 600);
    PWR_Labelhide->hide();
    /*进行功率档位的选择*/
    Widget_Button = new QWidget(this);
    Widget_Button->setGeometry(125, 123, 219, 260);
    QGridLayout *Pwr_GridLayout = new QGridLayout;
    Button_Text.clear();
    Button_Text.append("123");
    Button_Text.append("124");
    Button_Text.append("125");
    Button_Text.append("126");
    Button_Text.append("127");
    Button_Text.append("128");
    Pwr_Button_Group = new QButtonGroup;
    for (int i = 0; i < 6; i++) {
        Pwr_Button.append(new QPushButton(this));
        Pwr_Button[i]->setText(Button_Text[i]);
        Pwr_Button[i]->setMaximumWidth(100);  Pwr_Button[i]->setMinimumHeight(36);
        Pwr_Button[i]->setStyleSheet
                ("background: qlineargradient(x1: 0,  y1: 0,  x2: 0,  y2: "\
                 "1, stop: 0 #5B5F5F,  stop: 0.5 #0C2436, stop: 1 #27405A);"\
                 "color:rgb(255,  255,  255);");
        Pwr_Button_Group->addButton(Pwr_Button[i], i);
        Pwr_GridLayout->addWidget(Pwr_Button[i], i, 0);
    }
    Pwr_Button.append(new QPushButton(this));
    Pwr_Button[6]->setText(QString(tr("空")));
    Pwr_Button[6]->setMaximumWidth(100);  Pwr_Button[6]->setMinimumHeight(36);
    Pwr_Button[6]->setStyleSheet\
            ("background: qlineargradient(x1: 0,  y1: 0,  x2: 0,  y2: "\
             "1, stop: 0 #5B5F5F,  stop: 0.5 #0C2436, stop: 1 #27405A);"\
             "color:rgb(255,  255,  255);");
    Pwr_Button_Group->addButton(Pwr_Button[6], 6);
    Pwr_GridLayout->addWidget(Pwr_Button[6], 0, 1);
    connect(Pwr_Button_Group, SIGNAL(buttonClicked(int)), this, SLOT(buttonJudge(int)));
    Widget_Button->setLayout(Pwr_GridLayout);
    Widget_Button->setStyleSheet("background-color:#191919");
    Widget_Button->hide();

    PWR_Row = 0;

    Pg_Button_Group = new QButtonGroup;
    Pg_Button_Group->addButton(ui->pushButton_1, 1);
    Pg_Button_Group->addButton(ui->pushButton_2, 2);
    Pg_Button_Group->addButton(ui->pushButton_3, 3);
    Pg_Button_Group->addButton(ui->pushButton_4, 4);
    Pg_Button_Group->addButton(ui->pushButton_5, 5);
    Pg_Button_Group->addButton(ui->pushButton_6, 6);
    connect(Pg_Button_Group, SIGNAL(buttonClicked(int)), this, SLOT(pg_buttonJudge(int)));
    for (int j = 1; j < 7; j++) {
        Pg_Button_Group->button(j)->hide();
    }
    Old_Id = 0;

    ui->pushButton_Volt->hide();
    int i;
    Volt_Widget = new QWidget(this);
    Volt_Widget->setGeometry(150, 100, 500, 400);
    Volt_Widget->setWindowFlags(Qt::WindowStaysOnTopHint);
    Volt_Widget->setStyleSheet("border-radius: 10px;padding:2px 4px;background-color: gray;"\
                               "color: black;border-color: black;");
    QGridLayout *IO_upside = new QGridLayout;
    QString IO_table[6] = {tr("补偿数值(V):"), tr("补偿数值(V):"), tr("补偿数值(V):"), \
                           tr("补偿数值(V):"), tr("补偿数值(V):"), tr("补偿数值(V):")};


    for (i = 0; i < 6; i++) {
        Volt_Button.append(new QPushButton(this));
        Volt_Button[i]->setText(tr("采集12%1").arg(QString::number(i + 3)));
        Volt_Button[i]->setMinimumHeight(50);
        Volt_Button[i]->setMinimumWidth(90);
        Volt_Button[i]->setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"\
                                      "stop: 0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);");
        IO_upside->addWidget(Volt_Button[i], i, 0);

        IO_Show_Lable.append(new QLabel(this));
        IO_Show_Lable[i]->setText(IO_table[i]);
        IO_Show_Lable[i]->setMaximumHeight(35); IO_Show_Lable[i]->setMaximumWidth(135);
        IO_Show_Lable[i]->setAlignment(Qt::AlignCenter);
        IO_upside->addWidget(IO_Show_Lable[i], i, 1);
        if (i < 6) {
            Volt_Line_Text.append(new QDoubleSpinBox(this));
            Volt_Line_Text[i]->setMaximumHeight(35);
            Volt_Line_Text[i]->setMaximumWidth(100); // IO_Line_Text[i]->setMaximumWidth(51);
            Volt_Line_Text[i]->setDecimals(0);
            Volt_Line_Text[i]->setSingleStep(1);
            Volt_Line_Text[i]->setMaximum(20);
            Volt_Line_Text[i]->setMinimum(-20);
            Volt_Line_Text[i]->setAlignment(Qt::AlignCenter);
            Volt_Line_Text[i]->setButtonSymbols(QAbstractSpinBox::NoButtons);
            IO_upside->addWidget(Volt_Line_Text[i], i, 2);
        }
    }

    Volt_Button_Group = new QButtonGroup;
    Volt_Button_Group->addButton(Volt_Button[0], 1);
    Volt_Button_Group->addButton(Volt_Button[1], 2);
    Volt_Button_Group->addButton(Volt_Button[2], 3);
    Volt_Button_Group->addButton(Volt_Button[3], 4);
    Volt_Button_Group->addButton(Volt_Button[4], 5);
    Volt_Button_Group->addButton(Volt_Button[5], 6);
    connect(Volt_Button_Group, SIGNAL(buttonClicked(int)), this, SLOT(Volt_sample(int)));

    Volt_Back_Lable = new QLabel(this);
    Volt_Back_Lable->setText("");
    Volt_Back_Lable->setMaximumHeight(35); Volt_Back_Lable->setMaximumWidth(135);
    Volt_Back_Lable->setAlignment(Qt::AlignCenter);
    IO_upside->addWidget(Volt_Back_Lable, 1, 5);

    QPushButton *IO_button_quit = new QPushButton;
    IO_button_quit->setText(tr("退出"));
    IO_button_quit->setMinimumHeight(50);
    IO_button_quit->setMinimumWidth(90);
    IO_button_quit->setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"\
                                  "stop: 0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);");
    IO_upside->addWidget(IO_button_quit, 0, 5);
    connect(IO_button_quit, SIGNAL(clicked()), this, SLOT(Volt_Widget_autoquit()));
    QVBoxLayout *Histogram_IO_Widget_layout = new QVBoxLayout;
    Histogram_IO_Widget_layout->addLayout(IO_upside);
    Volt_Widget->setLayout(Histogram_IO_Widget_layout);
    Volt_Widget->hide();

    Volt_Sample_Grade = 0;
    Volt_Sample_ONE = false;
    Volt_ONE = 0;

    Init_Channel_6 = false;

    Pri_PWR_Noise_Widget();
}

Widget_PWR::~Widget_PWR()
{
    delete ui;
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2018.7.18
  * brief:      噪音测试界面
******************************************************************************/
void Widget_PWR::Pri_PWR_Noise_Widget() {
    int i;
    Noise_Widget = new QWidget(this);
    Noise_Widget->setGeometry(150, 110, 500, 291);
    Noise_Widget->setWindowFlags(Qt::WindowStaysOnTopHint);
    Noise_Widget->setStyleSheet("border-radius: 10px;padding:2px 4px;"\
                                "background-color: gray;color: black;"\
                                "border-color: black;");
    QGridLayout *Noise_Widget_upside = new QGridLayout;
    Noise_CW = new QCheckBox;
    Noise_CW->setText(tr("正向噪音"));
    Noise_CW->setStyleSheet("QCheckBox::indicator {image: url(:/image/053.png);"\
                            "width: 55px;height: 45px;}"\
                            "QCheckBox::indicator:checked { image: url(:/image/051.png); }"\
                            "QCheckBox  { color: rgb(0, 0, 0);}");
    Noise_Widget_upside->addWidget(Noise_CW, 0, 0);
    Noise_CCW = new QCheckBox;
    Noise_CCW->setText(tr("反向噪音"));
    Noise_CCW->setStyleSheet("QCheckBox::indicator {image: url(:/image/053.png);"\
                            "width: 55px;height: 45px;}"\
                            "QCheckBox::indicator:checked { image: url(:/image/051.png); }"\
                            "QCheckBox  { color: rgb(0, 0, 0);}");
    Noise_Widget_upside->addWidget(Noise_CCW, 1, 0);
    connect(Noise_CW, SIGNAL(clicked(bool)), this, SLOT(Noise_CCW_clicked(bool)));

    Noise_Lable.append(new QLabel(this));
    Noise_Lable[0]->setText(tr("间隔时间"));
    Noise_Lable[0]->setMaximumHeight(35);
    Noise_Lable[0]->setMaximumWidth(135);
    Noise_Lable[0]->setAlignment(Qt::AlignCenter);
    Noise_Widget_upside->addWidget(Noise_Lable[0], 2, 0);

    for (i = 0; i < 3; i++) {
        Noise_Lable.append(new QLabel(this));
        Noise_Lable[i + 1]->setText(tr("时间(S)"));
        Noise_Lable[i + 1]->setMaximumHeight(35);
        Noise_Lable[i + 1]->setMaximumWidth(135);
        Noise_Lable[i + 1]->setAlignment(Qt::AlignCenter);
        Noise_Widget_upside->addWidget(Noise_Lable[i + 1], i, 1);
    }

    for (i = 0; i < 3; i++) {
        Npise_Double_Box.append(new QDoubleSpinBox(this));
        Npise_Double_Box[i]->setMaximumHeight(35);
        Npise_Double_Box[i]->setMaximumWidth(100);
        Npise_Double_Box[i]->setDecimals(1);
        Npise_Double_Box[i]->setSingleStep(0.1);
        Npise_Double_Box[i]->setMaximum(30.0);
        Npise_Double_Box[i]->setMinimum(0);
        Npise_Double_Box[i]->setAlignment(Qt::AlignCenter);
        Npise_Double_Box[i]->setButtonSymbols(QAbstractSpinBox::NoButtons);
        Noise_Widget_upside->addWidget(Npise_Double_Box[i], i, 2);
    }

    QPushButton *Noise_Widget_quit = new QPushButton;
    Noise_Widget_quit->setText(tr("退出"));
    Noise_Widget_quit->setMinimumHeight(50);
    Noise_Widget_quit->setMinimumWidth(90);
    Noise_Widget_quit->setStyleSheet("background: qlineargradient"\
                                  "(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #5B5F5F, "\
                                  "stop: 0.5 #0C2436,stop: 1 #27405A);");
    Noise_Widget_upside->addWidget(Noise_Widget_quit, 0, 5);
    connect(Noise_Widget_quit, SIGNAL(clicked()), this, SLOT(Noise_Widget_autoquit()));

    QVBoxLayout *Histogram_layout = new QVBoxLayout;
    Histogram_layout->addLayout(Noise_Widget_upside);
    Noise_Widget->setLayout(Histogram_layout);
    Noise_Widget->hide();
}

void Widget_PWR::Volt_sample(int i) {
    double a_double;
    double b_double;
    int a_int;
    int b_int;

    a_double = 0.0;
    b_double = 0.0;
    a_int = 0;
    b_int = 0;

    Volt_Sample_ONE = true;
    Volt_Sample_Grade = i;
    Volt_Back_Lable->setText("");

    a_double = ui->pwrTab->item(i-1, 8)->text().toDouble();
    a_int = (a_double*100 + 5)/10;
    b_double = ui->PWR_Volt->value();
    b_int = (b_double*10 + 5)/10;

    frame.can_id = 0x27;  frame.can_dlc = 0x08;
    frame.data[0] = 0x01; // 设置功率参数
    /*设置档位*/
    frame.data[1] = i; // 左工位
    frame.data[2] = a_int/256; //
    frame.data[3] = a_int%256;
    /*电源设置电压*/ // 内部
    frame.data[4] = ((4<<4)|(b_int/256));
    frame.data[5] = b_int%256;
    /*设置转向*/
    frame.data[6] = 0;
    frame.data[7] = 0;
    canSend(frame, 0);
}

void  Widget_PWR::Pri_Test_Two() {
    double a_double;
    double b_double;
    int a_int;
    int b_int;

    a_double = 0.0;
    b_double = 0.0;
    a_int = 0;
    b_int = 0;

    Volt_Back_Lable->setText("");
    a_double = ui->pwrTab->item(Volt_Sample_Grade-1, 8)->text().toDouble();
    a_int = (a_double*100 + 5) /10;
    b_double = (ui->PWR_Volt->value()+Volt_Line_Text[Volt_Sample_Grade-1]->value());
    b_int = (b_double*10 + 5) /10;

    frame.can_id = 0x27;  frame.can_dlc = 0x08;
    frame.data[0] = 0x01; // 设置功率参数
    /*设置档位*/
    frame.data[1] = Volt_Sample_Grade; // 左工位
    frame.data[2] = a_int/256; //
    frame.data[3] = a_int%256;
    /*电源设置电压*/ // 内部
    frame.data[4] = ((4<<4)|(b_int/256));
    frame.data[5] = b_int%256;
    /*设置转向*/
    frame.data[6] = 0;
    frame.data[7] = 0;
    canSend(frame, 0);
}

void Widget_PWR::Noise_Widget_autoquit() {
    Noise_Widget->hide();
    PWR_Labelhide->hide();
}

void Widget_PWR::Volt_Widget_autoquit() {
    Volt_Widget->hide();
}

void Widget_PWR::Noise_CCW_clicked(bool Click) {
    if (Click) {
        Noise_CCW->setEnabled(true);
    } else {
        Noise_CCW->setChecked(false);
        Noise_CCW->setDisabled(true);
    }
}

void Widget_PWR::mousePressEvent(QMouseEvent *event) //处理鼠标被按下事件
{
    if (ui->pwrTab->currentColumn() == 0) {
        Widget_Button->hide();   PWR_Labelhide->hide();
    }
}

void Widget_PWR::pg_buttonJudge(int id)
{
    if (PWM_Model != QString("PG")) { // -非Pg退出测试
        return;
    }
    if (Old_Id == 0) {
        //
    } else {
        Pg_Button_Group->button(Old_Id)->setStyleSheet\
                ("background: qlineargradient(x1: 0,  y1: 0,  x2: 0,  y2: 1, "\
                 "stop: 0 #5B5F5F,  stop: 0.5 #0C2436, stop: 1 #27405A);"\
                 "color:rgb(255,  255,  255);");
        Copy_PWR_List.replace(155+Old_Id-1, QString::number(ui->PG_volt->value()));
        Copy_PWR_List.replace(161, QString::number(ui->pg_count->value()));
        Copy_PWR_List.replace(5+Old_Id-1, QString::number(ui->checkBox_pg->checkState()));
        for (int i = 0; i < 2; i++) {
            Copy_PWR_List.replace(165+(Old_Id-1)*30+i*15, ui->pgTab->item(i, 1)->text());
            Copy_PWR_List.replace(166+(Old_Id-1)*30+i*15, ui->pgTab->item(i, 2)->text());
            Copy_PWR_List.replace(167+(Old_Id-1)*30+i*15, ui->pgTab->item(i, 3)->text());
            Copy_PWR_List.replace(168+(Old_Id-1)*30+i*15, ui->pgTab->item(i, 4)->text());
            Copy_PWR_List.replace(169+(Old_Id-1)*30+i*15, ui->pgTab->item(i, 5)->text());
            Copy_PWR_List.replace(170+(Old_Id-1)*30+i*15, ui->pgTab->item(i, 6)->text());
        }
    }

    Pg_Button_Group->button(id)->setStyleSheet\
            ("background: qlineargradient(x1: 0,  y1: 0,  x2: 0,  y2: 1,"\
             "stop: 0 #00A600,  stop: 0.5 #00A600, stop: 1 #27405A);"\
             "color:rgb(255,  255,  255);");
    QTableWidgetItem *PG_Item = new QTableWidgetItem;  // -PG信息
    PG_Item->setTextAlignment(Qt::AlignCenter);
    PG_Item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    PG_Item->setText(ui->pwrTab->item(id-1, 0)->text());
    ui->pgTab->setHorizontalHeaderItem(0, PG_Item);
    dd(id-1);
    Old_Id = id;
}

void Widget_PWR::dd(int data)
{
    int i;
    EPAR_Init_Flag = 1;

    ui->pgTab->setRowCount(0);
    ui->pgTab->setRowCount(2);

    QStringList lisit;   lisit << QString(tr("上限")) << QString(tr("下限"));
    if (Copy_PWR_List.at(5+data).toInt() == 2) {
        ui->checkBox_pg->setChecked(true);
    } else {
        ui->checkBox_pg->setChecked(false);
    }
    ui->PG_volt->setValue(Copy_PWR_List.at(155+data).toDouble());
    data = data*30;

    PG_QTableWidgetItem.clear();
    for (i = 0; i < 2; i++) {
        PG_QTableWidgetItem.append(new QTableWidgetItem);
        PG_QTableWidgetItem[i]->setTextAlignment(Qt::AlignCenter);
        PG_QTableWidgetItem[i]->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        PG_QTableWidgetItem[i]->setText(lisit.at(i));
        ui->pgTab->setItem(i, 0, PG_QTableWidgetItem[i]);
    }
    for (i = 0; i < 2; i++) {
        QTableWidgetItem *pg_high = new QTableWidgetItem;    // 高电平
        pg_high->setTextAlignment(Qt::AlignCenter);
        pg_high->setText(Copy_PWR_List.at(165+data+i*15));
        ui->pgTab->setItem(i, 1, pg_high);
        QTableWidgetItem *pg_low = new QTableWidgetItem;     // 低电平
        pg_low->setTextAlignment(Qt::AlignCenter);
        pg_low->setText(Copy_PWR_List.at(166+data+i*15));
        ui->pgTab->setItem(i, 2, pg_low);
        QTableWidgetItem *pg_fre = new QTableWidgetItem;     // 频率
        pg_fre->setTextAlignment(Qt::AlignCenter);
        pg_fre->setText(Copy_PWR_List.at(167+data+i*15));
        ui->pgTab->setItem(i, 3, pg_fre);
        QTableWidgetItem *pg_duty = new QTableWidgetItem;    // 占空比
        pg_duty->setTextAlignment(Qt::AlignCenter);
        pg_duty->setText(Copy_PWR_List.at(168+data+i*15));
        ui->pgTab->setItem(i, 4, pg_duty);
        QTableWidgetItem *pg_current = new QTableWidgetItem; // 电流
        pg_current->setTextAlignment(Qt::AlignCenter);
        pg_current->setText(Copy_PWR_List.at(169+data+i*15));
        ui->pgTab->setItem(i, 5, pg_current);
        QTableWidgetItem *pg_speed_widget = new QTableWidgetItem; // 转速
        pg_speed_widget->setTextAlignment(Qt::AlignCenter);
        pg_speed_widget->setText(Copy_PWR_List.at(170+data+i*15));
        ui->pgTab->setItem(i, 6, pg_speed_widget);
    }
    qApp->processEvents();
    EPAR_Init_Flag = 0;
}
void Widget_PWR::buttonJudge(int id)
{
    Widget_Button->hide();
    PWR_Labelhide->hide();

    if (id == 6) {
        Copy_PWR_List.replace(35 + PWR_Row*20, "0");
        QTableWidgetItem *Table_Grade = new QTableWidgetItem;  //-档位
        Table_Grade->setTextAlignment(Qt::AlignCenter);
        Table_Grade->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        Table_Grade->setText("---");
        ui->pwrTab->setItem(PWR_Row, 0, Table_Grade);
    } else {
        Copy_PWR_List.replace(35 + PWR_Row*20, QString::number(id+1));
        QTableWidgetItem *Table_Grade = new QTableWidgetItem;  //-档位
        Table_Grade->setTextAlignment(Qt::AlignCenter);
        Table_Grade->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        Table_Grade->setText(Button_Text.at(id));
        ui->pwrTab->setItem(PWR_Row, 0, Table_Grade);
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.11.5
  * brief:      初始化电参设置
******************************************************************************/
void Widget_PWR::Pri_PWR_Init(QStringList List) // #define  PWM_Model "COMMON"
// PG COMMON   // PG电机 普通电机
{
    int i, j;
    QString Model;
    i = 0;
    j = 0;
    Model = List.at(0);
    Set_pwr_Turn = List.at(1).toInt();
    EPAR_Init_Flag = 1;
    pwrturn.clear();   pwrturn << QString(tr("不测")) \
                               << QString(tr("反转")) << QString(tr("正转"));
    pwr_set_turn.clear();
    pwr_set_turn << QString(tr("反转")) << QString(tr("正转"));
    PWM_Model = Model;
    ui->pwrTab->setRowCount(PWM_Row_Count);
    ui->pwrset_Turn->setRowCount(PWM_Row_Count);

    if (Set_pwr_Turn) {
        ui->label_time->show();   ui->PWR_time->show();
        ui->pwrset_Turn->show();
        ui->pwrTab->setGeometry(50, 110, 651, 291);
        ui->pwrTab->setColumnWidth(0, 70);
    } else {
        //
    }

    if (Model == QString("PG")) {
         ui->pgTab->setRowCount(2);
    } else {
        ui->Com_PG_DLR->hide();
        ui->label_pg_conut_2->hide();
        ui->checkBox_pg->hide();
        ui->label_pg_volt->hide();   ui->PG_volt->hide();
        ui->label_pg_conut->hide();  ui->pg_count->hide();
        ui->pgTab->hide();
        ui->frame->hide();
    }

    /*    Box_PWR_Grade_List.clear();
        for (i=0; i<PWM_Row_Count; i++)
        {
            Box_PWR_Grade_List.append(new QCheckBox);
            Box_PWR_Grade_List[i]->setStyleSheet\
            ("QCheckBox::indicator {image: url(:/image/053.png);"\
            width: 45px;height: 45px;}QCheckBox::indicator:checked "\
            "{image: url(:/image/051.png);}");
            Box_PWR_Grade_List[i]->setText(Button_Text.at(i));
        //  ui->pwrTab->setCellWidget(i, 0, Box_PWR_Grade_List[i]);
        } */


    // 总设置  0 电参    1 PG

    if (Copy_PWR_List.at(0).toInt() == 2) {
        ui->checkBox_pwm->setChecked(true);
    } else {
        //
    }
    if (Copy_PWR_List.at(2).toInt() == 2) {
        ui->checkBox_3->setChecked(true);
    } else {
        //
    }
    ui->Com_PG_DLR->setCurrentIndex(Copy_PWR_List.at(31).toInt() % 2);

    // 电参
    ui->PWR_Volt->setValue(Copy_PWR_List.at(25).toInt());
    ui->PWR_Fre->setValue(Copy_PWR_List.at(26).toInt());

    ui->PWR_Volt_up->setValue(Copy_PWR_List.at(27).toInt());
    ui->PWR_Volt_down->setValue(Copy_PWR_List.at(28).toInt());
    ui->PWR_Volume_value->setValue(Copy_PWR_List.at(29).toInt());
    ui->PWR_channel->setValue(Copy_PWR_List.at(30).toInt()); // 电源通道
    ui->PWR_time->setValue(Copy_PWR_List.at(33).toInt());

    for (i = 0; i < PWM_Row_Count; i++) {
        if (Copy_PWR_List.at(3).toInt() == 168) {     //-是否进行了更正
            QTableWidgetItem *Table_Grade = new QTableWidgetItem;  //-档位
            Table_Grade->setTextAlignment(Qt::AlignCenter);
            Table_Grade->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            if (Copy_PWR_List.at(35+i*20).toInt() != 0) {
                Table_Grade->setText(Button_Text.at(Copy_PWR_List.at(35+i*20).toInt()-1));
                Pg_Button_Group->button(i+1)->show();
                Pg_Button_Group->button(i+1)->setText\
                        (Button_Text.at(Copy_PWR_List.at(35+i*20).toInt()-1));
            } else {
                Table_Grade->setText("---");
            }
            ui->pwrTab->setItem(i, 0, Table_Grade);
        } else {
            QTableWidgetItem *Table_Grade = new QTableWidgetItem;  //-档位
            Table_Grade->setTextAlignment(Qt::AlignCenter);
            Table_Grade->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            if (Copy_PWR_List.at(35+i*20).toInt() != 0) {
                Table_Grade->setText(Button_Text.at(i));
                Copy_PWR_List.replace(35+i*20, QString::number(i+1));
                Pg_Button_Group->button(i+1)->show();
                Pg_Button_Group->button(i+1)->setText(Button_Text.at(i));
            } else {
                Table_Grade->setText("---");
            }
            if (Copy_PWR_List.at(2).toInt() != 0) {
                Copy_PWR_List.replace(5 + i, "2");
            }
            ui->pwrTab->setItem(i, 0, Table_Grade);
        }
        //        QTableWidgetItem *Volt_down = new QTableWidgetItem; //-电压下限
        //        Volt_down->setTextAlignment(Qt::AlignCenter);
        //        Volt_down->setText(Copy_PWR_List.at(36+i*20));
        //        ui->pwrTab->setItem(i, 1, Volt_down);

        //        QTableWidgetItem *Volt_up = new QTableWidgetItem;  //-电压上限
        //        Volt_up->setTextAlignment(Qt::AlignCenter);
        //        Volt_up->setText(Copy_PWR_List.at(37+i*20));
        //        ui->pwrTab->setItem(i, 2, Volt_up);

        QTableWidgetItem *Limit_down = new QTableWidgetItem;  // -电流下限
        Limit_down->setTextAlignment(Qt::AlignCenter);
        Limit_down->setText(Copy_PWR_List.at(38 + i*20));
        ui->pwrTab->setItem(i, 1, Limit_down);

        QTableWidgetItem *Limit_up = new QTableWidgetItem;  // -电流上限
        Limit_up->setTextAlignment(Qt::AlignCenter);
        Limit_up->setText(Copy_PWR_List.at(39 + i*20));
        ui->pwrTab->setItem(i, 2, Limit_up);

        QTableWidgetItem *Pwr_down = new QTableWidgetItem;  // -功率下限
        Pwr_down->setTextAlignment(Qt::AlignCenter);
        Pwr_down->setText(Copy_PWR_List.at(40 + i*20));
        ui->pwrTab->setItem(i, 3, Pwr_down);

        QTableWidgetItem *Pwr_up = new QTableWidgetItem;  // -功率上限
        Pwr_up->setTextAlignment(Qt::AlignCenter);
        Pwr_up->setText(Copy_PWR_List.at(41+i*20));
        ui->pwrTab->setItem(i, 4, Pwr_up);

        QTableWidgetItem *Volume_pressure_down = new QTableWidgetItem;  // 容压下限
        Volume_pressure_down->setTextAlignment(Qt::AlignCenter);
        Volume_pressure_down->setText(Copy_PWR_List.at(42 + i*20));
        ui->pwrTab->setItem(i, 5, Volume_pressure_down);

        QTableWidgetItem *Volume_pressure_up = new QTableWidgetItem;    // 容压上限
        Volume_pressure_up->setTextAlignment(Qt::AlignCenter);
        Volume_pressure_up->setText(Copy_PWR_List.at(43 + i*20));
        ui->pwrTab->setItem(i, 6, Volume_pressure_up);

        QTableWidgetItem *Volume_value = new QTableWidgetItem;    // 转向
        Volume_value->setTextAlignment(Qt::AlignCenter);
        Volume_value->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        Volume_value->setText(pwrturn[Copy_PWR_List.at(44+i*20).toInt()]);
        ui->pwrTab->setItem(i, 7, Volume_value);

        QTableWidgetItem *time = new QTableWidgetItem;    // 时间
        time->setTextAlignment(Qt::AlignCenter);
        time->setText(Copy_PWR_List.at(45 + i*20));
        ui->pwrTab->setItem(i, 8, time);

        Volt_Line_Text[i]->setValue(Copy_PWR_List.at(46 + i*20).toInt());
    }

    if (Set_pwr_Turn) {
        for (i = 0; i < PWM_Row_Count; i++) {
            QTableWidgetItem *pwrset_value = new QTableWidgetItem;    // 設置转向
            pwrset_value->setTextAlignment(Qt::AlignCenter);
            pwrset_value->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            pwrset_value->setText(pwr_set_turn[Copy_PWR_List.at(47+i*20).toInt()]);
            ui->pwrset_Turn->setItem(i, 0, pwrset_value);
        }
    }

    Npise_Double_Box[0]->setValue(Copy_PWR_List.at(31).toDouble()); // 噪音测试正转
    if (Copy_PWR_List.at(32).toInt() == 2) {
        Noise_CW->setChecked(true);
    } else {
        Noise_CW->setChecked(false);
    }
    Npise_Double_Box[1]->setValue(Copy_PWR_List.at(23).toDouble()); // 噪音测试反转
    if (Copy_PWR_List.at(24).toInt() == 2) {
        Noise_CCW->setChecked(true);
    } else {
        Noise_CCW->setChecked(false);
    }
    Npise_Double_Box[2]->setValue(Copy_PWR_List.at(22).toDouble()); // Delay_Time

    // PG
    if (Copy_PWR_List.at(3).toInt() == 168) { //-是否进行了更正
        //
    } else {
        Copy_PWR_List.replace(3, "168");
    }

    if (Model == QString("PG")) {
        //
    } else {
        ui->pgTab->setRowCount(0);
        ui->checkBox_pg->hide();
        ui->label_pg_volt->hide();   ui->PG_volt->hide();
        ui->label_pg_conut->hide();  ui->pg_count->hide();
        ui->pgTab->hide();
        ui->frame->hide();
        for (j = 1; j < 7; j++) {
            Pg_Button_Group->button(j)->hide();
        }
    }

    for (i = 1; i < 7; i++) {
        if (!(Pg_Button_Group->button(i)->isHidden())) {
            pg_buttonJudge(i);
            break;
        } else {
            //
        }
    }

    EPAR_Init_Flag = 0;
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2015.12.30
  * brief:      保存 PWR 配置
******************************************************************************/
void Widget_PWR::Pri_PWR_Data_Save()
{
    int i;
    Copy_PWR_List.replace(0, QString::number(ui->checkBox_pwm->checkState()));
    Copy_PWR_List.replace(2, QString::number(ui->checkBox_3->checkState()));

    /*保存空载*/
    Copy_PWR_List.replace(25, QString::number(ui->PWR_Volt->value()));
    Copy_PWR_List.replace(26, QString::number(ui->PWR_Fre->value()));
    Copy_PWR_List.replace(27, QString::number(ui->PWR_Volt_up->value()));
    Copy_PWR_List.replace(28, QString::number(ui->PWR_Volt_down->value()));
    Copy_PWR_List.replace(29, QString::number(ui->PWR_Volume_value->value()));
    Copy_PWR_List.replace(30, QString::number(ui->PWR_channel->value()));
    Copy_PWR_List.replace(31, QString::number(ui->Com_PG_DLR->currentIndex() % 2));

    Copy_PWR_List.replace(31, QString::number(Npise_Double_Box[0]->value())); // CW_Time
    Copy_PWR_List.replace(32, QString::number(Noise_CW->checkState()));       // CW
    Copy_PWR_List.replace(23, QString::number(Npise_Double_Box[1]->value())); // CCW_Time
    Copy_PWR_List.replace(24, QString::number(Noise_CCW->checkState()));      // CCW
    Copy_PWR_List.replace(22, QString::number(Npise_Double_Box[2]->value())); // Delay_Time
    Copy_PWR_List.replace(33, QString::number(ui->PWR_time->value())); // 等待时间
    for (i = 0; i < PWM_Row_Count; i++) {
        Copy_PWR_List.replace(38+i*20, ui->pwrTab->item(i, 1)->text());
        Copy_PWR_List.replace(39+i*20, ui->pwrTab->item(i, 2)->text());
        Copy_PWR_List.replace(40+i*20, ui->pwrTab->item(i, 3)->text());
        Copy_PWR_List.replace(41+i*20, ui->pwrTab->item(i, 4)->text());
        Copy_PWR_List.replace(42+i*20, ui->pwrTab->item(i, 5)->text());
        Copy_PWR_List.replace(43+i*20, ui->pwrTab->item(i, 6)->text());
        Copy_PWR_List.replace(45+i*20, ui->pwrTab->item(i, 8)->text());
        Copy_PWR_List.replace(46+i*20, Volt_Line_Text[i]->text());
    }

    /*保存PG*/
    if (ui->pgTab->rowCount() == 0) {
        return;
    }

    Copy_PWR_List.replace(155 + Old_Id - 1, QString::number(ui->PG_volt->value()));
    Copy_PWR_List.replace(161, QString::number(ui->pg_count->value()));
    Copy_PWR_List.replace(5 + Old_Id - 1, QString::number(ui->checkBox_pg->checkState()));
    for (int  i = 0; i < 2; i++) {
        Copy_PWR_List.replace(165+(Old_Id-1)*30+i*15, ui->pgTab->item(i, 1)->text());
        Copy_PWR_List.replace(166+(Old_Id-1)*30+i*15, ui->pgTab->item(i, 2)->text());
        Copy_PWR_List.replace(167+(Old_Id-1)*30+i*15, ui->pgTab->item(i, 3)->text());
        Copy_PWR_List.replace(168+(Old_Id-1)*30+i*15, ui->pgTab->item(i, 4)->text());
        Copy_PWR_List.replace(169+(Old_Id-1)*30+i*15, ui->pgTab->item(i, 5)->text());
        Copy_PWR_List.replace(170+(Old_Id-1)*30+i*15, ui->pgTab->item(i, 6)->text());
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.11.5
  * brief:      Conf 配置 PWR 界面
******************************************************************************/
void  Widget_PWR::Pri_PWR_Test_Parameter(QString str)
{
    int i = 0;
    int PWR_Test_All_number = 0;
    int PG_Test_All_Order = 0;
    str.clear();
    PWR_Test_Data.clear();
    PWR_SetData.clear();
    PG_Test_Order.clear();
    QStringList Number_data;  Number_data.clear();
    QStringList Turn_data;    Turn_data.clear();
    PWR_Test_All_number = 0;
    PG_Test_All_Order = 0;
    for (i = 0; i < PWM_Row_Count; i++) {
        if (Copy_PWR_List.at(35 + i*20).toInt() != 0) {
            PWR_Test_All_number++;
            Number_data.append(QString::number(i*10+Copy_PWR_List.at(35+i*20).toInt()));
            //  檔位
            if (Copy_PWR_List.at(5+i).toInt() == 2) {
                PG_Test_All_Order++;
                PG_Test_Order.append(QString::number(PG_Test_All_Order));
            } else {
                PG_Test_Order.append("0");
            }
            if (Set_pwr_Turn) {
                Turn_data.append(QString::number(Copy_PWR_List.at(47+i*20).toInt()));
            } else {
                //
            }
        } else {
            //
        }
    }
    PWR_Test_Data << QString::number(PWR_Test_All_number) << Number_data;
    PWR_SetData << QString::number(PWR_Test_All_number) << Turn_data;
}

void  Widget_PWR::Pri_PWR_Test_start(QString str)
{
    str.clear();
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.11.5
  * brief:      Conf 配置 PWR 界面
******************************************************************************/
void Widget_PWR::Pub_Conf_Set_PWR(QStringList List, QString str, int flag)
{
    switch (flag) {
    case 1:
        Pri_PWR_Init(List);
        break;
    case 2:
        Pri_PWR_Data_Save();
        break;
    case 3:
        Pri_PWR_Test_Parameter(str);
        break;
    case 4:
        Pri_PWR_power_chose(str.toInt());
        break;

    case 6:
        Turn_Shan = str.toInt();
        if (Turn_Shan) {
            ui->pwrTab->setColumnWidth(1, 0);
            ui->pwrTab->setColumnWidth(2, 0);
            ui->pwrTab->setColumnWidth(3, 0);
            ui->pwrTab->setColumnWidth(4, 0);
            ui->pwrTab->setColumnWidth(5, 0);
            ui->pwrTab->setColumnWidth(6, 0);
            ui->pwrTab->setColumnWidth(7, 300);
            ui->checkBox_3->setDisabled(true);
            ui->checkBox_3->setChecked(false);
        }
        break;
    case 7:
        Volt_Back_Lable->setText(QString::number(str.toDouble()/10, 'f', 0));
        break;
    case 8:
        if (Volt_Sample_ONE) {
            Volt_Sample_ONE = false;
            Volt_Line_Text[Volt_Sample_Grade-1]->setValue\
                    ((ui->PWR_Volt->value())-Volt_Back_Lable->text().toInt());
            Volt_ONE = (ui->PWR_Volt->value())-Volt_Back_Lable->text().toInt();
            Pri_Test_Two();
        } else {
            Volt_Line_Text[Volt_Sample_Grade-1]->setValue\
                    ((ui->PWR_Volt->value())-Volt_Back_Lable->text().toInt() + Volt_ONE);
            Volt_Back_Lable->setText(QString(tr("Ok")));
        }
        break;
    case 100:
        if (str.toInt()) {
            Init_Channel_6 = true;
            Pwr_Button[4]->hide();     Pwr_Button[5]->hide();
            Volt_Button[4]->hide();    Volt_Button[5]->hide();
            IO_Show_Lable[4]->hide();  IO_Show_Lable[5]->hide();
            Volt_Line_Text[4]->hide(); Volt_Line_Text[5]->hide();
        } else {
            Init_Channel_6 = false;
        }
        break;
    default:
        break;
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.2.23
  * brief:      配置PWR电源选择
******************************************************************************/
void Widget_PWR::Pri_PWR_power_chose(int value)
{
    if (value == 0) {
        //
    } else if (value == 1) {
        ui->label_volt->show();  ui->PWR_Volt->show();
        ui->label_fre->show();   ui->PWR_Fre->show();
    } else if (value == 2) {
        ui->label_channel->show(); ui->PWR_channel->show();
    } else if (value == 3) {
        ui->label_volt->show();  ui->PWR_Volt->show();
    } else if (value == 4) {
        ui->label_volt->show();  ui->PWR_Volt->show();
        ui->pushButton_Volt->show();
    } else {
        //
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.2.10
  * brief:      配置PWR，设置PG
******************************************************************************/
QStringList Widget_PWR::Pub_Set_PG(can_frame frame)
{
    double can_1;
    double can_2;
    double can_3;

    can_1 = 0.0;
    can_2 = 0.0;
    can_3 = 0.0;
    can_1 = (frame.data[1]*256+frame.data[2]);
    can_2 = (frame.data[3]*256+frame.data[4]);
    can_3 = (frame.data[5]*256+frame.data[6]);
    if (frame.data[0] == 1) { // 电流 低电平 高电平
        pg_Cur = (can_1)/100;
        pg_floor = (can_2)/100;
        pg_up = (can_3)/100;
    } else if (frame.data[0] == 2) { // 频率 min avr max
        pg_freq_min = (can_1)/10;
        pg_freq_max = (can_2)/10;
        pg_freq_avr = (can_3)/10;
    } else if (frame.data[0] == 3) { // 占空比 min avr max
        pg_duty_min = (can_1)/10;
        pg_duty_max = (can_2)/10;
        pg_duty_avr = (can_3)/10;
    } else {
        //
    }

    QStringList data;
    if (frame.data[0] == 3) {
        data.append(QString::number(pg_Cur, 'f', 2));      // 电流
        data.append(QString::number(pg_floor, 'f', 2));    // 低电平
        data.append(QString::number(pg_up, 'f', 2));       // 高电平
        data.append(QString::number(pg_freq_avr, 'f', 1)); // 频率
        data.append(QString::number(pg_duty_avr, 'f', 1)); // 占空比
        pg_speed = 60*pg_freq_avr/(ui->pg_count->value());
        data.append(QString::number(pg_speed, 'f', 0));    // 速度
    }
    return data;
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.2.10
  * brief:      配置PWR界面，转向是否可以选择
******************************************************************************/
void Widget_PWR::on_pwrTab_cellClicked(int row,  int column)
{
    // 苏恒 司密达 if ((column == 7)&&(row == 0))
    if (column == 0) {
        PWR_Labelhide->show();
        Widget_Button->show();
        PWR_Row = row;
    } else if (column == 7) { // India
        int resId = (Copy_PWR_List[44 + row*20].toInt() + 1)%pwrturn.size();
        if ((resId == 0) && (Turn_Shan)) {
            resId++;
        } else {
            //
        }
        Copy_PWR_List.replace(44+row*20, QString::number(resId));
        QTableWidgetItem *UnitItem = new QTableWidgetItem(pwrturn[resId]);
        UnitItem->setTextAlignment(Qt::AlignCenter);
        UnitItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ui->pwrTab->setItem(row, 7, UnitItem);
        ui->pwrTab->setEditTriggers(QAbstractItemView::AllEditTriggers);
    } else {
        //
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.11.5
  * brief:      配置PWR界面，PWR参数设定后进行参数规范设定
******************************************************************************/
void Widget_PWR::on_pwrTab_cellChanged(int row,  int column)
{
    QString str;
    int i, After_Point = 0;
    if (EPAR_Init_Flag != 0) {
        return;
    } else {
        //
    }
    EPAR_Init_Flag = 1;
    if (column != 7) {
        str = ui->pwrTab->item(row, column)->text();
        if (column == 0) {
            if (PWM_Model != QString("PG")) {
                EPAR_Init_Flag = 0;
                return;
            } else {
                //
            }
            if (str == QString(tr("---"))) {
                Pg_Button_Group->button(PWR_Row+1)->hide();
            } else {
                Pg_Button_Group->button(PWR_Row+1)->show();
                Pg_Button_Group->button(PWR_Row+1)->setText(str);
            }
            EPAR_Init_Flag = 0;
            return;
        }
        if (str == NULL) {
            ui->pwrTab->item(row, column)->setText("0");
        }
        for (i = 0; i < str.length(); i++) { //判断输入是" 0-9 . "
            if (((str[i] >= '0') && (str[i] <= '9')) || (str[i] == '.')) {
                //
            } else {
                ui->pwrTab->item(row, column)->setText("0");
                break;
            }
            if (str[i] == '.') { //  判断是否规范
                After_Point = str.length() - i - 1;
                if ((i == 0)) {
                    ui->pwrTab->item(row, column)->setText("0");
                }
                if (i == (str.length()-1)) {
                    ui->pwrTab->item(row, column)->setText\
                            (ui->pwrTab->item(row, column)->text().left(i));
                }
            }
        }
        if ((column == 1) || (column == 2)) {
            if (ui->pwrTab->item(row, column)->text().toDouble() > 5) {
                ui->pwrTab->item(row, column)->setText("5.000");
            }
            ui->pwrTab->item(row, column)->setText\
                    (QString::number(ui->pwrTab->item(row, column)->text().toDouble(), 'f', 3));
        }
        if ((column == 3) || (column == 4)) {
            if (ui->pwrTab->item(row, column)->text().toDouble() > 3000) {
                ui->pwrTab->item(row, column)->setText("3000.0");
            }
            ui->pwrTab->item(row, column)->setText\
                    (QString::number(ui->pwrTab->item(row, column)->text().toDouble(), 'f', 1));
        }
        if ((column == 5) || (column == 6)) {
            if (ui->pwrTab->item(row, column)->text().toDouble() > 600) {
                ui->pwrTab->item(row, column)->setText("600");
            }
            ui->pwrTab->item(row, column)->setText\
                    (QString::number(ui->pwrTab->item(row, column)->text().toDouble(), 'f', 0));
        }
        if (column == 8) {
            if (ui->pwrTab->item(row, column)->text().toDouble() > 1000)  {
                ui->pwrTab->item(row, column)->setText("999.9");
            }
            if (PWM_Model == QString("PG")) {
                if (ui->pwrTab->item(row, column)->text().toDouble() < 1.0) { // 1.0
                    ui->pwrTab->item(row, column)->setText("1.0");
                }
            } else if (Turn_Shan) {
                if (ui->pwrTab->item(row, column)->text().toDouble() < 1.0) { // 1.0
                    ui->pwrTab->item(row, column)->setText("1.0");
                }
            } else {
                if (ui->pwrTab->item(row, column)->text().toDouble() < 0.5) { // 0.5
                                    ui->pwrTab->item(row, column)->setText("0.5");
                }
            }
            ui->pwrTab->item(row, column)->setText\
                    (QString::number(ui->pwrTab->item(row, column)->text().toDouble(), 'f', 1));
        }

        if ((column == 1) || (column == 2)) {
            if ((ui->pwrTab->item(row, 1)->text().toDouble()) > \
                    (ui->pwrTab->item(row, 2)->text().toDouble())) {
                ui->pwrTab->item(row, 1)->setText("0.000");
            }
        }
        if ((column == 3) || (column == 4)) {
            if ((ui->pwrTab->item(row, 3)->text().toDouble()) > \
                    (ui->pwrTab->item(row, 4)->text().toDouble())) {
                ui->pwrTab->item(row, 3)->setText("0.0");
            }
        }
        if ((column == 5) || (column == 6)) {
            if ((ui->pwrTab->item(row, 5)->text().toDouble()) > \
                    (ui->pwrTab->item(row, 6)->text().toDouble())) {
                ui->pwrTab->item(row, 5)->setText("0");
            }
        }
    }
    EPAR_Init_Flag = 0;
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.12.10
  * brief:      PWR界面，电压上限输入完成
******************************************************************************/
void Widget_PWR::on_PWR_Volt_up_editingFinished()
{
    if ((ui->PWR_Volt_down->text().toDouble()) >= \
            (ui->PWR_Volt_up->text().toDouble())) {
        ui->PWR_Volt_down->setValue(0);
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.12.10
  * brief:      PWR界面，电压下限输入完成
******************************************************************************/
void Widget_PWR::on_PWR_Volt_down_editingFinished()
{
    if ((ui->PWR_Volt_down->text().toDouble()) >= \
            (ui->PWR_Volt_up->text().toDouble())) {
        ui->PWR_Volt_down->setValue(0);
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.2.5
  * brief:      配置PWR界面，PG参数设定后进行参数规范设定
******************************************************************************/
void Widget_PWR::on_pgTab_cellChanged(int row,  int column)
{
    QString str;
    int i, After_Point = 0;
    if (EPAR_Init_Flag == 0) {
        EPAR_Init_Flag = 1;
        str = ui->pgTab->item(row, column)->text();
        if (str == NULL) {
            ui->pgTab->item(row, column)->setText("0");
        }
        for (i = 0; i < str.length(); i++) { // 判断输入是" 0-9 . "
            if (((str[i] >= '0') && (str[i] <= '9')) || (str[i] == '.')) {
                //
            } else {
                ui->pgTab->item(row, column)->setText("0");
                break;
            }
            if (str[i] == '.') { //  判断是否规范
                After_Point = str.length() - i - 1;
                if ((i == 0)) {
                    ui->pgTab->item(row, column)->setText("0");
                }
                if (i == (str.length() - 1)) {
                    ui->pgTab->item(row, column)->setText\
                            (ui->pgTab->item(row, column)->text().left(i));
                }
            }
        }

        if (column == 1) { // 高电平
            if (ui->pgTab->item(row, column)->text().toDouble() > 15) {
                ui->pgTab->item(row, column)->setText("15.00");
            }
            ui->pgTab->item(row, column)->setText\
                    (QString::number(ui->pgTab->item(row, column)->text().toDouble(), 'f', 2));
        }
        if (column == 2) { // 低电平
            if (ui->pgTab->item(row, column)->text().toDouble() > 15) {
                ui->pgTab->item(row, column)->setText("15.00");
            }
            ui->pgTab->item(row, column)->setText\
                    (QString::number(ui->pgTab->item(row, column)->text().toDouble(), 'f', 2));
        }
        if (column == 3) { //频率
            if (ui->pgTab->item(row, column)->text().toDouble() < 20) {
                ui->pgTab->item(row, column)->setText("20.0");
            } else if (ui->pgTab->item(row, column)->text().toDouble() > 500) {
                ui->pgTab->item(row, column)->setText("500.0");
            }
            ui->pgTab->item(row, column)->setText\
                    (QString::number(ui->pgTab->item(row, column)->text().toDouble(), 'f', 1));
        }
        if (column == 4) { //占空比
            if (ui->pgTab->item(row, column)->text().toDouble() < 20) {
                ui->pgTab->item(row, column)->setText("20.0");
            } else if (ui->pgTab->item(row, column)->text().toDouble() > 80) {
                ui->pgTab->item(row, column)->setText("80.0");
            }
            ui->pgTab->item(row, column)->setText\
                    (QString::number(ui->pgTab->item(row, column)->text().toDouble(), 'f', 1));
        }
        if (column == 5) { //电流
            ui->pgTab->item(row, column)->setText\
                    (QString::number(ui->pgTab->item(row, column)->text().toDouble(), 'f', 2));
        }
        if (column == 6) { //转速
            ui->pgTab->item(row, column)->setText\
                    (QString::number(ui->pgTab->item(row, column)->text().toDouble(), 'f', 0));
        }

        if (column == 1) { // 高电平
            if ((ui->pgTab->item(0, 1)->text().toDouble()) < \
                    (ui->pgTab->item(1, 1)->text().toDouble())) {
                ui->pgTab->item(1, 1)->setText("0.00");
            }
        }
        if (column == 2) { // 低电平
            if ((ui->pgTab->item(0, 2)->text().toDouble()) < \
                    (ui->pgTab->item(1, 2)->text().toDouble())) {
                ui->pgTab->item(1, 2)->setText("0.00");
            }
        }
        if (column == 3) { // 频率
            if ((ui->pgTab->item(0, 3)->text().toDouble()) < \
                    (ui->pgTab->item(1, 3)->text().toDouble())) {
                ui->pgTab->item(1, 3)->setText("20.0");
            }
        }
        if (column == 4) { // 占空比
            if ((ui->pgTab->item(0, 4)->text().toDouble()) < \
                    (ui->pgTab->item(1, 4)->text().toDouble())) {
                ui->pgTab->item(1, 4)->setText("20.0");
            }
        }
        if (column == 5) {  // 电流
            if ((ui->pgTab->item(0, 5)->text().toDouble()) < \
                    (ui->pgTab->item(1, 5)->text().toDouble())) {
                ui->pgTab->item(1, 5)->setText("0.00");
            }
        }
        if (column == 6) { //电流
            if ((ui->pgTab->item(0, 6)->text().toDouble()) < \
                    (ui->pgTab->item(1, 6)->text().toDouble())) {
                ui->pgTab->item(1, 6)->setText("0.00");
            }
        }
        EPAR_Init_Flag = 0;
    }
}

QStringList Widget_PWR::PWR_Test_Param()
{
    QString str;
    QStringList  strSql;
    QStringList strParam, strTest, Back_List;;
    strTest.clear();
    strParam.clear();
    Back_List << "0" << "0";
    QStringList direction; direction << QString(tr("正转")) << QString(tr("反转"));
    QStringList turn;
    turn << QString(tr("不转")) << QString(tr("反转")) << QString(tr("正转"));
    str.clear();
    if (Copy_PWR_List.at(0).toInt() != 2) { //  电参
        return Back_List;
    }

    for (int j = 0; j < 6; j++) {
        if (Copy_PWR_List.at(35+j*20).toInt() != 0) {
            if (!Turn_Shan) {
                str += QString(tr("电参")) + \
                        Button_Text.at(Copy_PWR_List.at(35 + j*20).toInt()-1); // 电参
                strTest.append(str);   str.clear();
                str += "I:"+Copy_PWR_List.at(39 + j*20) + "A";
                str += " P:"+Copy_PWR_List.at(41 + j*20) + "W";
                str += " CU:"+Copy_PWR_List.at(43 + j*20) + "V";
                strParam.append(str);  str.clear();
                strSql.append(tr("电参"));
            }

            qDebug() << turn.at(Copy_PWR_List.at(44+j*20).toInt()) << Copy_PWR_List.at(44+j*20).toInt();
            if (Copy_PWR_List.at(44 + j*20).toInt() != 0) { // 转向
                str += QString(tr("转向"));
                strTest.append(str);   str.clear();
                str = turn.at(Copy_PWR_List.at(44+j*20).toInt());
                strParam.append(str);  str.clear();
                strSql.append(tr("转向"));
            }
            if ((PWM_Model == QString("PG")) && \
                    (Copy_PWR_List.at(5+j).toInt() == 2)) { // PG--测试数据
                str += QString(tr("PG"))+Button_Text.at(Copy_PWR_List.at(35+j*20).toInt()-1);
                strTest.append(str);   str.clear();
                str += Copy_PWR_List.at(166+j*15)+"V,"; // 165
                str += Copy_PWR_List.at(165+j*15)+"V,"; // 166
                str += Copy_PWR_List.at(167+j*15)+"Hz,"; // 167   ,
                str += Copy_PWR_List.at(168+j*15)+"%,"; // 168
                str += Copy_PWR_List.at(169+j*15)+"mA,"; // 169
                str += Copy_PWR_List.at(170+j*15)+"rpm"; // 170
                strParam.append(str);  str.clear();
                strSql.append(tr("PG"));
            }
        }
    }

    Back_List.clear();
    Back_List.append(QString::number(strTest.size()));
    Back_List.append(QString::number(strParam.size()));
    Back_List.append(QString::number(strSql.size()));
    Back_List.append(strTest);
    Back_List.append(strParam);
    Back_List.append(strSql);
    return Back_List;
}

void Widget_PWR::on_toolButton_4_clicked()
{
    Pwr_Usart_Count++;
    if (Pwr_Usart_Count >= 10) {
        Pwr_Usart_Count = 0;
        frame.can_id  = 0x27;  frame.can_dlc = 0x01; // 串口
        frame.data[0] = 0x0e; // 堵转
        canSend(frame, 1);
    }
}

void Widget_PWR::on_pushButton_Volt_clicked()
{
    Volt_Widget->show();
}

void Widget_PWR::on_pushButton_Noise_clicked()
{
    Noise_Widget->show();
    PWR_Labelhide->show();
}
void Widget_PWR::on_pwrset_Turn_cellClicked(int row, int column)
{
    if (column == 0) {
        int resId = (Copy_PWR_List[47 + row*20].toInt() + 1)%pwr_set_turn.size();
        if ((resId == 0) && (Turn_Shan)) {
             resId++;
        } else {
            //
        }
        Copy_PWR_List.replace(47+row*20, QString::number(resId));
        QTableWidgetItem *UnitItem = new QTableWidgetItem(pwr_set_turn[resId]);
        UnitItem->setTextAlignment(Qt::AlignCenter);
        UnitItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ui->pwrset_Turn->setItem(row, 0, UnitItem);
        ui->pwrset_Turn->setEditTriggers(QAbstractItemView::AllEditTriggers);
    }
}
void Widget_PWR::PWR_NetData(QStringList list, QString str)
{
    pwrturn.clear();   pwrturn << QString(tr("不测")) \
                               << QString(tr("反转")) << QString(tr("正转"));
    EPAR_Init_Flag = true;
    qDebug() << list << str;
    int i;
    if (str == QString(tr("cap_max"))) {
        for (i = 0; i < 6; i++) {
            ui->pwrTab->item(i, 6)->setText(list.at(i));
        }
    } else if (str == QString(tr("cap_min"))) {
        for (i = 0; i < 6; i++) {
            ui->pwrTab->item(i, 5)->setText(list.at(i));
        }
    } else if (str == QString(tr("curr_max"))) {
        for (i = 0; i < 6; i++) {
            ui->pwrTab->item(i, 2)->setText(list.at(i));
        }
    } else if (str == QString(tr("curr_min"))) {
        for (i = 0; i < 6; i++) {
            ui->pwrTab->item(i, 1)->setText(list.at(i));
        }
    } else if (str == QString(tr("pwr_max"))) {
        for (i = 0; i < 6; i++) {
            ui->pwrTab->item(i, 4)->setText(list.at(i));
        }
    } else if (str == QString(tr("pwr_min"))) {
        for (i = 0; i < 6; i++) {
            ui->pwrTab->item(i, 3)->setText(list.at(i));
        }
    } else if (str == QString(tr("test"))) {
        for (i = 0; i < 6; i++) {
            if (list.at(i).toInt() == 0) {
               ui->pwrTab->item(i, 0)->setText("---");
            } else {
               ui->pwrTab->item(i, 0)->setText(Button_Text[list.at(i).toInt()-1]);
            }

            Copy_PWR_List.replace(35 + i*20, list.at(i));
        }
    } else if (str == QString(tr("time"))) {
        for (i = 0; i < 6; i++) {
            ui->pwrTab->item(i, 8)->setText(list.at(i));
        }
    } else if (str == QString(tr("turn"))) {
        for (i = 0; i < 6; i++) {
            ui->pwrTab->item(i, 7)->setText(pwrturn[list.at(i).toInt()]);
            Copy_PWR_List.replace(44+i*20, list.at(i));
        }
    } else if (str == QString(tr("volt"))) {
        ui->PWR_Volt->setValue(list.at(0).toInt());
        Pri_PWR_Data_Save();
    } else {
        //
    }
    EPAR_Init_Flag = false;
}
