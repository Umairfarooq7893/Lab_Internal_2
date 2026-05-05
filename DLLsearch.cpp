#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev; 
    Node* next; 
};
Node* head = NULL;
void search(int key) {
    if (head == NULL) {
        cout << "List is empty";
        return;
    }
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Data found at position: " << pos;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not Found";
}
int main() {
    head = new Node{10, NULL, NULL};
    head->next = new Node{20, head, NULL};
    head->next->next = new Node{30, head->next, NULL};
    head->next->next->next = new Node{40, head->next->next, NULL}; // fixed duplicate

    search(20);

    return 0;
}