#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int smallest = i;              // assume root is smallest
    int left  = 2 * i + 1;
    int right = 2 * i + 2;

    // Find smallest among root, left and right
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If smallest is not root
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void heapSort(int arr[], int n) {
    // Step 1: Build min heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Extract elements
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);   // move smallest to end
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {20, 10, 30, 50, 60, 15, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "Sorted array using Min Heap:\n";
    printArray(arr, n);

    return 0;
}