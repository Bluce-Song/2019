/********************************************************************************
** Form generated from reading UI file 'widget_noload.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_NOLOAD_H
#define UI_WIDGET_NOLOAD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_Noload
{
public:
    QTableWidget *noloadTab;
    QTableWidget *noload_time_series;
    QLabel *label;
    QFrame *frame;
    QLabel *label_noload_power;
    QComboBox *Com_Power;
    QDoubleSpinBox *noload_volt;
    QLabel *label_noload_volt;
    QDoubleSpinBox *noload_vsp;
    QLabel *label_noload_vcc;
    QDoubleSpinBox *noload_vcc;
    QLabel *label_noload_vsp;
    QFrame *frame_2;
    QLabel *label_noload_power_2;
    QComboBox *Com_Turn;
    QLabel *label_noload_power_3;
    QDoubleSpinBox *noload_count;
    QFrame *frame_4;
    QComboBox *Com_Drive;
    QLabel *label_noload_drive;
    QLabel *label_vcc_drive;
    QComboBox *Com_Vcc_Drive;
    QFrame *frame_5;
    QLabel *label_noload_volt_2;
    QDoubleSpinBox *noload_GAIN;
    QLabel *label_noload_volt_3;
    QLabel *label_noload_volt_4;
    QDoubleSpinBox *noload_Ripple;
    QDoubleSpinBox *noload_Bandwidth;
    QLabel *label_noload_drive_2;
    QDoubleSpinBox *noload_pwmvsp;
    QPushButton *pushButton;
    QLabel *label_noload_time;
    QDoubleSpinBox *noload_time;
    QDoubleSpinBox *noload_item;

    void setupUi(QWidget *Widget_Noload)
    {
        if (Widget_Noload->objectName().isEmpty())
            Widget_Noload->setObjectName(QString::fromUtf8("Widget_Noload"));
        Widget_Noload->resize(721, 600);
        QFont font;
        font.setPointSize(11);
        Widget_Noload->setFont(font);
        noloadTab = new QTableWidget(Widget_Noload);
        if (noloadTab->columnCount() < 5)
            noloadTab->setColumnCount(5);
        QFont font1;
        font1.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem->setFont(font1);
        noloadTab->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setText(QString::fromUtf8("\347\224\265\346\265\201"));
        __qtablewidgetitem1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem1->setFont(font1);
        noloadTab->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setText(QString::fromUtf8("\347\224\265\345\216\213"));
        __qtablewidgetitem2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem2->setFont(font1);
        noloadTab->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setText(QString::fromUtf8("\345\212\237\347\216\207"));
        __qtablewidgetitem3->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem3->setFont(font1);
        noloadTab->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setText(QString::fromUtf8("\350\275\254\351\200\237"));
        __qtablewidgetitem4->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem4->setFont(font1);
        noloadTab->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        noloadTab->setObjectName(QString::fromUtf8("noloadTab"));
        noloadTab->setGeometry(QRect(30, 210, 583, 117));
        noloadTab->setFocusPolicy(Qt::NoFocus);
        noloadTab->setInputMethodHints(Qt::ImhNone);
        noloadTab->setEditTriggers(QAbstractItemView::AllEditTriggers);
        noloadTab->setAlternatingRowColors(false);
        noloadTab->setSelectionMode(QAbstractItemView::SingleSelection);
        noloadTab->horizontalHeader()->setDefaultSectionSize(50);
        noloadTab->horizontalHeader()->setStretchLastSection(true);
        noloadTab->verticalHeader()->setVisible(false);
        noloadTab->verticalHeader()->setDefaultSectionSize(40);
        noload_time_series = new QTableWidget(Widget_Noload);
        if (noload_time_series->columnCount() < 11)
            noload_time_series->setColumnCount(11);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem5->setFont(font1);
        noload_time_series->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem6->setFont(font1);
        noload_time_series->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem7->setFont(font1);
        noload_time_series->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem8->setFont(font1);
        noload_time_series->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem9->setFont(font1);
        noload_time_series->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem10->setFont(font1);
        noload_time_series->setHorizontalHeaderItem(5, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem11->setFont(font1);
        noload_time_series->setHorizontalHeaderItem(6, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem12->setFont(font1);
        noload_time_series->setHorizontalHeaderItem(7, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem13->setFont(font1);
        noload_time_series->setHorizontalHeaderItem(8, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem14->setFont(font1);
        noload_time_series->setHorizontalHeaderItem(9, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem15->setFont(font1);
        noload_time_series->setHorizontalHeaderItem(10, __qtablewidgetitem15);
        noload_time_series->setObjectName(QString::fromUtf8("noload_time_series"));
        noload_time_series->setGeometry(QRect(30, 320, 583, 77));
        noload_time_series->setFocusPolicy(Qt::NoFocus);
        noload_time_series->setInputMethodHints(Qt::ImhNone);
        noload_time_series->setEditTriggers(QAbstractItemView::AllEditTriggers);
        noload_time_series->setAlternatingRowColors(false);
        noload_time_series->setSelectionMode(QAbstractItemView::SingleSelection);
        noload_time_series->horizontalHeader()->setDefaultSectionSize(50);
        noload_time_series->horizontalHeader()->setStretchLastSection(true);
        noload_time_series->verticalHeader()->setVisible(false);
        noload_time_series->verticalHeader()->setDefaultSectionSize(40);
        label = new QLabel(Widget_Noload);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 400, 583, 201));
        label->setPixmap(QPixmap(QString::fromUtf8(":/image/Time.png")));
        label->setScaledContents(true);
        frame = new QFrame(Widget_Noload);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(30, 10, 211, 201));
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_noload_power = new QLabel(frame);
        label_noload_power->setObjectName(QString::fromUtf8("label_noload_power"));
        label_noload_power->setGeometry(QRect(10, 10, 71, 40));
        label_noload_power->setFont(font1);
        label_noload_power->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_noload_power->setAlignment(Qt::AlignCenter);
        Com_Power = new QComboBox(frame);
        Com_Power->setObjectName(QString::fromUtf8("Com_Power"));
        Com_Power->setGeometry(QRect(90, 10, 101, 40));
        Com_Power->setMinimumSize(QSize(66, 0));
        Com_Power->setMaximumSize(QSize(200, 50));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu"));
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(9);
        Com_Power->setFont(font2);
        Com_Power->setStyleSheet(QString::fromUtf8("\n"
"QComboBox {\n"
"font: 75 14pt \"Ubuntu\";\n"
"	color: rgb(255, 255, 255);\n"
"    border: 1px solid #32435E;\n"
"    border-radius: 3px;\n"
"    padding: 1px 10px 1px 3px;\n"
"    background:qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0 #080B10,stop:1 #212C3F);\n"
"}\n"
"QComboBox::down-arrow {\n"
"    image: url(:image/downarrow.png);\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 25px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: 32435E;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"	color: rgb(255, 255, 255);\n"
"    border: 2px solid #32435E;\n"
"    selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #506B79,stop: 1.0 #0D95A6);\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #1B2534, stop: 0.4 #010101,stop: 0.5 #000101, stop: 1.0 #1F2B3C);\n"
"}"));
        noload_volt = new QDoubleSpinBox(frame);
        noload_volt->setObjectName(QString::fromUtf8("noload_volt"));
        noload_volt->setGeometry(QRect(90, 55, 101, 40));
        noload_volt->setAlignment(Qt::AlignCenter);
        noload_volt->setButtonSymbols(QAbstractSpinBox::NoButtons);
        noload_volt->setDecimals(2);
        noload_volt->setMinimum(1);
        noload_volt->setMaximum(9999);
        noload_volt->setSingleStep(1);
        noload_volt->setValue(1);
        label_noload_volt = new QLabel(frame);
        label_noload_volt->setObjectName(QString::fromUtf8("label_noload_volt"));
        label_noload_volt->setGeometry(QRect(0, 55, 91, 40));
        label_noload_volt->setFont(font1);
        label_noload_volt->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_noload_volt->setAlignment(Qt::AlignCenter);
        noload_vsp = new QDoubleSpinBox(frame);
        noload_vsp->setObjectName(QString::fromUtf8("noload_vsp"));
        noload_vsp->setGeometry(QRect(90, 145, 101, 40));
        noload_vsp->setAlignment(Qt::AlignCenter);
        noload_vsp->setButtonSymbols(QAbstractSpinBox::NoButtons);
        noload_vsp->setDecimals(2);
        noload_vsp->setMinimum(0);
        noload_vsp->setMaximum(9999);
        noload_vsp->setSingleStep(1);
        noload_vsp->setValue(1);
        label_noload_vcc = new QLabel(frame);
        label_noload_vcc->setObjectName(QString::fromUtf8("label_noload_vcc"));
        label_noload_vcc->setGeometry(QRect(0, 100, 91, 40));
        label_noload_vcc->setFont(font1);
        label_noload_vcc->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_noload_vcc->setAlignment(Qt::AlignCenter);
        noload_vcc = new QDoubleSpinBox(frame);
        noload_vcc->setObjectName(QString::fromUtf8("noload_vcc"));
        noload_vcc->setGeometry(QRect(90, 100, 101, 40));
        noload_vcc->setAlignment(Qt::AlignCenter);
        noload_vcc->setButtonSymbols(QAbstractSpinBox::NoButtons);
        noload_vcc->setDecimals(2);
        noload_vcc->setMinimum(0);
        noload_vcc->setMaximum(9999);
        noload_vcc->setSingleStep(1);
        noload_vcc->setValue(1);
        label_noload_vsp = new QLabel(frame);
        label_noload_vsp->setObjectName(QString::fromUtf8("label_noload_vsp"));
        label_noload_vsp->setGeometry(QRect(0, 145, 91, 40));
        label_noload_vsp->setFont(font1);
        label_noload_vsp->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_noload_vsp->setAlignment(Qt::AlignCenter);
        frame_2 = new QFrame(Widget_Noload);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(250, 110, 201, 101));
        frame_2->setStyleSheet(QString::fromUtf8(""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_noload_power_2 = new QLabel(frame_2);
        label_noload_power_2->setObjectName(QString::fromUtf8("label_noload_power_2"));
        label_noload_power_2->setGeometry(QRect(10, 5, 71, 41));
        label_noload_power_2->setFont(font1);
        label_noload_power_2->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_noload_power_2->setAlignment(Qt::AlignCenter);
        Com_Turn = new QComboBox(frame_2);
        Com_Turn->setObjectName(QString::fromUtf8("Com_Turn"));
        Com_Turn->setGeometry(QRect(90, 5, 101, 40));
        Com_Turn->setMinimumSize(QSize(66, 0));
        Com_Turn->setMaximumSize(QSize(200, 50));
        Com_Turn->setFont(font2);
        Com_Turn->setStyleSheet(QString::fromUtf8("\n"
"QComboBox {\n"
"font: 75 14pt \"Ubuntu\";\n"
"	color: rgb(255, 255, 255);\n"
"    border: 1px solid #32435E;\n"
"    border-radius: 3px;\n"
"    padding: 1px 10px 1px 3px;\n"
"    background:qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0 #080B10,stop:1 #212C3F);\n"
"}\n"
"QComboBox::down-arrow {\n"
"    image: url(:image/downarrow.png);\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 25px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: 32435E;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"	color: rgb(255, 255, 255);\n"
"    border: 2px solid #32435E;\n"
"    selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #506B79,stop: 1.0 #0D95A6);\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #1B2534, stop: 0.4 #010101,stop: 0.5 #000101, stop: 1.0 #1F2B3C);\n"
"}"));
        label_noload_power_3 = new QLabel(frame_2);
        label_noload_power_3->setObjectName(QString::fromUtf8("label_noload_power_3"));
        label_noload_power_3->setGeometry(QRect(10, 50, 71, 41));
        label_noload_power_3->setFont(font1);
        label_noload_power_3->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_noload_power_3->setAlignment(Qt::AlignCenter);
        noload_count = new QDoubleSpinBox(frame_2);
        noload_count->setObjectName(QString::fromUtf8("noload_count"));
        noload_count->setGeometry(QRect(90, 50, 101, 40));
        noload_count->setAlignment(Qt::AlignCenter);
        noload_count->setButtonSymbols(QAbstractSpinBox::NoButtons);
        noload_count->setDecimals(0);
        noload_count->setMinimum(1);
        noload_count->setMaximum(10);
        noload_count->setSingleStep(1);
        noload_count->setValue(1);
        frame_4 = new QFrame(Widget_Noload);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(250, 10, 201, 101));
        frame_4->setStyleSheet(QString::fromUtf8(""));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        Com_Drive = new QComboBox(frame_4);
        Com_Drive->setObjectName(QString::fromUtf8("Com_Drive"));
        Com_Drive->setGeometry(QRect(90, 5, 101, 40));
        Com_Drive->setMinimumSize(QSize(66, 0));
        Com_Drive->setMaximumSize(QSize(200, 50));
        Com_Drive->setFont(font2);
        Com_Drive->setStyleSheet(QString::fromUtf8("\n"
"QComboBox {\n"
"font: 75 14pt \"Ubuntu\";\n"
"	color: rgb(255, 255, 255);\n"
"    border: 1px solid #32435E;\n"
"    border-radius: 3px;\n"
"    padding: 1px 10px 1px 3px;\n"
"    background:qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0 #080B10,stop:1 #212C3F);\n"
"}\n"
"QComboBox::down-arrow {\n"
"    image: url(:image/downarrow.png);\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 25px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: 32435E;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"	color: rgb(255, 255, 255);\n"
"    border: 2px solid #32435E;\n"
"    selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #506B79,stop: 1.0 #0D95A6);\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #1B2534, stop: 0.4 #010101,stop: 0.5 #000101, stop: 1.0 #1F2B3C);\n"
"}"));
        label_noload_drive = new QLabel(frame_4);
        label_noload_drive->setObjectName(QString::fromUtf8("label_noload_drive"));
        label_noload_drive->setGeometry(QRect(10, 5, 71, 40));
        label_noload_drive->setFont(font1);
        label_noload_drive->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_noload_drive->setAlignment(Qt::AlignCenter);
        label_vcc_drive = new QLabel(frame_4);
        label_vcc_drive->setObjectName(QString::fromUtf8("label_vcc_drive"));
        label_vcc_drive->setGeometry(QRect(10, 55, 71, 40));
        label_vcc_drive->setFont(font1);
        label_vcc_drive->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_vcc_drive->setAlignment(Qt::AlignCenter);
        Com_Vcc_Drive = new QComboBox(frame_4);
        Com_Vcc_Drive->setObjectName(QString::fromUtf8("Com_Vcc_Drive"));
        Com_Vcc_Drive->setGeometry(QRect(90, 55, 101, 40));
        Com_Vcc_Drive->setMinimumSize(QSize(66, 0));
        Com_Vcc_Drive->setMaximumSize(QSize(200, 50));
        Com_Vcc_Drive->setFont(font2);
        Com_Vcc_Drive->setStyleSheet(QString::fromUtf8("\n"
"QComboBox {\n"
"font: 75 14pt \"Ubuntu\";\n"
"	color: rgb(255, 255, 255);\n"
"    border: 1px solid #32435E;\n"
"    border-radius: 3px;\n"
"    padding: 1px 10px 1px 3px;\n"
"    background:qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0 #080B10,stop:1 #212C3F);\n"
"}\n"
"QComboBox::down-arrow {\n"
"    image: url(:image/downarrow.png);\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 25px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: 32435E;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"	color: rgb(255, 255, 255);\n"
"    border: 2px solid #32435E;\n"
"    selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #506B79,stop: 1.0 #0D95A6);\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #1B2534, stop: 0.4 #010101,stop: 0.5 #000101, stop: 1.0 #1F2B3C);\n"
"}"));
        frame_5 = new QFrame(Widget_Noload);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(460, 10, 151, 201));
        frame_5->setStyleSheet(QString::fromUtf8(""));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        label_noload_volt_2 = new QLabel(frame_5);
        label_noload_volt_2->setObjectName(QString::fromUtf8("label_noload_volt_2"));
        label_noload_volt_2->setGeometry(QRect(10, 10, 71, 40));
        label_noload_volt_2->setFont(font1);
        label_noload_volt_2->setStyleSheet(QString::fromUtf8(""));
        label_noload_volt_2->setAlignment(Qt::AlignCenter);
        noload_GAIN = new QDoubleSpinBox(frame_5);
        noload_GAIN->setObjectName(QString::fromUtf8("noload_GAIN"));
        noload_GAIN->setGeometry(QRect(80, 100, 60, 40));
        noload_GAIN->setAlignment(Qt::AlignCenter);
        noload_GAIN->setButtonSymbols(QAbstractSpinBox::NoButtons);
        noload_GAIN->setDecimals(0);
        noload_GAIN->setMinimum(0);
        noload_GAIN->setMaximum(5);
        noload_GAIN->setSingleStep(1);
        noload_GAIN->setValue(1);
        label_noload_volt_3 = new QLabel(frame_5);
        label_noload_volt_3->setObjectName(QString::fromUtf8("label_noload_volt_3"));
        label_noload_volt_3->setGeometry(QRect(10, 55, 71, 40));
        label_noload_volt_3->setFont(font1);
        label_noload_volt_3->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_noload_volt_3->setAlignment(Qt::AlignCenter);
        label_noload_volt_4 = new QLabel(frame_5);
        label_noload_volt_4->setObjectName(QString::fromUtf8("label_noload_volt_4"));
        label_noload_volt_4->setGeometry(QRect(10, 100, 71, 40));
        label_noload_volt_4->setFont(font1);
        label_noload_volt_4->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_noload_volt_4->setAlignment(Qt::AlignCenter);
        noload_Ripple = new QDoubleSpinBox(frame_5);
        noload_Ripple->setObjectName(QString::fromUtf8("noload_Ripple"));
        noload_Ripple->setGeometry(QRect(80, 10, 60, 40));
        noload_Ripple->setAlignment(Qt::AlignCenter);
        noload_Ripple->setButtonSymbols(QAbstractSpinBox::NoButtons);
        noload_Ripple->setDecimals(0);
        noload_Ripple->setMinimum(0);
        noload_Ripple->setMaximum(5);
        noload_Ripple->setSingleStep(1);
        noload_Ripple->setValue(1);
        noload_Bandwidth = new QDoubleSpinBox(frame_5);
        noload_Bandwidth->setObjectName(QString::fromUtf8("noload_Bandwidth"));
        noload_Bandwidth->setGeometry(QRect(80, 55, 60, 40));
        noload_Bandwidth->setAlignment(Qt::AlignCenter);
        noload_Bandwidth->setButtonSymbols(QAbstractSpinBox::NoButtons);
        noload_Bandwidth->setDecimals(0);
        noload_Bandwidth->setMinimum(0);
        noload_Bandwidth->setMaximum(5);
        noload_Bandwidth->setSingleStep(1);
        noload_Bandwidth->setValue(1);
        label_noload_drive_2 = new QLabel(frame_5);
        label_noload_drive_2->setObjectName(QString::fromUtf8("label_noload_drive_2"));
        label_noload_drive_2->setGeometry(QRect(10, 145, 71, 41));
        label_noload_drive_2->setFont(font1);
        label_noload_drive_2->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_noload_drive_2->setAlignment(Qt::AlignCenter);
        noload_pwmvsp = new QDoubleSpinBox(frame_5);
        noload_pwmvsp->setObjectName(QString::fromUtf8("noload_pwmvsp"));
        noload_pwmvsp->setEnabled(false);
        noload_pwmvsp->setGeometry(QRect(82, 145, 60, 40));
        noload_pwmvsp->setAlignment(Qt::AlignCenter);
        noload_pwmvsp->setButtonSymbols(QAbstractSpinBox::NoButtons);
        noload_pwmvsp->setDecimals(0);
        noload_pwmvsp->setMinimum(0);
        noload_pwmvsp->setMaximum(999);
        noload_pwmvsp->setSingleStep(1);
        noload_pwmvsp->setValue(1);
        pushButton = new QPushButton(frame_5);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(19, 140, 123, 51));
        label_noload_time = new QLabel(Widget_Noload);
        label_noload_time->setObjectName(QString::fromUtf8("label_noload_time"));
        label_noload_time->setGeometry(QRect(620, 20, 78, 40));
        label_noload_time->setFont(font1);
        label_noload_time->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_noload_time->setAlignment(Qt::AlignCenter);
        noload_time = new QDoubleSpinBox(Widget_Noload);
        noload_time->setObjectName(QString::fromUtf8("noload_time"));
        noload_time->setGeometry(QRect(620, 65, 78, 40));
        noload_time->setAlignment(Qt::AlignCenter);
        noload_time->setButtonSymbols(QAbstractSpinBox::NoButtons);
        noload_time->setDecimals(1);
        noload_time->setMinimum(1);
        noload_time->setMaximum(99999);
        noload_time->setSingleStep(1);
        noload_time->setValue(1);
        noload_item = new QDoubleSpinBox(Widget_Noload);
        noload_item->setObjectName(QString::fromUtf8("noload_item"));
        noload_item->setEnabled(false);
        noload_item->setGeometry(QRect(620, 110, 78, 40));
        noload_item->setAlignment(Qt::AlignCenter);
        noload_item->setButtonSymbols(QAbstractSpinBox::NoButtons);
        noload_item->setDecimals(0);
        noload_item->setMinimum(0);
        noload_item->setMaximum(999);
        noload_item->setSingleStep(1);
        noload_item->setValue(1);

        retranslateUi(Widget_Noload);

        QMetaObject::connectSlotsByName(Widget_Noload);
    } // setupUi

    void retranslateUi(QWidget *Widget_Noload)
    {
        Widget_Noload->setWindowTitle(QApplication::translate("Widget_Noload", "Form", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = noload_time_series->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QApplication::translate("Widget_Noload", "T0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = noload_time_series->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget_Noload", "T1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = noload_time_series->horizontalHeaderItem(3);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget_Noload", "T2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = noload_time_series->horizontalHeaderItem(4);
        ___qtablewidgetitem3->setText(QApplication::translate("Widget_Noload", "T3", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = noload_time_series->horizontalHeaderItem(5);
        ___qtablewidgetitem4->setText(QApplication::translate("Widget_Noload", "T4", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = noload_time_series->horizontalHeaderItem(6);
        ___qtablewidgetitem5->setText(QApplication::translate("Widget_Noload", "T5", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = noload_time_series->horizontalHeaderItem(7);
        ___qtablewidgetitem6->setText(QApplication::translate("Widget_Noload", "T6", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = noload_time_series->horizontalHeaderItem(8);
        ___qtablewidgetitem7->setText(QApplication::translate("Widget_Noload", "T7", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = noload_time_series->horizontalHeaderItem(9);
        ___qtablewidgetitem8->setText(QApplication::translate("Widget_Noload", "T8", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = noload_time_series->horizontalHeaderItem(10);
        ___qtablewidgetitem9->setText(QApplication::translate("Widget_Noload", "T9", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_noload_power->setText(QApplication::translate("Widget_Noload", "\347\224\265\346\272\220\357\274\232", 0, QApplication::UnicodeUTF8));
        Com_Power->clear();
        Com_Power->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("Widget_Noload", "\350\217\212\346\260\264", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_Noload", "\345\244\251\350\231\271", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_Noload", "\350\223\235\344\273\252", 0, QApplication::UnicodeUTF8)
        );
        label_noload_volt->setText(QApplication::translate("Widget_Noload", "vm\347\224\265\345\216\213(v)\357\274\232", 0, QApplication::UnicodeUTF8));
        label_noload_vcc->setText(QApplication::translate("Widget_Noload", "Vcc\347\224\265\345\216\213(v)\357\274\232", 0, QApplication::UnicodeUTF8));
        label_noload_vsp->setText(QApplication::translate("Widget_Noload", "Vsp\347\224\265\345\216\213(v)\357\274\232", 0, QApplication::UnicodeUTF8));
        label_noload_power_2->setText(QApplication::translate("Widget_Noload", "\350\275\254\345\220\221\357\274\232", 0, QApplication::UnicodeUTF8));
        Com_Turn->clear();
        Com_Turn->insertItems(0, QStringList()
         << QApplication::translate("Widget_Noload", "\344\270\215\346\265\213", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_Noload", "\351\241\272\346\227\266\351\222\210", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_Noload", "\351\200\206\346\227\266\351\222\210", 0, QApplication::UnicodeUTF8)
        );
        label_noload_power_3->setText(QApplication::translate("Widget_Noload", "\347\243\201\346\236\201\346\225\260\357\274\232", 0, QApplication::UnicodeUTF8));
        Com_Drive->clear();
        Com_Drive->insertItems(0, QStringList()
         << QApplication::translate("Widget_Noload", "\345\206\205\347\275\256", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_Noload", "\345\244\226\347\275\256", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_Noload", "\347\243\201\346\227\213", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_Noload", "\346\227\213\345\217\230", 0, QApplication::UnicodeUTF8)
        );
        label_noload_drive->setText(QApplication::translate("Widget_Noload", "\351\251\261\345\212\250\345\231\250\357\274\232", 0, QApplication::UnicodeUTF8));
        label_vcc_drive->setText(QApplication::translate("Widget_Noload", "vcc\351\251\261\345\212\250\357\274\232", 0, QApplication::UnicodeUTF8));
        Com_Vcc_Drive->clear();
        Com_Vcc_Drive->insertItems(0, QStringList()
         << QApplication::translate("Widget_Noload", "\345\206\205\347\275\256", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_Noload", "\345\244\226\347\275\256", 0, QApplication::UnicodeUTF8)
        );
        label_noload_volt_2->setText(QApplication::translate("Widget_Noload", "\347\272\271\346\263\242\357\274\232", 0, QApplication::UnicodeUTF8));
        label_noload_volt_3->setText(QApplication::translate("Widget_Noload", "\345\270\246\345\256\275\357\274\232", 0, QApplication::UnicodeUTF8));
        label_noload_volt_4->setText(QApplication::translate("Widget_Noload", "\345\242\236\347\233\212\357\274\232", 0, QApplication::UnicodeUTF8));
        label_noload_drive_2->setText(QApplication::translate("Widget_Noload", "\344\275\277\350\203\275\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Widget_Noload", "\350\241\245\345\201\277", 0, QApplication::UnicodeUTF8));
        label_noload_time->setText(QApplication::translate("Widget_Noload", "\346\265\213\350\257\225\346\227\266\351\227\264(S)\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget_Noload: public Ui_Widget_Noload {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_NOLOAD_H
