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
#include "MotorVehicle.h"
using namespace std;
namespace sdds {

	// CONSTRUCTORS:
	MotorVehicle::MotorVehicle() {
		// cout << "Creating Motor Vehicle with No Data" << endl;
	}
	MotorVehicle::MotorVehicle(const char* plateNo, int yrBuilt) { // : m_vehAddress("Factory") 
		set(plateNo, yrBuilt);
		strnCpy(m_vehAddress, "Factory", 8);
	}

	// Set valid (exist) plate number and year built to currect object
	void MotorVehicle::set(const char* plateNo, int yrBuilt) {
		if (plateNo && plateNo[0] != '\0') {
			strCpy(m_plateNo, plateNo);
		}
		if (yrBuilt) {
			m_yrBuilt = yrBuilt;
		}
	}
	// Moves the vehicle to the new address
	void MotorVehicle::moveTo(const char* address) {
		if (strCmp(m_vehAddress, address) != 0) {
			cout <<
				"|" << setw(8) << right << m_plateNo << "|" <<
				" |" << setw(20) << right << m_vehAddress << 
				" ---> " << setw(20) << left << address << "|" << endl;
				strnCpy(m_vehAddress, address, strLen(address) + 1);
		}
	}

	// READ FROM AND WRITE TO CONSOLE:
	ostream& MotorVehicle::write(ostream& os)const {
		os << 
			"| " << m_yrBuilt << 
			" | " << m_plateNo << 
			" | " << m_vehAddress;
		return os;
	}
	istream& MotorVehicle::read(istream& in) {
		// DO NOT NEED DYNAMIC ALLOCATION

		cout << "Built year: ";
		in >> m_yrBuilt;
		cout << "License plate: ";
		in >> m_plateNo;
		cout << "Current location: ";
		in >> m_vehAddress;

		return in;
	}

	// GETTERS:
	const char* MotorVehicle::getPlateNo()const {
		return m_plateNo;
	}
	const char* MotorVehicle::getVehAddress()const {
		return m_vehAddress;
	}
	int MotorVehicle::getYrBuilt()const {
		return m_yrBuilt;
	}

	// HELPER FUNCTIONS:

	// OVERLOAD DISPLAY AND READ:
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& mv) {
		return mv.write(os);
	}
	std::istream& operator>>(std::istream& in, MotorVehicle& mv) {
		return mv.read(in);
	}
}
