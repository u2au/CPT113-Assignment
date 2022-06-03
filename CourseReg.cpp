//
// Created by rinsuki on 03/06/2022.
//

#include "CourseReg.h"
#include <iostream>

using namespace std;

void CourseReg::menu()
{
    // Menu for Course Registration
    cout << "Course Registration Menu" << "\n"
         << "1 - Add Courses" << "\n"
         << "2 - Drop Courses" << "\n"
         << "0 - Exit" << "\n"
         << "Kindly type num of the function that you want to use: ";
    cin >> input;

    // Input Validation
    while (input != 0 && input != 1 && input != 2)
    {
        cout << "Sorry, '" << input << "' is not a valid num for the program." << "\n"
             << "Please type num of the function again: ";
        cin >> input;
    }

    switch (input)
    {
        // Back to the main menu
        case 0:
            // To be continued...
            cout << "";
            break;

        case 1:
            input = -1;
            cout << "Do you want to check the course list offered by School of Computer Science, USM? "
                 << "1 - Yes, 0 - No";

            // Input Validation
            while (input != 1 && input != 0)
            {
                cout << "Sorry, the num you typed was wrong." << "\n"
                     << "Please enter again: ";
                cin >> input;
            }

            // Display the course list
            if (input == 1)
            {

            }

            // Add Courses
            input = -1;
            cout << "Please type num of the course you want to drop: ";
            cin >> input;

            // Input Validation: Check if the num exists

            // Add a course
            while (input != 0)
            {
                if (input == 1) cout << "1";

                // Check if the course exists by the num

                // Successfully added
                cout << "Course #" << input << " has been added." << "\n"
                     << "If you want to add more, please continue typing the num." << "\n"
                     << "Press 0 to stop.";
                cin >> input;
            }

            break;

        case 2:
            input = -1;
            cout << "Course List"
                 // Linked List
                 << "Please type num of the course you want to drop: ";
            cin >> input;

            // Input Validation: Check if the num exists

            // Drop a course
            while (input != 0)
            {
                if (input == 1) cout << "1";

                cout << "Course #" << input << " has been dropped." << "\n"
                     << "If you want to drop more, please continue typing the num." << "\n"
                     << "Press 0 to stop.";
                cin >> input;
            }

            // Completion
            input = -1;
            cout << "Dropping operation completed. Do you want to see the current course list?" << "\n"
                 << "1 - Yes, 0 - No";

            // Input Validation
            while (input != 1 && input != 0)
            {
                cout << "Sorry, the num you typed was wrong." << "\n"
                     << "Please enter again: ";
                cin >> input;
            }

            // Display the current course list (after dropping)
            if (input == 1)
            {
                // To be continued...
            }

            cout << "Thanks for using Drop Courses." << endl;
            // Go back to the main menu or terminate the program.
            break;

        // Default
        default:
            cout << "Wrong lah!" << endl;
            break;
    }

}
