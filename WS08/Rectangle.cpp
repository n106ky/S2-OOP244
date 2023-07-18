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
#include "Rectangle.h"

using namespace std;
namespace sdds {

	// PUBLIC MEMBERS:

	Rectangle::Rectangle() : LblShape() {}

	void Rectangle::setEmpty() {
		m_height = 0;
		m_width = 0;
	}

	Rectangle::Rectangle(const char* labelContent, int width, int height): LblShape(labelContent) {
		m_width = width;
		m_height = height;
		if(m_height < 3 || m_width < (int)strlen(label()+2)) {
			setEmpty();
		}
	}

	void Rectangle::getSpecs(std::istream& in) {
		LblShape::getSpecs(in);
		in >> m_width;
		in.ignore(); // IGNORE ','
		in >> m_height;
		in.ignore(100, '\n');
	}

	void Rectangle::draw(std::ostream& os) const {
		// char frame[] = "+-|";
		//cout << "\nm_height: " << m_height << '\n';
		//cout << "\nm_width: " << m_width << '\n';
		if (m_height > 0 && m_width > 0) {
			os << '+' << setw(m_width - 1) << setfill('-') << '+' << '\n';							/* LINE 1  */	// (m_width - 2)
			os << '|'  << setw(m_width - 2) << setfill(' ') << left << label() << '|' << '\n';		/* LINE 2  */	// (m_width - 2)
			for (int i = 0; i < (m_height - 3); i++) {												/* LINE 3+ */ 
				os << '|' << right << setw(m_width - 1) << '|' << '\n';
			}
			os << '+' << setw(m_width - 1) << setfill('-') << '+';									/*  LAST  */	// (m_width - 2)
		}
	}
}