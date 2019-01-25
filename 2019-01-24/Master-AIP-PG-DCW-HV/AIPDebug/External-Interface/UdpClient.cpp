/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "UdpClient.h"

UdpClient::UdpClient(QObject *parent) : QUdpSocket(parent)
{
    Status = "free";
    Number = "----";
    Reply_conut = 0;
    Ini_Vacuum_Model = 0;
}

void UdpClient::Init()
{
    this->bind(6000); // QHostAddress::Broadcast,
    connect(this,  SIGNAL(readyRead()),  this,  SLOT(ReadAll()));
    QSettings *QSettings_Vacuum_Model = new QSettings(Sys_path, QSettings::IniFormat);
    QSettings_Vacuum_Model->setIniCodec("GB18030");
    Ini_Vacuum_Model = QSettings_Vacuum_Model->value("System/Vacuum_Model", "0").toInt(); // -设置真空测试
    delete QSettings_Vacuum_Model;
}

void UdpClient::Quit()
{
    this->close();
}

void UdpClient::InitSettings()
{
    qDebug() << "UdpClient::InitSettings()" << QTime::currentTime().toString() ;

    QSettings *set_Test_File = new QSettings(Sys_path,   QSettings::IniFormat);
    set_Test_File->setIniCodec("GB18030");
    Number = set_Test_File->value("Factory/text",  "V-0.0.0").toString();
    Ini_Vacuum_Model = set_Test_File->value("System/Vacuum_Model", "0").toInt(); // -设置真空测试
    QSettings File_Types(Test_File_path,   QSettings::IniFormat);
    File_Types.setIniCodec("UTF-8");
    QStringList Type_list = File_Types.value("DateFile/currentfile").toStringList();
    Types = Type_list.join(" ");
}

void UdpClient::SaveSettings() {
    //
}

