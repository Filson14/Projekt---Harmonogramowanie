/*
 * SelectionRoulette.h
 *
 *  Created on: May 2, 2014
 *      Author: Wojtek
 */

#ifndef SELECTIONROULETTE_H_
#define SELECTIONROULETTE_H_

#include "SelectionOperator.h"

class SelectionRoulette: public SelectionOperator {
private:
	long totalFitness;

public:
	SelectionRoulette();
	virtual ~SelectionRoulette();
	void prepareSelection(vector<Chromosom *> & population);
	Chromosom * selectParent();
};

#endif /* SELECTIONROULETTE_H_ */
