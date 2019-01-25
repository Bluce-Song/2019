/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "pic.h"

pic::pic()
{
    Test_Model_Vacuum = false;
    IO_Int = false;
    IO_in_Change = 0;
    IO_in_H = 0, IO_in_L = 0;   IO_in_H_ADD = 0;
    IO_in_H_State = 0, IO_in_L_State = 0; IO_in_H_State_ADD = 0;

    Out_Singal_H = 0;
    Out_Singal_L = 0; Out_Singal_Add = 0;

    L_Stop = false;
    R_Stop = false;

    Test_IMP = false;

    Test_IR_Finsh = true;
    Test_ACW_Finsh = true;

    L_Ready_Inhale_Air = false;
    R_Ready_Inhale_Air = false;

    System_ing = false;
    Current_Test_Window = false;

    L_Air_Press_Hold = false;
    R_Air_Press_Hold = false;

    IMP_Sample_ing = false;

    L_Judge_OK = true;
    R_Judge_OK = true;

    L_Stop_Push = false;
    R_Stop_Push = false;

    MAG_Drive = false;
    Test_MAG  = false;

    L_Test_Product = true;
    R_Test_Product = true;
    Test_ACW_Finsh_Default = false;
    Test_Start_Auto = false;

    MAG_Sample_ing = false;

    Test_Start_Auto_Disnable = false;
    Test_Back_Horizontal = false;

    L_Station_Ok = false;
    R_Station_Ok = false;
    L_Station_Order = false;
    R_Station_Order = false;

    Timer_Order = new QTimer(this);
    connect(Timer_Order, SIGNAL(timeout()), this, SLOT(Timer_Order_Go()));

    L_Timer_Cylinder_Up = new QTimer(this);
    connect(L_Timer_Cylinder_Up, SIGNAL(timeout()), this, SLOT(L_Cylinder_Up_Go()));

    R_Timer_Cylinder_Up = new QTimer(this);
    connect(R_Timer_Cylinder_Up, SIGNAL(timeout()), this, SLOT(R_Cylinder_Up_Go()));

    Vacuum_Model = true;
    L_Cylinder_Uping = false;  R_Cylinder_Uping = false;
    L_Horizontal_Reset = true; R_Horizontal_Reset = true;

    Timer_Real = new QTimer(this);
    connect(Timer_Real, SIGNAL(timeout()), this, SLOT(Cylinder_Real_Back()));

    IO_Reset = new QTimer(this);
    connect(IO_Reset, SIGNAL(timeout()), this, SLOT(IO_Join_Reset()));

    BenDuo_Vacuum_Control = 0;
    L_Test_Finsh = false;
    Pneumatic_clamp = false;
    Connect_Test_Enable = true;
    Shanr_Turn = 0;

    Beep_OK = 200;
    NG_Reset = false;
}
pic::~pic() {
    // -
}

void pic::IO_Join_Reset() {
    frame.can_id  = 0x2D;  frame.can_dlc = 0x04; // 绿智 初始气缸复位
    frame.data[0] = 0xf1;
    frame.data[1] = 0x00;
    frame.data[2] = 0x00;
    frame.data[3] = 0x00;
    canSend(frame, 88);
}

void pic::Cylinder_Real_Back() {
    qDebug() << "pic::Cylinder_Real_Back()";
    if (IN_L_Cylinder & IO_in_L) {
        qDebug() << "return---> pic::Cylinder_Real_Back()";
        return;
    } else {
        //
    }
    L_Stop = false;
    if (R_Station_Order) { // 右工位预约
        Timer_Order->setSingleShot(TRUE);
        Timer_Order->start(200); // 定时器200ms, 自启动
    } else {
        //
    }
    if (Test_MAG && MAG_Drive) {
        MAG_Drive_Disable();
    } else {
        //
    }
}
void pic::R_Cylinder_Up_Go() {
    qDebug() << "pic::R_Cylinder_Up_Go()";
    if (R_Cylinder_Uping) {
        R_Cylinder_Uping = false;
    } else {
        //
    }
}

void pic::L_Cylinder_Up_Go() {
    qDebug() << "pic::L_Cylinder_Up_Go()";
    if (L_Cylinder_Uping) {
        L_Cylinder_Uping = false;
        if ((IN_Vertical_Reset) & (IO_in_H_ADD)) { // 垂直复位
            //
        } else {
            L_Vertical_Cylinder_Back();
            qDebug() << "return---> pic::L_Cylinder_Up_Go()";
            return;
        }
        if ((IN_Horizontal_Reset) & (IO_in_H_ADD)) { // 水平复位
            //
        } else {
            L_Horizontal_Cylinder_Back();
        }
    } else {
      //
    }
}


void pic::Timer_Order_Go() {
    int Current_H;
    int Current_State;
    if (L_Station_Order) {
        Record_Test = 0;
        Current_H = IO_in_H;
        Current_State = IO_in_H_State;

        if (Test_IR) {
            Test_IR_Finsh = false;
        } else {
            //
        }
        if (Test_ACW) {
            Test_ACW_Finsh = false;
        } else {
            //
        }

        IO_in_H_State = (IO_in_H_State | IN_L_Start); // 左启动
        IO_in_H = (IO_in_H | IN_L_Start);

        Get_H_In(IN_L_Start);
        IO_in_H_State = Current_State;
        IO_in_H = Current_H;
    } else if (R_Station_Order) {
        Current_H = IO_in_H;
        Current_State = IO_in_H_State;

        if (Test_IR) {
            Test_IR_Finsh = false;
        } else {
            //
        }
        if (Test_ACW) {
            Test_ACW_Finsh = false;
        } else {
            //
        }

        IO_in_H_State = (IO_in_H_State | IN_R_Start); // 右启动
        IO_in_H = (IO_in_H | IN_R_Start);

        Get_H_In(IN_R_Start);
        IO_in_H_State = Current_State;
        IO_in_H = Current_H;
    } else {
        //
    }
}

void pic::analytical_in(int value) {
    int value_H, value_L; int value_H_Add;
    value_L = value%256;
    value_H = value%65536/256;
    value_H_Add = value/65536;
    IO_in_Change = 0;
    if (IO_in_H != value_L) {
        IO_in_Change = 1;
        IO_in_H_State = ((IO_in_H)^(value_L));
        IO_in_H = value_L;
    } else {
        //
    }
    if (IO_in_H_ADD != value_H_Add) {
        IO_in_Change = 100 + IO_in_Change;
        IO_in_H_State_ADD = ((IO_in_H_ADD)^(value_H_Add));
        IO_in_H_ADD = value_H_Add;
    } else {
        //
    }
    if (IO_in_L != value_H) {
        IO_in_Change = 10 + IO_in_Change;
        IO_in_L_State = ((IO_in_L)^(value_H));
        IO_in_L = value_H;
    } else {
       //
    }

    if (!IO_Int) {
        qDebug() << "return---> pic::analytical_in  Io_Int";
        IO_Int = true;
        Check_Init_State(IO_in_H, IO_in_L);
        return;
    } else {
        //
    }

    if (!IO_in_Change) {
        qDebug() << "return---> 2018-01-18---Return---!IO_in_Change";
        return;
    } else {
        //
    }

    if (Vacuum_Model) {
        if (IO_in_Change%10 == 1) {
            Get_H_In(IO_in_H_State);
        }
        if (IO_in_Change%100/10 == 1) {
            Get_L_In(IO_in_L_State);
        }
        if (IO_in_Change/100 == 1) {
            Get_H_In_ADD(IO_in_H_State_ADD);
        }
    } else {
        if (IO_in_Change%10 == 1) {
            Get_H_In_Commom(IO_in_H_State);
        }
        if (IO_in_Change%100/10 == 1) {
            Get_L_In_Commom(IO_in_L_State);
        }
        if (IO_in_Change/100 == 1) {
            Get_H_In_Commom_ADD(IO_in_H_State);
        }
    }
}

