/*
/
*/

#ifndef CPT113_ASSIGNMENT_STUDENT_H
#define CPT113_ASSIGNMENT_STUDENT_H
#include"Desa.h"
#include"Tuition.h"
#include"Intl.h"
#include"TotalFee.h"

#include "Student.cpp"
#include "Desa.cpp"
#include "Intl.cpp"
#include "Tuition.cpp"
#include "Output.cpp"

#include <iostream>

using namespace std;

class Student{
protected:
    int matricNum = 111111,
        desa = 0,
        insuranceLevel = 0,
        parkingTimes = 0;

    double desaFee = 0.0;

    double getDF,getTTF,getIntlF;// get perspective total fee from desa class,intl class and tuition class

    bool isInt = true,
         isFullyVaccinated = false,
         isFreshman = true;

    TotalFee f1,f2,f3,f;//use compoaition and operator overloading 


public:
    // Default Constructor
    Student() {}


    // Overloading Constructor
    Student(bool) {

    }

    ~Student() {
        cout << "Destructor is called" << endl;
    }


    // Prototype
    void setValue(int);

    // Inline Functions
    int whichDesa() const {return desa;}
    bool checkInt() const {return isInt;}
    bool checkFreshman() const {return isFreshman;}
    int getInsuranceLevel() const {return insuranceLevel;}
    int getParkingTimes() const {return parkingTimes;}

    //mutatot to getDF,getTTF,getIntlF
    void setFEES(){
         Desa d;
        getDF = d.getBasicCost();

        Tuition t;
        getTTF = t.getAcadFee();

        Intl i;
        getIntlF = i.getIntlTotal();
    }

    //pass getDF,getTTF,getIntlF to totalFee class
    void calcTTFEE(double getDF,double getTTF,double getIntlF) {
        f1.setTuiFee(getTTF);
        f2.setInternlFee(getIntlF);
        f3.setDsaFee(getDF);
        f2=f2+f3;
        f1=f1+f2;
        cout<<"the total fee is "<<f1.getTotal()<<endl;

        
    }


















    //operator overloading
    void setFeesToAllClass() {
        

    }






















};


#endif //CPT113_ASSIGNMENT_STUDENT_H
