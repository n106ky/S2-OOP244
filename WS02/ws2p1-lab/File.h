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
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();

	// TODO: Declare read prototypes
	bool read(char empNames[]);
	bool read(int& empNumber);
	bool read(double& empSalary);
}
#endif // !SDDS_FILE_H_
