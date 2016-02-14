#include "DataFile.h"

const std::string MESSAGE_WELCOME = "Welcome to TextBuddy. %s is ready for use";
const std::string MESSAGE_ADD_LINE = "added to %s: \"%s\"";
const std::string MESSAGE_DELETE_LINE = "deleted from %s: \"%s\"";
const std::string MESSAGE_CLEAR_CONTENTS = "all content deleted from %s";
const std::string MESSAGE_EMPTY_CONTENTS = "%s is empty";
const std::string MESSAGE_DISPLAY_CONTENTS = "%d. %s";
const std::string MESSAGE_SORTED_CONTENTS = "all content sorted alphabetically in %s";
const std::string MESSAGE_COMMAND_PROMPT = "command: ";
const std::string MESSAGE_TEXT_NAME_PROMPT = "Please input the text file: ";
const std::string MESSAGE_INVALID_COMMAND = "Invalid command inputted";

//constructor + destructor
DataFile::DataFile() {
}

DataFile::~DataFile() {
}

//setting the environment before properly executing main fucntion of TextBuddy
void DataFile::setEnvironment(int argc, char* argv[]) {
	if(checkForArguments(argc, argv) == false) { //MISSING ONE .TXT CHECKER
		_textFileName = promptForTextName();
	} else {
		_textFileName = argv[1];
	}

	if(checkForExistingTextFile() == true) {
		writeTextFiletoDataFile();
	} else {
		openNewTextFile();
	}
}

bool DataFile::checkForArguments(int argc, char* argv[]) {
	if (argc < 2) {
		return false;
	} else {
		return true;
	}
}

std::string DataFile::promptForTextName() {
	std::string textName;
	std::cout << MESSAGE_TEXT_NAME_PROMPT;
	std::cin >> textName;

	return textName;
}

bool DataFile::checkForExistingTextFile() {
	std::ifstream readFile(_textFileName);

	if (readFile.is_open()) {
		return true;
	} else {
		return false;
	}
}

void DataFile::writeTextFiletoDataFile() {
	std::string descriptionString;
	std::ifstream readFile(_textFileName);

	while (getline(readFile, descriptionString)) {	
		addLineToDataFile(descriptionString);
	}
}

void DataFile::openNewTextFile() {
	std::ofstream writeFile;

	writeFile.open(_textFileName);
}

void DataFile::displayWelcomePage() {
	sprintf_s(buffer, MESSAGE_WELCOME.c_str(), _textFileName.c_str());
	std::cout << buffer << std::endl;
}

//remove extra spaces before the inital word in the string
void DataFile::cleanInputString(std::string &descriptionString) {
	while (descriptionString[0] == ' ') {
		descriptionString.erase(descriptionString.begin()); 
	}
}

//executioning of commands
void DataFile::executeCommandUntilExit() {
	std::string input;
	std::string command;
	COMMAND_TYPE commandType;

	do {
		printCommandPrompt();
		std::cin >> command;
		std::getline(std::cin, input);

		cleanInputString(input);

		commandType = determineCommandType(command);
		executeCommand(commandType, input);

		writeContentsofDataFiletoTextFile();
	} while(commandType != EXIT);
}

void DataFile::executeCommand(COMMAND_TYPE commandType , std::string descriptionString) {
	switch(commandType) {
	case ADD:
		addLineToDataFile(descriptionString);
		printAfterAddCommandMessage(descriptionString);
		break;
	case DELETE:
		descriptionString = deleteAndReturnDeletedStringDescription(descriptionString);
		printAfterDeleteCommandMessage(descriptionString);
		break;
	case CLEAR:
		clearContentsFromDataFile();
		printAfterClearCommandMessage();
		break;
	case DISPLAY:
		displayContents();
		break;
	case SORT:
		sortDataFileAlphabetically();
		printAfterSortingAlphabetically();
		break;
	case EXIT:
		break;
	case INVALID:
		printInvalidCommand();
		break;
	}
}

//the following are functions that help detemine what command user inputted
DataFile::COMMAND_TYPE DataFile::determineCommandType(std::string command) {

	if(isAdd(command)) {
		return ADD;
	} else if(isDelete(command)) {
		return DELETE;
	} else if(isClear(command)) {
		return CLEAR;
	} else if(isDisplay(command)) {
		return DISPLAY;
	} else if(isSort(command)) {
		return SORT;
	} else if(isExit(command)) {
		return EXIT;
	} else {
		return INVALID;
	}
}

