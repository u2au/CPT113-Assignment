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
     if (matricNum < 0 || matricNum > 999999) {
        cout << "Invalid matriculation number. Please re-enter: "; 
        cin >> matricNum;  // Re-enter the matriculation number
        ofstream outFile;
        outFile.open("student.txt");
        outFile << matricNum << endl;
        outFile.close();
    }
    if (livesInHostel < 0 || livesInHostel > 4) {
        cout << "Invalid lives in hostel. Please re-enter: ";
        cin >> livesInHostel;  // Re-enter the lives in hostel
        ofstream outFile;
        outFile.open("student.txt");
        outFile << livesInHostel << endl;
        outFile.close();
    }
    if (insuranceLevel < 0 || insuranceLevel > 5) {
        cout << "Invalid insurance level. Please re-enter: ";
        cin >> insuranceLevel;  // Re-enter the insurance level
        ofstream outFile;
        outFile.open("student.txt");
        outFile << insuranceLevel << endl;
        outFile.close();
    }
    if (mealPlan < 0 || mealPlan > 5) {
        cout << "Invalid meal plan. Please re-enter: ";
        cin >> mealPlan;  // Re-enter the meal plan
        ofstream outFile;
        outFile.open("student.txt");
        outFile << mealPlan << endl;
        outFile.close();
    }
    if (isFreshman < 0 || isFreshman > 1) {
        cout << "Invalid is freshman. Please re-enter: ";
        cin >> isFreshman;  // Re-enter the is freshman
        ofstream outFile;
        outFile.open("student.txt");
        outFile << isFreshman << endl;
        outFile.close();
    }
    if (isInternational < 0 || isInternational > 1) {
        cout << "Invalid is international. Please re-enter: ";
        cin >> isInternational;  // Re-enter the is international
        ofstream outFile;
        outFile.open("student.txt");
        outFile << isInternational << endl;
        outFile.close();
    }
    if (isFullyVaccinated < 0 || isFullyVaccinated > 1) {
        cout << "Invalid is fully vaccinated. Please re-enter: ";
        cin >> isFullyVaccinated;  // Re-enter the is fully vaccinated
        ofstream outFile;
        outFile.open("student.txt");
        outFile << isFullyVaccinated << endl;
        outFile.close();
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
