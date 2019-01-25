/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     2.0
 * author:      SL
 * date:        2015.12.10
 * brief:       主界面
*******************************************************************************/
#ifndef IPMETHOD_H
#define IPMETHOD_H

#include <QWSInputMethod>
#include <w_keyb.h>

class IPMethod : public QWSInputMethod
{
    Q_OBJECT

public:
    IPMethod();
    ~IPMethod();

public:
    void updateHandler(int);

private:
    w_Keyb* wKeyb;

    QString content;
    bool isCapsLock;

signals:
    void SendCaps(bool);

private slots:
    void SendString(QString);
    void Preedit(QString);
    void Confirm();
    void Backspace();
    void Escape();
    void CapsLock();

    void Upspace();
    void Downspace();
    void Tabspace();
    void BackTabspace();
};

#endif // IPMETHOD_H
