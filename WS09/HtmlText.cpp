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
#include <cstring>
#include "HtmlText.h"
#include "cstring.h"
using namespace std;
namespace sdds {

    HtmlText::HtmlText(const char* filename, const char* title):Text(filename) {
        if (title) {
            m_title = new char[strLen(title) + 1];
            strCpy(m_title, title);
        }
    }

    // RULE OF THREE
    HtmlText::HtmlText(const HtmlText& ht) {
        *this = ht;
    }
    HtmlText& HtmlText::operator=(const HtmlText& ht) {
        if (this != &ht) {
            Text::operator=(ht);
            if (ht.m_title) {
                if (m_title) {
                    delete[] m_title;
                    m_title = nullptr;
                }
                m_title = new char[strLen(ht.m_title) + 1];
                strCpy(m_title, ht.m_title);
            }
        }
        return *this;
    }
    HtmlText::~HtmlText() {
        delete[] m_title;
        m_title = nullptr;
    }

     // WRITE OVERRIDE
    void HtmlText::write(ostream& os) const {
        bool occur_MS = false;

        os << "<html><head><title>";
        m_title ? os << m_title : os << "No title";
        os << "</title></head>\n<body>\n";
        if (m_title) {
            os << "<h1>" << m_title << "</h1>\n";
        }
        int contentLen = Text::getContentLen();
        for (int i = 0; i < contentLen; i++) {
            char ch = Text::operator[](i);
            switch (ch) {
            case ' ':
                // NOT WORKING AS IT IS CHANGING THE FIRST ONE NOT THE SECOND ONE.
                //if (Text::operator[](i+1) == ' ') {
                //    os << "&nbsp;";
                //}
                //else {
                //    os << ' ';
                //}
                if (occur_MS) {
                    os << "&nbsp;";
                }
                else {
                    occur_MS = true;
                    os << ' ';
                }
                break;
            case '<':
                occur_MS = false;
                os << "&lt;";
                break;
            case '>':
                occur_MS = false;
                os << "&gt;";
                break;
            case '\n':
                occur_MS = false;
                os << "<br />\n";
                break;
            default:
                occur_MS = false;
                os << ch;
                break;
            }
        }
        os << "</body>\n</html>";
    }
}