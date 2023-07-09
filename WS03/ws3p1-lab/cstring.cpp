/*
	OOP244 WS3-LAB

	KA YING, CHAN
	123231227
	kchan151@myseneca.ca

	MOHAMMAD SHAMAS
	NEE

	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	2023 MAY 31
*/
#include "cstring.h"
namespace sdds {
  

	// Copies the source character string into the destination upto "len" characters. 
	// The destination will be null terminated only if the number of the characters copied is less than "len".
	void strnCpy(char* des, const char* src, int len) {
		int i = 0;
		while (len > 0) {
			des[i] = src[i];
			i++, len--;
		}
		des[i] = '\0';
	}
}