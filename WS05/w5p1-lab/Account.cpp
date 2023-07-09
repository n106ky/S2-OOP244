/*
    OOP244 WS5-LAB

    KA YING, CHAN
    123231227
    kchan151@myseneca.ca

    MOHAMMAD SHAMAS
    NEE

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    2023 JUN 13
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {

   // PRIVATE:

   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }

   // PUBLIC:

   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   // Type conversion operators:
   Account::operator bool() const { 
       return (m_number >= 10000 && m_number <= 99999 && m_balance >= 0.0);
   }
   Account::operator int() const {
       return m_number;
   }
   Account::operator double() const {
       return m_balance;
   }

   // Unary member operator:
   bool Account::operator~() const {
       return m_number == 0;
   }

   // Binary member operators:
   Account& Account::operator=(int number) {
       if (operator~() && number >= 10000 && number <= 99999) { 
           m_number = number;
           if (!operator bool()) {
               setEmpty();
           }
       }
       return *this;
   }
   Account& Account::operator=(Account& r_acc) {
       if (operator~() && r_acc.operator bool()) {
           m_balance = r_acc.m_balance;
           r_acc.m_balance = 0.0;
           m_number = r_acc.m_number;
           r_acc.m_number = 0;
       }
       return *this;
   }
   Account& Account::operator+=(double balance) {
       if (operator bool() && balance >= 0) {
           m_balance += balance;
       }
       return *this;
   }
   Account& Account::operator-=(double balance) {
       if (operator bool() && balance >= 0 && m_balance > balance) {
           m_balance -= balance;
       }
       return *this;
   }
   Account& Account::operator<<(Account& r_acc) {
       if (this != &r_acc && r_acc.operator bool()) {
           m_balance += r_acc.m_balance;
           r_acc.m_balance = 0.0;
       }
       return *this;
   }
   Account& Account::operator>>(Account& l_acc) {
       if (this != &l_acc && l_acc.operator bool()) {
           l_acc.m_balance += m_balance;
           m_balance = 0.0;
       }
       return *this;
   }
    
   // HELPERS:

   // Binary helper operators:
   double operator+(const Account& l_acc, const Account& r_acc) {
       double sum = 0.0;
       if (l_acc.operator bool() && r_acc.operator bool()) {
           sum += l_acc.operator double() + r_acc.operator double();
       }
       return sum;
   }
   double operator+=(double& l_acc_balance, const Account& r_acc) {
       if (r_acc.operator bool()) {
           l_acc_balance += r_acc.operator double();
       }
       return l_acc_balance;
   }
}