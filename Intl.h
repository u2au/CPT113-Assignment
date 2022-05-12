//
// Created by rinsuki on 11/05/2022.
//

#ifndef CPT113_ASSIGNMENT_INTL_H
#define CPT113_ASSIGNMENT_INTL_H

#include "Student.h"
#include <iostream>

class Intl : public Student {
protected:
    double visaFee = 1200.0,
           quarantineFeePerDay = 150.0,
           quarantineFee = 0.0,
           intlFee = 0.0,
           totalIntl = 0.0;

    const int quarantineDays = 5;

public:
    // Default Constructor
    Intl() {}

    // Overloading Constructor
    Intl(int) {

    }

    // Prototype
    void calcQuarantineFee(bool, bool); // Mutator
    void calcTotalIntl(double &); // Mutator

    // Inline Functions
    double getVisaFee() const {return visaFee;} // Accessor
    double getTotalIntl() const {return totalIntl;} // Accessor




};


#endif //CPT113_ASSIGNMENT_INTL_H