void pic::Check_Init_State(int State_H, int State_L) {
    int i;
    int State_H_Change, State_L_Change;
    qDebug() << "Check_Init_State()";
    if ((State_H == 146) && (State_L == 4)) {
        return;
    } else {
        //
    }
    if (Vacuum_Model) {
        //
    } else {
        return;
    }
    if (State_H != 146) {
        State_H_Change = (State_H^146);
        for (i = 0; i < 8; i++) {
            if ((1 << i) & State_H_Change) {
                switch (i) {
                case 0:
                    //
                    break;
                case 1:
                    //
                    break;
                case 2: // 右光幕
                    //    F_R_Light_Curtain = true;
                    break;
                case 3:
                    //
                    break;
                case 4:
                    //
                    break;
                case 5: // 左光幕
                    //    F_L_Light_Curtain = true;
                    break;
                case 6:
                    //
                    break;
                case 7:
                    //
                    break;
                default:
                    //
                    break;
                }
            }
        }
    }
    if (State_L != 4) {
        State_L_Change = (State_L^4);
        for (i = 0; i < 8; i++) {
            if ((1 << i) & State_L_Change) {
                switch (i) {
                case 0: // 右气缸到位
                    //    R_Cylinder_Palce_OK = true; // 右真空罩到位
                    break;
                case 1:
                    //
                    break;
                case 2:
                    //
                    break;
                case 3: // 左气缸到位
                    //    L_Cylinder_Palce_OK = true; // 左真空罩到位
                    break;
                case 4:
                    Signal_pic_to_Main(QString(""), 14, 7);
                    break;
                case 5:
                    Signal_pic_to_Main(QString(""), 15, 7);
                    break;
                case 6:
                    //
                    break;
                case 7:
                    //
                    break;
                default:
                    //
                    break;
                }
            }
        }
    }
    PLC_CAN_Data(0x40, 0x02, 0x00); // 2018-01-12 真空罩上升
    usleep(1000);
    qDebug() << "pic::Check_Init_State   IO Reset";
}

void pic::Pubs_from_main(QStringList io_List, int value, int flag) {
    if (Vacuum_Model) {
        qDebug() << "pic::Pubs_from_main" << Vacuum_Model << \
                    io_List << value << flag;
    } else {
        qDebug() << "return---> pic::Pubs_from_main" << flag;
        if (flag == 1) {
            analytical_in(value);
        } else if (flag == 1000) {
            Beep_OK = io_List.at(1).toDouble() * 1000;
        } else {
            //
        }
        return;
    }
    int Current_State;
    int Current_H;
    switch (flag) {
    case 0:
        Vacuum_Model = value;
        break;
    case 1:
        analytical_in(value);
        break;
    case 2:
        L_Test_Finsh = true;
        L_Judge_OK = value;

        L_Air_Press_Hold = false;
        Out_Singal_H = Out_Singal_H & (~OUT_L_Station); // 断工位信号(蜂鸣器)
        Out_Singal_H = Out_Singal_H & (~OUT_L_Inhale_Air); // L-关闭吸气
        Out_Singal_H = Out_Singal_H | OUT_L_Exhaust_Air;
        PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
        if (Test_Model_Vacuum) { // 放气
            if (L_Stop) {
                L_Cylinder_Up();
            } else {
                L_Exhaust_Air();
            }
        } else {
            if (Test_MAG && MAG_Drive) {
                MAG_Drive_Disable();
            } else {
                //
            }
        }
        break;
    case 3:
        R_Judge_OK = value;

        R_Air_Press_Hold = false;
        Out_Singal_H = Out_Singal_H & (~OUT_R_Station);
        Out_Singal_H = Out_Singal_H & (~OUT_R_Inhale_Air);
        Out_Singal_H = Out_Singal_H | OUT_R_Exhaust_Air;
        PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);

//        if (!Test_IMP) { // 调试海立时，删除（右工位存在Ｂｕｇ）
//            qDebug() <<"11111";
//            break;
//        }
        if (Test_Model_Vacuum) { // 放气
            if (R_Stop) {
                R_Cylinder_Up();
            } else {
                R_Exhaust_Air();
            }
        } else {
            //
        }
        break;
    case 5:
        if (value/10) { // 耐压
            if (value%10 == 1) { // 耐压真空模式判定
                Test_ACW_Finsh_Default = true;
            } else {
                Test_ACW_Finsh_Default = false;
            }
        } else { // 匝间
            if (value%10 == 1) { // 匝间真空模式判定
                Out_Singal_L = Out_Singal_L | (OUT_Pumb); // 打开真空泵；
                PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
            } else {
                Out_Singal_L = Out_Singal_L & (~OUT_Pumb); // 关闭真空泵；
                PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
            }
        }
        break;
    case 6:
        if (value/10) {
            Test_IR_Finsh  = true;  Test_ACW_Finsh = true; // 测试绝缘完成 测试耐压完成

            System_ing = true; IMP_Sample_ing = true;
            if (value == 19) {
                L_Cylinder_Down(); L_Stop = false;
            } else if (value == 20) {
                R_Cylinder_Down(); R_Stop = false;
            } else {
                //
            }
        } else {
            System_ing = false; IMP_Sample_ing = false;
            L_Stop_Push = true; L_Exhaust_Air();
            R_Stop_Push = true; R_Exhaust_Air();
        }
        break;
    case 7:
        analytical_Item_Enable(io_List);
        break;
    case 8:
        if (System_ing) {
            // 测试中
        } else {
            L_Ready_Inhale_Air = false;
            R_Ready_Inhale_Air = false;
            break;
        }
        if (value == 3) {
            Test_IR_Finsh = true;
        } else if (value == 4) {
            Test_ACW_Finsh = true;
        } else {
            //
        }
        if ((Test_IR_Finsh) && (Test_ACW_Finsh)) {
            if (Test_Model_Vacuum) { // 测试匝间
                //
            } else {
                break;
            }
            if (L_Ready_Inhale_Air) {
                L_Ready_Inhale_Air = false;
                if (L_Stop) {
                    break;
                }
                L_Inhale_Air();
            } else if (R_Ready_Inhale_Air) {
                R_Ready_Inhale_Air = false;
                if (R_Stop) {
                    break;
                }
                R_Inhale_Air();
            } else {
                //
            }
        }
        break;
    case 9:
        System_ing = true;
        if (value) {
           MAG_Drive_Enable(); // 反嵌的驱动方式控制
        } else {
           MAG_Drive_Disable();
           System_ing = false;
        }
        break;
    case 10:
        //
        break;
    case 11:
        if (value/10 == 19) { // 左工位
            if (value%10 == 1) {
                L_Station_Ok = true;
            } else {
                L_Station_Ok = false;
            }
        } else if (value/10 == 20) { // 右工位
            if (value%10 == 1) {
                R_Station_Ok = true;
            } else {
                R_Station_Ok = false;
            }
        } else {
            //
        }
        if (value%10 == 1) {
            qDebug() << "System___ing True 测试完成"; // 测试中
            System_ing = true;
            if (value/10 == 19) { // 左工位
                L_Judge_OK = false;
            } else if (value/10 == 20) {
                R_Judge_OK = false;
            } else {
                //
            }
        } else {
            System_ing = false; qDebug() << "System____ing False 测试完成"; // 测试完成
        }
        break;
    case 12:
        if (value == 2) {
            Test_Model_Vacuum = false;
            Out_Singal_L = Out_Singal_L & (~OUT_Pumb); // 关闭真空泵；
            PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
            break;
        } else {
            //
        }
        if (value) {
            Test_Model_Vacuum = true;
            Out_Singal_L = Out_Singal_L | (OUT_Pumb); // 打开真空泵；
        } else {
            Test_Model_Vacuum = false;
            Out_Singal_L = Out_Singal_L & (~OUT_Pumb); // 关闭真空泵；
        }
        PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
        break;
    case 13:
        if (value == 1) {
            Current_Test_Window = true;
        } else {
            Current_Test_Window = false;
        }
        break;
    case 15:
        Record_Test = 0;
        Current_H = IO_in_H;
        Current_State = IO_in_H_State;
        if (value == 1) {
            IO_in_H_State = (IO_in_H_State | IN_R_Start); // 右启动
            IO_in_H = (IO_in_H | IN_R_Start);
            Get_H_In(IN_R_Start);
        } else {
            IO_in_H_State = (IO_in_H_State | IN_L_Start); // 左启动
            IO_in_H = (IO_in_H | IN_L_Start);
            Get_H_In(IN_L_Start);
        }
        IO_in_H_State = Current_State;
        IO_in_H = Current_H;
        break;
    case 17:
        Current_H = IO_in_H;
        Current_State = IO_in_H_State;
        if (value == 1) {
            IO_in_H_State = (IO_in_H_State | IN_R_Stop ); // 右停止
            IO_in_H = (IO_in_H | IN_R_Stop );
            Get_H_In(IN_R_Stop);
        } else {
            IO_in_H_State = (IO_in_H_State | IN_L_Stop ); // 左停止
            IO_in_H = (IO_in_H | IN_L_Stop );
            Get_H_In(IN_L_Stop);
        }
        IO_in_H_State = Current_State;
        IO_in_H = Current_H;
        break;
    case 18:
        Signal_pic_to_Main(QString(""), Out_Singal_L*256+Out_Singal_H, 6);
        break;
    case 19:
        if (value) {
            Test_Start_Auto = true;
            L_Test_Product  = false;
        } else {
            Test_Start_Auto = false;
            L_Test_Product  = true;
        }
        break;
    case 20:
        //
        break;
    case 21:
        L_Horizontal_Reset = true;
        R_Horizontal_Reset = true;
        L_Cylinder_Uping = false;
        R_Cylinder_Uping = false;

        L_Station_Ok = false;
        R_Station_Ok = false;

        System_ing = false;
        break;
    case 22:
        if (value) {
            Pneumatic_clamp = true;
        } else {
            Pneumatic_clamp = false;
        }
        qDebug() << "22" << Pneumatic_clamp;
        break;
    case 23:
        if (value == 0x13) {
            L_Air_Press_Hold = false;
            Out_Singal_H = Out_Singal_H & (~OUT_L_Inhale_Air); // L-关闭吸气
            Out_Singal_H = Out_Singal_H | OUT_L_Exhaust_Air;
            PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
        } else if (value == 0x14) {
            R_Air_Press_Hold = false;
            Out_Singal_H = Out_Singal_H & (~OUT_R_Inhale_Air); // R-关闭吸气
            Out_Singal_H = Out_Singal_H | OUT_R_Exhaust_Air;
            PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
        } else {
            L_Air_Press_Hold = false;
            Out_Singal_H = Out_Singal_H & (~OUT_L_Inhale_Air); // L-关闭吸气
            Out_Singal_H = Out_Singal_H | OUT_L_Exhaust_Air;
            PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
        }

        break;
    case 24:
        if (value) {
            Connect_Test_Enable = false;
        } else {
            Connect_Test_Enable = true;
        }
        break;
    case 119:
        Switchover_Factory = value; // 初始获取IO配置
        if (Switchover_Factory == LvZhi) {
            frame.can_id  = 0x2D;  frame.can_dlc = 0x03;
            frame.data[0] = 0xf1;
            frame.data[1] = 0x00;
            frame.data[2] = 0x00;
            canSend(frame, 88);
        }
        break;
    case 121:
        NG_Reset = value;
        break;
    default:
        //
        break;
    }
}

