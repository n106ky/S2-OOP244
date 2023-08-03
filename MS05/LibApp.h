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

namespace sdds {
    class LibApp { 
        bool m_changed{};
        Menu m_mainMenu{ "Seneca Library Application\n" };
        Menu m_exitMenu{ "Changes have been made to the data, what would you like to do?\n" };

        // PRIVATE FUNCTIONS:

        bool confirm(const char* message);

        // PRIVATE - STATEMENTS PRINTING:
        void load();
        void save();   
        void search();  
        void returnPub();  

    public:
        // PUBLIC - STATEMENTS PRINTING:
        void newPublication();
        void removePublication();
        void checkOutPub();

        // CONSTRUCTOR:
        LibApp();

        void run();
    };
}
#endif // !SDDS_LIBAPP_H



