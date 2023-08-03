/*
    OOP244 MS3

    KA YING, CHAN #123231227
    kchan151@myseneca.ca

    MOHAMMAD SHAMAS
    NEE

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    COMPLETED: 2023 JULY 21
*/
#ifndef SDDS_LIB_H_
#define SDDS_LIB_H_

namespace sdds {
    // GENERAL VALUES OF THE SYSTEM
    const int SDDS_MAX_LOAN_DAYS = 15;          // Maximum number of day a publication can be borrowed with no penalty
    const int SDDS_TITLE_WIDTH = 30;            // The width in which the title of a publication should be printed on the console
    const int SDDS_AUTHOR_WIDTH = 15;           // The width in which the author name of a book should be printed on the console
    const int SDDS_SHELF_ID_LEN = 4;            // The width in which the shelf id of a publication should be printed on the console
    const int SDDS_LIBRARY_CAPACITY = 5000;     // Maximum number of publications the library can hold.
}
#endif // !SDDS_LIB_H_
