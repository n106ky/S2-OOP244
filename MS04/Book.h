/*
    OOP244 MS3

    KA YING, CHAN #123231227
    kchan151@myseneca.ca

    MOHAMMAD SHAMAS
    NEE

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    COMPLETED: 2023 JULY 29
*/
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include "Publication.h"

namespace sdds {

    class Book: public Publication {
        char* m_authorName{};

    public:
        Book();
        void setToDefault();

        // RULE OF THREE:
        Book(const Book& src);
        Book& operator=(const Book& src);
        ~Book();

        // METHODS (OVERRIDE VIRTUAL FUNCTIONS):
        void set(int member_id);				        // Sets the membership attribute to either zero or a five-digit integer.
        char type()const;						        // Returns the character 'P' to identify this object as a "Publication object"

        std::ostream& write(std::ostream& os)const;		// Display content
        std::istream& read(std::istream& is);			// Read all the values in local variables before setting the attributes to any values
        operator bool() const;
    };

}

#endif // !SDDS_BOOK_H
