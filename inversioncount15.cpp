// Brute force aproach
long long count = 0;

for(int i = 0; i < n; i++)
{
    for(int j = i + 1; j < n; j++)
    {
        if(arr[i] > arr[j])
            count++;
    }
}


long long merge(int arr[], int s, int e)
{
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    // Create temporary arrays
    int *first = new int[len1];
    int *second = new int[len2];

    // Copy left half
    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    // Copy right half
    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    // Merge two sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    // Variable to store inversion count
    long long count = 0;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] <= second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            // Count inversions
            count += (len1 - index1);

            arr[mainArrayIndex++] = second[index2++];
        }
    }

    // Copy remaining elements
    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }

    // Free memory
    delete[] first;
    delete[] second;

    return count;
}

// We use long long because the maximum inversion count is 
// 2
// n(n−1)
// 	​

// . For large arrays (e.g., n = 100000), this value is about 5 × 10⁹, which exceeds the maximum value of an int (2,147,483,647). A long long safely stores these larger values.
