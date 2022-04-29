//
// Created by rinsuki on 29/04/2022.
//

#include "Student.h"
#include <iostream>

using namespace std;

private:
    double matricNum;
    int livesInHostel;
    bool isInternational;
    int insuranceLevel;
    bool isFullyVaccinated;
    int monthlyMealPlan;

    protected:
    bool  isFreshman;

    public:
    void read_file(){
        ifstream file;
        file.open("student.txt");    //read file
        if (file.is_open()){
            file >> matricNum;
            file >> livesInHostel;
            file >> isInternational;
            file >> insuranceLevel;
            file >> isFullyVaccinated;
            file >> monthlyMealPlan;
            file >> isFreshman;
        }
        else{
            cout << "Unable to open file";
        }

    }
// Default Constructor
Student::Student() {
    welc();
}
