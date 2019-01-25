/********************************************************************************
** Form generated from reading UI file 'widget_load.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_LOAD_H
#define UI_WIDGET_LOAD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_Load
{
public:
    QLabel *label;
    QLabel *label_load_volt;
    QLabel *label_load_vsp;
    QTableWidget *load_time_series;
    QLabel *label_load_vcc;
    QDoubleSpinBox *load_vcc;
    QTableWidget *loadTab;
    QDoubleSpinBox *load_vsp;
    QLabel *label_load_time;
    QDoubleSpinBox *load_volt;
    QDoubleSpinBox *load_time;
    QDoubleSpinBox *load_nm;
    QLabel *label_load_nm;
    QLabel *label_load_volt_2;
    QDoubleSpinBox *load_power;
    QLabel *label_load_volt_3;
    QDoubleSpinBox *load_drive;
    QLabel *label_noload_drive_2;
    QDoubleSpinBox *load_pwmvsp;

    void setupUi(QWidget *Widget_Load)
    {
        if (Widget_Load->objectName().isEmpty())
            Widget_Load->setObjectName(QString::fromUtf8("Widget_Load"));
        Widget_Load->resize(721, 600);
        QFont font;
        font.setPointSize(16);
        Widget_Load->setFont(font);
        label = new QLabel(Widget_Load);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 0, 431, 111));
        label->setAlignment(Qt::AlignCenter);
        label_load_volt = new QLabel(Widget_Load);
        label_load_volt->setObjectName(QString::fromUtf8("label_load_volt"));
        label_load_volt->setGeometry(QRect(120, 250, 71, 41));
        QFont font1;
        font1.setPointSize(9);
        label_load_volt->setFont(font1);
        label_load_volt->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_load_volt->setAlignment(Qt::AlignCenter);
        label_load_vsp = new QLabel(Widget_Load);
        label_load_vsp->setObjectName(QString::fromUtf8("label_load_vsp"));
        label_load_vsp->setGeometry(QRect(460, 300, 111, 41));
        label_load_vsp->setFont(font1);
        label_load_vsp->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_load_vsp->setAlignment(Qt::AlignCenter);
        load_time_series = new QTableWidget(Widget_Load);
        if (load_time_series->columnCount() < 14)
            load_time_series->setColumnCount(14);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem->setFont(font1);
        load_time_series->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem1->setFont(font1);
        load_time_series->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem2->setFont(font1);
        load_time_series->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem3->setFont(font1);
        load_time_series->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem4->setFont(font1);
        load_time_series->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem5->setFont(font1);
        load_time_series->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem6->setFont(font1);
        load_time_series->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem7->setFont(font1);
        load_time_series->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem8->setFont(font1);
        load_time_series->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem9->setFont(font1);
        load_time_series->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem10->setFont(font1);
        load_time_series->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem11->setFont(font1);
        load_time_series->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem12->setFont(font1);
        load_time_series->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem13->setFont(font1);
        load_time_series->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        load_time_series->setObjectName(QString::fromUtf8("load_time_series"));
        load_time_series->setGeometry(QRect(10, 460, 701, 91));
        load_time_series->setFocusPolicy(Qt::NoFocus);
        load_time_series->setInputMethodHints(Qt::ImhNone);
        load_time_series->setEditTriggers(QAbstractItemView::AllEditTriggers);
        load_time_series->setAlternatingRowColors(false);
        load_time_series->setSelectionMode(QAbstractItemView::SingleSelection);
        load_time_series->horizontalHeader()->setDefaultSectionSize(50);
        load_time_series->horizontalHeader()->setStretchLastSection(true);
        load_time_series->verticalHeader()->setVisible(false);
        load_time_series->verticalHeader()->setDefaultSectionSize(40);
        label_load_vcc = new QLabel(Widget_Load);
        label_load_vcc->setObjectName(QString::fromUtf8("label_load_vcc"));
        label_load_vcc->setGeometry(QRect(460, 250, 111, 41));
        label_load_vcc->setFont(font1);
        label_load_vcc->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_load_vcc->setAlignment(Qt::AlignCenter);
        load_vcc = new QDoubleSpinBox(Widget_Load);
        load_vcc->setObjectName(QString::fromUtf8("load_vcc"));
        load_vcc->setGeometry(QRect(570, 250, 60, 41));
        load_vcc->setAlignment(Qt::AlignCenter);
        load_vcc->setButtonSymbols(QAbstractSpinBox::NoButtons);
        load_vcc->setDecimals(2);
        load_vcc->setMinimum(0);
        load_vcc->setMaximum(999);
        load_vcc->setSingleStep(1);
        load_vcc->setValue(1);
        loadTab = new QTableWidget(Widget_Load);
        if (loadTab->columnCount() < 4)
            loadTab->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem14->setFont(font1);
        loadTab->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem15->setFont(font1);
        loadTab->setHorizontalHeaderItem(1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem16->setFont(font1);
        loadTab->setHorizontalHeaderItem(2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem17->setFont(font1);
        loadTab->setHorizontalHeaderItem(3, __qtablewidgetitem17);
        loadTab->setObjectName(QString::fromUtf8("loadTab"));
        loadTab->setGeometry(QRect(110, 110, 527, 121));
        loadTab->setFocusPolicy(Qt::NoFocus);
        loadTab->setInputMethodHints(Qt::ImhNone);
        loadTab->setEditTriggers(QAbstractItemView::AllEditTriggers);
        loadTab->setAlternatingRowColors(false);
        loadTab->setSelectionMode(QAbstractItemView::SingleSelection);
        loadTab->horizontalHeader()->setDefaultSectionSize(50);
        loadTab->horizontalHeader()->setStretchLastSection(true);
        loadTab->verticalHeader()->setVisible(false);
        loadTab->verticalHeader()->setDefaultSectionSize(40);
        load_vsp = new QDoubleSpinBox(Widget_Load);
        load_vsp->setObjectName(QString::fromUtf8("load_vsp"));
        load_vsp->setGeometry(QRect(570, 300, 60, 41));
        load_vsp->setAlignment(Qt::AlignCenter);
        load_vsp->setButtonSymbols(QAbstractSpinBox::NoButtons);
        load_vsp->setDecimals(2);
        load_vsp->setMinimum(0);
        load_vsp->setMaximum(999);
        load_vsp->setSingleStep(1);
        load_vsp->setValue(1);
        label_load_time = new QLabel(Widget_Load);
        label_load_time->setObjectName(QString::fromUtf8("label_load_time"));
        label_load_time->setGeometry(QRect(460, 350, 111, 41));
        label_load_time->setFont(font1);
        label_load_time->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_load_time->setAlignment(Qt::AlignCenter);
        load_volt = new QDoubleSpinBox(Widget_Load);
        load_volt->setObjectName(QString::fromUtf8("load_volt"));
        load_volt->setGeometry(QRect(190, 250, 60, 41));
        load_volt->setAlignment(Qt::AlignCenter);
        load_volt->setButtonSymbols(QAbstractSpinBox::NoButtons);
        load_volt->setDecimals(2);
        load_volt->setMinimum(0);
        load_volt->setMaximum(999);
        load_volt->setSingleStep(1);
        load_volt->setValue(1);
        load_time = new QDoubleSpinBox(Widget_Load);
        load_time->setObjectName(QString::fromUtf8("load_time"));
        load_time->setGeometry(QRect(570, 350, 60, 41));
        load_time->setAlignment(Qt::AlignCenter);
        load_time->setButtonSymbols(QAbstractSpinBox::NoButtons);
        load_time->setDecimals(1);
        load_time->setMinimum(0);
        load_time->setMaximum(999);
        load_time->setSingleStep(1);
        load_time->setValue(1);
        load_nm = new QDoubleSpinBox(Widget_Load);
        load_nm->setObjectName(QString::fromUtf8("load_nm"));
        load_nm->setGeometry(QRect(370, 250, 60, 41));
        load_nm->setAlignment(Qt::AlignCenter);
        load_nm->setButtonSymbols(QAbstractSpinBox::NoButtons);
        load_nm->setDecimals(2);
        load_nm->setMinimum(0);
        load_nm->setMaximum(999);
        load_nm->setSingleStep(1);
        load_nm->setValue(1);
        label_load_nm = new QLabel(Widget_Load);
        label_load_nm->setObjectName(QString::fromUtf8("label_load_nm"));
        label_load_nm->setGeometry(QRect(300, 250, 71, 41));
        label_load_nm->setFont(font1);
        label_load_nm->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_load_nm->setAlignment(Qt::AlignCenter);
        label_load_volt_2 = new QLabel(Widget_Load);
        label_load_volt_2->setObjectName(QString::fromUtf8("label_load_volt_2"));
        label_load_volt_2->setGeometry(QRect(120, 300, 71, 41));
        label_load_volt_2->setFont(font1);
        label_load_volt_2->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_load_volt_2->setAlignment(Qt::AlignCenter);
        load_power = new QDoubleSpinBox(Widget_Load);
        load_power->setObjectName(QString::fromUtf8("load_power"));
        load_power->setGeometry(QRect(190, 300, 60, 41));
        load_power->setAlignment(Qt::AlignCenter);
        load_power->setButtonSymbols(QAbstractSpinBox::NoButtons);
        load_power->setDecimals(0);
        load_power->setMinimum(0);
        load_power->setMaximum(999);
        load_power->setSingleStep(1);
        load_power->setValue(1);
        label_load_volt_3 = new QLabel(Widget_Load);
        label_load_volt_3->setObjectName(QString::fromUtf8("label_load_volt_3"));
        label_load_volt_3->setGeometry(QRect(120, 350, 71, 41));
        label_load_volt_3->setFont(font1);
        label_load_volt_3->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_load_volt_3->setAlignment(Qt::AlignCenter);
        load_drive = new QDoubleSpinBox(Widget_Load);
        load_drive->setObjectName(QString::fromUtf8("load_drive"));
        load_drive->setGeometry(QRect(190, 350, 60, 41));
        load_drive->setAlignment(Qt::AlignCenter);
        load_drive->setButtonSymbols(QAbstractSpinBox::NoButtons);
        load_drive->setDecimals(0);
        load_drive->setMinimum(0);
        load_drive->setMaximum(999);
        load_drive->setSingleStep(1);
        load_drive->setValue(1);
        label_noload_drive_2 = new QLabel(Widget_Load);
        label_noload_drive_2->setObjectName(QString::fromUtf8("label_noload_drive_2"));
        label_noload_drive_2->setGeometry(QRect(290, 350, 71, 41));
        label_noload_drive_2->setFont(font1);
        label_noload_drive_2->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_noload_drive_2->setAlignment(Qt::AlignCenter);
        load_pwmvsp = new QDoubleSpinBox(Widget_Load);
        load_pwmvsp->setObjectName(QString::fromUtf8("load_pwmvsp"));
        load_pwmvsp->setGeometry(QRect(360, 350, 60, 41));
        load_pwmvsp->setAlignment(Qt::AlignCenter);
        load_pwmvsp->setButtonSymbols(QAbstractSpinBox::NoButtons);
        load_pwmvsp->setDecimals(0);
        load_pwmvsp->setMinimum(0);
        load_pwmvsp->setMaximum(999);
        load_pwmvsp->setSingleStep(1);
        load_pwmvsp->setValue(1);

        retranslateUi(Widget_Load);

        QMetaObject::connectSlotsByName(Widget_Load);
    } // setupUi

    void retranslateUi(QWidget *Widget_Load)
    {
        Widget_Load->setWindowTitle(QApplication::translate("Widget_Load", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget_Load", "\350\264\237\350\275\275", 0, QApplication::UnicodeUTF8));
        label_load_volt->setText(QApplication::translate("Widget_Load", "\347\224\265\345\216\213\357\274\232", 0, QApplication::UnicodeUTF8));
        label_load_vsp->setText(QApplication::translate("Widget_Load", "Vsp\347\224\265\345\216\213\357\274\232", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = load_time_series->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QApplication::translate("Widget_Load", "T0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = load_time_series->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget_Load", "T1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = load_time_series->horizontalHeaderItem(3);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget_Load", "T2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = load_time_series->horizontalHeaderItem(4);
        ___qtablewidgetitem3->setText(QApplication::translate("Widget_Load", "T3", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = load_time_series->horizontalHeaderItem(5);
        ___qtablewidgetitem4->setText(QApplication::translate("Widget_Load", "T4", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = load_time_series->horizontalHeaderItem(6);
        ___qtablewidgetitem5->setText(QApplication::translate("Widget_Load", "T5", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = load_time_series->horizontalHeaderItem(7);
        ___qtablewidgetitem6->setText(QApplication::translate("Widget_Load", "T6", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = load_time_series->horizontalHeaderItem(8);
        ___qtablewidgetitem7->setText(QApplication::translate("Widget_Load", "T7", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = load_time_series->horizontalHeaderItem(9);
        ___qtablewidgetitem8->setText(QApplication::translate("Widget_Load", "T8", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = load_time_series->horizontalHeaderItem(10);
        ___qtablewidgetitem9->setText(QApplication::translate("Widget_Load", "T9", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = load_time_series->horizontalHeaderItem(11);
        ___qtablewidgetitem10->setText(QApplication::translate("Widget_Load", "T10", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = load_time_series->horizontalHeaderItem(12);
        ___qtablewidgetitem11->setText(QApplication::translate("Widget_Load", "T11", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = load_time_series->horizontalHeaderItem(13);
        ___qtablewidgetitem12->setText(QApplication::translate("Widget_Load", "T13", 0, QApplication::UnicodeUTF8));
        label_load_vcc->setText(QApplication::translate("Widget_Load", "Vcc\347\224\265\345\216\213\357\274\232", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = loadTab->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QApplication::translate("Widget_Load", "\347\224\265\346\265\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = loadTab->horizontalHeaderItem(2);
        ___qtablewidgetitem14->setText(QApplication::translate("Widget_Load", "\345\212\237\347\216\207", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = loadTab->horizontalHeaderItem(3);
        ___qtablewidgetitem15->setText(QApplication::translate("Widget_Load", "\350\275\254\351\200\237", 0, QApplication::UnicodeUTF8));
        label_load_time->setText(QApplication::translate("Widget_Load", "\346\265\213\350\257\225\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        label_load_nm->setText(QApplication::translate("Widget_Load", "\346\211\255\347\237\251\357\274\232", 0, QApplication::UnicodeUTF8));
        label_load_volt_2->setText(QApplication::translate("Widget_Load", "\347\224\265\346\272\220\357\274\232", 0, QApplication::UnicodeUTF8));
        label_load_volt_3->setText(QApplication::translate("Widget_Load", "\345\206\205\345\244\226\357\274\232", 0, QApplication::UnicodeUTF8));
        label_noload_drive_2->setText(QApplication::translate("Widget_Load", "pwm vsp\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget_Load: public Ui_Widget_Load {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_LOAD_H
