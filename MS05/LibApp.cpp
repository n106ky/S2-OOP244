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
#include <fstream>
#include <string>
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
        // First print "Loading Data"
        cout << "Loading Data\n";
        ifstream readfile;
        // and then open the data file for reading     
        // and read all the publications in dynamic instances pointed by the PPA Array.
        readfile.open(m_filename); // ios::in
        char type{};
        for (int i = 0; readfile; i++) { // Continue this until the ifstream reading fails.
            // Do this by first reading a single character for the type of publication
            readfile >> type;
            readfile.ignore(); // '\t'
            if (readfile) {
                // and then dynamically instantiating the corresponding object into the next available PPA element.
                if (type == 'P')
                    m_PPA[i] = new Publication;
                else if (type == 'B')
                    m_PPA[i] = new Book;
                if (m_PPA[i]) {
                    //  Then extract the object from the file stream and add one to the NOLP.
                    readfile >> *m_PPA[i];
                    m_noLoadedPubs++;
                    // Since the extraction operator calls the proper read function virtually,
                    // the object will be properly read from the file.
                                    // At the end set the LLRN to the reference number of the last publication read.
                    m_LLRN = m_PPA[i]->getRef(); // +1
                }
            }
        }
        readfile.close();
    }

    void LibApp::save() {
        cout << "Saving Data\n";
        ofstream writefile;
        writefile.open(m_filename);
        for (int i = 0; i < m_noLoadedPubs; i++) {
            if (m_PPA[i]->getRef()) {
                 m_PPA[i]->write(writefile);
            }
        }
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
        if (m_noLoadedPubs == SDDS_LIBRARY_CAPACITY) {
            cout << "Library is at its maximum capacity!\n";
        }
        else {
            cout << "Adding new publication to library\n";
            int selectedType = m_selectPubType.run();
            Publication* tempPub{};
            if (selectedType == 1) {
                tempPub = new Book; // *m_PPA
                tempPub->read(cin);
            }
            else if (selectedType == 2) {
                tempPub = new Publication; // *m_PPA
                tempPub->read(cin);
            }
            if (cin) {
                if (confirm("Add this publication to library?\n")) {
                    if (tempPub) {
                        m_LLRN++;
                        tempPub->setRef(m_LLRN);
                        m_PPA[m_noLoadedPubs] = tempPub;
                        m_noLoadedPubs++;
                        m_changed = true;
                        cout << "Publication added\n";
                    }
                    else {
                        m_changed = false;
                        cout << "Failed to add publication!\n";
                        delete m_PPA[m_noLoadedPubs];
                    }
                }
                else {
                    m_changed = false;
                    cout << "Aborted!\n";
                }
            }
            else {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Aborted!\n";
            }
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
        LibApp::setToDefault();
    }

    LibApp::LibApp(const char* filename) {
        if (filename) {
            strcpy(m_filename, filename);
        }
        LibApp::setToDefault();
    }

    void LibApp::setToDefault() {
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

        m_selectPubType <<
            /*1*/"Book" <<
            /*2*/"Publication";

        /* FOR TESTING: */
        //cout << "Creating new LibApp...\n" << endl;
        //cout << m_changed << endl <<
        //    m_mainMenu << endl <<
        //    m_exitMenu << endl;

        load();
    }
    LibApp::~LibApp() {
        for (int i = 0; i < SDDS_LIBRARY_CAPACITY; i++) {
            delete m_PPA[i];
        }
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
