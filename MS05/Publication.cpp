/*
	OOP244 Milestone

	KA YING, CHAN #123231227
	kchan151@myseneca.ca

	MOHAMMAD SHAMAS
	NEE

	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	MS03: 2023 JULY 29
	MS51: 2023 AUG 3
*/
#define _CRT_SECURE_NO_WARNINGS
// #include <ios>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Publication.h"

using namespace std;
namespace sdds {

	// CONSTRUCTOR:
	Publication::Publication() {
		setToDefault();
		// cout << "CREATING NEW PUBLICATION BY DEFAULT" << endl;
	}


	// MODIFIERS:
	void Publication::setToDefault() {
		if (m_title) {
			delete[] m_title;
		}
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		resetDate();
	}
	void Publication::set(int member_id) {
		m_membership = member_id;
	}
	void Publication::setRef(int value) {
		m_libRef = value;
	}
	void Publication::resetDate() {
		m_date = Date();
	}


	// QUERIES:
	char Publication::type()const {
		return 'P';
	}
	bool Publication::onLoan()const {
		return (m_membership != 0); // EITHER 0 or 5 digits
	}
	Date Publication::checkoutDate()const {
		return m_date;
	}
	bool Publication::operator==(const char* title)const {
		return strstr(m_title, title) != nullptr;
	}										
	Publication::operator const char* ()const {
		return m_title;
	}
	int Publication::getRef()const {
		return m_libRef;
	}


	// STREAMABLE PURE VIRTUAL FUNCTIONS:
	bool Publication::conIO(ios& obj)const {
		return (&cin == &obj || &cout == &obj);
	}
	ostream& Publication::write(ostream& os)const {
		if (conIO(os)) {
			// ADD IN MS4:
			char temp_title[SDDS_TITLE_WIDTH + 1]{};
			strncpy(temp_title, m_title, SDDS_TITLE_WIDTH);

			// ORIGINAL:
			os << "| " << m_shelfId << " | " << setw(30) << left << setfill('.') << temp_title << " | ";
			onLoan() ? os << m_membership : os << " N/A ";
			os << " | " << checkoutDate() << " |"; // m_date;

		}
		else {
			os << type() << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t";
			// onLoan() ? os << m_membership : os << " N/A ";
			os << m_membership << "\t" << checkoutDate(); // m_date;
			if (type() == 'P') {
				os << endl;
			}
		}
		return os;
	}
	istream& Publication::read(istream& in) {
		// Read all the values in LOCAL variables before setting the attributes.
		// Not correct:
		//char* temp_title{};
		//char *temp_shelfId{};
		char temp_title[255 + 1]{};
		char temp_shelfId[SDDS_SHELF_ID_LEN + 1]{};
		int temp_membership = 0;
		int temp_libRef = -1;
		Date temp_date;
		setToDefault();
		if (conIO(in)) {
			cout << "Shelf No: ";
			in >> temp_shelfId; // read the shelf number up to its limit
			if (strlen(temp_shelfId) != SDDS_SHELF_ID_LEN) {
				// Manually set the 'is' object to a fail state
				// in.clear(); // To clear (reset) any previous error flags
				in.setstate(ios::failbit);
			}
			cout << "Title: ";
			in.ignore();
			in.getline(temp_title, '\n');
			cout << "Date: ";
			in >> temp_date;
		}
		else {
			in >> temp_libRef;
			in.ignore(100, '\t'); // in.ignore();
			in.getline(temp_shelfId, SDDS_SHELF_ID_LEN + 1, '\t');
			in.getline(temp_title, 255 + 1, '\t');
			in >> temp_membership;
			in.ignore(); // in.ignore(100, '\t');
			in >> temp_date;
		}
		if (!temp_date) { // Not correct: temp_date.operator bool()
			in.setstate(ios::failbit);
		}
		if (in) { // !in.fail()
			m_title = new char[strlen(temp_title)+1];
			strcpy(m_title, temp_title);
			strcpy(m_shelfId, temp_shelfId);
			set(temp_membership);
			setRef(temp_libRef);
			m_date = temp_date;
		}
		return in;
	}
	Publication::operator bool() const {
		return (m_shelfId && m_shelfId[0] != '\0' && m_title && m_title[0] != '\0');
	}


	// THE RULE OF THREE
	Publication::Publication(const Publication& src) {
		//if (src){
		//	m_title = new char[strlen(src.m_title) + 1];
		//	strcpy(m_title, src.m_title);
		//	strcpy(m_shelfId, src.m_shelfId);
		//  set(src.m_membership);
		//  setRef(src.m_libRef);
		//	m_date = src.m_date;
		//	cout << "CREATING NEW PUBLICATION WITH COPY CONSTRUCTOR" << endl;
		//}
		*this = src;
	}
	Publication& Publication::operator=(const Publication& src) {
		if (this != &src) {
			if (src) {  // Same as src.operator bool()
				if (m_title) {
					delete[] m_title;
					m_title = nullptr;
				}
				m_title = new char[strlen(src.m_title) + 1];
				strcpy(m_title, src.m_title);
				strcpy(m_shelfId, src.m_shelfId);
				set(src.m_membership);
				setRef(src.m_libRef);
				m_date = src.m_date;
				// cout << "CREATING NEW PUBLICATION WITH COPY ASSIGNMENT" << endl;
			}
		}
		return *this;
	}
	Publication::~Publication() {
		delete[] m_title;
	}

}