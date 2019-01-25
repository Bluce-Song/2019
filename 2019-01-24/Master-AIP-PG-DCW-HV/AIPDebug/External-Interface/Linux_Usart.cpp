/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
// Serial.cpp: implementation of the CSerial class.
//
//////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/un.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <pthread.h>
#include <termios.h>
#include <QIODevice>

#include "Linux_Usart.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

typedef struct port_info {
    int baud_rate;
    int port_fd;
    char parity;
    char stop_bit;
    char flow_ctrl;
    char data_bits;
}*pport_info;
// get the baud_rate defination according to the baud rate
int get_baud_rate(u_int64_t baud_rate) {
    switch (baud_rate) {
        case 0:
            return B0;
        case 50:
            return B50;
        case 75:
            return B75;
        case 110:
            return B110;
        case 134:
            return B134;
        case 150:
            return B150;
        case 200:
            return B200;
        case 300:
            return B300;
        case 600:
            return B600;
        case 1200:
            return B1200;
        case 1800:
            return B1800;
        case 2400:
            return B2400;
        case 4800:
            return B4800;
        case 9600:
            return B9600;
        case 19200:
            return B19200;
        case 38400:
            return B38400;
        case 57600:
            return B57600;
        case 115200:
            return B115200;
        case 230400:
            return B230400;

        default:
            return -1;
    }
}

int set_port(pport_info p_info) {
    struct termios new_opt;
    int baud_rate;
    int status;

    tcgetattr(p_info->port_fd, &new_opt);
    bzero(&new_opt, sizeof(new_opt));

    baud_rate = get_baud_rate(p_info->baud_rate);

    tcflush(p_info->port_fd, TCIOFLUSH);
    cfsetispeed(&new_opt, baud_rate);
    cfsetospeed(&new_opt, baud_rate);
    status = tcsetattr(p_info->port_fd, TCSANOW, &new_opt);
    if (status != 0) {
        perror("tcsetattr::set baud rate failed\n");
        return -1;
    }

    new_opt.c_cflag |= CLOCAL;
    new_opt.c_cflag |= CREAD;
    new_opt.c_cflag |= HUPCL;
    switch (p_info->flow_ctrl) {
    case '0':
        new_opt.c_cflag &=~CRTSCTS;
        break;
    case '1':
        new_opt.c_cflag |=CRTSCTS;
        break;
    case '2':
        new_opt.c_iflag |= IXON | IXOFF | IXANY;
        break;
    }
    // printf("c_cflag(no ctl-flow) = %x\r\n", new_opt.c_cflag);

    // setup bit size
    new_opt.c_cflag &= ~CSIZE;
    switch (p_info->data_bits) {
    case '5':
        new_opt.c_cflag |=CS5;
        break;
    case '6':
        new_opt.c_cflag |=CS6;
        break;
    case '7':
        new_opt.c_cflag |=CS7;
        break;
    case '8':
        new_opt.c_cflag |=CS8;
        break;
    default:
        new_opt.c_cflag |=CS8;
    }
    printf("c_cflag |= CS8 => %x\r\n", new_opt.c_cflag);

    // setup parity
    switch (p_info->parity) {
    case 'n':
    case 'N':
        new_opt.c_cflag &= ~PARENB; /* Clear parity enable */
        new_opt.c_iflag &= ~INPCK;  /* Enable parity checking */
        break;

    case 'o':
    case 'O':
        new_opt.c_cflag |= (PARODD | PARENB); /* ÉèÖÃÎªÆæÐ§Ñé*/
        new_opt.c_iflag |= INPCK;             /* Disable parity checking */
        break;

    case 'e':
    case 'E':
        new_opt.c_cflag |= PARENB;   /* Enable parity */
        new_opt.c_cflag &= ~PARODD;  /* ×ª»»ÎªÅŒÐ§Ñé*/
        new_opt.c_iflag |= INPCK;    /* Disable parity checking */
        break;

    case 'S':
    case 's':  /*as no parity*/
        new_opt.c_cflag &= ~PARENB;
        new_opt.c_cflag &= ~CSTOPB;
        break;

    default:
        fprintf(stderr, "Unsupported parity\n");
        return -1;
    }
    // printf("c_cflag &=~PARENB => %x\r\n", new_opt.c_cflag);


    // setup stop-bit
    if (p_info->stop_bit == '2') {
        new_opt.c_cflag |= CSTOPB;
    } else {
        new_opt.c_cflag &= ~CSTOPB;
    }

    if ((p_info->parity != 'n') || \
            (p_info->parity != 'N')) {
        new_opt.c_iflag |= INPCK;
    }

    new_opt.c_lflag &= ~(ICANON | ECHO | ISIG); /*Input*/
    new_opt.c_oflag &= ~OPOST; /*Output*/

    new_opt.c_cc[VMIN] = 1;
    new_opt.c_cc[VTIME] = 1;

    tcflush(p_info->port_fd, TCIFLUSH);

    status = tcsetattr(p_info->port_fd, TCSANOW, &new_opt);
    if (status != 0) {
        perror("Cannot set the serial port parameters");
        return -1;
    }

    return status;
}

