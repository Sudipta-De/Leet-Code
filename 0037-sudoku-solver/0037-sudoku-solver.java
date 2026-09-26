class Solution {
    int[] rows = new int[9];
    int[] cols = new int[9];
    int[] boxes = new int[9];

    public void solveSudoku(char[][] board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    int n = board[r][c] - '1';
                    int bit = 1 << n;
                    rows[r] |= bit;
                    cols[c] |= bit;
                    boxes[(r / 3) * 3 + c / 3] |= bit;
                }
            }
        }

        solve(board, 0);
    }

    private boolean solve(char[][] board, int pos) {
        while (pos < 81) {
            int r = pos / 9;
            int c = pos % 9;

            if (board[r][c] == '.') {
                int b = (r / 3) * 3 + c / 3;
                int used = rows[r] | cols[c] | boxes[b];
                int available = (~used) & 0x1FF;

                while (available != 0) {
                    int bit = available & -available;
                    int n = Integer.numberOfTrailingZeros(bit);

                    board[r][c] = (char) ('1' + n);
                    rows[r] |= bit;
                    cols[c] |= bit;
                    boxes[b] |= bit;

                    if (solve(board, pos + 1))
                        return true;

                    rows[r] ^= bit;
                    cols[c] ^= bit;
                    boxes[b] ^= bit;
                    board[r][c] = '.';

                    available -= bit;
                }

                return false;
            }

            pos++;
        }

        return true;
    }
}