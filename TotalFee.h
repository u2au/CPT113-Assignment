/*totalFee function is used to calculate to total fee from Desa class, tuition class and intl(international) class,
this class use compo
 the operator overloading func in this class will be called in student class,
 */

#ifndef CPT113_ASSIGNMENT_TOTALFEE_H
#define CPT113_ASSIGNMENT_TOTALFEE_H

#include "Desa.h"
#include "Tuition.h"
#include "Intl.h"

class TotalFee {
private:


    double basicCost = 0.0, // class Desa
           acadFee = 0.0, //  class Tuition
           intlFee = 0.0, // class Intl
           totalFee = 0.0; // 非常坏 double

public:
    // Default Constructor
    TotalFee() {

    }

    // Overloading Constructor
    TotalFee(int) {
        getRespectiveFee();
    }

    // Since 'TotalFee.cpp' hasn't been uploaded, I put the new function here temporarily.
    // It'll be better if it could be moved to 'TotalFee.cpp'. (Don't forget to add the prefix 'TotalFee:' yo).
    // Feel free to use the variables for ur overloading operators! XD
    void getRespectiveFee() {
        Desa d;
        basicCost = d.getBasicCost();

        Tuition t;
        acadFee = t.getAcadFee();

        Intl i;
        intlFee = i.getTotalIntl();
    }


};
#endif //CPT113_ASSIGNMENT_TOTALFEE_H