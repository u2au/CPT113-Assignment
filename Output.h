//
// Created by rinsuki on 11/05/2022.
//

#ifndef CPT113_ASSIGNMENT_OUTPUT_H
#define CPT113_ASSIGNMENT_OUTPUT_H
class Output;

#include "Tuition.h"

class Output {
private:
    double necCost = 0.0;


public:
    // Default Constructor
    Output() {
        
    }
    double getNeoCost() const {
        return necCost;
    }
    // Prototype
  friend void Tuition::calcNecCost(Output&); // a friend function of class Output



};


#endif //CPT113_ASSIGNMENT_OUTPUT_H
