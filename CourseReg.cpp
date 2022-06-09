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

            }
            else if (operation == "drop") {
                if (!isEmpty) dropCourse(input);
                else cout << "Sorry, you can't drop the course since you haven't registered any course yet. \n";
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
    Student *trailPtr = nullptr;

    // Allocate a new node & store the value of the current list node in it
    newCourse = new Student;
    nodePtr = head;

    // Get data from a specific node from the course list
    for (int i = 1; i < num; i++) nodePtr = nodePtr->next;

    // Check if the course exists in the registration list
    if (ifExists(nodePtr->code)) cout << "Sorry, " << nodePtr->code << " has already in the registration list. Please enter next command. \n";
    else
    {
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

            while (coursePtr->next != nullptr) coursePtr = coursePtr->next;
            trailPtr = coursePtr;
            coursePtr = coursePtr->next;

            trailPtr->next = newCourse;
            newCourse->prev = trailPtr;
            courseEnd = newCourse;
            courseEnd->next = nullptr;

        }

        isEmpty = false;

        showReg('a');
    }

}

// Drop a course
void CourseReg::dropCourse(int num)
{
    Student *numPtr = courseHead;
    Student *dropPtr = courseHead;

    short reg = 0;
    bool valid = false;

    // Calculate num of registered courses
    if (courseHead == courseEnd) reg++;
    else reg++; // To avoid not counting the last node

    while (numPtr->next != nullptr) {
        numPtr = numPtr->next;
        reg++;
    }

    // Check if the num is valid
    if (num < 0 || num > reg)
    {
        cout << "Sorry, the num of the course to be dropped must be: \n"
                "larger than 0 and less than " << reg << ".\n"
             << "Please re-enter the command. \n";
        valid = false; // Go back to the menu

    } else valid = true;

    // If the num is valid, drop the selected course
    if (valid)
    {
        // Delete the only course in the registration list
        if (courseHead == courseEnd)
        {
            dropPtr = courseHead;
            courseHead = courseHead->next;
            delete dropPtr;

            cout << "Kindly add any course you like! Please enter any command. \n";
            isEmpty = true;

        }

        // Delete the first course in the registration list with multiple courses
        else if (num == 1)
        {
            dropPtr = courseHead;
            courseHead = courseHead->next;

            // Display
            showReg('d');
            cout << "Course #" << num << " " << dropPtr->courseCode << " has been dropped. Please enter next command. \n";
            delete dropPtr;
        }

        else // If the course to be deleted is not the first course in the list
        {
            for (int i = 1; i != num; i++) dropPtr = dropPtr->next;

            Student *trailPtr;
            trailPtr = dropPtr->prev;
            trailPtr->next = dropPtr->next;
            if (dropPtr->next != nullptr) dropPtr->next->prev = trailPtr;
            if (dropPtr == courseEnd) courseEnd = trailPtr;

            // Display
            showReg('d');
            cout << "Course #" << num << " " << dropPtr->courseCode << " has been dropped. Please enter next command. \n";
        }
    }

}

// Display the registration list
void CourseReg::showReg(char ops)
{
    Student *coursePtr;

    coursePtr = courseHead;
    cout << "Registered Courses List \n"
         << "Num\t\t" << "Code\t\t" << "Unit\t" << "Type\t" << endl;

    int i = 0; // For counting num of courses
    bool last = false;

    do {
        cout << ++i << "\t\t"
             << coursePtr->courseCode << "\t\t"
             << coursePtr->courseUnit << "\t\t"
             << coursePtr->courseType << "\t"
             << endl;

        // If the list only has 1 element, do not point to the next node
        if (courseHead != courseEnd) coursePtr = coursePtr->next;

        // Display the last node
        if (coursePtr->next == nullptr && courseHead != courseEnd)
        {
            cout << ++i << "\t\t"
                 << coursePtr->courseCode << "\t\t"
                 << coursePtr->courseUnit << "\t\t"
                 << coursePtr->courseType << "\t"
                 << endl;
        }

    } while (coursePtr->next != nullptr);

    // Display
    if (ops == 'a')
    {
        // Added a course
        cout << coursePtr->courseCode << " has been successfully added to your registration list! \n"
             << "Please enter next command: ";
    }

    // Display current registration list END
}

// Check if a course exists in the registration list
bool CourseReg::ifExists(string checkCode)
{
    bool found = false;
    Student *checkPtr;
    checkPtr = courseHead;

    if (courseHead == courseEnd) found = false;
    else
    {
        while (checkPtr != nullptr && !found)
        {
            if (checkPtr->courseCode == checkCode) found = true;
            else checkPtr = checkPtr->next;
        }
    }

    return found;
};
