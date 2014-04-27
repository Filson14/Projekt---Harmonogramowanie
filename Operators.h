/*
 * Operators.h
 *
 *  Created on: Apr 27, 2014
 *      Author: Wojtek
 */

#ifndef OPERATORS_H_
#define OPERATORS_H_
#include <vector>
#include "Chromosom.h"

/**
 *
 * \param currentPopulation
 * \param parentList
 * \param newPopulationSize
 */
void selectionRoulette (const vector<Chromosom*> currentPopulation, vector<Chromosom*> parentList, int newPopulationSize);

/**
 *
 * \param currentPopulation
 * \param parentList
 * \param newPopulationSize
 */
void selectionTournament (const vector<Chromosom*> currentPopulation, vector<Chromosom*> parentList, int newPopulationSize);

/**
 *
 * \param parentA
 * \param parentB
 * \param childA
 * \param childB
 */
void crossoverOperatorPPX(Chromosom* parentA, Chromosom* parentB, Chromosom* childA, Chromosom* childB);

/**
 * Funkcja dokonuje pojedynczej mutacji.
 * \param child
 */
void mutationSingle(Chromosom* child);

#endif /* OPERATORS_H_ */
