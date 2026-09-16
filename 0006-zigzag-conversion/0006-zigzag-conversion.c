char* convert(char* s, int numRows) {
    int len = strlen(s);

    if (numRows == 1 || numRows >= len) {
        return s;
    }

    char* result = (char*)malloc((len + 1) * sizeof(char));
    int index = 0;

    int cycle = 2 * (numRows - 1);

    for (int row = 0; row < numRows; row++) {

        for (int pos = row; pos < len; pos += cycle) {

            // Vertical character
            result[index++] = s[pos];

            // Diagonal character
            if (row != 0 && row != numRows - 1) {

                int diagonal = pos + cycle - 2 * row;

                if (diagonal < len) {
                    result[index++] = s[diagonal];
                }
            }
        }
    }

    result[index] = '\0';

    return result;
}