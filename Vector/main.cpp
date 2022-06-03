#if 1
#include <iostream>
#include<string.h>
#include <windows.h>
#include <vector>
#include<algorithm>
#include <string>
using namespace std;
using std::vector;
int Menu();
void cinfo();
void cprintorget();
void sinfo();
void sprintorget();
char password[16] = "1234";

class info//Information class
{
protected:
    long number;//Number of each course
    string name;//course name
public:
    info() {}
    info(long num, string name) :number(num), name(name) {}
};

class course : public info
{
protected:
    int credit;
    string teachername;//Lecturer's name
public:
    course() {}
    course(long num, string name, int cre, string tea) : info(num, name)
    {
        credit = cre;
        teachername = tea;
    }
    course(const course& c1)
    {
        number = c1.number;
        name = c1.name;
        credit = c1.credit;
        teachername = c1.teachername;
    }
    static void print();//output data
    static void get();//get data
    static void add();//add data
    static void del();//del data
    static void edit();//modify data
    static int ishave(long si);//query function
    friend class student;
};
vector<course> c;

class student : public info//student class
{

protected:
    string sex;
    string grade;
    long scredit;
public:
    vector<course> havec;//Query student course selection information
    student() {}
    student(long num, string name, string se, string gra, long scr) : info(num, name)
    {
        sex = se;
        grade = gra;
        scredit = scr;
    }
    static void print();//output data
    static void get();//get data
    static void add();//add data
    static void del();//del data
    static void edit();//modify data
    static int ishave(long si);//Check if the student exists
    static void addcourse();// Add courses for students
    static void delcourse();//Delete a course for a student
    static int ishavec(long si);//Check if the student has the course
};
vector<student> s;


void course::print()//print all course information
{
    system("cls");

    for (int i = 0; i < c.size(); i++)
    {
        cout << endl << "Course No.：" << c[i].number << "   Course Title：" << c[i].name << "   course credit：" \
			<< c[i].credit << "   Lecturer's name：" << c[i].teachername << endl;
    }

    cprintorget();
}

void course::get()//Get course information
{
    system("cls");
    long k = 1, kk;

    cout << "        Please enter the course No. to be inquired:      " << endl;
    cin >> kk;
    if (ishave(kk))
    {
        for (size_t i = 0; i < c.size(); i++)
            if (c[i].number == kk)
            {
                cout << endl << "Course No.：" << c[i].number << "   Course Title：" << c[i].name << "  course credit：" \
					<< c[i].credit << "   Lecturer's name：" << c[i].teachername << endl;
                break;
            }
    }
    else
    {
        cout << "              The course was not found .           " << endl;
    }
    cprintorget();
}

void course::add()
{
    system("cls");
    long k = 1; course c1;
    cout << "       Please enter the course No. to add：      " << endl;
    cin >> c1.number;
    while (ishave(c1.number))
    {

        system("cls");
        cout << "┃      The class has been added, please re-enter:      ┃" << endl;
        cout << "┃             (press 0 to exit)             ┃" << endl;
        cin >> k;
        if (k == 0)
        {
            cinfo();
            break;
        }
        else c1.number = k;

    }
    if (k != 0)
    {
        cout << "           Please enter the Course Title :          " << endl;
        cin >> c1.name;
        cout << "           Please enter course credit：           " << endl;
        cin >> c1.credit;
        cout << "          Please enter the instructor name:         " << endl;
        cin >> c1.teachername;
        system("cls");
        c.push_back(c1);
        cinfo();
    }
}

void course::del()//Teacher deletes course information
{
    system("cls");
    long k = 1, kk;
    cout << "        Please enter the course number to delete：       " << endl;
    cin >> kk;
    if (ishave(kk))
    {
        for (auto p = c.begin(); p != c.end();)
        {
            if (p->number == kk)
            {
                p = c.erase(p);
                break;
            }
            else
                ++p;
        }
        cout << "            The course was deleted successfully.          " << endl;
    }
    else
    {
        cout << "          You haven't added this class yet.        " << endl;
    }
}

void course::edit()//Teachers modify course information
{
    system("cls");
    long k = 1, kk;
    cout << "     Please enter the course ID of the course you want to modify:    " << endl;
    cin >> kk;
    if (ishave(kk))
    {
        for (size_t i = 0; i < c.size(); i++)
        {
            if (c[i].number == kk)
            {
                system("cls");

                cout << "         Please re-enter the Course Title:         " << endl;
                cin >> c[i].name;
                cout << "         Please re-enter course credit:         " << endl;
                cin >> c[i].credit;
                cout << "       Please re-enter the instructor name:       " << endl;
                cin >> c[i].teachername;
                cout << "            modified Successfully .              " << endl;
                break;
            }
        }
    }
    else
    {
        cout << "            This course does not exist.           " << endl;
    }

}

