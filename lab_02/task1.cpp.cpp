/*
Task 1: Shop item sales over five days using fixed-size array and pointers
*/
#include <iostream>
using namespace std;

int main() {
    int sales[5];
    int* p = sales;

    cout << "Enter sales for 5 days:\n";
    for (int i = 0; i < 5; ++i) {
        cin >> *(p + i);
    }

    int total = 0;
    cout << "Sales values: ";
    for (int i = 0; i < 5; ++i) {
        cout << *(p + i) << " ";
        total += *(p + i);
    }
    cout << "\nTotal sales: " << total << endl;

    *(p + 2) += 2;

    total = 0;
    cout << "Updated sales values: ";
    for (int i = 0; i < 5; ++i) {
        cout << *(p + i) << " ";
        total += *(p + i);
    }
    cout << "\nUpdated total sales: " << total << endl;

    return 0;
}