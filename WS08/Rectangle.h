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
#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_
#include "LblShape.h"

namespace sdds {
	class Rectangle: public LblShape {
		/*
		The Rectangle class inherits the LblShape class to create a frame with a label inside.
		*/

		/*
		Private Member variable
		Create two member variables called m_width and m_height to hold the width 
		and the height of a rectangular frame (number of characters).
		*/
		int m_width{};
		int m_height{};
	public:
		/*
		Default (no argument) constructor
		Sets the width and height member variables to zero. 
		It will also invoke the default constructor of the base class.
		*/
		Rectangle();

		void setEmpty();
		/*
		Three argument constructor
		Receives a Cstring for the label, 
		and two values for the width and height of the Rectangle from the argument list. 
		Passes the Cstring to the constructor of the base class 
		and sets the m_width and m_height member variables to the corresponding values received from the argument list. 
		
		However if the m_height is less than 3 or m_width is less the length of the label() + 2 
		it will set the Rectangle to an empty state.
		*/
		Rectangle(const char* labelContent, int width, int height);

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
		void getSpecs(std::istream& in);

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
		void draw(std::ostream& os) const;

	};


}

#endif // !SDDS_RECTANGLE_H_