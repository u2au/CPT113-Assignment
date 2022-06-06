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

void DoubleList::appendNode(int addnum){
	Course* newNode;
	newNode=new Course;
	newNode->
	
	
	
}

void DoubleList::deleteNode(int delnum){
	Course* nodeptr;
	Course* trailptr;
	
	bool found;
	if(head==nullptr)
	   cout<<" Can't delete from an empty list..."<<endl;
	else if(head->coursenum==delnum)
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
		
		while(nodeptr!=nullptr&& !found)
		    if(nodeptr->coursenum==delnum)
		     found=true;
		    else
		      nodeptr=nodeptr->next;
		if(nodeptr==nullptr)
		    cout<<"the courses to be delete is not in the list...please try again"<<endl;
		else if(nodeptr->coursenum==delnum)
		{
			trailptr=nodeptr->previous;
			trailptr->next=nodeptr->next;
			
			if(nodeptr->next!=nullptr)
			   nodeptr->next->prevoius=trailptr;
			   
			if(nodeptr==end)
			   last=trailptr;
			   
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
		cout << nodeptr->coursenum << "\t\t"
		     <<nodeptr->codes<<"\t\t"
             << nodeptr->units << "\t\t"
             << nodeptr->types << "\t\t"
             << endl;

        nodeptr = nodeptr->next;
    }
		
	}
	
}