int course::ishave(long si)//Check if the course is available
{
    for (size_t i = 0; i < c.size(); i++)
        if (c[i].number == si)
            return true;
    return false;
}
void student::print()//打印所有学生信息
{
    long sumk = 0;
    system("cls");
    for (int i = 0; i < s.size(); i++)
    {
        sumk = 0;
        cout << endl << "The student matric num：" << s[i].number << "   Name：" << s[i].name << "   Sex：" \
			<< s[i].sex << "   Grade：" << s[i].grade << endl << endl\
			<< "Students have chosen courses:" << endl;
        if (s[i].havec.size() == 0)
        {
            cout << "Null" << endl;
            continue;
        }
        else
        {
            for (int k = 0; k < s[i].havec.size(); k++)
            {
                cout << endl << "The course No.：" << s[i].havec[k].number << "   Course Title：" << s[i].havec[k].name << "   Course credit：" \
					<< s[i].havec[k].credit << "   lecturer name：" << s[i].havec[k].teachername << endl;
                sumk = sumk + s[i].havec[k].credit;

            }
            cout << endl << "This student has a total of " << s[i].scredit << "credit in this semster，have chosen" << s[i].havec.size() << "门，共" << sumk << "学分。" << endl;
        }
    }
    sprintorget();
}

void student::get()//Get student information
{
    system("cls");
    long k = 1, kk, sumk = 0;
    cout << "        Please enter the matric number to be inquired:      " << endl;
    cin >> kk;
    system("cls");
    if (ishave(kk))
    {
        for (size_t i = 0; i < s.size(); i++)
            if (s[i].number == kk)
            {
                cout << endl << "Matric num：" << s[i].number << "   Name：" << s[i].name << " Sex：" \
					<< s[i].sex << "   Grade：" << s[i].grade << endl << endl\
					<< "Students have chosen courses：" << endl;
                if (s[i].havec.size() == 0)
                {
                    cout << "Null " << endl;
                    continue;
                }
                else
                {
                    for (int k = 0; k < s[i].havec.size(); k++)
                    {
                        cout << endl << "Matric num：" << s[i].havec[k].number << "    Name：" << s[i].havec[k].name << "   Course credit：" \
							<< s[i].havec[k].credit << "    lecturer name：" << s[i].havec[k].teachername << endl;
                        sumk = sumk + s[i].havec[k].credit;

                    }
                    cout << endl << "This student has a total of" << s[i].scredit << "credit in this semster，have chosen" << s[i].havec.size() << "now, and total" << sumk << "credit。" << endl;
                }
            }
    }
    else
    {
        cout << "             There is no such student.            " << endl;
    }
    sprintorget();
}

void student::add()//Add student information
{
    system("cls");
    long k = 1; student s1;
    cout << "        Please enter the Matric num to be added:    " << endl;
    cin >> s1.number;
    while (ishave(s1.number))
    {
        system("cls");
        cout << "┃      The student has been added, please re-enter:      ┃" << endl;
        cout << "┃             (press 0 to exit)              ┃" << endl;
        cin >> k;
        if (k == 0)
        {
            sinfo();
            break;
        }
        else s1.number = k;

    }
    if (k != 0)
    {
        cout << "           Please enter student name:           " << endl;
        cin >> s1.name;
        cout << "          Please enter student gender:          " << endl;
        cin >> s1.sex;
        cout << "           Please enter student grade:           " << endl;
        cin >> s1.grade;
        system("cls");
        s.push_back(s1);
        sinfo();
    }
}

void student::del()    //Delete student information
{
    system("cls");
    long k = 1, kk;
    cout << "       Please enter the student matric num to delete:      " << endl;
    cin >> kk;
    if (ishave(kk))
    {
        for (auto p = s.begin(); p != s.end();)
        {
            if (p->number == kk)
            {
                p = s.erase(p);
                break;
            }
            else
                ++p;
        }
        cout << "            The student was successfully removed:          " << endl;

    }
    else
    {
        cout << "        You have not added this student yet.       " << endl;

    }
}

