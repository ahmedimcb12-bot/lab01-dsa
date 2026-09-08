#include <iostream>
using namespace std;

int main() {
    int arr[10];
    
    cout << "Enter 10 integers: ";
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }
    
    int count = 0; // Tracks the position for the next unique element
    
    for (int i = 0; i < 10; i++) {
        bool isDuplicate = false;
        
        // Check if the current element appeared previously in the array
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }
        
        // If it's a first occurrence, move it to the front at index 'count'
        if (!isDuplicate) {
            arr[count] = arr[i];
            count++;
        }
    }
    
    cout << "Unique values: {";
    for (int i = 0; i < count; i++) {
        cout << arr[i] << (i < count - 1 ? ", " : "");
    }
    cout << "}" << endl;
    cout << "Count: " << count << endl;
    
    return 0;
}