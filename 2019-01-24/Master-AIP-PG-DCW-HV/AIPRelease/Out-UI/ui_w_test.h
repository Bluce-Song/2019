/********************************************************************************
** Form generated from reading UI file 'w_test.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_TEST_H
#define UI_W_TEST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_w_Test
{
public:
    QLabel *label_5;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *waveLayout;
    QLabel *leftLabel;
    QLabel *rightLabel;
    QLabel *S1Label;
    QLabel *label_user;
    QLabel *label_number;
    QLabel *label_model;
    QLabel *label;
    QLabel *label_A;
    QLabel *label_B;
    QLabel *label_C;
    QPushButton *button_up;
    QPushButton *button_down;
    QLabel *label_temp;
    QFrame *frame_state;
    QLabel *label_6;
    QLabel *label_station;
    QLabel *label_7;
    QLabel *S1Label_2;
    QPushButton *button_set;
    QPushButton *button_back;
    QTableWidget *testTab;
    QWidget *gridLayoutWidget;
    QGridLayout *colorLayout;
    QLabel *colorLabel01;
    QLabel *colorLabel08;
    QLabel *colorLabel03;
    QLabel *colorLabel05;
    QLabel *colorLabel02;
    QLabel *colorLabel04;
    QLabel *colorLabel07;
    QLabel *colorLabel06;
    QLabel *label_qualified;
    QLabel *label_sum;
    QLabel *label_Unqualified;
    QToolButton *button_shape;
    QLabel *label_2;
    QToolButton *Key_E;
    QLabel *label_noise;

    void setupUi(QWidget *w_Test)
    {
        if (w_Test->objectName().isEmpty())
            w_Test->setObjectName(QString::fromUtf8("w_Test"));
        w_Test->resize(800, 600);
        w_Test->setStyleSheet(QString::fromUtf8(""));
        label_5 = new QLabel(w_Test);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(5, 575, 651, 25));
        QFont font;
        font.setPointSize(15);
        font.setBold(false);
        font.setWeight(50);
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8(""));
        label_5->setAlignment(Qt::AlignCenter);
        label_5->setWordWrap(true);
        horizontalLayoutWidget = new QWidget(w_Test);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 420, 611, 131));
        waveLayout = new QHBoxLayout(horizontalLayoutWidget);
        waveLayout->setSpacing(0);
        waveLayout->setObjectName(QString::fromUtf8("waveLayout"));
        waveLayout->setSizeConstraint(QLayout::SetMinimumSize);
        waveLayout->setContentsMargins(6, 0, 5, 0);
        leftLabel = new QLabel(w_Test);
        leftLabel->setObjectName(QString::fromUtf8("leftLabel"));
        leftLabel->setGeometry(QRect(5, 12, 651, 560));
        leftLabel->setStyleSheet(QString::fromUtf8("border:1px groove white;\n"
"    border-color: #447684;"));
        leftLabel->setFrameShape(QFrame::StyledPanel);
        rightLabel = new QLabel(w_Test);
        rightLabel->setObjectName(QString::fromUtf8("rightLabel"));
        rightLabel->setGeometry(QRect(660, 0, 141, 600));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        rightLabel->setFont(font1);
        S1Label = new QLabel(w_Test);
        S1Label->setObjectName(QString::fromUtf8("S1Label"));
        S1Label->setGeometry(QRect(670, 570, 121, 15));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        S1Label->setFont(font2);
        S1Label->setStyleSheet(QString::fromUtf8("background-color:#191919;\n"
"color: white;\n"
"font: 9pt;"));
        S1Label->setAlignment(Qt::AlignCenter);
        label_user = new QLabel(w_Test);
        label_user->setObjectName(QString::fromUtf8("label_user"));
        label_user->setGeometry(QRect(384, 551, 141, 20));
        label_user->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_user->setAlignment(Qt::AlignCenter);
        label_number = new QLabel(w_Test);
        label_number->setObjectName(QString::fromUtf8("label_number"));
        label_number->setGeometry(QRect(175, 550, 201, 21));
        QFont font3;
        font3.setBold(false);
        font3.setWeight(50);
        label_number->setFont(font3);
        label_number->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_number->setLineWidth(1);
        label_number->setAlignment(Qt::AlignCenter);
        label_model = new QLabel(w_Test);
        label_model->setObjectName(QString::fromUtf8("label_model"));
        label_model->setGeometry(QRect(6, 551, 171, 20));
        label_model->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-color: rgb(255, 255, 255);"));
        label_model->setAlignment(Qt::AlignCenter);
        label = new QLabel(w_Test);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(821, 117, 16, 16));
        label_A = new QLabel(w_Test);
        label_A->setObjectName(QString::fromUtf8("label_A"));
        label_A->setGeometry(QRect(6, 399, 199, 21));
        label_A->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border:0.5px groove white;\n"
"    border-color: #447684;"));
        label_A->setAlignment(Qt::AlignCenter);
        label_B = new QLabel(w_Test);
        label_B->setObjectName(QString::fromUtf8("label_B"));
        label_B->setGeometry(QRect(205, 399, 201, 21));
        label_B->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border:1px groove white;\n"
"    border-color: #447684;"));
        label_B->setAlignment(Qt::AlignCenter);
        label_C = new QLabel(w_Test);
        label_C->setObjectName(QString::fromUtf8("label_C"));
        label_C->setGeometry(QRect(406, 399, 201, 21));
        label_C->setStyleSheet(QString::fromUtf8("border:1px groove white;\n"
"color: rgb(255, 255, 255);\n"
"    border-color: #447684;"));
        label_C->setAlignment(Qt::AlignCenter);
        button_up = new QPushButton(w_Test);
        button_up->setObjectName(QString::fromUtf8("button_up"));
        button_up->setEnabled(false);
        button_up->setGeometry(QRect(607, 397, 47, 77));
        button_up->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/arrow_up.ico"), QSize(), QIcon::Normal, QIcon::Off);
        button_up->setIcon(icon);
        button_down = new QPushButton(w_Test);
        button_down->setObjectName(QString::fromUtf8("button_down"));
        button_down->setEnabled(false);
        button_down->setGeometry(QRect(607, 472, 47, 78));
        button_down->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/arrow_down.ico"), QSize(), QIcon::Normal, QIcon::Off);
        button_down->setIcon(icon1);
        label_temp = new QLabel(w_Test);
        label_temp->setObjectName(QString::fromUtf8("label_temp"));
        label_temp->setGeometry(QRect(529, 551, 121, 20));
        label_temp->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_temp->setAlignment(Qt::AlignCenter);
        frame_state = new QFrame(w_Test);
        frame_state->setObjectName(QString::fromUtf8("frame_state"));
        frame_state->setGeometry(QRect(670, 430, 121, 141));
        frame_state->setStyleSheet(QString::fromUtf8("border:1px groove ;\n"
"background-color:#191919;\n"
"border-radius:8px;\n"
"border-color: #447684;\n"
""));
        frame_state->setFrameShape(QFrame::StyledPanel);
        frame_state->setFrameShadow(QFrame::Raised);
        label_6 = new QLabel(frame_state);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(3, 70, 111, 61));
        QFont font4;
        font4.setPointSize(42);
        font4.setBold(true);
        font4.setItalic(false);
        font4.setWeight(75);
        label_6->setFont(font4);
        label_6->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"color: rgb(0, 255, 0);\n"
"font:Bold  42pt;\n"
"border: none;\n"
""));
        label_6->setAlignment(Qt::AlignCenter);
        label_station = new QLabel(frame_state);
        label_station->setObjectName(QString::fromUtf8("label_station"));
        label_station->setGeometry(QRect(10, 10, 101, 61));
        QFont font5;
        font5.setFamily(QString::fromUtf8("40pt"));
        font5.setBold(true);
        font5.setItalic(false);
        font5.setWeight(75);
        label_station->setFont(font5);
        label_station->setStyleSheet(QString::fromUtf8(""));
        label_station->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        label_7 = new QLabel(w_Test);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(670, 310, 121, 111));
        QFont font6;
        font6.setPointSize(21);
        label_7->setFont(font6);
        label_7->setStyleSheet(QString::fromUtf8("border:1px groove white;\n"
"border-radius:10px;\n"
"padding:2px 4px;\n"
"    background-color:#191919;\n"
"    border-color: #447684;\n"
""));
        label_7->setAlignment(Qt::AlignCenter);
        S1Label_2 = new QLabel(w_Test);
        S1Label_2->setObjectName(QString::fromUtf8("S1Label_2"));
        S1Label_2->setGeometry(QRect(670, 585, 121, 15));
        S1Label_2->setFont(font2);
        S1Label_2->setStyleSheet(QString::fromUtf8("    background-color:#191919;\n"
"color: white;\n"
"font: 9pt;"));
        S1Label_2->setAlignment(Qt::AlignCenter);
        button_set = new QPushButton(w_Test);
        button_set->setObjectName(QString::fromUtf8("button_set"));
        button_set->setGeometry(QRect(670, 70, 121, 50));
        button_set->setMinimumSize(QSize(0, 50));
        button_set->setMaximumSize(QSize(16777215, 50));
        button_set->setSizeIncrement(QSize(0, 50));
        button_set->setFont(font3);
        button_set->setStyleSheet(QString::fromUtf8(""));
        button_set->setIconSize(QSize(16, 16));
        button_back = new QPushButton(w_Test);
        button_back->setObjectName(QString::fromUtf8("button_back"));
        button_back->setGeometry(QRect(670, 10, 121, 50));
        button_back->setMinimumSize(QSize(0, 50));
        button_back->setSizeIncrement(QSize(0, 50));
        button_back->setFont(font3);
        button_back->setStyleSheet(QString::fromUtf8(""));
        button_back->setIconSize(QSize(255, 255));
        testTab = new QTableWidget(w_Test);
        if (testTab->columnCount() < 5)
            testTab->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        testTab->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        testTab->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        testTab->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        testTab->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        testTab->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        testTab->setObjectName(QString::fromUtf8("testTab"));
        testTab->setGeometry(QRect(5, 12, 651, 387));
        testTab->setFocusPolicy(Qt::NoFocus);
        testTab->setStyleSheet(QString::fromUtf8("QScrollBar:vertical {\n"
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
"}\n"
""));
        testTab->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        testTab->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        testTab->setEditTriggers(QAbstractItemView::NoEditTriggers);
        testTab->setSelectionMode(QAbstractItemView::NoSelection);
        testTab->setSelectionBehavior(QAbstractItemView::SelectRows);
        testTab->setRowCount(0);
        testTab->setColumnCount(5);
        testTab->horizontalHeader()->setHighlightSections(false);
        testTab->horizontalHeader()->setStretchLastSection(true);
        testTab->verticalHeader()->setVisible(false);
        testTab->verticalHeader()->setHighlightSections(false);
        gridLayoutWidget = new QWidget(w_Test);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(680, 320, 101, 91));
        colorLayout = new QGridLayout(gridLayoutWidget);
        colorLayout->setObjectName(QString::fromUtf8("colorLayout"));
        colorLayout->setContentsMargins(0, 0, 0, 0);
        colorLabel01 = new QLabel(gridLayoutWidget);
        colorLabel01->setObjectName(QString::fromUtf8("colorLabel01"));
        colorLabel01->setStyleSheet(QString::fromUtf8("border:none;"));
        colorLabel01->setFrameShape(QFrame::StyledPanel);
        colorLabel01->setAlignment(Qt::AlignCenter);

        colorLayout->addWidget(colorLabel01, 0, 0, 1, 1);

        colorLabel08 = new QLabel(gridLayoutWidget);
        colorLabel08->setObjectName(QString::fromUtf8("colorLabel08"));
        colorLabel08->setStyleSheet(QString::fromUtf8("border:none;"));
        colorLabel08->setFrameShape(QFrame::StyledPanel);
        colorLabel08->setAlignment(Qt::AlignCenter);

        colorLayout->addWidget(colorLabel08, 3, 1, 1, 1);

        colorLabel03 = new QLabel(gridLayoutWidget);
        colorLabel03->setObjectName(QString::fromUtf8("colorLabel03"));
        colorLabel03->setStyleSheet(QString::fromUtf8(""));
        colorLabel03->setFrameShape(QFrame::StyledPanel);
        colorLabel03->setAlignment(Qt::AlignCenter);

        colorLayout->addWidget(colorLabel03, 1, 0, 1, 1);

        colorLabel05 = new QLabel(gridLayoutWidget);
        colorLabel05->setObjectName(QString::fromUtf8("colorLabel05"));
        colorLabel05->setStyleSheet(QString::fromUtf8("border:none;"));
        colorLabel05->setFrameShape(QFrame::StyledPanel);
        colorLabel05->setAlignment(Qt::AlignCenter);

        colorLayout->addWidget(colorLabel05, 2, 0, 1, 1);

        colorLabel02 = new QLabel(gridLayoutWidget);
        colorLabel02->setObjectName(QString::fromUtf8("colorLabel02"));
        colorLabel02->setStyleSheet(QString::fromUtf8("border:none;"));
        colorLabel02->setFrameShape(QFrame::StyledPanel);
        colorLabel02->setAlignment(Qt::AlignCenter);

        colorLayout->addWidget(colorLabel02, 0, 1, 1, 1);

        colorLabel04 = new QLabel(gridLayoutWidget);
        colorLabel04->setObjectName(QString::fromUtf8("colorLabel04"));
        colorLabel04->setStyleSheet(QString::fromUtf8("border:none;\n"
""));
        colorLabel04->setFrameShape(QFrame::StyledPanel);
        colorLabel04->setAlignment(Qt::AlignCenter);

        colorLayout->addWidget(colorLabel04, 1, 1, 1, 1);

        colorLabel07 = new QLabel(gridLayoutWidget);
        colorLabel07->setObjectName(QString::fromUtf8("colorLabel07"));
        colorLabel07->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"border:none;"));
        colorLabel07->setFrameShape(QFrame::StyledPanel);
        colorLabel07->setAlignment(Qt::AlignCenter);

        colorLayout->addWidget(colorLabel07, 3, 0, 1, 1);

        colorLabel06 = new QLabel(gridLayoutWidget);
        colorLabel06->setObjectName(QString::fromUtf8("colorLabel06"));
        colorLabel06->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"border:none;"));
        colorLabel06->setFrameShape(QFrame::StyledPanel);
        colorLabel06->setAlignment(Qt::AlignCenter);

        colorLayout->addWidget(colorLabel06, 2, 1, 1, 1);

        label_qualified = new QLabel(w_Test);
        label_qualified->setObjectName(QString::fromUtf8("label_qualified"));
        label_qualified->setGeometry(QRect(717, 190, 31, 100));
        label_qualified->setMaximumSize(QSize(16777215, 100));
        QFont font7;
        font7.setPointSize(8);
        label_qualified->setFont(font7);
        label_qualified->setStyleSheet(QString::fromUtf8("background-color:  lime;\n"
"color: rgb(0, 0, 0);"));
        label_qualified->setAlignment(Qt::AlignCenter);
        label_sum = new QLabel(w_Test);
        label_sum->setObjectName(QString::fromUtf8("label_sum"));
        label_sum->setGeometry(QRect(675, 190, 31, 100));
        label_sum->setMaximumSize(QSize(16777215, 100));
        label_sum->setFont(font7);
        label_sum->setStyleSheet(QString::fromUtf8("background-color:blue;\n"
"color: rgb(0, 0, 0);"));
        label_sum->setAlignment(Qt::AlignCenter);
        label_Unqualified = new QLabel(w_Test);
        label_Unqualified->setObjectName(QString::fromUtf8("label_Unqualified"));
        label_Unqualified->setGeometry(QRect(759, 189, 31, 100));
        label_Unqualified->setMaximumSize(QSize(16777215, 100));
        label_Unqualified->setFont(font7);
        label_Unqualified->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 0, 0);\n"
"color: rgb(0, 0, 0);"));
        label_Unqualified->setAlignment(Qt::AlignCenter);
        button_shape = new QToolButton(w_Test);
        button_shape->setObjectName(QString::fromUtf8("button_shape"));
        button_shape->setGeometry(QRect(675, 190, 111, 101));
        button_shape->setMinimumSize(QSize(0, 50));
        button_shape->setMaximumSize(QSize(16777215, 120));
        button_shape->setSizeIncrement(QSize(0, 50));
        button_shape->setFont(font3);
        button_shape->setStyleSheet(QString::fromUtf8("QToolButton{border:0px;}"));
        button_shape->setIconSize(QSize(16, 16));
        label_2 = new QLabel(w_Test);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(670, 130, 121, 51));
        QFont font8;
        font8.setPointSize(40);
        font8.setBold(true);
        font8.setWeight(75);
        label_2->setFont(font8);
        label_2->setStyleSheet(QString::fromUtf8(""));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/image/logo\345\211\257\346\234\254.png")));
        label_2->setAlignment(Qt::AlignCenter);
        Key_E = new QToolButton(w_Test);
        Key_E->setObjectName(QString::fromUtf8("Key_E"));
        Key_E->setEnabled(true);
        Key_E->setGeometry(QRect(670, 570, 121, 31));
        Key_E->setStyleSheet(QString::fromUtf8("QToolButton{border:0px;}"));
        Key_E->setIconSize(QSize(64, 64));
        Key_E->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        label_noise = new QLabel(w_Test);
        label_noise->setObjectName(QString::fromUtf8("label_noise"));
        label_noise->setGeometry(QRect(670, 310, 121, 111));
        label_noise->setFont(font6);
        label_noise->setStyleSheet(QString::fromUtf8("border:1px groove white;\n"
"border-radius:10px;\n"
"padding:2px 4px;\n"
"    background-color:#191919;\n"
"    border-color: #447684;\n"
""));
        label_noise->setPixmap(QPixmap(QString::fromUtf8(":/image/sound_file.ico")));
        label_noise->setScaledContents(true);
        label_noise->setAlignment(Qt::AlignCenter);
        leftLabel->raise();
        rightLabel->raise();
        label->raise();
        S1Label->raise();
        label_user->raise();
        label_number->raise();
        label_model->raise();
        label_5->raise();
        horizontalLayoutWidget->raise();
        label_B->raise();
        label_C->raise();
        label_A->raise();
        button_up->raise();
        button_down->raise();
        label_temp->raise();
        frame_state->raise();
        label_7->raise();
        S1Label_2->raise();
        testTab->raise();
        gridLayoutWidget->raise();
        button_set->raise();
        button_back->raise();
        label_qualified->raise();
        label_sum->raise();
        label_Unqualified->raise();
        button_shape->raise();
        label_2->raise();
        Key_E->raise();
        label_noise->raise();

        retranslateUi(w_Test);

        QMetaObject::connectSlotsByName(w_Test);
    } // setupUi

    void retranslateUi(QWidget *w_Test)
    {
        label_5->setText(QApplication::translate("w_Test", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:15pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:15pt; color:#0055ff;\">\351\235\222\345\262\233\350\211\276\346\231\256\346\231\272\350\203\275\344\273\252\345\231\250\346\234\211\351\231\220\345\205\254\345\217\270--\347\224\265\346\234\272\347\273\274\345\220\210\346\265\213\350\257\225\344\273\252</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        leftLabel->setText(QString());
        rightLabel->setText(QString());
        S1Label->setText(QApplication::translate("w_Test", "<html><head/><body><p><span style=\" color:#0055ff;\">00:00:00</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_user->setText(QApplication::translate("w_Test", "\346\223\215\344\275\234\345\221\230:---", 0, QApplication::UnicodeUTF8));
        label_number->setText(QApplication::translate("w_Test", "\347\274\226\345\217\267:16888", 0, QApplication::UnicodeUTF8));
        label_model->setText(QApplication::translate("w_Test", "\345\236\213\345\217\267:565879", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_A->setText(QApplication::translate("w_Test", "\346\265\213\350\257\225\351\241\271", 0, QApplication::UnicodeUTF8));
        label_B->setText(QApplication::translate("w_Test", "\346\265\213\350\257\225\351\241\271", 0, QApplication::UnicodeUTF8));
        label_C->setText(QApplication::translate("w_Test", "\346\265\213\350\257\225\351\241\271", 0, QApplication::UnicodeUTF8));
        button_up->setText(QString());
        button_down->setText(QString());
        label_temp->setText(QApplication::translate("w_Test", "\346\270\251\345\272\246:--\302\260C", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("w_Test", "OK", 0, QApplication::UnicodeUTF8));
        label_station->setText(QApplication::translate("w_Test", "<html><head/><body><p>\345\217\263</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_7->setText(QString());
        S1Label_2->setText(QApplication::translate("w_Test", "<html><head/><body><p><span style=\" color:#0055ff;\">00:00:00</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        button_set->setText(QApplication::translate("w_Test", "\345\217\202\346\225\260\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        button_back->setText(QApplication::translate("w_Test", "\345\274\200\346\234\272\344\270\273\351\241\265", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = testTab->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QApplication::translate("w_Test", "\351\241\271\347\233\256", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = testTab->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QApplication::translate("w_Test", "\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = testTab->horizontalHeaderItem(3);
        ___qtablewidgetitem2->setText(QApplication::translate("w_Test", "\347\273\223\346\236\234", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = testTab->horizontalHeaderItem(4);
        ___qtablewidgetitem3->setText(QApplication::translate("w_Test", "\345\210\244\345\256\232", 0, QApplication::UnicodeUTF8));
        colorLabel01->setText(QApplication::translate("w_Test", "1", 0, QApplication::UnicodeUTF8));
        colorLabel08->setText(QApplication::translate("w_Test", "8", 0, QApplication::UnicodeUTF8));
        colorLabel03->setText(QApplication::translate("w_Test", "3", 0, QApplication::UnicodeUTF8));
        colorLabel05->setText(QApplication::translate("w_Test", "5", 0, QApplication::UnicodeUTF8));
        colorLabel02->setText(QApplication::translate("w_Test", "2", 0, QApplication::UnicodeUTF8));
        colorLabel04->setText(QApplication::translate("w_Test", "4", 0, QApplication::UnicodeUTF8));
        colorLabel07->setText(QApplication::translate("w_Test", "7", 0, QApplication::UnicodeUTF8));
        colorLabel06->setText(QApplication::translate("w_Test", "6", 0, QApplication::UnicodeUTF8));
        label_qualified->setText(QApplication::translate("w_Test", "6666", 0, QApplication::UnicodeUTF8));
        label_sum->setText(QApplication::translate("w_Test", "888", 0, QApplication::UnicodeUTF8));
        label_Unqualified->setText(QApplication::translate("w_Test", "0", 0, QApplication::UnicodeUTF8));
        button_shape->setText(QString());
        label_2->setText(QString());
        Key_E->setText(QString());
        label_noise->setText(QString());
        Q_UNUSED(w_Test);
    } // retranslateUi

};

namespace Ui {
    class w_Test: public Ui_w_Test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_TEST_H
