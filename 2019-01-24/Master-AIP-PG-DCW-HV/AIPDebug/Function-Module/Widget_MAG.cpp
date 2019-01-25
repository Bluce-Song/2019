/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "Widget_MAG.h"
#include "ui_Widget_MAG.h"

Widget_MAG::Widget_MAG(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_MAG)
{
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint); // 去掉标题栏
    ui->setupUi(this);

    Comb_MAGConf_List.append(ui->combConf4_2);  //  反嵌設置正反转动

    Line_MAG_List[0].append(ui->lineEdit_17);
    Line_MAG_List[1].append(ui->lineEdit_18);
    Line_MAG_List[2].append(ui->lineEdit_19);
    Line_MAG_List[3].append(ui->lineEdit_20);
    Line_MAG_List[4].append(ui->lineEdit_21);
    Line_MAG_List[5].append(ui->lineEdit_22);
    Line_MAG_List[6].append(ui->lineEdit_23);
    Line_MAG_List[7].append(ui->lineEdit_24);

    Line_MAG_List[8].append(ui->lineEdit_25);
    Line_MAG_List[9].append(ui->lineEdit_26);
    Line_MAG_List[10].append(ui->lineEdit_27);
    Line_MAG_List[11].append(ui->lineEdit_28);
    Line_MAG_List[12].append(ui->lineEdit_29);
    Line_MAG_List[13].append(ui->lineEdit_30);
    Line_MAG_List[14].append(ui->lineEdit_31);
    Line_MAG_List[15].append(ui->lineEdit_32);

    Line_RMAG_List[0].append(ui->lineEdit_1);
    Line_RMAG_List[1].append(ui->lineEdit_2);
    Line_RMAG_List[2].append(ui->lineEdit_3);
    Line_RMAG_List[3].append(ui->lineEdit_4);
    Line_RMAG_List[4].append(ui->lineEdit_5);
    Line_RMAG_List[5].append(ui->lineEdit_6);
    Line_RMAG_List[6].append(ui->lineEdit_7);
    Line_RMAG_List[7].append(ui->lineEdit_8);

    Line_RMAG_List[8].append(ui->lineEdit_9);
    Line_RMAG_List[9].append(ui->lineEdit_10);
    Line_RMAG_List[10].append(ui->lineEdit_11);
    Line_RMAG_List[11].append(ui->lineEdit_12);
    Line_RMAG_List[12].append(ui->lineEdit_13);
    Line_RMAG_List[13].append(ui->lineEdit_14);
    Line_RMAG_List[14].append(ui->lineEdit_15);
    Line_RMAG_List[15].append(ui->lineEdit_16);

    ui->lineEdit_17->hide();
    ui->lineEdit_18->hide();
    ui->lineEdit_19->hide();
    ui->lineEdit_20->hide();
    ui->lineEdit_21->hide();
    ui->lineEdit_22->hide();
    ui->lineEdit_23->hide();
    ui->lineEdit_24->hide();

    ui->lineEdit_25->hide();
    ui->lineEdit_26->hide();
    ui->lineEdit_27->hide();
    ui->lineEdit_28->hide();
    ui->lineEdit_29->hide();
    ui->lineEdit_30->hide();
    ui->lineEdit_31->hide();
    ui->lineEdit_32->hide();

    ui->lineEdit_1->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->lineEdit_5->hide();
    ui->lineEdit_6->hide();
    ui->lineEdit_7->hide();
    ui->lineEdit_8->hide();

    ui->oppTab->horizontalHeader()->setStyleSheet\
            ("QHeaderView::section{background-color:#191919;color: white;"\
             "padding-left: 4px;border: 1px solid #447684;}");
    ui->oppTab->horizontalHeader()->setFixedHeight(35);
    ui->oppTab->horizontalHeader()->setResizeMode(QHeaderView::Fixed);

    MAG_Group = new QButtonGroup;
    MAG_Group->addButton(ui->Key_1, 1);
    MAG_Group->addButton(ui->Key_2, 2);
    MAG_Group->addButton(ui->Key_3, 3);
    MAG_Group->addButton(ui->Key_4, 4);
    MAG_Group->addButton(ui->Key_5, 5);
    MAG_Group->addButton(ui->Key_6, 6);
    MAG_Group->addButton(ui->Key_7, 7);
    MAG_Group->addButton(ui->Key_8, 8);
    connect(MAG_Group, SIGNAL(buttonClicked(int)), this, SLOT(buttonJudge(int)));

    ui->dockWidget->hide();
    MAG_Labelhide = new QLabel(this);
    MAG_Labelhide->setGeometry(0, 0, 800, 600);
    MAG_Labelhide->hide();

    label_hide = new QLabel(this);
    label_hide->setGeometry(0, 0, 800, 600);
    label_hide->hide();
    Init_Channel_6 = false;

    Pri_Mag_power_UI();
    ui->combConf4_ROT2->hide();
    ui->label_31->hide();
    YY_Type = false;
    YY_ROT_Test = false;
    Init_MEKJ = false;
    MEKJ_Test = false;
}

Widget_MAG::~Widget_MAG()
{
    delete ui;
}

