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
 * Klasa obiektu reprezentuj¹cego pojedyncze zadanie w ramach danej pracy.
 */
class Task{
private:
	Machine* machine;	//!< WskaŸnik do maszyny u¿ytej w zadaniu.
	int start;		//!< Czas rozpoczêcia zadania.
	int time;		//!< Czas trwania zadania.

public:
	Task();
	~Task();

	/**
	 * Getter maszyny.
	 * \return WskaŸnik do maszyny.
	 */
	const Machine*& getMachine() const {
		return machine;
	}

	/**
	 * Setter maszyny.
	 * \param machine WskaŸnik do maszyny.
	 */
	void setMachine(const Machine*& machine) {
		this->machine = machine;
	}

	/**
	 * Getter czasu pocz¹tkowego zadania.
	 * \return Czas rozpoczêcia zadania
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
