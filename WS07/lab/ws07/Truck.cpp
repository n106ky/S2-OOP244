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
#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Truck.h"
using namespace std;
namespace sdds {

	// CONSTRUCTOR:
	Truck::Truck(const char* plateNo, int yrBuilt, double maxLoad, const char* vehAddress): MotorVehicle(plateNo, yrBuilt) {
		MotorVehicle::set(plateNo, yrBuilt);
		MotorVehicle::moveTo(vehAddress);
		m_MaxLoad = maxLoad;
	}

	// ADD AND UNLOAD CARGO:
	bool Truck::addCargo(double cargo) {
		bool isChanged = false;
		if (m_load == m_MaxLoad) {
			isChanged = false;
		}
		else if (m_load + cargo >= m_MaxLoad) {
			m_load = m_MaxLoad;
			isChanged = true;
		}
		else if (m_load + cargo <= m_MaxLoad){
			m_load += cargo;
			isChanged = true;
		}
		return isChanged;
	}
	bool Truck::unloadCargo() {
		bool isChanged = false;
		if (m_load > 0) {
			m_load = 0;
			isChanged = true;
		}
		return isChanged;
	}

	// READ FROM AND WRITE TO CONSOLE:
	ostream& Truck::write(ostream& os)const {
		os <<
			"| " << getYrBuilt() << " | " << getPlateNo() << " | " << getVehAddress() <<  " | " << m_load << '/' << m_MaxLoad;
		return os;
	}
	istream& Truck::read(istream& in) {
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> m_MaxLoad;
		cout << "Cargo: ";
		in >> m_load;

		return in;
	}

	// OVERLOAD DISPLAY AND READ:
	ostream& operator<<(ostream& os, const Truck& t) {
		return t.write(os);
	}
	istream& operator>>(istream& in, Truck& t) {
		return t.read(in);
	}
}