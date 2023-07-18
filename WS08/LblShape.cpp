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
	// PROTECTED MEMBERS:

	const char* LblShape::label() const {
		return m_label;
	}

	// PUBLIC MEMBERS:

	LblShape::LblShape() {}

	LblShape::LblShape(const char* labelContent) {
		if (labelContent) {
			m_label = new char[strlen(labelContent) + 1];
			strcpy(m_label, labelContent);
		}
	}

	LblShape::~LblShape() {
		delete[] m_label;
		m_label = nullptr;
	}

	void LblShape::getSpecs(istream& in) {
		char input[99 + 1];				// +1 for NULL TERMINATOR
		in.getline(input, 100, ',');	// GETLINE: will stop reading characters from the input stream once it encounters ','. 
		delete[] m_label;				// PREVENT MEMORY LEAK
		m_label = new char[strlen(input) + 1];
		strcpy(m_label, input);
	}
}