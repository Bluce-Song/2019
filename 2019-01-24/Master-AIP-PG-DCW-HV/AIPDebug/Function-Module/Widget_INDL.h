/*******************************************************************************
 * Copyright [2016]   <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     2.0.7.1
 * author:      sl
 * brief:       头文件
*******************************************************************************/
#ifndef WIDGET_INDL_H
#define WIDGET_INDL_H

#include <QWidget>
#include <QComboBox>
#include <QTableWidgetItem>
#include <QCheckBox>
#include <QMessageBox>
#include <QLabel>
#include <QDebug>
#include <QDoubleSpinBox>

#include "linux_can.h"

#define  INDL_init_Number 30
namespace Ui {
class Widget_INDL;
}

class Widget_INDL : public QWidget
{
    Q_OBJECT
public:
    explicit Widget_INDL(QWidget *parent = 0);
    ~Widget_INDL();
    void Pub_Conf_Set_INDL(QString str, int value, int flag);
    QStringList  Copy_INDL_List;
    int   INDL_TestItemsH, INDL_TestItemsL;   //  测试项高字节 测试项低字节
    int   INDL_TestNumber;                  //  电阻测试项目数量
    QStringList INDL_Test_Param();
    void INDL_NetData(QStringList, QString);

private slots:
    void on_indlTab_cellClicked(int row,  int column);
    void join_buttonJudge(int);
    void on_indlTab_cellChanged(int row,  int column);
    void on_Button_Auto_clicked();
    void on_INDL_Min_editingFinished();
    void on_Button_Comp_clicked();
    void Pri_INDL_WMessage(QString Waring_Text);
    void on_button_model_clicked();
    void IO_Widget_autoquit();

signals:
    void canSend(can_frame frame);
    void Lable_Display();
private:
    Ui::Widget_INDL *ui;

    QWidget   *INDL_Widget;
    QList<QLabel*>    INDL_Show_Lable;
    QList<QDoubleSpinBox*> INDL_DoubleSpinBox;
    QLabel       *INDL_Labelhide;
    QButtonGroup *INDL_Group;
    QList<QTableWidgetItem*>  INDL_QTableWidgetItem;
    QList<QTableWidgetItem*>  INDL_QTablePoint1;
    QList<QTableWidgetItem*>  INDL_QTablePoint2;
    QList<QCheckBox *>        Box_INDL_Grade_List;
    can_frame frame;
    QStringList INDL_Unit;


    bool  INDL_Init_Flag;
    bool  Init_Channel_6;

    void  mousePressEvent(QMouseEvent * event);
    void  Pri_INDL_Init();
    void  Pri_INDL_Data_Save();
    void  Pri_INDL_Test_Parameter();
    void  Pri_Pwr_WMessage(QString);
    void  Pri_INDL_Calibration_clear();
    void  Pri_INDL_Default_value(QString);
    void  Pri_INDL_Test_Start(int);
    void  Pri_INDL_Auto_Set(QString, int);
    void  Pri_INDL_Quiky_Test_Parameter();
};

#endif // WIDGET_INDL_H
