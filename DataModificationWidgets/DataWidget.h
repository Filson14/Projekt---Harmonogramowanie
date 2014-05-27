#ifndef DATAWIDGET_H
#define DATAWIDGET_H

#include <QWidget>
#include "AddingWidget.h"
#include "EditingWidget.h"
#include "DeletingWidget.h"

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
    void dataChanged();
private slots:
    void loadDataFromFile();
    void saveDataToFile();
    void generateRandomData();
    void emitChangeSignal();
    void updateWidgets();

};

#endif // DATAWIDGET_H
