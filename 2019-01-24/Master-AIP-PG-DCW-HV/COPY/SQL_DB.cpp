#include "SQL_DB.h"
#include <QDebug>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/un.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/types.h>
#include <linux/netlink.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

SQL_DB::SQL_DB(QObject *parent) :
    QThread(parent)
{

    QSettings *set_Sys = new QSettings(Sys_path, QSettings::IniFormat);
    set_Sys->setIniCodec("GB18030");
    QStringList Allocation_list;  Allocation_list<<"13"<<"14"<<"0"<<"0"<<"0"<<"0"<<"1"; // 默认 Allocation/Item

    System_currentProj_Number = set_Sys->value("Allocation/All","7").toString().toInt();
    currentProj_Real          = set_Sys->value("Allocation/Item",Allocation_list).toStringList();
    currentProj               = set_Sys->value("Allocation/Item",Allocation_list).toStringList().mid(5,System_currentProj_Number);
    Motor_PG_Commmon          = set_Sys->value("System/PG","Common").toString();
    ACW_Display = set_Sys->value("commonACW/text","0").toInt(); // 设置相间耐压和普通耐压的转换

    FILE *SD_Exist;
    SD_Exist = fopen("/dev/mmcblk0","r"); // 查看SD卡是否进行挂载
    if(SD_Exist!=NULL)
    {
        sdcard_exist = true;
        SQL_U.openSql("/mnt/sdcard/aip.db"); // 打开 sdcard 数据库
    }
    else
    {
        sdcard_exist = false;
        SQL_U.openSql("/mnt/nandflash/aip.db"); // 打开 nandflash 数据库
    }
    DB_Save_run = false;
    DB_MaxID_run = false;
    Test_Checking = false;
}

void SQL_DB::run() {
    if (DB_Save_run) {
        qDebug()<<"SQL_DB::DB_Save_run--->run()";
        DB_Save_run = false;
        Save_U_Data();

    }
    else if (DB_MaxID_run) {
        DB_MaxID_run = false;
        qDebug()<<"SQL_DB::DB_MaxID_run--->run()";
        Max_Id_Data();

    }
    else if(Test_Checking) {
        Test_Checking = false;
        qDebug()<<"QL_DB::Test_Checking--->run()";
        Test_CountData();
    }
    else {
        qDebug()<<"SQL_DB::else--->run()";
    }
}

