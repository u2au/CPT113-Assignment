// International.h, composition of class Student
#ifndef INTERNATIONAL_H
#define INTERNATIONAL_H

#include "TuitionAndInsuranceFee.h"
#include "Student.h"

class International {
private:
    Student s; // Composition
    double visaFee = 0,
           totalQuarantineFee = 0,
           totalIntl = 0;

    const double quarantinePerDay = 150.0;

    int quarantineDays = 5;

    bool isIntl = s.getIntl(),
         isFullyVaccinated = s.getVacStat(); // Get Vaccination Status

    
public:
    // Default constructor
    International() {
        if (isIntl)
        {
            getVisaFee();
            getQuarantineFee();
            getTotalIntlFee();
        }
    }

//    // Constructor 1：别删，，这个显示composition的特性，，
//    International(double visa, double quarantine, int days, double intlFee, double total, int numInsurance, int numMajor)
//    {
//        visaFee = visa;
//        totalQuarantineFee = quarantine;
//        quarantineDays = days;
//        intlTAndI = intlFee;
//        totalIntl = total;
//    }

//    // Use composition to set intlTAndI
//    void setIntlTAndI(int numInsurance, int numMajor)
//    {
//      //这里用fstream读insurance num 和 major num，还是用户手动输入？
//      //这两个应该在student里说实话，，等下改
//        TAndIFee.calcInsuranceFee(numInsurance);
//        TAndIFee.calcTuitionPerSem(numMajor);
//
//       intlTAndI = TAndIFee.getTotal();
//    }

    // Prototype
    double getVisaFee();
    double getQuarantineFee();
    double getTotalIntlFee();

};


#endif 
