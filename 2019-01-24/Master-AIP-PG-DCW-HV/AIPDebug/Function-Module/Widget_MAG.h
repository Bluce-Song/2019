/*******************************************************************************
 * Copyright [2016]   <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     2.0.7.1
 * author:      sl
 * brief:       头文件
*******************************************************************************/
#ifndef WIDGET_MAG_H
#define WIDGET_MAG_H

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QDoubleSpinBox>
#include <QTableWidgetItem>
#include <QString>
#include <QComboBox>
#include <QMessageBox>

#include "define.h"
#include "wt_wave.h"
#include "linux_can.h"

namespace Ui {
class Widget_MAG;
}

class Widget_MAG : public QWidget
{
    Q_OBJECT
public:
    explicit Widget_MAG(QWidget *parent = 0);
    ~Widget_MAG();

    QList<QCheckBox*>  Box_MAG_List;
    QList<QComboBox*>  Comb_MAGConf_List;
    QList<QLineEdit*>  Line_MAG_List[16];
    QList<QLineEdit*>  Line_RMAG_List[16];
    QList<QTableWidgetItem *> MAG_WidgetList[3];

    int  MAG_TestItems;
    int  MAG_TestNumber;
    bool MEKJ_Test;
    QStringList Copy_MAG_List;
    bool  YY_ROT_Test;

    int  MagDir_Conf(int, int, int *waveItt);
    int  Test_MagData(int, int, can_frame);
    void Pub_Conf_Set_MAG(QString str, int flag);
    QStringList MAG_Test_Param(int Mag_shapehide);
    void MAG_NetData(QStringList, QString);
private:
    Ui::Widget_MAG *ui;
    QButtonGroup *MAG_Group;
    QLabel *MAG_Labelhide;
    QList<wt_Wave *> MAG_WaveList;
    can_frame frame;
    QLabel    *label_Waring;
    QLabel    *label_hide;

    bool  YY_Type;
    bool  Init_Channel_6;
    bool  Init_MEKJ;
    void mousePressEvent(QMouseEvent * event);
    int Pri_MagDir_Conf(int); // Conf测试磁旋
    void Pri_MAG_Init(QString);
    void Pri_MAG_Save_Data();
    void Pri_MAG_SetTaskDir(QString);

    void Pri_MAG_Default_value(QString);
    void Pri_MAG_TestSample(); // TestSampleOPP
    void Pri_MAG_Test();       // TestOPP
    int  Pri_Mag_Trend(int *waveform_point);

    QCheckBox *Quick_Set_Standard;
    QWidget *Quick_Set_Widget;
    QPushButton *Quick_Set_Show_join;
    QList<QLabel*> Quick_Set_Show_Lable;
    QList<QDoubleSpinBox*> Quick_Set_DoubleSpinBox;
    QList<QDoubleSpinBox*> Quick_Set_Fre;
    void Pri_Mag_power_UI();

signals:
    void canSend(can_frame frame);

private slots:
    void initSpinBox(QDoubleSpinBox *spin,  int dec,  int min,  int max);
    void buttonJudge(int);
    void Box_0_clicked(int);
    void Box_1_clicked(int);
    void on_oppTab_cellChanged(int row,  int column);
    void on_oppTab_cellClicked(int row,  int column);
    void on_button_power_clicked();
    void Quick_Set_autoquit();
    void Quick_Set_Show_join_Clicked();
};

#endif // WIDGET_MAG_H
