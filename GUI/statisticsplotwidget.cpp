#include "statisticsplotwidget.h"

StatisticsPlotWidget::StatisticsPlotWidget(QWidget *parent) : QCustomPlot(parent)
{
    QVector<double> x(250), y0(250), y1(250);
    for (int i=0; i<250; ++i)
    {
    x[i] = i;
    y0[i] = exp(-i/150.0)*cos(i/10.0);
    y1[i] = 1.5 - (int)i/100;
    }

    this->xAxis->setLabel("Epoch");
    this->yAxis->setLabel("Fitness");
    this->yAxis->setAutoTickLabels(false);

    // create graph and assign data to it:
    this->addGraph();
    this->graph(0)->setPen(QPen(Qt::red));
    this->graph(0)->setData(x, y0);
    this->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    this->graph(0)->rescaleAxes();
    this->graph(0)->setName("Population");

    this->addGraph();
    this->graph(1)->setData(x, y1);
    this->graph(1)->rescaleAxes();
    this->graph(1)->setName("Best");

    this->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    this->replot();
    this->setFixedHeight(200);
    this->setFixedWidth(300);
}
