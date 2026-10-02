
class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> result = new ArrayList<>();
        int n = words.length;
        int i = 0;
        while (i < n) {
            int j = i;
            int lineLength = 0;
            while (j < n &&
                   lineLength + words[j].length() + (j - i) <= maxWidth) {
                lineLength += words[j].length();
                j++;
            }
            int wordCount = j - i;
            int spaces = maxWidth - lineLength;
            StringBuilder line = new StringBuilder();
            if (j == n || wordCount == 1) {
                for (int k = i; k < j; k++) {
                    line.append(words[k]);

                    if (k < j - 1) {
                        line.append(" ");
                    }
                }
                while (line.length() < maxWidth) {
                    line.append(" ");
                }
            } else {
                int gaps = wordCount - 1;
                int spacesPerGap = spaces / gaps;
                int extraSpaces = spaces % gaps;

                for (int k = i; k < j; k++) {
                    line.append(words[k]);
                    if (k < j - 1) {
                        int count = spacesPerGap;
                        if (k - i < extraSpaces) {
                            count++;
                        }
                        for (int s = 0; s < count; s++) {
                            line.append(" ");
                        }
                    }
                }
            }
            result.add(line.toString());
            i = j;
        }
        return result;
    }
}