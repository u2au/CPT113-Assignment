//
// Created by rinsuki on 29/04/2022.
//

#include "Student.h"
#include <iostream>
#include <fstream>

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
        file >> matricNum;
        file >> hostelType;
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

bool Student::getIntl() const {
    return isInternational;

}

bool Student::getVacStat() const {
    return isFullyVaccinated;

}

// Input Validation
void Student::inputValidation() {

    // Initialization
    ofstream correctData;
    correctData.open("student.txt");

    // Matric Num (double, 0-999999)
     while (matricNum < 0 || matricNum > 999999) {
        cout << "Invalid matriculation number. Please re-enter: "; 
        cin >> matricNum;  // Re-enter the matriculation number
        correctData << matricNum;
    }


     // Hostel Type (int, 0, 1-4)
    while (hostelType < 0 || hostelType > 4) {
        cout << "Invalid hostel type for " << matricNum << ". Please re-enter: ";
        cin >> hostelType;  // Re-enter the hostel type
        correctData << hostelType;
    }
    

    // International student? (bool, 0/1)
    while (isInternational != 0 && isInternational != 1) {
        cout << "Invalid is international. Please re-enter: ";
        cin >> isInternational;  // Re-enter whether international student
        correctData << isInternational;
    }

    
    // Insurance Level (int, 0, 1-5)
    while (insuranceLevel < 0 || insuranceLevel > 5) {
        cout << "Invalid insurance level. Please re-enter: ";
        cin >> insuranceLevel;  // Re-enter the insurance level
        correctData << insuranceLevel;
    }

    
    // Is Fully Vaccinated? (bool, 0/1)
    while (isFullyVaccinated != 0 && isFullyVaccinated != 1) {
        cout << "Invalid is fully vaccinated. Please re-enter: ";
        cin >> isFullyVaccinated;  // Re-enter whether fully vaccinated
        correctData << isFullyVaccinated;
    }
    

    // Meal Plan (int, 0, 1-5)
    while (mealPlan < 0 || mealPlan > 5) {
        cout << "Invalid meal plan. Please re-enter: ";
        cin >> mealPlan;  // Re-enter the meal plan
        correctData << mealPlan;
    }


    // Freshman? (bool, 0/1)
    while (isFreshman != 0 && isFreshman != 1) {
        cout << "Invalid is freshman. Please re-enter: ";
        cin >> isFreshman;  // Re-enter whether a freshman
        correctData << isFreshman;
    }


    // Close the original data file after the input validation
    correctData.close();

};

// Display the information (DEBUG)
//void Student::Display() {
//    cout << "Matric Num: " << matricNum << "\n"
//         << "Hostel Type: " << hostelType << "\n"
//         << "International Student? " << isInternational << "\n"
//         << "Insurance Level: " << insuranceLevel << "\n"
//         << "Fully Vaccinated? " << isFullyVaccinated << "\n"
//         << "Meal Plan: " << mealPlan << "\n"
//         << "Freshman? " << isFreshman << endl;
//
//}


// Output the data
//void Student::outputData() {
//
//
//}

// Get Sem
int Student::getSem() const {
    return sem;
}

// Get Meal Plan
int Student::getMealPlan() const {
    return mealPlan;
}

// Calculate Total Fees
//double Student::calcTotalFees() {
//    return 0;
//
//}
int Student::getInsuranceLevel()const{
    return insuranceLevel;
}

int Student::getCourseNum() const {
    return courseNum;
}

// Default Constructor
Student::Student() {
    welc();
    readFile();
    inputValidation();
//    Display();

}


