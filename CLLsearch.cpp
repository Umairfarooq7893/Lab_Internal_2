#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

// Search in circular linked list
void search(int key) {
    if (head == NULL) {
        cout << "List is empty";
        return;
    }
    Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == key) {
            cout << "Element found at position " << pos;
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    cout << "Element not found";
}
int main() {
    // Create circular list
    head = new Node{10, NULL};
    head->next = new Node{20, NULL};
    head->next->next = new Node{30, NULL};
    head->next->next->next = head;
    search(20);
    return 0;
}