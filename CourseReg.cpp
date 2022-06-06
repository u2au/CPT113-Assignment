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
    modifyCourse();


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
            newInfo->num =  currentNum;
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
        cout << infoPtr->num << "\t\t"
             << infoPtr->code << "\t\t"
             << infoPtr->unit << "\t\t"
             << infoPtr->type << "\t"
             << endl;

        infoPtr = infoPtr->next;
        count++
    }

    cout << "Currently, there are " << count << " courses offered to students from School of Computer Sciences. \n";

}

// Registration System
void CourseReg::modifyCourse()
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

    cout << "Input Formats: <operation> <num> \n"
         << "Operations: add, drop, exit \n"
         << "For example, if a student wants to add a course which num is 20, the command is: add 20 \n"
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
            	bool exist=search(input);
            	if( !exist)
            	   cout<<" Sorry this course doesn't exist...please enter again. \n"
            	else
				{
					//function addCousese	
                    cout << "Course #" << input << " has been added. Please enter next command. \n";
				}
            
            }
            else if (operation == "drop") {
            	//function dropCourse
            	
                cout << "Course #" << input << " has been dropped. Please enter next command. \n";
            }

            cin >> operation;
            if (operation != "exit") cin >> input;

        } while (operation != "exit");

    }
    else cout << "Thanks for using. \n";
}

bool CourseReg::search(int input){

    bool found=false;
	SetInfo* nodeptr;
	nodeptr=head;
	while(nodeptr!=nullptr && !found)
	{
		if(nodeptr->num==input)
		{
			found=true;
			addCourse(nodeptr->code,nodeptr->unit,nodeptr->type);
		}
		else
			nodeptr=nodeptr->next;
			
	if(found)
	    found=(nodeptr->num==imput);
	    
	    return found;
		
	}
}


void CourseReg::addCourse(string codes, short units, char types)
{
	// we want to copy the node we want from the existing list to a new list
    SetInfo *newNode;
    SetInfo *nodePtr;
    SetInfo *trailPtr;
	
	//allocate a new node & store the value of the current list ndoe in it
	newNode=new SetInfo;
	newNode->code=codes;
	newNode->type=types;
	newNode->unit=units;
	
	if(head==nullptr)
	{
		newNode->pre=nullptr;
		newNode->next=nullptr;
		head=newNode;
		end=newNode;
	}
	else
	{
		newNode->next=nullptr;
		end->next=newNode;
		newNode->pre=end;
		end=newNode;
	}

}

void CourseReg::deleteNode(int delnum){
	Course* nodeptr;
	Course* trailptr;
	
	bool found;
	if(head==nullptr)
	   cout<<" Can't delete from an empty list..."<<endl;
	else if(head->num==delnum)
	{
		nodeptr=head;
		head=head->next;
		 
		if(head!=nullptr)
		   head->previous=nullptr;
		else 
		   end=nullptr;
	}
	else
	{
		found=false;
		nodeptr=head;
		
		while(nodeptr!=nullptr && !found)
		    if(nodeptr->courseNum==delnum)
		     found=true;
		    else
		      nodeptr=nodeptr->next;
		if(nodeptr==nullptr)
		    cout<<"the courses to be delete is not in the list...please try again"<<endl;
		else if(nodeptr->courseNum==delnum)
		{
			trailptr=nodeptr->previous;
			trailptr->next=nodeptr->next;
			
			if(nodeptr->next!=nullptr)
			   nodeptr->next->previous=trailptr;
			   
//			if(nodeptr==end) last=trailptr;
			   
			   count--;
			   delete nodeptr;
		}
		   
	}
	
}

void CourseReg::showNewList(){
	//show the final courses student choose after add/drop courses
	
}

