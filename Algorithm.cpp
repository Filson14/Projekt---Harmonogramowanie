/*
 * Algorithm.cpp
 *
 *  Created on: Apr 27, 2014
 *      Author: Wojtek
 */

#include "Algorithm.h"
#include "SettingsStructures.h"

Algorithm::Algorithm(struct SettingsProblem & problem, struct SettingsAlgorithm & algorithm, struct SettingsOperator & operators) {
	this->jobCount = problem.jobCount;
	this->machineCount = problem.machineCount;

	this->maxEpochs = algorithm.maxEpochs;
	this->maxEpochsWithoutChange = algorithm.maxEpochsWithoutChange;
	this->populationSize = algorithm.populationSize;
	this->newPopulationSize = algorithm.newPopulationSize;
	this->mutationProbability = algorithm.mutationProbability;
	this->crossoverProbability = algorithm.crossoverProbability;

	this->selectionOperator = operators.selectionOperator;
	this->mutationOperator = operators.mutationOperator;
	this->crossoverOperator = operators.crossovoerOperator;

	this->bestChromosom = NULL;
	this->meanPopulationFitness = 0;
	this->population.reserve(populationSize);
	this->newPopulation.reserve(newPopulationSize);
}

Algorithm::~Algorithm() {
	for (int i = 0; i < this->populationSize; i++)
		delete this->population[i];

	for (int i = 0; i < this->newPopulationSize; i++)
		delete this->newPopulation[i];
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

	return (totalFitness / this->populationSize);
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

}


bool compareChromosoms(const Chromosom * A, const Chromosom * B) {
	return A->getFitness() > B->getFitness();
}



int main(int argc, const char* argv[] )
{
	SettingsProblem problem = {1, 1};
	SettingsAlgorithm algorithm = {10, 10, 5, 5, 1, 1};
	SettingsOperator operators = {NULL, NULL, NULL};
	Algorithm  algorithms = Algorithm(problem, algorithm, operators);
	algorithms.initializePopulation();

	for(int i = 0; i < 5; i++)
		cout << "Chromosom " << i << ": " << algorithms.population[i] << endl;

	cout << "Finished.";

}
