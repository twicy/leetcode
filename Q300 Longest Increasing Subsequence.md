# Q300 Longest Increasing Subsequence

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j >= 0; j--) {
                if (nums[i] > nums[j] && (dp[j] + 1 > dp[i])) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        for (int i = 0; i < dp.size(); i++) {
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};
```
