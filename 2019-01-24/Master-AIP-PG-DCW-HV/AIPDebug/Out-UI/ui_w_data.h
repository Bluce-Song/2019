/********************************************************************************
** Form generated from reading UI file 'w_data.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_DATA_H
#define UI_W_DATA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_w_Data
{
public:
    QLabel *label;
    QPushButton *back;
    QPushButton *button_in;
    QPushButton *button_put;
    QLabel *label_Udiak;
    QPushButton *button_out_model;
    QLineEdit *lineEdit;
    QPushButton *button_check;
    QLineEdit *Model;
    QLabel *label_Udiak_2;
    QTableWidget *tableWidget;
    QPushButton *button_start;
    QPushButton *button_stop;
    QLabel *label_Udiak_3;
    QPushButton *button_detailed;
    QLabel *label_5;
    QPushButton *button_clear;
    QTableView *tableView;
    QPushButton *button_change;
    QLabel *label_SD;

    void setupUi(QDialog *w_Data)
    {
        if (w_Data->objectName().isEmpty())
            w_Data->setObjectName(QString::fromUtf8("w_Data"));
        w_Data->resize(800, 600);
        w_Data->setAutoFillBackground(true);
        label = new QLabel(w_Data);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 800, 600));
        label->setStyleSheet(QString::fromUtf8(""));
        label->setFrameShape(QFrame::StyledPanel);
        back = new QPushButton(w_Data);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(670, 20, 111, 51));
        button_in = new QPushButton(w_Data);
        button_in->setObjectName(QString::fromUtf8("button_in"));
        button_in->setGeometry(QRect(510, 520, 98, 31));
        button_put = new QPushButton(w_Data);
        button_put->setObjectName(QString::fromUtf8("button_put"));
        button_put->setGeometry(QRect(637, 550, 151, 41));
        label_Udiak = new QLabel(w_Data);
        label_Udiak->setObjectName(QString::fromUtf8("label_Udiak"));
        label_Udiak->setGeometry(QRect(450, 550, 191, 41));
        QFont font;
        font.setPointSize(9);
        label_Udiak->setFont(font);
        label_Udiak->setAlignment(Qt::AlignCenter);
        button_out_model = new QPushButton(w_Data);
        button_out_model->setObjectName(QString::fromUtf8("button_out_model"));
        button_out_model->setGeometry(QRect(510, 520, 98, 31));
        lineEdit = new QLineEdit(w_Data);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(550, 520, 61, 31));
        lineEdit->setAlignment(Qt::AlignCenter);
        button_check = new QPushButton(w_Data);
        button_check->setObjectName(QString::fromUtf8("button_check"));
        button_check->setGeometry(QRect(480, 20, 81, 51));
        Model = new QLineEdit(w_Data);
        Model->setObjectName(QString::fromUtf8("Model"));
        Model->setGeometry(QRect(92, 20, 121, 51));
        Model->setAlignment(Qt::AlignCenter);
        label_Udiak_2 = new QLabel(w_Data);
        label_Udiak_2->setObjectName(QString::fromUtf8("label_Udiak_2"));
        label_Udiak_2->setGeometry(QRect(20, 20, 71, 51));
        label_Udiak_2->setAlignment(Qt::AlignCenter);
        tableWidget = new QTableWidget(w_Data);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(15, 80, 771, 420));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setFocusPolicy(Qt::NoFocus);
        tableWidget->setStyleSheet(QString::fromUtf8(""));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(5);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setHighlightSections(false);
        button_start = new QPushButton(w_Data);
        button_start->setObjectName(QString::fromUtf8("button_start"));
        button_start->setGeometry(QRect(220, 20, 111, 51));
        button_stop = new QPushButton(w_Data);
        button_stop->setObjectName(QString::fromUtf8("button_stop"));
        button_stop->setGeometry(QRect(360, 20, 111, 51));
        button_stop->setStyleSheet(QString::fromUtf8(""));
        label_Udiak_3 = new QLabel(w_Data);
        label_Udiak_3->setObjectName(QString::fromUtf8("label_Udiak_3"));
        label_Udiak_3->setGeometry(QRect(330, 20, 31, 41));
        label_Udiak_3->setAlignment(Qt::AlignCenter);
        button_detailed = new QPushButton(w_Data);
        button_detailed->setObjectName(QString::fromUtf8("button_detailed"));
        button_detailed->setGeometry(QRect(570, 20, 91, 51));
        label_5 = new QLabel(w_Data);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(552, 11, 16, 17));
        button_clear = new QPushButton(w_Data);
        button_clear->setObjectName(QString::fromUtf8("button_clear"));
        button_clear->setGeometry(QRect(200, 550, 121, 41));
        tableView = new QTableView(w_Data);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(15, 80, 771, 441));
        tableView->setStyleSheet(QString::fromUtf8("background-color:#191919;\n"
"color: rgb(255, 255, 255);\n"
"border: 1px outset solid #32435E;\n"
"border-style: groove;\n"
"    border-width: 1px;\n"
"    border-color: #447684;"));
        button_change = new QPushButton(w_Data);
        button_change->setObjectName(QString::fromUtf8("button_change"));
        button_change->setGeometry(QRect(20, 550, 161, 41));
        label_SD = new QLabel(w_Data);
        label_SD->setObjectName(QString::fromUtf8("label_SD"));
        label_SD->setGeometry(QRect(330, 550, 111, 41));
        label_SD->setFont(font);
        label_SD->setAlignment(Qt::AlignCenter);

        retranslateUi(w_Data);

        QMetaObject::connectSlotsByName(w_Data);
    } // setupUi

    void retranslateUi(QDialog *w_Data)
    {
        back->setText(QApplication::translate("w_Data", "\345\274\200\346\234\272\344\270\273\351\241\265", 0, QApplication::UnicodeUTF8));
        button_in->setText(QApplication::translate("w_Data", "\346\225\260\346\215\256\345\257\274\345\205\245", 0, QApplication::UnicodeUTF8));
        button_put->setText(QApplication::translate("w_Data", "\346\225\260\346\215\256\345\257\274\345\207\272", 0, QApplication::UnicodeUTF8));
        label_Udiak->setText(QApplication::translate("w_Data", "U\347\233\230-\357\274\237", 0, QApplication::UnicodeUTF8));
        button_out_model->setText(QApplication::translate("w_Data", "\345\236\213\345\217\267\345\257\274\345\207\272", 0, QApplication::UnicodeUTF8));
        button_check->setText(QApplication::translate("w_Data", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        Model->setText(QApplication::translate("w_Data", "AIP-II", 0, QApplication::UnicodeUTF8));
        label_Udiak_2->setText(QApplication::translate("w_Data", "\345\236\213\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QApplication::translate("w_Data", "\346\265\213\350\257\225\346\225\260\351\207\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QApplication::translate("w_Data", "\345\220\210\346\240\274\346\225\260\351\207\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem2->setText(QApplication::translate("w_Data", "\344\270\215\345\220\210\346\240\274\346\225\260\351\207\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem3->setText(QApplication::translate("w_Data", "\345\220\210\346\240\274\347\216\207", 0, QApplication::UnicodeUTF8));
        button_start->setText(QApplication::translate("w_Data", "\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        button_stop->setText(QApplication::translate("w_Data", "\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        label_Udiak_3->setText(QApplication::translate("w_Data", "\350\207\263", 0, QApplication::UnicodeUTF8));
        button_detailed->setText(QApplication::translate("w_Data", "\350\257\246\347\273\206\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label_5->setText(QString());
        button_clear->setText(QApplication::translate("w_Data", "\346\270\205\351\231\244\345\205\250\351\203\250\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        button_change->setText(QApplication::translate("w_Data", "\350\257\246\347\273\206\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        label_SD->setText(QApplication::translate("w_Data", "SD", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(w_Data);
    } // retranslateUi

};

namespace Ui {
    class w_Data: public Ui_w_Data {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_DATA_H
