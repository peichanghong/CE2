#pragma once
#include <string>
#include <iostream>

class MemoryPackage {
private:
	int _index;
	std::string _taskString;
public:
	MemoryPackage(std::string descriptionString);
	~MemoryPackage(void);
	int getIndex();
	std::string getString();
	void updateIdx(int index);
};

class MessagePackageSorter {
public:
	MessagePackageSorter();
	~MessagePackageSorter();
	bool operator() ( MemoryPackage& lhs,  MemoryPackage& rhs);
};

