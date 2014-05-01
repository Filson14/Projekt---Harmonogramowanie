#include "Database.h"

Database::Database(){

}

Database::~Database(){

}

bool Database::readFromFile(const char* filename){
	bool result = false;
	ifstream inputFile;
	int jobCount, machinesCount, tmp, flag=0;
	string data;
	vector<string> fields;
	vector<int> newMachines, times;
	inputFile.open(filename, ios::in);
	if(inputFile.good()){
		int pos = 0;
		getline(inputFile, data);

		while(data[pos] != 'x'){
			pos++;
		}
		istringstream(data.substr(0,pos)) >> jobCount;
		istringstream(data.substr(pos+1,data.length()-pos-1)) >> machinesCount;

		pos = 0;
		flag = 0;

		while(getline(inputFile,data)){
			pos = 0;
			for(int i=0; i<data.length(); i++){
				if(data[i] == ' '){
					istringstream(data.substr(pos, i-pos)) >> tmp;
					pos = i+1;

					if(flag == 0){
						newMachines.push_back(tmp);
						flag = 1;
					}else if(flag == 1){
						times.push_back(tmp);
						flag = 0;
					}
				}
			}
			istringstream(data.substr(pos, data.length()-pos)) >> tmp;
			if(flag == 0){
				newMachines.push_back(tmp);
				flag = 1;
			}else{
				times.push_back(tmp);
				flag = 0;
			}
		}
		if(newMachines.size() == jobCount*machinesCount && times.size() == jobCount*machinesCount){
			for(int i=0; i<jobCount; i++){
				Job *newJob = new Job();
				int timeSummary=0;
				for(int j=0; j<machinesCount; j++){
					int number = i*machinesCount+j;
					if(machineExists(newMachines[number])){
						newJob->addTask(this->getMachine(newMachines[number]), timeSummary, times[number]);
					}else{
						newJob->addTask(this->addMachine(newMachines[number]), timeSummary, times[number]);
					}
					timeSummary += times[number];
				}
				this->addJob(*newJob);
			}
			result = true;
		}else{
			cout << "Nieprawid³owa forma pliku." << endl;
		}
	}else{
		cout << "Wyst¹pi³ b³¹d podczas odczytu pliku.\n";
	}

	inputFile.close();
	return result;
}

Machine* Database::getMachine(int id){
	Machine *result = NULL;
	for(int i=0; i<machines.size(); i++){
		if(machines[i].getId() == id){
			result = &(machines[i]);
			break;
		}
	}
	return result;
}

bool Database::machineExists(int id){
	bool result = false;
	if(getMachine(id) != 0)
		result = true;
	return result;
}

Machine* Database::addMachine(int id){
	Machine newMachine(id);
	this->machines.push_back(newMachine);
	return &(machines.back());
}

Job* Database::addJob(Job newJob){
	this->jobs.push_back(newJob);
	return &(jobs.back());
}

Job* Database::addJob(){
	Job *newJob = new Job();
	this->jobs.push_back(*newJob);
	return &(jobs.back());
}

void Database::deleteMachine(int id){
	int i = 0;
	if(machineExists(id)){
		for(i=0; i<jobs.size(); i++){
			jobs[i].deleteTask(id);
		}
		/*
		i = 0;
		while(machines[i].getId() != id)
			i++;
		if(i < machines.size()){
			machines.erase(machines.begin()+i);
		}
		*/
	}else{
		cout << "Podana maszyna nie istnieje." << endl;;
	}
}
