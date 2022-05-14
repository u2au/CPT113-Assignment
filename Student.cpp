//
// Created by rinsuki on 11/05/2022.
//

#include "Student.h"
#include "Tuition.h"
#include "Desa.h"
#include "Intl.h"

using namespace std;

// Set values from main function (Mutator)
void Student::setValue(bool freshman, string maj,// class Tuition
                       short desaType, short insurance, short parking, // class Desa
                       bool intl, bool vac) { // class Intl

    setTuition(freshman, maj, intl);
    setDesa(desaType, insurance, parking);
    setIntl(intl, vac);

}

// Pass the values for class Tuition
void Student::passForTuition(string maj) {
    setAcadFee(acadFee);
}

// Pass the values for class Desa
void Student::passForDesa() {
    // Calculation
    calcBasicCost(basicCost);
}

// Pass the values for class Intl (Friend Function)
void passForIntl(double &total) {
    // Calculation
    Intl i;
    i.calcTotalIntl(total);
}

// Call For Intl
void Student::callForIntl() {
    passForIntl(totalIntl);
}

// Pass acadFee, totalIntl, basicCost to class TotalFee
// we use operator overloading function in student class to add three objects togother to claculate the total fee
void Student::calcTotalFee() { // Mutator
    f1.setAcadFee(acadFee);
    f2.setTotalIntl(totalIntl);
    f3.setBasicCost(basicCost);
    f2 = f2 + f3;
    f1 = f1 + f2;
    totalFee = f1.getTotal();

}

// Pass the values back to the main function
void Student::passValueBack(double &acad, double &basic, double &intl, double &tt) {
    acad = acadFee;
    basic = basicCost;
    intl = totalIntl;
    tt = totalFee;
}