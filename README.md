# CPT113-Assignment

The repository was made for CPT113 Assignment 1 Group 2.

Here is the checklist of the requirements given by the lecturer.
Kindly check it for convenience.

<img width="791" alt="image" src="https://user-images.githubusercontent.com/25454024/168418765-700e78d5-9c11-40ac-9224-85bf9a01fa6c.png">

1. UML Diagram
2. Classes with relevant attributes and proper processing

    There are <b>5 classes</b> in the program: <i>Student, Tuition, Desa, Intl, TotalFee</i>
    
3. Inheritance

    <i>Student </i> is a <b>derived class</b> of <i>Tuition, Desa, </i>and <i>Intl.</i>
    
    <img width="541" alt="image" src="https://user-images.githubusercontent.com/25454024/168419003-dd0f8e89-1bfb-4beb-83c3-4e43b65d7264.png">

4. Composition (object must be of type private)

    In <i>Student.h</i>, we use a <b>composition</b> of class <i>TotalFee.</i>

    <img width="412" alt="image" src="https://user-images.githubusercontent.com/25454024/168419149-f67a7b81-2a7a-446f-bec7-82ed537b7dcf.png">

5. Friend Functions

    In <i>Student.h</i>, we make a prototype of the friend function for <b>accessing functions</b> in <i>Student.cpp</i> but <b>not in class <i>Student.</i></b>

    <img width="410" alt="image" src="https://user-images.githubusercontent.com/25454024/168419220-b7a5f406-67c7-4557-a495-4801fb83bc9f.png">
    <br/>
    <img width="408" alt="image" src="https://user-images.githubusercontent.com/25454024/168419248-53352796-08f8-4143-82f1-15500fef5a07.png">
    
6. Operator Overloading

    In <i>Student.cpp</i>, we use an <b>operator overloading</b> function to calculate the total fees by using objects defined before.
    
    <img width="969" alt="image" src="https://user-images.githubusercontent.com/25454024/168419378-97f2119d-57bc-4670-b1dd-5d5223b26641.png">
    
7. Read input from a text file

    In <i>main.cpp</i>, we <b>read input from</b> a file called <b><i>Student.txt</i></b> and save it in the variables, then do the input validation.

    <img width="898" alt="image" src="https://user-images.githubusercontent.com/25454024/168419465-7c5cc5fd-4ae0-4330-a8b3-9629e0b53106.png">
  
8. You must <b>only use ONE object</b> in <b>main()</b>

    As you can see, there is only one object in main() of the program.
  
    <img width="312" alt="image" src="https://user-images.githubusercontent.com/25454024/168419596-57807fa7-18c2-43b6-8472-be5a7226b695.png">

9. <i>Student</i> must be the object of the derived class. The object must be in array of object.


...


