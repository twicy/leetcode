# Q90 Subsets II

```cpp
class Solution {
    vector<vector<int>> res;

    void iterate(vector<int>& nums, int index, vector<int> &curr) {
        if (index == nums.size()) {
            res.push_back(curr);
            return;
        }
        // either we take this number
        curr.push_back(nums[index]);
        iterate(nums, index + 1, curr);
        curr.pop_back();
        // or we dont take this number and jumps to next unique, differnet number
        while (index + 1 < nums.size() && (nums[index] == nums[index + 1])) {
            index++;
        }
        iterate(nums, index + 1, curr);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin() , nums.end());
        iterate(nums, 0, curr);
        return res;
    }
};
```
