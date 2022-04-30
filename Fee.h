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
           insuranceFee,
           mealFee;

public:
    Fee(); // Default Constructor

    // Prototype
    double calcHostelFee();
    double calcTuitionPerSem();
    double calcInsuranceFee();
    double calcMealFee();

    bool getVaccinationStatus();
    bool checkIntl();


};


#endif //CPT113_ASSIGNMENT_FEE_H
