#ifndef W_TEST_H
#define W_TEST_H

#include <QWidget>
#include <QTimer>
#include <QTableWidgetItem>
#include <QDebug>
#include <QScrollBar>
#include <QtCore/qmath.h>
#include <QMessageBox>
#include <QColor>
#include <QMouseEvent>
#include <QDockWidget>
#include <QtXml/qdom.h>
#include <QtXml/QDomDocument>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDir>

#include <iostream>
#include <iomanip>
#include <math.h>

#include "wt_wave.h"
#include "define.h"
#include "linux_rtc.h"
#include "linux_can.h"
#include "pwm_api.h"
#include "linux_sql.h"

#define Ver_System "Release"       // Debug  Release
#define ACW_Point  2

namespace Ui {
class w_Test;
}

class w_Test : public QWidget
{
    Q_OBJECT
public:
    explicit w_Test(QWidget *parent = 0);
    ~w_Test();

    QStringList strRES;   // -电阻
    QStringList strOPP;   // -反嵌
    QStringList strIR;    // -绝缘
    QStringList strACW;   // -交耐
    QStringList strITT;   // -匝间
    QStringList strPWR;   // -功率
    QStringList strBLOCK; // -堵转
    QStringList strLVS;   // -低启
    QStringList strINDL;  // -电感
    QStringList strPG;    // -BLDCPG
    QStringList strLOAD;  // -LOAD
    QStringList strNOLOAD; // -NOLOAD
    QStringList strBEMF;  // -BEMF

    int  DCR_Total_Number;                        // -电阻测试总数
    int  DCR_TestItem_H;   int  DCR_TestItem_L;   // -电阻测试项目的高项, 电阻测试项目的低项
    int  MAG_Total_Number;  int  MAG_TestItem;    // -反嵌测试总数 反嵌测试项目
    int  IMP_Total_Number;  int  IMP_TestItem;    // -匝间测试总数 匝间测试项目
    int  INDL_Total_Number;                       // -电感测试总数
    int  INDL_TestItem_H;  int  INDL_TestItem_L;  // -电感测试项目的高项 电感测试项目的低项
    bool IRFinsh;                                 // -绝缘完成标志
    bool NoLoadFinsh;                             // -空载完成标志
    int  TestIRACW;                               // -测试耐压绝缘FLAG
    QStringList ACWgroup_num;                     // -相间耐压组号
    int  ACW_Test_Count, ACW_Test_Total;           // -相间耐压测试数目 相间耐压测试总数
    QStringList IRgroup_num;                      // -相间绝缘组号
    int  IR_Test_Count, IR_Test_Total;             // -相间绝缘测试数目 相间绝缘测试总数

    int  START_Model;           // -启动方式
    bool Connect_Test;          // -连接测试
    int  JUMP_Chose;            // -页面跳转
    QStringList DLR_UpDown;     // -电阻参数(上限和下限)
    QStringList IMP_Param;      // -匝间参数(进行对比)
    QStringList COLOR_Id;       // -端子颜色
    QStringList PWR_Test_Data;  // -功率测试数据初始化
    QStringList FG_Test_Data;
    QStringList PG_Test_Order;  // -功率PG数据顺序测试化
    QStringList Conf_Item;      // -配置项目
    QStringList FG_Conf_Item;
    int PG_Test_State;
    bool AMP_Conneted; // 功放板增加新功能-针对Risatti

    void Pub_Main_to_test(QStringList, QString, int, int);
    void Pub_Main_can_to_test(can_frame, int);
    void Pub_IMP_Param(QStringList, int *waveform_point, int *waveform_point_compare);
    void Pub_MAG_Param(QStringList, int *waveform_point);
    void Pub_PWR_Param(QStringList, int *waveform_point, int *waveform_point_c);
    void Pub_FG_Param(QStringList);

    int  Back_Test_Status();

private:
    Ui::w_Test *ui;
    QList<QLabel*>  show_color;      // -显示颜色
    QList<QLabel*>  wave_name;       // -波形上面显示的名称
    QList<QLabel*>  test_parameters; // -测试配置参数 (型号名称 编号 操作者 管理员)
    QStringList     Test_Item;       // -开发的全部测试项目

