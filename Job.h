/*
 * Job.h
 *
 *  Created on: 28 kwi 2014
 *      Author: Filson
 */

#ifndef JOB_H_
#define JOB_H_

#include <list>
#include <iostream>
#include "Task.h"
#include "Machine.h"

using namespace std;
/**
 * Klasa obiektu reprezentuj¹cego pojedyncz¹ pracê do wykonania.
 */
class Job{
private:
	list<Task> taskList;	//!< Lista zadañ dla danej pracy.

public:
	Job();
	~Job();

	/**
	 * Getter listy zadañ.
	 */
	const list<Task>& getTaskList() const {
		return taskList;
	}
};



#endif /* JOB_H_ */
