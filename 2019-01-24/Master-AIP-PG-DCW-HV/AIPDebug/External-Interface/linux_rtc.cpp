/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "linux_rtc.h"

static int rtc_fd;
LINUX_RTC::LINUX_RTC() {
    // -
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.10
  * brief:      设置系统时间
******************************************************************************/
int LINUX_RTC::set_rtc(rtc_time rtc_tm)
{
    qDebug() << "set_rtc";
    int            ret;
    rtc_tm.tm_year -= 1900;                     // 年从1900开始
    rtc_tm.tm_mon -= 1;                         // 月从0开始
    if (rtc_fd == -1) {
        printf("/dev/rtc0 open error2\n");
        return -1;
    }

    ret = ioctl(rtc_fd, RTC_SET_TIME, &rtc_tm); // 设置RTC时间
    if (ret == -1) {
        printf("rtc ioctl RTC_SET_TIME error\r\n");
        return -1;
    }
    return 0;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.10
  * brief:      获取系统时间
******************************************************************************/
rtc_time LINUX_RTC::get_rtc()
{
    int                 ret;
    struct rtc_time     rtc_tm;
    time_t              t1;
    static  int         set_time = 0;
    set_time++;
    if (set_time == 1) {
        rtc_fd = open("/dev/rtc0", O_RDWR, 0);      // 打开RTC

        if (rtc_fd == -1) {
            printf("/dev/rtc0 open error1\n");
        }
        ret = ioctl(rtc_fd, RTC_RD_TIME, &rtc_tm);  // 读取时间
        if (ret < 0) {
            printf("RTC_RD_TIME failed %d", ret);
        }
        t1 = timelocal((tm*)&rtc_tm);             // 设置系统时间
        stime(&t1);

        rtc_tm.tm_year += 1900;                     // 年从1900开始
        rtc_tm.tm_mon += 1;                         // 月从１开始

    } else {
        ioctl(rtc_fd, RTC_RD_TIME, &rtc_tm);
        rtc_tm.tm_year += 1900;                     // 年从1900开始
        rtc_tm.tm_mon += 1;                         // 月从１开始
    }
    return rtc_tm;
}

/******************************************************************************
                                    END
******************************************************************************/
