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

#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_
#include <iostream>

namespace sdds {

	// THE SHAPE INTERFACE

	/*
	Create the following two Pure virtual functions:
	A pure virtual function is a virtual function that has no implementation.
	To indicate that the pure virtual function does not have implementation set its prototype to zero (= 0;) in the class declaration.
	*/
	class Shape {
	public:
		/*
		PVF 1: draw
		Returns void and receives a reference to ostream as an argument.
		This pure virtual function can not modify the current object.
		*/
		virtual void draw(std::ostream& os) const = 0;


		/*
		PVF 2: getSpecs
		Returns void and receives a reference to istream as an argument.
		*/
		virtual void getSpecs(std::istream& in) = 0;


		/*
		destructor:
		Create a virtual empty destructor for the shape interface.
		This guarantees that any dynamically allocated derived class from the shape interface pointed by a base class pointer
		will be removed properly from memory when deleted.
		*/
		virtual ~Shape();
	};

	/*
	Shape helper functions:
	Overload the insertion and extraction operators (using draw and getSpecs functions) so any shape object can be 
	written or read using ostream and istream.
	*/
	std::ostream& operator<<(std::ostream& os, const Shape& s);
	std::istream& operator>>(std::istream& in, Shape& s);

}

#endif // !SDDS_SHAPE_H_