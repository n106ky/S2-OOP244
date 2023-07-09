/*
	OOP244 WS4-LAB

	KA YING, CHAN
	123231227
	kchan151@myseneca.ca

	MOHAMMAD SHAMAS
	NEE

	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	2023 JUN 7
*/
#ifndef SDDS_CSTRING_H_
#define SDDS_CSTRING_H_
namespace sdds {
	// Copies the srouce character string into the destination
	void strCpy(char* des, const char* src);

	// Compares two C-strings 
	// returns 0 i thare the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strCmp(const char* s1, const char* s2);

	// returns the length of the C-string in characters
	int strLen(const char* s);
}
#endif // !SDDS_CSTRING_H_



