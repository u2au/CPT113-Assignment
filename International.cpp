//
// Created by rinsuki on 30/04/2022.
//

#include "International.h"
#include <iostream>
#include<fstream>

// Get Visa Fees
double International::getVisaFee() {
    if (f.checkIntl()) visaFee = 1200;
    else visaFee = 0;

    return visaFee;

}


// Quarantine Fees (if any)
double International::getQuarantineFee(int days) {
    //这儿看咋input 隔离天数，，？？？
    isFullyVaccinated = f.getVaccinationStatus();
    totalQuarantineFee=days*quarantinePerDay;
    // If no quarantine is required, then quarantine fees are 0
    if (isFullyVaccinated == 1) {
        return totalQuarantineFee;

    } else return 0;

}


/*这个是原来的现在不要了
International::International() {
    getVisaFee();
    getQuarantineFee();

}*/