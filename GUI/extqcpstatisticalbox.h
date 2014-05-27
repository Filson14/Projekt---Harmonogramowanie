#ifndef EXTQCPSTATISTICALBOX_H
#define EXTQCPSTATISTICALBOX_H

#include "qcustomplot.h"
#include <QMessageBox>
#include <QString>

class ExtQCPStatisticalBox : public QCPStatisticalBox
{
    Q_OBJECT

public:
    ExtQCPStatisticalBox (QCPAxis *keyAxis, QCPAxis *valueAxis);

public slots:
    void blockinfo(bool);

};

#endif // EXTQCPSTATISTICALBOX_H
