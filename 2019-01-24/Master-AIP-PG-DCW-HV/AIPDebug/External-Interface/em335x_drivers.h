/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     2.0
 * author:      SL
 * date:        2015.12.10
 * brief:       主界面
*******************************************************************************/
#ifndef __ASM_ARCH_EM335X_DRIVERS_H
#define __ASM_ARCH_EM335X_DRIVERS_H

#include <asm-generic/ioctl.h>

#define EM335X_DEV_MAJOR  251
#define EM335X_SYSINFO_MINOR  0   // EM335X_sysinfo
#define EM335X_ISA_MINOR  1   // EM335X_isa
#define EM335X_GPIO_MINOR  2   // EM335X_gpio
#define EM335X_KEYPAD_MINOR      3   // EM335X_keypad
#define EM335X_IRQ1_MINOR  4   // EM335X_irq1
#define EM335X_IRQ2_MINOR  5   // EM335X_irq2
#define EM335X_IRQ3_MINOR  6   // EM335X_irq3
#define EM335X_IRQ4_MINOR  7   // EM335X_irq4

#define EM335X_PWM1_MINOR  8   // EM335X_pwm1(->GPIO12 of EM335X)
#define EM335X_PWM2_MINOR  9   // EM335X_pwm2(->GPIO14 of EM335X)
#define EM335X_PWM3_MINOR  10   // EM335X_pwm3(->GPIO15 of EM335X)
#define EM335X_PWM4_MINOR  11   // EM335X_pwm3(->GPIO15 of EM335X)
#define EM335X_LCD_MINOR  12   // EM335X_lcd
#define EM335X_SPI_MINOR  13   // EM335X_spi(use hardware SPI1)
#define EM335X_AD_MINOR       14   // EM335X_ad


#define EM335X_BOARD_TYPE_EM335X 0
#define EM335X_BOARD_TYPE_EM9281 1
#define EM335X_BOARD_TYPE_EM9380 2
#define EM335X_BOARD_TYPE_EM9283 3
#define EM335X_BOARD_TYPE_EM9287 7



/*
* Emlinix JUN-2-2010: double input parameters can be used in more than one driver
*/
struct double_pars {
    unsigned int par1;
    unsigned int par2;
};


struct pwm_config_info {
    unsigned int freq;   /* in Hz */
    unsigned int duty;  /* in % */
    unsigned int polarity;
    unsigned int count;
};

struct daq_info {
    unsigned int cmd;  //  = 0, 1, 2, ....
    unsigned int data;  //  data value
    char  unit[16]; //  return unit string: "Voltage", "Kalvin"
};

/*
* Emlinix FEB-15-2010: ioctl cmd code definitions:
*/
#define EM335X_MAGIC    EM335X_DEV_MAJOR

#define EM335X_SYSINFO_IOCTL_GET_DBGSL  _IOR(EM335X_MAGIC,  0x00, unsigned int)
#define EM335X_SYSINFO_IOCTL_GET_BOARDTYPE _IOR(EM335X_MAGIC,  0x01, unsigned int)
#define EM335X_SYSINFO_IOCTL_GET_VID  _IOR(EM335X_MAGIC,  0x02, unsigned int)
#define EM335X_SYSINFO_IOCTL_GET_UID  _IOR(EM335X_MAGIC,  0x03, unsigned int)
#define EM335X_SYSINFO_IOCTL_GET_BOOTSTATUS _IOR(EM335X_MAGIC,  0x04, unsigned int)

#define EM335X_IRQ_IOCTL_GET_COUNT  _IOR(EM335X_MAGIC,  0x80, unsigned int)
#define EM335X_IOCTL_SET_IDLE   _IOR(EM335X_MAGIC,  0x81, unsigned int)
#define EM335X_IOCTL_GET_IDLESTATE  _IOR(EM335X_MAGIC,  0x82, unsigned int)


#define EM335X_PWM_IOCTL_START   _IOW(EM335X_MAGIC,  0xb0, struct double_pars)
#define EM335X_PWM_IOCTL_STOP   _IO(EM335X_MAGIC,   0xb1)
#define EM335X_COUNT_IOCTL_START   _IOW(EM335X_MAGIC,  0xb2, struct double_pars)
#define EM335X_COUNT_IOCTL_STOP   _IO(EM335X_MAGIC,   0xb3)

