#include "Algorithm.h"
#include <iostream>
#include "./DataModification/Database.h"
#include "./DataModification/Job.h"
#include "./DataModification/Machine.h"
#include "./DataModification/Task.h"
#include "SettingsStructures.h"

int main(int argc, char *argv[]){
	srand(time(NULL));

	Chromosom::getJobDatabase().readFromFile("test.txt");
	Chromosom::setJobCount(Chromosom::getJobDatabase().getJobsAmount());
	Chromosom::setMachineCount(Chromosom::getJobDatabase().getMachinesAmount());

	SettingsProblem problem = {Chromosom::getJobDatabase().getJobsAmount(), Chromosom::getJobDatabase().getMachinesAmount()};
	SettingsAlgorithm algorithm = {5, 5, 20, 60, 0.5, 0.5};
	SettingsOperator operators = {new SelectionTournament(0.95, 10), new MutationInversion(), new CrossoverTwoPoint()};

	Algorithm algo(problem, algorithm, operators);
	algo.runAlgorithm();


	return 0;
}
