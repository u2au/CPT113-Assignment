/*totalFee function is used to calculate to total fee from Desa class, tuition class and intl(international) class,
this class use compo
 the operator overloading func in this class will be called in student class,
 */

#ifndef CPT113_ASSIGNMENT_TOTALFEE_H
#define CPT113_ASSIGNMENT_TOTALFEE_H


class TotalFee {
private:


    double basicCost, // class Desa
           acadFee, //  class Tuition
           intlFee, // class Intl
           totalFee; // 非常坏 double eneennenenenen

public:
    // Default Constructor
    TotalFee() {
         basicCost = 0.0, 
           acadFee = 0.0, 
           intlFee = 0.0, 
           totalFee = 0.0;
    }

    // Overloading Constructor
    TotalFee(int) {
        
    }

    //mutator to set tuition fee 
    void setTuiFee(double tt) {
        tt=acadFee;
    }
     //mutator to set internation fee 
    void setInternlFee(double intln) {
        intlFee = intln;
    }
     //mutator to set desa fee 
    void setDsaFee(double dsa) {
        basicCost= dsa;
    }

    //operator overloading
    TotalFee operator+(const TotalFee&obj) {
        TotalFee temp;
        temp.basicCost=basicCost+obj.basicCost;
        temp.intlFee=intlFee+obj.intlFee;
        temp.acadFee=acadFee+obj.acadFee;

        return temp;
    }

    //accessor ,用operator overloading function在studnet class里将三个obj的相加，我们可以用这个来get 总共的费用
    double getTotal() {
        totalFee=basicCost+acadFee+intlFee;
        return totalFee;
    }


};
#endif //CPT113_ASSIGNMENT_TOTALFEE_H