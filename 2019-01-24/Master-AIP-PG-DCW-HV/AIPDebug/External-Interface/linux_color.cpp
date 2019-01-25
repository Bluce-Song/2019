/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "linux_color.h"

LINUX_COLOR::LINUX_COLOR(QWidget *parent) :
    QWidget(parent) {
     // -
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.19
  * brief:      背景颜色
******************************************************************************/
QColor LINUX_COLOR::backColor(int colr)
{
    QColor color;
    switch (colr) {
    case 0:
    {
        color.setRgb(0, 0, 0, 255);
        break;
    }
    case 1:
    {
        color.setRgb(170, 0, 0, 255);
        break;
    }
    case 2:
    {
        color.setRgb(0, 85, 0, 255);
        break;
    }
    case 3:
    {
        color.setRgb(170, 85, 0, 255);
        break;
    }
    case 4:
    {
        color.setRgb(0, 170, 0, 255);
        break;
    }
    case 5:
    {
        color.setRgb(170, 170, 0, 255);
        break;
    }
    case 6:
    {
        color.setRgb(0, 255, 0, 255);
        break;
    }
    case 7:
    {
        color.setRgb(170, 255, 0, 255);
        break;
    }
    case 8:
    {
        color.setRgb(0, 0, 127, 255);
        break;
    }
    case 9:
    {
        color.setRgb(170, 0, 127, 255);
        break;
    }
    case 10:
    {
        color.setRgb(0, 85, 127, 255);
        break;
    }
    case 11:
    {
        color.setRgb(170, 85, 127, 255);
        break;
    }
    case 12:
    {
        color.setRgb(0, 170, 127, 255);
        break;
    }
    case 13:
    {
        color.setRgb(170, 170, 127, 255);
        break;
    }
    case 14:
    {
        color.setRgb(0, 255, 127, 255);
        break;
    }
    case 15:
    {
        color.setRgb(170, 255, 127, 255);
        break;
    }
    case 16:
    {
        color.setRgb(0, 0, 255, 255);
        break;
    }
    case 17:
    {
        color.setRgb(170, 0, 255, 255);
        break;
    }
    case 18:
    {
        color.setRgb(0, 85, 255, 255);
        break;
    }
    case 19:
    {
        color.setRgb(170, 85, 255, 255);
        break;
    }
    case 20:
    {
        color.setRgb(0, 170, 255, 255);
        break;
    }
    case 21:
    {
        color.setRgb(170, 170, 255, 255);
        break;
    }
    case 22:
    {
        color.setRgb(0, 255, 255, 255);
        break;
    }
    case 23:
    {
        color.setRgb(170, 255, 255, 255);
        break;
    }
    case 24:
    {
        color.setRgb(85, 0, 0, 255);
        break;
    }
    case 25:
    {
        color.setRgb(255, 0, 0, 255);
        break;
    }
    case 26:
    {
        color.setRgb(85, 85, 0, 255);
        break;
    }
    case 27:
    {
        color.setRgb(255, 85, 0, 255);
        break;
    }
    case 28:
    {
        color.setRgb(85, 170, 0, 255);
        break;
    }
    case 29:
    {
        color.setRgb(255, 170, 0, 255);
        break;
    }
    case 30:
    {
        color.setRgb(85, 255, 0, 255);
        break;
    }
    case 31:
    {
        color.setRgb(255, 255, 0, 255);
        break;
    }
    case 32:
    {
        color.setRgb(85, 0, 127, 255);
        break;
    }
    case 33:
    {
        color.setRgb(255, 0, 127, 255);
        break;
    }
    case 34:
    {
        color.setRgb(85, 85, 127, 255);
        break;
    }
    case 35:
    {
        color.setRgb(255, 85, 127, 255);
        break;
    }
    case 36:
    {
        color.setRgb(85, 170, 127, 255);
        break;
    }
    case 37:
    {
        color.setRgb(255, 170, 127, 255);
        break;
    }
    case 38:
    {
        color.setRgb(85, 255, 127, 255);
        break;
    }
    case 39:
    {
        color.setRgb(255, 255, 127, 255);
        break;
    }
    case 40:
    {
        color.setRgb(85, 0, 255, 255);
        break;
    }
    case 41:
    {
        color.setRgb(255, 0, 255, 255);
        break;
    }
    case 42:
    {
        color.setRgb(85, 85, 255, 255);
        break;
    }
    case 43:
    {
        color.setRgb(255, 85, 255, 255);
        break;
    }
    case 44:
    {
        color.setRgb(85, 170, 255, 255);
        break;
    }
    case 45:
    {
        color.setRgb(255, 170, 255, 255);
        break;
    }
    case 46:
    {
        color.setRgb(85, 255, 255, 255);
        break;
    }
    case 47:
    {
        color.setRgb(255, 255, 255, 255);
        break;
    }
    default:
    {
        break;
    }
    }
    return color;
}
