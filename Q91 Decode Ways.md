# Q91 Decode Ways

```cpp
class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, 0);

        for (int i = 1; i < (int)dp.size(); i++) {
            int ones = (int)(s[i - 1] - '0');
            if (1 <= ones && ones <= 9) dp[i] = (i == 1) ? 1 : dp[i - 1];
    
            if (i >= 2) {
                int tens = (int)(s[i - 2] - '0');
                int num = tens * 10 + ones;
                if (10 <= num && num <= 26) dp[i] = (i == 2) ? dp[i - 2] + dp[i] + 1 : dp[i - 2] + dp[i];
            }
        }
        return dp[dp.size() - 1];
    }
};
```
