//HostelAndOtherFee cpp
#include"HostelAndOtherFee.h"
#include"MealAndTransportation.h"
#include<iostream>
using namespace std;
// Calculate the total hostel fee
void HostelAndOtherFee ::setHostelFee() {
    
    // If the student doesn't live in a hostel, terminate the function
    if (livesInHostel == 0) hostelFee =0;

    else {
        switch (livesInHostel) {
            // Sharing Room
            case 1:
                hostelFee = 120; // RM 120 per month, six months per semester
                break;

            // Sharing Room
            case 2:
                hostelFee = 240;
                break;

            // Family Accommodation with One Room
            case 3:
                hostelFee = 350;
                break;

            // Family Accommodation with Two Rooms
            case 4:
                hostelFee = 450;
                break;

            default:
                hostelFee = 0;
                cout << "Error\n";
                break;

        }

    }
   
}