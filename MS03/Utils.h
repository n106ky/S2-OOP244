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
#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_

namespace sdds {
	// FOR MENU:
	int getValidSelect(int min, int max);

	// CSTRING LIBRARY
	void strCpy(char* des, const char* src);
	int strLen(const char* s);
	void strCat(char* des, const char* src);
}
#endif // SDDS_UTILS_H__