    int  Error_Mount;                  // -错误计数(在测试过程中遇到错误时，
                                       // 在10次复位以上进行测试数据的复位)
    wt_Wave *wave[3];                  // -波形ABC显示区
    wt_Wave *Test_TShape;              // -放大显示的波形
    int  record_wave_row;              // -移除波形的行数
    int  waveform_all_count;           // -采集波形总数量
    int  waveform_row_count;           // -采集波形的行数
    int  Recrd_Wave;                   // -记录（匝间、反嵌、PG）的波形数量
    int  CRecrd_Wave;                  // -记录（匝间、反嵌、PG）的波形数量的备份
    QStringList WavePoint_strList[50]; // -保存波形数组

    QStringList strTest;    // -测试项目
    QStringList strParam;   // -测试参数
    QStringList strResult;  // -测试结果
    QStringList strJudge;   // -测试判定
    int  StrResult_Size;    // -结果
    int  StrJudge_Size;     // -判定


    int  DCR_Test_Record_Number;      // -记录电阻测试的数目
    int  MAG_Test_Record_Number;      // -记录反嵌测试的数目
    int  TaskMagDirnumber;            // -磁旋标记(正转-反转-不转)
    int  TaskMagDirnumber_ROT;        // 磁旋标记 正转 反转 不转
    int  MAG_Current_Testing_Item;    // -反嵌当前测试中项目
    QStringList TaskMagDirstrList[3]; // -反嵌测试列表
    int  INDL_Test_Record_Number;     // -记录电感测试的数目
    union  Resultunion  {             // -电感
        float Result;                 // -电感
        uint8_t dat[4];               // -电感
    };  Resultunion  ResultReg;       // -电感测试共用体
    int    Result_INDL;               // -电感测试数目
    float  Result_Main;               // -电感结果数据
    float  Result_Q;                  // -电感Q值数据
    double ResultTable_INDL_All[9];   // -电感结果(用于计算电感不平衡度)
    double ResultTable_INDL_Q[9];     // -Q值结果 (用于计算Q值不平衡度)
    bool RemoveLastIR;                // -移除(绝缘-耐压)最后行的标志
    bool RemoveLastNOLoad;            // -移除(空载)最后行的标志
    QStringList IR_Error;         // -相间绝缘耐压异常错误
    QStringList ACW_Error;         // -相间绝缘耐压异常错误
    int  IMP_Test_Record_Number;      // -记录匝间测试的数目
    int  IMP_Current_Testing_Item;    // -匝间当前测试中项目
    QList<wt_Wave *> IMP_Right_List;  // -匝间右匝间列表
    QList<wt_Wave *> IMP_Left_List;   // -匝间左匝间列表
    bool Data_Complete;               // -匝间测试包是否完整, 在匝间测试出现丢包时使用
    int    PWR_Test_Count;            // -功率测试数据
    int    FG_Test_Count;
    int    FG_Shape_Count;
    QStringList PWR_Result_Judge;     // -功率结果判定
    QStringList PG_list;              // -PG返回数据
    QStringList PG_Result_List;       // -PG结果提供显示
    QStringList PG_Row;               // -PG数据的显示（因为数据显示不开）
    int  Block_cycle;                 // -堵转采集计算的周期
    QStringList BLOCK_list;           // -堵转数据
    QStringList LVS_Result_Judge;     // -低启结果判定
    QPushButton *button_dump;

    struct {
        QTimer *Time;
        int Ms;
        int Us;
        bool Flag;
    }   Mouse;


    bool Button_Start_Time_Flag; //  按键自启动时候调用
    int  Button_Start_Station;   // -启动工位
    QStringList Self_starting;   // -自启动 （自启动标志）（左工位 右工位 双工位）（设置启动时间）

    QTimer *key_board;           // -按键板（进行条码扫描的输入）
    QString keyboard_string;     // -设置键盘-扫码输入字符串
    bool Non_barcode_scanner;    // -条形码扫描为0，不是条形码扫描为1
    int  scan_scart;             // -条码扫描起始
    int  scart_stop;             // -条码扫描终止

    struct { // -蜂鸣器
        QTimer *Time;
        int Grade;
        double OK_Time;
        double NG_Time;
        bool Flag;
    }   Beep;
    QTimer *dcr_board;     // -电阻板-蜂鸣器的报警
    QTimer *IO_Pumb_Start;
    QTimer *IO_Delay_Start;
    
    bool Test_noise_enabled; // 噪音使能
    double Noise_CW_Time;     // noise CW
    double Noise_CCW_Time;    // noise CCW
    double Noise_Delay_Time;  // noise 延时时间
    int Noise_step;
    QTimer *Noise_Stop; // noise--

