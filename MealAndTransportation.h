#ifndef MAT_H
#define MAT_H
class HostelAndOtherFee;//forward declaration of HostelFee class

class MealAndTransportation{
    private:
        int mealPlan;
        double mealFee;
        bool isTransportation;
        double transportationFee;
        double total;
    public:
        //default constructor
        MealAndTransportation(){
            mealPlan =0;
            mealFee = 0.0;
            transportationFee = 0.0;
            total = 0.0;
        }
        //cal meal fee
         double calcMealFee(int);
         //calc transportationFee
         double calcTransportationFee(bool);
         void addToOtherFee(double,HostelAndOtherFee&);//a friend function of HostelFee class

};
#endif