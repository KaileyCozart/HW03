#include "stdafx.h"
#include "readint.h"
#include <iostream>
#include <stdexcept>
#include <limits>
#include <ios>
#include <string>
using namespace std;

int main()
{
	int low, high;
	do {
		try
		{
			cin.exceptions(ios::failbit | ios::badbit);
			cout << "Enter the range of values to read.\n";
			cout << "low: ";
			cin >> low;
			cout << "high: ";
			cin >> high;
			int number = read_int("Please enter a number within the range: ", low, high);
			cout << "You entered " << number << endl;
		}
		catch (ios_base::failure) {
			cout << "catch ios_base::failure called in main()" << endl;
			cout << "Invalid Input" << endl;
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
		catch (std::invalid_argument &e) {
			cout << "catch invalid_argument::failure called in main()" << endl;
		}
	} while (true);
}

