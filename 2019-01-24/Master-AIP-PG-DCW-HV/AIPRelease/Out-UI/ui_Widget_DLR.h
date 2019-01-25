/********************************************************************************
** Form generated from reading UI file 'Widget_DLR.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_DLR_H
#define UI_WIDGET_DLR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_DLR
{
public:
    QLabel *label_27;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *button_autocalc;
    QLabel *label_12;
    QLabel *label_10;
    QWidget *dockWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *Key_1;
    QPushButton *Key_2;
    QPushButton *Key_3;
    QPushButton *Key_4;
    QPushButton *Key_5;
    QPushButton *Key_6;
    QPushButton *Key_7;
    QPushButton *Key_8;
    QSpacerItem *verticalSpacer;
    QLabel *label_11;
    QComboBox *Com_DLR;
    QDoubleSpinBox *Res_StandTemp;
    QDoubleSpinBox *Res_ComTemp;
    QDoubleSpinBox *Res_calculateDown;
    QDoubleSpinBox *Res_Time;
    QDoubleSpinBox *Res_calculateUp;
    QLabel *label_13;
    QLabel *label_14;
    QDoubleSpinBox *Res_Unbalance;
    QLabel *label_16;
    QTableWidget *resTab;
    QPushButton *button_model;

    void setupUi(QWidget *Widget_DLR)
    {
        if (Widget_DLR->objectName().isEmpty())
            Widget_DLR->setObjectName(QString::fromUtf8("Widget_DLR"));
        Widget_DLR->resize(721, 600);
        Widget_DLR->setFocusPolicy(Qt::NoFocus);
        label_27 = new QLabel(Widget_DLR);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(0, 470, 701, 131));
        label_27->setStyleSheet(QString::fromUtf8(""));
        label_27->setFrameShape(QFrame::Panel);
        label_8 = new QLabel(Widget_DLR);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(21, 479, 111, 31));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_8->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(Widget_DLR);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(230, 480, 111, 31));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_9->setAlignment(Qt::AlignCenter);
        button_autocalc = new QPushButton(Widget_DLR);
        button_autocalc->setObjectName(QString::fromUtf8("button_autocalc"));
        button_autocalc->setGeometry(QRect(450, 515, 111, 36));
        label_12 = new QLabel(Widget_DLR);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(230, 520, 111, 31));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_12->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(Widget_DLR);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 560, 111, 31));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_10->setAlignment(Qt::AlignCenter);
        dockWidget = new QWidget(Widget_DLR);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidget->setGeometry(QRect(150, 32, 111, 435));
        dockWidget->setMinimumSize(QSize(80, 0));
        dockWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayoutWidget = new QWidget(dockWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 10, 102, 426));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Key_1 = new QPushButton(verticalLayoutWidget);
        Key_1->setObjectName(QString::fromUtf8("Key_1"));
        Key_1->setMinimumSize(QSize(100, 47));
        Key_1->setMaximumSize(QSize(100, 47));

        verticalLayout->addWidget(Key_1);

        Key_2 = new QPushButton(verticalLayoutWidget);
        Key_2->setObjectName(QString::fromUtf8("Key_2"));
        Key_2->setMinimumSize(QSize(100, 47));
        Key_2->setMaximumSize(QSize(100, 47));

        verticalLayout->addWidget(Key_2);

        Key_3 = new QPushButton(verticalLayoutWidget);
        Key_3->setObjectName(QString::fromUtf8("Key_3"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(100);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Key_3->sizePolicy().hasHeightForWidth());
        Key_3->setSizePolicy(sizePolicy);
        Key_3->setMinimumSize(QSize(100, 47));
        Key_3->setMaximumSize(QSize(100, 47));

        verticalLayout->addWidget(Key_3);

        Key_4 = new QPushButton(verticalLayoutWidget);
        Key_4->setObjectName(QString::fromUtf8("Key_4"));
        sizePolicy.setHeightForWidth(Key_4->sizePolicy().hasHeightForWidth());
        Key_4->setSizePolicy(sizePolicy);
        Key_4->setMinimumSize(QSize(100, 47));
        Key_4->setMaximumSize(QSize(100, 47));

        verticalLayout->addWidget(Key_4);

        Key_5 = new QPushButton(verticalLayoutWidget);
        Key_5->setObjectName(QString::fromUtf8("Key_5"));
        Key_5->setMinimumSize(QSize(100, 47));
        Key_5->setMaximumSize(QSize(100, 47));

        verticalLayout->addWidget(Key_5);

        Key_6 = new QPushButton(verticalLayoutWidget);
        Key_6->setObjectName(QString::fromUtf8("Key_6"));
        Key_6->setMinimumSize(QSize(100, 47));
        Key_6->setMaximumSize(QSize(100, 47));

        verticalLayout->addWidget(Key_6);

        Key_7 = new QPushButton(verticalLayoutWidget);
        Key_7->setObjectName(QString::fromUtf8("Key_7"));
        Key_7->setMinimumSize(QSize(100, 47));
        Key_7->setMaximumSize(QSize(100, 47));

        verticalLayout->addWidget(Key_7);

        Key_8 = new QPushButton(verticalLayoutWidget);
        Key_8->setObjectName(QString::fromUtf8("Key_8"));
        Key_8->setMinimumSize(QSize(100, 47));
        Key_8->setMaximumSize(QSize(100, 47));

        verticalLayout->addWidget(Key_8);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_11 = new QLabel(Widget_DLR);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(460, 480, 91, 31));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_11->setAlignment(Qt::AlignCenter);
        Com_DLR = new QComboBox(Widget_DLR);
        Com_DLR->setObjectName(QString::fromUtf8("Com_DLR"));
        Com_DLR->setGeometry(QRect(570, 473, 81, 36));
        Com_DLR->setMinimumSize(QSize(66, 0));
        Com_DLR->setMaximumSize(QSize(200, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(18);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        Com_DLR->setFont(font);
        Com_DLR->setStyleSheet(QString::fromUtf8("\n"
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
"}"));
        Res_StandTemp = new QDoubleSpinBox(Widget_DLR);
        Res_StandTemp->setObjectName(QString::fromUtf8("Res_StandTemp"));
        Res_StandTemp->setGeometry(QRect(140, 473, 71, 36));
        Res_StandTemp->setFocusPolicy(Qt::ClickFocus);
        Res_StandTemp->setStyleSheet(QString::fromUtf8(""));
        Res_StandTemp->setInputMethodHints(Qt::ImhFormattedNumbersOnly);
        Res_StandTemp->setAlignment(Qt::AlignCenter);
        Res_StandTemp->setButtonSymbols(QAbstractSpinBox::NoButtons);
        Res_StandTemp->setDecimals(0);
        Res_ComTemp = new QDoubleSpinBox(Widget_DLR);
        Res_ComTemp->setObjectName(QString::fromUtf8("Res_ComTemp"));
        Res_ComTemp->setEnabled(true);
        Res_ComTemp->setGeometry(QRect(350, 473, 61, 36));
        Res_ComTemp->setStyleSheet(QString::fromUtf8(""));
        Res_ComTemp->setAlignment(Qt::AlignCenter);
        Res_ComTemp->setButtonSymbols(QAbstractSpinBox::NoButtons);
        Res_ComTemp->setDecimals(1);
        Res_ComTemp->setMinimum(-10);
        Res_ComTemp->setMaximum(10);
        Res_ComTemp->setSingleStep(0.1);
        Res_calculateDown = new QDoubleSpinBox(Widget_DLR);
        Res_calculateDown->setObjectName(QString::fromUtf8("Res_calculateDown"));
        Res_calculateDown->setGeometry(QRect(350, 515, 61, 36));
        Res_calculateDown->setStyleSheet(QString::fromUtf8(""));
        Res_calculateDown->setAlignment(Qt::AlignCenter);
        Res_calculateDown->setButtonSymbols(QAbstractSpinBox::NoButtons);
        Res_calculateDown->setDecimals(0);
        Res_Time = new QDoubleSpinBox(Widget_DLR);
        Res_Time->setObjectName(QString::fromUtf8("Res_Time"));
        Res_Time->setGeometry(QRect(140, 557, 71, 36));
        Res_Time->setStyleSheet(QString::fromUtf8(""));
        Res_Time->setAlignment(Qt::AlignCenter);
        Res_Time->setButtonSymbols(QAbstractSpinBox::NoButtons);
        Res_Time->setDecimals(1);
        Res_Time->setMaximum(20);
        Res_Time->setValue(0.1);
        Res_calculateUp = new QDoubleSpinBox(Widget_DLR);
        Res_calculateUp->setObjectName(QString::fromUtf8("Res_calculateUp"));
        Res_calculateUp->setGeometry(QRect(140, 515, 71, 36));
        Res_calculateUp->setStyleSheet(QString::fromUtf8(""));
        Res_calculateUp->setAlignment(Qt::AlignCenter);
        Res_calculateUp->setButtonSymbols(QAbstractSpinBox::NoButtons);
        Res_calculateUp->setDecimals(0);
        label_13 = new QLabel(Widget_DLR);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 520, 111, 31));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_13->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(Widget_DLR);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(230, 560, 121, 31));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_14->setAlignment(Qt::AlignCenter);
        Res_Unbalance = new QDoubleSpinBox(Widget_DLR);
        Res_Unbalance->setObjectName(QString::fromUtf8("Res_Unbalance"));
        Res_Unbalance->setGeometry(QRect(350, 560, 61, 36));
        Res_Unbalance->setStyleSheet(QString::fromUtf8(""));
        Res_Unbalance->setAlignment(Qt::AlignCenter);
        Res_Unbalance->setButtonSymbols(QAbstractSpinBox::NoButtons);
        Res_Unbalance->setDecimals(3);
        Res_Unbalance->setMaximum(99);
        label_16 = new QLabel(Widget_DLR);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(410, 560, 31, 31));
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_16->setAlignment(Qt::AlignCenter);
        resTab = new QTableWidget(Widget_DLR);
        if (resTab->columnCount() < 11)
            resTab->setColumnCount(11);
        QFont font1;
        font1.setPointSize(11);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        resTab->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        resTab->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        resTab->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font1);
        resTab->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font1);
        resTab->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font1);
        resTab->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font1);
        resTab->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font1);
        resTab->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font1);
        resTab->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font1);
        resTab->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font1);
        resTab->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        resTab->setObjectName(QString::fromUtf8("resTab"));
        resTab->setGeometry(QRect(0, 7, 701, 461));
        resTab->setFocusPolicy(Qt::WheelFocus);
        resTab->setInputMethodHints(Qt::ImhNone);
        resTab->setEditTriggers(QAbstractItemView::AllEditTriggers);
        resTab->setAlternatingRowColors(false);
        resTab->setSelectionMode(QAbstractItemView::SingleSelection);
        resTab->horizontalHeader()->setDefaultSectionSize(50);
        resTab->horizontalHeader()->setStretchLastSection(true);
        resTab->verticalHeader()->setVisible(false);
        resTab->verticalHeader()->setDefaultSectionSize(40);
        button_model = new QPushButton(Widget_DLR);
        button_model->setObjectName(QString::fromUtf8("button_model"));
        button_model->setGeometry(QRect(450, 560, 111, 36));
        resTab->raise();
        label_27->raise();
        label_8->raise();
        label_9->raise();
        button_autocalc->raise();
        label_12->raise();
        label_10->raise();
        label_11->raise();
        dockWidget->raise();
        Res_StandTemp->raise();
        Res_ComTemp->raise();
        Res_calculateDown->raise();
        Res_Time->raise();
        Com_DLR->raise();
        Res_calculateUp->raise();
        label_13->raise();
        label_14->raise();
        Res_Unbalance->raise();
        label_16->raise();
        button_model->raise();

        retranslateUi(Widget_DLR);

        QMetaObject::connectSlotsByName(Widget_DLR);
    } // setupUi

    void retranslateUi(QWidget *Widget_DLR)
    {
        Widget_DLR->setWindowTitle(QApplication::translate("Widget_DLR", "Form", 0, QApplication::UnicodeUTF8));
        label_27->setText(QString());
        label_8->setText(QApplication::translate("Widget_DLR", "\345\217\202\350\200\203\346\270\251\345\272\246(\302\260C)", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Widget_DLR", "\350\241\245\345\201\277\346\270\251\345\272\246(\302\260C)", 0, QApplication::UnicodeUTF8));
        button_autocalc->setText(QApplication::translate("Widget_DLR", "\350\207\252\345\212\250\350\256\241\347\256\227", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Widget_DLR", "\351\230\273\345\200\274\344\270\213\351\231\220( %)", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Widget_DLR", "\346\265\213\350\257\225\346\227\266\351\227\264(s)", 0, QApplication::UnicodeUTF8));
        Key_1->setText(QApplication::translate("Widget_DLR", "1", 0, QApplication::UnicodeUTF8));
        Key_2->setText(QApplication::translate("Widget_DLR", "2", 0, QApplication::UnicodeUTF8));
        Key_3->setText(QApplication::translate("Widget_DLR", "3", 0, QApplication::UnicodeUTF8));
        Key_4->setText(QApplication::translate("Widget_DLR", "4", 0, QApplication::UnicodeUTF8));
        Key_5->setText(QApplication::translate("Widget_DLR", "5", 0, QApplication::UnicodeUTF8));
        Key_6->setText(QApplication::translate("Widget_DLR", "6", 0, QApplication::UnicodeUTF8));
        Key_7->setText(QApplication::translate("Widget_DLR", "7", 0, QApplication::UnicodeUTF8));
        Key_8->setText(QApplication::translate("Widget_DLR", "8", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Widget_DLR", "\346\270\251\345\272\246\346\212\230\347\256\227", 0, QApplication::UnicodeUTF8));
        Com_DLR->clear();
        Com_DLR->insertItems(0, QStringList()
         << QApplication::translate("Widget_DLR", "\346\230\257", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_DLR", "\345\220\246", 0, QApplication::UnicodeUTF8)
        );
        label_13->setText(QApplication::translate("Widget_DLR", "\351\230\273\345\200\274\344\270\212\351\231\220( %)", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("Widget_DLR", "\347\224\265\351\230\273\344\270\215\345\271\263\350\241\241\345\272\246", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("Widget_DLR", "%", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = resTab->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget_DLR", "\347\224\265\351\230\273", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = resTab->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget_DLR", "\347\202\271\344\270\200", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = resTab->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget_DLR", "\347\202\271\344\272\214", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = resTab->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Widget_DLR", "\344\270\213\351\231\220", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = resTab->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Widget_DLR", "\344\270\212\351\231\220", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = resTab->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Widget_DLR", "\346\240\207\345\207\206\347\224\265\351\230\273", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = resTab->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Widget_DLR", "\345\215\225\344\275\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = resTab->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("Widget_DLR", "\346\235\220\346\226\231", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = resTab->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("Widget_DLR", "\345\267\246\350\241\245\345\201\277", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = resTab->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("Widget_DLR", "\345\217\263\350\241\245\345\201\277", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = resTab->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("Widget_DLR", "\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        button_model->setText(QApplication::translate("Widget_DLR", "\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget_DLR: public Ui_Widget_DLR {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_DLR_H