bool DataFile::isAdd(std::string command) {
	if(command.compare("add")==0) {
		return true;
	} else {
		return false;
	}
}

bool DataFile::isDelete(std::string command) {
	if(command.compare("delete")==0) {
		return true;
	} else {
		return false;
	}
}

bool DataFile::isClear(std::string command) {
	if(command.compare("clear")==0) {
		return true;
	} else {
		return false;
	}
}

bool DataFile::isDisplay(std::string command) {
	if(command.compare("display")==0) {
		return true;
	} else {
		return false;
	}
}

bool DataFile::isSort(std::string command) {
	if(command.compare("sort")==0) {
		return true;
	} else {
		return false;
	}
}

bool DataFile::isExit(std::string command) {
	if(command.compare("exit")==0) {
		return true;
	} else {
		return false;
	}
}

//the following functions are command feedback
void DataFile::printAfterAddCommandMessage(std::string descriptionString) {
	sprintf_s(buffer, MESSAGE_ADD_LINE.c_str(), _textFileName.c_str(), descriptionString.c_str());
	std::cout << buffer << std::endl;
}

void DataFile::printAfterDeleteCommandMessage(std::string descriptionString) {
	sprintf_s(buffer, MESSAGE_DELETE_LINE.c_str(), _textFileName.c_str(), descriptionString.c_str());
	std::cout << buffer << std::endl;
}

void DataFile::printAfterClearCommandMessage() {
	sprintf_s(buffer, MESSAGE_CLEAR_CONTENTS.c_str(), _textFileName.c_str());
	std::cout << buffer << std::endl;
}

void DataFile::printAfterSortingAlphabetically() {
	sprintf_s(buffer, MESSAGE_SORTED_CONTENTS.c_str(), _textFileName.c_str());
	std::cout << buffer << std::endl;
}

void DataFile::printInvalidCommand() {
	std::cout<< MESSAGE_INVALID_COMMAND <<std::endl;
}

void DataFile::printCommandPrompt() {
	std::cout<< MESSAGE_COMMAND_PROMPT;
}

//the following functions are internal functions of the object
void DataFile::addLineToDataFile(std::string descriptionString) {	
	_dataFile.push_back(descriptionString);
}

//print all content within data file with corresponding index
void DataFile::displayContents() {
	std::vector<std::string>::iterator dataFileIter = _dataFile.begin();
	int indexCount = 1; 

	if(_dataFile.empty()) { 
		sprintf_s(buffer, MESSAGE_EMPTY_CONTENTS.c_str(), _textFileName.c_str());
		std::cout << buffer << std::endl;
	} else {
		while (dataFileIter != _dataFile.end()) {
			sprintf_s(buffer, MESSAGE_DISPLAY_CONTENTS.c_str(), indexCount, (*dataFileIter).c_str());
			std::cout << buffer << std::endl;
			dataFileIter++;
			indexCount++;
		}
	}
}

std::string DataFile::deleteAndReturnDeletedStringDescription(std::string input) {
	std::string descriptionString;
	int deleteIdx;
	std::vector<std::string>::iterator dataFileIter = _dataFile.begin();
	std::istringstream iss(input);

	iss >> deleteIdx;

	dataFileIter = dataFileIter + deleteIdx - 1;
	descriptionString = *dataFileIter;
	_dataFile.erase(dataFileIter);

	return descriptionString;
}

//delete all description 
void DataFile::clearContentsFromDataFile() {
	_dataFile.clear();
}

void DataFile::sortDataFileAlphabetically() {
	std::sort(_dataFile.begin(), _dataFile.end());
}

//write the data stored in the class to the text file given by the user at the start of the program
void DataFile::writeContentsofDataFiletoTextFile() {
	std::ofstream writeFile;
	writeFile.close(); //close and reopen file to refresh the data file for overwriting
	writeFile.open(_textFileName);

	std::vector<std::string>::iterator dataFileIter = _dataFile.begin();
	while (dataFileIter != _dataFile.end()) {
		writeFile << *dataFileIter ; //write description in data structure to text file
		writeFile << std::endl;
		dataFileIter++;
	}
}


