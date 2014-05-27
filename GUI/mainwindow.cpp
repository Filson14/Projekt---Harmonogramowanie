#include <QWidget>
#include <QTabWidget>
#include <QGridLayout>
#include "settingswidget.h"
#include "statisticswidget.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *window = new QWidget();
    QGridLayout *centralLayout = new QGridLayout();
    SettingsWidget *setWidget = new SettingsWidget();
    //StatisticsPlotWidget *statPlot = new StatisticsPlotWidget(this);
    StatisticsWidget * statWidget = new StatisticsWidget();

    centralLayout->addWidget(setWidget, 1, 1);
    centralLayout->addWidget(statWidget, 2, 1);
    window->setLayout(centralLayout);

    this->setCentralWidget(window);
    this->setWindowTitle("My main window.");
    this->setFixedSize(1200, 700);
}

MainWindow::~MainWindow()
{

}
