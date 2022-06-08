//
// Created by rinsuki on 03/06/2022.
//

#include "CourseReg.h"
#include <iostream>
#include <fstream>

using namespace std;

void CourseReg::menu()
{
    // Welcome
    cout << "Welcome to USM CS Student Registration System! \n"
         << "Please wait... We're loading courses from the course list... \n";

    // Get the courses info
    setCourse();

    // Registration System
    terminal();


}

// Input Validation
void CourseReg::inputValidation()
{
    cout << "Sorry, the num you typed was wrong. Please enter again: ";
    cin >> input;
}

// Add Courses
void CourseReg::setCourse()
{
    // Open the course list
    ifstream infile;
    infile.open("CourseList.txt", ios::in);

    // Initialization
    int currentNum=0;
    string currentCode = "default";
    short currentUnit = 1;
    char currentType = 'D';

    // If the file is lost
    if (!infile) cout << "Sorry, we can't find any file called CourseList.txt." << endl;
    else
    {
        while (infile)
        {
            // SetInfo START
            SetInfo *newInfo;
            SetInfo *InfoPtr;

            // Read data from the course list
            infile >> currentNum;
            infile >> currentCode;
            infile >> currentUnit;
            infile >> currentType;

            // Allocate memory for new info
            newInfo = new SetInfo;

            // Assign the value to the node
            newInfo->num = currentNum;
            newInfo->code = currentCode;
            newInfo->unit = currentUnit;
            newInfo->type = currentType;

            // Make next pointer point to nullptr
            newInfo->next = nullptr;

            // If the course list is empty
            if (!head) head = newInfo;

            else
            {
                InfoPtr = head;
                while (InfoPtr->next) InfoPtr = InfoPtr->next; // Find the last node of info
                InfoPtr->next = newInfo; // Assign the value to the course list

            }

            numOfCourses++;
        }

        // Close the file
        infile.close();

        // Display num of the courses
        cout << "Thanks for waiting! There are " << --numOfCourses << " courses in the list. \n";
    }

}

// Display the list
void CourseReg::displayList()
{
    SetInfo *infoPtr;
    infoPtr = head;

    cout << "Here are the courses offered to CS students. \n"
         << "Num\t\t" << "Code\t\t" << "Unit\t" << "Type\t" << endl;

   int count = 0; // Initialization

    while (infoPtr->next)
    {
        cout <<infoPtr->num<<"\t\t"
	    	<< infoPtr->code << "\t\t"
             << infoPtr->unit << "\t\t"
             << infoPtr->type << "\t"
             << endl;

        infoPtr = infoPtr->next;
        count++;
    }

    cout << "Currently, there are " << count << " courses offered to students from School of Computer Sciences. \n";

}

// Registration System
void CourseReg::terminal()
{
	
    // Display the list
    cout << "Do you want to display all the courses offered to USM CS students? (1 - Yes, 0 - No) : ";
    cin >> input;

    while (input != 1 && input != 0) inputValidation(); // Input Validation

    // If yes, display the list
    system("CLS");
    if (input == 1) displayList();

    // Temp Variable
    string operation = "def";

    cout << "Input Formats: <operation> <course name> \n"
         << "Operations: add, drop, exit \n"
         << "For example, if a student wants to add course which num is 20 , the command is: add 20 \n"
         << "Kindly enter: exit, to exit anytime. \n";

    // Ask for input
    cin >> operation;
    if (operation != "exit")
    {
        cin >> input;
        do {
            // Input Validation
            while ((operation != "add" && operation != "drop" && operation != "exit")
                   || (input <= 0 || input > numOfCourses))
            {
                if (operation != "add" && operation != "drop" && operation != "exit") {
                    cout << "Sorry, possible operations are: add, drop, exit. Please re-enter the whole command. \n";
                }

                if (input <= 0 || input > numOfCourses) {
                    cout << "Sorry, valid range of the courses is: 1-" <<  numOfCourses << ". Please re-enter the whole command. \n";
                }

                cin >> operation;
                cin >> input;
            }

            // Add or drop a course
            if (operation == "add") {
            //	bool exist = search(input);
            //	if (exist==false) cout<< "Sorry this course doesn't exist... Please enter again. \n"; // cin?
            //	else
			//	{
					// function addCousese
                   addCourse(operation,input);
                    cout << "Course #" << input << " has been added. Please enter next command. \n";
			//	}
            
            }
            else if (operation == "drop") {
            	//function dropCourse
                  dropCourse(operation,input);
//                cout << "Course #" << input << " has been dropped. Please enter next command. \n";
            }

            cin >> operation;
            if (operation != "exit") cin >> input;

        } while (operation != "exit");

    }
    else cout << "Thanks for using. \n";
}

