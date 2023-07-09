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

    // ************************** MENUITEM FUNCTIONS ************************** // 

    void MenuItem::setItemEmpty() {
        m_content = nullptr;
    }
    MenuItem::MenuItem() {
        setItemEmpty();
    }
    MenuItem::MenuItem(const char* content) {
        if (content && content[0] != '\0') {
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
        //cout << "deleting m_content" << endl;
    }
    MenuItem::operator bool() const {
        return (m_content && m_content[0] != '\0'); // m_content;
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

    // ************************** MENU FUNCTIONS ************************** // 


    Menu::Menu() {
        //cout << "Creating an empty constructor" << endl;
    };

    Menu::Menu(const char* title): m_menuTitle{ title } {
        // cout << "Creating an constructor with title: "  << m_menuTitle << endl; 
        // HOW COME MENU TITLE IS 1 (goes into bool but not const char*)
    }

    Menu::~Menu() {
        for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++) { // MAX_MENU_ITEMS should be an countable value
            delete mI[i];
        }
        // cout << "deleting mI" << endl;
    }
    ostream& Menu::titleDisplay(ostream& os) {
        if (m_menuTitle) {
            m_menuTitle.display(); // why cant I do it like this? >> m_menuTitle.display(os);
        }
        return os;
    }
    ostream& Menu::menuDisplay(ostream& os) {

        m_menuTitle.display();
        if (m_menuTitle) {
            os << ':' << endl;
        }
        for (unsigned int i = 0; i < noOfItems; i++) {
            os << setw(2) << right << i + 1 << "- "; // NOT SURE
            mI[i]->display(); // mI[i]->display(os);
            os << endl;
        }
        os << setw(2) << right << "0" << "- Exit" << endl << "> ";

        return os;
    }
    unsigned int Menu::run() {
        menuDisplay();
        unsigned int select = getValidSelect(0, noOfItems);

        return select;
    }
    unsigned int Menu::operator~() { // same as run
        return run();
    }
    Menu& Menu::operator<<(const char* menuitemConent) { // Unlike WS4 it was receiving an int.  
       
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
    Menu::operator int()const {
        return noOfItems;
    }
    Menu::operator unsigned int()const {
        return noOfItems;
    }
    Menu::operator bool() const {
        return (noOfItems > 0);
    }
    const char* Menu::operator[](unsigned int value)const {
        const char* items;
        if (value <= noOfItems) {
            items = mI[value]->m_content;
        }
        else {
            items = mI[value % noOfItems == 0]->m_content;
        }
        return items;
    }

    ostream& operator<<(ostream& os, Menu& m) {
        return m.titleDisplay(os); // m1 title display goes here. no =cout, must pass os.
    }

}