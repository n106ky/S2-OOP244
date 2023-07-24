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

	// CSTRING LIBRARY
	void strCpy(char* des, const char* src)
	{
		int i = 0;
		for (i = 0; src[i] != '\0'; i++)
		{
			des[i] = src[i];
		}
		des[i] = '\0';
	}
	int strLen(const char* s)
	{
		int i = 0;
		while (s[i] != '\0')
		{
			i++;
		}

		return i;
	}
	void strCat(char* des, const char* src)
	{
		int len = strLen(des);
		int i;
		for (i = 0; src[i] != '\0'; i++)
		{
			des[i + len] = src[i];
		}
		des[i + len] = '\0';
	}
}