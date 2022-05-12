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
           intFee = 0.0,
           totalIntl = 0.0;

    const int quarantineDays = 5;

public:
    // Default Constructor
    Intl() {
//        if (isInt) {
//            if (!isFullyVaccinated) {
//                cout << "Quarantine Fee: ";
//                quarantineFee = calcQuarantineFee(quarantineFeePerDay, quarantineDays);
//                cout << quarantineFee << endl;
//            }
//
//            intFee = visaFee + quarantineFee;
//            cout << "Quarantine Fee, Visa Fee, Total: \n"
//                  << quarantineFee << " " << visaFee << " " << intFee << endl;
//        }
    }

    // Overloading Constructor
    Intl(int) {
        if (isInt) {
            if(!isFullyVaccinated) calcQuarantineFee(quarantineFee, quarantineDays);
            calcTotalIntl();
        }
    }

    // Prototype
    static double calcQuarantineFee(double, double); // Mutator
    void calcTotalIntl(); // Mutator

    // Inline Functions
    double getVisaFee() const {return visaFee;} // Accessor
    double getTotalIntl() const {return totalIntl;} // Accessor




};


#endif //CPT113_ASSIGNMENT_INTL_H
