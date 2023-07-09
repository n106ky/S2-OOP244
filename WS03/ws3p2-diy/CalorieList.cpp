/*
	OOP244 WS3-DIY

	KA YING, CHAN
	123231227
	kchan151@myseneca.ca

	MOHAMMAD SHAMAS
	NEE

	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	2023 JUN 1
*/
#include <iostream>
#include <cstdio>
#include <iomanip>
#include "CalorieList.h"
using namespace std;
namespace sdds {
    
	// Private

	// Sets the CalorieList to an empty state
	void CalorieList::setEmpty() {
		m_items = nullptr;
	}

	// Returns true if all the Items in the m_items array are valid
	bool CalorieList::isValid() const {
		bool valid = false;
		int i;
		if (m_items != nullptr) {
			valid = true;
			for (i = 0; i < m_noOfItems && valid != false; i++) {
				valid = m_items[i].isValid();
			}
		}
		return valid;
	}
	
	// Calculate total Calories for today
	int CalorieList::totalCal() const {
		int i;
		int sumCal = 0;
		for (i = 0; i < m_noOfItems; i++) {
			sumCal += m_items[i].calories();
		}
		return sumCal;
	}

	// Prints the title in the following format:
	void CalorieList::Title()const {

		cout << "+----------------------------------------------------+\n";
		if (isValid()) {
			cout << "| " << left << setw(50) << " Daily Calorie Consumption" << " |" << endl;
		}
		else {
			cout << "| " << left << setw(50) << "Invalid Calorie Consumption list" << " |" << endl;
		}
		cout << 
			"+--------------------------------+------+------------+\n"
			"| Food name                      | Cals | When       |\n"
			"+--------------------------------+------+------------+\n";
	}

	// Prints the footer in the following format:
	void CalorieList::footer()const {
		cout << "+--------------------------------+------+------------+\n";
		if (isValid()) {
			cout << "|    Total Calories for today: " << right << setw(8) << totalCal() << " |" << setw(13) << " |"  << endl;

		}
		else {
			cout << "|    Invalid Calorie Consumption list                |\n";
		}
		cout << "+----------------------------------------------------+\n";
	}

	// Public
	//initializing the list
	void CalorieList::init(int size) {
		int i;
		if (size <= 0) {
			setEmpty();
		}
		else {
			m_itemsAdded = 0;
			m_noOfItems = size;
			m_items = new Food[m_noOfItems];
			for (i = 0; i < m_noOfItems; i++) {
				m_items[i].setEmpty();
			}
		}
	}

	// Add items to the list
	bool CalorieList::add(const char* item_name, int calories, int when) {
		bool valid = false;
		if (m_itemsAdded < m_noOfItems) {
			m_items[m_itemsAdded].set(item_name, calories, when);
			m_itemsAdded++;
			valid = true;
		}
		return valid;
	}

	// Display all items
	void CalorieList::display()const {
		Title();
		int i;
		for (i = 0; i < m_noOfItems; i++) {
			m_items[i].display();
		}
		footer();
	}

	// Deallocates dynamic memories
	void CalorieList::deallocate() {
		delete[] m_items;
		m_items = nullptr;
	}
}