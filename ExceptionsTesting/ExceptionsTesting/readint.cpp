#include "stdafx.h"
#include "readint.h"
#include <iostream>
#include <stdexcept>
#include <limits>
#include <ios>
using namespace std;

int read_int(const string &prompt, int low, int high)
{

	int num = 0;
	bool run = true;
	while (run) {

		try {
			if (high <= low) {
				throw invalid_argument("Throwing invalid_argument");
				// Throw invalid_argument exception which is handled by man's catch() block
			}
			cout << prompt;
			cin >> num;
			if (num >= high || num <= low) {
				// Provide Informative Message
				cout << "The value you entered was not inside the range. Please try another number." << endl;
				// Re-Prompt For New Value
				// -- No need to throw an exception
				// Throw range_error
			}
			else {
				run = false;
			}
		}

		// throw invalid_argument exception for high and low not specifying a good range
		catch (range_error) {
			// Deals with user entering values outside the range specified by high and low
			// should be handled by read_int's internal exception handler
			// which exception should read_int throw first and why
			cout << "catch range_error called in read_int" << endl;
		}
		catch (ios_base::failure) {
			cout << "catch ios_base::failure called in read_int" << endl;
			// cout << "Invalid Input" << endl;
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}

	}
	return num;
}