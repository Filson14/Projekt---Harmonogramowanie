#include "Job.h"

Job::Job(){

}

Job::~Job(){

}

void Job::addTask(Machine* machine, int startTime, int duration){
	Task *newTask = new Task(machine, startTime, duration);
	this->taskList.push_back(*newTask);
}

void Job::addTask(Task newTask){
	taskList.push_back(newTask);
}

void Job::deleteTask(int machineId){
	int i=0;
	//cout << taskList.size() << endl;
	while(taskList[i].getMachine()->getId()!=machineId && i<taskList.size()){
		//cout << taskList[i].getMachine()->getId() << endl;
		i++;
	}
	//cout << i << endl;
	if(i < taskList.size()){
		taskList.erase(taskList.begin()+i);
	}
}
