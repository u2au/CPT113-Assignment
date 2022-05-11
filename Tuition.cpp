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

void Tuition::displayTuition() {
    cout << "Tuition: " << tuition << endl;
    if (s.checkFreshman()) cout << "Non-recurrent Fees: " << nonRecurrentFee << endl;
    else cout << "Recurrent Fees: " << recurrentFee << endl;

}

//accessor 
 double Tuition::getTuitionTotal(){
    if (s.checkFreshman())
           totalCost= tuition+extraFee+nonRecurrentFee;
    else 
        totalCost= tuition+extraFee+recurrentFee;
    
    return totalCost;
 }