/********************************************************************************
** Form generated from reading UI file 'Widget_INDL.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_INDL_H
#define UI_WIDGET_INDL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
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

class Ui_Widget_INDL
{
public:
    QTableWidget *indlTab;
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
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QDoubleSpinBox *INDL_time;
    QDoubleSpinBox *INDL_balance;
    QComboBox *Com_fre;
    QComboBox *Com_connetct;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QDoubleSpinBox *INDL_Max;
    QDoubleSpinBox *INDL_Min;
    QPushButton *Button_Auto;
    QPushButton *Button_Comp;
    QComboBox *Com_test;
    QLabel *label_Q;
    QDoubleSpinBox *Q_balance;
    QLabel *label_8;
    QComboBox *Com_volt;
    QPushButton *button_model;

    void setupUi(QWidget *Widget_INDL)
    {
        if (Widget_INDL->objectName().isEmpty())
            Widget_INDL->setObjectName(QString::fromUtf8("Widget_INDL"));
        Widget_INDL->resize(721, 600);
        indlTab = new QTableWidget(Widget_INDL);
        if (indlTab->columnCount() < 12)
            indlTab->setColumnCount(12);
        QFont font;
        font.setPointSize(11);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        indlTab->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        indlTab->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        indlTab->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        indlTab->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        indlTab->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        indlTab->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        indlTab->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font);
        indlTab->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font);
        indlTab->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font);
        indlTab->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font);
        indlTab->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font1);
        indlTab->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        indlTab->setObjectName(QString::fromUtf8("indlTab"));
        indlTab->setGeometry(QRect(10, 10, 691, 461));
        indlTab->setFocusPolicy(Qt::WheelFocus);
        indlTab->setInputMethodHints(Qt::ImhNone);
        indlTab->setEditTriggers(QAbstractItemView::AllEditTriggers);
        indlTab->setAlternatingRowColors(false);
        indlTab->setSelectionMode(QAbstractItemView::SingleSelection);
        indlTab->horizontalHeader()->setDefaultSectionSize(50);
        indlTab->horizontalHeader()->setStretchLastSection(true);
        indlTab->verticalHeader()->setVisible(false);
        indlTab->verticalHeader()->setDefaultSectionSize(40);
        dockWidget = new QWidget(Widget_INDL);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidget->setGeometry(QRect(160, 30, 111, 441));
        dockWidget->setMinimumSize(QSize(80, 0));
        dockWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayoutWidget = new QWidget(dockWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 102, 426));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Key_1 = new QPushButton(verticalLayoutWidget);
        Key_1->setObjectName(QString::fromUtf8("Key_1"));
        Key_1->setMinimumSize(QSize(100, 47));
        Key_1->setMaximumSize(QSize(100, 47));

        verticalLayout->addWidget(Key_1);

        Key_2 = new QPushButton(verticalLayoutWidget);
        Key_2->setObjectName(QString::fromUtf8("Key_2"));
        Key_2->setMinimumSize(QSize(100, 47));
        Key_2->setMaximumSize(QSize(100, 47));

        verticalLayout->addWidget(Key_2);

        Key_3 = new QPushButton(verticalLayoutWidget);
        Key_3->setObjectName(QString::fromUtf8("Key_3"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(100);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Key_3->sizePolicy().hasHeightForWidth());
        Key_3->setSizePolicy(sizePolicy);
        Key_3->setMinimumSize(QSize(100, 47));
        Key_3->setMaximumSize(QSize(100, 47));

        verticalLayout->addWidget(Key_3);

        Key_4 = new QPushButton(verticalLayoutWidget);
        Key_4->setObjectName(QString::fromUtf8("Key_4"));
        sizePolicy.setHeightForWidth(Key_4->sizePolicy().hasHeightForWidth());
        Key_4->setSizePolicy(sizePolicy);
        Key_4->setMinimumSize(QSize(100, 47));
        Key_4->setMaximumSize(QSize(100, 47));

        verticalLayout->addWidget(Key_4);

        Key_5 = new QPushButton(verticalLayoutWidget);
        Key_5->setObjectName(QString::fromUtf8("Key_5"));
        Key_5->setMinimumSize(QSize(100, 47));
        Key_5->setMaximumSize(QSize(100, 47));

        verticalLayout->addWidget(Key_5);

        Key_6 = new QPushButton(verticalLayoutWidget);
        Key_6->setObjectName(QString::fromUtf8("Key_6"));
        Key_6->setMinimumSize(QSize(100, 47));
        Key_6->setMaximumSize(QSize(100, 47));

        verticalLayout->addWidget(Key_6);

        Key_7 = new QPushButton(verticalLayoutWidget);
        Key_7->setObjectName(QString::fromUtf8("Key_7"));
        Key_7->setMinimumSize(QSize(100, 47));
        Key_7->setMaximumSize(QSize(100, 47));

        verticalLayout->addWidget(Key_7);

        Key_8 = new QPushButton(verticalLayoutWidget);
        Key_8->setObjectName(QString::fromUtf8("Key_8"));
        Key_8->setMinimumSize(QSize(100, 47));
        Key_8->setMaximumSize(QSize(100, 47));

        verticalLayout->addWidget(Key_8);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(Widget_INDL);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(5, 480, 101, 31));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Widget_INDL);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 480, 91, 31));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(Widget_INDL);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 560, 101, 31));
        QFont font2;
        font2.setPointSize(10);
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(Widget_INDL);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(380, 480, 101, 31));
        label_4->setAlignment(Qt::AlignCenter);
        INDL_time = new QDoubleSpinBox(Widget_INDL);
        INDL_time->setObjectName(QString::fromUtf8("INDL_time"));
        INDL_time->setGeometry(QRect(100, 480, 71, 36));
        INDL_time->setAlignment(Qt::AlignCenter);
        INDL_time->setButtonSymbols(QAbstractSpinBox::NoButtons);
        INDL_time->setDecimals(0);
        INDL_time->setMinimum(1);
        INDL_time->setMaximum(100);
        INDL_time->setSingleStep(1);
        INDL_time->setValue(1);
        INDL_balance = new QDoubleSpinBox(Widget_INDL);
        INDL_balance->setObjectName(QString::fromUtf8("INDL_balance"));
        INDL_balance->setGeometry(QRect(100, 560, 71, 36));
        INDL_balance->setAlignment(Qt::AlignCenter);
        INDL_balance->setButtonSymbols(QAbstractSpinBox::NoButtons);
        INDL_balance->setDecimals(3);
        INDL_balance->setMinimum(0);
        INDL_balance->setMaximum(100);
        INDL_balance->setSingleStep(1);
        INDL_balance->setValue(0);
        Com_fre = new QComboBox(Widget_INDL);
        Com_fre->setObjectName(QString::fromUtf8("Com_fre"));
        Com_fre->setGeometry(QRect(290, 480, 81, 36));
        Com_fre->setMinimumSize(QSize(66, 0));
        Com_fre->setMaximumSize(QSize(200, 50));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Ubuntu"));
        font3.setPointSize(16);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(9);
        Com_fre->setFont(font3);
        Com_fre->setStyleSheet(QString::fromUtf8("\n"
"QComboBox {\n"
"font: 75 16pt \"Ubuntu\";\n"
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
"    width:16px;\n"
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
        Com_connetct = new QComboBox(Widget_INDL);
        Com_connetct->setObjectName(QString::fromUtf8("Com_connetct"));
        Com_connetct->setGeometry(QRect(480, 480, 101, 36));
        Com_connetct->setMinimumSize(QSize(66, 0));
        Com_connetct->setMaximumSize(QSize(200, 50));
        Com_connetct->setFont(font3);
        Com_connetct->setStyleSheet(QString::fromUtf8("\n"
"QComboBox {\n"
"font: 75 16pt \"Ubuntu\";\n"
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
"}"));
        label_5 = new QLabel(Widget_INDL);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(170, 560, 21, 31));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(Widget_INDL);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(200, 520, 91, 31));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(Widget_INDL);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(0, 520, 101, 31));
        label_7->setAlignment(Qt::AlignCenter);
        INDL_Max = new QDoubleSpinBox(Widget_INDL);
        INDL_Max->setObjectName(QString::fromUtf8("INDL_Max"));
        INDL_Max->setGeometry(QRect(100, 520, 71, 36));
        INDL_Max->setAlignment(Qt::AlignCenter);
        INDL_Max->setButtonSymbols(QAbstractSpinBox::NoButtons);
        INDL_Max->setDecimals(0);
        INDL_Max->setMinimum(0);
        INDL_Max->setMaximum(100);
        INDL_Max->setSingleStep(1);
        INDL_Max->setValue(1);
        INDL_Min = new QDoubleSpinBox(Widget_INDL);
        INDL_Min->setObjectName(QString::fromUtf8("INDL_Min"));
        INDL_Min->setGeometry(QRect(290, 520, 81, 36));
        INDL_Min->setAlignment(Qt::AlignCenter);
        INDL_Min->setButtonSymbols(QAbstractSpinBox::NoButtons);
        INDL_Min->setDecimals(0);
        INDL_Min->setMinimum(0);
        INDL_Min->setMaximum(100);
        INDL_Min->setSingleStep(1);
        INDL_Min->setValue(1);
        Button_Auto = new QPushButton(Widget_INDL);
        Button_Auto->setObjectName(QString::fromUtf8("Button_Auto"));
        Button_Auto->setEnabled(true);
        Button_Auto->setGeometry(QRect(375, 520, 101, 36));
        Button_Comp = new QPushButton(Widget_INDL);
        Button_Comp->setObjectName(QString::fromUtf8("Button_Comp"));
        Button_Comp->setGeometry(QRect(480, 520, 101, 36));
        Com_test = new QComboBox(Widget_INDL);
        Com_test->setObjectName(QString::fromUtf8("Com_test"));
        Com_test->setGeometry(QRect(590, 480, 111, 36));
        Com_test->setMinimumSize(QSize(66, 0));
        Com_test->setMaximumSize(QSize(200, 50));
        Com_test->setFont(font3);
        Com_test->setStyleSheet(QString::fromUtf8("\n"
"QComboBox {\n"
"font: 75 16pt \"Ubuntu\";\n"
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
"}"));
        label_Q = new QLabel(Widget_INDL);
        label_Q->setObjectName(QString::fromUtf8("label_Q"));
        label_Q->setGeometry(QRect(200, 560, 91, 31));
        label_Q->setFont(font2);
        label_Q->setAlignment(Qt::AlignCenter);
        Q_balance = new QDoubleSpinBox(Widget_INDL);
        Q_balance->setObjectName(QString::fromUtf8("Q_balance"));
        Q_balance->setGeometry(QRect(290, 560, 81, 36));
        Q_balance->setAlignment(Qt::AlignCenter);
        Q_balance->setButtonSymbols(QAbstractSpinBox::NoButtons);
        Q_balance->setDecimals(3);
        Q_balance->setMinimum(0);
        Q_balance->setMaximum(100);
        Q_balance->setSingleStep(1);
        Q_balance->setValue(0);
        label_8 = new QLabel(Widget_INDL);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(380, 560, 21, 31));
        label_8->setAlignment(Qt::AlignCenter);
        Com_volt = new QComboBox(Widget_INDL);
        Com_volt->setObjectName(QString::fromUtf8("Com_volt"));
        Com_volt->setGeometry(QRect(375, 480, 101, 36));
        Com_volt->setMinimumSize(QSize(66, 0));
        Com_volt->setMaximumSize(QSize(200, 50));
        Com_volt->setFont(font3);
        Com_volt->setStyleSheet(QString::fromUtf8("\n"
"QComboBox {\n"
"font: 75 16pt \"Ubuntu\";\n"
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
"}"));
        Com_volt->setModelColumn(0);
        button_model = new QPushButton(Widget_INDL);
        button_model->setObjectName(QString::fromUtf8("button_model"));
        button_model->setGeometry(QRect(375, 560, 101, 36));
        QWidget::setTabOrder(indlTab, Com_connetct);
        QWidget::setTabOrder(Com_connetct, INDL_time);
        QWidget::setTabOrder(INDL_time, INDL_balance);
        QWidget::setTabOrder(INDL_balance, Key_1);
        QWidget::setTabOrder(Key_1, Key_2);
        QWidget::setTabOrder(Key_2, Key_3);
        QWidget::setTabOrder(Key_3, Key_4);
        QWidget::setTabOrder(Key_4, Key_5);
        QWidget::setTabOrder(Key_5, Key_6);
        QWidget::setTabOrder(Key_6, Key_7);
        QWidget::setTabOrder(Key_7, Key_8);
        QWidget::setTabOrder(Key_8, Com_fre);

        retranslateUi(Widget_INDL);

        Com_volt->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget_INDL);
    } // setupUi

    void retranslateUi(QWidget *Widget_INDL)
    {
        Widget_INDL->setWindowTitle(QApplication::translate("Widget_INDL", "Form", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = indlTab->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget_INDL", "\347\224\265\346\204\237", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = indlTab->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget_INDL", "\347\202\271\344\270\200", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = indlTab->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget_INDL", "\347\202\271\344\272\214", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = indlTab->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Widget_INDL", "\344\270\213\351\231\220", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = indlTab->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Widget_INDL", "\344\270\212\351\231\220", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = indlTab->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Widget_INDL", "Q\345\200\274\344\270\213\351\231\220", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = indlTab->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Widget_INDL", "Q\345\200\274\344\270\212\351\231\220", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = indlTab->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("Widget_INDL", "\346\240\207\345\207\206\347\224\265\346\204\237", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = indlTab->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("Widget_INDL", "\345\267\246\350\241\245\345\201\277", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = indlTab->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("Widget_INDL", "\345\217\263\350\241\245\345\201\277", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = indlTab->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("Widget_INDL", "\345\215\225\344\275\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = indlTab->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("Widget_INDL", "\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        Key_1->setText(QApplication::translate("Widget_INDL", "1", 0, QApplication::UnicodeUTF8));
        Key_2->setText(QApplication::translate("Widget_INDL", "2", 0, QApplication::UnicodeUTF8));
        Key_3->setText(QApplication::translate("Widget_INDL", "3", 0, QApplication::UnicodeUTF8));
        Key_4->setText(QApplication::translate("Widget_INDL", "4", 0, QApplication::UnicodeUTF8));
        Key_5->setText(QApplication::translate("Widget_INDL", "5", 0, QApplication::UnicodeUTF8));
        Key_6->setText(QApplication::translate("Widget_INDL", "6", 0, QApplication::UnicodeUTF8));
        Key_7->setText(QApplication::translate("Widget_INDL", "7", 0, QApplication::UnicodeUTF8));
        Key_8->setText(QApplication::translate("Widget_INDL", "8", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget_INDL", "\345\271\263\345\235\207\346\254\241\346\225\260\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget_INDL", "\351\242\221\347\216\207\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Widget_INDL", "\347\224\265\346\204\237\344\270\215\345\271\263\350\241\241\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Widget_INDL", "\350\277\236\346\216\245\346\226\271\345\274\217\357\274\232", 0, QApplication::UnicodeUTF8));
        Com_fre->clear();
        Com_fre->insertItems(0, QStringList()
         << QApplication::translate("Widget_INDL", "100", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_INDL", "120", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_INDL", "1K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_INDL", "10K", 0, QApplication::UnicodeUTF8)
        );
        Com_connetct->clear();
        Com_connetct->insertItems(0, QStringList()
         << QApplication::translate("Widget_INDL", "\344\270\262\350\201\224", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_INDL", "\345\271\266\350\201\224", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("Widget_INDL", "%", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Widget_INDL", "\344\270\212\351\231\220(%)\357\274\232", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Widget_INDL", "\344\270\213\351\231\220(%)\357\274\232", 0, QApplication::UnicodeUTF8));
        Button_Auto->setText(QApplication::translate("Widget_INDL", "\350\207\252\345\212\250\350\256\241\347\256\227", 0, QApplication::UnicodeUTF8));
        Button_Comp->setText(QApplication::translate("Widget_INDL", "\346\240\241\345\207\206\350\241\245\345\201\277", 0, QApplication::UnicodeUTF8));
        Com_test->clear();
        Com_test->insertItems(0, QStringList()
         << QApplication::translate("Widget_INDL", "\345\277\253\346\265\213", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_INDL", "\346\205\242\346\265\213", 0, QApplication::UnicodeUTF8)
        );
        label_Q->setText(QApplication::translate("Widget_INDL", "Q\345\200\274\344\270\215\345\271\263\350\241\241\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Widget_INDL", "%", 0, QApplication::UnicodeUTF8));
        Com_volt->clear();
        Com_volt->insertItems(0, QStringList()
         << QApplication::translate("Widget_INDL", "0.6V", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_INDL", "0.3V", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_INDL", "1.0V", 0, QApplication::UnicodeUTF8)
        );
        button_model->setText(QApplication::translate("Widget_INDL", "\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget_INDL: public Ui_Widget_INDL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_INDL_H
