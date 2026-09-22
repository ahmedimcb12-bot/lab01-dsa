// Task 3  Creating a record dynamically
// Allocate one Student record using new. Input and display its details through the pointer. Release the allocated memory using delete and set the pointer to nullptr.

#include<iostream>
using namespace std;
int main(){
    struct student{
        int roll_no;
        string full_name;
        int marks;
    };
    student s;
    student *s1= new student;
    
    cout<<"Enter Roll no."<<endl;
    cin>>s1->roll_no;
    cout<<"Enter Full name"<<endl;
    cin.ignore(); 
    getline(cin, s1->full_name);
    cout<<"Enter student's marks"<<endl;
    cin>>s1->marks;

    
    
    cout<<"Student roll no. "<<s1->roll_no<<endl;
    cout<<" Student name "<<s1->full_name<<endl;
    cout<<" Student marks "<<s1->marks<<endl;

   delete s1;
   s1=nullptr;
}


