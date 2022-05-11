//
// Created by rinsuki on 11/05/2022.
//

#ifndef CPT113_ASSIGNMENT_STUDENT_H
#define CPT113_ASSIGNMENT_STUDENT_H

#include <iostream>

using namespace std;

class Student {
protected:
    int matricNum = 111111,
        desa = 0,
        insuranceLevel = 0,
        parkingTimes = 0;

    double desaFee = 0.0;

    bool isInt = true,
         isFullyVaccinated = false,
         isFreshman = true;


public:
    Student() {
        getData();
        inputValidation();
    }

    // Prototype
    void getData();
    void inputValidation();

    // Inline Functions
    int whichDesa() const {return desa;}
    bool checkInt() const {return isInt;}
    bool checkFreshman() const {return isFreshman;}
    int getInsuranceLevel() const {return insuranceLevel;}
    int getParkingTimes() const {return parkingTimes;}


};


#endif //CPT113_ASSIGNMENT_STUDENT_H
