# Q63 Unique Paths II

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));

        res[0][0] = (obstacleGrid[0][0] == 0) ? 1:0;
        for (int i = 1; i < n; i++) {
            if (obstacleGrid[0][i] == 1) {
                res[0][i] = 0;
                continue;
            }
            res[0][i] = res[0][i - 1];
        }

        for (int j = 1; j < m; j++) {
            if (obstacleGrid[j][0] == 1) {
                res[j][0] = 0;
                continue;
            }
            res[j][0] = res[j - 1][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    res[i][j] = 0;
                    continue;
                }
                res[i][j] = res[i][j - 1] + res[i - 1][j];
            }
        }

        return res[m - 1][n - 1];
    }
};
```