void student::edit()//修改学生信息
{
    system("cls");
    long k = 1, kk;
    cout << "        Please enter the matric num of the student you want to modify:      " << endl;
    cin >> kk;
    if (ishave(kk))
    {
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i].number == kk)
            {
                system("cls");
                cout << "         Please re-enter student name:         " << endl;
                cin >> s[i].name;
                cout << "        Please re-enter student gender:        " << endl;
                cin >> s[i].sex;
                cout << "         Please re-enter student grade:         " << endl;
                cin >> s[i].grade;
                cout << "              Successfully modified.              " << endl;
                break;
            }
        }
    }
    else
    {
        cout << "             There is no such student.            " << endl;
    }
}

void student::addcourse()//Add the course
{
    system("cls");
    long k = 1, kk, sumk = 0, sk;
    cout << "           Please enter the student matric num:         " << endl;
    cin >> kk;
    if (ishave(kk))
    {
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i].number == kk)
            {

                cout << endl << "Matric num: " << s[i].number << "   Name：" << s[i].name << "   Sex：" \
					<< s[i].sex << "   Grade：" << s[i].grade << endl << endl\
					<< "Students have chosen courses：" << endl;
                if (s[i].havec.size() == 0)
                {
                    cout << "Null" << endl;

                }
                else
                {
                    for (int k = 0; k < s[i].havec.size(); k++)
                    {
                        cout << endl << "the Course No. ：" << s[i].havec[k].number << "   The course title：" << s[i].havec[k].name << "   the credit：" \
							<< s[i].havec[k].credit << "   the lecturer name：" << s[i].havec[k].teachername << endl;
                        sumk = sumk + s[i].havec[k].credit;

                    }
                    cout << endl << "This student has a total of" << s[i].scredit << "credit in this semester，have chosen" << s[i].havec.size() << "now, and total" << sumk << "credit。" << endl;

                }

                cout << "          Please enter the course to add:        " << endl;
                cin >> sk;
                for (size_t k = 0; k < s[i].havec.size(); k++)
                    if (s[i].havec[k].number == sk)
                    {
                        cout << "        This course already exists, cannot be added.       " << endl;
                    }
                    else
                    {
                        if (course::ishave(sk))
                        {
                            course c1;
                            for (size_t jk = 0; jk < c.size(); jk++)
                            {
                                if (c[jk].number == sk)
                                {
                                    c1.number = c[jk].number;
                                    c1.name = c[jk].name;
                                    c1.credit = c[jk].credit;
                                    c1.teachername = c[jk].teachername;
                                }
                            }
                            sumk = sumk + c1.credit;
                            if (sumk > s[i].scredit)
                            {
                                cout << "┃          There are not enough credits to add.        ┃" << endl;
                            }
                            else
                            {
                                s[i].havec.push_back(c1);
                                cout << "┃               Added successfully.            ┃" << endl;
                                break;
                            }


                        }
                        else
                        {
                            cout << "┃           The course does not exist in the system.        ┃" << endl;
                        }
                    }

            }
        }
    }
    else
    {
        cout << "              There is no such student.            " << endl;
    }
}

void student::delcourse()//delete course
{
    system("cls");
    long k = 1, kk, sumk = 0, sk;
    cout << "           Please enter the student matric number:         " << endl;
    cin >> kk;
    if (ishave(kk))
    {
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i].number == kk)
            {
                cout << endl << "Matric num：" << s[i].number << "   Name：" << s[i].name << "   Sex：" \
					<< s[i].sex << "   Grade：" << s[i].grade << endl << endl\
					<< "Students have chosen courses：" << endl;
                if (s[i].havec.size() == 0)
                {
                    cout << "Null" << endl;
                    continue;
                }
                else
                {
                    for (int k = 0; k < s[i].havec.size(); k++)
                    {
                        cout << endl << "The course num：" << s[i].havec[k].number << "   The course title：" << s[i].havec[k].name << "   the credit：" \
							<< s[i].havec[k].credit << "   the lecturer name：" << s[i].havec[k].teachername << endl;
                        sumk = sumk + s[i].havec[k].credit;

                    }
                    cout << endl << "This student has a total of" << s[i].scredit << "credit in this semester，have chosen" << s[i].havec.size() << "now, and total" << sumk << "credit。" << endl;
                }
                cout << "          Please enter the course to delete:        " << endl;
                cin >> sk;
                for (auto p = s[i].havec.begin(); p != s[i].havec.end();)
                {
                    if (p->number == sk)
                    {
                        p = s[i].havec.erase(p);
                        break;
                    }
                    else
                        ++p;
                }
                cout << "              deleted  successfully             " << endl;
            }
        }
    }
    else
    {
        cout << "              There is no such student.            " << endl;

    }
}

