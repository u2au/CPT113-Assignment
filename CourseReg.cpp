//
// Created by rinsuki on 03/06/2022.
//

#include "CourseReg.h"
#include <iostream>
#include <fstream>

using namespace std;

void CourseReg::menu()
{
    // Menu for Course Registration
    cout << "Course Registration Menu \n"
         << "1 - Add Courses \n"
         << "2 - Drop Courses \n"
         << "0 - Exit \n"
         << "Kindly type num of the function that you want to use: ";
    cin >> input;

    // Input Validation
    while (input != 0 && input != 1 && input != 2) inputValidation();

    switch (input)
    {
        // Back to the main menu
        case 0:
            // To be continued...
            cout << "";
            break;

        case 1:
            input = -1;
            cout << "Please wait... we're loading courses from the list." << endl;
//            r = true; // Mark the read status


            cout << "Do you want to check the course list offered by School of Computer Science, USM? \n"
                 << "1 - Yes, 0 - No \n";
            cin >> input;

            // Input Validation
            while (input != 1 && input != 0) inputValidation();

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
                cout << "Course #" << input << " has been added. \n"
                     << "If you want to add more, please continue typing the num. \n"
                     << "Press 0 to stop. \n";
                cin >> input;
            }

            cout << "Thanks for using Add Courses." << endl;
            // Go back to the main menu or terminate the program.
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

                cout << "Course #" << input << " has been dropped. \n"
                     << "If you want to drop more, please continue typing the num. \n"
                     << "Press 0 to stop. \n";
                cin >> input;
            }

            // Completion
            input = -1;
            cout << "Dropping operation completed. Do you want to see the current course list? \n"
                 << "1 - Yes, 0 - No \n";
            cin >> input;

            // Input Validation
            while (input != 1 && input != 0) inputValidation();

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

// Input Validation
void CourseReg::inputValidation()
{
    cout << "Sorry, the num you typed was wrong. Please enter again: ";
    cin >> input;
}

// Add Courses
void CourseReg::addCourse()
{
    // Open the course list
    fstream infile("CourseList.txt");

    // Get code from the file
    string currentCode;

    // Check if the file exists
    CourseCode *newCode;
    CourseCode *codePtr;

    // If the file is lost
    if (!infile) cout << "Sorry, we can't find any file called CourseList.txt." << endl;

    while (infile)
    {
        // Allocate memory for the new course code
        newCode = new CourseCode;

        // Assign the value to the node
        infile >> currentCode; // Read from file
        newCode->code = currentCode;

        // Make next pointer point to nullptr
        newCode->next = nullptr;

        // If the course list is empty
        if (!head) codePtr = head; // If yes, make codePtr point to head
        else while (codePtr->next) codePtr = codePtr->next; // If not, find the last node of course codes

        // Assign the value to the course list
        codePtr->next = newCode;

    }

    // Close the file
    infile.close();
}



// Display the list
void CourseReg::displayList() const
{
//    CourseCode *codePtr;
//    codePtr = head;
//
//    while (codePtr->next)
//    {
//        cout << codePtr << endl;
//        codePtr = codePtr->next;
//    }
}