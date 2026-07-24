#include <iostream>
using namespace std;

double power(double a, int b) {
    // Base case
    if (b == 0)
        return 1;

    if (b < 0)
        return 1.0 / power(a, -b);

    // Recursive call
    return a * power(a, b - 1);
}

int main() {
    int a = 2;
    int b = 5;

    cout << power(a, b);

    return 0;
}
