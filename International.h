
#ifndef INTERNATIONAL_H
#define INTERNATIONAL_H
#include "TuitionAndInsuranceFee.h"
#include"Student.h"//用student里的semster

class International {
private:
    double visaFee,
           totalQuarantineFee,
           internationalTAndI,
           totalInternational;

    const double quarantinePerDay = 150.0;

    int quarantineDays = 5;
    bool isFullyVaccinated;

    TuitionAndInsuranceFee TAndIFee; // Composition of tuitionAndInsuranceFee

    
public:
    // Default constructor
    International();

    // Constructor 1： 别删，，这个显示composition的特性，，
    International(double visa, double quarantine,int days, double interFee, double total, int numInsurance, int numMajor)
    {
        visaFee = visa;
        totalQuarantineFee = quarantine;
        quarantineDays = days;
        internationalTAndI = interFee;
        totalInternational = total;
    }

    // Use composition to set internationalTAndI
    void setInternationalTAndI(int numInsurance, int numMajor)
    {
      //这里用fstream读insurance num 和 major num，还是用户手动输入？
      //这两个应该在student里说实话，，等下改
        TAndIFee.calcInsuranceFee(numInsurance);
        TAndIFee.calcTuitionPerSem(numMajor);

       internationalTAndI=TAndIFee.getTotal();
    }

    double getInternationalTAndI() const {
        return internationalTAndI;
    }

    void setVisaFee();
    void setQuarantineFee(int daysQuarantine);//daysQuarantine 让user input还是读文件？


//以下两个function都要被叫到！
    double getQuarantineFee() const //这个只在totalFee class里叫一次
    {
        return totalQuarantineFee;
    }
    
    double getTotalInternationalFee() const //这个在 totalFee class里用int semster num当array num来叫
    {
        return visaFee+(internationalTAndI*5);

    }

};


#endif 
