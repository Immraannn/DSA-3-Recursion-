#include <iostream>
using namespace std;

// Function to merge two sorted subarrays
// First subarray: arr[s...mid]
// Second subarray: arr[mid+1...e]
void merge(int arr[], int s, int e) {

    // Find middle index
    int mid = s + (e - s) / 2;

    // Length of left subarray
    int len1 = mid - s + 1;

    // Length of right subarray
    int len2 = e - mid;

    // Dynamically create temporary arrays
    int *first = new int[len1];
    int *second = new int[len2];

    // Copy left part of original array into first[]
    int mainArrayIndex = s;

    for (int i = 0; i < len1; i++)
        first[i] = arr[mainArrayIndex++];

    // Reset index to beginning of right half
    mainArrayIndex = mid + 1;

    // Copy right part into second[]
    for (int i = 0; i < len2; i++)
        second[i] = arr[mainArrayIndex++];

    // index1 -> first array
    // index2 -> second array
    // mainArrayIndex -> original array
    int index1 = 0;
    int index2 = 0;

    // Start writing back from original starting position
    mainArrayIndex = s;

    // Compare elements of both arrays
    while (index1 < len1 && index2 < len2) {

        // Put smaller element into original array
        if (first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    // Copy remaining elements of first array
    while (index1 < len1)
        arr[mainArrayIndex++] = first[index1++];

    // Copy remaining elements of second array
    while (index2 < len2)
        arr[mainArrayIndex++] = second[index2++];

    // Free dynamically allocated memory
    delete[] first;
    delete[] second;
}

// Recursive Merge Sort function
void mergeSort(int arr[], int s, int e) {

    // Base case
    // If only one element is present,
    // it is already sorted.
    if (s >= e)
        return;

    // Find middle index
    int mid = s + (e - s) / 2;

    // Sort left half
    mergeSort(arr, s, mid);

    // Sort right half
    mergeSort(arr, mid + 1, e);

    // Merge both sorted halves
    merge(arr, s, e);
}

int main() {

    // Unsorted array
    int arr[] = {8, 4, 2, 6, 1, 5, 3, 7};

    // Calculate size of array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call Merge Sort
    mergeSort(arr, 0, n - 1);

    // Print sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
// Divide(mergesort)
     
//                  8 4 2 6 1 5 3 7                       
//                /                 \
//           8 4 2 6              1 5 3 7
//          /      \             /      \
//       8 4      2 6         1 5      3 7
//      /  \      /  \       /  \      /  \
//     8   4     2   6      1   5     3   7

// merge
//   8   4
// ↓
// 4 8

// 2   6
// ↓
// 2 6

// 4 8 + 2 6
// ↓
// 2 4 6 8

// 1 5 + 3 7
// ↓
// 1 3 5 7

// 2 4 6 8 + 1 3 5 7
// ↓
// 1 2 3 4 5 6 7 8
// mergeSort()
// Finds the middle of the array.
// Recursively sorts the left half.
// Recursively sorts the right half.
// Calls merge().
// merge()
// Creates two temporary arrays.
// Copies the left and right halves into them.
// Compares their elements one by one.
// Writes the smaller element back into the original array.
// Copies any remaining elements.
// Deletes the temporary arrays.

// mergeSort(0,5)
//     ↓
// mergeSort(0,2)
//     ↓
// mergeSort(0,1)
//     ↓
// mergeSort(0,0)  ← return
//     ↓
// mergeSort(1,1)  ← return
//     ↓
// merge(0,1)
//     ↓
// mergeSort(2,2)  ← return
//     ↓
// merge(0,2)
//     ↓
// mergeSort(3,5)
//     ↓
// mergeSort(3,4)
//     ↓
// mergeSort(3,3)  ← return
//     ↓
// mergeSort(4,4)  ← return
//     ↓
// merge(3,4)
//     ↓
// mergeSort(5,5)  ← return
//     ↓
// merge(3,5)
//     ↓
// merge(0,5)
// | Case         | Time Complexity |
// | ------------ | --------------- |
// | Best Case    | **O(n log n)**  |
// | Average Case | **O(n log n)**  |
// | Worst Case   | **O(n log n)**  |
