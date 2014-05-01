/*
 * SelectionTournament.cpp
 *
 *  Created on: May 1, 2014
 *      Author: Wojtek
 */
/*
#include "SelectionTournament.h"

SelectionTournament::SelectionTournament(int selectionProbability, int competitorCount) {
	this->competitorCount = competitorCount;
	this->selectionProbability = selectionProbability;
}

SelectionTournament::~SelectionTournament() {
}

void SelectionTournament::prepareSelection(const vector<Chromosom *> & population) {

}

Chromosom * SelectionTournament::selectParent() {
	int competitorProbability = this->selectionProbability;
	int randomCompetitor;
	vector<Chromosom *> competitors;
	srand(time(NULL));

	for(int i = 0; i < this->competitorCount; i++) {
		randomCompetitor = rand() % population.size();
		competitors.push_back(population[randomCompetitor]);
	}

	sort(competitors.begin(), competitors.end(), compareChromosoms);

	for(int i = 0; i < this->competitorCount; i++) {

	}



}

*/
