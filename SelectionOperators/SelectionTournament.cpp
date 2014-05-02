/*
 * SelectionTournament.cpp
 *
 *  Created on: May 1, 2014
 *      Author: Wojtek
 */

#include "SelectionTournament.h"

SelectionTournament::SelectionTournament(double selectionProbability, int competitorCount) {
	this->competitorCount = competitorCount;
	this->selectionProbability = selectionProbability;
}

SelectionTournament::~SelectionTournament() {
}

void SelectionTournament::prepareSelection(vector<Chromosom *> & population) {

	this->population = population;
}

Chromosom * SelectionTournament::selectParent() {
	int randomCompetitor;
	vector<Chromosom *> competitors;
	double competitorProbability = 1.0;

	for(int i = 0; i < this->competitorCount; i++) {
		randomCompetitor = rand() % this->population.size();
		cout << "Random competitor " << randomCompetitor << endl;
		//TODO Dont allow the same chromosom multiple times.
		competitors.push_back(this->population[randomCompetitor]);
	}

	sort(competitors.begin(), competitors.end(), compareChromosoms);

	for(int i = 0; i < this->competitorCount; i++) {
		competitorProbability *= this->selectionProbability;
		double randomProbability = (double) rand() / (RAND_MAX);

		if (randomProbability < competitorProbability)
			return competitors[i];
	}
	return competitors.back();
}
