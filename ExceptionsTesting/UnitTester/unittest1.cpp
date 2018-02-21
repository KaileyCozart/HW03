// Kailey Cozart
// CS-273
// Pete Tucker
// Assignment #3

#include "stdafx.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
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
			std::istringstream ss("Hello\n0");
			// std::ifstream ss("..\\UnitTester\\zeroinput.txt");  /* Alternatively, Use Resource File In This Project, Check File Path Before Running */
			std::streambuf *orig_cin = std::cin.rdbuf(ss.rdbuf());
			Assert::AreEqual(read_int("Please enter a number within the range: ", -3, 3), 0);
			std::cin.rdbuf(orig_cin);
			// ss.close(); /* Alternatively, Will Need This */
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
			std::istringstream ss("-3\n5\n10\n-2\n3");
			// std::ifstream ss("..\\UnitTester\\otherinputs.txt"); /* Alternatively, Use Resource File In This Project, Check File Path Before Running */
			std::streambuf *orig_cin = std::cin.rdbuf(ss.rdbuf());
			Assert::AreEqual(read_int("Please enter a number within the range: ", 0, 4), 3);
			std::cin.rdbuf(orig_cin);
			// ss.close(); /* Alternatively, Will Need This */
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