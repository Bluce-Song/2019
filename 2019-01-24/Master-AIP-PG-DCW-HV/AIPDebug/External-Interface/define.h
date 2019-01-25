/*******************************************************************************
 * Copyright [2016]   <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     2.0.7.1
 * author:      sl
 * brief:       头文件
*******************************************************************************/
#ifndef DEFINE_H
#define DEFINE_H

#include <QtGui/QApplication>
#include <QDesktopWidget>
#include <QDebug>


#define CONF  strList[0]
#define RES   strList[1]
#define OPP   strList[2]
#define INS   strList[3]
#define ACV   strList[4]
#define DCV   strList[5]
#define ITT   strList[6]
#define PWR   strList[7]
#define INDL  strList[8]
#define BLOCK strList[9]
#define LVS   strList[10]
#define BLDCPG strList[11]
#define LOAD   strList[12]
#define NOLOAD strList[13]
#define BEMF   strList[14]
#define HV     strList[15]

#define NUM_RES       16
#define NUM_RES_Con   25
#define NUM_OPP       820
#define NUM_INS
#define NUM_ACV
#define NUM_DCV
#define NUM_ITT       820
#define NUM_WAVE      800

// #define Current_Pro_Address           145  // -配置文件选项地址
// #define Current_Pro_Number_Address    30   // -配置文件总数地址
// #define Current_Pro_System_Address    45   // -配置系统文件总数地址
// #define Current_Pro_System_Sum        6    // -配置系统文件总数
// #define Current_Pro_Password_Address  85   // -配置密码文件总数地址
// #define Current_Pro_Password_Sum      3    // -配置密码文件总数

#define Start_model_Front     0   // -前面启动
#define Start_model_Remoter   1   // -脚踏启动
#define Start_model_Cover     2   // -滑罩启动
#define Start_model_Net       3   // -网络启动

#define User_Operator         0   // -操作员
#define User_Administrators   1   // -管理员

#define Receive_Stop          0   // -停止
#define Receive_Start         1   // -启动

#define Test_Station_Stay     4   // -呆住
#define Test_Station_Ask      3   // -询问
#define Test_Station_Inte     2   // -中断
#define Test_Station_Busy     1   // -忙碌
#define Test_Station_Free     0   // -空闲

#define Test_NG_Continue      0   // -继续
#define Test_NG_Stop          1   // -停止
#define Test_NG_Ask           2   // -询问

#define TestIW_IR             1   // -测试耐压板绝缘
#define TestIW_ACW            2   // -测试交流耐压板交耐
#define TestIW_DCW            3   // -测试直流耐压板交耐
#define TestIW_HV             4   // -测试高压搭线


#define wMain_Surface         0
#define wSyst_Surface         1
#define wModl_Surface         2
#define wData_Surface         3
#define wTest_Surface         4
#define wHelp_Surface         5
#define wBack_Surface         6
#define wColr_Surface         7
#define wConf_Surface         8
#define wDebug_Surface        9
#define wPassWord_Surface     10

#define Password_Syst         0
#define Password_Debug        1
#define Password_Conf         4

#define Memory_surplus        70   // -内存剩余70Mb,进行报警
#define Out_Board_Number      5    // -输出板个数
#define All_Model_Number      20   // -输出板5 空位0 功能总个数 14
                  // DLR MAG IR ACW DCW IMP PWR INDL STALL LVS BLDC-PG Load No-Load BEMF
                  // HV

#define Test_File_path         "/mnt/nandflash/AIP/configure/Test_File.ini"
#define Test_Debug_path        "/mnt/nandflash/AIP/debug/debug.ini"
#define Test_Count_path        "/mnt/nandflash/AIP/count/count.ini"
#define Test_Day_Record_path   "/mnt/nandflash/AIP/dayrecord/dayrecord.ini"
#define Sys_path               "/mnt/nandflash/AIP/Sys.ini"
#define data_path              "/mnt/nandflash/AIP/data.ini"
#define Test_Day_Record_Error  "/mnt/nandflash/AIP/dayrecord/day.ini"

#define   ZhongTe    1 // 中特
#define   LvZhi      2 // 绿智
#define   WeiLing    3 // 威灵
#define   BenDuo     4 // 本多通商
#define   NanXin     5 // 苏州南新
#define   KaiYu      6 // 日电产凯宇
#define   Bosch      7 // 博世
#define   BenDuoTWO  8 // 本多通商
#define   BDVacuum   9 // 本多真空
#define   Noise       11
#define   BePuDa      12
#define   MaiXing     13
#define   Ciximinghua 15 // G201708036
#define   DeChang     16
#define   BaoJiaLiYa  17
#define   WL_Hall     19
#define   ME_Hall     20 // 嗎恩科技
#define   NEW_Hall    21 // new rot

#define   NANXIN_Vacuum     35
#define   SAIPU             36
#define   Vacuum_Cooperate  40 // G201811010
#define   XINQIDIAN         41 // G201803049
// extern
#endif // DEFINE_H
