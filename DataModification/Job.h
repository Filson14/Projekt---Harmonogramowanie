/*
 * Job.h
 *
 *  Created on: 28 kwi 2014
 *      Author: Filson
 */

#ifndef JOB_H_
#define JOB_H_

#include <vector>
#include <iostream>
#include "Task.h"
#include "Machine.h"

using namespace std;
/**
 * Klasa obiektu reprezentuj¹cego pojedyñcz¹ pracê do wykonania.
 */
class Job{
private:
	vector<Task> taskList;	//!< Wektor zadañ dla danej pracy.

public:
	Job();
	~Job();

	/**
	 * Getter waktora zadañ.
	 * \return Referencja do wektora zadañ.
	 */
	const vector<Task>& getTaskList() const {
		return taskList;
	}

	void addTask(Machine* machine, int startTime, int duration);

	void addTask(Task newTask);
	void deleteTask(int machineId);
};



#endif /* JOB_H_ */
