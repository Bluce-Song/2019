/********************************************************************************
** Form generated from reading UI file 'w_colr.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_COLR_H
#define UI_W_COLR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_w_Colr
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *colorLayout;
    QPushButton *pushButton;

    void setupUi(QDialog *w_Colr)
    {
        if (w_Colr->objectName().isEmpty())
            w_Colr->setObjectName(QString::fromUtf8("w_Colr"));
        w_Colr->resize(800, 600);
        w_Colr->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 19, 19);"));
        gridLayoutWidget = new QWidget(w_Colr);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 80, 781, 511));
        colorLayout = new QGridLayout(gridLayoutWidget);
        colorLayout->setObjectName(QString::fromUtf8("colorLayout"));
        colorLayout->setVerticalSpacing(5);
        colorLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(w_Colr);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(680, 20, 111, 50));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}"));

        retranslateUi(w_Colr);

        QMetaObject::connectSlotsByName(w_Colr);
    } // setupUi

    void retranslateUi(QDialog *w_Colr)
    {
        w_Colr->setWindowTitle(QApplication::translate("w_Colr", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("w_Colr", "\350\256\276\347\275\256\351\246\226\351\241\265", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class w_Colr: public Ui_w_Colr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_COLR_H
