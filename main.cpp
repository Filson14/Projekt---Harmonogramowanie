#include <QApplication>
#include "./GUI/mainwindow.h"
#include "./Controller/controller.h"


int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    Database dt;
    dt.readFromFile("test1.txt");
    Chromosom::setJobDatabase(&dt);
    Algorithm * alg = new Algorithm();
    MainWindow * win = new MainWindow();
    win->setAttribute(Qt::WA_DeleteOnClose, true);
    Controller * controller = new Controller(alg, win, &Chromosom::getJobDatabase());
    win->show();
    a.exec();

    delete controller;
    delete alg;
    return 0;
}

