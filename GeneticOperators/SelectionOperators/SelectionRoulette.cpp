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
}

Chromosom & SelectionRoulette::selectParent() {
    int randomIndex;
    randomIndex = rand() % population.size();
    return population[randomIndex];
}

