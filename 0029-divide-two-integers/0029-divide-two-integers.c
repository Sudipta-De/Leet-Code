int divide(int dividend, int divisor) {
     if (dividend == -2147483648 && divisor == -1)
        return 2147483647;

    int negative = (dividend < 0) ^ (divisor < 0);

    long long a = dividend;
    long long b = divisor;

    if (a < 0)
        a = -a;

    if (b < 0)
        b = -b;

    long long quotient = 0;

    while (a >= b) {
        long long temp = b;
        long long multiple = 1;

        // Find the largest doubled divisor
        while ((temp << 1) <= a) {
            temp <<= 1;
            multiple <<= 1;
        }

        a -= temp;
        quotient += multiple;
    }

    if (negative)
        quotient = -quotient;

    return (int)quotient;
}