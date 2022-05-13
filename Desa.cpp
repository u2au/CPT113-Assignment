//
// Created by rinsuki on 11/05/2022.
//

#include "Desa.h"

// Calculate desa fee
float Desa::calcDesaFee(short desa) {
    // How long?
    month = 5;

    switch (desa) {
        // Sharing Room
        case 1:
            desaFee = 120 * month; // RM 120 per month, five months per semester on campus
            break;

        // Sharing Room
        case 2:
            desaFee = 240 * month;
            break;

        // Family Accommodation with One Room
        case 3:
            desaFee = 350 * month;
            break;

        // Family Accommodation with Two Rooms
        case 4:
            desaFee = 450 * month;
            break;

        default:
            desaFee = 0;
            break;

    }

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
    if (t < 5) parkingFee = 100 * t;
    else parkingFee = monthlyParkingCard;

    return parkingFee;
}

// Calculate the basic cost (including desa, insurance, and parking fees)
void Desa::calcBasicCost(double &basic) {
    basic = desaFee + insuranceFee + parkingFee;
}