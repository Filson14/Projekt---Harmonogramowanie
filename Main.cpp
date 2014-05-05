#include <iostream>
#include "./Algorithm.h"
#include "./DataModification/Database.h"
#include "./DataModification/Job.h"
#include "./DataModification/Machine.h"
#include "./DataModification/Task.h"


int main(int argc, char *argv[]){
	srand(time(NULL));

	Chromosom::getJobDatabase().readFromFile("/Users/Wojtek/Documents/Eclipse/Harmonogramowanie/Projekt-Harmonogramowanie/test.txt");
	Chromosom::setJobCount(Chromosom::getJobDatabase().getJobsAmount());
	Chromosom::setMachineCount(Chromosom::getJobDatabase().getMachinesAmount());

	SettingsProblem problem = {Chromosom::getJobDatabase().getJobsAmount(), Chromosom::getJobDatabase().getMachinesAmount()};
	SettingsAlgorithm algorithm = {5, 5, 6, 12, 0.5, 0.5};
	SettingsOperator operators = {new SelectionTournament(0.9, 4), new MutationInversion(), new CrossoverTwoPoint()};

	Algorithm algo(problem, algorithm, operators);
	algo.runAlgorithm();

	return 0;
}
