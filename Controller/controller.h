#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "./Algorithm/Algorithm.h"
#include "./Algorithm/SettingsStructures.h"
#include "./GUI/settingswidget.h"
#include "./GUI/statisticswidget.h"


class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(Algorithm * algorithm, SettingsWidget * settingsWidget, StatisticsWidget * statisticsWidget, QObject *parent = 0);

signals:

public slots:
    void runAlgorithm();
    void updateBestChromosom();
    void updateStatistics();

private:
    Algorithm * algorithm;
    SettingsWidget * settingsWidget;
    StatisticsWidget * statisticsWidget;


};

#endif // CONTROLLER_H
