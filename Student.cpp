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
    if (matricNum < 0) {
        cout << "Matriculation number must be greater than 0" << endl;
        exit(1);
    }
    if (livesInHostel < 0) {
        cout << "Lives in hostel must be greater than 0" << endl;
        exit(1);
    }
    if (insuranceLevel < 0) {
        cout << "Insurance level must be greater than 0" << endl;
        exit(1);
    }
    if (mealPlan < 0) {
        cout << "Mealplan must be greater than 0" << endl;
        exit(1);
    }
    if (isFreshman < 0 || isFreshman > 1) {
        cout << "Isfreshmanmust be 0 or 1" << endl;
        exit(1);
    }
    if (isInternational < 0 || isInternational > 1) {
        cout << "Isinternational must be 0 or 1" << endl;
        exit(1);
    }
    if (isFullyVaccinated < 0 || isFullyVaccinated > 1) {
        cout << "Isfullyvaccinated must be 0 or 1" << endl;
        exit(1);
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
