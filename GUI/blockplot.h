#ifndef BLOCKPLOT_H
#define BLOCKPLOT_H

#include "qcustomplot.h"
#include "../Algorithm/Chromosom.h"
#include "extqcpstatisticalbox.h"
#include <QWidget>
#include <QVector>
#include <QMessageBox>

#define XINT 20

class BlockPlot : public QCustomPlot
{
    Q_OBJECT
private:
    QVector<QColor> cVect;
public:
    explicit BlockPlot(QWidget *parent = 0);
    virtual ~BlockPlot();

signals:


public slots:
    void onDataChanged(Database* );
    void onBlockSelected(bool);


};

#endif // BLOCKPLOT_H
