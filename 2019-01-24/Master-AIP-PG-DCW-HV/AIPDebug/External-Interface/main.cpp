/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include <QtGui/QApplication>
#include <QTranslator>
#include <QTextCodec>
#include <QWSServer>
#include <QFile>
// #include <QtDBus/QDBusConnection>

#include "w_main.h"

void myMessageOutput(QtMsgType type, const char *msg) {
    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s\n", msg);
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s\n", msg);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s\n", msg);
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s\n", msg);
        abort(); //-在这里产生中断
    }
}
int main(int argc, char *argv[]) {
    qInstallMsgHandler(myMessageOutput);
    //解决中文显示乱码
    QTextCodec *codec = QTextCodec::codecForName("UTF-8"); // 设置编码方式
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

    QString language;
    QSettings *set_Sys = new QSettings(Sys_path, QSettings::IniFormat);  //  打开系统文本
    set_Sys->setIniCodec("GB18030");
    language = set_Sys->value("language/Text").toString();
    delete set_Sys;

    QApplication a(argc, argv);
    // QWSServer::setCursorVisible(false);//隐藏鼠标

    // 设置字号
    QFont font  = a.font();
    font.setPointSize(15);
    a.setFont(font); /* */


    QTranslator translator;
    if (language == "English") {
        translator.load(":aip.qm");
    } else if (language == "Japan") {
        translator.load(":aipJa.qm");
    } else {
        translator.load("");
    }
    a.installTranslator(&translator);

    QFile file(":/image/abc.qss");
    file.open(QFile::ReadOnly);
    QString qss = QLatin1String(file.readAll());
    a.setStyleSheet(qss);
    a.setPalette(QPalette(QColor("#F0F0F0")));
    // 显示主页
    w_Main w;
    w.show();
    return a.exec();
}

