/*
	OOP244 Milestone

	KA YING, CHAN #123231227
	kchan151@myseneca.ca

	MOHAMMAD SHAMAS
	NEE

	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	MS01			: 2023 JUL 9
	MS51, MS52, MS53: 2023 AUG 3
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

	// FOR LIBAPP:
	int getValidMembership() {
		int input;
		bool isValid = false;
		while (isValid == false) {
			cout << "Enter Membership number: ";
			cin >> input;
			if (input < 10000 || input > 99999) {
				cout << "Invalid membership number, try again: ";
			}
			else {
				isValid = true;
			}
		}
		return input;
	}
}