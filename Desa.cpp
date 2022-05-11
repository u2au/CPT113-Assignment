//
// Created by rinsuki on 11/05/2022.
//

#include "Desa.h"

// Calculate desa fee
double Desa::calcDesaFee(int desa) {
    // How long?
    month = 5;

    switch (desa) {
        // Sharing Room
        case 1:
            desaFee = 120 * month; // RM 120 per month, six months per semester
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
double Desa::calcInsurance(int level) {
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
double Desa::calcParking(int t) {
    if (t < 5) parkingFee = 100 * t;
    else parkingFee = monthlyParkingCard;

    return parkingFee;
}