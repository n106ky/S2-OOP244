/*
    OOP244 Milestone

    KA YING, CHAN #123231227
    kchan151@myseneca.ca

    MOHAMMAD SHAMAS
    NEE

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    MS02            : 2023 JUL 12
    MS51, MS52, MS53: 2023 AUG 3
    MS56            : 2023 AUG 4
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include "PublicationSelector.h"
#include "LibApp.h"
#include "Utils.h"

using namespace std;
namespace sdds {
    bool LibApp::confirm(const char* message) {
        Menu menu(message);
        menu << "Yes";
        return menu.run();
    }

    void LibApp::load() {
        cout << "Loading Data\n";
        ifstream readfile;
        readfile.open(m_filename); // ios::in
        char type{};
        for (int i = 0; readfile; i++) {
            readfile >> type;
            readfile.ignore(); // '\t'
            if (readfile) {
                if (type == 'P')
                    m_PPA[i] = new Publication;
                else if (type == 'B')
                    m_PPA[i] = new Book;
                if (m_PPA[i]) {
                    readfile >> *m_PPA[i];
                    m_noLoadedPubs++;
                    m_LLRN = m_PPA[i]->getRef();
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

    int LibApp::search(int searchModes) { // searchModes: 1 = All, 2 = OnLoan, 3 = Available
        //cout << "Searching for publication\n";

        PublicationSelector ps("Select one of the following found matches:");
        int selectedType = m_selectPubType.run();
        
        int selectionRef{};

        if (selectedType) {
            cout << "Publication Title: ";
            char tempTitle[256]{};
            cin.ignore();
            cin.getline(tempTitle, '\n');

            for (int i = 0; i < m_noLoadedPubs; i++) { 
                if (m_PPA[i] && strstr(*m_PPA[i], tempTitle)) { // Why do we need pointer here?
                    if (selectedType == 1) {
                        if (m_PPA[i]->type() == 'B') {
                            if (searchModes == 1) {
                                ps << m_PPA[i];
                            }
                            else if (searchModes == 2) {
                                if (m_PPA[i]->onLoan()) {
                                    ps << m_PPA[i];
                                }
                            }
                            else if (searchModes == 3) {
                                if (!m_PPA[i]->onLoan()) {
                                    ps << m_PPA[i];
                                }
                            }
                        }
                    }
                    else if (selectedType == 2) {
                        if (m_PPA[i]->type() == 'P') {
                            if (searchModes == 1) {
                                ps << m_PPA[i];
                            }
                            else if (searchModes == 2) {
                                if (m_PPA[i]->onLoan()) {
                                    ps << m_PPA[i];
                                }
                            }
                            else if (searchModes == 3) {
                                if (!m_PPA[i]->onLoan()) {
                                    ps << m_PPA[i];
                                }
                            }
                        }
                    }
                }
            }
            if (ps) {
                ps.sort();
                selectionRef = ps.run();
                if (selectionRef == 0) {
                    cout << "Aborted!\n";
                }
                else {
                    getPub(selectionRef)->write(cout) << endl;
                }
            }
            else {
                cout << "No matches found!\n";
            }
        }
        else {
            cout << "Aborted!\n";
        }
        return selectionRef;
    }

    void LibApp::returnPub() {
        cout << "Return publication to the library\n";
        int rtnRef = search(2);
        if (rtnRef != 0) {
            if (confirm("Return Publication?\n")) {
                Date d;
                /*TEST*/
                /*
                cout << "d: " << d << endl;
                cout << "Checkout date: " << getPub(rtnRef)->checkoutDate() << endl;
                cout << getPub(rtnRef)->checkoutDate().operator-(d) << endl;
                cout << d.operator-(getPub(rtnRef)->checkoutDate()) << endl;
                */
                int diff = d.operator-(getPub(rtnRef)->checkoutDate());
                if (diff > SDDS_MAX_LOAN_DAYS) { // If LATE > 15days
                    const double finePerDay = 0.5;
                    int lateDays = diff - 15;
                    double fine = finePerDay * lateDays;
                    cout << "Please pay $" << fixed << setprecision(2) << fine << " penalty for being " << lateDays << " days late!" << endl;
                }
                getPub(rtnRef)->set(0);
                m_changed = true;
                cout << "Publication returned\n";
            }
            else {
                m_changed = false;
            }
        }
    }

    // PUBLIC FUNCTIONS:

    Publication* LibApp::getPub(int libRef) {
        Publication* p{};
        for (int i = 0; i < m_noLoadedPubs; i++) {
            if (m_PPA[i]->getRef() == libRef) {
                p = m_PPA[i];
            }
        }
        return p;
    }

    void LibApp::newPublication() {
        if (m_noLoadedPubs == SDDS_LIBRARY_CAPACITY) {
            cout << "Library is at its maximum capacity!\n";
        }
        else {
            cout << "Adding new publication to the library\n";
            int selectedType = m_selectPubType.run();
            Publication* tempPub{};
            if (selectedType){
                if (selectedType == 1) {
                    tempPub = new Book;
                    tempPub->read(cin);
                }
                else if (selectedType == 2) {
                    tempPub = new Publication;
                    tempPub->read(cin);
                }
                if (cin) {
                    if (confirm("Add this publication to the library?\n")) {
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
            else {
                cout << "Aborted!\n";
            }  
        }
    }
    void LibApp::removePublication() {
        cout << "Removing publication from the library\n";
        int rtnRef = search(1);
        if (rtnRef != 0) {
            if (confirm("Remove this publication from the library?\n")) {
                getPub(rtnRef)->setRef(0);
                m_changed = true;
                cout << "Publication removed\n";
            }
            else {
                m_changed = false;
            }
        }
    }

    void LibApp::checkOutPub() {
        cout << "Checkout publication from the library\n";
        int rtnRef = search(3);
        if (rtnRef != 0) {
            if (confirm("Check out publication?\n")) {
                int memberID = getValidMembership();
                getPub(rtnRef)->set(memberID);
                m_changed = true;
                cout << "Publication checked out\n";
            }
            else {
                m_changed = false;
            }
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

        m_exitMenu <<
            /*1*/"Save changes and exit" <<
            /*2*/"Cancel and go back to the main menu";

        m_selectPubType <<
            /*1*/"Book" <<
            /*2*/"Publication";

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
