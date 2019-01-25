/********************************************************************************
** Form generated from reading UI file 'bemf.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BEMF_H
#define UI_BEMF_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BEMF
{
public:
    QLabel *label;

    void setupUi(QWidget *BEMF)
    {
        if (BEMF->objectName().isEmpty())
            BEMF->setObjectName(QString::fromUtf8("BEMF"));
        BEMF->resize(800, 600);
        label = new QLabel(BEMF);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(165, 200, 451, 101));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(BEMF);

        QMetaObject::connectSlotsByName(BEMF);
    } // setupUi

    void retranslateUi(QWidget *BEMF)
    {
        BEMF->setWindowTitle(QApplication::translate("BEMF", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BEMF", "\345\217\215\347\224\265\345\212\250\345\212\277", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BEMF: public Ui_BEMF {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BEMF_H
