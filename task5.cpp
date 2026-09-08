#include <iostream>
using namespace std;

int main() {
    int arr[8];
    
    cout << "Enter 8 integers: ";
    for (int i = 0; i < 8; i++) {
        cin >> arr[i];
    }
    
    int maxVal = arr[0], minVal = arr[0];
    int maxIdx = 0, minIdx = 0;
    
    // Find largest, smallest and their first occurrences
    for (int i = 1; i < 8; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
            maxIdx = i;
        }
        if (arr[i] < minVal) {
            minVal = arr[i];
            minIdx = i;
        }
    }
    
    cout << "Largest value: " << maxVal << " at index " << maxIdx << endl;
    cout << "Smallest value: " << minVal << " at index " << minIdx << endl;
    
    return 0;
}