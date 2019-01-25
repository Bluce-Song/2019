/********************************************************************************
** Form generated from reading UI file 'WinData.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDATA_H
#define UI_WINDATA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QTableView>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>
#include "Histogram.h"

QT_BEGIN_NAMESPACE

class Ui_WinData
{
public:
    QStackedWidget *WidgetShow;
    QWidget *WidgetTestData;
    QTableView *TabTestData;
    QWidget *WidgetDetail;
    QTableWidget *TabDetail;
    QGroupBox *WinDetail;
    Histogram *TextHistogram;
    QWidget *WidgetCtrl;
    QLabel *label_2;
    QLineEdit *EditType;
    QDateEdit *DateEdit1;
    QLabel *label;
    QDateEdit *DateEdit2;
    QPushButton *BtnShow;
    QPushButton *BtnCheck;
    QPushButton *BtnClear;
    QPushButton *BtnExit;

    void setupUi(QWidget *WinData)
    {
        if (WinData->objectName().isEmpty())
            WinData->setObjectName(QString::fromUtf8("WinData"));
        WinData->setWindowModality(Qt::NonModal);
        WinData->setEnabled(true);
        WinData->resize(800, 600);
        WinData->setMaximumSize(QSize(814, 16777215));
        WidgetShow = new QStackedWidget(WinData);
        WidgetShow->setObjectName(QString::fromUtf8("WidgetShow"));
        WidgetShow->setGeometry(QRect(9, 9, 781, 531));
        WidgetTestData = new QWidget();
        WidgetTestData->setObjectName(QString::fromUtf8("WidgetTestData"));
        TabTestData = new QTableView(WidgetTestData);
        TabTestData->setObjectName(QString::fromUtf8("TabTestData"));
        TabTestData->setGeometry(QRect(9, 9, 764, 514));
        TabTestData->verticalHeader()->setVisible(false);
        WidgetShow->addWidget(WidgetTestData);
        WidgetDetail = new QWidget();
        WidgetDetail->setObjectName(QString::fromUtf8("WidgetDetail"));
        TabDetail = new QTableWidget(WidgetDetail);
        if (TabDetail->columnCount() < 5)
            TabDetail->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TabDetail->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        TabDetail->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        TabDetail->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        TabDetail->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        TabDetail->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        TabDetail->setObjectName(QString::fromUtf8("TabDetail"));
        TabDetail->setGeometry(QRect(9, 9, 764, 192));
        TabDetail->setStyleSheet(QString::fromUtf8("QScrollBar:vertical {\n"
"    border: 1px solid #32435E;\n"
"    border-width: 0px 0px 0px 1px;\n"
"    background: #21252F;\n"
"    width: 12px;\n"
"    margin: 12px 0 12px 0;\n"
"}\n"
"QTableWidget\n"
"{\n"
"    background-color:#191919;\n"
"    color:white;\n"
"    border:none;\n"
"\n"
"    gridline-color:#447684;\n"
"    border-style: groove;\n"
"    border-width: 1px;\n"
"    border-color: #447684;   \n"
" \n"
"}"));
        TabDetail->verticalHeader()->setVisible(false);
        WinDetail = new QGroupBox(WidgetDetail);
        WinDetail->setObjectName(QString::fromUtf8("WinDetail"));
        WinDetail->setGeometry(QRect(9, 207, 764, 316));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WinDetail->sizePolicy().hasHeightForWidth());
        WinDetail->setSizePolicy(sizePolicy);
        WinDetail->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        TextHistogram = new Histogram(WinDetail);
        TextHistogram->setObjectName(QString::fromUtf8("TextHistogram"));
        TextHistogram->setGeometry(QRect(17, 25, 738, 280));
        WidgetShow->addWidget(WidgetDetail);
        WidgetCtrl = new QWidget(WinData);
        WidgetCtrl->setObjectName(QString::fromUtf8("WidgetCtrl"));
        WidgetCtrl->setGeometry(QRect(9, 547, 782, 44));
        label_2 = new QLabel(WidgetCtrl);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 33, 41));
        EditType = new QLineEdit(WidgetCtrl);
        EditType->setObjectName(QString::fromUtf8("EditType"));
        EditType->setGeometry(QRect(39, 0, 62, 44));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(EditType->sizePolicy().hasHeightForWidth());
        EditType->setSizePolicy(sizePolicy1);
        DateEdit1 = new QDateEdit(WidgetCtrl);
        DateEdit1->setObjectName(QString::fromUtf8("DateEdit1"));
        DateEdit1->setGeometry(QRect(107, 0, 115, 44));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(DateEdit1->sizePolicy().hasHeightForWidth());
        DateEdit1->setSizePolicy(sizePolicy2);
        label = new QLabel(WidgetCtrl);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(228, 0, 16, 41));
        DateEdit2 = new QDateEdit(WidgetCtrl);
        DateEdit2->setObjectName(QString::fromUtf8("DateEdit2"));
        DateEdit2->setGeometry(QRect(249, 0, 115, 44));
        sizePolicy2.setHeightForWidth(DateEdit2->sizePolicy().hasHeightForWidth());
        DateEdit2->setSizePolicy(sizePolicy2);
        DateEdit2->setDateTime(QDateTime(QDate(2017, 1, 1), QTime(0, 0, 0)));
        BtnShow = new QPushButton(WidgetCtrl);
        BtnShow->setObjectName(QString::fromUtf8("BtnShow"));
        BtnShow->setGeometry(QRect(376, 0, 97, 44));
        BtnShow->setMinimumSize(QSize(97, 44));
        BtnCheck = new QPushButton(WidgetCtrl);
        BtnCheck->setObjectName(QString::fromUtf8("BtnCheck"));
        BtnCheck->setGeometry(QRect(479, 0, 97, 44));
        BtnCheck->setMinimumSize(QSize(97, 44));
        BtnClear = new QPushButton(WidgetCtrl);
        BtnClear->setObjectName(QString::fromUtf8("BtnClear"));
        BtnClear->setGeometry(QRect(582, 0, 97, 44));
        BtnClear->setMinimumSize(QSize(97, 44));
        BtnExit = new QPushButton(WidgetCtrl);
        BtnExit->setObjectName(QString::fromUtf8("BtnExit"));
        BtnExit->setGeometry(QRect(685, 0, 97, 44));
        BtnExit->setMinimumSize(QSize(97, 44));

        retranslateUi(WinData);

        WidgetShow->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(WinData);
    } // setupUi

    void retranslateUi(QWidget *WinData)
    {
        WinData->setWindowTitle(QApplication::translate("WinData", "Form", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = TabDetail->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("WinData", "\351\241\271\347\233\256", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = TabDetail->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("WinData", "\346\265\213\350\257\225\346\200\273\346\225\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = TabDetail->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("WinData", "\345\220\210\346\240\274\346\225\260\351\207\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = TabDetail->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("WinData", "\344\270\215\345\220\210\346\240\274\346\225\260\351\207\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = TabDetail->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("WinData", "\345\220\210\346\240\274\347\216\207", 0, QApplication::UnicodeUTF8));
        WinDetail->setTitle(QApplication::translate("WinData", "\345\220\210\346\240\274\347\216\207", 0, QApplication::UnicodeUTF8));
        TextHistogram->setText(QApplication::translate("WinData", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("WinData", "\345\236\213\345\217\267:", 0, QApplication::UnicodeUTF8));
        DateEdit1->setDisplayFormat(QApplication::translate("WinData", "yyyy/MM/dd", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("WinData", "\350\207\263", 0, QApplication::UnicodeUTF8));
        DateEdit2->setDisplayFormat(QApplication::translate("WinData", "yyyy/MM/dd", 0, QApplication::UnicodeUTF8));
        BtnShow->setText(QApplication::translate("WinData", "\345\205\250\351\203\250\345\257\274\345\207\272", 0, QApplication::UnicodeUTF8));
        BtnCheck->setText(QApplication::translate("WinData", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        BtnClear->setText(QApplication::translate("WinData", "\346\270\205\347\251\272", 0, QApplication::UnicodeUTF8));
        BtnExit->setText(QApplication::translate("WinData", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WinData: public Ui_WinData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDATA_H
