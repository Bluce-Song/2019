/*******************************************************************************
 * Copyright [2016]   <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     2.0.7.1
 * author:      sl
 * brief:       头文件
*******************************************************************************/
#ifndef WIDGET_BEMF_H
#define WIDGET_BEMF_H

#include <QWidget>
#include <QTableWidgetItem>

#include "linux_can.h"
namespace Ui {
class Widget_BEMF;
}

class Widget_BEMF : public QWidget
{
    Q_OBJECT
public:
    explicit Widget_BEMF(QWidget *parent = 0);
    ~Widget_BEMF();
    QStringList Copy_BEMF_List;
    void Pub_Conf_Set_BEMF(QString, int);
    QStringList BEMF_Test_Param();
    void BEMF_NetData(QStringList, QString);

private:
    Ui::Widget_BEMF *ui;
    QList<QTableWidgetItem*>  BEMF_QTableWidgetItem;

    void Pri_BEMF_Init();
    void Pri_BEMF_Data_Save();
signals:
    void canSend(can_frame frame);
};

#endif // WIDGET_BEMF_H
