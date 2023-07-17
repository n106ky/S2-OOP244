#ifndef SDDS_CSTRING_H_
#define SDDS_CSTRING_H_
namespace sdds {

	// SELF-DEFINE CSTRING LIBRARY
   void strCpy(char* des, const char* src);
   void strnCpy(char* des, const char* src, int len);
   int strLen(const char* s);
   void strCat(char* des, const char* src);
   int strCmp(const char* s1, const char* s2);
}
#endif // !SDDS_CSTRING_H_
