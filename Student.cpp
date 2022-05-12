//
// Created by rinsuki on 11/05/2022.
//

#include "Student.h"
#include "Tuition.h"
#include "Desa.h"
#include "Intl.h"

#include <iostream>
#include <fstream>
using namespace std;

// Get the lines of 'Student.txt'
void Student::getFileLines() {
    string temp;

    ifstream file;
    file.open("./Student.txt");

    if (file.is_open()) {
        while(!file.eof()) {
            getline(file, temp);
            lineOfFile++;
        }
    } else cout << "Unable to open the file: Student.txt" << endl;


    file.close();
}


// Get Data from the file
void Student::getData() {
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
    else cout << "Unable to open the file: Student.txt" << endl;

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
    }

    // Monthly Parking Times (int, 0, 1-100)
    while (parkingTimes < 0 || parkingTimes > 100) {
        cout << "Invalid parking times. Please re-enter (0-100): ";
        cin >> parkingTimes; // Re-enter the parking times
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

// Pass the values for class Tuition
void Student::passForTuition() {
    // Calculation
    Tuition tt;
    tt.calcTuition(isInt);
    tt.calcExtraFee(isFreshman);
    tt.setAcadFee(acadFee);
    cout << acadFee << endl;

//    // Pass the value to class totalFee
////    TotalFee tf;
////    tf.setAcadFee(tt.getAcadFee());
////    cout << tf.getAcadFee() << endl;
}

// Pass the values for class Desa
void Student::passForDesa() {
    // Calculation
    Desa d;
    d.calcDesaFee(desa);
    d.calcInsurance(insuranceLevel);
    d.calcParking(parkingTimes);
    d.calcBasicCost(basicCost);
    cout << basicCost << endl;
}

// Pass the values for class Intl
void Student::passForIntl() {
    // Calculation
    Intl i;
    i.calcQuarantineFee(isInt, isFullyVaccinated);
    i.calcTotalIntl(totalIntl);
    cout << "Total Intl of class Student: " << totalIntl << endl;
}


// Pass acadFee, totalIntl, basicCost to class TotalFee
void Student::calcTotalFee() { // Mutator
    f1.setAcadFee(acadFee);
    f2.setTotalIntl(totalIntl);
    f3.setBasicCost(basicCost);
    f2 = f2 + f3;
    f1 = f1 + f2;
    cout << "The total fee is "<< f1.getTotal() << endl;

}

// Set the fees from the respective classes: Tuition, Desa, and Intl
void Student::setFees() { // Mutator
    Tuition t;
    acadFee = t.getAcadFee();

    Desa d;
    basicCost = d.getBasicCost();

    Intl i;
    totalIntl = i.getTotalIntl();
}