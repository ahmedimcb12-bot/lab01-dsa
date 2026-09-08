#include <iostream>
using namespace std;

int main() {
    int numbers[5];
    int total = 0;

    cout << "Enter 5 integers:\n";
    
    // First loop: read integers into the array
    for (int i = 0; i < 5; ++i) {
        cin >> numbers[i];
    }

    // Second loop: add them to total
    for (int i = 0; i < 5; ++i) {
        total += numbers[i];
    }

    cout << "Total: " << total << endl;
    
    return 0;
}