/*******************************************************************************
 * Copyright [2016]   <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     2.0.7.1
 * author:      sl
 * brief:       头文件
*******************************************************************************/
#ifndef WIDGET_LOAD_H
#define WIDGET_LOAD_H

#include <QWidget>
#include <QTableWidgetItem>

#include "linux_can.h"
namespace Ui {
class Widget_Load;
}

class Widget_Load : public QWidget
{
    Q_OBJECT
public:
    explicit Widget_Load(QWidget *parent = 0);
    ~Widget_Load();
    QStringList Copy_LOAD_List;
    void Pub_Conf_Set_LOAD(QString, int);
    QStringList LOAD_Test_Param();
    void LOAD_NetData(QStringList, QString);
private:
    Ui::Widget_Load *ui;
    QList<QTableWidgetItem*>  LOAD_QTableWidgetItem;
    QList<QTableWidgetItem*>  LOAD_Time_Series;

    void Pri_LOAD_Init();
    void Pri_LOAD_Data_Save();

signals:
    void canSend(can_frame frame);
};

#endif // WIDGET_LOAD_H
