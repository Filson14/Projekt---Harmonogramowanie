/*!
 * 	\file Chromosom.h
    \brief Naglowek klasy Chromosom.

    Szczegolowy opis.
*/

#ifndef CHROMOSOM_H_
#define CHROMOSOM_H_

#include <iostream>
#include <vector>
using namespace std;

class Chromosom {
private:
	static int jobCount;	//!< Liczba zadan do wykonania.
	static int machineCount;	//!< Liczba dostepnych maszyn.
	int fitness;	//!< Ocena chromosomu (jakosc rozwiazania).
	vector<int> genotype;	//!< Genotyp chromosomu (przechowuje rozwiazanie).
	vector<int> machineSchedule;	//!< Informacje o zajetosci maszyn.
	vector<int> jobSchedule;	//!< Informacje o postepach prac.

public:
	Chromosom();
	virtual ~Chromosom();

	/**
	 * Funkcja ustawia zmienna statyczna jobCount.
	 * \param jobCount liczba zadan do wykoniania
	 */
	void setJobCount(int jobCount);

	/**
	 * Funkcja ustawia zmienna statyczna machineCount.
	 * \param machineCount liczba dostepnych maszyn.
	 */
	void setMachineCount(int machineCount);

	/**
	 * Funkcja pobiera wartosc fitness chromosomu.
	 * \return wartosc zmiennej fitness.
	 */
	int getFitness() const;

	/**
	 * Funkcja pobiera referencje do genotypu chromosomu.
	 * \return referencja do genotypu chromosoma (const).
	 */
	const vector<int>& getGenotype();

	/**
	 * Funkcja ustawia genotypu chromosomu.
	 * \param referencja do genotypu chromosomu.
	 */
	void setGenotype(vector<int>& genotype);

	/**
	 * Funkcja generuje randomowy genotyp dla chromosomu.
	 */
	void generateRandomGenotype();

	/**
	 * Funkcja oblicza przystosowanie chromosomu (fitness) na podstawie genotypu.
	 * \return wartosc zmiennej fitness.
	 */
	int countFitness() ;

};

#endif /* CHROMOSOM_H_ */
