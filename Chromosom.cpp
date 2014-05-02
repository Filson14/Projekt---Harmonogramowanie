/*
 * Chromosom.cpp
 *
 *  Created on: Apr 27, 2014
 *      Author: Wojtek
 */
#include "DataModification/Database.h"
#include "Chromosom.h"
#include <ctime>
#include <cstdlib>

Chromosom::Chromosom() {
}

Chromosom::Chromosom(vector<int> genotype) {
	this->genotype=genotype;
}

Chromosom::Chromosom(vector<int> genotype,int jobCount, int machineCount ) {
	this->genotype=genotype;
	Chromosom::jobCount=jobCount;
	Chromosom::machineCount=machineCount;
}

Chromosom::~Chromosom() {
	// TODO Auto-generated destructor stub
}

void Chromosom::setJobCount(int jobCount) {
	Chromosom::jobCount=jobCount;
}

void Chromosom::setMachineCount(int machineCount) {
	Chromosom::machineCount=machineCount;
}

void Chromosom::setJobDatabase(Database& jobDatabase)
{
    Chromosom::jobDatabase=jobDatabase;
}

int Chromosom::getFitness() const {
	return this->fitness;
}

const vector<int>& Chromosom::getGenotype() const{
	return this->genotype;
}

Database& Chromosom::getJobDatabase()  {
	return Chromosom::jobDatabase;
}


void Chromosom::setGenotype(vector<int>& genotype) {
	this->genotype=genotype;
}

void Chromosom::generateRandomGenotype() {
    this->genotype=vector <int> (machineCount*jobCount,0);
	vector <int> taskScheduled (jobCount,0);
	int jobID;
	for(vector<int>::iterator it=genotype.begin();it!=genotype.end();it++)
	{
	    do
	    {
	        jobID=rand()%jobCount;
	    }
	    while(taskScheduled[jobID]>=machineCount);
	    taskScheduled[jobID]++;
	    *it=jobID;
	}

}

int Chromosom::countFitness() { //działa przy numeracji maszyn i jobów od 0 - do ustalenia
    vector<int> machineSchedule(machineCount,0);	//!< Informacje o zajetosci maszyn.
	vector<int> jobSchedule(jobCount,0);	//!< Informacje o postepach prac.
	vector<int> currentTaskCount(jobCount,0);
	int startingfit=0;
	int currentTasknum;
	int currentMachineId;
	for(vector<int>::iterator it=genotype.begin();it!=genotype.end();it++)
	{
	    currentTasknum=currentTaskCount[*it];
	    currentMachineId=jobDatabase.getJobs()[*it].getTaskList()[currentTasknum].getMachine()->getId();
	    currentTaskCount[*it]++;

	    if(machineSchedule[currentMachineId]>jobSchedule[*it])
	        jobSchedule[*it]=machineSchedule[currentMachineId]+jobDatabase.getJobs()[*it].getTaskList()[currentTasknum].getTime();
	    else
	        jobSchedule[*it]+=jobDatabase.getJobs()[*it].getTaskList()[currentTasknum].getTime();

	    machineSchedule[currentMachineId]+=jobDatabase.getJobs()[*it].getTaskList()[currentTasknum].getTime();
	}
	for(vector<int>::iterator it=jobSchedule.begin();it!=jobSchedule.end();it++)
	    if(jobSchedule[*it]>startingfit)
            startingfit=jobSchedule[*it];

    this->fitness=startingfit;
    return this->fitness;
}

void Chromosom::printGenotype()
{
    for(vector<int>::iterator it=genotype.begin();it!=genotype.end();it++)
        cout<<*it<<" ";
    cout<<endl;
}

void Chromosom::updateDatabaseWithStartTimes()
{
    vector<int> machineSchedule(machineCount,0);	//!< Informacje o zajetosci maszyn.
	vector<int> jobSchedule(jobCount,0);	//!< Informacje o postepach prac.
	vector<int> currentTaskCount(jobCount,0);
	int startingfit=0;
	int currentTasknum;
	int currentMachineId;
	for(vector<int>::iterator it=genotype.begin();it!=genotype.end();it++)
	{
	    currentTasknum=currentTaskCount[*it];
	    currentMachineId=jobDatabase.getJobs()[*it].getTaskList()[currentTasknum].getMachine()->getId();
	    currentTaskCount[*it]++;

	    if(machineSchedule[currentMachineId]>jobSchedule[*it])
	    {
	        jobSchedule[*it]=machineSchedule[currentMachineId]+jobDatabase.getJobs()[*it].getTaskList()[currentTasknum].getTime();
	    }
	    else
	    {
	        jobSchedule[*it]+=jobDatabase.getJobs()[*it].getTaskList()[currentTasknum].getTime();
	    }
	    machineSchedule[currentMachineId]+=jobDatabase.getJobs()[*it].getTaskList()[currentTasknum].getTime();
	}

}

void Chromosom::setRandomFitness()
{
    this->fitness=rand()%1000;
}


int Chromosom::jobCount=0;	//!< Liczba zadan do wykonania.
int Chromosom::machineCount=0;
Database Chromosom::jobDatabase;