void pic::analytical_Item_Enable(QStringList Item_List) {
    qDebug() << "pic::analytical_Item_Enable" << Item_List;
    if (Item_List.at(0).toInt() == 1) { // 匝间
        Test_IMP = true;
    } else {
        Test_IMP = false;
    }

    if (Item_List.at(1).toInt() == 1) { // 绝缘
        Test_IR = true;
    } else {
        Test_IR = false;
        Test_IR_Finsh = true;
    }

    if (Item_List.at(2).toInt() == 1) { // 交耐
        Test_ACW = true;
    } else {
        Test_ACW = false;
        Test_ACW_Finsh = true;
    }

    if (Item_List.at(3).toInt() == 1) { // 反嵌
        Test_MAG = true;
    } else {
        Test_MAG = false;
    }

    if (Item_List.at(4).toInt() == 1) { // 反嵌驱动-美芝项目
        MAG_Drive = true;
    } else {
        MAG_Drive = false;
        L_Horizontal_Reset = true;
        R_Horizontal_Reset = true;
    }
}

void pic::Pubs_from_Switchover(int Factory, int32_t value, int chose) {
    qDebug() << "pic::Pubs_from_Switchover" \
             << Switchover_Factory << Factory << value << chose;
    if (Switchover_Factory != Factory) {
        qDebug() << "return---> Switchover_Factory != Factory";
        return;
    }

    switch (chose) {
    case 0x01:
        frame.can_id  = 0x2D;  frame.can_dlc = 0x04;
        frame.data[0] = 0xf1;
        frame.data[1] = value % 256;
        frame.data[2] = value % 65536 / 256;
        frame.data[3] = value / 65536;
        canSend(frame, 88);
        break;
    case 0x02:
        frame.can_id  = 0x2D;  frame.can_dlc = 0x03; // 绿智 初始气缸复位
        frame.data[0] = 0xf1;
        frame.data[1] = value - 18;
        frame.data[2] = 0x00;
        canSend(frame, 88);
        break;
    case 0x03:
        frame.can_id  = 0x2D;  frame.can_dlc = 0x03; // 绿智 初始气缸复位
        frame.data[0] = 0xf1;
        frame.data[1] = value - 18;
        frame.data[2] = 0x00;
        canSend(frame, 88);
        IO_Reset->setSingleShot(TRUE);
        IO_Reset->start(Beep_OK); // 启动定时器,100Ms
        break;
    case 0x05:
        frame.can_id  = 0x2D;  frame.can_dlc = 0x03; // 南新 初始气缸复位
        frame.data[0] = 0xf1;
        frame.data[1] = (value - 18) * 8;
        frame.data[2] = 0x00;
        canSend(frame, 88);
        break;
    case 0x06:
        frame.can_id  = 0x2D;  frame.can_dlc = 0x03; // 日电产凯宇 下压气缸复位
        frame.data[0] = 0xf1;
        frame.data[1] = value;
        frame.data[2] = 0x00;
        canSend(frame, 88);
        break;
    case 0x07:
        frame.can_id  = 0x2D;  frame.can_dlc = 0x04; // 噪音测试
        frame.data[0] = 0xf1;
        frame.data[1] = value;
        frame.data[2] = 0x00;
        frame.data[3] = 0x00;
        canSend(frame, 88);
        break;
    case 0x09:
        frame.can_id  = 0x2D;  frame.can_dlc = 0x04; //
        frame.data[0] = 0xf1;
        frame.data[1] = (Out_Singal_H);

        if (value == 0) {
            BenDuo_Vacuum_Control = 0;
            frame.data[2] = (Out_Singal_L);
            frame.data[3] = (Out_Singal_Add);
        } else if (value == 1) {
            BenDuo_Vacuum_Control = 1;
            frame.data[2] = (0x40 | Out_Singal_L);
            frame.data[3] = (Out_Singal_Add);
        } else if (value == 2) {
            BenDuo_Vacuum_Control = 2;
            frame.data[2] = (Out_Singal_L);
            frame.data[3] = (0x02 | Out_Singal_Add);
        } else {
            BenDuo_Vacuum_Control = 0;
            frame.data[2] = (Out_Singal_L);
            frame.data[3] = (Out_Singal_Add);
        }
        canSend(frame, 88);
        break;
    case 12:
        frame.can_id  = 0x2D;  frame.can_dlc = 0x03; //
        frame.data[0] = 0xf1;
        frame.data[1] = value - 18;
        frame.data[2] = 0x00;
        canSend(frame, 88);
        break;
    case 13:
        frame.can_id  = 0x2D;  frame.can_dlc = 0x04; //
        frame.data[0] = 0xf1;
        if (value/100) {
            if (value%100 == 0x13) {
                frame.data[1] = 0x01;
            } else if (value%100 == 0x14) {
                frame.data[1] = 0x08;
            } else {
                frame.data[1] = 0x00;
            }
        } else {
            if (value%100 == 0x13) {
                frame.data[1] = 0x02;
            } else if (value%100 == 0x14) {
                frame.data[1] = 0x10;
            } else {
                frame.data[1] = 0x00;
            }
        }
        frame.data[2] = 0x00;
        frame.data[3] = 0x00;
        canSend(frame, 88);
        break;
    case 16:
        frame.can_id  = 0x2D;  frame.can_dlc = 0x04; //
        frame.data[0] = 0xf1;
        frame.data[1] = value % 256;
        frame.data[2] = value % 65536 / 256;
        frame.data[3] = value / 65536;
        canSend(frame, 88);
        break;
    case 17:
        Shanr_Turn = value - 18;
        PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
        break;
    case 18:
        frame.can_id  = 0x2D;  frame.can_dlc = 0x03;
        frame.data[0] = 0xf1;
        frame.data[1] = (value - 19)*7 + 1;
        frame.data[2] = 0x00;
        canSend(frame, 88);
        IO_Reset->setSingleShot(TRUE);
        IO_Reset->start(Beep_OK);
        break;
    default:
        //
        break;
    }
}