#define EM335X_AUART_MAJOR 242
#define EM335X_IOCTL_SET_RTS_PIN   _IOR(EM335X_AUART_MAJOR,  0x00, unsigned int)


#define GPIO0 (1 <<  0)
#define GPIO1 (1 <<  1)
#define GPIO2 (1 <<  2)
#define GPIO3 (1 <<  3)
#define GPIO4 (1 <<  4)
#define GPIO5 (1 <<  5)
#define GPIO6 (1 <<  6)
#define GPIO7 (1 <<  7)
#define GPIO8 (1 <<  8)
#define GPIO9 (1 <<  9)
#define GPIO10 (1 << 10)
#define GPIO11 (1 << 11)
#define GPIO12 (1 << 12)
#define GPIO13 (1 << 13)
#define GPIO14 (1 << 14)
#define GPIO15 (1 << 15)
#define GPIO16 (1 << 16)
#define GPIO17 (1 << 17)
#define GPIO18 (1 << 18)
#define GPIO19 (1 << 19)
#define GPIO20 (1 << 20)
#define GPIO21 (1 << 21)
#define GPIO22 (1 << 22)
#define GPIO23 (1 << 23)
#define GPIO24 (1 << 24)
#define GPIO25 (1 << 25)
#define GPIO26 (1 << 26)
#define GPIO27 (1 << 27)
#define GPIO28 (1 << 28)
#define GPIO29 (1 << 29)
#define GPIO30 (1 << 30)
#define GPIO31 (1 << 31)
#define GPIOX_FLAG (1 << 31)

#define EM335X_GPIO_OUTPUT_ENABLE  0
#define EM335X_GPIO_OUTPUT_DISABLE 1
#define EM335X_GPIO_OUTPUT_SET  2
#define EM335X_GPIO_OUTPUT_CLEAR  3
#define EM335X_GPIO_INPUT_STATE  5


#define  EM335X_PWM_START   10
#define  EM335X_PWM_STOP   11
#define  EM335X_COUNT_START   12
#define  EM335X_COUNT_STOP   13

// --------------------------------------------------------------------------------------------------------
//  CS&ZHL JAN-11-2013: definitions for AD in EM335X
//
#define EM335X_DAQ_VOLTAGE_CH0  0
#define EM335X_DAQ_VOLTAGE_CH1  1
#define EM335X_DAQ_VDD_5V   2
#define EM335X_DAQ_VDDIO_3V3  3
#define EM335X_DAQ_VDDA_1V8  4
#define EM335X_DAQ_VDDD_1V45  5
#define EM335X_DAQ_CPU_TEMPERATURE 6
#define EM335X_DAQ_BOARD_TEMPERATURE 7


/* app flags definition */
#define APP_FLAG_DEBUG_MODE      0x00000001
#define APP_FLAG_V3_MODE   0x00000002
#define APP_FLAG_CFG0   0x00000004
#define APP_FLAG_CFG1   0x00000008
#define APP_FLAG_LSTARTUP_END  0x80000000
#define APP_FLAG_DEFAULT_CFG  (APP_FLAG_CFG1 | APP_FLAG_CFG0)
#define APP_FLAG_INIT_MODE   (APP_FLAG_DEBUG_MODE | APP_FLAG_V3_MODE | APP_FLAG_DEFAULT_CFG)


/*CS&ZHL  JUN-05-2013: definitions for ISO7816 mode & RTS_TOGGLE */

#define EM335X_ISO7816_T0  (1 << 27)  //  D27 of termios.c_cflag
#define EM335X_ISO7816_T1  (1 << 26)  //  D26 of termios.c_cflag
#define EM335X_TTYS1_RTS_ENABLE (1 << 25)  //  D25 of termios.c_cflag
#define EM335X_TTYS1_DTR_ENABLE (1 << 24)  //  D24 of termios.c_cflag
#define EM335X_ISO7816_RXD_RESET (1 << 23)  //  D23 of termios.c_cflag
#define EM335X_RTS_CONTROL_TOGGLE (1 << 15)  //  D15 of termios.c_cflag
#define EM335X_ISO7816_MODE  (EM335X_ISO7816_T0 | EM335X_ISO7816_T1)

extern unsigned int is_debug(void);

#endif // __ASM_ARCH_EM335X_DRIVERS_H









