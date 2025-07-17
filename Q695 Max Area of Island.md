# Q695 Max Area of Island

```cpp
class Solution {
    pair<int, int> directions[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int area = 0;
    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col) {
        queue<pair<int, int>> q;
        q.push(make_pair(row, col));
        visited[row][col] = true;
        area++;
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            for (auto dir:directions) {
                int next_row = top.first + dir.first;
                int next_col = top.second + dir.second;
                if (next_row < 0 || next_row >= grid.size()) continue;
                if (next_col < 0 || next_col >= grid[0].size()) continue;
                if (visited[next_row][next_col] || grid[next_row][next_col] == 0) continue;
                visited[next_row][next_col] = true;
                area++;
                q.push(make_pair(next_row, next_col));
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    area = 0;
                    bfs(grid, visited, i, j);
                    result = max(result, area);
                }
            }
        }
        return result;
    }
};
```
