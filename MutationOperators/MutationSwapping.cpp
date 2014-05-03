/*
 * MutationSwapping.cpp
 *
 *  Created on: May 3, 2014
 *      Author: Wojtek
 */

#include "MutationSwapping.h"

MutationSwapping::MutationSwapping() {
	// TODO Auto-generated constructor stub

}

MutationSwapping::~MutationSwapping() {
	// TODO Auto-generated destructor stub
}

void MutationSwapping::performMutation(Chromosom & chromosom) {
	int swappingPoint1, swappingPoint2;
	vector<int> genotype = chromosom.getGenotype();

	swappingPoint1 = swappingPoint2 = rand() % genotype.size();
	while (swappingPoint1  == swappingPoint2)
		swappingPoint2 = rand() % genotype.size();

	int temp = genotype[swappingPoint1];
	genotype[swappingPoint1] = genotype[swappingPoint2];
	genotype[swappingPoint2] = temp;

	chromosom.setGenotype(genotype);

	//TODO Usunac wypisywanie w wersji finalnej.
	cout << "swappingPoint1: " << swappingPoint1 << " swappingPoint2: " << swappingPoint2 << endl;
}

