/********************************************************************************
** Form generated from reading UI file 'widget_bldc_pg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_BLDC_PG_H
#define UI_WIDGET_BLDC_PG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_BLDC_PG
{
public:
    QTableWidget *bldcpgTab;
    QFrame *frame;
    QLabel *label_bldcpg_volt;
    QDoubleSpinBox *bldcPG_volt;
    QLabel *label_bldcpg_conut;
    QDoubleSpinBox *bldcpg_count;
    QLabel *label_bldcpg_time;
    QComboBox *Com_DLR;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QCheckBox *checkBox_HALL_C;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QPushButton *HALL_D;
    QCheckBox *checkBox_HALL_D;
    QPushButton *HALL_A;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer;
    QCheckBox *checkBox_HALL_A;
    QPushButton *HALL_B;
    QCheckBox *checkBox_HALL_B;
    QPushButton *HALL_C;
    QCheckBox *checkBox_HALL_E;
    QPushButton *HALL_E;
    QLabel *label_bldcpg_volt_2;
    QDoubleSpinBox *bldcPG_wave;

    void setupUi(QWidget *Widget_BLDC_PG)
    {
        if (Widget_BLDC_PG->objectName().isEmpty())
            Widget_BLDC_PG->setObjectName(QString::fromUtf8("Widget_BLDC_PG"));
        Widget_BLDC_PG->resize(721, 600);
        bldcpgTab = new QTableWidget(Widget_BLDC_PG);
        if (bldcpgTab->columnCount() < 5)
            bldcpgTab->setColumnCount(5);
        QFont font;
        font.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem->setFont(font);
        bldcpgTab->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem1->setFont(font);
        bldcpgTab->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem2->setFont(font);
        bldcpgTab->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem3->setFont(font);
        bldcpgTab->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem4->setFont(font);
        bldcpgTab->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        bldcpgTab->setObjectName(QString::fromUtf8("bldcpgTab"));
        bldcpgTab->setGeometry(QRect(100, 160, 521, 117));
        bldcpgTab->setFocusPolicy(Qt::NoFocus);
        bldcpgTab->setInputMethodHints(Qt::ImhNone);
        bldcpgTab->setEditTriggers(QAbstractItemView::AllEditTriggers);
        bldcpgTab->setAlternatingRowColors(false);
        bldcpgTab->setSelectionMode(QAbstractItemView::SingleSelection);
        bldcpgTab->horizontalHeader()->setDefaultSectionSize(50);
        bldcpgTab->horizontalHeader()->setStretchLastSection(true);
        bldcpgTab->verticalHeader()->setVisible(false);
        bldcpgTab->verticalHeader()->setDefaultSectionSize(40);
        frame = new QFrame(Widget_BLDC_PG);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(100, 80, 521, 61));
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_bldcpg_volt = new QLabel(frame);
        label_bldcpg_volt->setObjectName(QString::fromUtf8("label_bldcpg_volt"));
        label_bldcpg_volt->setGeometry(QRect(10, 10, 81, 41));
        QFont font1;
        font1.setPointSize(11);
        label_bldcpg_volt->setFont(font1);
        label_bldcpg_volt->setStyleSheet(QString::fromUtf8(""));
        label_bldcpg_volt->setAlignment(Qt::AlignCenter);
        bldcPG_volt = new QDoubleSpinBox(frame);
        bldcPG_volt->setObjectName(QString::fromUtf8("bldcPG_volt"));
        bldcPG_volt->setGeometry(QRect(90, 10, 60, 41));
        bldcPG_volt->setAlignment(Qt::AlignCenter);
        bldcPG_volt->setButtonSymbols(QAbstractSpinBox::NoButtons);
        bldcPG_volt->setDecimals(1);
        bldcPG_volt->setMinimum(0);
        bldcPG_volt->setMaximum(15);
        bldcPG_volt->setSingleStep(0.1);
        bldcPG_volt->setValue(3.3);
        label_bldcpg_conut = new QLabel(frame);
        label_bldcpg_conut->setObjectName(QString::fromUtf8("label_bldcpg_conut"));
        label_bldcpg_conut->setGeometry(QRect(170, 10, 71, 41));
        label_bldcpg_conut->setFont(font1);
        label_bldcpg_conut->setStyleSheet(QString::fromUtf8(""));
        label_bldcpg_conut->setAlignment(Qt::AlignCenter);
        bldcpg_count = new QDoubleSpinBox(frame);
        bldcpg_count->setObjectName(QString::fromUtf8("bldcpg_count"));
        bldcpg_count->setGeometry(QRect(240, 10, 60, 41));
        bldcpg_count->setAlignment(Qt::AlignCenter);
        bldcpg_count->setButtonSymbols(QAbstractSpinBox::NoButtons);
        bldcpg_count->setDecimals(0);
        bldcpg_count->setMinimum(1);
        bldcpg_count->setMaximum(16);
        bldcpg_count->setSingleStep(1);
        bldcpg_count->setValue(1);
        label_bldcpg_time = new QLabel(frame);
        label_bldcpg_time->setObjectName(QString::fromUtf8("label_bldcpg_time"));
        label_bldcpg_time->setGeometry(QRect(330, 10, 71, 41));
        label_bldcpg_time->setFont(font1);
        label_bldcpg_time->setStyleSheet(QString::fromUtf8(""));
        label_bldcpg_time->setAlignment(Qt::AlignCenter);
        Com_DLR = new QComboBox(frame);
        Com_DLR->setObjectName(QString::fromUtf8("Com_DLR"));
        Com_DLR->setGeometry(QRect(400, 10, 111, 36));
        Com_DLR->setMinimumSize(QSize(66, 0));
        Com_DLR->setMaximumSize(QSize(200, 50));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu"));
        font2.setPointSize(18);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(9);
        Com_DLR->setFont(font2);
        Com_DLR->setStyleSheet(QString::fromUtf8("\n"
"QComboBox {\n"
"font: 75 18pt \"Ubuntu\";\n"
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
        gridLayoutWidget = new QWidget(Widget_BLDC_PG);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(100, 290, 521, 111));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(10);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        checkBox_HALL_C = new QCheckBox(gridLayoutWidget);
        checkBox_HALL_C->setObjectName(QString::fromUtf8("checkBox_HALL_C"));
        checkBox_HALL_C->setEnabled(true);
        checkBox_HALL_C->setMaximumSize(QSize(88, 35));
        checkBox_HALL_C->setFont(font1);
        checkBox_HALL_C->setStyleSheet(QString::fromUtf8(" QCheckBox::indicator {\n"
"	color: rgb(255, 255, 255);\n"
"image: url(:/image/053.png);\n"
"      width: 50px;\n"
"      height: 55px;\n"
"  }\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/image/051.png)\n"
";}\n"
"QCheckBox\n"
"{\n"
"   	color: rgb(255, 255, 255);\n"
"}\n"
""));
        checkBox_HALL_C->setIconSize(QSize(8, 8));
        checkBox_HALL_C->setAutoRepeatDelay(300);

        gridLayout->addWidget(checkBox_HALL_C, 1, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 2, 3, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 2, 2, 1, 1);

        HALL_D = new QPushButton(gridLayoutWidget);
        HALL_D->setObjectName(QString::fromUtf8("HALL_D"));
        HALL_D->setMinimumSize(QSize(90, 45));
        HALL_D->setMaximumSize(QSize(90, 45));

        gridLayout->addWidget(HALL_D, 0, 3, 1, 1);

        checkBox_HALL_D = new QCheckBox(gridLayoutWidget);
        checkBox_HALL_D->setObjectName(QString::fromUtf8("checkBox_HALL_D"));
        checkBox_HALL_D->setEnabled(true);
        checkBox_HALL_D->setMaximumSize(QSize(88, 35));
        checkBox_HALL_D->setFont(font1);
        checkBox_HALL_D->setStyleSheet(QString::fromUtf8(" QCheckBox::indicator {\n"
"	color: rgb(255, 255, 255);\n"
"image: url(:/image/053.png);\n"
"      width: 50px;\n"
"      height: 55px;\n"
"  }\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/image/051.png)\n"
";}\n"
"QCheckBox\n"
"{\n"
"   	color: rgb(255, 255, 255);\n"
"}\n"
""));
        checkBox_HALL_D->setIconSize(QSize(8, 8));
        checkBox_HALL_D->setAutoRepeatDelay(300);

        gridLayout->addWidget(checkBox_HALL_D, 1, 3, 1, 1);

        HALL_A = new QPushButton(gridLayoutWidget);
        HALL_A->setObjectName(QString::fromUtf8("HALL_A"));
        HALL_A->setMinimumSize(QSize(90, 45));
        HALL_A->setMaximumSize(QSize(90, 45));

        gridLayout->addWidget(HALL_A, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 2, 4, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        checkBox_HALL_A = new QCheckBox(gridLayoutWidget);
        checkBox_HALL_A->setObjectName(QString::fromUtf8("checkBox_HALL_A"));
        checkBox_HALL_A->setEnabled(true);
        checkBox_HALL_A->setMaximumSize(QSize(100, 35));
        checkBox_HALL_A->setFont(font1);
        checkBox_HALL_A->setStyleSheet(QString::fromUtf8(" QCheckBox::indicator {\n"
"	\n"
"	color: rgb(255,255, 255);\n"
"image: url(:/image/053.png);\n"
"      width: 50px;\n"
"      height: 55px;\n"
"  }\n"
"QCheckBox::indicator:checked {\n"
"color: rgb(255, 255, 255);\n"
"image: url(:/image/051.png);\n"
"}\n"
"QCheckBox\n"
"{\n"
"   	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        checkBox_HALL_A->setIconSize(QSize(8, 8));
        checkBox_HALL_A->setAutoRepeatDelay(300);

        gridLayout->addWidget(checkBox_HALL_A, 1, 0, 1, 1);

        HALL_B = new QPushButton(gridLayoutWidget);
        HALL_B->setObjectName(QString::fromUtf8("HALL_B"));
        HALL_B->setMinimumSize(QSize(90, 45));
        HALL_B->setMaximumSize(QSize(90, 45));

        gridLayout->addWidget(HALL_B, 0, 1, 1, 1);

        checkBox_HALL_B = new QCheckBox(gridLayoutWidget);
        checkBox_HALL_B->setObjectName(QString::fromUtf8("checkBox_HALL_B"));
        checkBox_HALL_B->setEnabled(true);
        checkBox_HALL_B->setMaximumSize(QSize(88, 35));
        checkBox_HALL_B->setFont(font1);
        checkBox_HALL_B->setStyleSheet(QString::fromUtf8(" QCheckBox::indicator {\n"
"	color: rgb(255, 255, 255);\n"
"image: url(:/image/053.png);\n"
"      width: 50px;\n"
"      height: 55px;\n"
"  }\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/image/051.png)\n"
";}\n"
"QCheckBox\n"
"{\n"
"   	color: rgb(255, 255, 255);\n"
"}"));
        checkBox_HALL_B->setIconSize(QSize(8, 8));
        checkBox_HALL_B->setAutoRepeatDelay(300);

        gridLayout->addWidget(checkBox_HALL_B, 1, 1, 1, 1);

        HALL_C = new QPushButton(gridLayoutWidget);
        HALL_C->setObjectName(QString::fromUtf8("HALL_C"));
        HALL_C->setMinimumSize(QSize(90, 45));
        HALL_C->setMaximumSize(QSize(90, 45));

        gridLayout->addWidget(HALL_C, 0, 2, 1, 1);

        checkBox_HALL_E = new QCheckBox(gridLayoutWidget);
        checkBox_HALL_E->setObjectName(QString::fromUtf8("checkBox_HALL_E"));
        checkBox_HALL_E->setEnabled(true);
        checkBox_HALL_E->setMaximumSize(QSize(88, 35));
        checkBox_HALL_E->setFont(font1);
        checkBox_HALL_E->setStyleSheet(QString::fromUtf8(" QCheckBox::indicator {\n"
"	color: rgb(255, 255, 255);\n"
"image: url(:/image/053.png);\n"
"      width: 50px;\n"
"      height: 55px;\n"
"  }\n"
"QCheckBox::indicator:checked {\n"
"image: url(:/image/051.png)\n"
";}\n"
"QCheckBox\n"
"{\n"
"   	color: rgb(255, 255, 255);\n"
"}\n"
""));
        checkBox_HALL_E->setIconSize(QSize(8, 8));
        checkBox_HALL_E->setAutoRepeatDelay(300);

        gridLayout->addWidget(checkBox_HALL_E, 1, 4, 1, 1);

        HALL_E = new QPushButton(gridLayoutWidget);
        HALL_E->setObjectName(QString::fromUtf8("HALL_E"));
        HALL_E->setMinimumSize(QSize(90, 45));
        HALL_E->setMaximumSize(QSize(90, 45));

        gridLayout->addWidget(HALL_E, 0, 4, 1, 1);

        label_bldcpg_volt_2 = new QLabel(Widget_BLDC_PG);
        label_bldcpg_volt_2->setObjectName(QString::fromUtf8("label_bldcpg_volt_2"));
        label_bldcpg_volt_2->setEnabled(false);
        label_bldcpg_volt_2->setGeometry(QRect(110, 30, 81, 41));
        label_bldcpg_volt_2->setFont(font1);
        label_bldcpg_volt_2->setStyleSheet(QString::fromUtf8(""));
        label_bldcpg_volt_2->setAlignment(Qt::AlignCenter);
        bldcPG_wave = new QDoubleSpinBox(Widget_BLDC_PG);
        bldcPG_wave->setObjectName(QString::fromUtf8("bldcPG_wave"));
        bldcPG_wave->setEnabled(false);
        bldcPG_wave->setGeometry(QRect(190, 30, 60, 41));
        bldcPG_wave->setAlignment(Qt::AlignCenter);
        bldcPG_wave->setButtonSymbols(QAbstractSpinBox::NoButtons);
        bldcPG_wave->setDecimals(0);
        bldcPG_wave->setMinimum(0);
        bldcPG_wave->setMaximum(3000);
        bldcPG_wave->setSingleStep(0.1);
        bldcPG_wave->setValue(3);
        QWidget::setTabOrder(Com_DLR, bldcPG_volt);
        QWidget::setTabOrder(bldcPG_volt, bldcpg_count);
        QWidget::setTabOrder(bldcpg_count, bldcPG_wave);
        QWidget::setTabOrder(bldcPG_wave, HALL_A);
        QWidget::setTabOrder(HALL_A, checkBox_HALL_D);
        QWidget::setTabOrder(checkBox_HALL_D, checkBox_HALL_B);
        QWidget::setTabOrder(checkBox_HALL_B, checkBox_HALL_C);
        QWidget::setTabOrder(checkBox_HALL_C, HALL_E);
        QWidget::setTabOrder(HALL_E, HALL_B);
        QWidget::setTabOrder(HALL_B, checkBox_HALL_E);
        QWidget::setTabOrder(checkBox_HALL_E, HALL_D);
        QWidget::setTabOrder(HALL_D, HALL_C);
        QWidget::setTabOrder(HALL_C, checkBox_HALL_A);

        retranslateUi(Widget_BLDC_PG);

        QMetaObject::connectSlotsByName(Widget_BLDC_PG);
    } // setupUi

    void retranslateUi(QWidget *Widget_BLDC_PG)
    {
        Widget_BLDC_PG->setWindowTitle(QApplication::translate("Widget_BLDC_PG", "Form", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = bldcpgTab->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QApplication::translate("Widget_BLDC_PG", "\344\275\216\347\224\265\345\271\263", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = bldcpgTab->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget_BLDC_PG", "\351\253\230\347\224\265\345\271\263", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = bldcpgTab->horizontalHeaderItem(3);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget_BLDC_PG", "\351\242\221\347\216\207", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = bldcpgTab->horizontalHeaderItem(4);
        ___qtablewidgetitem3->setText(QApplication::translate("Widget_BLDC_PG", "\345\215\240\347\251\272\346\257\224", 0, QApplication::UnicodeUTF8));
        label_bldcpg_volt->setText(QApplication::translate("Widget_BLDC_PG", "\347\224\265\345\216\213\357\274\210\357\274\266\357\274\211\357\274\232", 0, QApplication::UnicodeUTF8));
        label_bldcpg_conut->setText(QApplication::translate("Widget_BLDC_PG", "\346\236\201\346\225\260\357\274\232", 0, QApplication::UnicodeUTF8));
        label_bldcpg_time->setText(QApplication::translate("Widget_BLDC_PG", "\351\241\271\347\233\256\357\274\232", 0, QApplication::UnicodeUTF8));
        Com_DLR->clear();
        Com_DLR->insertItems(0, QStringList()
         << QApplication::translate("Widget_BLDC_PG", "\347\251\272\350\275\275", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_BLDC_PG", "\350\264\237\350\275\275", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_BLDC_PG", "BEMF", 0, QApplication::UnicodeUTF8)
        );
        checkBox_HALL_C->setText(QApplication::translate("Widget_BLDC_PG", "C", 0, QApplication::UnicodeUTF8));
        HALL_D->setText(QApplication::translate("Widget_BLDC_PG", "HALL-D", 0, QApplication::UnicodeUTF8));
        checkBox_HALL_D->setText(QApplication::translate("Widget_BLDC_PG", "D", 0, QApplication::UnicodeUTF8));
        HALL_A->setText(QApplication::translate("Widget_BLDC_PG", "HALL-A", 0, QApplication::UnicodeUTF8));
        checkBox_HALL_A->setText(QApplication::translate("Widget_BLDC_PG", "A", 0, QApplication::UnicodeUTF8));
        HALL_B->setText(QApplication::translate("Widget_BLDC_PG", "HALL-B", 0, QApplication::UnicodeUTF8));
        checkBox_HALL_B->setText(QApplication::translate("Widget_BLDC_PG", "B", 0, QApplication::UnicodeUTF8));
        HALL_C->setText(QApplication::translate("Widget_BLDC_PG", "HALL-C", 0, QApplication::UnicodeUTF8));
        checkBox_HALL_E->setText(QApplication::translate("Widget_BLDC_PG", "E", 0, QApplication::UnicodeUTF8));
        HALL_E->setText(QApplication::translate("Widget_BLDC_PG", "HALL-E", 0, QApplication::UnicodeUTF8));
        label_bldcpg_volt_2->setText(QApplication::translate("Widget_BLDC_PG", "\345\217\202\350\200\203\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget_BLDC_PG: public Ui_Widget_BLDC_PG {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_BLDC_PG_H
