//tuition fee and insurance fee header file
#ifndef TAI_H
#define TAI_H
#include"Student.h"
class TuitionAndInsuranceFee: public Student{
    private:
        int sem;//用student里的sem
        double tuitionFee;
        double insuranceFee;
        double total;
    public:
         TuitionAndInsuranceFee(){
             tuitionFee=0.0;
             insuranceFee=0.0;
             total=0.0;
         }
         TuitionAndInsuranceFee(double t,double i){
             tuitionFee=t;
             insuranceFee=i;
             
         }
         
        
         double getTuitionFee()const{
             return tuitionFee;
         }
         double getInsuranceFee()const{
             return insuranceFee;
         }
         double getTotal(){
             total=tuitionFee+insuranceFee;
             return total;
         }
         
};
#endif



