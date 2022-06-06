//doubly linked list for courses add/drop
#ifndef DL_H
#define DL_H
class DoubleList{
	private:
	    struct Course
    {
        string codes;
        int coursenum;//num of courses in coureseList.txt
        short units;
        char types;
        struct Course* previous;
        struct Course* next;
    };
    
    protected:
    	 int count;
    	 Course* head;
         Course* end; 	
    public:
    	DoubleList(){
    		head=nullptr;
    		end=nullptr;
    		count=0;
		}
		//to calculate how many courses has been added into the list
		int length()const{
			return count;
		}
	    //copy the node from another list
	    void copyCourses();
	
		//to add courses in the list
		void appendNode(int);
		//to drop the courses from the list
		void deleteNode(int);	
		void showList()const;
};
#endif