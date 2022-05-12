/*composition of studnet class

*/

#ifndef CPT113_ASSIGNMENT_DESA_H
#define CPT113_ASSIGNMENT_DESA_H

#include "Student.h"
#include <iostream>


using namespace std;

class Desa {

private:
    Student s; // Composition of class Student (of type private)
    int month = 0;

    double desaFee = 0.0,
           insuranceFee = 0.0,
           parkingFee = 0.0, // to be used in other classes
           monthlyParkingCard = 500.00; // No longer be afraid of cars being locked

    double basicCost = 0.0;


public:
    Desa() {};

    // Constructor
    Desa(int) {
//        cout << "Desa Fee: " << calcDesaFee(s.whichDesa()) << endl;
//        cout << "Insurance Fee: " << calcInsurance(s.getInsuranceLevel()) << endl;
//        cout << "Parking Fee: " << calcParking(s.getParkingTimes()) << endl;
    }

    // Prototype
    double calcDesaFee(int);
    double calcInsurance(int);
    double calcParking(int);
    void calcBasicCost(); // Mutator

    // Inline Functions
    double getBasicCost() const {return basicCost;}//accessor

    
};


#endif //CPT113_ASSIGNMENT_DESA_H
