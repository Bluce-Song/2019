/********************************************************************************
** Form generated from reading UI file 'Widget_PWR.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_PWR_H
#define UI_WIDGET_PWR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_PWR
{
public:
    QTableWidget *pwrTab;
    QTableWidget *pgTab;
    QCheckBox *checkBox_pwm;
    QCheckBox *checkBox_3;
    QLabel *label_grade_10;
    QDoubleSpinBox *PWR_Volume_value;
    QLabel *label_grade_8;
    QDoubleSpinBox *PWR_Volt_up;
    QLabel *label_grade_9;
    QDoubleSpinBox *PWR_Volt_down;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Volt;
    QLabel *label_volt;
    QDoubleSpinBox *PWR_Volt;
    QLabel *label_fre;
    QDoubleSpinBox *PWR_Fre;
    QLabel *label_channel;
    QDoubleSpinBox *PWR_channel;
    QLabel *label_time;
    QDoubleSpinBox *PWR_time;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_4;
    QFrame *frame;
    QLabel *label_pg_volt;
    QDoubleSpinBox *PG_volt;
    QCheckBox *checkBox_pg;
    QLabel *label_pg_conut;
    QDoubleSpinBox *pg_count;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_pg_conut_2;
    QComboBox *Com_PG_DLR;
    QPushButton *pushButton_Noise;
    QTableWidget *pwrset_Turn;

    void setupUi(QWidget *Widget_PWR)
    {
        if (Widget_PWR->objectName().isEmpty())
            Widget_PWR->setObjectName(QString::fromUtf8("Widget_PWR"));
        Widget_PWR->resize(721, 600);
        pwrTab = new QTableWidget(Widget_PWR);
        if (pwrTab->columnCount() < 9)
            pwrTab->setColumnCount(9);
        QFont font;
        font.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem->setFont(font);
        pwrTab->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem1->setFont(font);
        pwrTab->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem2->setFont(font);
        pwrTab->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem3->setFont(font);
        pwrTab->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem4->setFont(font);
        pwrTab->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem5->setFont(font);
        pwrTab->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem6->setFont(font);
        pwrTab->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem7->setFont(font);
        pwrTab->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem8->setFont(font);
        pwrTab->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        pwrTab->setObjectName(QString::fromUtf8("pwrTab"));
        pwrTab->setGeometry(QRect(20, 110, 681, 291));
        pwrTab->setFocusPolicy(Qt::NoFocus);
        pwrTab->setInputMethodHints(Qt::ImhNone);
        pwrTab->setEditTriggers(QAbstractItemView::AllEditTriggers);
        pwrTab->setAlternatingRowColors(false);
        pwrTab->setSelectionMode(QAbstractItemView::SingleSelection);
        pwrTab->horizontalHeader()->setDefaultSectionSize(50);
        pwrTab->horizontalHeader()->setStretchLastSection(true);
        pwrTab->verticalHeader()->setVisible(false);
        pwrTab->verticalHeader()->setDefaultSectionSize(40);
        pgTab = new QTableWidget(Widget_PWR);
        if (pgTab->columnCount() < 7)
            pgTab->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem9->setFont(font);
        pgTab->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem10->setFont(font);
        pgTab->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem11->setFont(font);
        pgTab->setHorizontalHeaderItem(2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem12->setFont(font);
        pgTab->setHorizontalHeaderItem(3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem13->setFont(font);
        pgTab->setHorizontalHeaderItem(4, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem14->setFont(font);
        pgTab->setHorizontalHeaderItem(5, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem15->setFont(font);
        pgTab->setHorizontalHeaderItem(6, __qtablewidgetitem15);
        pgTab->setObjectName(QString::fromUtf8("pgTab"));
        pgTab->setGeometry(QRect(20, 470, 527, 107));
        pgTab->setFocusPolicy(Qt::NoFocus);
        pgTab->setInputMethodHints(Qt::ImhNone);
        pgTab->setEditTriggers(QAbstractItemView::AllEditTriggers);
        pgTab->setAlternatingRowColors(false);
        pgTab->setSelectionMode(QAbstractItemView::SingleSelection);
        pgTab->horizontalHeader()->setDefaultSectionSize(50);
        pgTab->horizontalHeader()->setStretchLastSection(true);
        pgTab->verticalHeader()->setVisible(false);
        pgTab->verticalHeader()->setDefaultSectionSize(40);
        checkBox_pwm = new QCheckBox(Widget_PWR);
        checkBox_pwm->setObjectName(QString::fromUtf8("checkBox_pwm"));
        checkBox_pwm->setGeometry(QRect(20, 10, 100, 41));
        checkBox_pwm->setMinimumSize(QSize(91, 41));
        checkBox_pwm->setMaximumSize(QSize(100, 41));
        QFont font1;
        font1.setPointSize(11);
        checkBox_pwm->setFont(font1);
        checkBox_pwm->setStyleSheet(QString::fromUtf8(" QCheckBox::indicator {\n"
"	color: rgb(255, 255, 255);\n"
"image: url(:/image/053.png);\n"
"      width: 50px;\n"
"      height: 55px;\n"
"  }\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/image/051.png)\n"
";}\");\n"
""));
        checkBox_pwm->setIconSize(QSize(8, 8));
        checkBox_pwm->setAutoRepeatDelay(300);
        checkBox_3 = new QCheckBox(Widget_PWR);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(140, 10, 151, 41));
        checkBox_3->setMinimumSize(QSize(151, 41));
        checkBox_3->setMaximumSize(QSize(151, 41));
        checkBox_3->setFont(font1);
        checkBox_3->setStyleSheet(QString::fromUtf8(" QCheckBox::indicator {\n"
"	color: rgb(255, 255, 255);\n"
"image: url(:/image/053.png);\n"
"      width: 50px;\n"
"      height: 55px;\n"
"  }\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/image/051.png)\n"
";}\");\n"
""));
        checkBox_3->setIconSize(QSize(8, 8));
        checkBox_3->setAutoRepeatDelay(300);
        label_grade_10 = new QLabel(Widget_PWR);
        label_grade_10->setObjectName(QString::fromUtf8("label_grade_10"));
        label_grade_10->setGeometry(QRect(830, 10, 111, 41));
        label_grade_10->setMinimumSize(QSize(111, 41));
        label_grade_10->setMaximumSize(QSize(111, 41));
        label_grade_10->setAlignment(Qt::AlignCenter);
        PWR_Volume_value = new QDoubleSpinBox(Widget_PWR);
        PWR_Volume_value->setObjectName(QString::fromUtf8("PWR_Volume_value"));
        PWR_Volume_value->setGeometry(QRect(830, 10, 71, 41));
        PWR_Volume_value->setMinimumSize(QSize(70, 41));
        PWR_Volume_value->setMaximumSize(QSize(90, 41));
        PWR_Volume_value->setAlignment(Qt::AlignCenter);
        PWR_Volume_value->setButtonSymbols(QAbstractSpinBox::NoButtons);
        PWR_Volume_value->setDecimals(1);
        PWR_Volume_value->setMaximum(380);
        PWR_Volume_value->setSingleStep(0.1);
        PWR_Volume_value->setValue(1);
        label_grade_8 = new QLabel(Widget_PWR);
        label_grade_8->setObjectName(QString::fromUtf8("label_grade_8"));
        label_grade_8->setGeometry(QRect(830, 10, 101, 41));
        label_grade_8->setMinimumSize(QSize(81, 41));
        label_grade_8->setMaximumSize(QSize(101, 41));
        label_grade_8->setAlignment(Qt::AlignCenter);
        PWR_Volt_up = new QDoubleSpinBox(Widget_PWR);
        PWR_Volt_up->setObjectName(QString::fromUtf8("PWR_Volt_up"));
        PWR_Volt_up->setGeometry(QRect(830, 10, 70, 41));
        PWR_Volt_up->setMinimumSize(QSize(70, 41));
        PWR_Volt_up->setMaximumSize(QSize(80, 41));
        PWR_Volt_up->setAlignment(Qt::AlignCenter);
        PWR_Volt_up->setButtonSymbols(QAbstractSpinBox::NoButtons);
        PWR_Volt_up->setDecimals(1);
        PWR_Volt_up->setMaximum(380);
        PWR_Volt_up->setSingleStep(0.1);
        PWR_Volt_up->setValue(1);
        label_grade_9 = new QLabel(Widget_PWR);
        label_grade_9->setObjectName(QString::fromUtf8("label_grade_9"));
        label_grade_9->setGeometry(QRect(830, 10, 101, 41));
        label_grade_9->setMinimumSize(QSize(81, 41));
        label_grade_9->setMaximumSize(QSize(101, 41));
        label_grade_9->setAlignment(Qt::AlignCenter);
        PWR_Volt_down = new QDoubleSpinBox(Widget_PWR);
        PWR_Volt_down->setObjectName(QString::fromUtf8("PWR_Volt_down"));
        PWR_Volt_down->setGeometry(QRect(830, 10, 70, 41));
        PWR_Volt_down->setMinimumSize(QSize(70, 41));
        PWR_Volt_down->setMaximumSize(QSize(90, 41));
        PWR_Volt_down->setAlignment(Qt::AlignCenter);
        PWR_Volt_down->setButtonSymbols(QAbstractSpinBox::NoButtons);
        PWR_Volt_down->setDecimals(1);
        PWR_Volt_down->setMaximum(380);
        PWR_Volt_down->setSingleStep(0.1);
        PWR_Volt_down->setValue(1);
        horizontalLayoutWidget = new QWidget(Widget_PWR);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(140, 60, 769, 43));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_Volt = new QPushButton(horizontalLayoutWidget);
        pushButton_Volt->setObjectName(QString::fromUtf8("pushButton_Volt"));
        pushButton_Volt->setMinimumSize(QSize(100, 41));
        pushButton_Volt->setMaximumSize(QSize(100, 41));

        horizontalLayout->addWidget(pushButton_Volt);

        label_volt = new QLabel(horizontalLayoutWidget);
        label_volt->setObjectName(QString::fromUtf8("label_volt"));
        label_volt->setMinimumSize(QSize(51, 41));
        label_volt->setMaximumSize(QSize(61, 41));
        label_volt->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_volt);

        PWR_Volt = new QDoubleSpinBox(horizontalLayoutWidget);
        PWR_Volt->setObjectName(QString::fromUtf8("PWR_Volt"));
        PWR_Volt->setMinimumSize(QSize(70, 41));
        PWR_Volt->setMaximumSize(QSize(70, 41));
        PWR_Volt->setAlignment(Qt::AlignCenter);
        PWR_Volt->setButtonSymbols(QAbstractSpinBox::NoButtons);
        PWR_Volt->setDecimals(0);
        PWR_Volt->setMaximum(380);
        PWR_Volt->setSingleStep(0.1);
        PWR_Volt->setValue(1);

        horizontalLayout->addWidget(PWR_Volt);

        label_fre = new QLabel(horizontalLayoutWidget);
        label_fre->setObjectName(QString::fromUtf8("label_fre"));
        label_fre->setMinimumSize(QSize(86, 41));
        label_fre->setMaximumSize(QSize(101, 41));
        label_fre->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_fre);

        PWR_Fre = new QDoubleSpinBox(horizontalLayoutWidget);
        PWR_Fre->setObjectName(QString::fromUtf8("PWR_Fre"));
        PWR_Fre->setMinimumSize(QSize(70, 41));
        PWR_Fre->setMaximumSize(QSize(70, 41));
        PWR_Fre->setAlignment(Qt::AlignCenter);
        PWR_Fre->setButtonSymbols(QAbstractSpinBox::NoButtons);
        PWR_Fre->setDecimals(1);
        PWR_Fre->setMaximum(99);
        PWR_Fre->setSingleStep(0.1);
        PWR_Fre->setValue(1);

        horizontalLayout->addWidget(PWR_Fre);

        label_channel = new QLabel(horizontalLayoutWidget);
        label_channel->setObjectName(QString::fromUtf8("label_channel"));
        label_channel->setMinimumSize(QSize(71, 41));
        label_channel->setMaximumSize(QSize(101, 41));
        label_channel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_channel);

        PWR_channel = new QDoubleSpinBox(horizontalLayoutWidget);
        PWR_channel->setObjectName(QString::fromUtf8("PWR_channel"));
        PWR_channel->setMinimumSize(QSize(70, 41));
        PWR_channel->setMaximumSize(QSize(70, 41));
        PWR_channel->setAlignment(Qt::AlignCenter);
        PWR_channel->setButtonSymbols(QAbstractSpinBox::NoButtons);
        PWR_channel->setDecimals(0);
        PWR_channel->setMinimum(1);
        PWR_channel->setMaximum(3);
        PWR_channel->setSingleStep(1);
        PWR_channel->setValue(1);

        horizontalLayout->addWidget(PWR_channel);

        label_time = new QLabel(horizontalLayoutWidget);
        label_time->setObjectName(QString::fromUtf8("label_time"));
        label_time->setMinimumSize(QSize(125, 41));
        label_time->setMaximumSize(QSize(125, 41));
        label_time->setFont(font);
        label_time->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_time);

        PWR_time = new QDoubleSpinBox(horizontalLayoutWidget);
        PWR_time->setObjectName(QString::fromUtf8("PWR_time"));
        PWR_time->setMinimumSize(QSize(70, 41));
        PWR_time->setMaximumSize(QSize(70, 41));
        PWR_time->setAlignment(Qt::AlignCenter);
        PWR_time->setButtonSymbols(QAbstractSpinBox::NoButtons);
        PWR_time->setDecimals(0);
        PWR_time->setMinimum(0);
        PWR_time->setMaximum(5000);
        PWR_time->setSingleStep(1);
        PWR_time->setValue(0);

        horizontalLayout->addWidget(PWR_time);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButton_4 = new QToolButton(Widget_PWR);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setGeometry(QRect(650, 10, 71, 41));
        toolButton_4->setStyleSheet(QString::fromUtf8("QToolButton{border:0px;}\n"
""));
        frame = new QFrame(Widget_PWR);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(552, 457, 146, 121));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    border: 1px solid white;\n"
"    border-color: #447684;\n"
"    color: rgb(255, 255, 255);\n"
"}\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_pg_volt = new QLabel(frame);
        label_pg_volt->setObjectName(QString::fromUtf8("label_pg_volt"));
        label_pg_volt->setGeometry(QRect(10, 0, 71, 41));
        label_pg_volt->setFont(font);
        label_pg_volt->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_pg_volt->setAlignment(Qt::AlignCenter);
        PG_volt = new QDoubleSpinBox(frame);
        PG_volt->setObjectName(QString::fromUtf8("PG_volt"));
        PG_volt->setGeometry(QRect(80, 2, 63, 36));
        PG_volt->setAlignment(Qt::AlignCenter);
        PG_volt->setButtonSymbols(QAbstractSpinBox::NoButtons);
        PG_volt->setDecimals(1);
        PG_volt->setMinimum(3);
        PG_volt->setMaximum(15);
        PG_volt->setSingleStep(0.1);
        PG_volt->setValue(3.3);
        checkBox_pg = new QCheckBox(frame);
        checkBox_pg->setObjectName(QString::fromUtf8("checkBox_pg"));
        checkBox_pg->setEnabled(true);
        checkBox_pg->setGeometry(QRect(10, 80, 121, 41));
        checkBox_pg->setFont(font1);
        checkBox_pg->setStyleSheet(QString::fromUtf8(" QCheckBox::indicator {\n"
"	color: rgb(255, 255, 255);\n"
"image: url(:/image/053.png);\n"
"      width: 50px;\n"
"      height: 55px;\n"
"  }\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/image/051.png)\n"
";}\");\n"
""));
        checkBox_pg->setIconSize(QSize(8, 8));
        checkBox_pg->setAutoRepeatDelay(300);
        label_pg_conut = new QLabel(frame);
        label_pg_conut->setObjectName(QString::fromUtf8("label_pg_conut"));
        label_pg_conut->setGeometry(QRect(10, 40, 71, 41));
        label_pg_conut->setFont(font);
        label_pg_conut->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_pg_conut->setAlignment(Qt::AlignCenter);
        pg_count = new QDoubleSpinBox(frame);
        pg_count->setObjectName(QString::fromUtf8("pg_count"));
        pg_count->setGeometry(QRect(80, 42, 63, 37));
        pg_count->setAlignment(Qt::AlignCenter);
        pg_count->setButtonSymbols(QAbstractSpinBox::NoButtons);
        pg_count->setDecimals(0);
        pg_count->setMinimum(1);
        pg_count->setMaximum(16);
        pg_count->setSingleStep(1);
        pg_count->setValue(1);
        horizontalLayoutWidget_2 = new QWidget(Widget_PWR);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(20, 400, 536, 61));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_1 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setMinimumSize(QSize(83, 45));
        pushButton_1->setMaximumSize(QSize(83, 45));

        horizontalLayout_2->addWidget(pushButton_1);

        pushButton_2 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(83, 45));
        pushButton_2->setMaximumSize(QSize(83, 45));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(83, 45));
        pushButton_3->setMaximumSize(QSize(83, 45));

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(83, 45));
        pushButton_4->setMaximumSize(QSize(83, 45));

        horizontalLayout_2->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(83, 45));
        pushButton_5->setMaximumSize(QSize(83, 45));

        horizontalLayout_2->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(83, 45));
        pushButton_6->setMaximumSize(QSize(83, 45));

        horizontalLayout_2->addWidget(pushButton_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_pg_conut_2 = new QLabel(Widget_PWR);
        label_pg_conut_2->setObjectName(QString::fromUtf8("label_pg_conut_2"));
        label_pg_conut_2->setGeometry(QRect(560, 410, 71, 41));
        label_pg_conut_2->setFont(font);
        label_pg_conut_2->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_pg_conut_2->setAlignment(Qt::AlignCenter);
        Com_PG_DLR = new QComboBox(Widget_PWR);
        Com_PG_DLR->setObjectName(QString::fromUtf8("Com_PG_DLR"));
        Com_PG_DLR->setGeometry(QRect(630, 410, 63, 41));
        Com_PG_DLR->setMinimumSize(QSize(63, 0));
        Com_PG_DLR->setMaximumSize(QSize(200, 50));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu"));
        font2.setPointSize(15);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(9);
        Com_PG_DLR->setFont(font2);
        Com_PG_DLR->setStyleSheet(QString::fromUtf8("\n"
"QComboBox {\n"
"font: 75 15pt \"Ubuntu\";\n"
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
"    width: 18px;\n"
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
        pushButton_Noise = new QPushButton(Widget_PWR);
        pushButton_Noise->setObjectName(QString::fromUtf8("pushButton_Noise"));
        pushButton_Noise->setGeometry(QRect(20, 60, 100, 41));
        pushButton_Noise->setMinimumSize(QSize(100, 41));
        pushButton_Noise->setMaximumSize(QSize(100, 41));
        pwrset_Turn = new QTableWidget(Widget_PWR);
        if (pwrset_Turn->columnCount() < 1)
            pwrset_Turn->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem16->setFont(font);
        pwrset_Turn->setHorizontalHeaderItem(0, __qtablewidgetitem16);
        pwrset_Turn->setObjectName(QString::fromUtf8("pwrset_Turn"));
        pwrset_Turn->setGeometry(QRect(3, 110, 50, 291));
        pwrset_Turn->setFocusPolicy(Qt::NoFocus);
        pwrset_Turn->setInputMethodHints(Qt::ImhNone);
        pwrset_Turn->setEditTriggers(QAbstractItemView::AllEditTriggers);
        pwrset_Turn->setAlternatingRowColors(false);
        pwrset_Turn->setSelectionMode(QAbstractItemView::SingleSelection);
        pwrset_Turn->horizontalHeader()->setDefaultSectionSize(50);
        pwrset_Turn->horizontalHeader()->setStretchLastSection(true);
        pwrset_Turn->verticalHeader()->setVisible(false);
        pwrset_Turn->verticalHeader()->setDefaultSectionSize(40);
        QWidget::setTabOrder(checkBox_3, PG_volt);
        QWidget::setTabOrder(PG_volt, checkBox_pwm);
        QWidget::setTabOrder(checkBox_pwm, checkBox_pg);
        QWidget::setTabOrder(checkBox_pg, PWR_Volume_value);
        QWidget::setTabOrder(PWR_Volume_value, PWR_Volt);
        QWidget::setTabOrder(PWR_Volt, PWR_Volt_up);
        QWidget::setTabOrder(PWR_Volt_up, PWR_Volt_down);

        retranslateUi(Widget_PWR);

        QMetaObject::connectSlotsByName(Widget_PWR);
    } // setupUi

    void retranslateUi(QWidget *Widget_PWR)
    {
        Widget_PWR->setWindowTitle(QApplication::translate("Widget_PWR", "Form", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = pwrTab->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget_PWR", "\346\241\243\344\275\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = pwrTab->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget_PWR", "\347\224\265\346\265\201\344\270\213\351\231\220A", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = pwrTab->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget_PWR", "\347\224\265\346\265\201\344\270\212\351\231\220A", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = pwrTab->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Widget_PWR", "\345\212\237\347\216\207\344\270\213\351\231\220W", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = pwrTab->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Widget_PWR", "\345\212\237\347\216\207\344\270\212\351\231\220W", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = pwrTab->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Widget_PWR", "\345\256\271\345\216\213\344\270\213\351\231\220V", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = pwrTab->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Widget_PWR", "\345\256\271\345\216\213\344\270\212\351\231\220V", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = pwrTab->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("Widget_PWR", "\350\275\254\345\220\221", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = pwrTab->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("Widget_PWR", "\346\227\266\351\227\264S", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = pgTab->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("Widget_PWR", "\351\253\230\347\224\265\345\271\263", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = pgTab->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QApplication::translate("Widget_PWR", "\344\275\216\347\224\265\345\271\263", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = pgTab->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QApplication::translate("Widget_PWR", "\351\242\221\347\216\207", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = pgTab->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QApplication::translate("Widget_PWR", "\345\215\240\347\251\272\346\257\224", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = pgTab->horizontalHeaderItem(5);
        ___qtablewidgetitem13->setText(QApplication::translate("Widget_PWR", "\347\224\265\346\265\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = pgTab->horizontalHeaderItem(6);
        ___qtablewidgetitem14->setText(QApplication::translate("Widget_PWR", "\350\275\254\351\200\237", 0, QApplication::UnicodeUTF8));
        checkBox_pwm->setText(QApplication::translate("Widget_PWR", "\347\224\265\345\217\202", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("Widget_PWR", "\350\257\246\347\273\206\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        label_grade_10->setText(QApplication::translate("Widget_PWR", "\345\256\271\345\200\274\357\274\232", 0, QApplication::UnicodeUTF8));
        label_grade_8->setText(QApplication::translate("Widget_PWR", "\347\224\265\345\216\213\344\270\212\351\231\220\357\274\232", 0, QApplication::UnicodeUTF8));
        label_grade_9->setText(QApplication::translate("Widget_PWR", "\347\224\265\345\216\213\344\270\213\351\231\220\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton_Volt->setText(QApplication::translate("Widget_PWR", "\350\241\245\345\201\277\347\224\265\345\216\213", 0, QApplication::UnicodeUTF8));
        label_volt->setText(QApplication::translate("Widget_PWR", "\347\224\265\345\216\213\357\274\232", 0, QApplication::UnicodeUTF8));
        label_fre->setText(QApplication::translate("Widget_PWR", "\351\242\221\347\216\207\357\274\232", 0, QApplication::UnicodeUTF8));
        label_channel->setText(QApplication::translate("Widget_PWR", "\351\200\232\351\201\223\357\274\232", 0, QApplication::UnicodeUTF8));
        label_time->setText(QApplication::translate("Widget_PWR", "\346\241\243\344\275\215\345\210\207\346\215\242\346\227\266\351\227\264(ms)\357\274\232", 0, QApplication::UnicodeUTF8));
        toolButton_4->setText(QString());
        label_pg_volt->setText(QApplication::translate("Widget_PWR", "\347\224\265\345\216\213(V)\357\274\232", 0, QApplication::UnicodeUTF8));
        checkBox_pg->setText(QApplication::translate("Widget_PWR", "PG\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        label_pg_conut->setText(QApplication::translate("Widget_PWR", "\346\236\201\346\225\260\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton_1->setText(QApplication::translate("Widget_PWR", "Text", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Widget_PWR", "Text", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Widget_PWR", "Text", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("Widget_PWR", "Text", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("Widget_PWR", "Text", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("Widget_PWR", "Text", 0, QApplication::UnicodeUTF8));
        label_pg_conut_2->setText(QApplication::translate("Widget_PWR", "\344\270\212\346\213\211\347\224\265\351\230\273\357\274\232", 0, QApplication::UnicodeUTF8));
        Com_PG_DLR->clear();
        Com_PG_DLR->insertItems(0, QStringList()
         << QApplication::translate("Widget_PWR", "\346\230\257", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_PWR", "\345\220\246", 0, QApplication::UnicodeUTF8)
        );
        pushButton_Noise->setText(QApplication::translate("Widget_PWR", "\345\231\252\351\237\263\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = pwrset_Turn->horizontalHeaderItem(0);
        ___qtablewidgetitem15->setText(QApplication::translate("Widget_PWR", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget_PWR: public Ui_Widget_PWR {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_PWR_H
