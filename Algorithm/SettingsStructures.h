#ifndef SETTINGSSTRUCTURES_H_
#define SETTINGSSTRUCTURES_H_
#include "./SelectionOperators/SelectionOperator.h"
#include "./MutationOperators/MutationOperator.h"
#include "./CrossoverOperators/CrossoverOperator.h"

struct SettingsOperator {
	SelectionOperator * selectionOperator;	//!< Wskaznik do klasy pelniacej funkcje operatora selekcji.
	MutationOperator * mutationOperator;	//!< Wskaznik do klasy pelniacej funkcje operatora mutacji.
	CrossoverOperator * crossoverOperator;	//!< Wskaznik do klasy pelniacej funkcje operatora krzyzowania.

	//SettingsOperator(SelectionOperator * selectionOperator, MutationOperator * mutationOperator, CrossoverOperator * crossoverOperator);
	//~SettingsOperator();
};

struct SettingsAlgorithm {
	int maxEpochs;	//!< Maksymalna liczba epok;
	int maxEpochsWithoutChange;	//!< Maksymalna liczba epok bez zmiany najlepszego osobnika.
	int populationSize;	//!< Rozmiar populacji.
	int newPopulationSize;	//!< Rozmiar populacji powstalej z krzyzowania.
	double mutationProbability;	//!< Prawdopodobienstwo mutacji osobnika.
	double crossoverProbability;	//!< Prawdopodobienstwo krzyzowania.

	//SettingsAlgorithm(int maxEpochs, int maxEpochsWithoutChange, int populationSize, int newPopulationSize, int mutationProability, int crossoverProbability);
	//~SettingsAlgorithm();
};

#endif /* SettingsStructures.h */
