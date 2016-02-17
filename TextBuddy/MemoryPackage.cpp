#include "MemoryPackage.h"

MemoryPackage::MemoryPackage(std::string descriptionString) {
	_taskString = descriptionString;
}

MemoryPackage::~MemoryPackage(void) {
}

int MemoryPackage::getIndex() {
	return _index;
}
std::string MemoryPackage::getString() {
	return _taskString;
}

void MemoryPackage::updateIdx(int index) {
	_index = index;
}


MessagePackageSorter::MessagePackageSorter() {
}

MessagePackageSorter::~MessagePackageSorter(void) {
}

bool MessagePackageSorter::operator() ( MemoryPackage& lhs,  MemoryPackage& rhs)
{
	// get the field to sort by and make the comparison
	return lhs.getString( ) < rhs.getString();
}