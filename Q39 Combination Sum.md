# Q39 Combination Sum

```cpp
class Solution {
    vector<vector<int>> res;
    void backtrack(vector<int>& candidates, int target, int index, vector<int>& curr) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target) {
                return;
            }
            curr.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, curr);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        backtrack(candidates, target, 0, curr);
        return res;
    }
};
```
