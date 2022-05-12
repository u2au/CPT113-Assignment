//
// Created by rinsuki on 11/05/2022.
//
#include "Student.h"
#include "Desa.h"
#include "Intl.h"
#include "Tuition.h"
#include "Output.h"
#include "Student.cpp"
#include "Desa.cpp"
#include "Intl.cpp"
#include "Tuition.cpp"
#include "Output.cpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Prototype
void welc();
int getFileLines(int &);

void getData(int &, bool &, int &, int &, int &, bool &, bool &);
void inputValidation(int &, bool &, int &, int &, int &, bool &, bool &);

int main()
{
    // Variable Definition
    int fileLine = 0,
        matricNum = 111111,
        desa = 0,
        insuranceLevel = 0,
        parkingTimes = 0;

    bool isInt = true,
         isFullyVaccinated = false,
         isFreshman = true;

    // Welcome
    welc();

    // Get the number of lines of the data file
    getFileLines(fileLine);
    cout << fileLine << endl;

    // Array of object
    Student Output[fileLine];

//    // Save the matric num to the array of obj
//    for (int i = 0; i < fileLine; i++) {
//        Output[i].setValue(matricNum);
//    }

    // Not finished...

    // Get data and do input validation (with same parameters)
    getData(matricNum, isFreshman, // class Tuition
            desa, insuranceLevel, parkingTimes, // class Desa
            isInt, isFullyVaccinated); // class Intl

    inputValidation(matricNum, isFreshman,
                    desa, insuranceLevel, parkingTimes,
                    isInt, isFullyVaccinated);



    // Object of Array
//    Student Output[10];

//    // Call the constructors
//    Student(true);
//    Desa();
//    Intl();
//    Tuition();
//    Output();
//
//    // Get the values
//    Tuition(tuition, extraFee);

    return 0;
}

// Functions
void welc() {
    cout << "Welcome to use the Fee Calculator designed by Group 2 for Assignment 1 of CPT113!\n"
         << "This program may help you convert the choices of students to respective required amounts.\n"
         << "For example, it can convert the initial data '1' for desa to '600', "
         << "which means renting for a semester (5 months estimated), 150 per month.\n"
         << "Kindly press ENTER to start." << endl;

    cin.get();
}

int getFileLines(int &line) {
    string temp;

    ifstream file;
    file.open("./Student.txt");

    while(!file.eof()) {
        getline(file, temp);
        line++;
    }

    file.close();

    return line;
}

void getData(int &matric, bool &freshman, int &desa, int &insurance, int &parking, bool &intl, bool &vac) {
    ifstream file;
    file.open("./Student.txt");

    if (file.is_open()){
        file >> matric;
        file >> freshman;

        file >> desa;
        file >> insurance;
        file >> parking;

        file >> intl;
        file >> vac;

    }
    else cout << "Unable to open file\n";

}

void inputValidation(int &matric, bool &freshman, int &desa, int &insurance, int &parking, bool &intl, bool &vac) {
    // Matric Num (int, 0-999999)
    while (matric < 0 || matric > 999999) {
        cout << "Invalid matriculation number. Please re-enter (0-999999): ";
        cin >> matric;  // Re-enter the matriculation number
    }

    // Freshman? (bool, 0/1)
    while (freshman != 0 && freshman != 1) {
        cout << "Is " << matric << " a freshman? Please re-enter (0 - No, 1 - Yes): ";
        cin >> freshman;  // Re-enter whether a freshman
    }

    // Hostel Type (int, 0, 1-4)
    while (desa < 0 || desa > 4) {
        cout << "Invalid desa type for " << matric << ". Please re-enter (0-4): ";
        cin >> desa;  // Re-enter the hostel type
    }

    // Insurance Level (int, 0, 1-5)
    while (insurance < 0 || insurance > 5) {
        cout << "Invalid insurance level for " << matric << " . Please re-enter (0-5): ";
        cin >> insurance;  // Re-enter the insurance level
    }

    // Parking Times (int, 0, 1-100)
    while (parking < 0 || parking > 100) {
        cout << "Invalid parking times for " << matric << " . Please re-enter (0-100): ";
        cin >> parking;
    }

    // International student? (bool, 0/1)
    while (intl != 0 && intl != 1) {
        cout << "Invalid isInt. Is " << matric << " an international student? Please re-enter (0 - No, 1 - Yes): ";
        cin >> intl;  // Re-enter whether international student
    }

    // Fully Vaccinated? (bool, 0/1)
    while (vac != 0 && vac != 1) {
        cout << "Invalid vaccination status. Please re-enter (0 - Not Completed, 1 - Full): ";
        cin >> vac;  // Re-enter whether fully vaccinated
    }

}