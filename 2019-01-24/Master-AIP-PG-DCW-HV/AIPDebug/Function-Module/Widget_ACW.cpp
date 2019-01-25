/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "Widget_ACW.h"
#include "ui_Widget_ACW.h"

Widget_ACW::Widget_ACW(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_ACW) {
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint); // 去掉标题栏
    ui->setupUi(this);

    ui->acwTab->horizontalHeader()->setStyleSheet\
            ("QHeaderView::section{background-color:#191919;color: white;"\
             "padding-left: 4px;border: 1px solid #447684;}");
    ui->acwTab->horizontalHeader()->setFixedHeight(35);
    ui->acwTab->horizontalHeader()->setResizeMode(QHeaderView::Fixed);
    ui->acwTab->setColumnWidth(0, 41);  //  设置长度
    ui->acwTab->setColumnWidth(1, 60);
    ui->acwTab->setColumnWidth(2, 90);
    ui->acwTab->setColumnWidth(3, 68);
    ui->acwTab->setColumnWidth(4, 74);
    ui->acwTab->setColumnWidth(5, 72);
    ui->acwTab->setColumnWidth(6, 60);
    ui->acwTab->setColumnWidth(7, 60);
    ui->acwTab->setColumnWidth(8, 60);
    ui->acwTab->setColumnWidth(9, 60);
     // ui->acwTab->setColumnWidth(10, 47);

    ACW_btnGroup = new QButtonGroup;
    ACW_btnGroup->addButton(ui->OK, 1);
    connect(ACW_btnGroup, SIGNAL(buttonClicked(int)), this, SLOT(join_buttonJudge(int)));
    ui->OK->hide();

    Box_All_List.clear();
    Box_All_List.append(ui->checkBox_1);  //  1
    Box_All_List.append(ui->checkBox_2);
    Box_All_List.append(ui->checkBox_3);
    Box_All_List.append(ui->checkBox_4);
    Box_All_List.append(ui->checkBox_5);
    Box_All_List.append(ui->checkBox_6);
    Box_All_List.append(ui->checkBox_7);
    Box_All_List.append(ui->checkBox_8);
    Box_All_List.append(ui->checkBox_9);   //  PE
    Box_All_List.append(ui->checkBox_10);  //  ALL

    ui->checkBox_1->hide();
    ui->checkBox_2->hide();
    ui->checkBox_3->hide();
    ui->checkBox_4->hide();
    ui->checkBox_5->hide();
    ui->checkBox_6->hide();
    ui->checkBox_7->hide();
    ui->checkBox_8->hide();
    ui->checkBox_9->hide();
    ui->checkBox_10->hide();

    ACW_Labelhide = new QLabel(this);
    ACW_Labelhide->setGeometry(0, 0, 800, 600);
    ACW_Labelhide->hide();

    ui->acwTab->move(0, 110);
    ui->acwTab->hide();
    ui->widget->move(90, 140);
    ui->widget->hide();
    ui->dockwidget->move(190, 0);

    ACW_Test_Total = 0;
    ACW_Between_IR = false;
    Init_Flag = false;
    Init_Channel_6 = false;
    volt_set = 3000;
    ui->doubleSpinBox_Compensate->setDisabled(true);
    set_i_up = 20.00;
    Line_HV = false;
    Line_HV_High = "";
    Line_HV_Low = "";
}

Widget_ACW::~Widget_ACW()
{
    delete ui;
}

