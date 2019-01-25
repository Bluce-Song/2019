/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.30
 * brief:       软键盘界面
*******************************************************************************/
#include "w_keyb.h"
#include "ui_w_keyb.h"
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      软键盘界面初始化
******************************************************************************/
w_Keyb::w_Keyb(QWidget *parent) :
    QWidget(parent, Qt::Tool| Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint),
    ui(new Ui::w_Keyb)
{
    ui->setupUi(this);
    this->button_group = new QButtonGroup;
    this->SetKeyBoard();
    QObject::connect(this->button_group, SIGNAL(buttonClicked(int)), \
                     this, SLOT(ButtonJudge(int)));
    CapS = true;
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      软键盘析构
******************************************************************************/
w_Keyb::~w_Keyb()
{
    delete this->button_group;
    delete ui;
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      按键定义
******************************************************************************/
void w_Keyb::SetKeyBoard()
{
    this->button_group->addButton(ui->Key_0, Qt::Key_0);
    this->button_group->addButton(ui->Key_1, Qt::Key_1);
    this->button_group->addButton(ui->Key_2, Qt::Key_2);
    this->button_group->addButton(ui->Key_3, Qt::Key_3);
    this->button_group->addButton(ui->Key_4, Qt::Key_4);
    this->button_group->addButton(ui->Key_5, Qt::Key_5);
    this->button_group->addButton(ui->Key_6, Qt::Key_6);
    this->button_group->addButton(ui->Key_7, Qt::Key_7);
    this->button_group->addButton(ui->Key_8, Qt::Key_8);
    this->button_group->addButton(ui->Key_9, Qt::Key_9);

    this->button_group->addButton(ui->Key_A, Qt::Key_A);
    this->button_group->addButton(ui->Key_B, Qt::Key_B);
    this->button_group->addButton(ui->Key_C, Qt::Key_C);
    this->button_group->addButton(ui->Key_D, Qt::Key_D);
    this->button_group->addButton(ui->Key_E, Qt::Key_E);
    this->button_group->addButton(ui->Key_F, Qt::Key_F);
    this->button_group->addButton(ui->Key_G, Qt::Key_G);
    this->button_group->addButton(ui->Key_H, Qt::Key_H);
    this->button_group->addButton(ui->Key_I, Qt::Key_I);
    this->button_group->addButton(ui->Key_J, Qt::Key_J);
    this->button_group->addButton(ui->Key_K, Qt::Key_K);
    this->button_group->addButton(ui->Key_L, Qt::Key_L);
    this->button_group->addButton(ui->Key_M, Qt::Key_M);
    this->button_group->addButton(ui->Key_N, Qt::Key_N);
    this->button_group->addButton(ui->Key_O, Qt::Key_O);
    this->button_group->addButton(ui->Key_P, Qt::Key_P);
    this->button_group->addButton(ui->Key_Q, Qt::Key_Q);
    this->button_group->addButton(ui->Key_R, Qt::Key_R);
    this->button_group->addButton(ui->Key_S, Qt::Key_S);
    this->button_group->addButton(ui->Key_T, Qt::Key_T);
    this->button_group->addButton(ui->Key_U, Qt::Key_U);
    this->button_group->addButton(ui->Key_V, Qt::Key_V);
    this->button_group->addButton(ui->Key_W, Qt::Key_W);
    this->button_group->addButton(ui->Key_X, Qt::Key_X);
    this->button_group->addButton(ui->Key_Y, Qt::Key_Y);
    this->button_group->addButton(ui->Key_Z, Qt::Key_Z);

    this->button_group->addButton(ui->Key_Space, Qt::Key_Space);
    this->button_group->addButton(ui->Key_Enter, Qt::Key_Enter);
    // this->button_group->addButton(ui->Key_Escape, Qt::Key_Escape);
    this->button_group->addButton(ui->Key_Period, Qt::Key_Period);
    this->button_group->addButton(ui->Key_CapsLock, Qt::Key_CapsLock);
    this->button_group->addButton(ui->Key_Backspace, Qt::Key_Backspace);
    this->button_group->addButton(ui->Key_Minus, Qt::Key_Minus);
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      按键功能
******************************************************************************/
void w_Keyb::ButtonJudge(int id)
{
    switch (id)  {
    case Qt::Key_0 :
        emit this->SendString("0");
        break;
    case Qt::Key_1 :
        emit this->SendString("1");
        break;
    case Qt::Key_2 :
        emit this->SendString("2");
        break;
    case Qt::Key_3 :
        emit this->SendString("3");
        break;
    case Qt::Key_4 :
        emit this->SendString("4");
        break;
    case Qt::Key_5 :
        emit this->SendString("5");
        break;
    case Qt::Key_6 :
        emit this->SendString("6");
        break;
    case Qt::Key_7 :
        emit this->SendString("7");
        break;
    case Qt::Key_8 :
        emit this->SendString("8");
        break;
    case Qt::Key_9 :
        emit this->SendString("9");
        break;

    case Qt::Key_A :
        emit this->SendString("a");
        break;
    case Qt::Key_B :
        emit this->SendString("b");
        break;
    case Qt::Key_C :
        emit this->SendString("c");
        break;
    case Qt::Key_D :
        emit this->SendString("d");
        break;
    case Qt::Key_E :
        emit this->SendString("e");
        break;
    case Qt::Key_F :
        emit this->SendString("f");
        break;
    case Qt::Key_G :
        emit this->SendString("g");
        break;
    case Qt::Key_H :
        emit this->SendString("h");
        break;
    case Qt::Key_I :
        emit this->SendString("i");
        break;
    case Qt::Key_J :
        emit this->SendString("j");
        break;
    case Qt::Key_K :
        emit this->SendString("k");
        break;
    case Qt::Key_L :
        emit this->SendString("l");
        break;
    case Qt::Key_M :
        emit this->SendString("m");
        break;
    case Qt::Key_N :
        emit this->SendString("n");
        break;
    case Qt::Key_O :
        emit this->SendString("o");
        break;
    case Qt::Key_P :
        emit this->SendString("p");
        break;
    case Qt::Key_Q :
        emit this->SendString("q");
        break;
    case Qt::Key_R :
        emit this->SendString("r");
        break;
    case Qt::Key_S :
        emit this->SendString("s");
        break;
    case Qt::Key_T :
        emit this->SendString("t");
        break;
    case Qt::Key_U :
        emit this->SendString("u");
        break;
    case Qt::Key_V :
        emit this->SendString("v");
        break;
    case Qt::Key_W :
        emit this->SendString("w");
        break;
    case Qt::Key_X :
        emit this->SendString("x");
        break;
    case Qt::Key_Y :
        emit this->SendString("y");
        break;
    case Qt::Key_Z :
        emit this->SendString("z");
        break;

    case Qt::Key_Space :
        emit this->SendString(" ");
        break;
    case Qt::Key_Period:
        emit this->SendString(".");
        break;
    case Qt::Key_Minus:
        if (CapS) {
            emit this->SendString("_");
        } else {
            emit this->SendString("-");
        }
        break;
    case Qt::Key_Enter :
        emit this->SendEnter();
        emit this->SendEscape();
        break;
    case Qt::Key_Escape :
        emit this->SendEscape();
        break;
    case Qt::Key_Backspace :
        emit this->SendBackspace();
        break;
    case Qt::Key_CapsLock:
        emit this->SendCapsLock();
        if (CapS) {
            emit ui->Key_Minus->setText("-");
        } else {
            emit ui->Key_Minus->setText("_");
        }
        break;
    default:
        emit this->SendString("wrong");
        break;
    }
}

void w_Keyb::Caps(bool set)
{
    if (set) {
        CapS = true;
        ui->Key_CapsLock->setText(tr("大写"));
    } else {
        CapS = false;
        ui->Key_CapsLock->setText(tr("小写"));
    }
}

void w_Keyb::updatePos()
{
    int mouse_y = QCursor::pos().y(); // 鼠标点击处纵坐标
    if (mouse_y > 300) {
        this->move(41, 0);
    } else {
        this->move(41, 600 - 240);
    }
}

/******************************************************************************
                                    END
******************************************************************************/
