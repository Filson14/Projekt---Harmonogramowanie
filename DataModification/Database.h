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
	Database();
	~Database();

	/**
	 * Getter listy prac.
	 * \return Referencja listy prac.
	 */
	const vector<Job>& getJobs() const {
		return jobs;
	}

	/**
	 * Getter listy maszyn.
	 * \return Referencja listy maszyn.
	 */
	const vector<Machine>& getMachines() const {
		return machines;
	}

	bool readFromFile(const char* filename);
	bool saveToFile(const char* filename);

	Machine* getMachine(int id);
	bool machineExists(int id);

	Job* addJob(Job newJob);
	Job* addJob();
	Machine* addMachine(int id);
	void deleteMachine(int id);
};



#endif /* DATABASE_H_ */
