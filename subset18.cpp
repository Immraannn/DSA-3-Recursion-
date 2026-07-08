#include <iostream>
#include <vector>
using namespace std;

// Function to generate all subsets
void solve(vector<int> &arr, vector<int> output, int index)
{
    // Base Case
    if(index >= arr.size())
    {
        cout << "{ ";

        for(int i = 0; i < output.size(); i++)
            cout << output[i] << " ";

        cout << "}" << endl;
        return;
    }

    // Exclude current element
    solve(arr, output, index + 1);

    // Include current element
    output.push_back(arr[index]);

    solve(arr, output, index + 1);
}

int main()
{
    vector<int> arr = {1,2,3};

    vector<int> output;

    solve(arr, output, 0);

    return 0;
}
//output
// { }
// { 3 }
// { 2 }
// { 2 3 }
// { 1 }
// { 1 3 }
// { 1 2 }
// { 1 2 3 }

// stack call

solve({},0)
      │
      ▼
solve({},1)
      │
      ▼
solve({},2)
      │
      ▼
print {}

      ▲
      │ return

solve({2},2)
      │
      ▼
print {2}

      ▲
      │ return

solve({1},1)
      │
      ▼
solve({1},2)
      │
      ▼
print {1}

      ▲
      │ return

solve({1,2},2)
      │
      ▼
print {1,2}
