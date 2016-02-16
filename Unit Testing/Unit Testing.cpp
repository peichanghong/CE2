#include "stdafx.h"
#include "CppUnitTest.h"
#include "DataFile.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DataFileTest
{		
	TEST_CLASS(DataFileTest)
	{
	public:
		
		TEST_METHOD(AddLineTest)
		{
			{
			DataFile DataFileTest;
			std::string actualString;
			std::string expectedString = "Insert 1 line";

			DataFileTest.addLineToDataFile("Insert 1 line");

			actualString = DataFileTest._dataFile[0];
			Assert::AreEqual(expectedString, actualString );
		}
		}

	};
}