# Q54 Spiral Matrix

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int row_start = 0, row_end = matrix[0].size() - 1;
        int col_start = 0, col_end = matrix.size() - 1;
        while (row_start < row_end && col_start < col_end) {
            for (int i = row_start; i < row_end; i++) {
                res.push_back(matrix[col_start][i]);
            }
            for (int i = col_start; i < col_end; i++) {
                res.push_back(matrix[i][row_end]);
            }
            for (int i = row_end; i > row_start; i--) {
                res.push_back(matrix[col_end][i]);
            }
            for (int i = col_end; i > col_start; i--) {
                res.push_back(matrix[i][row_start]);
            }
            row_start++;
            row_end--;
            col_start++;
            col_end--;
        }

        if (row_start == row_end && (col_start < col_end)) {
            for (int i = col_start; i <= col_end; i++) {
                res.push_back(matrix[i][row_start]);
            }
        } else if (col_start == col_end && (row_start < row_end)) {
            for (int i = row_start; i <= row_end; i++) {
                res.push_back(matrix[col_start][i]);
            }
        } else if (col_start == col_end && (row_start == row_end)) {
            res.push_back(matrix[col_start][row_start]);
        }
        return res;
    }
};
```
