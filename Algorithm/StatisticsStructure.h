#ifndef STATISTICSSTRUCTURE_H
#define STATISTICSSTRUCTURE_H

#include <vector>

struct AlgorithmStatistics {
    int epoch;  //!< Numer aktualnej epoki.
    int lastImprovement;    //!< Ilość epok od wyboru najlepszego chromosomu.
    int sameParents;    //!< Ilość wyboru takich samych rodziców do krzyżowania.
    int mutationCount;  //!< Ilość przeprowadzonych mutacji.
    int crossoverCount; //!< Ilość przeprowadzonych krzyżowań.
    int invalidSolutions;   //!< Ilość niepoprawnych chromosomów powstałych po krzyżowaniu.

    vector<int> bestFitness;    //!< Struktura przechowująca wartości fitness najlepszego osobnika.
    vector<double> populationFitness;   //!< Struktura przechowująca wartości fitness populacji.

};


#endif // STATISTICSSTRUCTURE_H
