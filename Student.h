//
// Created by rinsuki on 29/04/2022.
//

#ifndef CPT113_ASSIGNMENT_STUDENT_H
#define CPT113_ASSIGNMENT_STUDENT_H


class Student {
private:
    double matricNum;

protected:
    int livesInHostel,
        insuranceLevel,
        mealPlan;

    bool isFreshman,
         isInternational,
         isFullyVaccinated;


public:
    Student();
    void readFile(); // Read From File
    void inputValidation();
    void Display();
    void outputData();


};


#endif //CPT113_ASSIGNMENT_STUDENT_H
