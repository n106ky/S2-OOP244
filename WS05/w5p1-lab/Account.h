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
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;

      // Type conversion operators:
      operator bool() const;
      operator int() const;
      operator double() const;

      // Unary member operator:
      bool operator~() const;

      // Binary member operators:
      Account& operator=(int number);
      Account& operator=(Account& other);
      Account& operator+=(double balance);
      Account& operator-=(double balance);
      Account& operator<<(Account& r_acc);
      Account& operator>>(Account& l_acc);
   };

   // helper function:

   // Binary helper operators:
   double operator+(const Account& l_acc, const Account& r_acc);
   double operator+=(double& l_acc_balance, const Account& r_acc);
}
#endif // SDDS_ACCOUNT_H_