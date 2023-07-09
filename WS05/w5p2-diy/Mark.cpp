/*
    OOP244 WS5-DIY

    KA YING, CHAN
    123231227
    kchan151@myseneca.ca

    MOHAMMAD SHAMAS
    NEE

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    2023 JUN 14
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

using namespace std;
namespace sdds {

   // PRIVATE:
   void Mark::setInvalid() {
       m_mark = -1;
   }

   // PUBLIC:

   // CONSTRUCTORS:
   Mark::Mark() {
       m_mark = 0;
   }
   Mark::Mark(int mark) {
      if (mark >= 0 && mark <= 100) {
          m_mark = mark;
      }
      else {
          setInvalid();
      }
   }

   // TYPE CONVERSION OPERATORS:

   Mark::operator bool() const {
       return (m_mark >= 0 && m_mark <= 100);
   }

   //  Mark to INT:
   Mark::operator int() const {
       int result = 0;
       if (operator bool()) {
           result = m_mark;
       }
       return result;
   }

   //  Mark to DOUBLE:
   Mark::operator double() const {
       double result = 0.0;
           if (m_mark >= 0 && m_mark < 50) {
               result = 0.0;
           }
           else if (m_mark >= 50 && m_mark < 60) {
               result = 1.0;
           }
           else if (m_mark >= 60 && m_mark < 70) {
               result = 2.0;
           }
           else if (m_mark >= 70 && m_mark < 80) {
               result = 3.0;
           }
           else if (m_mark >= 80 && m_mark <= 100) {
               result = 4.0;
           }
           else {
               result = 0.0;
           }
       return result;
   }

   //  Mark to CHAR:
   Mark::operator char() const {
       char result = 'X';

           if (m_mark >= 0 && m_mark < 50) {
               result = 'F';
           }
           else if (m_mark >= 50 && m_mark < 60) {
               result = 'D';
           }
           else if (m_mark >= 60 && m_mark < 70) {
               result = 'C';
           }
           else if (m_mark >= 70 && m_mark < 80) {
               result = 'B';
           }
           else if (m_mark >= 80 && m_mark <= 100) {
               result = 'A';
           }
           else {
               result = 'X';
           }
       return result;
   }

   // MEMBER OPERATORS:

   Mark& Mark::operator+=(const int mark) {
       if (operator bool() && mark > 0) {
           m_mark += mark;
       }    
       return *this;
   }
   Mark& Mark::operator=(const int mark) {
       if (mark >= 0 && mark <= 100) {
           m_mark = mark;
       }
       else {
           setInvalid();
       }
       return *this;
   }

   // HELPER FUNCTION:

   int& operator+=(int& mark, const Mark& m) {
           mark += m.operator int();
       return mark;
   }
}