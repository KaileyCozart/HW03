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
		
		TEST_METHOD(TestCase1)
		{
			std::ifstream ss("..\\UnitTester\\zeroinput.txt");
			if (ss.fail())
				throw int(-1);
			std::streambuf *orig_cin = std::cin.rdbuf(ss.rdbuf());

			Assert::AreEqual(read_int("Please enter a number within the range: ", -3, 3), 0);
			std::cin.rdbuf(orig_cin);
			ss.close();
		}

		TEST_METHOD(TestCase2)
		{
			auto func = []() {
				read_int("Please enter a number within the range: ", 5, 1);
			};

			Assert::ExpectException<std::invalid_argument>(func);
		}

		TEST_METHOD(TestCase3)
		{
			std::ifstream ss("..\\UnitTester\\otherinputs.txt");
			if (ss.fail())
				throw int(-1);
			std::streambuf *orig_cin = std::cin.rdbuf(ss.rdbuf());

			Assert::AreEqual(read_int("Please enter a number within the range: ", 0, 4), 0);
			std::cin.rdbuf(orig_cin);
			ss.close();
		}

		TEST_METHOD(TestCase4)
		{
			auto func = []() {
				read_int("Please enter a number within the range: ", 0, 0);
			};

			Assert::ExpectException<std::invalid_argument>(func);
		}

	};
}