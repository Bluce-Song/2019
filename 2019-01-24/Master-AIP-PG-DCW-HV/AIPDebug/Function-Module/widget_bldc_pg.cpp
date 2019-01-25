/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "widget_bldc_pg.h"
#include "ui_widget_bldc_pg.h"

Widget_BLDC_PG::Widget_BLDC_PG(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_BLDC_PG)
{
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint); //-去掉标题栏
    ui->setupUi(this);

    //  电阻设置表头
    ui->bldcpgTab->horizontalHeader()->setStyleSheet\
            ("QHeaderView::section{background-color:#191919;color: white;"\
             "padding-left: 4px;border: 1px solid #447684;}");
    ui->bldcpgTab->horizontalHeader()->setFixedHeight(35);
    ui->bldcpgTab->horizontalHeader()->setResizeMode(QHeaderView::Fixed);

    ui->bldcpgTab->setColumnWidth(0, 121);
    ui->bldcpgTab->setColumnWidth(1, 100);
    ui->bldcpgTab->setColumnWidth(2, 100);
    ui->bldcpgTab->setColumnWidth(3, 100);

    PG_Button_Group = new QButtonGroup;
    PG_Button_Group->addButton(ui->HALL_A, 0);
    PG_Button_Group->addButton(ui->HALL_B, 1);
    PG_Button_Group->addButton(ui->HALL_C, 2);
    PG_Button_Group->addButton(ui->HALL_D, 3);
    PG_Button_Group->addButton(ui->HALL_E, 4);
    connect(PG_Button_Group, SIGNAL(buttonClicked(int)), \
            this, SLOT(buttonJudge(int)));

    PG_Check_Box_Group.clear();
    PG_Check_Box_Group.append(ui->checkBox_HALL_A);
    PG_Check_Box_Group.append(ui->checkBox_HALL_B);
    PG_Check_Box_Group.append(ui->checkBox_HALL_C);
    PG_Check_Box_Group.append(ui->checkBox_HALL_D);
    PG_Check_Box_Group.append(ui->checkBox_HALL_E);

    ui->label_bldcpg_conut->hide();
    ui->bldcpg_count->hide();
    Old_Id = 0;
    FG_Init_Flag = false;
}

Widget_BLDC_PG::~Widget_BLDC_PG()
{
    delete ui;
}

void Widget_BLDC_PG::Pri_PG_Init(QStringList list) {
    int i = 0;
    int pg_count = 0;
    FG_Init_Flag = true;
    pg_count = list.at(0).toInt();
    ui->bldcPG_volt->setValue(Copy_BLDCPG_List.at(0).toDouble());
    ui->bldcpg_count->setValue(Copy_BLDCPG_List.at(1).toDouble());
    wave_count = Copy_BLDCPG_List.at(2).toInt();
    ui->bldcPG_wave->setValue(wave_count);
    ui->Com_DLR->setCurrentIndex(Copy_BLDCPG_List.at(3).toInt());

    ui->bldcpgTab->setRowCount(0);
    ui->bldcpgTab->setRowCount(2);

    for (i = 0; i < 5; i++) {
        if ((1 << i) & pg_count) {
            //
        } else {
            PG_Button_Group->button(i)->hide();
            PG_Check_Box_Group.at(i)->hide();
        }
    }

    QStringList lisit;   lisit << QString(tr("下限")) << QString(tr("上限"));
    PG_QTableWidgetItem.clear();
    for (i = 0; i < 2; i++) {
        PG_QTableWidgetItem.append(new QTableWidgetItem);
        PG_QTableWidgetItem[i]->setTextAlignment(Qt::AlignCenter);
        PG_QTableWidgetItem[i]->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        PG_QTableWidgetItem[i]->setText(lisit.at(i));
        ui->bldcpgTab->setItem(i, 0, PG_QTableWidgetItem[i]);
    }
    for (i = 0; i < 2; i++) {
        QTableWidgetItem *pg_high = new QTableWidgetItem;    // 低电平
        pg_high->setTextAlignment(Qt::AlignCenter);
        pg_high->setText(Copy_BLDCPG_List.at(51 + i*15));
        ui->bldcpgTab->setItem(i, 1, pg_high);
        QTableWidgetItem *pg_low = new QTableWidgetItem;     // 高电平
        pg_low->setTextAlignment(Qt::AlignCenter);
        pg_low->setText(Copy_BLDCPG_List.at(50 + i*15));
        ui->bldcpgTab->setItem(i, 2, pg_low);
        QTableWidgetItem *pg_fre = new QTableWidgetItem;     // 频率
        pg_fre->setTextAlignment(Qt::AlignCenter);
        pg_fre->setText(Copy_BLDCPG_List.at(52 + i*15));
        ui->bldcpgTab->setItem(i, 3, pg_fre);
        QTableWidgetItem *pg_duty = new QTableWidgetItem;    // 占空比
        pg_duty->setTextAlignment(Qt::AlignCenter);
        pg_duty->setText(Copy_BLDCPG_List.at(53 + i*15));
        ui->bldcpgTab->setItem(i, 4, pg_duty);
    }
    for (int i = 0; i < 5; i++) {
        if (Copy_BLDCPG_List.at(40 + i).toInt() == 2) {
            PG_Check_Box_Group[i]->setChecked(true);
        }
    }
    FG_Init_Flag = false;
}