void UdpClient::ReadAll()
{
    while (this->hasPendingDatagrams()) {
        QByteArray msg;
        msg.resize(this->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;
        this->readDatagram(msg.data(),  msg.size(),  &sender,  &senderPort);

        QStringList n = QString(msg).split(" ");
        quint16 Command;
        Command = quint16(n.at(0).toInt());
        n.removeFirst();
        QByteArray Param;
        Param = n.join(" ").toUtf8();
        sender_Record = sender;

        if (Command != 6030) {
            qDebug() << "UdpClient::" << Command;
        }
        if (msg.contains("!T")){
            Get_Net_Temp = QString(QString(msg).remove(("!T")));
            SendCommand(6000,  CMD_Put_GetTemp,  Get_Net_Temp.toUtf8());
        } else {
            //
        }

        switch (Command) {
        case 1666:
            emit SendCommand(6000,  CMD_In_ICO,  QString("").toUtf8());
            break;
        case 3000: // 查询在线主机 ---成功---
            InitSettings();
            TxMsg = "3001 ";
            TxMsg.append(Number);
            this->writeDatagram(TxMsg.toUtf8(), sender, 6000);
            break;
        case 3002: // 修改主机编号
            //
            break;
        case 3004: // 获取测试型号 ---成功---
            InitSettings();
            TxMsg = "3005 ";
            TxMsg.append(Types);
            this->writeDatagram(TxMsg.toUtf8(), sender, 6000);
            break;
        case 3006: // 设置测试型号 ---成功---
            if (!Param.isEmpty())
                emit SendCommand(6000, CMD_In_Param, Param);
            break;
        case 3008: // 启动左工位测试  ---成功---
            emit SendCommand(6000, CMD_In_START, QString("%1 %2").arg(0x13).arg(0x03).toUtf8());
            TxMsg = "3009 ";
            TxMsg.append(Number);
            this->writeDatagram(TxMsg.toUtf8(),  sender,  senderPort);
            break;
        case 3010: // 停止测试  ---成功---
            emit SendCommand(6000,  CMD_In_STOP,  QString("%1 %2").arg(0x13).arg(0x03).toUtf8());
            TxMsg = "3011 ";
            TxMsg.append(Number);
            this->writeDatagram(TxMsg.toUtf8(),  sender,  senderPort);
            break;
        case 3012: // 获取状态  ---成功---
            emit SendCommand(6000,  CMD_In_STATUS_Ing,  QString("").toUtf8());
            break;
     /* case 3014:
            TxMsg = "3015 ";
            TxMsg.append(Items.join("\n"));
            this->writeDatagram(TxMsg.toUtf8(),  sender,  senderPort);
            break;  */
        case 2000:
            Reply_conut = 0;
            break;
        case 6000:
            SendCommand(6000, CMD_In_Connect, QString("").toUtf8());
            break;
        case 6002:
            SendCommand(6000, CMD_In_Init_Data, msg);
            break;
        case 6004: // 解析接收数据
            Analy_XML_Data(n);
            break;
        case 6006: // 解析启动单项测试
            emit SendCommand(6000, CMD_In_Start_Item, msg);
            break;
        case 6008: // 跳转测试界面
            emit SendCommand(6000, CMD_In_Judge, QString("").toUtf8());
            break;
        case 6010: //-添加型号
            emit SendCommand(6000, CMD_In_Add_Model, msg);
            break;
        case 6012: //-删除型号
            emit SendCommand(6000, CMD_In_Del_Model, msg);
            break;
        case 6016: // 获取测试型号
            emit SendCommand(6000, CMD_In_Oder_Model, QString("").toUtf8());
            break;
        case 6018: // 设置测试型号
            emit SendCommand(6000, CMD_Put_Updae_Model, msg);
            break;
        case 6020: // 下发真空启动信号
            emit SendCommand(6000, CMD_Put_All_Start, msg);
            break;
        case 6022: // 发送停止信号
            emit SendCommand(6000, CMD_Put_All_Stop, msg);
            break;
        case 6026: // 测试超时
            emit SendCommand(6000, CMD_Put_Time, msg);
            break;
        case 6030: // 发送心跳包
            this->writeDatagram("0x31", sender_Record, 6000);
            break;
        case 6036: // 设置二代IO板输出状态
            emit SendCommand(6000, CMD_In_IO_Put, msg);
            break;
        case 6038: // 反嵌采集
            emit SendCommand(6000, CMD_In_MAG_Sample, msg);
            break;
        case 6041: // 匝间采样
            emit SendCommand(6000, CMD_In_IMP_Sample, msg);
            break;
        case 6046: // 匝间采样完成
            emit SendCommand(6000, CMD_In_IMP_Finsh, msg);
            break;
        case 6050:
            emit SendCommand(6000, CMD_In_IMP_Ready, msg);
            break;
        case 6052: // 开启真空模式
            emit SendCommand(6000, CMD_In_Vacuum_IMP, msg);
            break;
        case 6056: // 匝间拉伸压缩
            emit SendCommand(6000, CMD_In_IMP_PL, msg);
            break;
        case 6058: // 启动停止二代板IO板状态上传
            emit SendCommand(6000, CMD_In_PIC, msg);
            break;
        case 6066: // 常规启动信号
            emit SendCommand(6000, CMD_In_9a, msg);
            break;
        case 6067: // 自动启动信号
            emit SendCommand(6000, CMD_In_Start_Auto, msg);
            break;
        case 6068: // 耐压真空模式
            emit SendCommand(6000, CMD_In_Vacuum_ACW, msg);
            break;
        case 6070: // 发送禁止启动信号一次
            emit SendCommand(6000, CMD_In_Start_No, msg);
            break;
        case 6071: // 发送报警时间
            emit SendCommand(6000, CMD_IN_Beep, msg);
            break;
        case 6072: // 发送内置驱动变频器继电器切换
            emit SendCommand(6000, CMD_In_A2, msg);
            break;
        case 6073: // 发送外置驱动变频器继电器切换
            emit SendCommand(6000, CMD_In_A3, msg);
            break;
        case 6074: // 发送控制变频器电源
            emit SendCommand(6000, CMD_In_A4, msg);
            break;
        case 6077: // PC发送二代IO板输出状态,控石IO输出专用
            emit SendCommand(6000, CMD_In_A7, msg);
            break;
        case 6080: // 总合格/不合格信号
            emit SendCommand(6000, CMD_In_A8, msg);
            break;
        case 6083: // WD控制继电器
            emit SendCommand(6000, CMD_In_AA, msg);
            break;
        case 6084: // PC发送匝间定档采样 左/右 非真空/真空
            emit SendCommand(6000, CMD_In_A6, msg);
            break;
        case 6078: // 下发自动启动(老化实验室使用)
            emit SendCommand(6000, CMD_In_Test_Auto, msg);
            break;
        case 6081: // 清除状态(美芝状态使用)
            emit SendCommand(6000,  CMD_In_MEIZHI,  msg);
            break;
        case 6091:
            emit SendCommand(6000,  CMD_In_GetOut,  msg);
            break;
        case 6093:
            emit SendCommand(6000,  CMD_In_Two_ACW,  msg);
            break;
        case 6094:
            emit SendCommand(6000,  CMD_In_No_Start, msg);
            break;
        case 6096:
            emit SendCommand(6000,  CMD_In_Delay, msg);
            break;
        default:
         // this->writeDatagram("Error command",  sender_Record,  6000);
         // qDebug() << "UdpClient::msg" << msg;
            break;
        }
    }
}

void UdpClient::Analy_XML_Data(QStringList data)
{
     qDebug() << data;
    if (data.at(0) == QString(tr("Conf"))) {
        SendCommand(6000, CMD_In_CONF_Data, QString("1").toUtf8());
    } else if (data.at(0) == QString(tr("Sys"))) {
        SendCommand(6000, CMD_In_CONF_Data, QString("2").toUtf8());
    } else if (data.at(0) == QString(tr("DCR"))) {
        SendCommand(6000, CMD_In_CONF_Data, QString("3").toUtf8());
    } else if (data.at(0) == QString(tr("MAG"))) {
        SendCommand(6000, CMD_In_CONF_Data, QString("15").toUtf8());
    } else if (data.at(0) == QString(tr("DCW"))) {
        SendCommand(6000, CMD_In_CONF_Data, QString("16").toUtf8());
    } else if (data.at(0) == QString(tr("IR"))) {
        SendCommand(6000, CMD_In_CONF_Data, QString("4").toUtf8());
    } else if (data.at(0) == QString(tr("ACW"))) {
        SendCommand(6000, CMD_In_CONF_Data, QString("5").toUtf8());
    } else if (data.at(0) == QString(tr("IMP"))) {
        SendCommand(6000, CMD_In_CONF_Data, QString("6").toUtf8());
    } else if (data.at(0) == QString(tr("IND"))) {
        SendCommand(6000, CMD_In_CONF_Data, QString("7").toUtf8());
    } else if (data.at(0) == QString(tr("HALL"))) {
        SendCommand(6000, CMD_In_CONF_Data, QString("11").toUtf8());
    } else if (data.at(0) == QString(tr("LOAD"))) {
        SendCommand(6000, CMD_In_CONF_Data, QString("12").toUtf8());
    } else if (data.at(0) == QString(tr("NOLOAD"))) {
        SendCommand(6000, CMD_In_CONF_Data, QString("13").toUtf8());
    } else if (data.at(0) == QString(tr("PWR"))) {
        SendCommand(6000, CMD_In_CONF_Data, QString("8").toUtf8());
    } else if (data.at(0) == QString(tr("BEMF"))) {
        SendCommand(6000, CMD_In_CONF_Data, QString("14").toUtf8());
    } else {
        qDebug() << "UdpClient::Error data--Analy_XML_Data" << data;
    }
}

void UdpClient::ReadMessage_NoVacuum(quint16 addr,   quint16 cmd,   QByteArray msg)
{
    if (addr != 6000)
        return;
    switch (cmd) {
    case CMD_Put_ITEM:
        Items.append(msg);
        break;
    case CMD_Put_STATUS_Cheak:
        Status = msg;
        if (Status  ==  "free") {
            this->writeDatagram(Items.join("\n").toUtf8(), sender_Record, 6000);
            // G2018010134 189901119G QHostAddress::Broadcast
            Items.clear();
        } else {
            //
        }
        break;
    case CMD_Put_STATUS_Ing:
        Status = msg;
        TxMsg = "3013 "; TxMsg.append(Status);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
    case CMD_In_GetTemp:
        TxMsg.clear();
        TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        // G2018010134 189901119G QHostAddress::Broadcast
        break;
    default:
        // -
        break;
    }
}
void UdpClient::ReadMessage(quint16 addr,   quint16 cmd,   QByteArray msg)
{
    if (addr != 6000)
        return;
    if (Ini_Vacuum_Model) {
        //
    } else {
        return;
    }
    switch (cmd) {
    case CMD_Put_STATUS_Ing:
        Status = msg;
        TxMsg = "3013 "; TxMsg.append(Status);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
//    case CMD_Param:
//        TxMsg = "3007 ";
//        TxMsg.append(msg);
//        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
//        break;
    case CMD_Put_Login:
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
    case CMD_Put_Reply:
        Reply_conut++;
        TxMsg = "2000 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        if (Reply_conut > 30) { // >30s
            qDebug() << "UdpClient::Realy Fail";
        } else {
            //
        }
        break;
    case CMD_Put_Message: // 自检信息,错误警告编码,
        TxMsg = "6001 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
    case CMD_Test_Message: // 错误文本信息
        TxMsg = "6003 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
    case CMD_Put_CONF_Data: // 上传配置
        TxMsg = "6005 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
    case CMD_Put_Start_Item: // 单项测试完成
        TxMsg = "6007 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
    case CMD_Put_Oder_Model: // 上传测试型号
        TxMsg = "6017 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
   /* case CMD_ad: // 空载启动完成
        TxMsg = "6015 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break; */
    case CMD_Put_73: // 反电动势参数/空载参数
        TxMsg = "6019 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
    case CMD_Put_75: // 上传波形
        TxMsg = "6021 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
    case CMD_Put_76: // 上传温度
        TxMsg = "6032 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
    /*case CMD_77: // 空载测试完成
        TxMsg = "6033 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;*/
    case CMD_Put_IO_IN: // 上传IO板的状态
        TxMsg = "6037 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
    case CMD_Put_81:
        TxMsg = "6039 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
    case CMD_Put_82:
        TxMsg = "6040 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
    case CMD_Put_85:
        TxMsg = "6042 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
    case CMD_Put_86:
        TxMsg = "6043 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
    case CMD_Put_87:
        TxMsg = "6035 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
    case CMD_Put_V_State:
        TxMsg = "6053 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
    case CMD_Put_92:
        TxMsg = "6055 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
    case CMD_Put_96:
        TxMsg = "6059 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
    case CMD_Put_97:
        TxMsg = "6060 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
    case CMD_Put_98:
        TxMsg = "6061 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
    case CMD_Put_Close_Pumb:
        TxMsg = "6062 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
//    case CMD_Curtain:
//        TxMsg = "6063 "; TxMsg.append(msg);
//        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
//        break;
//    case CMD_Action:
//        TxMsg = "6064 "; TxMsg.append(msg);
//        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
//        break;
    case CMD_Put_MEIZHI:
        TxMsg = "6082 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
    case CMD_In_B0:
        TxMsg = "6083 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
    case CMD_Put_B1:
        TxMsg = "6085 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
    case CMD_Put_ROT:
        TxMsg = "6086 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
    case CMD_Put_PWR:
        TxMsg = "6089 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
    case CMD_Put_NoStart:
        TxMsg = "6095 "; TxMsg.append("");
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
    case CMD_Reset_Again:
        TxMsg = "6097 "; TxMsg.append(msg);
        this->writeDatagram(TxMsg.toUtf8(), sender_Record, 6000);
        break;
        break;
    default:
        //
        break;
    }
}






