// Header File of Tuition fee and Insurance fee
#ifndef TAI_H
#define TAI_H

class TuitionAndInsuranceFee{
    private:
        //int sem; //用student里的sem
        int majorNum;
        double tuitionFee;
        double insuranceFee;
        int levelOfInsurance;
        double total;

    public:
         // Default constructor: Initialization
         TuitionAndInsuranceFee(){
             majorNum = 0;
             tuitionFee = 0.0;
             levelOfInsurance = 0;
             insuranceFee = 0.0;
             total = 0.0;
         }

         // Prototype
         void calcInsuranceFee(int);
         void calcTuitionPerSem(int); //parameter里de具体看cpp

         // Get Total Fees
         double getTotal(){
             total = tuitionFee + insuranceFee;
             return total;
         }
         
};
#endif



