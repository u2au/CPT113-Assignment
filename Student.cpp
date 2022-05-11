//
// Created by rinsuki on 11/05/2022.
//

#include "Student.h"
#include <fstream>

// Get data
// Read from file
void Student::getData(){
    ifstream file;
    file.open("./Student.txt");

    if (file.is_open()){
        file >> matricNum;
        file >> isFreshman;

        file >> desa;
        file >> insuranceLevel;
        file >> parkingTimes;

        file >> isInt;
        file >> isFullyVaccinated;

    }
    else {
        cout << "Unable to open file\n";
    }

}

void Student::inputValidation() {
    // Matric Num (double, 0-999999)
    while (matricNum < 0 || matricNum > 999999) {
        cout << "Invalid matriculation number. Please re-enter: ";
        cin >> matricNum;  // Re-enter the matriculation number
    }

    // Freshman? (bool, 0/1)
    while (isFreshman != 0 && isFreshman != 1) {
        cout << "Invalid is freshman. Please re-enter: ";
        cin >> isFreshman;  // Re-enter whether a freshman
    }

    // Hostel Type (int, 0, 1-4)
    while (desa < 0 || desa > 4) {
        cout << "Invalid desa type for " << matricNum << ". Please re-enter: ";
        cin >> desa;  // Re-enter the hostel type
    }

    // Insurance Level (int, 0, 1-5)
    while (insuranceLevel < 0 || insuranceLevel > 5) {
        cout << "Invalid insurance level. Please re-enter: ";
        cin >> insuranceLevel;  // Re-enter the insurance level
//        correctData << insuranceLevel;
    }

    // Parking Times (int, 0, 1-100)
    while (parkingTimes < 0 || parkingTimes > 100) {
        cout << "Invalid parking times. Please re-enter (0-100): ";
        cin >> parkingTimes;
    }

    // International student? (bool, 0/1)
    while (isInt != 0 && isInt != 1) {
        cout << "Invalid isInt. Is this an international student? Please re-enter (0 - No, 1 - Yes): ";
        cin >> isInt;  // Re-enter whether international student
    }

    // Is Fully Vaccinated? (bool, 0/1)
    while (isFullyVaccinated != 0 && isFullyVaccinated != 1) {
        cout << "Invalid vaccination status. Please re-enter (0 - Not Completed, 1 - Full): ";
        cin >> isFullyVaccinated;  // Re-enter whether fully vaccinated
    }

}

