#include "AddingWidget.h"
#include <QGroupBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QComboBox>
#include <QFormLayout>
#include <QFileDialog>

AddingWidget::AddingWidget(QWidget *parent) :
    QWidget(parent)
{
    jobCombo = new QComboBox();
    machineCombo = new QComboBox();
    durationSpin = new QSpinBox();

    this->setGeometry(0, 0, 500, 200);

    fillJobsCombo();

    durationSpin->setMinimum(0);
    durationSpin->setMaximum(300);

    QObject::connect(jobCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(fillMachinesCombo()));

    QHBoxLayout *mainLayout = new QHBoxLayout();

    QVBoxLayout *leftSide = new QVBoxLayout();
    QVBoxLayout *rightSide = new QVBoxLayout();

    QVBoxLayout *jobLay = new QVBoxLayout();
    QVBoxLayout *machineLay = new QVBoxLayout();

    QGroupBox *jobGrp = new QGroupBox("JOB");
    QGroupBox *machineGrp = new QGroupBox("MACHINE");
    QGroupBox *taskGrp = new QGroupBox("TASK");

    QPushButton *addJobBtn = new QPushButton("ADD");
    QPushButton *addMachineBtn = new QPushButton("ADD");
    QPushButton *addTaskBtn = new QPushButton("ADD");

    QObject::connect(addJobBtn, SIGNAL(clicked()), this, SLOT(addJob()));
    QObject::connect(addMachineBtn, SIGNAL(clicked()), this, SLOT(addMachine()));
    QObject::connect(addTaskBtn, SIGNAL(clicked()), this, SLOT(addTask()));

    QFormLayout *taskLay = new QFormLayout;
    taskLay->addRow(tr("&Job:"), jobCombo);
    taskLay->addRow(tr("&Machine:"), machineCombo);
    taskLay->addRow(tr("&Duration:"), durationSpin);
    taskLay->addWidget(addTaskBtn);

    taskGrp->setLayout(taskLay);

    jobLay->addWidget(addJobBtn);
    machineLay->addWidget(addMachineBtn);

    jobGrp->setLayout(jobLay);
    machineGrp->setLayout(machineLay);

    leftSide->addWidget(jobGrp);
    leftSide->addWidget(machineGrp);

    rightSide->addWidget(taskGrp);

    mainLayout->addLayout(leftSide);
    mainLayout->addLayout(rightSide);

    this->setLayout(mainLayout);

}

void AddingWidget::fillMachinesCombo(){
    machineCombo->clear();
    machineCombo->addItem("Select...");
    durationSpin->setValue(0);
    if(jobCombo->currentIndex()!=0){
        Job &currJob = Chromosom::getJobDatabase().getJobs()[jobCombo->currentText().toInt()];
        vector <Machine*> &allMachines = Chromosom::getJobDatabase().getMachines();
        for(int i=0; i<allMachines.size(); i++){
            if( !currJob.isMachineUsed(allMachines[i]->getId()) )
                machineCombo->addItem(QString::number(allMachines[i]->getId()));
        }
    }
}

void AddingWidget::fillJobsCombo(){
    jobCombo->clear();
    machineCombo->clear();
    jobCombo->addItem("Select...");
    machineCombo->addItem("Select...");
    durationSpin->setValue(0);
    int jobCount = Chromosom::getJobDatabase().getJobsAmount();
    for(int i=0; i<jobCount; i++)
        jobCombo->addItem(QString::number(i));
}

void AddingWidget::addJob(){
    Chromosom::getJobDatabase().addJob();
    fillJobsCombo();
    fillMachinesCombo();
    emit dataChanged();
}

void AddingWidget::addMachine(){
    Chromosom::getJobDatabase().addMachine(Chromosom::getJobDatabase().getMachinesAmount());
    fillJobsCombo();
    fillMachinesCombo();
    emit dataChanged();
}

void AddingWidget::addTask(){
    if(jobCombo->currentIndex()!=0 && machineCombo->currentIndex()!=0){
        Job &selectedJob = Chromosom::getJobDatabase().getJobs()[jobCombo->currentText().toInt()];
        Machine* selectedMachine = Chromosom::getJobDatabase().getMachine(machineCombo->currentText().toInt());
        int duration = durationSpin->value();

        selectedJob.addTask(selectedMachine, 0, duration);

        fillMachinesCombo();
        emit dataChanged();
    }
}
