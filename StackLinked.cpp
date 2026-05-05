/*
    Author  : Umair Farooq
    program : Implementing a linked list based stack
*/
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class stack{
public:
    Node* top = NULL;
// using constructor initializing stack
    stack(){
        top = NULL;
    }
// defining push (member fxn)
    // since ll provides dynamic size hence no full
    void push(int value){
        Node* nn = new Node();
        nn->data = value;
        nn->next = top;

        top = nn; // update top
    }
// defining pop (member fxn)
    void pop(){
        if(top == NULL){
            cout<<"Stack UnderFlow";
        }else{
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
// defining peek (member fxn) 
    void peek(){
        if (top == NULL){
            cout<< " stack is empty";
        }else{
            cout<<top->data; 
        }
    }
    void display(){
        Node* temp = top;
        while(temp != NULL){
            cout<<temp->data<< "->";
            temp = temp->next;
        }
        cout<<"NULL";
    }
};
int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.peek();
    s.pop();
    s.peek();
}