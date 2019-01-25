/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     2.0
 * author:      SL
 * date:        2015.12.10
 * brief:       主界面
*******************************************************************************/
#ifndef PIC_H
#define PIC_H

#include <QApplication>
#include <QDebug>
#include <QTimer>
#include "define.h"
#include "linux_can.h"

#define OUT_R_Station       0x01 // 右工位信号---滑罩
#define OUT_R_Inhale_Air    0x02 // 右工位抽气
#define OUT_R_Exhaust_Air   0x04 // 右工位排气
#define OUT_L_Station       0x08 // 左工位信号---滑罩
#define OUT_L_Inhale_Air    0x10 // 左工位抽气
#define OUT_L_Exhaust_Air   0x20 // 左工位排气
#define OUT_R_Cylinder_Down 0x80 // 右工位气缸下降
#define OUT_R_Cylinder_Up   0x40 // 右工位气缸上升

#define OUT_1               0x01 //
#define OUT_L_Cylinder_Down 0x04 // 左工位气缸下降
#define OUT_L_Cylinder_Up   0x02 // 左工位气缸上升
#define OUT_2               0x08 //
#define OUT_Pumb            0x10 // 真空泵
#define OUT_Horizontal      0x20 // 横向气缸
#define OUT_Vertical        0x80 // 纵向气缸
#define OUT_5               0x40 //

#define OUT_ADD_1           0x01 //
#define OUT_ADD_2           0x02 //
#define OUT_ADD_3           0x04 //
#define OUT_ADD_4           0x08 //
#define OUT_ADD_5           0x10 //
#define OUT_ADD_6           0x20 //

#define IN_R_Start         0x01 // 右工位启动信号
#define IN_R_Stop          0x02 // 右工位停止
#define IN_R_Light_Curtain 0x04 // 右工位光幕
#define IN_L_Start         0x08 // 左工位启动信号
#define IN_L_Stop          0x10 // 左工位停止
#define IN_L_Light_Curtain 0x20 // 左工位光幕
#define IN_R_Inhale_Volt   0x40 // 右工位气压到位
#define IN_R_Exhaust_Volt  0x80 // 右工位气压到位 放气

#define IN_R_Cylinder      0x01 // 右工位气缸到位
#define IN_L_Inhale_Volt   0x02 // 左工位气压到位
#define IN_L_Exhaust_Volt  0x04 // 左工位气压到位 放气
#define IN_L_Cylinder      0x08 // 左工位气缸到位
#define IN_Error_1         0x10 // 相序错误
#define IN_Error_2         0x20 // 热继电器信号
#define IN_Motor_Ready     0x40 // 电机到位信号
#define IN_Vertical_GO     0x80 // 反嵌装置-垂直到位

#define IN_Vertical_Reset   0x01 // 反嵌装置-垂直复位
#define IN_Horizontal_Go    0x02 // 反嵌装置-横向到位
#define IN_Horizontal_Reset 0x04 // 反嵌装置-横向复位
#define IN_ADD_4            0x08 //

#define X00                0x01 //
#define X01                0x02 //
#define X02                0x04 //
#define X03                0x08 //
#define X04                0x10 //
#define X05                0x20 //
#define X10                0x40 //
#define X11                0x80 //

#define X12                0x01 //
#define X13                0x02 //
#define X14                0x04 //
#define X15                0x08 //
#define X20                0x10 //
#define X21                0x20 //
#define X22                0x40 //
#define X23                0x80 //
class pic : public QObject
{
    Q_OBJECT
public:
    pic();
    virtual ~pic();
    int Record_Test;

private:
    LINUX_CAN   can; // -can通信
    can_frame frame; // -can数据信息

    bool Test_IMP; // 测试匝间项目
    bool Test_IR;   bool Test_IR_Finsh;  //　测试绝缘项目　绝缘完成
    bool Test_ACW;  bool Test_ACW_Finsh; //　测试耐压项目　耐压完成
    bool Test_ACW_Finsh_Default; // 耐压真空模式　（默认完成）
    bool Test_MAG; // 测试反嵌项目
    int  BenDuo_Vacuum_Control; // 本多真空