int student::ishave(long si)
{
    for (size_t i = 0; i < s.size(); i++)
        if (s[i].number == si)
            return true;
    return false;
}

void cprintorget()//Query or display course information
{
    cout << endl;
    cout << "      ** Computer Science Student’s Registration System **   " << endl;
    cout << "      ┏━━━━━━━━━━━━━━━━━━━━━┓   " << endl;
    cout << "      ┃ Please select a feature：        ┃   " << endl;
    cout << "      ┃ 1. Query course information  ┃  " << endl;
    cout << "      ┃2. Display course information ┃  " << endl;
    cout << "      ┃ 3.back to previous page         ┃  " << endl;
    cout << "      ┗━━━━━━━━━━━━━━━━━━━━━┛   " << endl;
    cout << "      Please enter the serial number (1~3) to operate  " << endl;
    cout << endl;
    int ii, k = 1;
    cin >> ii;
    while (k)
    {
        if (ii > 3 || ii < 1)
        {
            cout << "invalid Input, please re-enter numbers 1~3." << endl;
            cin >> ii;
        }

        else
            k = 0;
    }
    system("cls");
    switch (ii)
    {
        case 1: course::get(); break;
        case 2: course::print(); break;
        case 3:cinfo(); break;
    }
}

void cinfo()//Student Course Selection Information
{
    system("cls");
    cout << endl;
    cout << "      ** Computer Science Student’s Registration System **   " << endl;
    cout << "      ┏━━━━━━━━━━━━━━━━━━━━━┓   " << endl;
    cout << "      ┃ Please select a feature：        ┃   " << endl;
    cout << "      ┃1. Query course information   ┃  " << endl;
    cout << "      ┃ 2. Add course information     ┃  " << endl;
    cout << "      ┃ 3. Delete course information ┃  " << endl;
    cout << "      ┃ 4. Modify course information┃  " << endl;
    cout << "      ┃ 5. Back to the main menu      ┃  " << endl;
    cout << "      ┗━━━━━━━━━━━━━━━━━━━━━┛   " << endl;
    cout << "      Please enter the serial number (1~5) to operate  " << endl;
    cout << endl;

    int ii, k = 1;
    cin >> ii;
    while (k)
    {
        if (ii > 5 || ii < 1)
        {
            cout << "invalid Input, please re-enter numbers 1~5." << endl;
            cin >> ii;
        }

        else
            k = 0;
    }
    system("cls");
    switch (ii)
    {
        case 1: cprintorget(); break;
        case 2:course::add(); break;
        case 3:course::del(); break;
        case 4:course::edit(); break;
        case 5:Menu(); break;
    }
}

void sprintorget()//Inquire or display student information
{
    cout << endl;
    cout << "      ** Computer Science Student’s Registration System **   " << endl;
    cout << "      ┏━━━━━━━━━━━━━━━━━━━━━┓   " << endl;
    cout << "      ┃ Please select a feature：        ┃   " << endl;
    cout << "      ┃ 1. Query course information  ┃  " << endl;
    cout << "      ┃2. Display course information ┃  " << endl;
    cout << "      ┃ 3.back to previous page         ┃  " << endl;
    cout << "      ┗━━━━━━━━━━━━━━━━━━━━━┛   " << endl;
    cout << "      Please enter the serial number (1~3) to operate  " << endl;
    cout << endl;
    int ii, k = 1;
    cin >> ii;
    while (k)
    {
        if (ii > 3 || ii < 1)
        {
            cout << "invalid Input, please re-enter numbers 1~3." << endl;
            cin >> ii;
        }

        else
            k = 0;
    }
    system("cls");
    switch (ii)
    {
        case 1: student::get(); break;
        case 2: student::print(); break;
        case 3:sinfo(); break;
    }
}

