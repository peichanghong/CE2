#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class DataFile {
private:
	//set environment stage
	bool checkForArguments(int argc, char* argv[]);
	bool checkForExistingTextFile();
	std::string promptForTextName();
	void writeTextFiletoDataFile();
	void openNewTextFile();


	//internal variables and data structure
	std::vector<std::string> _dataFile;
	std::string _textFileName; 
	char buffer[255];

	//object's internal function for commands
	void addLineToDataFile(std::string descriptionString);
	void displayData();
	std::string deleteData(int deleteIdx); //delete description pertaining to the index and push the back queue to replace the deleted description
	void clear(); //delete all description

	//command feedback
	void printAdd(std::string descriptionString);
	void printDelete(std::string descriptionString);
	void printClear();

public:
	void welcomePage();
	bool determineCommandType(); //always return true for conducting repetition unless user input "exit" 
	void save(); //save data from textbuddy to a file text 
	DataFile();
	//DataFile(std::string textFile); //create or read a text file
	~DataFile(void);
	void setEnvironment(int argc, char* argv[]);
	void displayWelcomePage();
};

