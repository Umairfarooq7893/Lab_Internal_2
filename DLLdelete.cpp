
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Global head
Node* head = NULL;

// Delete from beginning
void deleteFromBeginning() {

    // Case 1: List is empty
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;  // store current head
    head = head->next;  // move head to next node
    // If list is not empty after deletion
    if (head != NULL)
        head->prev = NULL; // new head should not have previous
    delete temp;  // free memory of old head
}

// Delete from end
void deleteFromEnd() {
    // Case 1: List is empty
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    // Case 2: Only one node present
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    // Traverse to last node
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // Remove last node
    temp->prev->next = NULL;
    delete temp;
}

// Delete from position
void deleteFromPosition(int position) {
    if (position < 1) {
        cout << "Position should be >= 1." << endl;
        return;
    }
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    if (position == 1) {
        deleteFromBeginning();
        return;
    }
    Node* temp = head;
    // Traverse to the node at the specified position
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position out of range." << endl;
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    delete temp;
}

// Display
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

// Main
int main() {
    head = new Node{10, NULL, NULL};
    head->next = new Node{20, head, NULL};
    head->next->next = new Node{30, head->next, NULL};
    head->next->next->next = new Node{40, head->next->next, NULL}; // fixed duplicate

    deleteFromBeginning();
    deleteFromEnd();
    deleteFromPosition(2);
    display();
    displayBackward();

    return 0;
}