/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     2.0
 * author:      SL
 * date:        2015.12.10
 * brief:       主界面
*******************************************************************************/
#ifndef W_CONF_H
#define W_CONF_H

#include <QDir>
#include <QTime>
#include <QTimer>
#include <QDebug>
#include <QWidget>
#include <QString>
#include <QThread>
#include <QSpinBox>
#include <QComboBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QSettings>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QTextCodec>
#include <QScrollBar>
#include <QMouseEvent>
#include <QMessageBox>
#include <QToolButton>
#include <QTextStream>
#include <QColorDialog>
#include <QSqlDatabase>
#include <QButtonGroup>
#include <QtCore/qmath.h>
#include <QTableWidgetItem>
#include <QRadioButton>

// #include <QtXml/>
#include <QtXml/qdom.h>
#include <QtXml/QDomDocument>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

#include <sys/statfs.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

#include "time.h"
#include "stdio.h"

#include "linux_Thread.h"
#include "linux_sql.h"
#include "pwm_api.h"
#include "wt_wave.h"
#include "linux_can.h"
#include "define.h"
#include "Widget_DLR.h"
#include "Widget_ACW.h"
#include "Widget_DCW.h"
#include "Widget_IMP.h"
#include "Widget_IR.h"
#include "Widget_MAG.h"
#include "Widget_PWR.h"
#include "Widget_INDL.h"
#include "Widget_BLOCK.h"
#include "Widget_LVS.h"
#include "widget_bldc_pg.h"
#include "widget_load.h"
#include "widget_noload.h"
#include "widget_bemf.h"
#include "Widget_HV.h"
#include "SqlClient.h" // 2017-6-30 设置数据库
#include "UdpClient.h"

namespace Ui {
class w_Conf;
}

class w_Conf : public QWidget
{
    Q_OBJECT

public:
    explicit w_Conf(QWidget *parent = 0);
    ~w_Conf();

private:
    Ui::w_Conf *ui;

public:
    Widget_DLR *WDLR;     //-电阻
    Widget_MAG *WMAG;     //-反嵌
    Widget_IR  *WIR;      //-绝缘
    Widget_ACW *WACW;     //-交耐
    Widget_DCW *WDCW;     //-直耐
    Widget_IMP *WIMP;     //-匝间
    Widget_PWR *WPWR;     //-功率
    Widget_INDL *WINDL;   //-电感
    Widget_BLOCK *WBLOCK; //-堵转
    Widget_LVS *WLVS;     //-低启
    Widget_BLDC_PG *WPG;     //-霍尔
    Widget_Load    *WLOAD;   //-负载
    Widget_Noload  *WNoLoad; //-空载
    Widget_BEMF    *WBEMF;   // -BEMF
    Widget_HV      *WHV;     // -HV

    int index_c;    //-保存当前页面的序列号

    QString     Ini_ActiveFile;  //-当前文件
    int  Conf_User; //-操作用户
    bool Ini_ACW_And_IR;    //-读取相间绝缘和耐压

    QStringList strList[16];
    QStringList colorIdList_C;
    QStringList strRES, strOPP, strIR, strACW, strDCW, strITT, strPWR, strINDL, strBLOCK, strLVS;
    QStringList strPG, strLOAD, strNOLOAD, strBEMF;
    QStringList strHV;


    QStringList strDLR_UpDown, strIMP_Param;
    QStringList currentFile;
    QStringList DateFile;
    QStringList Conf_Test;
    bool  Board_DLR;  bool Board_INDL;

    void  Pub_main_to_conf(QStringList, QString, int, int);
    void  Pub_QbyteArray_conf(QByteArray);

private:
    QButtonGroup *btnGroup_function; //-功能
    QButtonGroup *btnGroup_Color;    //-线夹颜色选择
    QButtonGroup *btnGroup_Conf;     //-测试项目
    QButtonGroup *Station_Chose_Group; // 快速設置工位
    QList<QRadioButton*> Station_QRadioPutton; //-项目按键

    QButtonGroup *btnGroup_IMP_Sample; //-匝间采集按键
    QStringList  Test_Item;            //-全部测试项目 (已经完成)

    struct {
        QTimer *Time;
        int Ms;
        int Us;
        bool Flag;
    } Mouse; //-鼠标


    bool TabWidget_Changed;  //-当前页面数据是否有改动
    bool Quick_Set;          //-快速设置标志
    int  remove_row;         //-移除项目,行数
    QLabel *Conf_label_Hide; //-隐藏标签
    bool  conf_Waring;       //-配置警告标志位
    QLabel *label_Waring;    //-警告标签
    QLabel *label_Waring_MAG;  //-反嵌警告
    QStringList parameter;   //-参数-程序包含的参数
    QStringList model_Type;  //-电机类型图
//    int Error_Item[19];      //-错误的项目
//    int Error_Item_Count[19];  // -错误的项目以累加进行判定
    int Count_Item;          //-功能数目

