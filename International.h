//
// Created by rinsuki on 30/04/2022.
//

#ifndef CPT113_ASSIGNMENT_INTERNATIONAL_H
#define CPT113_ASSIGNMENT_INTERNATIONAL_H

#include "Fee.h"

class International {
private:
    double visaFee,
           quarantinePerDay = 150,
           totalQuarantineFee = quarantinePerDay * 5;

    bool isFullyVaccinated;

    // Composition (Privately)
    Fee f;

public:
    International();
    double getVisaFee();
    double getQuarantineFee();



};


#endif //CPT113_ASSIGNMENT_INTERNATIONAL_H
