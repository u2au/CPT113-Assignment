//
// Created by rinsuki on 11/05/2022.
//

#include "Student.h"
#include "Tuition.h"
#include "Desa.h"
#include "Intl.h"

using namespace std;

// Set values from main function (Mutator)
void Student::setValue(bool freshman, // class Tuition
                       short desaType, short insurance, short parking, // class Desa
                       bool intl, bool vac) { // class Intl
    isFreshman = freshman;

    desa = desaType;
    insuranceLevel = insurance;
    parkingTimes = parking;

    isInt = intl;
    isFullyVaccinated = vac;

}

// Pass the values for class Tuition
void Student::passForTuition(string maj) {
    // Calculation
    Tuition tt;
    tt.calcTuition(maj, isInt);
    tt.calcExtraFee(isFreshman);
    tt.setAcadFee(acadFee);
}

// Pass the values for class Desa
void Student::passForDesa() {
    // Calculation
    Desa d;
    d.calcDesaFee(desa);
    d.calcInsurance(insuranceLevel);
    d.calcParking(parkingTimes);
    d.calcBasicCost(basicCost);
}

// Pass the values for class Intl (Friend Function)
void passForIntl(bool intl, bool vac, double &total) {
    // Calculation
    Intl i;
    i.calcQuarantineFee(intl, vac);
    i.calcTotalIntl(total);
}

// Call For Intl
void Student::callForIntl() {
    passForIntl(isInt, isFullyVaccinated, totalIntl);
}

// Pass acadFee, totalIntl, basicCost to class TotalFee
void Student::calcTotalFee(double &total) { // Mutator
    f1.setAcadFee(acadFee);
    f2.setTotalIntl(totalIntl);
    f3.setBasicCost(basicCost);
    f2 = f2 + f3;
    f1 = f1 + f2;
    total = f1.getTotal();

}

// Pass the values back to the main function
void Student::passValueBack(double &acad, double &basic, double &intl) {
    acad = acadFee;
    basic = basicCost;
    intl = totalIntl;
}