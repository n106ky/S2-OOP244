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
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include "Date.h"
using namespace std;
namespace sdds {
   bool Date::validate() {
      errCode(NO_ERROR);
      if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
         errCode(YEAR_ERROR);
      }
      else if (m_mon < 1 || m_mon > 12) {
         errCode(MON_ERROR);
      }
      else if (m_day < 1 || m_day > mdays()) {
         errCode(DAY_ERROR);
      }
      return !bad();
   }
   int Date::mdays()const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
      mon--;
      return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
   }
   int Date::systemYear()const {
      time_t t = time(NULL);
      tm lt = *localtime(&t);
      return lt.tm_year + 1900;
   }
   void Date::setToToday() {
      time_t t = time(NULL);
      tm lt = *localtime(&t);
      m_day = lt.tm_mday;
      m_mon = lt.tm_mon + 1;
      m_year = lt.tm_year + 1900;
      errCode(NO_ERROR);
   }
   int Date::daysSince0001_1_1()const { // Rata Die day since 0001/01/01 
      int ty = m_year;
      int tm = m_mon;
      if (tm < 3) {
         ty--;
         tm += 12;
      }
      return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
   }
   Date::Date() :m_CUR_YEAR(systemYear()) {
      setToToday();
   }
   Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
      m_year = year;
      m_mon = mon;
      m_day = day;
      validate();
   }
   const char* Date::dateStatus()const {
      return DATE_ERROR[errCode()];
   }
   int Date::currentYear()const {
      return m_CUR_YEAR;
   }
   void Date::errCode(int readErrorCode) {
      m_ErrorCode = readErrorCode;
   }
   int Date::errCode()const {
      return m_ErrorCode;
   }
   bool Date::bad()const {
      return m_ErrorCode != 0;
   }
  
   ostream& operator<<(ostream& os, const Date& RO) {
      return RO.write(os);
   }
   istream& operator>>(istream& is, Date& RO) {
      return RO.read(is);
   }

   
   // reads a date from the console in the following format YYYY / MM / DD
   istream& Date::read(istream& is) {
       // Clears the error code by setting it NO_ERROR
       errCode(NO_ERROR);

       // Reads the year, the month and the day member variables using istream and ignores a single separators.
       is >> m_year;
       is.ignore(); // Ignore a single character
       is >> m_mon;
       is.ignore();
       is >> m_day;

       // Checks if istream has failed. 
       // If fail, set the error code to CIN_FAILED and clears the istream.
       // If not, validate the values entered.
       if (is.fail()) {
           errCode(CIN_FAILED);
           is.clear();
       }
       else {
           validate();
       }

       // Flushes the keyboard
       is.ignore(2048, '\n');
       // Returns the istream object
       return is;
   }

   ostream& Date::write(ostream& os)const {
       // If the Date object is in a “bad” state(it is invalid) print the “dateStatus()”.
       if (bad()) {
           os << dateStatus();
       }
       else {
           /*
           Prints the year
           Prints a Slash “ / ”
           Prints the month in two spaces, padding the left digit with zero if the month is a single - digit number
           Prints a Slash “ / ”
           Prints the day in two spaces, padding the left digit with zero if the day is a single - digit number*/
           os << m_year << '/' << setw(2) << setfill('0') << m_mon << '/' << setw(2) << setfill('0') << m_day;
           
           // Makes sure the padding is set back to spaces from zero
           os << setfill(' ');
       }
       // Returns the ostream object.
       return os;
   }

   // Comparision between 2 dates:
   bool Date::operator==(const Date& d) const {
       return  daysSince0001_1_1() == d.daysSince0001_1_1();
   }
   bool Date::operator!=(const Date& d) const {
       return  daysSince0001_1_1() != d.daysSince0001_1_1();
   }
   bool Date::operator>=(const Date& d) const {
       return daysSince0001_1_1() >= d.daysSince0001_1_1();
   }
   bool Date::operator<=(const Date& d) const {
       return daysSince0001_1_1() <= d.daysSince0001_1_1();
   }
   bool Date::operator<(const Date& d) const {
       return daysSince0001_1_1() < d.daysSince0001_1_1();
   }
   bool Date::operator>(const Date& d) const {
       return daysSince0001_1_1() > d.daysSince0001_1_1();
   }

   // difference between 2 days:
   int Date::operator-(const Date& d) {
       int diff = daysSince0001_1_1() - d.daysSince0001_1_1();
       return diff;
   }

   // return true if the date is valid and false if it is not
   Date::operator bool() const {
       return (!bad());
   }
}
