#ifndef CPT113_ASSIGNMENT_STUDENT_H
#define CPT113_ASSIGNMENT_STUDENT_H

#include "Tuition.h"
#include "Desa.h"
#include "Intl.h"
#include "TotalFee.h"

#include <iostream>
#include <string>

using namespace std;

class Student : public Tuition, public Desa, public Intl {

private:
    TotalFee f1, f2, f3; // Use composition and operator overloading (of type private)

    // Variable Definition
    double acadFee,
           basicCost,
           totalIntl,
           totalFee;

public:
    // Default Constructor
    Student() {
        acadFee = 0.0;
        basicCost = 0.0;
        totalIntl = 0.0;
        totalFee = 0.0;
    }

    // Prototype
    void setValue(bool, string, short, short, short, bool, bool);
    void passForTuition();
    void passForDesa();
    void callForIntl();
    void passValueBack(double &, double &, double &, double &) const;
    void calcTotalFee();

    // Friend Function
    friend void passForIntl(double &);

};


#endif //CPT113_ASSIGNMENT_STUDENT_H
