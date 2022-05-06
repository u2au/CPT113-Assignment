//HostelFee
#ifndef HOSTEL_FEE
#define HOSTEL_FEE
#include"Student.h"//to use month in student class
#include"MealAndTransportation.h"
class HostelAndOtherFee:public Student{
    private:
        //int month;从student里来
        double hostelFee;
       static double otherFees;

    public:
    //default constructor
        HostelAndOtherFee():Student()
        {
            hostelFee=0.0;
            otherFees=0.0;
        }
    //cal hostelFee
     double calcHostelFee(int);
     //friend function
     friend void MealAndTransportation::addToOtherFee(double,HostelAndOtherFee&);



};

#endif
