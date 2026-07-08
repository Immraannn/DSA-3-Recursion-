#include <iostream>
using namespace std;

void reverseString(string &str, int start, int end) {
    // Base case
    if (start >= end)
        return;

    // Swap characters
    swap(str[start], str[end]);

    // Recursive call
    reverseString(str, start + 1, end - 1);
}

int main() {
    string str = "hello";

    reverseString(str, 0, str.length() - 1);

    cout << str;

    return 0;
}
