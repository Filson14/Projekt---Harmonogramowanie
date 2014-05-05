#include <iostream>
#include "./Algorithm.h"
#include "./DataModification/Database.h"
#include "./DataModification/Job.h"
#include "./DataModification/Machine.h"
#include "./DataModification/Task.h"


int main(int argc, char *argv[]){
	srand(time(NULL));

	Chromosom::getJobDatabase().readFromFile("/Users/Wojtek/Documents/Eclipse/Harmonogramowanie/Projekt-Harmonogramowanie/test3.txt");
	Chromosom::setJobCount(Chromosom::getJobDatabase().getJobsAmount());
	Chromosom::setMachineCount(Chromosom::getJobDatabase().getMachinesAmount());

	SettingsProblem problem = {Chromosom::getJobDatabase().getJobsAmount(), Chromosom::getJobDatabase().getMachinesAmount()};
	SettingsAlgorithm algorithm = {30, 15, 16, 20, 0.75, 0.35};
	SettingsOperator operators = {new SelectionTournament(0.5, 8), new MutationInversion(), new CrossoverTwoPoint()};

	Algorithm algo(problem, algorithm, operators);
	algo.runAlgorithm();

	return 0;
}
