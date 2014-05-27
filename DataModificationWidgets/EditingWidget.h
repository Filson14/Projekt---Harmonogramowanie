#ifndef EDITINGWIDGET_H
#define EDITINGWIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QSpinBox>

class EditingWidget : public QWidget
{
    Q_OBJECT

private:
    QComboBox *jobCombo;
    QComboBox *taskCombo;
    QComboBox *machineCombo;
    QComboBox *positionCombo;
    QSpinBox *durationSpin;

public:
    explicit EditingWidget(QWidget *parent = 0);

signals:
    void dataChanged();

public slots:
    void fillJobCombo();
    void fillTaskCombo();
    void fillMachineCombo();
    void fillPositionCombo();
    void saveChanges();

};

#endif // EDITINGWIDGET_H
