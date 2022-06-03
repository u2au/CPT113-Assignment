//
// Created by rinsuki on 03/06/2022.
//

#include "CourseReg.h"
#include <iostream>
#include <fstream>

using namespace std;

template <class T>
void CourseReg<T>::menu()
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
template <class T>
void CourseReg<T>::inputValidation()
{
    cout << "Sorry, the num you typed was wrong. Please enter again: ";
    cin >> input;
}

// Set Course Codes
template <class T>
void CourseReg<T>::setCode(T c)
{




}

// Set Course Units
void setUnit(short u)
{

}

// Set Course Types
void setType(char t)
{

}

// Add Courses
template <class T>
void CourseReg<T>::addCourse(T info)
{
    fstream infile("CourseList.txt");

    // Initialization
    CourseCode *newCode;
    CourseCode *codePtr;

    newCode = new CourseCode;
    newCode->code = info;
    newCode->next = nullptr;

    codePtr = head;

    while (infile)
    {
        infile >> info;
        codePtr->next = newCode;

//        infile >> info;
//        setUnit(info);
//
//        infile >> info;
//        setType(info);
    }

    infile.close();
}



// Display the list
template <class T>
void CourseReg<T>::displayList() const
{
    CourseCode *codePtr;
    codePtr = head;

    while (codePtr->next)
    {
        cout << codePtr << endl;
        codePtr = codePtr->next;
    }
}