//
// Created by rinsuki on 11/05/2022.
//

#include "Output.h"
#include "Tuition.h"

#include <iostream>
#include <fstream>

double calcNecCost() {
    Tuition t;
    t.displayTuition();
    return (t.getTuition() + t.getExtraFee());
}

double Output::getNecCost() {
    necCost = calcNecCost();

    // Display necessary costs
    cout << "Necessary Costs: " << necCost << endl;
    return necCost;
}

//// Output the tuition, NonRecurrent, Recurrent fee to the file
//void Output::outputFile() {
//    ofstream file;
//    file.open("./Output.txt");
//
//    if (file.is_open()) {
//        file << "Tuition: " << t.getTuition() << endl;
//        file << "NonRecurrentFee: " << t.getNonRecurrentFee() << endl;
//        file << "RecurrentFee: " << t.getRecurrentFee() << endl;
//    }
//    else {
//        cout << "Unable to open file\n";
//    }
//
//    file.close();
//}