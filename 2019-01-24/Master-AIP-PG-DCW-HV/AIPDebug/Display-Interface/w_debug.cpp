/*******************************************************************************
 * Copyright [2016]   <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     2.0.7.1
 * author:      sl
 * brief:       头文件
*******************************************************************************/
#include "w_debug.h"
#include "ui_w_debug.h"


w_Debug::w_Debug(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::w_Debug)
{
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint); // 去掉标题栏
    ui->setupUi(this);

    //配置按钮
    btnGroup = new QButtonGroup;
    btnGroup->addButton(ui->Key_A, Qt::Key_A);
    btnGroup->addButton(ui->Key_B, Qt::Key_B);
    btnGroup->addButton(ui->Key_C, Qt::Key_C);
    btnGroup->addButton(ui->Key_D, Qt::Key_D);
    btnGroup->addButton(ui->Key_E, Qt::Key_E);
    btnGroup->addButton(ui->Key_F, Qt::Key_F);
    connect(btnGroup, SIGNAL(buttonClicked(int)), this, SLOT(ButtonJudge(int)));


    DLR_Coefficient.append(ui->DLRBox_1);
    DLR_Coefficient.append(ui->DLRBox_2);
    DLR_Coefficient.append(ui->DLRBox_3);
    DLR_Coefficient.append(ui->DLRBox_4);
    DLR_Coefficient.append(ui->DLRBox_5);
    DLR_Coefficient.append(ui->DLRBox_6);
    DLR_Coefficient.append(ui->DLRBox_7);
    DLR_Coefficient.append(ui->DLRBox_8);

    DLR_btnGroup = new QButtonGroup;
    DLR_btnGroup->addButton(ui->DLR_1, 1);
    DLR_btnGroup->addButton(ui->DLR_2, 2);
    DLR_btnGroup->addButton(ui->DLR_3, 3);
    DLR_btnGroup->addButton(ui->DLR_4, 4);
    DLR_btnGroup->addButton(ui->DLR_5, 5);
    DLR_btnGroup->addButton(ui->DLR_6, 6);
    DLR_btnGroup->addButton(ui->DLR_7, 7);
    DLR_btnGroup->addButton(ui->DLR_8, 8);
    connect(DLR_btnGroup, SIGNAL(buttonClicked(int)), this, SLOT(DLRButtonJudge(int)));

    IMP_Coefficient.append(ui->IMP_Grade1_K);  IMP_Coefficient.append(ui->IMP_Grade1_B);
    IMP_Coefficient.append(ui->IMP_Grade2_K);  IMP_Coefficient.append(ui->IMP_Grade2_B);
    IMP_Coefficient.append(ui->IMP_Grade3_K);  IMP_Coefficient.append(ui->IMP_Grade3_B);
    IMP_Coefficient.append(ui->IMP_Grade4_K);  IMP_Coefficient.append(ui->IMP_Grade4_B);
    IMP_Coefficient.append(ui->IMP_Grade5_K);  IMP_Coefficient.append(ui->IMP_Grade5_B);
    IMP_Coefficient.append(ui->IMP_Grade6_K);  IMP_Coefficient.append(ui->IMP_Grade6_B);

    IMP_SetValue.append(ui->IMP_Text1_Low);
    IMP_SetValue.append(ui->IMP_Text1_High);
    IMP_SetValue.append(ui->IMP_Text2_Low);
    IMP_SetValue.append(ui->IMP_Text2_High);
    IMP_SetValue.append(ui->IMP_Text3_Low);
    IMP_SetValue.append(ui->IMP_Text3_High);

    IMP_btnGroup = new QButtonGroup;
    IMP_btnGroup->addButton(ui->IMP_Grade1_Low, 1);
    IMP_btnGroup->addButton(ui->IMP_Grade1_High, 2);
    IMP_btnGroup->addButton(ui->IMP_Grade2_Low, 3);
    IMP_btnGroup->addButton(ui->IMP_Grade2_High, 4);
    IMP_btnGroup->addButton(ui->IMP_Grade3_Low, 5);
    IMP_btnGroup->addButton(ui->IMP_Grade3_High, 6);
    IMP_btnGroup->addButton(ui->Button_IMP_Check, 7);
    IMP_btnGroup->addButton(ui->Button_IMP_CLear, 8);
    IMP_btnGroup->addButton(ui->IMP_Grade6_High, 9);
    connect(IMP_btnGroup, SIGNAL(buttonClicked(int)), this, SLOT(IMPButtonJudge(int)));

    //  ui->DLR_7->setDisabled(true);  //  档位 8 失能
    //  ui->DLR_8->setDisabled(true);  //  档位 8 失能
    IR_SetValue.append(ui->IR_Volt_textk);
    IR_SetValue.append(ui->IR_Volt_textb);
    IR_SetValue.append(ui->IR_DLR_Grade1_k);
    IR_SetValue.append(ui->IR_DLR_Grade1_b);
    IR_SetValue.append(ui->IR_DLR_Grade2_k);
    IR_SetValue.append(ui->IR_DLR_Grade2_b);
    IR_SetValue.append(ui->IR_DLR_Grade3_k);
    IR_SetValue.append(ui->IR_DLR_Grade3_b);

    IR_btnGroup = new QButtonGroup;
    IR_btnGroup->addButton(ui->IR500, 1);
    IR_btnGroup->addButton(ui->IR1000, 2);
    IR_btnGroup->addButton(ui->IR_Grade1_1M, 3);
    IR_btnGroup->addButton(ui->IR_Grade1_5M, 4);
    IR_btnGroup->addButton(ui->IR_Grade2_5M, 5);
    IR_btnGroup->addButton(ui->IR_Grade2_50M, 6);
    IR_btnGroup->addButton(ui->IR_Grade3_50M, 7);
    IR_btnGroup->addButton(ui->IR_Grade3_500M, 8);
    IR_btnGroup->addButton(ui->Button_IR_VoltClear, 9);
    IR_btnGroup->addButton(ui->Button_IR_DLRClear, 10);
    IR_btnGroup->addButton(ui->Button_IR_Check, 11);

    connect(IR_btnGroup, SIGNAL(buttonClicked(int)), this, SLOT(IRButtonJudge(int)));

    ACW_SetValue.append(ui->ACW_Volt_textk);
    ACW_SetValue.append(ui->ACW_Volt_textb);
    ACW_SetValue.append(ui->ACW_Grade1_k);
    ACW_SetValue.append(ui->ACW_Grade1_b);
    ACW_SetValue.append(ui->ACW_Grade2_k);
    ACW_SetValue.append(ui->ACW_Grade2_b);
    ACW_SetValue.append(ui->ACW_ARC);

    ACW_btnGroup = new QButtonGroup;
    ACW_btnGroup->addButton(ui->ACW_500, 1);
    ACW_btnGroup->addButton(ui->ACW_4500, 2);
    ACW_btnGroup->addButton(ui->ACW_Grade1_1, 3);
    ACW_btnGroup->addButton(ui->ACW_Grade1_2, 4);
    ACW_btnGroup->addButton(ui->ACW_Grade2_1, 5);
    ACW_btnGroup->addButton(ui->ACW_Grade2_2, 6);
    ACW_btnGroup->addButton(ui->Button_ACW_VoltClear, 7);
    ACW_btnGroup->addButton(ui->Button_ACW_CurrentClear, 8);
    ACW_btnGroup->addButton(ui->Button_ACW_Check, 9);
    connect(ACW_btnGroup, SIGNAL(buttonClicked(int)), this, SLOT(ACWButtonJudge(int)));

    PWR_Coefficient.append(ui->AVola);
    PWR_Coefficient.append(ui->ACurr);
    PWR_Coefficient.append(ui->APower);
    PWR_Coefficient.append(ui->BVola);
    PWR_Coefficient.append(ui->BCurr);
    PWR_Coefficient.append(ui->BPower);
    PWR_Coefficient.append(ui->CVola);
    PWR_Coefficient.append(ui->CCurr);
    PWR_Coefficient.append(ui->CPower);

    PWR_btnGroup = new QButtonGroup;
    PWR_btnGroup->addButton(ui->check,  1);
    PWR_btnGroup->addButton(ui->debug,  2);

