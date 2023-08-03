/*
    OOP244 Milestone

    KA YING, CHAN #123231227
    kchan151@myseneca.ca

    MOHAMMAD SHAMAS
    NEE

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    MS02: 2023 JULY 12
    MS51: 2023 AUG 3
*/
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
#include "Book.h"
#include "Publication.h"


namespace sdds {
    class LibApp { 
        bool m_changed{};
        Menu m_mainMenu{ "Seneca Library Application\n" };
        Menu m_exitMenu{ "Changes have been made to the data, what would you like to do?\n" };
        Menu m_selectPubType{ "Choose the type of publication:\n" }; 
        char m_filename[256]{};                         // Add an array of 256 characters to hold the publication data file name.
        Publication* m_PPA[SDDS_LIBRARY_CAPACITY]{};    // PPA: will be populated with all the records of the publication data file when the LibApp is instantiated.
        int m_noLoadedPubs{};                           // NOLP: hold the number of Publications loaded into the PPA
        int m_LLRN{};                                   // assign new library reference numbers

        bool confirm(const char* message);
        void load();
        void save();   
        void search(int searchModes);
        void returnPub();  

    public:
        void newPublication();
        void removePublication();
        void checkOutPub();
        void run();

        void setToDefault();
        LibApp();
        LibApp(const char *filename);
        ~LibApp();
    };
}
#endif // !SDDS_LIBAPP_H



