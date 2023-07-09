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

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

#define CODE_SIZE 3

namespace sdds {
	struct Population {
		char postal_code[CODE_SIZE + 1];
		int regional_pop;
	};

    bool load(struct Population& pop);
	bool load(const char filename[]);

    // Calculate the population of Canada (The sum of population of all regions)
	int sumOfPopulation();

	void display();
	void deallocateMemory();

}
#endif // SDDS_POPULATION_H_