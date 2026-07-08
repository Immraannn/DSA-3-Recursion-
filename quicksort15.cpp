#include <iostream>
using namespace std;

//-----------------------------------------------------------
// Partition Function
// Places the pivot element at its correct sorted position
// and arranges:
// Left  -> elements <= pivot
// Right -> elements > pivot
//-----------------------------------------------------------
int partition(int arr[], int s, int e)
{
    // Choose first element as pivot
    int pivot = arr[s];

    //-------------------------------------------------------
    // Step 1: Count how many elements are
    // smaller than or equal to the pivot.
    //-------------------------------------------------------
    int count = 0;

    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }

    //-------------------------------------------------------
    // Step 2: Find pivot's correct index
    //-------------------------------------------------------
    int pivotIndex = s + count;

    //-------------------------------------------------------
    // Step 3: Place pivot at its correct position
    //-------------------------------------------------------
    swap(arr[pivotIndex], arr[s]);

    //-------------------------------------------------------
    // Step 4: Rearrange remaining elements
    //
    // i -> moves from left
    // j -> moves from right
    //-------------------------------------------------------
    int i = s;
    int j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        //---------------------------------------------------
        // Move i until an element greater than pivot is found
        //---------------------------------------------------
        while (arr[i] <= pivot)
            i++;

        //---------------------------------------------------
        // Move j until an element smaller than or equal
        // to pivot is found
        //---------------------------------------------------
        while (arr[j] > pivot)
            j--;

        //---------------------------------------------------
        // Swap misplaced elements
        //---------------------------------------------------
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    //-------------------------------------------------------
    // Return pivot's final position
    //-------------------------------------------------------
    return pivotIndex;
}

//-----------------------------------------------------------
// Quick Sort Function
//-----------------------------------------------------------
void quickSort(int arr[], int s, int e)
{
    //-------------------------------------------------------
    // Base Case
    // If there is only one or zero elements,
    // it is already sorted.
    //-------------------------------------------------------
    if (s >= e)
        return;

    //-------------------------------------------------------
    // Partition the array and get pivot index
    //-------------------------------------------------------
    int p = partition(arr, s, e);

    //-------------------------------------------------------
    // Recursively sort left part
    //-------------------------------------------------------
    quickSort(arr, s, p - 1);

    //-------------------------------------------------------
    // Recursively sort right part
    //-------------------------------------------------------
    quickSort(arr, p + 1, e);
}

//-----------------------------------------------------------
// Main Function
//-----------------------------------------------------------
int main()
{
    int arr[] = {5, 3, 8, 4, 2, 7, 1, 10};

    int n = sizeof(arr) / sizeof(arr[0]);

    // Call Quick Sort
    quickSort(arr, 0, n - 1);

    // Print sorted array
    cout << "Sorted Array: ";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
