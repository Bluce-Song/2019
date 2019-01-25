/*******************************************************************************
 * Copyright [2016]   <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     2.1.0.170427
 * author:      zhaonanlin
 * brief:       柱状图
*******************************************************************************/
#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <QDebug>
#include <QLabel>
#include <QWidget>
#include <QPainter>
#include <QHash>
#include <QPaintEvent>

class Histogram : public QLabel
{
    Q_OBJECT
public:
    explicit Histogram(QWidget *parent = 0);

public slots:
    void setNames(QStringList msg);
    void setValues(QStringList msg);

private slots:
    virtual void paintEvent(QPaintEvent *);

private:
    QList<QColor> Colors;
    QStringList Names;
    QList<quint16> Values;
    quint16 Max;
};

#endif // _HOME_SL_MASTER_AIP_AIPDEBUG_EXTERNAL_INTERFACE_HISTOGRAM_H
