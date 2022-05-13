#ifndef CPT113_ASSIGNMENT_STUDENT_H
#define CPT113_ASSIGNMENT_STUDENT_H
//#include "Tuition.h"
#include "TotalFee.h"

#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    TotalFee f1, f2, f3; // Use composition and operator overloading (privately)

    // Variable Definition
    short desa = 0,
          insuranceLevel = 0,
          parkingTimes = 0;

    bool isInt = true,
            isFullyVaccinated = false,
            isFreshman = true;

    double acadFee = 0.0,
            basicCost = 0.0,
            totalIntl = 0.0;

protected:
    // For class Intl
    double quarantineFee = 0,
           quarantineFeePerDay = 150.0;

    const int quarantineDays = 5;


public:
    // Default Constructor
    Student() = default;

    // Overloading Constructor
    Student(string maj, bool freshman,
            short desa, short insurance, short parking,
            bool intl, bool vac,
            double &acad, double &basic, double &ttIntl, double &tt) {

        // Set the values from main function
        setValue(freshman, desa, insurance, parking, intl, vac);
        passForTuition(maj);
        passForDesa();
        callForIntl();
        passValueBack(acad, basic, ttIntl);
        calcTotalFee(tt);
    }

    // Destructor
    ~Student() {}


    // Prototype
    void setValue(bool, short, short, short, bool, bool);
    void passForTuition(string);
    void passForDesa();
    void callForIntl();

    // Friend Function
    friend void passForIntl(bool, bool, double &);
    void passValueBack(double &, double &, double &);
    void calcTotalFee(double &);

    // Inline Functions
    bool checkFreshman() const {return isFreshman;}

};


#endif //CPT113_ASSIGNMENT_STUDENT_H
