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
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"

namespace sdds {

    // [FOR NOW - INHERIT PUBLIC MENU FIRST]
    class LibApp: public Menu { 
        bool m_changed{};
        Menu m_mainMenu{};
        Menu m_exitMenu{}; 

        // PRIVATE FUNCTIONS:

        /*Instantiate a Menu in this function and initialize it with the message argument.
        Then add only a "yes" as a single menu item to the Menu.
        Finally, run the menu and return true if the run method of Menu returns 1 and otherwise this function returns false.*/
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
    };
}
#endif // !SDDS_LIBAPP_H



