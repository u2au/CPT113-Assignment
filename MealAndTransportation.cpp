//MealAndTransportation cpp
#include"MealAndTransportation.h"
#include"HostelAndOtherFee.h"
//meal plan&meal fee
double MealAndTransportation::calcMealFee(int mp) {
    switch (mp)
    {
        case 1:
            mealFee = 15;
            break;

        case 2:
            mealFee = 20;
            break;

        case 3:
            mealFee = 25;
            break;

        case 4:
            mealFee = 30;
            break;

        case 5:
            mealFee = 35;
            break;

        default:
            mealFee = 0;
            break;

    }

    return mealFee;
};
//transportationFee
double  MealAndTransportation::calcTransportationFee(bool isTransportation){
    const double monthlyBusFee=30;
    if(isTransportation){
        return transportationFee;
    }

}
//add meal fee and transportationFee to otherFees in HostelFee class
void  MealAndTransportation::addToOtherFee(double totalfee,HostelAndOtherFee&OF){
    OF.otherFees+=totalfee;

 }


