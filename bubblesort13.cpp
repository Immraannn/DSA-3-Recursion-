#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    // Base case
    if (n == 1 || n == 0)
        return;

    // One pass of Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }

    // Recursive call for first n-1 elements
    bubbleSort(arr, n - 1);
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
// bubbleSort(arr,5)
//         |
//         V
// bubbleSort(arr,4)
//         |
//         V
// bubbleSort(arr,3)
//         |
//         V
// bubbleSort(arr,2)
//         |
//         V
// bubbleSort(arr,1)
//         |
//       Return
//   | Case                  | Time    |
// | --------------------- | ------- |
// | Best Case (optimized) | `O(n)`  |
// | Average Case          | `O(n²)` |
// | Worst Case            | `O(n²)` |
// space=O(n) recursive call stack
