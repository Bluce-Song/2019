/*******************************************************************************
 * Copyright [2016]   <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     2.0.7.1
 * author:      sl
 * brief:       头文件
*******************************************************************************/
#ifndef WIDGET_IR_H
#define WIDGET_IR_H

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QTableWidgetItem>
#include <QLabel>
#include <QMessageBox>
#include <string>

#include "linux_can.h"
#include "define.h"

namespace Ui {
class Widget_IR;
}

class Widget_IR : public QWidget
{
    Q_OBJECT
public:
    explicit Widget_IR(QWidget *parent = 0);
    ~Widget_IR();

    int  IR_Test_Total; //-相间绝缘测试总数
    QStringList IRgroup_num; //-相间绝缘测试的组号
    QStringList Copy_IR_List; //-绝缘存储数据

    int  IR_Compensate(double);
    bool IR_Back_Key_E();
    bool IR_If_Compensate(QString);
    void Pub_Conf_Set_IR(QString string, int value);
    QStringList IR_Test_Param(bool);
    QStringList IR_Test_Result(QStringList);
    void IR_NetData(QStringList, QString);
    void IR_UsartData(QStringList);


private:
    Ui::Widget_IR *ui;

    int  IRHostJudge; //-绝缘测试结果，上位机进行自主判定
    bool ACW_Between_IR; //-普通交耐和相间交耐的区别
    bool Init_Flag; // -IR 初始化进行中
    bool IR_Compensate_Flag; //-绝缘补偿标志位
    bool Init_Channel_6;
    double IR_Compensate_Result; //-绝缘补偿数据
    QLabel *IR_Labelhide; //-绝缘隐藏标签
    can_frame frame;
    QButtonGroup *IR_btnGroup;
    QList<QCheckBox *> Box_All_List;
    QList<QCheckBox *> Box_IR_list;
    QList<QTableWidgetItem*>  IR_H;
    QList<QTableWidgetItem*>  IR_L;
    QList<QTableWidgetItem*>  IR_vola;
    QList<QTableWidgetItem*>  IR_bres;
    QList<QTableWidgetItem*>  IR_pres;
    QList<QTableWidgetItem*>  IR_time;
    QList<QTableWidgetItem*>  IR_compensate;
    QStringList IR_Volt; // 绝缘电压
    bool Line_HV;
    QString Line_HV_High;
    QString Line_HV_Low;

    void Pri_IR_Init(QString);
    void Pri_IR_Save_Data();
    void Pri_IR_Default_value();
    void Pri_IR_Test(QString, int);
    void Pri_IR_WMessage(QString Warning_Text);
    bool Pri_IR_T1T2_Judge(QString, QString);
    void Pri_IR_Param(QString);
    void Pri_IR_Group_One();
    void Pri_IR_Group_Two();

signals:
    void canSend(can_frame frame);

private slots:
    void join_buttonJudge(int);
    void box_statechange();
    void on_doubleSpinBox_IR_UpDCR_editingFinished();
    void on_doubleSpinBox_IR_DownDCR_editingFinished();
    void on_IrTab_cellClicked(int row,  int column);
    void on_IrTab_cellChanged(int row,  int column);
};

#endif // WIDGET_IR_H
