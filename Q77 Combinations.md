# Q77 Combinations

```cpp
class Solution {
    std::vector<std::vector<int>> res;
    void backtrack(int start, std::vector<int>& combination, int n, int k) {
        if (combination.size() == k) {
            res.push_back(combination);
            return;
        }
        for (int num = start; num <= n; num++) {
            combination.push_back(num);
            backtrack(num + 1, combination, n, k);
            combination.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        std::vector<int> comb;
        backtrack(1, comb, n, k);
        return res;
    }
};
```
