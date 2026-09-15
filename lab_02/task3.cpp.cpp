/*
Task 3: Fixed-size 2D array representing branches and days using row pointers
*/
#include <iostream>
using namespace std;

int main() {
    int sales[2][3];
    int (*rowPtr)[3] = sales;

    cout << "Enter sales for Branch 1 (3 days) then Branch 2 (3 days):\n";
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 3; ++c) {
            cin >> *(*(rowPtr + r) + c);
        }
    }

    cout << "\nSales Table (Rows: Branches, Cols: Days):\n";
    for (int r = 0; r < 2; ++r) {
        cout << "Branch " << (r + 1) << ": ";
        for (int c = 0; c < 3; ++c) {
            cout << *(*(rowPtr + r) + c) << " ";
        }
        cout << endl;
    }

    cout << "\nBranch totals:\n";
    for (int r = 0; r < 2; ++r) {
        int branchTotal = 0;
        for (int c = 0; c < 3; ++c) {
            branchTotal += *(*(rowPtr + r) + c);
        }
        cout << "Branch " << (r + 1) << " total: " << branchTotal << endl;
    }

    cout << "\nDay totals:\n";
    for (int c = 0; c < 3; ++c) {
        int dayTotal = 0;
        for (int r = 0; r < 2; ++r) {
            dayTotal += *(*(rowPtr + r) + c);
        }
        cout << "Day " << (c + 1) << " total: " << dayTotal << endl;
    }

    return 0;
}