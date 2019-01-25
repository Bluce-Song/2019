/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "wt_wave.h"

wt_Wave::wt_Wave(QWidget *parent) :
    QLabel(parent) {
    int i;
    for (i = 0; i < 1000; i++) {
        point[i] = 0;
    }
    num = 0;
    IMPFlag = 0;
    IMP_X = 0;
    IMP_Y = 0;
    IMP_Point = 1;
    Block_Point = 0;
    Red_line = 10;
    Green_line = 10;
    Test_Shape = 0;
    IMPBigShape_Flag = 0;
    TestShape_Flag = 0;

    //   connect(this,SIGNAL(SET_IMP(int)),WIMP,SLOT(buttonJudge(int)));
    //   QPalette palette;
    //   palette.setBrush(this->backgroundRole(),QBrush(QColor(0,0,0,255),Qt::SolidPattern));
    //   this->setPalette(palette);
    //   this->setAutoFillBackground(true);
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.05
  * brief:      绘制label
******************************************************************************/
void wt_Wave::paintEvent(QPaintEvent *)
{
    int i, k;
    int px[width()];
    // QPalette palette = this->palette();
    // palette.setBrush(this->backgroundRole(),QBrush(QColor(0,0,0,255),Qt::SolidPattern));
    // this->setPalette(palette);

    QPainter *painter = new QPainter(this);
    painter->setPen(QPen(Qt::darkGreen, 1, Qt::DotLine));

    //横线
    painter->drawLine(QPoint(0, height()*3/4), QPoint(width(), height()*3/4));
    painter->drawLine(QPoint(0, height()*2/4), QPoint(width(), height()*2/4));
    painter->drawLine(QPoint(0, height()*1/4), QPoint(width(), height()*1/4));

    //坚线
    painter->drawLine(QPoint(width()*1/4, 0), QPoint(width()*1/4, height()));
    painter->drawLine(QPoint(width()*2/4, 0), QPoint(width()*2/4, height()));
    painter->drawLine(QPoint(width()*3/4, 0), QPoint(width()*3/4, height()));

    if (num > 0) {
        if (IMPFlag == 1) {
            painter->setPen(QPen(Qt::green, 1, Qt::SolidLine));
            painter->drawLine(QPoint(Red_line, 0), QPoint(Red_line, height()));
            // painter->drawText(150, 20, QString::number(IMP_PP));
            painter->setPen(QPen(Qt::red, 1, Qt::SolidLine));
            painter->drawLine(QPoint(Green_line, 0), QPoint(Green_line, height()));   //*/
        } else if (IMPBigShape_Flag == 1) {
            painter->setPen(QPen(Qt::green, 1, Qt::SolidLine));
            painter->drawLine(QPoint(0, height()-1), QPoint(width(), height()-1));
            painter->drawLine(QPoint(0, 1), QPoint(width(), 1));
            painter->drawLine(QPoint(1, 0), QPoint(1, height()));
            painter->drawLine(QPoint(width()-1, 0), QPoint(width()-1, height()));

            painter->setPen(QPen(Qt::green,  1, Qt::SolidLine));
            painter->drawLine(QPoint(Red_line, 0), QPoint(Red_line, height()));
            painter->setPen(QPen(Qt::red, 1, Qt::SolidLine));
            painter->drawLine(QPoint(Green_line, 0), QPoint(Green_line, height()));   //*/

            painter->setPen(QPen(Qt::green, 1, Qt::SolidLine));
            //   painter->drawText(550, 35, "峰值"+QString::number(IMP_PP));
            painter->drawText(385, 35, QString(tr("频率"))+QString::number(IMP_Fre));
            painter->drawText(250, 35, IMP_string);
            painter->drawText(Red_line, 200, QString::number(Red_line));
            painter->drawText(Green_line-30, 220, QString::number(Green_line));
        } else if (TestShape_Flag == 1) {
            painter->setPen(QPen(Qt::green,  1, Qt::SolidLine));
            painter->drawText(385, 35, Test_string);
        }
        if (Test_Shape) {
            painter->drawText(150, 20, QString::number(Test_IMP_PP));
        } else {
            painter->drawText(150, 20, "");
        }



        for (i = 0; i < width(); i++) {
            px[i] = height() - point[i*num/width()]*height()/255;
        }
        if (IMP_Point == 1) {
            painter->setPen(QPen(Qt::white, 1, Qt::SolidLine));
            for (i = 0; i < width() - 1; i++) {
                painter->drawLine(QPoint(i, px[i]), QPoint(i + 1, px[i + 1]));
            }
        } else if (Block_Point == 1) {
            painter->setPen(QPen(Qt::white, 1, Qt::SolidLine));
            for (i = 0; i < num; i++) {
                Block_Save_Point.append(QString::number(px[i*width()/num]));
                painter->drawPoint(i*width()/num, px[i*width()/num]);
            }
            for (k = 0; k < Block_Save_Point.size()/num - 1; k++) {
                for (i = 0; i < num; i++) {
                    painter->drawPoint(i*width()/num, Block_Save_Point.at(i + k*num).toInt());
                }
            }
        } else {
            painter->setPen(QPen(Qt::blue, 1, Qt::DotLine));
            for (i = 0; i < width() - 1; i++) {
                painter->drawPoint(QPoint(i, px[i]));
            }
        }

        for (i = 0; i < width(); i++) {
            px[i] = height()-pointgreen[i*num/width()]*height()/255;
        }
        painter->setPen(QPen(Qt::green, 1, Qt::SolidLine));
        for (i = 0; i < width() - 1; i++) {
            painter->drawLine(QPoint(i, px[i]), QPoint(i + 1, px[i + 1]));
        }
    }
    painter->end();
}

void wt_Wave::mousePressEvent(QMouseEvent *ev)
{
    if (IMPFlag == 1) {
        this->update();
        emit SET_IMP((ev->globalY()-30)/64, 1);
    } else if (IMPBigShape_Flag == 1) {
        if ((ev->x())/(width()/2)) {
            Green_line = ev->x();
            if (Green_line > (width() - 20))
                Green_line = width() - 20;
            else
                Green_line = ev->x();
            this->update();
            SET_Point(Green_line, 1, (Green_line)*200/width());
        } else {
            Red_line = ev->x();
            if (Red_line < 20)
                Red_line = 20;
            this->update();
            SET_Point(Red_line, 2, Red_line*200/width());
        }
    } else if (TestShape_Flag == 1) {
        this->hide();
        SET_Free();
    }
}

/******************************************************************************
                                    END
******************************************************************************/

