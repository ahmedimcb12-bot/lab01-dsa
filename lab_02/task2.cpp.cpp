/*
Task 2: Dynamic 1D array for student marks with runtime size allocation
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter number of students (1-10): ";
    cin >> n;

    if (n < 1 || n > 10) {
        cout << "Error; no allocation or mark input" << endl;
        return 1;
    }

    int* marks = new int[n];
    cout << "Enter " << n << " marks (0 to 100): ";
    for (int i = 0; i < n; ++i) {
        cin >> *(marks + i);
    }

    int total = 0;
    int passCount = 0;
    cout << "Marks entered: ";
    for (int i = 0; i < n; ++i) {
        int current = *(marks + i);
        cout << current << " ";
        total += current;
        if (current >= 50) {
            passCount++;
        }
    }
    cout << endl;

    double average = static_cast<double>(total) / n;
    cout << "Total: " << total << endl;
    cout << "Average: " << fixed << setprecision(2) << average << endl;
    cout << "Pass count (>=50): " << passCount << endl;

    delete[] marks;
    marks = nullptr;

    return 0;
}