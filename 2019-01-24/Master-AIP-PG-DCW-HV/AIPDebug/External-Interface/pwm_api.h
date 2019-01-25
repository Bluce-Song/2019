/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     2.0
 * author:      SL
 * date:        2015.12.10
 * brief:       主界面
*******************************************************************************/
#ifndef __ASM_ARCH_PWM_API_H
#define __ASM_ARCH_PWM_API_H

#ifdef  __cplusplus
extern "C" {
#endif

#define PWM_POLARITY_NORMAL   (0 << 0)
#define PWM_POLARITY_INVERTED (1 << 0)

int Beep_PWM_Start(double duty);
int Beep_PWM_Stop();

int Led_PWM_Start(int duty);
int Led_PWM_Stop();

#ifdef __cplusplus
}
#endif

#endif
