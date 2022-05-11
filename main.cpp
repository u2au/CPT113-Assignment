//
// Created by rinsuki on 11/05/2022.
//
#include "Student.h"
#include "Desa.h"
#include "Intl.h"
#include "Tuition.h"
#include "Output.h"

#include <iostream>
using namespace std;

// Prototype
void welc();

int main()
{
    // Variable Definition
    double tuition, extraFee;

    // Welcome
    welc();

    // Call the constructors
    Student(true);
    Desa();
    Intl();
    Tuition();
    Output();

    // Get the values
    Tuition(tuition, extraFee);







    return 0;
}

// Functions
void welc() {
    cout << "Welcome to use the Fee Calculator designed by Group 2 for Assignment 1 of CPT113!\n"
         << "This program may help you convert the choices of students to respective required amounts.\n"
         << "For example, it can convert the initial data '1' for desa to '600', "
         << "which means renting for a semester (5 months estimated), 150 per month.\n"
         << "Kindly press ENTER to start." << endl;

    cin.get();
}