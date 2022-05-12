//
// Created by rinsuki on 11/05/2022.
//

#include "Student.h"

// Pass acadFee, totalIntl, basicCost to class TotalFee
void Student::calcTotalFee() {
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