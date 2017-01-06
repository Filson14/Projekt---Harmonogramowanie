#include "Machine.h"

using namespace std;

Machine::Machine(int id){
	this->id = id;
    this->label = "Machine " + to_string(id);
}

Machine::Machine(int id, string label){
    this->id = id;
    this->label = label;
}

Machine::~Machine(){

}
