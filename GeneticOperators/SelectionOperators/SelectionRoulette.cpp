/*
 * SelectionRoulette.cpp
 *
 *  Created on: May 2, 2014
 *      Author: Wojtek
 */

#include "SelectionRoulette.h"

SelectionRoulette::SelectionRoulette() {
	this->totalFitness = 0;

}

SelectionRoulette::~SelectionRoulette() {
	// TODO Auto-generated destructor stub
}

void SelectionRoulette::prepareSelection(vector<Chromosom> & population) {
	this->population = population;

	for(vector<Chromosom>::iterator it = this->population.begin(); it != this->population.end(); it++)
		this->totalFitness += (*it).getFitness();
}

Chromosom & SelectionRoulette::selectParent() {
	double combinedNormalizedFitness = 0.0;
	double randomProbability = (double) rand() / (RAND_MAX);

	vector<Chromosom>::iterator it = this->population.begin();
	while((combinedNormalizedFitness += ((double)(this->totalFitness - (*it).getFitness()) / this->totalFitness)) < randomProbability)
		it++;

	if(it == this->population.end())
		it--;

	return *it;
}

