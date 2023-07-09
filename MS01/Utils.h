/***********************************************************************
// OOP244 Utils Module
// File	Utils.h
// Version 
// Date	
// Author	
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// 
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__

namespace sdds {
	void strCpy(char* des, const char* src);
	int strLen(const char* s);
	void strCat(char* des, const char* src);
	int getValidSelect(int min, int max);
}
#endif // SDDS_UTILS_H__
