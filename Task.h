/*
 * Task.h
 *
 *  Created on: 28 kwi 2014
 *      Author: Filson
 */

#ifndef TASK_H_
#define TASK_H_

using namespace std;

class Task{
private:
	int machine;
	int start;
	int time;

public:
	Task();
	~Task();

	int getMachine() const {
		return machine;
	}

	void setMachine(int machine) {
		this->machine = machine;
	}

	int getStart() const {
		return start;
	}

	void setStart(int start) {
		this->start = start;
	}

	int getTime() const {
		return time;
	}

	void setTime(int time) {
		this->time = time;
	}
};




#endif /* TASK_H_ */
