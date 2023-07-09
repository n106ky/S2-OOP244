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
#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>

namespace sdds {
    class Mark {
        int m_mark;
        void setInvalid();
    public:
        // CONSTRUCTORS:
        Mark();
        Mark(int mark);

        // TYPE CONVERSION OPERATORS:
        operator bool() const;
        operator int() const;
        operator double() const;
        operator char() const;

        // MEMBER OPERATORS:
        Mark& operator+=(const int mark);
        Mark& operator=(const int mark);
    };

   // HELPER FUNCTION:
   int& operator+=(int& mark, const Mark& m);
}
#endif // SDDS_MARK_H_