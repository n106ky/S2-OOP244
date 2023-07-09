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
#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
#define CAL_MIN 0
#define CAL_MAX 3000

namespace sdds {
    class Food {
        char m_name[31];
        int m_cal;
        int m_time;
        char* m_meal;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, int cal, int time);
        void display()const;
        bool isValid()const;
        int calories()const;
        const char* meal()const;
    };
}
#endif