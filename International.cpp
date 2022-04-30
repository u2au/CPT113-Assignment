//
// Created by rinsuki on 30/04/2022.
//

#include "International.h"
#include <iostream>

// Quarantine Fees (if any)
double International::getQuarantineFee() {
    isFullyVaccinated = f.getVaccinationStatus();

    // If no quarantine is required, then quarantine fees are 0
    if (isFullyVaccinated == true) {
        return totalQuarantineFee;

    } else return 0;

}


International::International() {
    getQuarantineFee();

}