/******************************************************************************
  * version:    1.0
  * author:     jeremy
  * date:       2017.2.24
  * brief:      初始化相耐设置
******************************************************************************/
void Widget_ACW::Pri_ACW_Init(QString str)
{
    int i;
    Init_Flag = true;
    ui->acwTab->setRowCount(4);  // -设置行数
    ui->acwTab->setColumnCount(11);  // -设置列数

    freq.clear();     freq << "50" << "60";  // -設置頻率
    ACW_Between_IR = str.toInt();
    if (ACW_Between_IR) {
        ui->acwTab->show();     ui->acwTab->raise();
        ui->widget->hide();
    } else {
        ui->widget->show();     ui->widget->raise();
        ui->acwTab->hide();
    }

    ACW_T1_List.clear();
    ACW_T2_List.clear();
    ACW_voltage.clear();
    ACW_I_Max.clear();
    ACW_I_Min.clear();
    ACW_ARC.clear();
    ACW_time.clear();
    ACW_compensate.clear();
    Box_ACW_list.clear();
    for (i = 0; i < 4; i++) {
         // 初始化输入框
        QTableWidgetItem *number = new QTableWidgetItem;
        number->setTextAlignment(Qt::AlignCenter);
        number->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        number->setText(QString::number((i + 1)));
        ui->acwTab->setItem(i, 0, number);

        ACW_T1_List.append(new QTableWidgetItem);
        ACW_T1_List[i]->setTextAlignment(Qt::AlignCenter);
        ACW_T1_List[i]->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ACW_T1_List[i]->setText(Copy_ACW_List.at(30+i*16));
        ui->acwTab->setItem(i, 1, ACW_T1_List[i]);

        ACW_T2_List.append(new QTableWidgetItem);
        ACW_T2_List[i]->setTextAlignment(Qt::AlignCenter);
        ACW_T2_List[i]->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ACW_T2_List[i]->setText(Copy_ACW_List.at(31+i*16));
        ui->acwTab->setItem(i, 2, ACW_T2_List[i]);

        ACW_voltage.append(new QTableWidgetItem);
        ACW_voltage[i]->setTextAlignment(Qt::AlignCenter);
        ACW_voltage[i]->setText(Copy_ACW_List.at(32+i*16));
        ui->acwTab->setItem(i, 3, ACW_voltage[i]);

        ACW_I_Min.append(new QTableWidgetItem);
        ACW_I_Min[i]->setTextAlignment(Qt::AlignCenter);
        ACW_I_Min[i]->setText(Copy_ACW_List.at(33+i*16));
        ui->acwTab->setItem(i, 4, ACW_I_Min[i]);

        ACW_I_Max.append(new QTableWidgetItem);
        ACW_I_Max[i]->setTextAlignment(Qt::AlignCenter);
        ACW_I_Max[i]->setText(Copy_ACW_List.at(34+i*16));
        ui->acwTab->setItem(i, 5, ACW_I_Max[i]);

        ACW_ARC.append(new QTableWidgetItem);
        ACW_ARC[i]->setTextAlignment(Qt::AlignCenter);
        ACW_ARC[i]->setText(Copy_ACW_List.at(35+i*16));
        ui->acwTab->setItem(i, 6, ACW_ARC[i]);

        ACW_time.append(new QTableWidgetItem);
        ACW_time[i]->setTextAlignment(Qt::AlignCenter);
        ACW_time[i]->setText(Copy_ACW_List.at(36+i*16));
        ui->acwTab->setItem(i, 7, ACW_time[i]);


        QTableWidgetItem *ACW_freq = new QTableWidgetItem;
        ACW_freq->setTextAlignment(Qt::AlignCenter);
        ACW_freq->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ACW_freq->setText(freq[Copy_ACW_List.at(10).toInt()]);
        ui->acwTab->setItem(i, 8, ACW_freq);

        ACW_compensate.append(new QTableWidgetItem);
        ACW_compensate[i]->setTextAlignment(Qt::AlignCenter);
         //       ACW_compensate[i]->setText("*");
        ACW_compensate[i]->setText(Copy_ACW_List.at(37+i*16));
        ui->acwTab->setItem(i, 9, ACW_compensate[i]);


        Box_ACW_list.append(new QCheckBox);
        Box_ACW_list[i]->setStyleSheet\
                ("QCheckBox::indicator {image: url(:/image/053.png);width: 50px;"\
                 "height: 55px;}QCheckBox::indicator:checked {image: url(:/image/051.png);}");
        if (Copy_ACW_List.at(40+i*16).toInt() == 2) {
            Box_ACW_list[i]->setChecked(true);
        }
        ui->acwTab->setRowHeight(i, 70);
        ui->acwTab->setCellWidget(i, 10, Box_ACW_list[i]);
    }

    ui->double_Volt->setMaximum(volt_set);  //  500-5000 V
    ui->double_Volt->setMinimum(500);
    ui->double_Volt->setDecimals(0);
    ui->double_Volt->setValue(Copy_ACW_List.at(20).toDouble());

    ui->double_Time->setMaximum(999.9);  //  0.5-999.9 S
    ui->double_Time->setMinimum(0.5);
    ui->double_Time->setDecimals(1);
    ui->double_Time->setValue(Copy_ACW_List.at(21).toDouble());

    ui->double_I_Down->setMaximum(20.00);  //  0-2000V mA
    ui->double_I_Down->setMinimum(0);
    ui->double_I_Down->setDecimals(2);
    ui->double_I_Down->setValue(Copy_ACW_List.at(23).toDouble());

    ui->double_I_Up->setMaximum(20.00);  //  10-2000 mA
    ui->double_I_Up->setMinimum(0.10);
    ui->double_I_Up->setDecimals(2);
    ui->double_I_Up->setValue(Copy_ACW_List.at(24).toDouble());

    ui->comb_ARC->setCurrentIndex(Copy_ACW_List[0].toInt());
    ui->comb_Freq->setCurrentIndex(Copy_ACW_List[1].toInt());

    ACW_Compensate_Flag = Copy_ACW_List.at(2).toInt();
    if (ACW_Compensate_Flag) {
        ui->doubleSpinBox_Compensate->setValue(Copy_ACW_List.at(3).toDouble());
        ACW_Compensate_Result = Copy_ACW_List.at(3).toDouble();
    }
    for (i = 0; i < Box_All_List.size(); i++) {
        if (Copy_ACW_List.at(i).toInt() == 2) {
            Box_All_List.at(i)->setChecked(true);
        }
    }
    Init_Flag = false;
}

void Widget_ACW::mousePressEvent(QMouseEvent *event)  // 处理鼠标被按下事件
{
    if ((ui->acwTab->currentColumn() == 1) || \
            (ui->acwTab->currentColumn() == 2)) {
        ui->dockwidget->hide();   ACW_Labelhide->hide();
    }
}
/******************************************************************************
  * version:    1.0
  * author:     jeremy
  * date:       2017.3.1
  * brief:      OK按键槽函数
******************************************************************************/
void Widget_ACW::join_buttonJudge(int test_key)
{
    int i;
    QStringList check;
    QString sendcheck;
    ui->dockwidget->hide();  ACW_Labelhide->hide();
    for (i = 0; i < Box_All_List.size()-2; i++) {
        if (Box_All_List.at(i)->checkState() == 2) {
            check.append(QString::number(i+1));
            sendcheck = check.join("");
        }
    }
    if (Box_All_List.at(9)->checkState() == 2) {
        ui->acwTab->currentItem()->setText("12345678");
    } else if (Box_All_List[8]->checkState() == 2) {
        ui->acwTab->currentItem()->setText("PE");
    } else {
        if (sendcheck == tr("")) {
            ui->acwTab->currentItem()->setText("1");
        } else {
            ui->acwTab->currentItem()->setText(sendcheck);
        }
    }
    test_key = 0;
}

