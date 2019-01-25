/********************************************************************************
** Form generated from reading UI file 'Widget_IMP.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_IMP_H
#define UI_WIDGET_IMP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_IMP
{
public:
    QTableWidget *ittTab;
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
    QWidget *dockWidget_2;
    QPushButton *button_back;
    QDoubleSpinBox *doubleSpinBox_green;
    QDoubleSpinBox *doubleSpinBox_red;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *wate;
    QLabel *label;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_sample_collect;
    QPushButton *button_sample_cancle;
    QPushButton *button_sample_average;
    QSpacerItem *horizontalSpacer;
    QComboBox *comb_Station;
    QPushButton *pushButton;

    void setupUi(QWidget *Widget_IMP)
    {
        if (Widget_IMP->objectName().isEmpty())
            Widget_IMP->setObjectName(QString::fromUtf8("Widget_IMP"));
        Widget_IMP->resize(721, 600);
        ittTab = new QTableWidget(Widget_IMP);
        if (ittTab->columnCount() < 13)
            ittTab->setColumnCount(13);
        QFont font;
        font.setPointSize(11);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        ittTab->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        ittTab->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        ittTab->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        ittTab->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        ittTab->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        ittTab->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        ittTab->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font);
        ittTab->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font);
        ittTab->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        ittTab->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font);
        ittTab->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        ittTab->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font);
        ittTab->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        ittTab->setObjectName(QString::fromUtf8("ittTab"));
        ittTab->setGeometry(QRect(0, 7, 701, 550));
        ittTab->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ittTab->setEditTriggers(QAbstractItemView::AllEditTriggers);
        ittTab->setDragDropOverwriteMode(false);
        ittTab->setSelectionMode(QAbstractItemView::SingleSelection);
        ittTab->horizontalHeader()->setDefaultSectionSize(50);
        ittTab->horizontalHeader()->setStretchLastSection(true);
        ittTab->verticalHeader()->setVisible(false);
        ittTab->verticalHeader()->setDefaultSectionSize(64);
        ittTab->verticalHeader()->setMinimumSectionSize(40);
        dockWidget = new QWidget(Widget_IMP);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidget->setGeometry(QRect(150, 30, 101, 525));
        dockWidget->setMinimumSize(QSize(80, 0));
        verticalLayoutWidget = new QWidget(dockWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 10, 91, 498));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Key_1 = new QPushButton(verticalLayoutWidget);
        Key_1->setObjectName(QString::fromUtf8("Key_1"));
        Key_1->setMinimumSize(QSize(85, 56));
        Key_1->setMaximumSize(QSize(85, 56));

        verticalLayout->addWidget(Key_1);

        Key_2 = new QPushButton(verticalLayoutWidget);
        Key_2->setObjectName(QString::fromUtf8("Key_2"));
        Key_2->setMinimumSize(QSize(85, 56));
        Key_2->setMaximumSize(QSize(85, 56));

        verticalLayout->addWidget(Key_2);

        Key_3 = new QPushButton(verticalLayoutWidget);
        Key_3->setObjectName(QString::fromUtf8("Key_3"));
        Key_3->setMinimumSize(QSize(85, 56));
        Key_3->setMaximumSize(QSize(85, 56));

        verticalLayout->addWidget(Key_3);

        Key_4 = new QPushButton(verticalLayoutWidget);
        Key_4->setObjectName(QString::fromUtf8("Key_4"));
        Key_4->setMinimumSize(QSize(85, 56));
        Key_4->setMaximumSize(QSize(85, 56));

        verticalLayout->addWidget(Key_4);

        Key_5 = new QPushButton(verticalLayoutWidget);
        Key_5->setObjectName(QString::fromUtf8("Key_5"));
        Key_5->setMinimumSize(QSize(85, 56));
        Key_5->setMaximumSize(QSize(85, 56));

        verticalLayout->addWidget(Key_5);

        Key_6 = new QPushButton(verticalLayoutWidget);
        Key_6->setObjectName(QString::fromUtf8("Key_6"));
        Key_6->setMinimumSize(QSize(85, 56));
        Key_6->setMaximumSize(QSize(85, 56));

        verticalLayout->addWidget(Key_6);

        Key_7 = new QPushButton(verticalLayoutWidget);
        Key_7->setObjectName(QString::fromUtf8("Key_7"));
        Key_7->setMinimumSize(QSize(85, 56));
        Key_7->setMaximumSize(QSize(85, 56));

        verticalLayout->addWidget(Key_7);

        Key_8 = new QPushButton(verticalLayoutWidget);
        Key_8->setObjectName(QString::fromUtf8("Key_8"));
        Key_8->setMinimumSize(QSize(85, 56));
        Key_8->setMaximumSize(QSize(85, 56));

        verticalLayout->addWidget(Key_8);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        dockWidget_2 = new QWidget(Widget_IMP);
        dockWidget_2->setObjectName(QString::fromUtf8("dockWidget_2"));
        dockWidget_2->setGeometry(QRect(0, 7, 701, 551));
        dockWidget_2->setMinimumSize(QSize(80, 0));
        dockWidget_2->setStyleSheet(QString::fromUtf8("QWidget#dockWidget_2{background-color: #191919;}"));
        button_back = new QPushButton(dockWidget_2);
        button_back->setObjectName(QString::fromUtf8("button_back"));
        button_back->setGeometry(QRect(20, 20, 91, 41));
        doubleSpinBox_green = new QDoubleSpinBox(dockWidget_2);
        doubleSpinBox_green->setObjectName(QString::fromUtf8("doubleSpinBox_green"));
        doubleSpinBox_green->setGeometry(QRect(490, 20, 61, 41));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(doubleSpinBox_green->sizePolicy().hasHeightForWidth());
        doubleSpinBox_green->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(13);
        doubleSpinBox_green->setFont(font1);
        doubleSpinBox_green->setStyleSheet(QString::fromUtf8("color: rgb(214, 0, 0);"));
        doubleSpinBox_green->setAlignment(Qt::AlignCenter);
        doubleSpinBox_green->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_green->setDecimals(0);
        doubleSpinBox_green->setMinimum(345);
        doubleSpinBox_green->setMaximum(631);
        doubleSpinBox_red = new QDoubleSpinBox(dockWidget_2);
        doubleSpinBox_red->setObjectName(QString::fromUtf8("doubleSpinBox_red"));
        doubleSpinBox_red->setGeometry(QRect(160, 20, 61, 41));
        sizePolicy.setHeightForWidth(doubleSpinBox_red->sizePolicy().hasHeightForWidth());
        doubleSpinBox_red->setSizePolicy(sizePolicy);
        doubleSpinBox_red->setFont(font1);
        doubleSpinBox_red->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));
        doubleSpinBox_red->setAlignment(Qt::AlignCenter);
        doubleSpinBox_red->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_red->setDecimals(0);
        doubleSpinBox_red->setMinimum(20);
        doubleSpinBox_red->setMaximum(305);
        pushButton_4 = new QPushButton(dockWidget_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(230, 20, 98, 41));
        pushButton_5 = new QPushButton(dockWidget_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(370, 20, 98, 41));
        horizontalLayoutWidget = new QWidget(dockWidget_2);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(19, 89, 651, 451));
        wate = new QHBoxLayout(horizontalLayoutWidget);
        wate->setSpacing(0);
        wate->setObjectName(QString::fromUtf8("wate"));
        wate->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(Widget_IMP);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(450, 560, 241, 41));
        QFont font2;
        font2.setPointSize(12);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        horizontalLayoutWidget_2 = new QWidget(Widget_IMP);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(560, 560, 151, 42));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout->setSpacing(8);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        button_sample_collect = new QPushButton(horizontalLayoutWidget_2);
        button_sample_collect->setObjectName(QString::fromUtf8("button_sample_collect"));
        button_sample_collect->setMinimumSize(QSize(30, 36));
        button_sample_collect->setMaximumSize(QSize(30, 36));

        horizontalLayout->addWidget(button_sample_collect);

        button_sample_cancle = new QPushButton(horizontalLayoutWidget_2);
        button_sample_cancle->setObjectName(QString::fromUtf8("button_sample_cancle"));
        button_sample_cancle->setMinimumSize(QSize(30, 36));
        button_sample_cancle->setMaximumSize(QSize(30, 36));

        horizontalLayout->addWidget(button_sample_cancle);

        button_sample_average = new QPushButton(horizontalLayoutWidget_2);
        button_sample_average->setObjectName(QString::fromUtf8("button_sample_average"));
        button_sample_average->setMinimumSize(QSize(30, 36));
        button_sample_average->setMaximumSize(QSize(30, 36));

        horizontalLayout->addWidget(button_sample_average);

        horizontalSpacer = new QSpacerItem(2, 2, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        comb_Station = new QComboBox(Widget_IMP);
        comb_Station->setObjectName(QString::fromUtf8("comb_Station"));
        comb_Station->setGeometry(QRect(0, 560, 120, 40));
        comb_Station->setMinimumSize(QSize(120, 40));
        comb_Station->setMaximumSize(QSize(120, 40));
        QFont font3;
        font3.setPointSize(15);
        comb_Station->setFont(font3);
        comb_Station->setStyleSheet(QString::fromUtf8("\n"
"QComboBox {\n"
"\n"
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
        pushButton = new QPushButton(Widget_IMP);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 560, 101, 41));

        retranslateUi(Widget_IMP);

        QMetaObject::connectSlotsByName(Widget_IMP);
    } // setupUi

    void retranslateUi(QWidget *Widget_IMP)
    {
        Widget_IMP->setWindowTitle(QApplication::translate("Widget_IMP", "Form", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = ittTab->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget_IMP", "\345\214\235\351\227\264", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = ittTab->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget_IMP", "\347\253\257\344\270\200", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = ittTab->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget_IMP", "\347\253\257\344\272\214", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = ittTab->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Widget_IMP", "\347\224\265\345\216\213", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = ittTab->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Widget_IMP", "\346\254\241\346\225\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = ittTab->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Widget_IMP", "\351\235\242\347\247\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = ittTab->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Widget_IMP", "\345\267\256\347\247\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = ittTab->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("Widget_IMP", "\347\224\265\346\231\225", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = ittTab->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("Widget_IMP", "\347\233\270\344\275\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = ittTab->horizontalHeaderItem(10);
        ___qtablewidgetitem9->setText(QApplication::translate("Widget_IMP", "\346\263\242\345\275\242", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = ittTab->horizontalHeaderItem(12);
        ___qtablewidgetitem10->setText(QApplication::translate("Widget_IMP", "\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        Key_1->setText(QApplication::translate("Widget_IMP", "1", 0, QApplication::UnicodeUTF8));
        Key_2->setText(QApplication::translate("Widget_IMP", "2", 0, QApplication::UnicodeUTF8));
        Key_3->setText(QApplication::translate("Widget_IMP", "3", 0, QApplication::UnicodeUTF8));
        Key_4->setText(QApplication::translate("Widget_IMP", "4", 0, QApplication::UnicodeUTF8));
        Key_5->setText(QApplication::translate("Widget_IMP", "5", 0, QApplication::UnicodeUTF8));
        Key_6->setText(QApplication::translate("Widget_IMP", "6", 0, QApplication::UnicodeUTF8));
        Key_7->setText(QApplication::translate("Widget_IMP", "7", 0, QApplication::UnicodeUTF8));
        Key_8->setText(QApplication::translate("Widget_IMP", "8", 0, QApplication::UnicodeUTF8));
        button_back->setText(QApplication::translate("Widget_IMP", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("Widget_IMP", "<", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("Widget_IMP", ">", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        button_sample_collect->setText(QApplication::translate("Widget_IMP", "\351\207\207\351\233\206", 0, QApplication::UnicodeUTF8));
        button_sample_cancle->setText(QApplication::translate("Widget_IMP", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        button_sample_average->setText(QApplication::translate("Widget_IMP", "\345\271\263\345\235\207\350\256\241\347\256\227-\344\277\235\345\255\230\346\240\267\345\223\201", 0, QApplication::UnicodeUTF8));
        comb_Station->clear();
        comb_Station->insertItems(0, QStringList()
         << QApplication::translate("Widget_IMP", "\345\267\246\345\267\245\344\275\215", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_IMP", "\345\217\263\345\267\245\344\275\215", 0, QApplication::UnicodeUTF8)
         << QString()
        );
        pushButton->setText(QApplication::translate("Widget_IMP", "\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget_IMP: public Ui_Widget_IMP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_IMP_H
