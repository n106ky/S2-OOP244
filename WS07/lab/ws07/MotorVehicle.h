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
#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H

namespace sdds {
	class MotorVehicle {
		char m_plateNo[9]{};		// a license plate number as a statically allocated array of characters of size 9.
		char m_vehAddress[64]{};	// the address where the vehicle is at a given moment as a statically allocated array of characters of size 64.
		int m_yrBuilt{};			// the year when the vehicle was built.
	public:
		// CONSTRUCTORS:
		MotorVehicle();
		MotorVehicle(const char* plateNo, int yrBuilt);

		void set(const char* plateNo, int yrBuilt);	// Set valid (exist) plate number and year built to currect object
		void moveTo(const char* address);			// Moves the vehicle to the new address

		// READ FROM AND WRITE TO CONSOLE:
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);

		// GETTERS:
		const char* getPlateNo()const;
		const char* getVehAddress()const;
		int getYrBuilt()const;

	};

	// OVERLOAD DISPLAY AND READ:
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& mv);
	std::istream& operator>>(std::istream& os, MotorVehicle& mv);
}


#endif
