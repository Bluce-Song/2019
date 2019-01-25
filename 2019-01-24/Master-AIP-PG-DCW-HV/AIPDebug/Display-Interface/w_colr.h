/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     2.0
 * author:      SL
 * date:        2015.12.10
 * brief:       主界面
*******************************************************************************/
#ifndef W_COLR_H
#define W_COLR_H

#include <QDialog>
#include <QToolButton>
#include <QDebug>
#include <define.h>

#define ROW 12

namespace Ui {
class w_Colr;
}

class w_Colr : public QDialog
{
    Q_OBJECT
public:
    explicit w_Colr(QWidget *parent = 0);
    ~w_Colr();
    //    int cWin;
private:
    Ui::w_Colr *ui;
    QList<QToolButton *>  btnList;
    QButtonGroup         *Color_Group;

signals:
    void Signal_color_to_Main(QString, int, int);
private slots:
    void on_pushButton_clicked();
    void ButtonJudge(int);
};

#endif // W_COLR_H
