//
// Created by rinsuki on 11/05/2022.
//

#include "Desa.h"

void Desa::setDesa(short desaType, short insurance, short parking) {
	calcDesaFee(desaType);
	calcInsurance(insurance);
	calcParking(parking);
}

// Calculate desa fee
float Desa::calcDesaFee(short desa) {

    switch (desa) {
        // Sharing Room
        case 1:
            desaFee = 120.0;
            break;

        // Sharing Room
        case 2:
            desaFee = 240.0;
            break;

        // Family Accommodation with One Room
        case 3:
            desaFee = 350.0;
            break;

        // Family Accommodation with Two Rooms
        case 4:
            desaFee = 450.0;
            break;

        default:
            desaFee = 0;
            break;

    }

    desaFee *= 5; // RM 120 per month, five months per semester on campus

    return desaFee;

}

// Calculate Insurance Fees
float Desa::calcInsurance(short level) {
    switch (level) {
        case 1:
            insuranceFee = 1000;
            break;

        case 2:
            insuranceFee = 2000;
            break;

        case 3:
            insuranceFee = 5000;
            break;

        case 4:
            insuranceFee = 8000;
            break;

        case 5:
            insuranceFee = 10000;
            break;

        default:
            insuranceFee = 0;
            break;

    }

    return insuranceFee;
}

// Calculate Parking Fees
float Desa::calcParking(short t) {
    if (t < 5) parkingFee = parkingFeePerTime * t;
    else parkingFee = monthlyParkingCard;

    return parkingFee;
}

// Calculate the basic cost (including desa, insurance, and parking fees) and pass it to totalFee class by reference
void Desa::calcBasicCost(double &basic) const {
    basic = desaFee + insuranceFee + parkingFee;
}