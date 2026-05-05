#include <iostream>
#include <vector>
using namespace std;
class HashTableSC {
private:
    int size;
    vector<vector<int>> table;
    int hash(int key) {
        return key % size;
    }
public:
    HashTableSC(int s) {
        size = s;
        table.resize(size);
    }

    void insert(int key) {
        int index = hash(key);
        table[index].push_back(key);
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": ";
            for (int val : table[i]) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    HashTableSC hashTable(10);
    int keys[] = {15, 25, 35, 45};
    int n = sizeof(keys) / sizeof(keys[0]);
    for (int i = 0; i < n; i++) {
        hashTable.insert(keys[i]);
    }
    hashTable.display();
    return 0;
}

