//
// Created by rinsuki on 29/04/2022.
//

#ifndef CPT113_ASSIGNMENT_FEE_H
#define CPT113_ASSIGNMENT_FEE_H

#include "Student.h"

class Fee : public Student {
private:
    double hostelFee,
           tuitionPerSem,
           recurrent, nonRecurrent,
           insuranceFee;

public:
    Fee(); // Default Constructor



};


#endif //CPT113_ASSIGNMENT_FEE_H
