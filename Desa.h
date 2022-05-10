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
    Student s;
    int month = 0;

    double desaFee = 0.0,
           insuranceFee = 0.0,
           parkingFee = 0.0, // to be used in other classes
           monthlyParkingCard = 500.00; // No longer be afraid of cars being locked

public:
    // Default Constructor
    Desa() {
        cout << "Desa Fee: " << calcDesaFee(s.whichDesa()) << endl;
        cout << "Insurance Fee: " << calcInsurance(s.getInsuranceLevel()) << endl;
        cout << "Parking Fee: " << calcParking(s.getParkingTimes()) << endl;
    }

    // Prototype
    double calcDesaFee(int);
    double calcInsurance(int);
    double calcParking(int);

};


#endif //CPT113_ASSIGNMENT_DESA_H