void Widget_MAG::Pri_Mag_power_UI() {
    int i;
    Quick_Set_Widget = new QWidget(this);
    Quick_Set_Widget->setGeometry(205, 160, 350, 290);
    Quick_Set_Widget->setWindowFlags(Qt::WindowStaysOnTopHint);
    Quick_Set_Widget->setStyleSheet\
            (".QWidget{border-radius: 10px;padding:2px 4px;background-color: gray;"\
             "color: black;border-color: black;}");
    QGridLayout *Quick_Set_upside = new QGridLayout;
    Quick_Set_upside->setSpacing(20);
    QString Quick_Set_table[3]={QString(tr("电压(V):")), \
                         QString(tr("电流(A):")), \
                               QString(tr("频率(Khz):"))}; //
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
    Quick_Set_DoubleSpinBox[0]->setMaximum(60);
    Quick_Set_DoubleSpinBox[0]->setMinimum(0);
    Quick_Set_DoubleSpinBox[0]->setDecimals(1);
    Quick_Set_DoubleSpinBox[0]->setValue(10);
    Quick_Set_upside->addWidget(Quick_Set_DoubleSpinBox[0], 0, 1);

    Quick_Set_DoubleSpinBox.append(new QDoubleSpinBox(this));
    Quick_Set_DoubleSpinBox[1]->setMaximumHeight(35);
    Quick_Set_DoubleSpinBox[1]->setMaximumWidth(255);
    Quick_Set_DoubleSpinBox[1]->setMaximum(20);
    Quick_Set_DoubleSpinBox[1]->setMinimum(0);
    Quick_Set_DoubleSpinBox[1]->setDecimals(1);
    Quick_Set_DoubleSpinBox[1]->setValue(3);
    Quick_Set_upside->addWidget(Quick_Set_DoubleSpinBox[1], 1, 1);

    Quick_Set_DoubleSpinBox.append(new QDoubleSpinBox(this));
    Quick_Set_DoubleSpinBox[2]->setMaximumHeight(35);
    Quick_Set_DoubleSpinBox[2]->setMaximumWidth(255);
    Quick_Set_DoubleSpinBox[2]->setMaximum(40);
    Quick_Set_DoubleSpinBox[2]->setMinimum(1);
    Quick_Set_DoubleSpinBox[2]->setDecimals(0);
    Quick_Set_DoubleSpinBox[2]->setValue(20);
    Quick_Set_upside->addWidget(Quick_Set_DoubleSpinBox[2], 2, 1);

    QPushButton *Quick_Set_Show_quit = new QPushButton;
    Quick_Set_Show_quit->setText(tr("退出"));
    Quick_Set_Show_quit->setMinimumHeight(50);
    Quick_Set_Show_quit->setMinimumWidth(90);
    Quick_Set_Show_quit->setStyleSheet\
            ("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"\
             "stop: 0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);");
    Quick_Set_upside->addWidget(Quick_Set_Show_quit, 0, 2);
    connect(Quick_Set_Show_quit, SIGNAL(clicked()), this, SLOT(Quick_Set_autoquit()));


    Quick_Set_Show_join = new QPushButton;
    Quick_Set_Show_join->setText(tr("保存"));
    Quick_Set_Show_join->setMinimumHeight(50);
    Quick_Set_Show_join->setMinimumWidth(90);
    Quick_Set_Show_join->setStyleSheet\
            ("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"\
             "stop: 0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);");
    Quick_Set_upside->addWidget(Quick_Set_Show_join, 2, 2);
    connect(Quick_Set_Show_join, SIGNAL(clicked()), this, SLOT(Quick_Set_Show_join_Clicked()));

    QVBoxLayout *Histogram_Quick_Set_Widget_layout = new QVBoxLayout;
    Histogram_Quick_Set_Widget_layout->addLayout(Quick_Set_upside);
    Quick_Set_Widget->setLayout(Histogram_Quick_Set_Widget_layout);
    Quick_Set_Widget->hide();

    Quick_Set_Show_Lable[2]->hide();
    Quick_Set_DoubleSpinBox[2]->hide();
}

void Widget_MAG::Quick_Set_autoquit() {
    Quick_Set_Widget->hide();
    label_hide->hide();
}

void Widget_MAG::Quick_Set_Show_join_Clicked() {
    // 数据调用,保存数据
    Copy_MAG_List.replace(6561, QString::number(Quick_Set_DoubleSpinBox[0]->value()));
    Copy_MAG_List.replace(6562, QString::number(Quick_Set_DoubleSpinBox[1]->value()));
    Copy_MAG_List.replace(6564, QString::number(Quick_Set_DoubleSpinBox[2]->value()));
    Quick_Set_Widget->hide();
    label_hide->hide();
}

