//
// Created by rinsuki on 29/04/2022.
//
/*
#include "Fee.h"
#include <iostream>

using namespace std;

// Calculate the total hostel fee
double Fee::calcHostelFee() {
    // If the student doesn't live in a hostel, terminate the function
    if (livesInHostel == 0) return 0;

    else {
        switch (livesInHostel) {
            // Sharing Room
            case 1:
                hostelFee = 120 * 6; // RM 120 per month, six months per semester
                break;

            // Sharing Room
            case 2:
                hostelFee = 240 * 6;
                break;

            // Family Accommodation with One Room
            case 3:
                hostelFee = 350 * 6;
                break;

            // Family Accommodation with Two Rooms
            case 4:
                hostelFee = 450 * 6;
                break;

            default:
                hostelFee = 0;
                cout << "Error\n";
                break;

        }

    }
    return hostelFee;
}


// Calculate the tuition fees this semester
double Fee::calcTuitionPerSem() {
    // For International Students
    if (isInternational) tuitionPerSem = 8347;

    // For Local Students
    else tuitionPerSem = 1030;

    return tuitionPerSem;

}

// Get Insurance Fees


// Get Meal Fees

// Get Vaccinated Status
bool Fee::getVaccinationStatus() {

    return isFullyVaccinated;
}

// Check if the student is an international student
bool Fee::checkIntl() {

    return isInternational;
}

// Calculate the total fees



Fee::Fee() {
    calcHostelFee(); // Hostel
    calcTuitionPerSem(); // Tuition
    getVaccinationStatus(); // Vaccination
    calcInsuranceFee(); // Insurance
    calcMealFee(); // Meal

}

*/