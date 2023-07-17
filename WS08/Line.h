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
#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_
#include "LblShape.h"

/* THE LINE CONCRETE CLASS */

// Line inherits the LblShape class to create a horizontal line with a label.

namespace sdds {
	class Line: public LblShape {
		/*
		Private Member variable
		Create a member variable called m_length to hold the length of the Line in characters.
		*/
		int m_length{};
	public:
		/*
		Default (no argument) constructor
		Sets the m_length member variable to zero, 
		and invokes the default constructor of the base class.
		*/
		Line();

		/*
		Two argument constructor
		Receives a Cstring and a value for the length of the line. 
		Passes the Cstring to the constructor of the base class 
		and sets the m_length member variable to the value of the second argument.
		*/
		Line(const char* labelContent, int length);

		/*
		Destructor
		This class has no destructor implemented.
		*/

		/*
		getSpecs
		Reads comma-separated specs of the Line from istream.
		This function overrides the getSpecs function of the base class as follows.
		First, it will call the getSpecs function of the base class 
		then it will read the value of the m_length attribute from the istream argument, 
		and then it will ignore The rest of the characters up to and including the newline character '\n'.
		*/
		void getSpecs(std::istream& in);

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
		void draw(std::ostream& os) const;

	};
}

#endif // !SDDS_LINE_H
