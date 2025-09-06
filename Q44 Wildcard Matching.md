# Q44 Wildcard Matching

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(p.size() + 1, vector<bool>(s.size() + 1, false));
        dp[0][0] = true;
        for (int i = 0; i < p.size(); i++) {
            if (p[i] != '*') break;
            // * matches empty string
            dp[i + 1][0] = true;
        }

        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[0].size(); j++) {
                if (p[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[i - 1] != '*') {
                    dp[i][j] = dp[i - 1][j - 1] && (p[i - 1] == s[j - 1]);
                } else {
                    if (dp[i - 1][j]) dp[i][j] = true;
                    if (dp[i - 1][j - 1]) {
                        while (j < dp[0].size()) {
                            dp[i][j] = true;
                            j++;
                        }
                    }
                }
            }
        }
        return dp[p.size()][s.size()];
    }
};
```
