//
// Created by rinsuki on 11/05/2022.
//

#include "Intl.h"

void Intl::setIntl(bool intl, bool vac){
	calcQuarantineFee(intl, vac);
}



// Calculate Quarantine Fees
void Intl::calcQuarantineFee(bool i, bool vac) {
    if (i && !vac) quarantineFee = quarantineDays * quarantineFeePerDay;
}

// Calculate the visa fee and quarantine fee (if any) for international students
void Intl::calcTotalIntl(double &intl){ // Mutator
    intl = visaFee + quarantineFee;
}