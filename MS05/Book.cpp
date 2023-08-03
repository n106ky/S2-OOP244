/*
    OOP244 MS3

    KA YING, CHAN #123231227
    kchan151@myseneca.ca

    MOHAMMAD SHAMAS
    NEE

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    COMPLETED: 2023 JULY 29
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Book.h"
#include "Utils.h"

using namespace std;
namespace sdds {
    Book::Book(){} //: Publication()

    void Book::setToDefault() {
        if (m_authorName){
            delete[] m_authorName;
        }
        m_authorName = nullptr;
    }

    // RULE OF THREE:
    Book::Book(const Book& src) {  //: Publication(src)
        *this = src;
        //cout << "BOOK Copy Constructor\n";
    }
    Book& Book::operator=(const Book& src) { 
        if (this != &src) {
            if (src) {
                Publication::operator=(src); // Must call it to copy the entered input to Publication
                // cout << src.m_authorName << "\n";
                //cout << "BOOK Copy Assignment\n";
                setToDefault();
                m_authorName = new char[strlen(src.m_authorName) + 1];
                strcpy(m_authorName, src.m_authorName);
            }
        }
        return *this;
    }
    Book::~Book() {
        delete[] m_authorName;
        m_authorName = nullptr;
    }
   
    // METHODS (OVERRIDE VIRTUAL FUNCTIONS):
    // Sets the membership attribute to either zero or a five-digit integer.
    void Book::set(int member_id) {
        Publication::set(member_id);
        Publication::resetDate();
    }

    // Returns the character 'P' to identify this object as a "Publication object"
    char Book::type()const {
        return 'B';
    }

    ostream& Book::write(ostream& os)const {
        Publication::write(os);
        if (conIO(os)) {
            char temp_authorName[SDDS_AUTHOR_WIDTH + 1]{}; // EASIER THAN FOR LOOP.
            strncpy(temp_authorName, m_authorName, SDDS_AUTHOR_WIDTH);
            os << ' ';
            os << setw(SDDS_AUTHOR_WIDTH) << left << setfill(' ') << temp_authorName;
            os << " |";
        }
        else {
            os << '\t' << m_authorName << endl;
        }

        return os;
    }
    istream& Book::read(istream& is) {
        char temp_authorName[255 + 1];
        Publication::read(is);
        Book::setToDefault();
        if (conIO(is)) {
            is.ignore();
            cout << "Author: ";
            // is.getline(temp_authorName, 255 + 1);
            is.get(temp_authorName, 255+1);
        }
        else {
            is.ignore(1000,'\t'); // MUST BE CORRECT TO READ IT PROPERLY
            // is.getline(temp_authorName, 255 + 1);
            is.get(temp_authorName, 255 + 1);
        }
        if (is) {
            m_authorName = new char[strlen(temp_authorName) + 1];
            strcpy(m_authorName, temp_authorName);
        }
        return is;
    }

    Book::operator bool() const {
        return m_authorName && m_authorName[0] != '\0';
    }

}