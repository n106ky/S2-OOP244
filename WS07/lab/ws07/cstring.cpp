#include "cstring.h"
namespace sdds {
	void strCpy(char* des, const char* src) {
		int i = 0;
		for (i = 0; src[i] != '\0'; i++) {
			des[i] = src[i];
		}
		des[i] = '\0';
	}
	void strnCpy(char* des, const char* src, int len) {
		int i = 0;
		while (len > 0) {
			des[i] = src[i];
			i++;
			len--;
		}
	}
	int strLen(const char* s) {
		int i = 0;
		while (s[i] != '\0') {
			i++;
		}
		return i;
	}
	void strCat(char* des, const char* src) {
		int len = strLen(des);
		int i;
		for (i = 0; src[i] != '\0'; i++) {
			des[i + len] = src[i];
		}
		des[i + len] = '\0';
	}
	int strCmp(const char* s1, const char* s2) {
		int i, res = 0;
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
}