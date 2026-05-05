#include <iostream>
using namespace std;

const int SIZE = 10;

class HashTableQP {
private:
    int table[SIZE];

public:
    HashTableQP() {
        for (int i = 0; i < SIZE; i++)
            table[i] = -1; // -1 indicates empty slot
    }

    int hash(int key) {
        return key % SIZE;
    }

    void insert(int key) {
        int index = hash(key);
        int i = 0;
        while (table[index] != -1) {
            index = (index + i * i) % SIZE;  // Quadratic probing
            i++;
        }
        table[index] = key;
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << "Index " << i << ": ";
            if (table[i] == -1)
                cout << "Empty" << endl;
            else
                cout << table[i] << endl;
        }
    }
};

int main() {
    HashTableQP hashTable;
    int keys[] = {15, 25, 35, 45};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        hashTable.insert(keys[i]);
    }

    hashTable.display();

    return 0;
}