/******************************************************************************
  * version:    1.0
  * author:     jeremy
  * date:       2017.3.9
  * brief:      测试位状态判断
******************************************************************************/
void Widget_ACW::box_statechange()
{
    int i, j;
    for (i = 0; i < 4; i++) {
        if (Copy_ACW_List.at(40 + i*16).toInt() != 2) {
            continue;
        }
        for (j = 0; j < 7; j++) {
            if (Copy_ACW_List.at(31 + i*16).mid(j, 1) == "") {
                break;
            }

            if ((Copy_ACW_List.at(31 + i*16).mid(j, 1).toInt()) == \
                    (Copy_ACW_List.at(30 + i*16).mid(0, 1).toInt())) {
                Pri_ACW_WMessage(tr("       输入错误，端点有重合       "));
                ui->acwTab->item(i, 1)->setText("1");
                ui->acwTab->item(i, 2)->setText("2");
                break;
            } else if ((Copy_ACW_List.at(31 + i*16).mid(j, 1).toInt()) == \
                     (Copy_ACW_List.at(30 + i*16).mid(1, 1).toInt())) {
                Pri_ACW_WMessage(tr("       输入错误，端点有重合       "));
                ui->acwTab->item(i, 1)->setText("1");
                ui->acwTab->item(i, 2)->setText("2");
                break;
            } else if ((Copy_ACW_List.at(31 + i*16).mid(j, 1).toInt()) == \
                     (Copy_ACW_List.at(30 + i*16).mid(2, 1).toInt())) {
                Pri_ACW_WMessage(tr("       输入错误，端点有重合       "));
                ui->acwTab->item(i, 1)->setText("1");
                ui->acwTab->item(i, 2)->setText("2");
                break;
            }
        }
    }
}
/******************************************************************************
  * version:    1.0
  * author:     jeremy
  * date:       2017.3.1
  * brief:      保存相耐配置
******************************************************************************/
void Widget_ACW::Pri_ACW_Save_Data()
{
    int i;
     // 更新相间交耐数据
    if (ACW_Between_IR) {
        for (i = 0; i < 4; i++) {
            Copy_ACW_List.replace(30+i*16, (ui->acwTab->item(i, 1)->text()));
            Copy_ACW_List.replace(31+i*16, (ui->acwTab->item(i, 2)->text()));
            Copy_ACW_List.replace(32+i*16, (ACW_voltage[i]->text()));
            Copy_ACW_List.replace(33+i*16, (ACW_I_Min[i]->text()));
            Copy_ACW_List.replace(34+i*16, (ACW_I_Max[i]->text()));
            Copy_ACW_List.replace(35+i*16, (ACW_ARC[i]->text()));
            Copy_ACW_List.replace(36+i*16, (ACW_time[i]->text()));
            Copy_ACW_List.replace(37+i*16, (ACW_compensate[i]->text()));
            Copy_ACW_List.replace(40+i*16, QString::number(Box_ACW_list.at(i)->checkState()));
        }
    } else {
         // 更新普通交耐数据
        if (ui->label_ACW_Param->text() == "ACW-1") {
            Copy_ACW_List.replace(20, ui->double_Volt->text());
            Copy_ACW_List.replace(21, ui->double_Time->text());
            Copy_ACW_List.replace(23, ui->double_I_Down->text());
            Copy_ACW_List.replace(24, ui->double_I_Up->text());
            Copy_ACW_List.replace(0, QString::number(ui->comb_ARC->currentIndex()));
            Copy_ACW_List.replace(1, QString::number(ui->comb_Freq->currentIndex()));
        } else {
            Copy_ACW_List.replace(25, ui->double_Volt->text());
            Copy_ACW_List.replace(26, ui->double_Time->text());
            Copy_ACW_List.replace(28, ui->double_I_Down->text());
            Copy_ACW_List.replace(29, ui->double_I_Up->text());
            Copy_ACW_List.replace(4, QString::number(ui->comb_ARC->currentIndex()));
            Copy_ACW_List.replace(5, QString::number(ui->comb_Freq->currentIndex()));
        }

    }
    if (ACW_Compensate_Flag) { // -补偿后进行修改数值
        if (ui->label_ACW_Param->text() == "ACW-1") {
            Copy_ACW_List.replace(3, QString::number(ui->doubleSpinBox_Compensate->value(), 'f', 2));
            ui->doubleSpinBox_Compensate->setValue(Copy_ACW_List.at(3).toDouble());
        } else {
            Copy_ACW_List.replace(7, QString::number(ui->doubleSpinBox_Compensate->value(), 'f', 2));
            ui->doubleSpinBox_Compensate->setValue(Copy_ACW_List.at(7).toDouble());
        }

    }
}

