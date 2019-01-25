/********************************************************************************
** Form generated from reading UI file 'pwr_picture.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PWR_PICTURE_H
#define UI_PWR_PICTURE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pwr_picture
{
public:
    QLabel *label_2;
    QLabel *label;

    void setupUi(QWidget *pwr_picture)
    {
        if (pwr_picture->objectName().isEmpty())
            pwr_picture->setObjectName(QString::fromUtf8("pwr_picture"));
        pwr_picture->resize(800, 600);
        label_2 = new QLabel(pwr_picture);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 455, 567));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/image/pwr1.JPG")));
        label = new QLabel(pwr_picture);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(470, 20, 320, 572));
        label->setPixmap(QPixmap(QString::fromUtf8(":/image/pwr2.JPG")));

        retranslateUi(pwr_picture);

        QMetaObject::connectSlotsByName(pwr_picture);
    } // setupUi

    void retranslateUi(QWidget *pwr_picture)
    {
        pwr_picture->setWindowTitle(QApplication::translate("pwr_picture", "\347\224\265\345\217\202\350\207\252\345\212\250\350\260\203\350\257\225\346\216\245\347\272\277\345\233\276", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class pwr_picture: public Ui_pwr_picture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PWR_PICTURE_H
