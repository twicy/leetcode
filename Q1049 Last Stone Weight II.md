# Q1049 Last Stone Weight II

```cpp
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int i = 0; i < stones.size(); i++) {
            sum += stones[i];
        }

        vector<vector<bool> > dp(stones.size() + 1, vector<bool>(sum / 2 + 1, true));

        // sum = 0, true
        for (int i = 0; i < dp.size(); i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i < dp[0].size(); i++) {
            dp[0][i] = false;
        }

        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[0].size(); j++) {
                if (j >= stones[i - 1]) {
                    dp[i][j] = (dp[i - 1][j - stones[i - 1]]) || (dp[i - 1][j]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        for (int i = dp[0].size() - 1; i >= 0; i--) {
            if (dp[dp.size() - 1][i] == true) {
                return sum - 2 * i;
            }
        }

        return 0;
    }
};
```
