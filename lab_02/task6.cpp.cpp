/*
Task 6: Error inspection, correction, and core memory concepts analysis
*/
#include <iostream>
using namespace std;

int main() {
    int n = 3;
    int* values = new int[n];

    cout << "Enter 3 integers (e.g., 4 5 6): ";
    for (int i = 0; i < n; i++) {
        cin >> *(values + i);
    }

    cout << "Stored values: ";
    for (int i = 0; i < n; i++) {
        cout << *(values + i) << " ";
    }
    cout << endl;

    delete[] values;
    values = nullptr;

    return 0;
}