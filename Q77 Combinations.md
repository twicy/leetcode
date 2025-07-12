# Q77 Combinations

```cpp
class Solution {
    vector<vector<int>> res;
    void backtracking(vector<int> &curr, int i, int n, int k) {
        if (curr.size() == k) {
            res.push_back(curr);
            return;
        }
        if (n - i + 1 < k - curr.size()) {
            return;
        }
        for (int j = i; j <= n; j++) {
            curr.push_back(j);
            backtracking(curr, j + 1, n, k);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        backtracking(curr, 1, n, k);
        return res;
    }
};
```
