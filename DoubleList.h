//Doubly Linked List for Student's Registration
#ifndef DL_H
#define DL_H
class Student{
	public:
		int c_num ;
        string c_code ;
        short c_unit ;
        char c_type ;
        
        Student* next ;
        Student* prev ;
        
	
};
class StudentList{
	private:
		
		struct Student{
		int c_num;
        string c_code ;
        short c_unit ;
        char c_type ;
        
        Student* next ;
        Student* prev ;
			
		};
		Student* head ;
		Student* end ;
	protected:
		int count = 0 ;
		
	public:
		void copyCourse() ;
		bool search(int) ;
		void addCourse(int) ;
		void dropCourse(int) ;
		
		
	
};
#endif