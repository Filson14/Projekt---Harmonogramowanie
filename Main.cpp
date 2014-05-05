#include <iostream>
#include "./Algorithm.h"
#include "./DataModification/Database.h"
#include "./DataModification/Job.h"
#include "./DataModification/Machine.h"
#include "./DataModification/Task.h"


int main(int argc, char *argv[]){
	srand(time(NULL));

	if(Chromosom::getJobDatabase().readFromFile("test5.txt")){
		Chromosom::setJobCount(Chromosom::getJobDatabase().getJobsAmount());
		Chromosom::setMachineCount(Chromosom::getJobDatabase().getMachinesAmount());

		Chromosom::getJobDatabase().presentData();

		SettingsProblem problem = {Chromosom::getJobDatabase().getJobsAmount(), Chromosom::getJobDatabase().getMachinesAmount()};
		SettingsAlgorithm algorithm = {30, 15, 16, 20, 0.75, 0.35};
		SettingsOperator operators = {new SelectionTournament(0.5, 8), new MutationInversion(), new CrossoverTwoPoint()};

		Algorithm algo(problem, algorithm, operators);
		algo.runAlgorithm();

		Chromosom::getJobDatabase().presentData();
	}
	return 0;
}
