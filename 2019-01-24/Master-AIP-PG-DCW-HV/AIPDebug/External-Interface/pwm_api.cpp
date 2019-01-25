/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <QDebug>
#include "pwm_api.h"
#include "em335x_drivers.h"

#define POLARITY            PWM_POLARITY_INVERTED;
// #define POLARITY          PWM_POLARITY_NORMAL;

#ifdef  __cplusplus
extern "C" {
#endif

static int      count, Led_count;
int             Beep_fd, Led_fd;
char            device[32];
unsigned int    freq = 20000;
unsigned int    duty = 80;

int Beep_PWM_Start(double duty) {
    qDebug() << "Beep_PWM_Start";
    int                     rc;
    struct pwm_config_info  conf;
    count++;

    if (count == 1) {
        sprintf(device, "/dev/em335x_pwm%d", 2);
        Beep_fd = open(device, O_RDWR);
        if (Beep_fd < 0) {
            printf("can not open /dev/em335x_pwm%d device file!\n", 2);
            qDebug() << "Beep_PWM_Start:: error";
        }
    } else {
        //
    }

    // conf.cmd = EM335X_PWM_START;
    conf.freq = 2000;
    conf.duty = duty;
    conf.polarity = POLARITY;
    conf.count = 0;

    rc = write(Beep_fd, &conf, sizeof(struct pwm_config_info));
    return rc;
}
int Beep_PWM_Stop() {
    int                     rc;
    struct pwm_config_info  conf;
    count++;

    if (count == 1) {
        sprintf(device, "/dev/em335x_pwm%d", 2);
        Beep_fd = open(device, O_RDWR);
    } else {
        //
    }

    memset( &conf, 0, sizeof(struct pwm_config_info));
    //    conf.cmd = EM335X_PWM_STOP;

    rc = write(Beep_fd, &conf, sizeof(struct pwm_config_info));
    return rc;
}

int pwm_table[10] = {1, 2, 3, 5, 8, 9, 10, 20, 30, 100};
int Led_PWM_Start(int duty) {
    int                     rc;
    struct pwm_config_info  conf;
    Led_count++;
    if (Led_count == 1) {
        sprintf(device, "/dev/em335x_pwm%d", 1);
        Led_fd = open(device, O_RDWR);
        if (Led_fd < 0) {
            printf("can not open /dev/em335x_pwm%d device file!\n", 1);
        }
    }
    qDebug() << "Led_PWM_Start" << freq;
    // conf.cmd = EM335X_PWM_START;
    conf.freq = freq;
    conf.duty = pwm_table[duty];
    conf.polarity = PWM_POLARITY_NORMAL;
    conf.count = 0;

    rc = write(Led_fd, &conf, sizeof(struct pwm_config_info));
    return rc;
}
int Led_PWM_Stop() {
    int                     rc;
    struct pwm_config_info  conf;
    Led_count++;
    if (Led_count == 1) {
        sprintf(device, "/dev/em335x_pwm%d", 1);
        Led_fd = open(device, O_RDWR);
    }

    memset( &conf, 0, sizeof(struct pwm_config_info));
    //    conf.cmd = EM335X_PWM_STOP;

    rc = write(Led_fd, &conf, sizeof(struct pwm_config_info));
    return rc;
}

#ifdef   __cplusplus
}
#endif

