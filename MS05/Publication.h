/*
	OOP244 MS3

	KA YING, CHAN #123231227
	kchan151@myseneca.ca

	MOHAMMAD SHAMAS
	NEE

	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	COMPLETED: 2023 JULY 24
*/
#ifndef SDDS_PUBLICATION_H_
#define SDDS_PUBLICATION_H_
#include "Lib.h"
#include "Streamable.h"
#include "Date.h"
#include "Utils.h"

namespace sdds {

	/*
	Types of publications in Seneca Library

	Seneca Library holds two types of Publication; Periodical (like newspapers and Magazines) and Books.
	Publications are not loaned out to members.
	Members can check them out and read them in the library.
	These publications are put back on their shelves at the end of the day.

	Books can be borrowed and returned within 15 days.
	After 15 days, the member will be charged daily for a late penalty.
	*/

	/*
	The publication class is a general encapsulation of any periodic publication.
	Later by adding an author to the descendant of the Publication class we will encapsulate a Book for the system.
	*/
	class Publication : public Streamable {

		char* m_title{ nullptr };	// array of characters					// TITLE FOR THE PUBLICATION. DYNAMIC. MAX 255 CHAR.	// Wrong: char *m_title[255+1]{}; an array of character pointers with size of 256
		char m_shelfId[SDDS_SHELF_ID_LEN + 1]{};		// LOCATION OF THE PUBLICATION IN THE LIBRARY. EXACTLY 4 CHAR LONG. 
		int m_membership{};								/* MEMBERSHIP NUMBER OF MEMBERS OF THE LIBRARY. HOLD 5 DIGIT.
															IF NUMBER = 0, MEANS PUBLICATION IS AVALIABLE AND IS NOT CHECKED OUT BY ANY MEMBERS.
															IF NUMBER = 5, MEANS IT IS CHECKED OUT BY OTHER MEMBERS.*/
		int m_libRef{ -1 };								// INTERNAL SERIAL NUMBER TO UNIQUELY IDENTIFY EACH PUBLICATION IN THE SYSTEM. 1 BY DEFAULT. 
		Date m_date{}; 									/* A DATE OBJECT:
															PERIODICAL PUBLICATIONS:	USED AS THE PUBLISH DATE OF THE ITEM
															BOOKS:						USED AS "BORROWED DATE"
															DATE:						USED AS CURRENT DATE */
	public:

		// CONSTRUCTOR:
		Publication();									// Sets all the attributes to their default values.

		// MODIFIERS:
		void setToDefault();
		virtual void set(int member_id);				// Sets the membership attribute to either zero or a five-digit integer.
		void setRef(int value);							// Sets the **libRef** attribute value
		void resetDate();								// Sets the date to the current date of the system.

		// QUERIES:
		virtual char type()const;						// Returns the character 'P' to identify this object as a "Publication object"
		bool onLoan()const;								// Returns true is the publication is checkout (membership is non-zero)
		Date checkoutDate()const;						// Returns the date attribute
		bool operator==(const char* title)const;		// Returns true if the argument title appears anywhere in the title of the publication. 
														// Otherwise, it returns false; (use strstr() function in <cstring>)
		operator const char* ()const;					// Returns the title attribute
		int getRef()const;								// Returns the libRef attirbute.


		// STREAMABLE PURE VIRTUAL FUNCTIONS:
		bool conIO(std::ios& obj)const;					// Returns true if the address of the io object is the same as the address of either the cin object or the cout object.

		std::ostream& write(std::ostream& os)const;		// Display content
		std::istream& read(std::istream& is);			// Read all the values in local variables before setting the attributes to any values
		operator bool() const;							// Returns true if neither of the title or shelfId attributes is null or empty.

		// THE RULE OF THREE (COPYING IS ALLOWED):
		Publication(const Publication& src);
		Publication& operator=(const Publication& src);
		~Publication();
	};
}
#endif