void pic::Get_H_All_In_Commom() {
    int i;
    qDebug() << "pic::Get_H_All_In_Commom()";
    for (i = 0; i < 8; i++) {
        if ((1 << i) & IO_in_H_State) {
            Get_H_In_Commom(1 << i);
        }
    }
}

void pic::Get_H_In_Commom(int in_h) {
     switch (in_h) {
     case X00:
         if (X00 & IO_in_H) {
             Signal_pic_to_Test(QString(""), 1, 1);
         } else {
             //
         }
         break;
     case X01:
         if (X01 & IO_in_H) {
             Signal_pic_to_Test(QString(""), 2, 2);
         } else {
             //
         }
         break;
     case X02:
         if (X02 & IO_in_H) {
             Signal_pic_to_Test(QString(""), 3, 3);
         } else {
             //
         }
         break;
     case X03:
         if (X03 & IO_in_H) {
             Signal_pic_to_Test(QString(""), 4, 4);
         } else {
             //
         }
         break;
     case X04:
         if (X04 & IO_in_H) {
             Signal_pic_to_Test(QString(""), 5, 5);
         } else {
             //
         }
         break;
     case X05:
         if (X05 & IO_in_H) {
             Signal_pic_to_Test(QString(""), 1, 6);
         } else {
             Signal_pic_to_Test(QString(""), 0, 6);
         }
         break;
     case X10:
         if (X10 & IO_in_H) {
             Signal_pic_to_Test(QString(""), 1, 7);
         } else {
             Signal_pic_to_Test(QString(""), 0, 7);
         }
         break;
     default:
         Get_H_All_In_Commom();
         break;
     }
}

void pic::Get_L_In_Commom(int in_h) {
     //
    in_h = 0;
}

void pic::Get_H_In_Commom_ADD(int in_h) {
    switch (in_h) {
    case 0x08:
        if (0x08 & IO_in_H_ADD) {
            Signal_pic_to_Test(QString(""), 0, 8);
        } else {
            //
        }
        break;
    }
}

void pic::Get_H_All_In_ADD() {
    int i;
    for (i = 0; i < 8; i++) {
        if ((1 << i) & IO_in_H_State_ADD) {
            Get_H_In_ADD(1 << i);
        }
    }
}

void pic::Get_H_In_ADD(int in_h_add) {
    switch (in_h_add) {
    case IN_Vertical_Reset:
        if (IN_Vertical_Reset & IO_in_H_ADD) {
            qDebug() << "pic::Get_H_In_ADD  IN_Vertical_Reset";
        } else {
            return;
        }

        if (System_ing) { // 防止在单个信号控制时，进行动作
            L_Horizontal_Cylinder_Back();
        } else if (Test_Back_Horizontal) {
            Test_Back_Horizontal = false;
            L_Horizontal_Cylinder_Back();
        } else if (MAG_Sample_ing) {
            MAG_Sample_ing = false;
            L_Horizontal_Cylinder_Back();
        } else {
            return;
        }
        break;
    case IN_Horizontal_Go:
        if (IN_Horizontal_Go & IO_in_H_ADD) {
            qDebug() << "pic::Get_H_In_ADD  IN_Horizontal_Go";
        } else {
            return;
        }
        if (System_ing) { // 防止在单个信号控制时，进行动作
            L_Vertical_Cylinder_Go();
        } else {
            return;
        }
        break;
    case IN_Horizontal_Reset:
        if (IN_Horizontal_Reset & IO_in_H_ADD) {
            qDebug() << "pic::Get_H_In_ADD  IN_Horizontal_Reset if";
            L_Horizontal_Reset = true;
        } else {
            qDebug() << "return---> pic::Get_H_In_ADD  IN_Horizontal_Reset else";
            L_Horizontal_Reset = true;
            return;
        }
        if (System_ing) { // 防止在单个信号控制时，进行动作
            //
        } else {
            return;
        }
        break;
    case IN_ADD_4:
        if (IN_ADD_4 & IO_in_H_ADD) {
            qDebug() << "pic::Get_H_In_ADD  IN_ADD_4";
        } else {
            //
        }
        break;
    default:
        Get_H_All_In_ADD();
        break;
    }
}

void pic::Get_H_All_In() {
    int i;
    for (i = 0; i < 8; i++) {
        if (i == 5) {
            if ((0 << i) & IO_in_H_State) {
                Get_H_In(1 << i);
            }
        } else if (i == 2) {
            if ((0 << i) & IO_in_H_State) {
                Get_H_In(1 << i);
            }
        } else {
            if ((1 << i) & IO_in_H_State) {
                qDebug() << "pic::Get_H_All_In()" << i;
                Get_H_In(1 << i);
            }
        }
    }
}

