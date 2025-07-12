# Q46 Permutations

```cpp
class Solution {
    vector<vector<int>> res;
    void swap(vector<int>& nums, int l, int r) {
        int temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
    }
    void backtrack(vector<int>& nums, int start) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            swap(nums, start, i);
            backtrack(nums, start + 1);
            swap(nums, start, i);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
};
```

```cpp
class Solution {
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int> curr, vector<bool>& used) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            used[i] = true;
            curr.push_back(nums[i]);
            backtrack(nums, curr, used);
            curr.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<bool> used(nums.size(), false);
        backtrack(nums, curr, used);
        return res;
    }
};
```
