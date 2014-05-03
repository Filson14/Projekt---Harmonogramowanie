/*
 * MutationInversion.cpp
 *
 *  Created on: May 3, 2014
 *      Author: Wojtek
 */

#include "MutationInversion.h"

MutationInversion::MutationInversion() {
	// TODO Auto-generated constructor stub

}

MutationInversion::~MutationInversion() {
	// TODO Auto-generated destructor stub
}

void MutationInversion::performMutation(Chromosom & chromosom) {
	int inversionPoint1, inversionPoint2;
	vector<int> genotype = chromosom.getGenotype();
	vector<int> inversedGenotype;

	inversionPoint1 = inversionPoint2 = rand() % genotype.size();
	while (inversionPoint1  == inversionPoint2)
		inversionPoint2 = rand() % genotype.size();

	if (inversionPoint1 > inversionPoint2) {
		int temp = inversionPoint1;
		inversionPoint1 = inversionPoint2;
		inversionPoint2 = temp;
	}

	for (vector<int>::iterator it = genotype.begin() + inversionPoint2; it != genotype.end(); it++)
		inversedGenotype.push_back(*it);

	for (vector<int>::iterator it = genotype.begin() + inversionPoint1; it != genotype.begin() + inversionPoint2; it++)
		inversedGenotype.push_back(*it);

	for (vector<int>::iterator it = genotype.begin(); it != genotype.begin() + inversionPoint1; it++)
			inversedGenotype.push_back(*it);

	chromosom.setGenotype(inversedGenotype);

	//TODO Usunac wypisywanie w wersji finalnej.
	cout << "swappingPoint1: " << inversionPoint1 << " swappingPoint2: " << inversionPoint2 << endl;
}

