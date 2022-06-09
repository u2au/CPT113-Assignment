//
// Created by rinsuki on 09/06/2022.
//

#ifndef TUITION_CPP_CGPA_H
#define TUITION_CPP_CGPA_H

#include <string>

using namespace std;

class CGPA {
private:
    // Variable Definition
    short prevHrs = 0;

    float prevcgpa = 0.0,
          gpa = 0.0,
          cgpa = 0.0;

    bool sem1 = false,
         onlyCourse = true;

    // Declare a structure for the calculation list
    struct calcCGPA
    {
        string currentCode,
               currentGrade;

        short currentUnit;

        struct calcCGPA *next; // To point to the next node
//        struct calcCGPA *prev; // To point to the prev node
    };

    calcCGPA *head; // Head Pointer
//    calcCGPA *end; // End Pointer

    // Set arrays for storing grades info
    string grade[12] = {
            "A", "A-",
            "B+", "B", "B-",
            "C+", "C", "C-",
            "D+", "D", "D-",
            "F"
    };

    float gradePoint[12] = {
            4, 3.67,                        // A, A-
            3.33, 3.00, 2.67,         // B+, B, B-
            2.33, 2.00, 1.67,        // C+, C, C-
            1.33, 1.00, 0.67,      // D+, D, D-
            0                              // F
    };
    // Set arrays for storing grades info END

public:
    // Constructor
    CGPA () {
        head = nullptr;
    }

    // Prototype
    void setInfo();
    void setCourses(string, string, short);
    void calc();


};

class calcCGPA
{
public:
    string currentCode,
           currentGrade;

    short currentUnit;

    calcCGPA *next;

    // Constructor
    calcCGPA ()
    {
        currentCode = "Default";
        currentGrade = "D";
        currentUnit = 0;
    }
};

#endif //TUITION_CPP_CGPA_H
