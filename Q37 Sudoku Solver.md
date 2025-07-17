# Q37 Sudoku Solver

```cpp
class Solution {
    bool valid(vector<vector<char>>& curr, int row, int col, int num) {
        char ch = (char)('0' + num);
        for (int c = 0; c < 9; c++) {
            if (curr[row][c] == ch) return false;
        }
        for (int r = 0; r < 9; r++) {
            if (curr[r][col] == ch) return false;
        }

        int x_start = (row / 3) * 3;
        int y_start = (col / 3) * 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (curr[x_start + i][y_start + j] == ch) return false;
            }
        }
        return true;
    }

    bool backtrack(vector<vector<char>>& curr, int row, int col) {
        while (col < 9 && row < 9 && curr[row][col] != '.') {
            if (col != 8) {
                col++;
            } else {
                col = 0;
                row++;
            }
        }

        if (row == 9 && col == 0) {
            return true;
        }

        for (int i = 1; i <= 9; i++) {
            if (!valid(curr, row, col, i)) continue;
            curr[row][col] = (char)('0' + i);
            if (col != curr.size() - 1) {
                if (backtrack(curr, row, col + 1)) return true;
            } else {
                if(backtrack(curr, row + 1, 0)) return true;
            }
            curr[row][col] = '.';
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }
};
```