/******************************************************************************
  * version:    1.0
  * author:     jeremy
  * date:       2017.3.1
  * brief:      QTableWidget表点击槽函数
******************************************************************************/
void Widget_ACW::on_acwTab_cellClicked(int row,  int column)
{
    int i,  acwId;
    if (column  ==  1 || column  ==  2) {
        for (i = 0; i < Box_All_List.size(); i++) {
            Box_All_List[i]->setChecked(false);
        }
        if (column  ==  1) {
            ui->checkBox_1->show();  ui->checkBox_2->hide();  ui->checkBox_3->hide();
            ui->checkBox_4->show();  ui->checkBox_5->hide();  ui->checkBox_6->hide();
            ui->checkBox_7->show();  ui->checkBox_8->hide();
            ui->checkBox_9->show();  ui->checkBox_10->hide();
            ui->OK->show();
        } else if (column  ==  2) {
            ui->checkBox_1->show();  ui->checkBox_2->show();  ui->checkBox_3->show();
            ui->checkBox_4->show();  ui->checkBox_5->show();  ui->checkBox_6->show();
            ui->checkBox_7->show();  ui->checkBox_8->show();
            ui->checkBox_9->hide();   ui->checkBox_10->hide();
            ui->OK->show();
        }
        if (Init_Channel_6) {
            ui->checkBox_7->hide();
            ui->checkBox_8->hide();
        } else {
            //
        }
        ACW_Labelhide->show();
        ui->dockwidget->show();
        ui->dockwidget->raise();
    } else if (column  ==  8) {
        acwId = (Copy_ACW_List[10].toInt()+1)%freq.size();
        for (i = 0; i < 4; i++) {
            QTableWidgetItem *ACW_freq = new QTableWidgetItem;
            Copy_ACW_List.replace(10, QString::number(acwId));
            ACW_freq->setTextAlignment(Qt::AlignCenter);
            ACW_freq->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            ACW_freq->setText(freq[Copy_ACW_List.at(10).toInt()]);
            ui->acwTab->setItem(i, 8, ACW_freq);
        }
        ui->acwTab->setEditTriggers(QAbstractItemView::AllEditTriggers);
    }
    row = 0;
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.5.16
  * brief:      进行端子有无重合的判定
******************************************************************************/
bool Widget_ACW::Pri_ACW_T1T2_Judge(QString T1, QString T2)
{
    for (int i = 0; i < T1.length(); i++) {
        for (int j = 0; j < T2.length(); j++) {
            if (T1.mid(i, 1).toInt() == T2.mid(j, 1).toInt()) {
                return true;
            }
        }
    }
    return false;
}
/******************************************************************************
  * version:    1.0
  * author:     jeremy
  * date:       2017.3.1
  * brief:      QTableWidget表改变数值槽函数
******************************************************************************/
void Widget_ACW::on_acwTab_cellChanged(int row,  int column)
{
    int i, j;
    int After_Point = 0;
    QString str;
    if (Init_Flag) { // -初始化ing
        return;
    } else {
        Init_Flag = true;
    }

    if (column  ==  1 || column  ==  2) {
        if (Pri_ACW_T1T2_Judge(ui->acwTab->item(row,  1)->text(), \
                               ui->acwTab->item(row,  2)->text())) {
            ui->acwTab->item(row,  1)->setText("1");
            ui->acwTab->item(row,  2)->setText("2");
            Pri_ACW_WMessage(tr("       输入错误，端点有重合       "));
        } else {
            //
        }
    } else if ((column  ==  3) || (column  ==  4) || \
             (column  ==  5) || (column  ==  6) || \
             (column  ==  7) || (column  ==  9)) {
        str = ui->acwTab->item(row,  column)->text();
        if (str == NULL) {
            ui->acwTab->item(row,  column)->setText("0");
        }
        for (i = 0; i < str.length(); i++) {
            if (((str[i] >= '0') && (str[i] <= '9')) || (str[i] == '.')) {
                //
            } else {
                ui->acwTab->item(row,  column)->setText("0");
                break;
            }
            if (str[i] == '.') { // -判断是否规范
                After_Point = str.length() - i - 1;
                if ((i == 0)) {
                    ui->acwTab->item(row, column)->setText("0");
                }
                if (i == (str.length()-1)) {
                    ui->acwTab->item(row, column)->setText\
                            (ui->acwTab->item(row, column)->text().left(i));
                }
            }
        }

        if (ui->acwTab->item(row, 3)->text().toDouble() < 150) {
            ui->acwTab->item(row, 3)->setText("150");
        }
        if (column == 4 || column == 5) {
            if (ui->acwTab->item(row, column)->text().toDouble() > set_i_up) {
                ui->acwTab->item(row, column)->setText(QString::number(set_i_up));
            }
            ui->acwTab->item(row,  column)->setText\
                    (QString::number(ui->acwTab->item\
                                     (row, column)->text().toDouble(), 'f', 2));
        }
        if (column  ==  7) {
            if (ui->acwTab->item(row, 7)->text().toDouble() >= 100.0) {
                ui->acwTab->item(row,  column)->setText("99.9");
            }
            ui->acwTab->item(row,  column)->setText\
                    (QString::number(ui->acwTab->item\
                                     (row,  column)->text().toDouble(), 'f', 1));
            if (ui->acwTab->item(row, 7)->text().toDouble() <= 0.5) {
                ui->acwTab->item(row,  column)->setText("0.5");
            }
        }
        if (column  ==  9) {
            ui->acwTab->item(row,  column)->setText\
                    (QString::number(ui->acwTab->item\
                                     (row, column)->text().toDouble(), 'f', 2));
            if (ui->acwTab->item(row, 9)->text().toDouble() >= 2.00) {
                ui->acwTab->item(row,  column)->setText("2.00");
            }
        }

        if (column == 4) {
            if ((ui->acwTab->item(row, 4)->text().toDouble()) > \
                    (ui->acwTab->item(row, 5)->text().toDouble())) {
                Pri_ACW_WMessage(tr("       输入错误，下限大于上限      "));
                ui->acwTab->item(row, 4)->setText("0.00");
            }
        }
        if (column == 5) {
            if ((ui->acwTab->item(row, 4)->text().toDouble()) > \
                    (ui->acwTab->item(row, 5)->text().toDouble())) {
                Pri_ACW_WMessage(tr("       输入错误，下限大于上限       "));
                ui->acwTab->item(row, 4)->setText("0.00");
            }
        } else if (column == 6) {
            i = ui->acwTab->item(row,  column)->text().toInt();
            if (row == 0) {
                if (i >= 0 && i <= 9) {
                    for (j = 0; j < 4; j++) {
                        Copy_ACW_List.replace(35+j*16,  QString::number(i));
                        ACW_ARC.append(new QTableWidgetItem);
                        ACW_ARC[j]->setTextAlignment(Qt::AlignCenter);
                        ACW_ARC[j]->setText(Copy_ACW_List.at(35+j*16));
                        ui->acwTab->setItem(j, 6, ACW_ARC[j]);
                    }
                    ui->acwTab->item(row,  column)->setText(QString::number(i));
                } else {
                    ui->acwTab->item(row,  column)->setText("0");
                }
            } else {
                if (i  >=  0 && i <= 9) {
                    Copy_ACW_List.replace(35+row*16,  QString::number(i));
                    ACW_ARC.append(new QTableWidgetItem);
                    ACW_ARC[row]->setTextAlignment(Qt::AlignCenter);
                    ACW_ARC[row]->setText(Copy_ACW_List.at(35+row*16));
                    ui->acwTab->setItem(row, 6, ACW_ARC[row]);
                    ui->acwTab->item(row,  column)->setText(QString::number(i));
                } else {
                    ui->acwTab->item(row,  column)->setText("0");
                }
            }
            ui->acwTab->setEditTriggers(QAbstractItemView::AllEditTriggers);
        }
    }
    Init_Flag = false;
}
void Widget_ACW::on_double_I_Down_editingFinished()
{
    if ((ui->double_I_Down->text().toDouble()) >= \
            (ui->double_I_Up->text().toDouble())) {
        ui->double_I_Down->setValue(0);
    }
}
void Widget_ACW::on_double_I_Up_editingFinished()
{
    if ((ui->double_I_Down->text().toDouble()) >= \
            (ui->double_I_Up->text().toDouble())) {
        ui->double_I_Down->setValue(0);
    }
}
/******************************************************************************
  * version:    1.0
  * author:     jeremy
  * date:       2017.2.24
  * brief:      设置警告弹出框
******************************************************************************/
void Widget_ACW::Pri_ACW_WMessage(QString Waring_Text)
{
    QMessageBox message;
    message.setWindowFlags(Qt::FramelessWindowHint);
    message.setStyleSheet
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
  * author:     jeremy
  * date:       2017.3.1
  * brief:      快速设置
******************************************************************************/
void Widget_ACW::Pri_ACW_Default_value()
{
    if (ACW_Between_IR) {
        return;
    } else {
        //
    }
    //     ui->comb_ARC->setCurrentIndex(0);
    //     ui->comb_Freq->setCurrentIndex(0);
    //     ui->double_Volt->setValue(1800);
    //     ui->double_Time->setValue(1);
    //     ui->double_I_Down->setValue(0);
    //     ui->double_I_Up->setValue(5);
    //     ACW_Compensate_Flag = false;
}

void Widget_ACW::Pri_ACW_Group_Two() {
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
    frame.data[1] = 0x0A;  // -测试组号
    frame.data[2] = 0x05;  // -测试ACV
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

    Down_Limit = (Copy_ACW_List.at(28).toDouble() + Copy_ACW_List.at(7).toDouble());
    Down_Limit_int = (Down_Limit*1000 + 5)/10;
    time_double = Copy_ACW_List.at(26).toDouble();
    time_int = (time_double *100 + 5)/10;
    frame.can_id  = 0x23;
    frame.can_dlc = 0x08;
    frame.data[0] = 0x04;  // -交耐测试参数2
    frame.data[1] = 0x0A;  // -测试组号
    frame.data[2] = Copy_ACW_List.at(25).toInt()/256;  // -电压高低字节
    frame.data[3] = Copy_ACW_List.at(25).toInt()%256;
    frame.data[4] = time_int/256;  // -测试时间
    frame.data[5] = time_int%256;
    frame.data[6] = (Down_Limit_int)/256;  // -下限耐压单位0.01mA
    frame.data[7] = (Down_Limit_int)%256;
    canSend(frame);

    Up_Limit = Copy_ACW_List.at(29).toDouble() + Copy_ACW_List.at(7).toDouble();
    Up_Limit_int = (Up_Limit*1000 + 5)/10;
    frame.can_id  = 0x23;
    frame.can_dlc = 0x07;
    frame.data[0] = 0x05;  // -交耐测试参数3
    frame.data[1] = 0x0A;  // -测试组号
    frame.data[2] = (Up_Limit_int)/256;  // -上限耐压单位0.01mA
    frame.data[3] = (Up_Limit_int)%256;
    frame.data[4] = Copy_ACW_List[4].toInt();  // -电弧等级
    frame.data[5] = 0x03;  // -缓升
    frame.data[6] = 0x0a;  // -缓降
    canSend(frame);
}

void Widget_ACW::Pri_ACW_Group_One() {
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
    frame.data[1] = 0x00;  // -测试组号
    frame.data[2] = 0x05;  // -测试ACV
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

    Down_Limit = (Copy_ACW_List.at(23).toDouble() + Copy_ACW_List.at(3).toDouble());
    Down_Limit_int = (Down_Limit*1000 + 5)/10;
    time_double = Copy_ACW_List.at(21).toDouble();
    time_int = (time_double *100 + 5)/10;
    frame.can_id  = 0x23;
    frame.can_dlc = 0x08;
    frame.data[0] = 0x04;  // -交耐测试参数2
    frame.data[1] = 0x00;  // -测试组号
    frame.data[2] = Copy_ACW_List.at(20).toInt()/256;  // -电压高低字节
    frame.data[3] = Copy_ACW_List.at(20).toInt()%256;
    frame.data[4] = time_int/256;  // -测试时间
    frame.data[5] = time_int%256;
    frame.data[6] = (Down_Limit_int)/256;  // -下限耐压单位0.01mA
    frame.data[7] = (Down_Limit_int)%256;
    canSend(frame);

    Up_Limit = Copy_ACW_List.at(24).toDouble() + Copy_ACW_List.at(3).toDouble();
    Up_Limit_int = (Up_Limit*1000 + 5)/10;
    frame.can_id  = 0x23;
    frame.can_dlc = 0x07;
    frame.data[0] = 0x05;  // -交耐测试参数3
    frame.data[1] = 0x00;  // -测试组号
    frame.data[2] = (Up_Limit_int)/256;  // -上限耐压单位0.01mA
    frame.data[3] = (Up_Limit_int)%256;
    frame.data[4] = Copy_ACW_List[0].toInt();  // -电弧等级
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
void Widget_ACW::Pri_ACW_Test(int value)
{
    ACW_Test_Total = 0;
    ACWgroup_num.clear();
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
    if (ACW_Between_IR) {
        for (i = 0; i < 4; i++) {
            if (Box_ACW_list.at(i)->checkState() != 2) {
                continue;
            }
            frame.can_id  = 0x23;
            frame.can_dlc = 0x08;
            frame.data[0] = 0x03;  // -交耐测试参数1
            frame.data[1] = i;  // -测试组号
            frame.data[2] = 0x05;  // -测试ACV
            if (Copy_ACW_List.at(30+i*16) == "PE") {
                frame.data[3] = 0x80;  // -高压端
                frame.data[4] = 0x00;
            } else {
                /*高端can协议*/
                T1_H_Data = 0;
                T1_H = Copy_ACW_List.at(30 + i*16).split("");
                for (j = 1; j < T1_H.size() - 1; j++) {
                    T1_H_Data = T1_H_Data | (1 << (T1_H.at(j).toInt()-1));
                }
                frame.data[3] = 0x00;  // -高压端
                frame.data[4] = T1_H_Data;
            }

            if (Copy_ACW_List.at(31+i*16) == "PE") {
                frame.data[5] = 0x7f;  // -低压端
                frame.data[6] = 0xff;
            } else {
                /*低端can协议*/
                T2_H_Data = 0;
                T2_H =  Copy_ACW_List.at(31 + i*16).split("");
                for (j = 1; j < T2_H.size() - 1; j++) {
                    T2_H_Data = T2_H_Data | (1 << (T2_H.at(j).toInt()-1));
                }
                frame.data[5] = 0x00;  // -低压端
                frame.data[6] = T2_H_Data;
            }
            frame.data[7] = freq[Copy_ACW_List.at(10).toInt()].toInt()%256;
            canSend(frame);

            Down_Limit = (Copy_ACW_List.at(33+i*16).toDouble() + \
                          Copy_ACW_List.at(37+i*16).toDouble());
            Down_Limit_int = (Down_Limit*1000 + 5)/10;
            time_double = Copy_ACW_List.at(36+i*16).toDouble();
            time_int = (time_double *100 + 5)/10;

            frame.can_id  = 0x23;
            frame.can_dlc = 0x08;
            frame.data[0] = 0x04;  // -交耐测试参数2
            frame.data[1] = i;  // -测试组号
            frame.data[2] = Copy_ACW_List.at(32+i*16).toInt()/256;  // -电压高低字节
            frame.data[3] = Copy_ACW_List.at(32+i*16).toInt()%256;
            frame.data[4] = time_int/256;  // -测试时间
            frame.data[5] = time_int%256;
            frame.data[6] = Down_Limit_int/256;
            //  下限耐压单位0.01mA，绝缘单位0.1MΩ //  Copy_ACW_List.at(3)/256
            frame.data[7] = Down_Limit_int%256;
            //  Copy_ACW_List.at(3)%256
            canSend(frame);

            Up_Limit = (Copy_ACW_List.at(34+i*16).toDouble() + \
                        Copy_ACW_List.at(37+i*16).toDouble());
            Up_Limit_int = (Up_Limit*1000 + 5)/10;
            frame.can_id  = 0x23;
            frame.can_dlc = 0x07;
            frame.data[0] = 0x05;  // -交耐测试参数3
            frame.data[1] = i;  // -测试组号
            frame.data[2] = Up_Limit_int/256;
            //  上限耐压单位0.01mA，绝缘单位0.1MΩ  //  Copy_ACW_List.at(4)/256
            frame.data[3] = Up_Limit_int%256;
            frame.data[4] = Copy_ACW_List[35+i*16].toInt();  // -电弧等级
            frame.data[5] = 0x03;  // -缓升
            frame.data[6] = 0x0a;  // -缓降
            canSend(frame);

            ACW_Test_Total++;  // -测试总数
            ACWgroup_num.append(QString::number(i));
        }
    } else {
        if (value == 1) {
           Pri_ACW_Group_One();
        } else {
           Pri_ACW_Group_Two();
        }
    }
}

void Widget_ACW::ACW_UsartData(QStringList list) {
    Init_Flag = true;
    double ACW_usart_volt;
    double ACW_usart_down;
    double ACW_usart_up;
    double ACW_usart_time;
    int ACW_usart_arc;

    ACW_usart_volt = list.at(5).toDouble();
    ACW_usart_up = list.at(6).toDouble();
    ACW_usart_down = list.at(7).toDouble();
    ACW_usart_time = list.at(8).toDouble();
    ACW_usart_arc = list.at(9).toInt();


    Copy_ACW_List.replace(20, QString::number(ACW_usart_volt*1000));
    ui->double_Volt->setValue(ACW_usart_volt*1000);

    Copy_ACW_List.replace(24, list.at(6));
    ui->double_I_Up->setValue(ACW_usart_up);

    Copy_ACW_List.replace(23, list.at(7));
    ui->double_I_Down->setValue(ACW_usart_down);

    Copy_ACW_List.replace(21, list.at(8));
    ui->double_Time->setValue(ACW_usart_time);

    Copy_ACW_List.replace(0, list.at(9));
    ui->comb_ARC->setCurrentIndex(ACW_usart_arc%10);

    Init_Flag = false;
}

void  Widget_ACW::ACW_NetData(QStringList list, QString str) {
    int i;
    Init_Flag = true;
    if ((list.size() == 5) || (list.size() == 6)) {
        //
    } else {
        return;
    }

    if (list.size() == 5) {
        if (str == QString(tr("volt"))) {
            Copy_ACW_List.replace(20, list.at(4));
            ui->double_Volt->setValue(list.at(4).toInt());
        } else if (str == QString(tr("min"))) {
            Copy_ACW_List.replace(23, list.at(4));
            ui->double_I_Down->setValue(list.at(4).toDouble());
        } else if (str == QString(tr("max"))) {
            Copy_ACW_List.replace(24, list.at(4));
            ui->double_I_Up->setValue(list.at(4).toDouble());
        } else if (str == QString(tr("time"))) {
            Copy_ACW_List.replace(21, list.at(4));
            ui->double_Time->setValue(list.at(4).toDouble());
        } else if (str == QString(tr("freq"))) {
            Copy_ACW_List.replace(1, list.at(4));
            ui->comb_Freq->setCurrentIndex(list.at(4).toInt());
        } else if (str == QString(tr("arc"))) {
            Copy_ACW_List.replace(0, list.at(4));
            ui->comb_ARC->setCurrentIndex(list.at(4).toInt());
        } else if (str == QString(tr("comp"))) {
            Copy_ACW_List.replace(3, list.at(4));
            ACW_Compensate_Result = list.at(4).toDouble();
            ui->doubleSpinBox_Compensate->setValue(list.at(4).toDouble());
        } else if (str == QString(tr("comp_enable"))) {
            qDebug() << list.at(4);
            if (list.at(4).toInt() == 1) {
                ACW_Compensate_Flag = true;
            } else {
                ACW_Compensate_Flag = false;
            }
            Copy_ACW_List.replace(2, list.at(4));
        } else { //
            //
        }
    } else {
        if (str == QString(tr("volt"))) {
            Copy_ACW_List.replace(20, list.at(4));
            Copy_ACW_List.replace(25, list.at(5));
            ui->double_Volt->setValue(list.at(4).toInt());
        } else if (str == QString(tr("min"))) {
            Copy_ACW_List.replace(23, list.at(4));
            Copy_ACW_List.replace(28, list.at(5));
            ui->double_I_Down->setValue(list.at(4).toDouble());
        } else if (str == QString(tr("max"))) {
            Copy_ACW_List.replace(24, list.at(4));
            Copy_ACW_List.replace(29, list.at(5));
            ui->double_I_Up->setValue(list.at(4).toDouble());
        } else if (str == QString(tr("time"))) {
            Copy_ACW_List.replace(21, list.at(4));
            Copy_ACW_List.replace(26, list.at(5));
            ui->double_Time->setValue(list.at(4).toDouble());
        } else if (str == QString(tr("freq"))) {
            Copy_ACW_List.replace(1, list.at(4));
            Copy_ACW_List.replace(5, list.at(5));
            ui->comb_Freq->setCurrentIndex(list.at(4).toInt());
        } else if (str == QString(tr("arc"))) {
            Copy_ACW_List.replace(0, list.at(4));
            Copy_ACW_List.replace(4, list.at(5));
            ui->comb_ARC->setCurrentIndex(list.at(4).toInt());
        } else if (str == QString(tr("comp"))) {
            Copy_ACW_List.replace(3, list.at(4));
            ACW_Compensate_Result = list.at(4).toDouble();
            ui->doubleSpinBox_Compensate->setValue(list.at(4).toDouble());
        } else if (str == QString(tr("comp_enable"))) {
            qDebug() << list.at(4);
            if (list.at(4).toInt() == 1) {
                ACW_Compensate_Flag = true;
            } else {
                ACW_Compensate_Flag = false;
            }
            Copy_ACW_List.replace(2, list.at(4));
        } else {
            //
        }
    }


    if (str == QString(tr("volt"))) {
        for (i = 0; i < 4; i++) {
            ACW_voltage[i]->setText(list.at(i));
        }
    } else if (str == QString(tr("min"))) {
        for (i = 0; i < 4; i++) {
            ACW_I_Min[i]->setText(list.at(i));
        }
    } else if (str == QString(tr("max"))) {
        for (i = 0; i < 4; i++) {
            ACW_I_Max[i]->setText(list.at(i));
        }
    } else if (str == QString(tr("time"))) {
        for (i = 0; i < 4; i++) {
            ACW_time[i]->setText(list.at(i));
        }
    } else if (str == QString(tr("freq"))) {
        for (i = 0; i < 4; i++) {
            QTableWidgetItem *ACW_freq = new QTableWidgetItem;
            Copy_ACW_List.replace(10, list.at(i));
            ACW_freq->setTextAlignment(Qt::AlignCenter);
            ACW_freq->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            ACW_freq->setText(freq[Copy_ACW_List.at(10).toInt()]);
            ui->acwTab->setItem(i, 8, ACW_freq);
        }
    } else if (str == QString(tr("arc"))) {
        for (i = 0; i < 4; i++) {
            ACW_ARC[i]->setText(list.at(i));
        }
    } else if (str == QString(tr("test"))) {
        for (i = 0; i < 4; i++) {
            if (list.at(i).toInt() == 1) {
                Box_ACW_list[i]->setChecked(true);
            } else {
                Box_ACW_list[i]->setChecked(false);
            }
        }
    } else if (str == QString(tr("port1"))) {
        for (i = 0; i < 4; i++) {
            ui->acwTab->item(i, 1)->setText(list.at(i));
        }
    } else if (str == QString(tr("port2"))) {
        for (i = 0; i < 4; i++) {
            ui->acwTab->item(i, 2)->setText(list.at(i));
        }
    } else if (str == QString(tr("comp"))) {
        for (i = 0; i < 4; i++) {
            ui->acwTab->item(i, 9)->setText(list.at(i));
        }
    } else {
        //
    }

    Init_Flag = false;
}

QStringList Widget_ACW::ACW_Test_Result(QStringList ACW_Data)
{
    QStringList Back_QStringList;  Back_QStringList.clear();
    bool IRACW_True_Value;
    int  ACW_volt;
    int  ACW_Test_Count;
    double ACW_Show_Data;
    int ACW_Judge;
    int ACW_First_Test;

    IRACW_True_Value = ACW_Data.at(0).toInt();
    ACW_volt = ACW_Data.at(1).toInt();
    ACW_Test_Count = ACW_Data.at(2).toInt();
    ACW_Show_Data = ACW_Data.at(3).toDouble();
    ACW_Judge = ACW_Data.at(4).toInt();
    ACW_First_Test = ACW_Data.at(5).toInt();
    if (ACW_Between_IR) {
        if (IRACW_True_Value) {
            ACW_volt = Copy_ACW_List.at(32+(ACWgroup_num.at(ACW_Test_Count).toInt())*16).toInt();
        }
        Back_QStringList.append(QString::number(ACW_volt)+"V, ");
    } else {
        if (IRACW_True_Value) {
            if (ACW_First_Test == 1) {
                ACW_volt = Copy_ACW_List.at(20).toInt();
            } else {
                ACW_volt = Copy_ACW_List.at(25).toInt();
            }
        }
        Back_QStringList.append(QString::number(ACW_volt)+"V, ");
    }


    if (ACW_Compensate_Flag) { // -交耐补偿
        Back_QStringList.append(QString::number(ACW_Show_Data-(ACW_Compensate_Result)));
    } else {
        Back_QStringList.append(QString::number(ACW_Show_Data));
    }
    Back_QStringList.append(QString::number(ACW_Judge));

    return Back_QStringList;
}
QStringList Widget_ACW::ACW_Test_Param(bool Test_Enable)
{
    QString str;
    QStringList strSql;
    QStringList strTest, strParam;
    strTest.clear();
    strParam.clear();
    if (ACW_Between_IR) {
        for (int j = 0; j < 4; j++) {
            if (Copy_ACW_List[40+j*16].toInt()  ==  2) {
                str = QString(tr("交耐")) + QString::number(j+1);
                strTest.append(str);
                str.clear();
                str += QString(tr("高端:"));
                str += Copy_ACW_List.at(30+j*16); str += QString(tr(" "));
                str += Copy_ACW_List.at(32+j*16); str += "V,";
                str += Copy_ACW_List.at(34+j*16); str += "mA,ARC:";
                str += Copy_ACW_List.at(35+j*16);
                strParam.append(str);
                str.clear();
                strSql.append(tr("交耐"));
            }
        }
    } else {
        if (Test_Enable) {
            str = QString(tr("交耐"));
            strTest.append(str);
            str.clear();
            str += Copy_ACW_List.at(25);   str += "V,";
            str += Copy_ACW_List.at(29);   str += "mA,ARC:";
            str += Copy_ACW_List.at(4);
            strParam.append(str);
            str.clear();
            strSql.append(tr("交耐"));
        } else {
            str = QString(tr("交耐"));
            strTest.append(str);
            str.clear();
            str += Copy_ACW_List.at(20);   str += "V,";
            str += Copy_ACW_List.at(24);   str += "mA,ARC:";
            str += Copy_ACW_List.at(0);
            strParam.append(str);
            str.clear();
            strSql.append(tr("交耐"));
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
bool Widget_ACW::ACW_If_Compensate(QString ACW_Between_IR)
{
    if (ACW_Compensate_Flag) {
        ACW_Compensate_Flag = false;
        if (ui->label_ACW_Param->text() == "ACW-1") {
            Copy_ACW_List.replace(2, "0");
            Copy_ACW_List.replace(3, "0");
        } else {
            Copy_ACW_List.replace(6, "0");
            Copy_ACW_List.replace(7, "0");
        }

        ui->doubleSpinBox_Compensate->setValue(0);
        return true;
    } else {
        Pri_ACW_Init(ACW_Between_IR);
        frame.can_id = 0x23;  frame.can_dlc = 0x05;
        frame.data[0] = 0x01;
        frame.data[1] = 0x05;
        frame.data[2] = 0x00;
        frame.data[3] = 0x13;
        frame.data[4] = 0x00;
        canSend(frame);
        return false;
    }
}
bool Widget_ACW::ACW_Back_Key_E()
{
    if (ACW_Between_IR) {
        ACW_Compensate_Flag = false;
    }

    if (ACW_Compensate_Flag) {
        return 1;
    } else {
        return 0;
    }
}
int  Widget_ACW::ACW_Compensate(double Compensate_Value)
{
    if (ACW_Compensate_Flag) { //  ACW_Compensate_Flag!=0
        return 0;
    }
    ACW_Compensate_Result = Compensate_Value;
    if (ACW_Compensate_Result < 3) {
        ACW_Compensate_Flag = true;
        if (ui->label_ACW_Param->text() == "ACW-1") {
            Copy_ACW_List.replace(2, "1");
            Copy_ACW_List.replace(3, QString::number(ACW_Compensate_Result, 'f', 2));
        } else {
            Copy_ACW_List.replace(6, "1");
            Copy_ACW_List.replace(7, QString::number(ACW_Compensate_Result, 'f', 2));
        }
        ui->doubleSpinBox_Compensate->setValue(Copy_ACW_List.at(3).toDouble());
        return 1;
    } else {
        frame.can_id = 0x23;  frame.can_dlc = 0x01;
        frame.data[0] = 0x02;
        canSend(frame);
        ACW_Compensate_Flag = false;
        return 2;
    }
}

void  Widget_ACW::Pri_ACW_I_Init(QString list) {
    ui->double_I_Down->setMaximum(list.toDouble());
    ui->double_I_Up->setMaximum(list.toDouble());
    set_i_up = list.toDouble();
}

void  Widget_ACW::Pri_ACW_Volt_Init(QString list) {
    ui->double_Volt->setMinimum(list.toDouble());
}

void Widget_ACW::Pri_ACW_Param(QString value) {
    qDebug() << "ACW----2";
    if (value == "2") {
        ui->label_ACW_Param->setText("ACW-2");
        ui->double_Volt->setValue(Copy_ACW_List.at(25).toDouble());
        ui->double_Time->setValue(Copy_ACW_List.at(26).toDouble());
        ui->double_I_Down->setValue(Copy_ACW_List.at(28).toDouble());
        ui->double_I_Up->setValue(Copy_ACW_List.at(29).toDouble());
        ui->comb_ARC->setCurrentIndex(Copy_ACW_List[4].toInt());
        ui->comb_Freq->setCurrentIndex(Copy_ACW_List[5].toInt());
        ui->doubleSpinBox_Compensate->setValue(Copy_ACW_List.at(7).toDouble());
    } else {
        ui->label_ACW_Param->setText("ACW-1");
        ui->double_Volt->setValue(Copy_ACW_List.at(20).toDouble());
        ui->double_Time->setValue(Copy_ACW_List.at(21).toDouble());
        ui->double_I_Down->setValue(Copy_ACW_List.at(23).toDouble());
        ui->double_I_Up->setValue(Copy_ACW_List.at(24).toDouble());
        ui->comb_ARC->setCurrentIndex(Copy_ACW_List[0].toInt());
        ui->comb_Freq->setCurrentIndex(Copy_ACW_List[1].toInt());
        ui->doubleSpinBox_Compensate->setValue(Copy_ACW_List.at(3).toDouble());
    }
    qApp->processEvents();
}
void Widget_ACW::Pub_Conf_Set_ACW(QString str, int value)
{
    switch (value) {
    case 1:
        Pri_ACW_Init(str);
        break;
    case 2:
        Pri_ACW_Save_Data();
        if (ACW_Between_IR) {
            box_statechange();
        } else {
            //
        }
        break;
    case 3:
        Pri_ACW_Default_value();
        break;
    case 5:
        Pri_ACW_Test(1);
        break;
    case 6:
        Line_HV = true;
        Line_HV_High = str;
        break;
    case 7:
        Line_HV = true;
        Line_HV_Low = str;
        break;
    case 8:
        on_acwTab_cellClicked(0, 0);
        break;
    case 9:
        Pri_ACW_I_Init(str);
        break;
    case 10:
        Pri_ACW_Volt_Init(str);
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
    case 102:
        Pri_ACW_Test(2);
        break;
    case 103:
        Pri_ACW_Param(str);
        break;
    default:
        break;
    }
}
