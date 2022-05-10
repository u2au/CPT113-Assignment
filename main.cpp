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
    

    Student example[sem];//object array
    for(int i=0;i<sem;i++)
    {
        example[0]=example[0]+example[i];

    }
    
    cout<<"学生姓名,matric number ";
    //get each term (HostelPerSem, tuitionPerSem and intlFee) of all sems 
    cout<<"The total tuition fee of all semester is: "<<example[0].getTuitionPerSem()<<endl;
    cout<<"The total hostel fee of all semester is: "<<example[0].gethostelPerSem()<<endl;
    cout<<"The total international fee of all semester is: "<<example[0].getIntlFee()<<endl;
    //getTotalFee for all sem
    cout<<"The total fee of all semester is: "<<example[0].getTotalFees()<<endl;
    

        

    


    return 0;
}
