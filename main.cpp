//
// Created by rinsuki on 03/06/2022.
//

#include <iostream>
#include <string>
#include "CourseReg.h"

using namespace std;

// Header
void menu();

int main()
{
    // Welcome
    string name, matric;
    cout << "Welcome to use USM CS Student’s Registration System!" << "\n"
         << "Please type your name: ";
    cin >> name;
    cout << "Please enter your matric number: ";
    cin >> matric;

    // Display the menu
    menu();



    return 0;
}

void menu()
{
    short input = -1; // Initialization

    // Menu
    cout << "Main Menu \n"
         << "1 - Course Registration \n"
         << "2 - CGPA Calculator \n"
         << "0 - Exit \n"
         << "Kindly type num of the function that you want to use: ";
    cin >> input;

    // Input Validation
    while (input != 0 && input != 1 && input != 2)
    {
        cout << "Sorry, '" << input << "' is not a valid num for the program. \n"
             << "Please type num of the function again: ";
        cin >> input;
    }

    switch (input)
    {
        // Terminate the program
        case 0:
            cout << "Thanks for using." << endl;
            break;

        // Course Registration
        case 1:
            CourseReg(-1);
            break;

        // Default
        default:
            cout << "Wrong lah!" << endl;
            break;
    }

}