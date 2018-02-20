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
	cin.exceptions(ios_base::failbit);
	int num = 0;
	bool run = true;
	while (run) {

		try {
			if (high <= (low+1)) {  // Using Integers -- There Must Be At Least One Integer Between Numbers Entered
				throw std::invalid_argument("The lower range must be lower than the higher range minus one.");
			}
			cout << prompt;
			cin >> num;
			if (num >= high || num <= low) {
				throw std::range_error("The value you entered was not inside the range. Please try another number.");
			}
			else {
				run = false;
			}
		}
		catch (ios_base::failure) {  // User Enters An Invalid Input for Value
			cout << "Invalid Input. Must input an integer." << endl;
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
		catch (std::range_error& re) {  // User Enters Value Outside of Specified Range
			cerr <<  re.what() << endl;
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}

	}
	return num;
}