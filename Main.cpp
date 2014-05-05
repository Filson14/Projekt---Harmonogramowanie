#include <iostream>
#include "./DataModification/Database.h"
#include "./DataModification/Job.h"
#include "./DataModification/Machine.h"
#include "./DataModification/Task.h"
#include "Algorithm.h"
int main(int argc, char *argv[]){
	srand(time(NULL));

	Chromosom::getJobDatabase().readFromFile("test.txt");
	Chromosom::setJobCount(Chromosom::getJobDatabase().getJobsAmount());
	Chromosom::setMachineCount(Chromosom::getJobDatabase().getMachinesAmount());





	return 0;
}
