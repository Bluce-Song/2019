/********************************************************************************
** Form generated from reading UI file 'widget_bemf.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_BEMF_H
#define UI_WIDGET_BEMF_H

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

class Ui_Widget_BEMF
{
public:
    QLabel *label;
    QDoubleSpinBox *bemf_unbal;
    QTableWidget *bemfTab;
    QLabel *label_bemf_unbal;
    QDoubleSpinBox *bemf_speed;
    QLabel *label_bemf_speed;
    QDoubleSpinBox *bemf_turn;
    QLabel *label_bemf_turn;
    QDoubleSpinBox *bemf_hall;
    QLabel *label_bemf_hall;
    QLabel *label_bemf_unbal_2;
    QDoubleSpinBox *bemf_time;
    QLabel *label_bemf_unbal_3;
    QDoubleSpinBox *bemf_drive;
    QLabel *label_bemf_unbal_4;
    QDoubleSpinBox *bemf_volt;
    QDoubleSpinBox *bemf_volt_2;

    void setupUi(QWidget *Widget_BEMF)
    {
        if (Widget_BEMF->objectName().isEmpty())
            Widget_BEMF->setObjectName(QString::fromUtf8("Widget_BEMF"));
        Widget_BEMF->resize(721, 600);
        label = new QLabel(Widget_BEMF);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 0, 401, 91));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        bemf_unbal = new QDoubleSpinBox(Widget_BEMF);
        bemf_unbal->setObjectName(QString::fromUtf8("bemf_unbal"));
        bemf_unbal->setGeometry(QRect(250, 320, 60, 41));
        bemf_unbal->setAlignment(Qt::AlignCenter);
        bemf_unbal->setButtonSymbols(QAbstractSpinBox::NoButtons);
        bemf_unbal->setDecimals(0);
        bemf_unbal->setMinimum(1);
        bemf_unbal->setMaximum(999);
        bemf_unbal->setSingleStep(1);
        bemf_unbal->setValue(1);
        bemfTab = new QTableWidget(Widget_BEMF);
        if (bemfTab->columnCount() < 5)
            bemfTab->setColumnCount(5);
        QFont font1;
        font1.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem->setFont(font1);
        bemfTab->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem1->setFont(font1);
        bemfTab->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem2->setFont(font1);
        bemfTab->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem3->setFont(font1);
        bemfTab->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem4->setFont(font1);
        bemfTab->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        bemfTab->setObjectName(QString::fromUtf8("bemfTab"));
        bemfTab->setGeometry(QRect(140, 180, 527, 107));
        bemfTab->setFocusPolicy(Qt::NoFocus);
        bemfTab->setInputMethodHints(Qt::ImhNone);
        bemfTab->setEditTriggers(QAbstractItemView::AllEditTriggers);
        bemfTab->setAlternatingRowColors(false);
        bemfTab->setSelectionMode(QAbstractItemView::SingleSelection);
        bemfTab->horizontalHeader()->setDefaultSectionSize(50);
        bemfTab->horizontalHeader()->setStretchLastSection(true);
        bemfTab->verticalHeader()->setVisible(false);
        bemfTab->verticalHeader()->setDefaultSectionSize(40);
        label_bemf_unbal = new QLabel(Widget_BEMF);
        label_bemf_unbal->setObjectName(QString::fromUtf8("label_bemf_unbal"));
        label_bemf_unbal->setGeometry(QRect(150, 320, 101, 41));
        label_bemf_unbal->setFont(font1);
        label_bemf_unbal->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_bemf_unbal->setAlignment(Qt::AlignCenter);
        bemf_speed = new QDoubleSpinBox(Widget_BEMF);
        bemf_speed->setObjectName(QString::fromUtf8("bemf_speed"));
        bemf_speed->setGeometry(QRect(600, 330, 60, 41));
        bemf_speed->setAlignment(Qt::AlignCenter);
        bemf_speed->setButtonSymbols(QAbstractSpinBox::NoButtons);
        bemf_speed->setDecimals(0);
        bemf_speed->setMinimum(1);
        bemf_speed->setMaximum(999);
        bemf_speed->setSingleStep(1);
        bemf_speed->setValue(1);
        label_bemf_speed = new QLabel(Widget_BEMF);
        label_bemf_speed->setObjectName(QString::fromUtf8("label_bemf_speed"));
        label_bemf_speed->setGeometry(QRect(480, 330, 121, 41));
        label_bemf_speed->setFont(font1);
        label_bemf_speed->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_bemf_speed->setAlignment(Qt::AlignCenter);
        bemf_turn = new QDoubleSpinBox(Widget_BEMF);
        bemf_turn->setObjectName(QString::fromUtf8("bemf_turn"));
        bemf_turn->setGeometry(QRect(600, 380, 60, 41));
        bemf_turn->setAlignment(Qt::AlignCenter);
        bemf_turn->setButtonSymbols(QAbstractSpinBox::NoButtons);
        bemf_turn->setDecimals(0);
        bemf_turn->setMinimum(1);
        bemf_turn->setMaximum(999);
        bemf_turn->setSingleStep(1);
        bemf_turn->setValue(1);
        label_bemf_turn = new QLabel(Widget_BEMF);
        label_bemf_turn->setObjectName(QString::fromUtf8("label_bemf_turn"));
        label_bemf_turn->setGeometry(QRect(480, 380, 121, 41));
        label_bemf_turn->setFont(font1);
        label_bemf_turn->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_bemf_turn->setAlignment(Qt::AlignCenter);
        bemf_hall = new QDoubleSpinBox(Widget_BEMF);
        bemf_hall->setObjectName(QString::fromUtf8("bemf_hall"));
        bemf_hall->setGeometry(QRect(600, 430, 60, 41));
        bemf_hall->setAlignment(Qt::AlignCenter);
        bemf_hall->setButtonSymbols(QAbstractSpinBox::NoButtons);
        bemf_hall->setDecimals(0);
        bemf_hall->setMinimum(1);
        bemf_hall->setMaximum(999);
        bemf_hall->setSingleStep(1);
        bemf_hall->setValue(1);
        label_bemf_hall = new QLabel(Widget_BEMF);
        label_bemf_hall->setObjectName(QString::fromUtf8("label_bemf_hall"));
        label_bemf_hall->setGeometry(QRect(480, 430, 121, 41));
        label_bemf_hall->setFont(font1);
        label_bemf_hall->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_bemf_hall->setAlignment(Qt::AlignCenter);
        label_bemf_unbal_2 = new QLabel(Widget_BEMF);
        label_bemf_unbal_2->setObjectName(QString::fromUtf8("label_bemf_unbal_2"));
        label_bemf_unbal_2->setGeometry(QRect(150, 370, 101, 41));
        label_bemf_unbal_2->setFont(font1);
        label_bemf_unbal_2->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_bemf_unbal_2->setAlignment(Qt::AlignCenter);
        bemf_time = new QDoubleSpinBox(Widget_BEMF);
        bemf_time->setObjectName(QString::fromUtf8("bemf_time"));
        bemf_time->setGeometry(QRect(250, 370, 60, 41));
        bemf_time->setAlignment(Qt::AlignCenter);
        bemf_time->setButtonSymbols(QAbstractSpinBox::NoButtons);
        bemf_time->setDecimals(0);
        bemf_time->setMinimum(0);
        bemf_time->setMaximum(100000);
        bemf_time->setSingleStep(1);
        bemf_time->setValue(1);
        label_bemf_unbal_3 = new QLabel(Widget_BEMF);
        label_bemf_unbal_3->setObjectName(QString::fromUtf8("label_bemf_unbal_3"));
        label_bemf_unbal_3->setGeometry(QRect(150, 420, 101, 41));
        label_bemf_unbal_3->setFont(font1);
        label_bemf_unbal_3->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_bemf_unbal_3->setAlignment(Qt::AlignCenter);
        bemf_drive = new QDoubleSpinBox(Widget_BEMF);
        bemf_drive->setObjectName(QString::fromUtf8("bemf_drive"));
        bemf_drive->setGeometry(QRect(250, 420, 60, 41));
        bemf_drive->setAlignment(Qt::AlignCenter);
        bemf_drive->setButtonSymbols(QAbstractSpinBox::NoButtons);
        bemf_drive->setDecimals(0);
        bemf_drive->setMinimum(0);
        bemf_drive->setMaximum(100000);
        bemf_drive->setSingleStep(1);
        bemf_drive->setValue(1);
        label_bemf_unbal_4 = new QLabel(Widget_BEMF);
        label_bemf_unbal_4->setObjectName(QString::fromUtf8("label_bemf_unbal_4"));
        label_bemf_unbal_4->setGeometry(QRect(140, 470, 101, 41));
        label_bemf_unbal_4->setFont(font1);
        label_bemf_unbal_4->setStyleSheet(QString::fromUtf8("border: 0px solid white;"));
        label_bemf_unbal_4->setAlignment(Qt::AlignCenter);
        bemf_volt = new QDoubleSpinBox(Widget_BEMF);
        bemf_volt->setObjectName(QString::fromUtf8("bemf_volt"));
        bemf_volt->setGeometry(QRect(250, 470, 60, 41));
        bemf_volt->setAlignment(Qt::AlignCenter);
        bemf_volt->setButtonSymbols(QAbstractSpinBox::NoButtons);
        bemf_volt->setDecimals(2);
        bemf_volt->setMinimum(0);
        bemf_volt->setMaximum(100000);
        bemf_volt->setSingleStep(1);
        bemf_volt->setValue(1);
        bemf_volt_2 = new QDoubleSpinBox(Widget_BEMF);
        bemf_volt_2->setObjectName(QString::fromUtf8("bemf_volt_2"));
        bemf_volt_2->setGeometry(QRect(250, 530, 60, 41));
        bemf_volt_2->setAlignment(Qt::AlignCenter);
        bemf_volt_2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        bemf_volt_2->setDecimals(0);
        bemf_volt_2->setMinimum(0);
        bemf_volt_2->setMaximum(100000);
        bemf_volt_2->setSingleStep(1);
        bemf_volt_2->setValue(1);

        retranslateUi(Widget_BEMF);

        QMetaObject::connectSlotsByName(Widget_BEMF);
    } // setupUi

    void retranslateUi(QWidget *Widget_BEMF)
    {
        Widget_BEMF->setWindowTitle(QApplication::translate("Widget_BEMF", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget_BEMF", "\345\217\215\347\224\265\345\212\250\345\212\277", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = bemfTab->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QApplication::translate("Widget_BEMF", "\347\224\265\345\216\213", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = bemfTab->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget_BEMF", "\345\217\215\347\224\265\345\212\250\345\212\277", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = bemfTab->horizontalHeaderItem(3);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget_BEMF", "\347\233\270\344\275\215\345\267\256", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = bemfTab->horizontalHeaderItem(4);
        ___qtablewidgetitem3->setText(QApplication::translate("Widget_BEMF", "\347\233\270\344\275\215\345\267\2562", 0, QApplication::UnicodeUTF8));
        label_bemf_unbal->setText(QApplication::translate("Widget_BEMF", "\344\270\215\345\271\263\350\241\241\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        label_bemf_speed->setText(QApplication::translate("Widget_BEMF", "\344\274\272\346\234\215\350\275\254\351\200\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_bemf_turn->setText(QApplication::translate("Widget_BEMF", "\344\274\272\346\234\215\350\275\254\345\220\221\357\274\232", 0, QApplication::UnicodeUTF8));
        label_bemf_hall->setText(QApplication::translate("Widget_BEMF", "\344\270\216\351\234\215\345\260\224\347\233\270\344\275\215\345\267\256\357\274\232", 0, QApplication::UnicodeUTF8));
        label_bemf_unbal_2->setText(QApplication::translate("Widget_BEMF", "\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        label_bemf_unbal_3->setText(QApplication::translate("Widget_BEMF", "\345\206\205\345\244\226\357\274\232", 0, QApplication::UnicodeUTF8));
        label_bemf_unbal_4->setText(QApplication::translate("Widget_BEMF", " \347\224\265\345\216\213\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget_BEMF: public Ui_Widget_BEMF {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_BEMF_H
