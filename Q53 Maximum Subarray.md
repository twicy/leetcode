# Q53 Maximum Subarray

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        vector<int> dp(nums.size() + 1);

        dp[0] = 0;
        for (int i = 1; i < dp.size(); i++) {
            dp[i] = max(nums[i - 1], dp[i - 1] + nums[i - 1]);
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};
```
