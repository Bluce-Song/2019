/********************************************************************************
** Form generated from reading UI file 'Widget_DCW.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_DCW_H
#define UI_WIDGET_DCW_H

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

class Ui_Widget_DCW
{
public:
    QWidget *widget;
    QLabel *label_DCW_I_Down;
    QDoubleSpinBox *double_Volt;
    QDoubleSpinBox *double_Time;
    QDoubleSpinBox *double_I_Up;
    QLabel *label_DCW_Volt;
    QLabel *label_DCW_Time;
    QDoubleSpinBox *double_I_Down;
    QLabel *label_DCW_I_Up;
    QLabel *label_DCW_ARC;
    QComboBox *comb_ARC;
    QLabel *label_29;
    QDoubleSpinBox *doubleSpinBox_Compensate;
    QTableWidget *dcwTab;
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

    void setupUi(QWidget *Widget_DCW)
    {
        if (Widget_DCW->objectName().isEmpty())
            Widget_DCW->setObjectName(QString::fromUtf8("Widget_DCW"));
        Widget_DCW->resize(800, 600);
        widget = new QWidget(Widget_DCW);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(220, 320, 491, 281));
        label_DCW_I_Down = new QLabel(widget);
        label_DCW_I_Down->setObjectName(QString::fromUtf8("label_DCW_I_Down"));
        label_DCW_I_Down->setGeometry(QRect(230, 20, 121, 51));
        label_DCW_I_Down->setStyleSheet(QString::fromUtf8(""));
        label_DCW_I_Down->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
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
        label_DCW_Volt = new QLabel(widget);
        label_DCW_Volt->setObjectName(QString::fromUtf8("label_DCW_Volt"));
        label_DCW_Volt->setGeometry(QRect(30, 20, 71, 51));
        label_DCW_Volt->setStyleSheet(QString::fromUtf8(""));
        label_DCW_Volt->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_DCW_Time = new QLabel(widget);
        label_DCW_Time->setObjectName(QString::fromUtf8("label_DCW_Time"));
        label_DCW_Time->setGeometry(QRect(30, 90, 71, 51));
        label_DCW_Time->setStyleSheet(QString::fromUtf8(""));
        label_DCW_Time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        double_I_Down = new QDoubleSpinBox(widget);
        double_I_Down->setObjectName(QString::fromUtf8("double_I_Down"));
        double_I_Down->setGeometry(QRect(360, 20, 101, 51));
        double_I_Down->setStyleSheet(QString::fromUtf8(""));
        double_I_Down->setAlignment(Qt::AlignCenter);
        double_I_Down->setButtonSymbols(QAbstractSpinBox::NoButtons);
        label_DCW_I_Up = new QLabel(widget);
        label_DCW_I_Up->setObjectName(QString::fromUtf8("label_DCW_I_Up"));
        label_DCW_I_Up->setGeometry(QRect(230, 90, 121, 51));
        label_DCW_I_Up->setStyleSheet(QString::fromUtf8(""));
        label_DCW_I_Up->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_DCW_ARC = new QLabel(widget);
        label_DCW_ARC->setObjectName(QString::fromUtf8("label_DCW_ARC"));
        label_DCW_ARC->setGeometry(QRect(30, 160, 71, 51));
        label_DCW_ARC->setStyleSheet(QString::fromUtf8(""));
        label_DCW_ARC->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comb_ARC = new QComboBox(widget);
        comb_ARC->setObjectName(QString::fromUtf8("comb_ARC"));
        comb_ARC->setGeometry(QRect(110, 160, 101, 50));
        comb_ARC->setMaximumSize(QSize(120, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(18);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        comb_ARC->setFont(font);
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
        label_29 = new QLabel(widget);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(250, 160, 101, 51));
        label_29->setStyleSheet(QString::fromUtf8(""));
        label_29->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_Compensate = new QDoubleSpinBox(widget);
        doubleSpinBox_Compensate->setObjectName(QString::fromUtf8("doubleSpinBox_Compensate"));
        doubleSpinBox_Compensate->setGeometry(QRect(360, 160, 101, 51));
        doubleSpinBox_Compensate->setStyleSheet(QString::fromUtf8(""));
        doubleSpinBox_Compensate->setAlignment(Qt::AlignCenter);
        doubleSpinBox_Compensate->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Compensate->setDecimals(2);
        doubleSpinBox_Compensate->setMaximum(3);
        dcwTab = new QTableWidget(Widget_DCW);
        if (dcwTab->columnCount() < 11)
            dcwTab->setColumnCount(11);
        QFont font1;
        font1.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        dcwTab->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        dcwTab->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        dcwTab->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font1);
        dcwTab->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font1);
        dcwTab->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font1);
        dcwTab->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font1);
        dcwTab->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font1);
        dcwTab->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font1);
        dcwTab->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font1);
        dcwTab->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font1);
        dcwTab->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        dcwTab->setObjectName(QString::fromUtf8("dcwTab"));
        dcwTab->setGeometry(QRect(0, 0, 700, 315));
        dcwTab->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        dcwTab->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        dcwTab->setEditTriggers(QAbstractItemView::AllEditTriggers);
        dcwTab->setSelectionMode(QAbstractItemView::SingleSelection);
        dcwTab->horizontalHeader()->setStretchLastSection(true);
        dcwTab->verticalHeader()->setVisible(false);
        dockwidget = new QWidget(Widget_DCW);
        dockwidget->setObjectName(QString::fromUtf8("dockwidget"));
        dockwidget->setGeometry(QRect(140, 0, 121, 581));
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

        dcwTab->raise();
        widget->raise();
        dockwidget->raise();
        QWidget::setTabOrder(comb_ARC, double_Volt);
        QWidget::setTabOrder(double_Volt, double_Time);
        QWidget::setTabOrder(double_Time, double_I_Up);
        QWidget::setTabOrder(double_I_Up, double_I_Down);
        QWidget::setTabOrder(double_I_Down, dcwTab);
        QWidget::setTabOrder(dcwTab, doubleSpinBox_Compensate);
        QWidget::setTabOrder(doubleSpinBox_Compensate, checkBox_1);
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

        retranslateUi(Widget_DCW);

        QMetaObject::connectSlotsByName(Widget_DCW);
    } // setupUi

    void retranslateUi(QWidget *Widget_DCW)
    {
        Widget_DCW->setWindowTitle(QApplication::translate("Widget_DCW", "Form", 0, QApplication::UnicodeUTF8));
        label_DCW_I_Down->setText(QApplication::translate("Widget_DCW", "\347\224\265\346\265\201\344\270\213\351\231\220(mA)", 0, QApplication::UnicodeUTF8));
        label_DCW_Volt->setText(QApplication::translate("Widget_DCW", "\347\224\265\345\216\213(V)", 0, QApplication::UnicodeUTF8));
        label_DCW_Time->setText(QApplication::translate("Widget_DCW", "\346\227\266\351\227\264(s)", 0, QApplication::UnicodeUTF8));
        label_DCW_I_Up->setText(QApplication::translate("Widget_DCW", "\347\224\265\346\265\201\344\270\212\351\231\220(mA)", 0, QApplication::UnicodeUTF8));
        label_DCW_ARC->setText(QApplication::translate("Widget_DCW", "ARC", 0, QApplication::UnicodeUTF8));
        comb_ARC->clear();
        comb_ARC->insertItems(0, QStringList()
         << QApplication::translate("Widget_DCW", "0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_DCW", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_DCW", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_DCW", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_DCW", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_DCW", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_DCW", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_DCW", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_DCW", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_DCW", "9", 0, QApplication::UnicodeUTF8)
        );
        label_29->setText(QApplication::translate("Widget_DCW", "\350\241\245\345\201\277\345\200\274(mA)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = dcwTab->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget_DCW", "\350\200\220\345\216\213", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = dcwTab->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget_DCW", "\351\253\230\347\253\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = dcwTab->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget_DCW", "\344\275\216\347\253\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = dcwTab->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Widget_DCW", "\347\224\265\345\216\213(V)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = dcwTab->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Widget_DCW", "\347\224\265\346\265\201\344\270\213\351\231\220(mA)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = dcwTab->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Widget_DCW", "\347\224\265\346\265\201\344\270\212\351\231\220(mA)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = dcwTab->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Widget_DCW", "ARC", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = dcwTab->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("Widget_DCW", "\346\227\266\351\227\264(S)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = dcwTab->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("Widget_DCW", "\351\242\221\347\216\207", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = dcwTab->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("Widget_DCW", "\350\241\245\345\201\277\345\200\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = dcwTab->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("Widget_DCW", "\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        checkBox_1->setText(QApplication::translate("Widget_DCW", "1", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("Widget_DCW", "2 ", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("Widget_DCW", "3", 0, QApplication::UnicodeUTF8));
        checkBox_4->setText(QApplication::translate("Widget_DCW", "4", 0, QApplication::UnicodeUTF8));
        checkBox_5->setText(QApplication::translate("Widget_DCW", "5", 0, QApplication::UnicodeUTF8));
        checkBox_6->setText(QApplication::translate("Widget_DCW", "6", 0, QApplication::UnicodeUTF8));
        checkBox_7->setText(QApplication::translate("Widget_DCW", "7", 0, QApplication::UnicodeUTF8));
        checkBox_8->setText(QApplication::translate("Widget_DCW", "8", 0, QApplication::UnicodeUTF8));
        checkBox_9->setText(QApplication::translate("Widget_DCW", "PE", 0, QApplication::UnicodeUTF8));
        checkBox_10->setText(QApplication::translate("Widget_DCW", "ALL", 0, QApplication::UnicodeUTF8));
        OK->setText(QApplication::translate("Widget_DCW", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget_DCW: public Ui_Widget_DCW {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_DCW_H
