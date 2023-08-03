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
        Menu m_selectPubType{ "Choose the type of publication:\n" }; /* MS5:
                                                            Add a Menu to the LibApp for selection of publication type.
                                                            The title of this menu is: "Choose the type of publication:"
                                                            The publication type menu should also provide two selections: "Book" and "Publication".
                                                            Setup the publication type menu in the constructor as you did for the main and exit menus.*/
        // MS5:
        char m_filename[256]{}; // Add an array of 256 characters to hold the publication data file name.
        Publication* m_PPA[SDDS_LIBRARY_CAPACITY]{}; // PPA: will be populated with all the records of the publication data file when the LibApp is instantiated.
        int m_noLoadedPubs;     // NOLP: hold the number of Publications loaded into the PPA
        int m_LLRN;   /*
                        LLRN: Add an integer to hold the last library reference number read from the data file.

                        This number will be used to assign new library reference numbers to new publications added to the library. 
                        When a new publication is added to the library, this number will be added by one and then assigned to the new publication. (+1)
                        Doing this; each publication in the library will have a unique library reference number. */



        bool confirm(const char* message);

        // STATEMENTS PRINTING:
        void load();
        void save();   
        void search();  
        void returnPub();  

    public:
        // STATEMENTS PRINTING:
        void newPublication();
        void removePublication();
        void checkOutPub();

        // CONSTRUCTOR:
        LibApp();
        LibApp(const char *filename);
        void setToDefault();

        void run();

        ~LibApp();
    };
}
#endif // !SDDS_LIBAPP_H



