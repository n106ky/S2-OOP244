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
#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include <iostream>
#include "Label.h"

namespace sdds {
    class LabelMaker {
        
    public:
        // creates a dynamic array of Labels to the size of noOfLabels
        LabelMaker(int noOfLabels);

        // Gets the contents of the Labels as demonstrated in the Execution sample
        void readLabels();

        // Prints the Labels as demonstrated in the Execution sample
        void printLabels();

        // Deallocates the memory when LabelMaker goes out of scope.
        ~LabelMaker();
    };
 }
#endif // !SDDS_LABELMAKER_H