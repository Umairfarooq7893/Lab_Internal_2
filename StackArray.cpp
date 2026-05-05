#include<iostream>
using namespace std;

#define MAX 5

class stack_class {
private:
    int arr[MAX];  // Array to store stack elements
    int top;       // Keeps track of top index of stack

public:
    // constructor
    stack_class() {
        top = -1;
        /*
        Initializes stack.
        top = -1 → stack is empty
        */
    }

    // push
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow\n";
        } else {
            arr[++top] = value;
        }
    }

    // isFull
    bool isFull() {
        return top == MAX - 1;
    }

    // pop
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
        } else {
            top--;  // Decreases top (removes element).
        }
    }

    // isEmpty
    bool isEmpty() {
        return top == -1;  //Returns true if stack is empty
    }

    // peek
    int peek() {
        if (isEmpty()){
            cout << "Stack is empty\n";
        }else {
             return arr[top];
        }
    }
    void display(){
        cout<<"displaying stack"<<endl;
        for (int i = top; i >= 0; i--) {   // FIXED
            cout << arr[i] << " ";
        }  
    }
};

int main() {
    stack_class s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    cout << "After pop: " << s.peek() << endl;

    return 0;
}