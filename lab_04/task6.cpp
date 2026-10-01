#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

// Core functions from earlier tasks
void AddNode(int addData) {
    Node* newNode = new Node();
    newNode->data = addData;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) current = current->next;
        current->next = newNode;
    }
}

void InsertAtBeginning(int addData) {
    Node* newNode = new Node();
    newNode->data = addData;
    newNode->next = head;
    head = newNode;
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

void DeleteNode(int delData) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    if (head->data == delData) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted " << delData << endl;
        return;
    }
    Node* current = head;
    while (current->next != nullptr && current->next->data != delData) {
        current = current->next;
    }
    if (current->next == nullptr) {
        cout << "Value " << delData << " not found." << endl;
        return;
    }
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

// New functions for Task 6
void SearchNode(int value) {
    Node* current = head;
    int pos = 1;
    while (current != nullptr) {
        if (current->data == value) {
            cout << "Value " << value << " found at position " << pos << "." << endl;
            return;
        }
        current = current->next;
        pos++;
    }
    cout << "Value " << value << " not found in the list." << endl;
}

int CountNodes() {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void DisplaySecondNode() {
    if (head != nullptr && head->next != nullptr) {
        cout << "The second node contains: " << head->next->data << endl;
    } else {
        cout << "The list does not have a second node." << endl;
    }
}

int main() {
    int choice = 0;
    int value;

    while (choice != 8) {
        cout << "\n--- Linked List Application Menu ---" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Search by Value" << endl;
        cout << "4. Delete by Value" << endl;
        cout << "5. Display All Nodes" << endl;
        cout << "6. Count Nodes" << endl;
        cout << "7. Display Second Node" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                InsertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                AddNode(value);
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                SearchNode(value);
                break;
            case 4:
                cout << "Enter value to delete: ";
                cin >> value;
                DeleteNode(value);
                break;
            case 5:
                PrintList();
                break;
            case 6:
                cout << "Total nodes: " << CountNodes() << endl;
                break;
            case 7:
                DisplaySecondNode();
                break;
            case 8:
                cout << "Exiting application and releasing memory..." << endl;
                ClearList();
                break;
            default:
                cout << "Invalid menu choice. Please select 1-8." << endl;
        }
    }

    return 0;
}