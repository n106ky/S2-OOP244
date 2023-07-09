/*
    OOP244 WS3-DIY

    KA YING, CHAN
    123231227
    kchan151@myseneca.ca

    MOHAMMAD SHAMAS
    NEE

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    2023 JUN 1
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <iomanip>
#include "cstring.h"
#include "Food.h"
using namespace std;
namespace sdds {
    // Private:
    void Food::setName(const char* name) {
        strnCpy(m_name, name, 30);
    }

    // Public:
    // Sets the Item to a recognizable safe Empty State
    void Food::setEmpty() {
        m_name[0] = '\0';
        m_cal = 0;
    }

    // Sets the m_name, m_cal and m_time attributes if pass validation
    void Food::set(const char* name, int cal, int time) {
        if (name == nullptr || name[0] == '\0' || cal < CAL_MIN || cal > CAL_MAX) {
            setEmpty();
        }
        else {
            setName(name);
            m_cal = cal;
            m_time = time;
        }
    }

    // Display single item
    void Food::display() const {
        if (isValid()) {
            cout <<
                "| " << left << setw(30) << setfill('.') << m_name <<
                " | " << right << setw(4) << setfill(' ') << m_cal << 
                " | " << left << setw(11) << meal() << "|" << endl;
        }
        else {
            cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |\n";
        }
    }

    // Returns true if the item is not set to the empty state
    bool Food::isValid() const {
        return (m_name != nullptr && m_name[0] != '\0' && m_cal >= CAL_MIN && m_cal <= CAL_MAX && meal() != nullptr);
    }

    // Returns the m_cal attribute
    int Food::calories() const {
        return m_cal;
    }

    // Receive integer value of meal time and return it as string
    const char* Food::meal() const {
        const char* meal = nullptr;
        switch (m_time) {
        case 1:
            meal = "Breakfast";
            break;
        case 2:
            meal = "Lunch";
            break;
        case 3:
            meal = "Dinner";
            break;
        case 4:
            meal = "Snack";
            break;
        default:
            meal = nullptr;
            break;
        }
        return meal;
    }
    
}