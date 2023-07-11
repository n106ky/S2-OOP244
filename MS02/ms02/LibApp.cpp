/*
    OOP244 MS2

    KA YING, CHAN
    123231227
    kchan151@myseneca.ca

    MOHAMMAD SHAMAS
    NEE

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    2023 JULY 11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LibApp.h"
#include "Utils.h"
using namespace std;
namespace sdds {
    /*Instantiate a Menu in this function and initialize it with the message argument.
    Then add only a "yes" as a single menu item to the Menu.
    Finally, run the menu and return true if the run method of Menu returns 1 and otherwise this function returns false.*/
    bool LibApp::confirm(const char* message) {
        return 1;
    }

    // [DONE] PRIVATE - STATEMENTS PRINTING:
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

    // [DONE] PUBLIC - STATEMENTS PRINTING:
    void LibApp::newPublication() {
        cout << "Adding new publication to library\n";
        if (confirm("Add this publication to library?")) {
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
        if (confirm("Remove this publication from the library?")) {
            m_changed = true;
            cout << "Publication removed\n";
        }
        else {
            m_changed = false;
        }
    }
    void LibApp::checkOutPub() {
        search();
        if (confirm("Check out publication?")) {
            m_changed = true;
            cout << "Publication checked out\n";
        }
        else {
            m_changed = false;
        }
    }

    // [SHD BE OK - DEBUGGED AND EVERYTHING IS THERE] CONSTRUCTOR:
    LibApp::LibApp() {
        m_changed = false;     

        Menu m_mainMenu("Seneca Libray Application");
        m_mainMenu <<
            "Add New Publication" <<
            "Remove Publication" <<
            "Checkout publication from library" <<
            "Return publication to library";

        Menu m_exitMenu("Changes have been made to the data, what would you like to do?");
        m_exitMenu <<
            "Save changes and exit" <<
            "Cancel and go back to the main menu";

        cout << "Creating new LibApp...\n" << endl;
        cout << m_changed << endl <<
            m_mainMenu << endl <<
            m_exitMenu << endl;

        load();
    }


    // RUN:

    /*
    The run method is the main application driver.

    It displays the main menu
    and based on the user's selection calls the corresponding private method
    and repeats the above until the user chooses to exit.

    When the user selects exit, the value of m_changed is examined.
    If the value is false, then since the data of the application is not modified,
    the program terminates.

    If the value is true, the m_exitMenu is used by calling its run method.
    Doing so the user has the selection of saving and exiting,
    cancelling and going back to the main menu or exiting without saving.

    If the first one is selected, the save() method is called and the program terminates.
    If the second one is selected the program goes back to the main menu and execution continues.
    If the exit is selected, then the confirm menu will be called using the message:
    "This will discard all the changes are you sure?". If the user selects Yes, the program terminates.

    Otherwise, the program goes back to the main menu and execution resumes.

    When the program is terminated, the following message is printed:
    -------------------------------------------
    Thanks for using Seneca Library Application
    */

}
