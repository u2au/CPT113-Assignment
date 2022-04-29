//
// Created by rinsuki on 29/04/2022.
//

#include "Fee.h"
#include <iostream>

using namespace std;

// Calculate the total hostel fee
double calcHostelFee(int hostel, double *fee) {

    // If the student doesn't live in a hostel, terminate the function
    if (hostel == 0) return 0;

    else {
        switch (hostel) {
            // Sharing Room
            case 1:
                *fee = 120 * 6; // RM 120 per month, six months per semester
                break;

            // Sharing Room
            case 2:
                *fee = 240 * 6;
                break;

            // Family Accommodation with One Room
            case 3:
                *fee = 350 * 6;
                break;

            // Family Accommodation with Two Rooms
            case 4:
                *fee = 450 * 6;
                break;

            default:
                *fee = 0;
                cout << "Error\n";
                break;

        }

    }


    return 0;
}


// Calculate the tuition fees this semester
double calcTuitionPerSem(bool isInt, double *tuition) {
    if (isInt == true) *tuition = 12910;
    else *tuition = 1291; // uncertain

    return 0;

}



Fee::Fee() {
    calcHostelFee(livesInHostel, &hostelFee);
    calcTuitionPerSem(isInternational, &tuitionPerSem);
    cout << tuitionPerSem;
}

