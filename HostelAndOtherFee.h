//HostelFee
#ifndef HOSTEL_FEE
#define HOSTEL_FEE
#include "Student.h"
#include "MealAndTransportation.h"

class HostelAndOtherFee : public Student {
    private:
       double hostelFee,
              otherFees,
              total;

    public:
    // Default Constructor
        HostelAndOtherFee() : Student()
        {
            hostelFee = 0.0;
            otherFees = 0.0;
            total = 0.0;
        }

        // Mutator
        void setHostelFee();

        // Friend function
        friend void MealAndTransportation::addToOtherFee(double, HostelAndOtherFee&);



        // Accessor
        double getTotalFee(){
            total = hostelFee + otherFees;
            return total;
        }



};

#endif
