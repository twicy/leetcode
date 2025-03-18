# Q78 Subsets

```cpp
class Solution {
    vector<vector<int>> res;
    void backtracking(vector<int>& nums, int index, vector<int>& curr) {
        if (index == nums.size()) {
            res.push_back(curr);
            return;
        }
        backtracking(nums, index + 1, curr);
        curr.push_back(nums[index]);
        backtracking(nums, index + 1, curr);
        curr.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        backtracking(nums, 0, curr);
        return res;
    }
};
```