void Widget_MAG::mousePressEvent(QMouseEvent *event) //处理鼠标被按下事件
{
    event->x();
    ui->dockWidget->hide();   MAG_Labelhide->hide();
}
void Widget_MAG::buttonJudge(int id)
{
    ui->dockWidget->hide();   MAG_Labelhide->hide();
    if (id != 9) {
        ui->oppTab->currentItem()->setText(QString::number(id));
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.1.27
  * brief:      测试反嵌
******************************************************************************/
void Widget_MAG::Pri_MAG_TestSample()
{
    int i;
    MAG_TestItems = 0;
    MAG_TestNumber = 0;
    for (i = 0; i < 8; i++) {
        if ((Box_MAG_List[i]->checkState()) == 2) {
            //  if (Copy_MAG_List.at(NUM_OPP*i+3).toInt() == 2)
            frame.can_id =  0x22;   frame.can_dlc = 0x05;
            frame.data[0] = 0x04;
            frame.data[1] = i;
            frame.data[2] = ui->oppTab->item(i, 1)->text().toInt();
            frame.data[3] = ui->oppTab->item(i, 2)->text().toInt();
            if (ui->combConf_Station->currentText() == tr("左工位")) {
                frame.data[4] = 0x01;
            } else {
                frame.data[4] = 0x01;
            }
            canSend(frame);
            MAG_TestItems = MAG_TestItems + (1 << i);
            MAG_TestNumber++;
        }
    }
    if (MAG_TestItems != 0) {  //  判断选择是否为空
        frame.can_id  = 0x22;   frame.can_dlc = 0x06;
        frame.data[0] = 0x01;
        frame.data[1] = 0x02;
        if (ui->combConf_Station->currentText() == tr("左工位")) {
            frame.data[2] = 0x01;
            frame.data[3] = 0x13;
        } else if (ui->combConf_Station->currentText() == tr("右工位")) {
            frame.data[2] = 0x01;
            frame.data[3] = 0x14;
        } else {
            //
        }

        frame.data[4] = 0x00;
        frame.data[5] = MAG_TestItems;
        canSend(frame);
    }
    if (ui->combConf_Station->currentText() == tr("左工位")) {
        for (i = 0; i < 8; i++) {
            Line_MAG_List[i][0]->setText(QString::number(0));
        }
    } else {
        for (i = 0; i < 8; i++) {
            Line_RMAG_List[i][0]->setText(QString::number(0));
        }
    }
}
int Widget_MAG::Test_MagData(int flag, int station, can_frame dat)
{
    int value = 0;
    switch (flag) {
    case 1:
        if (ui->combConf_Station->currentText() == tr("左工位")) {
            Line_MAG_List[dat.data[1]][0]->setText(QString::number(dat.data[2]*256+dat.data[3]));
            Line_MAG_List[8 + dat.data[1]][0]->setText(QString::number(dat.data[4]));
        } else {
            Line_RMAG_List[dat.data[1]][0]->setText(QString::number(dat.data[2]*256+dat.data[3]));
            Line_RMAG_List[8 + dat.data[1]][0]->setText(QString::number(dat.data[4]));
        }
        break;
    case 2:
        if (station == 0x13) {
            if ((Line_MAG_List[dat.data[1]][0]->text()) == "0") {
                //  防止出现结果为0时的BUG
                value = 100;
            } else {
                value = (qAbs(((Line_MAG_List[dat.data[1]][0]->text()).toInt()) - \
                        (dat.data[2]*256+dat.data[3]))) * \
                        100/((Line_MAG_List[dat.data[1]][0]->text()).toInt());
            }
        } else {
            if ((Line_RMAG_List[dat.data[1]][0]->text()) == "0") {
                //  防止出现结果为0时的BUG
                value = 100;
            } else {
                value = (qAbs(((Line_RMAG_List[dat.data[1]][0]->text()).toInt()) - \
                        (dat.data[2]*256+dat.data[3]))) * \
                        100/((Line_RMAG_List[dat.data[1]][0]->text()).toInt());
            }
        }
        break;
    default:
        break;
    }
    return value;
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.1.27
  * brief:      测试反嵌
******************************************************************************/
void Widget_MAG::Pri_MAG_Test()
{
    int i;
    MAG_TestItems = 0;
    MAG_TestNumber = 0;
    for (i = 0; i < 8; i++) {
        if (Copy_MAG_List.at(NUM_OPP*i+3).toInt() == 2) {
            //  if (Copy_MAG_List.at(NUM_OPP*i+3).toInt() == 2)
            frame.can_id = 0x22; frame.can_dlc = 0x05;
            frame.data[0] = 0x04;
            frame.data[1] = i;
            frame.data[2] = Copy_MAG_List[i*NUM_OPP].toInt();
            frame.data[3] = Copy_MAG_List[i*NUM_OPP+1].toInt();
            frame.data[4] = Line_MAG_List[8+i][0]->text().toInt();

            canSend(frame);
            MAG_TestItems = MAG_TestItems + (1 << i);
            MAG_TestNumber++;
        }
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      初始化反嵌设置
******************************************************************************/
void Widget_MAG::Pri_MAG_Init(QString flag)
{
    int i, j;
    /* int dec[3] = {0, 0, 0};
    int min[3] = {1, 1, 1};
    int max[3] = {8, 8, 99};  */

    MAG_WaveList.clear();
    Box_MAG_List.clear();
    for (i = 0; i < 3; i++) {
        MAG_WidgetList[i].clear();
    }

    ui->oppTab->setRowCount(0);

    ui->oppTab->setColumnWidth(0, 100);
    ui->oppTab->setColumnWidth(4, 200);  //  在第4列显示 波形
    ui->oppTab->setColumnWidth(5, 75);

    for (i = 0; i < Copy_MAG_List.size()/NUM_OPP; i++) { // 一组有820个数据
        ui->oppTab->setRowCount(i + 1);

        //初始化输入框
        QTableWidgetItem *pItem = new QTableWidgetItem;  // 创建序号
        pItem->setTextAlignment(Qt::AlignCenter);
        switch (i) {
        case 0:
            pItem->setText(tr("主相"));
            break;        // 显示序列号
        case 1:
            pItem->setText(tr("副相"));
            break;
        default:
            pItem->setText(QString::number(i + 1));
            break;
        }
        pItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ui->oppTab->setItem(i, 0, pItem);

        for (j = 0; j < 3; j++) {
            MAG_WidgetList[j].append(new QTableWidgetItem);
            MAG_WidgetList[j][i]->setText(Copy_MAG_List.at(i*NUM_OPP+j));
            MAG_WidgetList[j][i]->setTextAlignment(Qt::AlignCenter);
            if (j != 2) {
                MAG_WidgetList[j][i]->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            }
            ui->oppTab->setItem(i, j+1, MAG_WidgetList[j][i]);
        }
        MAG_WaveList.append(new wt_Wave);                //  创建波形显示区
        ui->oppTab->setCellWidget(i, 4, MAG_WaveList[i]);  //  在第4行显示 波形
        if (Copy_MAG_List.at(NUM_OPP*i+3).toInt() == 2) {   //  反嵌是否选中
            for (j = 0; j < 400; j++) {   //  拉伸400个点
                MAG_WaveList[i]->point[j] = Copy_MAG_List.at(NUM_OPP*i + 20 + j).toDouble();
                MAG_WaveList[i]->pointgreen[j] = 260;
            }
        } else {
            for (j = 0; j < 400; j++) {   //  拉伸400个点
                MAG_WaveList[i]->point[j] = 260;
                MAG_WaveList[i]->pointgreen[j] = 260;
            }
        }
        MAG_WaveList[i]->num = 400;   //  拉伸400个点
        MAG_WaveList[i]->update();

        Box_MAG_List.append(new QCheckBox);
        Box_MAG_List[i]->setStyleSheet\
                ("QCheckBox::indicator {image: url(:/image/053.png);"\
                 "width: 75px;height: 55px;}QCheckBox::indicator:checked "\
                 "{image: url(:/image/051.png);}");
        if (Copy_MAG_List.at(NUM_OPP*i+3).toInt() == 2) {
            Box_MAG_List[i]->setChecked(true);
        }
        ui->oppTab->setCellWidget(i, 5, Box_MAG_List[i]);
        Line_MAG_List[i][0]->setText(Copy_MAG_List.at(NUM_OPP*i+4));
        Line_MAG_List[8+i][0]->setText(Copy_MAG_List.at(NUM_OPP*i+5));
        Line_RMAG_List[i][0]->setText(Copy_MAG_List.at(NUM_OPP*i+9));
        Line_RMAG_List[8+i][0]->setText(Copy_MAG_List.at(NUM_OPP*i+10));
    }

    connect(Box_MAG_List[0], SIGNAL(stateChanged(int)), this, SLOT(Box_0_clicked(int)));
    connect(Box_MAG_List[1], SIGNAL(stateChanged(int)), this, SLOT(Box_1_clicked(int)));
    if ((Box_MAG_List[0]->checkState() == 2) && (Box_MAG_List[1]->checkState() == 2)) {
        ui->combConf4_2->setCurrentIndex(Copy_MAG_List.at(6).toInt());
        // 任意一组数据进行选择
    } else {
        ui->combConf4_2->setDisabled(true);
    }
    ui->combConf4_ROT2->setCurrentIndex(Copy_MAG_List.at(6563).toInt());
    //    if ((flag.toInt()) == 2)
    //    {
    //        ui->oppTab->hide();
    //        ui->label_30->move(280, 30);
    //        ui->label_29->move(280, 70);
    //        ui->combConf4_2->move(280, 110);
    //        ui->combConf_Station->move(280, 170);
    //        ui->label->move(280, 230);
    //    }
    /*  DockWidget_y=ui->oppTab->rowViewportPosition(0)+(ui->oppTab->horizontalHeader()->height());
    DockWidget_x=ui->oppTab->columnViewportPosition(3);
    DockWidget_w=0;
    for (i=3;i<6;i++)
    {
        DockWidget_w=DockWidget_w+(ui->oppTab->columnWidth(i));
    }
    DockWidget_h=8*(ui->oppTab->rowHeight(0));
    ui->dockWidget->setGeometry(DockWidget_x, DockWidget_y, DockWidget_w, DockWidget_h);*/
    if (Copy_MAG_List.at(7).toInt() == 2) {
        ui->checkBox_zero->setChecked(true);
    }
    Box_MAG_List.append(ui->checkBox_zero);
    Quick_Set_DoubleSpinBox[0]->setValue(Copy_MAG_List.at(6561).toDouble());
    Quick_Set_DoubleSpinBox[1]->setValue(Copy_MAG_List.at(6562).toDouble());
    Quick_Set_DoubleSpinBox[2]->setValue(Copy_MAG_List.at(6564).toDouble());
    flag.clear();
}
int Widget_MAG::MagDir_Conf(int magnum, int mag_rotation, int *waveItt)
{
    int i = 0;
    int mag_zero_count = 0;
    int get_rot;
    get_rot = 100;
    for (i = 0; i < 400; i++) {
        MAG_WaveList[magnum]->point[i] = waveItt[i];
        MAG_WaveList[magnum]->pointgreen[i] = 260;
    }

    if (ui->checkBox_zero->checkState() == 2) {
        mag_zero_count = Pri_Mag_Trend(waveItt);
        Copy_MAG_List.replace(magnum*NUM_OPP+8, QString::number(mag_zero_count));
    } else {
        //
    }

    if ((Box_MAG_List[0]->checkState() == 2) && \
            (Box_MAG_List[1]->checkState() == 2)) {
        if (magnum == 1) { // 正反转
            get_rot = Pri_MagDir_Conf(mag_rotation);
        }
    }
    MAG_WaveList[magnum]->num = 400;
    MAG_WaveList[magnum]->update();
    return get_rot;
}

int  Widget_MAG::Pri_Mag_Trend(int *waveform_point) {
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

    for (i = 1; i < 398; i++) {
        if (data.at(i) != data.at(i + 1)) {
            data.replace(i + 1, data.at(i));
            i = i + 1;
        } else {

        }
    }*/ //測試趨勢
    int i = 0;
    bool Add_zero;
    int ping_point[400];
    Add_zero = false;
    int H_data = 0,L_data = 0;
    int Max_point = 0,Min_point = 0;
    H_data = 0;
    L_data = 0;

    int zero_count = 0;
    zero_count = 0;

    QStringList zero_list;
    zero_list.clear();

    int Start_Point;
    int Max_Point;
    Start_Point = 0;
    Max_Point = waveform_point[0];
    for (i = 1; i < 400; i++) {
        if (waveform_point[i] > Max_Point) {
            Max_Point = waveform_point[i];
            Start_Point = i;
        } else {
            //
        }
    }

    qDebug() << Start_Point;
    for (i = 0; i < (400 - Start_Point); i++) {
        ping_point[i] = waveform_point[i + Start_Point];
    }
    for (i = 0; i < (Start_Point); i++) {
        ping_point[i + (400 - Start_Point)] = waveform_point[i];
    }
    L_data = 0;
    H_data = 0;

    zero_count = 0;

    // find High
    for (i = 0; i < 400; i++) {
        if ((ping_point[i]) >= 128) {
            if (H_data == 0) {
                if (L_data > 6) {
                    zero_count++;
                } else {
                    //
                }
            } else {
                //
            }
            H_data++;
            L_data = 0;
        } else {
            if (L_data == 0) {
                if (H_data > 6) {
                    zero_count++;
                } else {
                    //
                }
            } else {
                //
            }
            L_data++;
            H_data = 0;
        }
    }
    qDebug() << "zero_count---new" << zero_count;
    return zero_count;
}

/***********************************************************
* @name	 	MagDir_Conf
* @brief  	磁场旋向测试函数
* @param  	None
* @retval 	None
***********************************************************/
int Widget_MAG::Pri_MagDir_Conf(int mag_rotation) // void *pvParameters
{
    uint16_t    i = 0, j = 0;
    int16_t     temp = 0;
    int rot_value;
    // 计算主副相的面积，差积，和左右移动的差积
    uint32_t    area1, area2, diff, diff1, diff2;
    area1 = 0;  area2 = 0;  diff = 0;  diff1 = 0;   diff2 = 0;

    for (i = 10; i < 390; i++) { // 波形差积  410改为390
        // 面积
        temp = (MAG_WaveList[0]->point[i]) - 0x80;
        area1 += temp*temp;
        temp = (MAG_WaveList[1]->point[i])  -0x80;
        area2 += temp*temp;
        // 差积
        temp = (MAG_WaveList[0]->point[i] - MAG_WaveList[1]->point[i]);
        diff += temp*temp;

        for (j = 1; j < 11; j++) {
            temp = (MAG_WaveList[0]->point[i] - MAG_WaveList[1]->point[i + j]);
            // 副相左移  point
            diff1 += temp*temp;
            temp = (MAG_WaveList[0]->point[i] - MAG_WaveList[1]->point[i - j]);
            // 副相右移  pointgreen
            diff2 += temp*temp;
        }
    }
    diff1 = diff1/10;
    diff2 = diff2/10;

    if (((diff*3 < area1) && (diff*3 < area2)) || \
            (area1 < (area2 >> 4)) || (area2 < (area1 >> 4))) {
        rot_value = 0;
    } else {
        if (diff1 < diff2) { //副相在前
            if (mag_rotation == 0) {
                rot_value = 1;
            } else {
                rot_value = 2;
            }
        } else if (diff1 > diff2) { // 主相在前
            if (mag_rotation == 0) {
                rot_value = 2;
            } else {
                rot_value = 1;
            }
        } else {
            rot_value = 0;
        }
    }
    Pri_MAG_SetTaskDir(QString::number(rot_value));
    return rot_value;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      保存反嵌配置
******************************************************************************/
void Widget_MAG::Pri_MAG_Save_Data()
{
    int i, j;
    //更新反嵌数据
    ui->dockWidget->hide();  MAG_Labelhide->hide();
    for (i = 0; i < Copy_MAG_List.size()/NUM_OPP; i++) {
        Copy_MAG_List.replace\
                (i*NUM_OPP, QString::number(ui->oppTab->item(i, 1)->text().toInt()));
        Copy_MAG_List.replace\
                (i*NUM_OPP + 1, QString::number(ui->oppTab->item(i, 2)->text().toInt()));
        Copy_MAG_List.replace(i*NUM_OPP + 2, MAG_WidgetList[2][i]->text());

        for (j = 0; j < NUM_WAVE; j++) {
            Copy_MAG_List.replace\
                    (NUM_OPP*i + 20 + j, QString::number(MAG_WaveList[i]->point[j]));
        }

        Copy_MAG_List.replace(i*NUM_OPP+3, QString::number(Box_MAG_List[i]->checkState()));
        Copy_MAG_List.replace(i*NUM_OPP+4, Line_MAG_List[i][0]->text());
        Copy_MAG_List.replace(i*NUM_OPP+5, Line_MAG_List[8+i][0]->text());
        Copy_MAG_List.replace(i*NUM_OPP+9, Line_RMAG_List[i][0]->text());
        Copy_MAG_List.replace(i*NUM_OPP+10, Line_RMAG_List[8+i][0]->text());

        if (ui->combConf4_2->isEnabled()) {  //  判断使能的情况进行保存
            Copy_MAG_List.replace\
                    (i*NUM_OPP+6, QString::number(ui->combConf4_2->currentIndex()));
        }
        Copy_MAG_List.replace\
                (6563, QString::number(ui->combConf4_ROT2->currentIndex()));
    }
    Copy_MAG_List.replace(7, QString::number(ui->checkBox_zero->checkState()));
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      doubleSpinBox初始化
******************************************************************************/
void Widget_MAG::initSpinBox(QDoubleSpinBox *spin,  int dec,  int min,  int max)
{
    spin->setMaximum(max);              // 最大值
    spin->setMinimum(min);              // 最小值
    spin->setDecimals(dec);             // 小数点后位数
    spin->setStyleSheet("border:none"); // 透明
    spin->setAlignment(Qt::AlignCenter); // 居中
    spin->setFocusPolicy(Qt::ClickFocus);
    spin->setButtonSymbols(QAbstractSpinBox::NoButtons);
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.3.1
  * brief:      磁旋的显示设置
******************************************************************************/
void Widget_MAG::Pri_MAG_SetTaskDir(QString str_TaskMag)
{
    int i, TaskMag;
    TaskMag = str_TaskMag.toInt();
    switch (TaskMag) {
    case 0:
        ui->label_29->setText(tr("不转"));
        break;
    case 1:
        ui->label_29->setText(tr("反转"));
        ui->combConf4_2->setCurrentIndex(1);  //  设定为反转
        break;
    case 2:
        ui->label_29->setText(tr("正转"));
        ui->combConf4_2->setCurrentIndex(0);  //  设定为正转
        break;
    case 3:
        for (i = 0; i < 8; i++) {
            MAG_WaveList[i]->num = 0;
            MAG_WaveList[i]->update();
        }
        ui->label_29->setText("");
        break;
    default: break;
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.3.1
  * brief:      磁旋的正反转设置
******************************************************************************/
void Widget_MAG::Box_0_clicked(int test_key)   //  正反转 是否可选
{
    if ((Box_MAG_List[0]->checkState() == 2) && \
            (Box_MAG_List[1]->checkState() == 2)) {
        ui->combConf4_2->setEnabled(true);
    } else {
        ui->combConf4_2->setDisabled(true);
    }
    test_key = 0;
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.3.1
  * brief:      磁旋的正反转设置
******************************************************************************/
void Widget_MAG::Box_1_clicked(int test_key)
{
    if ((Box_MAG_List[0]->checkState() == 2) && \
            (Box_MAG_List[1]->checkState() == 2)) {
        ui->combConf4_2->setEnabled(true);
    } else {
        ui->combConf4_2->setDisabled(true);
    }
    test_key = 0;
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.3.1
  * brief:      反嵌的端一和端二设置
******************************************************************************/
void Widget_MAG::on_oppTab_cellClicked(int row,  int column)
{
    ui->Key_1->show(); ui->Key_2->show(); ui->Key_3->show(); ui->Key_4->show();
    ui->Key_5->show(); ui->Key_6->show(); ui->Key_7->show(); ui->Key_8->show();
    if (Init_Channel_6) {
        ui->Key_7->hide();
        ui->Key_8->hide();
    } else {
        //
    }
    if ((column == 1) || (column == 2)) {
        MAG_Labelhide->show();
        ui->dockWidget->show();
        ui->dockWidget->raise();
    }
    row = 0;
}
void Widget_MAG::on_oppTab_cellChanged(int row,  int column)
{
    int i;
    QString str;
    if (column == 3) {
        str = ui->oppTab->item(row, column)->text();
        if (str == NULL) {
            ui->oppTab->item(row, column)->setText("0");
        }
        for (i = 0; i < str.length(); i++) { // 判断输入是" 0-9 . "
            if (((str[i] >= '0') && (str[i] <= '9'))) {
                //
            } else {
                ui->oppTab->item(row, column)->setText("0");
                break;
            }
        }
        if (ui->oppTab->item(row, column)->text().toInt() >= 100) {
            ui->oppTab->item(row, column)->setText("100");
        }
    }
}

void Widget_MAG::Pri_MAG_Default_value(QString number)
{
    int i;
    if (number.size() == 0) {
        return;
    } else {
        //
    }
    for (i = 0; i < 8; i++) {
        Box_MAG_List[i]->setChecked(false);
    }
    for (i = 0; i < number.size()/2; i++) {
        ui->oppTab->item(i, 1)->setText(number.mid(i*2, 1));
        ui->oppTab->item(i, 2)->setText(number.mid(i*2 + 1, 1));
        Box_MAG_List[i]->setChecked(true);
    }
}
QStringList Widget_MAG::MAG_Test_Param(int Mag_shapehide)
{
    QString str;
    QStringList strSql;
    QStringList strParam, strTest;
    strParam.clear();
    strTest.clear();
    if (Mag_shapehide == 0) {
        for (int j = 0; j < 8; j++) {
            if ((Box_MAG_List[j]->checkState()) == 2) {
                str = QString(tr("反嵌")) + Copy_MAG_List.at(NUM_OPP*j) + "-" \
                        + Copy_MAG_List.at(NUM_OPP*j + 1);
                strTest.append(str);
                str = MAG_WidgetList[2][j]->text() + "%";
                strParam.append(str);
                strSql.append(tr("反嵌"));
            }
        }
    } else { // 波形隐藏
        //
    }

    if (Comb_MAGConf_List[0]->isEnabled()) {  //  在测试界面是否显示
        if (Comb_MAGConf_List[0]->currentIndex() != 2) {
            str = QString(tr("磁旋"));
            strTest.append(str);
            str = Comb_MAGConf_List[0]->currentText();
            strParam.append(str);
            strSql.append(tr("磁旋"));
            if (YY_Type) {
                if (ui->combConf4_ROT2->currentIndex() != 2) {
                    YY_ROT_Test = true;
                    str = QString(tr("磁旋-2"));
                    strTest.append(str);
                    str = ui->combConf4_ROT2->currentText();
                    strParam.append(str);
                    strSql.append(tr("磁旋-2"));
                } else {
                    YY_ROT_Test = false;
                }
            } else {
                 YY_ROT_Test = false;
            }
        }
    }
    if (Init_MEKJ) { // 嗎恩科技
        if (ui->combConf4_ROT2->currentIndex() != 2) {
            MEKJ_Test = true;
            str = QString(tr("磁旋-2"));
            strTest.append(str);
            str = ui->combConf4_ROT2->currentText();
            strParam.append(str);
            strSql.append(tr("磁旋-2"));
        } else {
            MEKJ_Test = false;
        }
    } else {
        //
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

void Widget_MAG::MAG_NetData(QStringList list, QString str) {
    int i, j, wave_count;
    QStringList wave_data;
    if (str == QString(tr("test"))) {
        for (i = 0; i < 8; i++) {
            if (list.at(i).toInt() != 0) {
                Box_MAG_List[i]->setChecked(true);
            } else {
                Box_MAG_List[i]->setChecked(false);
            }
        }
    } else if (str == QString(tr("areal"))) {
        for (i = 0; i < 8; i++) {
            Line_MAG_List[i][0]->setText(list.at(i));
        }
    } else if (str == QString(tr("arear"))) {
        for (i = 0; i < 8; i++) {
            Line_RMAG_List[i][0]->setText(list.at(i));
        }
    } else if (str == QString(tr("dir"))) {
        ui->combConf4_2->setCurrentIndex(list.at(0).toInt());
    } else if (str == QString(tr("freql"))) {
        for (i = 0; i < 8; i++) {
            Line_MAG_List[i+8][0]->setText(list.at(i));
        }
    }  else if (str == QString(tr("freqr"))) {
        for (i = 0; i < 8; i++) {
            Line_RMAG_List[i+8][0]->setText(list.at(i));
        }
    } else if (str == QString(tr("port1"))) {
        for (i = 0; i < 8; i++) {
            ui->oppTab->item(i, 1)->setText(list.at(i));
        }
    } else if (str == QString(tr("port2"))) {
        for (i = 0; i < 8; i++) {
             ui->oppTab->item(i, 2)->setText(list.at(i));
        }
    } else if (str == QString(tr("max"))) {
        for (i = 0; i < 8; i++) {
             ui->oppTab->item(i, 3)->setText(list.at(i));
        }
    } else if (str == QString(tr("wave"))) {
        for (i = 0; i < 8; i++) {
            wave_data = list.at(i).split(" ");
            if (wave_data.size() > 1) {
                wave_count = wave_data.at(0).toInt();
                for (j = 0; j < 400; j++) {
                    Copy_MAG_List.replace(NUM_OPP*wave_count + 20 + j, wave_data.at(j + 1));
                    MAG_WaveList[wave_count]->point[j] = wave_data.at(j+1).toInt();
                }
            }
        }


        ui->dockWidget->hide();  MAG_Labelhide->hide();
        for (i = 0; i < Copy_MAG_List.size()/NUM_OPP; i++) {
            Copy_MAG_List.replace\
                    (i*NUM_OPP, QString::number(ui->oppTab->item(i, 1)->text().toInt()));
            Copy_MAG_List.replace\
                    (i*NUM_OPP+1, QString::number(ui->oppTab->item(i, 2)->text().toInt()));
            Copy_MAG_List.replace(i*NUM_OPP+2, MAG_WidgetList[2][i]->text());

            Copy_MAG_List.replace(i*NUM_OPP+3, QString::number(Box_MAG_List[i]->checkState()));
            Copy_MAG_List.replace(i*NUM_OPP+4, Line_MAG_List[i][0]->text());
            Copy_MAG_List.replace(i*NUM_OPP+5, Line_MAG_List[8+i][0]->text());
            Copy_MAG_List.replace(i*NUM_OPP+9, Line_RMAG_List[i][0]->text());
            Copy_MAG_List.replace(i*NUM_OPP+10, Line_RMAG_List[8+i][0]->text());
            if (ui->combConf4_2->isEnabled()) {  //  判断使能的情况进行保存
                Copy_MAG_List.replace\
                        (i*NUM_OPP+6, QString::number(ui->combConf4_2->currentIndex()));
            }
            Copy_MAG_List.replace\
                    (6563, QString::number(ui->combConf4_ROT2->currentIndex()));
        }
        Pri_MAG_Save_Data();
    } else {
        //
    }
}

void Widget_MAG::Pub_Conf_Set_MAG(QString str, int flag)
{
    switch (flag) {
    case 1:
        Pri_MAG_Init(str);
        break;
    case 2:
        Pri_MAG_Save_Data();
        break;
    case 3:
        if (ui->combConf_Station->currentText() == "") {
            label_Waring = new QLabel(this);
            label_Waring->setGeometry(0, 0, 800, 600);
            label_Waring->show();
            QMessageBox Collect_Ask;
            Collect_Ask.setWindowFlags(Qt::FramelessWindowHint);
            Collect_Ask.setStyleSheet\
                    ("QMessageBox{border:3px groove gray;"\
                     "}background-color: rgb(209,  209,  157);");
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
                ui->combConf_Station->setCurrentIndex(0);
            } else if (ret == QMessageBox::Save) {
                ui->combConf_Station->setCurrentIndex(1);
            } else if (ret == QMessageBox::Cancel) {
                //
            } else {
                //
            }
            label_Waring->hide();
        }
        if (ui->combConf_Station->currentText() != "") {
            Pri_MAG_SetTaskDir(str);
        }
        break;
    case 5:
        Pri_MAG_Default_value(str);
        break;
    case 6:
        Pri_MAG_TestSample();
        break;
    case 7:
        Pri_MAG_Test();
        break;
    case 8:
        on_oppTab_cellClicked(0, 0);
        break;
    case 9:
        ui->combConf_Station->setCurrentIndex(2);
        break;
    case 10:
        if (str == "19") {
            ui->combConf_Station->setCurrentIndex(0);
        } else if (str == "20") {
            ui->combConf_Station->setCurrentIndex(1);
        } else {
            ui->combConf_Station->setCurrentIndex(2);
        }
        break;
    case 14:
        if ((str == "YY") || (str == "Y-YY") || (str == "D-YY") \
                || (str == "YY-PT")|| (str == "YY-1")) {
            YY_Type = true;
            ui->combConf4_ROT2->show();
            ui->label_31->show();
        } else {
            if (Init_MEKJ) {
                // -与吗恩科技冲突
            } else {
                YY_Type = false;
                ui->combConf4_ROT2->hide();
                ui->label_31->hide();
            }
        }
        break;
    case 100:
        if (str.toInt()) {
            Init_Channel_6 = true;
        } else {
            Init_Channel_6 = false;
        }
        break;
    case 101:
        if (str == "19") { // IO_Model 19
            ui->oppTab->hide();
            ui->checkBox_zero->hide();
            ui->combConf_Station->hide();
            ui->label_29->hide();
            ui->combConf4_ROT2->hide();

            ui->label_30->move(300, 205);
            ui->combConf4_2->move(300, 250);
            ui->button_power->move(300, 380);
        } else if (str == "20") {
            Init_MEKJ = true;
            ui->oppTab->hide();
            ui->checkBox_zero->hide();
            ui->combConf_Station->hide();
            ui->combConf4_ROT2->show();

            ui->label_29->hide();
            ui->label_30->move(300, 205);
            ui->combConf4_2->move(300, 250);
            ui->combConf4_ROT2->move(300, 310);
            ui->button_power->move(300, 380);
        } else if (str == "21") {
            ui->oppTab->hide();
            ui->checkBox_zero->hide();
            ui->combConf_Station->hide();
            ui->label_29->hide();
            ui->combConf4_ROT2->hide();

            Quick_Set_Show_Lable[1]->hide();
            Quick_Set_DoubleSpinBox[1]->hide();
            Quick_Set_Show_Lable[2]->show();
            Quick_Set_DoubleSpinBox[2]->show();
            ui->label_30->move(300, 205);
            ui->combConf4_2->move(300, 250);
            ui->button_power->move(300, 380);
        } else {
            ui->button_power->hide();
            ui->combConf4_ROT2->hide();
        }
        break;
    default:
        //
        break;
    }
}

void Widget_MAG::on_button_power_clicked()
{
    Quick_Set_Widget->show();
    label_hide->show();
}
