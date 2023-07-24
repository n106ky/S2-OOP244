/*
    OOP244 MS3

    KA YING, CHAN #123231227
    kchan151@myseneca.ca

    MOHAMMAD SHAMAS
    NEE

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    COMPLETED: 2023 JULY 21
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Streamable.h"

using namespace std;
namespace sdds {

    istream& operator>>(istream& in, Streamable& s) {
        return s.read(in);
    }

    ostream& operator<<(ostream& os, const Streamable& s) {
        // Only if the Streamable object is in a valid state
        if (s) {
            s.write(os);
        }
        return os;
    }

    Streamable::~Streamable() {
    };
}