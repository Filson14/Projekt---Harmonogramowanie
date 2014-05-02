/*
 * SelectionTournament.h
 *
 *  Created on: May 1, 2014
 *      Author: Wojtek
 */

#ifndef SELECTIONTOURNAMENT_H_
#define SELECTIONTOURNAMENT_H_
#include <ctime>
#include <cstdlib>
#include <set>
#include <algorithm>
#include "../Algorithm.h"
#include "SelectionOperator.h"

class SelectionTournament: public SelectionOperator {
private:
	int competitorCount;
	double selectionProbability;

public:
	SelectionTournament(double selectionProbability, int competitorCount);
	virtual ~SelectionTournament();
	void prepareSelection(vector<Chromosom *> & population);
	Chromosom * selectParent();
};

#endif /* SELECTIONTOURNAMENT_H_ */
