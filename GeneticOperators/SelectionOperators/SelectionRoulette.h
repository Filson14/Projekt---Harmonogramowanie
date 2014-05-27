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

	/**
	 * Funkcja przygotowuje klase do procesu selekcji.
	 * \param population referencja do wektora zawierajacego populacje chromosomow.
	 */
	void prepareSelection(vector<Chromosom> & population);

	/**
	 * Funkcja wybiera osobnika metoda ruletki.
	 * \return wybrany osobnik z populacji.
	 */
	Chromosom & selectParent();
};

#endif /* SELECTIONROULETTE_H_ */
