/*
 * Task.h
 *
 *  Created on: 28 kwi 2014
 *      Author: Filson
 */

#ifndef TASK_H_
#define TASK_H_

#include "Machine.h"

using namespace std;

/**
 * Klasa obiektu reprezentuj�cego pojedyncze zadanie w ramach danej pracy.
 */
class Task{
private:
	Machine* machine;	//!< Wska�nik do maszyny u�ytej w zadaniu.
	int start;		//!< Czas rozpocz�cia zadania.
	int time;		//!< Czas trwania zadania.

public:
	Task();
	~Task();

	/**
	 * Getter maszyny.
	 * \return Wska�nik do maszyny.
	 */
	const Machine*& getMachine() const {
		return machine;
	}

	/**
	 * Setter maszyny.
	 * \param machine Wska�nik do maszyny.
	 */
	void setMachine(const Machine*& machine) {
		this->machine = machine;
	}

	/**
	 * Getter czasu pocz�tkowego zadania.
	 * \return Czas rozpocz�cia zadania
	 */
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
