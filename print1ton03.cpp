#include <iostream>
using namespace std;

void printCount(int n) {
    // Base case
    if (n == 0)
        return;

    // Recursive call
    printCount(n - 1);//head recursion

    // Print after recursion
    cout << n << " ";
}

int main() {
    int n;
    cin >> n;

    printCount(n);

    return 0;
}


CALLS (Going Down)

printCount(3)
 └── printCount(2)
      └── printCount(1)
           └── printCount(0)  ← Base case

RETURNS (Coming Up)

printCount(0) returns
        ↑
printCount(1) prints 1
        ↑
printCount(2) prints 2
        ↑
printCount(3) prints 3
