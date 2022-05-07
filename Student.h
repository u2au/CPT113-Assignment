//
// Created by rinsuki on 29/04/2022.
//

#ifndef CPT113_ASSIGNMENT_STUDENT_H
#define CPT113_ASSIGNMENT_STUDENT_H
//student class 是 base class
//student class 要有year num和sem num，是从文件读还是用户输入？
// r: 从文件读取，若有异常值则通过 inputValidation 要求用户 correct the data
class Student {
private:
    double matricNum;

protected:
    int hostelType,
        insuranceLevel,
        mealPlan,
        semester, month;

    bool isFreshman,
         isInternational,
         isFullyVaccinated;


public:
    // Default Constructor
    Student();

    // Prototype
    int getMonth() const {
        return month;
    }

    int getSem() const {
        return semester;
    }

    void readFile(); // Read From File
    void inputValidation();
    void Display();
    void outputData();


};


#endif //CPT113_ASSIGNMENT_STUDENT_H
