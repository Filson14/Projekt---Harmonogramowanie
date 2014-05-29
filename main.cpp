#include <QApplication>
#include "./GUI/mainwindow.h"
#include "./Controller/controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Chromosom::getJobDatabase().readFromFile("/Users/Wojtek/Documents/Projekty/Projekt-Harmonogramowanie/TestData/test4.txt");
    Chromosom::setJobCount(Chromosom::getJobDatabase().getJobsAmount());
    Chromosom::setMachineCount(Chromosom::getJobDatabase().getMachinesAmount());
    Algorithm * alg = new Algorithm();
    //Baza danych *.
    MainWindow w;
    Controller controller(alg, w.ui->mAlgorithmWidget, w.ui->mStatisticWidget);
    w.show();

    return a.exec();
}

