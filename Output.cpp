//
// Created by rinsuki on 11/05/2022.
//

#include "Output.h"
#include "Tuition.h"

#include <iostream>

double calcNecCost() {
    Tuition t;
    t.displayTuition();
    return (t.getTuition() + t.getExtraFee());
}

double Output::getNecCost() {
    necCost = calcNecCost();

    // Display necessary costs
    cout << "Necessary Costs: " << necCost << endl;
    return necCost;
}