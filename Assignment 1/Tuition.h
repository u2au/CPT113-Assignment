//
// Created by rinsuki on 11/05/2022.
//

#ifndef CPT113_ASSIGNMENT_TUITION_H
#define CPT113_ASSIGNMENT_TUITION_H

#include <iostream>
#include <string>

using namespace std;

class Tuition {
private:
    // Variable Definition
    double tuition;

    float recurrentFee,
          nonRecurrentFee,
          extraFee;

    string major;

public:
    // Default Constructor
    Tuition() {
        tuition = 0.0;
        recurrentFee = 112.50,
        nonRecurrentFee = 1330.00,
        extraFee = 0.0;
        major = "default";
    }

    // Prototype
    // Pass Values through this member function from derived class student and calculate tuition fee and extra fee.
    void setTuition(bool, string, bool);
    void calcTuition(bool); // Mutator
    void calcExtraFee(bool); // Mutator
    void setAcadFee(double &) const; // Mutator
    // Prototype END

};


#endif //CPT113_ASSIGNMENT_TUITION_H
