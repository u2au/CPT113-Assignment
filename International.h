
#ifndef INTERNATIONAL_H
#define INTERNATIONAL_H
#include "TuitionAndInsuranceFee.h"


class International {
private:
    double visaFee;
    double totalQuarantineFee;
    const double quarantinePerDay=150.0;
    int quarantineDays;  // totalQuarantineFee = quarantinePerDay *days<---这儿改成按天数计费
    double internationalTAndI;
    double totalInternational;

    bool isFullyVaccinated;

    TuitionAndInsuranceFee TAndIFee;//composition of tuitionAndInsuranceFee 

    
    
public:
     //default constructor
    International()
    {
        visaFee=0.0;
        totalQuarantineFee=0.0;
        quarantineDays=0;
        internationalTAndI=0.0;
        totalInternational=0.0;
    }

    //constructor 1： 别删，，这个显示composition的特性，，
    International(double visa,double quarantine,int days,double interFee,double total, double tuition,double insurance)
    {
        visaFee=visa;
        totalQuarantineFee=quarantine;
        quarantineDays=days;
        internationalTAndI=interFee;
        totalInternational=total;
    }

    //use composition to set internationalTAndI
    void setInternationalTAndI(double tuition,double insurance)
    {
       TuitionAndInsuranceFee TAndIFee(tuition,insurance);
       internationalTAndI=TAndIFee.getTotal();
    }

    double getInternationalTAndI()const
    {
        return internationalTAndI;
    }

    double getVisaFee();
    
    double getQuarantineFee(int daysQuarantine);//daysQuarantine 让user input还是读文件？
    
    double getTotalInternationalFee()const
    {
        return visaFee+totalQuarantineFee+(internationalTAndI*5);

    }

};


#endif 
