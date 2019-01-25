/*******************************************************************************
 * Copyright [2016]   <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     2.0.7.1
 * author:      sl
 * brief:       头文件
*******************************************************************************/
#ifndef WIDGET_PWR_H
#define WIDGET_PWR_H

#include <QWidget>
#include <QComboBox>
#include <QCheckBox>
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QTableWidgetItem>
#include <QDockWidget>
#include <QGridLayout>
#include <QDoubleSpinBox>

#include "linux_can.h"

namespace Ui {
class Widget_PWR;
}

class Widget_PWR : public QWidget
{
    Q_OBJECT
public:
    explicit Widget_PWR(QWidget *parent = 0);
    ~Widget_PWR();

    int   PWM_Row_Count;
    QStringList PWR_Test_Data;
    QStringList PWR_SetData;
    QStringList PG_Test_Order;
    void Pub_Conf_Set_PWR(QStringList List, QString str, int flag);
    QStringList Copy_PWR_List;

    QStringList Pub_Set_PG(can_frame frame);
    QStringList PWR_Test_Param();
    void PWR_NetData(QStringList, QString);

signals:
    void canSend(can_frame frame, int);

private slots:
    void on_pwrTab_cellClicked(int row,  int column);
    void on_pwrTab_cellChanged(int row,  int column);
    void on_PWR_Volt_up_editingFinished();
    void on_PWR_Volt_down_editingFinished();
    void on_pgTab_cellChanged(int row,  int column);


    void on_toolButton_4_clicked();
    void buttonJudge(int);
    void pg_buttonJudge(int);
    void on_pushButton_Volt_clicked();
    void Volt_Widget_autoquit();
    void Volt_sample(int);

    void on_pushButton_Noise_clicked();
    void Noise_Widget_autoquit();
    void Noise_CCW_clicked(bool);
    void on_pwrset_Turn_cellClicked(int row, int column);

private:
    Ui::Widget_PWR *ui;
    QList<QTableWidgetItem*>  PG_QTableWidgetItem;

    can_frame frame;
    QWidget *Widget_Button;
    QList<QPushButton *>  Pwr_Button;
    QButtonGroup *Pwr_Button_Group;
    QButtonGroup *Pg_Button_Group;
    QLabel       *PWR_Labelhide; // 功率隐藏
    bool   EPAR_Init_Flag;
    QStringList pwrturn;
    QStringList Button_Text;
    QStringList pwr_set_turn;

    int    PWR_Row;
    int    Old_Id;

    int     PWR_Test_All_number;
    bool    Turn_Shan;
    int     Set_pwr_Turn;
    int     Pwr_Usart_Count;
    QString PWM_Model;

    double pg_Cur, pg_floor, pg_up;
    double pg_freq_min, pg_freq_avr, pg_freq_max;
    double pg_duty_min, pg_duty_avr, pg_duty_max;
    double pg_speed;

    bool  Init_Channel_6;
    QWidget *Volt_Widget;
    QButtonGroup *Volt_Button_Group;
    QList<QLabel*>    IO_Show_Lable;
    QLabel            *Volt_Back_Lable;
    QList<QDoubleSpinBox *> Volt_Line_Text;
    QList<QPushButton *> Volt_Button;
    int Volt_Sample_Grade;
    bool Volt_Sample_ONE;
    int  Volt_ONE;

    QWidget   *Noise_Widget;
    QCheckBox *Noise_CW;
    QCheckBox *Noise_CCW;
    QList<QLabel*>  Noise_Lable;
    QList<QDoubleSpinBox *> Npise_Double_Box;

    void  mousePressEvent(QMouseEvent * event);
    void  Pri_PWR_Init(QStringList);
    void  Pri_PWR_Data_Save();
    void  Pri_PWR_Test_Parameter(QString);
    void  Pri_PWR_Test_start(QString);
    void  Pri_PWR_power_chose(int);
    void  dd(int);
    void  Pri_Test_Two();
    void  Pri_PWR_Noise_Widget();
};

#endif // WIDGET_PWR_H