    bool MAG_Drive; // 反嵌驱动
    bool Test_Model_Vacuum; // 测试真空模式
    bool IO_Int; // 第一次接收状态系统初始化
    bool System_ing; // 系统测试中（单步控制）
    bool Current_Test_Window; // 当前测试界面
    bool L_Air_Press_Hold; // 左气压到位
    bool R_Air_Press_Hold; // 右气压到位
    bool IMP_Sample_ing; // 匝间测试中
    bool MAG_Sample_ing; // 反嵌测试中

    bool L_Ready_Inhale_Air; // 左工位准备就绪抽真空
    bool R_Ready_Inhale_Air; // 右工位准备就绪抽真空
    int  IO_in_Change; // IO状态改变
    int  IO_in_H, IO_in_L; int IO_in_H_ADD; // IO端口状态
    int  IO_in_H_State, IO_in_L_State;  int IO_in_H_State_ADD;

    int  Out_Singal_H, Out_Singal_L;
    int  Out_Singal_Add; // 添加信号

    bool L_Stop; // 左工位停止
    bool R_Stop; // 右工位停止
    bool L_Judge_OK; // 左工位判定ｏｋ
    bool R_Judge_OK; // 右工位判定ｏｋ
    bool L_Stop_Push; // 左气缸停止下压
    bool R_Stop_Push; // 右气缸停止下压
    bool L_Test_Product; // 左电机样品到位
    bool R_Test_Product; // 右电机样品到位
    bool Test_Start_Auto; // 自动启动

    bool Test_Start_Auto_Disnable; // 自启动使能
    bool Test_Back_Horizontal;
    bool L_Station_Ok;    bool R_Station_Ok;    // 左右工位ＯＫ
    bool L_Station_Order; bool R_Station_Order; // 左右工位预约
    bool L_Test_Finsh;
    int  Shanr_Turn;
    QTimer *Timer_Order;       //-预约定时
    QTimer *L_Timer_Cylinder_Up; //-左气缸上升复位？
    QTimer *R_Timer_Cylinder_Up; //-右气缸上升复位？
    QTimer *Timer_Real;
    QTimer *IO_Reset;
    bool   NG_Reset;

    double Beep_OK, Beep_NG;
    bool L_Cylinder_Uping;   bool R_Cylinder_Uping;   // 左右气缸上升中
    bool L_Horizontal_Reset; bool R_Horizontal_Reset; // 左右横向复位
    bool Vacuum_Model; // 真空模式
    int  Switchover_Factory; // 判定选择模式
    bool Pneumatic_clamp; // 气动夹子
    bool Connect_Test_Enable;

    void analytical_in(int);
    void Check_Init_State(int, int);
    void Get_H_In(int); void Get_H_In_ADD(int);
    void Get_L_In(int);
    void Get_H_All_In(); void Get_H_All_In_ADD();
    void Get_L_All_In();

    void Get_H_In_Commom(int); void Get_H_In_Commom_ADD(int);
    void Get_L_In_Commom(int);
    void Get_H_All_In_Commom(); void Get_H_All_In_Commom_ADD();
    void Get_L_All_In_Commom();

    void R_Station_Start();
    void R_Cylinder_Down();
    void R_Cylinder_Up();
    void R_Inhale_Air();
    void R_Exhaust_Air();

    void L_Station_Start();
    void L_Cylinder_Down(); void L_Cylinder_Down_True();
    void L_Cylinder_Up();
    void L_Inhale_Air();
    void L_Exhaust_Air();

    void L_Horizontal_Cylinder_Go();
    void L_Horizontal_Cylinder_Back();
    void L_Vertical_Cylinder_Go();
    void L_Vertical_Cylinder_Back();

    void analytical_Item_Enable(QStringList);
    void MAG_Drive_Enable();
    void MAG_Drive_Disable();
    void MAG_Drive_Ready();

    void PLC_CAN_Data(int Data_1, int Data_2, int Data_3);
signals:
    void canSend(can_frame frame, int);
    void Signal_pic_to_Test(QString, int, int);
    void Signal_pic_to_Main(QString, int, int);

public slots:
    void Pubs_from_main(QStringList, int, int);
    void Pubs_from_Switchover(int, int32_t, int);

private slots:
    void Timer_Order_Go();
    void L_Cylinder_Up_Go();
    void R_Cylinder_Up_Go();
    void Cylinder_Real_Back();
    void IO_Join_Reset();
};

#endif // PIC_H
