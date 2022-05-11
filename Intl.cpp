//
// Created by rinsuki on 11/05/2022.
//

#include "Intl.h"

// Calculate Quarantine Fees
double Intl::calcQuarantineFee(double fee, double days) {
    return (fee * days);
}

//accessor
double Intl::getIntlTotal(){
   return  intFee;
}