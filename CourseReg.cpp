//
// Created by rinsuki on 03/06/2022.
//

#include "CourseReg.h"
#include <iostream>
#include <fstream>

using namespace std;

void CourseReg::menu()
{
    // Welcome
    cout << "Welcome to USM CS Student Registration System! \n"
         << "Please wait... We're loading courses from the course list... \n";

    // Get the courses info
    setCourse();

    // Registration System
    modifyCourse();


}

// Input Validation
void CourseReg::inputValidation()
{
    cout << "Sorry, the num you typed was wrong. Please enter again: ";
    cin >> input;
}

// Add Courses
void CourseReg::setCourse()
{
    // Open the course list
    ifstream infile;
    infile.open("CourseList.txt", ios::in);

    // Initialization
    string currentCode = "default";
    short currentUnit = 1;
    char currentType = 'D';

    // If the file is lost
    if (!infile) cout << "Sorry, we can't find any file called CourseList.txt." << endl;
    else
    {
        while (infile)
        {
            // SetInfo START
            SetInfo *newInfo;
            SetInfo *InfoPtr;

            // Read data from the course list
            infile >> currentCode;
            infile >> currentUnit;
            infile >> currentType;

            // Allocate memory for new info
            newInfo = new SetInfo;

            // Assign the value to the node
            newInfo->code = currentCode;
            newInfo->unit = currentUnit;
            newInfo->type = currentType;

            // Make next pointer point to nullptr
            newInfo->next = nullptr;

            // If the course list is empty
            if (!head) head = newInfo;

            else
            {
                InfoPtr = head;
                while (InfoPtr->next) InfoPtr = InfoPtr->next; // Find the last node of info
                InfoPtr->next = newInfo; // Assign the value to the course list

            }

            numOfCourses++;
        }

        // Close the file
        infile.close();

        // Display num of the courses
        cout << "Thanks for waiting! There are " << --numOfCourses << " courses in the list. \n";
    }

}

// Display the list
void CourseReg::displayList()
{
    SetInfo *infoPtr;
    infoPtr = head;

    cout << "Here are the courses offered to CS students. \n"
         << "Num\t\t" << "Code\t\t" << "Unit\t" << "Type\t" << endl;

    int num = 0; // Initialization

    while (infoPtr->next)
    {
        cout << ++num << "\t\t"
             << infoPtr->code << "\t\t"
             << infoPtr->unit << "\t\t"
             << infoPtr->type << "\t"
             << endl;

        infoPtr = infoPtr->next;
    }

    cout << "Currently, there are " << num << " courses offered to students from School of Computer Sciences. \n";

}

// Registration System
void CourseReg::modifyCourse()
{
    // Display the list
    cout << "Do you want to display all the courses offered to USM CS students? (1 - Yes, 0 - No) : ";
    cin >> input;

    while (input != 1 && input != 0) inputValidation(); // Input Validation

    // If yes, display the list
    system("CLS");
    if (input == 1) displayList();

    // Temp Variable
    string operation = "def";

    cout << "Input Formats: <operation> <num> \n"
         << "Operations: add, drop, exit \n"
         << "For example, if a student wants to add a course which num is 20, the command is: add 20 \n"
         << "Kindly enter: exit, to exit anytime. \n";

    // Ask for input
    cin >> operation;
    if (operation != "exit")
    {
        Student s;
        cin >> input;
        do {
            // Input Validation
            while ((operation != "add" && operation != "drop" && operation != "exit")
                   || (input <= 0 || input > numOfCourses))
            {
                if (operation != "add" && operation != "drop" && operation != "exit") {
                    cout << "Sorry, possible operations are: add, drop, exit. Please re-enter the whole command. \n";
                }

                if (input <= 0 || input > numOfCourses) {
                    cout << "Sorry, valid range of the courses is: 1-" <<  numOfCourses << ". Please re-enter the whole command. \n";
                }

                cin >> operation;
                cin >> input;
            }

            // Add or drop a course

            if (operation == "add") {
                addCourse(input);
                cout << "Course #" << input << " has been added. Please enter next command. \n";
            }
            else if (operation == "drop") {
                dropCourse(input);
                cout << "Course #" << input << " has been dropped. Please enter next command. \n";
            }

            cin >> operation;
            if (operation != "exit") cin >> input;

        } while (operation != "exit");

    }
    else cout << "Thanks for using. \n";
}

// Add a course
void CourseReg::addCourse(int num)
{
    // Copy the node we want from the existing list to a new list
    SetInfo *nodePtr = nullptr;
    Student *coursePtr;
    Student *newCourse;

    // Allocate a new node & store the value of the current list node in it
    newCourse = new Student;
    nodePtr = head;

    // Get data from a specific node from the course list
    for (int i = 1; i < num; i++) nodePtr = nodePtr->next;

//    // DEBUG
//    cout << nodePtr->code << endl;
//    newCourse->courseCode = "1";
//    cout << newCourse->courseCode << endl;

    // After pointing to the course we want to add, get information of the node
    newCourse->courseCode = nodePtr->code;
    newCourse->courseType = nodePtr->type;
    newCourse->courseUnit = nodePtr->unit;

    if (courseHead == nullptr) // Empty List
    {
        newCourse->prev = nullptr;
        newCourse->next = nullptr;
        courseHead = newCourse;
        courseEnd = newCourse;

    }
    else // Non-empty List
    {
        // Initialization
        Student *coursePtr = courseHead;
        Student *trailPtr = nullptr;

        while (coursePtr->next != NULL) coursePtr = coursePtr->next;
        trailPtr = coursePtr;
        coursePtr = coursePtr->next;

        trailPtr->next = newCourse;
        newCourse->prev = trailPtr;
        courseEnd = newCourse;
        courseEnd->next = nullptr;

        // DEBUG
        coursePtr = courseHead;
        cout << "Registered Courses List \n"
             << "Num\t\t" << "Code\t\t" << "Unit\t" << "Type\t" << endl;

        for (int i = 1; coursePtr->next != NULL; i++)
        {
            cout << i << "\t\t"
                 << coursePtr->courseCode << "\t\t"
                 << coursePtr->courseUnit << "\t\t"
                 << coursePtr->courseType << "\t"
                 << endl;

            coursePtr = coursePtr->next;
        }
        // DEBUG END
    }



}

// Drop a course
void CourseReg::dropCourse(int num)
{



}