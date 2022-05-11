//
// Created by rinsuki on 11/05/2022.
//

#include "Tuition.h"
#include "Output.h"

double Tuition::calcTuition(bool i, double &tut) {
    if (i) tut = 12910;
    else tut = 1030;

    return tut;
}

double Tuition::calcExtraFee(bool f, double &extra) {
    if (f) extra = nonRecurrentFee;
    else extra = recurrentFee;

    return extra;
}

void Tuition::displayTuition(bool f) {
    cout << "Tuition: " << tuition << endl;
    if (f) cout << "Non-recurrent Fees: " << nonRecurrentFee << endl;
    else cout << "Recurrent Fees: " << recurrentFee << endl;

}