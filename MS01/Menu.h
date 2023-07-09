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
#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_

namespace sdds {
    const unsigned int MAX_MENU_ITEMS = 20;
    unsigned int noOfItems = 0;

    class MenuItem { 
        // FULLY PRIVATE CLASS
        char* m_content{nullptr};
        void setItemEmpty();
        MenuItem();
        MenuItem(const char* content);

        // RULE OF THREE:
        MenuItem(const MenuItem& src) = delete;
        // Copy constructor and Copy assignment are deleted
        MenuItem& operator=(const MenuItem& src) = delete;
        ~MenuItem();

        // TYPE CONVERSION:
        operator bool() const;
        operator const char* () const;

        std::ostream& display(std::ostream& os)const;

        // Only accessible by the Menu class
        friend class Menu;
    };

    class Menu {
        MenuItem m_menuTitle{};
        MenuItem* mI[MAX_MENU_ITEMS]{};

    public:
        Menu();
        Menu(const char* title);

        // RULE OF THREE:
        Menu(const Menu& src) = delete;
        Menu& operator=(const Menu& src) = delete;
        ~Menu();

        // DISPLAY
        std::ostream& titleDisplay(std::ostream& os)const;
        std::ostream& menuDisplay(std::ostream& os)const;

        // This function displays the Menu and gets the user selection
        unsigned int run(); 
        Menu& operator~(); // Same as run
        Menu& operator<<(const char* menuitemConent); // add MenuItem to Menu

        operator int()const;
        operator unsigned int()const;
        operator bool() const;
        operator const char* () const;

        std::ostream& operator<<(std::ostream& os) const;
    };

}
#endif