void SQL_DB::Big_DataForm()
{
    qDebug()<<"Big_DataForm";
    int i,j,x,row_record=0,row_add=0;
    j=0; x=0;
    int row_field=0;
    QString    list_name = Search.at(0), list_start_time = Search.at(1), list_stop_time= Search.at(2);   // 得到搜索数据
    QSqlQuery  query(SQL_U.db);

    if(Get_BigData_Row<100) { // 限制查询条数,最多100条

    }
    else {
        Get_BigData_Row = 100;
    }
    qDebug()<<"0";
    query.setForwardOnly(true);
    if(list_name=="")
    {
        query.prepare(QString(tr("select  id from TestDa where 参数 >= '%1' and 参数 <= '%2' order by id desc limit %3")).arg(list_start_time).arg(list_stop_time).arg(Get_BigData_Row));
    }
    else
    {
        query.prepare(QString(tr("select id from TestDa where 结果 = :结果 and 参数 >= '%1' and 参数 <= '%2' order by id desc limit %3")).arg(list_start_time).arg(list_stop_time).arg(Get_BigData_Row));
        query.bindValue(tr(":结果"),list_name);   //电机型号
    }
    query.exec();
    QStringList FileRow;

    QStringList File_id,File_id_all;
    while(query.next())
    {
        File_id.append(query.value(0).toString());
    }

    qDebug()<<"1";
    for(i=0;i<File_id.size();i++)
    {
        query.prepare(QString(tr("select 判定 from TestDa where id = :id")));
        query.bindValue(":id",File_id.at(i).toInt()+2);   //电机型号
        query.exec();
        while(query.next())
        {
            File_id_all.append(query.value(0).toString());
        }
    }
    qDebug()<<"2";
    QStringList All_data;
    QStringList dlr_str,mag_str,ir_str,acw_str,imp_str,dlrbal_str,magr_str,indl_str,indlba_str,pwr_str,turn_str,block_str,lvs_str,pg_str;
    int dlr_number,mag_number,ir_number,acw_number,imp_number,dlrbal_number,magr_number,indl_number,indlba_number,pwr_number,turn_number,block_number,lvs_number,pg_number;
    QStringList hall_str,noload_str;
    int hall_number,noload_number;
    QStringList Add_data;

    for(i=0;i<File_id.size();i++)
    {
        Add_data.clear();
        All_data.clear();
        dlr_str.clear();  mag_str.clear();   ir_str.clear();  acw_str.clear();   imp_str.clear();   dlrbal_str.clear();   magr_str.clear();  indl_str.clear();  indlba_str.clear();  pwr_str.clear(); turn_str.clear(); block_str.clear(); lvs_str.clear(); pg_str.clear();
        dlr_number=0;mag_number=0; ir_number=0,acw_number=0,imp_number=0,dlrbal_number=0,magr_number=0,indl_number=0, indlba_number=0,pwr_number=0,turn_number=0,block_number=0,lvs_number=0,pg_number=0;
        hall_str.clear(); noload_str.clear();
        hall_number = 0; noload_number = 0;
        for(j=0;j<File_id_all.at(i).toInt()+3;j++)  // select data from TestDa
        {
            query.prepare(QString("select * from TestDa where id = :id"));
            query.bindValue(":id",File_id.at(i).toInt()+j);   //电机型号
            query.exec();
            while(query.next())
            {
                if(query.value(1).toString().contains("ITEM"))
                {
                    All_data.append(query.value(2).toString());
                    All_data.append(query.value(3).toString());
                    All_data.append(query.value(4).toString());
                }
                else if(query.value(1).toString().contains(tr("-电阻-")))  //电阻不平衡度
                {
                    dlrbal_number++;
                    dlrbal_str.append("DCR-Unbalance");
                    dlrbal_str.append(query.value(3).toString());
                    dlrbal_str.append(query.value(4).toString());
                }
                else if(query.value(1).toString().contains(tr("电阻")))    //电阻
                {
                    dlr_number++;
                    dlr_str.append(query.value(1).toString()+" "+query.value(2).toString());
                    dlr_str.append(query.value(3).toString());
                    dlr_str.append(query.value(4).toString());
                }
                else if(query.value(1).toString().contains(tr("反嵌")))    //反嵌
                {
                    mag_number++;
                    mag_str.append(query.value(1).toString()+" "+query.value(2).toString());
                    mag_str.append(query.value(3).toString());
                    mag_str.append(query.value(4).toString());
                }
                else if(query.value(1).toString()==(tr("磁旋")))    //磁旋
                {
                    magr_number++;
                    magr_str.append(query.value(1).toString()+" "+query.value(2).toString());
                    magr_str.append(query.value(3).toString());
                    magr_str.append(query.value(4).toString());
                }
                else if(query.value(1).toString().contains(tr("绝缘")))    //绝缘
                {
                    ir_number++;
                    ir_str.append(query.value(1).toString()+" "+query.value(2).toString());
                    ir_str.append(query.value(3).toString());
                    ir_str.append(query.value(4).toString());
                }
                else if(query.value(1).toString().contains(tr("交耐")))    //交耐
                {
                    acw_number++;
                    acw_str.append(query.value(1).toString()+" "+query.value(2).toString());
                    acw_str.append(query.value(3).toString());
                    acw_str.append(query.value(4).toString());
                }
                else if(query.value(1).toString().contains(tr("匝间")))    //匝间
                {
                    imp_number++;
                    imp_str.append(query.value(1).toString()+" "+query.value(2).toString());
                    imp_str.append(query.value(3).toString().split(","));
                    imp_str.append(query.value(4).toString());
                }
                else if(query.value(1).toString().contains(tr("-电感-")))  //电感不平衡度
                {
                    indlba_number++;
                    indlba_str.append("INDL-Unbalance,");
                    indlba_str.append(query.value(3).toString());
                    indlba_str.append(query.value(4).toString());
                }
                else if(query.value(1).toString().contains(tr("电感")))    //电感
                {
                    indl_number++;
                    indl_str.append(query.value(1).toString()+" "+query.value(2).toString());
                    indl_str.append(query.value(3).toString().split(","));
                    indl_str.append(query.value(4).toString());
                }
                else if(query.value(1).toString().contains(tr("电参")))    //电参
                {
                    pwr_number++;
                    pwr_str.append(query.value(1).toString()+" "+query.value(2).toString());
                    pwr_str.append(query.value(3).toString().split(","));
                    pwr_str.append(query.value(4).toString());
                }
                else if(query.value(1).toString()==(tr("转向")))    //转向
                {
                    turn_number++;
                    turn_str.append(query.value(1).toString()+" "+query.value(2).toString());
                    turn_str.append(query.value(3).toString());
                    turn_str.append(query.value(4).toString());
                }
                else if(query.value(1).toString().contains(tr("堵转")))    //堵转
                {
                    block_number++;
                    block_str.append(query.value(1).toString()+" "+query.value(2).toString());
                    block_str.append(query.value(3).toString().split(","));
                    block_str.append(query.value(4).toString());
                }
                else if(query.value(1).toString().contains(tr("低启")))    //低启
                {
                    lvs_number++;
                    lvs_str.append(query.value(1).toString()+" "+query.value(2).toString());
                    lvs_str.append(query.value(3).toString().split(","));
                    lvs_str.append(query.value(4).toString());
                }
                else if(query.value(1).toString().contains(tr("PG")))    //PG
                {
                    pg_number++;
                    pg_str.append(query.value(1).toString()+" "+query.value(2).toString());
                    pg_str.append(query.value(3).toString().split(","));
                    pg_str.append(query.value(4).toString());
                }
                else if(query.value(1).toString().contains(tr("HALL")))    //HALL
                {
                    hall_number++;
                    hall_str.append(query.value(1).toString()+" "+query.value(2).toString());
                    hall_str.append(query.value(3).toString().split(","));
                    hall_str.append(query.value(4).toString());
                }
                else if(query.value(1).toString().contains(tr("空载")))    //空载
                {
                    noload_number++;
                    noload_str.append(query.value(1).toString()+" "+query.value(2).toString());
                    noload_str.append(query.value(3).toString().split(","));
                    noload_str.append(query.value(4).toString());
                }
                else {

                }
            }
        }
        Add_data = All_data;
        for(row_field=1; row_field<currentProj.size(); row_field++)
        {
            switch(currentProj.at(row_field).toInt())
            {
            case 1:
                for(x=dlr_number;x<8;x++)
                {
                    dlr_str.append(" ");  dlr_str.append(" ");  dlr_str.append(" ");
                }
                for(x=dlrbal_number;x<1;x++)
                {
                    dlrbal_str.append(" ");  dlrbal_str.append(" ");  dlrbal_str.append(" ");
                }
                Add_data += dlr_str;
                Add_data += dlrbal_str;
                break;
            case 2:
                for(x=mag_number;x<8;x++)
                {
                    mag_str.append(" ");  mag_str.append(" ");  mag_str.append(" ");
                }
                for(x=magr_number;x<1;x++)
                {
                    magr_str.append(" ");  magr_str.append(" ");  magr_str.append(" ");
                }
                Add_data += mag_str;
                Add_data += magr_str;
                break;
            case 3:
                if(ACW_Display == 1) //进行相间绝缘的显示
                {
                    for(x=ir_number;x<4;x++)
                    {
                        ir_str.append(" ");  ir_str.append(" ");  ir_str.append(" ");
                    }
                    Add_data += ir_str;
                }
                else
                {
                    for(x=ir_number;x<1;x++)
                    {
                        ir_str.append(" ");  ir_str.append(" ");  ir_str.append(" ");
                    }

                    if(ir_str.size()>2)
                    {
                        ir_str = ir_str.mid(0,3);
                    }
                    Add_data += ir_str;
                }
                break;
            case 4:
                if(ACW_Display == 1) //进行相间耐压的显示
                {
                    for(x=acw_number;x<4;x++)
                    {
                        acw_str.append(" ");  acw_str.append(" ");  acw_str.append(" ");
                    }
                    Add_data += acw_str;
                }
                else
                {
                    for(x=acw_number;x<1;x++)
                    {
                        acw_str.append(" ");  acw_str.append(" ");  acw_str.append(" ");
                    }
                    if(acw_str.size()>2)
                    {
                        acw_str = acw_str.mid(0,3);
                    }
                    Add_data += acw_str;
                }
                break;
            case 5:

                break;
            case 6:
                for(x=imp_number;x<8;x++)
                {
                    imp_str.append(" ");  imp_str.append(" "); imp_str.append(" "); imp_str.append(" "); imp_str.append(" ");  imp_str.append(" ");
                }
                Add_data += imp_str;
                break;
            case 7:
                for(x=pwr_number;x<6;x++)
                {
                    pwr_str.append(" ");   pwr_str.append(" ");  pwr_str.append(" "); pwr_str.append(" ");  pwr_str.append(" ");
                }
                for(x=turn_number;x<6;x++)
                {
                    turn_str.append(" ");  turn_str.append(" ");  turn_str.append(" ");
                }
                if(Motor_PG_Commmon==QString(tr("PG")))
                {
                    for(x=pg_number;x<3;x++)
                    {
                        pg_str.append(" ");  pg_str.append(" ");  pg_str.append(" ");
                    }
                }


                Add_data += pwr_str;   Add_data += turn_str;

                if(Motor_PG_Commmon==QString(tr("PG")))
                {
                    Add_data += pg_str;
                }
                break;
            case 8:
                for(x=indl_number;x<8;x++)
                {
                    indl_str.append(" ");  indl_str.append(" "); indl_str.append(" "); indl_str.append(" ");
                }
                for(x=indlba_number;x<1;x++)
                {
                    indlba_str.append(" ");  indlba_str.append(" ");  indlba_str.append(" ");
                }
                Add_data += indl_str;
                Add_data += indlba_str;
                break;
            case 9:
                for(x=block_number;x<1;x++)
                {
                    block_str.append(" ");  block_str.append(" "); block_str.append(" "); block_str.append(" ");
                }
                Add_data += block_str;
                break;
            case 10:
                for(x=lvs_number;x<1;x++)
                {
                    lvs_str.append(" ");  lvs_str.append(" "); lvs_str.append(" "); lvs_str.append(" ");
                }
                Add_data += lvs_str;
                break;
            case 11: // hall
                for(x=hall_number;x<5;x++)
                {
                    hall_str.append(" ");   hall_str.append(" "); hall_str.append(" ");
                }
                Add_data += hall_str;
                break;
            case 12: // 负载

                break;
            case 13: // 空载
                for(x=noload_number;x<1;x++)
                {
                    noload_str.append(" ");   noload_str.append(" "); noload_str.append(" ");
                }
                Add_data += noload_str;
                break;
            case 14: // BEMF

                break;
            default:
                break;
            }
        }

        if(Add_data.size()==data_length)
        {

        }
        else if(Add_data.size()<data_length)
        {
            for(i=Add_data.size();i<=data_length;i++)
            {
                Add_data.append("");
            }
        }
        else if(Add_data.size()>data_length)
        {
            Add_data = Add_data.mid(0,data_length);
        }
        else
        {

        }
        FileRow.append(Add_data);

        row_record++;

        if(row_record==100) // 100行数据增加1页
        {
            qDebug()<<"row_record==100";
            row_record=0;
            row_add++;
            Singal_Data_Scale(FileRow,row_add,2);
            FileRow.clear();
        }
    }
    row_add++;
    Singal_Data_Scale(FileRow,row_add,2);
    FileRow.clear();

    Singal_Data_Scale(QStringList(""),6,6);
     qDebug()<<"Big_DataForm Finsh";
}

