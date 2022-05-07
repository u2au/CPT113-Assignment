
#ifndef INTERNATIONAL_H
#define INTERNATIONAL_H
#include "TuitionAndInsuranceFee.h"
#include"Student.h"//用student里的semster

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
    International(double visa,double quarantine,int days,double interFee,double total, int numInsurance,int numMajor)
    {
        visaFee=visa;
        totalQuarantineFee=quarantine;
        quarantineDays=days;
        internationalTAndI=interFee;
        totalInternational=total;
    }

    //use composition to set internationalTAndI
    void setInternationalTAndI(int numInsurance,int numMajor)
    {
      //这里用fstream读insurance num 和 major num，还是用户手动输入？
      //这两个应该在student里说实话，，等下改
        TAndIFee.calcInsuranceFee(numInsurance);
        TAndIFee.calcTuitionPerSem(numMajor);

       internationalTAndI=TAndIFee.getTotal();
    }

    double getInternationalTAndI()const
    {
        return internationalTAndI;
    }

    void setVisaFee();
    
    void setQuarantineFee(int daysQuarantine);//daysQuarantine 让user input还是读文件？


//以下两个function都要被叫到！
    double getQuarantineFee()const//这个只在totalFee class里叫一次
    {
        return totalQuarantineFee;
    }
    
    double getTotalInternationalFee()const//这个在 totalFee class里用int semster num当array num来叫
    {
        return visaFee+(internationalTAndI*5);

    }

};


#endif 
