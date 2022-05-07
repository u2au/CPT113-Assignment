//tuition fee and insurance fee header file
#ifndef TAI_H
#define TAI_H

class TuitionAndInsuranceFee{
    private:
        //int sem;//用student里的sem
        int majorNum;
        double tuitionFee;
        double insuranceFee;
        int levelOfInsurance;
        double total;
    public:
    //default constructor
         TuitionAndInsuranceFee(){
             majorNum=0;
             tuitionFee=0.0;
             levelOfInsurance=0;
             insuranceFee=0.0;
             total=0.0;
         }
       
         //calc insurance fee
         void calcInsuranceFee(int);
         //calc tuition fee
         void calcTuitionPerSem(int);//parameter里de具体看cpp

         
         double getTotal(){
             total=tuitionFee+insuranceFee;
             return total;
         }
         
};
#endif



