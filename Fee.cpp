//
// Created by rinsuki on 29/04/2022.
//

#include "Fee.h"
#include <iostream>

using namespace std;

// Calculate the total hostel fee
double Fee::calcHostelFee() {
    // If the student doesn't live in a hostel, terminate the function
    if (hostelFee == 0) return 0;

    else {
        switch (hostelType) {
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
double Fee::calcInsuranceFee() {
    switch (insuranceLevel)
    {
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

// Get Meal Fees
double Fee::calcMealFee() {
    switch (mealPlan)
    {
        case 1:
            mealFee = 15;
            break;

        case 2:
            mealFee = 20;
            break;

        case 3:
            mealFee = 25;
            break;

        case 4:
            mealFee = 30;
            break;

        case 5:
            mealFee = 35;
            break;

        default:
            mealFee = 0;
            break;

    }

    return mealFee;
}

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

