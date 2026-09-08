#include <iostream>
using namespace std;

int main() {
    int arr[6];
    
    cout << "Enter 6 integers: ";
    for (int i = 0; i < 6; i++) {
        cin >> arr[i];
    }
    
    // Reverse elements in-place by swapping opposite ends
    for (int i = 0; i < 6 / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[5 - i];
        arr[5 - i] = temp;
    }
    
    cout << "Reversed array: {";
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << (i < 5 ? ", " : "");
    }
    cout << "}" << endl;
    
    return 0;
}