void pic::Get_H_In(int in_h) {
    int Current_State;
    int Current_H;
    switch (in_h) {
    case IN_R_Light_Curtain:
        if (IN_R_Light_Curtain & IO_in_H) {
            qDebug() << "Get_H_In   IN_R_Light_Curtain";
            if (IN_R_Cylinder & IO_in_L) { // 右真空罩到位
                //
            } else {
                R_Stop_Push = true;
                if (IMP_Sample_ing) {
                    R_Cylinder_Up();
                } else if (R_Station_Order) {
                    R_Station_Order = false;
                    R_Cylinder_Up();
                } else {
                    R_Stop = true;
                    Out_Singal_H = Out_Singal_H & (~OUT_R_Station);
                    Out_Singal_H = Out_Singal_H & (~OUT_R_Cylinder_Down); //
                    PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
                }
            }
        } else {
            qDebug() << "Get_H_In  false";
//            if (Test_Start_Auto_Disnable) { // 暂时不加
//                qDebug() << "Test_Start_Auto_Disnable return";
//                Test_Start_Auto_Disnable = false;
//                return;
//            } else {
//                //
//            }
//            if ((R_Test_Product) && (Test_Start_Auto)) {
//                Current_H = IO_in_H;
//                Current_State = IO_in_H_State;
//                IO_in_H_State = IN_R_Start; // 左启动
//                IO_in_H = IN_R_Start;
//                Get_H_In(IO_in_H_State);

//                IO_in_H_State = Current_State;
//                IO_in_H = Current_H;
//            } else {
//                if (Test_Start_Auto) {
//                   Signal_pic_to_Main(QString(""), 18, 10);
//                } else {
//                    //
//                }
//                qDebug() << "R_Test_Product" << R_Test_Product <<\
//                            "Test_Start_Auto" << Test_Start_Auto;
//            }
        }
        break;
    case IN_L_Light_Curtain:
        if (IN_L_Light_Curtain & IO_in_H) {
            qDebug() << "Get_H_In  IN_L_Light_Curtain" << System_ing;
            if (IN_L_Cylinder & IO_in_L) { // 2018-01-12 左真空罩到位
                //
            } else {
                L_Stop_Push = true;
                if (IMP_Sample_ing) {
                    L_Cylinder_Up();
                } else if (L_Station_Order) {
                    L_Station_Order = false;
                    L_Cylinder_Up();
                } else {
                    L_Stop = true;
                    Out_Singal_H = Out_Singal_H & (~OUT_L_Station); // 断工位信号
                    Out_Singal_L = Out_Singal_L & (~OUT_L_Cylinder_Down); //
                    PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
                }
            }
            if (System_ing) {
                Test_Start_Auto_Disnable = true;
            }
        } else {
            qDebug() << "Get_H_In  IN_L_Light_Curtain  false";
            Record_Test = 0;
            Record_Test = Record_Test | 0x1000;
            if (Test_Start_Auto_Disnable) {
                qDebug() << "return---> Get_H_In  IN_L_Light_Curtain  Test_Start_Auto_Disnable";
                Test_Start_Auto_Disnable = false;
                Record_Test = Record_Test | 0x2000;
                return;
            } else {
                //
            }
            if ((L_Test_Product) && (Test_Start_Auto)) {
                Current_H = IO_in_H;
                Current_State = IO_in_H_State;
                Record_Test = Record_Test | 0x4000;
                IO_in_H_State = (IO_in_H_State | IN_L_Start); // 左启动
                IO_in_H = (IO_in_H | IN_L_Start);
                Get_H_In(IN_L_Start);

                IO_in_H_State = Current_State;
                IO_in_H = Current_H;
            } else {
                Record_Test = Record_Test | 0x8000;
                if (Test_Start_Auto) {
                   Signal_pic_to_Main(QString(""), 18, 10);
                } else {
                    //
                }
                qDebug() << "Get_H_In  IN_L_Light_Curtain  L_Test_Product" << L_Test_Product <<\
                            "Get_H_In  IN_L_Light_Curtain  Test_Start_Auto" << Test_Start_Auto;
            }
        }
        break;
    case IN_R_Start:
        if (Connect_Test_Enable) {

        } else {
            Signal_pic_to_Main(QString(""), 18, 11);
            break;
        }

        if (Current_Test_Window) {
            qDebug() << "Get_H_In  IN_R_Start  R-2";  //
        } else {
            qDebug() << "Get_H_In  IN_R_Start  R-3";  //
            break;
        }
        if (IN_R_Light_Curtain & IO_in_H) {
            qDebug() << "Get_H_In  IN_R_Start  R-R_Light_Curtain  -----Return";
            break;
        } else {
            //
        }
        if ((R_Cylinder_Uping) || (!R_Horizontal_Reset)) {
            qDebug() << "Get_H_In  IN_R_Start   R-return----" \
                     << R_Cylinder_Uping << R_Horizontal_Reset;
            break;
        } else {
            //
        }
        if (R_Test_Product) {
            qDebug() << "Get_H_In  IN_R_Start  R_Test_Product -----Return";
        } else {
            Signal_pic_to_Main(QString(""), 18, 10);
            break;
        }
        if (IN_R_Start & IO_in_H) {
            qDebug() << "Get_H_In  IN_R_Start  R-Start";
            if (System_ing) {
                if (R_Station_Ok) { // 当前工位测试中
                    qDebug() << "Get_H_In  IN_R_Start  R-5";
                    break;
                } else {
                    R_Station_Order = true; // 右工位进入预约状态->右工位真空泵下落
                    if (Test_Model_Vacuum) {
                        R_Ready_Inhale_Air = false;
                        R_Cylinder_Down();
                        R_Stop_Push = false;
                        R_Stop = false;
                    } else {
                        //
                    }
                    qDebug() << "Get_H_In  IN_R_Start  R-6";
                    break;
                }
            } else {
                qDebug() << "Get_H_In  IN_R_Start  R-7";  //
            }

            if (NG_Reset) {
                if (L_Judge_OK) {
                    //
                } else {
                    Signal_pic_to_Main(QString("Reset L Station"), 18, 12);
                    break;
                }
            } else {
                //
            }


            if (R_Station_Order) {
                qDebug() << "Get_H_In  IN_R_Start  R_Station_Order";
            } else {
                qDebug() << "Get_H_In  IN_R_Start  !!! R_Station_Order";
                if (IN_R_Cylinder & IO_in_L) {
                    qDebug() << "R-8";
                    break;
                } else {
                    //
                }
            }


            R_Station_Order = false;
            R_Stop = false;
            R_Station_Start();
            if (Test_Model_Vacuum) {
                R_Ready_Inhale_Air = false;
                R_Cylinder_Down();
                R_Stop_Push = false;
                R_Stop = false;
            } else {
                //
            }
            if (Test_IR) {
                Test_IR_Finsh = false;
            } else {
                //
            }
            if (Test_ACW) {
                Test_ACW_Finsh = false;
            } else {
                //
            }
            if (Test_ACW_Finsh_Default) {
                Test_ACW_Finsh = true;
            } else {
                qDebug() << "Get_H_In  IN_R_Start  R-10";  //  -
            }
        } else {
            qDebug() << "Get_H_In  IN_R_Start  R-9";  //
        }
        break;
    case IN_L_Start:
        L_Test_Finsh = false;
        Record_Test = Record_Test | 0x0800;

        if (Connect_Test_Enable) {

        } else {
            Signal_pic_to_Main(QString(""), 18, 11);
            break;
        }

        if (Current_Test_Window) {
            qDebug() << "Get_H_In  IN_L_Start  L-2"; //
        } else {
            qDebug() << "Get_H_In  IN_L_Start  L-3"; //
            Record_Test = Record_Test | 0x0001;
            break;
        }
        if (IN_L_Light_Curtain & IO_in_H) {
            qDebug() << "Get_H_In  IN_L_Start  L-L_Light_Curtain -----Return";
            Record_Test = Record_Test | 0x0002;
            break;
        } else {
            //
        }
        if ((L_Cylinder_Uping) || (!L_Horizontal_Reset)) {
            qDebug() << "Get_H_In  IN_L_Start  L-return----L" \
                     << L_Cylinder_Uping << L_Horizontal_Reset;
            Record_Test = Record_Test | 0x0004;
            break;
        } else {
            //
        }
        if (L_Test_Product) {
            qDebug() << "Get_H_In  IN_L_Start  L_Test_Product -----Return";
        } else {
            qDebug() << "Get_H_In  IN_L_Start  4";  //
            Signal_pic_to_Main(QString(""), 18, 10);
            Record_Test = Record_Test | 0x0008;
            break;
        }
        if (IN_L_Start & IO_in_H) {
            qDebug() << "Get_H_In  IN_L_Start  L-Start";
            if (System_ing) {
                if (L_Station_Ok) { // 当前工位测试中
                    qDebug() << "Get_H_In  IN_L_Start  L-5";
                    Record_Test = Record_Test | 0x0010;
                    break;
                } else {
                    L_Station_Order = true; // 左工位进入预约状态->左工位真空泵下落
                    if (Test_Model_Vacuum) {
                        L_Ready_Inhale_Air = false;
                        L_Cylinder_Down();
                        L_Stop_Push = false;
                        L_Stop = false;
                    } else {
                        //
                    }
                    Record_Test = Record_Test | 0x0020;
                    qDebug() << "Get_H_In  IN_L_Start  L-6";
                    break;
                }
            } else {
                //
            }

            if (NG_Reset) {
                if (R_Judge_OK) {
                    //
                } else {
                    Signal_pic_to_Main(QString("Reset R Station"), 18, 12);
                    break;
                }
            } else {
                //
            }


            if (L_Station_Order) {
                qDebug() << "Get_H_In  IN_L_Start  L_Station_Order";
            } else {
                qDebug() << "Get_H_In  IN_L_Start  !!! L_Station_Order";
                if (IN_L_Cylinder & IO_in_L) {
                    Record_Test = Record_Test | 0x0040;
                    qDebug() << "Get_H_In  IN_L_Start  L-7";
                    break;
                } else {
                    qDebug() << "Get_H_In  IN_L_Start  L-8"; //
                }
            }

            Record_Test = Record_Test | 0x0080;
            L_Station_Order = false;
            L_Stop = false;
            L_Station_Start();
            Record_Test = Record_Test | 0x0100;
            if (Test_Model_Vacuum) {
                L_Ready_Inhale_Air = false;
                L_Cylinder_Down();
                L_Stop_Push = false;
                L_Stop = false;
            } else {
                if (Test_MAG && MAG_Drive) {
                    qDebug() << "Get_H_In  IN_L_Start  启动反嵌装置";
                    MAG_Drive_Enable();
                } else {
                    qDebug() << "Get_H_In  IN_L_Start  L-9";
                }
            }
            if (Test_IR) {
                Test_IR_Finsh = false;
            } else {
                //
            }
            if (Test_ACW) {
                Test_ACW_Finsh = false;
            } else {
                //
            }
            if (Test_ACW_Finsh_Default) {
                Test_ACW_Finsh = true;
            } else {
                qDebug() << "Get_H_In  IN_L_Start  L-10";  //  -
            }
            Record_Test = Record_Test | 0x0200;
        } else {
            qDebug() << "Get_H_In  IN_L_Start  L-Start else";
            Record_Test = Record_Test | 0x0400;
        }
        qDebug() << "Get_H_In  IN_L_Start  " << QString::number(Record_Test);
        break;
    case IN_L_Stop:
        if ((IN_L_Stop & IO_in_H)) { // !
            qDebug() << "Get_H_In  IN_L_Stop";
            if (Pneumatic_clamp) {
                //
            } else {
                Signal_pic_to_Main(QString(""), 9, 9);
            }
            L_Stop_Push = true;
            L_Station_Order = false;
            if (IN_L_Cylinder & IO_in_L) { // 2018-01-12 左真空罩到位
                // -
            } else {
                L_Stop = true;
            }
            qDebug() << "Get_H_In  IN_L_Stop  Out_Singal_H" << Out_Singal_H;
            if (Out_Singal_H & OUT_L_Station) {
                qDebug() << "Get_H_In  IN_L_Stop  if";
                Out_Singal_H = Out_Singal_H & (~OUT_L_Station); // 断工位信号
                Out_Singal_L = Out_Singal_L & (~OUT_L_Cylinder_Down); //
                Out_Singal_H = Out_Singal_H & (~OUT_L_Inhale_Air);
                Out_Singal_H = Out_Singal_H | OUT_L_Exhaust_Air;
                PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
            } else {
                qDebug() << "Get_H_In  IN_L_Stop  else";
                L_Judge_OK = true;
                if (IN_L_Cylinder & IO_in_L) { // 判断气缸是否下面
                    qDebug() << "return---> Get_H_In  IN_L_Stop 1";
                    L_Exhaust_Air();
                    return;
                } else {
                    qDebug() << "Get_H_In  IN_L_Stop 2";
                }

                if (IN_L_Exhaust_Volt & IO_in_L) {
                    qDebug() << "Get_H_In  IN_L_Stop 3";
                } else {
                    qDebug() << "return---> Get_H_In  IN_L_Stop 4";
                    L_Exhaust_Air();
                    return;
                }

                qDebug() << "Get_H_In  IN_L_Stop IO_in_H_ADD" << IO_in_H_ADD;
                if ((IN_Vertical_Reset) & (IO_in_H_ADD)) { // 垂直复位
                    // -
                } else {
                    qDebug() << "return---> else";
                    L_Vertical_Cylinder_Back();
                    return;
                }
                if ((IN_Horizontal_Reset) & (IO_in_H_ADD)) { // 水平复位
                    // -
                } else {
                    L_Horizontal_Cylinder_Back();
                    return;
                }
                L_Cylinder_Up();
            }
        } else {
            qDebug() << "Get_H_In  IN_L_Stop L STOP else";
        }
        break;
    case IN_R_Stop:
        if ((IN_R_Stop & IO_in_H)) { // 修改Bug
            qDebug() << "Get_H_In  IN_R_Stop";
            Signal_pic_to_Main(QString(""), 9, 9);
            R_Stop_Push = true;
            R_Station_Order = false;
            if (IN_R_Cylinder & IO_in_L) { // 右真空罩到位
                // -
            } else {
                R_Stop = true;
            }
            if (Out_Singal_H & OUT_R_Station) {
                qDebug() << "Get_H_In  IN_R_Stop if";
                Out_Singal_H = Out_Singal_H & (~OUT_R_Station); // 断工位信号
                Out_Singal_H = Out_Singal_H & (~OUT_R_Cylinder_Down); //
                Out_Singal_H = Out_Singal_H & (~OUT_R_Inhale_Air);
                Out_Singal_H = Out_Singal_H | OUT_R_Exhaust_Air;
                PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
            } else {
                qDebug() << "Get_H_In  IN_R_Stop  else";
                R_Judge_OK = true;
                if (IN_R_Cylinder & IO_in_L) { // 判断气缸是否下面
                    qDebug() << "return---> Get_H_In  IN_R_Stop 1";
                    R_Exhaust_Air();
                    return;
                } else {
                    qDebug() << "Get_H_In  IN_R_Stop 2";
                }

                if (IN_R_Exhaust_Volt & IO_in_H) {
                    qDebug() << "Get_H_In  IN_R_Stop 3";
                } else {
                    qDebug() << "return---> Get_H_In  IN_R_Stop 4";
                    R_Exhaust_Air();
                    return;
                }
                R_Cylinder_Up();
            }
        } else {
            qDebug() << "Get_H_In  IN_R_Stop R STOP else";
        }
        break;
    case IN_R_Inhale_Volt:
        if (IN_R_Inhale_Volt & IO_in_H) {
            if (R_Air_Press_Hold) {
                Out_Singal_H = Out_Singal_H & (~OUT_R_Inhale_Air); // R-关闭吸气
                Out_Singal_H = Out_Singal_H & (~OUT_R_Exhaust_Air); // R-关闭排气
                PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
                break;
            } else {
                //
            }
            R_Air_Press_Hold = true;
            qDebug() << "Get_H_In  IN_R_Inhale_Volt Right Air Pressure ok";
            Out_Singal_H = Out_Singal_H & (~OUT_R_Inhale_Air); // R-关闭吸气
            Out_Singal_H = Out_Singal_H & (~OUT_R_Exhaust_Air); // R-关闭排气

            PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
            Signal_pic_to_Test(QString(""), 1, 101);
            Signal_pic_to_Main(QString(""), 5, 5);
        } else {
            qDebug() << "Get_H_In  IN_R_Inhale_Volt  false";
            if (R_Air_Press_Hold) {
                R_Inhale_Air();
            }
        }
        break;
    case IN_R_Exhaust_Volt:
        if (IN_R_Exhaust_Volt & IO_in_H) {
            qDebug() << "Get_H_In  IN_R_Exhaust_Volt  Right Air Pressure Exhaust ok";
            Signal_pic_to_Test(QString(""), 1, 103);
            R_Cylinder_Up();
        } else {
            qDebug() << "Get_H_In  IN_R_Exhaust_Volt false";
        }
        break;
    default:
        qDebug() << "Get_H_In  IN_R_Exhaust_Volt  Error";
        Get_H_All_In();
        break;
    }
}

