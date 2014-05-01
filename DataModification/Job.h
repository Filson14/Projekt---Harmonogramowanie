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
	vector<Task>& getTaskList(){
		return taskList;
	}

	void addTask(Machine* machine, int startTime, int duration);

	void addTask(Task newTask);
	void deleteTask(int machineId);
	void changeTaskDuration(int machineId, int duration);
	//TODO: metoda sprawdzajaca czy w danym jobie u�yto ju� podanej maszyny (?)
};



#endif /* JOB_H_ */
