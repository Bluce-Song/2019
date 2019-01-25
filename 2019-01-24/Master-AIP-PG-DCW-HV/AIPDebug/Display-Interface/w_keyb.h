/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     2.0
 * author:      SL
 * date:        2015.12.10
 * brief:       主界面
*******************************************************************************/
#ifndef W_KEYB_H
#define W_KEYB_H

#include <QWidget>
#include <QButtonGroup>
#include <QDebug>

namespace Ui {
class w_Keyb;
}

class w_Keyb : public QWidget
{
    Q_OBJECT
public:
    explicit w_Keyb(QWidget *parent = 0);
    ~w_Keyb();

    QButtonGroup *button_group;

private:
    Ui::w_Keyb *ui;

    QPoint  mouse_pos;
    QPoint  widget_pos;
    bool    should_move;
    bool    CapS;
    void SetKeyBoard();
public slots:
    void ButtonJudge(int);
    void updatePos();
    void Caps(bool);
signals:
    void SendString(QString str);
    void SendEnter();
    void SendBackspace();
    void SendEscape();
    void SendCapsLock();
    void SendCaps();
};

#endif // W_KEYB_H
