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
#include <iostream>
#include <iomanip>
#include "LabelMaker.h"
#include "Label.h"
#include "cstring.h"

using namespace std;
namespace sdds {
    int num_labels;
    Label* lbl;

    // creates a dynamic array of Labels to the size of noOfLabels
    LabelMaker::LabelMaker(int noOfLabels) {
            num_labels = noOfLabels;
            lbl = new Label[num_labels];
    }

    // Gets the contents of the Labels as demonstrated in the Execution sample
    void LabelMaker::readLabels() {
        int i;
        cout << "Enter " << num_labels << " labels:" << endl;
        for (i = 0; i < num_labels; i++) {
            cout << "Enter label number " << i+1 << endl;
            cout << "> "; 
            lbl[i].readLabel();
        }
    }

    // Prints the Labels as demonstrated in the Execution sample
    void LabelMaker::printLabels() {
        int i;
        for (i = 0; i < num_labels; i++) {
            lbl[i].printLabel();
            cout << "\n";
        }
    }

    // Deallocates the memory when LabelMaker goes out of scope.
    LabelMaker::~LabelMaker() {
        delete[] lbl;
    }

}