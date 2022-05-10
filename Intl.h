//
// Created by rinsuki on 11/05/2022.
//

#ifndef CPT113_ASSIGNMENT_INTL_H
#define CPT113_ASSIGNMENT_INTL_H

#include "Student.h"
#include <iostream>

class Intl : public Student {
protected:
    double visaFee = 1200,
           quarantineFeePerDay = 150,
           quarantineFee = 0,
           intFee = 0;

    int quarantineDays = 5;

public:
    // Overloading Constructor
    Intl() {
        if (isInt == true) {
            if (isFullyVaccinated == false) {
                cout << "Quarantine Fee: ";
                quarantineFee = calcQuarantineFee(quarantineFeePerDay, quarantineDays);
                cout << quarantineFee << endl;
            }
            intFee = visaFee + quarantineFee;
            cout << "Quarantine Fee, Visa Fee, Total: \n"
                  << quarantineFee << " " << visaFee << " " << intFee << endl;
        }
    }

    // Inline Functions
    double calcVisaFee() const {return visaFee;}

    // Prototype
    double calcQuarantineFee(double, double);


};


#endif //CPT113_ASSIGNMENT_INTL_H
