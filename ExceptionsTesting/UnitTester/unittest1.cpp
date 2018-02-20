#include "stdafx.h"
#include "CppUnitTest.h"
#include "readint.h"
#include <stdexcept>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTester
{		
	TEST_CLASS(ReadIntTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			auto func = []() {
				read_int("My prompt: ", 5, 1);
			};

			Assert::ExpectException<std::invalid_argument>(func);
		}

	};
}