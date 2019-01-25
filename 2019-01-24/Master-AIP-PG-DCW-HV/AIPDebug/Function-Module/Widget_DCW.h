/*******************************************************************************
 * Copyright [2016]   <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     2.0.7.1
 * author:      sl
 * brief:       头文件
*******************************************************************************/
#ifndef WIDGET_DCW_H
#define WIDGET_DCW_H

#include <QWidget>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QString>
#include <QLabel>
#include <QCheckBox>
#include <QDebug>
#include <QTableWidgetItem>
#include <QMessageBox>

#include "linux_can.h"
#include "define.h"

namespace Ui {
class Widget_DCW;
}

class Widget_DCW : public QWidget
{
    Q_OBJECT
public:
    explicit Widget_DCW(QWidget *parent = 0);
    ~Widget_DCW();
\
    int DCW_Test_Total; //-相间耐压测试总数
    QStringList DCWgroup_num; //-相间测试的数组
    QStringList Copy_DCW_List; //-耐压存储数据

    int  DCW_Compensate(double);
    bool DCW_Back_Key_E();
    bool DCW_If_Compensate(QString);
    void Pub_Conf_Set_DCW(QString, int);
    QStringList DCW_Test_Param();
    QStringList DCW_Test_Result(QStringList);
    void DCW_NetData(QStringList, QString);

private:
    Ui::Widget_DCW *ui;

    bool DCW_Between_IR; //-普通直耐和相间直耐的区别
    bool Init_Flag; // -DCW 初始化进行中
    bool DCW_Compensate_Flag; //-直耐补偿标志位
    double DCW_Compensate_Result; //-交耐补偿数据
    QLabel *DCW_Labelhide; //-直耐隐藏标签
    bool Init_Channel_6;
    int  volt_set;

    can_frame frame;
    QButtonGroup *DCW_btnGroup;
    QList<QCheckBox *> Box_All_List;
    QList<QCheckBox *> Box_DCW_list;
    QList<QTableWidgetItem*>  DCW_T1_List; //-相间高端
    QList<QTableWidgetItem*>  DCW_T2_List; //-相间低端
    QList<QTableWidgetItem*>  DCW_voltage; //-相间电压
    QList<QTableWidgetItem*>  DCW_I_Max; //-相间电流上限
    QList<QTableWidgetItem*>  DCW_I_Min; //-相间电流下限
    QList<QTableWidgetItem*>  DCW_ARC; //-相间电弧
    QList<QTableWidgetItem*>  DCW_time; //-相间时间
    QList<QTableWidgetItem*>  DCW_compensate; //-相间补偿
    QStringList freq;

    bool  Pri_DCW_T1T2_Judge(QString, QString);
    void  mousePressEvent(QMouseEvent * event);
    void  Pri_DCW_Init(QString);
    void  Pri_DCW_Save_Data();
    void  Pri_DCW_Default_value();
    void  Pri_DCW_Test();
    void  Pri_DCW_WMessage(QString Waring_Text);
    void  Pri_DCW_Param_Init(QString);

signals:
    void canSend(can_frame frame);

private slots:
    void join_buttonJudge(int);
    void on_dcwTab_cellChanged(int row,  int column);
    void on_dcwTab_cellClicked(int row,  int column);
    void box_statechange();
    void on_double_I_Down_editingFinished();
    void on_double_I_Up_editingFinished();
};

#endif // WIDGET_DCW_H
