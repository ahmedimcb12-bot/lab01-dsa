#include <iostream>

using namespace std;

// CircularQueue implementation required as a base for Task 4
class CircularQueue {
protected:
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

    virtual ~CircularQueue() {
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
    }

    int Dequeue() {
        if (IsEmpty()) {
            return -1;
        }
        int removedValue = arr[front];
        front = (front + 1) % capacity;
        count--;
        return removedValue;
    }

    int GetCount() const {
        return count;
    }

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
        cout << "\n";
    }
};

// Task 4: ComputerLabQueue inheriting/reusing CircularQueue
class ComputerLabQueue : public CircularQueue {
public:
    ComputerLabQueue(int size = 5) : CircularQueue(size) {}

    // RotateTurn: saves front ID, removes it, and enqueues it at the rear using queue operations
    void RotateTurn() {
        if (IsEmpty()) {
            cout << "Queue is empty! No students to rotate.\n";
            return;
        }
        if (GetCount() == 1) {
            cout << "Only one student in queue. Turn completed, queue remains unchanged:\n";
            Display();
            return;
        }

        // Save front ID, dequeue it, and enqueue at rear
        int frontID = Dequeue();
        Enqueue(frontID);
        cout << "Served / Rotated student ID: " << frontID << "\n";
    }
};

int main() {
    cout << "=== TASK 4: Rotating Service Turns Using a Circular Queue ===\n\n";

    // 1. Initialize queue and enqueue student IDs 101, 102, 103
    ComputerLabQueue labQ(5);
    labQ.Enqueue(101);
    labQ.Enqueue(102);
    labQ.Enqueue(103);

    cout << "Initial Queue:\n";
    labQ.Display();
    cout << "\n";

    // 2. Run 5 turns using a loop and display updated queue after each turn
    for (int i = 1; i <= 5; i++) {
        cout << "--- Turn " << i << " ---\n";
        labQ.RotateTurn();
        labQ.Display();
        cout << "\n";
    }

    // 3. Test an empty queue edge case
    cout << "--- Testing Empty Queue Edge Case ---\n";
    ComputerLabQueue emptyLab(5);
    emptyLab.RotateTurn(); // Should show the required empty message
    cout << "\n";

    // 4. Test a queue containing one student edge case
    cout << "--- Testing One Student Edge Case ---\n";
    ComputerLabQueue singleStudentLab(5);
    singleStudentLab.Enqueue(999);
    singleStudentLab.RotateTurn(); // Student must remain in the queue
    singleStudentLab.Display();

    return 0;
}