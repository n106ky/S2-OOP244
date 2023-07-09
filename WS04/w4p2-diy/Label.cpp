/*
    OOP244 WS4-LAB

    KA YING, CHAN
    123231227
    kchan151@myseneca.ca

    MOHAMMAD SHAMAS
    NEE

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    2023 JUN 8
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include "Label.h"
#include "cstring.h"

using namespace std;
namespace sdds {
    void Label::setToDefault() {
        m_content = nullptr;
        m_frame = nullptr;
        setFrame("+-+|+-+|");
    }

    void Label::setFrame(const char* frameArg) {
        if (frameArg && frameArg[0] != '\0') {
            delete[] m_frame;
            m_frame = nullptr;
            m_frame = new char[strLen(frameArg) + 1];
            strCpy(m_frame, frameArg);
        }
    }

    void Label::setContent(const char* content) {
        if (content && content[0] != '\0') {
            delete[] m_content;
            m_content = nullptr;
            m_content = new char[strLen(content) + 1];
            strCpy(m_content, content);
        }
    }

    // PUBLIC FUNCTIONS:

    // Creates an empty label and defaults the frame to "+-+|+-+|"
    Label::Label() {
        setToDefault();
    }

    // Creates an empty label and sets the frame to the frameArg argument.
    Label::Label(const char* frameArg) {
        setToDefault();
        setFrame(frameArg);
    }

    // Creates a Label with the frame set to frameArg and the content of the Label set to the corresponding argument.
    Label::Label(const char* frameArg, const char* content) {
        setToDefault();
        setFrame(frameArg);
        setContent(content);
    }

     // Makes sure there is no memory leak when the label goes out of scope.
    Label::~Label() {
        delete[] m_frame;
        m_frame = nullptr;
        delete[] m_content;
        m_content = nullptr;
    }

    // Reads the label from console up to 70 characters and stores it in the Label as shown in the Execution sample
    void Label::readLabel() {
        char labelStr[STR_SIZE + 1];
        scanf("%70[^\n]", labelStr);
        clearBuffer();
        setContent(labelStr);
    }

    // Prints the label by drawing the frame around the content ad shown in the Execution sample.
    std::ostream& Label::printLabel()const {
        if (m_frame && m_content) {
            cout << m_frame[0] << setw(strLen(m_content) + 3) << setfill(m_frame[1]) << m_frame[2] << endl;
            cout << m_frame[7] << setw(strLen(m_content) + 3) << setfill(' ') << m_frame[3] << endl;
            cout << m_frame[7] << " " << m_content << " " << m_frame[3] << endl;
            cout << m_frame[7] << setw(strLen(m_content) + 3) << setfill(' ') << m_frame[3] << endl;
            cout << m_frame[6] << setw(strLen(m_content) + 3) << setfill(m_frame[5]) << m_frame[4];
        };
        return cout;
    }

    void clearBuffer() {
        while (getchar() != '\n');
    }
}