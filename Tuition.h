//
// Created by rinsuki on 11/05/2022.
//

#ifndef CPT113_ASSIGNMENT_TUITION_H
#define CPT113_ASSIGNMENT_TUITION_H
#include "Student.h"

#include <iostream>
#include <string>

using namespace std;

class Tuition {
private:
    // Variable Definition
    double tuition = 0.0,
           acadFee = 0.0;

    float recurrentFee = 112.50,
          nonRecurrentFee = 1330.00,
          extraFee = 0.0;

public:
    // Default Constructor
    Tuition() = default;

    //pass value through this member function from derived class student and calculate tuition fee and extra fee.
    void setTuition(bool,string,bool);
    // Prototype
    void calcTuition(string, bool); // Mutator
    void calcExtraFee(bool); // Mutator
    void setAcadFee(double &); // Mutator

};


#endif //CPT113_ASSIGNMENT_TUITION_H
