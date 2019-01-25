/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     2.0
 * author:      SL
 * date:        2015.12.10
 * brief:       主界面
*******************************************************************************/
#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QDir>
#include <QTime>
#include <time.h>
#include <QObject>
#include <QSettings>
#include <QUdpSocket>
#include <QStringList>
#include <QFile>

#include <QtXml/QDomDocument>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

#include "define.h"

#define CMD_Put_ITEM           0x1001 // 更新测试项目
#define CMD_Put_STATUS_Cheak   0x1002 // 状态查询
#define CMD_Put_STATUS_Ing     0x1003 // 状态返回

#define CMD_Put_Login          0x1004 // 登入
#define CMD_Put_Reply          0x1005 // 应答
#define CMD_Put_Message        0x1006 // 警告
#define CMD_Put_CONF_Data      0x1007 // 配置数据
#define CMD_Put_Start_Item     0x1008 // 启动单个项目
#define CMD_Put_Oder_Model     0x1009 // 获取顺序
#define CMD_Put_Updae_Model    0x100A // 切换
#define CMD_Put_All_Start      0x100B // 总启动
#define CMD_Put_All_Stop       0x100C // 总停止 急停
#define CMD_Put_Time           0x100D // 超时   急停
#define CMD_Put_73             0x100E //
#define CMD_Put_75             0x100F //
#define CMD_Put_76             0x1010 //
#define CMD_Put_IO_IN          0x1011 //
#define CMD_Put_81             0x1012
#define CMD_Put_82             0x1013
#define CMD_Put_85             0x1014
#define CMD_Put_86             0x1015
#define CMD_Put_87             0x1016
#define CMD_Put_V_State        0x1017
#define CMD_Put_92             0x1018
#define CMD_Put_97             0x1019
#define CMD_Put_96             0x101A
#define CMD_Put_98             0x101B
#define CMD_Put_Close_Pumb     0x101C // 关闭真空泵
#define CMD_Put_MEIZHI         0x101D // 清除美芝状态
#define CMD_Put_B1             0x101E
#define CMD_Put_GetTemp        0x101F
#define CMD_Put_ROT            0x1020
#define CMD_Put_PWR            0x1021
#define CMD_Put_NoStart        0x1022
#define CMD_Test_Message       0x1023
#define CMD_Reset_Again        0x1024

#define CMD_In_START           0x2001 // 启动
#define CMD_In_STOP            0x2002 // 停止
#define CMD_In_STATUS_Ing      0x2003 // 查询状态
#define CMD_In_Param           0x2004 // 参数
#define CMD_In_ICO             0x2005 // 图标
#define CMD_In_Connect         0x2006 // 获取警告 连接设备
#define CMD_In_CONF_Data       0x2007 // 配置数据
#define CMD_In_Start_Item      0x2008 // 启动单个项目
#define CMD_In_Init_Data       0x2009 // 下发配置数据
#define CMD_In_Judge           0x200A // 跳转测试界面
#define CMD_In_Add_Model       0x200B // 添加测试型号
#define CMD_In_Del_Model       0x200C // 删除型号
#define CMD_In_Oder_Model      0x200D // 获取顺序
#define CMD_In_IO_Put          0x200E //
#define CMD_In_MAG_Sample      0x200F //
#define CMD_In_IMP_Sample      0x2010
#define CMD_In_IMP_Ready       0x2011
#define CMD_In_Vacuum_IMP      0x2012
#define CMD_In_IMP_Finsh       0x2013
#define CMD_In_IMP_PL          0x2014
#define CMD_In_PIC             0x2015
#define CMD_In_9a              0x2016
#define CMD_In_Vacuum_ACW      0x2017
#define CMD_In_Start_Auto      0x2018
#define CMD_In_Start_No        0x2019 //
#define CMD_IN_Beep            0x201A // Beep.ok Beep.ng
#define CMD_In_A2              0x201B
#define CMD_In_A3              0x201C
#define CMD_In_A4              0x201D
#define CMD_In_A7              0x201E
#define CMD_In_A8              0x201F
#define CMD_In_AA              0x2020
#define CMD_In_A6              0x2021
#define CMD_In_B0              0x2022
#define CMD_In_Test_Auto       0x2023 // 下发自动启动
#define CMD_In_MEIZHI          0x2024 // 清除美芝状态
#define CMD_In_GetTemp         0x2025 //
#define CMD_In_GetOut          0x2026 //
#define CMD_In_Two_ACW         0x2027 //
#define CMD_In_No_Start        0x2028 //
#define CMD_In_Delay           0x2029 //

//#define CMD_ad        0x72    //
//#define CMD_77        0x77    //
//#define CMD_Curtain   0x9d    // 光幕
//#define CMD_Action    0x9e    // 样品到位
//#define CMD_A9        0xa9

class UdpClient : public QUdpSocket
{
    Q_OBJECT
public:
    explicit UdpClient(QObject *parent = 0);


signals:
    void SendCommand(quint16 addr, quint16 cmd, QByteArray msg);

private slots:
    void Init(void);
    void Quit(void);
    void InitSettings(void);
    void SaveSettings(void);
    void ReadAll(void);
    void Analy_XML_Data(QStringList);

public slots:
    void ReadMessage(quint16 addr, quint16 cmd, QByteArray msg);\
    void ReadMessage_NoVacuum(quint16 addr, quint16 cmd, QByteArray msg);

private:
    QString Number;
    QString Types;
    QString FileInUse;
    QString TxMsg;
    QString Status;
    QStringList Items;
    QHostAddress sender_Record;
    int Reply_conut; // -PC回应计数
    int Ini_Vacuum_Model;
    QString Get_Net_Temp;
};

#endif // UDPCLIENT_H
