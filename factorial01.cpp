// | Function Return Type          | Recursive Call                               |
// | ----------------------------- | -------------------------------------------- |
// | `void`                        | `fun(...);`                                  |
// | `int`, `bool`, `string`, etc. | `return fun(...);` or use its returned value |



#include<iostream> 
using namespace std;

int factorial(int n) {
    
    //base case
    if(n==0)
        return 1;

    int smallerProblem = factorial(n-1);   
    int biggerProblem = n * smallerProblem;

    return biggerProblem;
}

int main() {

    int n;
    cin >> n;

    int ans = factorial(n);

    cout << ans << endl;

    return 0;
}
// Stack representation
// factorial(5)
// │
// ├── factorial(4)
// │   │
// │   ├── factorial(3)
// │   │   │
// │   │   ├── factorial(2)
// │   │   │   │
// │   │   │   ├── factorial(1)
// │   │   │   │   │
// │   │   │   │   └── factorial(0)
// │   │   │   │       return 1
// │   │   │   │
// │   │   │   └── return 1
// │   │   │
// │   │   └── return 2
// │   │
// │   └── return 6
// │
// └── return 24

// Final return = 120
