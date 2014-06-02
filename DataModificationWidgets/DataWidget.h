#ifndef DATAWIDGET_H
#define DATAWIDGET_H

#include <QWidget>
#include <QObject>
#include "AddingWidget.h"
#include "EditingWidget.h"
#include "DeletingWidget.h"
#include "DataStructure.h"

class DataWidget : public QWidget
{
    Q_OBJECT
private:

    AddingWidget *addWidget;
    EditingWidget *editWidget;
    DeletingWidget *delWidget;

public:
    explicit DataWidget(QWidget *parent = 0);

signals:
    void newDataStructure(DataStructure* );
    void subwidgetsRepaint(Database *);
    void dWRepaintRequest();
private slots:
    void loadDataFromFile();
    void saveDataToFile();
    void generateRandomData();
    void resetDatabase();
    void clearDatabase();
    void onAddJob();
    void onAddMachine();
    void onAddTask(int,int,int);
    void onDeleteJob(int);
    void onDeleteMachine(int);
    void onDeleteTask(int,int);
    void onEditChange(int,int,int,int,int,int);
    void onDWrepaint(Database*);
    void onSubwidgetRepaintRequest();

};

#endif // DATAWIDGET_H
