#include <iostream>
using namespace std;

int main() {
    // Declare and initialize the array
    int numbers[5] = {2, 4, 6, 8, 10};
    
    // Change the third element (index 2) to 7
    numbers[2] = 7;
    
    // Display all five values separated by spaces
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    return 0;
}