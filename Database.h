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

class Database{
private:
	list<Job> jobs;
	list<Machine> machines;

public:
	Database();
	~Database();

	const list<Job>& getJobs() const {
		return jobs;
	}

	const list<Machine>& getMachines() const {
		return machines;
	}
};



#endif /* DATABASE_H_ */
