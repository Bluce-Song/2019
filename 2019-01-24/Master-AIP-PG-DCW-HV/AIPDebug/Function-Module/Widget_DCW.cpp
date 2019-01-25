/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "Widget_DCW.h"
#include "ui_Widget_DCW.h"

Widget_DCW::Widget_DCW(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_DCW)
{
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint); // 去掉标题栏
    ui->setupUi(this);
    ui->dcwTab->horizontalHeader()->setStyleSheet\
            ("QHeaderView::section{background-color:#191919;color: white;"\
             "padding-left: 4px;border: 1px solid #447684;}");
    ui->dcwTab->horizontalHeader()->setFixedHeight(35);
    ui->dcwTab->horizontalHeader()->setResizeMode(QHeaderView::Fixed);
    ui->dcwTab->setColumnWidth(0, 41);  //  设置长度
    ui->dcwTab->setColumnWidth(1, 60);
    ui->dcwTab->setColumnWidth(2, 90);
    ui->dcwTab->setColumnWidth(3, 70);
    ui->dcwTab->setColumnWidth(4, 72);
    ui->dcwTab->setColumnWidth(5, 72);
    ui->dcwTab->setColumnWidth(6, 60);
    ui->dcwTab->setColumnWidth(7, 60);
    ui->dcwTab->setColumnWidth(8, 60);
    ui->dcwTab->setColumnWidth(9, 60);
     // ui->dcwTab->setColumnWidth(10, 47);

    DCW_btnGroup = new QButtonGroup;
    DCW_btnGroup->addButton(ui->OK, 1);
    connect(DCW_btnGroup, SIGNAL(buttonClicked(int)), this, SLOT(join_buttonJudge(int)));
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
    DCW_Labelhide = new QLabel(this);
    DCW_Labelhide->setGeometry(0, 0, 800, 600);
    DCW_Labelhide->hide();

    ui->dcwTab->move(0, 110);
    ui->dcwTab->hide();
    ui->widget->move(90, 140);
    ui->widget->hide();
    ui->dockwidget->move(190, 0);

    DCW_Test_Total = 0;
    DCW_Between_IR = false;
    Init_Flag = false;
    Init_Channel_6 = false;
    volt_set = 3000;
    ui->doubleSpinBox_Compensate->setDisabled(true);
}

