// Task 5  Checking whether a record exists
// Initialize a student pointer to nullptr. Write void displayIfExists(const Student* s) to display a record if it exists or print "No record available" otherwise. Call it before allocation, after allocating and entering a record, and after deleting the record and resetting the pointer to nullptr.
#include<iostream>
using namespace std;
struct Student{
    int roll_no=2;
    string name="Ahmed";
    int marks=34;
};
void displayifExists(const Student *s){
    if(s->roll_no!=2||s->name!="Ahmed"||s->marks!=34){
        cout<<"No record Available"<<endl;
    }
    else{    
        cout<<"Person available";
    }    
}
int main(){
    Student *s= new Student;
    cout<<"Enter Roll no."<<endl;
    cin>>s->roll_no;
    cout<<"Enter Full name"<<endl;
    cin>>s->name;
    cout<<"Enter student's marks"<<endl;
    cin>>s->marks;
    displayifExists(s);

    delete s;
    s=nullptr;
}
