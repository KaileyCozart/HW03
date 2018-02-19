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
		/*
		catch (out_of_range &oor) {  // Catch the out of range built-in exception function
			cout << oor.what() << endl;
		}
		*/
		catch (invalid_argument &e) {
			cout << "catch invalid_argument::failure called in main()" << endl;
			// cerr << "Exception: You supplied an invalid argument for read_int!\n";
		}
	} while (true);
}

