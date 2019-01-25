/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "linux_can.h"

// bool Global_Variable::Testing_Flag=0;
// int  Global_Variable::Testing_Win=0;
LINUX_CAN::LINUX_CAN()
{
    s = 0;
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.12
  * brief:      打开CAN，设置波特率
******************************************************************************/
int LINUX_CAN::canOpen(int bitrate)
{
    char str[256];

    struct can_filter rfilter[21];      //  rfilter 记录总数
    // #define CAN_SFF_MASK 0x000007FFU
    rfilter[0].can_id = 0x41;           // 电阻板ID
    rfilter[0].can_mask = CAN_SFF_MASK;
    rfilter[1].can_id = 0x441;          // 反嵌板波形ID
    rfilter[1].can_mask = CAN_SFF_MASK;
    rfilter[2].can_id = 0x61;           // 绝缘板ID
    rfilter[2].can_mask = CAN_SFF_MASK;
    rfilter[3].can_id = 0x261;          // 输出板ID  13
    rfilter[3].can_mask = CAN_SFF_MASK;
    rfilter[4].can_id = 0x81;           // 匝间板ID
    rfilter[4].can_mask = CAN_SFF_MASK;
    rfilter[5].can_id = 0x481;          // 匝间板波形ID
    rfilter[5].can_mask = CAN_SFF_MASK;

    rfilter[6].can_id = 0x281;          // 输出板ID  14
    rfilter[6].can_mask = CAN_SFF_MASK;
    rfilter[7].can_id = 0x2A1;          // 输出板ID  15
    rfilter[7].can_mask = CAN_SFF_MASK;
    rfilter[8].can_id = 0x2C1;          // 输出板ID  16
    rfilter[8].can_mask = CAN_SFF_MASK;
    rfilter[9].can_id = 0x2E1;          // 输出板ID  17
    rfilter[9].can_mask = CAN_SFF_MASK;

    rfilter[10].can_id = 0xC1;           // 电感板ID
    rfilter[10].can_mask = CAN_SFF_MASK;

    rfilter[11].can_id = 0xE1;           // 电参板ID 1   27
    rfilter[11].can_mask = CAN_SFF_MASK;

    rfilter[12].can_id = 0x101;          // 电参板ID 2   28
    rfilter[12].can_mask = CAN_SFF_MASK;

    rfilter[13].can_id = 0x521;          // 电参板 PG波形
    rfilter[13].can_mask = CAN_SFF_MASK;

    rfilter[14].can_id = 0x141;           // 绝缘板ID
    rfilter[14].can_mask = CAN_SFF_MASK;

    rfilter[15].can_id = 0x121;           // 电源切换板ID
    rfilter[15].can_mask = CAN_SFF_MASK;

    rfilter[16].can_id = 0x161;           // BLDC-WD板ID
    rfilter[16].can_mask = CAN_SFF_MASK;

    rfilter[17].can_id = 0x181;           // BLDC-PG板ID
    rfilter[17].can_mask = CAN_SFF_MASK;

    rfilter[18].can_id = 0x581;           // BLDC-PG板波形ID
    rfilter[18].can_mask = CAN_SFF_MASK;

    rfilter[19].can_id = 0x1A1;           // IO板ID
    rfilter[19].can_mask = CAN_SFF_MASK;

    rfilter[20].can_id = 0xA1;           // IO板ID
    rfilter[20].can_mask = CAN_SFF_MASK;

    s = socket(PF_CAN, SOCK_RAW, CAN_RAW);  //打开套接字
    if (s < 0) {
        // printf("Error while opening socket");
        return 0;
    }

    sprintf(str, "ip link set can0 type can bitrate %d restart-ms 100", bitrate);
    system("ifconfig can0 down");
    system(str);
    system("ifconfig can0 up");

    //  int loopback = 1;
    //  setsockopt(s, SOL_CAN_RAW, CAN_RAW_LOOPBACK, &loopback, sizeof(loopback));

    strcpy(ifr.ifr_name, "can0");
    if (ioctl(s, SIOCGIFINDEX, &ifr) < 0) {
        //  printf("Error while opening can0");
        return 0;
    }

    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        //  printf("Error in socket bind");
        return 0;
    }

    setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter, sizeof(rfilter)); // 设置规则
    return s;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.12
  * brief:      初始化CAN，设置波特率
******************************************************************************/
int LINUX_CAN::canClose()
{
    if (s > 0) {
        close(s);
    }
    return 0;
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.12
  * brief:      CAN发送一帧
******************************************************************************/
bool LINUX_CAN::canSend(can_frame frame)
{
    int nbytes;
    int ret;
    fd_set rdfds;
    struct timeval tv;

    if (s <= 0) {
        return false;
    }

    FD_ZERO(&rdfds);
    FD_SET(s, &rdfds);
    tv.tv_sec  = 0;                                         // 0秒
    tv.tv_usec = 0;                                         // 0微秒
    ret = select(s + 1, NULL, &rdfds, NULL, &tv);            // 监听是否可写
    if (ret < 0) {
        // printf("select failed 1 ");
        return false;
    } else if (ret == 0) {
        // printf("time out");
        return false;
    } else {
        if (FD_ISSET(s, &rdfds)) {
            nbytes = write(s, &frame, sizeof(struct can_frame));
            if (nbytes != sizeof(struct can_frame)) {
                perror("can raw socket write error");
                return false;
            }
        }
    }
    return true;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.12
  * brief:      读取CAN
******************************************************************************/
bool LINUX_CAN::canRecv()
{
    int nbytes;
    int ret;
    fd_set rdfds;
    struct timeval tv;

    if (s <= 0) {
        return false;
    }

    FD_ZERO(&rdfds);
    FD_SET(s, &rdfds);
    tv.tv_sec  = 0;                                         // 0秒
    tv.tv_usec = 0;                                         // 0微秒
    ret = select(s + 1, &rdfds, NULL, NULL, &tv);            // 监听是否可读
    if (ret < 0) {
        // printf("select failed 2 ");
        return false;
    } else if (ret == 0) {
        // printf( "time out\n" );
        return false;
    } else {
        if (FD_ISSET(s, &rdfds)) {
            nbytes = read(s, &frame,  sizeof(struct can_frame)); // 读取缓冲区
            return true;
        }
    }
    return true;
}
/*
void  LINUX_CAN::RES_Check()
{
    frame.can_id = 0x22;
    frame.can_dlc = 0x01;
    frame.data[0] = 0x00;
    canSend(frame);
}  */

/******************************************************************************
                                    END
******************************************************************************/
