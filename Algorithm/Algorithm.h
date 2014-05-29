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
#include "../GeneticOperators/MutationOperators/MutationSwappingPoint.h"
#include "../GeneticOperators/MutationOperators/MutationSwappingSegment.h"
#include "../GeneticOperators/MutationOperators/MutationReverse.h"



class Algorithm : public QObject
{
    Q_OBJECT

private:
    AlgorithmSettings settings; //!< Struktura przechowująca ustawienia algorytmu.
    AlgorithmStatistics statistics; //!< Struktura przechowująca statystyki pracy algorytmu.
	Chromosom bestChromosom;	//!< Liczba dostepnych maszyn.
	vector<Chromosom> population;	//!< Aktualna populacja.
    vector<Chromosom> newPopulation;	//!< Nowa populacja.


public:
    Algorithm();
    Algorithm(struct AlgorithmSettings & settings);
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

    /**
     * \brief updateSettings
     * \param algorithm
     * \param operators
     */
    void updateSettings(struct AlgorithmSettings & settings);

signals:

    void newBestChromosom(Database *);
    void newStatistics(const AlgorithmStatistics & stats);

public slots:
};

bool compareChromosoms(const Chromosom & A, const Chromosom & B);

#endif /* ALGORITHM_H_ */
