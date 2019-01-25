/********************************************************************************
** Form generated from reading UI file 'password.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORD_H
#define UI_PASSWORD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PassWord
{
public:
    QFrame *frame;
    QPushButton *MOK_Button;
    QPushButton *MCancel_Button;
    QLabel *label_3;
    QLineEdit *PwdLineEdit_old;
    QLineEdit *PwdLineEdit_new;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *PwdLineEdit_newc;
    QFrame *frame_2;
    QPushButton *pushButton;
    QLabel *label_6;
    QFrame *frame_3;
    QLabel *label_2;
    QLineEdit *PwdLineEdit;
    QPushButton *Make_Button;
    QPushButton *Ok_Button;
    QPushButton *Cancle_Button;

    void setupUi(QWidget *PassWord)
    {
        if (PassWord->objectName().isEmpty())
            PassWord->setObjectName(QString::fromUtf8("PassWord"));
        PassWord->resize(800, 600);
        PassWord->setStyleSheet(QString::fromUtf8("background: none;"));
        frame = new QFrame(PassWord);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(230, 20, 341, 311));
        frame->setStyleSheet(QString::fromUtf8("QFrame{background-color: rgb(63, 63, 63);}\n"
"QFrame{border:1px groove #191919;}\n"
"QFrame{border-radius:18px;}\n"
"QFrame{padding:2px 4px;}\n"
"\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        MOK_Button = new QPushButton(frame);
        MOK_Button->setObjectName(QString::fromUtf8("MOK_Button"));
        MOK_Button->setGeometry(QRect(30, 240, 98, 41));
        MOK_Button->setStyleSheet(QString::fromUtf8("background-color: rgb(118, 118, 118);\n"
"\n"
" border-style: outset;\n"
" border-width: 1px;\n"
"border-radius: 5px;\n"
" border-color: #191919;\n"
" color:white;\n"
"padding: 1px;\n"
"    border: 1px solid #447684;\n"
"background-color: rgb(85, 85, 85);"));
        MCancel_Button = new QPushButton(frame);
        MCancel_Button->setObjectName(QString::fromUtf8("MCancel_Button"));
        MCancel_Button->setGeometry(QRect(200, 240, 98, 41));
        MCancel_Button->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
" border-width: 1px;\n"
"border-radius: 5px;\n"
" border-color: #191919;\n"
" color:white;\n"
"padding: 1px;\n"
"border: 1px solid #447684;\n"
"background-color: rgb(85, 85, 85);"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 20, 221, 21));
        label_3->setStyleSheet(QString::fromUtf8("QFrame{border:none;}\n"
"QFrame{color: rgb(255, 255, 255);}\n"
""));
        PwdLineEdit_old = new QLineEdit(frame);
        PwdLineEdit_old->setObjectName(QString::fromUtf8("PwdLineEdit_old"));
        PwdLineEdit_old->setGeometry(QRect(80, 40, 181, 40));
        PwdLineEdit_old->setFocusPolicy(Qt::ClickFocus);
        PwdLineEdit_old->setStyleSheet(QString::fromUtf8("    border: 1px solid #447684;\n"
"    color:black;\n"
""));
        PwdLineEdit_old->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText);
        PwdLineEdit_old->setEchoMode(QLineEdit::Password);
        PwdLineEdit_new = new QLineEdit(frame);
        PwdLineEdit_new->setObjectName(QString::fromUtf8("PwdLineEdit_new"));
        PwdLineEdit_new->setGeometry(QRect(80, 110, 181, 41));
        PwdLineEdit_new->setFocusPolicy(Qt::ClickFocus);
        PwdLineEdit_new->setStyleSheet(QString::fromUtf8("    border: 1px solid #447684;\n"
"    color:black;\n"
""));
        PwdLineEdit_new->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText);
        PwdLineEdit_new->setEchoMode(QLineEdit::Password);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 90, 221, 20));
        label_4->setStyleSheet(QString::fromUtf8("QFrame{border:none;}\n"
"QFrame{color: rgb(255, 255, 255);}"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 160, 221, 21));
        label_5->setStyleSheet(QString::fromUtf8("QFrame{border:none;}\n"
"QFrame{color: rgb(255, 255, 255);}"));
        PwdLineEdit_newc = new QLineEdit(frame);
        PwdLineEdit_newc->setObjectName(QString::fromUtf8("PwdLineEdit_newc"));
        PwdLineEdit_newc->setGeometry(QRect(80, 180, 181, 41));
        PwdLineEdit_newc->setFocusPolicy(Qt::ClickFocus);
        PwdLineEdit_newc->setStyleSheet(QString::fromUtf8("    border: 1px solid #447684;\n"
"    color:black;\n"
""));
        PwdLineEdit_newc->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText);
        PwdLineEdit_newc->setEchoMode(QLineEdit::Password);
        frame_2 = new QFrame(PassWord);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(200, 120, 391, 211));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame{background-color: rgb(63, 63, 63);}\n"
"QFrame{border:1px groove #191919;}\n"
"QFrame{border-radius:18px;}\n"
"QFrame{padding:2px 4px;}\n"
"\n"
""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 136, 98, 41));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(118, 118, 118);\n"
"\n"
" border-style: outset;\n"
" border-width: 1px;\n"
"border-radius: 5px;\n"
" border-color: #191919;\n"
" color:white;\n"
"padding: 1px;\n"
"    border: 1px solid #447684;\n"
"background-color: rgb(85, 85, 85);"));
        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(80, 40, 231, 71));
        QFont font;
        font.setPointSize(15);
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("QFrame{border:none;}\n"
"QFrame{color: rgb(255, 255, 255);}"));
        frame_3 = new QFrame(PassWord);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(230, 150, 341, 180));
        frame_3->setStyleSheet(QString::fromUtf8("QFrame{background-color: rgb(63, 63, 63);}\n"
"QFrame{border:1px groove #191919;}\n"
"QFrame{border-radius:18px;}\n"
"QFrame{padding:2px 4px;}\n"
"\n"
""));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 20, 221, 31));
        label_2->setStyleSheet(QString::fromUtf8("QFrame{border:none;}\n"
"QFrame{color: rgb(255, 255, 255);}\n"
""));
        PwdLineEdit = new QLineEdit(frame_3);
        PwdLineEdit->setObjectName(QString::fromUtf8("PwdLineEdit"));
        PwdLineEdit->setGeometry(QRect(80, 50, 191, 41));
        PwdLineEdit->setFocusPolicy(Qt::StrongFocus);
        PwdLineEdit->setStyleSheet(QString::fromUtf8("    border: 1px solid #447684;\n"
"    color:black;\n"
""));
        PwdLineEdit->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText);
        PwdLineEdit->setEchoMode(QLineEdit::Password);
        Make_Button = new QPushButton(frame_3);
        Make_Button->setObjectName(QString::fromUtf8("Make_Button"));
        Make_Button->setGeometry(QRect(130, 110, 91, 41));
        Make_Button->setMinimumSize(QSize(91, 41));
        Make_Button->setMaximumSize(QSize(91, 41));
        Make_Button->setStyleSheet(QString::fromUtf8("background-color: rgb(118, 118, 118);\n"
"\n"
" border-style: outset;\n"
" border-width: 1px;\n"
"border-radius: 5px;\n"
" border-color: #191919;\n"
" color:white;\n"
"padding: 1px;\n"
"    border: 1px solid #447684;\n"
"background-color: rgb(85, 85, 85);"));
        Ok_Button = new QPushButton(frame_3);
        Ok_Button->setObjectName(QString::fromUtf8("Ok_Button"));
        Ok_Button->setGeometry(QRect(20, 110, 91, 41));
        Ok_Button->setMinimumSize(QSize(91, 41));
        Ok_Button->setMaximumSize(QSize(41, 16777215));
        Ok_Button->setStyleSheet(QString::fromUtf8("background-color: rgb(118, 118, 118);\n"
"\n"
" border-style: outset;\n"
" border-width: 1px;\n"
"border-radius: 5px;\n"
" border-color: #191919;\n"
" color:white;\n"
"padding: 1px;\n"
"    border: 1px solid #447684;\n"
"background-color: rgb(85, 85, 85);"));
        Cancle_Button = new QPushButton(frame_3);
        Cancle_Button->setObjectName(QString::fromUtf8("Cancle_Button"));
        Cancle_Button->setGeometry(QRect(240, 110, 91, 41));
        Cancle_Button->setMinimumSize(QSize(91, 41));
        Cancle_Button->setMaximumSize(QSize(91, 41));
        Cancle_Button->setStyleSheet(QString::fromUtf8("background-color: rgb(118, 118, 118);\n"
"\n"
" border-style: outset;\n"
" border-width: 1px;\n"
"border-radius: 5px;\n"
" border-color: #191919;\n"
" color:white;\n"
"padding: 1px;\n"
"    border: 1px solid #447684;\n"
"background-color: rgb(85, 85, 85);"));
        frame_3->raise();
        frame_2->raise();
        frame->raise();
        QWidget::setTabOrder(Cancle_Button, MOK_Button);
        QWidget::setTabOrder(MOK_Button, Ok_Button);
        QWidget::setTabOrder(Ok_Button, PwdLineEdit);
        QWidget::setTabOrder(PwdLineEdit, pushButton);
        QWidget::setTabOrder(pushButton, MCancel_Button);
        QWidget::setTabOrder(MCancel_Button, Make_Button);

        retranslateUi(PassWord);

        QMetaObject::connectSlotsByName(PassWord);
    } // setupUi

    void retranslateUi(QWidget *PassWord)
    {
        PassWord->setWindowTitle(QApplication::translate("PassWord", "Form", 0, QApplication::UnicodeUTF8));
        MOK_Button->setText(QApplication::translate("PassWord", "\347\241\256\350\256\244\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        MCancel_Button->setText(QApplication::translate("PassWord", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PassWord", "\350\257\267\350\276\223\345\205\245\345\216\237\345\247\213\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        PwdLineEdit_old->setText(QString());
        PwdLineEdit_new->setText(QString());
        label_4->setText(QApplication::translate("PassWord", "\350\257\267\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("PassWord", "\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        PwdLineEdit_newc->setText(QString());
        pushButton->setText(QApplication::translate("PassWord", "\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("PassWord", "\345\275\223\345\211\215\346\223\215\344\275\234\346\250\241\345\274\217\346\230\257\346\223\215\344\275\234\345\221\230\357\274\214\n"
"\346\227\240\346\235\203\351\231\220\350\277\233\350\241\214\344\277\235\345\255\230\345\222\214\344\277\256\346\224\271\343\200\202", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PassWord", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        PwdLineEdit->setText(QString());
        Make_Button->setText(QApplication::translate("PassWord", "\344\277\256\346\224\271\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        Ok_Button->setText(QApplication::translate("PassWord", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        Cancle_Button->setText(QApplication::translate("PassWord", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PassWord: public Ui_PassWord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORD_H