    struct {
        QTimer *Time;
        bool Flag;
    }Beep; //-蜂鸣器

    bool same_ip_address;   // -本机ip和连接网络的ip是否处在同一个网段
    bool NetSQL_OpenOk;     //-网络数据库是否打开

    QLabel *label_Set;      //-"设置中,请稍候“，警告标签
    QLabel *lable_Zero;     //-"正在清零。请稍候"，警告标签

    int  Ini_Power_Chose;   //-读取功率板的电源选择
    int  Ini_Mag_Hide;      //-读取反嵌波形是否隐藏
    bool Ini_Udp_Enable;    // -读取-UDP-使能

    QCheckBox *Quick_Set_Standard;
    QWidget *Quick_Set_Widget;
    QPushButton *Quick_Set_Show_join;
    QList<QLabel*> Quick_Set_Show_Lable;
    QList<QDoubleSpinBox*> Quick_Set_DoubleSpinBox;
    void Quick_Set_UI();

    QThread    *U_Thread;
    int  Out_Channel_6;
    bool PWR_Test_Usart;
    bool Ini_IMP5000;
    bool Ini_IR5000;
    bool Ini_DCR15;
    int  Ini_Set_pwr_Turn;
    double  Ini_ACW_I_Up;
    double  Ini_DCW_I_Up;
    int  Ini_DCW_Volt_Up;
    int  Ini_IMP_36;
    int  Ini_IO_Model;
    int  Ini_ACW_Volt_Limit;

    bool Ini_DCR_Cancle;
    int  Ini_Number;        //-读取当前系统的数量
    int  Ini_IRHostJudge;   //-读取绝缘主机判定结果
    int  Ini_DCR_Balance;   //-电阻不平衡度测试的方式
    int  Ini_Pwr_Turn;      //-设置通功率只显示转向
    QStringList Ini_System; //-读取当前系统
    QStringList Ini_Proj;   //-读取系统设置(后面)
    QStringList Ini_Proj_Real;   //-读取系统设置的全部
    QStringList Ini_Password;    //-读取系统的密码
    QString     Ini_SQL_Enable;  //-读取数据库使能
    QString     Ini_Factory;     //-读取出厂编号
    QString     Ini_Set_ImpVolt; // -读取匝间是否返回电压
    QString     Ini_Motor;       // -读取电机是否为PG电机
    QString     Ini_Task_Table;  //-读取系统的任务表名

    bool        Ini_imp_min;     //-匝间设置上下限制
    int         Ini_BLDC_Start_Mode;
    int         Ini_BLDC_Start_Item;
    int         Ini_BLDC_PG_Chose;
    int         Ini_Line_HV;
    QString     Line_HV_High, Line_HV_Low;

    bool SQL_Init;             //-网络下载数据库初始化,（为大洋进行设定）
    QWidget *SQL_Widget;       //-网络下载数据库窗口
    QStringList SQL_Task;      //-网络下载数据库信息列表
    QList<QLabel*> SQL_lable;  //-网络下载数据库标签
    QList<QLineEdit*> SQL_Line_Text; //-网络下载数据库文本
    QComboBox *SQL_Produce_Plan;     //-网络下载数据库计划
    QComboBox *SQL_Produce_Number;   //-网络下载数据库生产数量

    QWidget *Item_Widget;            //-项目选择窗口
    QList<QPushButton*> Item_Putton; //-项目按键
    QButtonGroup *btnGroup_Item;     //-测试项目的按键
    QCheckBox    *Item_Chose_Box;    //-测试项目的选择

    union  Resultunion { //-接收电感数据
        float   Result;
        uint8_t dat[4];
    };
    Resultunion  Result_indl;

    int   IRACW_Compensate; // -绝缘交耐进行补偿
    int   Test_Occur_Debug; // -测试遇不合格测试
    QString  serial_number; // -测试编号
    QStringList    strTest; // -测试项目
    QStringList   strParam; // -测试参数
    QStringList   sql_Test; // -数据库测试保存项目

    bool  sdcard_exist;
    int   iColorBtn;                      // -颜色选择按键id
    QList<QToolButton *> qColor_BtnList;  // -颜色选择按键按键列表
    QStringList  colorIdList;             // -颜色选择按键

    can_frame    frame;
    LINUX_SQL    sql;
    LINUX_SQL    sql_net;
    SqlClient    sql_Client;
    QThread      *thread_sql;