void SQL_DB::Delete_Data_Data()
{
    qDebug()<<"删除数据库";
    SQL_U.deleteAll("TestDa");
    if(sdcard_exist)
    {
        system("cp /mnt/nandflash/AIP/aip.db /mnt/sdcard/"); // 2017.6.8 增加
    }
    else
    {
        system("cp /mnt/nandflash/AIP/aip.db /mnt/nandflash/"); // 2017 3 10 增加
    }
    system("sync");
}

void SQL_DB::Slot_Data_to_SQLDB(QString USB,QStringList str,int flag)
{
    qDebug()<<"Slot_Data_to_SQLDB"<<flag;
    switch(flag)
    {
    case 1:
        DB_Save_run = true;
        list_name = str.at(0);
        list_start_time = str.at(1);
        list_stop_time = str.at(2);   // 得到搜索数据
        USB_name = str.at(3);
        break;
    case 2:
        DB_MaxID_run = true;
        break;
    case 3:
        qDebug()<<"3";
        Search = str;
        Test_Checking = true;
        run();
        break;
    case 4:
        Delete_Data_Data();
        break;
    default:

        break;
    }
    USB.clear();
}

void SQL_DB::Max_Id_Data() {
    int Maxid = SQL_U.selectMax("TestDa");
    Singal_Data_Scale(QStringList(""),Maxid,4);
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2017.11.27
  * brief:      数据管理界面的数据测试
******************************************************************************/
void SQL_DB::Test_CountData()
{
    int i,j;
    QString  name = Search.at(0);
    QString  start_time= Search.at(1);
    QString  stop_time= Search.at(2);   // 得到搜索数据

    QStringList count_list;
    QStringList model_list;
    QStringList listcopy,listcopy_all,listcopy_error;

    int all = 0,all_error = 0; // 总数量
    int DLR_All = 0,DLR_Error = 0,DLRBalance_All = 0,DLRBalance_Error = 0; // 电阻 电阻不平衡度
    int MAG_All = 0,MAG_Error = 0,MAGR_All = 0,MAGR_Error = 0; // 反嵌 磁旋
    int IR_All = 0,IR_Error = 0; // 绝缘
    int ACW_All = 0,ACW_Error = 0; // 交耐
    int IMP_All = 0,IMP_Error = 0; // 匝间
    int PWR_All = 0,PWR_Error = 0; // 电参
    int TURN_All = 0,TURN_Error = 0; // 转向
    int INDL_All = 0,INDL_Error = 0,INDLBA_All = 0, INDLBA_Error = 0; // 电感 电感不平衡度
    int BLOCK_All = 0,BLOCK_Error = 0; // 堵转
    int LVS_All = 0,LVS_Error = 0; // 低启
    int PG_All = 0,PG_Error = 0; // PG
    int HALL_All = 0,HALL_Error = 0; // HALL
    int NOLOAD_All = 0,NOLOAD_Error = 0; // NOLOAD

    QSqlQuery query(SQL_U.db);

    if(name=="")  //  无名称搜索+日期
    {
        qDebug()<<"无名称和日期搜索"<<start_time<<stop_time;
        query.prepare(QString(tr("select 结果,判定,配置 from TestDa where 参数 >= '%1' and 参数 <= '%2'")).arg(start_time).arg(stop_time));  //
        query.exec();
        while(query.next())
        {
            all++;
            if(query.value(2).toString()!="")
            {
                model_list.append(query.value(0).toString());   // 连接电机型号名称
                listcopy = query.value(2).toString().split("------");  //  分割符号
                listcopy_all = listcopy.at(0).split(" ");
                listcopy_error = listcopy.at(1).split(" ");
                if(query.value(1).toString()!="OK")
                {
                    all_error++;
                    for(i=0;i<listcopy_all.size();i++)
                    {
                        if(listcopy_all.at(i)==tr("电阻"))
                        {
                            DLR_All++;
                        }
                        else if(listcopy_all.at(i)==tr("电阻不平衡度"))
                        {
                            DLRBalance_All++;
                        }
                        else if(listcopy_all.at(i)==tr("反嵌"))
                        {
                            MAG_All++;
                        }
                        else if(listcopy_all.at(i)==tr("磁旋"))
                        {
                            MAGR_All++;
                        }
                        else if(listcopy_all.at(i)==tr("绝缘"))
                        {
                            IR_All++;
                        }
                        else if(listcopy_all.at(i)==tr("交耐"))
                        {
                            ACW_All++;
                        }
                        else if(listcopy_all.at(i)==tr("匝间"))
                        {
                            IMP_All++;
                        }
                        else if(listcopy_all.at(i)==tr("电感"))
                        {
                            INDL_All++;
                        }
                        else if(listcopy_all.at(i)==tr("电感不平衡度"))
                        {
                            INDLBA_All++;
                        }
                        else if(listcopy_all.at(i)==tr("电参"))
                        {
                            PWR_All++;
                        }
                        else if(listcopy_all.at(i)==tr("转向"))
                        {
                            TURN_All++;
                        }
                        else if(listcopy_all.at(i)==tr("堵转"))
                        {
                            BLOCK_All++;
                        }
                        else if(listcopy_all.at(i)==tr("低启"))
                        {
                            LVS_All++;
                        }
                        else if(listcopy_all.at(i).contains(tr("PG")))
                        {
                            PG_All++;
                        }
                        else if (listcopy_all.at(i).contains(tr("HALL"))) {
                            HALL_All++;
                        } else if (listcopy_all.at(i).contains(tr("空载"))) {
                            NOLOAD_All++;
                        } else {

                        }
                    }
                    for(i=0;i<listcopy_error.size();i++)
                    {
                        if(listcopy_error.at(i)==tr("电阻"))
                        {
                            DLR_Error++;
                        }
                        else if(listcopy_error.at(i)==tr("电阻不平衡度"))
                        {
                            DLRBalance_Error++;
                        }
                        else if(listcopy_error.at(i)==tr("反嵌"))
                        {
                            MAG_Error++;
                        }
                        else if(listcopy_error.at(i)==tr("磁旋"))
                        {
                            MAGR_Error++;
                        }
                        else if(listcopy_error.at(i)==tr("绝缘"))
                        {
                            IR_Error++;
                        }
                        else if(listcopy_error.at(i)==tr("交耐"))
                        {
                            ACW_Error++;
                        }
                        else if(listcopy_error.at(i)==tr("匝间"))
                        {
                            IMP_Error++;
                        }
                        else if(listcopy_error.at(i)==tr("电感"))
                        {
                            INDL_Error++;
                        }
                        else if(listcopy_error.at(i)==tr("电感不平衡度"))
                        {
                            INDLBA_Error++;
                        }
                        else if(listcopy_error.at(i)==tr("电参"))
                        {
                            PWR_Error++;
                        }
                        else if(listcopy_error.at(i)==tr("转向"))
                        {
                            TURN_Error++;
                        }
                        else if(listcopy_error.at(i)==tr("堵转"))
                        {
                            BLOCK_Error++;
                        }
                        else if(listcopy_error.at(i)==tr("低启"))
                        {
                            LVS_Error++;
                        }
                        else if(listcopy_error.at(i)==tr("PG"))
                        {
                            PG_Error++;
                        }
                        else if (listcopy_all.at(i).contains(tr("HALL"))) {
                            HALL_Error++;
                        } else if (listcopy_all.at(i).contains(tr("空载"))) {
                            NOLOAD_Error++;
                        } else {

                        }
                    }
                }
                else
                {
                    for(i=0;i<listcopy_all.size();i++)
                    {
                        if(listcopy_all.at(i)==tr("电阻"))
                        {
                            DLR_All++;
                        }
                        else if(listcopy_all.at(i)==tr("电阻不平衡度"))
                        {
                            DLRBalance_All++;
                        }
                        else if(listcopy_all.at(i)==tr("反嵌"))
                        {
                            MAG_All++;
                        }
                        else if(listcopy_all.at(i)==tr("磁旋"))
                        {
                            MAGR_All++;
                        }
                        else if(listcopy_all.at(i)==tr("绝缘"))
                        {
                            IR_All++;
                        }
                        else if(listcopy_all.at(i)==tr("交耐"))
                        {
                            ACW_All++;
                        }
                        else if(listcopy_all.at(i)==tr("匝间"))
                        {
                            IMP_All++;
                        }
                        else if(listcopy_all.at(i)==tr("电感"))
                        {
                            INDL_All++;
                        }
                        else if(listcopy_all.at(i)==tr("电感不平衡度"))
                        {
                            INDLBA_All++;
                        }
                        else if(listcopy_all.at(i)==tr("电参"))
                        {
                            PWR_All++;
                        }
                        else if(listcopy_all.at(i)==tr("转向"))
                        {
                            TURN_All++;
                        }
                        else if(listcopy_all.at(i)==tr("堵转"))
                        {
                            BLOCK_All++;
                        }
                        else if(listcopy_all.at(i)==tr("低启"))
                        {
                            LVS_All++;
                        }
                        else if(listcopy_all.at(i).contains(tr("PG")))
                        {
                            PG_All++;
                        }
                        else if (listcopy_all.at(i).contains(tr("HALL"))) {
                            HALL_All++;
                        } else if (listcopy_all.at(i).contains(tr("空载"))) {
                            NOLOAD_All++;
                        } else {

                        }
                    }
                }
            }
        }
    }
    else    //  电机型号+日期
    {
        qDebug()<<"电机型号和日期搜索";
        query.prepare(QString(tr("select 结果,判定,配置 from TestDa where 结果 = :结果 and 参数 >= '%1' and 参数 <= '%2'")).arg(start_time).arg(stop_time));  //
        query.bindValue(tr(":结果"),name);
        query.exec();
        while(query.next())
        {
            all++;
            model_list.append(query.value(0).toString());   // 连接电机型号名称
            listcopy = query.value(2).toString().split("------");  //  分割符号  ------
            listcopy_all = listcopy.at(0).split(" ");
            listcopy_error = listcopy.at(1).split(" ");
            if(query.value(1).toString()!="OK")
            {
                all_error++;
                qDebug() << "listcopy_all" << listcopy_all;
                qDebug()<<"all_error----"<<all_error<<"    listcopy_error----"<<listcopy_error;
                for(i=0;i<listcopy_all.size();i++)
                {
                    if(listcopy_all.at(i)==tr("电阻"))
                    {
                        DLR_All++;
                    }
                    else if(listcopy_all.at(i)==tr("电阻不平衡度"))
                    {
                        DLRBalance_All++;
                    }
                    else if(listcopy_all.at(i)==tr("反嵌"))
                    {
                        MAG_All++;
                    }
                    else if(listcopy_all.at(i)==tr("磁旋"))
                    {
                        MAGR_All++;
                    }
                    else if(listcopy_all.at(i)==tr("绝缘"))
                    {
                        IR_All++;
                    }
                    else if(listcopy_all.at(i)==tr("交耐"))
                    {
                        ACW_All++;
                    }
                    else if(listcopy_all.at(i)==tr("匝间"))
                    {
                        IMP_All++;
                    }
                    else if(listcopy_all.at(i)==tr("电感"))
                    {
                        INDL_All++;
                    }
                    else if(listcopy_all.at(i)==tr("电感不平衡度"))
                    {
                        INDLBA_All++;
                    }
                    else if(listcopy_all.at(i)==tr("电参"))
                    {
                        PWR_All++;
                    }
                    else if(listcopy_all.at(i)==tr("转向"))
                    {
                        TURN_All++;
                    }
                    else if(listcopy_all.at(i)==tr("堵转"))
                    {
                        BLOCK_All++;
                    }
                    else if(listcopy_all.at(i)==tr("低启"))
                    {
                        LVS_All++;
                    }
                    else if(listcopy_all.at(i).contains(tr("PG")))
                    {
                        PG_All++;
                    }
                    else if (listcopy_all.at(i).contains(tr("HALL"))) {
                        HALL_All++;
                    } else if (listcopy_all.at(i).contains(tr("空载"))) {
                        NOLOAD_All++;
                    } else {

                    }
                }
                for(i=0;i<listcopy_error.size();i++)
                {
              //      qDebug()<<"listcopy_error.at(i)"<<listcopy_error.at(i);
                    if(listcopy_error.at(i)==tr("电阻"))
                    {
                        DLR_Error++;
                    }
                    else if(listcopy_error.at(i)==tr("电阻不平衡度"))
                    {
                        DLRBalance_Error++;
                    }
                    else if(listcopy_error.at(i)==tr("反嵌"))
                    {
                        MAG_Error++;
                    }
                    else if(listcopy_error.at(i)==tr("磁旋"))
                    {
                        MAGR_Error++;
                    }
                    else if(listcopy_error.at(i)==tr("绝缘"))
                    {
                        IR_Error++;
                    }
                    else if(listcopy_error.at(i)==tr("交耐"))
                    {
                        ACW_Error++;
                    }
                    else if(listcopy_error.at(i)==tr("匝间"))
                    {
                        IMP_Error++;
                    }
                    else if(listcopy_error.at(i)==tr("电感"))
                    {
                        INDL_Error++;
                    }
                    else if(listcopy_error.at(i)==tr("电感不平衡度"))
                    {
                        INDLBA_Error++;
                    }
                    else if(listcopy_error.at(i)==tr("电参"))
                    {
                        PWR_Error++;
                    }
                    else if(listcopy_error.at(i)==tr("转向"))
                    {
                        TURN_Error++;
                    }
                    else if(listcopy_error.at(i)==tr("堵转"))
                    {
                        BLOCK_Error++;  qDebug()<<"堵转 增加";
                    }
                    else if(listcopy_error .at(i)==tr("低启"))
                    {
                        LVS_Error++;
                    }
                    else if(listcopy_error.at(i)==tr("PG"))
                    {
                        PG_Error++;
                    }
                    else if (listcopy_all.at(i).contains(tr("HALL"))) {
                        HALL_Error++;
                    } else if (listcopy_all.at(i).contains(tr("空载"))) {
                        NOLOAD_Error++;
                    } else {

                    }
                }
            }
            else
            {
                for(i=0;i<listcopy_all.size();i++)
                {
                    if(listcopy_all.at(i)==tr("电阻"))
                    {
                        DLR_All++;
                    }
                    else if(listcopy_all.at(i)==tr("电阻不平衡度"))
                    {
                        DLRBalance_All++;
                    }
                    else if(listcopy_all.at(i)==tr("反嵌"))
                    {
                        MAG_All++;
                    }
                    else if(listcopy_all.at(i)==tr("磁旋"))
                    {
                        MAGR_All++;
                    }
                    else if(listcopy_all.at(i)==tr("绝缘"))
                    {
                        IR_All++;
                    }
                    else if(listcopy_all.at(i)==tr("交耐"))
                    {
                        ACW_All++;
                    }
                    else if(listcopy_all.at(i)==tr("匝间"))
                    {
                        IMP_All++;
                    }
                    else if(listcopy_all.at(i)==tr("电感"))
                    {
                        INDL_All++;
                    }
                    else if(listcopy_all.at(i)==tr("转向"))
                    {
                        TURN_All++;
                    }
                    else if(listcopy_all.at(i)==tr("电感不平衡度"))
                    {
                        INDLBA_All++;
                    }
                    else if(listcopy_all.at(i)==tr("电参"))
                    {
                        PWR_All++;
                    }
                    else if(listcopy_all.at(i)==tr("堵转"))
                    {
                        BLOCK_All++;
                    }
                    else if(listcopy_all.at(i)==tr("低启"))
                    {
                        LVS_All++;
                    }
                    else if(listcopy_all.at(i).contains(tr("PG")))
                    {
                        PG_All++;
                    }
                    else if (listcopy_all.at(i).contains(tr("HALL"))) {
                        HALL_All++;
                    } else if (listcopy_all.at(i).contains(tr("空载"))) {
                        NOLOAD_All++;
                    } else {

                    }
                }
            }
        }
    }
    Get_BigData_Row = all;
    count_list<<tr("总数")<<QString::number(all)<<QString::number(all_error);
    data_length = 9;
    for(i=1; i<currentProj.size(); i++)
    {
        switch(currentProj.at(i).toInt())
        {
        case 1: count_list<<tr("电阻")<<QString::number(DLR_All)<<QString::number(DLR_Error);
                count_list<<tr("电阻不平衡度")<<QString::number(DLRBalance_All)<<QString::number(DLRBalance_Error);
                data_length += 27;
            break;
        case 2: count_list<<tr("反嵌")<<QString::number(MAG_All)<<QString::number(MAG_Error);
                count_list<<tr("磁旋")<<QString::number(MAGR_All)<<QString::number(MAGR_Error);
                data_length += 27;
            break;
        case 3:  count_list<<tr("绝缘")<<QString::number(IR_All)<<QString::number(IR_Error);
            if(ACW_Display) {
                data_length += 12;
            }
            else {
                data_length += 3;
            }
            break;
        case 4:  count_list<<tr("交耐")<<QString::number(ACW_All)<<QString::number(ACW_Error);
            if(ACW_Display) {
                data_length += 12;
            }
            else {
                data_length += 3;
            }
            break;
        case 5:
            break;
        case 6:
            count_list<<tr("匝间")<<QString::number(IMP_All)<<QString::number(IMP_Error);
            data_length += 48;
            break;
        case 7: count_list<<tr("电参")<<QString::number(PWR_All)<<QString::number(PWR_Error);
                count_list<<tr("转向")<<QString::number(TURN_All)<<QString::number(TURN_Error);
                data_length += 48;
                if(Motor_PG_Commmon==QString(tr("PG")))
                {
                   count_list<<tr("PG")<<QString::number(PG_All)<<QString::number(PG_Error);
                   data_length += 9;
                }
            break;
        case 8: count_list<<tr("电感")<<QString::number(INDL_All)<<QString::number(INDL_Error);
                count_list<<tr("电感不平衡度")<<QString::number(INDLBA_All)<<QString::number(INDLBA_Error);
                data_length += 35;
            break;
        case 9: count_list<<tr("堵转")<<QString::number(BLOCK_All)<<QString::number(BLOCK_Error);
            data_length += 4;
            break;
        case 10: count_list<<tr("低启")<<QString::number(LVS_All)<<QString::number(LVS_Error);
            data_length += 4;
            break;
        case 11: // hall
            count_list<<tr("HALL")<<QString::number(HALL_All)<<QString::number(HALL_Error);
            data_length += 15;
            break;
        case 12: // 负载

            break;
        case 13: // 空载
            count_list<<tr("空载")<<QString::number(NOLOAD_All)<<QString::number(NOLOAD_Error);
            data_length += 3;
            break;
        case 14: // BEMF

            break;
        default:
            break;
        }
    }
    qDebug()<<"count_list"<<count_list;
    if(model_list.size()>1)
    {
        for(i=0;i<model_list.size();i++)
        {
            for(j=1+i;j<model_list.size();j++)
            {
                if(model_list.at(i).compare(model_list.at(j))==0)
                {
                    model_list.removeAt(j);
                    j--;
                }
            }
        }
    }
    qDebug()<<"111";
    if(model_list.size()!=0)
    {
        count_list<<"Model"<<QString::number(model_list.size())<<model_list;
    }
    else
    {
        if(name=="")  // 无名称搜索
        {
            count_list<<"Model"<<"0"<<" ";
        }
        else          // 有名称搜索
        {
            if(count_list.at(1)=="0")
            {
                count_list<<"Model"<<"0"<<" ";
            }
            else
            {
                count_list<<"Model"<<"1"<<name;
            }
        }
    }
    qDebug()<<"222";
    Singal_Data_Scale(count_list,5,5);
    Big_DataForm();
}

void SQL_DB::Save_U_Data()
{
    int i,j = 0,x = 0;
    int row_record = 0;
    int row_add = 0;
    int row_field = 0;
    QEventLoop eventloop;

    QSqlQuery  query(SQL_U.db);

    QString Table_head; // 导出数据建立表头 (date,电机型号,总结果,时间,温度,工位,用户,id)
    Table_head.append(tr("date,电机型号,总结果,时间,温度,工位,编码,用户,总项目,"));
    for(row_field = 1; row_field<currentProj.size(); row_field++)
    {
        switch(currentProj.at(row_field).toInt())
        {
        case 1:
            for(i=0;i<8;i++)
            {   Table_head += QString(tr("电阻%1参数,电阻%1(ohm),电阻%1判定,")).arg(QString::number(i+1));   }
            Table_head += QString(tr("电阻不平衡度参数参数,不平衡度,不平衡度判定,"));
            break;
        case 2:
            for(i=0;i<8;i++)
            {   Table_head += QString(tr("反嵌%1参数,反嵌%1,反嵌%1判定,")).arg(QString::number(i+1));   }
            Table_head += QString(tr("磁旋参数,磁旋,磁旋判定,"));
            break;
        case 3:
            if(ACW_Display==1) // 相间绝缘
            {
                for(i=0;i<4;i++)
                {   Table_head += QString(tr("绝缘%1参数,绝缘%1(M ohm),绝缘%1判定,")).arg(QString::number(i+1));   }
            }
            else
            {
                Table_head += QString(tr("绝缘参数,绝缘(M ohm),绝缘判定,"));
            }
            break;
        case 4:
            if(ACW_Display==1) // 相间交耐
            {
                for(i=0;i<4;i++)
                {   Table_head += QString(tr("交耐%1参数,交耐%1(mA),交耐%1判定,")).arg(QString::number(i+1));   }
            }
            else
            {
                Table_head += QString(tr("交耐参数,交耐(mA),交耐,"));
            }
            break;
        case 5:

            break;
        case 6:
            for(i=0;i<8;i++)
            {   Table_head += QString(tr("匝间%1参数,面积%1,差积%1,电晕%1,相位%1,匝间%1判定,")).arg(QString::number(i+1));   }
            break;
        case 7:
            for(i=0;i<6;i++)
            {
                Table_head += QString(tr("电参%1参数,电流%1(A),功率%1(W),容压%1(V),电参%1判定,")).arg(QString::number(i+1));
            }
            for(i=0;i<6;i++)
            {
                Table_head += QString(tr("转向%1参数,转向%1,转向%1判定,")).arg(QString::number(i+1));
            }
            if(Motor_PG_Commmon==QString(tr("PG")))
            {
                for(i=0;i<3;i++)
                {
                    Table_head += QString(tr("PG %1参数,PG %1,PG %1判定,")).arg(QString::number(i+1));
                }
            }
            break;
        case 8:
            for(i=0;i<8;i++)
            {   Table_head += QString(tr("电感参数%1参数,电感%1(H),Q值%1,电感%1判定,")).arg(QString::number(i+1));  }
            Table_head += QString(tr("电感不平衡度参数,电感不平衡度,电感不平衡度判定,"));
            break;
        case 9:
            Table_head += QString(tr("堵转参数,电流(A),功率(W),堵转判定,"));
            break;
        case 10:
            Table_head += QString(tr("低启参数,电流(A),功率(W),低启判定,"));
            break;
        case 11: // hall
            for(i=0;i<5;i++)
            {
                Table_head += QString(tr("HALL %1参数,HALL %1,HALL %1判定,")).arg(QString::number(i+1));
            }
            break;
        case 12:

            break;
        case 13: // 空载
            Table_head += QString(tr("空载参数,空载,空载判定,"));
            break;
        case 14:

            break;
        default:
            break;
        }
    }
    Table_head = Table_head.left(Table_head.size()-1);
    Table_head += "\n";
    j=0; x=0;
    query.exec();
    QString ExportName = QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-");
    QString filePath = QString("/mnt/%1/%2.csv").arg(USB_name).arg(ExportName+"Data");  //存储U盘位置
    query.setForwardOnly(true);
    int Maxid = SQL_U.selectMax("TestDa");
    qDebug()<<"Maxid"<<Maxid;

    if(list_start_time==list_stop_time) { // 同日期
        if(list_name=="")
        {
            query.prepare(QString(tr("select id from TestDa where 参数 = '%1'")).arg(list_start_time));
        }
        else
        {
            query.prepare(QString(tr("select id from TestDa where 结果 = :结果 and 参数 = '%1'")).arg(list_start_time));
            query.bindValue(tr(":结果"),list_name);
        }
    }
    else { // 不同日期
        if(list_name=="")
        {
            query.prepare(QString(tr("select id from TestDa where 参数 >= '%1' and 参数 <= '%2'")).arg(list_start_time).arg(list_stop_time));
        }
        else
        {
            query.prepare(QString(tr("select id from TestDa where 结果 = :结果 and 参数 >= '%1' and 参数 <= '%2'")).arg(list_start_time).arg(list_stop_time));
            query.bindValue(tr(":结果"),list_name);
        }
    }
    query.exec();
    qDebug()<<"finsh--step 1";

    QString FileRow; FileRow.append(Table_head);
    QStringList File_id; // 步骤一
    int File_id_count;
    while(query.next())
    {
        File_id.append(query.value(0).toString());
    }
    File_id_count = File_id.size();
    qDebug()<<"finsh--step 2";

    QStringList File_id_all; // 步骤二
    for(i=0;i<File_id.size();i++)
    {
        query.prepare(QString(tr("select 判定 from TestDa where id = :id")));
        query.bindValue(":id",File_id.at(i).toInt()+2); // 电机型号
        query.exec();
        while(query.next())
        {
            File_id_all.append(query.value(0).toString());
        }
    }
    qDebug()<<"finsh--step 3";

    QString All_data;
    QString dlr_str;      int dlr_number;
    QString mag_str;      int mag_number;
    QString ir_str;       int ir_number;
    QString acw_str;      int acw_number;
    QString imp_str;      int imp_number;
    QString dlrbal_str;   int dlrbal_number;
    QString magr_str;     int magr_number;
    QString indl_str;     int indl_number;
    QString indlba_str;   int indlba_number;
    QString pwr_str;      int pwr_number;
    QString turn_str;     int turn_number;
    QString block_str;    int block_number;
    QString lvs_str;      int lvs_number;
    QString pg_str;       int pg_number;
    QString hall_str;     int hall_number; // hall
    QString noload_str;   int noload_number; // 空载
    QString Add_data;

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB18030")); // GB2312
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));   // GB2312
    QFile csvFile(filePath);
    csvFile.open(QIODevice::ReadWrite); // QIODevice::Text

    for(i=0;i<File_id.size();i++)
    {
        Add_data.clear();
        All_data.clear();

        dlr_str.clear();    dlr_number = 0;
        mag_str.clear();    mag_number = 0;
        ir_str.clear();     ir_number= 0;
        acw_str.clear();    acw_number = 0;
        imp_str.clear();    imp_number = 0;
        dlrbal_str.clear(); dlrbal_number = 0;
        magr_str.clear();   magr_number = 0;
        indl_str.clear();   indl_number = 0;
        indlba_str.clear(); indlba_number = 0;
        pwr_str.clear();    pwr_number = 0;
        turn_str.clear();   turn_number = 0;
        block_str.clear();  block_number = 0;
        lvs_str.clear();    lvs_number = 0;
        pg_str.clear();     pg_number = 0;
        hall_str.clear();   hall_number = 0;
        noload_str.clear(); noload_number = 0;

        for(j=0;j<File_id_all.at(i).toInt()+3;j++) // select data from TestDa
        {
            query.prepare(QString("select * from TestDa where id = :id"));
            query.bindValue(":id",File_id.at(i).toInt()+j); // 电机型号
            query.exec();
            while(query.next())
            {
                if(query.value(1).toString().contains("ITEM"))
                {
                    All_data.append(query.value(2).toString()+",");
                    All_data.append(query.value(3).toString()+",");
                    All_data.append(query.value(4).toString()+",");
                }
                else if(query.value(1).toString().contains(tr("-电阻-")))  //电阻不平衡度
                {
                    dlrbal_number++;
                    dlrbal_str.append("DCR-Unbalance,");
                    dlrbal_str.append(query.value(3).toString()+",");
                    dlrbal_str.append(query.value(4).toString()+",");
                }
                else if(query.value(1).toString().contains(tr("电阻")))
                {
                    dlr_number++;
                    dlr_str.append(query.value(1).toString()+" "+query.value(2).toString()+",");
                    dlr_str.append(query.value(3).toString()+",");
                    dlr_str.append(query.value(4).toString()+",");
                }
                else if(query.value(1).toString().contains(tr("反嵌")))    //反嵌
                {
                    mag_number++;
                    mag_str.append(query.value(1).toString()+" "+query.value(2).toString()+",");
                    mag_str.append(query.value(3).toString()+",");
                    mag_str.append(query.value(4).toString()+",");
                }
                else if(query.value(1).toString()==(tr("磁旋")))    //磁旋
                {
                    magr_number++;
                    magr_str.append(query.value(1).toString()+" "+query.value(2).toString()+",");
                    magr_str.append(query.value(3).toString()+",");
                    magr_str.append(query.value(4).toString()+",");
                }
                else if(query.value(1).toString().contains(tr("绝缘")))    //绝缘
                {
                    ir_number++;
                    ir_str.append(query.value(1).toString()+" "+query.value(2).toString()+",");
                    ir_str.append(query.value(3).toString()+",");
                    ir_str.append(query.value(4).toString()+",");
                }
                else if(query.value(1).toString().contains(tr("交耐")))    //交耐
                {
                    acw_number++;
                    acw_str.append(query.value(1).toString()+" "+query.value(2).toString()+",");
                    acw_str.append(query.value(3).toString()+",");
                    acw_str.append(query.value(4).toString()+",");
                }
                else if(query.value(1).toString().contains(tr("匝间")))    //匝间
                {
                    imp_number++;
                    imp_str.append(query.value(1).toString()+" "+query.value(2).toString()+",");
                    imp_str.append(query.value(3).toString()+",");
                    imp_str.append(query.value(4).toString()+",");
                }
                else if(query.value(1).toString().contains(tr("-电感-")))    //电感不平衡度
                {
                    indlba_number++;
                    indlba_str.append("INDL-Unbalance,");
                    indlba_str.append(query.value(3).toString()+",");
                    indlba_str.append(query.value(4).toString()+",");
                }
                else if(query.value(1).toString().contains(tr("电感")))    //电感
                {
                    indl_number++;
                    indl_str.append(query.value(1).toString()+" "+query.value(2).toString()+",");
                    indl_str.append(query.value(3).toString()+",");
                    indl_str.append(query.value(4).toString()+",");
                }
                else if(query.value(1).toString().contains(tr("电参")))    //电参
                {
                    pwr_number++;
                    pwr_str.append(query.value(1).toString()+" "+query.value(2).toString()+",");
                    pwr_str.append(query.value(3).toString()+",");
                    pwr_str.append(query.value(4).toString()+",");
                }
                else if(query.value(1).toString()==(tr("转向")))    //转向
                {
                    turn_number++;
                    turn_str.append(query.value(1).toString()+" "+query.value(2).toString()+",");
                    turn_str.append(query.value(3).toString()+",");
                    turn_str.append(query.value(4).toString()+",");
                }
                else if(query.value(1).toString().contains(tr("堵转")))    //堵转
                {
                    block_number++;
                    block_str.append(query.value(1).toString()+" "+query.value(2).toString()+",");
                    block_str.append(query.value(3).toString()+",");
                    block_str.append(query.value(4).toString()+",");
                }
                else if(query.value(1).toString().contains(tr("低启")))    //低启
                {
                    lvs_number++;
                    lvs_str.append(query.value(1).toString()+" "+query.value(2).toString()+",");
                    lvs_str.append(query.value(3).toString()+",");
                    lvs_str.append(query.value(4).toString()+",");
                }
                else if(query.value(1).toString().contains(tr("PG")))    //pg
                {
                    pg_number++;
                    pg_str.append(query.value(1).toString()+" "+query.value(2).toString()+",");
                    pg_str.append(query.value(3).toString()+",");
                    pg_str.append(query.value(4).toString()+",");
                }
                else if(query.value(1).toString().contains(tr("HALL")))    //HALL
                {
                    hall_number++;
                    hall_str.append(query.value(1).toString()+" "+query.value(2).toString()+",");
                    hall_str.append(query.value(3).toString()+",");
                    hall_str.append(query.value(4).toString()+",");
                }
                else if(query.value(1).toString().contains(tr("空载")))    //空载
                {
                    noload_number++;
                    noload_str.append(query.value(1).toString()+" "+query.value(2).toString()+",");
                    noload_str.append(query.value(3).toString()+",");
                    noload_str.append(query.value(4).toString()+",");
                }
                else {

                }
            }
        }
        Add_data = All_data;
        for(row_field=1; row_field<currentProj.size(); row_field++)
        {
            switch(currentProj.at(row_field).toInt())
            {
            case 1:
                for(x=dlr_number;x<8;x++)
                {
                    dlr_str.append(" ,");  dlr_str.append(" ,");  dlr_str.append(" ,");
                }
                for(x=dlrbal_number;x<1;x++)
                {
                    dlrbal_str.append(" ,");  dlrbal_str.append(" ,");  dlrbal_str.append(" ,");
                }
                Add_data += dlr_str;
                Add_data += dlrbal_str;
                break;
            case 2:
                for(x=mag_number;x<8;x++)
                {
                    mag_str.append(" ,");  mag_str.append(" ,");  mag_str.append(" ,");
                }
                for(x=magr_number;x<1;x++)
                {
                    magr_str.append(" ,");  magr_str.append(" ,");  magr_str.append(" ,");
                }
                Add_data += mag_str;
                Add_data += magr_str;
                break;
            case 3:
                if(ACW_Display==1) // 相间绝缘
                {
                    for(x=ir_number;x<4;x++)
                    {
                        ir_str.append(" ,");  ir_str.append(" ,");  ir_str.append(" ,");
                    }
                }
                else
                {
                    for(x=ir_number;x<1;x++)
                    {
                        ir_str.append(" ,");  ir_str.append(" ,");  ir_str.append(" ,");
                    }
                }
                Add_data += ir_str;
                break;
            case 4:
                if(ACW_Display==1) // 相间耐压
                {
                    for(x=acw_number;x<4;x++)
                    {
                        acw_str.append(" ,");  acw_str.append(" ,");  acw_str.append(" ,");
                    }
                }
                else
                {
                    for(x=acw_number;x<1;x++)
                    {
                        acw_str.append(" ,");  acw_str.append(" ,");  acw_str.append(" ,");
                    }
                }
                Add_data += acw_str;
                break;
            case 5:

                break;
            case 6:
                for(x=imp_number;x<8;x++)
                {
                    imp_str.append(" ,");  imp_str.append(" ,");imp_str.append(" ,");imp_str.append(" ,");imp_str.append(" ,");  imp_str.append(" ,");
                }
                Add_data += imp_str;
                break;
            case 7:
                for(x=pwr_number;x<6;x++)
                {
                    pwr_str.append(" ,");   pwr_str.append(" ,");pwr_str.append(" ,");pwr_str.append(" ,");   pwr_str.append(" ,");
                }
                for(x=turn_number;x<6;x++)
                {
                    turn_str.append(" ,");  turn_str.append(" ,");  turn_str.append(" ,");
                }
                if(Motor_PG_Commmon==QString(tr("PG")))
                {
                    for(x=pg_number;x<3;x++)
                    {
                        pg_str.append(" ,");  pg_str.append(" ,");  pg_str.append(" ,");
                    }
                }


                Add_data += pwr_str;  Add_data += turn_str;
                if(Motor_PG_Commmon==QString(tr("PG")))
                {
                    Add_data += pg_str;
                }
                break;
            case 8:
                for(x=indl_number;x<8;x++)
                {
                    indl_str.append(" ,");  indl_str.append(" ,");indl_str.append(" ,");  indl_str.append(" ,");
                }
                for(x=indlba_number;x<1;x++)
                {
                    indlba_str.append(" ,");  indlba_str.append(" ,");  indlba_str.append(" ,");
                }
                Add_data += indl_str;
                Add_data += indlba_str;
                break;
            case 9:
                for(x=block_number;x<1;x++)
                {
                    block_str.append(" ,");  block_str.append(" ,");block_str.append(" ,");  block_str.append(" ,");
                }
                Add_data += block_str;
                break;
            case 10:
                for(x=lvs_number;x<1;x++)
                {
                    lvs_str.append(" ,");  lvs_str.append(" ,");lvs_str.append(" ,");  lvs_str.append(" ,");
                }
                Add_data += lvs_str;
                break;
            case 11: // ｈａｌｌ
                for(x=hall_number;x<5;x++)
                {
                    hall_str.append(" ,");  hall_str.append(" ,");hall_str.append(" ,");
                }
                Add_data += hall_str;
                break;
            case 12: // 负载

                break;
            case 13: // 空载
                for(x=noload_number;x<1;x++)
                {
                    noload_str.append(" ,");  noload_str.append(" ,");noload_str.append(" ,");
                }
                Add_data += noload_str;
                break;
            case 14: // BEMF

                break;
            default:
                break;
            }
        }

        FileRow.append(Add_data);
        FileRow.append("\n");
        QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB18030"));   //   GB2312
        row_record++;
        if(row_record==600)
        {
            row_record=0;
            row_add++;
            csvFile.write(FileRow.toAscii());  //  csvFile.close();
            system("sync");

            Singal_Data_Scale(QStringList(""),row_add*600*100/File_id_count,1);
            FileRow.clear();
            QTimer::singleShot(200, &eventloop, SLOT(quit()));
        }
        QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    }
    qDebug()<<"system sync finsh";

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB18030"));   //   GB2312  GB18030
    csvFile.write(FileRow.toAscii());
    system("sync");
    QTimer::singleShot(5666, &eventloop, SLOT(quit()));
    eventloop.exec();
    system("sync");
    csvFile.close();
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    qDebug()<<tr("结束");
    Singal_Data_Scale(QStringList(""),3,3);
}


