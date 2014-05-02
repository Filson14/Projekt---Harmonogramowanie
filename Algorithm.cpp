/*
 * Algorithm.cpp
 *
 *  Created on: Apr 27, 2014
 *      Author: Wojtek
 */

#include "Algorithm.h"
#include "SettingsStructures.h"
#include "SelectionOperators/SelectionTournament.h"
#include "SelectionOperators/SelectionRoulette.h"

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

		//TODO Usunac po testach.
		newChromosom->setRandomFitness();
		//TODO Odkomentowac jak wersja Olka i Filipa beda w pelni dzialajace.
		//newChromosom->countFitness();

		this->population.push_back(newChromosom);
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
	this->selectionOperator->prepareSelection(this->population);
	this->selectionOperator->selectParent()->printGenotype();
}

void Algorithm::printPopulation() {
		for(int i = 0; i < this->populationSize; i++) {
			cout << "Chromosom " << i << ": " << this->population[i] << " | Fitness: " << this->population[i]->getFitness() << " | Genotype: ";
			this->population[i]->printGenotype();
		}
	}


bool compareChromosoms(const Chromosom * A, const Chromosom * B) {
	return A->getFitness() < B->getFitness();
}


int main(int argc, const char* argv[] )
{
	srand(time(NULL));
	SettingsProblem problem = {5, 5};
	SettingsAlgorithm algorithm = {5, 5, 5, 5, 5, 5};
	SettingsOperator operators = { new SelectionRoulette(), NULL, NULL};
	Algorithm  algorithms = Algorithm(problem, algorithm, operators);
	Chromosom::setJobCount(problem.jobCount);
	Chromosom::setMachineCount(problem.machineCount);
	algorithms.initializePopulation();
	algorithms.printPopulation();
	algorithms.generateNewPopulation();

	cout << "Finished.";
}
