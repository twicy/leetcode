# Q36 Valid Sudoku

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            int arr[9] = {0};
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    continue;
                }
                int num = (int)(board[row][col] - '1');
                if (arr[num] == 1) return false;
                arr[num] = 1;
            }
        }

        for (int col = 0; col < 9; col++) {
            int arr[9] = {0};
            for (int row = 0; row < 9; row++) {
                if (board[row][col] == '.') {
                    continue;
                }
                int num = (int)(board[row][col] - '1');
                if (arr[num] == 1) return false;
                arr[num] = 1;
            }
        }

        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                int arr[9] = {0};
                for (int x = row * 3; x < row * 3 + 3; x++) {
                    for (int y = col * 3; y < col * 3 + 3; y++) {
                        if (board[x][y] == '.') {
                            continue;
                        }
                        int num = (int)(board[x][y] - '1');
                        if (arr[num] == 1) return false;
                        arr[num] = 1;
                    }
                }
            }
        }
        return true;
    }
};
```
