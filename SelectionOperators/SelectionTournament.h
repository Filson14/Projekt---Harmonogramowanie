/*
 * SelectionTournament.h
 *
 *  Created on: May 1, 2014
 *      Author: Wojtek
 */

#ifndef SELECTIONTOURNAMENT_H_
#define SELECTIONTOURNAMENT_H_

#include "SelectionOperator.h"

class SelectionTournament: public SelectionOperator {
private:
	int selectionProbability;

public:
	SelectionTournament(int selectionProbability);
	virtual ~SelectionTournament();
	void prepareSelection(const vector<Chromosom *> population);
	Chromosom * selectParent();
};

#endif /* SELECTIONTOURNAMENT_H_ */
