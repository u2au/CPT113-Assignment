//
// Created by rinsuki on 03/06/2022.
//

#include <iostream>
#include <string>
#include "CourseReg.h"

using namespace std;

void menu(short);

int main()
{
    // Variables Definition
    bool readList = false;

    // Welcome
    string name, matric;
    cout << "Welcome to use USM CS Student’s Registration System! \n"
         << "Please type your name: "; // Name
    cin >> name;
    cout << "Please enter your matric number: "; // Matric Num
    cin >> matric;
    cout << "Welcome, " << name << " (" << matric << ")!" << endl; // Greetings

    // Display the menu
    menu(-1);



    return 0;
}

void menu(short input)
{
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

    if (input == 0) cout << "Thank you. \n";
    else if (input == 1) CourseReg(-1);
//    else ; // hasn't finished

}