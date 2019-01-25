/********************************************************************************
** Form generated from reading UI file 'w_help.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_HELP_H
#define UI_W_HELP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_w_Help
{
public:
    QLabel *label;
    QPushButton *Key_A;
    QLabel *Label_Display;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QLabel *DLabel05;
    QPushButton *pushButton_up;
    QPushButton *pushButton_down;

    void setupUi(QWidget *w_Help)
    {
        if (w_Help->objectName().isEmpty())
            w_Help->setObjectName(QString::fromUtf8("w_Help"));
        w_Help->resize(800, 600);
        w_Help->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(w_Help);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(17, 550, 771, 51));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(13);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));
        Key_A = new QPushButton(w_Help);
        Key_A->setObjectName(QString::fromUtf8("Key_A"));
        Key_A->setGeometry(QRect(660, 10, 131, 61));
        Key_A->setFocusPolicy(Qt::TabFocus);
        Key_A->setStyleSheet(QString::fromUtf8("QToolButton{border:0px;}"));
        Key_A->setIconSize(QSize(64, 64));
        Label_Display = new QLabel(w_Help);
        Label_Display->setObjectName(QString::fromUtf8("Label_Display"));
        Label_Display->setGeometry(QRect(20, 10, 221, 61));
        QFont font1;
        font1.setPointSize(18);
        Label_Display->setFont(font1);
        textEdit = new QTextEdit(w_Help);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(true);
        textEdit->setGeometry(QRect(10, 80, 781, 471));
        pushButton = new QPushButton(w_Help);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(330, 10, 131, 61));
        DLabel05 = new QLabel(w_Help);
        DLabel05->setObjectName(QString::fromUtf8("DLabel05"));
        DLabel05->setGeometry(QRect(10, 80, 781, 471));
        DLabel05->setStyleSheet(QString::fromUtf8("border:2px groove gray;\n"
""));
        DLabel05->setFrameShape(QFrame::WinPanel);
        DLabel05->setPixmap(QPixmap(QString::fromUtf8(":/new/M1S1.jpg")));
        DLabel05->setScaledContents(true);
        DLabel05->setAlignment(Qt::AlignCenter);
        pushButton_up = new QPushButton(w_Help);
        pushButton_up->setObjectName(QString::fromUtf8("pushButton_up"));
        pushButton_up->setGeometry(QRect(230, 10, 91, 61));
        pushButton_down = new QPushButton(w_Help);
        pushButton_down->setObjectName(QString::fromUtf8("pushButton_down"));
        pushButton_down->setGeometry(QRect(470, 10, 91, 61));

        retranslateUi(w_Help);

        QMetaObject::connectSlotsByName(w_Help);
    } // setupUi

    void retranslateUi(QWidget *w_Help)
    {
        w_Help->setWindowTitle(QApplication::translate("w_Help", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("w_Help", "\346\254\242\350\277\216\346\202\250\350\264\255\344\271\260\346\234\254\344\272\247\345\223\201\357\274\214\346\234\211\351\227\256\351\242\230\350\257\267\350\207\264\347\224\265    0532-87973318                                        \351\235\222\345\262\233\350\211\276\346\231\256\346\231\272\350\203\275\344\273\252\345\231\250\346\234\211\351\231\220\345\205\254\345\217\270", 0, QApplication::UnicodeUTF8));
        Key_A->setText(QApplication::translate("w_Help", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        Label_Display->setText(QApplication::translate("w_Help", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        textEdit->setHtml(QApplication::translate("w_Help", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\265\213\350\257\225\344\270\255...</p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("w_Help", "\350\256\241\351\207\217\345\233\276\347\211\207", 0, QApplication::UnicodeUTF8));
        DLabel05->setText(QString());
        pushButton_up->setText(QApplication::translate("w_Help", "\344\270\212\344\270\200\345\274\240", 0, QApplication::UnicodeUTF8));
        pushButton_down->setText(QApplication::translate("w_Help", "\344\270\213\344\270\200\345\274\240", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class w_Help: public Ui_w_Help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_HELP_H
