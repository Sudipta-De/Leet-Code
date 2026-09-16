char* longestPalindrome(char* s) {

    int n = strlen(s);

    static char result[1001];

    int start = 0;
    int maxLength = 1;

    for (int center = 0; center < n; center++) {

        // Odd length palindrome
        int left = center;
        int right = center;

        while (left >= 0 && right < n && s[left] == s[right]) {

            if (right - left + 1 > maxLength) {
                start = left;
                maxLength = right - left + 1;
            }

            left--;
            right++;
        }

        // Even length palindrome
        left = center;
        right = center + 1;

        while (left >= 0 && right < n && s[left] == s[right]) {

            if (right - left + 1 > maxLength) {
                start = left;
                maxLength = right - left + 1;
            }

            left--;
            right++;
        }
    }

    strncpy(result, s + start, maxLength);
    result[maxLength] = '\0';

    return result;
}