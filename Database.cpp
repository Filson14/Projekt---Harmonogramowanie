#include "Database.h"

Database::Database(){
	readFromFile("test.txt");
}

Database::~Database(){

}

bool Database::readFromFile(const char* filename){

	ifstream inputFile;
	int jobCount, machinesCount;
	string data;
	vector<string> fields;
	inputFile.open(filename, ios::in);
	if(inputFile.good()){
		while(getline(inputFile, data, 'x')){
		   fields.push_back(data);
		}
		if(fields.capacity() != 2){
			cout << "Plik nieprawid³owy." << endl;
			return false;
		}
		istringstream(fields[0]) >> jobCount;
		istringstream(fields[1]) >> machinesCount;
		fields.clear();

		cout << jobCount << "x" << machinesCount << endl;

/*		while(getline(inputFile, data, ' ')){
			cout << data << "__" << endl;

		}
*/
	}else{
		cout << "Wyst¹pi³ b³¹d podczas odczytu pliku.\n";
	}



	inputFile.close();
	return true;
}

bool Database::machineExists(int id){
	bool result = false;
	for(int i=0; i<machines.capacity(); i++){
		if(machines[i].getId() == id){
			result = true;
			break;
		}
	}
	return result;
}

