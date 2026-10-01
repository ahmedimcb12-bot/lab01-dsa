#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

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

void PrintList() {
    Node* current = head;
    cout << "List: ";
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

// Function to delete the first node matching the requested value
void DeleteNode(int delData) {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    // Case 1: The node to delete is the first node (or only node)
    if (head->data == delData) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted " << delData << endl;
        return;
    }

    // Case 2: The node is in the middle or end
    Node* current = head;
    while (current->next != nullptr && current->next->data != delData) {
        current = current->next;
    }

    // If we reached the end and didn't find the value
    if (current->next == nullptr) {
        cout << "Value " << delData << " not found in the list." << endl;
        return;
    }

    // Value found, reconnect and delete
    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
    cout << "Deleted " << delData << endl;
}

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
    cout << "--- Task 5: Deleting a Node by Value ---" << endl;
    
    // Setting up the specific test case: 10, 20, 20, 30
    AddNode(10);
    AddNode(20);
    AddNode(20);
    AddNode(30);
    
    cout << "Initial list setup:" << endl;
    PrintList();

    // Testing deletion
    cout << "\nAttempting to delete 20 (should only remove the first 20):" << endl;
    DeleteNode(20);
    PrintList(); // Expecting 10, 20, 30

    cout << "\nAttempting to delete the first node (10):" << endl;
    DeleteNode(10);
    PrintList(); 

    cout << "\nAttempting to delete the last node (30):" << endl;
    DeleteNode(30);
    PrintList(); 

    cout << "\nAttempting to delete the only remaining node (20):" << endl;
    DeleteNode(20);
    PrintList(); 

    cout << "\nAttempting to delete from an empty list (100):" << endl;
    DeleteNode(100);
    PrintList(); 

    ClearList();
    return 0;
}