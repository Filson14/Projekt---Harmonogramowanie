/*
 * Algorithm.cpp
 *
 *  Created on: Apr 27, 2014
 *      Author: Wojtek
 */

#include "Algorithm.h"

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
	this->crossoverOperator = operators.crossoverOperator;

	this->meanPopulationFitness = 0;
}

Algorithm::~Algorithm() {

	this->population.clear();
	this->newPopulation.clear();
}

void Algorithm::initializePopulation() {
	Chromosom newChromosom;
	for(int i = 0; i < populationSize; i++) {
		newChromosom = Chromosom();
		newChromosom.generateRandomGenotype();
		newChromosom.countFitness();

		//TODO Usunac po testach.
		//newChromosom.setRandomFitness();
		this->population.push_back(newChromosom);
	}
	sort(this->population.begin(), this->population.end(), compareChromosoms);
}

double Algorithm::evaluatePopulation() {
	long totalFitness = 0;
	int i = 0;

	for(vector<Chromosom>::iterator it = this->newPopulation.begin(); it != this->newPopulation.end(); it++) {
		//TODO Usunac po testach.
		(*it).setRandomFitness();
		totalFitness += (*it).getFitness();
		//(*it).countFitness();
		cout << i++;
	}
	return (totalFitness / this->populationSize);
}

void Algorithm::selectNewPopulation() {
	sort(this->newPopulation.begin(), this->newPopulation.end(), compareChromosoms);
	this->population.clear();

	for(int i = 0; i < populationSize; i++)
		this->population.push_back(this->newPopulation[i]);

	this->newPopulation.clear();
}

void Algorithm::generateNewPopulation() {
	Chromosom childA, childB;

	this->selectionOperator->prepareSelection(this->population);
	for(int index = 0; index < newPopulationSize;)
	{
		childA = Chromosom();
		childB = Chromosom();
		Chromosom& parentA = this->selectionOperator->selectParent();
		Chromosom& parentB = this->selectionOperator->selectParent();

		if (parentA.getGenotype() == parentB.getGenotype()) {
			//cout << "=== THE SAME PARENTS ===" << endl;
			continue;
		}
		crossoverOperator->crossChromosoms(parentA, parentB, childA, childB);
		this->newPopulation.push_back(childA);
		this->newPopulation.push_back(childB);
		index = index + 2;

		//TODO Usunac w finalnej wersji.
		//cout << "Parent A Genotype: ";
		//parentA.printGenotype();
		//cout << "Child A Genotype:  ";
		//childA.printGenotype();
		//cout << "Parent B Genotype: ";
		//parentB.printGenotype();
		//cout << "Child B Genotype:  ";
		//childB.printGenotype();
	}
/*
	int i = 0;
	for(vector<Chromosom>::iterator it = this->newPopulation.begin(); it != this->newPopulation.end(); it++) {
		cout << "Chromosom " << i++ << ": " << " | Fitness: " << (*it).getFitness() << " | Genotype: ";
		(*it).printGenotype();
	}

	int equalCount = 0;
	for(int i = 0; i < newPopulationSize; i++) {
		for(int j = i+1; j < newPopulationSize; j++) {
			if(this->newPopulation[i].getGenotype() == this->newPopulation[j].getGenotype())
				equalCount++;
		}
	}
	cout << "Equal count: " << equalCount << endl;
*/
}

void Algorithm::printPopulation(const vector<Chromosom> & population) {
	for(vector<Chromosom>::const_iterator it = population.begin(); it != population.end(); it++)
		(*it).printChromosom();
}

void Algorithm::runAlgorithm() {
	cout << "Initializing population... ";
	this->initializePopulation();
	cout << "OK" << endl;

	for(int i = 0; i < 10; i++) {

		cout << "Generating new population (epoche: " << i << ")... ";
		this->generateNewPopulation();
		cout << "OK" << endl;

		cout << "Evaluate population...";
		this->evaluatePopulation();
		cout << "OK" << endl;
		cout << "Population: " << endl;
		this->printPopulation(this->population);
		cout << "New population: " << endl;
		this->printPopulation(this->newPopulation);

		cout << "Select new population... ";
		this->selectNewPopulation();
		cout << "OK" << endl;
	}

	this->bestChromosom.printChromosom();
}

bool compareChromosoms(const Chromosom & A, const Chromosom & B) {
	return A.getFitness() < B.getFitness();
}

/*
int main(int argc, const char* argv[] )
{
	srand(time(NULL));
	SettingsProblem problem = {5, 5};
	SettingsAlgorithm algorithm = {5, 5, 10, 10, 5, 5};
	SettingsOperator operators = {new SelectionTournament(0.95, 3), new MutationInversion(), new CrossoverTwoPoint()};
	Algorithm  algorithms = Algorithm(problem, algorithm, operators);
	Chromosom::setJobCount(problem.jobCount);
	Chromosom::setMachineCount(problem.machineCount);
	algorithms.initializePopulation();
	algorithms.printPopulation();
	algorithms.generateNewPopulation();

	cout << "Finished.";
}
*/

