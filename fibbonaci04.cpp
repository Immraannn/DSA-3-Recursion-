#include <iostream>
using namespace std;

int fibonacci(int n) {
    // Base cases
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    // Recursive call
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void printSeries(int n, int i = 0) {
    // Base case
    if (i == n)
        return;

    // Print current Fibonacci number
    cout << fib(i) << " ";

    // Recursive call
    printSeries(n, i + 1);
}

int main() {
    int n;
    cin >> n;

    cout << fibonacci(n);

    return 0;
}
//output
//5
//5

 //                         fib(5)
 //                       /        \
 //                  fib(4)        fib(3)
 //                 /     \        /     \
 //            fib(3)   fib(2)  fib(2)  fib(1)
 //           /    \     /   \    /   \
 //      fib(2) fib(1) fib(1) fib(0) fib(1) fib(0)
 //      /   \
 // fib(1) fib(0)


// fib(2) = fib(1) + fib(0)
//        = 1 + 0
//        = 1

// fib(3) = fib(2) + fib(1)
//        = 1 + 1
//        = 2

// fib(4) = fib(3) + fib(2)
//        = 2 + 1
//        = 3

// fib(5) = fib(4) + fib(3)
//        = 3 + 2
//        = 5
