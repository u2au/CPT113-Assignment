//
// Created by rinsuki on 29/04/2022.
//

#include <iostream>
#include "Student.h"

using namespace std;

int main() {
    // Variable Definition
    int sem;
    double totalTuitionFee = 0.0,
           totalHostelFee = 0.0,
           totalIntl = 0.0,
           totalFeeTotalSem = 0.0;

    // Start to calculate
    Student();

    Student example[sem]; // Object Array

    for (int i = 0; i < sem; i++) example[0] = example[0] + example[i];
    
    // Get each term (HostelPerSem, tuitionPerSem and intlFee) of all semesters
    totalHostelFee = example[0].gethostelPerSem();
    totalTuitionFee = example[0].getTuitionPerSem();
    totalIntl = example[0].getIntlFee();

    // getTotalFee for all sem
    totalFeeTotalSem = example[0].getTotalFees();

    cout << "Matric number: " << endl;
    cout << "The total tuition fee and insurance fee of all semester is: " << totalTuitionFee << endl;
    cout << "The total hostel fee of all semester is: " << totalHostelFee << endl;
    cout << "The total international fee of all semester is: " << totalIntl << endl;
    cout << "The total fee of all semester is: " << totalFeeTotalSem << endl;

    return 0;
}
