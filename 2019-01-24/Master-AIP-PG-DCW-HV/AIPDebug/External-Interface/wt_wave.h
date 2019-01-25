/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     2.0
 * author:      SL
 * date:        2015.12.10
 * brief:       主界面
*******************************************************************************/
#ifndef WT_WAVE_H
#define WT_WAVE_H

#include <QWidget>
#include <QLabel>
#include <QPainter>
#include <math.h>
#include <QDebug>
#include <QMouseEvent>

#include "ipmethod.h"

#define POINT    210
#define HEIGHT   130
#define PI       3.1415

class wt_Wave : public QLabel
{
    Q_OBJECT

public:
    explicit wt_Wave(QWidget *parent = 0);
signals:
    void SET_IMP(int, bool);
    void SET_Point(int, int, int);
    void SET_Free();

public:
    int  num;
    int  Red_line;
    int  Green_line;
    int  IMPFlag;
    bool Test_Shape;
    bool IMPBigShape_Flag;
    bool TestShape_Flag;
    bool IMP_Point;
    bool Block_Point;
    QString IMP_string;
    QString Test_string;
    int IMP_PP;
    int Test_IMP_PP;  //  匝间峰峰值 电压
    int IMP_Fre;
    int IMP_X;
    int IMP_Y;
    int point[1000];
    int pointgreen[1000];
    int lablenum;
    int sample_point[8][400];
    QStringList  Block_Save_Point;

public slots:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent * event);
};

#endif // WT_WAVE_H
