#include "Database.h"

Database::Database(){

}

Database::~Database(){
	this->clearDatabase();
}

bool Database::readFromFile(const char* filename){
	clearDatabase();
	bool result = false;
	ifstream inputFile;
	int jobCount, machinesCount, tmp, flag=0;
	string data;
	vector<string> fields;
	vector<int> newMachines, times;
	Job *newJob;

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
		int lineCounter = 0;
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
			lineCounter++;
		}
		if(lineCounter == jobCount && newMachines.size() == jobCount*machinesCount && times.size() == jobCount*machinesCount){
			for(int i=0; i<jobCount; i++){
				newJob = new Job();
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
		cout << "Wyst¹pi³ b³¹d podczas odczytu pliku." << endl;
	}

	inputFile.close();
	return result;
}

bool Database::saveToFile(const char* filename){
	bool result = false;
	ofstream outputFile;
	outputFile.open(filename, ios::out | ios::trunc);
	if(outputFile.is_open()){
		outputFile << jobs.size() << "x" << machines.size();
		for(int i=0; i<jobs.size(); i++){
			outputFile << endl;
			vector<Task> tasks = jobs[i].getTaskList();
			for(int j=0; j<tasks.size(); j++){
				if(j != 0)
					outputFile << " ";
				outputFile << tasks[j].getMachine()->getId() << " ";
				outputFile << tasks[j].getTime();
			}
		}
	}else{
		cout << "Nie uda³o siê otworzyæ pliku." << endl;
	}
	outputFile.close();
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
	Machine *newMachine = new Machine(id);
	this->machines.push_back(*newMachine);
	return newMachine;
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
		i = 0;
		while(machines[i].getId() != id)
			i++;
		if(i < machines.size()){
			machines.erase(machines.begin()+i);
		}
	}else{
		cout << "Podana maszyna nie istnieje." << endl;;
	}
}

Database* Database::generateRandomData(int jobCount, int machinesCount){
	int randMachine, randElem, timeSummary, randTime;
	Job *newJob;
	vector<int> tempVector;
	if(jobCount>0 && machinesCount>0){
		clearDatabase();
		for(int i=0; i<machinesCount; i++){
			this->addMachine(i);
			tempVector.push_back(i);
		}

		for(int i=0; i<jobCount; i++){
			newJob = new Job();
			timeSummary = 0;

			for(int j=0; j<machinesCount; j++){
				/*randElem = rand() % tempVector.size();
				//while dla bezpieczenstwa - ponowne losowanie nie powinno byc konieczne
				while(newJob->isMachineUsed(tempVector[randElem]))
					randElem = rand() % tempVector.size();
				randMachine = tempVector[randElem];
				*/
				randMachine = rand() % machinesCount;
				while(newJob->isMachineUsed(randMachine))
					randMachine = rand() % machinesCount;

				randTime = rand() % 20;
				newJob->addTask(this->getMachine(randMachine), timeSummary, randTime);
				timeSummary += randTime;
			}
			//cout << endl;
			this->addJob(*newJob);
		}
	}

	return this;
}

void Database::clearDatabase(){
	jobs.clear();
	machines.clear();
}

void Database::resetDatabase(){
	int timeSummary;
	for(int i=0; i<jobs.size(); i++){
		timeSummary = 0;
		vector<Task> &list = jobs[i].getTaskList();
		for(int j=0; j<list.size(); j++){
			list[j].setStart(timeSummary);
			timeSummary += list[j].getTime();
		}
	}
}

void Database::presentData(){
	cout << endl << "Prezentujê dane:" << endl;
	cout <<  "<maszyna>(<d³ugosc>/<start>)" << endl << endl;
	for(int i=0; i<jobs.size(); i++){
		vector<Task> tasks = jobs[i].getTaskList();
		for(int j=0; j<tasks.size(); j++){
			cout << jobs[i].getTaskList()[j].getMachine()->getId() << "(";
			cout << jobs[i].getTaskList()[j].getTime() << "/";
			cout << jobs[i].getTaskList()[j].getStart() << ")  ";
		}
		cout << endl;
	}
	cout << endl;
}

struct SettingsProblem Database::generateSettingsStruct(){
	struct SettingsProblem StngsPrblm;
	StngsPrblm.jobCount = jobs.size();
	StngsPrblm.machineCount = machines.size();
	return StngsPrblm;
}

