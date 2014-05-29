#include "controller.h"

Controller::Controller(Algorithm * algorithm, MainWindow * window, Database * database, QObject *parent) : QObject(parent)
{
    this->algorithm = algorithm;
    this->database = database;
    this->settingsWidget = window->ui->mAlgorithmWidget;
    this->statisticsWidget = window->ui->mStatisticWidget;
    this->blockPlotWidget = window->ui->mBlockPlot;


    connect(settingsWidget, SIGNAL(runAlgorithm()), statisticsWidget, SLOT(clearStatistics()));
    connect(settingsWidget, SIGNAL(runAlgorithm()), window, SLOT(onRunAlgorithm()));
    connect(settingsWidget, SIGNAL(runAlgorithm()), this, SLOT(runAlgorithm()));
    connect(algorithm, SIGNAL(newBestChromosom(Database*)), blockPlotWidget, SLOT(onDataChanged(Database*)));
    connect(algorithm, SIGNAL(newStatistics(const AlgorithmStatistics &)), statisticsWidget, SLOT(updateStatistics(const AlgorithmStatistics &)));
}

void Controller::runAlgorithm()
{
    AlgorithmSettings settings;
    this->settingsWidget->fetchSettings(settings);
    settings.crossoverOperator = new CrossoverTwoPoint();
    settings.mutationOperator = new MutationSwappingPoint();
    settings.selectionOperator = new SelectionRoulette();

    algorithm->updateSettings(settings);
    algorithm->runAlgorithm();
}

void Controller::updateBestChromosom()
{
    printf("newBestChromosom signal recieved, I'm on it.\n");
    fflush(NULL);
}

