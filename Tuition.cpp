//
// Created by rinsuki on 11/05/2022.
//

#include "Tuition.h"
#include "Output.h"

double Tuition::calcTuition(bool i) {
    if (i == true) tuition = 12910;
    else tuition = 1030;

    return tuition;
}

double Tuition::calcExtraFee(bool f) {
    if (f == true) extraFee = nonRecurrentFee;
    else extraFee = recurrentFee;

    return extraFee;
}

void Tuition::calcNecCost(Output &OF) {
    necCost += (tuition + extraFee);
    OF.passNecCost(necCost);
}