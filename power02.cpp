double power(int n) {
    // Base case
    if (n == 0)
        return 1;

    // Negative power
    if (n < 0)
        return 1.0 / power(-n);

    // Recursive case
    return 2 * power(n - 1);
}
