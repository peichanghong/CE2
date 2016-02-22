#include "stdafx.h"
#include "CppUnitTest.h"
#include "DataFile.cpp"
#include "MemoryPackage.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DataFileTest
{		
    TEST_CLASS(DataFileTest) {
public:

    TEST_METHOD(AddLineTest)
    {
        {
            DataFile DataFileTest;
            std::string actualString;
            std::string expectedString = "Insert 1 line";

            DataFileTest.addLineToDataFile("Insert 1 line");

            actualString = (DataFileTest._dataFile[0]).getString();
            Assert::AreEqual(expectedString, actualString );
        }
    }

    TEST_METHOD(SortingTest) {
        DataFile DataFileTest;
        std::string actualString;
        std::string expectedString[4] = {"abba","bob","cat","rabbit"};
        int i = 0;

        DataFileTest.displayWelcomePage();
        DataFileTest.addLineToDataFile("cat");
        DataFileTest.addLineToDataFile("rabbit");
        DataFileTest.addLineToDataFile("bob");
        DataFileTest.addLineToDataFile("abba");

        DataFileTest.sortDataFileAlphabetically();

        while(i!=4) {
            actualString = (DataFileTest._dataFile[i]).getString();
            Assert::AreEqual(expectedString[i], actualString );
            i++;
        }
    }

    TEST_METHOD(DeleteTest) {
        DataFile DataFileTest;
        std::string actualString;
        std::string expectedString[3] = {"cat","bob","abba"};
        std::string returnString;
        std::string expectedReturnString = "rabbit";
        int i = 0;

        DataFileTest.displayWelcomePage();
        DataFileTest.addLineToDataFile("cat");
        DataFileTest.addLineToDataFile("rabbit");
        DataFileTest.addLineToDataFile("bob");
        DataFileTest.addLineToDataFile("abba");

        DataFileTest.updateNumberingToDataFile();
        DataFileTest.createDisplayList();

        returnString = DataFileTest.deleteAndReturnDeletedStringDescription("2");

        Assert::AreEqual(expectedReturnString, returnString );
        while(i!=3) {
            actualString = (DataFileTest._dataFile[i]).getString();
            Assert::AreEqual(expectedString[i], actualString );
            i++;
        }
    }

    TEST_METHOD(SearchAndDeleteTest) {
        DataFile DataFileTest;
        std::string actualString;
        std::string expectedString[3] = {"cat","bob","abba"};
        std::string returnString;
        std::string expectedReturnString = "rabbit";
        int i = 0;

        DataFileTest.displayWelcomePage();
        DataFileTest.addLineToDataFile("cat");
        DataFileTest.addLineToDataFile("rabbit");
        DataFileTest.addLineToDataFile("bob");
        DataFileTest.addLineToDataFile("abba");

        DataFileTest.updateNumberingToDataFile();
        DataFileTest.searchForKeywords("bb");

        returnString = DataFileTest.deleteAndReturnDeletedStringDescription("1");

        Assert::AreEqual(expectedReturnString, returnString );
        while(i!=3) {
            actualString = (DataFileTest._dataFile[i]).getString();
            Assert::AreEqual(expectedString[i], actualString );
            i++;
        }
    }
    };
}