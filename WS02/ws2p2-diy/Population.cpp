/*
    OOP244 WS2-DIY

    KA YING, CHAN
    123231227
    kchan151@myseneca.ca

    MOHAMMAD SHAMAS
    NEE

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    2023 May 24
*/

#include <iostream>
#include "Population.h"
#include "File.h"


using namespace std;
namespace sdds {

	int totalRecords;
	Population* pop;

    bool load(struct Population& pop) {
		return read(pop.postal_code) && read(pop.regional_pop);
    }

    bool load(const char filename[]) {
        bool ok = false;
        int i;
        if (openFile(filename)) {
            totalRecords = noOfRecords();
            pop = new Population[totalRecords];
            for (i = 0; i < totalRecords; i++) {
                if (load(pop[i])) {
                    ok = true;
                }
                else {
                    cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
                    ok = false;
                }
            }
            closeFile();
        }
        else {
            cout << "Could not open data file: " << filename << endl;
        }
        return ok;
    }

    void sort() {
        int i, j;
        Population temp;
        for (i = totalRecords - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (pop[j].regional_pop > pop[j + 1].regional_pop) {
                    temp = pop[j];
                    pop[j] = pop[j + 1];
                    pop[j + 1] = temp;
                }
            }
        }
    }

    // Calculate the population of Canada (The sum of population of all regions)
	int sumOfPopulation()
	{
		int i;
		int sum = 0;
		for (i = 0; i < totalRecords; i++) {
			sum += pop[i].regional_pop;
		}
		return sum;
	}

	void display() {
		int i = 0;
        sort();
		cout << "Postal Code: population\n"
			"-------------------------" << endl;
		for (i = 0; i < totalRecords; i++) {
			cout << i + 1 << "- " << pop[i].postal_code << ":  " <<  pop[i].regional_pop << endl;
		}
		cout << "-------------------------\n"
			"Population of Canada: " << sumOfPopulation() << endl;
	}

	void deallocateMemory() {
		delete[] pop;
	}
}