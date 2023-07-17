/*
	OOP244 WS07

	KA YING, CHAN
	123231227
	kchan151@myseneca.ca

	MOHAMMAD SHAMAS
	NEE

	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	2023 JULY 10
*/
#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H
#include "MotorVehicle.h"

namespace sdds {
	class Truck: public MotorVehicle {
		double m_MaxLoad{};
		double m_load{};
	public:
		// CONSTRUCTOR:
		Truck(const char* plateNo, int yrBuilt, double maxLoad, const char* vehAddress);

		// ADD AND UNLOAD CARGO:
		bool addCargo(double cargo);
		bool unloadCargo();

		// READ FROM AND WRITE TO CONSOLE:
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};

	// OVERLOAD DISPLAY AND READ:
	std::ostream& operator<<(std::ostream& os, const Truck& t);
	std::istream& operator>>(std::istream& in, Truck& t);
}


#endif