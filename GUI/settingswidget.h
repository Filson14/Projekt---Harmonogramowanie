#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QCheckBox>
#include "qspinboxenhenced.h"

#define DOUBLE_SPIN_MIN 0.0
#define DOUBLE_SPIN_MAX 1.0
#define DOUBLE_SPIN_STEP 0.05
#define SPIN_MIN 5
#define SPIN_MAX 30000
#define SPIN_STEP 25

class SettingsWidget : public QWidget
{
    Q_OBJECT

private slots:
    void runButtonClicked();


private:
    void getSettings();

    QHBoxLayout *widgetLayout;  //!< Glowny layout widgetu SettingsWidget
    QFormLayout *algorithmGroupLayout;  //!< Layout groupboxa algorithmGroup
    QFormLayout *operatorGroupLayout;   //!< Layout groupboxa operatorGroup
    QFormLayout *populationGroupLayout; //!< Layout groupboxa populationGroup
    QGroupBox *algorithmGroup;  //!< Groupbox przechowuje pola zwiazane z ogolnymi ustawieniami algorytmu
    QGroupBox *operatorGroup;   //!< Groupbox przechowuje pola zwiazane z ustawieniami operatorow
    QGroupBox *populationGroup; //!< Groupbox przechowuje pola zwiazane z ustawieniami populacji
    QLabel *epochCountLabel;    //!<
    QLabel *noImprovementLabel;
    QLabel *repairChromosomLabel;
    QLabel *crossOperatorLabel;
    QLabel *crossProbabilityLabel;
    QLabel *mutOperatorLabel;
    QLabel *mutProbabilityLabel;
    QLabel *selOperatorLabel;
    QLabel *popSizeLabel;
    QLabel *newPopSizeLabel;
    QSpinBox *epochCountEdit;
    QSpinBox *noImprovementEdit;
    QDoubleSpinBox *crossProbabilityEdit;
    QDoubleSpinBox *mutProbabilityEdit;
    QSpinBoxEnhenced *popSizeEdit;
    QSpinBoxEnhenced *newPopSizeEdit;
    QComboBox *crossOperatorBox;
    QComboBox *mutOperatorBox;
    QComboBox *selOperatorBox;
    QCheckBox *repairChromosomCheck;
    QPushButton *runButton;

public:
    explicit SettingsWidget(QWidget *parent = 0);
    ~SettingsWidget();

/*
 * signals:
 *      Deklaracja sygnałów emitowane przez dialog.
 */

 /*
  * slots:
  *     Deklaracja slotów w posiadaniu klasy.
  */

};

#endif // SETTINGSDIALOG_H
