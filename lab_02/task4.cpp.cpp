/*
Task 4: Dynamic 2D matrix with runtime rows and cols, tie-handling, and cleanup
*/
#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter number of students (rows, 1-10): ";
    cin >> rows;
    cout << "Enter number of subjects (cols, 1-10): ";
    cin >> cols;

    if (rows < 1 || rows > 10 || cols < 1 || cols > 10) {
        cout << "Error: Invalid rows or columns." << endl;
        return 1;
    }

    int** marks = new int*[rows];
    for (int r = 0; r < rows; ++r) {
        marks[r] = new int[cols];
    }

    cout << "Enter marks for each student row by row:\n";
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            cin >> *(*(marks + r) + c);
        }
    }

    cout << "\nMarks Matrix:\n";
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            cout << *(*(marks + r) + c) << " ";
        }
        cout << endl;
    }

    int bestStudent = 1;
    int maxTotal = -1;

    for (int r = 0; r < rows; ++r) {
        int currentTotal = 0;
        for (int c = 0; c < cols; ++c) {
            currentTotal += *(*(marks + r) + c);
        }
        cout << "Student " << (r + 1) << " Total: " << currentTotal << endl;

        if (r == 0 || currentTotal > maxTotal) {
            maxTotal = currentTotal;
            bestStudent = r + 1;
        }
    }

    cout << "Top student: " << bestStudent << " (Total: " << maxTotal << ")" << endl;

    for (int r = 0; r < rows; ++r) {
        delete[] marks[r];
    }
    delete[] marks;
    marks = nullptr;

    return 0;
}