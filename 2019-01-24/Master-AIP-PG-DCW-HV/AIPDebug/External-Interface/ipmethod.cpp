/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "ipmethod.h"
static bool State_Flag;
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.29
  * brief:      输入法初始化
******************************************************************************/
IPMethod::IPMethod()
{
    this->wKeyb = NULL;

    State_Flag = 0;
    isCapsLock = true;
    if (NULL == this->wKeyb) {
        this->wKeyb = new w_Keyb;

        connect(this->wKeyb, SIGNAL(SendString(QString)), this, SLOT(Preedit(QString)));
        connect(this->wKeyb, SIGNAL(SendEnter()), this, SLOT(Confirm()));
        connect(this->wKeyb, SIGNAL(SendBackspace()), this, SLOT(Backspace()));
        connect(this->wKeyb, SIGNAL(SendEscape()), this, SLOT(Escape()));
        connect(this->wKeyb, SIGNAL(SendCapsLock()), this, SLOT(CapsLock()));
        connect(this, SIGNAL(SendCaps(bool)), this->wKeyb, SLOT(Caps(bool)));
    }
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.29
  * brief:      输入法析构
******************************************************************************/
IPMethod::~IPMethod()
{
    delete this->wKeyb;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.29
  * brief:      输入
******************************************************************************/
void IPMethod::Preedit(QString newcontent)
{
    if (isCapsLock)
        sendCommitString(newcontent.toUpper(), 0, 0);
    else
        sendCommitString(newcontent.toLower(), 0, 0);
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.29
  * brief:      输入
******************************************************************************/
void IPMethod::SendString(QString newcontent)
{
    sendCommitString(newcontent, 0, 0);
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.29
  * brief:      确认输入
******************************************************************************/
void IPMethod::Confirm()
{
    sendCommitString(content, 0, 0);
    content.clear();
    //  QApplication::focusWidget()->clearFocus();

    //  if (NULL==this->wKeyb)
    //  {
    //      return;
    //  }
    //  else
    //  {
    //      this->wKeyb->hide();
    //  }
    //  QApplication::focusWidget()->clearFocus();
}
/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.8.10
  * brief:      上下
******************************************************************************/
void IPMethod::Upspace()
{
    QWSServer::sendKeyEvent(0x01000013, Qt::Key_Up, Qt::NoModifier, true, false);
}
void IPMethod::Downspace()
{
    QWSServer::sendKeyEvent(0x01000015, Qt::Key_Down, Qt::NoModifier, true, false);
}
void IPMethod::Tabspace()
{
    QWSServer::sendKeyEvent(0x01000001, Qt::Key_Tab, Qt::NoModifier, true, false);
}
void IPMethod::BackTabspace()
{
    QWSServer::sendKeyEvent(0x01000002, Qt::Key_Backtab, Qt::NoModifier, true, false);
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.29
  * brief:      删除
******************************************************************************/
void IPMethod::Backspace()
{
    //  sendCommitString("",-1,1);
    QWSServer::sendKeyEvent(0x01000003, Qt::Key_Backspace, Qt::NoModifier, true, false);

    /*  if (this->content.isEmpty())
    {
        sendCommitString(content,-1,1);
    }
    else
    {
        this->content.chop(1);
        sendPreeditString(content,0);
    } */
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.29
  * brief:      退出
******************************************************************************/
void IPMethod::Escape()
{
    if (NULL == this->wKeyb) {
        return;
    } else if (State_Flag == 1) {
        this->wKeyb->hide();
        QApplication::focusWidget()->clearFocus();
        State_Flag = 0;
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.29
  * brief:      大小写切换
******************************************************************************/
void IPMethod::CapsLock()
{
    if (isCapsLock) {
        isCapsLock = false;
    } else {
        isCapsLock = true;
    }
    SendCaps(isCapsLock);
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.29
  * brief:      输入法启动
******************************************************************************/
void IPMethod::updateHandler(int type)
{
    switch (type) {
    case QWSInputMethod::FocusIn:
        this->wKeyb->show();
        this->wKeyb->raise();
        this->wKeyb->updatePos();
        State_Flag = 1;
        break;
    case QWSInputMethod::FocusOut:
        if (NULL == this->wKeyb) {
            break;
        } else {
            this->wKeyb->hide();
            State_Flag = 0;
            //  delete this->wKeyb;
        }
        //  this->wKeyb=NULL;
        break;
    default:
        break;
    }
}
/******************************************************************************
                                    END
******************************************************************************/
