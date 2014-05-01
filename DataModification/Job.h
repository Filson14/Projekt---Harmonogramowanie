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
 * Klasa obiektu reprezentuj�cego pojedy�cz� prac� do wykonania.
 */
class Job{
private:
	vector<Task> taskList;	//!< Wektor zada� dla danej pracy.

public:
	Job();
	~Job();

	/**
	 * Getter waktora zada�.
	 * \return Referencja do wektora zada�.
	 */
	const vector<Task>& getTaskList() const {
		return taskList;
	}

	void addTask(Machine* machine, int startTime, int duration);

	void addTask(Task newTask);
	void deleteTask(int machineId);
};



#endif /* JOB_H_ */
