#ifndef SETTINGSSTRUCTURES_H_
#define SETTINGSSTRUCTURES_H_
#include "./SelectionOperators/SelectionOperator.h"
#include "./MutationOperators/MutationOperator.h"
#include "./CrossoverOperators/CrossoverOperator.h"

struct SettingsOperator {
	const SelectionOperator * selectionOperator;
	const MutationOperator * mutationOperator;
	const CrossoverOperator * crossovoerOperator;

	//SettingsOperator(SelectionOperator * selectionOperator, MutationOperator * mutationOperator, CrossoverOperator * crossoverOperator);
	//~SettingsOperator();
};

struct SettingsAlgorithm {
	const int maxEpochs;	//!< Maksymalna liczba epok;
	const int maxEpochsWithoutChange;	//!< Maksymalna liczba epok bez zmiany najlepszego osobnika.
	const int populationSize;	//!< Rozmiar populacji.
	const int newPopulationSize;	//!< Rozmiar populacji powstalej z krzyzowania.
	const double mutationProbability;	//!< Prawdopodobienstwo mutacji osobnika.
	const double crossoverProbability;	//!< Prawdopodobienstwo krzyzowania.

	//SettingsAlgorithm(int maxEpochs, int maxEpochsWithoutChange, int populationSize, int newPopulationSize, int mutationProability, int crossoverProbability);
	//~SettingsAlgorithm();
};

struct SettingsProblem {
	const int jobCount;
	const int machineCount;

	//SettingsProblem (int jobCount, int machineCount);
	//~SettingsProblem();
};

#endif /* SettingsStructures.h */