void sinfo()
{
    system("cls");
    cout << endl;
    cout << "      ** Computer Science Student’s Registration System **   " << endl;
    cout << "      ┏━━━━━━━━━━━━━━━━━━━━━┓   " << endl;
    cout << "      ┃ Please select a feature：         ┃   " << endl;
    cout << "      ┃ 1. Query student information  ┃  " << endl;
    cout << "      ┃ 2. Add student information     ┃  " << endl;
    cout << "      ┃ 3. Delete student information ┃  " << endl;
    cout << "      ┃ 4. Modify student information┃  " << endl;
    cout << "      ┃ 5. Add courses for students     ┃  " << endl;
    cout << "      ┃ 6. Delete courses for students ┃  " << endl;
    cout << "      ┃ 7. Back to the main menu        ┃  " << endl;
    cout << "      ┗━━━━━━━━━━━━━━━━━━━━━┛   " << endl;
    cout << "      Please enter the serial number (1~7) to operate:  " << endl;
    cout << endl;

    int ii, k = 1;
    cin >> ii;
    while (k)
    {
        if (ii > 7 || ii < 1)
        {
            cout << "invalid Input, please re-enter numbers 1~7." << endl;
            cin >> ii;
        }

        else
            k = 0;
    }
    system("cls");
    switch (ii)
    {
        case 1: sprintorget(); break;
        case 2:student::add(); break;
        case 3:student::del(); break;
        case 4:student::edit(); break;
        case 5:student::addcourse(); break;
        case 6:student::delcourse(); break;
        case 7:Menu(); break;
    }
}

void login()//login interface
{
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃                                      ┃" << endl;
    cout << "┃Welcome to the registration system management terminal!┃" << endl;
    cout << "┃                                      ┃" << endl;
    cout << "┃    Please enter password：（default password：1234）      ┃" << endl;
    cout << "┃                                      ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    int k = 0;
    char input[16];
    cin >> input;
    while (strcmp(password, input) != 0)
    {
        cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
        cout << "┃                                      ┃" << endl;
        cout << "┃        Wrong password, please re-enter.        ┃" << endl;
        cout << "┃                                      ┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
        cin >> input;
        k++;

        if (k > 3)
        {
            cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
            cout << "┃                                      ┃" << endl;
            cout << "┃    input error exceeds 5 times, Please try again in five seconds.   ┃" << endl;
            cout << "┃                                      ┃" << endl;
            cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
            Sleep(5000);
            k = 0;
            system("cls");
            cout << "             Try again.             " << endl;
            cin >> input;
        }
    }

    if (strcmp(password, input) == 0)
    {
        system("cls");
        cout << "          Login successful, welcome!         " << endl;
    }
}

void changepassword()//change Pswd
{
    int kk = 1;
    char p1[16], p2[16];
    while (kk) {
        system("cls");
        cout << "            Please enter a new password:            " << endl;
        cin >> p1;
        cout << "           Please enter your password again to confirm:           " << endl;
        cin >> p2;
        if (strcmp(p1, p2) != 0)
        {
            cout << "  The passwords entered twice do not match, please re-enter. " << endl;
        }
        else
        {
            system("cls");
            cout << "       Password changed successfully, please log in again.     " << endl;
            strcpy_s(password, p1);
            kk = 0;
            login();
        }
    }
}


int Menu()//main menu
{
    while (1)
    {
        cout << endl;
        cout << "      **Computer Science Student’s Registration System**   " << endl;
        cout << "      ┏━━━━━━━━━━━━━━━━━━━━━┓   " << endl;
        cout << "      ┃ Please select a feature：                       ┃   " << endl;
        cout << "      ┃ 1. Course information management     ┃  " << endl;
        cout << "      ┃ 2. Student Information Management   ┃  " << endl;
        cout << "      ┃ 3. Change the password                        ┃  " << endl;
        cout << "      ┃ 4. Logout                                                ┃  " << endl;
        cout << "      ┃ 5. Exit the system                                   ┃  " << endl;
        cout << "      ┗━━━━━━━━━━━━━━━━━━━━━┛   " << endl;
        cout << "      Please enter the serial number (1~7) to operate:  " << endl;
        cout << endl;

        int ii, k = 1;
        cin >> ii;
        while (k)
        {
            if (ii > 5 || ii < 1)
            {
                cout << "invalid Input, please re-enter numbers 1~5." << endl;
                cin >> ii;
            }

            else
                k = 0;
        }

        switch (ii)
        {
            case 1: cinfo(); break;
            case 2: sinfo(); break;
            case 3:
            {
                changepassword();
                login();
                break;
            }
            case 4:
            {
                system("cls");
                cout << "┃         Logout succeeded, please log in again.       ┃" << endl;
                login();
            }
                break;
            case 5: return 0;
                break;
        }
    }
}
//*****************************************************//

int main()
{
    Menu();
    return 0;
}
#endif