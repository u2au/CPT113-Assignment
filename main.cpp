//
// Created by rinsuki on 29/04/2022.
//
#include <iostream>
#include "Student.h"

using namespace std;
/*main 里输入：1.matric number
              2.year num和sem num
              */
int main() {
    int sem;
    //sem 咋来？
    double totalTuitionFee=0.0;
    double totalHostFee=0.0;
    double totalIntl=0.0;
    double totalFeeTotalSem=0.0;

    Student example[sem];//object array
    for(int i=0;i<sem;i++)
    {
        example[0]=example[0]+example[i];

    }
    
    //get each term (HostelPerSem, tuitionPerSem and intlFee) of all sems 
    totalHostFee=example[0].gethostelPerSem();
    totalTuitionFee=example[0].getTuitionPerSem();
    totalIntl=example[0].getIntlFee();

    //getTotalFee for all sem
    totalFeeTotalSem=example[0].getTotalFees();

    cout<<"";
        

    


    return 0;
}
