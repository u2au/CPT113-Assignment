#ifndef CPT113_ASSIGNMENT_DESA_H
#define CPT113_ASSIGNMENT_DESA_H


#include <iostream>

using namespace std;

class Desa {

private:
    float desaFee,
          insuranceFee,
          parkingFee,
          parkingFeePerTime,
          monthlyParkingCard; // No longer be afraid of cars being locked
  

public:
    // Default Constructor
    Desa() {
        desaFee = 0,
        insuranceFee = 0,
        parkingFee = 0,
        parkingFeePerTime = 100,
        monthlyParkingCard = 500;
    }
    
    // Pass values through this member function from derived class and calculate desa fee, insurance fee and parking fee
    void setDesa(short, short, short);

    // Prototype
    float calcDesaFee(short);
    float calcInsurance(short);
    float calcParking(short);
    void calcBasicCost(double &) const; // Mutator
};


#endif //CPT113_ASSIGNMENT_DESA_H


