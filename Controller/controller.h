#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "../DataModificationWidgets/DataWidget.h"
#include "../Algorithm/Algorithm.h"
#include "../Algorithm/SettingsStructures.h"
#include "../GUI/mainwindow.h"
#include "../GUI/blockplot.h"
#include "../DataModification/Database.h"


class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(Algorithm * algorithm, MainWindow * window, Database * database, QObject *parent = 0);

signals:

public slots:
    void runAlgorithm();
    void updateBestChromosom();

private:
    Algorithm * algorithm;
    Database * database;
    SettingsWidget * settingsWidget;
    StatisticsWidget * statisticsWidget;
    BlockPlot * blockPlotWidget;
    DataWidget* dataWidget;


};

#endif // CONTROLLER_H