    /*********************读取系统设置********************/
    int  Ini_Number;      // -读取当前系统的数量
    int  Ini_Mag_Hide;    // -读取反嵌波形是否隐藏
    int  Ini_NG_Data;     // -只显示(NG)数据
    int  Ini_Stagnate;    // -防呆
    int  Ini_NineBoard;   // -8插板和9插板的区分
    int  Ini_AMPTemp;     // -机箱内部温度的数值
    int  Ini_DCR_Ask;     // -询问继续模式
    int  GND_Volt;
    int  NG_Push;
//    int  Ini_NoBalance;   // -电阻不平衡度测试
    int  Ini_LR;          // -工位信号反转
    int  Ini_Pwr_Turn;    // -假转子
    bool Ini_ACWandIR;    // -相间绝缘耐压
    bool Ini_SaveNG;      // -数据库不保存不合格信号
    int  Ini_Direction;   // -功率改变转向
    int  Ini_Power_Chose; // -功率板电源选择
    int  Ini_LVS_Judge;   // -低启的判定方式
    int  PGturn_model;    // -PG转向测试方式
    QString Ini_Motor;    // -PG电机测试
    QStringList Ini_Proj; // -读取系统设置(后面)
    int  Ini_MAG_Device;
    bool Ini_Vacuum_Model;
    bool Ini_imp_min;
    int  Ini_BLDC_PG;
    int  Ini_IO_Model;
    bool Ini_IO_Test;
    bool Ini_IO_Delay;      // IO启动延时
    int  Ini_IO_Delay_Time; // IO延时时间

    /********************功率显示窗口*******************/
    QWidget *PWR_Par_Widget;
    QList<QLabel*> PWR_Lable;
    QList<QLabel*> PWR_Display_Lable;

    /********************柱状图显示的信息****************/
    QWidget *Histogram_Widget;
    QWidget *PLC_Singal_Widget; //
    QLineEdit *Text_Edit;
    QList<QLabel*> PushHist_List;
    QList<QLabel*> PushHist_Text;
    QList<QLabel*> PushHist_Count_Text;
    QList<QLabel*> Histogram_List;

    /******************询问和提示显示窗口******************/
    QWidget *Ask_Widget;
    QLabel  *Ask_Up_label;

    /******************获取测试中的状态******************/
    struct {
        int Finshed_Count;    // -测试中已经完成的项目数量
        int Next_Finsh_Count; // -测试已经下发的项目数量 (也就是下一次需要完成的数目)
        int Current_Row;      // -测试当前行显示
        int NG_Item;          // -记录不合格的项目
        int Status_Ing;       // -测试运行中的状态
        bool Interrupted;     // -中断
        bool Judge_NG;
        QString serial_number;       // -(编号)条码信息
    }   Test;

    LINUX_RTC rtc;
    can_frame frame;
    int  Error_Item[19];         // -错误的项目
    int  Error_Item_Count[19];   // -错误的项目以累加进行判定
    int  Back_board_ID[17];      // -背板ID
    bool False_Test;             // -功率测试失败
    bool DCR_Connect;            // -电阻短路
    bool Cancel_No_Save;         // -测试询问取消，在大洋数据库时增加功能
    int  Station_Chose;          // -工位选择
    QLabel  *lable_stop;         // -停止
    QLabel  *lable_GND_Volt;
    QLabel  *label_Show;         // -波形图
    QLabel  *label_Waring;       // -警告标签
    bool Test_Waring_Flag;       // -警告标签-测试警告标志位
   
    QString Main_ActiveFile;     // -当前文件名称
    QString Start_Time;          // -启动时间
    QStringList turn;            // -功率的转向
    int Model_Occur_Unqualified;  // -遇不合格测试项目的模式
    bool Temp_Error;             // - 温度错误         九插板使用
    bool Temp_In;                // -机箱内部温度过高  九插板使用
    int  In_Temp;                // -机箱内部温度数值  九插板使用
    int  Test_GND_Volt;          // -接地电压         九插板使用

    bool  Test_Model_Vacuum; // 匝间真空模式
    bool  Test_IMP_Ready;
    bool  Test_Model_Vacuum_ACW;
    bool  Test_ACW_Ready;
    bool  Vacuum_Ready;
    bool  Test_MAG_Ready;
    bool  MAG_Drive;

