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
 * Klasa obiektu reprezentuj¹cego dane wejsciowe programu.
 */
class Database{
private:
	vector<Job> jobs;			//!< Lista prac, dla których jest generowany harmonogram.
	vector<Machine> machines;	//!< Lista dostêpnych maszyn.

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
	 * Funkcja odczytuj¹ca plik tekstowy z danymi wejsciowymi do programu.
	 * \param filename Sciezka do pliku.
	 * \return True - jesli odczyt przebiegnie pomyslnie; False - w przeciwnym wypadku.
	 */
	bool readFromFile(const char* filename);

	/**
	 * Funkcja zapisuj¹ca podane dane wejsciowe do pliku.
	 * \param filename Sciezka do pliku.
	 * \return True - jesli zapis przebiegnie pomyslnie; False - w przeciwnym wypadku.
	 */
	bool saveToFile(const char* filename);

	/**
	 * Funkcja pobieraj¹ca maszynê z listy wszystkich maszyn w bazie.
	 * \param id Id poszukiwanej maszyny.
	 * \return WskaŸnik do szukanej maszyny.
	 */
	Machine* getMachine(int id);

	/**
	 * Funkcja sprawdzaj¹ca czy podana maszyna zosta³a ju¿ wpisana do bazy.
	 * \param id Id szukanej maszyny.
	 * \return True - jesli maszyna jest w bazie; False - w przeciwnym wypadku.
	 */
	bool machineExists(int id);

	/**
	 * Funkcja dodaj¹ca wygenerowan¹ wczesniej pracê do bazy.
	 * \param newJob Obiekt klasy Job.
	 * \return WskaŸnik do nowododanej pracy.
	 */
	Job* addJob(Job newJob);

	/**
	 * Funkcja dodaj¹ca czyst¹ (bez dodanych tasków) pracê.
	 * \return WskaŸnik do nowododanej pracy.
	 */
	Job* addJob();

	/**
	 * Funkcja dodaj¹ca maszynê do bazy.
	 * \param id Id nowej maszyny.
	 * \return WskaŸnik do nowododanej maszyny.
	 */
	Machine* addMachine(int id);

	/**
	 * Metoda usuwaj¹ca maszynê z bazy.
	 * \param id Id usuwanej maszyny.
	 */
	void deleteMachine(int id);

	/**
	 * Funkcja generuj¹ca losowe dane wejsciowe do programu.
	 * \param jobCount Ilosc prac do wygenerowania.
	 * \param machinesCount Ilosc maszyn do u¿ycia.
	 * \return WskaŸnik do bie¿¹cego obiektu klasy Database.
	 */
	Database* generateRandomData(int jobCount, int machinesCount);

	/**
	 * Metoda czyszcz¹ca obiekt Database (czysci listy prac i maszyn).
	 */
	void clearDatabase();

	/**
	 * Metoda zeruj¹ca dane wejsciowe programu (sprowadza dane do formu przed wykonaniem algorytmu).
	 */
	void resetDatabase();

};



#endif /* DATABASE_H_ */
