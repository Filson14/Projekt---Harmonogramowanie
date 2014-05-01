#include "Job.h"

Job::Job(){

}

Job::~Job(){
	this->taskList.clear();
}

void Job::addTask(Machine* machine, int startTime, int duration){
	Task newTask(machine, startTime, duration);
	this->taskList.push_back(newTask);
}

void Job::addTask(Task newTask){
	taskList.push_back(newTask);
}

void Job::deleteTask(int machineId){
	int i=0;
	while(i<=taskList.size()-1 && taskList[i].getMachine()->getId()!=machineId){
		i++;
	}
	if(i < taskList.size()){
		int timeToDelete = taskList[i].getTime();
		taskList.erase(taskList.begin()+i);
		for(int j=i; j<taskList.size(); j++){
			int currentStart = taskList[j].getStart();
			taskList[j].setStart(currentStart - timeToDelete);
		}
	}
}

void Job::changeTaskDuration(int machineId, int duration){
	int i=0;
	if(duration >= 0){
		while(i<=taskList.size()-1 && taskList[i].getMachine()->getId()!=machineId){
			i++;
		}
		if(i < taskList.size()){
			int diff = duration - taskList[i].getTime();
			taskList[i].setTime(duration);
			for(int j=i+1; j<taskList.size(); j++){
				int currentStart = taskList[j].getStart();
				taskList[j].setStart(currentStart + diff);
			}
		}
	}
}
