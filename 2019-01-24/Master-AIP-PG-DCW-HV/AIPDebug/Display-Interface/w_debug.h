/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     2.0
 * author:      SL
 * date:        2015.12.10
 * brief:       主界面
*******************************************************************************/
#ifndef W_debug_H
#define W_debug_H

#include <QDialog>
#include <QLineEdit>
#include <QButtonGroup>
#include <QtDebug>
#include <linux_can.h>
#include <QSpinBox>
#include <QCheckBox>
#include <QColor>
#include <QtGui>

#include <linux_rtc.h>
#include <pwm_api.h>
#include <define.h>
#include <pwr_picture.h>
#include <QLabel>
#include <sys/utsname.h>


namespace Ui {
class w_Debug;
}

class w_Debug : public QDialog
{
    Q_OBJECT
public:
    explicit w_Debug(QWidget *parent = 0);
    ~w_Debug();
    pwr_picture *pwr_pic;

private:
    Ui::w_Debug  *ui;
    QButtonGroup *btnGroup;
    QButtonGroup *DLR_btnGroup;
    QLabel *Debug_Labelhide; //-调试隐藏标签

    QButtonGroup *IR_btnGroup;
    QButtonGroup *ACW_btnGroup;
    QButtonGroup *PWR_btnGroup;
    QList<QCheckBox *> SystemConf[20];
    QStringList        System_Item; // 对系统项目的代号进行编辑
    QList<QCheckBox *> ParameterConf[1];
    can_frame frame;
    QList<QDoubleSpinBox *> DLR_Coefficient;   //  电阻调试系数列表
    QList<QDoubleSpinBox *> IR_SetValue;       //  绝缘 设置参数
    QList<QDoubleSpinBox *> ACW_SetValue;      //  耐压 设置参数
    QList<QDoubleSpinBox *> IMP_SetValue;      //  匝间 设置参数
    QList<QDoubleSpinBox *> IMP_Coefficient;   //  匝间调试系数列表
    QList<QDoubleSpinBox *> PWR_Coefficient;   //  电参调试系数列表
    QButtonGroup *IMP_btnGroup;
    int IMP_ID;
    int Debug_IMP_Testing_Flag;

    struct {
        QTimer *Time;
        int Grade;
        int OK_Time;
        int NG_Time;
        int Flag;
    }Beep;

    int ZeroAndDLR;   //  零点值和电阻值
    int IR_Grade;
    int Button_Start_Flag;
    QStringList System_currentProj;
    QStringList Self_starting; //-设置自启动列表 （启动信号）（左工位 右工位 双工位）（启动时间）

    void Debug_DLR_KB(int Grade, int K);
    void Debug_TestDLR_CAN(int data);
    void Debug_IMP_KB(int id, int Grade, int K, int B);
    void Debug_PWR_KB(int id, int Grade, int K1,  int K2,  int K3);
    void Debug_TestIMP_CAN(int data, int Grade);
    void Debug_IR_KB(int Numb, int Count, int K, int B);
    void Debug_TestINS_CAN(int Itemnumb, int Type, int Data, int Grade);

    void Debug_slot_from_main_one(QStringList list);
    void R_Debug_DLRData(int data);
    void R_Debug_IWData(double data);
    void Slot_Print_TextC(QStringList);
    void Debug_slot_from_main_six(QStringList list);
    void Debug_slot_from_main_seven(QStringList list);
    void Debug_slot_from_main_eight(QString);
    void Debug_slot_from_main_nine(QStringList list);
    void Debug_slot_from_main_eleven(QStringList list);
    void Debug_slot_from_main_twlve(QStringList list, QString str);
    void Debug_slot_from_main_thirteen(QString str);
    void sleep(unsigned int msec);

signals:
    void Singal_debug_to_main(QStringList, int, int);
    void Singal_Save_Debug(QString, QString);
    void canSend(can_frame frame, int);

public slots:
    void Slot_from_Main(QStringList, QString, int);
    void Slot_TransformCmd(quint16 addr, quint16 cmd, QByteArray data);
private slots:
    void ButtonJudge(int);
    void DLRButtonJudge(int);
    void IMPButtonJudge(int);
    void IRButtonJudge(int);
    void ACWButtonJudge(int);
    void PWRButtonJudge(int);
    void on_tabWidget2_currentChanged(int index);
    void on_System_Current_clicked();
    void on_Button_DLR_Check_clicked();
    void on_Button_DLR_Clear_clicked();
    void on_Button_Start_clicked();
    void Beep_Stop();
    void on_Button_Conf_clicked();
    //   void on_Button_Ip_clicked();
    //   void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_clicked();
    void on_pushButton_IO_In_clicked();
    void on_Button_uname_clicked();
    void on_Button_uname_2_clicked();
};

#endif // DIALOG_H



