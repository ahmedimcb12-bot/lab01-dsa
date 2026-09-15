/*
Task 5: Dynamic array expansion by copying elements to accommodate a new student mark
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n (1-10): ";
    cin >> n;
    if (n < 1 || n > 10) {
        cout << "Invalid size." << endl;
        return 1;
    }

    int* marks = new int[n];
    cout << "Enter " << n << " marks: ";
    for (int i = 0; i < n; ++i) {
        cin >> *(marks + i);
    }

    int newMark;
    cout << "Enter new mark to append: ";
    cin >> newMark;

    int* newMarks = new int[n + 1];
    for (int i = 0; i < n; ++i) {
        *(newMarks + i) = *(marks + i);
    }
    *(newMarks + n) = newMark;

    delete[] marks;
    marks = newMarks;
    n += 1;

    cout << "Updated marks: ";
    for (int i = 0; i < n; ++i) {
        cout << *(marks + i) << " ";
    }
    cout << endl;

    delete[] marks;
    marks = nullptr;

    return 0;
}