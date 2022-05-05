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
    
//input validation
void Student::inputValidation() {
    // Input validation
    // Input validation
    if (matricNum < 100000 || matricNum > 999999) {
        cout << "Matriculation number must be greater than 0" << endl; // Validate matric number
        exit(1);  // exit if file not opened
    }
    if (livesInHostel < 0 || livesInHostel > 4) {
        cout << "Lives in hostel must be greater than 0" << endl; // Validate livesinhostel
        exit(1);  // exit if file not opened
    }
    if (insuranceLevel < 0 || insuranceLevel > 5) {
        cout << "Insurance level must be greater than 0" << endl; // Validate insurancelevel
        exit(1);  // exit if file not opened
    }
    if (mealPlan < 0 || mealPlan > 5) {
        cout << "Meal plan must be greater than 0" << endl; // Validate mealplan
        exit(1);  // exit if file not opened
    }
    if (isFreshman < 0 || isFreshman > 1) {
        cout << "Is freshman must be 0 or 1" << endl; // Validate isfreshman
        exit(1);  // exit if file not opened
    }
    if (isInternational < 0 || isInternational > 1) {
        cout << "Is international must be 0 or 1" << endl; // Validate isinternational
        exit(1);  // exit if file not opened
    }
    if (isFullyVaccinated < 0 || isFullyVaccinated > 1) {
        cout << "Is fully vaccinated must be 0 or 1" << endl; // Validate isfullyvaccinated
        exit(1);  // exit if file not opened
    }
};



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
