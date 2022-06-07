//
// Created by rinsuki on 03/06/2022.
//

#ifndef TUITION_CPP_COURSEREG_H
#define TUITION_CPP_COURSEREG_H
#include <string>

using namespace std;

class CourseReg {
private:
    
    int numOfCourses = 0;

    // Declare a structure for the info-setting list
    struct SetInfo
    {
    	int num;
        string code;
        short unit;
        char type;


        struct SetInfo *next;
        //struct SetInfo *prev;
    };

    SetInfo *head; // Head Pointer for setting Info
 //   SetInfo *end;  //end pointer for setting Info

    // Declare a structure for the Student's Registration Doubly Linked List
    struct Student
    {
        int num;
        string code;
        short unit;
        char type;

        struct Student *next;
        struct Student *prev;
    };

    Student *courseHead;
    Student *courseEnd;

    protected:
    	  int count=0;//to calculate the number of courses has been added
    	  short input;

//     //Declare a structure for the Unit List
//    struct Unit
//    {
//        short unit;
//        struct Unit *next;
//    };
//
//    Unit *unitHead; // Head Pointer for the Unit List
//
//    // Declare a structure for the Type List
//    struct Type
//    {
//        short type;
//        struct Type *next;
//    };
//
//    Unit *typeHead; // Head Pointer for the Unit List

public:
    // Default Constructor
    CourseReg() {
        input = -1;
        head = nullptr;
        courseHead = nullptr;
        courseEnd = nullptr;
    }

    string code;
//    CourseReg *next;
//    CourseReg *prev;

//    // Destructor
//    ~CourseReg();

    // Prototype
    void menu();
    void inputValidation();
    void setCourse();
    void displayList();
    void terminal();
    void modifyCourse(char, int);
    void passData(string, short, char);
    
  // bool search(int);
  // void addCourse(char, string);
  //  void dropCourse(string);
   void showNewList();//finally show the courses this student has choose

};

// Linked List for Info
class SetInfo
{
public:
	int num;
    string code; // Current Code
    short unit;
    char type;

    SetInfo *next; // Pointer to the next code
   // SetInfo *pre;

    // Constructor
    SetInfo()
    {

    }

//    CourseCode (string currentCode)
//    {
//        code = currentCode;
//        next = nullptr;
//    }

};

// Doubly Linked List for Student's Registration
class Student
{
	public:
    	int num;
        string code;
        short unit;
        char type;

        struct Student *next;
        struct Student *prev;
    



};

#endif //TUITION_CPP_COURSEREG_H
