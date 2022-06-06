#include"DoubleList.h"
#include <iostream>

using namespace std;
//bool DoubleList::search(const int num){
//	bool found=false;
//	 Course* nodeptr;
//	 
//	 nodeptr=head;
//	 while(nodeptr!=nullptr&& !found)
//	    if(nodeptr->coursenum)
//	       found=true;
//	    else
//	       nodeptr=nodeptr->next;
//	    
//	if(found)
//	   found=(nodeptr->coursenum==num);//test for equality
//	   
//	return found;
//}

void DoubleList::appendNode(string node, int unit, char type)
{
	Course *newNode;
    Course *nodePtr;
    Course *trailPtr;

	newNode = new Course;
	newNode->courseCode = node;
    newNode->courseUnit = unit;
    newNode->courseType = type;

    if (head == NULL) head = newNode;
    else
    {
        while (nodePtr != NULL)
        {
            trailPtr = nodePtr;
            nodePtr = nodePtr->next;
        }
    }

    nodePtr = newNode;

}

void DoubleList::deleteNode(int delnum){
	Course* nodeptr;
	Course* trailptr;
	
	bool found;
	if(head==nullptr)
	   cout<<" Can't delete from an empty list..."<<endl;
	else if(head->courseNum==delnum)
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

void DoubleList::showList(){
	Course* nodeptr;
	nodeptr=head;
	while(nodeptr!=nullptr){
		count++;
		cout << nodeptr->courseNum << "\t\t"
		     << nodeptr->courseCode<<"\t\t"
             << nodeptr->courseUnit << "\t\t"
             << nodeptr->courseType << "\t\t"
             << endl;

        nodeptr = nodeptr->next;
    }
	
}