//tuition fee and insurance fee
#include"TuitionAndInsuranceFee.h"
void TuitionAndInsuranceFee::calcInsuranceFee(int insuranceLevel) {
    switch (insuranceLevel)
    {
        case 1:
            insuranceFee = 1000;
            break;

        case 2:
            insuranceFee = 2000;
            break;

        case 3:
            insuranceFee = 5000;
            break;

        case 4:
            insuranceFee = 8000;
            break;

        case 5:
            insuranceFee = 10000;
            break;

        default:
            insuranceFee = 0;
            break;

    }

   
}
void TuitionAndInsuranceFee::calcTuitionPerSem(int numOfMajor){

    //学费也是一个switch，然后不同专业代号读不同学费
   

}