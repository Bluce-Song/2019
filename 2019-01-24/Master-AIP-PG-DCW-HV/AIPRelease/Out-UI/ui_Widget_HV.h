/********************************************************************************
** Form generated from reading UI file 'Widget_HV.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_HV_H
#define UI_WIDGET_HV_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_HV
{
public:
    QWidget *widget;
    QLabel *label_HV_I_Down;
    QDoubleSpinBox *double_Volt;
    QDoubleSpinBox *double_Time;
    QDoubleSpinBox *double_I_Up;
    QLabel *label_HV_Volt;
    QLabel *label_HV_Time;
    QDoubleSpinBox *double_I_Down;
    QLabel *label_HV_I_Up;
    QLabel *label_HV_Freq;
    QLabel *label_HV_ARC;
    QComboBox *comb_ARC;
    QComboBox *comb_Freq;

    void setupUi(QWidget *Widget_HV)
    {
        if (Widget_HV->objectName().isEmpty())
            Widget_HV->setObjectName(QString::fromUtf8("Widget_HV"));
        Widget_HV->resize(721, 600);
        Widget_HV->setContextMenuPolicy(Qt::DefaultContextMenu);
        widget = new QWidget(Widget_HV);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(230, 320, 491, 281));
        label_HV_I_Down = new QLabel(widget);
        label_HV_I_Down->setObjectName(QString::fromUtf8("label_HV_I_Down"));
        label_HV_I_Down->setGeometry(QRect(230, 20, 121, 51));
        label_HV_I_Down->setStyleSheet(QString::fromUtf8(""));
        label_HV_I_Down->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
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
        label_HV_Volt = new QLabel(widget);
        label_HV_Volt->setObjectName(QString::fromUtf8("label_HV_Volt"));
        label_HV_Volt->setGeometry(QRect(30, 20, 71, 51));
        label_HV_Volt->setStyleSheet(QString::fromUtf8(""));
        label_HV_Volt->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_HV_Time = new QLabel(widget);
        label_HV_Time->setObjectName(QString::fromUtf8("label_HV_Time"));
        label_HV_Time->setGeometry(QRect(30, 90, 71, 51));
        label_HV_Time->setStyleSheet(QString::fromUtf8(""));
        label_HV_Time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        double_I_Down = new QDoubleSpinBox(widget);
        double_I_Down->setObjectName(QString::fromUtf8("double_I_Down"));
        double_I_Down->setGeometry(QRect(360, 20, 101, 51));
        double_I_Down->setStyleSheet(QString::fromUtf8(""));
        double_I_Down->setAlignment(Qt::AlignCenter);
        double_I_Down->setButtonSymbols(QAbstractSpinBox::NoButtons);
        label_HV_I_Up = new QLabel(widget);
        label_HV_I_Up->setObjectName(QString::fromUtf8("label_HV_I_Up"));
        label_HV_I_Up->setGeometry(QRect(230, 90, 121, 51));
        label_HV_I_Up->setStyleSheet(QString::fromUtf8(""));
        label_HV_I_Up->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_HV_Freq = new QLabel(widget);
        label_HV_Freq->setObjectName(QString::fromUtf8("label_HV_Freq"));
        label_HV_Freq->setGeometry(QRect(230, 160, 121, 51));
        label_HV_Freq->setStyleSheet(QString::fromUtf8(""));
        label_HV_Freq->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_HV_ARC = new QLabel(widget);
        label_HV_ARC->setObjectName(QString::fromUtf8("label_HV_ARC"));
        label_HV_ARC->setGeometry(QRect(30, 160, 71, 51));
        label_HV_ARC->setStyleSheet(QString::fromUtf8(""));
        label_HV_ARC->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
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
        comb_Freq = new QComboBox(widget);
        comb_Freq->setObjectName(QString::fromUtf8("comb_Freq"));
        comb_Freq->setGeometry(QRect(360, 160, 101, 50));
        comb_Freq->setMaximumSize(QSize(120, 50));
        comb_Freq->setFont(font);
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
        QWidget::setTabOrder(comb_ARC, comb_Freq);
        QWidget::setTabOrder(comb_Freq, double_Time);
        QWidget::setTabOrder(double_Time, double_I_Up);
        QWidget::setTabOrder(double_I_Up, double_I_Down);
        QWidget::setTabOrder(double_I_Down, double_Volt);

        retranslateUi(Widget_HV);

        QMetaObject::connectSlotsByName(Widget_HV);
    } // setupUi

    void retranslateUi(QWidget *Widget_HV)
    {
        Widget_HV->setWindowTitle(QApplication::translate("Widget_HV", "Form", 0, QApplication::UnicodeUTF8));
        label_HV_I_Down->setText(QApplication::translate("Widget_HV", "\347\224\265\346\265\201\344\270\213\351\231\220(mA)", 0, QApplication::UnicodeUTF8));
        label_HV_Volt->setText(QApplication::translate("Widget_HV", "\347\224\265\345\216\213(V)", 0, QApplication::UnicodeUTF8));
        label_HV_Time->setText(QApplication::translate("Widget_HV", "\346\227\266\351\227\264(s)", 0, QApplication::UnicodeUTF8));
        label_HV_I_Up->setText(QApplication::translate("Widget_HV", "\347\224\265\346\265\201\344\270\212\351\231\220(mA)", 0, QApplication::UnicodeUTF8));
        label_HV_Freq->setText(QApplication::translate("Widget_HV", "\351\242\221\347\216\207(Hz)", 0, QApplication::UnicodeUTF8));
        label_HV_ARC->setText(QApplication::translate("Widget_HV", "ARC", 0, QApplication::UnicodeUTF8));
        comb_ARC->clear();
        comb_ARC->insertItems(0, QStringList()
         << QApplication::translate("Widget_HV", "0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_HV", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_HV", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_HV", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_HV", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_HV", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_HV", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_HV", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_HV", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_HV", "9", 0, QApplication::UnicodeUTF8)
        );
        comb_Freq->clear();
        comb_Freq->insertItems(0, QStringList()
         << QApplication::translate("Widget_HV", "50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_HV", "60", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class Widget_HV: public Ui_Widget_HV {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_HV_H
