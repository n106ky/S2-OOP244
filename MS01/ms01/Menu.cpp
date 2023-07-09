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
#include "Date.h"
#include "Menu.h"
#include "Utils.h"
using namespace std;
namespace sdds {

    // MENUITEM:
    void MenuItem::setItemEmpty() {
        m_content = nullptr;
    }
    MenuItem::MenuItem() {
        setItemEmpty();
    }
    MenuItem::MenuItem(const char* content) {
        if (content) {
            m_content = new char[strLen(content) + 1];
            strCpy(m_content, content);
        }
        else {
            setItemEmpty();
        }
    }
    MenuItem::~MenuItem() {
        delete[] m_content;
        m_content = nullptr;
        cout << "MenuItem is dying... " << endl;
    }
    MenuItem::operator bool() const {
        return m_content;
    }
    MenuItem::operator const char* () const {
        return m_content;
    }

    ostream& MenuItem::display(ostream& os)const {
        if (*this) {
            os << m_content;
        }
        return os;
    }

    // MENU:
    //void Menu::setMenuEmpty() {
    //    mI = nullptr;
    //}
    Menu::Menu() {
        cout << "Creating an empty constructor" << endl;
    };
    Menu::Menu(const char* title): m_menuTitle{ title } {
        cout << "Creating an constructor with title: "  << m_menuTitle << endl; // HOW COME MENU TITLE IS 1 (goes into bool but not const char*)
    }

    Menu::~Menu() {
        for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++) { // MAX_MENU_ITEMS should be an countable value
            delete mI[i];
        }
        cout << "mI is dying... " << endl;
    }
    ostream& Menu::titleDisplay(ostream& os)const {
        if (m_menuTitle) {
            m_menuTitle.display(os); // NOT SURE
        }
        return os;
    }
    ostream& Menu::menuDisplay(ostream& os)const {
        titleDisplay(os);
        os << ':' << endl;
        for (unsigned int i = 0; i < noOfItems; i++) {
            os << i + 1 << '- ';
            mI[i]->display(os);
            os << endl;
        }

        return os;
    }
    unsigned int Menu::run() {
        unsigned int select;
        // menuDisplay();
        // getValidSelect(); 

        return select;
    }
    Menu& Menu::operator~() { // same as run
        run();
        return *this;
    }
    Menu& Menu::operator<<(const char* menuitemConent) { // Unlike ws4 it is receiving an int.  
       
        if (noOfItems < MAX_MENU_ITEMS) {
            // Dynamically create a new MenuItem
            MenuItem* newItem = new MenuItem(menuitemConent);

            // Store the address in the next available spot
            mI[noOfItems] = newItem;

            // Increase the number of allocated MenuItem pointers
            noOfItems++;
        }
        return *this;
    }


}