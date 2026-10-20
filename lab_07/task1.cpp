#include<iostream>
using namespace std;

const int MAX_SIZE = 8; 
int arr[MAX_SIZE];
int front;
int rear;

class ArrayQue {
public:
// Empty check
bool isEmpty() {
if (front == -1 || front > rear) { 
return true;
}
return false;
}

// Full check
bool isFull() {
if (rear == MAX_SIZE - 1) { 
return true;
}
return false;
}

// Inserting
void enque(int value) {
if (isFull()) {
cout << "Queue is full " << endl;
return;
}

if (front == -1) { 
front = 0;
}

rear++; 
arr[rear] = value;
cout << value << " Entered " << endl;
}

// Deleting
void deque() {
if (isEmpty()) {
cout << "Queue is Empty " << endl;
return;
}


cout << "Deleted " << arr[front] << endl;

if (front == rear) { // only 1 element.
front = -1;
rear = -1;
}
else {
front++; // Multiple elements 
}
}

// Peeking
void peek() {
if (isEmpty()) {
cout << "Queue is Empty " << endl;
}
else {
cout << "Front Element: " << arr[front] << endl;
}
}

// Displaying
void display() {
if (isEmpty()) {
cout << "Queue is Empty " << endl;
return;
}
for (int i = front; i <= rear; i++) {
cout << arr[i] << " ";
}
cout << endl;
}
};

int main() {
front = -1;
rear = -1;
ArrayQue aq;

cout << "=======================" << endl;
aq.enque(10);
aq.enque(20);
aq.enque(30);
aq.enque(40);
aq.enque(50);

cout << "=======================" << endl;
cout << "Queue Elements: ";
aq.display();

cout << "=======================" << endl;
aq.deque(); // 10 delete 
aq.deque(); // 20 delete 
aq.deque(); // 30 delete 

cout << "=======================" << endl;
cout << "Remaining Elements: ";
aq.display(); 

cout << "=======================" << endl;
aq.peek(); 

return 0;
}
