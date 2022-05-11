//
// Created by rinsuki on 11/05/2022.
//

#include "Intl.h"

// Calculate Quarantine Fees
double Intl::calcQuarantineFee(double fee, double days) {
    return (fee * days);
}

// Calculate the visa fee and quarantine fee (if any) for international students
void Intl::calcTotalIntl(){ // Mutator
    intFee = visaFee + quarantineFee;
}