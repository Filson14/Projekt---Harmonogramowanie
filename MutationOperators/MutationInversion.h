/*
 * MutationInversion.h
 *
 *  Created on: May 3, 2014
 *      Author: Wojtek
 */

#ifndef MUTATIONINVERSION_H_
#define MUTATIONINVERSION_H_

#include "MutationOperator.h"

class MutationInversion: public MutationOperator {
public:
	MutationInversion();
	virtual ~MutationInversion();

	/**
	 * Funkcja dokonuje mutacji chromosomu poprzez inwersje dwoch segmentow chromosomu.
	 * \param chromosom osobnik ktory podlega mutacji.
	 */
	void performMutation(Chromosom & chromosom);
};

#endif /* MUTATIONINVERSION_H_ */
