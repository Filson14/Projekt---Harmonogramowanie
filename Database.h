/*
 * Database.h
 *
 *  Created on: 28 kwi 2014
 *      Author: Filson
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include <list>
#include <iostream>
#include "Job.h"
#include "Machine.h"

using namespace std;
/**
 * Klasa obiektu reprezentuj�cego dane wejsciowe programu.
 */
class Database{
private:
	list<Job> jobs;			//!< Lista prac, dla kt�rych jest generowany harmonogram.
	list<Machine> machines;	//!< Lista dost�pnych maszyn.

public:
	Database();
	~Database();

	/**
	 * Getter listy prac.
	 */
	const list<Job>& getJobs() const {
		return jobs;
	}

	/**
	 * Getter listy maszyn.
	 */
	const list<Machine>& getMachines() const {
		return machines;
	}
};



#endif /* DATABASE_H_ */
