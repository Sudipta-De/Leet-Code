bool isPerfectSquare(int num) {
    if (num < 2)
        return true;

    int left = 1;
    int right = num / 2;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if ((long long)mid * mid == num)
            return true;

        if ((long long)mid * mid < num)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;

}