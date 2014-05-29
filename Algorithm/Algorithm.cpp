/*
 * Algorithm.cpp
 *
 *  Created on: Apr 27, 2014
 *      Author: Wojtek
 */

#include "Algorithm.h"

Algorithm::Algorithm() : QObject() {

}

Algorithm::Algorithm(struct AlgorithmSettings & settings) : QObject() {

    this->settings.maxEpochs = settings.maxEpochs;
    this->settings.maxEpochsWithoutChange = settings.maxEpochsWithoutChange;
    this->settings.populationSize = settings.populationSize;
    this->settings.newPopulationSize = settings.newPopulationSize;
    this->settings.mutationProbability = settings.mutationProbability;
    this->settings.crossoverProbability = settings.crossoverProbability;

    this->settings.selectionOperator = settings.selectionOperator;
    this->settings.mutationOperator = settings.mutationOperator;
    this->settings.crossoverOperator = settings.crossoverOperator;

    this->statistics.clearStatistics();
}

Algorithm::~Algorithm() {
    population.clear();
    newPopulation.clear();
}

void Algorithm::initializePopulation() {
	Chromosom newChromosom;
    for(int i = 0; i < settings.populationSize; i++) {
		newChromosom = Chromosom();
		newChromosom.generateRandomGenotype();
		newChromosom.countFitness();

        population.push_back(newChromosom);
	}
    sort(population.begin(), population.end(), compareChromosoms);
}

double Algorithm::evaluatePopulation() {
	long totalFitness = 0;

	for(vector<Chromosom>::iterator it = this->newPopulation.begin(); it != this->newPopulation.end(); it++) {
		totalFitness += (*it).countFitness();
	}

    return (totalFitness / settings.newPopulationSize);
}

void Algorithm::selectNewPopulation() {
    sort(newPopulation.begin(), newPopulation.end(), compareChromosoms);
    population.clear();

    for(int i = 0; i < settings.populationSize; i++)
        population.push_back(newPopulation[i]);

    newPopulation.clear();
}

void Algorithm::generateNewPopulation() {
	Chromosom childA, childB;
    int crossoverCount = 0, mutationCount = 0, invalidChromosomCount = 0, sameParentsCount = 0;

    settings.selectionOperator->prepareSelection(population);
    for(int index = 0; index < settings.newPopulationSize;)
	{
		childA = Chromosom();
        childB = Chromosom();

        Chromosom& parentA = settings.selectionOperator->selectParent();
        Chromosom& parentB = settings.selectionOperator->selectParent();

		if (parentA.getGenotype() == parentB.getGenotype()) {
            sameParentsCount++;
			continue;
		}

        if (((double) rand()) / (RAND_MAX) < settings.crossoverProbability) {
            settings.crossoverOperator->crossChromosoms(parentA, parentB, childA, childB);
            crossoverCount++;
            if (settings.repairChromosom) {
                childA.repairChromosom();
                childB.repairChromosom();
            }

            if (!childA.isValid() || !childB.isValid()) {
                invalidChromosomCount++;
				continue;
			}
		} else {
			childA = parentA;
			childB = parentB;
		}

        if ((double) rand() / (RAND_MAX) < settings.mutationProbability) {
            settings.mutationOperator->performMutation(childA);
            mutationCount++;
        }

        if ((double) rand() / (RAND_MAX) < settings.mutationProbability) {
            settings.mutationOperator->performMutation(childB);
            mutationCount++;
        }

		this->newPopulation.push_back(childA);
		this->newPopulation.push_back(childB);
        index = index + 2;
    }
}

void Algorithm::printPopulation(const vector<Chromosom> & population) {
	for(vector<Chromosom>::const_iterator it = population.begin(); it != population.end(); it++)
		(*it).printChromosom();
}

void Algorithm::runAlgorithm() {
    int currentEpoch = 0;
    int lastImprovement = 0;
    statistics.clearStatistics();

    cout << "Initializing population... ";
    this->initializePopulation();
	cout << "OK" << endl;
	this->bestChromosom = this->population[0];
	do {

        cout << "Epoche: " << currentEpoch << " ====================== "<< endl;
        cout << "Generating new population... ";
		this->generateNewPopulation();
		cout << "OK" << endl;

		cout << "Evaluate population...";
        double meanFitness = this->evaluatePopulation();
		cout << "OK" << endl;

		cout << "Select new population... ";
		this->selectNewPopulation();
        cout << "OK" << endl;
        if(compareChromosoms(population[0], bestChromosom)) {
            bestChromosom = population[0];
            bestChromosom.updateDatabaseWithStartTimes();
            lastImprovement = 0;
            emit newBestChromosom(&bestChromosom.getJobDatabase());
		}
		else
            lastImprovement++;


        statistics.lastImprovement = lastImprovement;
        statistics.epoch.push_back((double)currentEpoch);
        statistics.bestFitness.push_back(bestChromosom.getFitness());
        statistics.populationFitness.push_back(meanFitness);


        if (currentEpoch % 10 == 0)
            emit newStatistics(statistics);

        cout << "Mean fitness: " << meanFitness << endl;
    } while ((currentEpoch++ < settings.maxEpochs) && (lastImprovement < settings.maxEpochsWithoutChange));

	cout << "AND THE WINNER IS... *drum roll*" << endl;
    bestChromosom.printChromosom();
    bestChromosom.updateDatabaseWithStartTimes();
}

void Algorithm::updateSettings(struct AlgorithmSettings & newSettings)
{
    this->settings.maxEpochs = newSettings.maxEpochs;
    this->settings.maxEpochsWithoutChange = newSettings.maxEpochsWithoutChange;
    this->settings.repairChromosom = newSettings.repairChromosom;
    this->settings.populationSize = newSettings.populationSize;
    this->settings.newPopulationSize = newSettings.newPopulationSize;
    this->settings.mutationProbability = newSettings.mutationProbability;
    this->settings.crossoverProbability = newSettings.crossoverProbability;

    this->settings.selectionOperator = newSettings.selectionOperator;
    this->settings.mutationOperator = newSettings.mutationOperator;
    this->settings.crossoverOperator = newSettings.crossoverOperator;
}

bool compareChromosoms(const Chromosom & A, const Chromosom & B) {
	return A.getFitness() < B.getFitness();
}

