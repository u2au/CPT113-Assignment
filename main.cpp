//
// Created by rinsuki on 11/05/2022.
//
#include "Student.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Prototype
void welc();
void getFileLines(int &);
void inputValidation(int &, bool &, int &, int &, int &, bool &, bool &);

int main()
{
    // Variable Definition
    int matricNum = 111111,
        desa = 0,
        insuranceLevel = 0,
        parkingTimes = 0,
        lineOfFile = 0;

    bool isInt = true,
         isFullyVaccinated = false,
         isFreshman = true;

    double acadFee = 0.0,
           basicCost = 0.0,
           totalIntl = 0.0;

    // Welcome
    welc();

    // Get the number of the lines of 'Student.txt', which is the number of the students
    getFileLines(lineOfFile);

    // Array of Object (?
    Student Obj[1];

    // Open the file
    ifstream file;
    file.open("./Student.txt");

    // Overloading Constructor
    for (int numOfStudents = 0; numOfStudents < lineOfFile; numOfStudents++) {

        // Save the data to the variables
        if (file.is_open()) {
            file >> matricNum;
            file >> isFreshman; // class Tuition

            file >> desa;
            file >> insuranceLevel;
            file >> parkingTimes; // class Desa

            file >> isInt;
            file >> isFullyVaccinated; // class Intl

        } else cout << "Unable to open file\n";

        // Do the input Validation
        inputValidation(matricNum, isFreshman,
                        desa, insuranceLevel, parkingTimes,
                        isInt, isFullyVaccinated);

        // Pass the values through the overloading function of class Student
        Student(matricNum, isFreshman,
                desa, insuranceLevel, parkingTimes,
                isInt, isFullyVaccinated, acadFee, basicCost, totalIntl);

        cout << "The variables passed back from class Student: "
             << acadFee << basicCost << totalIntl << endl;
        
    }






//    // Save the matric num to the array of obj
//    for (int i = 0; i < fileLine; i++) {
//        Output[i].setValue(matricNum);
//    }

    // Not finished...

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
         << "Kindly press ENTER to start.";

    cin.get();
}

// Get the lines of 'Student.txt'
void getFileLines(int &line) {
    string temp;

    ifstream file;
    file.open("./Student.txt");

    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, temp);
            line++;
        }
    } else cout << "Unable to open the file: Student.txt" << endl;


    file.close();
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