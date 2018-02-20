#include "stdafx.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include "CppUnitTest.h"
#include "readint.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTester
{		
	TEST_CLASS(ReadIntTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::ifstream ss("..\\UnitTester\\zeroinput.txt");
			if (ss.fail())
				throw int(-1);
			std::streambuf *orig_cin = std::cin.rdbuf(ss.rdbuf());

			Assert::AreEqual(read_int("My prompt: ", -3, 3), 0);
			std::cin.rdbuf(orig_cin);
			ss.close();
		}

		TEST_METHOD(TestMethod2)
		{
			auto func = []() {
				read_int("My prompt: ", 5, 1);
			};

			Assert::ExpectException<std::invalid_argument>(func);
		}

	};
}