/*created by Lxt

#ifndef CPT113_ASSIGNMENT_OUTPUTFILE_H
#define CPT113_ASSIGNMENT_OUTPUTFILE_H


#include "Tuition.h"
#include <fstream>


//将tuition，nonRecurrentFee，recurrentFee三个数据输出文件
class outputfile {
private:
    Tuition &Tuition;
    double &nonRecurrentFee;
    double &recurrentFee;

public:
    outputfile(Tuition &t, double &nonRecurrentFee, double &recurrentFee);
    void output();
}
*/