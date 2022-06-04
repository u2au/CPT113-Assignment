//
// Created by rinsuki on 03/06/2022.
//

#ifndef TUITION_CPP_COURSEREG_H
#define TUITION_CPP_COURSEREG_H
#include <string>

using namespace std;

// Linked List for Course Codes
class CourseCode
{
public:
    string code; // Current Code
    CourseCode *next; // Pointer to the next code

    // Constructor
    CourseCode();

    CourseCode (string currentCode)
    {
        code = currentCode;
        next = nullptr;
    }

};

class CourseReg {
private:
    short input;
    CourseCode *head; // Head Pointer for the Course Code List

public:
    // Default Constructor
    CourseReg() {
        input = -1;
        head = nullptr;
    }

    // Overloading Constructor
    CourseReg(short init) {
        input = init;
        menu();
    }

//    // Destructor
//    ~CourseReg();

    // Prototype
    void menu();
    void inputValidation();
    void addCourse();

    void dropCourse();
    void displayList() const;

};

#endif //TUITION_CPP_COURSEREG_H
