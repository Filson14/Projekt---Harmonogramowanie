#ifndef STATISTICSPLOTWIDGET_H
#define STATISTICSPLOTWIDGET_H

#include <QWidget>
#include "qcustomplot.h"

class StatisticsPlotWidget : public QCustomPlot
{
    Q_OBJECT
public:
    explicit StatisticsPlotWidget(QWidget *parent = 0);

signals:

public slots:

};

#endif // STATISTICSPLOTWIDGET_H
