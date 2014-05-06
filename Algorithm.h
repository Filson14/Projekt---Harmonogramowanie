/*
 * Algorithm.h
 *
 *  Created on: Apr 27, 2014
 *      Author: Wojtek
 */

#ifndef ALGORITHM_H_
#define ALGORITHM_H_
#include <vector>
#include <algorithm>
#include "Chromosom.h"
#include "SettingsStructures.h"
#include "SelectionOperators/SelectionTournament.h"
#include "SelectionOperators/SelectionRoulette.h"
#include "CrossoverOperators/CrossoverOnePoint.h"
#include "CrossoverOperators/CrossoverTwoPoint.h"
#include "MutationOperators/MutationSwapping.h"
#include "MutationOperators/MutationInversion.h"



class Algorithm {
private:
	int maxEpochs;	//!< Maksymalna liczba epok;
	int maxEpochsWithoutChange;	//!< Maksymalna liczba epok bez zmiany najlepszego osobnika.
	int jobCount;	//!< Liczba zadan do wykonania.
	int machineCount;	//!< Liczba dostepnych maszyn.
	int populationSize;	//!< Rozmiar populacji.
	int newPopulationSize;	//!< Rozmiar populacji powstalej z krzyzowania.
	double meanPopulationFitness;	//!< Srednie przystosowanie populacji.
	double mutationProbability;	//!< Prawdopodobienstwo mutacji osobnika.
	double crossoverProbability;	//!< Prawdopodobienstwo krzyzowania.
	Chromosom bestChromosom;	//!< Liczba dostepnych maszyn.
	vector<Chromosom> population;	//!< Aktualna populacja.
	vector<Chromosom> newPopulation;	//!< Nowa populacja.

	SelectionOperator * selectionOperator;	//!< Operator selekcji osobnikow.
	MutationOperator * mutationOperator;	//!< Operator mutacji osobnik
	CrossoverOperator * crossoverOperator;	//!< Operator krzyzowania osobnikow.

public:
	Algorithm(struct SettingsProblem & problem, struct SettingsAlgorithm & algorithm, struct SettingsOperator & operators);
	virtual ~Algorithm();

	/**
	 * Funkcja tworzy poczatkowa populacje chromosomow oraz ja ewaluuje.
	 */
	void initializePopulation();

	/**
	* Funkcja oblicza srednie przystosowanie populacji.
	*/
	double evaluatePopulation();

	/**
	 * Funkcja wybiera najlepsze osobniki powstale z krzyzowania do aktualnej populacji.
	 */
	void selectNewPopulation();

	/**
	 * Funkcja odpowiada za dzialanie algorytmu.
	 */
	void runAlgorithm();

	/**
	 * Funkcja tworzy nowa populacje.
	 */
	void generateNewPopulation();

	/**
	 * Funkcja wyswietla populacje.
	 */
	void printPopulation(const vector<Chromosom> & population);
};

bool compareChromosoms(const Chromosom & A, const Chromosom & B);

#endif /* ALGORITHM_H_ */
