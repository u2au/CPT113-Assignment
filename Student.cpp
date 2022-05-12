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

// Set values from main function (Mutator)
void Student::setValue(int matric, bool freshman, // class Tuition
                       int desaType, int insurance, int parking, // class Desa
                       bool intl, bool vac) { // class Intl

    matricNum = matric;
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

// Set the academic fees and basic costs respectively
void setAcadAndBasic() {

}