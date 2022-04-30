//
// Created by rinsuki on 30/04/2022.
//

#include "International.h"
#include <iostream>

// Get Visa Fees
double International::getVisaFee() {
    if (f.checkIntl()) visaFee = 1200;
    else visaFee = 0;

    return visaFee;

}


// Quarantine Fees (if any)
double International::getQuarantineFee() {
    isFullyVaccinated = f.getVaccinationStatus();

    // If no quarantine is required, then quarantine fees are 0
    if (isFullyVaccinated == 1) {
        return totalQuarantineFee;

    } else return 0;

}


International::International() {
    getVisaFee();
    getQuarantineFee();

}