//
// Created by rinsuki on 11/05/2022.
//

#include "Student.h"
#include "Tuition.h"
#include "Desa.h"
#include "Intl.h"

#include <iostream>
using namespace std;

// Pass the values for class Tuition
void Student::passForTuition() {
    Tuition tt;
    tt.calcTuition(isInt);
    tt.calcExtraFee(isFreshman);
    tt.setAcadFee();

    TotalFee tf;
    tf.setAcadFee(tt.getAcadFee());
    cout << tf.getAcadFee() << endl;
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