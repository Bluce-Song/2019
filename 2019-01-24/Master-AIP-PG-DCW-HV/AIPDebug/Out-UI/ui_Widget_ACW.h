/********************************************************************************
** Form generated from reading UI file 'Widget_ACW.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_ACW_H
#define UI_WIDGET_ACW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_ACW
{
public:
    QTableWidget *acwTab;
    QWidget *dockwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QCheckBox *checkBox_1;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox_10;
    QPushButton *OK;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QLabel *label_ACW_I_Down;
    QDoubleSpinBox *double_Volt;
    QDoubleSpinBox *double_Time;
    QDoubleSpinBox *double_I_Up;
    QLabel *label_ACW_Volt;
    QLabel *label_ACW_Time;
    QDoubleSpinBox *double_I_Down;
    QLabel *label_ACW_I_Up;
    QLabel *label_ACW_Freq;
    QLabel *label_ACW_ARC;
    QComboBox *comb_ARC;
    QComboBox *comb_Freq;
    QLabel *label_29;
    QDoubleSpinBox *doubleSpinBox_Compensate;
    QLabel *label_ACW_Param;

    void setupUi(QWidget *Widget_ACW)
    {
        if (Widget_ACW->objectName().isEmpty())
            Widget_ACW->setObjectName(QString::fromUtf8("Widget_ACW"));
        Widget_ACW->resize(721, 600);
        Widget_ACW->setContextMenuPolicy(Qt::DefaultContextMenu);
        acwTab = new QTableWidget(Widget_ACW);
        if (acwTab->columnCount() < 11)
            acwTab->setColumnCount(11);
        QFont font;
        font.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        acwTab->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        acwTab->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        acwTab->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        acwTab->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        acwTab->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        acwTab->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        acwTab->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font);
        acwTab->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font);
        acwTab->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font);
        acwTab->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font);
        acwTab->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        acwTab->setObjectName(QString::fromUtf8("acwTab"));
        acwTab->setGeometry(QRect(0, 0, 700, 315));
        acwTab->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        acwTab->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        acwTab->setEditTriggers(QAbstractItemView::AllEditTriggers);
        acwTab->setSelectionMode(QAbstractItemView::SingleSelection);
        acwTab->horizontalHeader()->setStretchLastSection(true);
        acwTab->verticalHeader()->setVisible(false);
        dockwidget = new QWidget(Widget_ACW);
        dockwidget->setObjectName(QString::fromUtf8("dockwidget"));
        dockwidget->setGeometry(QRect(100, 0, 121, 581));
        dockwidget->setStyleSheet(QString::fromUtf8("background-color:#191919"));
        verticalLayoutWidget = new QWidget(dockwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 121, 581));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        checkBox_1 = new QCheckBox(verticalLayoutWidget);
        checkBox_1->setObjectName(QString::fromUtf8("checkBox_1"));
        checkBox_1->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"image: url(:/image/053.png);\n"
"      width: 65px;\n"
"      height: 45px;\n"
"  }\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/image/051.png);\n"
"}\n"
"QCheckBox\n"
"{\n"
"background-color: rgb(25, 25, 25);\n"
"	color: rgb(255, 255, 255);\n"
"}"));

        verticalLayout->addWidget(checkBox_1);

        checkBox_2 = new QCheckBox(verticalLayoutWidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"image: url(:/image/053.png);\n"
"      width: 65px;\n"
"      height: 45px;\n"
"  }\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/image/051.png);\n"
"}\n"
"QCheckBox\n"
"{\n"
"background-color: rgb(25, 25, 25);\n"
"	color: rgb(255, 255, 255);\n"
"}"));

        verticalLayout->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(verticalLayoutWidget);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"image: url(:/image/053.png);\n"
"      width: 65px;\n"
"      height: 45px;\n"
"  }\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/image/051.png);\n"
"}\n"
"QCheckBox\n"
"{\n"
"background-color: rgb(25, 25, 25);\n"
"	color: rgb(255, 255, 255);\n"
"}"));

        verticalLayout->addWidget(checkBox_3);

        checkBox_4 = new QCheckBox(verticalLayoutWidget);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"image: url(:/image/053.png);\n"
"      width: 65px;\n"
"      height: 45px;\n"
"  }\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/image/051.png);\n"
"}\n"
"QCheckBox\n"
"{\n"
"background-color: rgb(25, 25, 25);\n"
"	color: rgb(255, 255, 255);\n"
"}"));

        verticalLayout->addWidget(checkBox_4);

        checkBox_5 = new QCheckBox(verticalLayoutWidget);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"image: url(:/image/053.png);\n"
"      width: 65px;\n"
"      height: 45px;\n"
"  }\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/image/051.png);\n"
"}\n"
"QCheckBox\n"
"{\n"
"background-color: rgb(25, 25, 25);\n"
"	color: rgb(255, 255, 255);\n"
"}"));

        verticalLayout->addWidget(checkBox_5);

        checkBox_6 = new QCheckBox(verticalLayoutWidget);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"image: url(:/image/053.png);\n"
"      width: 65px;\n"
"      height: 45px;\n"
"  }\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/image/051.png);\n"
"}\n"
"QCheckBox\n"
"{\n"
"background-color: rgb(25, 25, 25);\n"
"	color: rgb(255, 255, 255);\n"
"}"));

        verticalLayout->addWidget(checkBox_6);

        checkBox_7 = new QCheckBox(verticalLayoutWidget);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"image: url(:/image/053.png);\n"
"      width: 65px;\n"
"      height: 45px;\n"
"  }\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/image/051.png);\n"
"}\n"
"QCheckBox\n"
"{\n"
"background-color: rgb(25, 25, 25);\n"
"	color: rgb(255, 255, 255);\n"
"}"));

        verticalLayout->addWidget(checkBox_7);

        checkBox_8 = new QCheckBox(verticalLayoutWidget);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));
        checkBox_8->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"image: url(:/image/053.png);\n"
"      width: 65px;\n"
"      height: 45px;\n"
"  }\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/image/051.png);\n"
"}\n"
"QCheckBox\n"
"{\n"
"background-color: rgb(25, 25, 25);\n"
"	color: rgb(255, 255, 255);\n"
"}"));

        verticalLayout->addWidget(checkBox_8);

        checkBox_9 = new QCheckBox(verticalLayoutWidget);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));
        checkBox_9->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"image: url(:/image/053.png);\n"
"      width: 65px;\n"
"      height: 45px;\n"
"  }\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/image/051.png);\n"
"}\n"
"QCheckBox\n"
"{\n"
"background-color: rgb(25, 25, 25);\n"
"	color: rgb(255, 255, 255);\n"
"}"));

        verticalLayout->addWidget(checkBox_9);

        checkBox_10 = new QCheckBox(verticalLayoutWidget);
        checkBox_10->setObjectName(QString::fromUtf8("checkBox_10"));
        checkBox_10->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"image: url(:/image/053.png);\n"
"      width: 65px;\n"
"      height: 45px;\n"
"  }\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/image/051.png);\n"
"}\n"
"QCheckBox\n"
"{\n"
"background-color: rgb(25, 25, 25);\n"
"	color: rgb(255, 255, 255);\n"
"}"));

        verticalLayout->addWidget(checkBox_10);

        OK = new QPushButton(verticalLayoutWidget);
        OK->setObjectName(QString::fromUtf8("OK"));
        OK->setEnabled(true);
        OK->setMinimumSize(QSize(0, 40));
        OK->setMaximumSize(QSize(16777215, 40));
        OK->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #5B5F5F, stop: 0.5 #0C2436,stop: 1 #27405A);\n"
"    border-style: outset;\n"
"    border-width: 1px;\n"
"    border-radius: 5px;\n"
"    border-color: #11223F;\n"
"    color:white;\n"
"    padding: 1px;\n"
"}\n"
"QPushButton::hover{\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #758385, stop: 0.5 #122C39,stop: 1 #0E7788);\n"
"    border-color: #11505C;\n"
"}\n"
"QPushButton::pressed{\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #969B9C, stop: 0.5 #16354B,stop: 1 #244F76);\n"
"    border-color: #11505C;\n"
"}\n"
"QPushButton#up_Button{\n"
"border:1px groove white;\n"
"image: url(:/image/arrow_up.ico);\n"
"border-color: #447684;\n"
"    background-color:#191919;\n"
"}\n"
"QPushButton#down_Button{\n"
"border:1px groove white;\n"
"image: url(:/image/arrow_down.ico);\n"
"    border-color: #447684;\n"
"    background-color:#191919;\n"
"}"));

        verticalLayout->addWidget(OK);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        widget = new QWidget(Widget_ACW);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(230, 320, 491, 281));
        label_ACW_I_Down = new QLabel(widget);
        label_ACW_I_Down->setObjectName(QString::fromUtf8("label_ACW_I_Down"));
        label_ACW_I_Down->setGeometry(QRect(230, 20, 121, 51));
        label_ACW_I_Down->setStyleSheet(QString::fromUtf8(""));
        label_ACW_I_Down->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        double_Volt = new QDoubleSpinBox(widget);
        double_Volt->setObjectName(QString::fromUtf8("double_Volt"));
        double_Volt->setGeometry(QRect(110, 20, 101, 51));
        double_Volt->setStyleSheet(QString::fromUtf8(""));
        double_Volt->setAlignment(Qt::AlignCenter);
        double_Volt->setButtonSymbols(QAbstractSpinBox::NoButtons);
        double_Time = new QDoubleSpinBox(widget);
        double_Time->setObjectName(QString::fromUtf8("double_Time"));
        double_Time->setGeometry(QRect(110, 90, 101, 51));
        double_Time->setStyleSheet(QString::fromUtf8(""));
        double_Time->setAlignment(Qt::AlignCenter);
        double_Time->setButtonSymbols(QAbstractSpinBox::NoButtons);
        double_I_Up = new QDoubleSpinBox(widget);
        double_I_Up->setObjectName(QString::fromUtf8("double_I_Up"));
        double_I_Up->setGeometry(QRect(360, 90, 101, 51));
        double_I_Up->setStyleSheet(QString::fromUtf8(""));
        double_I_Up->setAlignment(Qt::AlignCenter);
        double_I_Up->setButtonSymbols(QAbstractSpinBox::NoButtons);
        label_ACW_Volt = new QLabel(widget);
        label_ACW_Volt->setObjectName(QString::fromUtf8("label_ACW_Volt"));
        label_ACW_Volt->setGeometry(QRect(30, 20, 71, 51));
        label_ACW_Volt->setStyleSheet(QString::fromUtf8(""));
        label_ACW_Volt->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_ACW_Time = new QLabel(widget);
        label_ACW_Time->setObjectName(QString::fromUtf8("label_ACW_Time"));
        label_ACW_Time->setGeometry(QRect(30, 90, 71, 51));
        label_ACW_Time->setStyleSheet(QString::fromUtf8(""));
        label_ACW_Time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        double_I_Down = new QDoubleSpinBox(widget);
        double_I_Down->setObjectName(QString::fromUtf8("double_I_Down"));
        double_I_Down->setGeometry(QRect(360, 20, 101, 51));
        double_I_Down->setStyleSheet(QString::fromUtf8(""));
        double_I_Down->setAlignment(Qt::AlignCenter);
        double_I_Down->setButtonSymbols(QAbstractSpinBox::NoButtons);
        label_ACW_I_Up = new QLabel(widget);
        label_ACW_I_Up->setObjectName(QString::fromUtf8("label_ACW_I_Up"));
        label_ACW_I_Up->setGeometry(QRect(230, 90, 121, 51));
        label_ACW_I_Up->setStyleSheet(QString::fromUtf8(""));
        label_ACW_I_Up->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_ACW_Freq = new QLabel(widget);
        label_ACW_Freq->setObjectName(QString::fromUtf8("label_ACW_Freq"));
        label_ACW_Freq->setGeometry(QRect(230, 160, 121, 51));
        label_ACW_Freq->setStyleSheet(QString::fromUtf8(""));
        label_ACW_Freq->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_ACW_ARC = new QLabel(widget);
        label_ACW_ARC->setObjectName(QString::fromUtf8("label_ACW_ARC"));
        label_ACW_ARC->setGeometry(QRect(30, 160, 71, 51));
        label_ACW_ARC->setStyleSheet(QString::fromUtf8(""));
        label_ACW_ARC->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comb_ARC = new QComboBox(widget);
        comb_ARC->setObjectName(QString::fromUtf8("comb_ARC"));
        comb_ARC->setGeometry(QRect(110, 160, 101, 50));
        comb_ARC->setMaximumSize(QSize(120, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(9);
        comb_ARC->setFont(font1);
        comb_ARC->setStyleSheet(QString::fromUtf8("\n"
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
        comb_Freq = new QComboBox(widget);
        comb_Freq->setObjectName(QString::fromUtf8("comb_Freq"));
        comb_Freq->setGeometry(QRect(360, 160, 101, 50));
        comb_Freq->setMaximumSize(QSize(120, 50));
        comb_Freq->setFont(font1);
        comb_Freq->setStyleSheet(QString::fromUtf8("\n"
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
        label_29 = new QLabel(widget);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(0, 230, 101, 51));
        label_29->setStyleSheet(QString::fromUtf8(""));
        label_29->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_Compensate = new QDoubleSpinBox(widget);
        doubleSpinBox_Compensate->setObjectName(QString::fromUtf8("doubleSpinBox_Compensate"));
        doubleSpinBox_Compensate->setGeometry(QRect(110, 230, 101, 51));
        doubleSpinBox_Compensate->setStyleSheet(QString::fromUtf8(""));
        doubleSpinBox_Compensate->setAlignment(Qt::AlignCenter);
        doubleSpinBox_Compensate->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Compensate->setDecimals(2);
        doubleSpinBox_Compensate->setMaximum(3);
        label_ACW_Param = new QLabel(Widget_ACW);
        label_ACW_Param->setObjectName(QString::fromUtf8("label_ACW_Param"));
        label_ACW_Param->setGeometry(QRect(10, 540, 101, 51));
        QFont font2;
        font2.setPointSize(13);
        label_ACW_Param->setFont(font2);
        label_ACW_Param->setStyleSheet(QString::fromUtf8(""));
        label_ACW_Param->setAlignment(Qt::AlignCenter);
        QWidget::setTabOrder(acwTab, comb_ARC);
        QWidget::setTabOrder(comb_ARC, comb_Freq);
        QWidget::setTabOrder(comb_Freq, double_Time);
        QWidget::setTabOrder(double_Time, double_I_Up);
        QWidget::setTabOrder(double_I_Up, double_I_Down);
        QWidget::setTabOrder(double_I_Down, double_Volt);
        QWidget::setTabOrder(double_Volt, checkBox_1);
        QWidget::setTabOrder(checkBox_1, checkBox_2);
        QWidget::setTabOrder(checkBox_2, checkBox_3);
        QWidget::setTabOrder(checkBox_3, checkBox_4);
        QWidget::setTabOrder(checkBox_4, checkBox_5);
        QWidget::setTabOrder(checkBox_5, checkBox_6);
        QWidget::setTabOrder(checkBox_6, checkBox_7);
        QWidget::setTabOrder(checkBox_7, checkBox_8);
        QWidget::setTabOrder(checkBox_8, checkBox_9);
        QWidget::setTabOrder(checkBox_9, checkBox_10);
        QWidget::setTabOrder(checkBox_10, OK);

        retranslateUi(Widget_ACW);

        QMetaObject::connectSlotsByName(Widget_ACW);
    } // setupUi

    void retranslateUi(QWidget *Widget_ACW)
    {
        Widget_ACW->setWindowTitle(QApplication::translate("Widget_ACW", "Form", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = acwTab->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget_ACW", "\350\200\220\345\216\213", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = acwTab->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget_ACW", "\351\253\230\347\253\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = acwTab->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget_ACW", "\344\275\216\347\253\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = acwTab->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Widget_ACW", "\347\224\265\345\216\213(V)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = acwTab->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Widget_ACW", "\347\224\265\346\265\201\344\270\213\351\231\220(mA)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = acwTab->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Widget_ACW", "\347\224\265\346\265\201\344\270\212\351\231\220(mA)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = acwTab->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Widget_ACW", "ARC", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = acwTab->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("Widget_ACW", "\346\227\266\351\227\264(S)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = acwTab->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("Widget_ACW", "\351\242\221\347\216\207", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = acwTab->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("Widget_ACW", "\350\241\245\345\201\277\345\200\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = acwTab->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("Widget_ACW", "\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        checkBox_1->setText(QApplication::translate("Widget_ACW", "1", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("Widget_ACW", "2 ", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("Widget_ACW", "3", 0, QApplication::UnicodeUTF8));
        checkBox_4->setText(QApplication::translate("Widget_ACW", "4", 0, QApplication::UnicodeUTF8));
        checkBox_5->setText(QApplication::translate("Widget_ACW", "5", 0, QApplication::UnicodeUTF8));
        checkBox_6->setText(QApplication::translate("Widget_ACW", "6", 0, QApplication::UnicodeUTF8));
        checkBox_7->setText(QApplication::translate("Widget_ACW", "7", 0, QApplication::UnicodeUTF8));
        checkBox_8->setText(QApplication::translate("Widget_ACW", "8", 0, QApplication::UnicodeUTF8));
        checkBox_9->setText(QApplication::translate("Widget_ACW", "PE", 0, QApplication::UnicodeUTF8));
        checkBox_10->setText(QApplication::translate("Widget_ACW", "ALL", 0, QApplication::UnicodeUTF8));
        OK->setText(QApplication::translate("Widget_ACW", "OK", 0, QApplication::UnicodeUTF8));
        label_ACW_I_Down->setText(QApplication::translate("Widget_ACW", "\347\224\265\346\265\201\344\270\213\351\231\220(mA)", 0, QApplication::UnicodeUTF8));
        label_ACW_Volt->setText(QApplication::translate("Widget_ACW", "\347\224\265\345\216\213(V)", 0, QApplication::UnicodeUTF8));
        label_ACW_Time->setText(QApplication::translate("Widget_ACW", "\346\227\266\351\227\264(s)", 0, QApplication::UnicodeUTF8));
        label_ACW_I_Up->setText(QApplication::translate("Widget_ACW", "\347\224\265\346\265\201\344\270\212\351\231\220(mA)", 0, QApplication::UnicodeUTF8));
        label_ACW_Freq->setText(QApplication::translate("Widget_ACW", "\351\242\221\347\216\207(Hz)", 0, QApplication::UnicodeUTF8));
        label_ACW_ARC->setText(QApplication::translate("Widget_ACW", "ARC", 0, QApplication::UnicodeUTF8));
        comb_ARC->clear();
        comb_ARC->insertItems(0, QStringList()
         << QApplication::translate("Widget_ACW", "0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_ACW", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_ACW", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_ACW", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_ACW", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_ACW", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_ACW", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_ACW", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_ACW", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_ACW", "9", 0, QApplication::UnicodeUTF8)
        );
        comb_Freq->clear();
        comb_Freq->insertItems(0, QStringList()
         << QApplication::translate("Widget_ACW", "50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_ACW", "60", 0, QApplication::UnicodeUTF8)
        );
        label_29->setText(QApplication::translate("Widget_ACW", "\350\241\245\345\201\277\345\200\274(mA)", 0, QApplication::UnicodeUTF8));
        label_ACW_Param->setText(QApplication::translate("Widget_ACW", "ACW-1", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget_ACW: public Ui_Widget_ACW {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_ACW_H
