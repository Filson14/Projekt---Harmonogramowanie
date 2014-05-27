#ifndef DELETINGWIDGET_H
#define DELETINGWIDGET_H

#include <QWidget>
#include <QComboBox>

class DeletingWidget : public QWidget
{
    Q_OBJECT

private:
    QComboBox *jobCombo;
    QComboBox *machineCombo;
    QComboBox *taskJobCombo;
    QComboBox *taskMachineCombo;

public:
    explicit DeletingWidget(QWidget *parent = 0);

signals:
    void dataChanged();

public slots:
    void fillJobsCombos();
    void fillMachineCombo();
    void fillTaskMachineCombo();
    void deleteJob();
    void deleteMachine();
    void deleteTask();

};

#endif // DELETINGWIDGET_H
