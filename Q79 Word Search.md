# Q79 Word Search

```cpp
class Solution {
    bool if_valid(vector<vector<char>>& board, int row, int col) {
        if (row < 0 || row >= board.size()) return false;
        if (col < 0 || col >= board[0].size()) return false;
        if (board[row][col] == '#') return false;
        return true;
    }
    pair<int, int> directions[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool bfs(vector<vector<char>>& board, int row, int col, string word, int index) {
        if (index == word.size()) return true;
        if (!if_valid(board, row, col)) return false;
        if (board[row][col] != word[index]) return false;

        board[row][col] = '#';
        for (auto dir : directions) {
            int next_row = row + dir.first;
            int next_col = col + dir.second;
            if (bfs(board, next_row, next_col, word, index + 1)) return true;
        }
        board[row][col] = word[index];
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (bfs(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};
```
