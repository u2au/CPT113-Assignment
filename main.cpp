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
    //结合student看下sem咋读，，，，，，，速度速度5555555555555
    double totalTuitionFee=0.0;
    double totalHostelFee=0.0;
    double totalIntl=0.0;
    double totalFeeTotalSem=0.0;

    Student example[sem];//object array
    for(int i=0;i<sem;i++)
    {
        example[0]=example[0]+example[i];

    }
    
    //get each term (HostelPerSem, tuitionPerSem and intlFee) of all sems 
    totalHostelFee=example[0].gethostelPerSem();
    totalTuitionFee=example[0].getTuitionPerSem();
    totalIntl=example[0].getIntlFee();

    //getTotalFee for all sem
    totalFeeTotalSem=example[0].getTotalFees();

    cout<<"学生姓名,matric number ";
    cout<<"The total tuition fee of all semester is: "<<totalTuitionFee<<endl;
    cout<<"The total hostel fee of all semester is: "<<totalHostelFee<<endl;
    cout<<"The total international fee of all semester is: "<<totalIntl<<endl;
    cout<<"The total fee of all semester is: "<<totalFeeTotalSem<<endl;
    

        

    


    return 0;
}
