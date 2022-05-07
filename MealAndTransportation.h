#ifndef MAT_H
#define MAT_H

#include "Student.h"

class HostelAndOtherFee;// Forward declaration of HostelFee class

class MealAndTransportation {

    private:
        Student s; // Composition of class Student
        int mealPlan = s.getMealPlan();

        double mealFee = 0,
                transportationFee = 0,
                total = 0;

        bool isTransportation;

    public:
        // Default constructor
        MealAndTransportation() {
            calcMealFee(mealPlan);
//            calcTransportationFee(isTransportation);
//            addToOtherFee();
        }

        // Prototype
        double calcMealFee(int);
        double calcTransportationFee(bool);
        void addToOtherFee(double, HostelAndOtherFee&); // a friend function of HostelFee class

};
#endif