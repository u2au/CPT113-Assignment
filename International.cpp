//
// Created by rinsuki on 30/04/2022.
//

#include "International.h"

// Get Visa Fees
double International::getVisaFee() {
    // Only for international students
    if (isIntl) visaFee = 1200;
    else visaFee = 0;

    return visaFee;

}


// Quarantine Fees (if any)
double International::getQuarantineFee() {

    // Only for international students
    if (isIntl) {
        totalQuarantineFee = 0;

    } else {

        // If no quarantine is required, then quarantine fees are 0
        if (isFullyVaccinated == 1) {
            totalQuarantineFee = quarantineDays * quarantinePerDay;

        } else
            totalQuarantineFee = 0;

    }


    return totalQuarantineFee;

}

// Fees for international students
double International::getTotalIntlFee() {
    totalIntl = visaFee + totalQuarantineFee;

    return totalIntl;
}
