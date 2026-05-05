#include <iostream>
using namespace std;

bool isPalindrome(char arr[], int n) {
    char stack[n];
    int top = -1;

    for(int i = 0; i < n; i++) {
        stack[++top] = arr[i];
    }

    for(int i = 0; i < n; i++) {
        if(arr[i] != stack[top--]) {
            return false;
        }
    }

    return true;
}

int main() {
    char arr[100];

    cout << "Enter string (avoid spaces): ";
    cin >> arr;

    int n = 0;
    while(arr[n] != '\0') {
        n++;
    }

    if(isPalindrome(arr, n))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";
}