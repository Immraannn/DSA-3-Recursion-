class Solution {
public:
    void merge(vector<int>& nums, int s, int mid, int e) {
        vector<int> temp;

        int i = s;
        int j = mid + 1;

        // Merge two sorted halves
        while (i <= mid && j <= e) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }

        // Copy remaining elements of left half
        while (i <= mid) {
            temp.push_back(nums[i++]);
        }

        // Copy remaining elements of right half
        while (j <= e) {
            temp.push_back(nums[j++]);
        }

        // Copy back to original array
        for (int k = 0; k < temp.size(); k++) {
            nums[s + k] = temp[k];
        }
    }

    void mergeSort(vector<int>& nums, int s, int e) {
        // Base case
        if (s >= e)
            return;

        int mid = s + (e - s) / 2;

        // Sort left half
        mergeSort(nums, s, mid);

        // Sort right half
        mergeSort(nums, mid + 1, e);

        // Merge both halves
        merge(nums, s, mid, e);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
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
