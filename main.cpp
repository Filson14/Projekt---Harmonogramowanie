#include <QApplication>
#include "./GUI/mainwindow.h"
#include "./Controller/controller.h"


int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    Chromosom::getJobDatabase().readFromFile("/Users/Wojtek/Documents/Projekty/Projekt-Harmonogramowanie/TestData/test1.txt");
    Chromosom::setJobCount(Chromosom::getJobDatabase().getJobsAmount());
    Chromosom::setMachineCount(Chromosom::getJobDatabase().getMachinesAmount());
    Algorithm * alg = new Algorithm();
    MainWindow * win = new MainWindow();
    Controller controller(alg, win, &Chromosom::getJobDatabase());
    win->show();

    return a.exec();
}

