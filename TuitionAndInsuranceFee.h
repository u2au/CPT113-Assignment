//tuition fee and insurance fee header file
#ifndef TAI_H
#define TAI_H
class TuitionAndInsuranceFee{
    private:
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
         void setTuitionFee(double t){
             tuitionFee=t;

         }
         void setInsuranceFee(double i){
             insuranceFee=i;
         }
         double getTuitionFee()const{
             return tuitionFee;
         }
         double getInsuranceFee()const{
             return insuranceFee;
         }
         double getTotal()const{
             return tuitionFee+insuranceFee;
         }
         
};
#endif



