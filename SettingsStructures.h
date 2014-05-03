#ifndef SETTINGSSTRUCTURES_H_
#define SETTINGSSTRUCTURES_H_
#include "./SelectionOperators/SelectionOperator.h"
#include "./MutationOperators/MutationOperator.h"
#include "./CrossoverOperators/CrossoverOperator.h"

struct SettingsOperator {
	SelectionOperator * selectionOperator;
	MutationOperator * mutationOperator;
	CrossoverOperator * crossoverOperator;

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

struct SettingsProblem {
	int jobCount;
	int machineCount;

	//SettingsProblem (int jobCount, int machineCount);
	//~SettingsProblem();
};

#endif /* SettingsStructures.h */
