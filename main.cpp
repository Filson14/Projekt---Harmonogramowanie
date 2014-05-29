#include <QApplication>
#include "./GUI/mainwindow.h"
#include "./Controller/controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Chromosom::getJobDatabase().readFromFile("/Users/Wojtek/Documents/Projekty/Harmonogramowanie/TestData/test1.txt");
    Chromosom::setJobCount(Chromosom::getJobDatabase().getJobsAmount());
    Chromosom::setMachineCount(Chromosom::getJobDatabase().getMachinesAmount());
    Algorithm * alg = new Algorithm();
    MainWindow w;
    Controller controller(alg, w.setWidget, w.statWidget);
    w.show();

    return a.exec();
}

