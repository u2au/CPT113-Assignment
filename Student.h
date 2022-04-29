//
// Created by rinsuki on 29/04/2022.
//

#ifndef CPT113_ASSIGNMENT_STUDENT_H
#define CPT113_ASSIGNMENT_STUDENT_H

class Student {
private:
    double matricNum;
    int insuranceLevel,
        monthlyMealPlan;

    bool isFullyVaccinated;

protected:
    int livesInHostel;
    bool isFreshman,
         isInternational;


public:
    Student();

};


#endif //CPT113_ASSIGNMENT_STUDENT_H
