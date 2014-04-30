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
 * Klasa obiektu reprezentuj¹cego dane wejsciowe programu.
 */
class Database{
private:
	list<Job> jobs;			//!< Lista prac, dla których jest generowany harmonogram.
	list<Machine> machines;	//!< Lista dostêpnych maszyn.

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
