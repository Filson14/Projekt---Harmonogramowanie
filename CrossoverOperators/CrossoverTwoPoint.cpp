/*
 * CrossoverTwoPoint.cpp
 *
 *  Created on: May 2, 2014
 *      Author: Wojtek
 */

#include "CrossoverTwoPoint.h"

CrossoverTwoPoint::CrossoverTwoPoint() {
	// TODO Auto-generated constructor stub

}

CrossoverTwoPoint::~CrossoverTwoPoint() {
	// TODO Auto-generated destructor stub
}

void CrossoverTwoPoint::crossChromosoms(const Chromosom & parentA, const Chromosom & parentB, Chromosom & childA, Chromosom & childB) {
	int crossoverPoint1, crossoverPoint2;
	const vector<int> parentAGenotype = parentA.getGenotype();
	const vector<int> parentBGenotype = parentB.getGenotype();
	vector<int> childAGenotype = parentA.getGenotype();
	vector<int> childBGenotype = parentB.getGenotype();

	crossoverPoint1 = crossoverPoint2 = (rand() % (parentAGenotype.size() - 2)) + 1;
	while (crossoverPoint1  == crossoverPoint2)
		crossoverPoint2 = (rand() % (parentAGenotype.size() - 2)) + 1;

	if (crossoverPoint1 > crossoverPoint2) {
		int temp = crossoverPoint1;
		crossoverPoint1 = crossoverPoint2;
		crossoverPoint2 = temp;
	}
	cout << "Crossover Point1: " << crossoverPoint1 << " Crossover Point2: " << crossoverPoint2 << endl;

	for(int i = 0; i < crossoverPoint1; i++) {
		childAGenotype[i] = parentBGenotype[i];
		childBGenotype[i] = parentAGenotype[i];
	}

	for(int i = 0; i < crossoverPoint2; i++) {
			childAGenotype[i] = parentBGenotype[i];
			childBGenotype[i] = parentAGenotype[i];
		}

	childA.setGenotype(childAGenotype);
	childB.setGenotype(childBGenotype);
}
