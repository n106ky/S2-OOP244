/*
    OOP244
    WS2-LAB

    KA YING, CHAN
    123231227
    kchan151@myseneca.ca

    MOHAMMAD SHAMAS
    NEE

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    2023 May 23
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
FILE* fptr;
bool openFile(const char filename[]) {
    fptr = fopen(filename, "r");
    return fptr != NULL;
}
int noOfRecords() {
    int noOfRecs = 0;
    char ch;
    while (fscanf(fptr, "%c", &ch) == 1) {
        noOfRecs += (ch == '\n');
    }
    rewind(fptr);
    return noOfRecs;
}
void closeFile() {
    if (fptr) fclose(fptr);
}

// TODO: read functions go here    
bool read(char empNames[]) {
    return fscanf(fptr, "%[^\n]\n", empNames) == 1;
}
bool read(int& empNumber) {
    return fscanf(fptr, "%d,", &empNumber) == 1;
}
bool read(double& empSalary) {
    return fscanf(fptr, "%lf,", &empSalary) == 1;
}
}