bool CourseReg::search(int cname){//to search if the course student want to drop exist in the doubly linked list (course added)

    bool found=false;
	Student* nodeptr;
	nodeptr=courseHead;
	while(nodeptr!=nullptr && !found)
	{
		if(nodeptr->num==cname)
		{
			found=true;
		
		}
		else
			nodeptr=nodeptr->next;
   }

	if(found)
	    found=(nodeptr->num==input);

	    return found;

	
}


void CourseReg::addCourse(string ops, int num)
{
	// we want to copy the node we want from the existing list to a new list
    SetInfo *nodePtr;
    Student *newNode;

    
        // Allocate a new node & store the value of the current list ndoe in it
        newNode = new Student;

        // Get data from a specific node from the course list
        nodePtr = nullptr;
        for (int i = 1; i < num; i++) 
		nodePtr = nodePtr->next;

        newNode->num = nodePtr->num ;
        newNode->code = nodePtr->code;
        newNode->type = nodePtr->type;
        newNode->unit = nodePtr->unit;

        if (head == nullptr) // Empty List
        {
            newNode->prev = nullptr;
            newNode->next = nullptr;
            courseHead = newNode;
            courseEnd = newNode;
        }
        else // Non-empty List
        {
            newNode->next = nullptr;
            courseEnd->next = newNode;
            newNode->prev = courseEnd;
            courseEnd = newNode;
        }
         showNewList();
}


void CourseReg::dropCourse(string ops, int cnum){
	    Student *coursePtr;
        Student *trailPtr;

        bool found = false;
    if (courseHead == nullptr) 
	    cout << "You haven't added any course yet."<< endl; 
    
    else
   {
   	  // Display the results
    	bool exist=search(cnum);
    	if(exist){
		
		    if (courseHead != nullptr && cnum == 1) // If the first one is the one to be deleted
           {
            coursePtr = courseHead;
            courseHead = courseHead->next;

                if (courseHead != nullptr) 
			    courseHead->prev = nullptr;
                else 
			    courseEnd = nullptr;
           }
           else
          {
            coursePtr = courseHead;

               for (int i = 1; coursePtr != nullptr && found == false; i++)
            {
                if (i == cnum)
                {
                    found = true;
                    break;
                }
                else coursePtr = coursePtr->next;
            }
		
	}
}
    	else{
		cout<<"no such course exist, please enter again.\n"<<endl;
	}
	showNewList();
   	
   	
   }

           
}

void CourseReg::showNewList(){
	//show the final courses student choose after add/drop courses
	Student *coursePtr;
    Student *trailPtr;
    if(courseHead == nullptr)
      cout<<"You didn't have any courses yet...\n";
    else
    {
    	coursePtr= courseHead;
    	while(coursePtr!=nullptr){
    		cout<<"Those are the course you choose:\n"<<endl;
    		cout<<coursePtr->num<<" "<<coursePtr->code<<" "
			    <<coursePtr->type<<" "<<coursePtr->unit<<endl;
    		coursePtr->next;
		}
	}      
	
}