void Widget_BLDC_PG::Pri_PG_Data_Save() {
    Copy_BLDCPG_List.replace(0, QString::number(ui->bldcPG_volt->value()));
    Copy_BLDCPG_List.replace(1, QString::number(ui->bldcpg_count->value()));
  //  Copy_BLDCPG_List.replace(2, QString::number(ui->bldcPG_wave->value()));
     Copy_BLDCPG_List.replace(3, QString::number(ui->Com_DLR->currentIndex()));

    for (int i = 0; i < 2; i++) {
        Copy_BLDCPG_List.replace(51+(Old_Id)*30+i*15, ui->bldcpgTab->item(i, 1)->text());
        Copy_BLDCPG_List.replace(50+(Old_Id)*30+i*15, ui->bldcpgTab->item(i, 2)->text());
        Copy_BLDCPG_List.replace(52+(Old_Id)*30+i*15, ui->bldcpgTab->item(i, 3)->text());
        Copy_BLDCPG_List.replace(53+(Old_Id)*30+i*15, ui->bldcpgTab->item(i, 4)->text());
    }
    int i = 0, j = 0;
    j = 0;
    for (i = 0; i < 5; i++) {
        if (PG_Check_Box_Group[i]->checkState() == 2) {
            j++;
        }
    }
    if (j == 0) {
        j = 1;
        PG_Check_Box_Group[0]->setChecked(true);
    }

    for (i = 0; i < 5; i++) {
        Copy_BLDCPG_List.replace(40 + i, QString::number(PG_Check_Box_Group[i]->checkState()));
    }




    FG_Test_Data.clear();
    int Test_All_number = 0;
    Test_All_number = 0;
    QStringList Number_data;  Number_data.clear();
    QStringList Hall_Param;
    Hall_Param << "A" << "B" << "C" << "D" << "E";


    for (int i = 0; i < 5; i++) {
        if (Copy_BLDCPG_List.at(40 + i).toInt() == 2) {
            Test_All_number++;
            Number_data.append(Hall_Param.at(i));
        }
    }

    if (Test_All_number == 0) {
        Test_All_number = 1;
        Number_data.append(QString(tr("mA")));
    } else {
        //
    }

    FG_Test_Data << QString::number(Test_All_number) << Number_data;
    wave_count = 0;
    QStringList Hall_Count;
    Hall_Count << "E" << "D" << "C" << "B" << "A" << "Z" << "Y" << "X";
    for (j = 1; j < FG_Test_Data.size(); j++) {
        for (i = 0; i < 8; i++) {
            if (FG_Test_Data.at(j) == Hall_Count.at(i)) {
                wave_count = wave_count | (1 << (7 - i));
            }
        }
    }/**/
    wave_count = wave_count + (ui->Com_DLR->currentIndex() * 1000);
    ui->bldcPG_wave->setValue(wave_count);
    Copy_BLDCPG_List.replace(2, QString::number(wave_count));
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.11.5
  * brief:      Conf 配置 BLDCPG 界面
******************************************************************************/
void Widget_BLDC_PG::Pub_Conf_Set_PG(QStringList list, int flag)
{
    switch (flag) {
    case 1:
        Pri_PG_Init(list);
        break;
    case 2:
        Pri_PG_Data_Save();
        break;
    }
}

QStringList Widget_BLDC_PG::PG_Test_Param()
{
    QString str;
    QStringList strSql;
    QStringList strParam, strTest;
    strTest.clear();
    strParam.clear();

    FG_Test_Data.clear();
    int Test_All_number;
    Test_All_number = 0;
    QStringList Number_data;  Number_data.clear();

  /*  str = QString(tr("FG")); strTest.append(str);
    str = QString(tr("H ")) + Copy_BLDCPG_List.at(66) + QString(tr("V,"));
    str += QString(tr("L ")) + Copy_BLDCPG_List.at(65) + QString(tr("V,"));
    str += QString(tr("f ")) + Copy_BLDCPG_List.at(67) + QString(tr("Hz,"));
    str += Copy_BLDCPG_List.at(53)+QString(tr("%-")) + \
            Copy_BLDCPG_List.at(68)+QString(tr("%")); // 卧龙
    // str += Copy_BLDCPG_List.at(69)+QString(tr("-"))+\
    // Copy_BLDCPG_List.at(54)+QString(tr(","));
    // str += Copy_BLDCPG_List.at(55)+QString(tr("-"))+\
    // Copy_BLDCPG_List.at(70)+QString(tr(","));  // 卧龙
    // str += Copy_BLDCPG_List.at(56)+QString(tr("-"))+\
    // Copy_BLDCPG_List.at(71)+QString(tr(""));    // 卧龙
    strParam.append(str);
    strSql.append(tr("霍尔")); */

    QStringList Hall_Param;
    Hall_Param << "A" << "B" << "C" << "D" << "E";

    for (int i = 0; i < 5; i++) {
        if (Copy_BLDCPG_List.at(40 + i).toInt() == 2) {
            Test_All_number++;
            Number_data.append(Hall_Param.at(i));

            str = QString(tr("HALL-")) + Hall_Param.at(i);
            strTest.append(str);
            str = QString(tr("L-")) + Copy_BLDCPG_List.at(66 + i*30) + QString(tr("V,"));
            str += QString(tr("H-")) + Copy_BLDCPG_List.at(65 + i*30) + QString(tr("V,"));
            str += QString(tr("f-")) + Copy_BLDCPG_List.at(67 + i*30) + QString(tr("Hz"));
            str += QString(tr(" "));
            str += Copy_BLDCPG_List.at(53 + i*30)+QString(tr("%-")) + \
                    Copy_BLDCPG_List.at(68 + i*30)+QString(tr("%")); // 卧龙
            strParam.append(str);
            strSql.append(tr("霍尔"));
        }
    }

    QStringList Back_List;
    Back_List.append(QString::number(strTest.size()));
    Back_List.append(QString::number(strParam.size()));
    Back_List.append(QString::number(strSql.size()));
    Back_List.append(strTest);
    Back_List.append(strParam);
    Back_List.append(strSql);

    if (Test_All_number == 0) {
        Test_All_number = 1;
        Number_data.append(QString(tr("mA")));
    } else {
        //
    }
    FG_Test_Data << QString::number(Test_All_number) << Number_data;

    return Back_List;
}
void Widget_BLDC_PG::BLDCPG_NetData(QStringList list, QString str) {
    if (str == QString(tr("volt_low_min"))) {
        ui->bldcpgTab->item(0, 1)->setText(list.at(0));
    } else if (str == QString(tr("volt_low_max"))) {
        ui->bldcpgTab->item(1, 1)->setText(list.at(0));
    } else if (str == QString(tr("volt_up_min"))) {
        ui->bldcpgTab->item(0, 2)->setText(list.at(0));
        Pri_PG_Data_Save();
    } else if (str == QString(tr("volt_up_max"))) {
        ui->bldcpgTab->item(1, 2)->setText(list.at(0));
    } else if (str == QString(tr("freq_min"))) {
        ui->bldcpgTab->item(0, 3)->setText(list.at(0));
    } else if (str == QString(tr("freq_max"))) {
        ui->bldcpgTab->item(1, 3)->setText(list.at(0));
    } else if (str == QString(tr("duty_min"))) {
        ui->bldcpgTab->item(0, 4)->setText(list.at(0));
    } else if (str == QString(tr("duty_max"))) {
        ui->bldcpgTab->item(1, 4)->setText(list.at(0));
    } else if (str == QString(tr("count"))) {
        ui->bldcpg_count->setValue(list.at(0).toDouble());
    } else {
        //
    }
}

void Widget_BLDC_PG::buttonJudge(int id) {
//    if (Old_Id == 0) {
//        //
//    } else {
        PG_Button_Group->button(Old_Id)->setStyleSheet\
                ("background: qlineargradient(x1: 0,  y1: 0,  x2: 0,  y2: 1, "\
                 "stop: 0 #5B5F5F,  stop: 0.5 #0C2436, stop: 1 #27405A);"\
                 "color:rgb(255,  255,  255);");
        for (int i = 0; i < 2; i++) {
            Copy_BLDCPG_List.replace(51+(Old_Id)*30+i*15, ui->bldcpgTab->item(i, 1)->text());
            Copy_BLDCPG_List.replace(50+(Old_Id)*30+i*15, ui->bldcpgTab->item(i, 2)->text());
            Copy_BLDCPG_List.replace(52+(Old_Id)*30+i*15, ui->bldcpgTab->item(i, 3)->text());
            Copy_BLDCPG_List.replace(53+(Old_Id)*30+i*15, ui->bldcpgTab->item(i, 4)->text());
        }
//    }

    PG_Button_Group->button(id)->setStyleSheet\
            ("background: qlineargradient(x1: 0,  y1: 0,  x2: 0,  y2: 1,"\
             "stop: 0 #00A600,  stop: 0.5 #00A600, stop: 1 #27405A);"\
             "color:rgb(255,  255,  255);");
    QTableWidgetItem *FG_Item = new QTableWidgetItem;  // -PG信息
    FG_Item->setTextAlignment(Qt::AlignCenter);
    FG_Item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    FG_Item->setText(PG_Button_Group->button(id)->text());
    ui->bldcpgTab->setHorizontalHeaderItem(0, FG_Item);
    dd(id);
    Old_Id = id;
}
void Widget_BLDC_PG::dd(int data)
{
    int i;
    FG_Init_Flag = true;

    ui->bldcpgTab->setRowCount(0);
    ui->bldcpgTab->setRowCount(2);

    QStringList lisit;   lisit << QString(tr("下限")) << QString(tr("上限"));

    data = data*30;
    PG_QTableWidgetItem.clear();
    for (i = 0; i < 2; i++) {
        PG_QTableWidgetItem.append(new QTableWidgetItem);
        PG_QTableWidgetItem[i]->setTextAlignment(Qt::AlignCenter);
        PG_QTableWidgetItem[i]->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        PG_QTableWidgetItem[i]->setText(lisit.at(i));
        ui->bldcpgTab->setItem(i, 0, PG_QTableWidgetItem[i]);
    }
    for (i = 0; i < 2; i++) {
        QTableWidgetItem *pg_high = new QTableWidgetItem;    // 低电平
        pg_high->setTextAlignment(Qt::AlignCenter);
        pg_high->setText(Copy_BLDCPG_List.at(51 + data + i*15));
        ui->bldcpgTab->setItem(i, 1, pg_high);
        QTableWidgetItem *pg_low = new QTableWidgetItem;     // 高电平
        pg_low->setTextAlignment(Qt::AlignCenter);
        pg_low->setText(Copy_BLDCPG_List.at(50 + data + i*15));
        ui->bldcpgTab->setItem(i, 2, pg_low);
        QTableWidgetItem *pg_fre = new QTableWidgetItem;     // 频率
        pg_fre->setTextAlignment(Qt::AlignCenter);
        pg_fre->setText(Copy_BLDCPG_List.at(52 + data + i*15));
        ui->bldcpgTab->setItem(i, 3, pg_fre);
        QTableWidgetItem *pg_duty = new QTableWidgetItem;    // 占空比
        pg_duty->setTextAlignment(Qt::AlignCenter);
        pg_duty->setText(Copy_BLDCPG_List.at(53 + data + i*15));
        ui->bldcpgTab->setItem(i, 4, pg_duty);
    }
    qApp->processEvents();
    FG_Init_Flag = false;
}

void Widget_BLDC_PG::on_bldcpgTab_cellChanged(int row, int column)
{
    QString str;
    int i = 0, After_Point = 0;
    if (FG_Init_Flag) {
        return;
    } else {
        FG_Init_Flag = true;
    }
    FG_Init_Flag = true;
    str = ui->bldcpgTab->item(row, column)->text();
    if (str == NULL) {
        ui->bldcpgTab->item(row, column)->setText("0");
    }
    for (i = 0; i < str.length(); i++) { // 判断输入是" 0-9 . "
        if (((str[i] >= '0') && (str[i] <= '9')) || (str[i] == '.')) {
            //
        } else {
            ui->bldcpgTab->item(row, column)->setText("0");
            break;
        }
        if (str[i] == '.') { //  判断是否规范
            After_Point = str.length() - i - 1;
            if ((i == 0)) {
                ui->bldcpgTab->item(row, column)->setText("0");
            }
            if (i == (str.length() - 1)) {
                ui->bldcpgTab->item(row, column)->setText\
                        (ui->bldcpgTab->item(row, column)->text().left(i));
            }
        }
    }

    if (column == 1) { // 低电平
        if (ui->bldcpgTab->item(row, column)->text().toDouble() > 15) {
            ui->bldcpgTab->item(row, column)->setText("15.00");
        }
        ui->bldcpgTab->item(row, column)->setText\
                (QString::number(ui->bldcpgTab->item(row, column)->text().toDouble(), 'f', 2));
    }
    if (column == 2) { // 高电平
        if (ui->bldcpgTab->item(row, column)->text().toDouble() > 15) {
            ui->bldcpgTab->item(row, column)->setText("15.00");
        }
        ui->bldcpgTab->item(row, column)->setText\
                (QString::number(ui->bldcpgTab->item(row, column)->text().toDouble(), 'f', 2));
    }
    if (column == 3) { //频率
        if (ui->bldcpgTab->item(row, column)->text().toDouble() < 20) {
            ui->bldcpgTab->item(row, column)->setText("20.0");
        } else if (ui->bldcpgTab->item(row, column)->text().toDouble() > 500) {
            ui->bldcpgTab->item(row, column)->setText("900.0");
        }
        ui->bldcpgTab->item(row, column)->setText\
                (QString::number(ui->bldcpgTab->item(row, column)->text().toDouble(), 'f', 1));
    }
    if (column == 4) { //占空比
        if (ui->bldcpgTab->item(row, column)->text().toDouble() < 20) {
            ui->bldcpgTab->item(row, column)->setText("20.0");
        } else if (ui->bldcpgTab->item(row, column)->text().toDouble() > 80) {
            ui->bldcpgTab->item(row, column)->setText("80.0");
        }
        ui->bldcpgTab->item(row, column)->setText\
                (QString::number(ui->bldcpgTab->item(row, column)->text().toDouble(), 'f', 1));
    }

    if (column == 1) { // 低电平
        if ((ui->bldcpgTab->item(0, 1)->text().toDouble()) > \
                (ui->bldcpgTab->item(1, 1)->text().toDouble())) {
            ui->bldcpgTab->item(1, 1)->setText("0.00");
        }
    }
    if (column == 2) { // 高电平
        if ((ui->bldcpgTab->item(0, 2)->text().toDouble()) > \
                (ui->bldcpgTab->item(1, 2)->text().toDouble())) {
            ui->bldcpgTab->item(1, 2)->setText("0.00");
        }
    }
    if (column == 3) { // 频率
        if ((ui->bldcpgTab->item(0, 3)->text().toDouble()) > \
                (ui->bldcpgTab->item(1, 3)->text().toDouble())) {
            ui->bldcpgTab->item(1, 3)->setText("20.0");
        }
    }
    if (column == 4) { // 占空比
        if ((ui->bldcpgTab->item(0, 4)->text().toDouble()) > \
                (ui->bldcpgTab->item(1, 4)->text().toDouble())) {
            ui->bldcpgTab->item(1, 4)->setText("20.0");
        }
    }
    FG_Init_Flag = 0;
}
