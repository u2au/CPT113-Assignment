//HostelAndOtherFee cpp
#include "HostelAndOtherFee.h"

// Calculate the total hostel fee
void HostelAndOtherFee::setHostelFee() {
    
    // If the student doesn't live in a hostel, terminate the function
    if (hostelType == 0) hostelFee = 0;

    else {
        switch (hostelType) {
            // Sharing Room
            case 1:
                hostelFee = 120 * 5; // RM 120 per month, five months per semester
                break;

            // Sharing Room
            case 2:
                hostelFee = 240 * 5;
                break;

            // Family Accommodation with One Room
            case 3:
                hostelFee = 350 * 5;
                break;

            // Family Accommodation with Two Rooms
            case 4:
                hostelFee = 450 * 5;
                break;

            // The student won't live in a hostel
            default:
                hostelFee = 0;
                break;

        }

    }
   
}