#include <iostream>
#include <string>
using namespace std;

// Struct definition
struct student {
    int roll_no;
    string name;
    float marks;
};

// Display
void displayStudent(const student* s) {
    cout << "\n--- Student Details ---" << endl;
    cout << "Roll No: " << s->roll_no << endl;
    cout << "Name:    " << s->name << endl;
    cout << "Marks:   " << s->marks << endl;
}
//update marks
void updateMarks(student* s, float newMarks) {
    s->marks = newMarks;
    cout << "Marks updated successfully!" << endl;
}

int main() {
    // Start with a null pointer to indicate no record exists yet
    student* s = nullptr; 
    int choice;

    do {
        cout << "\n=== Student Record Menu ===" << endl;
        cout << "1. Create Record" << endl;
        cout << "2. Display Record" << endl;
        cout << "3. Update Marks" << endl;
        cout << "4. Delete Record" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1: // Create
                if (s != nullptr) {
                    cout << "Error: A record already exists! Delete it first before creating a new one." << endl;
                } else {
                    s = new student;
                    cout << "Enter Roll No: ";
                    cin >> s->roll_no;
                    
                    cout << "Enter Name: ";
                    cin.ignore(); // Clear the input buffer before getline
                    getline(cin, s->name);
                    
                    cout << "Enter Marks: ";
                    cin >> s->marks;
                    cout << "Record created successfully." << endl;
                }
                break;

            case 2: // Display
                if (s == nullptr) {
                    cout << "Error: No record exists to display." << endl;
                } else {
                    displayStudent(s);
                }
                break;

            case 3: // Update
                if (s == nullptr) {
                    cout << "Error: No record exists to update." << endl;
                } else {
                    float newMarks;
                    cout << "Enter new marks: ";
                    cin >> newMarks;
                    updateMarks(s, newMarks);
                }
                break;

            case 4: // Delete
                if (s == nullptr) {
                    cout << "Error: No record exists to delete." << endl;
                } else {
                    delete s;
                    s = nullptr; 
                    cout << "Record deleted successfully." << endl;
                }
                break;

            case 5: 
                if (s != nullptr) {
                    
                    delete s; 
                    s = nullptr;
                }
                cout << "Exiting application..." << endl;
                break;

            default: 
                cout << "Invalid choice! Please enter a number between 1 and 5." << endl;
        }
    } while (choice != 5);

    return 0;
}