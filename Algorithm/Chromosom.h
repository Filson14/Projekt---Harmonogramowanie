/*!
 * 	\file Chromosom.h
    \brief Naglowek klasy Chromosom.

    Szczegolowy opis.
*/

#ifndef CHROMOSOM_H_
#define CHROMOSOM_H_

#define RANDOMREPAIR 50

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include "../DataModification/Database.h"
using namespace std;

/**
 * Klasa przechowuje chromosom. Ka�dy chromosom odpowiada jednemu poprawnemu rozwi�zaniu problemu.
 * Krzy�uj�c oraz mutuj�c wybrane chromosomy zbli�amy si� do optymalnego rozwi�zania.
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
	 * Domy�lny konstruktor klasy Chromosom.
	 * Tworzony Chromosom ma pusty genotyp.
	 */
	Chromosom();
	/**
	 * Konstruktor kt�ry pozwala na pocz�tkowe ustawienie genotypu.
	 * \param genotype genotyp chromosomu
	 */
    Chromosom(vector<int> genotype);
    /**
	 * Konstruktor kt�ry pozwala na pocz�tkowe ustawienie bazy danych wej�ciowych, liczby zada� oraz liczby maszyn.
	 * \param jobDatabase baza danych wej�ciowych.
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

	static int getMachineCount() ;
	static int getJobCount() ;
	bool isValid();

	/**
	 * Funkcja pobiera wartosc fitness chromosomu.
	 * \return wartosc zmiennej fitness.
	 */
	 int getFitness() const;

    /**
	 * Funkcja ustawia baze danych wej�ciowych dla algorytmu.
	 * \param jobDatabase Baza danych wej�ciowych
	 */
	static void setJobDatabase(Database& jobDatabase);


	/**
	 * Funkcja zwraca referencje do genotypu chromosomu.
	 * \return referencja do genotypu chromosoma (const).
	 */
	const vector<int>& getGenotype() const;

    /**
	 * Funkcja zwraca referencje do bazy danych wej�ciowych.
	 * \return referencja do bazy danych wej�ciowych.
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
	 * Funkcja wypisuje genotyp na standardowe wyj�cie (konsol�).
	 */
    void printGenotype() const;

    void printChromosom() const;

    /**
	 * Funkcja aktualizuje baz� danych wej�ciowych o czasu rozpocz�cia poszczeg�lnych zada� w ka�dej z prac.
	 */
    void updateDatabaseWithStartTimes();

    /**
	 * Funkcja ustawia zmienn� fitness na losow� warto�� z zakresu 0-999 (w celach testowych).
	 */
    void setRandomFitness();

    bool repairChromosom();



};

#endif /* CHROMOSOM_H_ */
