#include <iostream>
using namespace std;

// Folding hash function
int foldHash(int key) {
    int sum = 0;

    while (key > 0) {
        sum += key % 100;   // take 2 digits at a time
        key /= 100;
    }

    return sum; // only folding, no mod, no table
}

int main() {
    int keys[] = {1234, 5678, 9101, 1122};
    int n = 4;

    for (int i = 0; i < n; i++) {
        cout << "Key: " << keys[i] 
             << " -> Folded Value: " << foldHash(keys[i]) << endl;
    }

    return 0;
}