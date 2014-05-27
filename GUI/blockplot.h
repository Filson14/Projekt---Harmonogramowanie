#ifndef BLOCKPLOT_H
#define BLOCKPLOT_H

#include "qcustomplot.h"
#include "../Algorithm/Chromosom.h"
#include "extqcpstatisticalbox.h"
#include <QWidget>
#include <QVector>
#include <QMessageBox>

class BlockPlot : public QCustomPlot
{
    Q_OBJECT
private:
    void construct();
    QVector<QColor> cVect;
    QVector<ExtQCPStatisticalBox*> allSP;
public:
    explicit BlockPlot(Chromosom* best=0,QWidget *parent = 0);

signals:

public slots:

};

#endif // BLOCKPLOT_H
