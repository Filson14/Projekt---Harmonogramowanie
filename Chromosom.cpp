/*
 * Chromosom.cpp
 *
 *  Created on: Apr 27, 2014
 *      Author: Wojtek
 */

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

int Chromosom::countFitness() {
	// TODO Cialo funkcji
}

int Chromosom::jobCount=0;	//!< Liczba zadan do wykonania.
int Chromosom::machineCount=0;
