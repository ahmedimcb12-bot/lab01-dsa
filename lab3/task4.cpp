// Task 4  Using functions with pointers
// Create and input a dynamically allocated student record. Implement the following functions. In main(), display the record, update its marks, and display it again. Release the memory before the program ends.
// void displayStudent(const Student* s);
// void updateMarks(Student* s, float newMarks);
#include<iostream>
using namespace std;

struct student {
    int roll_no = 2;
    string name = "Ahmed";
    float marks = 24.2f;
};

void displayStudent(const student* s) {
    cout << "roll no. " << s->roll_no << endl; 
    cout << "name " << s->name << endl; 
    cout << "marks " << s->marks << endl; 
}
void updateMarks(student *s, float newMarks) {
    s->marks = newMarks;
}

int main() {
    
    student* s = new student;

    cout << "Display the details of student " << endl;
    displayStudent(s); 
    
    cout << "\nUpdating the marks of Student" << endl;
    updateMarks(s, 64.5f);

    cout << "After updation " << endl;
    displayStudent(s);

    delete s;
    s = nullptr;

    return 0;
}