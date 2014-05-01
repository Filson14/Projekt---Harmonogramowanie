/*
 * CrossoverOperator.h
 *
 *  Created on: May 1, 2014
 *      Author: Wojtek
 */

#ifndef CROSSOVEROPERATOR_H_
#define CROSSOVEROPERATOR_H_
#include "../Chromosom.h"

class CrossoverOperator {
public:
	CrossoverOperator();
	virtual ~CrossoverOperator();
	virtual void crossChromosoms(const Chromosom & parentA, const Chromosom & parentB, Chromosom & childA, Chromosom & childB) = 0;

};

#endif /* CROSSOVEROPERATOR_H_ */
