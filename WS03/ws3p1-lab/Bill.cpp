/*
	OOP244 WS3-LAB

	KA YING, CHAN
	123231227
	kchan151@myseneca.ca

	MOHAMMAD SHAMAS
	NEE

	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	2023 MAY 31
*/
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {

	// Private

	// Sets the Bill object to an empty state
	void Bill::setEmpty() {
		m_title[0] = '\0';
		m_items = nullptr;
	}

	// Returns true if m_title is not empty and m_items is not null and all the Items in the m_items array are valid.
	bool Bill::isValid() const {
		bool valid = false;
		int i;
		if (m_title != nullptr && m_title[0] != '\0' && m_items != nullptr) { 
			valid = true;
			for (i = 0; i < m_noOfItems && valid != false; i++) {
				valid = m_items[i].isValid();
			}
		}
		return valid;
	}

	// Adds all the taxes of the items using a loop and returns the sum.
	double Bill::totalTax() const {
		int i;
		double sumTax = 0.0;
		for (i = 0; i < m_noOfItems; i++) {
			sumTax += m_items[i].tax();
		}
		return sumTax;
	}

	// Adds all the prices of the items using a loop and returns the sum;
	double Bill::totalPrice() const {
		int i;
		double sumPrice = 0.0;
		for (i = 0; i < m_noOfItems; i++) {
			sumPrice += m_items[i].price();
		}
		return sumPrice;
	}

	// Prints the title in the following format:
	void Bill::Title()const {

		cout << "+--------------------------------------+\n";
		if (isValid()) {
			cout << "| " << left << setw(36) << m_title << " |" << endl;
		}
		else {
			cout << "| Invalid Bill                         |\n";
		}
		cout << "+----------------------+---------+-----+\n"
			"| Item Name            | Price   + Tax |\n"
			"+----------------------+---------+-----+\n";
	}

	// Prints the footer in the following format:
	void Bill::footer()const {
		cout << "+----------------------+---------+-----+\n";
		if (isValid()) {
			cout << fixed << setprecision(2);
			cout << "|                Total Tax: " << right << setw(10) << totalTax() << " |" << endl;
			cout << "|              Total Price: " << right << setw(10) << totalPrice() << " |" << endl;
			cout << "|          Total After Tax: " << right << setw(10) << totalTax() + totalPrice() << " |" << endl;

		}
		else {
			cout << "| Invalid Bill                         |\n";
		}
		cout << "+--------------------------------------+\n";
	}

	// Public

	//initializing list
	void Bill::init(const char* title, int noOfItems) {
		int i;
		if (title == nullptr || noOfItems <= 0) {
			setEmpty();
		}
		else {
			m_itemsAdded = 0;
			strnCpy(m_title, title, 36);
			m_noOfItems = noOfItems;
			m_items = new Item[m_noOfItems];
			for (i = 0; i < m_noOfItems; i++) {
				m_items[i].setEmpty();
			}
		}
	}

	// Add item to list
	bool Bill::add(const char* item_name, double price, bool taxed) {
		bool valid = false;
		if (m_itemsAdded < m_noOfItems) {
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded++;
			valid = true;
		}
		return valid;
	}

	// Display all items
	void Bill::display()const {
		Title();
		int i;
		for (i = 0; i < m_noOfItems; i++) {
			m_items[i].display();
		}
		footer();
	}

	// Deallocates dynamic memories
	void Bill::deallocate() {
		delete[] m_items;
		m_items = nullptr;
	}
}