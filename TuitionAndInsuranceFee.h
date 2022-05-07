// Header File of Tuition fee and Insurance fee
#ifndef TAI_H
#define TAI_H

#include "Student.h"

class TuitionAndInsuranceFee : public Student {

    private:
        //int sem; //用student里的sem
        int majorNum = 0;

        double tuitionFee = 0,
               insuranceFee = 0,
               total = 0;

    public:
         // Default constructor: Initialization
         TuitionAndInsuranceFee() {
             calcTuitionPerSem();
             calcInsuranceFee();
             getTotalTI();
         }

         // Prototype
         double calcTuitionPerSem();
         double calcInsuranceFee();

         // Get Total Fees of tuition fees and insurance fees
         double getTotalTI();
         
};
#endif



