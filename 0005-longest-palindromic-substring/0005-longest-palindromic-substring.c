char* longestPalindrome(char* s) {

    int n = strlen(s);

    static char result[1001];

    int dp[1000][1000];

    int start = 0;
    int maxlength = 1;

    // Single characters are palindromes
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // Check substrings of length 2 to n
    for (int length = 2; length <= n; length++) {

        for (int i = 0; i <= n - length; i++) {

            int j = i + length - 1;

            if (s[i] == s[j]) {

                if (length == 2) {
                    dp[i][j] = 1;       // FIX 1
                }
                else {
                    dp[i][j] = dp[i + 1][j - 1];
                }

                if (dp[i][j] && length > maxlength) {
                    start = i;          // FIX 2
                    maxlength = length;
                }
            }
            else {
                dp[i][j] = 0;
            }
        }
    }

    strncpy(result, s + start, maxlength);
    result[maxlength] = '\0';

    return result;
}