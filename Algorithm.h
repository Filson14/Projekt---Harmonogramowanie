/*
 * Algorithm.h
 *
 *  Created on: Apr 27, 2014
 *      Author: Wojtek
 */

#ifndef ALGORITHM_H_
#define ALGORITHM_H_
#include "Chromosom.h"
#include <vector>
#include <algorithm>

class Algorithm {
private:
	const int MAX_EPOCHS;	//!< Maksymalna liczba epok;
	const int MAX_EPOCHS_WITHOUT_CHANGE;	//!< Maksymalna liczba epok bez zmiany najlepszego osobnika.

	int jobCount;	//!< Liczba zadan do wykonania.
	int machineCount;	//!< Liczba dostepnych maszyn.
	int populationSize;	//!< Rozmiar populacji.
	int newPopulationSize;	//!< Rozmiar populacji powstalej z krzyzowania.
	double meanPopulationFitness;	//!< Srednie przystosowanie populacji.
	double mutationProbability;	//!< Prawdopodobienstwo mutacji osobnika.
	double crossoverProbability;	//!< Prawdopodobienstwo krzyzowania.
	Chromosom* bestChromosom;	//!< Liczba dostepnych maszyn.
	vector<Chromosom*> population;	//!< Aktualna populacja.
	vector<Chromosom*> newPopulation;	//!< Nowa populacja.

	Chromosom * (*selectionOperator)();	//!< Wskaznik do funkcji wybierajacej osobniki do krzyzowania.
	void (*crossoverOperator)(Chromosom* parentA, Chromosom* parentB, Chromosom* childA, Chromosom* childB);	//!< Wskaznik do funkcji krzyzujacej osobniki.

public:
	Algorithm(int jobCount, int machineCount, int populationSize, int newPopulationSize);
	virtual ~Algorithm();

	/**
	 * Funkcja tworzy poczatkowa populacje chromosomow.
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
	 * Funkcja tworzy nowa populacje.
	 */
	void generateNewPopulation();

	//TODO Operator mutacji
	//TODO Operatory krzyzowania
	//TODO Operatory selekcji
};

bool compareChromosoms(const Chromosom * A, const Chromosom * B);

#endif /* ALGORITHM_H_ */
