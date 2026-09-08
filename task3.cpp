#include <iostream>
using namespace std;

class Student {
public:
    int rollNumber;
    int marks;

    void display() {
        cout << "Roll Number: " << rollNumber << "\n";
        cout << "Marks: " << marks << "\n";
    }
};

int main() {
    Student s1;
    s1.rollNumber = 1;
    s1.marks = 75;

    Student s2;
    s2.rollNumber = 2;
    s2.marks = 90;

    cout << "--- Initial Values ---\n";
    cout << "Student 1:\n";
    s1.display();
    cout << "Student 2:\n";
    s2.display();

    // Modify only s1
    s1.marks = 80;

    cout << "\n--- After modifying s1.marks ---\n";
    cout << "Student 1:\n";
    s1.display();
    cout << "Student 2:\n";
    s2.display();

    return 0;
}