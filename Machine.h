/*
 * Machine.h
 *
 *  Created on: 28 kwi 2014
 *      Author: Filson
 */

#ifndef MACHINE_H_
#define MACHINE_H_

class Machine{
private:
	int id;

public:
	Machine();
	~Machine();

	int getId() const {
		return id;
	}

	void setId(int id) {
		this->id = id;
	}
};



#endif /* MACHINE_H_ */
