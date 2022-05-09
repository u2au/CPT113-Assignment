//
// Created by rinsuki on 29/04/2022.
//

#ifndef CPT113_ASSIGNMENT_STUDENT_H
#define CPT113_ASSIGNMENT_STUDENT_H
//student class 是 base class
//student class 要有year num和sem num，是从文件读还是用户输入？
// r: 从文件读取，若有异常值则通过 inputValidation 要求用户 correct the data
class Student {
private:
    double matricNum = 111111,
        //这三个新加的oo要用
           HostelPerSem, 
           tuitionPerSem,
           intlFee,
           totalFees;
           
    int hostelType = 0,
        insuranceLevel = 0,
        mealPlan = 0,
        sem = 0,
        courseNum=0;

protected:
    

    bool isFreshman,
         isInternational,
         isFullyVaccinated;


public:
    // Default Constructor
    Student();

    bool getIntl() const;
    bool getVacStat() const;

    // Prototype
    int getSem() const;
    int getMealPlan() const;

    int getInsuranceLevel()const;
    int getCourseNum()const;

    void readFile(); // Read From File
    void inputValidation();

//    void Display();
//    void outputData();

    double calcTotalFee();

    //operator overloaded
    Student operator+(const Student&object)
    {
        Student temp;
        temp.HostelPerSem=HostelPerSem+object.HostelPerSem;
        temp.tuitionPerSem=tuitionPerSem+object.tuitionPerSem;
        temp.intlFee=intlFee+object.intlFee;
        return temp;
    }


    //accessor function
    double gethostelPerSem()const
    {
        return HostelPerSem;
    }

    double getTuitionPerSem()const
    {
         return tuitionPerSem;
    }

    double getIntlFee()const
    {
        return intlFee;
    }

    double getTotalFees()
    {
        totalFees=HostelPerSem+tuitionPerSem+intlFee;
        return totalFees;
    }
    


};


#endif //CPT113_ASSIGNMENT_STUDENT_H
