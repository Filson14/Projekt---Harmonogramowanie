#include "AddingWidget.h"
#include <QGroupBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QComboBox>
#include <QFormLayout>
#include <QFileDialog>
#include <QMessageBox>

AddingWidget::AddingWidget(QWidget *parent) :
    QWidget(parent)
{
    jobCombo = new QComboBox();
    machineCombo = new QComboBox();
    durationSpin = new QSpinBox();

    this->setGeometry(0, 0, 500, 200);

    //emit databaseRequest();

    durationSpin->setMinimum(0);
    durationSpin->setMaximum(300);

    QObject::connect(jobCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(emitDTRequest()));

    QHBoxLayout *mainLayout = new QHBoxLayout();

    QVBoxLayout *leftSide = new QVBoxLayout();
    QVBoxLayout *rightSide = new QVBoxLayout();

    QVBoxLayout *jobLay = new QVBoxLayout();
    QVBoxLayout *machineLay = new QVBoxLayout();

    QGroupBox *jobGrp = new QGroupBox("Job");
    QGroupBox *machineGrp = new QGroupBox("Machine");
    QGroupBox *taskGrp = new QGroupBox("Task");

    QPushButton *addJobBtn = new QPushButton("Add");
    QPushButton *addMachineBtn = new QPushButton("Add");
    QPushButton *addTaskBtn = new QPushButton("Add");

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

void AddingWidget::fillMachinesCombo(Database* mydt){
    machineCombo->clear();
    machineCombo->addItem("Select...");
    durationSpin->setValue(0);
    if(jobCombo->currentIndex()>0){
        Job &currJob = mydt->getJobs()[jobCombo->currentText().toInt()];
        vector <Machine*> &allMachines = mydt->getMachines();
        for(unsigned int i=0; i<allMachines.size(); i++){
            if( !currJob.isMachineUsed(allMachines[i]->getId()) )
                machineCombo->addItem(QString::number(allMachines[i]->getId()));
        }
    }
}

void AddingWidget::fillJobsCombo(Database* mydt){
    jobCombo->clear();
    machineCombo->clear();
    jobCombo->addItem("Select...");
    machineCombo->addItem("Select...");
    durationSpin->setValue(0);
    int jobCount = mydt->getJobsAmount();
    for(int i=0; i<jobCount; i++)
        jobCombo->addItem(QString::number(i));
}

void AddingWidget::addJob(){
    emit addJobSig();
}

void AddingWidget::addMachine(){
    emit addMachineSig();
}

void AddingWidget::addTask(){
    emit addTaskSig(jobCombo->currentText().toInt(),machineCombo->currentText().toInt(),durationSpin->value());
}

void AddingWidget::emitDTRequest()
{
    printf("newBestChromosom signal recieved, I'm on it.\n");
    fflush(NULL);
    if(jobCombo->currentIndex()==0)
        return;
    emit subwidgetRepaintRequest();
}
