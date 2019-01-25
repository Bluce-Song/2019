/********************************************************************************
** Form generated from reading UI file 'w_main.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_MAIN_H
#define UI_W_MAIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_w_Main
{
public:
    QLabel *label;
    QToolButton *Key_E;
    QTextBrowser *Print_Text;
    QLabel *label_2;
    QLabel *label_Version;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Key_A;
    QPushButton *Key_B;
    QPushButton *Key_C;
    QPushButton *Key_D;
    QLabel *label_4;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_;
    QLabel *label_no_connect;
    QLabel *label_clock;
    QLabel *label_hand;
    QLabel *label_print;
    QLabel *label_sqldata;
    QLabel *label_net;

    void setupUi(QWidget *w_Main)
    {
        if (w_Main->objectName().isEmpty())
            w_Main->setObjectName(QString::fromUtf8("w_Main"));
        w_Main->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/\350\211\276\346\231\256\347\225\214\351\235\242.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        w_Main->setWindowIcon(icon);
        w_Main->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(w_Main);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 800, 600));
        label->setPixmap(QPixmap(QString::fromUtf8(":/image/d1.bmp")));
        Key_E = new QToolButton(w_Main);
        Key_E->setObjectName(QString::fromUtf8("Key_E"));
        Key_E->setEnabled(true);
        Key_E->setGeometry(QRect(30, 480, 101, 91));
        Key_E->setStyleSheet(QString::fromUtf8("QToolButton{border:0px;}"));
        Key_E->setIconSize(QSize(64, 64));
        Key_E->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        Print_Text = new QTextBrowser(w_Main);
        Print_Text->setObjectName(QString::fromUtf8("Print_Text"));
        Print_Text->setEnabled(true);
        Print_Text->setGeometry(QRect(170, 410, 461, 171));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Print_Text->sizePolicy().hasHeightForWidth());
        Print_Text->setSizePolicy(sizePolicy);
        Print_Text->setLayoutDirection(Qt::LeftToRight);
        Print_Text->setStyleSheet(QString::fromUtf8("font: 75 italic 11pt \"Ubuntu\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: none;\n"
"border: none;\n"
"\n"
"\n"
""));
        label_2 = new QLabel(w_Main);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 350, 701, 231));
        label_2->setStyleSheet(QString::fromUtf8("background: #191919;\n"
"color: rgb(255, 255, 255);\n"
"background-color: none;"));
        label_2->setAlignment(Qt::AlignCenter);
        label_Version = new QLabel(w_Main);
        label_Version->setObjectName(QString::fromUtf8("label_Version"));
        label_Version->setGeometry(QRect(280, 380, 251, 31));
        label_Version->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(255, 255, 255);"));
        label_Version->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(w_Main);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(100, 460, 621, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Key_A = new QPushButton(horizontalLayoutWidget);
        Key_A->setObjectName(QString::fromUtf8("Key_A"));
        Key_A->setEnabled(true);
        Key_A->setMinimumSize(QSize(121, 71));
        Key_A->setMaximumSize(QSize(121, 71));
        Key_A->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}\n"
"QPushButton#up_Button{\n"
"border:1px groove white;\n"
"image: url(:/image/arrow_up.ico);\n"
"border-color: #447684;\n"
"    background-color:#191919;\n"
"}\n"
"QPushButton#down_Button{\n"
"border:1px groove white;\n"
"image: url(:/image/arrow_down.ico);\n"
"    border-color: #447684;\n"
"    background-color:#191919;\n"
"}"));
        Key_A->setIconSize(QSize(64, 64));

        horizontalLayout->addWidget(Key_A);

        Key_B = new QPushButton(horizontalLayoutWidget);
        Key_B->setObjectName(QString::fromUtf8("Key_B"));
        Key_B->setEnabled(true);
        Key_B->setMinimumSize(QSize(121, 71));
        Key_B->setMaximumSize(QSize(121, 71));
        Key_B->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}\n"
"QPushButton#up_Button{\n"
"border:1px groove white;\n"
"image: url(:/image/arrow_up.ico);\n"
"border-color: #447684;\n"
"    background-color:#191919;\n"
"}\n"
"QPushButton#down_Button{\n"
"border:1px groove white;\n"
"image: url(:/image/arrow_down.ico);\n"
"    border-color: #447684;\n"
"    background-color:#191919;\n"
"}"));
        Key_B->setIconSize(QSize(64, 64));

        horizontalLayout->addWidget(Key_B);

        Key_C = new QPushButton(horizontalLayoutWidget);
        Key_C->setObjectName(QString::fromUtf8("Key_C"));
        Key_C->setEnabled(true);
        Key_C->setMinimumSize(QSize(121, 71));
        Key_C->setMaximumSize(QSize(121, 71));
        Key_C->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}\n"
"QPushButton#up_Button{\n"
"border:1px groove white;\n"
"image: url(:/image/arrow_up.ico);\n"
"border-color: #447684;\n"
"    background-color:#191919;\n"
"}\n"
"QPushButton#down_Button{\n"
"border:1px groove white;\n"
"image: url(:/image/arrow_down.ico);\n"
"    border-color: #447684;\n"
"    background-color:#191919;\n"
"}"));
        Key_C->setIconSize(QSize(64, 64));

        horizontalLayout->addWidget(Key_C);

        Key_D = new QPushButton(horizontalLayoutWidget);
        Key_D->setObjectName(QString::fromUtf8("Key_D"));
        Key_D->setEnabled(true);
        Key_D->setMinimumSize(QSize(121, 71));
        Key_D->setMaximumSize(QSize(121, 71));
        Key_D->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}\n"
"QPushButton#up_Button{\n"
"border:1px groove white;\n"
"image: url(:/image/arrow_up.ico);\n"
"border-color: #447684;\n"
"    background-color:#191919;\n"
"}\n"
"QPushButton#down_Button{\n"
"border:1px groove white;\n"
"image: url(:/image/arrow_down.ico);\n"
"    border-color: #447684;\n"
"    background-color:#191919;\n"
"}"));
        Key_D->setIconSize(QSize(64, 64));

        horizontalLayout->addWidget(Key_D);

        label_4 = new QLabel(w_Main);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 360, 771, 51));
        label_4->setStyleSheet(QString::fromUtf8("background: #191919;\n"
"color: rgb(255, 255, 255);\n"
"background-color: none;\n"
"\n"
""));
        label_4->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget_2 = new QWidget(w_Main);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(310, 10, 481, 51));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_ = new QLabel(horizontalLayoutWidget_2);
        label_->setObjectName(QString::fromUtf8("label_"));
        label_->setMinimumSize(QSize(131, 31));
        label_->setMaximumSize(QSize(131, 16777215));
        label_->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(255, 255, 255);"));
        label_->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_);

        label_no_connect = new QLabel(horizontalLayoutWidget_2);
        label_no_connect->setObjectName(QString::fromUtf8("label_no_connect"));
        label_no_connect->setMinimumSize(QSize(41, 49));
        label_no_connect->setMaximumSize(QSize(41, 49));
        label_no_connect->setPixmap(QPixmap(QString::fromUtf8(":/image/connect_no.png")));

        horizontalLayout_2->addWidget(label_no_connect);

        label_clock = new QLabel(horizontalLayoutWidget_2);
        label_clock->setObjectName(QString::fromUtf8("label_clock"));
        label_clock->setMinimumSize(QSize(41, 49));
        label_clock->setMaximumSize(QSize(41, 49));
        label_clock->setPixmap(QPixmap(QString::fromUtf8(":/image/chronometer.png")));

        horizontalLayout_2->addWidget(label_clock);

        label_hand = new QLabel(horizontalLayoutWidget_2);
        label_hand->setObjectName(QString::fromUtf8("label_hand"));
        label_hand->setMinimumSize(QSize(41, 49));
        label_hand->setMaximumSize(QSize(41, 49));
        label_hand->setPixmap(QPixmap(QString::fromUtf8(":/image/hand-1.png")));

        horizontalLayout_2->addWidget(label_hand);

        label_print = new QLabel(horizontalLayoutWidget_2);
        label_print->setObjectName(QString::fromUtf8("label_print"));
        label_print->setMinimumSize(QSize(41, 0));
        label_print->setMaximumSize(QSize(41, 16777215));
        label_print->setPixmap(QPixmap(QString::fromUtf8(":/image/printer.png")));
        label_print->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_print);

        label_sqldata = new QLabel(horizontalLayoutWidget_2);
        label_sqldata->setObjectName(QString::fromUtf8("label_sqldata"));
        label_sqldata->setMinimumSize(QSize(40, 0));
        label_sqldata->setMaximumSize(QSize(40, 16777215));
        label_sqldata->setPixmap(QPixmap(QString::fromUtf8(":/image/database.png")));
        label_sqldata->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_sqldata);

        label_net = new QLabel(horizontalLayoutWidget_2);
        label_net->setObjectName(QString::fromUtf8("label_net"));
        label_net->setMinimumSize(QSize(40, 0));
        label_net->setMaximumSize(QSize(40, 16777215));
        label_net->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_net->setPixmap(QPixmap(QString::fromUtf8(":/image/wifi.png")));
        label_net->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_net);

        label->raise();
        Key_E->raise();
        label_Version->raise();
        horizontalLayoutWidget->raise();
        Print_Text->raise();
        label_4->raise();
        label_2->raise();
        horizontalLayoutWidget_2->raise();
        QWidget::setTabOrder(Key_A, Key_B);
        QWidget::setTabOrder(Key_B, Key_C);
        QWidget::setTabOrder(Key_C, Key_D);
        QWidget::setTabOrder(Key_D, Print_Text);
        QWidget::setTabOrder(Print_Text, Key_E);

        retranslateUi(w_Main);

        QMetaObject::connectSlotsByName(w_Main);
    } // setupUi

    void retranslateUi(QWidget *w_Main)
    {
        label->setText(QString());
        Key_E->setText(QString());
        Print_Text->setHtml(QApplication::translate("w_Main", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:72; font-style:italic;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Motor comprehensive tester</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Testing...</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("w_Main", "<html><head/><body><p><br/></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_Version->setText(QApplication::translate("w_Main", "\347\211\210\346\234\254\357\274\232", 0, QApplication::UnicodeUTF8));
        Key_A->setText(QApplication::translate("w_Main", "\347\263\273\347\273\237\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        Key_B->setText(QApplication::translate("w_Main", "\345\236\213\345\217\267\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        Key_C->setText(QApplication::translate("w_Main", "\346\225\260\346\215\256\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        Key_D->setText(QApplication::translate("w_Main", "\350\277\233\345\205\245\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("w_Main", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">\350\255\246\345\221\212\357\274\232\345\234\250\344\275\277\347\224\250\345\211\215\357\274\214\350\257\267\347\241\256\344\277\235\344\273\252\345\231\250\347\224\265\346\272\220\346\216\245\345\234\260\346\255\243\345\270\270</span></p><p align=\"center\"><span style=\" font-size:18pt;\"><br/></span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_->setText(QString());
        label_no_connect->setText(QString());
        label_clock->setText(QString());
        label_hand->setText(QString());
        label_print->setText(QString());
        label_sqldata->setText(QString());
        label_net->setText(QString());
        Q_UNUSED(w_Main);
    } // retranslateUi

};

namespace Ui {
    class w_Main: public Ui_w_Main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_MAIN_H
