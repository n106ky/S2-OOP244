/*
    OOP244
    WS2-LAB

    KA YING, CHAN
    123231227
    kchan151@myseneca.ca

    MOHAMMAD SHAMAS
    NEE

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    2023 May 23
*/

#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"

using namespace std;
namespace sdds {

    int noOfEmployees;
    Employee* employees;


    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // TODO: Finish the implementation of the 1 arg load function which
    // reads one employee record from the file and loads it into the employee reference argument
    bool load(struct Employee& emp) {
        bool ok = false;
        char name[128];

        if (read(emp.m_empNo) && read(emp.m_salary) && read(name)) {
            emp.m_name = new char[strLen(name) + 1];
            strCpy(emp.m_name, name);
            ok = true;
        }
        else {
            ok = false;
        }
        return ok;
    }

    // TODO: Finish the implementation of the 0 arg load function 
    bool load() {
        bool ok = false;
        int i;
        if (openFile(DATAFILE)) {
            noOfEmployees = noOfRecords();
            employees = new Employee[noOfEmployees];

            for (i = 0; i < noOfEmployees; i++) {
                if (load(employees[i])) {
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
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        return ok;
    }

    // TODO: Implementation for the display functions go here
    void display(const struct Employee& emp, int i)
    {
            cout << i + 1 << "- " << emp.m_empNo << ": " << emp.m_name << ", " << emp.m_salary << endl;
    }

    void display()
    {
        int i;
        sort();
        cout << "Employee Salary report, sorted by employee number\n"
            "no- Empno, Name, Salary\n"
            "------------------------------------------------\n";
        for (i = 0; i < noOfEmployees; i++)
        {
            display(employees[i], i);
        }
    }

    // TODO: Implementation for the deallocateMemory function goes here
    void deallocateMemory()
    {
        int i;
        for (i = 0; i < noOfEmployees; i++) {
            delete[] employees[i].m_name;
        }
        delete[] employees;
    }
}