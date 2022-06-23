//
// Created by rinsuki on 09/06/2022.
//

#include "CGPA.h"
#include <iostream>
#include <iomanip> // setprecision(2);

using namespace std;

void CGPA::setInfo()
{
	system("CLS");
	
    // Initialization
    short input = -1;

    // Welcome
    cout << "Welcome to CGPA Calculator! \n"
         << "Are you in year 1 semester 1 ? (1 for yes, 0 for no) : ";

    // Ask for input
    cin >> input;

    // Input Validation (0 or 1)
    while (input != 0 && input != 1)
    {
        cout << "The input must be 0 or 1. Please re-enter: ";
        cin >> input;
    }

    // Set Credit hours and CGPA of a student who is not in semester 1
    if (input == 0) // Not a freshman
    {
        // Credit Hours
        cout << "Please enter your credit hours first: ";
        cin >> prevHrs;

        // Input Validation (> 0)
        while (prevHrs <= 0)
        {
            if (prevHrs == 0)
            {
                cout << "Are you in year 1 semester 1 ? (1 for yes, 0 for no) : ";
                cin >> input;

                // Input Validation (0 or 1)
                while (input != 0 && input != 1)
                {
                    cout << "The input must be 0 or 1. Please re-enter: ";
                    cin >> input;
                }

                if (input == 1)
                {
                    sem1 = true;
                    break;
                }
            }

            cout << "The credit hours must be larger than 0. Please re-enter: ";
            cin >> prevHrs;
        }
        // Credit Hours END

        // CGPA
        // Record the Credit Hours
        cout << "Great. Please type your CGPA until last semester: ";
        cin >> prevcgpa;

        // Input Validation (0.0 - 4.0)
        while (prevcgpa < 0.0 || prevcgpa > 4.0)
        {
            cout << "Sorry, the range of CGPA is 0.0 - 4.0. Please re-enter: ";
            cin >> prevcgpa;
        }
        // CGPA End

    } else sem1 = true;
    // Set END

    // Current Semester
    string courseCode = "def",
           courseGrade = "U";

    short unit = 0;

    cout << "Input Formats: <courseCode> <grade> <unit> \n"
         << "Please do not add any space when inputting course code. \n"
         << "For example, if a student wants to add a course called CPT113, his grade is A-, and the unit of the course is 3: \n"
         << "Input: CPT113 A- 3, to calculate the CGPA. \n"
         << "Kindly enter: exit, to exit anytime. \n";

    // Calculation
    while (courseCode != "exit")
    {
        // Ask for input
        cin >> courseCode;
        if (courseCode == "exit")
        {
            cout << "Thanks for using. \n";
            break;
        }

        else cin >> courseGrade >> unit;

        // Input Validation
        bool gradeVal = false,
             unitVal;

        // Check if the grade exists
        for (int i = 0; i < 12; i++) if (courseGrade == grade[i]) gradeVal = true;

        // Check if the unit is valid
        if (unit <= 0) unitVal = false;
        else unitVal = true;

        if (!gradeVal)
            cout << "'" << courseGrade << "' is not a valid grade. \n";

        if (!unitVal)
            cout << "Unit of the course must be larger than 0. Please enter next command. \n";

        // If everything is okay
        if (gradeVal && unitVal)
        {
            setCourses(courseCode, courseGrade, unit);
            calc();
        }

        // Input Validation END
    }


}

// Set the courses
void CGPA::setCourses(string newCode, string newGrade, short newUnit)
{
    // Save info into the calculation list
    calcCGPA *newCourse;
    calcCGPA *coursePtr;

    // Allocate memory for new info
    newCourse = new calcCGPA;

    // Assign the values to the node
    newCourse->currentCode = newCode;
    newCourse->currentGrade = newGrade;
    newCourse->currentUnit = newUnit;

    // Make next pointer point to nullptr
    newCourse->next = nullptr;

    // Save the new node to the end of the calculation list
    if (!head) head = newCourse; // Empty List

    else // Non-empty List
    {
        coursePtr = head;
        while (coursePtr->next) coursePtr = coursePtr->next; // Find the last node of info
        coursePtr->next = newCourse; // Assign the value to the course list
        onlyCourse = false;
    }
}

// Calculate CGPA
void CGPA::calc()
{
    // Initialization
    calcCGPA *matchPtr = head;
    calcCGPA *calcPtr = head;

    double GP,                   // GP by course
           courseGP,            // Total GP by course
           totalGP = 0.0;      // Total GP

    auto totalUnit = 0;
    bool conversion = false;

    // Convert grade to grade point (GP)
    do {
        for (int i = 0; (i <= 11 && !conversion); i++)
        {
            // If respective grade is found
            if (matchPtr->currentGrade == grade[i])
            {
                conversion = true; // Conversion Ends
                GP = gradePoint[i]; // Assign respective GP to the local var
                courseGP = GP * (matchPtr->currentUnit);

                // Add to total GP
                totalGP += courseGP;
                totalUnit += matchPtr->currentUnit;
            }
        }

        conversion = false; // Default

        // Point to next node
        if (!onlyCourse) matchPtr = matchPtr->next;

    } while (matchPtr->next != nullptr);

    // For the last node
    if (!onlyCourse)
    {
    	system("CLS");
    	
        for (int i = 0; (i <= 11 && !conversion); i++)
        {
            // If respective grade is found
            if (matchPtr->currentGrade == grade[i])
            {
                conversion = true; // Conversion Ends
                GP = gradePoint[i]; // Assign respective GP to the local var
                courseGP = GP * (matchPtr->currentUnit);

                // Add to total GP
                totalGP += courseGP;
                totalUnit += matchPtr->currentUnit;
            }
        }
    }

    // Display the results, and calculate
    cout << "Calculation Results \n"
         << "Course\t\t" << "Grade\t\t" << "Unit\n";

    // Check if the course is the only course in the list
    if (onlyCourse)
    {
        cout << calcPtr->currentCode << "\t\t"
             << calcPtr->currentGrade << "\t\t"
             << calcPtr->currentUnit << "\n\n";

        gpa = totalGP / (calcPtr->currentUnit);
    }

    // If there are multiple courses in the calculation list
    else
	{
        while (calcPtr->next != nullptr)
        {
            // Display
            cout << calcPtr->currentCode << "\t\t"
                 << calcPtr->currentGrade << "\t\t"
                 << calcPtr->currentUnit << "\n";

            calcPtr = calcPtr->next;
        }

        // Display
        cout << calcPtr->currentCode << "\t\t"
             << calcPtr->currentGrade << "\t\t"
             << calcPtr->currentUnit << "\n\n";

        gpa = totalGP / totalUnit;

    }

    // Calculate CGPA
    if (sem1) cgpa = gpa;
    else
    {
        // Initialization
        double prevGP = prevcgpa * prevHrs;

        // Get total GP including last semester(s)
        totalGP += prevGP;
        totalUnit += prevHrs;

        // Calculation
        cgpa = totalGP / totalUnit;

    }

    // Display GPA and CGPA
    cout << "GPA: " << gpa << " \n" << fixed << setprecision(2)
         << "CGPA: " << cgpa << " \n" << fixed << setprecision(2);

}
