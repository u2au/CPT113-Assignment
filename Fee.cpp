//
// Created by rinsuki on 29/04/2022.
//

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
    if (isInternational == true) {
        tuitionPerSem = 12910;

    } else tuitionPerSem = 1291; // uncertain

    return 0;

}

// Get Vaccinated Status
bool Fee::getVaccinationStatus() {

    return isFullyVaccinated;
}


Fee::Fee() {
    calcHostelFee(); // Hostel
    calcTuitionPerSem(); // Tuition
    getVaccinationStatus(); // Get Vaccination Status
}

