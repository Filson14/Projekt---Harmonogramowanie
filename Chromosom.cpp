/*
 * Chromosom.cpp
 *
 *  Created on: Apr 27, 2014
 *      Author: Wojtek
 */
#include "Database.h"
#include "Chromosom.h"

Chromosom::Chromosom() {
	// TODO Auto-generated destructor stub
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

int Chromosom::getFitness() const {
	return this->fitness;
}

const vector<int>& Chromosom::getGenotype() {
	return this->genotype;
}

void Chromosom::setGenotype(vector<int>& genotype) {
	this->genotype=genotype;
}

void Chromosom::generateRandomGenotype() {
	// TODO Cialo funkcji
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

int Chromosom::jobCount=0;	//!< Liczba zadan do wykonania.
int Chromosom::machineCount=0;
Database Chromosom::jobDatabase;
