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
