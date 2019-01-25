/*******************************************************************************
 * Copyright [2016]   <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     2.0.7.1
 * author:      sl
 * brief:       头文件
*******************************************************************************/
#ifndef WIDGET_BLDC_PG_H
#define WIDGET_BLDC_PG_H

#include <QWidget>
#include <QTableWidgetItem>
#include <QButtonGroup>
#include <QCheckBox>

#include "linux_can.h"

namespace Ui {
class Widget_BLDC_PG;
}

class Widget_BLDC_PG : public QWidget
{
    Q_OBJECT
public:
    explicit Widget_BLDC_PG(QWidget *parent = 0);
    ~Widget_BLDC_PG();
    QStringList Copy_BLDCPG_List;
    QStringList FG_Test_Data;
    int wave_count;

    void Pub_Conf_Set_PG(QStringList, int);
    QStringList PG_Test_Param();
    void BLDCPG_NetData(QStringList, QString);

private:
    Ui::Widget_BLDC_PG *ui;
    QList<QTableWidgetItem*>  PG_QTableWidgetItem;
    QButtonGroup *PG_Button_Group;
    QList<QCheckBox *> PG_Check_Box_Group;
    int  Old_Id;
    bool FG_Init_Flag;


    void Pri_PG_Init(QStringList);
    void Pri_PG_Data_Save();
    void dd(int);

signals:
    void canSend(can_frame frame);

private slots:
    void buttonJudge(int);
    void on_bldcpgTab_cellChanged(int row, int column);
};

#endif // WIDGET_BLDC_PG_H
