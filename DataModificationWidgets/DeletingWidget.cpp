#include "DeletingWidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QGroupBox>
#include <QFormLayout>
#include "../Chromosom.h"

DeletingWidget::DeletingWidget(QWidget *parent) :
    QWidget(parent)
{
    jobCombo = new QComboBox();
    machineCombo = new QComboBox();
    taskJobCombo = new QComboBox();
    taskMachineCombo = new QComboBox();

    this->setGeometry(0, 0, 500, 200);

    fillJobsCombos();
    fillMachineCombo();
    fillTaskMachineCombo();

    QObject::connect(taskJobCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(fillTaskMachineCombo()));

    QHBoxLayout *mainLayout = new QHBoxLayout();

    QVBoxLayout *leftSide = new QVBoxLayout();
    QVBoxLayout *rightSide = new QVBoxLayout();

    QVBoxLayout *jobLay = new QVBoxLayout();
    QVBoxLayout *machineLay = new QVBoxLayout();

    QGroupBox *jobGrp = new QGroupBox("Job");
    QGroupBox *machineGrp = new QGroupBox("Machine");
    QGroupBox *taskGrp = new QGroupBox("Task");

    QPushButton *delJobBtn = new QPushButton("Delete");
    QPushButton *delMachineBtn = new QPushButton("Delete");
    QPushButton *delTaskBtn = new QPushButton("Delete");

    QObject::connect(delJobBtn, SIGNAL(clicked()), this, SLOT(deleteJob()));
    QObject::connect(delMachineBtn, SIGNAL(clicked()), this, SLOT(deleteMachine()));
    QObject::connect(delTaskBtn, SIGNAL(clicked()), this, SLOT(deleteTask()));

    QFormLayout *taskLay = new QFormLayout;
    taskLay->addRow(tr("&Job:"), taskJobCombo);
    taskLay->addRow(tr("&Machine:"), taskMachineCombo);
    taskLay->addWidget(delTaskBtn);

    taskGrp->setLayout(taskLay);

    jobLay->addWidget(jobCombo);
    jobLay->addWidget(delJobBtn);

    machineLay->addWidget(machineCombo);
    machineLay->addWidget(delMachineBtn);

    jobGrp->setLayout(jobLay);
    machineGrp->setLayout(machineLay);

    leftSide->addWidget(jobGrp);
    leftSide->addWidget(machineGrp);

    rightSide->addWidget(taskGrp);

    mainLayout->addLayout(leftSide);
    mainLayout->addLayout(rightSide);

    this->setLayout(mainLayout);
}

void DeletingWidget::fillJobsCombos(){
    jobCombo->clear();
    taskJobCombo->clear();

    jobCombo->addItem("Select...");
    taskJobCombo->addItem("Select...");
    int jobCount = Chromosom::getJobDatabase().getJobsAmount();
    for(int i=0; i<jobCount; i++){
        jobCombo->addItem(QString::number(i));
        taskJobCombo->addItem(QString::number(i));
    }
}

void DeletingWidget::fillMachineCombo(){
    machineCombo->clear();
    machineCombo->addItem("Select...");

    vector <Machine*> &allMachines = Chromosom::getJobDatabase().getMachines();
    for(int i=0; i<allMachines.size(); i++)
        machineCombo->addItem(QString::number(allMachines[i]->getId()));
}

void DeletingWidget::fillTaskMachineCombo(){
    taskMachineCombo->clear();
    taskMachineCombo->addItem("Select...");
    if(taskJobCombo->currentIndex()!=0){
        Job &currJob = Chromosom::getJobDatabase().getJobs()[taskJobCombo->currentText().toInt()];
        vector <Task> &allTasks = currJob.getTaskList();
        for(int i=0; i<allTasks.size(); i++){
           taskMachineCombo->addItem( QString::number(allTasks[i].getMachine()->getId()) );
        }
    }
}

void DeletingWidget::deleteJob(){
    if(jobCombo->currentIndex()!=0){
        Chromosom::getJobDatabase().deleteJob(jobCombo->currentText().toInt());
        fillJobsCombos();
        emit dataChanged();
    }

}

void DeletingWidget::deleteMachine(){
    if(machineCombo->currentIndex()!=0){
        Chromosom::getJobDatabase().deleteMachine(machineCombo->currentText().toInt());
        fillMachineCombo();
        fillTaskMachineCombo();
        emit dataChanged();
    }
}

void DeletingWidget::deleteTask(){
    if(taskJobCombo->currentIndex()!=0 && taskMachineCombo->currentIndex()!=0){
        Chromosom::getJobDatabase().getJobs()[taskJobCombo->currentText().toInt()].deleteTask(taskMachineCombo->currentText().toInt());
        fillTaskMachineCombo();
        emit dataChanged();
    }
}
