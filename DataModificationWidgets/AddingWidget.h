#ifndef ADDINGWIDGET_H
#define ADDINGWIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QSlider>
#include <QSpinBox>
#include "../DataModification/Database.h"
#include "../Chromosom.h"

class AddingWidget : public QWidget
{
    Q_OBJECT

private:
    QComboBox *jobCombo;
    QComboBox *machineCombo;
    QSpinBox *durationSpin;
public:
    explicit AddingWidget(QWidget *parent = 0);

signals:
    void dataChanged();
public slots:
    void fillMachinesCombo();
    void fillJobsCombo();
    void addJob();
    void addMachine();
    void addTask();
};

#endif // ADDINGWIDGET_H
