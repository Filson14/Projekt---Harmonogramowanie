#include <iostream>
#include "./Algorithm/Algorithm.h"
#include "./DataModification/Database.h"
#include "./DataModification/Job.h"
#include "./DataModification/Machine.h"
#include "./DataModification/Task.h"


int main(int argc, char *argv[]){
	srand(time(NULL));

    if(Chromosom::getJobDatabase().readFromFile("/Users/Wojtek/Documents/Projekty/Harmonogramowanie/TestData/test1.txt")){
		Chromosom::setJobCount(Chromosom::getJobDatabase().getJobsAmount());
		Chromosom::setMachineCount(Chromosom::getJobDatabase().getMachinesAmount());

		SettingsAlgorithm algorithm = {500, 75, 20, 30, 0.85, 0.25};
		SettingsOperator operators = {new SelectionTournament(0.7, 8), new MutationInversion(), new CrossoverTwoPoint()};

        Algorithm algo(algorithm, operators);
		algo.runAlgorithm();

		Chromosom::getJobDatabase().presentData();
	}
	return 0;
}
