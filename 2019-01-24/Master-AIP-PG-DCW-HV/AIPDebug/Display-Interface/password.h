/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     2.0
 * author:      SL
 * date:        2015.12.10
 * brief:       主界面
*******************************************************************************/
#ifndef PASSWORD_H
#define PASSWORD_H

#include <QWidget>
#include <QDesktopWidget>
#include <QLineEdit>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>

#include "define.h"

namespace Ui {
class PassWord;
}

class PassWord : public QWidget
{
    Q_OBJECT
public:
    explicit PassWord(QWidget *parent = 0);
    ~PassWord();

    int Password_Check;
    struct {
        QString Syst;
        QString Debug;
        QString Conf;
    }Password;

    void CheckDisplay(int);
private slots:
    void on_Cancle_Button_clicked();
    void on_Ok_Button_clicked();
    void on_MCancel_Button_clicked();
    void on_Make_Button_clicked();
    void on_MOK_Button_clicked();

signals:
    void Singal_pass_to_main(int, int);
private:
    Ui::PassWord *ui;
};

#endif // PASSWORD_H
