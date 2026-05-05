#include <iostream>
using namespace std;

int get_middle_two_digits(int num) {
    int square = num * num;

    // Extract middle 2 digits from the square
    // Assumes the square has at least 3 digits
    if (square < 100) return square; // fallback if too small

    while (square >= 10000) {
        square /= 10;
    }

    return (square / 10) % 100; // get middle 2 digits
}

int hash_middle_of_square(int key, int size) {
    int middle = get_middle_two_digits(key);
    return middle % size;
}

int main() {
    int keys[] = {15, 27, 8, 12};
    int size = 10;
    int n = sizeof(keys) / sizeof(keys[0]);
    int hash_values[n];
    for (int i = 0; i < n; i++) {
        hash_values[i] = hash_middle_of_square(keys[i], size);
    }

    cout << "Middle of Square Hash Values: ";
    for (int i = 0; i < n; i++) {
        cout << hash_values[i] << " ";
    }
    cout << endl;

    return 0;
}

