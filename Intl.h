//
// Created by rinsuki on 11/05/2022.
//

#ifndef CPT113_ASSIGNMENT_INTL_H
#define CPT113_ASSIGNMENT_INTL_H

#include "Student.h"
#include <iostream>

class Intl : public Student {
private:
    float visaFee = 1200.0;

public:
    // Default Constructor
    Intl() = default;

    // Prototype
    void calcQuarantineFee(bool, bool); // Mutator
    void calcTotalIntl(double &); // Mutator

};


#endif //CPT113_ASSIGNMENT_INTL_H
