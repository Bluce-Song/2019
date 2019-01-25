/*******************************************************************************
 * Copyright [2016]   <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     2.0.7.1
 * author:      sl
 * brief:       头文件
*******************************************************************************/
#include "password.h"
#include "ui_password.h"

PassWord::PassWord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PassWord)
{
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint); // 去掉标题栏
    ui->setupUi(this);

    QPalette palette;
    QColor color(190, 230, 250);
    color.setAlphaF(0.0);
    palette.setBrush(this->backgroundRole(), color);
    this->setPalette(palette);

    // 如果这个QWidget直接show，是有背景色的，但是如果放到一个父Widget中时，它就没有了效果。添加如下代码后就可以了：
    this->setAutoFillBackground(true);
    ui->frame->hide();
    ui->frame_2->hide();
}

PassWord::~PassWord()
{
    delete ui;
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.5.5
  * brief:      密码取消按键
******************************************************************************/
void PassWord::on_Cancle_Button_clicked()
{
    qDebug() << "PassWord::Password_Check" << Password_Check;
    switch (Password_Check) {
    case Password_Syst:
        Singal_pass_to_main(wMain_Surface, 1);
        break;
    case Password_Debug:
        Singal_pass_to_main(wSyst_Surface, 1);
        break;
    case Password_Conf:
        Singal_pass_to_main(wTest_Surface, 1);
        break;
    default:
        break;
    }
    ui->PwdLineEdit->clear();
    ui->PwdLineEdit_new->clear();
    ui->PwdLineEdit_old->clear();
    ui->PwdLineEdit_newc->clear();
    ui->frame->hide();
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.5.5
  * brief:      密码确定按键
******************************************************************************/
void PassWord::on_Ok_Button_clicked()
{
    int Error_Flag = 0;
    qDebug() << "Password_Check" << Password_Check \
             << "ui->PwdLineEdit->text()" << ui->PwdLineEdit->text();
    switch (Password_Check) {
    case Password_Syst: //  进入配置系统界面
        if ((Password.Syst == ui->PwdLineEdit->text()) || \
                ("AIP9918" == ui->PwdLineEdit->text())) {
            Singal_pass_to_main(wSyst_Surface, 1);
        } else {
            Error_Flag = 1;
        }
        break;
    case Password_Debug: //  进入调试界面
        if ((Password.Debug == ui->PwdLineEdit->text()) || \
                ("AIP9918" == ui->PwdLineEdit->text())) {
            Singal_pass_to_main(wDebug_Surface, 1);
        }   else {
            Error_Flag = 1;
        }
        break;
    case Password_Conf: //  进入配置调试参数界面
        if (Password.Conf == ui->PwdLineEdit->text()) {
            Singal_pass_to_main(wConf_Surface, 1);
        }   else {
            Error_Flag = 1;
        }
        break;
    default:
        break;
    }
    ui->PwdLineEdit->clear();   //  密码输入对话框清空
    if (Error_Flag == 1) {
        QMessageBox message;
        message.setWindowFlags(Qt::FramelessWindowHint);
        message.setStyleSheet
                ("QMessageBox{border: gray;border-radius: 10px;"\
                 "padding:2px 4px;background-color: gray;}");
        message.setText(tr("       密码错误     \n       请重新输入    "));
        message.addButton(QMessageBox::Ok)->setStyleSheet
                ("height:39px;width:75px;border:5px groove;border:none;"\
                 "border-radius:10px;padding:2px 4px;");
        message.setButtonText(QMessageBox::Ok, QString(tr("确 定")));
        message.setIcon(QMessageBox::Warning);
        message.exec();
    }
    ui->frame->hide();
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.5.5
  * brief:      修改密码取消按键
******************************************************************************/
void PassWord::on_MCancel_Button_clicked()
{
    ui->frame->hide();
    ui->PwdLineEdit->clear();
    ui->PwdLineEdit_new->clear();
    ui->PwdLineEdit_old->clear();
    ui->PwdLineEdit_newc->clear();
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.5.5
  * brief:      修改密码按键
******************************************************************************/
void PassWord::on_Make_Button_clicked()
{
    ui->frame->show();
    ui->PwdLineEdit->clear();
    ui->PwdLineEdit_new->clear();
    ui->PwdLineEdit_old->clear();
    ui->PwdLineEdit_newc->clear();
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.5.5
  * brief:      密码修改确定按键
******************************************************************************/
void PassWord::on_MOK_Button_clicked()
{
    int Error_Flag = 0, Success_Flag = 0;
    switch (Password_Check) {
    case Password_Syst:   //  系统修改密码
        if ((Password.Syst == ui->PwdLineEdit_old->text()) || \
                ("AIP9918" == ui->PwdLineEdit_old->text())) {
            if ((ui->PwdLineEdit_new->text() == ui->PwdLineEdit_newc->text()) && \
                    (ui->PwdLineEdit_new->text() != NULL)) {
                Password.Syst = ui->PwdLineEdit_new->text();
                Success_Flag = 1;
            } else {
                Error_Flag = 2;
            }
        } else {
            Error_Flag = 1;
        }
        break;
    case Password_Debug:   //  调试修改密码
        if ((Password.Debug == ui->PwdLineEdit_old->text()) || \
                ("AIP9918" == ui->PwdLineEdit->text())) {
            if ((ui->PwdLineEdit_new->text() == ui->PwdLineEdit_newc->text()) && \
                    (ui->PwdLineEdit_new->text() != NULL)) {
                Password.Debug = ui->PwdLineEdit_new->text();
                Success_Flag = 1;
            } else {
                Error_Flag = 2;
            }
        }  else {
            Error_Flag = 1;
        }
        break;
    case Password_Conf:   //  配置修改密码
        if ((Password.Conf == ui->PwdLineEdit_old->text()) || \
                ("AIP9918" == ui->PwdLineEdit_old->text())) {
            if (ui->PwdLineEdit_new->text() == ui->PwdLineEdit_newc->text()) {
                Password.Conf = ui->PwdLineEdit_new->text();
                Success_Flag = 1;
            } else {
                Error_Flag = 2;
            }
        } else {
            Error_Flag = 1;
        }
        break;
    default:
        break;
    }
    ui->PwdLineEdit_new->clear();
    ui->PwdLineEdit_old->clear();
    ui->PwdLineEdit_newc->clear();
    if (Error_Flag == 1) {
        QMessageBox *message = new QMessageBox(this);
        message->setWindowFlags(Qt::FramelessWindowHint);
        message->setStyleSheet("QMessageBox{border: gray;border-radius: 10px;"\
                               "padding:2px 4px;background-color: gray;}");
        message->setText(tr("       旧密码错误     \n       请重新输入    "));
        message->addButton(QMessageBox::Ok)->setStyleSheet
                ("height:39px;width:75px;border:5px groove;border:none;"\
                 "background-color: rgb(63, 63, 63);border-radius:10px;padding:2px 4px;");
        message->setButtonText(QMessageBox::Ok, QString(tr("确 定")));
        message->setIcon(QMessageBox::Warning);
        message->exec();
    }
    if (Error_Flag == 2) {
        QMessageBox *message = new QMessageBox(this);
        message->setWindowFlags(Qt::FramelessWindowHint);
        message->setStyleSheet("QMessageBox{border: gray;border-radius: 10px;"\
                               "padding:2px 4px;background-color: gray;}");
        message->setText(tr("    新密码输入不一致     \n       请重新输入    "));
        message->addButton(QMessageBox::Ok)->setStyleSheet
                ("height:39px;width:75px;border:5px groove;border:none;"\
                 "background-color: rgb(63, 63, 63);border-radius:10px;padding:2px 4px;");
        message->setButtonText(QMessageBox::Ok, QString(tr("确 定")));
        message->setIcon(QMessageBox::Warning);
        message->exec();
    }
    if (Success_Flag == 1) {
        ui->frame->hide();
        QMessageBox *message = new QMessageBox(this);
        message->setAttribute(Qt::WA_DeleteOnClose);
        QTimer::singleShot(888, message, SLOT(accept()));

        message->setWindowFlags(Qt::FramelessWindowHint);
        message->setStyleSheet
                ("QMessageBox{border: gray;border-radius: 10px;"\
                 "padding:2px 4px;background-color: gray;}");
        message->setText(tr("      修改成功     "));
        message->addButton(QMessageBox::Ok)->setStyleSheet
                ("height:39px;width:75px;border:5px groove"\
                 ";border:none;background-color: rgb(63, 63, 63);"\
                 "border-radius:10px;padding:2px 4px;");
        message->setButtonText(QMessageBox::Ok, QString(tr("确 定")));
        message->setIcon(QMessageBox::Warning);
        message->exec();
        //   emit Signal_MakePassword();
        Singal_pass_to_main(2, 2);
    }
}

/******************************************************************************
  * version:    1.0
  * author:     sl
  * date:       2016.6.7
  * brief:      修改密码是否显示
******************************************************************************/
void PassWord::CheckDisplay(int Window)
{
    if (Window == 1) {  // 系统设置界面  取消修改密码
        ui->Make_Button->hide();
    } else {
        ui->Make_Button->show();
    }
}


