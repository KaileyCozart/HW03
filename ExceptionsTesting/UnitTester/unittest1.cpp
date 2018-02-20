#include "stdafx.h"
#include <stdexcept>
#include <fstream>
#include <iostream>
#include "CppUnitTest.h"
#include "readint.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTester
{		
	TEST_CLASS(ReadIntTest)
	{
	public:
		
		/*
		TEST_METHOD(TestMethod1)
		{
			ifstream ss("..\\UnitTester\\zeroinput.txt");
			if (ss.fail())
				throw int(-1);
			streambuf *orig_cin = cin.rdbuf(ss.rdbuf());

			Assert::AreEqual(read_int("My prompt: ", -3, 3), 0);
			cin.rdbuf(orig_cin);
			ss.close();
		}
		*/

		TEST_METHOD(TestMethod2)
		{
			auto func = []() {
				read_int("My prompt: ", 5, 1);
			};

			Assert::ExpectException<std::invalid_argument>(func);
		}

	};
}