//
// Created by rinsuki on 11/05/2022.
//

#include "Tuition.h"

// Set the tuition fee for international students and local students separately
void Tuition::calcTuition(bool i) { // Mutator
    if (i) tuition = 12910;
    else tuition = 1030;

}

// Set the (non-)recurrent fee depending on whether the student is freshman
void Tuition::calcExtraFee(bool f) { // Mutator
    if (f) extraFee = nonRecurrentFee;
    else extraFee = recurrentFee;

}

void Tuition::displayTuition() {
    cout << "Tuition: " << tuition << endl; // Mutator
    if (s.checkFreshman()) cout << "Non-recurrent Fees: " << nonRecurrentFee << endl;
    else cout << "Recurrent Fees: " << recurrentFee << endl;

}

// Calculate all the academic fee (including tuition fees, and (non-)recurrent fees)
void Tuition::calcAcadFee(){ // Mutator (?
    // Execute calcExtraFee first, then variable tuition and variable extraFee can save correct value.
    // After that, what we need to do next is adding them together, and return the academic fee (acadFee).
    acadFee = tuition + extraFee;

 }