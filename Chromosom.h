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

/**
 * Klasa przechowuje chromosom. Ka¿dy chromosom odpowiada jednemu poprawnemu rozwi¹zaniu problemu.
 * Krzy¿uj¹c oraz mutuj¹c wybrane chromosomy zbli¿amy siê do optymalnego rozwi¹zania.
 */

class Chromosom {
private:
	static int jobCount;	//!< Liczba zadan do wykonania.
	static int machineCount;	//!< Liczba dostepnych maszyn.
    static Database jobDatabase; //!< baza danych
	int fitness;	//!< Ocena chromosomu (jakosc rozwiazania).
	vector<int> genotype;	//!< Genotyp chromosomu (przechowuje rozwiazanie).

public:
    /**
	 * Domyœlny konstruktor klasy Chromosom.
	 * Tworzony Chromosom ma pusty genotyp.
	 */
	Chromosom();
	/**
	 * Konstruktor który pozwala na pocz¹tkowe ustawienie genotypu.
	 * \param genotype genotyp chromosomu
	 */
    Chromosom(vector<int> genotype);
    /**
	 * Konstruktor który pozwala na pocz¹tkowe ustawienie bazy danych wejœciowych, liczby zadañ oraz liczby maszyn.
	 * \param jobDatabase baza danych wejœciowych.
     * \param jobCount liczba zadan do wykoniania.
     * \param machineCount liczba dostepnych maszyn.
	 */
    Chromosom(Database& jobDatabase,int jobCount, int machineCount);

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
	 int getFitness() const;

    /**
	 * Funkcja ustawia baze danych wejœciowych dla algorytmu.
	 * \param jobDatabase Baza danych wejœciowych
	 */
	static void setJobDatabase(Database& jobDatabase);


	/**
	 * Funkcja zwraca referencje do genotypu chromosomu.
	 * \return referencja do genotypu chromosoma (const).
	 */
	const vector<int>& getGenotype() const;

    /**
	 * Funkcja zwraca referencje do bazy danych wejœciowych.
	 * \return referencja do bazy danych wejœciowych.
	 */
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
	 * Funkcja wypisuje genotyp na standardowe wyjœcie (konsolê).
	 */
    void printGenotype();

    /**
	 * Funkcja aktualizuje bazê danych wejœciowych o czasu rozpoczêcia poszczególnych zadañ w ka¿dej z prac.
	 */
    void updateDatabaseWithStartTimes();

    /**
	 * Funkcja ustawia zmienn¹ fitness na losow¹ wartoœæ z zakresu 0-999 (w celach testowych).
	 */
    void setRandomFitness();



};

#endif /* CHROMOSOM_H_ */
