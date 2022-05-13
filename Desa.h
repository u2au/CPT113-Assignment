/*composition of studnet class

*/

#ifndef CPT113_ASSIGNMENT_DESA_H
#define CPT113_ASSIGNMENT_DESA_H

#include "Student.h"
#include <iostream>


using namespace std;

class Desa {

private:
    Student s; // Composition of class Student (private)
    short month = 0;

    int desaFee = 0,
        insuranceFee = 0,
        parkingFee = 0, // to be used in other classes
        monthlyParkingCard = 500; // No longer be afraid of cars being locked

public:
    // Default Constructor
    Desa() {};

    // Prototype
    float calcDesaFee(short);
    float calcInsurance(short);
    float calcParking(short);
    void calcBasicCost(double &); // Mutator
};


#endif //CPT113_ASSIGNMENT_DESA_H
