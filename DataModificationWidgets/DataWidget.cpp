#include "DataWidget.h"
#include <QGroupBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QButtonGroup>
#include <QFileDialog>
#include "../DataModification/Database.h"

DataWidget::DataWidget(QWidget *parent) :
    QWidget(parent)
{
    this->resize(600, 200);

    this->addWidget = new AddingWidget();
    this->editWidget = new EditingWidget();
    this->delWidget = new DeletingWidget();

    QObject::connect(addWidget, SIGNAL(dataChanged()), this, SLOT(emitChangeSignal()));
    QObject::connect(addWidget, SIGNAL(dataChanged()), delWidget, SLOT(fillJobsCombos()));
    QObject::connect(addWidget, SIGNAL(dataChanged()), editWidget, SLOT(fillJobCombo()));

    QObject::connect(delWidget, SIGNAL(dataChanged()), this, SLOT(emitChangeSignal()));
    QObject::connect(delWidget, SIGNAL(dataChanged()), addWidget, SLOT(fillJobsCombo()));
    QObject::connect(delWidget, SIGNAL(dataChanged()), editWidget, SLOT(fillJobCombo()));

    QObject::connect(editWidget, SIGNAL(dataChanged()), this, SLOT(emitChangeSignal()));
    QObject::connect(editWidget, SIGNAL(dataChanged()), addWidget, SLOT(fillJobsCombo()));
    QObject::connect(editWidget, SIGNAL(dataChanged()), delWidget, SLOT(fillJobsCombos()));

    QStackedLayout *pageLayout = new QStackedLayout();
    pageLayout->addWidget(addWidget);
    pageLayout->addWidget(delWidget);
    pageLayout->addWidget(editWidget);

    QGroupBox *dataGrp = new QGroupBox("DATA", this);
    QGroupBox *fileGrp = new QGroupBox("FILE", this);

    QHBoxLayout *mainLayout = new QHBoxLayout();

    QVBoxLayout *dataLayout = new QVBoxLayout();
    QVBoxLayout *fileLayout = new QVBoxLayout();

    QPushButton *addBtn = new QPushButton("ADD");
    QPushButton *delBtn = new QPushButton("DELETE");
    QPushButton *editBtn = new QPushButton("EDIT");

    QButtonGroup *btnGroup = new QButtonGroup(this);
    btnGroup->addButton(addBtn, 0);
    btnGroup->addButton(delBtn, 1);
    btnGroup->addButton(editBtn, 2);
    
    QObject::connect(btnGroup, SIGNAL(buttonClicked(int)), pageLayout, SLOT(setCurrentIndex(int)));

    dataLayout->addWidget(addBtn);
    dataLayout->addWidget(delBtn);
    dataLayout->addWidget(editBtn);

    QPushButton *loadBtn = new QPushButton("LOAD");
    QPushButton *saveBtn = new QPushButton("SAVE");
    QPushButton *generateDataBtn = new QPushButton("GENERATE");

    QObject::connect(loadBtn, SIGNAL(clicked()), this, SLOT(loadDataFromFile()));
    QObject::connect(saveBtn, SIGNAL(clicked()), this, SLOT(saveDataToFile()));
    QObject::connect(generateDataBtn, SIGNAL(clicked()), this, SLOT(generateRandomData()));

    fileLayout->addWidget(loadBtn);
    fileLayout->addWidget(saveBtn);
    fileLayout->addWidget(generateDataBtn);

    dataGrp->setLayout(dataLayout);
    fileGrp->setLayout(fileLayout);

    mainLayout->addWidget(dataGrp);
    mainLayout->addWidget(fileGrp);
    mainLayout->addLayout(pageLayout);

    this->setLayout(mainLayout);


    this->show();
}

void DataWidget::loadDataFromFile(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"C://", tr("Text File (*.txt)"));
    if(fileName!=""){
        Chromosom::getJobDatabase().readFromFile(fileName.toStdString().c_str());
        updateWidgets();
        emit dataChanged();
    }
}

void DataWidget::saveDataToFile(){
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),"C://", tr("Text File (*.txt)"));
    if(fileName!=""){
        Chromosom::getJobDatabase().saveToFile(fileName.toStdString().c_str());
        updateWidgets();
        emit dataChanged();
    }
}

void DataWidget::generateRandomData(){
    Chromosom::getJobDatabase().generateRandomData(5, 5);
    updateWidgets();
    emit dataChanged();
}

void DataWidget::emitChangeSignal(){
    emit dataChanged();
}

void DataWidget::updateWidgets(){
    addWidget->fillJobsCombo();
    delWidget->fillJobsCombos();
    delWidget->fillMachineCombo();
    editWidget->fillJobCombo();
}
