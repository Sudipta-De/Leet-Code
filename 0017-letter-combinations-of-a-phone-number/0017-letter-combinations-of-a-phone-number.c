/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    char *map[] = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    int n = 0;

    while (digits[n] != '\0')
        n++;

    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }

    int total = 1;

    for (int i = 0; i < n; i++) {
        int digit = digits[i] - '0';

        if (digit == 7 || digit == 9)
            total *= 4;
        else
            total *= 3;
    }

    char **result = malloc(total * sizeof(char *));

    for (int i = 0; i < total; i++)
        result[i] = malloc((n + 1) * sizeof(char));

    for (int i = 0; i < total; i++) {
        int x = i;

        for (int j = n - 1; j >= 0; j--) {
            int digit = digits[j] - '0';
            int len = 0;

            while (map[digit][len] != '\0')
                len++;

            result[i][j] = map[digit][x % len];
            x /= len;
        }

        result[i][n] = '\0';
    }

    *returnSize = total;

    return result;
}