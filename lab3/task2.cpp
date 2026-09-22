// Task 2  Accessing a structure through a pointer
// Create a pointer to a student variable. Input the record, then use the arrow operator (->) to display its details, update its marks with a new value entered by the user, and display the updated record.
#include<iostream>
using namespace std;
int main(){
    struct student{
        int roll_no;
        string full_name;
        int marks;
    };
    student s;
    student *s1=&s;
    cout<<"Before updation"<<endl;

    cout<<"Enter Roll no."<<endl;
    cin>>s1->roll_no;
    cout<<"Enter Full name"<<endl;
    cin>>s1->full_name;
    cout<<"Enter student's marks"<<endl;
    cin>>s1->marks;

    
    
    cout<<"Student roll no. "<<s1->roll_no<<endl;
    cout<<" Student name "<<s1->full_name<<endl;
    cout<<" Student marks "<<s1->marks<<endl;

    cout<<endl;

    cout<<"After updation"<<endl;
    
    cout<<"Enter Roll no."<<endl;
    cin>>s1->roll_no;
    cout<<"Enter Full name"<<endl;
    cin>>s1->full_name;
    cout<<"Enter student's marks"<<endl;
    cin>>s1->marks;

    cout<<" Student name "<<s1->full_name<<endl;
    cout<<" Student roll_no. "<<s1->roll_no<<endl;
    cout<<" Student marks "<<s1->marks<<endl;
}


