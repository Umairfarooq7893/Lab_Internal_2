#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;
// Delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    Node* last = head;
    while (last->next != head){
        last = last->next;
    }
    head = head->next;
    last->next = head;
    delete temp;
}
// Delete from end
void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    Node* prev = NULL;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    delete temp;
}
// Delete from specific position
void deleteFromPosition(int position) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    if (position < 1) {
        cout << "Position should be >= 1.\n";
        return;
    }
    if (position == 1) {
        deleteFromBeginning();
        return;
    }
    Node* temp = head;
    Node* prev = NULL;
        for (int i = 1; i < position && temp->next != head; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp->next == head && position > 1) {
            cout << "Position out of range." << endl;
            return;
        }
        prev->next = temp->next;
        delete temp;
    }
    // Function to display the circular linked list
    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl;
    }
int main() {
    head = new Node{10, NULL};

    head->next = new Node{20, NULL};           // second node
    head->next->next = new Node{30, NULL};     // third node

    head->next->next->next = head;

    // Create circular list
    deleteFromBeginning();
    deleteFromEnd();
    deleteFromPosition(2);

    display();

    return 0;
}