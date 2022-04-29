//
// Created by rinsuki on 29/04/2022.
//

#include "Student.h"
#include "Fee.h"
#include <iostream>
#include <fstream> // ifstream

using namespace std;

// Welcome
void welc() {
    cout << "Welcome to use Fee Calculator! \n";
}

// Read from file
void readFile(double num, double hostel, bool isInt, int insurance, bool vac, int meal, bool freshman){
    ifstream file;
    file.open("student.txt");
    if (file.is_open()){
        file >> num; // Matric Number
        file >> hostel;
        file >> isInt;
        file >> insurance;
        file >> vac;
        file >> meal;
        file >> freshman;
    }
    else {
        cout << "Unable to open file\n";
    }

}


// Default Constructor
Student::Student() {
    welc();
    readFile(&matricNum, &livesInHostel, &isInternational, &insuranceLevel,
             &isFullyVaccinated, &monthlyMealPlan, &isFreshman);
    Fee();


}