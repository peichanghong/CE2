#include "dataFile.h"
//remove extra spaces before the inital word in the string
void cleanDescriptionString(std::string &descriptionString) {
	while (descriptionString[0] == ' ') {
		descriptionString.erase(descriptionString.begin()); 
	}
}

void dataFile::welcomePage() {
	std::cout << "Welcome to TextBuddy. " << _dataFile << " is ready for use" << std::endl;
}

//determine the command type the user specify and function call the corrsponding action
bool dataFile::determineCommandType() {
	std::string commandTypeString ;
	std::string descriptionString;

	int deleteIdx;
	std::cout << "command: ";
	std::cin >> commandTypeString; 

	if (commandTypeString == "add") {
		std::getline( std::cin, descriptionString);

		cleanDescriptionString(descriptionString);
		addDescription(descriptionString);
		printAdd(descriptionString);
	}
	else {
		if (commandTypeString == "delete") {
			std::cin >> deleteIdx;

			descriptionString = deleteData(deleteIdx);
			printDelete(descriptionString);
		}
		else {
			if (commandTypeString == "clear") {
				clear();
				printClear();
			}
			else {
				if (commandTypeString == "display") {
					displayData();
				}
				else {
					if (commandTypeString == "exit") {
						return false;
					}
				}
			}
		}
	}
	return true;
}

//the following functions are command feedback
void dataFile::printAdd(std::string descriptionString) {
	std::cout << "added to "  << _dataFile << ": " << "\"" << descriptionString << "\"" << std::endl;
}

void dataFile::printDelete(std::string descriptionString) {
	std::cout << "deleted from " << _dataFile << ": " << "\"" << descriptionString << "\"" << std::endl;
}

void dataFile::printClear(){
	std::cout << "all content deleted from " << _dataFile << std::endl;
}


//the following functions are internal functions of the object
void dataFile::addDescription(std::string descriptionString) {	
	_dataStructure.push_back(descriptionString);
}

//print all content within data file with corresponding index
void dataFile::displayData() {
	std::vector<std::string>::iterator dataStructureIter = _dataStructure.begin();
	int indexCount = 1; 

	if (!_dataStructure.empty()) {
		while(dataStructureIter != _dataStructure.end()) {
			std::cout << indexCount << ". " << *dataStructureIter << std::endl;
			dataStructureIter++;
			indexCount++;
		}
	}
	if (_dataStructure.empty()) {
		std::cout << _dataFile << " is empty" << std::endl;
	}

}

std::string dataFile::deleteData(int deleteIdx) {
	std::string dataDescription;
	std::vector<std::string>::iterator dataStructureIter = _dataStructure.begin();

	dataStructureIter = dataStructureIter + deleteIdx - 1;
	dataDescription = *dataStructureIter;
	_dataStructure.erase(dataStructureIter);

	return dataDescription;
}

//delete all description 
void dataFile::clear() {
	_dataStructure.clear();
}

//write the data stored in the class to the text file given by the user at the start of the program
void dataFile::save() {
	std::ofstream writeFile;
	writeFile.close(); //close and reopen file to refresh the data file for overwriting
	writeFile.open(_dataFile);

	std::vector<std::string>::iterator dataStructureIter = _dataStructure.begin();
	while (dataStructureIter != _dataStructure.end()) {
		writeFile << *dataStructureIter ; //write description in data structure to text file
		writeFile << std::endl;
		dataStructureIter++;
	}

}

//constructor + destructor
dataFile::dataFile(std::string textFile) {
	std::ofstream writeFile;
	std::ifstream readFile(textFile);
	std::string descriptionString;

	_dataFile = textFile;

	if (readFile.is_open()) {							//check if there is an existing text file created 
		while (getline(readFile, descriptionString)) {	//write file to internal data structure
			addDescription(descriptionString);
		}
	}
	else {
		writeFile.open(_dataFile); //create text file for storage of data file
	}
}

dataFile::~dataFile(void) {
}

