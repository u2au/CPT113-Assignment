//
// Created by rinsuki on 11/05/2022.
//

#include "Student.h"
#include "Tuition.h"
#include "Desa.h"
#include "Intl.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Set values from main function (Mutator)
void Student::setValue(int matric, string maj, bool freshman, // class Tuition
                       int desaType, int insurance, int parking, // class Desa
                       bool intl, bool vac) { // class Intl

    matricNum = matric;
    major = maj;
    isFreshman = freshman;

    desa = desaType;
    insuranceLevel = insurance;
    parkingTimes = parking;

    isInt = intl;
    isFullyVaccinated = vac;

}

// Pass the values for class Tuition
void Student::passForTuition() {
    // Calculation
    Tuition tt;
    tt.calcTuition(major, isInt);
    tt.calcExtraFee(isFreshman);
    tt.setAcadFee(acadFee);
//    cout << acadFee << endl;

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
//    cout << basicCost << endl;
}

// Call For Intl
void passForIntl(bool, bool, double &); // Prototype
void Student::callForIntl() {
    passForIntl(isInt, isFullyVaccinated, totalIntl);
}

// Pass the values for class Intl (Friend Function)
void passForIntl(bool intl, bool vac, double &total) {
    // Calculation
    Intl i;
    i.calcQuarantineFee(intl, vac);
    i.calcTotalIntl(total);
//    cout << "Total Intl of class Student: " << totalIntl << endl;
}


// Pass acadFee, totalIntl, basicCost to class TotalFee
void Student::calcTotalFee(double &total) { // Mutator
    f1.setAcadFee(acadFee);
    f2.setTotalIntl(totalIntl);
    f3.setBasicCost(basicCost);
    f2 = f2 + f3;
    f1 = f1 + f2;
    total = f1.getTotal();
//    cout << "The total fee is "<< total << endl;


}

// Pass the values back to the main function
void Student::passValueBack(double &acad, double &basic, double &intl) {
    acad = acadFee;
    basic = basicCost;
    intl = totalIntl;
}

// Set the academic fees and basic costs respectively
void Student::setAcadAndBasic() {

}