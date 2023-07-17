/*
	OOP244 WS08

	KA YING, CHAN
	123231227
	kchan151@myseneca.ca

	MOHAMMAD SHAMAS
	NEE

	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	2023 JULY 17
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "LblShape.h"

using namespace std;
namespace sdds {
	/*
	Protected members:
	label()
	Add a query called label that returns the unmodifiable value of m_label member variable.
	*/
	const char* LblShape::label() const {
		return m_label;
	}
	// Public members:
	/*
	Default (no argument) constructor
	Sets the label pointer to null.
	(You don't need to do this if the m_label is already initialized to null)
	*/
	LblShape::LblShape() {}

	/*
	One argument constructor
	Allocates memory large enough to hold the incoming Cstring argument pointed by the m_label member variable.
	Then copies the Cstring argument to the newly allocated memory.
	*/
	LblShape::LblShape(const char* labelContent) {
		if (labelContent) {
			m_label = new char[strlen(labelContent) + 1];
			strcpy(m_label, labelContent);
		}
	}

	/*
	Destructor
	Deletes the memory pointed by m_label member variable.
	*/
	LblShape::~LblShape() {
		delete[] m_label;
	}

	/*
	getSpecs
	Reads a comma-delimited Cstring form istream:
	Override the Shape::getSpecs pure virtual function to receive a Cstring (a label) from istream up to the ',' character (and then extract and ignore the comma).
	Afterward, follow the same logic as was done in the one argument constructor;
	Allocate memory large enough to hold the Cstring and copy the Cstring into the newly allocated memory.
	*/
	void LblShape::getSpecs(istream& in) {
		char input[99 + 1]; // +1 for NULL TERMINATOR
		in.getline(input, 100, ','); // The function will stop reading characters from the input stream once it encounters ','. 
		if (input) {
			m_label = new char[strlen(input) + 1];
			strcpy(m_label, input);
		}
	}

}