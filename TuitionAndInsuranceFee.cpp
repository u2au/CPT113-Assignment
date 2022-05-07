//tuition fee and insurance fee
#include"TuitionAndInsuranceFee.h"
double TuitionAndInsuranceFee::calcInsuranceFee() {

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

    return insuranceFee;
   
}

double TuitionAndInsuranceFee::calcTuitionPerSem(){

    // 学费也是一个switch，然后不同专业代号读不同学费
    // 暂时按照 cs 的来，其他专业后弄
    if (isInternational) tuitionFee = 12910;
    else tuitionFee = 1320;

    return tuitionFee;

}

double TuitionAndInsuranceFee::getTotalTI() {
    total = tuitionFee + insuranceFee;

    return total;

}
