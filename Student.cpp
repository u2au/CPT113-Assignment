//
// Created by rinsuki on 29/04/2022.
//

#include "Student.h"
#include "Fee.h"
#include <iostream>
#include <fstream> // ifstream

using namespace std;

// Welcome
void welc() {
    cout << "Welcome to use Fee Calculator! \n";
}

// Read from file
void Student::readFile(){
    ifstream file;
    file.open("student.txt");
    if (file.is_open()){
        file >> matricNum; // Matric Number
        file >> livesInHostel;
        file >> isInternational;
        file >> insuranceLevel;
        file >> isFullyVaccinated;
        file >> monthlyMealPlan;
        file >> isFreshman;

    }
    else {
        cout << "Unable to open file\n";
    }

}

// Display the information
void Student::Display() {
    cout << "Matric Num: " << matricNum
    << "\nHostel Type: " << livesInHostel
    << "\nInternational Student? " << isInternational
    << "\nInsurance Level: " << insuranceLevel
    << "\nFully Vaccinated? " << isFullyVaccinated
    << "\nMonthly Meal Plan: " << monthlyMealPlan
    << "\nFreshman? " << isFreshman << endl;

}



// Default Constructor
Student::Student() {
    welc();
    readFile();
    Fee();
    Display();


}