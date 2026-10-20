#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedQueue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor initializes an empty queue
    LinkedQueue() : front(nullptr), rear(nullptr) {}

    // Destructor to release all remaining nodes before exit
    ~LinkedQueue() {
        cout << "[Destructor] Clearing queue:\n";
        ClearQueue();
    }

    // Check if the queue is empty
    bool IsEmpty() const {
        return front == nullptr;
    }

    // Enqueue: Insert at the rear (O(1) time complexity)
    void Enqueue(int value) {
        Node* newNode = new Node(value);
        if (IsEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << value << "\n";
    }

    // Dequeue: Remove from the front (O(1) time complexity)
    int Dequeue() {
        if (IsEmpty()) {
            cout << "Queue Underflow! Queue is already empty.\n";
            return -1;
        }

        Node* temp = front;
        int removedValue = temp->data;
        
        front = front->next;

        // Reset rear to nullptr when the last node is deleted
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        cout << "Dequeued: " << removedValue << "\n";
        return removedValue;
    }

    // Peek: View the front element without removing it
    int Peek() const {
        if (IsEmpty()) {
            cout << "Queue is empty! No front element to peek.\n";
            return -1;
        }
        return front->data;
    }

    // Display all elements from front to rear
    void Display() const {
        if (IsEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        Node* current = front;
        cout << "Queue (Front to Rear): ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }

    // ClearQueue: Release all remaining nodes and reset pointers
    void ClearQueue() {
        while (!IsEmpty()) {
            Node* temp = front;
            front = front->next;
            cout << "Released node with value: " << temp->data << "\n";
            delete temp;
        }
        rear = nullptr; // Ensure rear is safely reset
    }
};

int main() {
    LinkedQueue q;

    cout << "=== 1. Testing Empty Queue Operations ===\n";
    cout << "Is queue empty? " << (q.IsEmpty() ? "Yes" : "No") << "\n";
    q.Peek();
    q.Dequeue();

    cout << "\n=== 2. Enqueue 10, 20, 30 ===\n";
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    cout << "\n=== 3. Dequeue Once & Display Remaining (20, 30) ===\n";
    q.Dequeue(); // Removes 10
    q.Display(); // Should output 20 30

    cout << "\n=== 4. Test Peek (Must show 20) ===\n";
    cout << "Peek front element: " << q.Peek() << "\n";

    cout << "\n=== 5. Removal of Only/Remaining Nodes & Rear Reset Test ===\n";
    q.Dequeue(); // Removes 20
    q.Dequeue(); // Removes 30 (Last node deleted -> rear resets to nullptr)
    cout << "Is queue empty now? " << (q.IsEmpty() ? "Yes" : "No") << "\n";

    cout << "\n=== 6. Insertion After Queue Becomes Empty ===\n";
    q.Enqueue(50);
    q.Enqueue(60);
    q.Display();

    cout << "\n=== 7. Final Clean Up & Exit ===\n";
    q.ClearQueue(); // Manually clear remaining nodes before exit

    return 0;
}