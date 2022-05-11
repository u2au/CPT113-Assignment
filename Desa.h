//
// Created by rinsuki on 11/05/2022.
//

#ifndef CPT113_ASSIGNMENT_DESA_H
#define CPT113_ASSIGNMENT_DESA_H

#include <iostream>
#include "Student.h"
using namespace std;

class Desa {

private:
    Student s; // Composition of class Student (of type private)
    int month = 0;

    double desaFee = 0.0,
           insuranceFee = 0.0,
           parkingFee = 0.0, // to be used in other classes
           monthlyParkingCard = 500.00; // No longer be afraid of cars being locked

public:
    Desa() {}; // Default Constructor

    // Overloading Constructor
    Desa(int d, int i, int p) {
        cout << "Desa Fee: " << d << endl;
        cout << "Insurance Fee: " << i << endl;
        cout << "Parking Fee: " << p << endl;
    }

    // Prototype
    double calcDesaFee(int);
    double calcInsurance(int);
    double calcParking(int);

    // Operator Overloading
    Desa operator+(const Desa &obj) {
        Desa d;
        d.desaFee = desaFee + obj.desaFee;
        d.insuranceFee = insuranceFee + obj.insuranceFee;
        d.parkingFee = parkingFee + obj.parkingFee;

        return d;
    }

};


#endif //CPT113_ASSIGNMENT_DESA_H