    QStringList  conf_c; // -CONF的复制
    QStringList  checked_File;
    QStringList  test_Inifile;
    QStringList  test_List;
    QStringList  AutoSet[8];
    struct {
        QString Color;
        QString DLR;
        QString MAG;
        QString IMP;
        QString IINDL; // -勿修改
    }Ini;

    int   DCR_Balance; // 电阻不平衡度测试
    bool  isopend;
    bool  Exist_Pwr;
    int   Right_Test;
    bool  Quick_set_IRACW_Value;
    bool  Ini_Vacuum_Model;

    void  mousePressEvent(QMouseEvent * event);
    void  mouseReleaseEvent(QMouseEvent * event);
    bool  handleMousePressEvent(QMouseEvent *event);
    int   timeval_subtract(struct timeval*, struct timeval*, struct timeval*);

    int   Get_Ip_Address();
    void  Beep_State();
    void  Usart_GetFcous();
    void  Sync_Conf();
    void  Sync_Test_Widget();
    void  Save_Ini_DateFile();
    void  Init_Conf_file(int, QStringList);
    void  Conf_ProjKey(int i, bool);
    void  Get_SqlData();
    void  Init_Conf_Interface();
    void  Save_SqlData();
    void  Save_SystemConf_Data(int);
    void  Save_ConfData();
    void  Set_Color(QString colr);
    void  Save_Hint();
    void  Init_test_TableWidget();
    void  Pri_Conf_WMessage(QString Waring_Text);
    void  Conf_Net_WMessage(QString data);
    void  DLR_Compensate_Back(QStringList);
    void  Conf_Set_User(int);
    void  Quick_Set_Function();
    void  Save_Test_Data(QStringList);
    void  Usart_Button(int);
    void  PC_CONF_Data();
    void  PC_SYS_Data();
    void  PC_Item_DCR_Data();
    void  PC_Item_IR_Data();
    void  PC_Item_ACW_Data();
    void  PC_Item_DCW_Data();
    void  PC_Item_IMP_Data();
    void  PC_Item_PWR_Data();
    void  PC_Item_IND_Data();
    void  PC_Item_PGHALL_Data();
    void  PC_Item_LOAD_Data();
    void  PC_Item_NOLOAD_Data();
    void  PC_Item_BEMF_Data();
    void  PC_Item_MAG_Data();

    void  PC_Test_Param_Data(QStringList);
    void  PC_Test_Param_connect();
    QStringList Board_DLR_TestData(can_frame);
    void  FG_bound_Item();
    void  PWR_DCR_bound_Item();
    void  Conf_Usart_Data(int, QStringList);
    void  Delete_File();

signals:
    void canSend(can_frame frame, int);
    void Singal_Data_Scale(QStringList, int, int);
    void Singal_Conf_to_Main(QStringList, QString, int, int);
    void WriteMessage(quint16, quint16, QByteArray);
    void WriteMessage_NoVacuum(quint16, quint16, QByteArray);
    void WConf_DeviceOpen();
    void WConf_WriteSql(QByteArray);
    void sendAppMap(QVariantMap msg);

public slots:
    void SlOT_CanSendFrame(can_frame frame);
    void SlOT_Receive_3_6_test(int);
    void SlOT_CanSendFrame_PWR(can_frame frame, int);
    void SlOT_Lable_Display();
    void Slot_test_to_conf(QStringList, QString, int);
    void Slot_Save_Debug(QString, QString);
    void Slot_Save_DayRecoord(QString, QString);
    void SlOT_can_to_conf(can_frame frame, QStringList, int);

private slots:
    void beep_stop();
    void test_mouse_check();
    void SlOT_ButtonProj(int);
    void SlOT_Button_IMP_Sample(int);
    void SlOT_Button_Function_Judge(int);
    void SlOT_Button_Color_Judge(int);
    void SlOT_Button_Conf_Judge(int);
    void on_fileBtnAdd_clicked();
    void on_fileBtnDel_clicked();
    void on_fileBtnCheck_clicked();
    void Item_Chose_Box_stateChanged(int);
    int  on_MotorType_currentIndexChanged(int index);
    void on_test_clicked(const QModelIndex &index);
    void on_fileTab_cellClicked(int row, int column);
    void on_SQL_Task_clicked();
    void SQL_Produce_Plan_textChanged(const QString &);
    void SQL_Produce_Number_textChanged(const QString &);
    void SQL_Widget_autoquit();
    void Quick_Set_autoquit();
    void Quick_Set_Show_join_Clicked();
    void ModeButtonsToggled(int);
};

#endif // W_CONF_H
