/*
 * Algorithm.cpp
 *
 *  Created on: Apr 27, 2014
 *      Author: Wojtek
 */

#include "Algorithm.h"

/* ZMIENNE GLOBALNE TYMCZASOWE */

Algorithm::Algorithm(int jobCount, int machineCount, int populationSize, int newPopulationSize) : MAX_EPOCHS(1), MAX_EPOCHS_WITHOUT_CHANGE(2) {
	this->jobCount = jobCount;
	this->machineCount = machineCount;
	this->populationSize = populationSize;
	this->newPopulationSize = newPopulationSize;
	this->meanPopulationFitness = 0;

	this->population.reserve(populationSize);
	this->newPopulation.reserve(newPopulationSize);
}

Algorithm::~Algorithm() {
	// TODO Auto-generated destructor stub
}

void Algorithm::initializePopulation() {
	Chromosom * newChromosom;
	for(int i = 0; i < populationSize; i++) {
		newChromosom = new Chromosom();
		newChromosom->generateRandomGenotype();
		newChromosom->countFitness();
		this->population[i] = newChromosom;
	}
}

double Algorithm::evaluatePopulation() {
	long totalFitness = 0;

	for (int i = 0; i < this->populationSize; i++)
		totalFitness += this->population[i]->getFitness();

	return totalFitness / this->populationSize;
}

void Algorithm::selectNewPopulation() {
	sort(this->newPopulation.begin(), this->newPopulation.end(), compareChromosoms);

	for(int i = 0; i < newPopulationSize; i++) {
		if (i < populationSize) {
			delete population[i];
			population[i] = newPopulation[i];
		}
		else
			delete newPopulation[i];

		newPopulation[i] = NULL;
	}
}

void Algorithm::generateNewPopulation() {
	Chromosom * parentA = NULL, * parentB = NULL, * childA = NULL, * childB = NULL;

	for (int i = 0; i < newPopulationSize; i = i + 2) {
		parentA = selectionOperator();
		parentB = selectionOperator();

		childA->countFitness();
		childB->countFitness();
	}
}


bool compareChromosoms(const Chromosom * A, const Chromosom * B) {
	return A->getFitness() > B->getFitness();
}



int main(int argc, const char* argv[] )
{
	int currentEpoch = 0, epochsWithoutChange = 0;
	Algorithm  algorithm = Algorithm(10, 10, 10, 10);
	algorithm.initializePopulation();

	cout << "Finished.";

}
