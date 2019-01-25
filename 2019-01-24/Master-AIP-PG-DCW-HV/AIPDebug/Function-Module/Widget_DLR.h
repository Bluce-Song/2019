/*******************************************************************************
 * Copyright [2016]   <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     2.0.7.1
 * author:      sl
 * brief:       头文件
*******************************************************************************/
#ifndef WIDGET_DLR_H
#define WIDGET_DLR_H

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QInputDialog>
#include <QComboBox>
#include <QTableWidgetItem>
#include <QString>
#include <QtCore/qmath.h>
#include <QMessageBox>

#include "define.h"
#include "linux_can.h"

#define  Meterial_Copper      0.0039  //  铜
#define  Meterial_CA_Alloy    0.0041  //  铜铝
#define  Meterial_Aluminum    0.0043  //  铝

namespace Ui {
class Widget_DLR;

}

class Widget_DLR : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_DLR(QWidget *parent = 0);
    ~Widget_DLR();

    QStringList Copy_DLR_List;

    int   DLR_TestItemsH, DLR_TestItemsL; //-测试项高字节 测试项低字节
    int   DLR_TestNumber; //-电阻测试项目数量
    bool  DLR_Compensate_Left, DLR_Compensate_Right;
    bool  DLR_Temp_Flag;

    void   on_AutoSet(QStringList);
    void   Pub_Conf_Set_DLR(QString str, int flag);
    double RealTime_Compensate(double, int);
    QStringList DCR_Test_Param();
    bool   Pub_Conf_Station(QString);
    int    Pub_Conf_DLR_Compensate(QStringList);
    QStringList DCR_Test_Result(can_frame, int, double);
    QStringList DCR_Test_Quick_Result(can_frame);
    void DLR_NetData(QStringList, QString);

private:
    Ui::Widget_DLR *ui;
    QLabel       *DLR_Labelhide; // 电阻隐藏
    QButtonGroup *DLR_Group; // 电阻 T1和T2 选择组
    QList<QCheckBox *> DLR_Box_List; // 电阻使能选框
    QList<QComboBox *> DLR_Comb_List; // 是否需要补偿温度
    QList<QDoubleSpinBox  *>  Edit_DLR_List; //-电阻包含的参数项目进行归整
    QList<QTableWidgetItem *> DLR_SpinList[16];
    QList<QTableWidgetItem*>  DLR_T1_List; // T1
    QList<QTableWidgetItem*>  DLR_T2_List; // T2
    QList<QTableWidgetItem*>  DLR_STD_List; // 标准电阻
//    QList<QTableWidgetItem*>  DLR_Offset_List_Left, DLR_Offset_List_Right; //补偿
    QStringList DLR_Meterial; // 电阻材料
    QStringList DLR_Unit; // 电阻单位
    can_frame frame;
    bool  button_autocalc_Flag;
    bool  Init_Flag;

    bool  Init_Channel_6;
    bool  Init_dcr_15;
    int   Init_dcr_balance;
    bool  YY_Type;
    QWidget   *DCR_Widget;
    QList<QLabel*>    DCR_Show_Lable;
    QList<QDoubleSpinBox*> DCR_DoubleSpinBox;

    QString   strRES_Compensate;
    QString   strRES_Compensate_Value;
    int   strRES_Compensate_Grade;
    int   strRES_Compensate_Num;
    int   RES_Compensate_Sum; // 电阻进行补偿时，进行补偿计数
    int   RES_Compensate_Ok;  // 电阻补偿是否完成
    QString   DCR_Offect_Station;

    int   Pri_judge_grade(int, bool);
    bool  Pri_check_extreme_point();
    void  mousePressEvent(QMouseEvent * event);
    void  Pri_Dlr_WMessage(QString Waring_Text);
    void  Pri_DLR_Init(QString);
    void  Pri_DLR_Init_Compensate();
    void  Pri_DLR_Save_Data();
    void  Pri_DLR_Test(QString);
    void  Pri_DLR_Start(QString);
    void  Pri_DLR_Default_value(QString);

    void  Pri_DLR_Set_PWR_Conf();

signals:
    void canSend(can_frame frame);

private slots:
    void initSpinBox(QDoubleSpinBox *spin, int dec, int min, int max);
    void join_buttonJudge(int);
    void on_resTab_cellChanged(int row, int column);
    void on_resTab_cellClicked(int row, int column);
    void on_button_autocalc_clicked();
    void on_Res_calculateUp_editingFinished();
    void on_button_model_clicked();
    void IO_Widget_autoquit();
};

#endif // WIDGET_DLR_H
