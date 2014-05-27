/*
 * Algorithm.h
 *
 *  Created on: Apr 27, 2014
 *      Author: Wojtek
 */

#ifndef ALGORITHM_H_
#define ALGORITHM_H_
#include <QObject>
#include <vector>
#include <algorithm>
#include "Chromosom.h"
#include "SettingsStructures.h"
#include "StatisticsStructure.h"
#include "../GeneticOperators/SelectionOperators/SelectionTournament.h"
#include "../GeneticOperators/SelectionOperators/SelectionRoulette.h"
#include "../GeneticOperators/CrossoverOperators/CrossoverOnePoint.h"
#include "../GeneticOperators/CrossoverOperators/CrossoverTwoPoint.h"
#include "../GeneticOperators/MutationOperators/MutationSwapping.h"
#include "../GeneticOperators/MutationOperators/MutationInversion.h"



class Algorithm : public QObject
{

    Q_OBJECT
private:
	int maxEpochs;	//!< Maksymalna liczba epok;
	int maxEpochsWithoutChange;	//!< Maksymalna liczba epok bez zmiany najlepszego osobnika.
	int populationSize;	//!< Rozmiar populacji.
    int newPopulationSize;	//!< Rozmiar populacji powstalej z krzyzowania.
	double mutationProbability;	//!< Prawdopodobienstwo mutacji osobnika.
	double crossoverProbability;	//!< Prawdopodobienstwo krzyzowania.
	Chromosom bestChromosom;	//!< Liczba dostepnych maszyn.
	vector<Chromosom> population;	//!< Aktualna populacja.
	vector<Chromosom> newPopulation;	//!< Nowa populacja.

	SelectionOperator * selectionOperator;	//!< Operator selekcji osobnikow.
	MutationOperator * mutationOperator;	//!< Operator mutacji osobnik
	CrossoverOperator * crossoverOperator;	//!< Operator krzyzowania osobnikow.
    AlgorithmStatistics statistics; //!< Struktura przechowująca statystyki pracy algorytmu.

public:
    Algorithm(struct SettingsAlgorithm & algorithm, struct SettingsOperator & operators);
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

signals:
public slots:
};

bool compareChromosoms(const Chromosom & A, const Chromosom & B);

#endif /* ALGORITHM_H_ */
