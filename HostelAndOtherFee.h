//HostelFee
#ifndef HOSTEL_FEE
#define HOSTEL_FEE
#include "Student.h"
#include "MealAndTransportation.h"

class HostelAndOtherFee : public Student {
    private:
    //int month;从student里来
       double hostelFee;
       static double otherFees;
       double total;

    public:
    // Default Constructor
        HostelAndOtherFee() : Student()
        {
            hostelFee = 0.0;
            otherFees = 0.0;
            total = 0.0;

        }

    // Set hostelFee
    void setHostelFee();

    // Friend function
    friend void MealAndTransportation::addToOtherFee(double, HostelAndOtherFee&);

    // 在totalFee class里叫这个
    double getTotalFee(){
        total = hostelFee + otherFees;
        return total;
    }


};

#endif
