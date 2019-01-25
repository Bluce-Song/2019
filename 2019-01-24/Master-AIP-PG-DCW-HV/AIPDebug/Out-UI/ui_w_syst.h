/********************************************************************************
** Form generated from reading UI file 'w_syst.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_SYST_H
#define UI_W_SYST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_w_Syst
{
public:
    QPushButton *Key_A;
    QPushButton *Timer;
    QDoubleSpinBox *spinBox_2;
    QDoubleSpinBox *spinBox_1;
    QDoubleSpinBox *spinBox_3;
    QDoubleSpinBox *spinBox_6;
    QDoubleSpinBox *spinBox_4;
    QDoubleSpinBox *spinBox_5;
    QDoubleSpinBox *Beep_OK;
    QDoubleSpinBox *Beep_NG;
    QPushButton *Key_H;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_10;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_12;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QDoubleSpinBox *scan_start;
    QDoubleSpinBox *scan_stop;
    QLabel *label_25;
    QLabel *label_26;
    QLineEdit *lineEdit;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *Button_Check_3;
    QComboBox *comb_Start;
    QPushButton *Button_Check;
    QLabel *label_11;
    QLabel *label_8;
    QComboBox *comb_Conf;
    QLabel *label;
    QPushButton *Beep_Button;
    QComboBox *comb_Beep;
    QLabel *label_2;
    QLabel *label_21;
    QComboBox *comb_Led;
    QPushButton *Led_Button;
    QPushButton *Button_Check_2;
    QLabel *label_18;
    QLabel *label_32;
    QPushButton *Button_SQL;
    QPushButton *Button_IO;
    QPushButton *Button_Usart;
    QLabel *label_27;
    QComboBox *comb_language;
    QLabel *label_28;
    QComboBox *comb_power;
    QLabel *label_3;
    QLabel *label_30;
    QComboBox *comb_imp_back;
    QLabel *label_9;
    QLabel *label_31;

    void setupUi(QDialog *w_Syst)
    {
        if (w_Syst->objectName().isEmpty())
            w_Syst->setObjectName(QString::fromUtf8("w_Syst"));
        w_Syst->resize(800, 600);
        w_Syst->setStyleSheet(QString::fromUtf8(""));
        Key_A = new QPushButton(w_Syst);
        Key_A->setObjectName(QString::fromUtf8("Key_A"));
        Key_A->setGeometry(QRect(680, 15, 111, 51));
        Key_A->setFocusPolicy(Qt::TabFocus);
        Key_A->setStyleSheet(QString::fromUtf8("QToolButton{border:0px;}"));
        Key_A->setIconSize(QSize(64, 64));
        Timer = new QPushButton(w_Syst);
        Timer->setObjectName(QString::fromUtf8("Timer"));
        Timer->setGeometry(QRect(540, 530, 111, 41));
        spinBox_2 = new QDoubleSpinBox(w_Syst);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(210, 530, 51, 41));
        spinBox_2->setStyleSheet(QString::fromUtf8(""));
        spinBox_2->setAlignment(Qt::AlignCenter);
        spinBox_2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_2->setDecimals(0);
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(13);
        spinBox_1 = new QDoubleSpinBox(w_Syst);
        spinBox_1->setObjectName(QString::fromUtf8("spinBox_1"));
        spinBox_1->setGeometry(QRect(110, 530, 71, 41));
        spinBox_1->setStyleSheet(QString::fromUtf8(""));
        spinBox_1->setAlignment(Qt::AlignCenter);
        spinBox_1->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_1->setDecimals(0);
        spinBox_1->setMinimum(2000);
        spinBox_1->setMaximum(3000);
        spinBox_3 = new QDoubleSpinBox(w_Syst);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(290, 530, 51, 41));
        spinBox_3->setStyleSheet(QString::fromUtf8(""));
        spinBox_3->setAlignment(Qt::AlignCenter);
        spinBox_3->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_3->setDecimals(0);
        spinBox_3->setMinimum(1);
        spinBox_3->setMaximum(31);
        spinBox_6 = new QDoubleSpinBox(w_Syst);
        spinBox_6->setObjectName(QString::fromUtf8("spinBox_6"));
        spinBox_6->setGeometry(QRect(730, 530, 61, 41));
        spinBox_6->setStyleSheet(QString::fromUtf8(""));
        spinBox_6->setAlignment(Qt::AlignCenter);
        spinBox_6->setDecimals(0);
        spinBox_6->setMaximum(59);
        spinBox_4 = new QDoubleSpinBox(w_Syst);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setGeometry(QRect(370, 530, 51, 41));
        spinBox_4->setStyleSheet(QString::fromUtf8(""));
        spinBox_4->setAlignment(Qt::AlignCenter);
        spinBox_4->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_4->setDecimals(0);
        spinBox_4->setMaximum(23);
        spinBox_5 = new QDoubleSpinBox(w_Syst);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
        spinBox_5->setGeometry(QRect(450, 530, 51, 41));
        spinBox_5->setStyleSheet(QString::fromUtf8(""));
        spinBox_5->setAlignment(Qt::AlignCenter);
        spinBox_5->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_5->setDecimals(0);
        spinBox_5->setMaximum(59);
        Beep_OK = new QDoubleSpinBox(w_Syst);
        Beep_OK->setObjectName(QString::fromUtf8("Beep_OK"));
        Beep_OK->setGeometry(QRect(200, 430, 61, 41));
        Beep_OK->setAlignment(Qt::AlignCenter);
        Beep_OK->setButtonSymbols(QAbstractSpinBox::NoButtons);
        Beep_OK->setDecimals(1);
        Beep_OK->setMaximum(99);
        Beep_OK->setSingleStep(0.1);
        Beep_OK->setValue(1);
        Beep_NG = new QDoubleSpinBox(w_Syst);
        Beep_NG->setObjectName(QString::fromUtf8("Beep_NG"));
        Beep_NG->setGeometry(QRect(440, 430, 61, 41));
        Beep_NG->setAlignment(Qt::AlignCenter);
        Beep_NG->setButtonSymbols(QAbstractSpinBox::NoButtons);
        Beep_NG->setDecimals(1);
        Beep_NG->setMaximum(99);
        Beep_NG->setSingleStep(0.1);
        Beep_NG->setValue(3);
        Key_H = new QPushButton(w_Syst);
        Key_H->setObjectName(QString::fromUtf8("Key_H"));
        Key_H->setGeometry(QRect(680, 75, 111, 51));
        Key_H->setStyleSheet(QString::fromUtf8("QToolButton{border:0px;}"));
        Key_H->setIconSize(QSize(64, 64));
        label_6 = new QLabel(w_Syst);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(110, 430, 91, 41));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(w_Syst);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(320, 430, 111, 41));
        label_7->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(w_Syst);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 530, 91, 41));
        label_10->setStyleSheet(QString::fromUtf8(""));
        label_10->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(w_Syst);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(180, 530, 31, 41));
        label_13->setStyleSheet(QString::fromUtf8(""));
        label_13->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(w_Syst);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(260, 530, 31, 41));
        label_14->setStyleSheet(QString::fromUtf8(""));
        label_14->setAlignment(Qt::AlignCenter);
        label_15 = new QLabel(w_Syst);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(340, 530, 31, 41));
        label_15->setStyleSheet(QString::fromUtf8(""));
        label_15->setAlignment(Qt::AlignCenter);
        label_16 = new QLabel(w_Syst);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(420, 530, 31, 41));
        label_16->setStyleSheet(QString::fromUtf8(""));
        label_16->setAlignment(Qt::AlignCenter);
        label_17 = new QLabel(w_Syst);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(500, 530, 31, 41));
        label_17->setStyleSheet(QString::fromUtf8(""));
        label_17->setAlignment(Qt::AlignCenter);
        label_19 = new QLabel(w_Syst);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(270, 430, 21, 41));
        label_19->setStyleSheet(QString::fromUtf8(""));
        label_19->setAlignment(Qt::AlignCenter);
        label_20 = new QLabel(w_Syst);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(500, 430, 31, 41));
        label_20->setStyleSheet(QString::fromUtf8(""));
        label_20->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(w_Syst);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(0, 430, 111, 41));
        label_12->setStyleSheet(QString::fromUtf8(""));
        label_12->setAlignment(Qt::AlignCenter);
        label_22 = new QLabel(w_Syst);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 480, 91, 41));
        label_22->setStyleSheet(QString::fromUtf8(""));
        label_22->setAlignment(Qt::AlignCenter);
        label_23 = new QLabel(w_Syst);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(110, 480, 91, 41));
        label_23->setAlignment(Qt::AlignCenter);
        label_24 = new QLabel(w_Syst);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(320, 480, 111, 41));
        label_24->setAlignment(Qt::AlignCenter);
        scan_start = new QDoubleSpinBox(w_Syst);
        scan_start->setObjectName(QString::fromUtf8("scan_start"));
        scan_start->setGeometry(QRect(200, 480, 61, 41));
        scan_start->setAlignment(Qt::AlignCenter);
        scan_start->setButtonSymbols(QAbstractSpinBox::NoButtons);
        scan_start->setDecimals(0);
        scan_start->setMaximum(1000);
        scan_start->setSingleStep(1);
        scan_start->setValue(1);
        scan_stop = new QDoubleSpinBox(w_Syst);
        scan_stop->setObjectName(QString::fromUtf8("scan_stop"));
        scan_stop->setGeometry(QRect(440, 480, 61, 41));
        scan_stop->setAlignment(Qt::AlignCenter);
        scan_stop->setButtonSymbols(QAbstractSpinBox::NoButtons);
        scan_stop->setDecimals(0);
        scan_stop->setMinimum(0);
        scan_stop->setMaximum(1000);
        scan_stop->setSingleStep(1);
        scan_stop->setValue(1);
        label_25 = new QLabel(w_Syst);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(270, 480, 21, 41));
        label_25->setStyleSheet(QString::fromUtf8(""));
        label_25->setAlignment(Qt::AlignCenter);
        label_26 = new QLabel(w_Syst);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(500, 480, 31, 41));
        label_26->setStyleSheet(QString::fromUtf8(""));
        label_26->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(w_Syst);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(540, 480, 241, 41));
        gridLayoutWidget = new QWidget(w_Syst);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 10, 681, 241));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Button_Check_3 = new QPushButton(gridLayoutWidget);
        Button_Check_3->setObjectName(QString::fromUtf8("Button_Check_3"));
        Button_Check_3->setMinimumSize(QSize(141, 51));
        Button_Check_3->setMaximumSize(QSize(141, 51));

        gridLayout->addWidget(Button_Check_3, 3, 1, 1, 1);

        comb_Start = new QComboBox(gridLayoutWidget);
        comb_Start->setObjectName(QString::fromUtf8("comb_Start"));
        comb_Start->setMinimumSize(QSize(141, 51));
        comb_Start->setMaximumSize(QSize(141, 51));
        QFont font;
        font.setPointSize(17);
        comb_Start->setFont(font);

        gridLayout->addWidget(comb_Start, 0, 3, 1, 1);

        Button_Check = new QPushButton(gridLayoutWidget);
        Button_Check->setObjectName(QString::fromUtf8("Button_Check"));
        Button_Check->setMinimumSize(QSize(141, 51));
        Button_Check->setMaximumSize(QSize(141, 51));

        gridLayout->addWidget(Button_Check, 1, 1, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(91, 51));
        label_11->setMaximumSize(QSize(91, 51));
        label_11->setStyleSheet(QString::fromUtf8(""));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_11, 1, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(100, 51));
        label_8->setMaximumSize(QSize(100, 51));
        label_8->setStyleSheet(QString::fromUtf8(""));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        comb_Conf = new QComboBox(gridLayoutWidget);
        comb_Conf->setObjectName(QString::fromUtf8("comb_Conf"));
        comb_Conf->setMinimumSize(QSize(141, 51));
        comb_Conf->setMaximumSize(QSize(141, 51));
        comb_Conf->setFont(font);

        gridLayout->addWidget(comb_Conf, 0, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(101, 51));
        label->setMaximumSize(QSize(101, 51));
        label->setStyleSheet(QString::fromUtf8(""));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 2, 1, 1);

        Beep_Button = new QPushButton(gridLayoutWidget);
        Beep_Button->setObjectName(QString::fromUtf8("Beep_Button"));
        Beep_Button->setMinimumSize(QSize(141, 51));
        Beep_Button->setMaximumSize(QSize(141, 51));

        gridLayout->addWidget(Beep_Button, 2, 3, 1, 1);

        comb_Beep = new QComboBox(gridLayoutWidget);
        comb_Beep->setObjectName(QString::fromUtf8("comb_Beep"));
        comb_Beep->setMinimumSize(QSize(101, 0));
        comb_Beep->setMaximumSize(QSize(120, 120));
        QFont font1;
        font1.setPointSize(16);
        comb_Beep->setFont(font1);
        comb_Beep->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(comb_Beep, 2, 4, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(91, 51));
        label_2->setMaximumSize(QSize(91, 51));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_21 = new QLabel(gridLayoutWidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setMinimumSize(QSize(101, 51));
        label_21->setMaximumSize(QSize(101, 51));
        label_21->setStyleSheet(QString::fromUtf8(""));
        label_21->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_21, 1, 2, 1, 1);

        comb_Led = new QComboBox(gridLayoutWidget);
        comb_Led->setObjectName(QString::fromUtf8("comb_Led"));
        comb_Led->setMinimumSize(QSize(101, 0));
        comb_Led->setMaximumSize(QSize(200, 120));
        comb_Led->setFont(font1);

        gridLayout->addWidget(comb_Led, 2, 2, 1, 1);

        Led_Button = new QPushButton(gridLayoutWidget);
        Led_Button->setObjectName(QString::fromUtf8("Led_Button"));
        Led_Button->setMinimumSize(QSize(141, 51));
        Led_Button->setMaximumSize(QSize(141, 51));

        gridLayout->addWidget(Led_Button, 2, 1, 1, 1);

        Button_Check_2 = new QPushButton(gridLayoutWidget);
        Button_Check_2->setObjectName(QString::fromUtf8("Button_Check_2"));
        Button_Check_2->setMinimumSize(QSize(141, 51));
        Button_Check_2->setMaximumSize(QSize(141, 51));

        gridLayout->addWidget(Button_Check_2, 1, 3, 1, 1);

        label_18 = new QLabel(gridLayoutWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setMinimumSize(QSize(91, 51));
        label_18->setMaximumSize(QSize(101, 51));
        label_18->setStyleSheet(QString::fromUtf8(""));
        label_18->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_18, 3, 0, 1, 1);

        label_32 = new QLabel(gridLayoutWidget);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setMinimumSize(QSize(101, 51));
        label_32->setMaximumSize(QSize(91, 51));
        label_32->setStyleSheet(QString::fromUtf8(""));
        label_32->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_32, 3, 2, 1, 1);

        Button_SQL = new QPushButton(gridLayoutWidget);
        Button_SQL->setObjectName(QString::fromUtf8("Button_SQL"));
        Button_SQL->setMinimumSize(QSize(141, 51));
        Button_SQL->setMaximumSize(QSize(141, 51));

        gridLayout->addWidget(Button_SQL, 3, 3, 1, 1);

        Button_IO = new QPushButton(gridLayoutWidget);
        Button_IO->setObjectName(QString::fromUtf8("Button_IO"));
        Button_IO->setMinimumSize(QSize(121, 51));
        Button_IO->setMaximumSize(QSize(141, 51));

        gridLayout->addWidget(Button_IO, 0, 4, 1, 1);

        Button_Usart = new QPushButton(gridLayoutWidget);
        Button_Usart->setObjectName(QString::fromUtf8("Button_Usart"));
        Button_Usart->setMinimumSize(QSize(141, 51));
        Button_Usart->setMaximumSize(QSize(141, 51));

        gridLayout->addWidget(Button_Usart, 1, 4, 1, 1);

        label_27 = new QLabel(w_Syst);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(10, 370, 91, 51));
        label_27->setMinimumSize(QSize(91, 51));
        label_27->setMaximumSize(QSize(91, 51));
        label_27->setStyleSheet(QString::fromUtf8(""));
        label_27->setAlignment(Qt::AlignCenter);
        comb_language = new QComboBox(w_Syst);
        comb_language->setObjectName(QString::fromUtf8("comb_language"));
        comb_language->setEnabled(false);
        comb_language->setGeometry(QRect(123, 370, 141, 50));
        comb_language->setMaximumSize(QSize(200, 120));
        comb_language->setFont(font);
        label_28 = new QLabel(w_Syst);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(280, 370, 271, 51));
        label_28->setStyleSheet(QString::fromUtf8(""));
        label_28->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        comb_power = new QComboBox(w_Syst);
        comb_power->setObjectName(QString::fromUtf8("comb_power"));
        comb_power->setGeometry(QRect(123, 310, 141, 50));
        comb_power->setMaximumSize(QSize(200, 120));
        comb_power->setFont(font1);
        label_3 = new QLabel(w_Syst);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 310, 91, 51));
        label_3->setMinimumSize(QSize(91, 51));
        label_3->setMaximumSize(QSize(91, 51));
        label_3->setAlignment(Qt::AlignCenter);
        label_30 = new QLabel(w_Syst);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(280, 310, 271, 51));
        label_30->setStyleSheet(QString::fromUtf8(""));
        label_30->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        comb_imp_back = new QComboBox(w_Syst);
        comb_imp_back->setObjectName(QString::fromUtf8("comb_imp_back"));
        comb_imp_back->setGeometry(QRect(123, 250, 141, 51));
        comb_imp_back->setMinimumSize(QSize(141, 51));
        comb_imp_back->setMaximumSize(QSize(141, 51));
        comb_imp_back->setFont(font);
        label_9 = new QLabel(w_Syst);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 250, 91, 51));
        label_9->setMinimumSize(QSize(91, 51));
        label_9->setMaximumSize(QSize(91, 51));
        label_9->setStyleSheet(QString::fromUtf8(""));
        label_9->setAlignment(Qt::AlignCenter);
        label_31 = new QLabel(w_Syst);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(280, 250, 271, 51));
        label_31->setStyleSheet(QString::fromUtf8(""));
        label_31->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        QWidget::setTabOrder(spinBox_6, comb_Start);
        QWidget::setTabOrder(comb_Start, Timer);
        QWidget::setTabOrder(Timer, spinBox_2);
        QWidget::setTabOrder(spinBox_2, Key_A);
        QWidget::setTabOrder(Key_A, spinBox_3);
        QWidget::setTabOrder(spinBox_3, Led_Button);
        QWidget::setTabOrder(Led_Button, spinBox_1);
        QWidget::setTabOrder(spinBox_1, spinBox_4);
        QWidget::setTabOrder(spinBox_4, spinBox_5);
        QWidget::setTabOrder(spinBox_5, comb_Conf);
        QWidget::setTabOrder(comb_Conf, comb_Led);
        QWidget::setTabOrder(comb_Led, Beep_OK);
        QWidget::setTabOrder(Beep_OK, Beep_NG);
        QWidget::setTabOrder(Beep_NG, Key_H);
        QWidget::setTabOrder(Key_H, Button_Check);
        QWidget::setTabOrder(Button_Check, Button_Check_2);
        QWidget::setTabOrder(Button_Check_2, scan_start);
        QWidget::setTabOrder(scan_start, scan_stop);
        QWidget::setTabOrder(scan_stop, lineEdit);

        retranslateUi(w_Syst);

        QMetaObject::connectSlotsByName(w_Syst);
    } // setupUi

    void retranslateUi(QDialog *w_Syst)
    {
        Key_A->setText(QApplication::translate("w_Syst", "\344\277\235\345\255\230\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        Timer->setText(QApplication::translate("w_Syst", "\347\241\256\345\256\232\346\233\264\346\224\271", 0, QApplication::UnicodeUTF8));
        Key_H->setText(QApplication::translate("w_Syst", "\350\260\203\350\257\225\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("w_Syst", "\345\220\210\346\240\274\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("w_Syst", "\344\270\215\345\220\210\346\240\274\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("w_Syst", "\350\256\276\347\275\256\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("w_Syst", "\345\271\264", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("w_Syst", "\346\234\210", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("w_Syst", "\346\227\245", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("w_Syst", "\346\227\266", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("w_Syst", "\345\210\206", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("w_Syst", "\347\247\222", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("w_Syst", "\347\247\222", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("w_Syst", "\346\212\245\350\255\246\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("w_Syst", "\346\235\241\347\240\201\346\211\253\346\217\217\357\274\232", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("w_Syst", "\350\265\267\345\247\213\345\255\227\350\212\202\357\274\232", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("w_Syst", "\347\273\223\346\235\237\345\255\227\350\212\202\357\274\232", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("w_Syst", "\344\275\215", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("w_Syst", "\344\275\215", 0, QApplication::UnicodeUTF8));
        Button_Check_3->setText(QApplication::translate("w_Syst", "\347\275\221\347\273\234", 0, QApplication::UnicodeUTF8));
        comb_Start->clear();
        comb_Start->insertItems(0, QStringList()
         << QApplication::translate("w_Syst", "\346\214\211\351\222\256\345\220\257\345\212\250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "\350\204\232\350\270\217\345\220\257\345\212\250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "\346\273\221\347\275\251\345\220\257\345\212\250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "\347\275\221\347\273\234\345\220\257\345\212\250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "\350\277\236\346\216\245\345\220\257\345\212\250", 0, QApplication::UnicodeUTF8)
        );
        Button_Check->setText(QApplication::translate("w_Syst", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("w_Syst", "\347\212\266\346\200\201\346\237\245\350\257\242\357\274\232", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("w_Syst", "\344\272\256\345\272\246/\351\237\263\351\207\217\357\274\232", 0, QApplication::UnicodeUTF8));
        comb_Conf->clear();
        comb_Conf->insertItems(0, QStringList()
         << QApplication::translate("w_Syst", "\346\223\215\344\275\234\345\221\230", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "\347\256\241\347\220\206\345\221\230", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("w_Syst", "\345\220\257\345\212\250\346\226\271\345\274\217\357\274\232", 0, QApplication::UnicodeUTF8));
        Beep_Button->setText(QApplication::translate("w_Syst", "\351\237\263\351\207\217 \350\256\276\345\256\232\346\237\245\347\234\213", 0, QApplication::UnicodeUTF8));
        comb_Beep->clear();
        comb_Beep->insertItems(0, QStringList()
         << QApplication::translate("w_Syst", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "10", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("w_Syst", "\346\223\215\344\275\234\347\224\250\346\210\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("w_Syst", "\346\240\241\345\207\206\345\261\217\345\271\225\357\274\232", 0, QApplication::UnicodeUTF8));
        comb_Led->clear();
        comb_Led->insertItems(0, QStringList()
         << QApplication::translate("w_Syst", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "10", 0, QApplication::UnicodeUTF8)
        );
        Led_Button->setText(QApplication::translate("w_Syst", "\344\272\256\345\272\246 \350\256\276\345\256\232\346\237\245\347\234\213", 0, QApplication::UnicodeUTF8));
        Button_Check_2->setText(QApplication::translate("w_Syst", "\346\240\241\345\207\206", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("w_Syst", "\347\275\221\347\273\234\357\274\232", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("w_Syst", "\346\225\260\346\215\256\345\272\223\357\274\232", 0, QApplication::UnicodeUTF8));
        Button_SQL->setText(QApplication::translate("w_Syst", "\346\225\260\346\215\256\345\272\223", 0, QApplication::UnicodeUTF8));
        Button_IO->setText(QApplication::translate("w_Syst", "\351\205\215\347\275\256\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        Button_Usart->setText(QApplication::translate("w_Syst", "\344\270\262\345\217\243", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("w_Syst", "\350\257\255\350\250\200\357\274\232", 0, QApplication::UnicodeUTF8));
        comb_language->clear();
        comb_language->insertItems(0, QStringList()
         << QApplication::translate("w_Syst", "\344\270\255\346\226\207", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "English", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "Japan", 0, QApplication::UnicodeUTF8)
        );
        label_28->setText(QApplication::translate("w_Syst", "<\344\277\235\345\255\230\350\277\224\345\233\236>\357\274\214\351\207\215\345\220\257\347\224\237\346\225\210", 0, QApplication::UnicodeUTF8));
        comb_power->clear();
        comb_power->insertItems(0, QStringList()
         << QApplication::translate("w_Syst", "\346\227\240", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "\350\211\276\346\231\256", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "\345\244\226\351\203\250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "\345\217\230\345\216\213\345\231\250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "\345\206\205\351\203\250", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("w_Syst", "\347\224\265\346\272\220\357\274\232", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("w_Syst", "<\344\277\235\345\255\230\350\277\224\345\233\236>\357\274\214\351\207\215\345\220\257\347\224\237\346\225\210", 0, QApplication::UnicodeUTF8));
        comb_imp_back->clear();
        comb_imp_back->insertItems(0, QStringList()
         << QApplication::translate("w_Syst", "\345\217\215\351\246\210", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Syst", "\344\270\215\345\217\215\351\246\210", 0, QApplication::UnicodeUTF8)
        );
        label_9->setText(QApplication::translate("w_Syst", "\345\214\235\351\227\264\347\224\265\345\216\213\357\274\232", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("w_Syst", "<\344\277\235\345\255\230\350\277\224\345\233\236>\357\274\214\351\207\215\345\220\257\347\224\237\346\225\210", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(w_Syst);
    } // retranslateUi

};

namespace Ui {
    class w_Syst: public Ui_w_Syst {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_SYST_H