//    PWR_btnGroup = new  QButtonGroup;
//    PWR_btnGroup->addButton(ui->pushButton, 1);
//    PWR_btnGroup->addButton(ui->pushButton_2, 2);
//    PWR_btnGroup->addButton(ui->pushButton_3, 3);
//    PWR_btnGroup->addButton(ui->pushButton_4, 4);
//    PWR_btnGroup->addButton(ui->pushButton_5, 7);
//    PWR_btnGroup->addButton(ui->pushButton_6,8);
//    PWR_btnGroup->addButton(ui->pushButton_7, 9);
//    PWR_btnGroup->addButton(ui->pushButton_8, 10);
//    PWR_btnGroup->addButton(ui->pushButton_9, 11);
//    PWR_btnGroup->addButton(ui->pushButton_10, 12);
//    connect(PWR_btnGroup, SIGNAL(buttonClicked(int)), this, SLOT(PWRButtonJudge(int)));

    connect(PWR_btnGroup,  SIGNAL(buttonClicked(int)),  this,  SLOT(PWRButtonJudge(int)));

    Debug_Labelhide = new QLabel(this);
    Debug_Labelhide->setGeometry(0, 0, 800, 600);
    QPalette pa;                                      //背景颜色
    pa.setColor(QPalette::Background,  Qt::transparent);
    Debug_Labelhide->setAutoFillBackground(true);           //背景使能
    Debug_Labelhide->setPalette(pa);
    Debug_Labelhide->hide();

    SystemConf[0].append(ui->checkBox_7);   // 输出13  1
    SystemConf[1].append(ui->checkBox_8);   // 输出14  2
    SystemConf[2].append(ui->checkBox_9);   // 输出15  3
    SystemConf[3].append(ui->checkBox_10);  // 输出16  4
    SystemConf[4].append(ui->checkBox_11);  // 输出17  5
    //  空余一位  6
    SystemConf[5].append(ui->checkBox_1);   // 电阻 7  1
    SystemConf[6].append(ui->checkBox_2);   // 反嵌 8  2
    SystemConf[7].append(ui->checkBox_3);   // 绝缘 9  3
    SystemConf[8].append(ui->checkBox_4);   // 交耐 10 4
    SystemConf[9].append(ui->checkBox_5);   // 直板 11 5
    SystemConf[10].append(ui->checkBox_6);  // 匝间 12 6
    SystemConf[11].append(ui->checkBox_12); // 功率 13 7
    SystemConf[12].append(ui->checkBox_14); // 电感 14 8
    SystemConf[13].append(ui->checkBox_15); // 堵转 15 9
    SystemConf[14].append(ui->checkBox_16); // 低启 16 10
    SystemConf[15].append(ui->checkBox_13); // 霍尔    11
    SystemConf[16].append(ui->checkBox_17); // 负载    12
    SystemConf[17].append(ui->checkBox_18); // 空载    13
    SystemConf[18].append(ui->checkBox_19); // BEMF   14
    SystemConf[19].append(ui->checkBox_20); // 高压   1５
    System_Item.clear();
    /* 输出 13 14 15 16 17 */
    /* 电阻 反嵌 绝缘 交耐 直耐 匝间 */
    /* 功率 电感 堵转 低启 */
    /* 霍尔 负载 空载 BEMF */
    /* 高压 */
    System_Item << tr("13") << tr("14") << tr("15") << tr("16") << tr("17")\
               << tr("1") << tr("2") << tr("3") << tr("4") << tr("5") << tr("6")\
              << tr("7") << tr("8") << tr("9") << tr("10")\
             << tr("11") << tr("12") << tr("13") << tr("14")\
             << tr("15");
    ParameterConf[0].clear();
    ParameterConf[0].append(ui->checkBox_IR_SetVolt); //  绝缘配置列表

    ui->checkBox_1->setChecked(true);
    ui->checkBox_2->setChecked(true);
    ui->checkBox_3->setChecked(true);
    ui->checkBox_4->setChecked(true);
    ui->checkBox_5->setChecked(true);
    ui->checkBox_6->setChecked(true);

    ui->Key_A->hide();
    ui->Key_B->hide();
    ui->Key_C->hide();
    ui->Key_D->hide();

    // ui->IR_DLR_1->hide();
    // ui->IR_DLR_2->hide();

    ZeroAndDLR = 0;
    IR_Grade = 0;


    Debug_IMP_Testing_Flag = 1;
    // ui->DLRBox->hide();
    // ui->DLRBox_0->hide();

    Beep.Time =  new QTimer(this);
    connect(Beep.Time, SIGNAL(timeout()), this, SLOT(Beep_Stop()));

    ui->IMP_Grade2_2500->hide();
    ui->IMP_Grade2_4500->hide();
    ui->IMP_Text2_2500->hide();
    ui->IMP_Text2_4500->hide();

    ui->IMP_Grade1_Low->hide();  ui->IMP_Grade2_Low->hide();
    ui->IMP_Grade3_Low->hide();
    ui->IMP_Text1_Low->hide();  ui->IMP_Text2_Low->hide();  ui->IMP_Text3_Low->hide();
    ui->IMP_Grade1_B->hide();  ui->IMP_Grade2_B->hide();  ui->IMP_Grade3_B->hide();
    ui->label_4->hide();
    ui->IMP_Grade6_High->hide(); ui->IMP_Text6_High->hide();
    ui->IMP_Grade6_B->hide();
    ui->IMP_Grade5_K->hide(); ui->IMP_Grade5_B->hide();
    ui->IMP_Grade4_K->hide(); ui->IMP_Grade4_B->hide();

    ui->textBrowser->setReadOnly(true);

    Self_starting.clear();  //  自启动自校验设置
    Self_starting.append(QString::number(Button_Start_Flag));
    Self_starting.append(QString::number(ui->comb_Start_2->currentIndex()));
    Self_starting.append((ui->Button_Start_Time->text()));

    QSettings *set_Test_File = new QSettings(Sys_path,  QSettings::IniFormat);
    set_Test_File->setIniCodec("GB18030");

    QString Factory_number = set_Test_File->value("Factory/text", "V-0.0.0").toString();
    ui->text_Factory_number->setText(Factory_number);
    ui->text_Ask_Model->setText(set_Test_File->value("DCR_In/text", "1").toString());
    ui->text_Temp->setText(set_Test_File->value("AMP_Temp/text", "50").toString());
    ui->text_GND->setText(set_Test_File->value("System/GND", "20").toString());
    ui->IO__Model->setText(set_Test_File->value("System/IO_Model", "0").toString());

    if (QString(set_Test_File->value(QString("MAG/text")\
              .toUtf8().data()).toString().toUtf8().data()) == "negative") { // 磁旋转向
        ui->checkBox_mag->setChecked(true);
    } else {
        //
    }

    if (QString(set_Test_File->value(QString("PGturn/text")\
              .toUtf8().data()).toString().toUtf8().data()) == "induction") { // 感应方式
        ui->checkBox_induction->setChecked(true);
    } else {
        //
    }

    if (set_Test_File->value("Allocation/Set", 0).toInt() == 2) { // -IRACW_True_Value
        ui->checkBox_IR_SetVolt->setChecked(true);
    } else {
        //
    }

    if (set_Test_File->value("magshapehide/text", 0).toInt() == 2) {  //  magshapehide
        ui->checkBox_mag_shapehide->setChecked(true);
    } else {
        //
    }

    if (set_Test_File->value("NG/text", 0).toInt() == 2) {  //  NG
        ui->checkBox_NG->setChecked(true);
    } else {
        //
    }

    if (set_Test_File->value("commonACW/text", 0).toInt()  ==  1) { //
        ui->checkBox_nacw->setChecked(true);
    } else {
        //
    }


    if (set_Test_File->value("outsingal/text", 0).toInt() == 2) {  //  输出板信号
        ui->checkBox_singal->setChecked(true);
    } else {
        //
    }

    if (set_Test_File->value("UDP/text", 0).toInt() == 2) {  //  输出板信号
        ui->checkBox_UDP->setChecked(true);
    } else {
        //
    }

    if (set_Test_File->value("IRHostJudge/text", 0).toInt() == 2) {  //  上位机判断绝缘
        ui->checkBox_IR_HostJudge->setChecked(true);
    } else {
        //
    }

    if (set_Test_File->value("BoardNumber/text", 0).toInt() == 2) {  //  8插板
        ui->checkBox_9Board->setChecked(true);
    } else {
        //
    }

    if (set_Test_File->value("System/PG", "Common").toString() == "PG") {  //  PG电机信号
        ui->checkBox_PG->setChecked(true);
    } else {
        //
    }

    if (set_Test_File->value("System/WD", "Common").toString() == "WD") {  //  WD
        ui->checkBox_WD->setChecked(true);
    } else {
        //
    }

    if (set_Test_File->value("System/new_rot", 0).toInt() == 2) {  //  WD
        ui->checkBox_new_rot->setChecked(true);
    } else {
        //
    }

    if (set_Test_File->value("System/ACSW", 0).toInt() == 2) {  //  PG电机信号
        ui->checkBox_ACSW->setChecked(true);
    } else {
        //
    }

    if (set_Test_File->value("System/LR", 0).toInt() == 2) { // 左右工位信号反转
        ui->checkBox_LR->setChecked(true);
    } else {
        //
    }

    if (set_Test_File->value("System/Order", 0).toInt() == 2) { // 左右工位预约
        ui->checkBox_Order->setChecked(true);
    } else {
        //
    }

    if (set_Test_File->value("System/DCR_Cancle", 0).toInt() == 2) { // 左右工位预约
       ui->checkBox_DCR_Cancle->setChecked(true);
    } else {
       //
    }

    if (set_Test_File->value("System/Set_Turn", 0).toInt() == 2) { // 功率设置正反转
       ui->checkBox_PWR_Turn->setChecked(true);
    } else {
       //
    }

    if (set_Test_File->value("System/Turn", 0).toInt() == 2) { // 功率转向逆转
        ui->checkBox_Turn->setChecked(true);
    } else {
        //
    }

    if (set_Test_File->value("System/Shan_Turn", 0).toInt() == 2) { // 假转子测试
        ui->checkBox_Sham_Turn->setChecked(true);
    } else {
        //
    }

    if (set_Test_File->value("System/IO", 0).toInt() == 2) { // IO板使能
        ui->checkBox_IO->setChecked(true);
    } else {
        //
    }

    if (set_Test_File->value("System/LR_Beep", 0).toInt() == 2) { // LR_BEEP使能
        ui->checkBox_LR_Beep->setChecked(true);
    } else {
        //
    }



    if (set_Test_File->value("System/IO_Test", 0).toInt() == 2) { // IO板使能
        ui->checkBox_IO__Test->setChecked(true);
    } else {
        //
    }
    if (set_Test_File->value("System/IO_Delay", 0).toInt() == 2) { // IO板延时时间
        ui->checkBox_IO__Delay->setChecked(true);
    } else {
        //
    }
    if (set_Test_File->value("KongShi/Enable", 0).toInt() == 2) { // IO板延时时间
        ui->checkBox__KongShi->setChecked(true);
    } else {
        //
    }

    if (set_Test_File->value("DeChang/Enable", 0).toInt() == 2) { // IO板延时时间
         ui->checkBox__DeChang->setChecked(true);
    } else {
          //
    }

    if (set_Test_File->value("DeChang/Connect", 0).toInt() == 2) { // IO板延时时间
         ui->checkBox__W_Connect->setChecked(true);
    } else {
         //
    }

    if (set_Test_File->value("DeChang/Discharge", 0).toInt() == 2) { // IO板延时时间
        ui->checkBox__Discharge->setChecked(true);
    } else {
        //
    }

    if (set_Test_File->value("IO/Start_Stop", 0).toInt() == 2) { // IO板延时时间
        ui->checkBox_IO_Start->setChecked(true);
    } else {
        //
    }

    if (set_Test_File->value("System/IMP_36", 0).toInt() == 2) { // IO板延时时间
        ui->checkBox_IMP_36->setChecked(true);
    } else {
        //
    }

    if (set_Test_File->value("System/out6", 0).toInt() == 2) { // 输出６通道
        ui->checkBox_out6->setChecked(true);
    } else {
        //
    }

    if (set_Test_File->value("System/IMP5000", 0).toInt() == 2) { // IMP5000
        ui->checkBox_IMP5000->setChecked(true);
    } else {
        //
    }

    if (set_Test_File->value("System/IR5000", 0).toInt() == 2) { // IR5000
        ui->checkBox_IR5000->setChecked(true);
    } else {
        //
    }
    System_currentProj = set_Test_File->value("Allocation/Item").toStringList();
    Debug_slot_from_main_one(System_currentProj);

    delete set_Test_File;
