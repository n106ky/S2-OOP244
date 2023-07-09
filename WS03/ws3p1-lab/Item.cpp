/*
    OOP244 WS3-LAB

    KA YING, CHAN
    123231227
    kchan151@myseneca.ca

    MOHAMMAD SHAMAS
    NEE

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    2023 MAY 31
*/
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds {
    // Private:
    // Sets the itemName as "name" and take up to 20 characters.
    void Item::setName(const char* name) {
            strnCpy(m_itemName, name, 20);
    }

    // Public:
    // Sets the Item to a recognizable safe Empty State
    void Item::setEmpty() {
        m_price = 0.0;
        m_itemName[0] = '\0';
    }

    // Sets the m_itemName, m_price and m_taxed attributes if pass validation
    void Item::set(const char* name, double price, bool taxed) {
        if (name == nullptr || name[0] == '\0' || price <= 0.0) {
            setEmpty();
        }
        else {
            setName(name);
            m_price = price;
            m_taxed = taxed;
        }
    }

    //  display single item
    void Item::display() const {
        if (isValid()) {
            cout << "| " << left << setw(20) << setfill('.') << m_itemName;
            cout << " | " << right << setw(7) << setfill(' ') << m_price << fixed << setprecision(2) << " | ";
            cout << (m_taxed ? "Yes" : "No ") << " |" <<endl;
        }
        else {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |\n";
        }
    }

    // Returns true if the Item is not set to the empty state
    bool Item::isValid() const {
        return (m_itemName != nullptr && m_itemName[0] != '\0' && m_price > 0.0) == 1;
    }

    // Returns the m_price attribute
    double Item::price() const {
        return m_price;
    }

    // Returns the product with taxRate if m_taxed is true
    double Item::tax() const {
        double product = 0.0;
        const double taxRate = 0.13;
        if (m_taxed) {
            product =  m_price * taxRate;
        }
        return product;
    }
}