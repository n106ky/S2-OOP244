/*
	OOP244 WS4-LAB

	KA YING, CHAN
	123231227
	kchan151@myseneca.ca

	MOHAMMAD SHAMAS
	NEE

	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	2023 JUN 8
*/
#include "cstring.h"
namespace sdds {
	void strCpy(char* des, const char* src)
	{
		int i = 0;
		for (i = 0; src[i] != '\0'; i++)
		{
			des[i] = src[i];
		}
		des[i] = '\0';
	}

	int strCmp(const char* s1, const char* s2)
	{
		int i, res = 0;
		for (i = 0; s1[i] != '\0'; i++)
		{
			if (s1[i] > s2[i]) {
				res = 1;
			}
			else if (s2[i] > s1[i]) {
				res = -1;
			}
			else {
				res = 0;
			}
		}

		return res;
	}

	// returns the length of the C-string in characters
	int strLen(const char* s)
	{
		int i = 0;
		while (s[i] != '\0')
		{
			i++;
		}

		return i;
	}
}