//    ui->Print_Text->setReadOnly(true);
}

w_Debug::~w_Debug()
{
    delete btnGroup;
    delete ui;
}
void w_Debug::on_Button_Start_clicked()
{
    if (ui->Button_Start->text() == QString(tr("停止"))) {
        ui->Button_Start->setText(tr("自启动"));
        Button_Start_Flag = 1;
    } else if (ui->Button_Start->text() == QString(tr("自启动"))) {
        ui->Button_Start->setText(tr("停止"));
        Button_Start_Flag = 0;
    }
}
void w_Debug::Slot_Print_TextC(QStringList list)
{
    ui->textBrowser->append(list.join(" "));
}
void w_Debug::Beep_Stop()
{
    Beep_PWM_Stop();
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.2.29
  * brief:      按键选择
******************************************************************************/
void w_Debug::ButtonJudge(int id )
{
    int i = 0;
    int a = 0, c = 0;
    int x = 0, y = 0;
    switch (id) {
    case Qt::Key_A:
        if (ui->tabWidget2->currentIndex() == 2) {  //计算绝缘电压 KB 数值
            a = ui->IR_lineEdit_500->text().toInt();
            c = ui->IR_lineEdit_1000->text().toInt();
            x = (c - a)*1024/500;       //  k = (bn - md)/(bc - ad);  // (U2 - U1)*1024/500;
            y = a + 500 - 500*x/1024;     //  b = (mc - an)/(bc - ad);  // U1 + 500 - 500*k/1024

            ui->IR_Volt_textk->setStyleSheet("color:rgb(0, 170, 0)");
            ui->IR_Volt_textk->setValue(x);
            ui->IR_Volt_textb->setStyleSheet("color:rgb(0, 170, 0)");
            ui->IR_Volt_textb->setValue(y);
        }
        if (ui->tabWidget2->currentIndex() == 3) {  //计算耐压电压 KB 数值
            a = ui->ACW_lineEdit_500->text().toInt();
            c = ui->ACW_lineEdit_4500->text().toInt();
            x = (c - a)*1024/4000;       //  k = (bn - md)/(bc - ad);  // (U2 - U1)*1024/500;
            y = a + 500 - 500*x/1024;      //  b = (mc - an)/(bc - ad);  // U1 + 500 - 500*k/1024
            ui->ACW_Volt_textk->setStyleSheet("color:rgb(0, 170, 0)");
            ui->ACW_Volt_textk->setValue(x);
            ui->ACW_Volt_textb->setStyleSheet("color:rgb(0, 170, 0)");
            ui->ACW_Volt_textb->setValue(y);
        }
        if (ui->tabWidget2->currentIndex() == 1) {
            //
        }
        if (ui->tabWidget2->currentIndex() == 4) {
            for (i = 0; i < 3; i++) {
                int U1 = IMP_SetValue[i*2]->text().toInt();   U1 = 0;
                int U2 = IMP_SetValue[i*2 + 1]->text().toInt();
                int u1 = IMP_btnGroup->button(i*2 + 1)->text().toInt();  u1 = 0;
                int u2 = IMP_btnGroup->button(i*2 + 2)->text().toInt();
                //  int k = (U2 - U1)*1024/(u2 - u1);
                int k = (U2)*1024/(u2);
                IMP_Coefficient[i*2]->setStyleSheet("color:rgb(0,170,0)");
                IMP_Coefficient[i*2]->setValue(k);

                //  IMP_Coefficient[i*2 + 1]->setStyleSheet("color:rgb(0,170,0)");
                //  IMP_Coefficient[i*2 + 1]->setValue(500 + U1 - u1*k/1024);
                IMP_Coefficient[i*2 + 1]->setValue(500);
            }

            IMP_Coefficient[10]->setStyleSheet("color:rgb(0,170,0)");
            IMP_Coefficient[10]->setValue(3000*1024/ui->IMP_Text3_High->text().toInt());
        }
        break;
    case Qt::Key_B:
        ZeroAndDLR = 1;
        if (ui->tabWidget2->currentIndex() == 1) {
            Debug_TestDLR_CAN(ui->DLR_Grade->text().toInt());
        }
        if (ui->tabWidget2->currentIndex() == 3) {
            int Grade1_I2 = ui->ACW_Current_22->text().toInt();
            int Grade1_I1 = ui->ACW_Current_12->text().toInt();
            int Grade1_i2 = ui->ACW_Current_21->text().toInt();
            int Grade1_i1 = ui->ACW_Current_11->text().toInt();
            int Grade1_k = (Grade1_I2 - Grade1_I1)*1024/(Grade1_i2 - Grade1_i1);
            ACW_SetValue[2]->setValue(Grade1_k);
            ACW_SetValue[3]->setValue(500 + Grade1_I1 - Grade1_k*Grade1_i1/1024);

            Grade1_I2 = ui->ACW_Current_42->text().toInt();
            Grade1_I1 = ui->ACW_Current_32->text().toInt();
            Grade1_i2 = ui->ACW_Current_41->text().toInt();
            Grade1_i1 = ui->ACW_Current_31->text().toInt();
            int Grade2_k = (Grade1_I2 - Grade1_I1)*1024/(Grade1_i2 - Grade1_i1);
            ACW_SetValue[4]->setValue(Grade2_k);
            ACW_SetValue[5]->setValue(500 + Grade1_I1 - Grade2_k*Grade1_i1/1024);
        }
        break;
    case Qt::Key_C:
        ZeroAndDLR = 2;
        if (ui->tabWidget2->currentIndex() == 1) {
            Debug_TestDLR_CAN(ui->DLR_Grade->text().toInt());
        }
        break;
    case Qt::Key_D:
        if (ui->tabWidget2->currentIndex()  ==  5) {
            pwr_picture *pwr_pic = new pwr_picture;
            pwr_pic->show();   pwr_pic->raise();   pwr_pic->activateWindow();  pwr_pic->setFocus();
        }
        break;
    case Qt::Key_E:  //  保存参数
        if (ui->tabWidget2->currentIndex() == 1) {  //  保存电阻调试参数
            QString Dlr_str;
            for (i = 0; i < 8; i++) {
                Debug_DLR_KB(i + 1, DLR_Coefficient[i]->value());
                Dlr_str.append(QString::number(DLR_Coefficient[i]->value()) + " ");
            }
            Singal_Save_Debug("DLR", Dlr_str);
        }
        if (ui->tabWidget2->currentIndex() == 2) {  //  保存绝缘调试参数
            QString Ir_Volt_str, Ir_Dlr_str;
            Debug_IR_KB(0, 1, IR_SetValue[0]->value(), IR_SetValue[1]->value());
            Ir_Volt_str.append(QString::number(IR_SetValue[0]->value()) + " " + \
                    QString::number(IR_SetValue[0]->value()) + " ");
            Singal_Save_Debug("IR-VOLT", Ir_Volt_str);
            for (i = 1; i < 4; i++) {
                Debug_IR_KB(i, 1, IR_SetValue[i*2]->value(), IR_SetValue[i*2 + 1]->value());
                Ir_Dlr_str.append(QString::number(IR_SetValue[i*2]->value()) + " " + \
                        QString::number(IR_SetValue[i*2 + 1]->value()) + " ");
            }
            Singal_Save_Debug("IR-DLR", Ir_Dlr_str);
        }
        if (ui->tabWidget2->currentIndex() == 3) {  //  保存耐压调试参数
            QString Acw_Volt_str, Acw_Dlr_str;
            Debug_IR_KB(4, 1, ACW_SetValue[0]->value(), ACW_SetValue[1]->value());
            Acw_Volt_str.append(QString::number(ACW_SetValue[0]->value()) + " " + \
                    QString::number(ACW_SetValue[0]->value()) + " ");
            Singal_Save_Debug("ACW-VOLT", Acw_Volt_str);
            for (i = 1; i < 3; i++) {
                Debug_IR_KB(i + 4, 1, ACW_SetValue[i*2]->value(), ACW_SetValue[i*2 + 1]->value());
                Acw_Dlr_str.append(QString::number(ACW_SetValue[i*2]->value()) + " " + \
                        QString::number(ACW_SetValue[i*2 + 1]->value()) + " ");
            }
            Debug_IR_KB(0x0a, 1, ACW_SetValue[6]->value(), 500);
            Singal_Save_Debug("ACW-CURRENT", Acw_Dlr_str);
        }
        if (ui->tabWidget2->currentIndex() == 4) {   //  保存匝间调试参数
            QString Imp_str;
            for (i = 0; i < 6; i++) {
                Debug_IMP_KB(0x24, i, IMP_Coefficient[i*2]->value(), \
                        IMP_Coefficient[i*2+1]->value());
                Imp_str.append(QString::number(IMP_Coefficient[i*2]->value()) + " " + \
                        QString::number(IMP_Coefficient[i*2 + 1]->value()) + " ");
            }
            Singal_Save_Debug("IMP", Imp_str);
        }
        if (ui->tabWidget2->currentIndex() == 5) {  //  保存电参调试参数
            QString Pwr_str;
            for (i = 0; i < 3; i++) {
                Debug_PWR_KB(0x27, i, PWR_Coefficient[i*3]->value(), \
                        PWR_Coefficient[i*3+1]->value(), PWR_Coefficient[i*3+2]->value());
                Pwr_str.append(QString::number(PWR_Coefficient[i*3]->value()) + " " + \
                        QString::number(PWR_Coefficient[i*3 + 1]->value()) + " " + \
                        QString::number(PWR_Coefficient[i*3+2]->value()) + " ");
            }
            Singal_Save_Debug("PWR", Pwr_str);
        }
        if (ui->tabWidget2->currentIndex() == 2) {
            //
        }

        Beep.Time->setSingleShot(TRUE);  //  设置蜂鸣器短促的提示声音
        Beep.Time->start(50);
        Beep_PWM_Start(99);
        break;
    case Qt::Key_F:
        Self_starting.clear();  //  自启动自校验设置
        Self_starting.append(QString::number(Button_Start_Flag));
        Self_starting.append(QString::number(ui->comb_Start_2->currentIndex()));
        Self_starting.append((ui->Button_Start_Time->text()));
        Singal_debug_to_main(Self_starting, 1, 1);
        break;
    default:
        //
        break;
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.4.6
  * brief:      电阻调试按键
******************************************************************************/
void w_Debug::DLRButtonJudge(int id)
{
    if ((id >= 1) && (id <= 8)) {
        ui->DLR_Grade->setText(QString::number(id));
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.6.3
  * brief:      匝间 按键
******************************************************************************/
void w_Debug::IMPButtonJudge(int id)
{
    if (((id >= 1) && (id <= 6)) && (Debug_IMP_Testing_Flag)) {
        Debug_IMP_Testing_Flag = 0;
        int Volt = 0;
        if (id == 1) {
            Volt = 500;
        } else {
            Volt = (id*500-(id%2)*500);
        }

        if (Volt >= 3000) {
            Volt = 3000;
        }
        IMP_ID = id;
        Debug_TestIMP_CAN(Volt, (id + 1)/2);  // (Volt/2500+1)
    } else if (id == 7) {  //  参数查询
        Beep.Time->setSingleShot(TRUE);  //  设置蜂鸣器短促的提示声音
        Beep.Time->start(50);
        Beep_PWM_Start(99);

        Debug_IMP_KB(0x24, 0xee, 0, 0);
    } else if (id == 8) { // 参数清空
        Beep.Time->setSingleShot(TRUE);  //  设置蜂鸣器短促的提示声音
        Beep.Time->start(50);
        Beep_PWM_Start(99);

        Debug_IMP_KB(0x24, 0xff, 0, 0);
    } else if (id == 9) { //  调试不带返回的电压的数值
        Debug_TestIMP_CAN(2500, 3);
    } else {
        //
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.6.3
  * brief:      绝缘 按键（电压和电阻）
******************************************************************************/
void w_Debug::IRButtonJudge(int id)
{
    if ((id == 1) || (id == 2)) {
        IR_Grade = 0;
        Debug_TestINS_CAN(1, 4, (id*500), 0);
    } else if ((id >= 3) && (id <= 8)) {
        IR_Grade = id-2;
        Debug_TestINS_CAN(1, 4, 500, (id-1)/2);
    } else if (id == 9) {
        Beep.Time->setSingleShot(TRUE);  //  设置蜂鸣器短促的提示声音
        Beep.Time->start(50);
        Beep_PWM_Start(99);
        Debug_IR_KB(0, 1, 1024, 500);
    } else if (id == 10) {
        Beep.Time->setSingleShot(TRUE);  //  设置蜂鸣器短促的提示声音
        Beep.Time->start(50);
        Beep_PWM_Start(99);
        Debug_IR_KB(1, 3, 1024, 500);
    } else if (id == 11) {
        Beep.Time->setSingleShot(TRUE);  //  设置蜂鸣器短促的提示声音
        Beep.Time->start(50);
        Beep_PWM_Start(99);
        Debug_IR_KB(0xee, 1, 0, 0);
    } else {
        //
    }
}
/******************************************************************************
  * version:    1.0
  * author:     jeremy
  * date:       2017.3.16
  * brief:      延时函数
******************************************************************************/
void w_Debug::sleep(unsigned int msec)
{
    QTime reachTime = QTime::currentTime().addMSecs(msec);
    while (QTime::currentTime() < reachTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void w_Debug::PWRButtonJudge(int id)
{
    if (id  ==  1) { // 查询
        Beep.Time->setSingleShot(TRUE);  //  设置蜂鸣器短促的提示声音
        Beep.Time->start(50);
        Beep_PWM_Start(99);

        frame.can_id = 0x27; frame.can_dlc = 0x02;      // 调试参数
        frame.data[0] = 0x06;
        frame.data[1] = 0xee;
        canSend(frame,  wDebug_Surface);
    } else if (id  ==  2) { // 调试
        Debug_Labelhide->show();
        ui->debug->setText(tr("请等待.."));
        frame.can_id = 0x27; frame.can_dlc = 0x02;      // 全部恢复默认值
        frame.data[0] = 0x06;
        frame.data[1] = 0xff;
        canSend(frame, wDebug_Surface);

        frame.can_id = 0x27; frame.can_dlc = 0x01;      // 自动调试
        frame.data[0] = 0x09;
        canSend(frame,  wDebug_Surface);

        sleep(10000);                                   // 延时
        Debug_Labelhide->hide();
        ui->debug->setText(tr("调试"));


        frame.can_id = 0x27; frame.can_dlc = 0x02;      // 调试参数
        frame.data[0] = 0x06;
        frame.data[1] = 0xee;
        canSend(frame,  wDebug_Surface);
    } else {
        //
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.6.3
  * brief:      耐压 按键（电压和电阻）
******************************************************************************/
void w_Debug::ACWButtonJudge(int id)
{
    if ((id == 1) || (id == 2)) {
        IR_Grade = 0;
        Debug_TestINS_CAN(0, 5, (id/2)*4000+500, 0);
    } else if ((id >= 3) && (id <= 6)) {
        IR_Grade = id-2;
        if (id == 6) {
            Debug_TestINS_CAN(0, 5, 600, (id-1)/2);
        } else {
            Debug_TestINS_CAN(0, 5, (500+(id%2)*100), (id-1)/2);
        }
    } else if (id == 7) {
        Beep.Time->setSingleShot(TRUE);  //  设置蜂鸣器短促的提示声音
        Beep.Time->start(50);
        Beep_PWM_Start(99);
        Debug_IR_KB(4, 1, 1024, 500);
    } else if (id == 8) {
        Beep.Time->setSingleShot(TRUE);  //  设置蜂鸣器短促的提示声音
        Beep.Time->start(50);
        Beep_PWM_Start(99);
        Debug_IR_KB(5, 2, 1024, 500);
    } else if (id == 9) {
        Beep.Time->setSingleShot(TRUE);  //  设置蜂鸣器短促的提示声音
        Beep.Time->start(50);
        Beep_PWM_Start(99);
        Debug_IR_KB(0xee, 1, 0, 0);
    } else {
        //
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.2.29
  * brief:      选项卡切换
******************************************************************************/
void w_Debug::on_tabWidget2_currentChanged(int index)
{
    this->setFocus();
    switch (index) {
    case 0:  // 系统设置
        ui->Key_A->hide();  ui->Key_B->hide();  ui->Key_C->hide();
        ui->Key_D->hide();  ui->Key_E->show();  ui->Key_F->show();
        ui->Key_E->setText(tr("保存"));     ui->Key_F->setText(tr("退出"));
        break;
    case 1:  // 电阻测试
        frame.can_id = 0x22;  frame.can_dlc = 0x04;
        frame.data[0] = 0x06;
        frame.data[1] = 0xee;
        frame.data[2] = 0x40;
        frame.data[3] = 0x00;
        canSend(frame, wDebug_Surface);

        ui->Key_A->show();  ui->Key_B->show();  ui->Key_C->show();
        ui->Key_D->hide();  ui->Key_E->show();  ui->Key_F->show();
        ui->Key_A->setText(tr("换档"));
        ui->Key_B->setText(tr("零点"));
        ui->Key_C->setText(tr("电阻"));
        ui->Key_E->setText(tr("保存"));
        ui->Key_F->setText(tr("退出"));
        break;
    case 2:  // 绝缘测试
        Debug_IR_KB(0xee, 1, 0, 0);
        ui->Key_A->show();  ui->Key_B->hide();  ui->Key_C->hide();
        ui->Key_D->hide();  ui->Key_E->show();  ui->Key_F->show();
        ui->Key_A->setText(tr("计算电压"));
        ui->Key_E->setText(tr("保存"));
        ui->Key_F->setText(tr("退出"));
        break;
    case 3:  // 耐压测试
        Debug_IR_KB(0xee, 1, 0, 0);
        ui->Key_A->show();  ui->Key_B->show();  ui->Key_C->hide();
        ui->Key_D->hide();  ui->Key_E->show();  ui->Key_F->show();
        ui->Key_A->setText(tr("计算电压"));
        ui->Key_B->setText(tr("计算电流"));
        ui->Key_E->setText(tr("保存"));
        ui->Key_F->setText(tr("退出"));
        break;
    case 4:  // 匝间测试
        Debug_IMP_KB(0x24, 0xee, 0, 0);
        ui->Key_A->show();  ui->Key_B->hide();  ui->Key_C->hide();
        ui->Key_D->hide();  ui->Key_E->show();  ui->Key_F->show();
        ui->Key_A->setText(tr("计算"));
        ui->Key_E->setText(tr("保存"));
        ui->Key_F->setText(tr("退出"));
        break;
    case 5:  // 电参测试
        frame.can_id = 0x27; frame.can_dlc = 0x02;      //跳转到电参测试界面查询
        frame.data[0] = 0x06;
        frame.data[1] = 0xee;
        canSend(frame,  wDebug_Surface);

        ui->Key_A->hide();  ui->Key_B->hide();  ui->Key_C->hide();
        ui->Key_D->show();  ui->Key_E->show();  ui->Key_F->show();
        ui->Key_D->setText(tr("接线图"));
        ui->Key_E->setText(tr("保存"));
        ui->Key_F->setText(tr("退出"));
        break;
    case 6:  // 泄漏测试
        ui->Key_A->show();  ui->Key_B->show();  ui->Key_C->hide();
        ui->Key_D->hide();  ui->Key_E->show();  ui->Key_F->show();
        ui->Key_A->setText(tr("调试"));
        ui->Key_B->setText(tr("计算"));
        ui->Key_E->setText(tr("保存"));
        ui->Key_F->setText(tr("退出"));
        break;
    case 7:  // 其他调试
        ui->Key_A->show();  ui->Key_B->show();  ui->Key_C->hide();
        ui->Key_D->hide();  ui->Key_E->show();  ui->Key_F->show();
        ui->Key_A->setText(tr("调试"));
        ui->Key_B->setText(tr("计算"));
        ui->Key_E->setText(tr("保存"));
        ui->Key_F->setText(tr("退出"));
        break;
    case 8:
        //
        break;
    default:
        ui->tabWidget2->setCurrentIndex(0);
        break;
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.4.7
  * brief:      调试电阻数据返回
******************************************************************************/
void w_Debug::R_Debug_DLRData(int data)
{
    double data_double;
    data_double = data;
    if (ui->tabWidget2->currentIndex() == 1) {  //  电阻测试结果返回
        if (ZeroAndDLR == 1) {
            ui->DLRBox_0->setValue(data_double);
        }
        if (ZeroAndDLR == 2) {
            ui->DLRBox->setValue(data_double);
            if (ui->DLRBox->text().toInt() > ui->DLRBox_0->text().toInt()) {
                DLR_Coefficient[ui->DLR_Grade->text().toInt()-1]->setValue\
                        (16384*10000/(ui->DLRBox->text().toInt()-ui->DLRBox_0->text().toInt()));
                DLR_Coefficient[ui->DLR_Grade->text().toInt()-1]->setStyleSheet\
                        ("color:rgb(0, 170,0)");
            } else {
                QMessageBox::warning(this, tr("Warning"), tr("Error"), QMessageBox::Yes);
            }
        }
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.4.7
  * brief:      调试绝缘耐压数据返回
******************************************************************************/
void w_Debug::R_Debug_IWData(double data)
{
    int k = 0, b = 0;
    if (ui->tabWidget2->currentIndex() == 2) {  // 绝缘测试结果返回
        if (IR_Grade != 0) {  //  档位
            if ((IR_Grade%2) == 1) {
                ui->IR_DLR_1->setText(QString::number(data));
            }
            if ((IR_Grade%2) == 0) {
                ui->IR_DLR_2->setText(QString::number(data));
                if ((IR_Grade == 2) && \
                        ((ui->IR_DLR_2->text().toInt()-ui->IR_DLR_1->text().toInt()) > 300)) {
                    k = 400*1024/((ui->IR_DLR_2->text().toInt()-ui->IR_DLR_1->text().toInt()));
                    b = 600-(ui->IR_DLR_1->text().toInt())*k/1024;
                    ui->IR_DLR_Grade1_k->setStyleSheet("color:rgb(0, 170, 0)");
                    ui->IR_DLR_Grade1_k->setValue(k);
                    ui->IR_DLR_Grade1_b->setStyleSheet("color:rgb(0, 170, 0)");
                    ui->IR_DLR_Grade1_b->setValue(b);
                } else if ((IR_Grade == 4) && \
                         ((ui->IR_DLR_2->text().toInt()-ui->IR_DLR_1->text().toInt()) > 300)) {
                    k = 450*1024/((ui->IR_DLR_2->text().toInt()-ui->IR_DLR_1->text().toInt()));
                    b = 550-(ui->IR_DLR_1->text().toInt())*k/1024;
                    ui->IR_DLR_Grade2_k->setStyleSheet("color:rgb(0, 170, 0)");
                    ui->IR_DLR_Grade2_k->setValue(k);
                    ui->IR_DLR_Grade2_b->setStyleSheet("color:rgb(0, 170, 0)");
                    ui->IR_DLR_Grade2_b->setValue(b);
                } else if ((IR_Grade == 6) && \
                           ((ui->IR_DLR_2->text().toInt()-ui->IR_DLR_1->text().toInt()) > 300)) {
                    k = 450*1024/((ui->IR_DLR_2->text().toInt()-ui->IR_DLR_1->text().toInt()));
                    b = 550-(ui->IR_DLR_1->text().toInt())*k/1024;
                    ui->IR_DLR_Grade3_k->setStyleSheet("color:rgb(0, 170, 0)");
                    ui->IR_DLR_Grade3_k->setValue(k);
                    ui->IR_DLR_Grade3_b->setStyleSheet("color:rgb(0, 170, 0)");
                    ui->IR_DLR_Grade3_b->setValue(b);
                } else {
                    //
                }
            }
        }
    }
    if (ui->tabWidget2->currentIndex() == 3) {  //  耐压测试结果返回
        if (IR_Grade != 0) {  //  档位
            if (IR_Grade == 1) {
                ui->ACW_Current_11->setText(QString::number(data));
            }
            if (IR_Grade == 2) {
                ui->ACW_Current_21->setText(QString::number(data));
            }
            if (IR_Grade == 3) {
                ui->ACW_Current_31->setText(QString::number(data));
            }
            if (IR_Grade == 4) {
                ui->ACW_Current_41->setText(QString::number(data));
            }
        }
    } else {
        //
    }
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.4.9
  * brief:      调试绝缘耐压数据发送
  *             测试组号Itemnumb (0/1) 测试型号Type(4/5)  数据 data  档位 Grade
******************************************************************************/
void w_Debug::Debug_TestINS_CAN(int Itemnumb, int Type, int Data, int Grade)
{
    int Freq = 0, DownLimit = 0, Toplimit = 0;
    if (Type == 4) {
        Freq = 0;       // 频率 Freq(50/60/0)
        DownLimit = 0;  // 下限 DownLimit
        Toplimit = 0;   // 上限 Toplimit
    } else if (Type == 5) {
        Freq = 50;      // 频率
        DownLimit = 1;
        Toplimit = 2000;
    } else {
        //
    }
    frame.can_id  = 0x23;
    frame.can_dlc = 0x08;
    frame.data[0] = 0x03;       // 参数1
    frame.data[1] = Itemnumb;   // 组号
    frame.data[2] = Type;       // 型号
    frame.data[3] = 0x00;  frame.data[4] = 0x00;  // 耐压高端
    frame.data[5] = 0xff;  frame.data[6] = 0xff;  // 耐压低端
    frame.data[7] = Freq;       // 频率
    canSend(frame, wDebug_Surface);

    frame.can_id  = 0x23;
    frame.can_dlc = 0x08;
    frame.data[0] = 0x04;       // 参数2
    frame.data[1] = Itemnumb;   // 组号
    frame.data[2] = Data/256;  frame.data[3] = Data%256;  // 电压低字节
    frame.data[4] = 0x00;      frame.data[5] = 0x1e;      // 时间
    frame.data[6] = DownLimit/256;   frame.data[7] = DownLimit%256;
    // 下限耐压单位0.01mA，绝缘单位0.1MΩ
    canSend(frame, wDebug_Surface);

    frame.can_id  = 0x23;
    frame.can_dlc = 0x07;
    frame.data[0] = 0x05;       // 参数3
    frame.data[1] = Itemnumb;   // 组号
    frame.data[2] = Toplimit/256;   frame.data[3] = Toplimit%256;
    // 上限耐压单位0.01mA，绝缘单位0.1MΩ
    frame.data[4] = 0x00;       // 电弧等级
    frame.data[5] = 0x03;       // 缓升
    frame.data[6] = 0x0a;       // 缓降
    canSend(frame, wDebug_Surface);

    frame.can_id = 0x23;
    frame.can_dlc = 0x05;
    frame.data[0] = 0x01;
    frame.data[1] = Type;      // 型号
    frame.data[2] = Grade;     // 档位
    frame.data[3] = 0x13;      // 工位
    frame.data[4] = Itemnumb;  // 组号
    canSend(frame, wDebug_Surface);
}

void w_Debug::on_System_Current_clicked()   //  修改系统配置
{
    int i = 0;
    System_currentProj.clear();
    for (i = 0; i < Out_Board_Number; i++) {  // 判断输出板
        if (SystemConf[i][0]->checkState() == 2) {
            System_currentProj.append(System_Item.at(i));
        } else {
            System_currentProj.append("0");
        }
    }
    System_currentProj.append("0");
    for (i = Out_Board_Number; i < All_Model_Number; i++) {
        // 判断功能板状态  DLR MAG IR ACW DCW IMP  PWR INDL DZ LVS
        if (SystemConf[i][0]->checkState() == 2) {
            System_currentProj.append(System_Item.at(i));
        } else {
           //
        }
    }
    QSettings *set_Test_File = new QSettings(Sys_path,  QSettings::IniFormat);
    set_Test_File->setIniCodec("GB18030");
    set_Test_File->setValue("Allocation/All", QString::number(System_currentProj.size()));
    set_Test_File->setValue("Allocation/Item", QStringList(System_currentProj));\
    system("sync");
    delete set_Test_File;
}

void w_Debug::on_Button_DLR_Check_clicked()
{
    Beep.Time->setSingleShot(TRUE);  //  设置蜂鸣器短促的提示声音
    Beep.Time->start(50);
    Beep_PWM_Start(99);
    frame.can_id = 0x22;  frame.can_dlc = 0x04;
    frame.data[0] = 0x06;
    frame.data[1] = 0xee;
    frame.data[2] = 0x40;
    frame.data[3] = 0x00;
    canSend(frame, wDebug_Surface);
}
void w_Debug::on_Button_DLR_Clear_clicked()
{
    Beep.Time->setSingleShot(TRUE);  //  设置蜂鸣器短促的提示声音
    Beep.Time->start(50);
    Beep_PWM_Start(99);
    frame.can_id = 0x22;  frame.can_dlc = 0x04;
    frame.data[0] = 0x06;
    frame.data[1] = 0xff;
    frame.data[2] = 0x40;
    frame.data[3] = 0x00;
    canSend(frame, wDebug_Surface);
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.6.20
  * brief:      调试电阻KB （）
******************************************************************************/
void w_Debug::Debug_DLR_KB(int Grade, int K)
{
    frame.can_id = 0x22;  frame.can_dlc = 0x04;
    frame.data[0] = 0x06;
    frame.data[1] = Grade;  //  档位
    frame.data[2] = K/256;
    frame.data[3] = int(K)%256;
    canSend(frame, wDebug_Surface);
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.6.9
  * brief:      调试电阻数据发送
  *             数据 data
******************************************************************************/
void w_Debug::Debug_TestDLR_CAN(int data)
{
    frame.can_id = 0x22;  frame.can_dlc = 0x06;
    frame.data[0] = 0x03;
    frame.data[1] = 0;
    frame.data[2] = 1;
    frame.data[3] = 2;
    frame.data[4] = data;
    frame.data[5] = 10;  // 电阻测试时间
    canSend(frame, wDebug_Surface);

    frame.can_id = 0x22;  frame.can_dlc = 0x06;
    frame.data[0] = 0x01;  frame.data[1] = 0x01;  frame.data[2] = 0x00;
    frame.data[3] = 0x13;  frame.data[4] = 0X00;  frame.data[5] = 0X01;
    canSend(frame, wDebug_Surface);
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.6.3
  * brief:      调试匝间KB （设置，查询，清空）
******************************************************************************/
void w_Debug::Debug_IMP_KB(int id, int Grade, int K, int B)
{
    frame.can_id = id;  frame.can_dlc = 0x06;
    frame.data[0] = 0x06;
    frame.data[1] = Grade;
    frame.data[2] = K/256;   // K 数值
    frame.data[3] = K%256;
    frame.data[4] = B/256;   // B 数值
    frame.data[5] = B%256;

    canSend(frame, wDebug_Surface);
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.4.9
  * brief:      调试匝间的电压（int data 1000  2000 2500 4500, int Grade 1 2）
******************************************************************************/
void w_Debug::Debug_TestIMP_CAN(int data, int Grade)
{
    frame.can_id = 0x24; frame.can_dlc = 0x08;
    frame.data[0] = 0x03; frame.data[1] = 0;
    frame.data[2] = 1;   // 测试点
    frame.data[3] = 2;
    frame.data[4] = data/256;  frame.data[5] = data%256;    // 电压
    frame.data[6] = (Grade << 4) + 1;  // 档位
    frame.data[7] = 7;   // 频率
    canSend(frame, wDebug_Surface);

    frame.can_id = 0x24;   frame.can_dlc = 0x05;
    frame.data[0] = 0x01;  frame.data[1] = 0x00; // 0x00测试;0x01自动选频采样;0x02;定频采样;
    frame.data[2] = 0x13;
    frame.data[3] = 0x00;
    frame.data[4] = 0x01;
    canSend(frame, wDebug_Surface);
}
/******************************************************************************
  * version:    1.0
  * author:     jeremy
  * date:       2017.3.15
  * brief:      调试电参KB
******************************************************************************/
void w_Debug::Debug_PWR_KB(int id,  int Grade,  int K1,  int K2, int K3)
{
    frame.can_id = id;  frame.can_dlc = 0x08;
    frame.data[0] = 0x06;
    frame.data[1] = Grade;
    frame.data[2] = K1/256;
    frame.data[3] = K1%256;
    frame.data[4] = K2/256;
    frame.data[5] = K2%256;
    frame.data[6] = K3/256;
    frame.data[7] = K3%256;
    canSend(frame, wDebug_Surface);
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.6.4
  * brief:      调试绝缘和耐压的KB（Numb-----0 绝缘电压 1~3绝缘电阻  4交耐电压  56交耐电流）
******************************************************************************/
void w_Debug::Debug_IR_KB(int Numb, int Count, int K, int B)
{
    int i = 0;
    for (i = Numb; i < Numb + Count; i++) {
        frame.can_id = 0x23;   frame.can_dlc = 0x06;
        frame.data[0] = 0x06;
        frame.data[1] = i;
        frame.data[2] = K/256;   // K 数值
        frame.data[3] = K%256;
        frame.data[4] = B/256;   // B 数值
        frame.data[5] = B%256;
        canSend(frame, wDebug_Surface);
    }
}
void w_Debug::on_Button_Conf_clicked()
{
    QSettings *set_Test_File = new QSettings(Sys_path, QSettings::IniFormat);
    set_Test_File->setIniCodec("GB18030");
    set_Test_File->setValue("Factory/text", ui->text_Factory_number->text());
    set_Test_File->setValue("DCR_In/text", ui->text_Ask_Model->text());
    set_Test_File->setValue("AMP_Temp/text", ui->text_Temp->text());
    set_Test_File->setValue("System/GND", ui->text_GND->text());
    set_Test_File->setValue("System/Unbalance", ui->text_Unbalance->text());
    set_Test_File->setValue("System/IO_Model", ui->IO__Model->text());

    if (ui->checkBox_mag->checkState() == 2) { // 保存转向
        set_Test_File->setIniCodec("GB18030");
        set_Test_File->setValue(QString("MAG/text").toUtf8().data(), \
                                QString("negative").toUtf8().data());
    } else {
        set_Test_File->setIniCodec("GB18030");
        set_Test_File->setValue(QString("MAG/text").toUtf8().data(), \
                                QString("Positive").toUtf8().data());
    }

    if (ui->checkBox_induction->checkState() == 2) { // 保存整机的转向测量方式
        set_Test_File->setValue(QString("PGturn/text").toUtf8().data(), \
                                QString("induction").toUtf8().data());
    } else {
        set_Test_File->setValue(QString("PGturn/text").toUtf8().data(), \
                                QString("hall").toUtf8().data());
    }

    if (ui->checkBox_IR_SetVolt->checkState() == 2) { // 绝缘电压显示方式
        set_Test_File->setValue("Allocation/Set", "2");
    } else {
        set_Test_File->setValue("Allocation/Set", "0");
    }

    if (ui->checkBox_mag_shapehide->checkState() == 2) { // 反嵌波形隐藏
        set_Test_File->setValue("magshapehide/text", "2");
    } else {
        set_Test_File->setValue("magshapehide/text", "0");
    }

    if (ui->checkBox_NG->checkState() == 2) {
        set_Test_File->setValue("NG/text", "2");
    } else {
        set_Test_File->setValue("NG/text", "0");
    }

    if (ui->checkBox_singal->checkState() == 2) {
        set_Test_File->setValue("outsingal/text", "2");
    } else {
        set_Test_File->setValue("outsingal/text", "0");
    }

    if (ui->checkBox_UDP->checkState() == 2) {
        set_Test_File->setValue("UDP/text", "2");
    } else {
        set_Test_File->setValue("UDP/text", "0");
    }

    if (ui->checkBox_nacw->checkState() == 2) {
        set_Test_File->setValue("commonACW/text", "1");
    } else {
        set_Test_File->setValue("commonACW/text", "0");
    }

    if (ui->checkBox_IR_HostJudge->checkState() == 2) { // 上位机判断绝缘
        set_Test_File->setValue("IRHostJudge/text", "2");
    } else {
        set_Test_File->setValue("IRHostJudge/text", "0");
    }

    if (ui->checkBox_9Board->checkState() == 2) { // 9插板状态
        set_Test_File->setValue("BoardNumber/text", "2");
    } else {
        set_Test_File->setValue("BoardNumber/text", "0");
    }

    if (ui->checkBox_PG->checkState() == 2) { // PG电机
        set_Test_File->setValue("System/PG", "PG");
    } else {
        set_Test_File->setValue("System/PG", "Common");
    }

    if (ui->checkBox_WD->checkState() == 2) { // WD电机
        set_Test_File->setValue("System/WD", "WD");
    } else {
        set_Test_File->setValue("System/WD", "Common");
    }

    if (ui->checkBox_new_rot->checkState() == 2) {
        set_Test_File->setValue("System/new_rot", "2");
    } else {
        set_Test_File->setValue("System/new_rot", "0");
    }

    if (ui->checkBox_ACSW->checkState() == 2) {  //  PG电机信号
        set_Test_File->setValue("System/ACSW", "2");
    } else {
        set_Test_File->setValue("System/ACSW", "0");
    }

    if (ui->checkBox_LR->checkState() == 2) { // 左右工位信号反转
        set_Test_File->setValue("System/LR", "2");
    } else {
        set_Test_File->setValue("System/LR", "0");
    }

    if (ui->checkBox_Order->checkState() == 2) { // 左右工位信号
        set_Test_File->setValue("System/Order", "2");
    } else {
        set_Test_File->setValue("System/Order", "0");
    }

    if (ui->checkBox_DCR_Cancle->checkState() == 2) { // 功率测试前取消电阻
        set_Test_File->setValue("System/DCR_Cancle", "2");
    } else {
        set_Test_File->setValue("System/DCR_Cancle", "0");
    }

    if (ui->checkBox_PWR_Turn->checkState() == 2) { // 功率设置正反转
        set_Test_File->setValue("System/Set_Turn", "2");
    } else {
        set_Test_File->setValue("System/Set_Turn", "0");
    }

    if (ui->checkBox_Turn->checkState() == 2) { // 功率转向
        set_Test_File->setValue("System/Turn", "2");
    } else {
        set_Test_File->setValue("System/Turn", "0");
    }

    if (ui->checkBox_Sham_Turn->checkState() == 2) { // 假转子
        set_Test_File->setValue("System/Shan_Turn", "2");
    } else {
        set_Test_File->setValue("System/Shan_Turn", "0");
    }

    if (ui->checkBox_IO->checkState() == 2) {
        set_Test_File->setValue("System/IO", "2");
    } else {
        set_Test_File->setValue("System/IO", "0");
    }

    if (ui->checkBox_LR_Beep->checkState() == 2) {
        set_Test_File->setValue("System/LR_Beep", "2");
    } else {
        set_Test_File->setValue("System/LR_Beep", "0");
    }

    if (ui->checkBox_IO__Test->checkState() == 2) {
        set_Test_File->setValue("System/IO_Test", "2");
    } else {
        set_Test_File->setValue("System/IO_Test", "0");
    }

    if (ui->checkBox_IO__Delay->checkState() == 2) {
        set_Test_File->setValue("System/IO_Delay", "2");
    } else {
        set_Test_File->setValue("System/IO_Delay", "0");
    }

    if (ui->checkBox__KongShi->checkState() == 2) {
        set_Test_File->setValue("KongShi/Enable", "2");
    } else {
        set_Test_File->setValue("KongShi/Enable", "0");
    }

    if (ui->checkBox__DeChang->checkState() == 2) {
        set_Test_File->setValue("DeChang/Enable", "2");
    } else {
        set_Test_File->setValue("DeChang/Enable", "0");
    }

    if (ui->checkBox__W_Connect->checkState() == 2) {
        set_Test_File->setValue("DeChang/Connect", "2");
    } else {
        set_Test_File->setValue("DeChang/Connect", "0");
    }

    if (ui->checkBox__Discharge->checkState() == 2) {
        set_Test_File->setValue("DeChang/Discharge", "2");
    } else {
        set_Test_File->setValue("DeChang/Discharge", "0");
    }

    if (ui->checkBox_IO_Start->checkState() == 2) {
        set_Test_File->setValue("IO/Start_Stop", "2");
    } else {
        set_Test_File->setValue("IO/Start_Stop", "0");
    }

    if (ui->checkBox_IMP_36->checkState() == 2) {
        set_Test_File->setValue("System/IMP_36", "2");
    } else {
        set_Test_File->setValue("System/IMP_36", "0");
    }

    if (ui->checkBox_out6->checkState() == 2) {
        set_Test_File->setValue("System/out6", "2");
    } else {
        set_Test_File->setValue("System/out6", "0");
    }

    if (ui->checkBox_IMP5000->checkState() == 2) {
        set_Test_File->setValue("System/IMP5000", "2");
    } else {
        set_Test_File->setValue("System/IMP5000", "0");
    }

    if (ui->checkBox_IR5000->checkState() == 2) {
        set_Test_File->setValue("System/IR5000", "2");
    } else {
        set_Test_File->setValue("System/IR5000", "0");
    }

    // system("cp /mnt/nandflash/AIP/Sys.ini /mnt/nfs");
    system("sync");
    delete set_Test_File;

    Beep.Time->setSingleShot(TRUE);  //  设置蜂鸣器短促的提示声音
    Beep.Time->start(50);
    Beep_PWM_Start(99);
}

// void w_Debug::on_Button_Ip_clicked()
// {
//    int sock_get_ip;
//    char ipaddr[50];
//    struct   sockaddr_in *sin;
//    struct   ifreq ifr_ip;
//    if ((sock_get_ip = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
//        //
//    }
//    memset(&ifr_ip, 0, sizeof(ifr_ip));
//    strncpy(ifr_ip.ifr_name, "eth0", sizeof(ifr_ip.ifr_name) - 1);
//    if (ioctl(sock_get_ip, SIOCGIFADDR, &ifr_ip) < 0) {
//        //
//    }
//    sin = (struct sockaddr_in *)&ifr_ip.ifr_addr;
//    strcpy(ipaddr, inet_ntoa(sin->sin_addr));
//    ui->Button_Ip->setText(ipaddr);
// }
void w_Debug::Slot_from_Main(QStringList strlist, QString str, int value)
{
    switch (value) {
    case 1:
        //  Debug_slot_from_main_one(strlist);
        break;
    case 2:
        R_Debug_DLRData(str.toInt());
        break;
    case 3:
        R_Debug_IWData(str.toDouble());
        break;
    case 4:
        Slot_Print_TextC(strlist);
        break;
    case 5:
        on_tabWidget2_currentChanged(10);
        break;
    case 6:
        Debug_slot_from_main_six(strlist);
        break;
    case 7:
        Debug_slot_from_main_seven(strlist);
        break;
    case 8:
        Debug_slot_from_main_eight(str);
        break;
    case 9:
        Debug_slot_from_main_nine(strlist);
        break;
    case 10:
        Debug_IMP_Testing_Flag = 1;
        break;
    case 11:
        Debug_slot_from_main_eleven(strlist);
        break;
    case 12:
        Debug_slot_from_main_twlve(strlist, str);
        break;
    case 13:
        Debug_slot_from_main_thirteen(str);
        break;
    case 15:
           ui->IO_BitL->setText(strlist.at(0));
           ui->IO_BitH->setText(strlist.at(1));
           ui->IO_BitHH->setText(strlist.at(2));
        break;
    default:
        break;
    }
}

void w_Debug::Debug_slot_from_main_thirteen(QString str)
{
    if (str == QString(tr("6"))) {
        ui->label_6->setText("校准中");
    } else {
        ui->label_6->setText("完成");
    }
}

void w_Debug::Debug_slot_from_main_twlve(QStringList list, QString str)
{
    switch (str.toInt()) {
    case 0:
        ui->AVola->setValue(QString::number(list.at(0).toInt()).toDouble());
        ui->ACurr->setValue(QString::number(list.at(1).toInt()).toDouble());
        ui->APower->setValue(QString::number(list.at(2).toInt()).toDouble());
        break;
    case 1:
        ui->BVola->setValue(QString::number(list.at(0).toInt()).toDouble());
        ui->BCurr->setValue(QString::number(list.at(1).toInt()).toDouble());
        ui->BPower->setValue(QString::number(list.at(2).toInt()).toDouble());
        break;
    case 2:
        ui->CVola->setValue(QString::number(list.at(0).toInt()).toDouble());
        ui->CCurr->setValue(QString::number(list.at(1).toInt()).toDouble());
        ui->CPower->setValue(QString::number(list.at(2).toInt()).toDouble());
        break;
    default:
        //
        break;
    }
}
void w_Debug::Debug_slot_from_main_eleven(QStringList list)
{
    //    ui->PWRA_Volt->setValue(list.at(0).toDouble());
    //    ui->PWRA_Current->setValue(list.at(1).toDouble());
    //    ui->PWRA_Pwr->setValue(list.at(2).toDouble());
    list.clear();
}
void w_Debug::Debug_slot_from_main_nine(QStringList list)
{
    int can_1 = 0, can_2 = 0, can_3 = 0;
    can_1 = list.at(0).toInt();
    can_2 = list.at(1).toInt();
    can_3 = list.at(2).toInt();

    IMP_Coefficient[(can_1)*2]->setStyleSheet("color:rgb(255, 255, 255)");
    IMP_Coefficient[(can_1)*2]->setValue(can_2*256 + can_3);
    //  wDebug->IMP_Coefficient[(can.frame.data[1])*2+1]->setStyleSheet("color:rgb(255,255,255)");
    //  wDebug->IMP_Coefficient[(can.frame.data[1])*2+1]->setValue(can.frame.data[4]*256+can.frame.data[5]);
}

void w_Debug::Debug_slot_from_main_eight(QString str)
{
    IMP_btnGroup->button(IMP_ID)->setText(str);
}
void w_Debug::Debug_slot_from_main_seven(QStringList list)
{
    int can_1 = 0, can_2 = 0, can_3 = 0;
    can_1 = list.at(0).toInt();
    can_2 = list.at(1).toInt();
    can_3 = list.at(2).toInt();

    DLR_Coefficient[can_1-1]->setStyleSheet("color:rgb(255, 255, 255)");
    DLR_Coefficient[can_1-1]->setValue(can_2*256 + can_3);
}
void w_Debug::Debug_slot_from_main_six(QStringList list)
{
    int can_1, can_2, can_3, can_4, can_5;
    can_1 = list.at(0).toInt();
    can_2 = list.at(1).toInt();
    can_3 = list.at(2).toInt();
    can_4 = list.at(3).toInt();
    can_5 = list.at(4).toInt();

    if (can_1 <= 3) {
        IR_SetValue[can_1*2]->setStyleSheet("color:rgb(255, 255, 255)");
        IR_SetValue[can_1*2]->setValue(can_2*256+can_3);
        IR_SetValue[can_1*2+1]->setStyleSheet("color:rgb(255, 255, 255)");
        IR_SetValue[can_1*2+1]->setValue(can_4*256+can_5);
    } else if (can_1 <= 6) {
        ACW_SetValue[(can_1-4)*2]->setStyleSheet("color:rgb(255, 255, 255)");
        ACW_SetValue[(can_1-4)*2]->setValue(can_2*256+can_3);
        ACW_SetValue[(can_1-4)*2+1]->setStyleSheet("color:rgb(255, 255, 255)");
        ACW_SetValue[(can_1-4)*2+1]->setValue(can_4*256+can_5);
    } else if (can_1 == 10) {
        ACW_SetValue[can_1-4]->setStyleSheet("color:rgb(255, 255, 255)");
        ACW_SetValue[can_1-4]->setValue(can_2*256+can_3);
    } else {
        //
    }
}
void w_Debug::Debug_slot_from_main_one(QStringList list)
{
    int i;
    System_currentProj = list;

    for (i = 0; i < All_Model_Number; i++) {
        SystemConf[i].at(0)->setChecked(false);
    }

    for (i = 0; i < System_currentProj.size(); i++) {
        if (i <= Out_Board_Number) { // 2018-5-30
            if (System_currentProj.at(i).toInt()  !=  0) {
                SystemConf[i][0]->setChecked(true);  //  设置输出板
            }
        } else {
            SystemConf[System_currentProj.at(i).toInt() + 4][0]->setChecked(true);
        }
    }
}

void w_Debug::Slot_TransformCmd(quint16 addr, quint16 cmd, QByteArray data)
{
    cmd = 0;
    switch (addr) {
    case 8:
        Singal_debug_to_main(QStringList(""), 3, 3);
        break;
    case 10:
    //    ui->Print_Text->append(QString(data));
        Singal_debug_to_main(QStringList(""), 4, 4);
        break;
    default:
        break;
    }
}

// void w_Debug::on_pushButton_11_clicked()
// {
//    //    frame.can_id = 0x28;  frame.can_dlc = 0x06;
//    //    frame.data[0] = 0x06;
//    //    frame.data[1] = (int)(ui->ppp1->value());
//    //    frame.data[2] = (int)(ui->pppk->value())/256;  //  K
//    //    frame.data[3] = (int)(ui->pppk->value())%256;
//    //    frame.data[4] = 0x01;  //  B
//    //    frame.data[5] = 0xf4;
//    //    canSend(frame, wDebug_Surface);
// }

void w_Debug::on_pushButton_12_clicked()
{
    frame.can_id  = 0x26;  frame.can_dlc = 0x08;
    frame.data[0] = 0x01;
    frame.data[1] = 0x00;
    frame.data[2] = 0x03;
    frame.data[3] = 0x13;
    frame.data[4] = 0x00;
    frame.data[5] = 0x00;
    frame.data[6] = 0x07;
    frame.data[7] = 0x08;
    canSend(frame, wDebug_Surface);
}

void w_Debug::on_pushButton_13_clicked()   // 查询电感板状态
{
    frame.can_id  = 0x26;  frame.can_dlc = 0x01;
    frame.data[0] = 0x00;
    frame.data[1] = 0x00;
    canSend(frame, wDebug_Surface);
}

void w_Debug::on_pushButton_clicked()
{
    frame.can_id  = 0x2D;  frame.can_dlc = 0x04;
    frame.data[0] = 0xf1;
    frame.data[1] = (1 << (ui->IO_Bit1->text().toInt()));
    frame.data[2] = (1 << (ui->IO_Bit2->text().toInt()));
    frame.data[3] = (1 << (ui->IO_Bit3->text().toInt()));
    canSend(frame, wDebug_Surface);
}
void w_Debug::on_pushButton_IO_In_clicked()
{
    frame.can_id  = 0x2D;  frame.can_dlc = 0x01;
    frame.data[0] = 0xf0;
    canSend(frame, wDebug_Surface);
}


void w_Debug::on_Button_uname_clicked()
{
    struct utsname uts;
    QString QString_uname;

    if (uname(&uts)  >= 0) {
        QString_uname = QString(QLatin1String(uts.release)) + "  " + \
                QString(QLatin1String(uts.machine)) + "  " + \
                QString(QLatin1String(uts.version)) + "  " + \
                QString(QLatin1String(uts.domainname));
        ui->Button_uname->setText(QString_uname);
    } else {
        //
    }
}

void w_Debug::on_Button_uname_2_clicked()
{
    system("cp /mnt/nandflash/AIP/Sys.ini /mnt/Record");
}

