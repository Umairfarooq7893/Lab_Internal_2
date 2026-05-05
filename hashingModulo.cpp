#include <iostream>
using namespace std;
int hash_modulo(int key, int size) {
    return key % size;
}
int main() {
    int keys[] = {15, 27, 8, 12};
    int size = 10;
    int n = sizeof(keys) / sizeof(keys[0]);
    int hash_values[n];
    for (int i = 0; i < n; i++) {
        hash_values[i] = hash_modulo(keys[i], size);
    }
    cout << "Modulo Hash Values: ";
    for (int i = 0; i < n; i++) {
        cout << hash_values[i] << " ";
    }
    cout << endl;
    return 0;
}

