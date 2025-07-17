# Q797 All Paths From Source to Target

```cpp
class Solution {
    vector<vector<int>> res;
    void dfs(vector<vector<int>>& graph, vector<int> &curr, int index) {
        if (index == graph.size() - 1) {
            res.push_back(curr);
            return;
        }

        for (int i = 0; i < graph[index].size(); i++) {
            int neighbour = graph[index][i];
            curr.push_back(neighbour);
            dfs(graph, curr, neighbour);
            curr.pop_back();
        }
        
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> curr;
        curr.push_back(0);
        dfs(graph, curr, 0);
        return res;
    }
};
```
