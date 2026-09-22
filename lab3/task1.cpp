// Task 1  Creating a structure
// Define the Student structure. Declare one student variable, input its roll number, full name, and marks, and display all details with clear labels.
#include<iostream>
using namespace std;
int main(){
    struct student{
        int roll_no;
        string full_name;
        int marks;
    };
    student s;

    cout<<"Enter Roll no."<<endl;
    cin>>s.roll_no;
    cout<<"Enter Full name"<<endl;
    cin>>s.full_name;
    cout<<"Enter student's marks"<<endl;
    cin>>s.marks;


    cout<<"Student roll no. "<<s.roll_no;
    cout<<" Student name "<<s.full_name;
    cout<<" Student marks "<<s.marks;
}
