/********************************************************************************
** Form generated from reading UI file 'Widget_LVS.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_LVS_H
#define UI_WIDGET_LVS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_LVS
{
public:
    QTableWidget *lvsTab;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *lable_volt;
    QDoubleSpinBox *LVS_Volt;
    QLabel *label_fre;
    QDoubleSpinBox *LVS_Fre;
    QLabel *label_channel;
    QDoubleSpinBox *LVS_channel;
    QLabel *lable_Turn;
    QComboBox *combConf_Turn;
    QPushButton *pushButton_Volt;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_4;
    QFrame *frame;
    QRadioButton *radio_Pwr;
    QRadioButton *radio_Turn;
    QLabel *label_grade_9;
    QDoubleSpinBox *LVS_grade;

    void setupUi(QWidget *Widget_LVS)
    {
        if (Widget_LVS->objectName().isEmpty())
            Widget_LVS->setObjectName(QString::fromUtf8("Widget_LVS"));
        Widget_LVS->resize(722, 600);
        lvsTab = new QTableWidget(Widget_LVS);
        if (lvsTab->columnCount() < 5)
            lvsTab->setColumnCount(5);
        QFont font;
        font.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem->setFont(font);
        lvsTab->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem1->setFont(font);
        lvsTab->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem2->setFont(font);
        lvsTab->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem3->setFont(font);
        lvsTab->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem4->setFont(font);
        lvsTab->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        lvsTab->setObjectName(QString::fromUtf8("lvsTab"));
        lvsTab->setGeometry(QRect(80, 360, 521, 61));
        lvsTab->setFocusPolicy(Qt::NoFocus);
        lvsTab->setInputMethodHints(Qt::ImhNone);
        lvsTab->setEditTriggers(QAbstractItemView::AllEditTriggers);
        lvsTab->setAlternatingRowColors(false);
        lvsTab->setSelectionMode(QAbstractItemView::SingleSelection);
        lvsTab->horizontalHeader()->setDefaultSectionSize(50);
        lvsTab->horizontalHeader()->setStretchLastSection(true);
        lvsTab->verticalHeader()->setVisible(false);
        lvsTab->verticalHeader()->setDefaultSectionSize(40);
        horizontalLayoutWidget = new QWidget(Widget_LVS);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(80, 240, 652, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lable_volt = new QLabel(horizontalLayoutWidget);
        lable_volt->setObjectName(QString::fromUtf8("lable_volt"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(91);
        sizePolicy.setVerticalStretch(41);
        sizePolicy.setHeightForWidth(lable_volt->sizePolicy().hasHeightForWidth());
        lable_volt->setSizePolicy(sizePolicy);
        lable_volt->setMinimumSize(QSize(61, 41));
        lable_volt->setMaximumSize(QSize(91, 41));
        lable_volt->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lable_volt);

        LVS_Volt = new QDoubleSpinBox(horizontalLayoutWidget);
        LVS_Volt->setObjectName(QString::fromUtf8("LVS_Volt"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(61);
        sizePolicy1.setVerticalStretch(41);
        sizePolicy1.setHeightForWidth(LVS_Volt->sizePolicy().hasHeightForWidth());
        LVS_Volt->setSizePolicy(sizePolicy1);
        LVS_Volt->setMinimumSize(QSize(61, 41));
        LVS_Volt->setMaximumSize(QSize(61, 41));
        LVS_Volt->setAlignment(Qt::AlignCenter);
        LVS_Volt->setButtonSymbols(QAbstractSpinBox::NoButtons);
        LVS_Volt->setDecimals(0);
        LVS_Volt->setMinimum(1);
        LVS_Volt->setMaximum(255);
        LVS_Volt->setSingleStep(1);
        LVS_Volt->setValue(1);

        horizontalLayout->addWidget(LVS_Volt);

        label_fre = new QLabel(horizontalLayoutWidget);
        label_fre->setObjectName(QString::fromUtf8("label_fre"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(61);
        sizePolicy2.setVerticalStretch(41);
        sizePolicy2.setHeightForWidth(label_fre->sizePolicy().hasHeightForWidth());
        label_fre->setSizePolicy(sizePolicy2);
        label_fre->setMinimumSize(QSize(51, 41));
        label_fre->setMaximumSize(QSize(51, 41));
        label_fre->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_fre);

        LVS_Fre = new QDoubleSpinBox(horizontalLayoutWidget);
        LVS_Fre->setObjectName(QString::fromUtf8("LVS_Fre"));
        LVS_Fre->setMinimumSize(QSize(61, 41));
        LVS_Fre->setMaximumSize(QSize(61, 41));
        LVS_Fre->setSizeIncrement(QSize(61, 41));
        LVS_Fre->setAlignment(Qt::AlignCenter);
        LVS_Fre->setButtonSymbols(QAbstractSpinBox::NoButtons);
        LVS_Fre->setDecimals(1);
        LVS_Fre->setMaximum(99);
        LVS_Fre->setSingleStep(0.1);
        LVS_Fre->setValue(1);

        horizontalLayout->addWidget(LVS_Fre);

        label_channel = new QLabel(horizontalLayoutWidget);
        label_channel->setObjectName(QString::fromUtf8("label_channel"));
        label_channel->setMinimumSize(QSize(51, 41));
        label_channel->setMaximumSize(QSize(51, 41));
        label_channel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_channel);

        LVS_channel = new QDoubleSpinBox(horizontalLayoutWidget);
        LVS_channel->setObjectName(QString::fromUtf8("LVS_channel"));
        LVS_channel->setMinimumSize(QSize(61, 41));
        LVS_channel->setMaximumSize(QSize(61, 41));
        LVS_channel->setAlignment(Qt::AlignCenter);
        LVS_channel->setButtonSymbols(QAbstractSpinBox::NoButtons);
        LVS_channel->setDecimals(0);
        LVS_channel->setMinimum(1);
        LVS_channel->setMaximum(3);
        LVS_channel->setSingleStep(1);
        LVS_channel->setValue(1);

        horizontalLayout->addWidget(LVS_channel);

        lable_Turn = new QLabel(horizontalLayoutWidget);
        lable_Turn->setObjectName(QString::fromUtf8("lable_Turn"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(89);
        sizePolicy3.setVerticalStretch(41);
        sizePolicy3.setHeightForWidth(lable_Turn->sizePolicy().hasHeightForWidth());
        lable_Turn->setSizePolicy(sizePolicy3);
        lable_Turn->setMinimumSize(QSize(51, 41));
        lable_Turn->setMaximumSize(QSize(51, 41));
        lable_Turn->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lable_Turn);

        combConf_Turn = new QComboBox(horizontalLayoutWidget);
        combConf_Turn->setObjectName(QString::fromUtf8("combConf_Turn"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(1);
        sizePolicy4.setHeightForWidth(combConf_Turn->sizePolicy().hasHeightForWidth());
        combConf_Turn->setSizePolicy(sizePolicy4);
        combConf_Turn->setMinimumSize(QSize(0, 41));
        combConf_Turn->setMaximumSize(QSize(101, 41));
        QFont font1;
        font1.setPointSize(18);
        combConf_Turn->setFont(font1);
        combConf_Turn->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
"\n"
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
        combConf_Turn->setFrame(true);

        horizontalLayout->addWidget(combConf_Turn);

        pushButton_Volt = new QPushButton(horizontalLayoutWidget);
        pushButton_Volt->setObjectName(QString::fromUtf8("pushButton_Volt"));
        pushButton_Volt->setMinimumSize(QSize(100, 41));
        pushButton_Volt->setMaximumSize(QSize(100, 41));

        horizontalLayout->addWidget(pushButton_Volt);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButton_4 = new QToolButton(Widget_LVS);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setGeometry(QRect(500, 40, 98, 91));
        toolButton_4->setStyleSheet(QString::fromUtf8("QToolButton{border:0px;}\n"
""));
        frame = new QFrame(Widget_LVS);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(80, 100, 181, 101));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    border: 1px solid white;\n"
"    border-color: #447684;\n"
"    color: rgb(255, 255, 255);\n"
"}\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        radio_Pwr = new QRadioButton(frame);
        radio_Pwr->setObjectName(QString::fromUtf8("radio_Pwr"));
        radio_Pwr->setGeometry(QRect(10, 10, 151, 41));
        radio_Pwr->setStyleSheet(QString::fromUtf8("QRadioButton\n"
"{\n"
"color: rgb(255, 255, 255);\n"
"}\n"
" QRadioButton::indicator {\n"
"	color: rgb(255, 255, 255);\n"
"image: url(:/image/053.png);\n"
"      width: 45px;\n"
"      height: 35px;\n"
"  }\n"
"QRadioButton::indicator:checked {\n"
"image: url(:/image/051.png)\n"
";}\");\n"
""));
        radio_Turn = new QRadioButton(frame);
        radio_Turn->setObjectName(QString::fromUtf8("radio_Turn"));
        radio_Turn->setGeometry(QRect(10, 50, 151, 41));
        radio_Turn->setStyleSheet(QString::fromUtf8("QRadioButton\n"
"{\n"
"color: rgb(255, 255, 255);\n"
"}\n"
" QRadioButton::indicator {\n"
"	color: rgb(255, 255, 255);\n"
"image: url(:/image/053.png);\n"
"      width: 45px;\n"
"      height: 35px;\n"
"  }\n"
"QRadioButton::indicator:checked {\n"
"image: url(:/image/051.png)\n"
";}\");\n"
"\n"
"\n"
""));
        label_grade_9 = new QLabel(Widget_LVS);
        label_grade_9->setObjectName(QString::fromUtf8("label_grade_9"));
        label_grade_9->setGeometry(QRect(80, 300, 91, 41));
        label_grade_9->setMinimumSize(QSize(91, 41));
        label_grade_9->setMaximumSize(QSize(91, 41));
        label_grade_9->setAlignment(Qt::AlignCenter);
        LVS_grade = new QDoubleSpinBox(Widget_LVS);
        LVS_grade->setObjectName(QString::fromUtf8("LVS_grade"));
        LVS_grade->setGeometry(QRect(180, 300, 61, 41));
        LVS_grade->setAlignment(Qt::AlignCenter);
        LVS_grade->setButtonSymbols(QAbstractSpinBox::NoButtons);
        LVS_grade->setDecimals(0);
        LVS_grade->setMinimum(1);
        LVS_grade->setMaximum(6);
        LVS_grade->setSingleStep(1);
        LVS_grade->setValue(1);
        QWidget::setTabOrder(toolButton_4, LVS_Fre);
        QWidget::setTabOrder(LVS_Fre, LVS_Volt);
        QWidget::setTabOrder(LVS_Volt, LVS_channel);

        retranslateUi(Widget_LVS);

        QMetaObject::connectSlotsByName(Widget_LVS);
    } // setupUi

    void retranslateUi(QWidget *Widget_LVS)
    {
        Widget_LVS->setWindowTitle(QApplication::translate("Widget_LVS", "Form", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = lvsTab->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget_LVS", "\347\224\265\346\265\201\344\270\213\351\231\220A", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = lvsTab->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget_LVS", "\347\224\265\346\265\201\344\270\212\351\231\220A", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = lvsTab->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget_LVS", "\345\212\237\347\216\207\344\270\213\351\231\220W", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = lvsTab->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Widget_LVS", "\345\212\237\347\216\207\344\270\212\351\231\220W", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = lvsTab->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Widget_LVS", "\346\227\266\351\227\264S", 0, QApplication::UnicodeUTF8));
        lable_volt->setText(QApplication::translate("Widget_LVS", "\345\244\226\351\203\250\347\224\265\345\216\213\357\274\232", 0, QApplication::UnicodeUTF8));
        label_fre->setText(QApplication::translate("Widget_LVS", "\351\242\221\347\216\207\357\274\232", 0, QApplication::UnicodeUTF8));
        label_channel->setText(QApplication::translate("Widget_LVS", "\351\200\232\351\201\223\357\274\232", 0, QApplication::UnicodeUTF8));
        lable_Turn->setText(QApplication::translate("Widget_LVS", "\350\275\254\345\220\221\357\274\232", 0, QApplication::UnicodeUTF8));
        combConf_Turn->clear();
        combConf_Turn->insertItems(0, QStringList()
         << QApplication::translate("Widget_LVS", "\345\217\215\350\275\254", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget_LVS", "\346\255\243\350\275\254", 0, QApplication::UnicodeUTF8)
        );
        pushButton_Volt->setText(QApplication::translate("Widget_LVS", "\350\241\245\345\201\277\347\224\265\345\216\213", 0, QApplication::UnicodeUTF8));
        toolButton_4->setText(QString());
        radio_Pwr->setText(QApplication::translate("Widget_LVS", "\345\212\237\347\216\207\345\210\244\345\256\232", 0, QApplication::UnicodeUTF8));
        radio_Turn->setText(QApplication::translate("Widget_LVS", "\350\275\254\345\220\221\345\210\244\345\256\232", 0, QApplication::UnicodeUTF8));
        label_grade_9->setText(QApplication::translate("Widget_LVS", "\346\241\243\344\275\215\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget_LVS: public Ui_Widget_LVS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_LVS_H
