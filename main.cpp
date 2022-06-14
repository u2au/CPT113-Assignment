//
// Created by rinsuki on 03/06/2022.
//

#include <iostream>
#include <string>
#include "CourseReg.h"
#include "CGPA.h"


using namespace std;

void menu(short);

int main()
{
    // Variables Definition
    bool readList = false;

    // Welcome
    string name, matric;
    cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
    cout << "■                                                        ■ \n";
    cout << "■  Welcome to use USM CS Student's Registration System!  ■ \n" ;
    cout << "■                                                        ■ \n";
    cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout<< "＞ Please type your name: "; // Name
    cin >> name;
    cout << "＞ Please enter your matric number: "; // Matric Num
    cin >> matric;
    cout << "Welcome, " << name << " (" << matric << ")!" << endl; // Greetings

    // Display the menu
    menu(-1);



    return 0;
}

void menu(short input)
{
    // Menu
    cout << "\n■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n" 
    << "■\t\t\tMain Menu\t\t\t■ \n"
        << "■\t\t  1 - Course Registration  \t\t■ \n"
        << "■\t\t    2 - CGPA Calculator    \t\t■ \n"
        << "■\t\t\t0 - Exit\t\t\t■ \n"
        << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
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
    else if (input == 1)
    {
        CourseReg cr;
        cr.menu();
    }

    else if (input == 2)
    {
        CGPA cg;
        cg.setInfo();

    }

}
