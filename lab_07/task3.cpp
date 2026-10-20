#include <iostream>

using namespace std;

class CircularQueue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    CircularQueue(int size = 5) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool IsEmpty() const {
        return count == 0;
    }

    bool IsFull() const {
        return count == capacity;
    }

    void Enqueue(int value) {
        if (IsFull()) {
            cout << "Queue Overflow! Cannot enqueue " << value << ".\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        count++;
        cout << "Enqueued: " << value << "\n";
    }

    int Dequeue() {
        if (IsEmpty()) {
            cout << "Queue Underflow! Queue is empty.\n";
            return -1;
        }
        int removedValue = arr[front];
        front = (front + 1) % capacity;
        count--;
        cout << "Dequeued: " << removedValue << "\n";
        return removedValue;
    }

    int GetFront() const { return front; }
    int GetRear() const { return rear; }
    int GetCount() const { return count; }

    void Display() const {
        if (IsEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue (Front to Rear): ";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % capacity;
            cout << arr[index] << " ";
        }
        cout << " | [front = " << front << ", rear = " << rear << "]\n";
    }

    void Clear() {
        front = 0;
        rear = -1;
        count = 0;
    }
};

int main() {
    cout << "=== TASK 3: Circular Queue Testing ===\n";
    CircularQueue cq(5);

    // Enqueue 10, 20, 30, 40, 50
    cq.Enqueue(10);
    cq.Enqueue(20);
    cq.Enqueue(30);
    cq.Enqueue(40);
    cq.Enqueue(50);

    // Dequeue twice
    cq.Dequeue();
    cq.Dequeue();

    // Enqueue 60 and 70 (tests circular wraparound)
    cq.Enqueue(60);
    cq.Enqueue(70);

    // Display and verify front = 2, rear = 1
    cq.Display();

    // Reject another insertion (Full queue)
    cq.Enqueue(80);

    // Empty the queue
    while (!cq.IsEmpty()) {
        cq.Dequeue();
    }

    // Test one further dequeue on empty queue
    cq.Dequeue();

    // Test insertion into an empty queue again
    cq.Enqueue(100);
    cq.Enqueue(200);
    cq.Display();
    cout << "\n";

    return 0;
}