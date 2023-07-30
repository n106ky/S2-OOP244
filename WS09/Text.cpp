/*
    OOP244 NEE WS09
    MOHAMMAD SHAMAS

    KA YING, CHAN #123231227
    kchan151@myseneca.ca

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Completed date: 2023 JULY 26
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "Text.h"
#include "cstring.h"
using namespace std;
namespace sdds {
    int Text::getFileLength() const {
        int len = 0;
        ifstream fin(m_filename);
        while (fin) {
            fin.get();
            len += !!fin;
        }
        return len;
    }

    // PROTECTED FUNCTIONS:
    const char& Text::operator[](int index)const {
        return m_content[index];
    }

    // GETTER: return length to child class
    int Text::getContentLen() const {
        return getFileLength();
    }

    // CONSTRUCTOR:
    Text::Text(const char* filename) {
        if (filename) {
            m_filename = new char[strLen(filename) + 1];
            strCpy(m_filename, filename);
        }
    }

    // RULE OF THREE
    Text::Text(const Text& x) {
        *this = x;
        // cout << "Copy Constructor" << endl;
    }
    Text& Text::operator=(const Text& x) {
        if (this != &x) {
            if (x.m_filename) { // && x.m_content
                if (m_filename) {
                    delete[] m_filename;
                    m_filename = nullptr;
                }
                m_filename = new char[strLen(x.m_filename) + 1];
                strcpy(m_filename, x.m_filename);
                read();
                // m_content = new char[strlen(x.m_content) + 1];
                // strcpy(m_content, x.m_content);
                // cout << "Copy Assignment" << endl;
           }
        }
        return *this;
    }
    Text::~Text() {
        delete[] m_filename;
        m_filename = nullptr;
        delete[] m_content;
        m_content = nullptr;
    }

    // DISPLAY & READ
    void Text::read() {
        fstream m_file;
        int i = 0;
        char ch = 'x';
        m_file.open(m_filename, ios::in);
        if (m_file.is_open()) {
            if (m_content) {
                delete[] m_content;
                m_content = nullptr;
            }
            m_content = new char[getFileLength() + 1];
            while (m_file.get(ch)) {
                m_content[i++] = ch;
            }
        }
        m_content[i] = '\0';
        m_file.close();
    }
    void Text::write(ostream& os) const {
        if (m_content) {
            os << m_content; // << endl;
        }
    }

    ostream& operator<<(ostream& os, const Text& x) {
        x.write(os);
        return os;
    }

}