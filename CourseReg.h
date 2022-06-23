//
// Created by rinsuki on 03/06/2022.
//

#ifndef TUITION_CPP_COURSEREG_H
#define TUITION_CPP_COURSEREG_H
#include <string>

using namespace std;

class CourseReg {
	
private:
    short input;
    int numOfCourses = 0;
    bool isEmpty = true;
    string strInput;

    // Declare a structure for the info-setting list
    struct SetInfo
    {
        int num;
        string code;
        short unit;
        char type;


        struct SetInfo *next;
    };

    SetInfo *head; // Head Pointer for setting Info

    // Declare a structure for the Course Registration Doubly Linked List
    struct Student
    {
        string courseCode;
        short courseUnit;
        char courseType;

        struct Student *next;
        struct Student *prev;
    };

    Student *courseHead;
    Student *courseEnd;

public:
    // Default Constructor
    CourseReg() {
        input = -1;
        head = nullptr;
        courseHead = nullptr;
        courseEnd = nullptr;
    }

    // Prototype
    void menu();
    void inputValidation();
    void setCourse();
    void displayList();
    void modifyCourse();
    void addCourse(int);
    void dropCourse(int);
    void showReg(char);
    bool ifExists(string);
    void searchCourse(string);

};

#endif //TUITION_CPP_COURSEREG_H
