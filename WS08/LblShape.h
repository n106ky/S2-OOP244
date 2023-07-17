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
#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_
#include "Shape.h"
namespace sdds {

	// The LBLSHAPE ABSTRACT CLASS (THE LEBELED SHAPE CLASS)

	/*
	Inherit an abstract class from the interface Shape called LblShape.
	This class adds a label to a Shape.

	This class will implement the pure virtual function getSpecs but will not implement the draw function;
	Therefore it remains abstract.
	*/
	class LblShape : public Shape {

		/*Private Member variable:
		Add a character pointer member variable called m_label and initialize it to null.
		This member variable will be used to hold the dynamically allocated label for the Shape.
		*/
		char* m_label{ nullptr };


	protected: // WHY DO WE NEED TO MAKE IT PROTECTED AGAIN? (ONLY FOR DERIVED MEMBER RIGHT?)
		/*
		Protected members:
		label()
		Add a query called label that returns the unmodifiable value of m_label member variable.
		*/
		const char* label() const;

	public:
		// Public members:
		/*
		Default (no argument) constructor
		Sets the label pointer to null. 
		(You don't need to do this if the m_label is already initialized to null)
		*/
		LblShape();

		/*
		One argument constructor
		Allocates memory large enough to hold the incoming Cstring argument pointed by the m_label member variable. 
		Then copies the Cstring argument to the newly allocated memory.
		*/
		LblShape(const char* labelContent);

		// *** RULE OF THREE ***
		/*
		Destructor
		Deletes the memory pointed by m_label member variable.
		*/
		virtual ~LblShape();
		/*
		deleted actions
		The copy constructor and assignment operator are deleted to prevent copying or assignment of instances of this class.
		*/
		LblShape(const LblShape& src) = delete;
		LblShape& operator=(const LblShape& src) = delete;
		
		/*
		getSpecs
		Reads a comma-delimited Cstring form istream:
		Override the Shape::getSpecs pure virtual function to receive a Cstring (a label) from istream up to the ',' character (and then extract and ignore the comma). 
		Afterward, follow the same logic as was done in the one argument constructor; 
		Allocate memory large enough to hold the Cstring and copy the Cstring into the newly allocated memory.
		*/
		virtual void getSpecs(std::istream& in);


		// Will not implement the draw function
		virtual void draw(std::ostream& os) const = 0;
	};	
}

#endif // !SDDS_LBLSHAPE_H_
