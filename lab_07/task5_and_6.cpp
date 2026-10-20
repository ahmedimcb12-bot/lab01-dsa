#include <iostream>

using namespace std;

// ==========================================
// TASK 5: Array Deque Implementation
// ==========================================
class ArrayDeque {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    ArrayDeque(int size = 5) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~ArrayDeque() {
        delete[] arr;
    }

    bool IsEmpty() const { 
        return count == 0; 
    }

    bool IsFull() const { 
        return count == capacity; 
    }

    void InsertFront(int value) {
        if (IsFull()) {
            cout << "Deque Overflow! Cannot insert " << value << " at front.\n";
            return;
        }
        front = (front - 1 + capacity) % capacity;
        arr[front] = value;
        count++;
        cout << "Inserted " << value << " at Front.\n";
    }

    void InsertRear(int value) {
        if (IsFull()) {
            cout << "Deque Overflow! Cannot insert " << value << " at rear.\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        count++;
        cout << "Inserted " << value << " at Rear.\n";
    }

    int DeleteFront() {
        if (IsEmpty()) {
            cout << "Deque Underflow! Deque is empty.\n";
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % capacity;
        count--;
        cout << "Deleted " << val << " from Front.\n";
        return val;
    }

    int DeleteRear() {
        if (IsEmpty()) {
            cout << "Deque Underflow! Deque is empty.\n";
            return -1;
        }
        int val = arr[rear];
        rear = (rear - 1 + capacity) % capacity;
        count--;
        cout << "Deleted " << val << " from Rear.\n";
        return val;
    }

    void Display() const {
        if (IsEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }
        cout << "Deque (Front to Rear): ";
        for (int i = 0; i < count; i++) {
            int idx = (front + i) % capacity;
            cout << arr[idx] << " ";
        }
        cout << "\n";
    }
};

void TestArrayDeque() {
    cout << "=== TASK 5: Array Deque Testing ===\n";
    ArrayDeque dq(5);

    // 1. Insert 20 at rear, 10 at front, 30 at rear -> Expect 10, 20, 30
    cout << "\n--- Sequence 1: Initial Insertions ---\n";
    dq.InsertRear(20);
    dq.InsertFront(10);
    dq.InsertRear(30);
    dq.Display(); // Expect: 10 20 30

    // 2. Delete from rear, then front -> Expect 20 remaining
    cout << "\n--- Sequence 2: Deletions ---\n";
    dq.DeleteRear();   // Deletes 30
    dq.DeleteFront();  // Deletes 10
    dq.Display(); // Expect: 20

    // 3. Insert 5 at front, 30 and 40 at rear, then 1 at front -> Expect 1, 5, 20, 30, 40
    cout << "\n--- Sequence 3: Mixed Insertions to Full Capacity ---\n";
    dq.InsertFront(5);
    dq.InsertRear(30);
    dq.InsertRear(40);
    dq.InsertFront(1);
    dq.Display(); // Expect: 1 5 20 30 40

    // 4. Reject further insertion at either end
    cout << "\n--- Sequence 4: Overflow Testing ---\n";
    dq.InsertFront(99);

    // 5. Test deletion of the only value from each end in separate runs, followed by deletion from empty
    cout << "\n--- Sequence 5: Single Node & Empty Deletions ---\n";
    ArrayDeque testDq(3);
    testDq.InsertRear(100);
    testDq.DeleteFront(); // Remove only value from front
    testDq.DeleteFront(); // Deletion from empty

    testDq.InsertRear(200);
    testDq.DeleteRear();  // Remove only value from rear
    testDq.DeleteRear();  // Deletion from empty
    cout << "\n";
}


// ==========================================
// TASK 6: Linked Deque Implementation
// ==========================================
struct DNode {
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class LinkedDeque {
private:
    DNode* front;
    DNode* rear;

public:
    LinkedDeque() : front(nullptr), rear(nullptr) {}

    ~LinkedDeque() {
        ClearDeque();
    }

    bool IsEmpty() const { 
        return front == nullptr; 
    }

    void InsertFront(int value) {
        DNode* newNode = new DNode(value);
        if (IsEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        front->prev = nullptr; // Ensure front->prev is nullptr
        cout << "Inserted " << value << " at Front.\n";
    }

    void InsertRear(int value) {
        DNode* newNode = new DNode(value);
        if (IsEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        rear->next = nullptr; // Ensure rear->next is nullptr
        cout << "Inserted " << value << " at Rear.\n";
    }

    int DeleteFront() {
        if (IsEmpty()) {
            cout << "Deque Underflow! Deque is empty.\n";
            return -1;
        }
        DNode* temp = front;
        int val = temp->data;
        
        front = front->next;
        if (front != nullptr) {
            front->prev = nullptr;
        } else {
            rear = nullptr; // Deque became empty
        }
        delete temp;
        cout << "Deleted " << val << " from Front.\n";
        return val;
    }

    int DeleteRear() {
        if (IsEmpty()) {
            cout << "Deque Underflow! Deque is empty.\n";
            return -1;
        }
        DNode* temp = rear;
        int val = temp->data;

        rear = rear->prev;
        if (rear != nullptr) {
            rear->next = nullptr;
        } else {
            front = nullptr; // Deque became empty
        }
        delete temp;
        cout << "Deleted " << val << " from Rear.\n";
        return val;
    }

    void Display() const {
        if (IsEmpty()) {
            cout << "Linked Deque is empty.\n";
            return;
        }
        DNode* current = front;
        cout << "Linked Deque (Front to Rear): ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }

    void ClearDeque() {
        while (!IsEmpty()) {
            DNode* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
        cout << "[ClearDeque] All nodes released.\n";
    }
};

void RunLinkedDequeMenu() {
    cout << "=== TASK 6: Linked Deque Testing & Interactive Menu Simulation ===\n";
    LinkedDeque ld;

    // 1. Insert 20 at rear, 10 at front, 30 at rear -> Expect 10, 20, 30
    cout << "\n--- Test Case 1: Initial Sequence ---\n";
    ld.InsertRear(20);
    ld.InsertFront(10);
    ld.InsertRear(30);
    ld.Display(); // Expect: 10 20 30

    // 2. Delete from front and rear -> Expect 20
    cout << "\n--- Test Case 2: Deletions ---\n";
    ld.DeleteFront(); // Removes 10
    ld.DeleteRear();  // Removes 30
    ld.Display(); // Expect: 20

    // 3. Delete the remaining node, then insert again
    cout << "\n--- Test Case 3: Empty & Re-insertion ---\n";
    ld.DeleteFront(); // Removes 20 (deque now empty)
    ld.InsertFront(77);
    ld.Display();

    // 4. Separately test removing the only node from the opposite end
    cout << "\n--- Test Case 4: Single Node Removal from Opposite End ---\n";
    ld.ClearDeque();
    ld.InsertRear(88);
    ld.DeleteFront(); // Remove only node via front when inserted at rear
    ld.Display();

    // 5. Exiting with nodes remaining / Destructor cleanup check
    cout << "\n--- Test Case 5: Exit with Nodes Remaining (Destructor Demo) ---\n";
    {
        LinkedDeque tempDq;
        tempDq.InsertRear(500);
        tempDq.InsertFront(400);
        // Destructor will automatically call ClearDeque() here when tempDq goes out of scope
    }
    cout << "\n";
}

int main() {
    TestArrayDeque();
    RunLinkedDequeMenu();
    return 0;
}