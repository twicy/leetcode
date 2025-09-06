# Q73 Set Matrix Zeroes

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows;
        set<int> cols;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for (auto it = rows.begin(); it != rows.end(); it++) {
            for (int i = 0; i < matrix[0].size(); i++) {
                matrix[*it][i] = 0;
            }
        }
        for (auto it = cols.begin(); it != cols.end(); it++) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][*it] = 0;
            }
        }
    }
};
```
