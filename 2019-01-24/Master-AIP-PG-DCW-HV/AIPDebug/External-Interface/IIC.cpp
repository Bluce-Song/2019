#include <stdio.h>
#include <linux/types.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <assert.h>
#include <string.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <linux/rtc.h>
#include <QDebug>
#include "IIC.h"
#include "em335x_drivers.h"

int  Gpio_fd;

int I2COpen() {
    unsigned char i;
    unsigned char InitTime[] = {
    0x00, 0x01, 0x09, 0x01, 0x09, 0x02, 0x11
    }; // 秒　分　时　日　月　（周）　年
    Gpio_fd = open( "/dev/em335x_gpio", O_RDWR);
    GPIO_OutEnable(GPIO23);
    GPIO_OutEnable(GPIO27);
    GPIO_OutEnable(GPIO26);

    GPIO_OutClear(GPIO23); // CE
    GPIO_OutClear(GPIO27); // 初始化 DS1302 通信引脚

    i = DS1302SingleRead(0); // 读取秒寄存器
    qDebug() << i;
    if ((i & 0x80) != 0) {    // 由秒寄存器最高位CH的值判断 DS1302 是否已停止
        qDebug() << "I2COpen()";
        DS1302SingleWrite(7, 0x00); // 撤销写保护以允许写入数据
        for (i=0; i<7; i++) { // 设置 DS1302 为默认的初始时间
            DS1302SingleWrite(i, InitTime[i]);
        }
    } else {
        qDebug() << "I2COpen()-----------OK";
    }
}


int GPIO_PinState(unsigned int* pPinState) {
    int 				rc;
    struct double_pars	dpars;
    dpars.par1 = EM335X_GPIO_INPUT_STATE;	// 5
    dpars.par2 = *pPinState;
    rc = read(Gpio_fd, &dpars, sizeof(struct double_pars));
    if (!rc) {
        *pPinState = dpars.par2;
    }
    return rc;
}


int GPIO_OutEnable(unsigned int dwEnBits) {
    int                 rc;
    struct double_pars  dpars;

    dpars.par1 = EM335X_GPIO_OUTPUT_ENABLE; // 0
    dpars.par2 = dwEnBits;

    rc = write(Gpio_fd, &dpars, sizeof(struct double_pars));
    return rc;
}
int GPIO_OutDisable(unsigned int dwDisBits) {
    int                 rc;
    struct double_pars  dpars;

    dpars.par1 = EM335X_GPIO_OUTPUT_DISABLE; // 1
    dpars.par2 = dwDisBits;

    rc = write(Gpio_fd, &dpars, sizeof(struct double_pars));
    return rc;
}
int GPIO_OutSet(unsigned int dwSetBits) {
    int                 rc;
    struct double_pars  dpars;

    dpars.par1 = EM335X_GPIO_OUTPUT_SET;   // 2
    dpars.par2 = dwSetBits;

    rc = write(Gpio_fd, &dpars, sizeof(struct double_pars));
    return rc;
}
int GPIO_OutClear(unsigned int dwClearBits) {
    int                 rc;
    struct double_pars  dpars;

    dpars.par1 = EM335X_GPIO_OUTPUT_CLEAR;  // 3
    dpars.par2 = dwClearBits;

    rc = write(Gpio_fd, &dpars, sizeof(struct double_pars));
    return rc;
}


void DS1302ByteWrite(unsigned char dat){
    unsigned char mask;
    unsigned char a_dat = 0;

    a_dat = 0; a_dat = 0; a_dat = 0;
    for (mask=0x01; mask!=0; mask<<=1){
        if ((mask&dat) != 0){
            GPIO_OutSet(GPIO26);
        }else{
            GPIO_OutClear(GPIO26);
        }
        GPIO_OutSet(GPIO27);
        GPIO_OutClear(GPIO27);
    }
    GPIO_OutSet(GPIO26);
}

unsigned char DS1302ByteRead(){
    int y;
    unsigned char mask;
    unsigned char dat_read = 0;
    unsigned int dwPinState;
    y = 0;
    dwPinState = GPIO26;
    for (y = 0; y < 8; y++){
        mask = (1 << (y));
        dwPinState = GPIO26;
        GPIO_PinState(&dwPinState);
        if (dwPinState == (1<<26)){
            dat_read |= mask;
        } else {
            //
        }
        if (y == 7) {
            break;
        }
        GPIO_OutSet(GPIO27);
        GPIO_OutClear(GPIO27);
    }
    return dat_read;
}

void DS1302SingleWrite(unsigned char reg, unsigned char dat){
    GPIO_OutSet(GPIO23);
    usleep(1);
    GPIO_OutEnable(GPIO26);
    DS1302ByteWrite((reg<<1)|0x80);
    DS1302ByteWrite(dat);
    usleep(1);
    GPIO_OutClear(GPIO23);
}

unsigned char DS1302SingleRead(unsigned char reg){
    unsigned char dat;
    GPIO_OutSet(GPIO23);
    usleep(1);
    GPIO_OutEnable(GPIO26);
    DS1302ByteWrite((reg<<1)|0x81);
    GPIO_OutDisable(GPIO26);
    dat = DS1302ByteRead();
    usleep(1);
    GPIO_OutClear(GPIO23);
    return dat;
}

