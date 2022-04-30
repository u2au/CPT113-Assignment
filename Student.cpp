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
        file >> mealPlan;
        file >> isFreshman;

    }
    else {
        cout << "Unable to open file\n";
    }

}

// Input Validation
void Student::inputValidation() {
    // Hostel



}

// Display the information
void Student::Display() {
    cout << "Matric Num: " << matricNum << "\n"
         << "Hostel Type: " << livesInHostel << "\n"
         << "International Student? " << isInternational << "\n"
         << "Insurance Level: " << insuranceLevel << "\n"
         << "Fully Vaccinated? " << isFullyVaccinated << "\n"
         << "Meal Plan: " << mealPlan << "\n"
         << "Freshman? " << isFreshman << endl;

}


// Output the data
void Student::outputData() {


}


// Default Constructor
Student::Student() {
    welc();
    readFile();
    Fee();
//    Display();


}