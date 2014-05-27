/*
 * MutationSwapping.h
 *
 *  Created on: May 3, 2014
 *      Author: Wojtek
 */

#ifndef MUTATIONSWAPPING_H_
#define MUTATIONSWAPPING_H_

#include "MutationOperator.h"

class MutationSwapping: public MutationOperator {
public:
	MutationSwapping();
	virtual ~MutationSwapping();

	/**
	 * Funkcja dokonuje mutacji chromosomu poprzez zamiane pojedynczych genow.
	 * \param chromosom osobnik ktory podlega mutacji.
	 */
	void performMutation(Chromosom & chromosom);
};

#endif /* MUTATIONSWAPPING_H_ */
