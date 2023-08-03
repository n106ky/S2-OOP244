/*
    OOP244 MS2

    KA YING, CHAN
    123231227
    kchan151@myseneca.ca

    MOHAMMAD SHAMAS
    NEE

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    2023 JULY 12
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LibApp.h"
#include "Utils.h"
using namespace std;
namespace sdds {
    bool LibApp::confirm(const char* message) {
        Menu menu(message);
        menu << "Yes";
        return menu.run();
    }

    // PRIVATE - STATEMENTS PRINTING:
    void LibApp::load() {

        cout << "Loading Data\n";
    } 
    void LibApp::save() {
        cout << "Saving Data\n";
    } 
    void LibApp::search() {
        cout << "Searching for publication\n";
    }
    void LibApp::returnPub() {
        search();
        cout << "Returning publication\n";
        cout << "Publication returned\n";
        m_changed = true;
    }

    // PUBLIC FUNCTIONS:

    // PUBLIC - STATEMENTS PRINTING:
    void LibApp::newPublication() {
        cout << "Adding new publication to library\n";
        if (confirm("Add this publication to library?\n")) {
            m_changed = true;
            cout << "Publication added\n";
        }
        else {
            m_changed = false;
        }
    }
    void LibApp::removePublication() {
        cout << "Removing publication from library\n";
        search();
        if (confirm("Remove this publication from the library?\n")) {
            m_changed = true;
            cout << "Publication removed\n";
        }
        else {
            m_changed = false;
        }
    }
    void LibApp::checkOutPub() {
        search();
        if (confirm("Check out publication?\n")) {
            m_changed = true;
            cout << "Publication checked out\n";
        }
        else {
            m_changed = false;
        }
    }

    // CONSTRUCTOR:
    LibApp::LibApp() {
        m_changed = false;     

        //Menu m_mainMenu("Seneca Libray Application"); // CAUTION: IT WILL CREATE ANOTHER OBJECT. NOT CORRECT.
        m_mainMenu <<
            /*1*/"Add New Publication" <<
            /*2*/"Remove Publication" <<
            /*3*/"Checkout publication from library" <<
            /*4*/"Return publication to library";

        // Menu m_exitMenu("Changes have been made to the data, what would you like to do?");
        m_exitMenu << 
            /*1*/"Save changes and exit" <<
            /*2*/"Cancel and go back to the main menu";

        /* FOR TESTING: */
        //cout << "Creating new LibApp...\n" << endl;
        //cout << m_changed << endl <<
        //    m_mainMenu << endl <<
        //    m_exitMenu << endl;

        load();
    }

    void LibApp::run() {
        int exitSelect = 0;
        int mainSelect = 0;
        do {
            mainSelect = m_mainMenu.run();
            switch (mainSelect) {
            case 1:
                newPublication();
                break;
            case 2:
                removePublication();
                break;
            case 3:
                checkOutPub();
                break;
            case 4:
                returnPub();
                break;
            default:
                if (m_changed) {
                    exitSelect = m_exitMenu.run();
                    if (exitSelect == 1) {
                        save();
                    }
                    else if (exitSelect == 2) {
                        mainSelect = 1; // JUST NOT ZERO, TO KEEP THE LOOP RUNNING 
                    }
                    else {
                        if (!confirm("This will discard all the changes are you sure?\n")) {
                            m_changed = false;
                        }
                    }
                }
            }
            cout << "\n";
        } while (mainSelect); 
        cout <<
            "-------------------------------------------\n"
            "Thanks for using Seneca Library Application\n";
    }
}
