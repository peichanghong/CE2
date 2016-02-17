//
//	TextBuddy [CS2103 CE1]
//
//	TextBuddy is a CLI C++ program that can be used to manipulate text within a file
//	
//	This program will create a text file specified by the user
//	The user can manipulate the text file with the corresponding commands
//	The program will save the text file specified whenever a command is given
//	In the instances that a text file that the user specify has existed, 
//	the informtion within the file will be transfered into TextBuddy
//	Otherwise, TextBuddy will create a new text file in the same directory
//
//	The user can input the following commands:
//	[add <text>]------- add text into the specified text file
//	[delete <number>]--	delete text at the corresponding line given by the user
//	[display]----------	display the file contents
//	[clear]------------	delete all file content in the text file
//	[exit] ------------	exit the TextBuddy program
//
//	Assumptions:
//	User will input the correct format of the commands
//	User will input a valid text file for saving the data file
//
//	File is saved after every command to prevent accidental or early termination
//@author: Pei Chang Hong

#include "DataFile.h"

std::string checkForDataFile(int argc, char* argv[]); 

int main (int argc, char* argv[]) {
	DataFile TextBuddy ;

	TextBuddy.setEnvironment(argc,argv);
	TextBuddy.displayWelcomePage();

	TextBuddy.executeCommandUntilExit();

	return 0;
}


