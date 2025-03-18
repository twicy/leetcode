# Q1 Two Sum

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        std::map<int, int> mp;
        for (size_t i = 0; i < nums.size(); i++) {
            auto it = mp.find(nums[i]);
            if (it != mp.end()) {
                ans[0] = it->second;
                ans[1] = i;
                return ans;
            }
            mp.insert(pair<int, int>(target - nums[i], i));
        }
        // should not reach here
        return ans;
    }
};
```
