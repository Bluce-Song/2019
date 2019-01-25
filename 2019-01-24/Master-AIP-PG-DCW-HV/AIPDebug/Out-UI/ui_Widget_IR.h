/********************************************************************************
** Form generated from reading UI file 'Widget_IR.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_IR_H
#define UI_WIDGET_IR_H

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

class Ui_Widget_IR
{
public:
    QTableWidget *IrTab;
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
    QDoubleSpinBox *doubleSpinBox_IR_DownDCR;
    QLabel *label_IR_Time;
    QLabel *label_IR_up_DCR;
    QLabel *label_IR_Volt;
    QComboBox *ComboBox_IR_Volt;
    QDoubleSpinBox *doubleSpinBox_IR_UpDCR;
    QDoubleSpinBox *doubleSpinBox_Compensate;
    QLabel *label_IR_Offect;
    QLabel *label_IR_Down_DCR;
    QDoubleSpinBox *doubleSpinBox_IR_Time;
    QLabel *label_IR_Param;

    void setupUi(QWidget *Widget_IR)
    {
        if (Widget_IR->objectName().isEmpty())
            Widget_IR->setObjectName(QString::fromUtf8("Widget_IR"));
        Widget_IR->resize(721, 580);
        IrTab = new QTableWidget(Widget_IR);
        if (IrTab->columnCount() < 9)
            IrTab->setColumnCount(9);
        QFont font;
        font.setPointSize(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem->setFont(font);
        IrTab->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem1->setFont(font);
        IrTab->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem2->setFont(font);
        IrTab->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem3->setFont(font);
        IrTab->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem4->setFont(font);
        IrTab->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem5->setFont(font);
        IrTab->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem6->setFont(font);
        IrTab->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem7->setFont(font);
        IrTab->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem8->setFont(font);
        IrTab->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        IrTab->setObjectName(QString::fromUtf8("IrTab"));
        IrTab->setGeometry(QRect(5, 0, 680, 315));
        IrTab->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        IrTab->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        IrTab->setEditTriggers(QAbstractItemView::AllEditTriggers);
        IrTab->setSelectionMode(QAbstractItemView::SingleSelection);
        IrTab->horizontalHeader()->setStretchLastSection(true);
        IrTab->verticalHeader()->setVisible(false);
        dockwidget = new QWidget(Widget_IR);
        dockwidget->setObjectName(QString::fromUtf8("dockwidget"));
        dockwidget->setGeometry(QRect(100, 10, 141, 521));
        dockwidget->setStyleSheet(QString::fromUtf8("background-color:#191919"));
        verticalLayoutWidget = new QWidget(dockwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 131, 521));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

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

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        widget = new QWidget(Widget_IR);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(230, 310, 491, 271));
        doubleSpinBox_IR_DownDCR = new QDoubleSpinBox(widget);
        doubleSpinBox_IR_DownDCR->setObjectName(QString::fromUtf8("doubleSpinBox_IR_DownDCR"));
        doubleSpinBox_IR_DownDCR->setGeometry(QRect(380, 90, 101, 51));
        QFont font1;
        font1.setPointSize(13);
        doubleSpinBox_IR_DownDCR->setFont(font1);
        doubleSpinBox_IR_DownDCR->setStyleSheet(QString::fromUtf8(""));
        doubleSpinBox_IR_DownDCR->setAlignment(Qt::AlignCenter);
        doubleSpinBox_IR_DownDCR->setButtonSymbols(QAbstractSpinBox::NoButtons);
        label_IR_Time = new QLabel(widget);
        label_IR_Time->setObjectName(QString::fromUtf8("label_IR_Time"));
        label_IR_Time->setGeometry(QRect(40, 90, 71, 51));
        label_IR_Time->setStyleSheet(QString::fromUtf8(""));
        label_IR_Time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_IR_up_DCR = new QLabel(widget);
        label_IR_up_DCR->setObjectName(QString::fromUtf8("label_IR_up_DCR"));
        label_IR_up_DCR->setGeometry(QRect(250, 90, 121, 51));
        label_IR_up_DCR->setStyleSheet(QString::fromUtf8(""));
        label_IR_up_DCR->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_IR_Volt = new QLabel(widget);
        label_IR_Volt->setObjectName(QString::fromUtf8("label_IR_Volt"));
        label_IR_Volt->setGeometry(QRect(40, 20, 71, 51));
        label_IR_Volt->setStyleSheet(QString::fromUtf8(""));
        label_IR_Volt->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ComboBox_IR_Volt = new QComboBox(widget);
        ComboBox_IR_Volt->setObjectName(QString::fromUtf8("ComboBox_IR_Volt"));
        ComboBox_IR_Volt->setGeometry(QRect(130, 20, 101, 50));
        ComboBox_IR_Volt->setMinimumSize(QSize(66, 0));
        ComboBox_IR_Volt->setMaximumSize(QSize(200, 50));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu"));
        font2.setPointSize(18);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(9);
        ComboBox_IR_Volt->setFont(font2);
        ComboBox_IR_Volt->setStyleSheet(QString::fromUtf8("\n"
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
        doubleSpinBox_IR_UpDCR = new QDoubleSpinBox(widget);
        doubleSpinBox_IR_UpDCR->setObjectName(QString::fromUtf8("doubleSpinBox_IR_UpDCR"));
        doubleSpinBox_IR_UpDCR->setGeometry(QRect(380, 20, 101, 51));
        doubleSpinBox_IR_UpDCR->setFont(font1);
        doubleSpinBox_IR_UpDCR->setStyleSheet(QString::fromUtf8(""));
        doubleSpinBox_IR_UpDCR->setAlignment(Qt::AlignCenter);
        doubleSpinBox_IR_UpDCR->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Compensate = new QDoubleSpinBox(widget);
        doubleSpinBox_Compensate->setObjectName(QString::fromUtf8("doubleSpinBox_Compensate"));
        doubleSpinBox_Compensate->setGeometry(QRect(130, 180, 101, 51));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(doubleSpinBox_Compensate->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Compensate->setSizePolicy(sizePolicy);
        doubleSpinBox_Compensate->setFont(font1);
        doubleSpinBox_Compensate->setStyleSheet(QString::fromUtf8(""));
        doubleSpinBox_Compensate->setAlignment(Qt::AlignCenter);
        doubleSpinBox_Compensate->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Compensate->setMaximum(65537);
        label_IR_Offect = new QLabel(widget);
        label_IR_Offect->setObjectName(QString::fromUtf8("label_IR_Offect"));
        label_IR_Offect->setGeometry(QRect(20, 180, 91, 51));
        label_IR_Offect->setStyleSheet(QString::fromUtf8(""));
        label_IR_Offect->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_IR_Down_DCR = new QLabel(widget);
        label_IR_Down_DCR->setObjectName(QString::fromUtf8("label_IR_Down_DCR"));
        label_IR_Down_DCR->setGeometry(QRect(250, 20, 121, 51));
        label_IR_Down_DCR->setStyleSheet(QString::fromUtf8(""));
        label_IR_Down_DCR->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_IR_Time = new QDoubleSpinBox(widget);
        doubleSpinBox_IR_Time->setObjectName(QString::fromUtf8("doubleSpinBox_IR_Time"));
        doubleSpinBox_IR_Time->setGeometry(QRect(130, 90, 101, 51));
        sizePolicy.setHeightForWidth(doubleSpinBox_IR_Time->sizePolicy().hasHeightForWidth());
        doubleSpinBox_IR_Time->setSizePolicy(sizePolicy);
        doubleSpinBox_IR_Time->setFont(font1);
        doubleSpinBox_IR_Time->setStyleSheet(QString::fromUtf8(""));
        doubleSpinBox_IR_Time->setAlignment(Qt::AlignCenter);
        doubleSpinBox_IR_Time->setButtonSymbols(QAbstractSpinBox::NoButtons);
        label_IR_Param = new QLabel(Widget_IR);
        label_IR_Param->setObjectName(QString::fromUtf8("label_IR_Param"));
        label_IR_Param->setGeometry(QRect(10, 520, 101, 51));
        label_IR_Param->setFont(font1);
        label_IR_Param->setStyleSheet(QString::fromUtf8(""));
        label_IR_Param->setAlignment(Qt::AlignCenter);
        QWidget::setTabOrder(IrTab, ComboBox_IR_Volt);
        QWidget::setTabOrder(ComboBox_IR_Volt, doubleSpinBox_IR_DownDCR);
        QWidget::setTabOrder(doubleSpinBox_IR_DownDCR, doubleSpinBox_IR_UpDCR);
        QWidget::setTabOrder(doubleSpinBox_IR_UpDCR, doubleSpinBox_Compensate);
        QWidget::setTabOrder(doubleSpinBox_Compensate, doubleSpinBox_IR_Time);

        retranslateUi(Widget_IR);

        QMetaObject::connectSlotsByName(Widget_IR);
    } // setupUi

    void retranslateUi(QWidget *Widget_IR)
    {
        Widget_IR->setWindowTitle(QApplication::translate("Widget_IR", "Form", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = IrTab->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget_IR", "\347\273\235\347\274\230", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = IrTab->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget_IR", "\351\253\230\347\253\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = IrTab->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget_IR", "\344\275\216\347\253\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = IrTab->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Widget_IR", "\347\224\265\345\216\213(V)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = IrTab->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Widget_IR", "\347\224\265\351\230\273\344\270\213\351\231\220(M\316\251)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = IrTab->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Widget_IR", "\347\224\265\351\230\273\344\270\212\351\231\220(M\316\251)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = IrTab->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Widget_IR", "\346\227\266\351\227\264(S)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = IrTab->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("Widget_IR", "\350\241\245\345\201\277\345\200\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = IrTab->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("Widget_IR", "\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        checkBox_1->setText(QApplication::translate("Widget_IR", "1", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("Widget_IR", "2 ", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("Widget_IR", "3", 0, QApplication::UnicodeUTF8));
        checkBox_4->setText(QApplication::translate("Widget_IR", "4", 0, QApplication::UnicodeUTF8));
        checkBox_5->setText(QApplication::translate("Widget_IR", "5", 0, QApplication::UnicodeUTF8));
        checkBox_6->setText(QApplication::translate("Widget_IR", "6", 0, QApplication::UnicodeUTF8));
        checkBox_7->setText(QApplication::translate("Widget_IR", "7", 0, QApplication::UnicodeUTF8));
        checkBox_8->setText(QApplication::translate("Widget_IR", "8", 0, QApplication::UnicodeUTF8));
        checkBox_9->setText(QApplication::translate("Widget_IR", "PE", 0, QApplication::UnicodeUTF8));
        checkBox_10->setText(QApplication::translate("Widget_IR", "ALL", 0, QApplication::UnicodeUTF8));
        OK->setText(QApplication::translate("Widget_IR", "OK", 0, QApplication::UnicodeUTF8));
        label_IR_Time->setText(QApplication::translate("Widget_IR", "\346\227\266\351\227\264(s)", 0, QApplication::UnicodeUTF8));
        label_IR_up_DCR->setText(QApplication::translate("Widget_IR", "\347\224\265\351\230\273\344\270\212\351\231\220(M\316\251)", 0, QApplication::UnicodeUTF8));
        label_IR_Volt->setText(QApplication::translate("Widget_IR", "\347\224\265\345\216\213(V)", 0, QApplication::UnicodeUTF8));
        ComboBox_IR_Volt->clear();
        ComboBox_IR_Volt->insertItems(0, QStringList()
         << QApplication::translate("Widget_IR", "500", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_IR", "1000", 0, QApplication::UnicodeUTF8)
        );
        label_IR_Offect->setText(QApplication::translate("Widget_IR", "\350\241\245\345\201\277\345\200\274(M\316\251)", 0, QApplication::UnicodeUTF8));
        label_IR_Down_DCR->setText(QApplication::translate("Widget_IR", "\347\224\265\351\230\273\344\270\213\351\231\220(M\316\251)", 0, QApplication::UnicodeUTF8));
        label_IR_Param->setText(QApplication::translate("Widget_IR", "IR-1", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget_IR: public Ui_Widget_IR {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_IR_H
