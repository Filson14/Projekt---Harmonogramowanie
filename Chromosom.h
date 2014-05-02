/*!
 * 	\file Chromosom.h
    \brief Naglowek klasy Chromosom.

    Szczegolowy opis.
*/

#ifndef CHROMOSOM_H_
#define CHROMOSOM_H_

#include <iostream>
#include <vector>
#include "DataModification/Database.h"
using namespace std;

class Chromosom {
private:
	static int jobCount;	//!< Liczba zadan do wykonania.
	static int machineCount;	//!< Liczba dostepnych maszyn.
    static Database jobDatabase; //!< baza danych
	int fitness;	//!< Ocena chromosomu (jakosc rozwiazania).
	vector<int> genotype;	//!< Genotyp chromosomu (przechowuje rozwiazanie).

public:
	Chromosom();
    Chromosom(vector<int>);
    Chromosom(vector<int> ,int , int);

	virtual ~Chromosom();

	/**
	 * Funkcja ustawia zmienna statyczna jobCount.
	 * \param jobCount liczba zadan do wykoniania
	 */
	static void setJobCount(int jobCount);

	/**
	 * Funkcja ustawia zmienna statyczna machineCount.
	 * \param machineCount liczba dostepnych maszyn.
	 */
	static void setMachineCount(int machineCount);

	/**
	 * Funkcja pobiera wartosc fitness chromosomu.
	 * \return wartosc zmiennej fitness.
	 */

	static void setJobDatabase(Database&);

	int getFitness() const;

	/**
	 * Funkcja pobiera referencje do genotypu chromosomu.
	 * \return referencja do genotypu chromosoma (const).
	 */
	const vector<int>& getGenotype() const;

	static Database& getJobDatabase();

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

	/**
	 * Funkcja wypisuje genotyp.
	 */

	 void printGenotype();

	 void updateDatabaseWithStartTimes();

	 void setRandomFitness();



};

#endif /* CHROMOSOM_H_ */
