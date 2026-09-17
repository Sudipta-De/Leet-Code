int romanToInt(char* s) {
  static const int value[256] = {
        ['I'] = 1,
        ['V'] = 5,
        ['X'] = 10,
        ['L'] = 50,
        ['C'] = 100,
        ['D'] = 500,
        ['M'] = 1000
    };

    int result = 0;

    for (int i = 0; s[i]; i++) {
        if (value[(unsigned char)s[i]] < value[(unsigned char)s[i + 1]])
            result -= value[(unsigned char)s[i]];
        else
            result += value[(unsigned char)s[i]];
    }

    return result;
}