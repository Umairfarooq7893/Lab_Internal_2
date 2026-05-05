#include <iostream>
using namespace std;

#define SIZE 10

int main() {
    int arr[SIZE];

    // Initialize array
    for (int i = 0; i < SIZE; i++)
        arr[i] = -1;

    int keys[] = {23, 43, 13, 27};
    int n = 4;

    // Insert elements
    for (int i = 0; i < n; i++) {
        int key = keys[i];
        int index = key % SIZE;

        // Linear probing
        while (arr[index] != -1) {
            index = (index + 1) % SIZE;
        }

        arr[index] = key;
    }

    // Display
    cout << "Hash Table:\n";
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] == -1)
            cout << i << " --> Empty\n";
        else
            cout << i << " --> " << arr[i] << "\n";
    }

    return 0;
}