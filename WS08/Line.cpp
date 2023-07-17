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
	/*
	Default (no argument) constructor
	Sets the m_length member variable to zero,
	and invokes the default constructor of the base class.
	*/
	Line::Line(): LblShape() {}

	/*
	Two argument constructor
	Receives a Cstring and a value for the length of the line.
	Passes the Cstring to the constructor of the base class
	and sets the m_length member variable to the value of the second argument.
	*/
	Line::Line(const char* labelContent, int length): LblShape(labelContent) {
		m_length = length;
	}

	/*
	getSpecs
	Reads comma-separated specs of the Line from istream.
	This function overrides the getSpecs function of the base class as follows.
	First, it will call the getSpecs function of the base class
	then it will read the value of the m_length attribute from the istream argument,
	and then it will ignore The rest of the characters up to and including the newline character '\n'.
	*/
	void Line::getSpecs(std::istream& in) {
		LblShape::getSpecs(in);
		// DO NOT NEED, ALREADY IGNORED.
		//in.ignore(100,',');
		//in.ignore(); // IGNORE ',' 
		in >> m_length;
		in.ignore(100, '\n');
	}

	/*
	draw
	This function overrides the draw function of the base class.
	If the m_length member variable is greater than zero and the label() is not null,
	this function will first print the label() and then go to the new line.
	Afterwards it keeps printing the '=' (assignment character) to the value of the m_length member variable.
	Otherwise, it will take no action.

	For example, if the Cstring returned by the label query is "Separator"
	and the length is 40, the draw function should insert the following into ostream:

	Separator
	========================================
	*/
	void Line::draw(std::ostream& os) const {
		//cout << "m_length: " << m_length << '\n';
		if (m_length > 0 && label()) {
			os << label() << endl;
			os << setw(m_length) << setfill('=') << '\n';
		}
	}

}