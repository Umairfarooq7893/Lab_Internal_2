#include<iostream>
using namespace std;

// Function to check if opening and closing brackets match
bool isMatching(char open , char close){
    return (open == '('&&close == ')')||   // round brackets
           (open == '['&&close == ']')||   // square brackets
           (open == '{'&&close == '}');   // curly brackets
}

// Function to check if expression has balanced parentheses
bool checkParenthesis(string expr){
    char stack[100];   // array used as stack
    int top = -1;      // stack is initially empty

    // Traverse each character in expression
    for(int i = 0 ; i < expr.length(); i++){
        char ch = expr[i];

        // If opening bracket, push to stack
        if(ch == '(' || ch == '[' || ch == '{'){
            stack[++top] = ch;
        }

        // If closing bracket
        else if (ch == ')' || ch == ']' || ch == '}'){

            // If stack is empty → no matching opening
            if(top == -1){
                return false;
            }

            // Check if top matches current closing bracket
            if(isMatching(stack[top], ch)){
                top--;   // pop from stack
            } else {
                return false;  // mismatch
            }
        }
    }

    // If stack is empty → balanced, else not balanced
    return (top == -1);
}

int main(){
    string expr ="{{([])}}";  // input expression

    // Check and print result
    if(checkParenthesis(expr))
        cout<< "Balanced";
    else
        cout<< "Not Balanced";
}