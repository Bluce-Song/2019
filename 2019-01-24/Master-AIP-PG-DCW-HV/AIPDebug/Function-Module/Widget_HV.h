/*******************************************************************************
 * Copyright [2016]   <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     2.0.7.1
 * author:      sl
 * brief:       头文件
*******************************************************************************/
#ifndef WIDGET_ HV_H
#define WIDGET_HV_H

#include <QWidget>
#include <QCheckBox>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QLabel>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QDebug>
#include <QString>
#include <QPushButton>

#include "define.h"
#include "linux_can.h"


namespace Ui {
class Widget_HV;
}

class Widget_HV : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_HV(QWidget *parent = 0);
    ~Widget_HV();

    QStringList Copy_HV_List; //-高存储数据
    void Pub_Conf_Set_HV(QString str, int value);
    QStringList HV_Test_Param();
    QStringList HV_Test_Result(QStringList);
    void HV_NetData(QStringList, QString);
    void Pri_HV_Param(QString);
    void Pri_HV_Group_One();

private:
    Ui::Widget_HV *ui;

    bool ACW_Between_IR; //-普通交耐和相间交耐的区别
    bool Init_Flag; // -IR 初始化进行中
    bool Init_Channel_6;
    int  volt_set;
    double  set_i_up;
    can_frame frame;
    QButtonGroup *HV_btnGroup;
    QList<QCheckBox *> Box_All_List;
    QList<QCheckBox *> Box_HV_list;

    QStringList freq;
    bool Line_HV;
    QString Line_HV_High;
    QString Line_HV_Low;

    void  mousePressEvent(QMouseEvent * event);
    void  Pri_HV_Init(QString);
    void  Pri_HV_Save_Data();
    void  Pri_HV_Default_value();
    void  Pri_HV_Test();

signals:
    void canSend(can_frame frame);

private slots:
    void on_double_I_Down_editingFinished();
    void on_double_I_Up_editingFinished();
};

#endif // WIDGET_ACW_H
