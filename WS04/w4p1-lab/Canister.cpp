/*
    OOP244 WS4-LAB

    KA YING, CHAN
    123231227
    kchan151@myseneca.ca

    MOHAMMAD SHAMAS
    NEE

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    2023 JUN 7
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Canister.h"

using namespace std;
namespace sdds {
    const double PI = 3.14159265;

    void Canister::setToDefault() { 
        m_contentName = nullptr;
        m_height = 13.0;
        m_diameter = 10.0;
        m_contentVolume = 0.0;
        m_usable = true;
    }

    void Canister::setName(const char* Cstr) {
        if (Cstr && m_usable) {
            delete[] m_contentName;
            m_contentName = nullptr;
            m_contentName = new char[strLen(Cstr) + 1];
            strCpy(m_contentName, Cstr);
        }
    }

    bool Canister::isEmpty()const { 
        return (m_contentVolume < 0.00001);
    }

    bool Canister::hasSameContent(const Canister& C) const { 
        return m_contentName && C.m_contentName && strCmp(m_contentName, C.m_contentName) == 0;
    }

// public:
    Canister::Canister() {
        setToDefault();
    }

    Canister::Canister(const char* contentName) {
        setToDefault();
        setName(contentName);
    }

    Canister::Canister(double height, double diameter, const char* contentName) {
        setToDefault();
        if (height >= HGT_MIN && height <= HGT_MAX && diameter >= DIA_MIN && diameter <= DIA_MAX) {
            m_height = height;
            m_diameter = diameter;
            m_contentVolume = 0.0;
            setName(contentName);
        }
        else {
            m_usable = false;
        }
    }

    Canister::~Canister() {
        delete[] m_contentName;
        m_contentName = nullptr;
    }

    Canister& Canister::setContent(const char* contentName) {
        if (!contentName || contentName[0] == '\0') {
            m_usable = false;
        }
        else if (isEmpty()) {
            setName(contentName);
        }
        else if (strCmp(m_contentName, contentName)) {
            m_usable = false;
        }
        return *this;
    }

    Canister& Canister::pour(double quantity) {
        if (m_usable && quantity && (volume() + quantity) <= capacity()) {
                m_contentVolume += quantity;
        }
        else {
            m_usable = false;
        }
        return *this;
    }

    Canister& Canister::pour(Canister& C) {
        if (C.isEmpty()) {
            clear();
            setName(C.m_contentName);
        }
        else {
            setContent(C.m_contentName);
        }

        if (C.volume() > (capacity() - volume())) {
            C.m_contentVolume -= capacity() - volume();
            m_contentVolume = capacity();
        }
        else {
            pour(C.m_contentVolume);
            C.m_contentVolume = 0.0;
        }
   
        return *this;
    }

    double Canister::volume()const {
        return m_contentVolume;
    }

    std::ostream& Canister::display()const {
        cout << fixed << setprecision(1) << setw(7) << capacity() << "cc (" << m_height << "x" << m_diameter << ") Canister";
        if (!m_usable) {
            cout << " of Unusable content, discard!";
        }
        else if (m_contentName) {
            cout << fixed << setprecision(1) << " of " << setw(7) << volume() << "cc   " << m_contentName;
        }
        return cout;
    }

    double Canister::capacity()const {
        return  PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
    }

    void Canister::clear() {
            delete[] m_contentName;
            m_contentName = nullptr;
            m_contentVolume = 0.0;
            m_usable = true;
    }
}