/*
 * Machine.h
 *
 *  Created on: 28 kwi 2014
 *      Author: Filson
 */

#ifndef MACHINE_H_
#define MACHINE_H_

#include <string>
#include <iostream>

using namespace std;

/**
 * Klasa obiektu reprezentuj¹cego pojedyncz¹ maszynê.
 */
class Machine{
private:
	int id; //!< ID maszyny.
    string label; //!< Opis maszyny

public:
	/**
	 * Konstruktor klasy.
	 * \param id Id maszyny
	 */
    Machine(int id);

    /**
     * Konstruktor klasy.
     * \param id Id maszyny
     * \param label Etykieta maszyny
     */
    Machine(int id, string label);

	/**
	 * Destruktor klasy.
	 */
	~Machine();

	/**
	 * Getter dla id maszyny.
	 * \return Id maszyny.
	 */
	int getId() const {
		return id;
	}

	/**
	 * Setter dla id maszyny.
	 * \param id Id do ustawienia
	 */
	void setId(int id) {
		this->id = id;
	}

    /**
     * Getter dla etykiety maszyny.
     * \return Etykieta maszyny.
     */
    string getLabel() const {
        return label;
    }

    /**
     * Setter dla etykiety maszyny.
     * \param label Etykieta do ustawienia
     */
    void setLabel(string label) {
        this->label = label;
    }
};



#endif /* MACHINE_H_ */
