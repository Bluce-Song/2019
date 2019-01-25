/*******************************************************************************
 * Copyright [2016]   <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     2.0.7.1
 * author:      sl
 * brief:       头文件
*******************************************************************************/
#include "w_help.h"
#include "ui_w_help.h"
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.12
  * brief:      单击开始
******************************************************************************/
w_Help::w_Help(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::w_Help)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint); // 去掉标题栏
    this->setWindowFlags(Qt::FramelessWindowHint); //
    name << "main" << "syst" << "model" << "data" << "test" \
         << " " << " " << "color" << "conf" << "debug" << "main" \
         << "conf" << "dlr" << "mag" << "ir" << "acw" << "" << "imp" \
         << "pwr" << "indr" << "block" << "lvs";
    ui->textEdit->setReadOnly(true);
    ui->pushButton->hide();  ui->pushButton_up->hide(); ui->pushButton_down->hide();
    ui->DLabel05->hide();
    Picture_count = 1;
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.12
  * brief:      单击开始
******************************************************************************/
w_Help::~w_Help()
{
    delete ui;
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.12
  * brief:      单击开始
******************************************************************************/
void w_Help::updateText(int win, int index)
{
    ui->DLabel05->hide();
    ui->pushButton->hide();  ui->pushButton_up->hide(); ui->pushButton_down->hide();
    if (win != 5) {
        cWin = win;
        if (win == 8) {
            win = 11 + index;
        }
        switch (win) {
        case 0:
            ui->Label_Display->setText(tr("主界面帮助"));
            Picture_count = 1;
            ui->pushButton->show();
            ui->pushButton_up->show();
            ui->pushButton_down->show();
            break;
        case 1:
            ui->Label_Display->setText(tr("系统设置帮助"));
            break;
        case 2:
            ui->Label_Display->setText(tr("型号管理帮助"));
            break;
        case 3:
            ui->Label_Display->setText(tr("数据管理帮助"));
            break;
        case 4:
            ui->Label_Display->setText(tr("测试界面帮助"));
            break;
        case 7:
            ui->Label_Display->setText(tr("颜色界面帮助"));
            break;
        case 8:
            ui->Label_Display->setText(tr("设置界面帮助"));
            break;
        case 9:
            ui->Label_Display->setText(tr("调试界面帮助"));
            break;
        case 10:
            ui->Label_Display->setText(tr("主界面帮助"));
            break;
        default:
            //
            break;
        }
        if (win >= name.size())
            win = name.size() - 1;
        QString Path;
        if (ui->Key_A->text() == "返回")
            Path = QString("/mnt/nandflash/AIP/help-ch/%1.txt").arg(name[win]);
        else
            Path = QString("/mnt/nandflash/AIP/help-en/%1.txt").arg(name[win]);

        QFile file(Path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            ui->textEdit->setText("  ");
            return;
        } else {
            QTextStream in(&file);
            in.setCodec(QTextCodec::codecForName("UTF-8"));
            QString Test = in.readAll();
            ui->textEdit->setText(Test);
        }
    }
}
/******************************************************************************
                                    END
******************************************************************************/

void w_Help::on_Key_A_clicked()
{
    sendData(cWin);
    this->hide();
}

void w_Help::on_pushButton_clicked()
{
    if (ui->pushButton->text() == QString(tr("计量图片"))) {
        ui->pushButton->setText(tr("隐藏"));
        ui->DLabel05->show();
        ui->pushButton_up->show();
        ui->pushButton_down->show();

        ui->DLabel05->clear();
        QPixmap *pixmap;
        pixmap = new QPixmap(QString("/mnt/nandflash/AIP/Model/%1.jpg").arg(Picture_count));
        ui->DLabel05->setPixmap(*pixmap);
    } else if (ui->pushButton->text() == QString(tr("隐藏"))) {
        ui->pushButton->setText(tr("计量图片"));
        ui->DLabel05->hide();
        ui->pushButton_up->hide();
        ui->pushButton_down->hide();
    } else {
        //
    }
}

void w_Help::on_pushButton_down_clicked()
{
    Picture_count++;
    if (Picture_count >= 5) {
        Picture_count = 5;
    }
    QPixmap *pixmap;
    pixmap = new QPixmap(QString("/mnt/nandflash/AIP/Model/%1.jpg").arg(Picture_count));
    ui->DLabel05->setPixmap(*pixmap);
}

void w_Help::on_pushButton_up_clicked()
{
    Picture_count--;
    if (Picture_count <= 1) {
        Picture_count = 1;
    }
    QPixmap *pixmap;
    pixmap = new QPixmap(QString("/mnt/nandflash/AIP/Model/%1.jpg").arg(Picture_count));
    ui->DLabel05->setPixmap(*pixmap);
}
