// Kailey Cozart
// CS-273
// Pete Tucker
// Assignment #3

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
			cin.exceptions(ios_base::failbit);
			cout << "\nEnter the range of values to read.\n";
			cout << "low: ";
			cin >> low;
			cout << "high: ";
			cin >> high;
			int number = read_int("Please enter a number within the range: ", low, high);
			cout << "You entered " << number << endl;
		}
		catch (ios_base::failure) {  // User Enters An Invalid Input for Range
			cout << "Invalid Input. Must input an integer." << endl;
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
		catch (std::invalid_argument& ia) {  // User Enters Higher Value for Lower Range
			cerr << ia.what() << endl;
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
	} while (true);
}

