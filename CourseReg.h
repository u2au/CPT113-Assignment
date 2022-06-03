//
// Created by rinsuki on 03/06/2022.
//

#ifndef TUITION_CPP_COURSEREG_H
#define TUITION_CPP_COURSEREG_H

class CourseReg {
private:
    short input;

public:
    // Default Constructor
    CourseReg() {
        input = -1;
    }

    // Overloading Constructor
    CourseReg(short init) {
        input = init;
        menu();
    }

    // Prototype
    void menu();
    void inputValidation();

};


#endif //TUITION_CPP_COURSEREG_H