    bool  Vacuum_pump_Close;
    int   System_Free_Time;

    QStringList Hall_Update;
    QStringList NoLoad_Update;
    bool Start_No;
    
    QStringList Test_Message;
    int  Last_Station; // 上一次测试的工位(阿斯科禁止启动一个工位)
    int  Key_E_Count;      // 按键计数５次时显示ＩＯ的输入状态
    QLabel *IO_Input_Data; // 输入IO板的数据
    
    bool Kai_Yu_Curtain;   // 日电产凯宇光幕
    int  Kai_Yu_Oid_Count; // 日电产凯宇记录测试次数 Ｏｌｄ
    int  Kai_Yu_New_Count; // 日电产凯宇记录测试次数 Ｎｅｗ
    bool Kai_yu_In_Place;  // 日电产凯宇到位信号
    bool Kai_Yu_Clumped;   // 日电产凯宇夹住样品信号
    bool Kai_Yu_Pushed;    // 日电产凯宇压住样品信号
    void Kai_Yu_Ready_Test();

    bool IO_Test_Readying;
    bool Kongshi_Stall;
    bool Kongshi_Continue_Test;
    int  Kongshi_Stall_Time;
    
    QStringList No_load_Param;
    QStringList FG_Param_A;
    QStringList Hall_Count;
    QStringList FG_direction;

    bool Ini_ROT;
    QStringList mag_zero;
    bool BenDuo_L,BenDuo_R;
    QStringList Shape_Hall_A,Shape_Hall_B,Shape_Hall_C;
    bool handleMousePressEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent  *event);
    void keyReleaseEvent(QKeyEvent * event);
    //  int timeval_subtract(struct timeval*,  struct timeval*,  struct timeval*);
    //  struct timeval start, stop, diff;

    bool NetTest_Ready_DLR;      bool DLR_Issue_Ing;
    bool NetTest_Ready_MAG;      bool MAG_Issue_Ing;
    bool NetTest_Ready_IR;       bool IR_Issue_Ing;
    bool NetTest_Ready_ACW;      bool ACW_Issue_Ing;
    bool NetTest_Ready_IMP;      bool IMP_Issue_Ing;
    bool NetTest_Ready_IND;      bool IND_Issue_Ing;
    bool NetTest_Resdy_HALL;     bool HALL_Issue_Ing;
    bool NetTest_Resdy_LOAD;     bool LOAD_Issue_Ing;
    bool NetTest_Resdy_NOLOAD;   bool NOLOAD_Issue_Ing;
    bool NetTest_Resdy_BEMF;     bool BEMF_Issue_Ing;


    void Can_Start_DLR();
    void Can_Start_MAG();
    void Can_Start_IR();
    void Can_Start_ACW();
    void Can_Start_DCW();
    void Can_Start_IMP();
    void Can_Start_PWR(int);
    void Can_Start_INDL();
    void Can_Start_BLOCK();
    void Can_Start_LVS();
    void Can_Start_DLR_True();
    void Can_Test_IMP_Parameter();

    void Can_Start_BLDCHALL();
    void Can_Start_LOAD();
    void Can_Start_NOLOAD();
    void Can_Start_BEMF();

    void Can_Stop(int);

    void InitTest_Interface(QStringList);
    void ChangeLable(int Lable, int number);

    void Test_Ready();
    void Test_Start();
    void Test_NG_Data();
    void Test_SelfStart();
    void Test_Delete_Row(int);
    void Test_Mag_Trend(int,int *waveform_point);
    void Test_Mag_MagDir(QString, int);
    void Test_Get_Temp(QString);
    void Test_Overtime_Alarm(int);
    int  Test_Judge_TotalResult();
    void Test_Judge_State(QString);
    void Test_Usart_Clicked(QString);
    void Test_KEY_Surface(QString USART);
    void Test_Beep_State(double, QString);
    void Test_Block_ResultData(QStringList);
    void Test_WMessage(int number,QString Waring_Text);
    void Test_Background_Param(QStringList);
    void Test_PWR_ResultData(QStringList, int);

    bool parameter_Issue_ing();
    void join_test_start(int, int);
    void join_test_stop(int);
    void join_test_occur_unqualified_Continue(int);
    void join_test_occur_unqualified_Stop(int);
    void join_test_occur_unqualified_Ask(int);

    void Board_DLR_Data(QStringList); // -电阻测试数据
    void Board_MAG_Data(QStringList); // -反嵌测试数据
    void Board_IR_Data(QStringList);  // -绝缘测试数据
    void Board_ACW_Data(QStringList); // -交耐测试数据
    void Board_DCW_Data();            // -直耐测试数据
    void Board_IMP_Data(QStringList); // -匝间测试数据
    void Board_INDL_Data();           // -电感测试数据
    void Board_PWR_Data();            // -功率测试数据
    void Board_BLOCK_Data();          // -堵转测试数据
    void Board_LVS_Data();            // -低启测试数据
    void Board_DLR_Unbalance(int);    // -电阻不平衡度测试
    void Board_FG_Data(QStringList);
    void Board_NOLOAD_Data(QStringList);
    void Board_LOAD_Data(QStringList);
    void Board_BEMF_Data(QStringList);

    void MAG_Check_Button(int);
    void IMP_Check_Button(int);
    void PG_Check_Button(int);
    void FG_Check_Button(int);
    void IMP_Init_Wave(QString);
    void PG_Param(QStringList, int *waveform_point, int *waveform_point_c);
    void FG_Param(QStringList);
    void Test_PWR_Widget(double, int);
    void PC_Test_Result_Data(QString, QString);
    void PC_Test_Result_ItemData(QString, QString);
    void Test_Record(QString);

    double Volt_A, Current_A, Pwr_A;   // -A相电压， 电流，功率
    double Volt_B, Current_B, Pwr_B;   // -B相电压， 电流，功率
    double Volt_C, Current_C, Pwr_C;   // -C相电压， 电流，功率
    double Pf_A, Freq_A, time;         // -功率因数，频率，时间
    double Dir, Speed;                // -转向，转速
    double Hall_Speed;               // -霍尔转速

    bool   Net_Start_Item;           // -网络启动单个项目
    bool   Net_Stop__Item;
    QStringList Pub_Set_PWR(can_frame frame);
    double pg_Cur, pg_floor, pg_up;               // -pg电流，下限，上限
    double pg_freq_min, pg_freq_avr, pg_freq_max; // -pg频率最小，平均，最大
    double pg_duty_min, pg_duty_avr, pg_duty_max; // -pg周期最小，平均，最大
    QStringList Pub_Set_PG(can_frame frame);
    double Turn_Elec_force;   // -反电动势
    bool Exist_PWR;           // -判断是否存在功率，在启动电阻时进行反电动势的检测
    void Pri_Ask_Test_Exit(); // -询问退出(未调用)
    QStringList Test_GND_Volt_List;

    void Test_Process();
    void Modification_Soft_Askoll(int); // 阿斯科(工位必须交替使用)
    void Pri_main_to_test_four(QString, int);
    void TTT();
    void Test_CiXiMingHua();
