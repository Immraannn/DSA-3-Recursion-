#include <iostream>
using namespace std;

bool isSorted(int arr[], int size) {
    // Base case
    if (size == 0 || size == 1)
        return true;

    // Check current pair
    if (arr[0] > arr[1])
        return false;

    // Recursive call
    return isSorted(arr + 1, size - 1);//After arr + 1, the original arr[1] becomes the new arr[0].
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    if (isSorted(arr, size))
        cout << "Array is sorted";
    else
        cout << "Array is not sorted";

    return 0;
}
// time and space complex-O(n)
