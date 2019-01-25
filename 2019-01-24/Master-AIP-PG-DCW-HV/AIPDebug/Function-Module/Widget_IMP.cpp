/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "Widget_IMP.h"
#include "ui_Widget_IMP.h"

Widget_IMP::Widget_IMP(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_IMP)
{
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint); // 去掉标题栏
    ui->setupUi(this);

    IMP_Group = new QButtonGroup;
    IMP_Group->addButton(ui->Key_1, 1);
    IMP_Group->addButton(ui->Key_2, 2);
    IMP_Group->addButton(ui->Key_3, 3);
    IMP_Group->addButton(ui->Key_4, 4);
    IMP_Group->addButton(ui->Key_5, 5);
    IMP_Group->addButton(ui->Key_6, 6);
    IMP_Group->addButton(ui->Key_7, 7);
    IMP_Group->addButton(ui->Key_8, 8);
    connect(IMP_Group, SIGNAL(buttonClicked(int)), this, SLOT(slot_imp_buttonJudge(int)));

    btnGroup_Set = new QButtonGroup;
    btnGroup_Set->addButton(ui->pushButton_4, 3);
    btnGroup_Set->addButton(ui->pushButton_5, 4);
    connect(btnGroup_Set, SIGNAL(buttonClicked(int)), this, SLOT(slot_imp_buttonJudge_set(int)));

    ui->ittTab->horizontalHeader()->setStyleSheet\
            ("QHeaderView::section{background-color:#191919;color: white;"\
             "padding-left: 4px;border: 1px solid #447684;}");
    ui->ittTab->horizontalHeader()->setFixedHeight(35);
    ui->ittTab->horizontalHeader()->setResizeMode(QHeaderView::Fixed);

    ui->dockWidget->hide();
    IMP_Test_Ready = true;
    IMP_Labelhide = new QLabel(this);
    IMP_Labelhide->setGeometry(0, 0, 800, 600);
    IMP_Labelhide->hide();
    //  IMP_Labelhide->setStyleSheet("background-color:#757575");

    lableset = new QLabel(this);
    Display_Shape = new wt_Wave(this);
    //  Display_Shape->setGeometry(0, 0, 800, 557);
    Display_Shape->IMP_Point = 1;
    Display_Shape->Red_line = 0;
    Display_Shape->Green_line = 0;
    Display_Shape->IMP_Y = 0;
    Display_Shape->IMP_X = 0;
    Display_Shape->IMPBigShape_Flag = 1;
    Display_Shape->setStyleSheet("background-color:#191919;");
    Display_Shape->setWindowFlags(Qt::Tool|Qt::FramelessWindowHint); // Qt::Dialog |
    Display_Shape->hide();
    ui->wate->addWidget(Display_Shape, 0);

    connect(Display_Shape, SIGNAL(SET_Point(int, int, int)), \
            this, SLOT(slot_imp_set_point(int, int, int)));
    Init_Flag = false;
    ui->dockWidget_2->hide();
    IMP_Add_Sample = false;

    int i;
    for (i = 0; i < 12; i++) {
        IMP_Right_Wave.append(new wt_Wave);
    }
    for (i = 0; i < 12; i++) {
        IMP_Left__Wave.append(new wt_Wave); // 默认波形
    }
//  ui->comb_Station->setDisabled(true);
    ui->button_sample_average->hide();
    ui->button_sample_cancle->hide();
    ui->button_sample_collect->hide();
    IMP_NO_Back_Volt = false;
    Testing_Real = false;
    Init_Channel_6 = false;

    volt_set = 3000;

    Pri_IMP_Set_UI();
    Copy_IMP_Gear.clear();
    for (i = 0; i < 8; i++) {
        Copy_IMP_Gear.append("0"); //
    }
}
Widget_IMP::~Widget_IMP()
{
    delete ui;
}

void Widget_IMP::Pri_IMP_Set_UI() {
    int i;
    Imp_Set_Widget = new QWidget(this);
    Imp_Set_Widget->setGeometry(175, 150, 450, 270);
    Imp_Set_Widget->setWindowFlags(Qt::WindowStaysOnTopHint);
    Imp_Set_Widget->setStyleSheet\
            (".QWidget{border-radius: 10px;padding:2px 4px;background-color: gray;"\
             "color: black;border-color: black;}");
    QGridLayout *Set_upside = new QGridLayout;
    Set_upside->setSpacing(20);
    QString Set_table[3]={QString(tr("匝间模式:")), \
                         QString(tr("")), QString(tr("组合Y形"))}; //
    for (i = 0; i < 3; i++) {
        Set_Show_Lable.append(new QLabel(this));
        Set_Show_Lable[i]->setText(Set_table[i]);
        Set_Show_Lable[i]->setMaximumHeight(35);
        Set_Show_Lable[i]->setMaximumWidth(135);
        Set_Show_Lable[i]->setAlignment(Qt::AlignCenter);
        Set_upside->addWidget(Set_Show_Lable[i], i, 0);
    }

    Set_Compare_CheckBox = new QCheckBox(this);
    Set_Compare_CheckBox->setText(tr("比较模式"));
    Set_Compare_CheckBox->setStyleSheet\
            ("QCheckBox::indicator {image: url(:/image/053.png);width: 55px;"\
             "height: 45px;}QCheckBox::indicator:checked { image: url(:/image/051.png); }"\
             "QCheckBox  { color: rgb(0, 0, 0);}");
    Set_upside->addWidget(Set_Compare_CheckBox, 0, 1);

    Set_Systematic_CheckBox = new QCheckBox(this);
    Set_Systematic_CheckBox->setText(tr("综合模式"));
    Set_Systematic_CheckBox->setStyleSheet\
            ("QCheckBox::indicator {image: url(:/image/053.png);width: 55px;"\
             "height: 45px;}QCheckBox::indicator:checked { image: url(:/image/051.png); }"\
             "QCheckBox  { color: rgb(0, 0, 0);}");
    Set_upside->addWidget(Set_Systematic_CheckBox, 1, 1);

    Set_Yes_CheckBox = new QCheckBox(this);
    Set_Yes_CheckBox->setText(tr(""));
    Set_Yes_CheckBox->setStyleSheet\
            ("QCheckBox::indicator {image: url(:/image/053.png);width: 55px;"\
             "height: 45px;}QCheckBox::indicator:checked { image: url(:/image/051.png); }"\
             "QCheckBox  { color: rgb(0, 0, 0);}");
    Set_upside->addWidget(Set_Yes_CheckBox, 2, 1);
    Set_Yes_CheckBox->setChecked(false);
    Set_Yes_CheckBox->setDisabled(true);
    connect(Set_Yes_CheckBox, SIGNAL(stateChanged(int)), this, SLOT(onStateChanged(int)));

    QPushButton *Set_Show_quit = new QPushButton(this);
    Set_Show_quit->setText(tr("退出"));
    Set_Show_quit->setMinimumHeight(50);
    Set_Show_quit->setMinimumWidth(90);
    Set_Show_quit->setStyleSheet\
            ("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"\
             "stop: 0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);");
    Set_upside->addWidget(Set_Show_quit, 0, 2);
    connect(Set_Show_quit, SIGNAL(clicked()), this, SLOT(Set_autoquit()));

    QVBoxLayout *imp_layout = new QVBoxLayout(this);
    imp_layout->addLayout(Set_upside);
    Imp_Set_Widget->setLayout(imp_layout);
    Imp_Set_Widget->hide();
}

void Widget_IMP::Set_autoquit() {
    IMP_Labelhide->hide();
    Imp_Set_Widget->hide();
}

void Widget_IMP::onStateChanged(int State_flag) {
    if (State_flag) {
        Signal_imp_3_6_test(2); // 打开交流接触器
    } else {
        Signal_imp_3_6_test(0); // 关闭交流接触器
    }
}

