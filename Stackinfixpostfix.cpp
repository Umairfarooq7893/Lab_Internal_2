#include<iostream>
using namespace std;
#define max  100

class Stack{
private:
    int top;
    char arr[max];
public:
    Stack(){
        top = -1;
    }
    void push(char ch){
        if(top == max -1){
            cout<< "Stack Over Flow";
            return;
        }
        arr[++top] = ch;
    }
    char pop(){
        if(top == -1){
            cout<<"Stack UnderFlow \n";
            return '\0';
        }
        return arr[top--];
        
    }
    char peek(){
        return (top == -1)?'\0':arr[top];
    }
    bool isEmpty(){
        return top == -1;
    }
};
    int precedence(char op){
        if(op == '^') return 3;
        if(op == '*' ||op == '/' ||op == '%') return 2;
        if(op == '+'||op == '-') return 1;
    }
    bool isOperand(char ch){
        return(ch>='a' && ch <= 'z')||
              (ch>='A' && ch <= 'Z')||
              (ch>='0' && ch <= '1');
    }

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";

    for (char ch : infix) {
        if (isOperand(ch)) {
            postfix += ch;
        } 
        else if (ch == '(') {
            s.push(ch);
        } 
        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop(); // Remove '('
        } 
        else {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) {
                postfix += s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

// Main function
int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix Expression: " << infix << endl;
    cout << "Postfix Expression: " << infixToPostfix(infix) << endl;
    return 0;
}