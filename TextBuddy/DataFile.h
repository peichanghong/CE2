#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>


class DataFile {
#ifndef TESTMODE 
private:
	//internal variables and data structure
	std::vector<std::string> _dataFile;
	std::string _textFileName; 
	char buffer[255];

	enum COMMAND_TYPE {
		ADD, DELETE, CLEAR, DISPLAY, SORT, EXIT, INVALID 
	};

	//set environment stage
	bool checkForArguments(int argc, char* argv[]);
	bool checkForExistingTextFile();
	std::string promptForTextName();
	void writeTextFiletoDataFile();
	void openNewTextFile();

	//determine command type functions
	COMMAND_TYPE determineCommandType(std::string command);
	bool isAdd(std::string command);
	bool isDelete(std::string command);
	bool isClear(std::string command);
	bool isSort(std::string command);
	bool isDisplay(std::string command);
	bool isExit(std::string command);

	//object's internal function for commands
	void executeCommand(COMMAND_TYPE commandType , std::string descriptionString);

	void addLineToDataFile(std::string descriptionString);
	void displayContents();
	std::string deleteAndReturnDeletedStringDescription(std::string input); //delete description pertaining to the index and push the back queue to replace the deleted description
	void clearContentsFromDataFile(); //delete all description
	void sortDataFileAlphabetically();

	//command feedback
	void printAfterAddCommandMessage(std::string descriptionString);
	void printAfterDeleteCommandMessage(std::string descriptionString);
	void printAfterClearCommandMessage();
	void printAfterSortingAlphabetically();
	void printInvalidCommand();
	void printCommandPrompt();

	//helper function
	void cleanInputString(std::string &descriptionString);
	void writeContentsofDataFiletoTextFile(); //save data from textbuddy to a file text 

#else 
public:
	//internal variables and data structure
	std::vector<std::string> _dataFile;
	std::string _textFileName; 
	char buffer[255];

	enum COMMAND_TYPE {
		ADD, DELETE, CLEAR, DISPLAY, SORT, EXIT, INVALID 
	};

	//set environment stage
	bool checkForArguments(int argc, char* argv[]);
	bool checkForExistingTextFile();
	std::string promptForTextName();
	void writeTextFiletoDataFile();
	void openNewTextFile();

	//determine command type functions
	COMMAND_TYPE determineCommandType(std::string command);
	bool isAdd(std::string command);
	bool isDelete(std::string command);
	bool isClear(std::string command);
	bool isSort(std::string command);
	bool isDisplay(std::string command);
	bool isExit(std::string command);

	//object's internal function for commands
	void executeCommand(COMMAND_TYPE commandType , std::string descriptionString);

	void addLineToDataFile(std::string descriptionString);
	void displayContents();
	std::string deleteAndReturnDeletedStringDescription(std::string input); //delete description pertaining to the index and push the back queue to replace the deleted description
	void clearContentsFromDataFile(); //delete all description
	void sortDataFileAlphabetically();

	//command feedback
	void printAfterAddCommandMessage(std::string descriptionString);
	void printAfterDeleteCommandMessage(std::string descriptionString);
	void printAfterClearCommandMessage();
	void printAfterSortingAlphabetically();
	void printInvalidCommand();
	void printCommandPrompt();

	//helper function
	void cleanInputString(std::string &descriptionString);
	void writeContentsofDataFiletoTextFile(); //save data from textbuddy to a file text 
#endif

public:

	DataFile();
	~DataFile(void);
	void setEnvironment(int argc, char* argv[]);
	void displayWelcomePage();
	void executeCommandUntilExit();
};