void Widget_IMP::mousePressEvent(QMouseEvent *event) // 处理鼠标被按下事件
{
    event->x();
    ui->dockWidget->hide();
    Imp_Set_Widget->hide();
    IMP_Labelhide->hide();
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.2.16
  * brief:      测试界面下发-匝间参数
******************************************************************************/
void Widget_IMP::Pri_IMP_Test()
{
    int i;
    IMP_TestItems = 0;
    IMP_TestNumber = 0;
    for (i = 0; i < 8; i++) {
        if (Copy_IMP_List.at(NUM_ITT*i+8).toInt() == 2) { //  判断匝间数据库是否被勾选
            frame.can_id = 0x24; frame.can_dlc = 0x08;
            frame.data[0] = 0x03; frame.data[1] = i;
            frame.data[2] = Copy_IMP_List[i*NUM_ITT].toInt(); // 测试点
            frame.data[3] = Copy_IMP_List[i*NUM_ITT + 1].toInt();
            if (Set_Compare_CheckBox->checkState() == 2) {
                frame.data[4] =(Copy_IMP_List[10].toInt())/256;   // 下发实际电压
                frame.data[5] =(Copy_IMP_List[10].toInt())%256;
            } else {
                frame.data[4] =(Copy_IMP_List[i*NUM_ITT+10].toInt())/256;   // 下发实际电压
                frame.data[5] =(Copy_IMP_List[i*NUM_ITT+10].toInt())%256;
            }
            qDebug() << "---Test down volt---" << (Copy_IMP_List[i*NUM_ITT + 10].toInt());
            if (Copy_IMP_List[i*NUM_ITT+2].toInt() <= 1000) {
                frame.data[6] = 1;
            } else if (Copy_IMP_List[i*NUM_ITT+2].toInt() <= 2000) {
                frame.data[6] = 2;
            } else if (Copy_IMP_List[i*NUM_ITT+2].toInt() <= 4000) {
                frame.data[6] = 3;
            } else {
                frame.data[6] = 4;
            }
            if (Copy_IMP_Gear.at(i).toInt() != 0) {
                frame.data[6] = Copy_IMP_Gear.at(i).toInt();
            } else {
                //
            }
            if (Copy_IMP_List[i*NUM_ITT+3].toInt() == 1) {
                frame.data[6] = ((frame.data[6] << 4) + Copy_IMP_List[i*NUM_ITT + 3].toInt());
            } else {
                frame.data[6] = ((frame.data[6] << 4) + Copy_IMP_List[i*NUM_ITT + 3].toInt());
            }
            if (Set_Compare_CheckBox->checkState() == 2) {
                frame.data[7] = Copy_IMP_List[9].toInt();
                //频率 frame.data[7] = setting[OTHER+i*ITT_NUM+9].toInt();
            } else {
                frame.data[7] = Copy_IMP_List[i*NUM_ITT+9].toInt();
                //频率 frame.data[7] = setting[OTHER+i*ITT_NUM+9].toInt();
            }
            canSend(frame);

            IMP_TestItems = IMP_TestItems + (1 << i);
            IMP_TestNumber++;
        }
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.2.22
  * brief:      测试匝间采样
******************************************************************************/
void Widget_IMP::Pri_IMP_TestSample(int model, int station)
{
    qDebug() << "Widget_IMP::Pri_IMP_TestSample";
    int i;
    for (i = 0; i < 8; i++) {
        IMP_WaveList[i]->num = 0;
        IMP_WaveList[i]->update();
    }
    IMP_TestItems = 0;
    IMP_TestNumber = 0;
    for (i = 0; i < 8; i++) {
        if ((Box_IMP_List[i]->checkState()) == 2) { // 判断匝间是否被勾选
            if (model == 1) {
                Pri_IMP_SetSample_Sarameter(i, ui->ittTab->item(i, 3)->text().toInt());
                // 采集波形，实际电压
            } else if (model == 0) {
                Pri_IMP_SetSample_Sarameter(i, Copy_IMP_List[i*NUM_ITT+10].toInt());
                // 进入测试模式
            } else {
                //
            }
            IMP_TestItems = IMP_TestItems + (1 << i);
            IMP_TestNumber++;
        }
    }
    if (IMP_TestItems != 0) {
        if ((IMP_NO_Back_Volt) && (model == 1)) { // 不反馈电压, 初始化采集
            Pri_IMP_SetSample_Test(4, IMP_TestItems, station);
        } else {
            Pri_IMP_SetSample_Test(model, IMP_TestItems, station);
        }
    } else {
        IMP_Test_Ready = true;
    }
    qDebug() << "Widget_IMP::Pri_IMP_TestSample Finsh";
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      初始化匝间设置
******************************************************************************/
void Widget_IMP::Pri_IMP_Init(QString File)
{
    int i, j;
    Init_Flag = true; // 进行初始化
    Current_File = File;
    IMP_WaveList.clear();
    IMP_WaveSqlList.clear();
    for (i = 0; i < 8; i++) { // 匝间列表
        Spin_IMP_List[i].clear();
    }

    ui->ittTab->setRowCount(0);
    ui->ittTab->setColumnWidth(0, 40); // 序号
    ui->ittTab->setColumnWidth(1, 38); // 低端
    ui->ittTab->setColumnWidth(2, 38); // 高端
    ui->ittTab->setColumnWidth(3, 50); // 电晕
    ui->ittTab->setColumnWidth(4, 40); // 次数
    ui->ittTab->setColumnWidth(5, 45); // 面积
    ui->ittTab->setColumnWidth(6, 45); // 差积
    ui->ittTab->setColumnWidth(7, 48); // 电晕
    ui->ittTab->setColumnWidth(8, 40); // 相位
    ui->ittTab->setColumnWidth(9, 34); // <
    ui->ittTab->setColumnWidth(10, 200); // 波形
    ui->ittTab->setColumnWidth(11, 34); // >

    for (i = 0; i < Copy_IMP_List.size()/NUM_ITT; i++) { // 一组有8个数据
        ui->ittTab->setRowCount(i + 1);

        IMP_WaveList.append(new wt_Wave);
        IMP_WaveSqlList.append(new wt_Wave);
        IMP_WaveList[i]->IMPFlag = 1;
        IMP_WaveList[i]->IMP_PP = 0;
        IMP_WaveList[i]->IMP_Point = 1;
        IMP_WaveList[i]->IMP_Y = (ui->ittTab->rowViewportPosition(i));
        IMP_WaveList[i]->IMP_X = ui->ittTab->columnViewportPosition(10);

        if (Copy_IMP_List.at(NUM_ITT*i + 11).toInt() >= \
                Copy_IMP_List.at(NUM_ITT*i + 12).toInt()) {
            // 对判断的坐标进行划分
            Copy_IMP_List.replace(NUM_ITT*i + 11, "20");
            Copy_IMP_List.replace(NUM_ITT*i + 12, "630");
        }
        IMP_WaveList[i]->Red_line = Copy_IMP_List.at(NUM_ITT*i + 11).toInt()*200/651;
        IMP_WaveList[i]->Green_line = Copy_IMP_List.at(NUM_ITT*i + 12).toInt()*200/651;

        if ((IMP_WaveList[i]->Red_line > 100) || (IMP_WaveList[i]->Red_line == 0)) {
            IMP_WaveList[i]->Red_line = 30;
            Copy_IMP_List.replace(NUM_ITT*i + 11, QString::number(3*651/20));
        } else {
            //
        }
        if (IMP_WaveList[i]->Green_line < 100) {
            IMP_WaveList[i]->Green_line = 170;
            Copy_IMP_List.replace(NUM_ITT*i + 12, QString::number(17*651/20));
        } else {
            //
        }

        connect(IMP_WaveList[i], SIGNAL(SET_IMP(int, bool)), \
                this, SLOT(slot_big_shape(int, bool)));
        ui->ittTab->setCellWidget(i, 10, IMP_WaveList[i]);  //  波形显示区

        for (j = 0; j < 8; j++) {
            Spin_IMP_List[j].append(new QTableWidgetItem);
            Spin_IMP_List[j][i]->setText(Copy_IMP_List.at(NUM_ITT*i + j));
            Spin_IMP_List[j][i]->setTextAlignment(Qt::AlignCenter);
            if (j < 2) {
                Spin_IMP_List[j][i]->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            }
            ui->ittTab->setItem(i, j + 1, Spin_IMP_List[j][i]);
        }

        if (Copy_IMP_List.at(NUM_ITT*i+8).toInt() == 2) { // 匝间是否选中
            for (j = 0; j < 400; j++) {   //  拉伸400个点
                IMP_WaveSqlList[i]->point[j] = Copy_IMP_List.at(NUM_ITT*i + 20 + j).toInt();
                IMP_WaveList[i]->point[j] = Copy_IMP_List.at(NUM_ITT*i + 20 + j).toInt()/4;
                IMP_WaveList[i]->pointgreen[j] = 260;
            }
        } else {
            for (j = 0; j < 400; j++) {   //  拉伸400个点
                IMP_WaveList[i]->point[j] = 260;
                IMP_WaveList[i]->pointgreen[j] = 260;
            }
        }
        IMP_WaveList[i]->num = 400;   //  拉伸400个点
        IMP_WaveList[i]->update();


        QTableWidgetItem *Number_Test_Items = new QTableWidgetItem; // 显示测试项序号
        Number_Test_Items->setTextAlignment(Qt::AlignCenter);
        Number_Test_Items->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        Number_Test_Items->setText(QString::number(i+1));
        ui->ittTab->setItem(i, 0, Number_Test_Items);

        QTableWidgetItem *Symbol_Less = new QTableWidgetItem(tr("<")); // <
        Symbol_Less->setTextAlignment(Qt::AlignCenter);
        Symbol_Less->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ui->ittTab->setItem(i, 9, Symbol_Less);

        QTableWidgetItem *Symbol_Greater = new QTableWidgetItem(tr(">")); // >
        Symbol_Greater->setTextAlignment(Qt::AlignCenter);
        Symbol_Greater->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ui->ittTab->setItem(i, 11, Symbol_Greater);
    }

    Box_IMP_List.clear();
    for (i = 0; i < 8; i++) {
        Box_IMP_List.append(new QCheckBox);
        Box_IMP_List[i]->setStyleSheet\
                ("QCheckBox::indicator {image: url(:/image/053.png);"\
                 "width: 50px;height: 55px;}QCheckBox::indicator:checked"\
                 "{image: url(:/image/051.png);}");

        if (Copy_IMP_List.at(NUM_ITT*i + 8).toInt() == 2) {
            Box_IMP_List[i]->setChecked(true);
        }
    }
    for (i = 0; i < 8; i++) {
        ui->ittTab->setCellWidget(i, 12, Box_IMP_List[i]);
    }
    lableset->setGeometry(ui->ittTab->columnViewportPosition(10), 7, 200, 550);
    lableset->setStyleSheet("background-color:#454545");
    lableset->hide();
    Init_Flag = false;

    QSettings set_File(QString("/mnt/nandflash/AIP/ConfFile/%1.ini").arg\
                       (Current_File), QSettings::IniFormat);
    if (set_File.contains("IMPleft/value")) { // 以前存在的 IMPleft/value 删除
        set_File.setValue("IMPleft/value", "0");
    } else {
        //
    }

    if (!(set_File.contains("IMP/righvalue"))) { // 17 设置
        set_File.setValue("IMP/righvalue", Copy_IMP_List);
        Right_value = Copy_IMP_List;  // 17
    } else {
        Right_value = set_File.value("IMP/righvalue").toStringList();  // 17
    }
    system("sync");
    if (Right_value.size() < 6561) {
        Right_value.clear();
        for (j = 0; j < 6561; j++) {
            Right_value.append("0");
        }
    } else {
        //
    }

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 400; j++) {
            IMP_Right_Wave[11]->sample_point[i][j] = \
                    Right_value.at(NUM_ITT*i + 20 + j).toInt(); // 17
        }
    }

    if (Copy_IMP_List.at(16).toInt() == 2) {
        Set_Compare_CheckBox->setChecked(true);
    } else {
        //
    }
    if (Copy_IMP_List.at(17).toInt() == 2) {
        Set_Systematic_CheckBox->setChecked(true);
    } else {
        //
    }
    if (Copy_IMP_List.at(13).toInt() == 2) {
        Set_Yes_CheckBox->setChecked(true);
    } else {
        //
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      保存匝间配置
******************************************************************************/
void Widget_IMP::Pri_IMP_Data_Save()
{
    int i, j;
    ui->dockWidget->hide(); Imp_Set_Widget->hide(); IMP_Labelhide->hide();
    //更新匝间数据
    for (i = 0; i < Copy_IMP_List.size()/NUM_ITT; i++) {
        Copy_IMP_List.replace\
                (i*NUM_ITT, QString::number(ui->ittTab->item(i, 1)->text().toInt()));
        Copy_IMP_List.replace\
                (i*NUM_ITT + 1, QString::number(ui->ittTab->item(i, 2)->text().toInt()));
        for (j = 2; j < 8; j++) {
            Copy_IMP_List.replace(i*NUM_ITT + j, Spin_IMP_List[j][i]->text());
        }
        Copy_IMP_List.replace(i*NUM_ITT + 8, QString::number(Box_IMP_List[i]->checkState()));
        //  使按键取代测试
    }

    IMP_Test_Ready = true;
    if (ui->comb_Station->currentText() == tr("左工位")) { // 进行左工位的数据保存
        for (i = 0; i < Copy_IMP_List.size()/NUM_ITT; i++) {
            for (j = 0; j < NUM_WAVE; j++) {
                Copy_IMP_List.replace\
                        (NUM_ITT*i + 20 + j, QString::number(IMP_WaveSqlList[i]->point[j]));
            }
        }
    } else if (ui->comb_Station->currentText() == tr("右工位")) { // 进行右工位的数据保存
        QSettings set_File(QString("/mnt/nandflash/AIP/ConfFile/%1.ini").arg\
                           (Current_File), QSettings::IniFormat);
        set_File.setValue("IMP/righvalue", Right_value);
        system("sync");
    } else {
        //
    }

    if (Set_Compare_CheckBox->checkState() == 2) {
        Copy_IMP_List.replace(16, "2");
    } else {
        Copy_IMP_List.replace(16, "0");
    }

    if (Set_Systematic_CheckBox->checkState() == 2) {
        Copy_IMP_List.replace(17, "2");
    } else {
        Copy_IMP_List.replace(17, "0");
    }

    if (Set_Yes_CheckBox->checkState() == 2) {
        Copy_IMP_List.replace(13, "2");
    } else {
        Copy_IMP_List.replace(13, "0");
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      doubleSpinBox初始化
******************************************************************************/
void Widget_IMP::Pri_initSpinBox(QDoubleSpinBox *spin,  int dec, int min, int max)
{
    spin->setMaximum(max);               // 最大值
    spin->setMinimum(min);               // 最小值
    spin->setDecimals(dec);              // 小数点后位数
    spin->setStyleSheet("border:none");  // 透明
    spin->setAlignment(Qt::AlignCenter); // 居中
    spin->setFocusPolicy(Qt::ClickFocus);
    spin->setButtonSymbols(QAbstractSpinBox::NoButtons);
}
void Widget_IMP::Pri_IMP_SetSample_Sarameter(int i, int volt)
{
    int times; //  冲击次数
    frame.can_id = 0x24; frame.can_dlc = 0x08;
    frame.data[0] = 0x03; frame.data[1] = i;
    frame.data[2] = ui->ittTab->item(i, 1)->text().toInt(); // 测试点
    frame.data[3] = ui->ittTab->item(i, 2)->text().toInt();
    frame.data[4] = (volt)/256; // 电压
    frame.data[5] = (volt)%256;
    if (ui->ittTab->item(i, 3)->text().toInt() <= 1000) {
        frame.data[6] = 1;
    } else if (ui->ittTab->item(i, 3)->text().toInt() <= 2000) {
        frame.data[6] = 2;
    } else if (ui->ittTab->item(i, 3)->text().toInt() <= 4000) {
        frame.data[6] = 3;
    } else {
        frame.data[6] = 4;
    } // 档位
    if (Copy_IMP_Gear.at(i).toInt() != 0) {
        frame.data[6] = Copy_IMP_Gear.at(i).toInt();
    } else {
        //
    }
    if (ui->ittTab->item(i, 4)->text().toInt() == 1) {
      times = 2;
    } else {
      times = ui->ittTab->item(i, 4)->text().toInt();
    }
    frame.data[6]=((frame.data[6] << 4)+times);
    if (ui->comb_Station->currentText() == QString(tr("左工位"))) {
        frame.data[7] = Copy_IMP_List[i*NUM_ITT+9].toInt(); // 频率
    } else if (ui->comb_Station->currentText() == QString(tr("右工位"))) {
        frame.data[7] = Copy_IMP_List[i*NUM_ITT+14].toInt(); // 频率
    } else {
        //
    }

    canSend(frame);
}
void Widget_IMP::Pri_IMP_SetSample_Test(int model, int i, int station)
{
    frame.can_id = 0x24;   frame.can_dlc = 0x05;
    frame.data[0] = 0x01;  frame.data[1] = model; // 0x00测试;0x01自动选频采样;0x02;定频采样;
    frame.data[2] = station;
    frame.data[3] = 0x00;
    frame.data[4] = i;
    if (model == 4) {
        Testing_Real = true;
    } else {
        Testing_Real = false;
    }
    canSend(frame);
    ui->label->setText(tr("正在采集中..."));
}
void Widget_IMP::Pri_IMP_Init_Join(QString Type)
{
    if ((Type == "ABC") || ((Type == "ABC-Pt"))){
        Set_Yes_CheckBox->setEnabled(true);
        if (Copy_IMP_List.at(13).toInt() == 2) {
            Signal_imp_3_6_test(2);
        } else {
            //
        }
    } else {
        Set_Yes_CheckBox->setDisabled(true);
    }
    ui->comb_Station->setCurrentIndex(2);
    ui->dockWidget_2->hide();
    sample_time = 1;
    IMP_Test_Ready = true;
}
void Widget_IMP::Pri_IMP_Default_value(QString number)  //  匝间设置默认数值
{
    int i;
    QStringList imp_number;
    imp_number = number.split("&&");
    for (i = 0; i < 8; i++) {
        ui->ittTab->item(i, 3)->setText(imp_number.at(1));
        ui->ittTab->item(i, 7)->setText("0");
        ui->ittTab->item(i, 8)->setText("0");
    }
    if (imp_number.at(0).size() == 0) {
        return;
    } else {
        //
    }
    for (i = 0; i < 8; i++) {
        Box_IMP_List[i]->setChecked(false);
    }
    for (i = 0; i < imp_number.at(0).size()/2; i++) {
        ui->ittTab->item(i, 1)->setText(imp_number.at(0).mid(i*2, 1));
        ui->ittTab->item(i, 2)->setText(imp_number.at(0).mid(i*2+1, 1));
        Box_IMP_List[i]->setChecked(true);
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.5.19
  * brief:      设置警告弹出框
******************************************************************************/
void Widget_IMP::Pri_IMP_WMessage(QString Waring_Text)
{
    QMessageBox *message = new QMessageBox(this);
    message->setWindowFlags(Qt::FramelessWindowHint);
    message->setStyleSheet\
            ("QMessageBox{border: gray;border-radius: 10px;"\
             "padding:2px 4px;background-color: gray;}");
    message->setText("\n"+Waring_Text+"\n");

    message->addButton(QMessageBox::Ok)->setStyleSheet\
            ("height:39px;width:75px;border:5px groove;border:none;"\
             "border-radius:10px;padding:2px 4px;");
    message->setButtonText(QMessageBox::Ok, QString(tr("确 定")));
    message->setIcon(QMessageBox::Warning);
    message->exec();
}
/*******************************************************************************
 *	@name:	Area
 *  @brief:	面积
 *  @param:
 *  @retval:
*******************************************************************************/
double  Widget_IMP::Pri_IMP_Area(int *stwave, int *wave, uint8_t origin, uint16_t terminal)
{
    uint32_t starea = 0;
    uint32_t area = 0;
    double   diff = 0;
    uint16_t i;
    for (i = origin; i < terminal; i++) {
        // 标准面积
        if (stwave[i] > 0x200)
            starea += stwave[i] - 0x200;
        else
            starea += 0x200 - stwave[i];
        // 面积
        if (wave[i] > 0x200)
            area += wave[i] - 0x200;
        else
            area += 0x200 - wave[i];
    }
    diff = ((double)((int32_t)(area-starea)))*100;
    diff = (diff/((double)((int32_t)starea)));
    if (diff < (-99.9)) {
        diff = -99.9;
    } else if (diff > (99.9))  {
        diff = 99.9;
    } else {
        //
    }
    return diff;
}
/*******************************************************************************
 * @name:	Diff
 * @brief:	差积
 * @param:
 * @retval:
*******************************************************************************/
double  Widget_IMP::Pri_IMP_Diff(int *stwave, int *wave, uint8_t origin, uint16_t terminal)
{
    uint32_t starea = 0;
    double diff = 0;
    uint32_t diff2 = 0;
    uint16_t i;
    uint16_t temp1, temp2;
    if (origin == 0)
        origin = 1;
    if (terminal > 398)
        terminal = 398;
    for (i = origin; i < terminal; i++) {
        // 标准面积
        if (stwave[i] > 0x200)
            starea += stwave[i] - 0x200;
        else
            starea += 0x200 - stwave[i];
        // 差积1  原始数据
        if (wave[i] > stwave[i])
            diff += wave[i] - stwave[i];
        else
            diff += stwave[i] - wave[i];
        // 差积2  平滑1次处理
        temp1 = stwave[i-1] + (stwave[i] << 1) + stwave[i + 1];
        temp2 = wave[i-1] + (wave[i] << 1) + wave[i + 1];
        if (temp1 > temp2)
            diff2 += temp1 - temp2;
        else
            diff2 += temp2 - temp1;
    }
    diff2 = diff2 >> 2;
    // 取较小的
    if (diff > diff2)
        diff = diff2;

    // printf("starea=%d diff=%d", starea, diff);
    diff = diff*100;
    diff = diff/starea;
    if (diff > (99.9)) {
        diff = 99.9;
    } else {
        //
    }
    return diff;
}
/*******************************************************************************
 *	@name:	Flut
 * @brief:	电晕
 * @param:
 * @retval:
 *******************************************************************************/
int  Widget_IMP::Pri_IMP_Flut(int *wave, uint8_t origin, uint16_t terminal)
{
    int32_t flut = 0;
    uint16_t i;
    for (i = origin; i < terminal; i++) {
        if (wave[i] > wave[i + 1])
            flut += wave[i] - wave[i + 1];
        else
            flut += wave[i + 1] - wave[i];
    }
    if (flut < (-65535)) {
        flut = -65535;
    } else if (flut > (65535)) {
        flut = 65535;
    } else {
        //
    }
    return flut;
}
/*******************************************************************************
 * @name:	phase
 * @brief:	相位
 * @param:
 * @retval:
 *******************************************************************************/
int  Widget_IMP::Pri_IMP_Phase(int *stwave, int *wave, uint8_t origin, uint16_t terminal)
{
    uint16_t i;
    int32_t phase1 = 0, phase2 = 0;
    for (i = origin; i < terminal; i++) {
        phase1 += (stwave[i] - 0x200)*(stwave[i] - 0x200);
        phase2 += (stwave[i] - 0x200)*(wave[i] - 0x200);
    }

    phase2 = phase1 - phase2;
    phase2 = phase2*100/phase1;
    if (phase2 > (99)) {
        phase2 = 99;
    } else {
        //
    }

    return phase2;
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.10.21
  * brief:      设置
******************************************************************************/
void Widget_IMP::slot_imp_set_point(int point, int flag, int p)
{
    if (flag == 1) {
        ui->doubleSpinBox_green->setValue(point);
        IMP_WaveList[Record_Row]->Green_line = p;
    } else if (flag == 2) {
        ui->doubleSpinBox_red->setValue(point);
        IMP_WaveList[Record_Row]->Red_line = p;
    }
}
void Widget_IMP::slot_big_shape(int ShapeCount, bool Flag)
{
    if (Flag == 1) {
        ui->dockWidget_2->show();
        ui->label->show();
    }

    int j;
    Record_Row = ShapeCount;
    if ((Box_IMP_List[Record_Row]->checkState()) == 2) {
        Display_Shape->show();
        QString str = QString(tr("匝间")) + (ui->ittTab->item(ShapeCount, 1)->text()) + \
                "-" + (ui->ittTab->item(ShapeCount, 2)->text());
        Display_Shape->IMP_string = str;
        Display_Shape->IMP_Fre = Copy_IMP_List[ShapeCount*NUM_ITT + 9].toInt();
        Display_Shape->IMP_PP  = IMP_WaveList[ShapeCount]->IMP_PP;
        Display_Shape->Red_line = Copy_IMP_List.at(NUM_ITT*ShapeCount + 11).toInt();
        Display_Shape->Green_line = Copy_IMP_List.at(NUM_ITT*ShapeCount + 12).toInt();

        for (j = 0; j < 400; j++) {   //  拉伸400个点
            Display_Shape->point[j] = IMP_WaveList[ShapeCount]->point[j];
            Display_Shape->pointgreen[j] = 260;
        }
        Display_Shape->num = 400;   //  拉伸400个点
        Display_Shape->update();
    }
    ui->doubleSpinBox_red->setValue(Copy_IMP_List.at(NUM_ITT*ShapeCount + 11).toInt());
    ui->doubleSpinBox_green->setValue((Copy_IMP_List.at(NUM_ITT*ShapeCount + 12).toInt()));
}
void Widget_IMP::slot_imp_buttonJudge(int id)
{
    ui->dockWidget->hide(); Imp_Set_Widget->hide();  IMP_Labelhide->hide();
    if (id != 9) {
        ui->ittTab->currentItem()->setText(QString::number(id));
    }
}
void Widget_IMP::slot_imp_buttonJudge_set(int id)
{
    if ((id == 3) || (id == 4)) {
        if (id == 3) {       // 左拉伸
            on_ittTab_cellClicked(Record_Row, 9);
        } else if (id == 4) {  // 右拉伸
            on_ittTab_cellClicked(Record_Row, 11);
        }
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.10.21
  * brief:      采集第N个样品 添加样品
******************************************************************************/
void Widget_IMP::on_button_sample_collect_clicked()
{
    IMP_Add_Sample = true;
    ui->button_sample_cancle->setText(QString(tr("取消第 %1 个样品")).arg(sample_time));
    if (sample_time <= 10) {
        Pri_IMP_TestSample(0, 0x13+ui->comb_Station->currentIndex());
        // 0x00测试;0x01自动选频采样  这里选用 0
    }
    sample_time++;
    if (sample_time >= 11) {
        sample_time = 11;
        ui->button_sample_collect->setText(tr("采集完成样品"));
    } else {
        ui->button_sample_collect->setText(QString(tr("采集第 %1 个样品")).arg(sample_time));
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.10.21
  * brief:      取消第N个样品
******************************************************************************/
void Widget_IMP::on_button_sample_cancle_clicked()
{
    if (sample_time == 1) {
        return;
    }
    sample_time--;
    ui->button_sample_collect->setText(QString(tr("采集第 %1 个样品")).arg(sample_time));
    if (sample_time == 1) {
        ui->button_sample_cancle->setText(tr("取消"));
        ui->label->setText(tr("默认--采集完成"));
    } else {
        ui->button_sample_cancle->setText(QString(tr("取消第 %1 个样品")).arg(sample_time - 1));
        ui->label->setText(QString(tr("样品-%1-采集OK")).arg(sample_time - 1));
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.10.21
  * brief:      计算平均采样
******************************************************************************/
void Widget_IMP::on_button_sample_average_clicked()
{
    int i, j, x;
    if (ui->comb_Station->currentText() == QString(tr("右工位"))) {
        for (x = 0; x < 8; x++) {
            for (j = 0; j < 400; j++) {
                IMP_Right_Wave[11]->sample_point[x][j] = 0;
            }
        }
    } else if (ui->comb_Station->currentText() == QString(tr("左工位"))) {
        for (x = 0; x < 8; x++) {
            for (j = 0; j < 400; j++) {
                IMP_Left__Wave[11]->sample_point[x][j] = 0;
            }
        }
    } else {
        //
    }

    if ((sample_time-1) >= 1) {
        for (i = 1; i < sample_time; i++) {
            for (x = 0; x < 8; x++) {
                if ((Box_IMP_List[x]->checkState()) == 2) {
                    if (ui->comb_Station->currentText() == QString(tr("右工位"))) {
                        for (j = 0; j < 400; j++) {
                            IMP_Right_Wave[11]->sample_point[x][j] += \
                                    IMP_Right_Wave[i]->sample_point[x][j];
                        }
                    } else if (ui->comb_Station->currentText() == QString(tr("左工位"))) {
                        for (j = 0; j < 400; j++) {
                            IMP_Left__Wave[11]->sample_point[x][j] += \
                                    IMP_Left__Wave[i]->sample_point[x][j];
                        }
                    } else {
                        //
                    }
                }
            }
        }
        for (x = 0; x < 8; x++) {
            if ((Box_IMP_List[x]->checkState()) == 2) {
                if (ui->comb_Station->currentText() == QString(tr("左工位"))) {
                    for (j = 0; j < 400; j++) { // 拉伸400个点
                        IMP_WaveSqlList[x]->point[j] = \
                                (IMP_Left__Wave[11]->sample_point[x][j]/(sample_time - 1));
                        Copy_IMP_List.replace(NUM_ITT*x + 20 + j, \
                                              QString::number(IMP_WaveSqlList[x]->point[j]));
                        IMP_WaveList[x]->point[j] = \
                                IMP_Left__Wave[11]->sample_point[x][j]/(sample_time-1)/4;
                        IMP_WaveList[x]->pointgreen[j] = 260;
                    }
                } else if (ui->comb_Station->currentText() == QString(tr("右工位"))) {
                    for (j = 0; j < 400; j++) {   //  拉伸400个点
                        IMP_Right_Wave[11]->sample_point[x][j] = \
                                IMP_Right_Wave[11]->sample_point[x][j]/(sample_time - 1);
                        IMP_WaveList[x]->point[j] = IMP_Right_Wave[11]->sample_point[x][j]/4;
                        IMP_WaveList[x]->pointgreen[j] = 260;
                    }
                } else {
                    //
                }
                IMP_WaveList[x]->num = 400;   //  拉伸400个点
                IMP_WaveList[x]->update();
            }
        }
    }
    if (ui->comb_Station->currentText() == tr("右工位")) {
        QSettings set_File(QString("/mnt/nandflash/AIP/ConfFile/%1.ini").arg\
                           (Current_File), QSettings::IniFormat);
        for (i = 0; i < 8; i++) {
            if ((Box_IMP_List[i]->checkState()) == 2) {
                for (j = 0; j < 400; j++) {
                    Right_value.replace(NUM_ITT*i + 20 + j, \
                    QString::number((IMP_Right_Wave[11]->sample_point[i][j])));
                }
            }
        }
        set_File.setValue("IMP/righvalue", Right_value); // 17
    }

    sample_time = 1;
    ui->button_sample_collect->setText(QString(tr("采集第 %1 个样品")).arg(sample_time));
    ui->button_sample_cancle->setText(tr("取消"));
    ui->label->setText(tr("默认--采集完成"));
}
void Widget_IMP::on_button_back_clicked()
{
    ui->dockWidget_2->hide();
    Copy_IMP_List.replace(Record_Row*NUM_ITT + 11, QString::number(Display_Shape->Red_line));
    Copy_IMP_List.replace(Record_Row*NUM_ITT + 12, QString::number(Display_Shape->Green_line));
}
void Widget_IMP::on_ittTab_cellClicked(int row,  int column)
{
    int fre;
    int Fre_Chose, Volt_Chose, Station_Chose;
    Record_Row = ui->ittTab->currentRow(); // 得到当前测试行
    ui->Key_1->show(); ui->Key_2->show(); ui->Key_3->show(); ui->Key_4->show();
    ui->Key_5->show(); ui->Key_6->show(); ui->Key_7->show(); ui->Key_8->show();

    if (Init_Channel_6) {
        ui->Key_7->hide();
        ui->Key_8->hide();
    } else {
        //
    }

    if ((column == 1) || (column == 2)) {
        IMP_Labelhide->show();
        ui->dockWidget->show();
        ui->dockWidget->raise();
    } else if (((Box_IMP_List[row]->checkState()) == 2) && \
             (IMP_Test_Ready) && (!IMP_Add_Sample)) {
        if ((column == 9) || (column == 11)) {
            //
        } else {
            return;
        }
        if (ui->comb_Station->currentIndex() == 2) {
            Pri_IMP_WMessage(QString(tr("   请将滑罩移动到对应的工位   ")));
            return;
        }
        sample_time = 1;
        if (ui->comb_Station->currentText() == QString(tr("左工位"))) {
            Fre_Chose = 9;
            Volt_Chose = 10;
            Station_Chose = 0x13;
        } else { // 右工位
            Fre_Chose = 14;
            Volt_Chose = 15;
            Station_Chose = 0x14;
        }

        if (column == 9) { // 压缩
            IMP_Test_Ready = false;
            fre = Copy_IMP_List[row*NUM_ITT + Fre_Chose].toInt();
            fre++;
            if (fre >= 15) {
                fre = 15;
            }
            Copy_IMP_List.replace(row*NUM_ITT + Fre_Chose, QString::number(fre));

            IMP_WaveList[row]->num = 0; IMP_WaveList[row]->update();
            if (IMP_NO_Back_Volt) { // 拉伸使用返回
                Pri_IMP_SetSample_Sarameter(row, \
                                            Copy_IMP_List[row*NUM_ITT + Volt_Chose].toInt());
                // ui->ittTab->item(row, 3)->text().toInt()
                Pri_IMP_SetSample_Test(0, (1 << row), Station_Chose);
            } else {
                Pri_IMP_SetSample_Sarameter(row, ui->ittTab->item(row, 3)->text().toInt());
                Pri_IMP_SetSample_Test(2, (1 << row), Station_Chose);
            }
        } else if (column == 11) { // 拉伸
            IMP_Test_Ready = false;
            fre = Copy_IMP_List[row*NUM_ITT + Fre_Chose].toInt();
            fre--;
            if (fre <= 0) {
                fre = 0;
            }
            Copy_IMP_List.replace(row*NUM_ITT + Fre_Chose, QString::number(fre));

            IMP_WaveList[row]->num = 0;
            IMP_WaveList[row]->update();
            if (IMP_NO_Back_Volt) {
                Pri_IMP_SetSample_Sarameter(row, \
                                            Copy_IMP_List[row*NUM_ITT+Volt_Chose].toInt());
                // ui->ittTab->item(row, 3)->text().toInt()
                Pri_IMP_SetSample_Test(0, (1 << row), Station_Chose);
            } else {
                Pri_IMP_SetSample_Sarameter(row, ui->ittTab->item(row, 3)->text().toInt());
                Pri_IMP_SetSample_Test(2, (1 << row), Station_Chose);
            }
        } else {
            //
        }
    }
}
void Widget_IMP::on_ittTab_cellChanged(int row,  int column)
{
    int i, x;
    QString str;
    if (Init_Flag) {
        return;
    }

    Init_Flag = true;
    if ((column >= 3) && (column <= 8)) {
        str = ui->ittTab->item(row, column)->text();
        if (str == NULL) {
            ui->ittTab->item(row, column)->setText("0");
        }
        for (i = 0; i < str.length(); i++) { //判断输入是" 0-9 . "
            if (((str[i] >= '0') && (str[i] <= '9')) || (str[i] == '.')) {
                //
            } else {
                ui->ittTab->item(row, column)->setText("0");
                break;
            }
        }
        if (column == 3) {
            if (ui->ittTab->item(row, column)->text().toInt() >= volt_set) {
                ui->ittTab->item(row, column)->setText(QString::number(volt_set));
            } else if (ui->ittTab->item(row, column)->text().toInt() < 500) {
                ui->ittTab->item(row, column)->setText("500");
            } else {
                //
            }
            for (i = 0; i < 8; i++) {
                for (x = 0; x < 400; x++) {
                    IMP_WaveSqlList[i]->point[x] = 0;
                    IMP_Right_Wave[11]->sample_point[i][x] = 0;
                }
            }
            if (row == 0) {
                for (i = 0; i < 8; i++) {
                    Copy_IMP_List.replace(i*NUM_ITT + 10, \
                            ui->ittTab->item(row, column)->text());
                    Copy_IMP_List.replace(i*NUM_ITT + 15, \
                            ui->ittTab->item(row, column)->text());
                }
            } else {
                Copy_IMP_List.replace(row*NUM_ITT + 10, \
                        ui->ittTab->item(row, column)->text());
                Copy_IMP_List.replace(row*NUM_ITT + 15, \
                        ui->ittTab->item(row, column)->text());
            }
        } else if (column == 4) {
            if (ui->ittTab->item(row, column)->text().toInt() >= 15) {
                ui->ittTab->item(row, column)->setText("15");
            }
            ui->ittTab->item(row, column)->setText(
                        (QString::number(ui->ittTab->item(row, column)->text().toDouble() \
                                                    , 'f', 0)));

        } else if (column == 5) {
            if (ui->ittTab->item(row, column)->text().toInt() >= 99) {
                ui->ittTab->item(row, column)->setText("99");
            }
            ui->ittTab->item(row, column)->setText(
                        (QString::number(ui->ittTab->item(row, column)->text().toDouble() \
                                                    , 'f', 1)));
        } else if (column == 6) {
            if (ui->ittTab->item(row, column)->text().toInt() >= 99) {
                ui->ittTab->item(row, column)->setText("99");
            }
            ui->ittTab->item(row, column)->setText(
                        (QString::number(ui->ittTab->item(row, column)->text().toDouble() \
                                                    , 'f', 1)));
        } else if (column == 7) {
            if (ui->ittTab->item(row, column)->text().toInt() >= 65535) {
                ui->ittTab->item(row, column)->setText("65535");
            }
            ui->ittTab->item(row, column)->setText(
                        (QString::number(ui->ittTab->item(row, column)->text().toDouble() \
                                                    , 'f', 0)));
        } else if (column == 8) {
            if (ui->ittTab->item(row, column)->text().toInt() >= 99) {
                ui->ittTab->item(row, column)->setText("99");
            }
            ui->ittTab->item(row, column)->setText(
                        (QString::number(ui->ittTab->item(row, column)->text().toDouble() \
                                                    , 'f', 0)));
        } else {
            //
        }
        if (row == 0) {
            for (i = 1; i <= 7; i++) {
                ui->ittTab->item(i, column)->setText(ui->ittTab->item(0, column)->text());
            }
        }
    }
    Init_Flag = false;
}
void Widget_IMP::on_doubleSpinBox_red_editingFinished()
{
    Display_Shape->Red_line = ui->doubleSpinBox_red->value();
    Display_Shape->update();
    IMP_WaveList[Record_Row]->Red_line = ui->doubleSpinBox_red->value()*200/651;
}
void Widget_IMP::on_doubleSpinBox_green_editingFinished()
{
    Display_Shape->Green_line = (ui->doubleSpinBox_green->value());
    Display_Shape->update();
    IMP_WaveList[Record_Row]->Green_line = ui->doubleSpinBox_green->value()*200/651;
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.10.24
  * brief:      左右工位信号进行更改
******************************************************************************/
void Widget_IMP::on_comb_Station_currentIndexChanged(int index)
{
    sample_time = 1;
    ui->button_sample_collect->setText(QString(tr("采集第 %1 个样品")).arg(sample_time));
    ui->button_sample_cancle->setText(tr("取消"));
    index = 0;
}


void Widget_IMP::IMP_NetData(QStringList list, QString str) {
    Init_Flag = true;
    int i, j, wave_count;
    QStringList wave_data;
    if (str == QString(tr("test"))) {
        for (i = 0; i < 8; i++) {
            if (list.at(i).toInt() != 0) {
                Box_IMP_List[i]->setChecked(true);
            } else {
                Box_IMP_List[i]->setChecked(false);
            }
        }
    } else if (str == QString(tr("area"))) {
        for (i = 0; i < 8; i++) {
            ui->ittTab->item(i, 5)->setText(list.at(i));
        }
    } else if (str == QString(tr("area_min"))) {
        for (i = 0; i < 8; i++) {
            Copy_IMP_List.replace(i*NUM_ITT+19, list.at(i));
        }
    } else if (str == QString(tr("diff"))) {
        for (i = 0; i < 8; i++) {
            ui->ittTab->item(i, 6)->setText(list.at(i));
        }
    } else if (str == QString(tr("diff_min"))) {
        for (i = 0; i < 8; i++) {
            Copy_IMP_List.replace(i*NUM_ITT+18, list.at(i));
        }
    } else if (str == QString(tr("flut"))) {
        for (i = 0; i < 8; i++) {
            ui->ittTab->item(i, 7)->setText(list.at(i));
        }
    } else if (str == QString(tr("gear"))) {
        for (i = 0; i < 8; i++) {
            Copy_IMP_Gear.replace(i, list.at(i));
        }
    } else if (str == QString(tr("freqsL"))) {
        for (i = 0; i < 8; i++) {
            Copy_IMP_List.replace(NUM_ITT*i+9, list.at(i)); // 保存左工位的频率
        }
    } else if (str == QString(tr("freqsR"))) {
        for (i = 0; i < 8; i++) {
             Copy_IMP_List.replace(NUM_ITT*i+14, list.at(i)); // 保存右工位频率
        }
    } else if (str == QString(tr("phase"))) {
        for (i = 0; i < 8; i++) {
            ui->ittTab->item(i, 8)->setText(list.at(i));
        }
    }  else if (str == QString(tr("from"))) {
        for (i = 0; i < 8; i++) {
            Copy_IMP_List.replace(i*NUM_ITT + 11, list.at(i));
        }
    }  else if (str == QString(tr("stop"))) {
        for (i = 0; i < 8; i++) {
            Copy_IMP_List.replace(i*NUM_ITT + 12, list.at(i));
        }
    } else if (str == QString(tr("time"))) {
        for (i = 0; i < 8; i++) {
            ui->ittTab->item(i, 4)->setText(list.at(i));
        }
    } else if (str == QString(tr("volt"))) {
        for (i = 0; i < 8; i++) {
            ui->ittTab->item(i, 3)->setText(list.at(i));
        }
    } else if (str == QString(tr("port1"))) {
        for (i = 0; i < 8; i++) {
            ui->ittTab->item(i, 1)->setText(list.at(i));
        }
    } else if (str == QString(tr("port2"))) {
        for (i = 0; i < 8; i++) {
             ui->ittTab->item(i, 2)->setText(list.at(i));
        }
    } else if (str == QString(tr("wave"))) {
        for (i = 0; i < 8; i++) {
            wave_data = list.at(i).split(" ");
            if (wave_data.size() > 1) {
                wave_count = wave_data.at(0).toInt();
                for (j = 0; j < 400; j++) {
                    IMP_WaveSqlList[i]->point[j] = wave_data.at(j + 1).toInt();
                }
            }
        }
    } else if (str == QString(tr("waveR"))) {
        for (i = 0; i < 8; i++) {
            wave_data = list.at(i).split(" ");
            if (wave_data.size() > 1) {
                wave_count = wave_data.at(0).toInt();
                for (j = 0; j < 400; j++) {
                    Right_value.replace(NUM_ITT*i + 20 + j, wave_data.at(j + 1));
                    IMP_Right_Wave[11]->sample_point[i][j] = wave_data.at(j + 1).toInt(); // 17
                }
            }
        }
        Pri_IMP_Data_Save();
    } else {
        //
    }
    Init_Flag = false;
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.10.24
  * brief:      IMP  判定结果
******************************************************************************/
QStringList Widget_IMP::Pub_Main_IMP_Result(int ittwaveframe, int *waveItt, int station)
{
    QStringList imp_result;  imp_result << "0" << "0" << "0" << "0";
    double Area = 0.0;
    double Phase_Test;
    Phase_Test = 0.0;
    int IMP_origin, IMP_terminal;
    if (Set_Compare_CheckBox->checkState() == 2) {
        ittwaveframe = 0;
    } else {
        //
    }

    IMP_origin = (Copy_IMP_List.at(NUM_ITT*ittwaveframe+11).toInt())*400/651;
    IMP_terminal = (Copy_IMP_List.at(NUM_ITT*ittwaveframe+12).toInt())*400/651;
    if (station == 0x13) {
        Area = Pri_IMP_Area(IMP_WaveSqlList[ittwaveframe]->point, \
                            waveItt, IMP_origin, IMP_terminal);
        imp_result.replace(0, QString::number(Area, 'f', 1));
        imp_result.replace(1, QString::number\
                           (Pri_IMP_Diff(IMP_WaveSqlList[ittwaveframe]->point, waveItt, \
                                         IMP_origin, IMP_terminal), 'f', 1));
        imp_result.replace(2, QString::number(Pri_IMP_Flut(waveItt, IMP_origin, IMP_terminal)));
        Phase_Test = Pri_IMP_Phase(IMP_WaveSqlList[ittwaveframe]->point,  waveItt, \
                                   IMP_origin, IMP_terminal)*100/(100+Area);
        imp_result.replace(3, QString::number(Phase_Test, 'f', 0));
    } else if (station != 0x13) {
        Area = Pri_IMP_Area(IMP_Right_Wave[11]->sample_point[ittwaveframe], \
                waveItt, IMP_origin, IMP_terminal);
        imp_result.replace(0, QString::number(Area, 'f', 1));
        imp_result.replace(1, QString::number\
                           (Pri_IMP_Diff(IMP_Right_Wave[11]->sample_point[ittwaveframe], \
                            waveItt, IMP_origin, IMP_terminal), 'f', 1));
        imp_result.replace(2, QString::number(Pri_IMP_Flut(waveItt, IMP_origin, IMP_terminal)));
         Phase_Test= Pri_IMP_Phase(IMP_Right_Wave[11]->sample_point[ittwaveframe], \
         waveItt, IMP_origin, IMP_terminal)*100/(100+Area);
         imp_result.replace(3, QString::number(Phase_Test, 'f', 0));
    } else {
        //
    }
    return imp_result;
}
QStringList Widget_IMP::Pub_Main_IMP_Result_Compare(int ittwaveframe, \
                                                    int *waveItt, int *Compare_waveItt) {
    double Phase_Test;
    Phase_Test = 0.0;
    QStringList imp_result;  imp_result << "0" << "0" << "0" << "0";
    double Area = 0.0;
    int IMP_origin, IMP_terminal;
    IMP_origin = (Copy_IMP_List.at(NUM_ITT*ittwaveframe + 11).toInt())*400/651;
    IMP_terminal = (Copy_IMP_List.at(NUM_ITT*ittwaveframe + 12).toInt())*400/651;

    Area = Pri_IMP_Area(Compare_waveItt, waveItt, IMP_origin, IMP_terminal);
    imp_result.replace(0, QString::number(Area, 'f', 1));
    imp_result.replace(1, QString::number(Pri_IMP_Diff(Compare_waveItt, waveItt, \
                                                       IMP_origin, IMP_terminal), 'f', 1));
    imp_result.replace(2, QString::number(Pri_IMP_Flut(waveItt, IMP_origin, IMP_terminal)));
    Phase_Test = Pri_IMP_Phase(Compare_waveItt, \
                               waveItt, IMP_origin, IMP_terminal)*100/(100+Area);
    imp_result.replace(3, QString::number(Phase_Test, 'f', 0));

    return imp_result;
}

QStringList Widget_IMP::Pub_Main_IMP_Result_Compare_2(int ittwaveframe, int *waveItt, \
                                                      int *Compare_waveItt, int station) {
    QStringList imp_result;  imp_result << "0" << "0" << "0" << "0";
    double Area = 0.0;
    double Phase_Test;
    Phase_Test = 0.0;
    int IMP_origin, IMP_terminal;
    if (ittwaveframe%3 == 0) {
        IMP_origin = (Copy_IMP_List.at(NUM_ITT*ittwaveframe + 11).toInt())*400/651;
        IMP_terminal = (Copy_IMP_List.at(NUM_ITT*ittwaveframe + 12).toInt())*400/651;
        if (station == 0x13) {
            Area = Pri_IMP_Area\
                    (IMP_WaveSqlList[ittwaveframe]->point, waveItt, IMP_origin, IMP_terminal);
            imp_result.replace(0, \
                               QString::number(Area, 'f', 1));
            imp_result.replace(1, \
                               QString::number(Pri_IMP_Diff\
                                               (IMP_WaveSqlList[ittwaveframe]->point, \
                                                waveItt, IMP_origin, IMP_terminal), 'f', 1));
            imp_result.replace(2, \
                               QString::number(Pri_IMP_Flut(waveItt, IMP_origin, IMP_terminal)));
            Phase_Test = Pri_IMP_Phase(IMP_WaveSqlList[ittwaveframe]->point, waveItt, IMP_origin, \
                                                            IMP_terminal)*100/(100+Area);
            imp_result.replace(3, QString::number(Phase_Test, 'f', 0));
        } else if (station != 0x13) {
            Area = Pri_IMP_Area\
                    (IMP_Right_Wave[11]->sample_point[ittwaveframe], \
                    waveItt, IMP_origin, IMP_terminal);
            imp_result.replace(0, QString::number(Area, 'f', 1));
            imp_result.replace(1, QString::number(Pri_IMP_Diff\
                                               (IMP_Right_Wave[11]->sample_point[ittwaveframe], \
                                               waveItt, IMP_origin, IMP_terminal), 'f', 1));
            imp_result.replace(2, \
                               QString::number(Pri_IMP_Flut(waveItt, IMP_origin, IMP_terminal)));
            Phase_Test = Pri_IMP_Phase (IMP_Right_Wave[11]->sample_point[ittwaveframe], waveItt, \
                    IMP_origin, IMP_terminal)*100/(100 + Area);
            imp_result.replace(3, QString::number(Phase_Test, 'f', 0));
        } else {
            //
        }
        return imp_result;
    } else {
        IMP_origin = (Copy_IMP_List.at(NUM_ITT*ittwaveframe+11).toInt())*400/651;
        IMP_terminal = (Copy_IMP_List.at(NUM_ITT*ittwaveframe+12).toInt())*400/651;

        Area = Pri_IMP_Area(Compare_waveItt, waveItt, IMP_origin, IMP_terminal);
        imp_result.replace(0, QString::number(Area, 'f', 1));
        imp_result.replace\
                (1, QString::number(Pri_IMP_Diff \
                                    (Compare_waveItt, waveItt, IMP_origin, IMP_terminal), 'f', 1));
        imp_result.replace\
                (2, QString::number(Pri_IMP_Flut\
                                    (waveItt, IMP_origin, IMP_terminal)));
        Phase_Test = Pri_IMP_Phase(Compare_waveItt, waveItt, IMP_origin, \
                                   IMP_terminal)*100/(100+Area);
        imp_result.replace(3, QString::number(Phase_Test, 'f', 0));

        return imp_result;
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.10.24
  * brief:      IMP 保存采集波形
******************************************************************************/
void Widget_IMP::Pub_Main_IMP_Get_date(int ittwaveframe, int *waveItt)
{
    int i;
    for (i = 0; i < 400; i++) {
        if (IMP_Add_Sample) {
            if (ui->comb_Station->currentText() == QString(tr("左工位"))) {
                IMP_Left__Wave[sample_time-1]->sample_point[ittwaveframe][i] = waveItt[i];
            } else if (ui->comb_Station->currentText() == QString(tr("右工位"))) {
                IMP_Right_Wave[sample_time-1]->sample_point[ittwaveframe][i] = waveItt[i];
            } else {
                //
            }
        } else { // 2017.3.8 增加左右工位分别采集
            if (ui->comb_Station->currentText() == QString(tr("左工位"))) {
                IMP_WaveSqlList[ittwaveframe]->point[i] = waveItt[i];
            } else if (ui->comb_Station->currentText() == QString(tr("右工位"))) {
                Right_value.replace(NUM_ITT*ittwaveframe + 20 + i, QString::number(waveItt[i]));
                IMP_Right_Wave[11]->sample_point[ittwaveframe][i] = waveItt[i]; // 17
            }
        }
        IMP_WaveList[ittwaveframe]->point[i] = waveItt[i]/4;
        IMP_WaveList[ittwaveframe]->pointgreen[i] = 260;
    }
    IMP_WaveList[ittwaveframe]->num = 400;
    IMP_WaveList[ittwaveframe]->update();
    slot_big_shape(ittwaveframe, 0);
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.10.24
  * brief:      imp  是否采样完成
******************************************************************************/
void Widget_IMP::Pub_Main_IMP_FinshSample()
{
    if (sample_time == 1) {
        qDebug() << "Widget_IMP::Pub_Main_IMP_FinshSample()";
        ui->label->setText(tr("默认--采集完成"));
        Pri_IMP_Data_Save(); // 匝间保存数据
    } else {
        ui->label->setText(QString(tr("样品-%1-采集完成")).arg(sample_time - 1));
    }

    IMP_Add_Sample = false;
    IMP_Test_Ready = true;
}
void Widget_IMP::Pub_Conf_Get_Result(can_frame frame, int flag)
{
    switch (flag) {
    case 1:
        if (ui->comb_Station->currentText() == QString(tr("左工位"))) {
            Copy_IMP_List.replace(frame.data[1]*NUM_ITT+9, QString::number(frame.data[3]));
            // 保存左工位的频率
            if ((Testing_Real) || (!IMP_NO_Back_Volt)) {
                Copy_IMP_List.replace(frame.data[1]*NUM_ITT+10, \
                        QString::number(frame.data[4]*256+frame.data[5]));
                // 左工位的电压
            }
        } else if (ui->comb_Station->currentText() == QString(tr("右工位"))) {
            Copy_IMP_List.replace(frame.data[1]*NUM_ITT+14, QString::number(frame.data[3]));
            // 保存右工位频率
            if ((Testing_Real) || (!IMP_NO_Back_Volt)) {
                Copy_IMP_List.replace(frame.data[1]*NUM_ITT+15, \
                        QString::number(frame.data[4]*256+frame.data[5]));
                // 右工位的电压
            }
        } else {
            //
        }
        break;
    default:
        break;
    }
}
QStringList Widget_IMP::IMP_Test_Param(bool up_down)
{
    int j;
    QString str;
    QStringList strSql;
    QStringList strParam, strTest;
    QStringList area_down, diff_down;
    strTest.clear();
    strParam.clear();

    area_down.clear();
    diff_down.clear();

    for (j = 0; j < 8; j++) {
        area_down.append("");
        diff_down.append("");
    }
    if (up_down) {
        for (j = 0; j < 8; j++) {
            if ((Copy_IMP_List[j*NUM_ITT + 8].toInt())) {
                area_down.replace(j, Copy_IMP_List.at(j*NUM_ITT + 19) + "~");
                diff_down.replace(j, Copy_IMP_List.at(j*NUM_ITT + 18) + "~");
            } else {
                //
            }
        }
    } else {
        //
    }
    for (j = 0; j < 8; j++) {
        if ((Copy_IMP_List[j*NUM_ITT + 8].toInt())) {
            str = QString(tr("匝间")) + Copy_IMP_List.at(NUM_ITT*j) + \
                    "-" + Copy_IMP_List.at(NUM_ITT*j + 1);
            strTest.append(str);
            str.clear();
            if ((Spin_IMP_List[6][j]->text().toInt()) || \
                    (Spin_IMP_List[7][j]->text().toInt())) {
                str += Spin_IMP_List[2][j]->text();  str += "V,";
                str += area_down.at(j) + Spin_IMP_List[4][j]->text();  str += ",";
                // str += ",面积:";
                str += diff_down.at(j) + Spin_IMP_List[5][j]->text();  str += ",";
                // str += ",差积:";
                str += Spin_IMP_List[6][j]->text();  str += ",";  // str += ",电晕:";
                str += Spin_IMP_List[7][j]->text();               // str += ",相位:";
            } else {
                str += Spin_IMP_List[2][j]->text();  str += "V,";
                str += QString(tr("面积:")) + area_down.at(j) + Spin_IMP_List[4][j]->text();
                str += ",";
                str += QString(tr("差积:")) + diff_down.at(j) + Spin_IMP_List[5][j]->text();
            }
            strParam.append(str);
            strSql.append(tr("匝间"));
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
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.10.24
  * brief:      配置界面 IMP 函数分配
******************************************************************************/
void Widget_IMP::Pub_Conf_Set_IMP(QString Conf_str, int flag)
{
    switch (flag) {
    case 1:
        Pri_IMP_Init(Conf_str);
        break;
    case 3:
        Pri_IMP_Init_Join(Conf_str);
        break;
    case 4:
        Pri_IMP_Data_Save();
        break;
    case 6:
        Pri_IMP_Default_value(Conf_str);
        break;
    case 7:
        if (!IMP_Test_Ready) // 判断匝间采集是否进入就绪状态
            break;
        IMP_Test_Ready = false;
        if (ui->comb_Station->currentText() == "") {
            IMP_Test_Ready = true;
            label_Waring = new QLabel(this);
            label_Waring->setGeometry(0, 0, 800, 600);
            label_Waring->show();
            //   Pri_IMP_WMessage(QString(tr("   请将滑罩移动到对应的工位   ")));
            QMessageBox Collect_Ask;
            Collect_Ask.setWindowFlags(Qt::FramelessWindowHint);
            Collect_Ask.setStyleSheet\
                    ("QMessageBox{border:3px groove gray;"\
                     "}background-color: rgb(209, 209, 157);");
            Collect_Ask.setText(tr("   请将滑罩移动到对应的工位   \n   "\
                                   "或者点击下面的工位信号进行选择  "));
            Collect_Ask.addButton(QMessageBox::Ok)->setStyleSheet\
                    ("border:none;height:30px;width:65px;border:5px groove gray;"\
                     "border-radius:10px;padding:2px 4px;");
            Collect_Ask.addButton(QMessageBox::Save)->setStyleSheet\
                    ("border:none;height:30px;width:65px;border:5px groove gray;"\
                     "border-radius:10px;padding:2px 4px;");
            Collect_Ask.addButton(QMessageBox::Cancel)->setStyleSheet\
                    ("border:none;height:30px;width:65px;border:5px groove gray;"\
                     "border-radius:10px;padding:2px 4px;");
            Collect_Ask.setButtonText(QMessageBox::Ok, QString(tr("左")));
            Collect_Ask.setButtonText(QMessageBox::Save, QString(tr("右")));
            Collect_Ask.setButtonText(QMessageBox::Cancel, QString(tr("取消")));
            Collect_Ask.setIcon(QMessageBox::Warning);
            int ret = Collect_Ask.exec();
            if (ret == QMessageBox::Ok) {
                ui->comb_Station->setCurrentIndex(0);
            } else if (ret == QMessageBox::Save) {
                ui->comb_Station->setCurrentIndex(1);
            } else if (ret == QMessageBox::Cancel) {
                //
            } else {
                //
            }
            label_Waring->hide();
        }
        if (ui->comb_Station->currentText() == tr("左工位")) {
            ui->dockWidget_2->hide();  sample_time = 1;
            Pri_IMP_TestSample(1, 0x13); // 0x00测试;0x01自动选频采样（1 自动选频采样）
        } else if (ui->comb_Station->currentText() == tr("右工位")) {
            Pri_IMP_TestSample(1, 0x14); // 0x00测试;0x01自动选频采样（1 自动选频采样）
        } else {
            //
        }
        break;
    case 9:
        on_ittTab_cellClicked(0, 0);
        break;
    case 12:
        IMP_NO_Back_Volt = true;
        break;
    case 13:
        if (Conf_str == "19") {
            ui->comb_Station->setCurrentIndex(0);
        } else if (Conf_str == "20") {
            ui->comb_Station->setCurrentIndex(1);
        } else {
        //    ui->comb_Station->setCurrentIndex(2);
        }
        break;
    case 15:
        on_ittTab_cellClicked(Conf_str.toInt()/10, Conf_str.toInt()%10+8);
        break;
    case 100:
        if (Conf_str.toInt()) {
            Init_Channel_6 = true;
        } else {
            Init_Channel_6 = false;
        }
        break;
    case 101:
        if (Conf_str.toInt()) {
            volt_set = 5000;
        } else {
            volt_set = 3000;
        }
        break;
    default:
        break;
    }
}
bool Widget_IMP::Pub_Conf_GetSample(int id)
{
    switch (id) {
    case 0:
        on_button_sample_collect_clicked();
        break;
    case 1:
        on_button_sample_cancle_clicked();
        break;
    case 2:
        if ((sample_time-1) < 1) {
            break;
        }
        on_button_sample_average_clicked();
        break;
    default:
        //
        break;
    }
    return IMP_Test_Ready;
}

void Widget_IMP::on_pushButton_clicked()
{
    IMP_Labelhide->show();
    Imp_Set_Widget->show();
}
