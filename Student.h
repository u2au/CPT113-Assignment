//
// Created by rinsuki on 29/04/2022.
//

#ifndef CPT113_ASSIGNMENT_STUDENT_H
#define CPT113_ASSIGNMENT_STUDENT_H

class Student {
protected:
    //这三个新加的oo要用
    double matricNum = 111111,
           HostelPerSem,
           tuitionPerSem;

    // Fee Related
    double insuranceFee,
           totalTIFee,
           intlFee,
           totalFees;

    int hostelType = 0,
        insuranceLevel = 0,
        mealPlan = 0,
        sem = 0;

    bool isFreshman,
         isInternational,
         isFullyVaccinated;


public:
    // Default Constructor
    Student();

    // Prototype
    bool getIntl() const;
    bool getVacStat() const;
//    int getSem() const;
    int getMealPlan() const;
//    int getInsuranceLevel() const;
//    int getCourseNum() const;

    void readFile(); // Read From File
    void inputValidation();
//    void Display();
//    void outputData();
//    double calcTotalFee();

//    HostelAndOtherFee::HostelAndOtherFee();



    // Operator overloading
    Student operator+(const Student&object)
    {
        Student temp;
        temp.HostelPerSem = HostelPerSem + object.HostelPerSem;
        temp.tuitionPerSem = tuitionPerSem + object.tuitionPerSem;
        temp.intlFee = intlFee + object.intlFee;
        return temp;
    }


    // Accessor functions
    double gethostelPerSem() const
    {
        return HostelPerSem;
    }

    double getTuitionPerSem() const
    {
         return tuitionPerSem;
    }

    double getIntlFee() const
    {
        return intlFee;
    }

    double getTotalFees()
    {
        totalFees = HostelPerSem + tuitionPerSem + intlFee;
        return totalFees;
    }
    


};


#endif //CPT113_ASSIGNMENT_STUDENT_H
