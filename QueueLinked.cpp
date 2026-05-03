#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Queue using Linked List
class Queue {
    Node *front, *rear;

public:
    Queue() {
        front = rear = NULL;
    }

    // Enqueue (Insert)
    void enqueue(int x) {
        Node* temp = new Node(x);

        if (rear == NULL) {  // Empty queue
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    // Dequeue (Delete)
    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;
        cout << "Deleted: " << temp->data << endl;

        front = front->next;

        if (front == NULL)  // Queue becomes empty
            rear = NULL;

        delete temp;
    }

    // Display
    void display() {
        if (front == NULL) {
            cout << "Queue is Empty\n";
            return;
        }

        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.display();

    return 0;
}