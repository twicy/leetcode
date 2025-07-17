# Q376 Wiggle Subsequence

```cpp
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        int prev_diff = 0, curr_diff = 0;
        int res = 1;

        for (int i = 0; i < nums.size() - 1; i++) {
            curr_diff = nums[i + 1] - nums[i];
            if ((prev_diff <= 0 && curr_diff > 0) ||
                (prev_diff >= 0 && curr_diff < 0)) {
                    res++;
                    prev_diff = curr_diff;
            }
        }
        return res;
    }
};
```
