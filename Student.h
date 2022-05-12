#ifndef CPT113_ASSIGNMENT_STUDENT_H
#define CPT113_ASSIGNMENT_STUDENT_H
//#include "Tuition.h"
#include "TotalFee.h"

#include <iostream>

using namespace std;

class Student {
private:
    TotalFee f1, f2, f3, f; // Use composition and operator overloading (privately)

protected:
    // Variable Definition
    int matricNum = 111111,
            desa = 0,
            insuranceLevel = 0,
            parkingTimes = 0,
            lineOfFile = 0;

    bool isInt = true,
         isFullyVaccinated = false,
         isFreshman = true;

    //    double getDF, getTI, getIntlF;
    double acadFee = 0.0,
           basicCost = 0.0,
           totalIntl = 0.0; // get perspective total fee from desa class,intl class and tuition class



public:
    // Default Constructor
    Student() {}

    // Overloading Constructor
    Student(int) {
        getFileLines();
        getData();
        inputValidation();

        passForTuition();
        passForDesa();
        passForIntl();
        calcTotalFee();

    }

    // Destructor
    ~Student() {
        cout << "Destructor is called." << endl;
    }


    // Prototype
    void getFileLines();
    void getData();
    void inputValidation();

//    void setData();
    void passForTuition();
    void passForDesa();
    void passForIntl();
    void setFees();
    void calcTotalFee();

    // Inline Functions
    int whichDesa() const {return desa;}
    bool checkInt() const {return isInt;}
    bool checkFreshman() const {return isFreshman;}
    int getInsuranceLevel() const {return insuranceLevel;}
    int getParkingTimes() const {return parkingTimes;}



    // Operator overloading
    // Why set fee to classes? typo?
//    void setData() {
//
//    }

};


#endif //CPT113_ASSIGNMENT_STUDENT_H
