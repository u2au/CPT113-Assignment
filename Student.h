#ifndef CPT113_ASSIGNMENT_STUDENT_H
#define CPT113_ASSIGNMENT_STUDENT_H
//#include "Tuition.h"
#include "TotalFee.h"

#include <iostream>
#include <string>

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

    string major = "default";



public:
    // Default Constructor
    Student() {}

    // Overloading Constructor
    Student(int matric, string maj, bool freshman, int desa, int insurance, int parking, bool intl, bool vac, double &acad, double &basic, double &ttIntl, double &tt) {
        // Set the values from main function
        setValue(matric, maj, freshman, desa, insurance, parking, intl, vac);
        passForTuition();
        passForDesa();
        callForIntl();
        passValueBack(acad, basic, ttIntl);
        calcTotalFee(tt);

    }

    // Destructor
    ~Student() {}


    // Prototype
    void setValue(int, string, bool, int, int, int, bool, bool);


    void passForTuition();
    void passForDesa();
    void callForIntl();

    // Friend Function
    friend void passForIntl(bool, bool, double &);

    void setFees();
    void passValueBack(double &, double &, double &);
    void calcTotalFee(double &);

    void setAcadAndBasic();

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
