//
// Created by rinsuki on 12/05/2022.
//

#ifndef CPT113_ASSIGNMENT_INFILE_H
#define CPT113_ASSIGNMENT_INFILE_H

#include <iostream>
using namespace std;

class Infile {
protected:
    // Variable Definition
    int matricNum = 111111,
        desa = 0,
        insuranceLevel = 0,
        parkingTimes = 0,
        lineOfFile = 0;

    bool isInt = true,
         isFullyVaccinated = false,
         isFreshman = true;


public:
    Infile() {} // Default Constructor

    // Overloading Constructor
    Infile(int) {
        getFileLines();
        getData();
        inputValidation();
    }

    // Prototype
    void getFileLines();
    void getData();
    void inputValidation();

};


#endif //CPT113_ASSIGNMENT_INFILE_H
