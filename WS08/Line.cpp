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
#include <iomanip>
#include <cstring>
#include "Line.h"

using namespace std;
namespace sdds {
	
	// PUBLIC MEMBERS:

	Line::Line(): LblShape() {}

	Line::Line(const char* labelContent, int length): LblShape(labelContent) {
		m_length = length;
	}

	void Line::getSpecs(std::istream& in) {
		LblShape::getSpecs(in);
		// DO NOT NEED, ALREADY IGNORED.
		//in.ignore(100,',');
		//in.ignore(); // IGNORE ',' 
		in >> m_length;
		in.ignore(100, '\n');
	}

	void Line::draw(std::ostream& os) const {
		//cout << "m_length: " << m_length << '\n';
		if (m_length > 0 && label()) {
			os << label() << endl;
			// os << setw(m_length+1) << setfill('=') << '\n'; // +1 for <newline>
			for (int i = 0; i < m_length; i++) {
				os << "=";
			}
		}
	}
}