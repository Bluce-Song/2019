/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "Widget_INDL.h"
#include "ui_Widget_INDL.h"

Widget_INDL::Widget_INDL(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_INDL)
{
    ui->setupUi(this);
    //   电感设置表头
    ui->indlTab->horizontalHeader()->setStyleSheet\
            ("QHeaderView::section{background-color:#191919;color: white;"\
             "padding-left: 4px;border: 1px solid #447684;}");
    ui->indlTab->horizontalHeader()->setFixedHeight(35);
    ui->indlTab->horizontalHeader()->setResizeMode(QHeaderView::Fixed);
    ui->indlTab->setColumnWidth(0, 45); // -序号
    ui->indlTab->setColumnWidth(1, 45); // -端子T1
    ui->indlTab->setColumnWidth(2, 45); // -端子T2
    ui->indlTab->setColumnWidth(3, 70); // -下限
    ui->indlTab->setColumnWidth(4, 70); // -上限
    ui->indlTab->setColumnWidth(5, 70); // -Q值下限
    ui->indlTab->setColumnWidth(6, 70); // -Q值上限
    ui->indlTab->setColumnWidth(7, 60); // -补偿数值
    ui->indlTab->setColumnWidth(8, 60); // -标准值
    ui->indlTab->setColumnWidth(9, 60); // -使能
    ui->indlTab->setColumnWidth(10, 50); // -使能

    INDL_Group = new QButtonGroup;
    INDL_Group->addButton(ui->Key_1, 1);
    INDL_Group->addButton(ui->Key_2, 2);
    INDL_Group->addButton(ui->Key_3, 3);
    INDL_Group->addButton(ui->Key_4, 4);
    INDL_Group->addButton(ui->Key_5, 5);
    INDL_Group->addButton(ui->Key_6, 6);
    INDL_Group->addButton(ui->Key_7, 7);
    INDL_Group->addButton(ui->Key_8, 8);
    connect(INDL_Group, SIGNAL(buttonClicked(int)), this, SLOT(join_buttonJudge(int)));

    ui->dockWidget->hide();
    INDL_Labelhide = new QLabel(this);
    INDL_Labelhide->setGeometry(0, 0, 800, 600);
    INDL_Labelhide->hide();
    INDL_Init_Flag = false;

    ui->Button_Comp->hide();
    Init_Channel_6 = false;

    int i;
    INDL_Widget = new QWidget(this);
    INDL_Widget->setGeometry(150, 180, 500, 250);
    INDL_Widget->setWindowFlags(Qt::WindowStaysOnTopHint);
    INDL_Widget->setStyleSheet("border-radius: 10px;padding:2px 4px;background-color: gray;"\
                              "color: black;border-color: black;");
    QGridLayout *IO_upside = new QGridLayout;
    QString IO_table[1]={QString(tr("不平衡度模式:"))};
    for (i = 0; i < 1; i++) {
        INDL_Show_Lable.append(new QLabel(this));
        INDL_Show_Lable[i]->setText(IO_table[i]);
        INDL_Show_Lable[i]->setMaximumHeight(35); INDL_Show_Lable[i]->setMaximumWidth(155);
        INDL_Show_Lable[i]->setAlignment(Qt::AlignCenter);
        IO_upside->addWidget(INDL_Show_Lable[i], i, 0);
        if (i < 1) {
            INDL_DoubleSpinBox.append(new QDoubleSpinBox(this));
            INDL_DoubleSpinBox[i]->setMaximumHeight(35);
            INDL_DoubleSpinBox[i]->setMaximumWidth(255);
            INDL_DoubleSpinBox[i]->setMaximum(3);
            INDL_DoubleSpinBox[i]->setMinimum(1);
            INDL_DoubleSpinBox[i]->setDecimals(0);
            IO_upside->addWidget(INDL_DoubleSpinBox[i], i, 1);
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
    INDL_Widget->setLayout(Histogram_IO_Widget_layout);
    INDL_Widget->hide();
}

Widget_INDL::~Widget_INDL()
{
    delete ui;
}

void Widget_INDL::IO_Widget_autoquit() {
    INDL_Widget->hide();
}

void Widget_INDL::mousePressEvent(QMouseEvent *event) // 处理鼠标被按下事件
{
    if ((ui->indlTab->currentColumn() == 1) || \
            (ui->indlTab->currentColumn() == 2)) {
        ui->dockWidget->hide();   INDL_Labelhide->hide();
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.11.5
  * brief:      初始化电感设置
******************************************************************************/
void Widget_INDL::Pri_INDL_Init()
{
    int i;
    INDL_Init_Flag = true;
    ui->indlTab->setRowCount(8);   //  设置电感行数
    INDL_QTableWidgetItem.clear();
    Box_INDL_Grade_List.clear();
    INDL_Unit.clear();     INDL_Unit << "uH" << "mH";      //    电感单位

    ui->INDL_time->setValue(Copy_INDL_List.at(0).toInt());
    ui->INDL_balance->setValue(Copy_INDL_List.at(1).toDouble());
    ui->Com_fre->setCurrentIndex(Copy_INDL_List.at(2).toInt());
    ui->Com_connetct->setCurrentIndex(Copy_INDL_List.at(3).toInt());
    ui->INDL_Max->setValue(Copy_INDL_List.at(4).toInt());
    ui->INDL_Min->setValue(Copy_INDL_List.at(5).toInt());
    ui->Com_test->setCurrentIndex(Copy_INDL_List.at(6).toInt());
    ui->Q_balance->setValue(Copy_INDL_List.at(7).toDouble());
    ui->Com_volt->setCurrentIndex(Copy_INDL_List.at(8).toInt());
    for (i = 0; i < 8; i++) {
        ui->indlTab->setRowHeight(i, 53);
        QTableWidgetItem *INDL_Number = new QTableWidgetItem;  //   序号
        INDL_Number->setTextAlignment(Qt::AlignCenter);
        INDL_Number->setText(QString::number(i+1));
        INDL_Number->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ui->indlTab->setItem(i, 0, INDL_Number);

        QTableWidgetItem *INDL_Point_one = new QTableWidgetItem;  //   端子 1
        INDL_Point_one->setTextAlignment(Qt::AlignCenter);
        INDL_Point_one->setText(Copy_INDL_List.at(INDL_init_Number+20*i+0));
        INDL_Point_one->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ui->indlTab->setItem(i, 1, INDL_Point_one);

        QTableWidgetItem *INDL_Point_two = new QTableWidgetItem;  //   端子 2
        INDL_Point_two->setTextAlignment(Qt::AlignCenter);
        INDL_Point_two->setText(Copy_INDL_List.at(INDL_init_Number+20*i+1));
        INDL_Point_two->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ui->indlTab->setItem(i, 2, INDL_Point_two);

        QTableWidgetItem *Down_Limit = new QTableWidgetItem;  //   电感下限
        Down_Limit->setTextAlignment(Qt::AlignCenter);
        Down_Limit->setText(Copy_INDL_List.at(INDL_init_Number+20*i+2));
        ui->indlTab->setItem(i, 3, Down_Limit);

        QTableWidgetItem *Up_Limit = new QTableWidgetItem;   //   电感上限
        Up_Limit->setTextAlignment(Qt::AlignCenter);
        Up_Limit->setText(Copy_INDL_List.at(INDL_init_Number+20*i+3));
        ui->indlTab->setItem(i, 4, Up_Limit);

        QTableWidgetItem *QDown_Limit = new QTableWidgetItem;  //   Q值下限
        QDown_Limit->setTextAlignment(Qt::AlignCenter);
        QDown_Limit->setText(Copy_INDL_List.at(INDL_init_Number+20*i+4));
        ui->indlTab->setItem(i, 5, QDown_Limit);

        QTableWidgetItem *QUp_Limit = new QTableWidgetItem;   //   Q值上限
        QUp_Limit->setTextAlignment(Qt::AlignCenter);
        QUp_Limit->setText(Copy_INDL_List.at(INDL_init_Number+20*i+5));
        ui->indlTab->setItem(i, 6, QUp_Limit);

        QTableWidgetItem *Stand_INDL = new QTableWidgetItem;   //   标准电感
        Stand_INDL->setTextAlignment(Qt::AlignCenter);
        Stand_INDL->setText(Copy_INDL_List.at(INDL_init_Number+20*i+6));
        ui->indlTab->setItem(i, 7, Stand_INDL);

        QTableWidgetItem *UnitItem = new QTableWidgetItem; //
        UnitItem->setTextAlignment(Qt::AlignCenter);
        UnitItem->setText(INDL_Unit[Copy_INDL_List.at(INDL_init_Number+20*i+7).toInt()]);
        UnitItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ui->indlTab->setItem(i, 10, UnitItem);

        Box_INDL_Grade_List.append(new QCheckBox);   //  测试项目选择 勾选项目
        Box_INDL_Grade_List[i]->setStyleSheet\
                ("QCheckBox::indicator {image: url(:/image/053.png);"\
                 "width: 45px;height: 45px;}QCheckBox::indicator:checked "\
                 "{image: url(:/image/051.png);}");
        ui->indlTab->setCellWidget(i, 11, Box_INDL_Grade_List[i]);

        if (Copy_INDL_List.at(INDL_init_Number + i*20 + 8).toInt() == 2) {
            // 档位   (高 中 低 微 超微 极微)
            Box_INDL_Grade_List.at(i)->setChecked(true);
        }

        QTableWidgetItem *Compensation = new QTableWidgetItem;   //   补偿电感
        Compensation->setTextAlignment(Qt::AlignCenter);
        Compensation->setText(Copy_INDL_List.at(INDL_init_Number + 20*i + 9));
        ui->indlTab->setItem(i, 8, Compensation);

        QTableWidgetItem *R_Compensation = new QTableWidgetItem; //  右工位-补偿电感
        R_Compensation->setTextAlignment(Qt::AlignCenter);
        R_Compensation->setText(Copy_INDL_List.at(INDL_init_Number + 20*i + 10));
        ui->indlTab->setItem(i, 9, R_Compensation);
    }
    if (Copy_INDL_List.at(10).toInt() == 0) {
        INDL_DoubleSpinBox[0]->setValue(1);
    } else {
        INDL_DoubleSpinBox[0]->setValue(Copy_INDL_List.at(10).toInt());
    }
    INDL_Init_Flag = false;
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.11.5
  * brief:      电感参数进行快速设置
******************************************************************************/
void Widget_INDL::Pri_INDL_Quiky_Test_Parameter()
{
    int i;
    INDL_TestItemsH = 0;
    INDL_TestItemsL = 0;
    INDL_TestNumber = 0;
    for (i = 0; i < 8; i++) {
        if (Box_INDL_Grade_List.at(i)->checkState() != 2) {
            continue;
        }
        frame.can_id = 0x26;  frame.can_dlc = 0x07;
        frame.data[0] = 0x03;
        frame.data[1] = i;
        frame.data[2] = ui->indlTab->item(i, 1)->text().toInt(); //  抽头
        frame.data[3] = ui->indlTab->item(i, 2)->text().toInt();
        frame.data[4] = 1;
        frame.data[5] = 0x0b;
        frame.data[6] = (0x00|0x09);
        if (i >= 8) {
            INDL_TestItemsH = INDL_TestItemsH + (1 << (i-8));   //   高字节
        } else {
            INDL_TestItemsL = INDL_TestItemsL + (1 << i);       //   低字节
        }
        INDL_TestNumber++;                                  //   测试总数
        canSend(frame);
        usleep(1000);  usleep(1000);  usleep(1000);
        usleep(1000);  usleep(1000);  usleep(1000);
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2015.12.30
  * brief:      保存 INDL 配置
******************************************************************************/
void Widget_INDL::Pri_INDL_Test_Parameter()
{
    int i;
    i = 0;
    int Indl_Volt = 0;
    INDL_TestItemsH = 0;
    INDL_TestItemsL = 0;
    INDL_TestNumber = 0;
    if (ui->Com_volt->currentIndex() == 0) {
        Indl_Volt = 0x08;
    } else if (ui->Com_volt->currentIndex() == 1) {
        Indl_Volt = 0x00;
    } else if (ui->Com_volt->currentIndex() == 2) {
        Indl_Volt = 0x10;
    } else {
        Indl_Volt = 0x08;
    }
    for (i = 0; i < 8; i++) {
        if (Box_INDL_Grade_List.at(i)->checkState() != 2) {
            continue;
        }

        frame.can_id = 0x26;  frame.can_dlc = 0x07;
        frame.data[0] = 0x03;
        frame.data[1] = i;
        frame.data[2] = ui->indlTab->item(i, 1)->text().toInt(); //  抽头
        frame.data[3] = ui->indlTab->item(i, 2)->text().toInt();
        frame.data[4] = ui->INDL_time->text().toInt();
        if (ui->Com_fre->currentText() == "1K") {
            //  frame.data[5]  频率 电压 档位
            if (ui->indlTab->item(i, 10)->text() == "mH") {
                if (6.28*1*ui->indlTab->item(i, 7)->text().toDouble()/1000 < 1) {
                    frame.data[5] = 0x0b;
                } else if (6.28*1*ui->indlTab->item(i, 7)->text().toDouble()/1000 < 10) {
                    frame.data[5] = 0x2b;
                } else {
                    frame.data[5] = 0x3b;
                }
            } else {
                frame.data[5] = 0x0b;
            }
        } else if (ui->Com_fre->currentText() == "10K") {
            if (ui->indlTab->item(i, 10)->text() == "mH") {
                if (6.28*10*ui->indlTab->item(i, 7)->text().toDouble()/1000 < 1) {
                    frame.data[5] = 0x0c;
                } else if (6.28*10*ui->indlTab->item(i, 7)->text().toDouble()/1000 < 10) {
                    frame.data[5] = 0x2c;
                } else {
                    frame.data[5] = 0x3c;
                }
            } else {
                frame.data[5] = 0x0c;
            }
        } else if (ui->Com_fre->currentText() == "100") {
            if (ui->indlTab->item(i, 10)->text() == "mH") {
                if (6.28*0.1*ui->indlTab->item(i, 7)->text().toDouble()/1000 < 1) {
                    frame.data[5] = 0x09;
                } else if (6.28*0.1*ui->indlTab->item(i, 7)->text().toDouble()/1000 < 10) {
                    frame.data[5] = 0x29;
                } else {
                    frame.data[5] = 0x39;
                }
            } else {
                frame.data[5] = 0x09;
            }
        } else if (ui->Com_fre->currentText() == "120") {
            if (ui->indlTab->item(i, 10)->text() == "mH") {
                if (6.28*0.12*ui->indlTab->item(i, 7)->text().toDouble()/1000 < 1) {
                    frame.data[5] = 0x0a;
                } else if (6.28*0.12*ui->indlTab->item(i, 7)->text().toDouble()/1000 < 10) {
                    frame.data[5] = 0x2a;
                } else {
                    frame.data[5] = 0x3a;
                }
            } else {
                frame.data[5] = 0x0a;
            }
        }
        frame.data[5] = frame.data[5] & 0XE7;
        frame.data[5] = frame.data[5] | Indl_Volt;
        int connetct;                               //   frame.data[6]  连接方式 电压增益 电流增益
        if (ui->Com_connetct->currentText() == QString(tr("串联"))) {
            connetct = 0x00;
        } else {
            connetct = 0x40;
        }
        if (ui->indlTab->item(i, 10)->text() == "mH") {
            frame.data[6] = (connetct|0x09);
        } else {
            if (ui->indlTab->item(i, 4)->text().toDouble() < 500) {
                frame.data[6] = (connetct|0x0f);
            } else {
                frame.data[6] = (connetct|0x09);
            }
        }

        if (i >= 8) {
            INDL_TestItemsH = INDL_TestItemsH + (1 << (i-8));   //   高字节
        } else {
            INDL_TestItemsL = INDL_TestItemsL + (1 << i);       //   低字节
        }
        INDL_TestNumber++;                                  //   测试总数

        canSend(frame);

        usleep(1000);  usleep(1000);  usleep(1000);
        usleep(1000);  usleep(1000);  usleep(1000);
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2015.12.30
  * brief:      保存 INDL 配置
******************************************************************************/
void Widget_INDL::Pri_INDL_Data_Save()
{
    int i;
    Copy_INDL_List.replace(0, ui->INDL_time->text());
    Copy_INDL_List.replace(1, ui->INDL_balance->text());
    Copy_INDL_List.replace(2, QString::number(ui->Com_fre->currentIndex()));
    Copy_INDL_List.replace(3, QString::number(ui->Com_connetct->currentIndex()));
    Copy_INDL_List.replace(4, ui->INDL_Max->text());
    Copy_INDL_List.replace(5, ui->INDL_Min->text());
    Copy_INDL_List.replace(6, QString::number(ui->Com_test->currentIndex()));
    Copy_INDL_List.replace(7, ui->Q_balance->text());
    Copy_INDL_List.replace(8, QString::number(ui->Com_volt->currentIndex()));
    Copy_INDL_List.replace(10, QString::number(INDL_DoubleSpinBox[0]->value()));
    for (i = 0; i < 8; i++) {
        Copy_INDL_List.replace(INDL_init_Number + 20*i + 0, ui->indlTab->item(i, 1)->text());
        //  端子号
        Copy_INDL_List.replace(INDL_init_Number + 20*i + 1, ui->indlTab->item(i, 2)->text());
        Copy_INDL_List.replace(INDL_init_Number + 20*i + 2, ui->indlTab->item(i, 3)->text());
        //  电感上限 下限
        Copy_INDL_List.replace(INDL_init_Number + 20*i + 3, ui->indlTab->item(i, 4)->text());
        Copy_INDL_List.replace(INDL_init_Number + 20*i + 4, ui->indlTab->item(i, 5)->text());
        //  Q值上限 下限
        Copy_INDL_List.replace(INDL_init_Number + 20*i + 5, ui->indlTab->item(i, 6)->text());
        Copy_INDL_List.replace(INDL_init_Number + 20*i + 6, ui->indlTab->item(i, 7)->text());
        //  标准电感
        Copy_INDL_List.replace(INDL_init_Number + 20*i + 9, ui->indlTab->item(i, 8)->text());
        //  补偿
        Copy_INDL_List.replace(INDL_init_Number + 20*i + 10, ui->indlTab->item(i, 9)->text());
        //  补偿
        Copy_INDL_List.replace(INDL_init_Number + 20*i + 8, \
                               QString::number(Box_INDL_Grade_List.at(i)->checkState()));
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.5.19
  * brief:      设置警告弹出框
******************************************************************************/
void Widget_INDL::Pri_Pwr_WMessage(QString Waring_Text)
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
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.11.5
  * brief:      Conf 配置 INDL 界面
******************************************************************************/
void Widget_INDL::Pub_Conf_Set_INDL(QString str, int value, int flag)
{
    switch (flag) {
    case 1:
        Pri_INDL_Init();
        break;
    case 2:
        Pri_INDL_Data_Save();
        break;
    case 3:
        Pri_INDL_Test_Parameter();
        break;
    case 4:
        Pri_INDL_Test_Start(value);
        break;
    case 6:
        Pri_INDL_Default_value(str);
        break;
    case 7:
        Pri_INDL_Auto_Set(str, value);
        break;
    case 8:
        Pri_INDL_Quiky_Test_Parameter();
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
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.11.5
  * brief:      INDL界面, 单位自动设定
******************************************************************************/
void Widget_INDL::Pri_INDL_Auto_Set(QString str, int value)
{
    if ((str.toDouble() > 1000) && (str.toDouble() < 10000000)) { //  单位设置 mH
        if (ui->indlTab->item(value-1, 10)->text() != "mH") {
            on_indlTab_cellClicked(value-1, 10);
        }
        ui->indlTab->item(value - 1, 7)->setText(QString::number(str.toDouble()/1000));
        on_Button_Auto_clicked();
    } else if ((str.toDouble() < 1000)&&(str.toDouble() > 0)) { //  单位设置 uH
        if (ui->indlTab->item(value-1, 10)->text() != "uH") {
            on_indlTab_cellClicked(value-1, 10);
        }
        ui->indlTab->item(value-1, 7)->setText(str);
        on_Button_Auto_clicked();
    } else {
        //
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.11.5
  * brief:      INDL界面, 测试启动
******************************************************************************/
void Widget_INDL::Pri_INDL_Test_Start(int INDL_Station)
{
    frame.can_id  = 0x26;  frame.can_dlc = 0x08;
    frame.data[0] = 0x01;
    frame.data[1] = 0x00;
    frame.data[2] = 0x00;
    frame.data[3] = INDL_Station;
    frame.data[4] = INDL_TestItemsH;
    frame.data[5] = INDL_TestItemsL;
    frame.data[6] = 0x07;
    frame.data[7] = 0x08;
    canSend(frame);
    usleep(500);
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.11.5
  * brief:      INDL界面, 电感默认设置
******************************************************************************/
void Widget_INDL::Pri_INDL_Default_value(QString number)
{
    int i;
    ui->INDL_time->setValue(1);
    ui->Com_fre->setCurrentIndex(2);
    ui->Com_connetct->setCurrentIndex(0);
    ui->Com_test->setCurrentIndex(0);
    ui->INDL_Min->setValue(5);
    ui->INDL_Max->setValue(5);
    if (number.size() == 0) {
        return;
    } else {
        //
    }
    for (i = 0; i < 8; i++) {
        Box_INDL_Grade_List[i]->setChecked(false);
    }
    for (i = 0; i < number.size()/2; i++) {
        ui->indlTab->item(i, 1)->setText(number.mid(i*2, 1));
        ui->indlTab->item(i, 2)->setText(number.mid(i*2 + 1, 1));
        Box_INDL_Grade_List[i]->setChecked(true);
    }
//    ui->INDL_balance->setValue(0);
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.11.5
  * brief:      端点的选择
******************************************************************************/
void Widget_INDL::join_buttonJudge(int id)
{
    ui->dockWidget->hide();  INDL_Labelhide->hide();
    if (id != 9) {
        ui->indlTab->currentItem()->setText(QString::number(id));
    }
}
void Widget_INDL::INDL_NetData(QStringList list, QString str) {
    INDL_Init_Flag = true;
    int i;
    QStringList Volt_List;
    Volt_List.clear();
    Volt_List.append("2");
    Volt_List.append("0");
    Volt_List.append("1");
    if (str == QString(tr("test"))) {
        for (i = 0; i < 8; i++) {
            if (list.at(i).toInt() != 0) {
                Box_INDL_Grade_List[i]->setChecked(true);
            } else {
                Box_INDL_Grade_List[i]->setChecked(false);
            }
        }
    } else if (str == QString(tr("port1"))) {
        for (i = 0; i < 8; i++) {
            ui->indlTab->item(i, 1)->setText(list.at(i));
        }
    } else if (str == QString(tr("port2"))) {
        for (i = 0; i < 8; i++) {
             ui->indlTab->item(i, 2)->setText(list.at(i));
        }
    } else if (str == QString(tr("unit"))) {
        for (i = 0; i < 8; i++) {
            ui->indlTab->item(i, 10)->setText(INDL_Unit[list.at(i).toInt()]);
            Copy_INDL_List.replace(37+20*i, list.at(i));
        }
    } else if (str == QString(tr("min"))) {
        for (i = 0; i < 8; i++) {
             ui->indlTab->item(i, 3)->setText(list.at(i));
        }
    } else if (str == QString(tr("max"))) {
        for (i = 0; i < 8; i++) {
             ui->indlTab->item(i, 4)->setText(list.at(i));
        }
    } else if (str == QString(tr("qmin"))) {
        for (i = 0; i < 8; i++) {
             ui->indlTab->item(i, 5)->setText(list.at(i));
        }
    } else if (str == QString(tr("qmax"))) {
        for (i = 0; i < 8; i++) {
             ui->indlTab->item(i, 6)->setText(list.at(i));
        }
    } else if (str == QString(tr("std"))) {
        for (i = 0; i < 8; i++) {
             ui->indlTab->item(i, 7)->setText(list.at(i));
        }
    } else if (str == QString(tr("mode"))) {
        ui->INDL_time->setValue(list.at(0).toDouble());
        ui->Com_fre->setCurrentIndex(list.at(1).toInt());
        ui->Com_connetct->setCurrentIndex(list.at(2).toInt());
        ui->Com_test->setCurrentIndex(list.at(3).toInt());
        if (list.size() >= 5) {
            ui->Com_volt->setCurrentIndex(Volt_List.at(list.at(4).toInt()).toInt());
        }
    } else if (str == QString(tr("noun"))) {
        ui->INDL_balance->setValue(list.at(0).toDouble());
    } else if (str == QString(tr("wire_comp1"))) {
        for (i = 0; i < 8; i++) {
             ui->indlTab->item(i, 8)->setText(list.at(i));
        }
    } else if (str == QString(tr("wire_comp2"))) {
        for (i = 0; i < 8; i++) {
             ui->indlTab->item(i, 9)->setText(list.at(i));
        }
        Pri_INDL_Data_Save();
    } else {
        //
    }
    INDL_Init_Flag = false;
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.11.5
  * brief:      INDL界面, 电感界面单击
******************************************************************************/
void Widget_INDL::on_indlTab_cellClicked(int row,  int column)
{
    int number_column;
    ui->Key_1->show();
    ui->Key_2->show();
    ui->Key_3->show();
    ui->Key_4->show();
    ui->Key_5->show();
    ui->Key_6->show();
    ui->Key_7->show();
    ui->Key_8->show();

    if (Init_Channel_6) {
        ui->Key_7->hide();
        ui->Key_8->hide();
    } else {
        //
    }

    if (column == 1 || column == 2) {
        if (column == 1) {
            number_column = ui->indlTab->item(row, 2)->text().toInt();
            if ((number_column == 1) || (number_column == 4) || (number_column == 7)) {
                ui->Key_1->hide();   ui->Key_4->hide();   ui->Key_7->hide();
            } else if ((number_column == 2) || (number_column == 5) || (number_column == 8)) {
                ui->Key_2->hide();   ui->Key_5->hide();   ui->Key_8->hide();
            } else if ((number_column == 3) || (number_column == 6)) {
                ui->Key_3->hide();   ui->Key_6->hide();
            }
        } else if (column == 2) {
            number_column = ui->indlTab->item(row, 1)->text().toInt();
            if ((number_column == 1) || (number_column == 4) || (number_column == 7)) {
                ui->Key_1->hide();   ui->Key_4->hide();   ui->Key_7->hide();
            } else if ((number_column == 2) || (number_column == 5) || (number_column == 8)) {
                ui->Key_2->hide();   ui->Key_5->hide();   ui->Key_8->hide();
            } else if ((number_column == 3) || (number_column == 6)) {
                ui->Key_3->hide();   ui->Key_6->hide();
            }
        } else {
            //
        }

        INDL_Labelhide->show();
        ui->dockWidget->show();
        ui->dockWidget->raise();
    } else if (column == 10) {
        INDL_Init_Flag = true;
        int indlId = (Copy_INDL_List.at(INDL_init_Number + 20*row + 7).toInt() \
                      + 1)%INDL_Unit.size();
        Copy_INDL_List.replace(INDL_init_Number + 20*row + 7, QString::number(indlId));
        QTableWidgetItem *UnitItem = new QTableWidgetItem();  //    INDL_Unit[indlId]
        UnitItem->setTextAlignment(Qt::AlignCenter);
        UnitItem->setText(INDL_Unit[Copy_INDL_List.at(INDL_init_Number+20*row+7).toInt()]);
        UnitItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ui->indlTab->setItem(row, 10, UnitItem);
        if (indlId == 0) {      //  uH
            ui->indlTab->item(row, 7)->setText("200.0");
            ui->indlTab->item(row, 4)->setText("300.0");
            ui->indlTab->item(row, 3)->setText("100.0");
        } else if (indlId == 1) { //  mH
            ui->indlTab->item(row, 7)->setText("200.0");
            ui->indlTab->item(row, 4)->setText("300.0");
            ui->indlTab->item(row, 3)->setText("100.0");
        } else {
            //
        }
        //       else if (indlId == 2)  //  H
        //       {
        //           ui->indlTab->item(row, 7)->setText("2.000");
        //           ui->indlTab->item(row, 4)->setText("3.000");
        //           ui->indlTab->item(row, 3)->setText("1.000");
        //       }
        INDL_Init_Flag = false;
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.11.5
  * brief:      INDL界面, 输入完成规范设置
******************************************************************************/
void Widget_INDL::on_indlTab_cellChanged(int row,  int column)
{
    QString str;
    int i, After_Point = 0;
    if (INDL_Init_Flag) {
        return;
    }
    INDL_Init_Flag = true;
    if ((column == 3) || (column == 4) || (column == 5) || \
            (column == 6) || (column == 7) || (column == 8) || (column == 9)) {
        str = ui->indlTab->item(row, column)->text();
        if (str == NULL) {
            ui->indlTab->item(row, column)->setText("0");
        }
        for (i = 0; i < str.length(); i++) { // 判断输入是" 0-9 . "
            if (((str[i] >= '0') && (str[i] <= '9')) || \
                    (str[i] == '.') || (str[i] == '-')) {
                //
            } else {
                ui->indlTab->item(row, column)->setText("0");
                break;
            }
            if (str[i] == '.') { //   判断是否规范
                After_Point = str.length()-i-1;
                if ((i == 0)) {
                    ui->indlTab->item(row, column)->setText("0");
                }
                if (i == (str.length()-1)) {
                    ui->indlTab->item(row, column)->setText(ui->indlTab->item\
                                                            (row, column)->text().left(i));
                }
            }
        }
        if ((column == 3) || (column == 4) || (column == 7) || (column == 9)) {
            if (ui->indlTab->item(row, 10)->text() == "uH") {  //   单位是uH
                if (ui->indlTab->item(row, column)->text().toDouble() < 1000) {
                    ui->indlTab->item(row, column)->setText\
                            (QString::number(ui->indlTab->item\
                                             (row, column)->text().toDouble(), 'f', 1));
                } else {
                    ui->indlTab->item(row, column)->setText("999.9");
                }
            }
            if (ui->indlTab->item(row, 10)->text() == "mH") {  //   单位是mH
                if (ui->indlTab->item(row, column)->text().toDouble() < 10) {
                    ui->indlTab->item(row, column)->setText\
                            (QString::number(ui->indlTab->item\
                                             (row, column)->text().toDouble(), 'f', 3));
                } else if (ui->indlTab->item(row, column)->text().toDouble() < 100) {
                    ui->indlTab->item(row, column)->setText\
                            (QString::number(ui->indlTab->item\
                                             (row, column)->text().toDouble(), 'f', 2));
                } else if (ui->indlTab->item(row, column)->text().toDouble() < 1000) {
                    ui->indlTab->item(row, column)->setText\
                            (QString::number(ui->indlTab->item\
                                             (row, column)->text().toDouble(), 'f', 1));
                } else if (ui->indlTab->item(row, column)->text().toDouble() <= 10000) {
                    ui->indlTab->item(row, column)->setText\
                            (QString::number(ui->indlTab->item\
                                             (row, column)->text().toDouble(), 'f', 0));
                } else {
                    ui->indlTab->item(row, column)->setText("10000");
                }
            }
        }
        if ((column == 5) || (column == 6)) {
            if (ui->indlTab->item(row, column)->text().toDouble() == 0) {
                ui->indlTab->item(row, column)->setText("0.000");
            } else if (ui->indlTab->item(row, column)->text().toDouble() < 10) {
                ui->indlTab->item(row, column)->setText\
                        (QString::number(ui->indlTab->item\
                                         (row, column)->text().toDouble(), 'f', 3));
            } else if (ui->indlTab->item(row, column)->text().toDouble() < 100) {
                ui->indlTab->item(row, column)->setText\
                        (QString::number(ui->indlTab->item\
                                         (row, column)->text().toDouble(), 'f', 2));
            } else if (ui->indlTab->item(row, column)->text().toDouble() < 1000) {
                ui->indlTab->item(row, column)->setText\
                        (QString::number(ui->indlTab->item\
                                         (row, column)->text().toDouble(), 'f', 1));
            } else if (ui->indlTab->item(row, column)->text().toDouble() < 10000)  {
                ui->indlTab->item(row, column)->setText\
                        (QString::number(ui->indlTab->item\
                                         (row, column)->text().toDouble(), 'f', 0));
            } else {
                ui->indlTab->item(row, column)->setText("9999");
            }
        }
        if ((column == 3) || (column == 4)) {
            if ((ui->indlTab->item(row, 3)->text().toDouble()) > \
                    (ui->indlTab->item(row, 4)->text().toDouble())) {
                ui->indlTab->item(row, 3)->setText("0.0");
            }
        }
        if ((column == 5) || (column == 6)) {
            if ((ui->indlTab->item(row, 5)->text().toDouble()) > \
                    (ui->indlTab->item(row, 6)->text().toDouble())) {
                ui->indlTab->item(row, 5)->setText("0.000");
            }
        }
        if ((row == 0) && (column == 8)) {
            for (i = 1; i <= 7; i++) {
                ui->indlTab->item(i, column)->setText(ui->indlTab->item(0, column)->text());
            }
        }
//        if ((row == 0) && (column == 9)) {
//            for (i = 1; i <= 7; i++) {
//                ui->indlTab->item(i, column)->setText(ui->indlTab->item(0, column)->text());
//            }
//        }
    }
    INDL_Init_Flag = false;
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.11.5
  * brief:      INDL界面, 电感自动计算
******************************************************************************/
void Widget_INDL::on_Button_Auto_clicked()
{
    int i;
    INDL_Init_Flag = true;
    for (i = 0; i < 8; i++) {  //   电感测试项目 8项
        if (Box_INDL_Grade_List[i]->checkState() != 2) {
            continue;
        }
        if (ui->indlTab->item(i, 10)->text() == "uH") {
            if (ui->indlTab->item(i, 7)->text().toDouble()*(100 + \
                                        ui->INDL_Min->text().toInt())/100 > 1000) {
                ui->indlTab->item(i, 4)->setText("999.9");
            } else {
                ui->indlTab->item(i, 4)->setText\
                        (QString::number(ui->indlTab->item(i, 7)->text().toDouble()*(100 + \
                                     ui->INDL_Min->text().toInt())/100, 'f', 1));
            }
            ui->indlTab->item(i, 3)->setText\
                    (QString::number(ui->indlTab->item(i, 7)->text().toDouble()*(100 - \
                                             ui->INDL_Max->text().toInt())/100, 'f', 1));
        } else if (ui->indlTab->item(i, 10)->text() == "mH") {
            if (ui->indlTab->item(i, 7)->text().toDouble() * \
                    (100 + ui->INDL_Min->text().toInt())/100 < 10) {
                ui->indlTab->item(i, 4)->setText\
                        (QString::number(ui->indlTab->item(i, 7)->text().toDouble() * \
                                         (100+ui->INDL_Min->text().toInt())/100, 'f', 3));
            } else if (ui->indlTab->item(i, 7)->text().toDouble() * \
                       (100+ui->INDL_Min->text().toInt())/100 < 100) {
                ui->indlTab->item(i, 4)->setText\
                        (QString::number(ui->indlTab->item(i, 7)->text().toDouble() * \
                                         (100+ui->INDL_Min->text().toInt())/100, 'f', 2));
            } else if (ui->indlTab->item(i, 7)->text().toDouble() * \
                       (100+ui->INDL_Min->text().toInt())/100 < 1000) {
                ui->indlTab->item(i, 4)->setText\
                        (QString::number(ui->indlTab->item(i, 7)->text().toDouble() * \
                                         (100+ui->INDL_Min->text().toInt())/100, 'f', 1));
            } else if (ui->indlTab->item(i, 7)->text().toDouble() * \
                       (100+ui->INDL_Min->text().toInt())/100 <= 10000) {
                ui->indlTab->item(i, 4)->setText\
                        (QString::number(ui->indlTab->item(i, 7)->text().toDouble() * \
                                         (100+ui->INDL_Min->text().toInt())/100, 'f', 0));
            } else {
                ui->indlTab->item(i, 4)->setText("10000");
            }

            if (ui->indlTab->item(i, 7)->text().toDouble() * \
                    (100 - ui->INDL_Min->text().toInt())/100 < 10) {
                ui->indlTab->item(i, 3)->setText\
                        (QString::number(ui->indlTab->item(i, 7)->text().toDouble() * \
                                         (100 - ui->INDL_Max->text().toInt())/100, 'f', 3));
            } else if (ui->indlTab->item(i, 7)->text().toDouble() * \
                     (100 - ui->INDL_Min->text().toInt())/100 < 100) {
                ui->indlTab->item(i, 3)->setText\
                        (QString::number(ui->indlTab->item(i, 7)->text().toDouble() * \
                                         (100 - ui->INDL_Max->text().toInt())/100, 'f', 2));
            } else if (ui->indlTab->item(i, 7)->text().toDouble() * \
                     (100 - ui->INDL_Min->text().toInt())/100 < 1000) {
                ui->indlTab->item(i, 3)->setText\
                        (QString::number(ui->indlTab->item(i, 7)->text().toDouble() * \
                                         (100 - ui->INDL_Max->text().toInt())/100, 'f', 1));
            } else if (ui->indlTab->item(i, 7)->text().toDouble() * \
                     (100-  ui->INDL_Min->text().toInt())/100 <= 10000) {
                ui->indlTab->item(i, 3)->setText\
                        (QString::number(ui->indlTab->item(i, 7)->text().toDouble() * \
                                         (100 - ui->INDL_Max->text().toInt())/100, 'f', 0));
            } else {
                ui->indlTab->item(i, 3)->setText("10000");
            }
        } else {
            //
        }
    }
    INDL_Init_Flag = false;
}

void Widget_INDL::on_INDL_Min_editingFinished()
{
    ui->INDL_Max->setValue(ui->INDL_Min->value());
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.5.19
  * brief:      设置警告弹出框  电感
******************************************************************************/
void Widget_INDL::Pri_INDL_WMessage(QString Waring_Text)
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
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.11.5
  * brief:      INDL界面, 电感通道清零
******************************************************************************/
void Widget_INDL::on_Button_Comp_clicked()
{
    QMessageBox message;
    message.setWindowFlags(Qt::FramelessWindowHint);
    message.setStyleSheet\
            ("QMessageBox{border:3px groove gray;}background-color: rgb(209,  209,  157);");
    message.setText(tr("      请将清零的端子短接    \n      然后继续操作      "));
    message.addButton(QMessageBox::Ok)->setStyleSheet\
            ("border:none;height:30px;width:65px;border:5px groove gray;"\
             "border-radius:10px;padding:2px 4px;");
    message.addButton(QMessageBox::Cancel)->setStyleSheet\
            ("border:none;height:30px;width:65px;border:5px groove gray;"\
             "border-radius:10px;padding:2px 4px;");
    message.setButtonText(QMessageBox::Ok, QString(tr("确 定")));
    message.setButtonText(QMessageBox::Cancel, QString(tr("取 消")));
    message.setIcon(QMessageBox::Warning);
    int ret = message.exec();
    if (ret == QMessageBox::Ok) {
        Pri_INDL_Calibration_clear();
        Lable_Display();
    }
    if (ret == QMessageBox::Cancel) {
        //
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.11.5
  * brief:      INDL界面, 电感通道清零，下发参数
******************************************************************************/
void Widget_INDL::Pri_INDL_Calibration_clear()
{
    int i;
    int INDL_Zero_TestItemsL = 0;
    for (i = 0; i < 8; i++) {
        if (Box_INDL_Grade_List.at(i)->checkState() != 2) {
            continue;
        }
        frame.can_id = 0x26;  frame.can_dlc = 0x07;
        frame.data[0] = 0x03;
        frame.data[1] = i;
        frame.data[2] = ui->indlTab->item(i, 1)->text().toInt();  //  抽头
        frame.data[3] = ui->indlTab->item(i, 2)->text().toInt();
        frame.data[4] = 0x01;
        if (ui->Com_fre->currentText() == "1K") {       //  frame.data[5]  频率 电压  档位
            frame.data[5] = 0x0b;
        } else {
            frame.data[5] = 0x0c;
        }

        int connetct;                               //   frame.data[6]  连接方式 电压增益 电流增益
        if (ui->Com_connetct->currentText() == QString(tr("串联"))) {
            connetct = 0x00;
        } else {
            connetct = 0x40;
        }
        if (ui->indlTab->item(i, 10)->text() == "mH") {
            frame.data[6] = (connetct|0x09);
        } else {
            if (ui->indlTab->item(i, 4)->text().toDouble() < 500) {
                frame.data[6] = (connetct|0x0f);
            } else {
                frame.data[6] = (connetct|0x09);
            }
        }
        INDL_Zero_TestItemsL = 1 << i;       //   低字节
        canSend(frame);
        usleep(500);
        break;  //   勾选第一个进行
    }

    if (INDL_Zero_TestItemsL != 0) {
        frame.can_id = 0x26;  frame.can_dlc = 0x08;
        frame.data[0] = 0x01;
        frame.data[1] = 0x00;
        frame.data[2] = 0x01;
        frame.data[3] = 0x13;
        frame.data[4] = 0x00;
        frame.data[5] = INDL_Zero_TestItemsL;   //   低字节
        frame.data[6] = 0x07;
        frame.data[7] = 0x08;
        canSend(frame);
        usleep(500);
    }
}
QStringList Widget_INDL::INDL_Test_Param()
{
    QString str;
    QStringList strSql;
    QStringList strParam, strTest;
    strTest.clear();
    strParam.clear();
    QStringList  indl_unit;
    indl_unit.clear();  indl_unit << "u" << "m";         //  << "H"

    for (int j = 0; j < 8; j++) {
        if (Box_INDL_Grade_List[j]->checkState() != 2) { //   电感
            continue;
        }
        if (Copy_INDL_List[7] == "0.0") {
            str = QString(tr("电感"))+ Copy_INDL_List.at(INDL_init_Number+20*j+0) + "-" + \
                    Copy_INDL_List.at(INDL_init_Number+20*j+1);       //   电参
            strTest.append(str);   str.clear();
            str = Copy_INDL_List.at(INDL_init_Number+20*j+2) + \
                    indl_unit[Copy_INDL_List.at(INDL_init_Number+20*j+7).toInt()] + "-" + \
                    Copy_INDL_List.at(INDL_init_Number+20*j+3) + \
                    indl_unit[Copy_INDL_List.at(INDL_init_Number+20*j+7).toInt()];
            strParam.append(str);  str.clear();
            strSql.append(tr("电感"));
        } else if (Copy_INDL_List[7] == "0.000") {
            str = QString(tr("电感"))+ Copy_INDL_List.at(INDL_init_Number+20*j+0) + "-" + \
                    Copy_INDL_List.at(INDL_init_Number+20*j+1);       //   电参
            strTest.append(str);   str.clear();
            str = Copy_INDL_List.at(INDL_init_Number+20*j+2) + \
                    indl_unit[Copy_INDL_List.at(INDL_init_Number+20*j+7).toInt()] + "-" + \
                    Copy_INDL_List.at(INDL_init_Number+20*j+3) + \
                    indl_unit[Copy_INDL_List.at(INDL_init_Number+20*j+7).toInt()];
            strParam.append(str);  str.clear();
            strSql.append(tr("电感"));
        } else {
            str = QString(tr("电感")) + Copy_INDL_List.at(INDL_init_Number+20*j+0) + "-" \
                    + Copy_INDL_List.at(INDL_init_Number+20*j+1);       //   电参
            strTest.append(str);
            str.clear();
            //  indl_unit[Copy_INDL_List.at(INDL_init_Number+20*j+7).toInt()] +
            str =  Copy_INDL_List.at(INDL_init_Number+20*j+2) + "-" + \
                    Copy_INDL_List.at(INDL_init_Number+20*j+3) + \
                    indl_unit[Copy_INDL_List.at(INDL_init_Number+20*j+7).toInt()] +", Q-";
            str += Copy_INDL_List.at(INDL_init_Number+20*j+4) + "-" + \
                    Copy_INDL_List.at(INDL_init_Number+20*j+5);
            strParam.append(str);  str.clear();
            strSql.append(tr("电感"));
        }
    }
    if (Copy_INDL_List.at(10).toInt() == 1) {
        if (INDL_TestNumber >= 3) {
            if (Copy_INDL_List[1] == "0.000") {
                //
            } else if (Copy_INDL_List[1] == "0.0") {
                //
            } else {
                strTest.append(QString(tr("电感")));
                strParam.append(QString(tr("不平衡度 ")) + Copy_INDL_List[1] + "%");
                strSql.append(tr("电感"));
            }
        }
    }  else if (Copy_INDL_List.at(10).toInt() == 2) {
        if ((Copy_INDL_List.at(1) != "0.000") && (INDL_TestNumber >= 2)) {
            strTest.append(QString(tr("电感")));
            strParam.append(QString(tr("不平衡度 ")) + Copy_INDL_List.at(1) + "%");
            strSql.append(tr("电感"));
        }   //-将(-电感-)修改为(电感)
    } else if (Copy_INDL_List.at(10).toInt() == 3) {
        if ((Copy_INDL_List.at(1) != "0.000") && (INDL_TestNumber >= 2)) {
            strTest.append(QString(tr("电感")));
            strParam.append(QString(tr("不平衡度 ")) + Copy_INDL_List.at(1));
            strSql.append(tr("电感"));
        }   //-将(-电阻-)修改为(电阻)
    } else if (Copy_INDL_List.at(10).toInt() == 0) {
        if (INDL_TestNumber >= 3) {
            if (Copy_INDL_List[1] == "0.000") {
                //
            } else if (Copy_INDL_List[1] == "0.0") {
                //
            } else {
                strTest.append(QString(tr("电感")));
                strParam.append(QString(tr("不平衡度 ")) + Copy_INDL_List[1] + "%");
                strSql.append(tr("电感"));
            }
        }
    } else {
        //
    } // -将(-电感-)修改为(电感)

    if (INDL_TestNumber >= 3) {
        if (Copy_INDL_List[7] == "0.000") {
            //
        } else if (Copy_INDL_List[7] == "0.0") {
            //
        } else {
            strTest.append(QString(tr("Q值")));
            strParam.append(QString(tr("不平衡度 ")) + Copy_INDL_List[7] + "%");
            strSql.append(tr("电感"));
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
void Widget_INDL::on_button_model_clicked()
{
    INDL_Widget->show();
}
