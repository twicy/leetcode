# Q59 Spiral Matrix II

```cpp
class Solution {
    int directions [4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool valid (vector<vector<int>> &ans, int i, int j) {
        int n = ans.size();
        return (0 <= i && i < n) && (0 <= j && j < n) && (ans[i][j] == 0);
    }
public:
    vector<vector<int>> generateMatrix(int n) {
        int i = 0, j = 0;
        int direction = 0;
        vector<vector<int>> ans(n, vector<int>(n, 0));

        for (int index = 1; index <= n * n; index++) {
            ans[i][j] = index;
            int next_i, next_j;
            next_i = i + directions[direction][0];
            next_j = j + directions[direction][1];
            if (!valid(ans, next_i, next_j)) {
                direction = (direction + 1) % 4;
                next_i = i + directions[direction][0];
                next_j = j + directions[direction][1];
            }
            i = next_i;
            j = next_j;
        }
        return ans;
    }
};
```