CSerial::CSerial() {
    m_DatLen = 0;
    m_ExitThreadFlag = 0;
}

CSerial::~CSerial() {
    //
}
    //  extern QBuffer buffer(&w->byteArray);
int CSerial::ReceiveThreadFunc(void* lparam)
{
    CSerial *pSer = (CSerial*)lparam;
    fd_set fdRead;
    int ret;
    struct timeval aTime;

    while (1) {
        if (pSer->m_ExitThreadFlag) {
            break;
        }
        usleep(1000);
        FD_ZERO(&fdRead);
        FD_SET(pSer->m_fd, &fdRead);

        aTime.tv_sec = 0;
        aTime.tv_usec = 0;

        ret = select(pSer->m_fd + 1, &fdRead, NULL, NULL, &aTime);
        // printf("select ret = %d\n", ret);

        if (ret < 0) {
            pSer->ClosePort();
            break;
        }

        if (ret > 0) {
            if (FD_ISSET(pSer->m_fd, &fdRead)) {
                pSer->m_DatLen = read(pSer->m_fd, pSer->DatBuf, 100);
                if (pSer->m_DatLen > 0) {
                    pSer->DatBuf[pSer->m_DatLen] = 0;
                    pSer->PackagePro(pSer->DatBuf, pSer->m_DatLen);

                    emit pSer->readyRead(pSer->DatBuf);
                }
            }
            // pthread_mutex_unlock(&pSer->mutex);
        }
    }

    printf("ReceiveThreadFunc finished\n");
    pthread_exit(NULL);
    return 0;
}

int CSerial::OpenPort(char *PortNo, int baudrate, char databits, char stopbits, char parity)
{
    char portname[20];
    struct port_info info;
    pthread_attr_t attr;
    int res;

    sprintf(portname, "/dev/%s", PortNo);
    if ((m_fd = open(portname, O_RDWR | O_NOCTTY | O_NONBLOCK)) == -1) {
        // O_RDWR | O_NOCTTY | O_NDELAY |
        perror("Cannot open the desired port");
        return -1;
    }
    //
    // Fill in the device control block.
    //
    // ÐÞžÄÏà¹Ø²ÎÊý
    info.baud_rate = baudrate;
    info.parity = parity;
    info.data_bits = databits;
    info.flow_ctrl = '0';
    info.port_fd = m_fd;
    info.stop_bit = stopbits;

    printf("port:%s baudrate:%d\n", portname, baudrate);

    if (set_port(&info) == -1) {
        printf("set port fail\n");
        return -1;
    }


    res = pthread_attr_init(&attr);
    if (res != 0) {
        printf("Create attribute failed\n");
    }
    res = pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM); // PTHREAD_SCOPE_SYSTEM
    res += pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if (res != 0) {
        printf("Setting attribute failed\n");
    }

    res = pthread_create(&m_thread, &attr, \
                         (void *(*) (void *))&ReceiveThreadFunc, (void*)this);
    if (res != 0) {
        close(m_fd);
        return -1;
    }
    pthread_attr_destroy(&attr);
    return 0;
}

int CSerial::WritePort(char *Buf, int len)
{
    int sendlen = 0;
    sendlen = write(m_fd, Buf, len);
    if (sendlen == len) {
        return sendlen;
    } else {
        tcflush(m_fd, TCOFLUSH);
        return -1;
    }
}

int CSerial::PackagePro(char* Buf, int len)
{
    int i1;
    len = 0;
    return Buf[i1];
}

int CSerial::ClosePort() {
    m_ExitThreadFlag = 1;
    close(m_fd);
    return 0;
}