void pic::Get_L_All_In() {
    int i;
    for (i = 0; i < 8; i++) {
        if ((1 << i) & IO_in_L_State) {
            Get_L_In(1 << i);
        }
    }
}

void pic::Get_L_In(int in_l) {
    switch (in_l) {
    case IN_R_Cylinder:
        qDebug() << "pic::Get_L_In IN_R_Cylinder";
        if (IN_R_Cylinder & IO_in_L) {
            if (System_ing) {
                if (R_Station_Order) {
                    break;
                } else {
                    // -
                }
            } else {
                qDebug() << "IN_R_Cylinder else break";
                break;
            }
            if (R_Stop) {
                qDebug() << "IN_R_Cylinder break";
                break;
            }
            qDebug() << "pic::Get_L_In IN_R_Cylinder Go";
            R_Stop = false;
            if ((Test_IR_Finsh) && (Test_ACW_Finsh)) {
                // -
            } else {
                qDebug() << "pic::Get_L_In IN_R_Cylinder Go else";
                R_Ready_Inhale_Air = true;
                break;
            }
            if (Test_Model_Vacuum) { // 右气缸到位——————>抽气
                R_Inhale_Air();
            }
        } else {
            qDebug() << "pic::Get_L_In IN_R_Cylinder else";
            R_Stop = false;
            if (L_Station_Order) { // 左工位预约
                Timer_Order->setSingleShot(TRUE);
                Timer_Order->start(200); // 定时器200ms, 自启动
            } else {
                // -
            }
        }
        break;
    case IN_L_Cylinder:
        if (IN_L_Cylinder & IO_in_L) {
            qDebug() << "pic::Get_L_In IN_L_Cylinder if";
            if (System_ing) {
                if (L_Station_Order) {
                    break;
                } else {
                    //
                }
            } else {
                break;
            }
            if (L_Stop) {
                break;
            }
            qDebug() << "pic::Get_L_In IN_L_Cylinder  Go";
            L_Stop = false;
            if ((Test_IR_Finsh) && (Test_ACW_Finsh)) {
                //
            } else {
                L_Ready_Inhale_Air = true;
                qDebug() << "pic::Get_L_In IN_L_Cylinder Go else" << Test_IR_Finsh << Test_ACW_Finsh;
                break;
            }
            if (Test_Model_Vacuum) { // 左气缸到位——————>抽气
                L_Inhale_Air();
            }
        } else {
            qDebug() << "pic::Get_L_In IN_L_Cylinder  300";
            Timer_Real->setSingleShot(TRUE);
            Timer_Real->start(300);
        }
        break;

    case IN_L_Inhale_Volt:
        if (IN_L_Inhale_Volt & IO_in_L) {
            if (L_Air_Press_Hold) {
                Out_Singal_H = Out_Singal_H & (~OUT_L_Inhale_Air); // L-关闭吸气
                Out_Singal_H = Out_Singal_H & (~OUT_L_Exhaust_Air); // L-关闭排气

                PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
                break;
            } else {
                //
            }
            if (L_Test_Finsh) {
                L_Test_Finsh = false;
                break;
            } else {
                //
            }
            L_Air_Press_Hold = true;
            qDebug() << "pic::Get_L_In IN_L_Inhale_Volt  Left Air Pressure ok";
            Out_Singal_H = Out_Singal_H & (~OUT_L_Inhale_Air); // L-关闭吸气
            Out_Singal_H = Out_Singal_H & (~OUT_L_Exhaust_Air); // L-关闭排气
            PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
            Signal_pic_to_Test(QString(""), 1, 101);
            Signal_pic_to_Main(QString(""), 3, 3);
        } else {
            qDebug() << "pic::Get_L_In IN_L_Inhale_Volt  false";
            if (L_Air_Press_Hold) {
                L_Inhale_Air();
            }
        }
        break;
    case IN_L_Exhaust_Volt:
        if (IN_L_Exhaust_Volt & IO_in_L) {
            qDebug() << "pic::Get_L_In IN_L_Exhaust_Volt   Left Air Pressure Exhaust ok";
            Signal_pic_to_Test(QString(""), 1, 103);
            L_Cylinder_Up();
        } else {
            qDebug() << "pic::Get_L_In IN_L_Exhaust_Volt  false";
        }
        break;
    case IN_Error_1:
        if (IN_Error_1 & IO_in_L) {
            Signal_pic_to_Main(QString(""), 14, 7);
        }
        break;
    case IN_Error_2:
        if (IN_Error_2 & IO_in_L) {
            Signal_pic_to_Main(QString(""), 15, 7);
        }
        break;
    case IN_Motor_Ready:
        if (IN_Motor_Ready & IO_in_L) { // 电机样品到位
            L_Test_Product = true; qDebug() << "pic::Get_L_In IN_Motor_Ready ";
        } else {
            L_Test_Product = false;
            Signal_pic_to_Main(QString(""), 8, 8);
        }
        break;
    case IN_Vertical_GO:
        if (Switchover_Factory == BDVacuum) {
            if (IN_Vertical_GO & IO_in_L) { // 步进电机到位
                R_Test_Product = true;  qDebug() << "pic::Get_L_In R_IN_Motor_Ready";
            } else {
                R_Test_Product = false;
            }
            break;
        } else {
            //
        }
        if (System_ing) { // 防止在单个信号控制时，进行动作
            //
        } else {
            return;
        }

        if (IN_Vertical_GO & IO_in_L) { // 步进电机到位
            qDebug() << "pic::Get_L_In IN_Vertical_GO";
            MAG_Drive_Ready();
        } else {
            //
        }
        break;
    default:
        qDebug() << "pic::Get_L_In   Error";
        Get_L_All_In();
        break;
    }
}

