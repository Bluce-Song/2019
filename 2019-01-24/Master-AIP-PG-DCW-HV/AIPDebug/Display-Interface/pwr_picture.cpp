/*******************************************************************************
 * Copyright [2016]   <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     2.0.7.1
 * author:      sl
 * brief:       头文件
*******************************************************************************/
#include "pwr_picture.h"
#include "ui_pwr_picture.h"

pwr_picture::pwr_picture(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pwr_picture)
{
    ui->setupUi(this);
}

pwr_picture::~pwr_picture()
{
    delete ui;
}
