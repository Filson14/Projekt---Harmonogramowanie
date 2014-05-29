#include "controller.h"

Controller::Controller(Algorithm * algorithm, SettingsWidget * settingsWidget, StatisticsWidget * statisticsWidget, QObject *parent) : QObject(parent)
{
    this->algorithm = algorithm;
    this->settingsWidget = settingsWidget;
    this->statisticsWidget = statisticsWidget;

    connect(settingsWidget, SIGNAL(runAlgorithm()), this, SLOT(runAlgorithm()));
    connect(settingsWidget, SIGNAL(runAlgorithm()), statisticsWidget, SLOT(clearStatistics()));
    connect(algorithm, SIGNAL(newBestChromosom()), this, SLOT(updateBestChromosom()));
    connect(algorithm, SIGNAL(newStatistics(const AlgorithmStatistics &)), statisticsWidget, SLOT(updateStatistics(const AlgorithmStatistics &)));
}

void Controller::runAlgorithm()
{
    AlgorithmSettings settings;
    this->settingsWidget->fetchSettings(settings);
    settings.crossoverOperator = new CrossoverTwoPoint();
    settings.mutationOperator = new MutationInversion();
    settings.selectionOperator = new SelectionTournament(0.7, 3);

    algorithm->updateSettings(settings);
    algorithm->runAlgorithm();
}

void Controller::updateBestChromosom()
{
    printf("newBestChromosom signal recieved, I'm on it.\n");
    fflush(NULL);
}

void Controller::updateStatistics()
{
    AlgorithmStatistics statistics;
    algorithm->fetchStatistics(statistics);
    statisticsWidget->updateStatistics(statistics);

    printf("newStatistics signal recieved, I'm on it.\n");
    fflush(NULL);
}
