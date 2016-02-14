#include "DataFile.h"
//remove extra spaces before the inital word in the string
void cleanDescriptionString(std::string &descriptionString) {
	while (descriptionString[0] == ' ') {
		descriptionString.erase(descriptionString.begin()); 
	}
}

void DataFile::welcomePage() {
	std::cout << "Welcome to TextBuddy. " << _textFileName << " is ready for use" << std::endl;
}

//determine the command type the user specify and function call the corrsponding action
bool DataFile::determineCommandType() {
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
void DataFile::printAdd(std::string descriptionString) {
	std::cout << "added to "  << _textFileName << ": " << "\"" << descriptionString << "\"" << std::endl;
}

void DataFile::printDelete(std::string descriptionString) {
	std::cout << "deleted from " << _textFileName << ": " << "\"" << descriptionString << "\"" << std::endl;
}

void DataFile::printClear(){
	std::cout << "all content deleted from "<< _textFileName << std::endl;
}


//the following functions are internal functions of the object
void DataFile::addDescription(std::string descriptionString) {	
	_dataFile.push_back(descriptionString);
}

//print all content within data file with corresponding index
void DataFile::displayData() {
	std::vector<std::string>::iterator dataStructureIter = _dataFile.begin();
	int indexCount = 1; 

	if (!_dataFile.empty()) {
		while(dataStructureIter != _dataFile.end()) {
			std::cout << indexCount << ". " << *dataStructureIter << std::endl;
			dataStructureIter++;
			indexCount++;
		}
	}
	if (_dataFile.empty()) {
		std::cout << _textFileName << " is empty" << std::endl;
	}

}

std::string DataFile::deleteData(int deleteIdx) {
	std::string dataDescription;
	std::vector<std::string>::iterator dataStructureIter = _dataFile.begin();

	dataStructureIter = dataStructureIter + deleteIdx - 1;
	dataDescription = *dataStructureIter;
	_dataFile.erase(dataStructureIter);

	return dataDescription;
}

//delete all description 
void DataFile::clear() {
	_dataFile.clear();
}

//write the data stored in the class to the text file given by the user at the start of the program
void DataFile::save() {
	std::ofstream writeFile;
	writeFile.close(); //close and reopen file to refresh the data file for overwriting
	writeFile.open(_textFileName);

	std::vector<std::string>::iterator dataStructureIter = _dataFile.begin();
	while (dataStructureIter != _dataFile.end()) {
		writeFile << *dataStructureIter ; //write description in data structure to text file
		writeFile << std::endl;
		dataStructureIter++;
	}

}

//constructor + destructor
DataFile::DataFile(std::string textFile) {
	std::ofstream writeFile;
	std::ifstream readFile(textFile);
	std::string descriptionString;

	_textFileName = textFile;

	if (readFile.is_open()) {							//check if there is an existing text file created 
		while (getline(readFile, descriptionString)) {	//write file to internal data structure
			addDescription(descriptionString);
		}
	}
	else {
		writeFile.open(_textFileName); //create text file for storage of data file
	}
}

DataFile::~DataFile(void) {
}

