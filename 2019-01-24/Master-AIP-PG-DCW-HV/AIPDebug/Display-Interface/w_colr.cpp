/*******************************************************************************
 * Copyright (c) 2016,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2016.01.20
 * brief:       颜色选择界面
*******************************************************************************/
#include "w_colr.h"
#include "ui_w_colr.h"
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.01.20
  * brief:      颜色选择界面初始化
******************************************************************************/
const QColor colorset[2][7] = {
    {
        QColor(255, 255, 255, 255), QColor(240, 78, 153, 255), QColor(254, 69, 52, 255),
        QColor(106, 231, 71, 255), QColor(49, 134, 17, 255), QColor(246, 254, 0, 255),
        QColor(255, 0, 0, 255),
    },
    {
        QColor(120, 120, 120, 255), QColor(249, 121, 0, 255), QColor(0, 0, 0, 255),
        QColor(128, 64, 0, 255), QColor(105, 0, 128, 255), QColor(64, 0, 124, 255),
        QColor(46, 48, 146, 255),
    },
};
w_Colr::w_Colr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::w_Colr)
{
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint); // 去掉标题栏
    ui->setupUi(this);
    //   cWin = 0;

    int i = 0, j = 0;
    QString str;
    Color_Group = new QButtonGroup;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 7; j++) {
            btnList.append(new QToolButton(this));      // 创建按钮
            str = QString("border:3px groove white;border-radius:10px;"\
                          "height:90px;width:90px;background-color:%1").arg(colorset[i][j].name());
            btnList[i*7+j]->setStyleSheet(str);

            Color_Group->addButton(btnList[i*7 + j], i*7 + j);          // 添加按钮

            ui->colorLayout->addWidget(btnList[i*7 + j], i, j); // 添加布局
        }
    }
    connect(Color_Group, SIGNAL(buttonClicked(int)), this, SLOT(ButtonJudge(int)));
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.01.20
  * brief:      颜色选择界面析构
******************************************************************************/
w_Colr::~w_Colr()
{
    delete Color_Group;
    delete ui;;
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.01.20
  * brief:      点击按钮,发送颜色信息
******************************************************************************/
void w_Colr::ButtonJudge(int id)
{
    Signal_color_to_Main(colorset[id/7][id%7].name(), 2, 2);
    Signal_color_to_Main(QString(""), wConf_Surface, 1);
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.05.20
  * brief:      返回设置界面
******************************************************************************/
void w_Colr::on_pushButton_clicked()
{
    Signal_color_to_Main(QString(""), wConf_Surface, 1);
}

/******************************************************************************
                                    END
******************************************************************************/
