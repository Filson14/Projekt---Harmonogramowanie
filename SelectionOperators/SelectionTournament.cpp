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
	double randomProbability, competitorProbability = 1.0;
	set<int> indicesUsed;
	vector<Chromosom *> competitors;


	for(int i = 0; i < this->competitorCount; i++) {
		do {
			randomCompetitor = rand() % this->population.size();
		} while (indicesUsed.find(randomCompetitor) != indicesUsed.end());
		indicesUsed.insert(randomCompetitor);
		competitors.push_back(this->population[randomCompetitor]);
	}

	sort(competitors.begin(), competitors.end(), compareChromosoms);

	for(int i = 0; i < this->competitorCount; i++) {
		competitorProbability *= this->selectionProbability;
		randomProbability = (double) rand() / (RAND_MAX);

		if (randomProbability < competitorProbability)
			return competitors[i];
	}
	return competitors.back();
}
