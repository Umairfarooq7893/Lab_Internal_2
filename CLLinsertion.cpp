#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at Beginning
void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

// Insert at End
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

    void insertAtPosition(int value, int position) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }
        if (position == 1) {
            insertAtBeginning(value);
            return;
        }
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next =NULL;

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp->next != head; i++) {
            temp = temp->next;
        }
        if (temp->next == head && position > 2) {
            cout << "Position out of range." << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
// Display
void display() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(head)\n";
}

// Main
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);

    insertAtBeginning(5);
    insertAtPosition(15, 3);

    display();
    return 0;
}