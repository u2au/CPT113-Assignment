// Header File of Tuition fee and Insurance fee
#ifndef TAI_H
#define TAI_H

#include "Student.h"

class TuitionAndInsuranceFee: public Student{

    private:
         Student st;// composition
       
        int majorNum =st.getCourseNum();
        int insuranceLevel=st.getInsuranceLevel();

        double tuitionFee = 0.0,
               insuranceFee = 0.0,
               total = 0.0;

       

    public:
         // Default constructor: Initialization
         TuitionAndInsuranceFee() {
             calcTuitionPerSem(majorNum);
             calcInsuranceFee(insuranceLevel);
             getTotalTI();
         }

         // Prototype
         double calcTuitionPerSem(int);
         double calcInsuranceFee(int);

         // Get Total Fees of tuition fees and insurance fees
         double getTotalTI();
         
};
#endif



