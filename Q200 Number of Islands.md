# Q200 Number of Islands

```cpp
class Solution {
    int res = 0;
    pair<int, int> directions[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<char>>& grid, int row, int col, int first_lander) {
        if (row >= grid.size() || row < 0) return;
        if (col >= grid[0].size() || col < 0) return;
        if (grid[row][col] == '#' || grid[row][col] == '0') return;
        if (first_lander) res++;
        grid[row][col] = '#';
        for (auto direction:directions) {
            int next_row = row + direction.first;
            int next_col = col + direction.second;
            dfs(grid, next_row, next_col, false);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                dfs(grid, i, j, true);
            }
        }
        return res;
    }
};
```
