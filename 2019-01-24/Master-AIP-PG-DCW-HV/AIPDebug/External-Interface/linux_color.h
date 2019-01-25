/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     2.0
 * author:      SL
 * date:        2015.12.10
 * brief:       主界面
*******************************************************************************/
#ifndef LINUX_COLOR_H
#define LINUX_COLOR_H

#include <QWidget>

class LINUX_COLOR : public QWidget
{
    Q_OBJECT
public:
    explicit LINUX_COLOR(QWidget *parent = 0);
signals:

public slots:
    QColor backColor(int color);
};

#endif // LINUX_COLOR_H