signals:
    void Sigtest_Usart_Send(char *Buf);
    void Signal_Test_to_Main(int, int);
    void canSend(can_frame frame, int);
    void Sigtest_Save_Data(QStringList, QString, int);
    void WriteMessage(quint16,  quint16,  QByteArray);
    void Signal_test_to_pic(QStringList, int, int);
    void Signal_test_to_Switchover(int, int32_t, int);

private slots:
    void join_updateTime();
    void join_key_out();
    void join_beep_stop();
    void join_shape_set_free();
    void join_test_mouse_check();
    void join_autoquit();
    void join_autodump(bool);
    void join_autoconfirm();
    void join_test_button_start();

    void join_test_hall();


    void on_button_shape_clicked();
    void on_testTab_clicked(const QModelIndex &index);
    void on_testTab_cellClicked(int row,  int column);
    void on_button_up_clicked();
    void on_button_set_clicked();
    void on_button_down_clicked();
    void on_button_back_clicked();
    void test_join_dcr_stop();
    void IO_Pumb_Start_timeout();
    void IO_Delay_Start_timeout();
    void Noise_Stop_timeout();
    void Pri_Ask_Test_Current();  // -询问(重测当前)
    void Pri_Ask_Test_Continue(); // -询问(继续)
    void Pri_Ask_Test_Stop();     // -询问(终止(上传数据库))
    void Pri_Ask_Test_Cancel();   // -询问(取消(不上传数据库))
    void on_Key_E_clicked();

public slots:
    void join_updatedata(QStringList);
    void Pubs_from_pic(QString, int, int);
};

#endif // W_TEST_H
