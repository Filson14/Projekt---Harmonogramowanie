/*
 * Database.h
 *
 *  Created on: 28 kwi 2014
 *      Author: Filson
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include "Job.h"
#include "Machine.h"

using namespace std;
/**
 * Klasa obiektu reprezentuj�cego dane wejsciowe programu.
 */
class Database{
private:
	vector<Job> jobs;			//!< Lista prac, dla kt�rych jest generowany harmonogram.
	vector<Machine> machines;	//!< Lista dost�pnych maszyn.

public:
	/**
	 * Konstruktor klasy.
	 */
	Database();

	/**
	 * Destruktor klasy.
	 */
	~Database();

	/**
	 * Getter listy prac.
	 * \return Referencja listy prac.
	 */
	vector<Job>& getJobs(){
		return jobs;
	}

	/**
	 * Getter listy maszyn.
	 * \return Referencja listy maszyn.
	 */
	vector<Machine>& getMachines(){
		return machines;
	}

	/**
	 * Funkcja odczytuj�ca plik tekstowy z danymi wejsciowymi do programu.
	 * \param filename Sciezka do pliku.
	 * \return True - jesli odczyt przebiegnie pomyslnie; False - w przeciwnym wypadku.
	 */
	bool readFromFile(const char* filename);

	/**
	 * Funkcja zapisuj�ca podane dane wejsciowe do pliku.
	 * \param filename Sciezka do pliku.
	 * \return True - jesli zapis przebiegnie pomyslnie; False - w przeciwnym wypadku.
	 */
	bool saveToFile(const char* filename);

	/**
	 * Funkcja pobieraj�ca maszyn� z listy wszystkich maszyn w bazie.
	 * \param id Id poszukiwanej maszyny.
	 * \return Wska�nik do szukanej maszyny.
	 */
	Machine* getMachine(int id);

	/**
	 * Funkcja sprawdzaj�ca czy podana maszyna zosta�a ju� wpisana do bazy.
	 * \param id Id szukanej maszyny.
	 * \return True - jesli maszyna jest w bazie; False - w przeciwnym wypadku.
	 */
	bool machineExists(int id);

	/**
	 * Funkcja dodaj�ca wygenerowan� wczesniej prac� do bazy.
	 * \param newJob Obiekt klasy Job.
	 * \return Wska�nik do nowododanej pracy.
	 */
	Job* addJob(Job newJob);

	/**
	 * Funkcja dodaj�ca czyst� (bez dodanych task�w) prac�.
	 * \return Wska�nik do nowododanej pracy.
	 */
	Job* addJob();

	/**
	 * Funkcja dodaj�ca maszyn� do bazy.
	 * \param id Id nowej maszyny.
	 * \return Wska�nik do nowododanej maszyny.
	 */
	Machine* addMachine(int id);

	/**
	 * Metoda usuwaj�ca maszyn� z bazy.
	 * \param id Id usuwanej maszyny.
	 */
	void deleteMachine(int id);

	/**
	 * Funkcja generuj�ca losowe dane wejsciowe do programu.
	 * \param jobCount Ilosc prac do wygenerowania.
	 * \param machinesCount Ilosc maszyn do u�ycia.
	 * \return Wska�nik do bie��cego obiektu klasy Database.
	 */
	Database* generateRandomData(int jobCount, int machinesCount);

	/**
	 * Metoda czyszcz�ca obiekt Database (czysci listy prac i maszyn).
	 */
	void clearDatabase();

	/**
	 * Metoda zeruj�ca dane wejsciowe programu (sprowadza dane do formu przed wykonaniem algorytmu).
	 */
	void resetDatabase();

};



#endif /* DATABASE_H_ */
