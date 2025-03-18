# Q1919 Remove One Element to Make the Array Strictly Increasing

```cpp
class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int second_chance = true;
        int prev = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > prev) {
                prev = nums[i];
                continue;
            }
            if (!second_chance) {
                return false;
            }
            second_chance = false;
            // prev = nums[i - 1] < nums[i]
            if (i >= 2 && nums[i - 2] >= nums[i]) {
                // deleting i
                prev = nums[i - 1];
            } else {
                // deleting i - 1
                prev = nums[i];
            }
        }
        return true;
    }
};
```
