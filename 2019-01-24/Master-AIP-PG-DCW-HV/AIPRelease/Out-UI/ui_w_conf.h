/********************************************************************************
** Form generated from reading UI file 'w_conf.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_CONF_H
#define UI_W_CONF_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_w_Conf
{
public:
    QLabel *label_31;
    QLabel *label_User;
    QLabel *label;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QPushButton *Key_E;
    QPushButton *Key_C;
    QPushButton *Key_B;
    QSpacerItem *verticalSpacer;
    QPushButton *Button_ALL;
    QPushButton *Key_D;
    QPushButton *Key_A;
    QStackedWidget *stackedWidget;
    QWidget *W_All;
    QLabel *label_37;
    QLabel *Label_Picture;
    QWidget *gridLayoutWidget_6;
    QGridLayout *colrLayout;
    QLabel *DLabel05_4;
    QLabel *T003Label;
    QLabel *T002Label;
    QTableWidget *fileTab;
    QLabel *TLabel08;
    QPushButton *fileBtnCheck;
    QPushButton *fileBtnAdd;
    QLineEdit *fileEdit1;
    QLabel *label_Text;
    QPushButton *fileBtnDel;
    QTableWidget *test;
    QComboBox *combConf1;
    QLineEdit *file_number;
    QLabel *label_36;
    QLabel *label_35;
    QComboBox *MotorType;
    QLabel *label_34;
    QLabel *label_38;
    QPushButton *SQL_Task;
    QPushButton *Button_DLR;
    QPushButton *Button_MAG;
    QPushButton *Button_IR;
    QPushButton *Button_DCW;
    QPushButton *Button_ACW;
    QPushButton *Button_IMP;
    QPushButton *imp_button_add;
    QPushButton *imp_button_cancel;
    QPushButton *imp_button_finsh;
    QPushButton *Button_PWR;
    QPushButton *Button_INDL;
    QPushButton *Button_BLOCK;
    QPushButton *Button_LVS;
    QPushButton *Button_Hall;
    QPushButton *Button_Load;
    QPushButton *Button_NoLoad;
    QPushButton *Button_BEMF;
    QPushButton *Button_HV;

    void setupUi(QWidget *w_Conf)
    {
        if (w_Conf->objectName().isEmpty())
            w_Conf->setObjectName(QString::fromUtf8("w_Conf"));
        w_Conf->resize(800, 600);
        label_31 = new QLabel(w_Conf);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(320, 760, 601, 91));
        label_31->setFrameShape(QFrame::Panel);
        label_User = new QLabel(w_Conf);
        label_User->setObjectName(QString::fromUtf8("label_User"));
        label_User->setGeometry(QRect(299, 0, 401, 600));
        label = new QLabel(w_Conf);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(812, 230, 16, 17));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        layoutWidget = new QWidget(w_Conf);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(710, 10, 87, 351));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        Key_E = new QPushButton(layoutWidget);
        Key_E->setObjectName(QString::fromUtf8("Key_E"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Key_E->sizePolicy().hasHeightForWidth());
        Key_E->setSizePolicy(sizePolicy);
        Key_E->setMinimumSize(QSize(0, 50));
        Key_E->setMaximumSize(QSize(16777215, 50));
        Key_E->setStyleSheet(QString::fromUtf8("QToolButton{border:0px;}"));
        Key_E->setIconSize(QSize(64, 64));

        gridLayout_2->addWidget(Key_E, 6, 0, 1, 1);

        Key_C = new QPushButton(layoutWidget);
        Key_C->setObjectName(QString::fromUtf8("Key_C"));
        sizePolicy.setHeightForWidth(Key_C->sizePolicy().hasHeightForWidth());
        Key_C->setSizePolicy(sizePolicy);
        Key_C->setMinimumSize(QSize(0, 50));
        Key_C->setMaximumSize(QSize(16777215, 50));
        Key_C->setStyleSheet(QString::fromUtf8("QToolButton{border:0px;}"));
        Key_C->setIconSize(QSize(64, 64));

        gridLayout_2->addWidget(Key_C, 4, 0, 1, 1);

        Key_B = new QPushButton(layoutWidget);
        Key_B->setObjectName(QString::fromUtf8("Key_B"));
        sizePolicy.setHeightForWidth(Key_B->sizePolicy().hasHeightForWidth());
        Key_B->setSizePolicy(sizePolicy);
        Key_B->setMinimumSize(QSize(0, 50));
        Key_B->setMaximumSize(QSize(16777215, 50));
        Key_B->setStyleSheet(QString::fromUtf8("QToolButton{border:0px;}"));
        Key_B->setIconSize(QSize(64, 64));

        gridLayout_2->addWidget(Key_B, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 7, 0, 1, 1);

        Button_ALL = new QPushButton(layoutWidget);
        Button_ALL->setObjectName(QString::fromUtf8("Button_ALL"));
        sizePolicy.setHeightForWidth(Button_ALL->sizePolicy().hasHeightForWidth());
        Button_ALL->setSizePolicy(sizePolicy);
        Button_ALL->setMinimumSize(QSize(0, 45));
        Button_ALL->setMaximumSize(QSize(16777215, 48));

        gridLayout_2->addWidget(Button_ALL, 3, 0, 1, 1);

        Key_D = new QPushButton(layoutWidget);
        Key_D->setObjectName(QString::fromUtf8("Key_D"));
        sizePolicy.setHeightForWidth(Key_D->sizePolicy().hasHeightForWidth());
        Key_D->setSizePolicy(sizePolicy);
        Key_D->setMinimumSize(QSize(0, 50));
        Key_D->setMaximumSize(QSize(16777215, 50));
        Key_D->setStyleSheet(QString::fromUtf8("QToolButton{border:0px;}"));
        Key_D->setIconSize(QSize(64, 64));

        gridLayout_2->addWidget(Key_D, 5, 0, 1, 1);

        Key_A = new QPushButton(layoutWidget);
        Key_A->setObjectName(QString::fromUtf8("Key_A"));
        sizePolicy.setHeightForWidth(Key_A->sizePolicy().hasHeightForWidth());
        Key_A->setSizePolicy(sizePolicy);
        Key_A->setMinimumSize(QSize(0, 50));
        Key_A->setMaximumSize(QSize(16777215, 50));
        Key_A->setSizeIncrement(QSize(0, 38));
        Key_A->setStyleSheet(QString::fromUtf8(""));
        Key_A->setIconSize(QSize(64, 64));

        gridLayout_2->addWidget(Key_A, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(w_Conf);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 700, 600));
        W_All = new QWidget();
        W_All->setObjectName(QString::fromUtf8("W_All"));
        label_37 = new QLabel(W_All);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(460, 390, 171, 31));
        label_37->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        Label_Picture = new QLabel(W_All);
        Label_Picture->setObjectName(QString::fromUtf8("Label_Picture"));
        Label_Picture->setGeometry(QRect(460, 260, 231, 161));
        Label_Picture->setStyleSheet(QString::fromUtf8("border:2px groove gray;\n"
""));
        Label_Picture->setFrameShape(QFrame::WinPanel);
        Label_Picture->setPixmap(QPixmap(QString::fromUtf8(":/new/M1S1.jpg")));
        Label_Picture->setScaledContents(true);
        Label_Picture->setAlignment(Qt::AlignCenter);
        gridLayoutWidget_6 = new QWidget(W_All);
        gridLayoutWidget_6->setObjectName(QString::fromUtf8("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(460, 440, 231, 151));
        colrLayout = new QGridLayout(gridLayoutWidget_6);
        colrLayout->setObjectName(QString::fromUtf8("colrLayout"));
        colrLayout->setContentsMargins(0, 0, 0, 0);
        DLabel05_4 = new QLabel(W_All);
        DLabel05_4->setObjectName(QString::fromUtf8("DLabel05_4"));
        DLabel05_4->setGeometry(QRect(470, 400, 221, 171));
        DLabel05_4->setStyleSheet(QString::fromUtf8("border:2px groove none ;\n"
"border:none;\n"
"border-radius:12px;"));
        DLabel05_4->setFrameShape(QFrame::WinPanel);
        DLabel05_4->setPixmap(QPixmap(QString::fromUtf8(":/new/M1S1.jpg")));
        DLabel05_4->setScaledContents(true);
        DLabel05_4->setAlignment(Qt::AlignCenter);
        T003Label = new QLabel(W_All);
        T003Label->setObjectName(QString::fromUtf8("T003Label"));
        T003Label->setGeometry(QRect(300, 10, 141, 591));
        T003Label->setFrameShape(QFrame::StyledPanel);
        T003Label->setAlignment(Qt::AlignCenter);
        T002Label = new QLabel(W_All);
        T002Label->setObjectName(QString::fromUtf8("T002Label"));
        T002Label->setGeometry(QRect(0, 10, 291, 591));
        T002Label->setFrameShape(QFrame::StyledPanel);
        T002Label->setAlignment(Qt::AlignCenter);
        fileTab = new QTableWidget(W_All);
        if (fileTab->columnCount() < 1)
            fileTab->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        fileTab->setHorizontalHeaderItem(0, __qtablewidgetitem);
        fileTab->setObjectName(QString::fromUtf8("fileTab"));
        fileTab->setGeometry(QRect(10, 20, 270, 377));
        fileTab->setFocusPolicy(Qt::NoFocus);
        fileTab->setStyleSheet(QString::fromUtf8(""));
        fileTab->setFrameShape(QFrame::StyledPanel);
        fileTab->setFrameShadow(QFrame::Sunken);
        fileTab->setLineWidth(1);
        fileTab->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        fileTab->setAutoScrollMargin(39);
        fileTab->setEditTriggers(QAbstractItemView::NoEditTriggers);
        fileTab->setSelectionMode(QAbstractItemView::NoSelection);
        fileTab->setSelectionBehavior(QAbstractItemView::SelectRows);
        fileTab->setRowCount(0);
        fileTab->horizontalHeader()->setCascadingSectionResizes(false);
        fileTab->horizontalHeader()->setStretchLastSection(true);
        fileTab->verticalHeader()->setVisible(false);
        fileTab->verticalHeader()->setHighlightSections(true);
        fileTab->verticalHeader()->setMinimumSectionSize(21);
        TLabel08 = new QLabel(W_All);
        TLabel08->setObjectName(QString::fromUtf8("TLabel08"));
        TLabel08->setGeometry(QRect(20, 440, 251, 41));
        TLabel08->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        TLabel08->setAlignment(Qt::AlignCenter);
        fileBtnCheck = new QPushButton(W_All);
        fileBtnCheck->setObjectName(QString::fromUtf8("fileBtnCheck"));
        fileBtnCheck->setGeometry(QRect(10, 540, 81, 45));
        fileBtnAdd = new QPushButton(W_All);
        fileBtnAdd->setObjectName(QString::fromUtf8("fileBtnAdd"));
        fileBtnAdd->setGeometry(QRect(100, 540, 81, 45));
        fileEdit1 = new QLineEdit(W_All);
        fileEdit1->setObjectName(QString::fromUtf8("fileEdit1"));
        fileEdit1->setGeometry(QRect(10, 480, 270, 41));
        fileEdit1->setFocusPolicy(Qt::StrongFocus);
        fileEdit1->setMaxLength(25);
        fileEdit1->setCursorPosition(0);
        fileEdit1->setAlignment(Qt::AlignCenter);
        fileEdit1->setReadOnly(false);
        label_Text = new QLabel(W_All);
        label_Text->setObjectName(QString::fromUtf8("label_Text"));
        label_Text->setGeometry(QRect(10, 396, 270, 41));
        label_Text->setLayoutDirection(Qt::LeftToRight);
        label_Text->setStyleSheet(QString::fromUtf8("\n"
"    border: 1px solid #447684;\n"
"    border-radius: 3px;\n"
"    color:white;\n"
"\n"
"    selection-background-color: #0A246A;"));
        label_Text->setAlignment(Qt::AlignCenter);
        fileBtnDel = new QPushButton(W_All);
        fileBtnDel->setObjectName(QString::fromUtf8("fileBtnDel"));
        fileBtnDel->setGeometry(QRect(190, 540, 81, 45));
        test = new QTableWidget(W_All);
        if (test->columnCount() < 1)
            test->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        test->setHorizontalHeaderItem(0, __qtablewidgetitem1);
        test->setObjectName(QString::fromUtf8("test"));
        test->setGeometry(QRect(310, 20, 121, 571));
        test->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        test->setEditTriggers(QAbstractItemView::NoEditTriggers);
        test->setSelectionMode(QAbstractItemView::NoSelection);
        test->setRowCount(0);
        test->horizontalHeader()->setStretchLastSection(true);
        test->verticalHeader()->setVisible(false);
        combConf1 = new QComboBox(W_All);
        combConf1->setObjectName(QString::fromUtf8("combConf1"));
        combConf1->setGeometry(QRect(560, 130, 131, 50));
        combConf1->setMaximumSize(QSize(160, 50));
        QFont font;
        font.setPointSize(20);
        combConf1->setFont(font);
        combConf1->setStyleSheet(QString::fromUtf8("\n"
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
        file_number = new QLineEdit(W_All);
        file_number->setObjectName(QString::fromUtf8("file_number"));
        file_number->setGeometry(QRect(560, 70, 131, 50));
        file_number->setFocusPolicy(Qt::StrongFocus);
        file_number->setMaxLength(15);
        file_number->setCursorPosition(0);
        file_number->setAlignment(Qt::AlignCenter);
        file_number->setReadOnly(false);
        label_36 = new QLabel(W_All);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(460, 190, 101, 50));
        label_36->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_36->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_35 = new QLabel(W_All);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(460, 70, 101, 50));
        label_35->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
""));
        label_35->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        MotorType = new QComboBox(W_All);
        MotorType->setObjectName(QString::fromUtf8("MotorType"));
        MotorType->setGeometry(QRect(559, 190, 131, 50));
        MotorType->setMaximumSize(QSize(150, 50));
        MotorType->setFont(font);
        MotorType->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	color: rgb(255, 255, 255);\n"
"    border: 1px solid #32435E;\n"
"    border-radius: 3px;\n"
"    padding: 1px 8px 1px 3px;\n"
"    background:qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0 #080B10,stop:1 #212C3F);\n"
"}\n"
"QComboBox::down-arrow {\n"
"    image: url(:image/downarrow.png);\n"
"}\n"
"QComboBox::drop-down {\n"
"\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: 32435E;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 0px;\n"
"    border-bottom-right-radius: 0px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"	color: rgb(255, 255, 255);\n"
"    border: 2px solid #32435E;\n"
"    selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #506B79,stop: 1.0 #0D95A6);\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #1B2534, stop: 0.4 #010101,stop: 0.5 #000101, stop: 1.0 #1F2B3C);\n"
"}"));
        label_34 = new QLabel(W_All);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(460, 130, 101, 50));
        label_34->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
""));
        label_34->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_38 = new QLabel(W_All);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(460, 10, 101, 51));
        label_38->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
""));
        label_38->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        SQL_Task = new QPushButton(W_All);
        SQL_Task->setObjectName(QString::fromUtf8("SQL_Task"));
        SQL_Task->setGeometry(QRect(560, 10, 131, 50));
        stackedWidget->addWidget(W_All);
        label_38->raise();
        SQL_Task->raise();
        label_36->raise();
        label_35->raise();
        label_34->raise();
        MotorType->raise();
        file_number->raise();
        combConf1->raise();
        DLabel05_4->raise();
        label_37->raise();
        Label_Picture->raise();
        gridLayoutWidget_6->raise();
        T003Label->raise();
        T002Label->raise();
        fileTab->raise();
        TLabel08->raise();
        fileBtnCheck->raise();
        fileBtnAdd->raise();
        fileEdit1->raise();
        label_Text->raise();
        fileBtnDel->raise();
        test->raise();
        Button_DLR = new QPushButton(w_Conf);
        Button_DLR->setObjectName(QString::fromUtf8("Button_DLR"));
        Button_DLR->setGeometry(QRect(810, 572, 85, 25));
        sizePolicy.setHeightForWidth(Button_DLR->sizePolicy().hasHeightForWidth());
        Button_DLR->setSizePolicy(sizePolicy);
        Button_DLR->setMinimumSize(QSize(0, 25));
        Button_DLR->setMaximumSize(QSize(16777215, 25));
        Button_MAG = new QPushButton(w_Conf);
        Button_MAG->setObjectName(QString::fromUtf8("Button_MAG"));
        Button_MAG->setGeometry(QRect(810, 570, 85, 25));
        sizePolicy.setHeightForWidth(Button_MAG->sizePolicy().hasHeightForWidth());
        Button_MAG->setSizePolicy(sizePolicy);
        Button_MAG->setMinimumSize(QSize(0, 25));
        Button_MAG->setMaximumSize(QSize(16777215, 25));
        Button_IR = new QPushButton(w_Conf);
        Button_IR->setObjectName(QString::fromUtf8("Button_IR"));
        Button_IR->setGeometry(QRect(810, 570, 85, 25));
        sizePolicy.setHeightForWidth(Button_IR->sizePolicy().hasHeightForWidth());
        Button_IR->setSizePolicy(sizePolicy);
        Button_IR->setMinimumSize(QSize(0, 25));
        Button_IR->setMaximumSize(QSize(16777215, 25));
        Button_DCW = new QPushButton(w_Conf);
        Button_DCW->setObjectName(QString::fromUtf8("Button_DCW"));
        Button_DCW->setGeometry(QRect(810, 570, 85, 25));
        sizePolicy.setHeightForWidth(Button_DCW->sizePolicy().hasHeightForWidth());
        Button_DCW->setSizePolicy(sizePolicy);
        Button_DCW->setMinimumSize(QSize(0, 25));
        Button_DCW->setMaximumSize(QSize(16777215, 25));
        Button_ACW = new QPushButton(w_Conf);
        Button_ACW->setObjectName(QString::fromUtf8("Button_ACW"));
        Button_ACW->setGeometry(QRect(810, 570, 85, 25));
        sizePolicy.setHeightForWidth(Button_ACW->sizePolicy().hasHeightForWidth());
        Button_ACW->setSizePolicy(sizePolicy);
        Button_ACW->setMinimumSize(QSize(0, 25));
        Button_ACW->setMaximumSize(QSize(16777215, 25));
        Button_IMP = new QPushButton(w_Conf);
        Button_IMP->setObjectName(QString::fromUtf8("Button_IMP"));
        Button_IMP->setGeometry(QRect(810, 570, 85, 25));
        sizePolicy.setHeightForWidth(Button_IMP->sizePolicy().hasHeightForWidth());
        Button_IMP->setSizePolicy(sizePolicy);
        Button_IMP->setMinimumSize(QSize(0, 25));
        Button_IMP->setMaximumSize(QSize(16777215, 25));
        imp_button_add = new QPushButton(w_Conf);
        imp_button_add->setObjectName(QString::fromUtf8("imp_button_add"));
        imp_button_add->setGeometry(QRect(710, 420, 85, 50));
        sizePolicy.setHeightForWidth(imp_button_add->sizePolicy().hasHeightForWidth());
        imp_button_add->setSizePolicy(sizePolicy);
        imp_button_add->setMinimumSize(QSize(0, 50));
        imp_button_add->setMaximumSize(QSize(16777215, 50));
        imp_button_add->setSizeIncrement(QSize(0, 38));
        imp_button_add->setStyleSheet(QString::fromUtf8(""));
        imp_button_add->setIconSize(QSize(64, 64));
        imp_button_cancel = new QPushButton(w_Conf);
        imp_button_cancel->setObjectName(QString::fromUtf8("imp_button_cancel"));
        imp_button_cancel->setGeometry(QRect(710, 480, 85, 50));
        sizePolicy.setHeightForWidth(imp_button_cancel->sizePolicy().hasHeightForWidth());
        imp_button_cancel->setSizePolicy(sizePolicy);
        imp_button_cancel->setMinimumSize(QSize(0, 50));
        imp_button_cancel->setMaximumSize(QSize(16777215, 50));
        imp_button_cancel->setSizeIncrement(QSize(0, 38));
        imp_button_cancel->setStyleSheet(QString::fromUtf8(""));
        imp_button_cancel->setIconSize(QSize(64, 64));
        imp_button_finsh = new QPushButton(w_Conf);
        imp_button_finsh->setObjectName(QString::fromUtf8("imp_button_finsh"));
        imp_button_finsh->setGeometry(QRect(710, 540, 85, 50));
        sizePolicy.setHeightForWidth(imp_button_finsh->sizePolicy().hasHeightForWidth());
        imp_button_finsh->setSizePolicy(sizePolicy);
        imp_button_finsh->setMinimumSize(QSize(0, 50));
        imp_button_finsh->setMaximumSize(QSize(16777215, 50));
        imp_button_finsh->setSizeIncrement(QSize(0, 38));
        imp_button_finsh->setStyleSheet(QString::fromUtf8(""));
        imp_button_finsh->setIconSize(QSize(64, 64));
        Button_PWR = new QPushButton(w_Conf);
        Button_PWR->setObjectName(QString::fromUtf8("Button_PWR"));
        Button_PWR->setGeometry(QRect(810, 570, 85, 25));
        sizePolicy.setHeightForWidth(Button_PWR->sizePolicy().hasHeightForWidth());
        Button_PWR->setSizePolicy(sizePolicy);
        Button_PWR->setMinimumSize(QSize(0, 25));
        Button_PWR->setMaximumSize(QSize(16777215, 25));
        Button_INDL = new QPushButton(w_Conf);
        Button_INDL->setObjectName(QString::fromUtf8("Button_INDL"));
        Button_INDL->setGeometry(QRect(810, 570, 85, 25));
        sizePolicy.setHeightForWidth(Button_INDL->sizePolicy().hasHeightForWidth());
        Button_INDL->setSizePolicy(sizePolicy);
        Button_INDL->setMinimumSize(QSize(0, 25));
        Button_INDL->setMaximumSize(QSize(16777215, 25));
        Button_BLOCK = new QPushButton(w_Conf);
        Button_BLOCK->setObjectName(QString::fromUtf8("Button_BLOCK"));
        Button_BLOCK->setGeometry(QRect(810, 570, 85, 25));
        sizePolicy.setHeightForWidth(Button_BLOCK->sizePolicy().hasHeightForWidth());
        Button_BLOCK->setSizePolicy(sizePolicy);
        Button_BLOCK->setMinimumSize(QSize(0, 25));
        Button_BLOCK->setMaximumSize(QSize(16777215, 25));
        Button_LVS = new QPushButton(w_Conf);
        Button_LVS->setObjectName(QString::fromUtf8("Button_LVS"));
        Button_LVS->setGeometry(QRect(810, 570, 85, 25));
        sizePolicy.setHeightForWidth(Button_LVS->sizePolicy().hasHeightForWidth());
        Button_LVS->setSizePolicy(sizePolicy);
        Button_LVS->setMinimumSize(QSize(0, 25));
        Button_LVS->setMaximumSize(QSize(16777215, 25));
        Button_Hall = new QPushButton(w_Conf);
        Button_Hall->setObjectName(QString::fromUtf8("Button_Hall"));
        Button_Hall->setGeometry(QRect(810, 570, 85, 25));
        sizePolicy.setHeightForWidth(Button_Hall->sizePolicy().hasHeightForWidth());
        Button_Hall->setSizePolicy(sizePolicy);
        Button_Hall->setMinimumSize(QSize(0, 25));
        Button_Hall->setMaximumSize(QSize(16777215, 25));
        Button_Load = new QPushButton(w_Conf);
        Button_Load->setObjectName(QString::fromUtf8("Button_Load"));
        Button_Load->setGeometry(QRect(810, 570, 85, 25));
        sizePolicy.setHeightForWidth(Button_Load->sizePolicy().hasHeightForWidth());
        Button_Load->setSizePolicy(sizePolicy);
        Button_Load->setMinimumSize(QSize(0, 25));
        Button_Load->setMaximumSize(QSize(16777215, 25));
        Button_NoLoad = new QPushButton(w_Conf);
        Button_NoLoad->setObjectName(QString::fromUtf8("Button_NoLoad"));
        Button_NoLoad->setGeometry(QRect(810, 570, 85, 25));
        sizePolicy.setHeightForWidth(Button_NoLoad->sizePolicy().hasHeightForWidth());
        Button_NoLoad->setSizePolicy(sizePolicy);
        Button_NoLoad->setMinimumSize(QSize(0, 25));
        Button_NoLoad->setMaximumSize(QSize(16777215, 25));
        Button_BEMF = new QPushButton(w_Conf);
        Button_BEMF->setObjectName(QString::fromUtf8("Button_BEMF"));
        Button_BEMF->setGeometry(QRect(810, 570, 85, 25));
        sizePolicy.setHeightForWidth(Button_BEMF->sizePolicy().hasHeightForWidth());
        Button_BEMF->setSizePolicy(sizePolicy);
        Button_BEMF->setMinimumSize(QSize(0, 25));
        Button_BEMF->setMaximumSize(QSize(16777215, 25));
        Button_HV = new QPushButton(w_Conf);
        Button_HV->setObjectName(QString::fromUtf8("Button_HV"));
        Button_HV->setGeometry(QRect(810, 560, 85, 25));
        sizePolicy.setHeightForWidth(Button_HV->sizePolicy().hasHeightForWidth());
        Button_HV->setSizePolicy(sizePolicy);
        Button_HV->setMinimumSize(QSize(0, 25));
        Button_HV->setMaximumSize(QSize(16777215, 25));
        Button_DLR->raise();
        Button_MAG->raise();
        Button_IR->raise();
        Button_DCW->raise();
        Button_ACW->raise();
        Button_IMP->raise();
        label->raise();
        layoutWidget->raise();
        label_User->raise();
        label_31->raise();
        stackedWidget->raise();
        imp_button_add->raise();
        imp_button_cancel->raise();
        imp_button_finsh->raise();
        Button_PWR->raise();
        Button_INDL->raise();
        Button_BLOCK->raise();
        Button_LVS->raise();
        Button_Hall->raise();
        Button_Load->raise();
        Button_NoLoad->raise();
        Button_BEMF->raise();
        Button_HV->raise();
        QWidget::setTabOrder(Key_D, Button_DCW);
        QWidget::setTabOrder(Button_DCW, fileBtnAdd);
        QWidget::setTabOrder(fileBtnAdd, fileBtnDel);
        QWidget::setTabOrder(fileBtnDel, Button_ACW);
        QWidget::setTabOrder(Button_ACW, Button_IMP);
        QWidget::setTabOrder(Button_IMP, Key_E);
        QWidget::setTabOrder(Key_E, fileBtnCheck);
        QWidget::setTabOrder(fileBtnCheck, fileEdit1);
        QWidget::setTabOrder(fileEdit1, Key_B);
        QWidget::setTabOrder(Key_B, Key_C);
        QWidget::setTabOrder(Key_C, Key_A);
        QWidget::setTabOrder(Key_A, Button_DLR);
        QWidget::setTabOrder(Button_DLR, Button_MAG);
        QWidget::setTabOrder(Button_MAG, Button_IR);
        QWidget::setTabOrder(Button_IR, test);

        retranslateUi(w_Conf);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(w_Conf);
    } // setupUi

    void retranslateUi(QWidget *w_Conf)
    {
        label_31->setText(QString());
        label_User->setText(QString());
        label->setText(QString());
        Key_E->setText(QApplication::translate("w_Conf", "\350\241\245\345\201\277", 0, QApplication::UnicodeUTF8));
        Key_C->setText(QApplication::translate("w_Conf", "\345\277\253\351\200\237\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        Key_B->setText(QApplication::translate("w_Conf", "\344\277\235\345\255\230\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        Button_ALL->setText(QApplication::translate("w_Conf", "\350\256\276\347\275\256\351\246\226\351\241\265", 0, QApplication::UnicodeUTF8));
        Key_D->setText(QApplication::translate("w_Conf", "\345\267\246\351\207\207\351\233\206", 0, QApplication::UnicodeUTF8));
        Key_A->setText(QApplication::translate("w_Conf", "\346\265\213\350\257\225\344\270\273\351\241\265", 0, QApplication::UnicodeUTF8));
        label_37->setText(QApplication::translate("w_Conf", "\347\272\277\345\244\271\351\242\234\350\211\262:", 0, QApplication::UnicodeUTF8));
        Label_Picture->setText(QString());
        DLabel05_4->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = fileTab->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("w_Conf", "\347\224\265\346\234\272\345\236\213\345\217\267", 0, QApplication::UnicodeUTF8));
        TLabel08->setText(QApplication::translate("w_Conf", "\346\226\260\345\273\272\345\236\213\345\217\267", 0, QApplication::UnicodeUTF8));
        fileBtnCheck->setText(QApplication::translate("w_Conf", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        fileBtnAdd->setText(QApplication::translate("w_Conf", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        fileEdit1->setText(QString());
        label_Text->setText(QApplication::translate("w_Conf", "6", 0, QApplication::UnicodeUTF8));
        fileBtnDel->setText(QApplication::translate("w_Conf", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = test->horizontalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("w_Conf", "\346\265\213\350\257\225\351\241\271\347\233\256", 0, QApplication::UnicodeUTF8));
        combConf1->clear();
        combConf1->insertItems(0, QStringList()
         << QApplication::translate("w_Conf", "\347\273\247\347\273\255", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Conf", "\345\201\234\346\255\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("w_Conf", "\350\257\242\351\227\256", 0, QApplication::UnicodeUTF8)
        );
        file_number->setText(QString());
        label_36->setText(QApplication::translate("w_Conf", "\347\224\265\346\234\272\347\261\273\345\236\213:", 0, QApplication::UnicodeUTF8));
        label_35->setText(QApplication::translate("w_Conf", "\351\273\230\350\256\244\347\274\226\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("w_Conf", "\351\201\207\344\270\215\345\220\210\346\240\274:", 0, QApplication::UnicodeUTF8));
        label_38->setText(QApplication::translate("w_Conf", "\344\270\213\350\275\275\344\273\273\345\212\241:", 0, QApplication::UnicodeUTF8));
        SQL_Task->setText(QApplication::translate("w_Conf", "\344\273\273\345\212\241\350\241\250", 0, QApplication::UnicodeUTF8));
        Button_DLR->setText(QApplication::translate("w_Conf", "\347\224\265\351\230\273", 0, QApplication::UnicodeUTF8));
        Button_MAG->setText(QApplication::translate("w_Conf", "\345\217\215\345\265\214", 0, QApplication::UnicodeUTF8));
        Button_IR->setText(QApplication::translate("w_Conf", "\347\273\235\347\274\230", 0, QApplication::UnicodeUTF8));
        Button_DCW->setText(QApplication::translate("w_Conf", "\347\233\264\350\200\220", 0, QApplication::UnicodeUTF8));
        Button_ACW->setText(QApplication::translate("w_Conf", "\344\272\244\350\200\220", 0, QApplication::UnicodeUTF8));
        Button_IMP->setText(QApplication::translate("w_Conf", "\345\214\235\351\227\264", 0, QApplication::UnicodeUTF8));
        imp_button_add->setText(QApplication::translate("w_Conf", "\345\242\236\345\212\240\346\240\267\345\223\201", 0, QApplication::UnicodeUTF8));
        imp_button_cancel->setText(QApplication::translate("w_Conf", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        imp_button_finsh->setText(QApplication::translate("w_Conf", "\351\207\207\351\233\206\345\256\214\346\210\220", 0, QApplication::UnicodeUTF8));
        Button_PWR->setText(QApplication::translate("w_Conf", "\347\224\265\345\217\202", 0, QApplication::UnicodeUTF8));
        Button_INDL->setText(QApplication::translate("w_Conf", "\347\224\265\346\204\237", 0, QApplication::UnicodeUTF8));
        Button_BLOCK->setText(QApplication::translate("w_Conf", "\347\224\265\346\204\237", 0, QApplication::UnicodeUTF8));
        Button_LVS->setText(QApplication::translate("w_Conf", "\344\275\216\345\220\257", 0, QApplication::UnicodeUTF8));
        Button_Hall->setText(QApplication::translate("w_Conf", "\351\234\215\345\260\224", 0, QApplication::UnicodeUTF8));
        Button_Load->setText(QApplication::translate("w_Conf", "\350\264\237\350\275\275", 0, QApplication::UnicodeUTF8));
        Button_NoLoad->setText(QApplication::translate("w_Conf", "\347\251\272\350\275\275", 0, QApplication::UnicodeUTF8));
        Button_BEMF->setText(QApplication::translate("w_Conf", "BEMF", 0, QApplication::UnicodeUTF8));
        Button_HV->setText(QApplication::translate("w_Conf", "BEMF", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(w_Conf);
    } // retranslateUi

};

namespace Ui {
    class w_Conf: public Ui_w_Conf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_CONF_H
