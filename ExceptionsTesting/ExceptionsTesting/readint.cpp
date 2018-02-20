#include "stdafx.h"
#include "readint.h"
#include <iostream>
#include <stdexcept>
#include <limits>
#include <ios>
#include <string>
using namespace std;

int read_int(const string &prompt, int low, int high)
{
	cin.exceptions(ios::failbit | ios::badbit);
	int num = 0;
	bool run = true;
	while (run) {

		try {
			if (high <= low) {
				throw std::invalid_argument("Throwing invalid_argument");  // Throw invalid_argument exception which is handled by man's catch() block
			}
			cout << prompt;
			cin >> num;
			if (num >= high || num <= low) {
				cout << "The value you entered was not inside the range. Please try another number." << endl;
				throw std::range_error("Throwing range_error");
			}
			else {
				run = false;
			}
		}
		catch (ios_base::failure) {
			cout << "catch ios_base::failure called in read_int" << endl;
			cout << "Invalid Input" << endl;
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
		catch (std::range_error& ex) {  // Deals with user entering values outside the range specified by high and low
			cout << "catch range_error called in read_int" << endl;
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}

	}
	return num;
}