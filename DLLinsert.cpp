#include <iostream>
using namespace std;
// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
};
// Global head pointer
Node* head = NULL;

// Insert at beginning
void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    // Case 1: List is empty
    if (head == NULL) {
        head = newNode;
    // Case 2: List already has nodes
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Insert at end
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    // Case 1: List is empty
    if (head == NULL) {
        head = newNode;
        return;
    }
    // Traverse to last node
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // Link last node with new node
    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at position
void insertAtPosition(int value, int position) {
    // Invalid position
    if (position < 1) {
        cout << "Position should be >= 1." << endl;
        return;
    }
    // Insert at beginning case
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    Node* temp = head;

    // Traverse to (position - 1) node
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position out of range." << endl;
        delete newNode;  // avoid memory leak
        return;
    }
    // Insert new node between temp and temp->next
    newNode->next = temp->next;
    newNode->prev = temp;
    // If not inserting at last position
    if (temp->next != NULL)
        temp->next->prev = newNode; // fix backward link of next node
    temp->next = newNode;  // connect previous node to new node
}

// Display forward
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
    // Display the list from end to beginning
    void displayBackward() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        // Traverse to the last node
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // Traverse backward using prev pointers
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }

// Main function
int main() {
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtPosition(15, 2);
    insertAtPosition(25, 4);

    cout << "Doubly Linked List (Insertion): ";
    display();

    return 0;
}