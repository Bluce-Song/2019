/********************************************************************************
** Form generated from reading UI file 'Widget_BLOCK.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_BLOCK_H
#define UI_WIDGET_BLOCK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_BLOCK
{
public:
    QDoubleSpinBox *DZ_time;
    QLabel *label_current;
    QDoubleSpinBox *DZ_grade;
    QPushButton *pushButton_3;
    QLabel *label_cycle;
    QPushButton *pushButton_2;
    QLabel *label_pwr;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *waveLayout;
    QPushButton *pushButton;
    QTableWidget *dzTab;
    QLabel *label_grade_9;
    QLabel *label_grade_10;
    QToolButton *toolButton_4;
    QTextEdit *textEdit;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_volt;
    QDoubleSpinBox *BLOCK_Volt;
    QLabel *label_fre;
    QDoubleSpinBox *BLOCK_Fre;
    QLabel *label_channel;
    QDoubleSpinBox *BLOCK_channel;
    QPushButton *pushButton_Volt;
    QSpacerItem *horizontalSpacer;
    QLabel *label_hide;
    QDoubleSpinBox *DZ_Cycle;

    void setupUi(QWidget *Widget_BLOCK)
    {
        if (Widget_BLOCK->objectName().isEmpty())
            Widget_BLOCK->setObjectName(QString::fromUtf8("Widget_BLOCK"));
        Widget_BLOCK->resize(711, 600);
        DZ_time = new QDoubleSpinBox(Widget_BLOCK);
        DZ_time->setObjectName(QString::fromUtf8("DZ_time"));
        DZ_time->setGeometry(QRect(210, 60, 61, 41));
        DZ_time->setAlignment(Qt::AlignCenter);
        DZ_time->setButtonSymbols(QAbstractSpinBox::NoButtons);
        DZ_time->setDecimals(0);
        DZ_time->setMinimum(10);
        DZ_time->setMaximum(2000);
        DZ_time->setSingleStep(1);
        DZ_time->setValue(10);
        label_current = new QLabel(Widget_BLOCK);
        label_current->setObjectName(QString::fromUtf8("label_current"));
        label_current->setGeometry(QRect(300, 320, 131, 41));
        label_current->setAlignment(Qt::AlignCenter);
        DZ_grade = new QDoubleSpinBox(Widget_BLOCK);
        DZ_grade->setObjectName(QString::fromUtf8("DZ_grade"));
        DZ_grade->setGeometry(QRect(360, 60, 61, 41));
        DZ_grade->setAlignment(Qt::AlignCenter);
        DZ_grade->setButtonSymbols(QAbstractSpinBox::NoButtons);
        DZ_grade->setDecimals(0);
        DZ_grade->setMinimum(1);
        DZ_grade->setMaximum(6);
        DZ_grade->setSingleStep(1);
        DZ_grade->setValue(1);
        pushButton_3 = new QPushButton(Widget_BLOCK);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(460, 260, 141, 51));
        label_cycle = new QLabel(Widget_BLOCK);
        label_cycle->setObjectName(QString::fromUtf8("label_cycle"));
        label_cycle->setGeometry(QRect(130, 320, 51, 41));
        label_cycle->setAlignment(Qt::AlignCenter);
        pushButton_2 = new QPushButton(Widget_BLOCK);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 260, 141, 51));
        label_pwr = new QLabel(Widget_BLOCK);
        label_pwr->setObjectName(QString::fromUtf8("label_pwr"));
        label_pwr->setGeometry(QRect(470, 320, 111, 41));
        label_pwr->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(Widget_BLOCK);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(120, 370, 431, 201));
        waveLayout = new QHBoxLayout(horizontalLayoutWidget);
        waveLayout->setSpacing(0);
        waveLayout->setObjectName(QString::fromUtf8("waveLayout"));
        waveLayout->setSizeConstraint(QLayout::SetMinimumSize);
        waveLayout->setContentsMargins(6, 0, 5, 0);
        pushButton = new QPushButton(Widget_BLOCK);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 260, 141, 51));
        dzTab = new QTableWidget(Widget_BLOCK);
        if (dzTab->columnCount() < 4)
            dzTab->setColumnCount(4);
        QFont font;
        font.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem->setFont(font);
        dzTab->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem1->setFont(font);
        dzTab->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem2->setFont(font);
        dzTab->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem3->setFont(font);
        dzTab->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        dzTab->setObjectName(QString::fromUtf8("dzTab"));
        dzTab->setGeometry(QRect(110, 110, 491, 107));
        dzTab->setFocusPolicy(Qt::NoFocus);
        dzTab->setInputMethodHints(Qt::ImhNone);
        dzTab->setEditTriggers(QAbstractItemView::AllEditTriggers);
        dzTab->setAlternatingRowColors(false);
        dzTab->setSelectionMode(QAbstractItemView::SingleSelection);
        dzTab->horizontalHeader()->setDefaultSectionSize(50);
        dzTab->horizontalHeader()->setStretchLastSection(true);
        dzTab->verticalHeader()->setVisible(false);
        dzTab->verticalHeader()->setDefaultSectionSize(40);
        label_grade_9 = new QLabel(Widget_BLOCK);
        label_grade_9->setObjectName(QString::fromUtf8("label_grade_9"));
        label_grade_9->setGeometry(QRect(290, 60, 71, 41));
        QFont font1;
        font1.setPointSize(10);
        label_grade_9->setFont(font1);
        label_grade_9->setAlignment(Qt::AlignCenter);
        label_grade_10 = new QLabel(Widget_BLOCK);
        label_grade_10->setObjectName(QString::fromUtf8("label_grade_10"));
        label_grade_10->setGeometry(QRect(110, 60, 91, 41));
        label_grade_10->setFont(font1);
        label_grade_10->setAlignment(Qt::AlignCenter);
        toolButton_4 = new QToolButton(Widget_BLOCK);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setGeometry(QRect(0, 240, 98, 91));
        toolButton_4->setStyleSheet(QString::fromUtf8("QToolButton{border:0px;}\n"
""));
        textEdit = new QTextEdit(Widget_BLOCK);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(570, 370, 130, 201));
        horizontalLayoutWidget_2 = new QWidget(Widget_BLOCK);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(110, 0, 589, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_volt = new QLabel(horizontalLayoutWidget_2);
        label_volt->setObjectName(QString::fromUtf8("label_volt"));
        label_volt->setMinimumSize(QSize(91, 41));
        label_volt->setMaximumSize(QSize(91, 41));
        label_volt->setFont(font1);
        label_volt->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_volt);

        BLOCK_Volt = new QDoubleSpinBox(horizontalLayoutWidget_2);
        BLOCK_Volt->setObjectName(QString::fromUtf8("BLOCK_Volt"));
        BLOCK_Volt->setMinimumSize(QSize(61, 41));
        BLOCK_Volt->setMaximumSize(QSize(61, 41));
        BLOCK_Volt->setAlignment(Qt::AlignCenter);
        BLOCK_Volt->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BLOCK_Volt->setDecimals(0);
        BLOCK_Volt->setMinimum(1);
        BLOCK_Volt->setMaximum(255);
        BLOCK_Volt->setSingleStep(1);
        BLOCK_Volt->setValue(1);

        horizontalLayout->addWidget(BLOCK_Volt);

        label_fre = new QLabel(horizontalLayoutWidget_2);
        label_fre->setObjectName(QString::fromUtf8("label_fre"));
        label_fre->setMinimumSize(QSize(81, 41));
        label_fre->setMaximumSize(QSize(81, 41));
        label_fre->setFont(font1);
        label_fre->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_fre);

        BLOCK_Fre = new QDoubleSpinBox(horizontalLayoutWidget_2);
        BLOCK_Fre->setObjectName(QString::fromUtf8("BLOCK_Fre"));
        BLOCK_Fre->setMinimumSize(QSize(61, 41));
        BLOCK_Fre->setMaximumSize(QSize(61, 41));
        BLOCK_Fre->setAlignment(Qt::AlignCenter);
        BLOCK_Fre->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BLOCK_Fre->setDecimals(1);
        BLOCK_Fre->setMaximum(99);
        BLOCK_Fre->setSingleStep(0.1);
        BLOCK_Fre->setValue(1);

        horizontalLayout->addWidget(BLOCK_Fre);

        label_channel = new QLabel(horizontalLayoutWidget_2);
        label_channel->setObjectName(QString::fromUtf8("label_channel"));
        label_channel->setMinimumSize(QSize(71, 41));
        label_channel->setMaximumSize(QSize(101, 41));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        label_channel->setFont(font2);
        label_channel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_channel);

        BLOCK_channel = new QDoubleSpinBox(horizontalLayoutWidget_2);
        BLOCK_channel->setObjectName(QString::fromUtf8("BLOCK_channel"));
        BLOCK_channel->setMinimumSize(QSize(80, 41));
        BLOCK_channel->setMaximumSize(QSize(90, 41));
        BLOCK_channel->setAlignment(Qt::AlignCenter);
        BLOCK_channel->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BLOCK_channel->setDecimals(0);
        BLOCK_channel->setMinimum(1);
        BLOCK_channel->setMaximum(3);
        BLOCK_channel->setSingleStep(1);
        BLOCK_channel->setValue(1);

        horizontalLayout->addWidget(BLOCK_channel);

        pushButton_Volt = new QPushButton(horizontalLayoutWidget_2);
        pushButton_Volt->setObjectName(QString::fromUtf8("pushButton_Volt"));
        pushButton_Volt->setMinimumSize(QSize(100, 41));
        pushButton_Volt->setMaximumSize(QSize(100, 41));

        horizontalLayout->addWidget(pushButton_Volt);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_hide = new QLabel(Widget_BLOCK);
        label_hide->setObjectName(QString::fromUtf8("label_hide"));
        label_hide->setGeometry(QRect(90, 360, 621, 231));
        DZ_Cycle = new QDoubleSpinBox(Widget_BLOCK);
        DZ_Cycle->setObjectName(QString::fromUtf8("DZ_Cycle"));
        DZ_Cycle->setGeometry(QRect(190, 320, 61, 41));
        DZ_Cycle->setAlignment(Qt::AlignCenter);
        DZ_Cycle->setButtonSymbols(QAbstractSpinBox::NoButtons);
        DZ_Cycle->setDecimals(0);
        DZ_Cycle->setMinimum(0);
        DZ_Cycle->setMaximum(200);
        DZ_Cycle->setSingleStep(1);
        DZ_Cycle->setValue(3);
        QWidget::setTabOrder(pushButton_3, pushButton_2);
        QWidget::setTabOrder(pushButton_2, BLOCK_Volt);
        QWidget::setTabOrder(BLOCK_Volt, DZ_time);
        QWidget::setTabOrder(DZ_time, DZ_grade);
        QWidget::setTabOrder(DZ_grade, pushButton);
        QWidget::setTabOrder(pushButton, BLOCK_Fre);

        retranslateUi(Widget_BLOCK);

        QMetaObject::connectSlotsByName(Widget_BLOCK);
    } // setupUi

    void retranslateUi(QWidget *Widget_BLOCK)
    {
        Widget_BLOCK->setWindowTitle(QApplication::translate("Widget_BLOCK", "Form", 0, QApplication::UnicodeUTF8));
        label_current->setText(QApplication::translate("Widget_BLOCK", "\347\224\265\346\265\201:", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Widget_BLOCK", "\351\207\207\351\233\206\345\256\214\346\210\220", 0, QApplication::UnicodeUTF8));
        label_cycle->setText(QApplication::translate("Widget_BLOCK", "\345\221\250\346\234\237:", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Widget_BLOCK", "\346\233\264\346\215\242\347\224\265\346\234\272", 0, QApplication::UnicodeUTF8));
        label_pwr->setText(QApplication::translate("Widget_BLOCK", "\345\212\237\347\216\207:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Widget_BLOCK", "\351\207\207\351\233\206", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = dzTab->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QApplication::translate("Widget_BLOCK", "\347\224\265\345\216\213", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = dzTab->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget_BLOCK", "\347\224\265\346\265\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = dzTab->horizontalHeaderItem(3);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget_BLOCK", "\345\212\237\347\216\207", 0, QApplication::UnicodeUTF8));
        label_grade_9->setText(QApplication::translate("Widget_BLOCK", "\346\241\243\344\275\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_grade_10->setText(QApplication::translate("Widget_BLOCK", "\346\227\266\351\227\264(ms)\357\274\232", 0, QApplication::UnicodeUTF8));
        toolButton_4->setText(QString());
        label_volt->setText(QApplication::translate("Widget_BLOCK", "\345\244\226\351\203\250\347\224\265\345\216\213(V)\357\274\232", 0, QApplication::UnicodeUTF8));
        label_fre->setText(QApplication::translate("Widget_BLOCK", "\351\242\221\347\216\207(Hz)\357\274\232", 0, QApplication::UnicodeUTF8));
        label_channel->setText(QApplication::translate("Widget_BLOCK", "\351\200\232\351\201\223\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton_Volt->setText(QApplication::translate("Widget_BLOCK", "\350\241\245\345\201\277\347\224\265\345\216\213", 0, QApplication::UnicodeUTF8));
        label_hide->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget_BLOCK: public Ui_Widget_BLOCK {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_BLOCK_H
