#include <iostream>
#include <string>

using namespace std;

int main() {
    //CGPA Calculator
    cout << "welcome to CGPA calculator !" << endl;
    cout << "Are you a freshman? (1 for yes, 0 for no)" << endl;
    int freshman;
    cin >> freshman;
    if (freshman == 1) {
        cout << "How many courses have you enrolled this semester?" << endl;
        int num;
        cin >> num;
        //Dynamically allocate memory
        string* gpa = new string[num];
        double* credit = new double[num];
        string* course = new string[num];
        double total_credit = 0;
        for (int i = 0; i < num; i++) {
            cout << "Please enter the your grade of course " << i + 1 << ": " << endl;
            cin >> gpa[i];
            cout << "Please enter the credit of course " << i + 1 << ": " << endl;
            cin >> credit[i];
            total_credit += credit[i];
        }

        //º∆À„CGPA
        double sum = 0;
        for (int i = 0; i < num; i++) {
            if (gpa[i] == "A") {
                sum += 4 * credit[i];
            }
            else if (gpa[i] == "A-") {
                sum += 3.7 * credit[i];
            }
            else if (gpa[i] == "B+") {
                sum += 3.3 * credit[i];
            }
            else if (gpa[i] == "B") {
                sum += 3 * credit[i];
            }
            else if (gpa[i] == "B-") {
                sum += 2.7 * credit[i];
            }
            else if (gpa[i] == "C+") {
                sum += 2.3 * credit[i];
            }
            else if (gpa[i] == "C") {
                sum += 2 * credit[i];
            }
            else if (gpa[i] == "C-") {
                sum += 1.7 * credit[i];
            }
            else if (gpa[i] == "D+") {
                sum += 1.3 * credit[i];
            }
            else if (gpa[i] == "D") {
                sum += 1 * credit[i];
            }
            else if (gpa[i] == "F") {
                sum += 0 * credit[i];
            }
        }

        //cout this semester CGPA
        cout << "Your CGPA is " << sum / total_credit << endl;
    }

    else if (freshman == 0) {
        cout << "How many courses have you enrolled this semester?" << endl;
        int num;
        cin >> num;

        string* gpa = new string[num];
        double* credit = new double[num];
        string* course = new string[num];


        //Dynamically allocate memory

        double total_credit = 0;

        for (int i = 0; i < num; i++) {
            cout << "Please enter the your grade of course " << i + 1 << ": " << endl;
            cin >> gpa[i];
            cout << "Please enter the credit of course " << i + 1 << ": " << endl;
            cin >> credit[i];
            total_credit += credit[i];
        }

        //cal CGPA
        double sum = 0;
        for (int i = 0; i < num; i++) {
            if (gpa[i] == "A") {
                sum += 4 * credit[i];
            }
            else if (gpa[i] == "A-") {
                sum += 3.7 * credit[i];
            }
            else if (gpa[i] == "B+") {
                sum += 3.3 * credit[i];
            }
            else if (gpa[i] == "B") {
                sum += 3 * credit[i];
            }
            else if (gpa[i] == "B-") {
                sum += 2.7 * credit[i];
            }
            else if (gpa[i] == "C+") {
                sum += 2.3 * credit[i];
            }
            else if (gpa[i] == "C") {
                sum += 2 * credit[i];
            }
            else if (gpa[i] == "C-") {
                sum += 1.7 * credit[i];
            }
            else if (gpa[i] == "D+") {
                sum += 1.3 * credit[i];
            }
            else if (gpa[i] == "D") {
                sum += 1 * credit[i];
            }
            else if (gpa[i] == "F") {
                sum += 0 * credit[i];
            }

        }
        cout << "plz enter the previous semesters credit" << endl;
        double pre_credit;
        cin >> pre_credit;
        cout << "plz enter the previous semesters CGPA" << endl;
        double pre_gpa;
        cin >> pre_gpa;

        sum = sum + pre_credit * pre_gpa;
        total_credit = total_credit + pre_credit;   //cal CGPA 
        
        //print total CGPA
        cout << "Your CGPA is " << sum / total_credit << endl;

    }

    else {
    cout << "invalid input! " << endl; //input validation
    }

    return 0;
}


