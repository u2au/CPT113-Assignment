#include "Outputfile.h"
#include "Tuition.h"

#include <iostream>

//output the tuition, NonRecurrent, Recurrent fee to the file
void outputfile::output() {
    ofstream file;
    file.open("./output.txt");
    if (file.is_open()) {
        file << "Tuition: " << t.getTuition() << endl;
        file << "NonRecurrentFee: " << t.getNonRecurrentFee() << endl;
        file << "RecurrentFee: " << t.getRecurrentFee() << endl;
    }
    else {
        cout << "Unable to open file\n";
    }
    file.close();
}
