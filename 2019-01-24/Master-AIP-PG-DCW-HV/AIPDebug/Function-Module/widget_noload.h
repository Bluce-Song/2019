/*******************************************************************************
 * Copyright [2016]   <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     2.0.7.1
 * author:      sl
 * brief:       头文件
*******************************************************************************/
#ifndef WIDGET_NOLOAD_H
#define WIDGET_NOLOAD_H

#include <QWidget>

#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTimer>
#include <QDialog>
#include <QDockWidget>
#include <QGridLayout>
#include <QTextCodec>
#include <QSettings>
#include <QCheckBox>
#include <QDir>
#include <QTime>
#include <QButtonGroup>
#include <QSpinBox>
#include <QString>
#include <QDebug>
#include <QInputDialog>
#include <QMessageBox>
#include <netdb.h>

#include "linux_can.h"

namespace Ui {
class Widget_Noload;
}

class Widget_Noload : public QWidget
{
    Q_OBJECT
public:
    explicit Widget_Noload(QWidget *parent = 0);
    ~Widget_Noload();
    QStringList Copy_NOLOAD_List;
    void Pub_Conf_Set_NOLOAD(QStringList, int);
    QStringList NOLOAD_Test_Param();
    void NOLOAD_NetData(QStringList, QString);
private:
    Ui::Widget_Noload *ui;
    QList<QTableWidgetItem*>  NOLOAD_QTableWidgetItem;
    QList<QTableWidgetItem*>  NOLOAD_Time_Series;

    QWidget *Test_Widget;
    QList<QLabel*>    IO_Show_Lable;
    QList<QDoubleSpinBox*> IO_Line_Text;

    bool  NoLoad_Init_Flag;
    void  Pri_NOLOAD_Init(QStringList);
    void  Pri_NOLOAD_Data_Save();

signals:
    void canSend(can_frame frame);
private slots:
    void on_noloadTab_cellChanged(int row, int column);
    void on_pushButton_clicked();
    void IO_Widget_autoquit();
};

#endif // WIDGET_NOLOAD_H
