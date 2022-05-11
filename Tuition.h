//
// Created by rinsuki on 11/05/2022.
//

#ifndef CPT113_ASSIGNMENT_TUITION_H
#define CPT113_ASSIGNMENT_TUITION_H
#include "Student.h"
#include "Output.h"
#include <iostream>

using namespace std;

class Tuition {
private:
    Student s;
    double tuition = 0.0,
           recurrentFee = 112.50,
           nonRecurrentFee = 1330.00,
           extraFee = 0.0,
           acadFee = 0.0;

public:
    // Default Constructor
    Tuition() {};

    // Overloading Constructor
    Tuition(int) {

    }

    // Prototype
    void calcTuition(bool); // Mutator
    void calcExtraFee(bool); // Mutator
    void displayTuition(); // Mutator
    void calcAcadFee(); // Mutator


    // Inline Function
    double getTuition() const {return tuition;} // Accessor
    double getExtraFee() const {return extraFee;} // Accessor
    double getAcadFee() const {return acadFee;}  // Accessor

};


#endif //CPT113_ASSIGNMENT_TUITION_H
