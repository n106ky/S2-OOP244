/*
	OOP244 MS1

	KA YING, CHAN
	123231227
	kchan151@myseneca.ca

	MOHAMMAD SHAMAS
	NEE

	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	2023 JULY 9
*/
#include <iostream>
#include "Utils.h"
using namespace std;
namespace sdds {
	// FOR MENU:
	int getValidSelect(int min, int max) {
		int input;
		bool isValid = false;
		while (isValid == false) {
			cin >> input;
			if (!cin || input < min || input > max) {
				cout << "Invalid Selection, try again: ";
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else {
				isValid = true;
			}
		}
		return input;
	}
}