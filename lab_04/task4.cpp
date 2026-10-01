
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

// Function to insert at the end
void AddNode(int addData) {
    Node* newNode = new Node();
    newNode->data = addData;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to insert at the beginning
void InsertAtBeginning(int addData) {
    Node* newNode = new Node();
    newNode->data = addData;
    newNode->next = head;
    head = newNode;
}

// Function to print the list
void PrintList() {
    Node* current = head;
    cout << "Current List: ";
    if (current == nullptr) {
        cout << "Empty";
    }
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

// Function to clear the list and free memory
void ClearList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

int main() {
    cout << "--- Task 4: Inserting at the Beginning ---" << endl;
    
    // Starting with an empty list, insert 20 at the beginning
    cout << "Inserting 20 at the beginning..." << endl;
    InsertAtBeginning(20);
    PrintList();

    // Insert 10 at the beginning
    cout << "Inserting 10 at the beginning..." << endl;
    InsertAtBeginning(10);
    PrintList();

    // Append 30
    cout << "Appending 30 at the end..." << endl;
    AddNode(30);
    PrintList(); // Final order must be 10, 20, 30

    ClearList();
    return 0;
}