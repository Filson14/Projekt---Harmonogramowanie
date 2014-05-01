/*
 * SelectionTournament.cpp
 *
 *  Created on: May 1, 2014
 *      Author: Wojtek
 */
#include <Random>
#include <time.h>
#include "SelectionTournament.h"

SelectionTournament::SelectionTournament(int selectionProbability) {
	this->selectionProbability = selectionProbability;
}

SelectionTournament::~SelectionTournament() {
	// TODO Auto-generated destructor stub
}

void SelectionTournament::prepareSelection(const vector<Chromosom *> population) {

}

Chromosom * SelectionTournament::selectParent() {
	vector<Chromosom *> competitors;
	srand(time(NULL));


}

