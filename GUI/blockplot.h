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
    QVector<QColor> cVect;
    QVector<ExtQCPStatisticalBox*> allSP;
    void clearAllBoxes();
public:
    explicit BlockPlot(QWidget *parent = 0);

signals:

public slots:
    void onDataChanged(Database* );


};

#endif // BLOCKPLOT_H
