# Q74 Search a 2D Matrix

```cpp
class Solution {
public:
    int locate_row(vector<vector<int>>& matrix, int target) {
        if (target < matrix[0][0] || target > matrix[matrix.size() - 1][matrix[0].size() - 1]) return -1;
        int row_up = 0, row_down = matrix.size() - 1;
        while (row_up <= row_down) {
            int row_mid = (row_up + row_down) / 2;
            if (matrix[row_mid][0] <= target && target <= matrix[row_mid][matrix[0].size() - 1]) {
                return row_mid;
            } else if (matrix[row_mid][0] > target) {
                row_down = row_mid - 1;
            } else {
                row_up = row_mid + 1;
            }
        }
        return -1;
    }

    bool locate_col(vector<int>& matrix, int target) {
        int left = 0, right = matrix.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[mid] == target) {
                return true;
            } else if (matrix[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = locate_row(matrix, target);
        if (row == -1) return false;
        return locate_col(matrix[row], target);
    }
};
```
