#include <iostream>
using namespace std;

bool linearSearch(int arr[], int size, int key) {
    // Base case
    if (size == 0)
        return false;

    // Check current element
    if (arr[0] == key)
        return true;

    // Recursive call
    return linearSearch(arr + 1, size - 1, key);
}

int main() {
    int arr[] = {5, 8, 2, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 9;

    if (linearSearch(arr, size, key))
        cout << "Element Found";
    else
        cout << "Element Not Found";

    return 0;
}

// | Recursive Call              | `arr[0]` | Original Array Index |
// | --------------------------- | -------- | -------------------- |
// | `linearSearch(arr,5,key)`   | 5        | 0                    |
// | `linearSearch(arr+1,4,key)` | 8        | 1                    |
// | `linearSearch(arr+1,3,key)` | 2        | 2                    |
// | `linearSearch(arr+1,2,key)` | 9        | 3                    |
// | `linearSearch(arr+1,1,key)` | 1        | 4                    

//   Time: O(n) (in the worst case, every element is checked)
// Space: O(n) (due to the recursive call stack)
