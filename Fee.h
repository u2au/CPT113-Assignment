//
// Created by rinsuki on 29/04/2022.
//

#ifndef CPT113_ASSIGNMENT_FEE_H
#define CPT113_ASSIGNMENT_FEE_H

#include "Student.h"
/*fee 分开，拆成:5个class，
    1：hostelAndOtherFee，hostel：住宿类型和水电费 ；other：见4
        （done）2：学费和保险，          
        （90%done，缺隔离天数input方式）3：international，学费和保险当composition（国际生翻几倍），然后额外加visaFee和隔离费
    4. MealAndTransportationFee，给1当friend function，费用记到1的totalFee里

    5.totalFee，是student class 的dervied class。
        *用operator+ overloaded function来算总共fee。
    totalFee里用student class里的一些数据（year num，sem num），
    得到totalSemNum: (y1s1=1,y1s2=2,y2s1=2+1,y2s2=2X2,y3s1=2x2+1,y3s2=2X3,y4s1=2x3+1,y4s2=2X4)
   
    exp. student class做object array：
        student hana【totalSemNum】；
        用operator + overloaded function来计算总费用

*/
class Fee : public Student {
private:
    double hostelFee,
           tuitionPerSem,
           recurrent, nonRecurrent,
           insuranceFee,
           mealFee;

public:
    Fee(); // Default Constructor

    // Prototype
    double calcHostelFee();
    double calcTuitionPerSem();
    double calcInsuranceFee();
    double calcMealFee();

    bool getVaccinationStatus();
    bool checkIntl();



};


#endif //CPT113_ASSIGNMENT_FEE_H
