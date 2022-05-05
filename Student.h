//
// Created by rinsuki on 29/04/2022.
//

#ifndef CPT113_ASSIGNMENT_STUDENT_H
#define CPT113_ASSIGNMENT_STUDENT_H
//student class 是base class
//student class要有year num和sem num，是从文件读还是用户输入？
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

    // Prototype
    void readFile(); // Read From File
    void inputValidation();
    void Display();
    void outputData();


};


#endif //CPT113_ASSIGNMENT_STUDENT_H
