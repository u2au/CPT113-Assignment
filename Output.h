//
// Created by rinsuki on 11/05/2022.
//

#ifndef CPT113_ASSIGNMENT_OUTPUT_H
#define CPT113_ASSIGNMENT_OUTPUT_H

#include "Tuition.h"

class Output {
private:
    double necCost = 0.0;

public:
    // Default Constructor
    Output() {
        getNecCost();
    }

    // Friend Function
    friend double calcNecCost();

    // Prototype
    double getNecCost();




};


#endif //CPT113_ASSIGNMENT_OUTPUT_H
