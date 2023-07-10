/*
	OOP244 
	WS1-DIY

	KA YING, CHAN
	123231227

	MOHAMMAD SHAMAS
	NEE
*/


#include <iostream>
#include "cstring.h"

using namespace std;
namespace sdds {


	// Copies the srouce character string into the destination
	void strCpy(char* des, const char* src) {
		int i = 0;
		for (i = 0; src[i] != '\0'; i++) {
			des[i] = src[i];
		}
		des[i] = '\0';
	}

	// Copies the source character string into the destination upto "len" characters. 
	// The destination will be null terminated only if the number of the characters copied is less than "len".
	void strnCpy(char* des, const char* src, int len) {
		int i = 0;
		while (len > 0) {
			des[i] = src[i];
			i++;
			len--;
		}
	}
	
	// Compares two C-strings 
	// returns 0 if they are the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strCmp(const char* s1, const char* s2) {
		int i, res;
		for (i = 0; s1[i] != '\0'; i++) {
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

	
	// returns 0 if they are the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strnCmp(const char* s1, const char* s2, int len) {
		int i, res;
		for (i = 0; s1[i] != '\0' && len > 0; i++, len--) {
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
	int strLen(const char* s) {
		int i = 0;
		while (s[i] != '\0') {
			i++;
		}
		return i;
	}
	
	// returns the address of first occurance of "str2" in "str1"
	// returns nullptr if no match is found
	const char* strStr(const char* str1, const char* str2)
	{
		int i, j;
		int count = 0, len;
		const char* s;

		len = strLen(str2);
		for (i = 0; str1[i] != '\0' && count != len; i++) { // loop the whole string once. if str1 is a to z. [a] will be the first character.
			for (j = 0; j < len; j++) { // e.g. str2 length is 4. Starting at a, it is continuously checking [a-b-c-d] of str1, if no match with str2, next i-loop will be [b-c-d-e] of str1 and so on. 
				if (str1[i + j] == str2[j]) {
					count++;
				}
			}
		}
		//cout << "i: " << i << endl;
		if (count == len) {
			s = &str1[i - 1];
		}
		else {
			s = NULL;
		}
		return s;
	}

	// Concantinates "src" C-string to the end of "des"
	void strCat(char* des, const char* src) {
		int len = strLen(des);
		int i;
		for (i = 0; src[i] != '\0'; i++) {
			des[i + len] = src[i];
		}
		des[i + len] = '\0';
	}
}