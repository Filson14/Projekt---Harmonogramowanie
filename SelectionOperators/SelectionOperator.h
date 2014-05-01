/*
 * SelectionOperator.h
 *
 *  Created on: May 1, 2014
 *      Author: Wojtek
 */

#ifndef SELECTIONOPERATOR_H_
#define SELECTIONOPERATOR_H_
#include <vector>
#include "../Chromosom.h"

class SelectionOperator {
protected:
	const vector<Chromosom *> population;
public:

	SelectionOperator();
	virtual ~SelectionOperator();
	virtual void prepareSelection(const vector<Chromosom *> population) = 0;
	virtual Chromosom * selectParent() = 0;
};

#endif /* SELECTIONOPERATOR_H_ */
