/*******************************************************************************
 * Copyright [2016]   <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     2.0.7.1
 * author:      sl
 * brief:       头文件
*******************************************************************************/
#ifndef WIDGET_IMP_H
#define WIDGET_IMP_H

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QDoubleSpinBox>
#include <QTableWidgetItem>
#include <QString>
#include <QComboBox>
#include <QMessageBox>
#include <QSettings>
#include <QVBoxLayout>

#include "define.h"
#include "wt_wave.h"
#include "linux_can.h"

namespace Ui {
class Widget_IMP;
}

class Widget_IMP : public QWidget
{
    Q_OBJECT
public:
    explicit Widget_IMP(QWidget *parent = 0);
    ~Widget_IMP();

    QList<QTableWidgetItem *> Spin_IMP_List[8];
    //    QList<QDoubleSpinBox *>   RealVolt_IMP_List;
    QList<wt_Wave *> IMP_WaveList;
    QStringList      Copy_IMP_List;
    QStringList      Copy_IMP_Gear;
    int  IMP_TestItems;
    int  IMP_TestNumber;


    void Pub_Conf_Set_IMP(QString str, int flag);
    bool Pub_Conf_GetSample(int);
    void Pub_Main_IMP_FinshSample();
    void Pub_Main_IMP_Get_date(int ittwaveframe, int *waveItt);
    QStringList Pub_Main_IMP_Result(int ittwaveframe, int *waveItt, int station);
    QStringList Pub_Main_IMP_Result_Compare(int ittwaveframe, int *waveItt, int *Compare_waveItt);
    QStringList Pub_Main_IMP_Result_Compare_2(int ittwaveframe, int *waveItt, \
                                              int *Compare_waveItt, int station);
    void Pub_Conf_Get_Result(can_frame frame, int);
    QStringList IMP_Test_Param(bool);
    void IMP_NetData(QStringList, QString);

private:
    Ui::Widget_IMP    *ui;
    QButtonGroup      *IMP_Group;
    QButtonGroup      *btnGroup_Set;
    QList<QCheckBox *> Box_IMP_List;
    QList<wt_Wave *>   IMP_WaveSqlList;
    QList<wt_Wave *>   IMP_Right_Wave; // 右工位  ！13  右工位
    QList<wt_Wave *>   IMP_Left__Wave; // 默认工位 13   左工位
    QLabel    *IMP_Labelhide;
    QLabel    *lableset;
    QLabel    *label_Waring;
    wt_Wave   *Display_Shape;
    can_frame frame;

    bool Init_Channel_6;
    int  Record_Row;
    int  sample_time;
    bool IMP_Test_Ready; // 匝间状态OK
    bool IMP_Add_Sample; // 匝间多样品采集
    bool Init_Flag;
    bool IMP_NO_Back_Volt;
    bool Testing_Real; // 左右工位-正在采集波形，非拉伸
    QString Current_File;
    QStringList Right_value; // 17
    int volt_set;

    void mousePressEvent(QMouseEvent * event);
    double  Pri_IMP_Area(int *stwave, int *wave, uint8_t origin, uint16_t terminal);
    double  Pri_IMP_Diff(int *stwave, int *wave, uint8_t origin, uint16_t terminal);
    int  Pri_IMP_Flut(int *wave, uint8_t origin, uint16_t terminal);
    int  Pri_IMP_Phase(int *stwave, int *wave, uint8_t origin, uint16_t terminal);
    void Pri_IMP_Init(QString);
    void Pri_IMP_Init_Join(QString);
    void Pri_IMP_Data_Save();
    void Pri_IMP_Default_value(QString);
    void Pri_IMP_SetSample_Sarameter(int, int);
    void Pri_IMP_SetSample_Test(int, int, int);
    void Pri_IMP_TestSample(int model, int station);
    void Pri_IMP_Test();
    void Pri_IMP_WMessage(QString Waring_Text);
    void Pri_initSpinBox(QDoubleSpinBox *spin,  int dec,  int min,  int max);


    QWidget *Imp_Set_Widget;
    QList<QLabel*> Set_Show_Lable;
    QCheckBox *Set_Compare_CheckBox;
    QCheckBox *Set_Systematic_CheckBox;
    QCheckBox *Set_Yes_CheckBox;
    void Pri_IMP_Set_UI();

signals:
    void canSend(can_frame frame);
    void Signal_imp_3_6_test(int); // 匝间三相六线控制交流接触器

private slots:
    void on_button_sample_collect_clicked();
    void on_button_sample_cancle_clicked();
    void on_button_sample_average_clicked();
    void on_button_back_clicked();
    void on_ittTab_cellChanged(int row,  int column);
    void on_ittTab_cellClicked(int row,  int column);
    void on_doubleSpinBox_red_editingFinished();
    void on_doubleSpinBox_green_editingFinished();
    void on_comb_Station_currentIndexChanged(int index);
    void slot_imp_buttonJudge(int);
    void slot_imp_buttonJudge_set(int);
    void slot_imp_set_point(int, int, int);
    void slot_big_shape(int, bool);
    void on_pushButton_clicked();
    void Set_autoquit();
    void onStateChanged(int);
};

#endif // WIDGET_IMP_H