void pic::MAG_Drive_Ready() { //
    qDebug() << "pic::MAG_Drive_Ready()";
    if (IMP_Sample_ing) { // 测试匝间中
        L_Cylinder_Down_True();
        qDebug() << "return---> pic::MAG_Drive_Ready()";
        return;
    } else {
        //
    }
    if (Current_Test_Window) {
        Signal_pic_to_Test(QString(""), 2, 102); // 继续执行操作，真空装置就位
    } else {
        Signal_pic_to_Main(QString(""), 3, 3);
        return;
    }
    if (Test_Model_Vacuum) { // 真空状态, 落下气缸
        L_Cylinder_Down_True();
    } else { // 非真空状态
        // -
    }
}

void pic::R_Station_Start() {
    Out_Singal_H = Out_Singal_H | OUT_R_Station; //
    PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
}
void pic::R_Cylinder_Down() {
    if (IN_R_Cylinder & IO_in_L) { // R真空泵下降到位
        qDebug() << "pic::R_Cylinder_Down()";
        if ((Test_IR_Finsh) && (Test_ACW_Finsh)) {
            //
        } else {
            qDebug() << "return pic::R_Cylinder_Down() else";
            R_Ready_Inhale_Air = true;
            return;
        }
        if (Test_Model_Vacuum) { // 右气缸到位——————>抽气
            R_Inhale_Air();
        }
        qDebug() << "return pic::R_Cylinder_Down() if";
        return;
    } else {
        // -
    }
    if (IN_R_Light_Curtain & IO_in_H) {
        qDebug() << "return pic::R_Cylinder_Down() if 2";
        return;
    } else {
        //
    }

    Out_Singal_H = Out_Singal_H & (~OUT_R_Inhale_Air); // R-关闭吸气
    Out_Singal_H = Out_Singal_H & (~OUT_R_Exhaust_Air); // R-关闭排气
    Out_Singal_H = Out_Singal_H | OUT_R_Cylinder_Down;
    Out_Singal_H = Out_Singal_H & (~OUT_R_Cylinder_Up);
    PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
}
void pic::R_Cylinder_Up() {
    if (R_Stop_Push) {
        qDebug() << "pic::R_Cylinder_Up()" << R_Stop_Push << R_Judge_OK;
        R_Stop_Push = false;
        R_Judge_OK = true;
    }
    if (IN_R_Exhaust_Volt & IO_in_H) {
        //
    } else {
        qDebug() << "return pic::R_Cylinder_Up() else";
        return;
    }
    if (R_Judge_OK) {
        //
    } else {
        qDebug() << "return pic::R_Cylinder_Up() R_Judge_OK";
        return;
    }
    Out_Singal_H = Out_Singal_H | OUT_R_Cylinder_Up;
    Out_Singal_H = Out_Singal_H & (~OUT_R_Cylinder_Down);
    Out_Singal_H = Out_Singal_H & (~OUT_R_Station);
    PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
    if (IN_R_Cylinder & IO_in_L) {
        qDebug() << "pic::R_Cylinder_Up() if";
        R_Cylinder_Uping = true;
        R_Timer_Cylinder_Up->setSingleShot(TRUE);
        R_Timer_Cylinder_Up->start(1500); // 定时器1500ms, 自启动
    } else {
        qDebug() << "pic::R_Cylinder_Up() else";
    }
}
void pic::R_Inhale_Air() {
    qDebug() << "pic::R_Inhale_Air()" << R_Station_Order;
    if (R_Station_Order) {
        qDebug() << "return pic::R_Inhale_Air() R_Station_Order";
        return;
    } else {
        //
    }
    if (IN_R_Cylinder & IO_in_L) {
        //
    } else {
        qDebug() << "return pic::R_Inhale_Air()";
        return;
    }

    Out_Singal_H = Out_Singal_H | OUT_R_Inhale_Air; // R-开始吸气
    Out_Singal_H = Out_Singal_H & (~OUT_R_Exhaust_Air); // R-关闭排气
    PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
}
void pic::R_Exhaust_Air() {
    R_Air_Press_Hold = false;
    if (IN_R_Exhaust_Volt & IO_in_H) {
        Out_Singal_H = Out_Singal_H & (~OUT_R_Inhale_Air);
        R_Cylinder_Up();
        qDebug() << "return pic::R_Exhaust_Air() if";
        return;
    } else {
        qDebug() << "pic::R_Exhaust_Air() else";
    }
    Out_Singal_H = Out_Singal_H & (~OUT_R_Inhale_Air);
    Out_Singal_H = Out_Singal_H | OUT_R_Exhaust_Air;
    PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
}

