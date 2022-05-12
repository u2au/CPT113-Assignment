#ifndef CPT113_ASSIGNMENT_STUDENT_H
#define CPT113_ASSIGNMENT_STUDENT_H
#include "Infile.h"
//#include "Tuition.h"
#include "TotalFee.h"

#include <iostream>

using namespace std;

class Student : public Infile {
private:
    TotalFee f1, f2, f3, f; // Use composition and operator overloading (privately)

protected:
    int matricNum = 111111,
        desa = 0,
        insuranceLevel = 0,
        parkingTimes = 0;

    double desaFee = 0.0;

//    double getDF, getTI, getIntlF;
    double acadFee, basicCost, totalIntl; // get perspective total fee from desa class,intl class and tuition class

    bool isInt = true,
         isFullyVaccinated = false,
         isFreshman = true;




public:
    // Default Constructor
    Student() {}

    // Overloading Constructor
    Student(int) {
        passForTuition();

    }

    // Destructor
    ~Student() {
        cout << "Destructor is called." << endl;
    }


    // Prototype
    void passForTuition();
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
    void setData() {

    }

};


#endif //CPT113_ASSIGNMENT_STUDENT_H
