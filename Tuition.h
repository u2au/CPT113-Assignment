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
    Student s; // Composition (private)

    // Variable Definition
    int numOfMajors = 5;

    double tuition = 0.0,
           recurrentFee = 112.50,
           nonRecurrentFee = 1330.00,
           extraFee = 0.0,
           acadFee = 0.0;

public:
    // Default Constructor
    Tuition() {};


    // Prototype
    void calcTuition(string, bool); // Mutator
    void calcExtraFee(bool); // Mutator
    void displayTuition(); // Mutator
    void setAcadFee(double &); // Mutator


    // Inline Function
    double getTuition() const {return tuition;} // Accessor
    double getExtraFee() const {return extraFee;} // Accessor
    double getAcadFee() const {return acadFee;}  // Accessor

};


#endif //CPT113_ASSIGNMENT_TUITION_H
