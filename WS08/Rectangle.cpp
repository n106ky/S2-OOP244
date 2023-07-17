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
	/*
	Default (no argument) constructor
	Sets the width and height member variables to zero.
	It will also invoke the default constructor of the base class.
	*/
	Rectangle::Rectangle() : LblShape() {}

	void Rectangle::setEmpty() {
		m_height = 0;
		m_width = 0;
	}
	/*
	Three argument constructor
	Receives a Cstring for the label,
	and two values for the width and height of the Rectangle from the argument list.
	Passes the Cstring to the constructor of the base class
	and sets the m_width and m_height member variables to the corresponding values received from the argument list.

	However if the m_height is less than 3 or m_width is less the length of the label() + 2
	it will set the Rectangle to an empty state.
	*/

	// p.s: To call the base class constructor LblShape(labelContent) within the derived class constructor, 
	// you need to use the member initialization list and provide the base class constructor with the appropriate arguments.
	Rectangle::Rectangle(const char* labelContent, int width, int height): LblShape(labelContent) {
		m_width = width;
		m_height = height;
		if(m_height < 3 || m_width < strlen(label()+2)) {
			setEmpty();
		}
	}

	/*
	Destructor
	This class has no destructor implemented.
	*/

	/*
	getSpecs
	Reads comma-separated specs of the Rectangle from istream.
	This function overrides the getSpecs function of the base class as follows.

	First, it will call the getSpecs function of the base class,
	then it will read two comma-separated values from istream for m_width and m_length
	and then ignores the rest of the characters up to and including the newline character ('\n').
	*/
	void Rectangle::getSpecs(std::istream& in) {
		LblShape::getSpecs(in);
		//in.ignore(100, ',');
		//in.ignore(); // IGNORE ','
		in >> m_width;
		//in.ignore(100, ',');
		in.ignore(); // IGNORE ','
		in >> m_height;
		in.ignore(100, '\n');
		//in.ignore(); // IGNORE '\n'
	}

	/*
	draw
	This function overrides the draw function of the base class.
	If the Rectangle is not in an empty state, this function will draw a rectangle with a label inside as follows,
	otherwise, it will do nothing:

	First line:
	prints '+', then prints the '-' character (m_width - 2) times
	and then prints '+' and goes to newline.

	Second line:
	prints '|', then in (m_width-2) spaces it prints the label() left justified
	and then prints '|' and goes to new line.

	In next (m_height - 3) lines:
	prints '|', (m_width-2) spaces then prints '|' and goes to new line.

	Last line: exactly like first line.

	For example, if the Cstring returned by the label query is "Container",
	the width is 30 and the height is 5,
	this function should insert the following into ostream:
	+----------------------------+
	|Container                   |
	|                            |
	|                            |
	+----------------------------+
	*/
	void Rectangle::draw(std::ostream& os) const {
		// char frame[] = "+-|";
		//cout << "\nm_height: " << m_height << '\n';
		//cout << "\nm_width: " << m_width << '\n';
		if (m_height > 0 && m_width > 0) {
			/* LINE 1  */ os << '+' << setw(m_width - 2) << setfill('-') << '+' << '\n';
			/* LINE 2  */ os << '|'  << setw(m_width - 3) << setfill(' ') << left << label() << '|' << '\n';
			/* LINE 3+ */ 
			for (int i = 0; i < (m_height - 3); i++) {
				os << '|' << right << setw(m_width - 2) << '|' << '\n';
			}
			/*  LAST  */ os << '+' << setw(m_width - 2) << setfill('-') << '+';
		}
	}




}