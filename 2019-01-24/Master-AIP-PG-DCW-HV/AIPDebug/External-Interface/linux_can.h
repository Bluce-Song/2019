/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     2.0
 * author:      SL
 * date:        2015.12.10
 * brief:       主界面
*******************************************************************************/
#ifndef LINUX_CAN_H
#define LINUX_CAN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <linux/can/error.h>
#include <linux/netlink.h>
#include <errno.h>
#include <QDebug>
#include <unistd.h>
#include <netinet/in.h>
#include <net/if.h>
#include <fcntl.h>
#include <sys/un.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>

#include "string.h"



class LINUX_CAN {
public:
    LINUX_CAN();

public:
    int                     s;
    struct sockaddr_can     addr;
    struct ifreq            ifr;
    can_frame               frame;

    int  canOpen(int bitrate);
    int  canClose();
    bool canSend(can_frame frame);
    bool canRecv();
};


#endif // LINUX_CAN_H
