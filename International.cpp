//
// Created by rinsuki on 30/04/2022.
//

#include "International.h"
#include <iostream>

// Get Visa Fees
void International::setVisaFee() {
    if (f.checkIntl()) visaFee = 1200;
    else visaFee = 0;

}


// Quarantine Fees (if any)
void International::setQuarantineFee(int days) {
    
    //这儿看咋input 隔离天数，，？？？
    // r: 固定好的，五天.
    isFullyVaccinated = f.getVaccinationStatus();
    // If no quarantine is required, then quarantine fees are 0
    if (isFullyVaccinated == 1) {
        totalQuarantineFee = 5 * quarantinePerDay;

    } else 
        totalQuarantineFee=0;

}

