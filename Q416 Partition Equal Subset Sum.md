# Q416 Partition Equal Subset Sum

```cpp
class Solution {

public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        if (sum % 2 == 1) {
            return false;
        }

        vector<vector<bool>> dp(nums.size(), vector<bool>(sum / 2 + 1, true));

        // sum == 0, then true;
        for (int i = 0; i < dp.size(); i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i < dp[0].size(); i++) {
            dp[0][i] = false;
        }

        // i -> num, j -> sum
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[0].size(); j++) {
                if (j >= nums[i]) {
                    dp[i][j] = (dp[i - 1][j]) ||
                            (dp[i - 1][j - nums[i]]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[dp.size() - 1][dp[0].size() - 1];
    }
};
```
