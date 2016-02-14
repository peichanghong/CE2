#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class dataFile {
private:
	//internal variables and data structure
	std::vector<std::string> _dataStructure;
	std::string _dataFile; 

	//object's internal function for commands
	void addDescription(std::string descriptionString);
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
	dataFile(std::string textFile); //create or read a text file
	~dataFile(void);
};

