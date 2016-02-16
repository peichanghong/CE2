#include "stdafx.h"
#include "CppUnitTest.h"
#include "DataFile.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DataFileTest
{		
	TEST_CLASS(DataFileTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			DataFile DatafileTest;
			DatafileTest.displayWelcomePage();
		}

	};
}