void pic::L_Station_Start() {
    Out_Singal_H = Out_Singal_H | OUT_L_Station; // 吸合工位信号
    PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
}
void pic::L_Cylinder_Down() {
    if (MAG_Drive) {
        qDebug() << "return pic::L_Cylinder_Down()";
        MAG_Drive_Enable();
        return;
    } else {
        L_Cylinder_Down_True();
    }
}
void pic::L_Cylinder_Down_True() {
    if (IN_L_Cylinder & IO_in_L) { // L真空泵下降到位
        if ((Test_IR_Finsh) && (Test_ACW_Finsh)) {
            //
        } else {
            L_Ready_Inhale_Air = true;
            qDebug() << "return pic::L_Cylinder_Down_True() else ";
            return;
        }
        if (Test_Model_Vacuum) { // 左气缸到位——————>抽气
            L_Inhale_Air();
        }
        qDebug() << "return pic::L_Cylinder_Down_True() if ";
        return;
    } else {
        //
    }
    if (IN_L_Light_Curtain & IO_in_H) {
        return;
    } else {
        //
    }
    Out_Singal_H = Out_Singal_H & (~OUT_L_Inhale_Air); // L-关闭吸气
    Out_Singal_H = Out_Singal_H & (~OUT_L_Exhaust_Air); // L-关闭排气
    Out_Singal_L = Out_Singal_L | OUT_L_Cylinder_Down;
    Out_Singal_L = Out_Singal_L & (~OUT_L_Cylinder_Up);
    PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
}

void pic::L_Cylinder_Up() {
    if (L_Stop_Push) {
        qDebug() << "L_Cylinder_Up()" << L_Stop_Push << L_Judge_OK;
        L_Stop_Push = false;
        L_Judge_OK = true;
    }
    if (IN_L_Exhaust_Volt & IO_in_L) {
        //
    } else {
        qDebug() << "return L_Cylinder_Up()";
        return;
    }
    if (L_Judge_OK) {
        //
    } else {
        qDebug() << "return L_Cylinder_Up() L_Judge_OK";
        return;
    }
    L_Test_Finsh = false;
    Out_Singal_L = Out_Singal_L | OUT_L_Cylinder_Up;
    Out_Singal_L = Out_Singal_L & (~OUT_L_Cylinder_Down);
    Out_Singal_H = Out_Singal_H & (~OUT_L_Station); // 断工位信号
    PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
    if (IN_L_Cylinder & IO_in_L) {
        qDebug() << "pic::L_Cylinder_Up() if";
        L_Cylinder_Uping = true;
        L_Timer_Cylinder_Up->setSingleShot(TRUE);
        L_Timer_Cylinder_Up->start(1500); // 定时器1500ms, 自启动
    } else {
        qDebug() << "pic::L_Cylinder_Up() else";
    }
}
void pic::L_Inhale_Air() {
    qDebug() << "pic::L_Inhale_Air()" << L_Station_Order;
    if (L_Station_Order) {
        qDebug() << "return pic::L_Inhale_Air() L_Station_Order";
        return;
    } else {
        //
    }

    if (IN_L_Cylinder & IO_in_L) {
        //
    } else {
        qDebug() << "return pic::L_Inhale_Air()";
        return;
    }
    /* 没有真空泵时进行测试
   * Signal_pic_to_Test(QString(""), 1, 101);
     Signal_pic_to_Main(QString(""), 3, 3); */
    qDebug() << "L_Inhale_Air()";
    Out_Singal_H = Out_Singal_H | OUT_L_Inhale_Air; // L-开始吸气
    Out_Singal_H = Out_Singal_H & (~OUT_L_Exhaust_Air); // L-关闭排气
    PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
}
void pic::L_Exhaust_Air() {
    qDebug() << "pic::L_Exhaust_Air()";
    L_Air_Press_Hold = false;
    if (IN_L_Exhaust_Volt & IO_in_L) { // 左排气 ok
        qDebug() << "pic::L_Exhaust_Air() L_Cylinder_Up();";
        Out_Singal_H = Out_Singal_H & (~OUT_L_Inhale_Air); // L-关闭吸气
        L_Cylinder_Up();
        qDebug() << "return pic::L_Exhaust_Air() ---Return--- L_Cylinder_Up()";
        return;
    } else {
        qDebug() << "pic::L_Exhaust_Air() Go";
    }
    Out_Singal_H = Out_Singal_H & (~OUT_L_Inhale_Air); // L-关闭吸气
    Out_Singal_H = Out_Singal_H | OUT_L_Exhaust_Air; // L-开始排气
    PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
}

void pic::MAG_Drive_Enable() {
    qDebug() << "pic::MAG_Drive_Enable()";
    if (IN_Vertical_GO & IO_in_L) {
        MAG_Drive_Ready();
    } else {
        //
    }
    L_Horizontal_Cylinder_Go();
}

void pic::MAG_Drive_Disable() {
    qDebug() << "pic::MAG_Drive_Disable()";
    if (MAG_Drive) {
        //
    } else {
        qDebug() << "return pic::MAG_Drive_Disable() return";
        return;
    }
    if (IN_L_Cylinder & IO_in_L) { // 判断气缸是否下面
        L_Exhaust_Air();
        qDebug() << "return pic::MAG_Drive_Disable() L_Exhaust_Air()";
        return;
    } else {
        //
    }
    MAG_Sample_ing = true;
    L_Vertical_Cylinder_Back();
}

/*************横向气缸->Gｏ*************/
void pic::L_Horizontal_Cylinder_Go() {
    Out_Singal_L = Out_Singal_L | OUT_Horizontal;
    PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
}

/*************横向气缸->Back*************/
void pic::L_Horizontal_Cylinder_Back() {
    Out_Singal_L = Out_Singal_L & (~OUT_Horizontal);
    PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
}

/*************纵向气缸->Gｏ*************/
void pic::L_Vertical_Cylinder_Go() {
    Out_Singal_L = Out_Singal_L | OUT_Vertical;
    PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
}

/*************纵向气缸->Back*************/
void pic::L_Vertical_Cylinder_Back() {
    Out_Singal_L = Out_Singal_L & (~OUT_Vertical);
    PLC_CAN_Data(Out_Singal_H, Out_Singal_L, Out_Singal_Add);
    Test_Back_Horizontal = true;
}

/******************************************************************************
      * version:    1.0
      * author:     sl
      * date:       2017.12.01
      * brief:      Can发送ＩＯ版信息
******************************************************************************/
void pic::PLC_CAN_Data(int Data_1, int Data_2, int Data_3) {
    if (BenDuo_Vacuum_Control == 0) {
        //
    } else if (BenDuo_Vacuum_Control == 1) {
        Data_2 = Data_2 | 0x40;
    } else if (BenDuo_Vacuum_Control == 2) {
        Data_3 = Data_3 | 0x02;
    } else {
        //
    }

    if (Shanr_Turn%3 == 0) {
        Data_2 = Data_2 & 0xf6;
    } else if (Shanr_Turn%3 == 1) {
        Data_2 = Data_2 | 0x01;
    } else if (Shanr_Turn%3 == 2) {
        Data_2 = Data_2 | 0x08;
    } else {
        //
    }

    qDebug() << "pic::PLC_CAN_Data------------->" << Data_1 << Data_2 << Data_3;
    frame.can_id  = 0x2D;  frame.can_dlc = 0x04;
    frame.data[0] = 0xf1;
    frame.data[1] = Data_1;
    frame.data[2] = Data_2;
    frame.data[3] = Data_3;
    canSend(frame, 88);
    usleep(600);
}