Widget_DCW::~Widget_DCW()
{
    delete ui;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      初始化直耐设置
******************************************************************************/
void Widget_DCW::Pri_DCW_Init(QString str) {
    int i;
    Init_Flag = true;
    ui->dcwTab->setRowCount(4);  // -设置行数
    ui->dcwTab->setColumnCount(11);  // -设置列数

    freq.clear();     freq << "50" << "60";  // -設置頻率
    DCW_Between_IR = str.toInt();
    if (DCW_Between_IR) {
        ui->dcwTab->show();     ui->dcwTab->raise();
        ui->widget->hide();
    } else {
        ui->widget->show();     ui->widget->raise();
        ui->dcwTab->hide();
    }

    DCW_T1_List.clear();
    DCW_T2_List.clear();
    DCW_voltage.clear();
    DCW_I_Max.clear();
    DCW_I_Min.clear();
    DCW_ARC.clear();
    DCW_time.clear();
    DCW_compensate.clear();
    Box_DCW_list.clear();
    for (i = 0; i < 4; i++) {
         // 初始化输入框
        QTableWidgetItem *number = new QTableWidgetItem;
        number->setTextAlignment(Qt::AlignCenter);
        number->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        number->setText(QString::number((i + 1)));
        ui->dcwTab->setItem(i, 0, number);

        DCW_T1_List.append(new QTableWidgetItem);
        DCW_T1_List[i]->setTextAlignment(Qt::AlignCenter);
        DCW_T1_List[i]->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        DCW_T1_List[i]->setText(Copy_DCW_List.at(30+i*16));
        ui->dcwTab->setItem(i, 1, DCW_T1_List[i]);

        DCW_T2_List.append(new QTableWidgetItem);
        DCW_T2_List[i]->setTextAlignment(Qt::AlignCenter);
        DCW_T2_List[i]->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        DCW_T2_List[i]->setText(Copy_DCW_List.at(31+i*16));
        ui->dcwTab->setItem(i, 2, DCW_T2_List[i]);

        DCW_voltage.append(new QTableWidgetItem);
        DCW_voltage[i]->setTextAlignment(Qt::AlignCenter);
        DCW_voltage[i]->setText(Copy_DCW_List.at(32+i*16));
        ui->dcwTab->setItem(i, 3, DCW_voltage[i]);

        DCW_I_Min.append(new QTableWidgetItem);
        DCW_I_Min[i]->setTextAlignment(Qt::AlignCenter);
        DCW_I_Min[i]->setText(Copy_DCW_List.at(33+i*16));
        ui->dcwTab->setItem(i, 4, DCW_I_Min[i]);

        DCW_I_Max.append(new QTableWidgetItem);
        DCW_I_Max[i]->setTextAlignment(Qt::AlignCenter);
        DCW_I_Max[i]->setText(Copy_DCW_List.at(34+i*16));
        ui->dcwTab->setItem(i, 5, DCW_I_Max[i]);

        DCW_ARC.append(new QTableWidgetItem);
        DCW_ARC[i]->setTextAlignment(Qt::AlignCenter);
        DCW_ARC[i]->setText(Copy_DCW_List.at(35+i*16));
        ui->dcwTab->setItem(i, 6, DCW_ARC[i]);

        DCW_time.append(new QTableWidgetItem);
        DCW_time[i]->setTextAlignment(Qt::AlignCenter);
        DCW_time[i]->setText(Copy_DCW_List.at(36+i*16));
        ui->dcwTab->setItem(i, 7, DCW_time[i]);


        QTableWidgetItem *DCW_freq = new QTableWidgetItem;
        DCW_freq->setTextAlignment(Qt::AlignCenter);
        DCW_freq->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        DCW_freq->setText(freq[Copy_DCW_List.at(10).toInt()]);
        ui->dcwTab->setItem(i, 8, DCW_freq);

        DCW_compensate.append(new QTableWidgetItem);
        DCW_compensate[i]->setTextAlignment(Qt::AlignCenter);
         //       ACW_compensate[i]->setText("*");
        DCW_compensate[i]->setText(Copy_DCW_List.at(37+i*16));
        ui->dcwTab->setItem(i, 9, DCW_compensate[i]);


        Box_DCW_list.append(new QCheckBox);
        Box_DCW_list[i]->setStyleSheet\
                ("QCheckBox::indicator {image: url(:/image/053.png);width: 50px;"\
                 "height: 55px;}QCheckBox::indicator:checked {image: url(:/image/051.png);}");
        if (Copy_DCW_List.at(40+i*16).toInt() == 2) {
            Box_DCW_list[i]->setChecked(true);
        }
        ui->dcwTab->setRowHeight(i, 70);
        ui->dcwTab->setCellWidget(i, 10, Box_DCW_list[i]);
    }

    ui->double_Volt->setMaximum(volt_set);  //  500-5000 V
    ui->double_Volt->setMinimum(200);
    ui->double_Volt->setDecimals(0);
    ui->double_Volt->setValue(Copy_DCW_List.at(20).toDouble());

    ui->double_Time->setMaximum(999.9);  //  0.5-999.9 S
    ui->double_Time->setMinimum(0.5);
    ui->double_Time->setDecimals(1);
    ui->double_Time->setValue(Copy_DCW_List.at(21).toDouble());

    ui->double_I_Down->setMaximum(10.00);  //  0-1000V mA
    ui->double_I_Down->setMinimum(0);
    ui->double_I_Down->setDecimals(2);
    ui->double_I_Down->setValue(Copy_DCW_List.at(23).toDouble());

    ui->double_I_Up->setMaximum(10.00);  //  10-1000 mA
    ui->double_I_Up->setMinimum(0.10);
    ui->double_I_Up->setDecimals(2);
    ui->double_I_Up->setValue(Copy_DCW_List.at(24).toDouble());

    ui->comb_ARC->setCurrentIndex(Copy_DCW_List[0].toInt());

    DCW_Compensate_Flag = Copy_DCW_List.at(2).toInt();
    if (DCW_Compensate_Flag) {
        ui->doubleSpinBox_Compensate->setValue(Copy_DCW_List.at(3).toDouble());
        DCW_Compensate_Result = Copy_DCW_List.at(3).toDouble();
    }
    for (i = 0; i < Box_All_List.size(); i++) {
        if (Copy_DCW_List.at(i).toInt() == 2) {
            Box_All_List.at(i)->setChecked(true);
        }
    }
    Init_Flag = false;
}

void Widget_DCW::mousePressEvent(QMouseEvent *event)  // 处理鼠标被按下事件
{
    if ((ui->dcwTab->currentColumn() == 1) || \
            (ui->dcwTab->currentColumn() == 2)) {
        ui->dockwidget->hide();   DCW_Labelhide->hide();
    }
}
/******************************************************************************
  * version:    1.0
  * author:     jeremy
  * date:       2017.3.1
  * brief:      OK按键槽函数
******************************************************************************/
void Widget_DCW::join_buttonJudge(int test_key)
{
    int i;
    QStringList check;
    QString sendcheck;
    ui->dockwidget->hide();  DCW_Labelhide->hide();
    for (i = 0; i < Box_All_List.size()-2; i++) {
        if (Box_All_List.at(i)->checkState() == 2) {
            check.append(QString::number(i+1));
            sendcheck = check.join("");
        }
    }
    if (Box_All_List.at(9)->checkState() == 2) {
        ui->dcwTab->currentItem()->setText("12345678");
    } else if (Box_All_List[8]->checkState() == 2) {
        ui->dcwTab->currentItem()->setText("PE");
    } else {
        if (sendcheck == tr("")) {
            ui->dcwTab->currentItem()->setText("1");
        } else {
            ui->dcwTab->currentItem()->setText(sendcheck);
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
void Widget_DCW::box_statechange()
{
    int i, j;
    for (i = 0; i < 4; i++) {
        if (Copy_DCW_List.at(40 + i*16).toInt() != 2) {
            continue;
        }
        for (j = 0; j < 7; j++) {
            if (Copy_DCW_List.at(31 + i*16).mid(j, 1) == "") {
                break;
            }

            if ((Copy_DCW_List.at(31 + i*16).mid(j, 1).toInt()) == \
                    (Copy_DCW_List.at(30 + i*16).mid(0, 1).toInt())) {
                Pri_DCW_WMessage(tr("       输入错误，端点有重合       "));
                ui->dcwTab->item(i, 1)->setText("1");
                ui->dcwTab->item(i, 2)->setText("2");
                break;
            } else if ((Copy_DCW_List.at(31 + i*16).mid(j, 1).toInt()) == \
                     (Copy_DCW_List.at(30 + i*16).mid(1, 1).toInt())) {
                Pri_DCW_WMessage(tr("       输入错误，端点有重合       "));
                ui->dcwTab->item(i, 1)->setText("1");
                ui->dcwTab->item(i, 2)->setText("2");
                break;
            } else if ((Copy_DCW_List.at(31 + i*16).mid(j, 1).toInt()) == \
                     (Copy_DCW_List.at(30 + i*16).mid(2, 1).toInt())) {
                Pri_DCW_WMessage(tr("       输入错误，端点有重合       "));
                ui->dcwTab->item(i, 1)->setText("1");
                ui->dcwTab->item(i, 2)->setText("2");
                break;
            }
        }
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      保存直耐配置
******************************************************************************/
void Widget_DCW::Pri_DCW_Save_Data() {
    int i;
     // 更新相间交耐数据
    if (DCW_Between_IR) {
        for (i = 0; i < 4; i++) {
            Copy_DCW_List.replace(30+i*16, (ui->dcwTab->item(i, 1)->text()));
            Copy_DCW_List.replace(31+i*16, (ui->dcwTab->item(i, 2)->text()));
            Copy_DCW_List.replace(32+i*16, (DCW_voltage[i]->text()));
            Copy_DCW_List.replace(33+i*16, (DCW_I_Min[i]->text()));
            Copy_DCW_List.replace(34+i*16, (DCW_I_Max[i]->text()));
            Copy_DCW_List.replace(35+i*16, (DCW_ARC[i]->text()));
            Copy_DCW_List.replace(36+i*16, (DCW_time[i]->text()));
            Copy_DCW_List.replace(37+i*16, (DCW_compensate[i]->text()));
            Copy_DCW_List.replace(40+i*16, QString::number(Box_DCW_list.at(i)->checkState()));
        }
    } else {
         // 更新普通交耐数据
        Copy_DCW_List.replace(20, ui->double_Volt->text());
        Copy_DCW_List.replace(21, ui->double_Time->text());
        Copy_DCW_List.replace(23, ui->double_I_Down->text());
        Copy_DCW_List.replace(24, ui->double_I_Up->text());
        Copy_DCW_List.replace(0, QString::number(ui->comb_ARC->currentIndex()));
//        Copy_DCW_List.replace(1, QString::number(ui->comb_Freq->currentIndex()));
    }
    if (DCW_Compensate_Flag) { // -补偿后进行修改数值
        Copy_DCW_List.replace(3, QString::number(ui->doubleSpinBox_Compensate->value(), 'f', 2));
        ui->doubleSpinBox_Compensate->setValue(Copy_DCW_List.at(3).toDouble());
    }
}

/******************************************************************************
  * version:    1.0
  * author:     jeremy
  * date:       2017.3.1
  * brief:      QTableWidget表点击槽函数
******************************************************************************/
void Widget_DCW::on_dcwTab_cellClicked(int row,  int column)
{
    int i,  dcwId;
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
        DCW_Labelhide->show();
        ui->dockwidget->show();
        ui->dockwidget->raise();
    } else if (column  ==  8) {
        dcwId = (Copy_DCW_List[10].toInt()+1)%freq.size();
        for (i = 0; i < 4; i++) {
            QTableWidgetItem *DCW_freq = new QTableWidgetItem;
            Copy_DCW_List.replace(10, QString::number(dcwId));
            DCW_freq->setTextAlignment(Qt::AlignCenter);
            DCW_freq->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            DCW_freq->setText(freq[Copy_DCW_List.at(10).toInt()]);
            ui->dcwTab->setItem(i, 8, DCW_freq);
        }
        ui->dcwTab->setEditTriggers(QAbstractItemView::AllEditTriggers);
    }
    row = 0;
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.5.16
  * brief:      进行端子有无重合的判定
******************************************************************************/
bool Widget_DCW::Pri_DCW_T1T2_Judge(QString T1, QString T2)
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
void Widget_DCW::on_dcwTab_cellChanged(int row,  int column)
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
        if (Pri_DCW_T1T2_Judge(ui->dcwTab->item(row,  1)->text(), \
                               ui->dcwTab->item(row,  2)->text())) {
            ui->dcwTab->item(row,  1)->setText("1");
            ui->dcwTab->item(row,  2)->setText("2");
            Pri_DCW_WMessage(tr("       输入错误，端点有重合       "));
        } else {
            //
        }
    } else if ((column  ==  3) || (column  ==  4) || \
             (column  ==  5) || (column  ==  6) || \
             (column  ==  7) || (column  ==  9)) {
        str = ui->dcwTab->item(row,  column)->text();
        if (str == NULL) {
            ui->dcwTab->item(row,  column)->setText("0");
        }
        for (i = 0; i < str.length(); i++) {
            if (((str[i] >= '0') && (str[i] <= '9')) || (str[i] == '.')) {
                //
            } else {
                ui->dcwTab->item(row,  column)->setText("0");
                break;
            }
            if (str[i] == '.') { // -判断是否规范
                After_Point = str.length() - i - 1;
                if ((i == 0)) {
                    ui->dcwTab->item(row, column)->setText("0");
                }
                if (i == (str.length()-1)) {
                    ui->dcwTab->item(row, column)->setText\
                            (ui->dcwTab->item(row, column)->text().left(i));
                }
            }
        }

        if (ui->dcwTab->item(row, 3)->text().toDouble() < 150) {
            ui->dcwTab->item(row, 3)->setText("150");
        }
        if (column == 4 || column == 5) {
            if (ui->dcwTab->item(row, column)->text().toDouble() > 20) {
                ui->dcwTab->item(row, column)->setText("20.00");
            }
            ui->dcwTab->item(row,  column)->setText\
                    (QString::number(ui->dcwTab->item\
                                     (row, column)->text().toDouble(), 'f', 2));
        }
        if (column  ==  7) {
            if (ui->dcwTab->item(row, 7)->text().toDouble() >= 100.0) {
                ui->dcwTab->item(row,  column)->setText("99.9");
            }
            ui->dcwTab->item(row,  column)->setText\
                    (QString::number(ui->dcwTab->item\
                                     (row,  column)->text().toDouble(), 'f', 1));
            if (ui->dcwTab->item(row, 7)->text().toDouble() <= 0.5) {
                ui->dcwTab->item(row,  column)->setText("0.5");
            }
        }
        if (column  ==  9) {
            ui->dcwTab->item(row,  column)->setText\
                    (QString::number(ui->dcwTab->item\
                                     (row, column)->text().toDouble(), 'f', 2));
            if (ui->dcwTab->item(row, 9)->text().toDouble() >= 2.00) {
                ui->dcwTab->item(row,  column)->setText("2.00");
            }
        }

        if (column == 4) {
            if ((ui->dcwTab->item(row, 4)->text().toDouble()) > \
                    (ui->dcwTab->item(row, 5)->text().toDouble())) {
                Pri_DCW_WMessage(tr("       输入错误，下限大于上限      "));
                ui->dcwTab->item(row, 4)->setText("0.00");
            }
        }
        if (column == 5) {
            if ((ui->dcwTab->item(row, 4)->text().toDouble()) > \
                    (ui->dcwTab->item(row, 5)->text().toDouble())) {
                Pri_DCW_WMessage(tr("       输入错误，下限大于上限       "));
                ui->dcwTab->item(row, 4)->setText("0.00");
            }
        } else if (column == 6) {
            i = ui->dcwTab->item(row,  column)->text().toInt();
            if (row == 0) {
                if (i >= 0 && i <= 9) {
                    for (j = 0; j < 4; j++) {
                        Copy_DCW_List.replace(35+j*16,  QString::number(i));
                        DCW_ARC.append(new QTableWidgetItem);
                        DCW_ARC[j]->setTextAlignment(Qt::AlignCenter);
                        DCW_ARC[j]->setText(Copy_DCW_List.at(35+j*16));
                        ui->dcwTab->setItem(j, 6, DCW_ARC[j]);
                    }
                    ui->dcwTab->item(row,  column)->setText(QString::number(i));
                } else {
                    ui->dcwTab->item(row,  column)->setText("0");
                }
            } else {
                if (i  >=  0 && i <= 9) {
                    Copy_DCW_List.replace(35+row*16,  QString::number(i));
                    DCW_ARC.append(new QTableWidgetItem);
                    DCW_ARC[row]->setTextAlignment(Qt::AlignCenter);
                    DCW_ARC[row]->setText(Copy_DCW_List.at(35+row*16));
                    ui->dcwTab->setItem(row, 6, DCW_ARC[row]);
                    ui->dcwTab->item(row,  column)->setText(QString::number(i));
                } else {
                    ui->dcwTab->item(row,  column)->setText("0");
                }
            }
            ui->dcwTab->setEditTriggers(QAbstractItemView::AllEditTriggers);
        }
    }
    Init_Flag = false;
}

void Widget_DCW::on_double_I_Down_editingFinished()
{
    if ((ui->double_I_Down->text().toDouble()) >= \
            (ui->double_I_Up->text().toDouble())) {
        ui->double_I_Down->setValue(0);
    }
}
void Widget_DCW::on_double_I_Up_editingFinished()
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
void Widget_DCW::Pri_DCW_WMessage(QString Waring_Text)
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

void Widget_DCW::Pri_DCW_Default_value()
{
    if (DCW_Between_IR) {
        return;
    }
    //     ui->comb_ARC->setCurrentIndex(0);
    //     ui->comb_Freq->setCurrentIndex(0);
    //     ui->double_Volt->setValue(1800);
    //     ui->double_Time->setValue(1);
    //     ui->double_I_Down->setValue(0);
    //     ui->double_I_Up->setValue(5);
    //     ACW_Compensate_Flag = false;
}

void Widget_DCW::Pri_DCW_Test() {
    DCW_Test_Total = 0;
    DCWgroup_num.clear();
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
    if (DCW_Between_IR) {
        for (i = 0; i < 4; i++) {
            if (Box_DCW_list.at(i)->checkState() != 2) {
                continue;
            }
            frame.can_id  = 0x23;
            frame.can_dlc = 0x08;
            frame.data[0] = 0x03;  // -交耐测试参数1
            frame.data[1] = i;  // -测试组号
            frame.data[2] = 0x07;  // -测试ACV
            if (Copy_DCW_List.at(30+i*16) == "PE" || \
                    Copy_DCW_List.at(31+i*16) == "PE") {
                frame.data[3] = 0x80;  // -高压端
                frame.data[4] = 0x00;
                frame.data[5] = 0x7f;  // -低压端
                frame.data[6] = 0xff;
            } else {
                /*高端can协议*/
                T1_H_Data = 0;
                T1_H = Copy_DCW_List.at(30 + i*16).split("");
                for (j = 1; j < T1_H.size() - 1; j++) {
                    T1_H_Data = T1_H_Data | (1 << (T1_H.at(j).toInt()-1));
                }
                frame.data[3] = 0x00;  // -高压端
                frame.data[4] = T1_H_Data;


                /*低端can协议*/
                T2_H_Data = 0;
                T2_H =  Copy_DCW_List.at(31 + i*16).split("");
                for (j = 1; j < T2_H.size() - 1; j++) {
                    T2_H_Data = T2_H_Data | (1 << (T2_H.at(j).toInt()-1));
                }
                frame.data[5] = 0x00;  // -低压端
                frame.data[6] = T2_H_Data;
            }
            frame.data[7] = freq[Copy_DCW_List.at(10).toInt()].toInt()%256;
            canSend(frame);

            time_double = Copy_DCW_List.at(36+i*16).toDouble();
            time_int = (time_double*100 + 5)/10;
            Down_Limit = (Copy_DCW_List.at(33+i*16).toDouble() + \
                          Copy_DCW_List.at(37+i*16).toDouble());
            Down_Limit_int = (Down_Limit*1000 + 5)/10;
            frame.can_id  = 0x23;
            frame.can_dlc = 0x08;
            frame.data[0] = 0x04;  // -交耐测试参数2
            frame.data[1] = i;  // -测试组号
            frame.data[2] = Copy_DCW_List.at(32+i*16).toInt()/256;  // -电压高低字节
            frame.data[3] = Copy_DCW_List.at(32+i*16).toInt()%256;
            frame.data[4] = time_int/256;  // -测试时间
            frame.data[5] = time_int%256;
            frame.data[6] = Down_Limit_int/256;
            //  下限耐压单位0.01mA，绝缘单位0.1MΩ //  Copy_DCW_List.at(3)/256
            frame.data[7] = Down_Limit_int%256;
            //  Copy_DCW_List.at(3)%256
            canSend(frame);

            Up_Limit = (Copy_DCW_List.at(34+i*16).toDouble() + \
                       Copy_DCW_List.at(37+i*16).toDouble());
            Up_Limit_int = (Up_Limit*1000 + 5)/10;
            frame.can_id  = 0x23;
            frame.can_dlc = 0x07;
            frame.data[0] = 0x05;  // -交耐测试参数3
            frame.data[1] = i;  // -测试组号
            frame.data[2] = Up_Limit_int/256;
            //  上限耐压单位0.01mA，绝缘单位0.1MΩ  //  Copy_DCW_List.at(4)/256
            frame.data[3] = Up_Limit_int%256;
            frame.data[4] = Copy_DCW_List[35+i*16].toInt();  // -电弧等级
            frame.data[5] = 0x03;  // -缓升
            frame.data[6] = 0x0a;  // -缓降
            canSend(frame);

            DCW_Test_Total++;  // -测试总数
            DCWgroup_num.append(QString::number(i));
        }
    } else {
        frame.can_id  = 0x23;
        frame.can_dlc = 0x08;
        frame.data[0] = 0x03;  // -交耐测试参数1
        frame.data[1] = 0x02;  // -测试组号
        frame.data[2] = 0x07;  // -测试ACV
        frame.data[3] = 0x80;  // -高压端
        frame.data[4] = 0x00;
        frame.data[5] = 0xff;  // -低压端
        frame.data[6] = 0xff;
        frame.data[7] = 0x00;
        canSend(frame);

        time_double = Copy_DCW_List.at(21).toDouble();
        time_int = (time_double*100 + 5)/10;
        Down_Limit = (Copy_DCW_List.at(23).toDouble() + Copy_DCW_List.at(3).toDouble());
        Down_Limit_int = (Down_Limit*1000 + 5)/10;
        frame.can_id  = 0x23;
        frame.can_dlc = 0x08;
        frame.data[0] = 0x04;  // -交耐测试参数2
        frame.data[1] = 0x02;  // -测试组号
        frame.data[2] = Copy_DCW_List.at(20).toInt()/256;  // -电压高低字节
        frame.data[3] = Copy_DCW_List.at(20).toInt()%256;
        frame.data[4] = time_int/256;  // -测试时间
        frame.data[5] = time_int%256;
        frame.data[6] = Down_Limit_int/256;  // -下限耐压单位0.01mA
        frame.data[7] = Down_Limit_int%256;
        canSend(frame);

        Up_Limit = Copy_DCW_List.at(24).toDouble() + Copy_DCW_List.at(3).toDouble();
        Up_Limit_int = (Up_Limit*1000 + 5)/10;
        frame.can_id  = 0x23;
        frame.can_dlc = 0x07;
        frame.data[0] = 0x05;  // -交耐测试参数3
        frame.data[1] = 0x02;  // -测试组号
        frame.data[2] = (Up_Limit_int)/256;  // -上限耐压单位0.01mA
        frame.data[3] = (Up_Limit_int)%256;
        frame.data[4] = Copy_DCW_List[0].toInt();  // -电弧等级
        frame.data[5] = 0x03;  // -缓升
        frame.data[6] = 0x0a;  // -缓降
        canSend(frame);
    }
}

void  Widget_DCW::DCW_NetData(QStringList list, QString str) {
    Init_Flag = true;
    if ((list.size() == 5) || (list.size() == 6)) {
        //
    } else {
        return;
    }

    if (str == QString(tr("volt"))) {
        Copy_DCW_List.replace(20, list.at(4));
        ui->double_Volt->setValue(list.at(4).toInt());
    } else if (str == QString(tr("min"))) {
        Copy_DCW_List.replace(23, list.at(4));
        ui->double_I_Down->setValue(list.at(4).toDouble());
    } else if (str == QString(tr("max"))) {
        Copy_DCW_List.replace(24, list.at(4));
        ui->double_I_Up->setValue(list.at(4).toDouble());
    } else if (str == QString(tr("time"))) {
        Copy_DCW_List.replace(21, list.at(4));
        ui->double_Time->setValue(list.at(4).toDouble());
    } else if (str == QString(tr("freq"))) {
//        Copy_DCW_List.replace(1, list.at(4));
//        ui->comb_Freq->setCurrentIndex(list.at(4).toInt());
    } else if (str == QString(tr("arc"))) {
        Copy_DCW_List.replace(0, list.at(4));
        ui->comb_ARC->setCurrentIndex(list.at(4).toInt());
    } else if (str == QString(tr("comp"))) {
        Copy_DCW_List.replace(3, list.at(4));
        DCW_Compensate_Result = list.at(4).toDouble();
        ui->doubleSpinBox_Compensate->setValue(list.at(4).toDouble());
    } else if (str == QString(tr("comp_enable"))) {
        qDebug() << list.at(4);
        if (list.at(4).toInt() == 1) {
            DCW_Compensate_Flag = true;
        } else {
            DCW_Compensate_Flag = false;
        }
        Copy_DCW_List.replace(2, list.at(4));
    } else {
        //
    }
    Init_Flag = false;
}

QStringList Widget_DCW::DCW_Test_Result(QStringList DCW_Data)
{
    QStringList Back_QStringList;  Back_QStringList.clear();
    bool IRDCW_True_Value;
    int  DCW_volt;
    int  DCW_Test_Count;
    double DCW_Show_Data;
    int DCW_Judge;

    IRDCW_True_Value = DCW_Data.at(0).toInt();
    DCW_volt = DCW_Data.at(1).toInt();
    DCW_Test_Count = DCW_Data.at(2).toInt();
    DCW_Show_Data = DCW_Data.at(3).toDouble();
    DCW_Judge = DCW_Data.at(4).toInt();

    if (DCW_Between_IR) {
        if (IRDCW_True_Value) {
            DCW_volt = Copy_DCW_List.at(32+(DCWgroup_num.at(DCW_Test_Count).toInt())*16).toInt();
        }
        Back_QStringList.append(QString::number(DCW_volt)+"V, ");
    } else {
        if (IRDCW_True_Value) {
            DCW_volt = Copy_DCW_List.at(20).toInt();
        }
        Back_QStringList.append(QString::number(DCW_volt)+"V, ");
    }


    if (DCW_Compensate_Flag) { // -交耐补偿
        Back_QStringList.append(QString::number(DCW_Show_Data-(DCW_Compensate_Result)));
    } else {
        Back_QStringList.append(QString::number(DCW_Show_Data));
    }
    Back_QStringList.append(QString::number(DCW_Judge));

    return Back_QStringList;
}

QStringList Widget_DCW::DCW_Test_Param()
{
    int j;
    j = 0;
    QString str;
    QStringList strSql;
    QStringList strTest, strParam;
    strTest.clear();
    strParam.clear();
    if (DCW_Between_IR) {
        for (j = 0; j < 4; j++) {
            if (Copy_DCW_List[40+j*16].toInt()  ==  2) {
                str = QString(tr("直耐")) + QString::number(j+1);
                strTest.append(str);
                str.clear();
                str += QString(tr("高端:"));
                str += Copy_DCW_List.at(30+j*16); str += QString(tr(" "));
                str += Copy_DCW_List.at(32+j*16); str += "V,";
                str += Copy_DCW_List.at(34+j*16); str += "mA,ARC:";
                str += Copy_DCW_List.at(35+j*16);
                strParam.append(str);
                str.clear();
                strSql.append(tr("直耐"));
            }
        }
    } else {
        str = QString(tr("直耐"));
        strTest.append(str);
        str.clear();
        str += ui->double_Volt->text();   str += "V,";
        str += ui->double_I_Up->text();   str += "mA,ARC:";
        str += ui->comb_ARC->currentText();
        strParam.append(str);
        str.clear();
        strSql.append(tr("直耐"));
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

bool Widget_DCW::DCW_If_Compensate(QString DCW_Between_IR)
{
    if (DCW_Compensate_Flag) {
        DCW_Compensate_Flag = false;
        Copy_DCW_List.replace(2, "0");
        Copy_DCW_List.replace(3, "0");
        ui->doubleSpinBox_Compensate->setValue(0);
        return true;
    } else {
        Pri_DCW_Init(DCW_Between_IR);
        frame.can_id = 0x23;  frame.can_dlc = 0x05;
        frame.data[0] = 0x01;
        frame.data[1] = 0x07;
        frame.data[2] = 0x00;
        frame.data[3] = 0x13;
        frame.data[4] = 0x00;
        canSend(frame);
        return false;
    }
}

bool Widget_DCW::DCW_Back_Key_E()
{
    if (DCW_Between_IR) {
        DCW_Compensate_Flag = false;
    }

    if (DCW_Compensate_Flag) {
        return 1;
    } else {
        return 0;
    }
}

int Widget_DCW::DCW_Compensate(double Compensate_Value)
{
    if (DCW_Compensate_Flag) { //  DCW_Compensate_Flag!=0
        return 0;
    }
    DCW_Compensate_Result = Compensate_Value;
    if (DCW_Compensate_Result < 3) {
        DCW_Compensate_Flag = true;
        Copy_DCW_List.replace(2, "1");
        Copy_DCW_List.replace(3, QString::number(DCW_Compensate_Result, 'f', 2));
        ui->doubleSpinBox_Compensate->setValue(Copy_DCW_List.at(3).toDouble());
        return 1;
    } else {
        frame.can_id = 0x23;  frame.can_dlc = 0x01;
        frame.data[0] = 0x02;
        canSend(frame);
        DCW_Compensate_Flag = false;
        return 2;
    }
}

void Widget_DCW::Pri_DCW_Param_Init(QString list) {
    ui->double_I_Down->setMaximum(list.toDouble());
    ui->double_I_Up->setMaximum(list.toDouble());
}

void Widget_DCW::Pub_Conf_Set_DCW(QString str, int value) {
    switch (value) {
    case 1:
        Pri_DCW_Init(str);
        break;
    case 2:
        Pri_DCW_Save_Data();
        if (DCW_Between_IR) {
            box_statechange();
        } else {
            //
        }
        break;
    case 3:
        Pri_DCW_Default_value();
        break;
    case 5:
        Pri_DCW_Test();
        break;
    case 9:
        Pri_DCW_Param_Init(str);
        break;
    case 100:
        if (str.toInt()) {
            Init_Channel_6 = true;
        } else {
            Init_Channel_6 = false;
        }
        break;
    case 103:
        if (str.toInt() > 100) {
            volt_set = str.toInt();
        } else {
            volt_set = 3000;
        }
        break;
    default:
        //
        break;
    }
}
