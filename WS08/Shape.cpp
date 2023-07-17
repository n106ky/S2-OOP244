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
#include "Shape.h"

using namespace std;
namespace sdds {
	Shape::~Shape() {
	}

	ostream& operator<<(ostream& os, const Shape& s) {
		s.draw(os);
		return os;
	}
	istream& operator>>(istream& in, Shape& s) {
		s.getSpecs(in);
		return in;
	}
}