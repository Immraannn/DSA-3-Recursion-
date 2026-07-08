#include <iostream>
using namespace std;

bool binarySearch(int arr[], int start, int end, int key) {
    // Base case
    if (start > end)
        return false;

    int mid = start + (end - start) / 2;

    // Element found
    if (arr[mid] == key)
        return true;

    // Search in left half
    if (key < arr[mid])
        return binarySearch(arr, start, mid - 1, key);

    // Search in right half
    return binarySearch(arr, mid + 1, end, key);
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 10;

    if (binarySearch(arr, 0, size - 1, key))
        cout << "Element Found";
    else
        cout << "Element Not Found";

    return 0;
}
