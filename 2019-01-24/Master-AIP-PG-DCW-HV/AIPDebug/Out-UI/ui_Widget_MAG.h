/********************************************************************************
** Form generated from reading UI file 'Widget_MAG.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_MAG_H
#define UI_WIDGET_MAG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_MAG
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_12;
    QLineEdit *lineEdit_17;
    QLineEdit *lineEdit_18;
    QLineEdit *lineEdit_19;
    QLineEdit *lineEdit_20;
    QLineEdit *lineEdit_21;
    QLineEdit *lineEdit_22;
    QLineEdit *lineEdit_23;
    QLineEdit *lineEdit_24;
    QLabel *label_30;
    QLabel *label_29;
    QTableWidget *oppTab;
    QComboBox *combConf4_2;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_25;
    QLineEdit *lineEdit_26;
    QLineEdit *lineEdit_27;
    QLineEdit *lineEdit_28;
    QLineEdit *lineEdit_29;
    QLineEdit *lineEdit_30;
    QLineEdit *lineEdit_31;
    QLineEdit *lineEdit_32;
    QWidget *dockWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *Key_1;
    QPushButton *Key_2;
    QPushButton *Key_3;
    QPushButton *Key_4;
    QPushButton *Key_5;
    QPushButton *Key_6;
    QPushButton *Key_7;
    QPushButton *Key_8;
    QSpacerItem *verticalSpacer;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_1;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QComboBox *combConf_Station;
    QCheckBox *checkBox_zero;
    QPushButton *button_power;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_14;
    QLineEdit *lineEdit_15;
    QLineEdit *lineEdit_16;
    QLabel *label_31;
    QComboBox *combConf4_ROT2;

    void setupUi(QWidget *Widget_MAG)
    {
        if (Widget_MAG->objectName().isEmpty())
            Widget_MAG->setObjectName(QString::fromUtf8("Widget_MAG"));
        Widget_MAG->resize(700, 580);
        layoutWidget = new QWidget(Widget_MAG);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(700, 310, 60, 260));
        gridLayout_12 = new QGridLayout(layoutWidget);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        lineEdit_17 = new QLineEdit(layoutWidget);
        lineEdit_17->setObjectName(QString::fromUtf8("lineEdit_17"));
        lineEdit_17->setEnabled(true);
        lineEdit_17->setStyleSheet(QString::fromUtf8(""));

        gridLayout_12->addWidget(lineEdit_17, 0, 0, 1, 1);

        lineEdit_18 = new QLineEdit(layoutWidget);
        lineEdit_18->setObjectName(QString::fromUtf8("lineEdit_18"));
        lineEdit_18->setEnabled(true);

        gridLayout_12->addWidget(lineEdit_18, 1, 0, 1, 1);

        lineEdit_19 = new QLineEdit(layoutWidget);
        lineEdit_19->setObjectName(QString::fromUtf8("lineEdit_19"));

        gridLayout_12->addWidget(lineEdit_19, 2, 0, 1, 1);

        lineEdit_20 = new QLineEdit(layoutWidget);
        lineEdit_20->setObjectName(QString::fromUtf8("lineEdit_20"));

        gridLayout_12->addWidget(lineEdit_20, 3, 0, 1, 1);

        lineEdit_21 = new QLineEdit(layoutWidget);
        lineEdit_21->setObjectName(QString::fromUtf8("lineEdit_21"));

        gridLayout_12->addWidget(lineEdit_21, 4, 0, 1, 1);

        lineEdit_22 = new QLineEdit(layoutWidget);
        lineEdit_22->setObjectName(QString::fromUtf8("lineEdit_22"));

        gridLayout_12->addWidget(lineEdit_22, 5, 0, 1, 1);

        lineEdit_23 = new QLineEdit(layoutWidget);
        lineEdit_23->setObjectName(QString::fromUtf8("lineEdit_23"));

        gridLayout_12->addWidget(lineEdit_23, 6, 0, 1, 1);

        lineEdit_24 = new QLineEdit(layoutWidget);
        lineEdit_24->setObjectName(QString::fromUtf8("lineEdit_24"));

        gridLayout_12->addWidget(lineEdit_24, 7, 0, 1, 1);

        label_30 = new QLabel(Widget_MAG);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(560, 130, 121, 41));
        QFont font;
        font.setPointSize(17);
        label_30->setFont(font);
        label_30->setStyleSheet(QString::fromUtf8("border:2px groove #191919;\n"
"border-radius:8px;\n"
"\n"
"color: white;"));
        label_30->setAlignment(Qt::AlignCenter);
        label_29 = new QLabel(Widget_MAG);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(560, 70, 121, 41));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy);
        label_29->setFont(font);
        label_29->setStyleSheet(QString::fromUtf8("border:2px groove #447684;\n"
"border-radius:8px;\n"
"\n"
"color: white;"));
        label_29->setAlignment(Qt::AlignCenter);
        oppTab = new QTableWidget(Widget_MAG);
        if (oppTab->columnCount() < 6)
            oppTab->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        oppTab->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        oppTab->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        oppTab->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        oppTab->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        oppTab->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        oppTab->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        oppTab->setObjectName(QString::fromUtf8("oppTab"));
        oppTab->setGeometry(QRect(0, 7, 531, 550));
        oppTab->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        oppTab->setEditTriggers(QAbstractItemView::AllEditTriggers);
        oppTab->setTabKeyNavigation(true);
        oppTab->setDragDropOverwriteMode(false);
        oppTab->setSelectionMode(QAbstractItemView::SingleSelection);
        oppTab->horizontalHeader()->setDefaultSectionSize(50);
        oppTab->horizontalHeader()->setStretchLastSection(true);
        oppTab->verticalHeader()->setVisible(false);
        oppTab->verticalHeader()->setDefaultSectionSize(64);
        oppTab->verticalHeader()->setMinimumSectionSize(40);
        combConf4_2 = new QComboBox(Widget_MAG);
        combConf4_2->setObjectName(QString::fromUtf8("combConf4_2"));
        combConf4_2->setGeometry(QRect(560, 170, 121, 50));
        combConf4_2->setMinimumSize(QSize(66, 0));
        combConf4_2->setMaximumSize(QSize(200, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(9);
        combConf4_2->setFont(font1);
        combConf4_2->setStyleSheet(QString::fromUtf8("\n"
"QComboBox {\n"
"font: 75 18pt \"Ubuntu\";\n"
"	color: rgb(255, 255, 255);\n"
"    border: 1px solid #32435E;\n"
"    border-radius: 3px;\n"
"    padding: 1px 18px 1px 3px;\n"
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
"}\n"
""));
        layoutWidget_3 = new QWidget(Widget_MAG);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(700, 310, 60, 260));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_25 = new QLineEdit(layoutWidget_3);
        lineEdit_25->setObjectName(QString::fromUtf8("lineEdit_25"));

        verticalLayout_2->addWidget(lineEdit_25);

        lineEdit_26 = new QLineEdit(layoutWidget_3);
        lineEdit_26->setObjectName(QString::fromUtf8("lineEdit_26"));

        verticalLayout_2->addWidget(lineEdit_26);

        lineEdit_27 = new QLineEdit(layoutWidget_3);
        lineEdit_27->setObjectName(QString::fromUtf8("lineEdit_27"));

        verticalLayout_2->addWidget(lineEdit_27);

        lineEdit_28 = new QLineEdit(layoutWidget_3);
        lineEdit_28->setObjectName(QString::fromUtf8("lineEdit_28"));

        verticalLayout_2->addWidget(lineEdit_28);

        lineEdit_29 = new QLineEdit(layoutWidget_3);
        lineEdit_29->setObjectName(QString::fromUtf8("lineEdit_29"));

        verticalLayout_2->addWidget(lineEdit_29);

        lineEdit_30 = new QLineEdit(layoutWidget_3);
        lineEdit_30->setObjectName(QString::fromUtf8("lineEdit_30"));

        verticalLayout_2->addWidget(lineEdit_30);

        lineEdit_31 = new QLineEdit(layoutWidget_3);
        lineEdit_31->setObjectName(QString::fromUtf8("lineEdit_31"));

        verticalLayout_2->addWidget(lineEdit_31);

        lineEdit_32 = new QLineEdit(layoutWidget_3);
        lineEdit_32->setObjectName(QString::fromUtf8("lineEdit_32"));

        verticalLayout_2->addWidget(lineEdit_32);

        dockWidget = new QWidget(Widget_MAG);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidget->setGeometry(QRect(200, 30, 101, 521));
        dockWidget->setMinimumSize(QSize(80, 0));
        verticalLayoutWidget = new QWidget(dockWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 10, 91, 498));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Key_1 = new QPushButton(verticalLayoutWidget);
        Key_1->setObjectName(QString::fromUtf8("Key_1"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(85);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Key_1->sizePolicy().hasHeightForWidth());
        Key_1->setSizePolicy(sizePolicy1);
        Key_1->setMinimumSize(QSize(85, 56));
        Key_1->setMaximumSize(QSize(16777215, 56));

        verticalLayout->addWidget(Key_1);

        Key_2 = new QPushButton(verticalLayoutWidget);
        Key_2->setObjectName(QString::fromUtf8("Key_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Key_2->sizePolicy().hasHeightForWidth());
        Key_2->setSizePolicy(sizePolicy2);
        Key_2->setMinimumSize(QSize(85, 56));
        Key_2->setMaximumSize(QSize(85, 56));

        verticalLayout->addWidget(Key_2);

        Key_3 = new QPushButton(verticalLayoutWidget);
        Key_3->setObjectName(QString::fromUtf8("Key_3"));
        sizePolicy2.setHeightForWidth(Key_3->sizePolicy().hasHeightForWidth());
        Key_3->setSizePolicy(sizePolicy2);
        Key_3->setMinimumSize(QSize(85, 56));
        Key_3->setMaximumSize(QSize(85, 56));

        verticalLayout->addWidget(Key_3);

        Key_4 = new QPushButton(verticalLayoutWidget);
        Key_4->setObjectName(QString::fromUtf8("Key_4"));
        sizePolicy2.setHeightForWidth(Key_4->sizePolicy().hasHeightForWidth());
        Key_4->setSizePolicy(sizePolicy2);
        Key_4->setMinimumSize(QSize(85, 56));
        Key_4->setMaximumSize(QSize(85, 56));

        verticalLayout->addWidget(Key_4);

        Key_5 = new QPushButton(verticalLayoutWidget);
        Key_5->setObjectName(QString::fromUtf8("Key_5"));
        sizePolicy2.setHeightForWidth(Key_5->sizePolicy().hasHeightForWidth());
        Key_5->setSizePolicy(sizePolicy2);
        Key_5->setMinimumSize(QSize(85, 56));
        Key_5->setMaximumSize(QSize(85, 56));

        verticalLayout->addWidget(Key_5);

        Key_6 = new QPushButton(verticalLayoutWidget);
        Key_6->setObjectName(QString::fromUtf8("Key_6"));
        sizePolicy2.setHeightForWidth(Key_6->sizePolicy().hasHeightForWidth());
        Key_6->setSizePolicy(sizePolicy2);
        Key_6->setMinimumSize(QSize(85, 56));
        Key_6->setMaximumSize(QSize(85, 56));

        verticalLayout->addWidget(Key_6);

        Key_7 = new QPushButton(verticalLayoutWidget);
        Key_7->setObjectName(QString::fromUtf8("Key_7"));
        sizePolicy2.setHeightForWidth(Key_7->sizePolicy().hasHeightForWidth());
        Key_7->setSizePolicy(sizePolicy2);
        Key_7->setMinimumSize(QSize(85, 56));
        Key_7->setMaximumSize(QSize(85, 56));

        verticalLayout->addWidget(Key_7);

        Key_8 = new QPushButton(verticalLayoutWidget);
        Key_8->setObjectName(QString::fromUtf8("Key_8"));
        sizePolicy2.setHeightForWidth(Key_8->sizePolicy().hasHeightForWidth());
        Key_8->setSizePolicy(sizePolicy2);
        Key_8->setMinimumSize(QSize(85, 56));
        Key_8->setMaximumSize(QSize(85, 56));

        verticalLayout->addWidget(Key_8);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalLayoutWidget_2 = new QWidget(Widget_MAG);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(700, 310, 60, 260));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEdit_1 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_1->setObjectName(QString::fromUtf8("lineEdit_1"));

        verticalLayout_3->addWidget(lineEdit_1);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout_3->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout_3->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        verticalLayout_3->addWidget(lineEdit_4);

        lineEdit_5 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        verticalLayout_3->addWidget(lineEdit_5);

        lineEdit_6 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        verticalLayout_3->addWidget(lineEdit_6);

        lineEdit_7 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        verticalLayout_3->addWidget(lineEdit_7);

        lineEdit_8 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));

        verticalLayout_3->addWidget(lineEdit_8);

        combConf_Station = new QComboBox(Widget_MAG);
        combConf_Station->setObjectName(QString::fromUtf8("combConf_Station"));
        combConf_Station->setEnabled(false);
        combConf_Station->setGeometry(QRect(560, 20, 121, 50));
        combConf_Station->setMinimumSize(QSize(66, 0));
        combConf_Station->setMaximumSize(QSize(200, 50));
        combConf_Station->setFont(font1);
        combConf_Station->setStyleSheet(QString::fromUtf8("\n"
"QComboBox {\n"
"font: 75 18pt \"Ubuntu\";\n"
"	color: rgb(255, 255, 255);\n"
"    border: 1px solid #32435E;\n"
"    border-radius: 3px;\n"
"    padding: 1px 18px 1px 3px;\n"
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
"}\n"
""));
        checkBox_zero = new QCheckBox(Widget_MAG);
        checkBox_zero->setObjectName(QString::fromUtf8("checkBox_zero"));
        checkBox_zero->setGeometry(QRect(550, 510, 141, 41));
        QFont font2;
        font2.setPointSize(12);
        checkBox_zero->setFont(font2);
        checkBox_zero->setStyleSheet(QString::fromUtf8(" QCheckBox::indicator {\n"
"	color: rgb(255, 255, 255);\n"
"image: url(:/image/053.png);\n"
"      width: 45px;\n"
"      height: 35px;\n"
"  }\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/image/051.png)\n"
";}\n"
"QCheckBox\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
""));
        button_power = new QPushButton(Widget_MAG);
        button_power->setObjectName(QString::fromUtf8("button_power"));
        button_power->setGeometry(QRect(560, 460, 121, 41));
        verticalLayoutWidget_3 = new QWidget(Widget_MAG);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(700, 310, 60, 260));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        lineEdit_9 = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));

        verticalLayout_4->addWidget(lineEdit_9);

        lineEdit_10 = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));

        verticalLayout_4->addWidget(lineEdit_10);

        lineEdit_11 = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));

        verticalLayout_4->addWidget(lineEdit_11);

        lineEdit_12 = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));

        verticalLayout_4->addWidget(lineEdit_12);

        lineEdit_13 = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));

        verticalLayout_4->addWidget(lineEdit_13);

        lineEdit_14 = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_14->setObjectName(QString::fromUtf8("lineEdit_14"));

        verticalLayout_4->addWidget(lineEdit_14);

        lineEdit_15 = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_15->setObjectName(QString::fromUtf8("lineEdit_15"));

        verticalLayout_4->addWidget(lineEdit_15);

        lineEdit_16 = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_16->setObjectName(QString::fromUtf8("lineEdit_16"));

        verticalLayout_4->addWidget(lineEdit_16);

        label_31 = new QLabel(Widget_MAG);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(560, 240, 121, 41));
        label_31->setFont(font);
        label_31->setStyleSheet(QString::fromUtf8("border:2px groove #191919;\n"
"border-radius:8px;\n"
"\n"
"color: white;"));
        label_31->setAlignment(Qt::AlignCenter);
        combConf4_ROT2 = new QComboBox(Widget_MAG);
        combConf4_ROT2->setObjectName(QString::fromUtf8("combConf4_ROT2"));
        combConf4_ROT2->setGeometry(QRect(560, 280, 121, 50));
        combConf4_ROT2->setMinimumSize(QSize(66, 0));
        combConf4_ROT2->setMaximumSize(QSize(200, 50));
        combConf4_ROT2->setFont(font1);
        combConf4_ROT2->setStyleSheet(QString::fromUtf8("\n"
"QComboBox {\n"
"font: 75 18pt \"Ubuntu\";\n"
"	color: rgb(255, 255, 255);\n"
"    border: 1px solid #32435E;\n"
"    border-radius: 3px;\n"
"    padding: 1px 18px 1px 3px;\n"
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
"}\n"
""));

        retranslateUi(Widget_MAG);

        QMetaObject::connectSlotsByName(Widget_MAG);
    } // setupUi

    void retranslateUi(QWidget *Widget_MAG)
    {
        Widget_MAG->setWindowTitle(QApplication::translate("Widget_MAG", "Form", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("Widget_MAG", "\347\243\201\346\227\213", 0, QApplication::UnicodeUTF8));
        label_29->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = oppTab->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget_MAG", "\345\217\215\345\265\214", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = oppTab->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget_MAG", "\347\253\257\344\270\200", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = oppTab->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget_MAG", "\347\253\257\344\272\214", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = oppTab->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Widget_MAG", "\344\270\212\351\231\220", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = oppTab->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Widget_MAG", "\346\263\242\345\275\242", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = oppTab->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Widget_MAG", "\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        combConf4_2->clear();
        combConf4_2->insertItems(0, QStringList()
         << QApplication::translate("Widget_MAG", "\346\255\243\350\275\254", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_MAG", "\345\217\215\350\275\254", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_MAG", "\344\270\215\346\265\213", 0, QApplication::UnicodeUTF8)
        );
        lineEdit_25->setText(QApplication::translate("Widget_MAG", "1", 0, QApplication::UnicodeUTF8));
        lineEdit_26->setText(QApplication::translate("Widget_MAG", "1", 0, QApplication::UnicodeUTF8));
        lineEdit_27->setText(QApplication::translate("Widget_MAG", "1", 0, QApplication::UnicodeUTF8));
        lineEdit_28->setText(QApplication::translate("Widget_MAG", "1", 0, QApplication::UnicodeUTF8));
        lineEdit_29->setText(QApplication::translate("Widget_MAG", "1", 0, QApplication::UnicodeUTF8));
        lineEdit_30->setText(QApplication::translate("Widget_MAG", "1", 0, QApplication::UnicodeUTF8));
        lineEdit_31->setText(QApplication::translate("Widget_MAG", "1", 0, QApplication::UnicodeUTF8));
        lineEdit_32->setText(QApplication::translate("Widget_MAG", "1", 0, QApplication::UnicodeUTF8));
        Key_1->setText(QApplication::translate("Widget_MAG", "1", 0, QApplication::UnicodeUTF8));
        Key_2->setText(QApplication::translate("Widget_MAG", "2", 0, QApplication::UnicodeUTF8));
        Key_3->setText(QApplication::translate("Widget_MAG", "3", 0, QApplication::UnicodeUTF8));
        Key_4->setText(QApplication::translate("Widget_MAG", "4", 0, QApplication::UnicodeUTF8));
        Key_5->setText(QApplication::translate("Widget_MAG", "5", 0, QApplication::UnicodeUTF8));
        Key_6->setText(QApplication::translate("Widget_MAG", "6", 0, QApplication::UnicodeUTF8));
        Key_7->setText(QApplication::translate("Widget_MAG", "7", 0, QApplication::UnicodeUTF8));
        Key_8->setText(QApplication::translate("Widget_MAG", "8", 0, QApplication::UnicodeUTF8));
        lineEdit_1->setText(QApplication::translate("Widget_MAG", "1", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setText(QApplication::translate("Widget_MAG", "1", 0, QApplication::UnicodeUTF8));
        lineEdit_3->setText(QApplication::translate("Widget_MAG", "1", 0, QApplication::UnicodeUTF8));
        lineEdit_4->setText(QApplication::translate("Widget_MAG", "1", 0, QApplication::UnicodeUTF8));
        lineEdit_5->setText(QApplication::translate("Widget_MAG", "1", 0, QApplication::UnicodeUTF8));
        lineEdit_6->setText(QApplication::translate("Widget_MAG", "1", 0, QApplication::UnicodeUTF8));
        lineEdit_7->setText(QApplication::translate("Widget_MAG", "1", 0, QApplication::UnicodeUTF8));
        lineEdit_8->setText(QApplication::translate("Widget_MAG", "1", 0, QApplication::UnicodeUTF8));
        combConf_Station->clear();
        combConf_Station->insertItems(0, QStringList()
         << QApplication::translate("Widget_MAG", "\345\267\246\345\267\245\344\275\215", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_MAG", "\345\217\263\345\267\245\344\275\215", 0, QApplication::UnicodeUTF8)
         << QString()
        );
        checkBox_zero->setText(QApplication::translate("Widget_MAG", "\351\233\266\347\202\271\345\210\244\346\226\255", 0, QApplication::UnicodeUTF8));
        button_power->setText(QApplication::translate("Widget_MAG", "\347\224\265\346\272\220\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        lineEdit_9->setText(QApplication::translate("Widget_MAG", "1", 0, QApplication::UnicodeUTF8));
        lineEdit_10->setText(QApplication::translate("Widget_MAG", "1", 0, QApplication::UnicodeUTF8));
        lineEdit_11->setText(QApplication::translate("Widget_MAG", "1", 0, QApplication::UnicodeUTF8));
        lineEdit_12->setText(QApplication::translate("Widget_MAG", "1", 0, QApplication::UnicodeUTF8));
        lineEdit_13->setText(QApplication::translate("Widget_MAG", "1", 0, QApplication::UnicodeUTF8));
        lineEdit_14->setText(QApplication::translate("Widget_MAG", "1", 0, QApplication::UnicodeUTF8));
        lineEdit_15->setText(QApplication::translate("Widget_MAG", "1", 0, QApplication::UnicodeUTF8));
        lineEdit_16->setText(QApplication::translate("Widget_MAG", "1", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("Widget_MAG", "\347\243\201\346\227\213-2", 0, QApplication::UnicodeUTF8));
        combConf4_ROT2->clear();
        combConf4_ROT2->insertItems(0, QStringList()
         << QApplication::translate("Widget_MAG", "\346\255\243\350\275\254", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_MAG", "\345\217\215\350\275\254", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_MAG", "\344\270\215\346\265\213", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class Widget_MAG: public Ui_Widget_MAG {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_MAG_H
