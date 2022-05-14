/*totalFee function is used to calculate to total fee from Desa class, tuition class and intl(international) class,
this class use compo
 the operator overloading func in this class will be called in student class,
 */

#ifndef CPT113_ASSIGNMENT_TOTALFEE_H
#define CPT113_ASSIGNMENT_TOTALFEE_H

#include <iostream>
using namespace std;

class TotalFee {
private:
    double acadFee = 0.0, //  class Tuition
           basicCost = 0.0, // class Desa
           totalIntl = 0.0, // class Intl
           totalFee = 0.0;

public:
    // Default Constructor
    TotalFee() = default;

    // Set Academic Fees
    void setAcadFee(double acad) { // Mutator
        acadFee = acad;
    }

    // Set Total Intl Fees
    void setTotalIntl(double intl) { // Mutator
        totalIntl = intl;
    }

     // Set Basic Cost
    void setBasicCost(double bsc) { // Mutator
        basicCost = bsc;
    }

    // Operator overloading
    TotalFee operator+(const TotalFee &obj) {
        TotalFee t;
        t.basicCost = basicCost + obj.basicCost;
        t.totalIntl = totalIntl + obj.totalIntl;
        t.acadFee = acadFee + obj.acadFee;

        return t;
    }

    double getTotal() { // Accessor
        totalFee = acadFee + basicCost + totalIntl;
        return totalFee;
    }

};
#endif //CPT113_ASSIGNMENT_TOTALFEE_H